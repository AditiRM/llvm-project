//===- AMDGPUMCInstLower.cpp - Lower AMDGPU MachineInstr to an MCInst -----===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
/// \file
/// Code to lower AMDGPU MachineInstrs to their corresponding MCInst.
//
//===----------------------------------------------------------------------===//
//

#include "AMDGPUMCInstLower.h"
#include "AMDGPU.h"
#include "AMDGPUAsmPrinter.h"
#include "AMDGPUMachineFunction.h"
#include "MCTargetDesc/AMDGPUInstPrinter.h"
#include "MCTargetDesc/AMDGPUMCExpr.h"
#include "MCTargetDesc/AMDGPUMCTargetDesc.h"
#include "SIMachineFunctionInfo.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCObjectStreamer.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/Support/Endian.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/Format.h"
#include <algorithm>

using namespace llvm;

#include "AMDGPUGenMCPseudoLowering.inc"

AMDGPUMCInstLower::AMDGPUMCInstLower(MCContext &ctx,
                                     const TargetSubtargetInfo &st,
                                     const AsmPrinter &ap):
  Ctx(ctx), ST(st), AP(ap) { }

static AMDGPUMCExpr::Specifier getSpecifier(unsigned MOFlags) {
  switch (MOFlags) {
  default:
    return AMDGPUMCExpr::S_None;
  case SIInstrInfo::MO_GOTPCREL:
  case SIInstrInfo::MO_GOTPCREL64:
    return AMDGPUMCExpr::S_GOTPCREL;
  case SIInstrInfo::MO_GOTPCREL32_LO:
    return AMDGPUMCExpr::S_GOTPCREL32_LO;
  case SIInstrInfo::MO_GOTPCREL32_HI:
    return AMDGPUMCExpr::S_GOTPCREL32_HI;
  case SIInstrInfo::MO_REL32_LO:
    return AMDGPUMCExpr::S_REL32_LO;
  case SIInstrInfo::MO_REL32_HI:
    return AMDGPUMCExpr::S_REL32_HI;
  case SIInstrInfo::MO_REL64:
    return AMDGPUMCExpr::S_REL64;
  case SIInstrInfo::MO_ABS32_LO:
    return AMDGPUMCExpr::S_ABS32_LO;
  case SIInstrInfo::MO_ABS32_HI:
    return AMDGPUMCExpr::S_ABS32_HI;
  case SIInstrInfo::MO_ABS64:
    return AMDGPUMCExpr::S_ABS64;
  }
}

bool AMDGPUMCInstLower::lowerOperand(const MachineOperand &MO,
                                     MCOperand &MCOp) const {
  switch (MO.getType()) {
  default:
    break;
  case MachineOperand::MO_Immediate:
    MCOp = MCOperand::createImm(MO.getImm());
    return true;
  case MachineOperand::MO_Register:
    MCOp = MCOperand::createReg(AMDGPU::getMCReg(MO.getReg(), ST));
    return true;
  case MachineOperand::MO_MachineBasicBlock:
    MCOp = MCOperand::createExpr(
        MCSymbolRefExpr::create(MO.getMBB()->getSymbol(), Ctx));
    return true;
  case MachineOperand::MO_GlobalAddress: {
    const GlobalValue *GV = MO.getGlobal();
    SmallString<128> SymbolName;
    AP.getNameWithPrefix(SymbolName, GV);
    MCSymbol *Sym = Ctx.getOrCreateSymbol(SymbolName);
    const MCExpr *Expr =
        MCSymbolRefExpr::create(Sym, getSpecifier(MO.getTargetFlags()), Ctx);
    int64_t Offset = MO.getOffset();
    if (Offset != 0) {
      Expr = MCBinaryExpr::createAdd(Expr,
                                     MCConstantExpr::create(Offset, Ctx), Ctx);
    }
    MCOp = MCOperand::createExpr(Expr);
    return true;
  }
  case MachineOperand::MO_ExternalSymbol: {
    MCSymbol *Sym = Ctx.getOrCreateSymbol(StringRef(MO.getSymbolName()));
    const MCSymbolRefExpr *Expr = MCSymbolRefExpr::create(Sym, Ctx);
    MCOp = MCOperand::createExpr(Expr);
    return true;
  }
  case MachineOperand::MO_RegisterMask:
    // Regmasks are like implicit defs.
    return false;
  case MachineOperand::MO_MCSymbol:
    if (MO.getTargetFlags() == SIInstrInfo::MO_FAR_BRANCH_OFFSET) {
      MCSymbol *Sym = MO.getMCSymbol();
      MCOp = MCOperand::createExpr(Sym->getVariableValue());
      return true;
    }
    break;
  }
  llvm_unreachable("unknown operand type");
}

// Lower true16 D16 Pseudo instruction to d16_lo/d16_hi MCInst based on
// Dst/Data's .l/.h selection
void AMDGPUMCInstLower::lowerT16D16Helper(const MachineInstr *MI,
                                          MCInst &OutMI) const {
  unsigned Opcode = MI->getOpcode();
  const auto *TII = static_cast<const SIInstrInfo*>(ST.getInstrInfo());
  const SIRegisterInfo &TRI = TII->getRegisterInfo();
  const auto *Info = AMDGPU::getT16D16Helper(Opcode);

  llvm::AMDGPU::OpName OpName;
  if (TII->isDS(Opcode)) {
    if (MI->mayLoad())
      OpName = llvm::AMDGPU::OpName::vdst;
    else if (MI->mayStore())
      OpName = llvm::AMDGPU::OpName::data0;
    else
      llvm_unreachable("LDS load or store expected");
  } else {
    OpName = AMDGPU::hasNamedOperand(Opcode, llvm::AMDGPU::OpName::vdata)
                 ? llvm::AMDGPU::OpName::vdata
                 : llvm::AMDGPU::OpName::vdst;
  }

  // select Dst/Data
  int VDstOrVDataIdx = AMDGPU::getNamedOperandIdx(Opcode, OpName);
  const MachineOperand &MIVDstOrVData = MI->getOperand(VDstOrVDataIdx);

  // select hi/lo MCInst
  bool IsHi = AMDGPU::isHi16Reg(MIVDstOrVData.getReg(), TRI);
  Opcode = IsHi ? Info->HiOp : Info->LoOp;

  int MCOpcode = TII->pseudoToMCOpcode(Opcode);
  assert(MCOpcode != -1 &&
         "Pseudo instruction doesn't have a target-specific version");
  OutMI.setOpcode(MCOpcode);

  // lower operands
  for (int I = 0, E = MI->getNumExplicitOperands(); I < E; I++) {
    const MachineOperand &MO = MI->getOperand(I);
    MCOperand MCOp;
    if (I == VDstOrVDataIdx)
      MCOp = MCOperand::createReg(TRI.get32BitRegister(MIVDstOrVData.getReg()));
    else
      lowerOperand(MO, MCOp);
    OutMI.addOperand(MCOp);
  }

  if (AMDGPU::hasNamedOperand(MCOpcode, AMDGPU::OpName::vdst_in)) {
    MCOperand MCOp;
    lowerOperand(MIVDstOrVData, MCOp);
    OutMI.addOperand(MCOp);
  }
}

void AMDGPUMCInstLower::lower(const MachineInstr *MI, MCInst &OutMI) const {
  unsigned Opcode = MI->getOpcode();
  const auto *TII = static_cast<const SIInstrInfo *>(ST.getInstrInfo());

  // FIXME: Should be able to handle this with lowerPseudoInstExpansion. We
  // need to select it to the subtarget specific version, and there's no way to
  // do that with a single pseudo source operation.
  if (Opcode == AMDGPU::S_SETPC_B64_return)
    Opcode = AMDGPU::S_SETPC_B64;
  else if (Opcode == AMDGPU::SI_CALL) {
    // SI_CALL is just S_SWAPPC_B64 with an additional operand to track the
    // called function (which we need to remove here).
    OutMI.setOpcode(TII->pseudoToMCOpcode(AMDGPU::S_SWAPPC_B64));
    MCOperand Dest, Src;
    lowerOperand(MI->getOperand(0), Dest);
    lowerOperand(MI->getOperand(1), Src);
    OutMI.addOperand(Dest);
    OutMI.addOperand(Src);
    return;
  } else if (Opcode == AMDGPU::SI_TCRETURN ||
             Opcode == AMDGPU::SI_TCRETURN_GFX) {
    // TODO: How to use branch immediate and avoid register+add?
    Opcode = AMDGPU::S_SETPC_B64;
  } else if (AMDGPU::getT16D16Helper(Opcode)) {
    lowerT16D16Helper(MI, OutMI);
    return;
  }

  int MCOpcode = TII->pseudoToMCOpcode(Opcode);
  if (MCOpcode == -1) {
    LLVMContext &C = MI->getParent()->getParent()->getFunction().getContext();
    C.emitError("AMDGPUMCInstLower::lower - Pseudo instruction doesn't have "
                "a target-specific version: " + Twine(MI->getOpcode()));
  }

  OutMI.setOpcode(MCOpcode);

  for (const MachineOperand &MO : MI->explicit_operands()) {
    MCOperand MCOp;
    lowerOperand(MO, MCOp);
    OutMI.addOperand(MCOp);
  }

  int FIIdx = AMDGPU::getNamedOperandIdx(MCOpcode, AMDGPU::OpName::fi);
  if (FIIdx >= (int)OutMI.getNumOperands())
    OutMI.addOperand(MCOperand::createImm(0));
}

bool AMDGPUAsmPrinter::lowerOperand(const MachineOperand &MO,
                                    MCOperand &MCOp) const {
  const GCNSubtarget &STI = MF->getSubtarget<GCNSubtarget>();
  AMDGPUMCInstLower MCInstLowering(OutContext, STI, *this);
  return MCInstLowering.lowerOperand(MO, MCOp);
}

const MCExpr *AMDGPUAsmPrinter::lowerConstant(const Constant *CV,
                                              const Constant *BaseCV,
                                              uint64_t Offset) {

  // Intercept LDS variables with known addresses
  if (const GlobalVariable *GV = dyn_cast<const GlobalVariable>(CV)) {
    if (std::optional<uint32_t> Address =
            AMDGPUMachineFunction::getLDSAbsoluteAddress(*GV)) {
      auto *IntTy = Type::getInt32Ty(CV->getContext());
      return AsmPrinter::lowerConstant(ConstantInt::get(IntTy, *Address),
                                       BaseCV, Offset);
    }
  }

  if (const MCExpr *E = lowerAddrSpaceCast(TM, CV, OutContext))
    return E;
  return AsmPrinter::lowerConstant(CV, BaseCV, Offset);
}

static void emitVGPRBlockComment(const MachineInstr *MI, const SIInstrInfo *TII,
                                 const TargetRegisterInfo *TRI,
                                 const SIMachineFunctionInfo *MFI,
                                 MCStreamer &OS) {
  // The instruction will only transfer a subset of the registers in the block,
  // based on the mask that is stored in m0. We could search for the instruction
  // that sets m0, but most of the time we'll already have the mask stored in
  // the machine function info. Try to use that. This assumes that we only use
  // block loads/stores for CSR spills.
  Register RegBlock =
      TII->getNamedOperand(*MI, MI->mayLoad() ? AMDGPU::OpName::vdst
                                              : AMDGPU::OpName::vdata)
          ->getReg();
  Register FirstRegInBlock = TRI->getSubReg(RegBlock, AMDGPU::sub0);
  uint32_t Mask = MFI->getMaskForVGPRBlockOps(RegBlock);

  if (!Mask)
    return; // Nothing to report

  SmallString<512> TransferredRegs;
  for (unsigned I = 0; I < sizeof(Mask) * 8; ++I) {
    if (Mask & (1 << I)) {
      (llvm::Twine(" ") + TRI->getRegAsmName(FirstRegInBlock + I))
          .toVector(TransferredRegs);
    }
  }

  OS.emitRawComment(" transferring at most " + TransferredRegs);
}

void AMDGPUAsmPrinter::emitInstruction(const MachineInstr *MI) {
  // FIXME: Enable feature predicate checks once all the test pass.
  // AMDGPU_MC::verifyInstructionPredicates(MI->getOpcode(),
  //                                        getSubtargetInfo().getFeatureBits());

  if (MCInst OutInst; lowerPseudoInstExpansion(MI, OutInst)) {
    EmitToStreamer(*OutStreamer, OutInst);
    return;
  }

  const GCNSubtarget &STI = MF->getSubtarget<GCNSubtarget>();
  AMDGPUMCInstLower MCInstLowering(OutContext, STI, *this);

  StringRef Err;
  if (!STI.getInstrInfo()->verifyInstruction(*MI, Err)) {
    LLVMContext &C = MI->getParent()->getParent()->getFunction().getContext();
    C.emitError("Illegal instruction detected: " + Err);
    MI->print(errs());
  }

  if (MI->isBundle()) {
    const MachineBasicBlock *MBB = MI->getParent();
    MachineBasicBlock::const_instr_iterator I = ++MI->getIterator();
    while (I != MBB->instr_end() && I->isInsideBundle()) {
      emitInstruction(&*I);
      ++I;
    }
  } else {
    // We don't want these pseudo instructions encoded. They are
    // placeholder terminator instructions and should only be printed as
    // comments.
    if (MI->getOpcode() == AMDGPU::SI_RETURN_TO_EPILOG) {
      if (isVerbose())
        OutStreamer->emitRawComment(" return to shader part epilog");
      return;
    }

    if (MI->getOpcode() == AMDGPU::WAVE_BARRIER) {
      if (isVerbose())
        OutStreamer->emitRawComment(" wave barrier");
      return;
    }

    if (MI->getOpcode() == AMDGPU::SCHED_BARRIER) {
      if (isVerbose()) {
        std::string HexString;
        raw_string_ostream HexStream(HexString);
        HexStream << format_hex(MI->getOperand(0).getImm(), 10, true);
        OutStreamer->emitRawComment(" sched_barrier mask(" + HexString + ")");
      }
      return;
    }

    if (MI->getOpcode() == AMDGPU::SCHED_GROUP_BARRIER) {
      if (isVerbose()) {
        std::string HexString;
        raw_string_ostream HexStream(HexString);
        HexStream << format_hex(MI->getOperand(0).getImm(), 10, true);
        OutStreamer->emitRawComment(
            " sched_group_barrier mask(" + HexString + ") size(" +
            Twine(MI->getOperand(1).getImm()) + ") SyncID(" +
            Twine(MI->getOperand(2).getImm()) + ")");
      }
      return;
    }

    if (MI->getOpcode() == AMDGPU::IGLP_OPT) {
      if (isVerbose()) {
        std::string HexString;
        raw_string_ostream HexStream(HexString);
        HexStream << format_hex(MI->getOperand(0).getImm(), 10, true);
        OutStreamer->emitRawComment(" iglp_opt mask(" + HexString + ")");
      }
      return;
    }

    if (MI->getOpcode() == AMDGPU::SI_MASKED_UNREACHABLE) {
      if (isVerbose())
        OutStreamer->emitRawComment(" divergent unreachable");
      return;
    }

    if (MI->isMetaInstruction()) {
      if (isVerbose())
        OutStreamer->emitRawComment(" meta instruction");
      return;
    }

    if (isVerbose())
      if (STI.getInstrInfo()->isBlockLoadStore(MI->getOpcode()))
        emitVGPRBlockComment(MI, STI.getInstrInfo(), STI.getRegisterInfo(),
                             MF->getInfo<SIMachineFunctionInfo>(),
                             *OutStreamer);

    MCInst TmpInst;
    MCInstLowering.lower(MI, TmpInst);
    EmitToStreamer(*OutStreamer, TmpInst);

#ifdef EXPENSIVE_CHECKS
    // Check getInstSizeInBytes on explicitly specified CPUs (it cannot
    // work correctly for the generic CPU).
    //
    // The isPseudo check really shouldn't be here, but unfortunately there are
    // some negative lit tests that depend on being able to continue through
    // here even when pseudo instructions haven't been lowered.
    //
    // We also overestimate branch sizes with the offset bug.
    if (!MI->isPseudo() && STI.isCPUStringValid(STI.getCPU()) &&
        (!STI.hasOffset3fBug() || !MI->isBranch())) {
      SmallVector<MCFixup, 4> Fixups;
      SmallVector<char, 16> CodeBytes;

      std::unique_ptr<MCCodeEmitter> InstEmitter(createAMDGPUMCCodeEmitter(
          *STI.getInstrInfo(), OutContext));
      InstEmitter->encodeInstruction(TmpInst, CodeBytes, Fixups, STI);

      assert(CodeBytes.size() == STI.getInstrInfo()->getInstSizeInBytes(*MI));
    }
#endif

    if (DumpCodeInstEmitter) {
      // Disassemble instruction/operands to text
      DisasmLines.resize(DisasmLines.size() + 1);
      std::string &DisasmLine = DisasmLines.back();
      raw_string_ostream DisasmStream(DisasmLine);

      AMDGPUInstPrinter InstPrinter(*TM.getMCAsmInfo(), *STI.getInstrInfo(),
                                    *STI.getRegisterInfo());
      InstPrinter.printInst(&TmpInst, 0, StringRef(), STI, DisasmStream);

      // Disassemble instruction/operands to hex representation.
      SmallVector<MCFixup, 4> Fixups;
      SmallVector<char, 16> CodeBytes;

      DumpCodeInstEmitter->encodeInstruction(
          TmpInst, CodeBytes, Fixups, MF->getSubtarget<MCSubtargetInfo>());
      HexLines.resize(HexLines.size() + 1);
      std::string &HexLine = HexLines.back();
      raw_string_ostream HexStream(HexLine);

      for (size_t i = 0; i < CodeBytes.size(); i += 4) {
        unsigned int CodeDWord =
            support::endian::read32le(CodeBytes.data() + i);
        HexStream << format("%s%08X", (i > 0 ? " " : ""), CodeDWord);
      }

      DisasmLineMaxLen = std::max(DisasmLineMaxLen, DisasmLine.size());
    }
  }
}

//===- InferAlignment.cpp -------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Infer alignment for load, stores and other memory operations based on
// trailing zero known bits information.
//
//===----------------------------------------------------------------------===//

#include "llvm/Transforms/Scalar/InferAlignment.h"
#include "llvm/Analysis/AssumptionCache.h"
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/KnownBits.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils/Local.h"

using namespace llvm;

static bool tryToImproveAlign(
    const DataLayout &DL, Instruction *I,
    function_ref<Align(Value *PtrOp, Align OldAlign, Align PrefAlign)> Fn) {

  if (auto *PtrOp = getLoadStorePointerOperand(I)) {
    Align OldAlign = getLoadStoreAlignment(I);
    Align PrefAlign = DL.getPrefTypeAlign(getLoadStoreType(I));

    Align NewAlign = Fn(PtrOp, OldAlign, PrefAlign);
    if (NewAlign > OldAlign) {
      setLoadStoreAlignment(I, NewAlign);
      return true;
    }
  }
  // TODO: Also handle memory intrinsics.
  return false;
}

bool inferAlignment(Function &F, AssumptionCache &AC, DominatorTree &DT) {
  const DataLayout &DL = F.getDataLayout();
  bool Changed = false;

  // Enforce preferred type alignment if possible. We do this as a separate
  // pass first, because it may improve the alignments we infer below.
  for (BasicBlock &BB : F) {
    for (Instruction &I : BB) {
      Changed |= tryToImproveAlign(
          DL, &I, [&](Value *PtrOp, Align OldAlign, Align PrefAlign) {
            if (PrefAlign > OldAlign)
              return std::max(OldAlign,
                              tryEnforceAlignment(PtrOp, PrefAlign, DL));
            return OldAlign;
          });
    }
  }

  // Compute alignment from known bits.
  for (BasicBlock &BB : F) {
    for (Instruction &I : BB) {
      Changed |= tryToImproveAlign(
          DL, &I, [&](Value *PtrOp, Align OldAlign, Align PrefAlign) {
            KnownBits Known = computeKnownBits(PtrOp, DL, &AC, &I, &DT);
            unsigned TrailZ = std::min(Known.countMinTrailingZeros(),
                                       +Value::MaxAlignmentExponent);
            return Align(1ull << std::min(Known.getBitWidth() - 1, TrailZ));
          });
    }
  }

  return Changed;
}

PreservedAnalyses InferAlignmentPass::run(Function &F,
                                          FunctionAnalysisManager &AM) {
  AssumptionCache &AC = AM.getResult<AssumptionAnalysis>(F);
  DominatorTree &DT = AM.getResult<DominatorTreeAnalysis>(F);
  inferAlignment(F, AC, DT);
  // Changes to alignment shouldn't invalidated analyses.
  return PreservedAnalyses::all();
}

; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt < %s -passes=instcombine -S | FileCheck %s
; RUN: opt < %s -passes=instcombine -use-constant-int-for-fixed-length-splat -S | FileCheck %s

target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64"

declare void @use16(i16)
declare void @use32(i32)

define i8 @testi8i8(i8 %add) {
; CHECK-LABEL: @testi8i8(
; CHECK-NEXT:    [[TMP1:%.*]] = icmp sgt i8 [[ADD:%.*]], -1
; CHECK-NEXT:    [[X:%.*]] = select i1 [[TMP1]], i8 127, i8 -128
; CHECK-NEXT:    ret i8 [[X]]
;
  %sh = ashr i8 %add, 7
  %x = xor i8 %sh, 127
  ret i8 %x
}

define i8 @testi16i8(i16 %add) {
; CHECK-LABEL: @testi16i8(
; CHECK-NEXT:    [[TMP1:%.*]] = icmp sgt i16 [[ADD:%.*]], -1
; CHECK-NEXT:    [[X:%.*]] = select i1 [[TMP1]], i8 27, i8 -28
; CHECK-NEXT:    ret i8 [[X]]
;
  %sh = ashr i16 %add, 15
  %t = trunc i16 %sh to i8
  %x = xor i8 %t, 27
  ret i8 %x
}

define i32 @testi64i32(i64 %add) {
; CHECK-LABEL: @testi64i32(
; CHECK-NEXT:    [[TMP1:%.*]] = icmp sgt i64 [[ADD:%.*]], -1
; CHECK-NEXT:    [[X:%.*]] = select i1 [[TMP1]], i32 127, i32 -128
; CHECK-NEXT:    ret i32 [[X]]
;
  %sh = ashr i64 %add, 63
  %t = trunc i64 %sh to i32
  %x = xor i32 %t, 127
  ret i32 %x
}

define i128 @testi128i128(i128 %add) {
; CHECK-LABEL: @testi128i128(
; CHECK-NEXT:    [[TMP1:%.*]] = icmp sgt i128 [[ADD:%.*]], -1
; CHECK-NEXT:    [[X:%.*]] = select i1 [[TMP1]], i128 27, i128 -28
; CHECK-NEXT:    ret i128 [[X]]
;
  %sh = ashr i128 %add, 127
  %x = xor i128 %sh, 27
  ret i128 %x
}

define <4 x i8> @testv4i16i8(<4 x i16> %add) {
; CHECK-LABEL: @testv4i16i8(
; CHECK-NEXT:    [[TMP1:%.*]] = icmp sgt <4 x i16> [[ADD:%.*]], splat (i16 -1)
; CHECK-NEXT:    [[X:%.*]] = select <4 x i1> [[TMP1]], <4 x i8> splat (i8 27), <4 x i8> splat (i8 -28)
; CHECK-NEXT:    ret <4 x i8> [[X]]
;
  %sh = ashr <4 x i16> %add, <i16 15, i16 15, i16 15, i16 15>
  %t = trunc <4 x i16> %sh to <4 x i8>
  %x = xor <4 x i8> %t, <i8 27, i8 27, i8 27, i8 27>
  ret <4 x i8> %x
}

define <4 x i8> @testv4i16i8_poison(<4 x i16> %add) {
; CHECK-LABEL: @testv4i16i8_poison(
; CHECK-NEXT:    [[TMP1:%.*]] = icmp sgt <4 x i16> [[ADD:%.*]], splat (i16 -1)
; CHECK-NEXT:    [[X:%.*]] = select <4 x i1> [[TMP1]], <4 x i8> <i8 27, i8 27, i8 poison, i8 27>, <4 x i8> <i8 -28, i8 -28, i8 poison, i8 -28>
; CHECK-NEXT:    ret <4 x i8> [[X]]
;
  %sh = ashr <4 x i16> %add, <i16 15, i16 poison, i16 15, i16 15>
  %t = trunc <4 x i16> %sh to <4 x i8>
  %x = xor <4 x i8> %t, <i8 27, i8 27, i8 poison, i8 27>
  ret <4 x i8> %x
}

; Negative tests

define i8 @wrongimm(i16 %add) {
; CHECK-LABEL: @wrongimm(
; CHECK-NEXT:    [[SH:%.*]] = ashr i16 [[ADD:%.*]], 14
; CHECK-NEXT:    [[T:%.*]] = trunc nsw i16 [[SH]] to i8
; CHECK-NEXT:    [[X:%.*]] = xor i8 [[T]], 27
; CHECK-NEXT:    ret i8 [[X]]
;
  %sh = ashr i16 %add, 14
  %t = trunc i16 %sh to i8
  %x = xor i8 %t, 27
  ret i8 %x
}

; PR52397 Some of the lanes of the xor/ashr are unused, becoming poison.
define <4 x i32> @vectorpoison(<6 x i32> %0) {
; CHECK-LABEL: @vectorpoison(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[ISNOTNEG:%.*]] = icmp sgt <6 x i32> [[TMP0:%.*]], splat (i32 -1)
; CHECK-NEXT:    [[SHR:%.*]] = sext <6 x i1> [[ISNOTNEG]] to <6 x i32>
; CHECK-NEXT:    [[TMP1:%.*]] = shufflevector <6 x i32> [[SHR]], <6 x i32> poison, <4 x i32> <i32 0, i32 1, i32 0, i32 2>
; CHECK-NEXT:    ret <4 x i32> [[TMP1]]
;
entry:
  %neg = xor <6 x i32> %0, <i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
  %shr = ashr <6 x i32> %neg, <i32 31, i32 31, i32 31, i32 31, i32 31, i32 31>
  %1 = shufflevector <6 x i32> %shr, <6 x i32> poison, <4 x i32> <i32 0, i32 1, i32 0, i32 2>
  ret <4 x i32> %1
}


; One use

define i16 @extrause(i16 %add) {
; CHECK-LABEL: @extrause(
; CHECK-NEXT:    [[SH:%.*]] = ashr i16 [[ADD:%.*]], 15
; CHECK-NEXT:    [[X:%.*]] = xor i16 [[SH]], 27
; CHECK-NEXT:    call void @use16(i16 [[SH]])
; CHECK-NEXT:    ret i16 [[X]]
;
  %sh = ashr i16 %add, 15
  %x = xor i16 %sh, 27
  call void @use16(i16 %sh)
  ret i16 %x
}

define i16 @extrause_trunc1(i32 %add) {
; CHECK-LABEL: @extrause_trunc1(
; CHECK-NEXT:    [[SH:%.*]] = ashr i32 [[ADD:%.*]], 31
; CHECK-NEXT:    call void @use32(i32 [[SH]])
; CHECK-NEXT:    [[TMP1:%.*]] = icmp sgt i32 [[ADD]], -1
; CHECK-NEXT:    [[X:%.*]] = select i1 [[TMP1]], i16 127, i16 -128
; CHECK-NEXT:    ret i16 [[X]]
;
  %sh = ashr i32 %add, 31
  %t = trunc i32 %sh to i16
  call void @use32(i32 %sh)
  %x = xor i16 %t, 127
  ret i16 %x
}

define i16 @extrause_trunc2(i32 %add) {
; CHECK-LABEL: @extrause_trunc2(
; CHECK-NEXT:    [[SH:%.*]] = ashr i32 [[ADD:%.*]], 31
; CHECK-NEXT:    [[T:%.*]] = trunc nsw i32 [[SH]] to i16
; CHECK-NEXT:    call void @use16(i16 [[T]])
; CHECK-NEXT:    [[X:%.*]] = xor i16 [[T]], 127
; CHECK-NEXT:    ret i16 [[X]]
;
  %sh = ashr i32 %add, 31
  %t = trunc i32 %sh to i16
  call void @use16(i16 %t)
  %x = xor i16 %t, 127
  ret i16 %x
}

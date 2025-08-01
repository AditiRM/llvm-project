; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -mtriple=aarch64-- | FileCheck %s --check-prefixes=CHECK,CHECK-SD
; RUN: llc < %s -mtriple=aarch64-- -global-isel | FileCheck %s --check-prefixes=CHECK,CHECK-GI

; Ensure chains of comparisons produce chains of `ccmp`

; (x0 < x1) && (x2 > x3)
define i32 @cmp_and2(i32 %0, i32 %1, i32 %2, i32 %3) {
; CHECK-SD-LABEL: cmp_and2:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    cmp w0, w1
; CHECK-SD-NEXT:    ccmp w2, w3, #0, lo
; CHECK-SD-NEXT:    cset w0, hi
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: cmp_and2:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    cmp w0, w1
; CHECK-GI-NEXT:    cset w8, lo
; CHECK-GI-NEXT:    cmp w2, w3
; CHECK-GI-NEXT:    cset w9, hi
; CHECK-GI-NEXT:    and w0, w8, w9
; CHECK-GI-NEXT:    ret
  %5 = icmp ult i32 %0, %1
  %6 = icmp ugt i32 %2, %3
  %7 = select i1 %5, i1 %6, i1 false
  %8 = zext i1 %7 to i32
  ret i32 %8
}

; (x0 < x1) && (x2 > x3) && (x4 != x5)
define i32 @cmp_and3(i32 %0, i32 %1, i32 %2, i32 %3, i32 %4, i32 %5) {
; CHECK-SD-LABEL: cmp_and3:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    cmp w0, w1
; CHECK-SD-NEXT:    ccmp w2, w3, #0, lo
; CHECK-SD-NEXT:    ccmp w4, w5, #4, hi
; CHECK-SD-NEXT:    cset w0, ne
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: cmp_and3:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    cmp w0, w1
; CHECK-GI-NEXT:    cset w8, lo
; CHECK-GI-NEXT:    cmp w2, w3
; CHECK-GI-NEXT:    cset w9, hi
; CHECK-GI-NEXT:    cmp w4, w5
; CHECK-GI-NEXT:    and w8, w8, w9
; CHECK-GI-NEXT:    cset w9, ne
; CHECK-GI-NEXT:    and w0, w8, w9
; CHECK-GI-NEXT:    ret
  %7 = icmp ult i32 %0, %1
  %8 = icmp ugt i32 %2, %3
  %9 = select i1 %7, i1 %8, i1 false
  %10 = icmp ne i32 %4, %5
  %11 = select i1 %9, i1 %10, i1 false
  %12 = zext i1 %11 to i32
  ret i32 %12
}

; (x0 < x1) && (x2 > x3) && (x4 != x5) && (x6 == x7)
define i32 @cmp_and4(i32 %0, i32 %1, i32 %2, i32 %3, i32 %4, i32 %5, i32 %6, i32 %7) {
; CHECK-SD-LABEL: cmp_and4:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    cmp w2, w3
; CHECK-SD-NEXT:    ccmp w0, w1, #2, hi
; CHECK-SD-NEXT:    ccmp w4, w5, #4, lo
; CHECK-SD-NEXT:    ccmp w6, w7, #0, ne
; CHECK-SD-NEXT:    cset w0, eq
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: cmp_and4:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    cmp w2, w3
; CHECK-GI-NEXT:    cset w8, hi
; CHECK-GI-NEXT:    cmp w0, w1
; CHECK-GI-NEXT:    cset w9, lo
; CHECK-GI-NEXT:    cmp w4, w5
; CHECK-GI-NEXT:    cset w10, ne
; CHECK-GI-NEXT:    cmp w6, w7
; CHECK-GI-NEXT:    and w8, w8, w9
; CHECK-GI-NEXT:    cset w11, eq
; CHECK-GI-NEXT:    and w9, w10, w11
; CHECK-GI-NEXT:    and w0, w8, w9
; CHECK-GI-NEXT:    ret
  %9 = icmp ugt i32 %2, %3
  %10 = icmp ult i32 %0, %1
  %11 = select i1 %9, i1 %10, i1 false
  %12 = icmp ne i32 %4, %5
  %13 = select i1 %11, i1 %12, i1 false
  %14 = icmp eq i32 %6, %7
  %15 = select i1 %13, i1 %14, i1 false
  %16 = zext i1 %15 to i32
  ret i32 %16
}

; (x0 < x1) || (x2 > x3)
define i32 @cmp_or2(i32 %0, i32 %1, i32 %2, i32 %3) {
; CHECK-SD-LABEL: cmp_or2:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    cmp w0, w1
; CHECK-SD-NEXT:    ccmp w2, w3, #0, hs
; CHECK-SD-NEXT:    cset w0, ne
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: cmp_or2:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    cmp w0, w1
; CHECK-GI-NEXT:    cset w8, lo
; CHECK-GI-NEXT:    cmp w2, w3
; CHECK-GI-NEXT:    cset w9, ne
; CHECK-GI-NEXT:    orr w8, w8, w9
; CHECK-GI-NEXT:    and w0, w8, #0x1
; CHECK-GI-NEXT:    ret
  %5 = icmp ult i32 %0, %1
  %6 = icmp ne i32 %2, %3
  %7 = select i1 %5, i1 true, i1 %6
  %8 = zext i1 %7 to i32
  ret i32 %8
}

; (x0 < x1) || (x2 > x3) || (x4 != x5)
define i32 @cmp_or3(i32 %0, i32 %1, i32 %2, i32 %3, i32 %4, i32 %5) {
; CHECK-SD-LABEL: cmp_or3:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    cmp w0, w1
; CHECK-SD-NEXT:    ccmp w2, w3, #2, hs
; CHECK-SD-NEXT:    ccmp w4, w5, #0, ls
; CHECK-SD-NEXT:    cset w0, ne
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: cmp_or3:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    cmp w0, w1
; CHECK-GI-NEXT:    cset w8, lo
; CHECK-GI-NEXT:    cmp w2, w3
; CHECK-GI-NEXT:    cset w9, hi
; CHECK-GI-NEXT:    cmp w4, w5
; CHECK-GI-NEXT:    orr w8, w8, w9
; CHECK-GI-NEXT:    cset w9, ne
; CHECK-GI-NEXT:    orr w8, w8, w9
; CHECK-GI-NEXT:    and w0, w8, #0x1
; CHECK-GI-NEXT:    ret
  %7 = icmp ult i32 %0, %1
  %8 = icmp ugt i32 %2, %3
  %9 = select i1 %7, i1 true, i1 %8
  %10 = icmp ne i32 %4, %5
  %11 = select i1 %9, i1 true, i1 %10
  %12 = zext i1 %11 to i32
 ret i32 %12
}

; (x0 < x1) || (x2 > x3) || (x4 != x5) || (x6 == x7)
define i32 @cmp_or4(i32 %0, i32 %1, i32 %2, i32 %3, i32 %4, i32 %5, i32 %6, i32 %7) {
; CHECK-SD-LABEL: cmp_or4:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    cmp w0, w1
; CHECK-SD-NEXT:    ccmp w2, w3, #2, hs
; CHECK-SD-NEXT:    ccmp w4, w5, #0, ls
; CHECK-SD-NEXT:    ccmp w6, w7, #4, eq
; CHECK-SD-NEXT:    cset w0, eq
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: cmp_or4:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    cmp w0, w1
; CHECK-GI-NEXT:    cset w8, lo
; CHECK-GI-NEXT:    cmp w2, w3
; CHECK-GI-NEXT:    cset w9, hi
; CHECK-GI-NEXT:    cmp w4, w5
; CHECK-GI-NEXT:    cset w10, ne
; CHECK-GI-NEXT:    cmp w6, w7
; CHECK-GI-NEXT:    orr w8, w8, w9
; CHECK-GI-NEXT:    cset w11, eq
; CHECK-GI-NEXT:    orr w9, w10, w11
; CHECK-GI-NEXT:    orr w8, w8, w9
; CHECK-GI-NEXT:    and w0, w8, #0x1
; CHECK-GI-NEXT:    ret
  %9 = icmp ult i32 %0, %1
  %10 = icmp ugt i32 %2, %3
  %11 = select i1 %9, i1 true, i1 %10
  %12 = icmp ne i32 %4, %5
  %13 = select i1 %11, i1 true, i1 %12
  %14 = icmp eq i32 %6, %7
  %15 = select i1 %13, i1 true, i1 %14
  %16 = zext i1 %15 to i32
  ret i32 %16
}

; (x0 != 0) || (x1 != 0)
define i32 @true_or2(i32 %0, i32 %1) {
; CHECK-SD-LABEL: true_or2:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    orr w8, w0, w1
; CHECK-SD-NEXT:    cmp w8, #0
; CHECK-SD-NEXT:    cset w0, ne
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: true_or2:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    cmp w0, #0
; CHECK-GI-NEXT:    cset w8, ne
; CHECK-GI-NEXT:    cmp w1, #0
; CHECK-GI-NEXT:    cset w9, ne
; CHECK-GI-NEXT:    orr w8, w8, w9
; CHECK-GI-NEXT:    and w0, w8, #0x1
; CHECK-GI-NEXT:    ret
  %3 = icmp ne i32 %0, 0
  %4 = icmp ne i32 %1, 0
  %5 = select i1 %3, i1 true, i1 %4
  %6 = zext i1 %5 to i32
  ret i32 %6
}

; (x0 != 0) || (x1 != 0) || (x2 != 0)
define i32 @true_or3(i32 %0, i32 %1, i32 %2) {
; CHECK-SD-LABEL: true_or3:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    orr w8, w0, w1
; CHECK-SD-NEXT:    orr w8, w8, w2
; CHECK-SD-NEXT:    cmp w8, #0
; CHECK-SD-NEXT:    cset w0, ne
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: true_or3:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    cmp w0, #0
; CHECK-GI-NEXT:    cset w8, ne
; CHECK-GI-NEXT:    cmp w1, #0
; CHECK-GI-NEXT:    cset w9, ne
; CHECK-GI-NEXT:    cmp w2, #0
; CHECK-GI-NEXT:    orr w8, w8, w9
; CHECK-GI-NEXT:    cset w9, ne
; CHECK-GI-NEXT:    orr w8, w8, w9
; CHECK-GI-NEXT:    and w0, w8, #0x1
; CHECK-GI-NEXT:    ret
  %4 = icmp ne i32 %0, 0
  %5 = icmp ne i32 %1, 0
  %6 = select i1 %4, i1 true, i1 %5
  %7 = icmp ne i32 %2, 0
  %8 = select i1 %6, i1 true, i1 %7
  %9 = zext i1 %8 to i32
  ret i32 %9
}

; (b > -3 && a < c)
define i32 @neg_range_int(i32 %a, i32 %b, i32 %c) {
; CHECK-LABEL: neg_range_int:
; CHECK:       // %bb.0:
; CHECK-NEXT:    cmp w0, w2
; CHECK-NEXT:    ccmn w1, #3, #4, lt
; CHECK-NEXT:    csel w0, w1, w0, gt
; CHECK-NEXT:    ret
  %cmp = icmp sgt i32 %b, -3
  %cmp1 = icmp slt i32 %a, %c
  %or.cond = and i1 %cmp, %cmp1
  %retval.0 = select i1 %or.cond, i32 %b, i32 %a
  ret i32 %retval.0
}

; (b > -(d | 1) && a < c)
define i32 @neg_range_int_comp(i32 %a, i32 %b, i32 %c, i32 %d) {
; CHECK-SD-LABEL: neg_range_int_comp:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    orr w8, w3, #0x1
; CHECK-SD-NEXT:    cmp w0, w2
; CHECK-SD-NEXT:    ccmn w1, w8, #4, lt
; CHECK-SD-NEXT:    csel w0, w1, w0, gt
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: neg_range_int_comp:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    orr w8, w3, #0x1
; CHECK-GI-NEXT:    cmp w0, w2
; CHECK-GI-NEXT:    neg w8, w8
; CHECK-GI-NEXT:    ccmp w1, w8, #4, lt
; CHECK-GI-NEXT:    csel w0, w1, w0, gt
; CHECK-GI-NEXT:    ret
  %dor = or i32 %d, 1
  %negd = sub i32 0, %dor
  %cmp = icmp sgt i32 %b, %negd
  %cmp1 = icmp slt i32 %a, %c
  %or.cond = and i1 %cmp, %cmp1
  %retval.0 = select i1 %or.cond, i32 %b, i32 %a
  ret i32 %retval.0
}

; (b >u -(d | 1) && a < c)
define i32 @neg_range_int_comp_u(i32 %a, i32 %b, i32 %c, i32 %d) {
; CHECK-SD-LABEL: neg_range_int_comp_u:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    orr w8, w3, #0x1
; CHECK-SD-NEXT:    cmp w0, w2
; CHECK-SD-NEXT:    ccmn w1, w8, #0, lt
; CHECK-SD-NEXT:    csel w0, w1, w0, hi
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: neg_range_int_comp_u:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    orr w8, w3, #0x1
; CHECK-GI-NEXT:    cmp w0, w2
; CHECK-GI-NEXT:    neg w8, w8
; CHECK-GI-NEXT:    ccmp w1, w8, #0, lt
; CHECK-GI-NEXT:    csel w0, w1, w0, hi
; CHECK-GI-NEXT:    ret
  %dor = or i32 %d, 1
  %negd = sub i32 0, %dor
  %cmp = icmp ugt i32 %b, %negd
  %cmp1 = icmp slt i32 %a, %c
  %or.cond = and i1 %cmp, %cmp1
  %retval.0 = select i1 %or.cond, i32 %b, i32 %a
  ret i32 %retval.0
}

; (b > -(d | 1) && a u < c)
define i32 @neg_range_int_comp_ua(i32 %a, i32 %b, i32 %c, i32 %d) {
; CHECK-SD-LABEL: neg_range_int_comp_ua:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    orr w8, w3, #0x1
; CHECK-SD-NEXT:    cmp w0, w2
; CHECK-SD-NEXT:    ccmn w1, w8, #4, lo
; CHECK-SD-NEXT:    csel w0, w1, w0, gt
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: neg_range_int_comp_ua:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    orr w8, w3, #0x1
; CHECK-GI-NEXT:    cmp w0, w2
; CHECK-GI-NEXT:    neg w8, w8
; CHECK-GI-NEXT:    ccmp w1, w8, #4, lo
; CHECK-GI-NEXT:    csel w0, w1, w0, gt
; CHECK-GI-NEXT:    ret
  %dor = or i32 %d, 1
  %negd = sub i32 0, %dor
  %cmp = icmp sgt i32 %b, %negd
  %cmp1 = icmp ult i32 %a, %c
  %or.cond = and i1 %cmp, %cmp1
  %retval.0 = select i1 %or.cond, i32 %b, i32 %a
  ret i32 %retval.0
}

; (b <= -3 && a > c)
define i32 @neg_range_int_2(i32 %a, i32 %b, i32 %c) {
; CHECK-SD-LABEL: neg_range_int_2:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    cmp w0, w2
; CHECK-SD-NEXT:    ccmn w1, #4, #4, gt
; CHECK-SD-NEXT:    csel w0, w1, w0, gt
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: neg_range_int_2:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    cmp w0, w2
; CHECK-GI-NEXT:    ccmn w1, #3, #8, gt
; CHECK-GI-NEXT:    csel w0, w1, w0, ge
; CHECK-GI-NEXT:    ret
  %cmp = icmp sge i32 %b, -3
  %cmp1 = icmp sgt i32 %a, %c
  %or.cond = and i1 %cmp, %cmp1
  %retval.0 = select i1 %or.cond, i32 %b, i32 %a
  ret i32 %retval.0
}

; (b < -(d | 1) && a >= c)
define i32 @neg_range_int_comp2(i32 %a, i32 %b, i32 %c, i32 %d) {
; CHECK-SD-LABEL: neg_range_int_comp2:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    orr w8, w3, #0x1
; CHECK-SD-NEXT:    cmp w0, w2
; CHECK-SD-NEXT:    ccmn w1, w8, #0, ge
; CHECK-SD-NEXT:    csel w0, w1, w0, lt
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: neg_range_int_comp2:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    orr w8, w3, #0x1
; CHECK-GI-NEXT:    cmp w0, w2
; CHECK-GI-NEXT:    neg w8, w8
; CHECK-GI-NEXT:    ccmp w1, w8, #0, ge
; CHECK-GI-NEXT:    csel w0, w1, w0, lt
; CHECK-GI-NEXT:    ret
  %dor = or i32 %d, 1
  %negd = sub i32 0, %dor
  %cmp = icmp slt i32 %b, %negd
  %cmp1 = icmp sge i32 %a, %c
  %or.cond = and i1 %cmp, %cmp1
  %retval.0 = select i1 %or.cond, i32 %b, i32 %a
  ret i32 %retval.0
}

; (b <u -(d | 1) && a > c)
define i32 @neg_range_int_comp_u2(i32 %a, i32 %b, i32 %c, i32 %d) {
; CHECK-SD-LABEL: neg_range_int_comp_u2:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    orr w8, w3, #0x1
; CHECK-SD-NEXT:    cmp w0, w2
; CHECK-SD-NEXT:    ccmn w1, w8, #2, gt
; CHECK-SD-NEXT:    csel w0, w1, w0, lo
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: neg_range_int_comp_u2:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    orr w8, w3, #0x1
; CHECK-GI-NEXT:    cmp w0, w2
; CHECK-GI-NEXT:    neg w8, w8
; CHECK-GI-NEXT:    ccmp w1, w8, #2, gt
; CHECK-GI-NEXT:    csel w0, w1, w0, lo
; CHECK-GI-NEXT:    ret
  %dor = or i32 %d, 1
  %negd = sub i32 0, %dor
  %cmp = icmp ult i32 %b, %negd
  %cmp1 = icmp sgt i32 %a, %c
  %or.cond = and i1 %cmp, %cmp1
  %retval.0 = select i1 %or.cond, i32 %b, i32 %a
  ret i32 %retval.0
}

; (b > -(d | 1) && a u > c)
define i32 @neg_range_int_comp_ua2(i32 %a, i32 %b, i32 %c, i32 %d) {
; CHECK-SD-LABEL: neg_range_int_comp_ua2:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    orr w8, w3, #0x1
; CHECK-SD-NEXT:    cmp w0, w2
; CHECK-SD-NEXT:    ccmn w1, w8, #4, hi
; CHECK-SD-NEXT:    csel w0, w1, w0, gt
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: neg_range_int_comp_ua2:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    orr w8, w3, #0x1
; CHECK-GI-NEXT:    cmp w0, w2
; CHECK-GI-NEXT:    neg w8, w8
; CHECK-GI-NEXT:    ccmp w1, w8, #4, hi
; CHECK-GI-NEXT:    csel w0, w1, w0, gt
; CHECK-GI-NEXT:    ret
  %dor = or i32 %d, 1
  %negd = sub i32 0, %dor
  %cmp = icmp sgt i32 %b, %negd
  %cmp1 = icmp ugt i32 %a, %c
  %or.cond = and i1 %cmp, %cmp1
  %retval.0 = select i1 %or.cond, i32 %b, i32 %a
  ret i32 %retval.0
}

; (b > -(d | 1) && a u == c)
define i32 @neg_range_int_comp_ua3(i32 %a, i32 %b, i32 %c, i32 %d) {
; CHECK-SD-LABEL: neg_range_int_comp_ua3:
; CHECK-SD:       // %bb.0:
; CHECK-SD-NEXT:    orr w8, w3, #0x1
; CHECK-SD-NEXT:    cmp w0, w2
; CHECK-SD-NEXT:    ccmn w1, w8, #4, eq
; CHECK-SD-NEXT:    csel w0, w1, w0, gt
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: neg_range_int_comp_ua3:
; CHECK-GI:       // %bb.0:
; CHECK-GI-NEXT:    orr w8, w3, #0x1
; CHECK-GI-NEXT:    cmp w0, w2
; CHECK-GI-NEXT:    neg w8, w8
; CHECK-GI-NEXT:    ccmp w1, w8, #4, eq
; CHECK-GI-NEXT:    csel w0, w1, w0, gt
; CHECK-GI-NEXT:    ret
  %dor = or i32 %d, 1
  %negd = sub i32 0, %dor
  %cmp = icmp sgt i32 %b, %negd
  %cmp1 = icmp eq i32 %a, %c
  %or.cond = and i1 %cmp, %cmp1
  %retval.0 = select i1 %or.cond, i32 %b, i32 %a
  ret i32 %retval.0
}

; -(a | 1) > (b | 3) && a < c
define i32 @neg_range_int_c(i32 %a, i32 %b, i32 %c) {
; CHECK-SD-LABEL: neg_range_int_c:
; CHECK-SD:       // %bb.0: // %entry
; CHECK-SD-NEXT:    orr w8, w0, #0x1
; CHECK-SD-NEXT:    orr w9, w1, #0x3
; CHECK-SD-NEXT:    cmn w9, w8
; CHECK-SD-NEXT:    ccmp w2, w0, #2, lo
; CHECK-SD-NEXT:    cset w0, lo
; CHECK-SD-NEXT:    ret
;
; CHECK-GI-LABEL: neg_range_int_c:
; CHECK-GI:       // %bb.0: // %entry
; CHECK-GI-NEXT:    orr w8, w0, #0x1
; CHECK-GI-NEXT:    orr w9, w1, #0x3
; CHECK-GI-NEXT:    neg w8, w8
; CHECK-GI-NEXT:    cmp w9, w8
; CHECK-GI-NEXT:    cset w8, lo
; CHECK-GI-NEXT:    cmp w2, w0
; CHECK-GI-NEXT:    cset w9, lo
; CHECK-GI-NEXT:    and w0, w8, w9
; CHECK-GI-NEXT:    ret
entry:
  %or = or i32 %a, 1
  %sub = sub i32 0, %or
  %or1 = or i32 %b, 3
  %cmp = icmp ult i32 %or1, %sub
  %cmp2 = icmp ult i32 %c, %a
  %0 = and i1 %cmp, %cmp2
  %land.ext = zext i1 %0 to i32
  ret i32 %land.ext
}

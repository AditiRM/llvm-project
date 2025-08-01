; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py UTC_ARGS: --version 5
; RUN: llc < %s | FileCheck -check-prefix=ENABLED %s
; RUN: llc -disable-nvptx-load-store-vectorizer < %s | FileCheck -check-prefix=DISABLED %s
; RUN: %if ptxas %{ llc < %s | %ptxas-verify %}
; RUN: %if ptxas %{ llc -disable-nvptx-load-store-vectorizer < %s | %ptxas-verify %}

target triple = "nvptx64-nvidia-cuda"

; Check that the load-store vectorizer is enabled by default for nvptx, and
; that it's disabled by the appropriate flag.

define i32 @f(ptr %p) {
; ENABLED-LABEL: f(
; ENABLED:       {
; ENABLED-NEXT:    .reg .b32 %r<4>;
; ENABLED-NEXT:    .reg .b64 %rd<2>;
; ENABLED-EMPTY:
; ENABLED-NEXT:  // %bb.0:
; ENABLED-NEXT:    ld.param.b64 %rd1, [f_param_0];
; ENABLED-NEXT:    ld.v2.b32 {%r1, %r2}, [%rd1];
; ENABLED-NEXT:    add.s32 %r3, %r1, %r2;
; ENABLED-NEXT:    st.param.b32 [func_retval0], %r3;
; ENABLED-NEXT:    ret;
;
; DISABLED-LABEL: f(
; DISABLED:       {
; DISABLED-NEXT:    .reg .b32 %r<4>;
; DISABLED-NEXT:    .reg .b64 %rd<2>;
; DISABLED-EMPTY:
; DISABLED-NEXT:  // %bb.0:
; DISABLED-NEXT:    ld.param.b64 %rd1, [f_param_0];
; DISABLED-NEXT:    ld.b32 %r1, [%rd1];
; DISABLED-NEXT:    ld.b32 %r2, [%rd1+4];
; DISABLED-NEXT:    add.s32 %r3, %r1, %r2;
; DISABLED-NEXT:    st.param.b32 [func_retval0], %r3;
; DISABLED-NEXT:    ret;
  %p.1 = getelementptr i32, ptr %p, i32 1
  %v0 = load i32, ptr %p, align 8
  %v1 = load i32, ptr %p.1, align 4
  %sum = add i32 %v0, %v1
  ret i32 %sum
}

define half @fh(ptr %p) {
; ENABLED-LABEL: fh(
; ENABLED:       {
; ENABLED-NEXT:    .reg .b16 %rs<10>;
; ENABLED-NEXT:    .reg .b32 %r<13>;
; ENABLED-NEXT:    .reg .b64 %rd<2>;
; ENABLED-EMPTY:
; ENABLED-NEXT:  // %bb.0:
; ENABLED-NEXT:    ld.param.b64 %rd1, [fh_param_0];
; ENABLED-NEXT:    ld.v4.b16 {%rs1, %rs2, %rs3, %rs4}, [%rd1];
; ENABLED-NEXT:    ld.b16 %rs5, [%rd1+8];
; ENABLED-NEXT:    cvt.f32.f16 %r1, %rs2;
; ENABLED-NEXT:    cvt.f32.f16 %r2, %rs1;
; ENABLED-NEXT:    add.rn.f32 %r3, %r2, %r1;
; ENABLED-NEXT:    cvt.rn.f16.f32 %rs6, %r3;
; ENABLED-NEXT:    cvt.f32.f16 %r4, %rs4;
; ENABLED-NEXT:    cvt.f32.f16 %r5, %rs3;
; ENABLED-NEXT:    add.rn.f32 %r6, %r5, %r4;
; ENABLED-NEXT:    cvt.rn.f16.f32 %rs7, %r6;
; ENABLED-NEXT:    cvt.f32.f16 %r7, %rs7;
; ENABLED-NEXT:    cvt.f32.f16 %r8, %rs6;
; ENABLED-NEXT:    add.rn.f32 %r9, %r8, %r7;
; ENABLED-NEXT:    cvt.rn.f16.f32 %rs8, %r9;
; ENABLED-NEXT:    cvt.f32.f16 %r10, %rs8;
; ENABLED-NEXT:    cvt.f32.f16 %r11, %rs5;
; ENABLED-NEXT:    add.rn.f32 %r12, %r10, %r11;
; ENABLED-NEXT:    cvt.rn.f16.f32 %rs9, %r12;
; ENABLED-NEXT:    st.param.b16 [func_retval0], %rs9;
; ENABLED-NEXT:    ret;
;
; DISABLED-LABEL: fh(
; DISABLED:       {
; DISABLED-NEXT:    .reg .b16 %rs<10>;
; DISABLED-NEXT:    .reg .b32 %r<13>;
; DISABLED-NEXT:    .reg .b64 %rd<2>;
; DISABLED-EMPTY:
; DISABLED-NEXT:  // %bb.0:
; DISABLED-NEXT:    ld.param.b64 %rd1, [fh_param_0];
; DISABLED-NEXT:    ld.b16 %rs1, [%rd1];
; DISABLED-NEXT:    ld.b16 %rs2, [%rd1+2];
; DISABLED-NEXT:    ld.b16 %rs3, [%rd1+4];
; DISABLED-NEXT:    ld.b16 %rs4, [%rd1+6];
; DISABLED-NEXT:    ld.b16 %rs5, [%rd1+8];
; DISABLED-NEXT:    cvt.f32.f16 %r1, %rs2;
; DISABLED-NEXT:    cvt.f32.f16 %r2, %rs1;
; DISABLED-NEXT:    add.rn.f32 %r3, %r2, %r1;
; DISABLED-NEXT:    cvt.rn.f16.f32 %rs6, %r3;
; DISABLED-NEXT:    cvt.f32.f16 %r4, %rs4;
; DISABLED-NEXT:    cvt.f32.f16 %r5, %rs3;
; DISABLED-NEXT:    add.rn.f32 %r6, %r5, %r4;
; DISABLED-NEXT:    cvt.rn.f16.f32 %rs7, %r6;
; DISABLED-NEXT:    cvt.f32.f16 %r7, %rs7;
; DISABLED-NEXT:    cvt.f32.f16 %r8, %rs6;
; DISABLED-NEXT:    add.rn.f32 %r9, %r8, %r7;
; DISABLED-NEXT:    cvt.rn.f16.f32 %rs8, %r9;
; DISABLED-NEXT:    cvt.f32.f16 %r10, %rs8;
; DISABLED-NEXT:    cvt.f32.f16 %r11, %rs5;
; DISABLED-NEXT:    add.rn.f32 %r12, %r10, %r11;
; DISABLED-NEXT:    cvt.rn.f16.f32 %rs9, %r12;
; DISABLED-NEXT:    st.param.b16 [func_retval0], %rs9;
; DISABLED-NEXT:    ret;
  %p.1 = getelementptr half, ptr %p, i32 1
  %p.2 = getelementptr half, ptr %p, i32 2
  %p.3 = getelementptr half, ptr %p, i32 3
  %p.4 = getelementptr half, ptr %p, i32 4
  %v0 = load half, ptr %p, align 64
  %v1 = load half, ptr %p.1, align 4
  %v2 = load half, ptr %p.2, align 4
  %v3 = load half, ptr %p.3, align 4
  %v4 = load half, ptr %p.4, align 4
  %sum1 = fadd half %v0, %v1
  %sum2 = fadd half %v2, %v3
  %sum3 = fadd half %sum1, %sum2
  %sum = fadd half %sum3, %v4
  ret half %sum
}

define float @ff(ptr %p) {
; ENABLED-LABEL: ff(
; ENABLED:       {
; ENABLED-NEXT:    .reg .b32 %r<10>;
; ENABLED-NEXT:    .reg .b64 %rd<2>;
; ENABLED-EMPTY:
; ENABLED-NEXT:  // %bb.0:
; ENABLED-NEXT:    ld.param.b64 %rd1, [ff_param_0];
; ENABLED-NEXT:    ld.v4.b32 {%r1, %r2, %r3, %r4}, [%rd1];
; ENABLED-NEXT:    ld.b32 %r5, [%rd1+16];
; ENABLED-NEXT:    add.rn.f32 %r6, %r1, %r2;
; ENABLED-NEXT:    add.rn.f32 %r7, %r3, %r4;
; ENABLED-NEXT:    add.rn.f32 %r8, %r6, %r7;
; ENABLED-NEXT:    add.rn.f32 %r9, %r8, %r5;
; ENABLED-NEXT:    st.param.b32 [func_retval0], %r9;
; ENABLED-NEXT:    ret;
;
; DISABLED-LABEL: ff(
; DISABLED:       {
; DISABLED-NEXT:    .reg .b32 %r<10>;
; DISABLED-NEXT:    .reg .b64 %rd<2>;
; DISABLED-EMPTY:
; DISABLED-NEXT:  // %bb.0:
; DISABLED-NEXT:    ld.param.b64 %rd1, [ff_param_0];
; DISABLED-NEXT:    ld.b32 %r1, [%rd1];
; DISABLED-NEXT:    ld.b32 %r2, [%rd1+4];
; DISABLED-NEXT:    ld.b32 %r3, [%rd1+8];
; DISABLED-NEXT:    ld.b32 %r4, [%rd1+12];
; DISABLED-NEXT:    ld.b32 %r5, [%rd1+16];
; DISABLED-NEXT:    add.rn.f32 %r6, %r1, %r2;
; DISABLED-NEXT:    add.rn.f32 %r7, %r3, %r4;
; DISABLED-NEXT:    add.rn.f32 %r8, %r6, %r7;
; DISABLED-NEXT:    add.rn.f32 %r9, %r8, %r5;
; DISABLED-NEXT:    st.param.b32 [func_retval0], %r9;
; DISABLED-NEXT:    ret;
  %p.1 = getelementptr float, ptr %p, i32 1
  %p.2 = getelementptr float, ptr %p, i32 2
  %p.3 = getelementptr float, ptr %p, i32 3
  %p.4 = getelementptr float, ptr %p, i32 4
  %v0 = load float, ptr %p, align 64
  %v1 = load float, ptr %p.1, align 4
  %v2 = load float, ptr %p.2, align 4
  %v3 = load float, ptr %p.3, align 4
  %v4 = load float, ptr %p.4, align 4
  %sum1 = fadd float %v0, %v1
  %sum2 = fadd float %v2, %v3
  %sum3 = fadd float %sum1, %sum2
  %sum = fadd float %sum3, %v4
  ret float %sum
}

define void @combine_v16i8(ptr noundef align 16 %ptr1, ptr noundef align 16 %ptr2) {
; ENABLED-LABEL: combine_v16i8(
; ENABLED:       {
; ENABLED-NEXT:    .reg .b32 %r<36>;
; ENABLED-NEXT:    .reg .b64 %rd<3>;
; ENABLED-EMPTY:
; ENABLED-NEXT:  // %bb.0:
; ENABLED-NEXT:    ld.param.b64 %rd1, [combine_v16i8_param_0];
; ENABLED-NEXT:    ld.v4.b32 {%r1, %r2, %r3, %r4}, [%rd1];
; ENABLED-NEXT:    prmt.b32 %r5, %r4, 0, 0x7773U;
; ENABLED-NEXT:    prmt.b32 %r6, %r4, 0, 0x7772U;
; ENABLED-NEXT:    prmt.b32 %r7, %r4, 0, 0x7771U;
; ENABLED-NEXT:    prmt.b32 %r8, %r3, 0, 0x7773U;
; ENABLED-NEXT:    prmt.b32 %r9, %r3, 0, 0x7772U;
; ENABLED-NEXT:    prmt.b32 %r10, %r3, 0, 0x7771U;
; ENABLED-NEXT:    prmt.b32 %r11, %r2, 0, 0x7773U;
; ENABLED-NEXT:    prmt.b32 %r12, %r2, 0, 0x7772U;
; ENABLED-NEXT:    prmt.b32 %r13, %r2, 0, 0x7771U;
; ENABLED-NEXT:    prmt.b32 %r14, %r1, 0, 0x7773U;
; ENABLED-NEXT:    prmt.b32 %r15, %r1, 0, 0x7772U;
; ENABLED-NEXT:    prmt.b32 %r16, %r1, 0, 0x7771U;
; ENABLED-NEXT:    ld.param.b64 %rd2, [combine_v16i8_param_1];
; ENABLED-NEXT:    and.b32 %r17, %r1, 255;
; ENABLED-NEXT:    and.b32 %r18, %r2, 255;
; ENABLED-NEXT:    and.b32 %r19, %r3, 255;
; ENABLED-NEXT:    and.b32 %r20, %r4, 255;
; ENABLED-NEXT:    add.s32 %r21, %r17, %r16;
; ENABLED-NEXT:    add.s32 %r22, %r21, %r15;
; ENABLED-NEXT:    add.s32 %r23, %r22, %r14;
; ENABLED-NEXT:    add.s32 %r24, %r23, %r18;
; ENABLED-NEXT:    add.s32 %r25, %r24, %r13;
; ENABLED-NEXT:    add.s32 %r26, %r25, %r12;
; ENABLED-NEXT:    add.s32 %r27, %r26, %r11;
; ENABLED-NEXT:    add.s32 %r28, %r27, %r19;
; ENABLED-NEXT:    add.s32 %r29, %r28, %r10;
; ENABLED-NEXT:    add.s32 %r30, %r29, %r9;
; ENABLED-NEXT:    add.s32 %r31, %r30, %r8;
; ENABLED-NEXT:    add.s32 %r32, %r31, %r20;
; ENABLED-NEXT:    add.s32 %r33, %r32, %r7;
; ENABLED-NEXT:    add.s32 %r34, %r33, %r6;
; ENABLED-NEXT:    add.s32 %r35, %r34, %r5;
; ENABLED-NEXT:    st.b32 [%rd2], %r35;
; ENABLED-NEXT:    ret;
;
; DISABLED-LABEL: combine_v16i8(
; DISABLED:       {
; DISABLED-NEXT:    .reg .b32 %r<32>;
; DISABLED-NEXT:    .reg .b64 %rd<3>;
; DISABLED-EMPTY:
; DISABLED-NEXT:  // %bb.0:
; DISABLED-NEXT:    ld.param.b64 %rd1, [combine_v16i8_param_0];
; DISABLED-NEXT:    ld.b8 %r1, [%rd1];
; DISABLED-NEXT:    ld.param.b64 %rd2, [combine_v16i8_param_1];
; DISABLED-NEXT:    ld.b8 %r2, [%rd1+1];
; DISABLED-NEXT:    ld.b8 %r3, [%rd1+2];
; DISABLED-NEXT:    ld.b8 %r4, [%rd1+3];
; DISABLED-NEXT:    ld.b8 %r5, [%rd1+4];
; DISABLED-NEXT:    ld.b8 %r6, [%rd1+5];
; DISABLED-NEXT:    ld.b8 %r7, [%rd1+6];
; DISABLED-NEXT:    ld.b8 %r8, [%rd1+7];
; DISABLED-NEXT:    ld.b8 %r9, [%rd1+8];
; DISABLED-NEXT:    ld.b8 %r10, [%rd1+9];
; DISABLED-NEXT:    ld.b8 %r11, [%rd1+10];
; DISABLED-NEXT:    ld.b8 %r12, [%rd1+11];
; DISABLED-NEXT:    ld.b8 %r13, [%rd1+12];
; DISABLED-NEXT:    ld.b8 %r14, [%rd1+13];
; DISABLED-NEXT:    ld.b8 %r15, [%rd1+14];
; DISABLED-NEXT:    ld.b8 %r16, [%rd1+15];
; DISABLED-NEXT:    add.s32 %r17, %r1, %r2;
; DISABLED-NEXT:    add.s32 %r18, %r17, %r3;
; DISABLED-NEXT:    add.s32 %r19, %r18, %r4;
; DISABLED-NEXT:    add.s32 %r20, %r19, %r5;
; DISABLED-NEXT:    add.s32 %r21, %r20, %r6;
; DISABLED-NEXT:    add.s32 %r22, %r21, %r7;
; DISABLED-NEXT:    add.s32 %r23, %r22, %r8;
; DISABLED-NEXT:    add.s32 %r24, %r23, %r9;
; DISABLED-NEXT:    add.s32 %r25, %r24, %r10;
; DISABLED-NEXT:    add.s32 %r26, %r25, %r11;
; DISABLED-NEXT:    add.s32 %r27, %r26, %r12;
; DISABLED-NEXT:    add.s32 %r28, %r27, %r13;
; DISABLED-NEXT:    add.s32 %r29, %r28, %r14;
; DISABLED-NEXT:    add.s32 %r30, %r29, %r15;
; DISABLED-NEXT:    add.s32 %r31, %r30, %r16;
; DISABLED-NEXT:    st.b32 [%rd2], %r31;
; DISABLED-NEXT:    ret;
  %val0 = load i8, ptr %ptr1, align 16
  %ptr1.1 = getelementptr inbounds i8, ptr %ptr1, i64 1
  %val1 = load i8, ptr %ptr1.1, align 1
  %ptr1.2 = getelementptr inbounds i8, ptr %ptr1, i64 2
  %val2 = load i8, ptr %ptr1.2, align 2
  %ptr1.3 = getelementptr inbounds i8, ptr %ptr1, i64 3
  %val3 = load i8, ptr %ptr1.3, align 1
  %ptr1.4 = getelementptr inbounds i8, ptr %ptr1, i64 4
  %val4 = load i8, ptr %ptr1.4, align 4
  %ptr1.5 = getelementptr inbounds i8, ptr %ptr1, i64 5
  %val5 = load i8, ptr %ptr1.5, align 1
  %ptr1.6 = getelementptr inbounds i8, ptr %ptr1, i64 6
  %val6 = load i8, ptr %ptr1.6, align 2
  %ptr1.7 = getelementptr inbounds i8, ptr %ptr1, i64 7
  %val7 = load i8, ptr %ptr1.7, align 1
  %ptr1.8 = getelementptr inbounds i8, ptr %ptr1, i64 8
  %val8 = load i8, ptr %ptr1.8, align 8
  %ptr1.9 = getelementptr inbounds i8, ptr %ptr1, i64 9
  %val9 = load i8, ptr %ptr1.9, align 1
  %ptr1.10 = getelementptr inbounds i8, ptr %ptr1, i64 10
  %val10 = load i8, ptr %ptr1.10, align 2
  %ptr1.11 = getelementptr inbounds i8, ptr %ptr1, i64 11
  %val11 = load i8, ptr %ptr1.11, align 1
  %ptr1.12 = getelementptr inbounds i8, ptr %ptr1, i64 12
  %val12 = load i8, ptr %ptr1.12, align 4
  %ptr1.13 = getelementptr inbounds i8, ptr %ptr1, i64 13
  %val13 = load i8, ptr %ptr1.13, align 1
  %ptr1.14 = getelementptr inbounds i8, ptr %ptr1, i64 14
  %val14 = load i8, ptr %ptr1.14, align 2
  %ptr1.15 = getelementptr inbounds i8, ptr %ptr1, i64 15
  %val15 = load i8, ptr %ptr1.15, align 1
  %lane0 = zext i8 %val0 to i32
  %lane1 = zext i8 %val1 to i32
  %lane2 = zext i8 %val2 to i32
  %lane3 = zext i8 %val3 to i32
  %lane4 = zext i8 %val4 to i32
  %lane5 = zext i8 %val5 to i32
  %lane6 = zext i8 %val6 to i32
  %lane7 = zext i8 %val7 to i32
  %lane8 = zext i8 %val8 to i32
  %lane9 = zext i8 %val9 to i32
  %lane10 = zext i8 %val10 to i32
  %lane11 = zext i8 %val11 to i32
  %lane12 = zext i8 %val12 to i32
  %lane13 = zext i8 %val13 to i32
  %lane14 = zext i8 %val14 to i32
  %lane15 = zext i8 %val15 to i32
  %red.1 = add i32 %lane0, %lane1
  %red.2 = add i32 %red.1, %lane2
  %red.3 = add i32 %red.2, %lane3
  %red.4 = add i32 %red.3, %lane4
  %red.5 = add i32 %red.4, %lane5
  %red.6 = add i32 %red.5, %lane6
  %red.7 = add i32 %red.6, %lane7
  %red.8 = add i32 %red.7, %lane8
  %red.9 = add i32 %red.8, %lane9
  %red.10 = add i32 %red.9, %lane10
  %red.11 = add i32 %red.10, %lane11
  %red.12 = add i32 %red.11, %lane12
  %red.13 = add i32 %red.12, %lane13
  %red.14 = add i32 %red.13, %lane14
  %red = add i32 %red.14, %lane15
  store i32 %red, ptr %ptr2, align 4
  ret void
}

define void @combine_v16i8_unaligned(ptr noundef align 8 %ptr1, ptr noundef align 16 %ptr2) {
; ENABLED-LABEL: combine_v16i8_unaligned(
; ENABLED:       {
; ENABLED-NEXT:    .reg .b32 %r<36>;
; ENABLED-NEXT:    .reg .b64 %rd<3>;
; ENABLED-EMPTY:
; ENABLED-NEXT:  // %bb.0:
; ENABLED-NEXT:    ld.param.b64 %rd1, [combine_v16i8_unaligned_param_0];
; ENABLED-NEXT:    ld.v2.b32 {%r1, %r2}, [%rd1];
; ENABLED-NEXT:    prmt.b32 %r3, %r2, 0, 0x7773U;
; ENABLED-NEXT:    prmt.b32 %r4, %r2, 0, 0x7772U;
; ENABLED-NEXT:    prmt.b32 %r5, %r2, 0, 0x7771U;
; ENABLED-NEXT:    prmt.b32 %r6, %r1, 0, 0x7773U;
; ENABLED-NEXT:    prmt.b32 %r7, %r1, 0, 0x7772U;
; ENABLED-NEXT:    prmt.b32 %r8, %r1, 0, 0x7771U;
; ENABLED-NEXT:    ld.param.b64 %rd2, [combine_v16i8_unaligned_param_1];
; ENABLED-NEXT:    ld.v2.b32 {%r9, %r10}, [%rd1+8];
; ENABLED-NEXT:    prmt.b32 %r11, %r10, 0, 0x7773U;
; ENABLED-NEXT:    prmt.b32 %r12, %r10, 0, 0x7772U;
; ENABLED-NEXT:    prmt.b32 %r13, %r10, 0, 0x7771U;
; ENABLED-NEXT:    prmt.b32 %r14, %r9, 0, 0x7773U;
; ENABLED-NEXT:    prmt.b32 %r15, %r9, 0, 0x7772U;
; ENABLED-NEXT:    prmt.b32 %r16, %r9, 0, 0x7771U;
; ENABLED-NEXT:    and.b32 %r17, %r1, 255;
; ENABLED-NEXT:    and.b32 %r18, %r2, 255;
; ENABLED-NEXT:    and.b32 %r19, %r9, 255;
; ENABLED-NEXT:    and.b32 %r20, %r10, 255;
; ENABLED-NEXT:    add.s32 %r21, %r17, %r8;
; ENABLED-NEXT:    add.s32 %r22, %r21, %r7;
; ENABLED-NEXT:    add.s32 %r23, %r22, %r6;
; ENABLED-NEXT:    add.s32 %r24, %r23, %r18;
; ENABLED-NEXT:    add.s32 %r25, %r24, %r5;
; ENABLED-NEXT:    add.s32 %r26, %r25, %r4;
; ENABLED-NEXT:    add.s32 %r27, %r26, %r3;
; ENABLED-NEXT:    add.s32 %r28, %r27, %r19;
; ENABLED-NEXT:    add.s32 %r29, %r28, %r16;
; ENABLED-NEXT:    add.s32 %r30, %r29, %r15;
; ENABLED-NEXT:    add.s32 %r31, %r30, %r14;
; ENABLED-NEXT:    add.s32 %r32, %r31, %r20;
; ENABLED-NEXT:    add.s32 %r33, %r32, %r13;
; ENABLED-NEXT:    add.s32 %r34, %r33, %r12;
; ENABLED-NEXT:    add.s32 %r35, %r34, %r11;
; ENABLED-NEXT:    st.b32 [%rd2], %r35;
; ENABLED-NEXT:    ret;
;
; DISABLED-LABEL: combine_v16i8_unaligned(
; DISABLED:       {
; DISABLED-NEXT:    .reg .b32 %r<32>;
; DISABLED-NEXT:    .reg .b64 %rd<3>;
; DISABLED-EMPTY:
; DISABLED-NEXT:  // %bb.0:
; DISABLED-NEXT:    ld.param.b64 %rd1, [combine_v16i8_unaligned_param_0];
; DISABLED-NEXT:    ld.b8 %r1, [%rd1];
; DISABLED-NEXT:    ld.param.b64 %rd2, [combine_v16i8_unaligned_param_1];
; DISABLED-NEXT:    ld.b8 %r2, [%rd1+1];
; DISABLED-NEXT:    ld.b8 %r3, [%rd1+2];
; DISABLED-NEXT:    ld.b8 %r4, [%rd1+3];
; DISABLED-NEXT:    ld.b8 %r5, [%rd1+4];
; DISABLED-NEXT:    ld.b8 %r6, [%rd1+5];
; DISABLED-NEXT:    ld.b8 %r7, [%rd1+6];
; DISABLED-NEXT:    ld.b8 %r8, [%rd1+7];
; DISABLED-NEXT:    ld.b8 %r9, [%rd1+8];
; DISABLED-NEXT:    ld.b8 %r10, [%rd1+9];
; DISABLED-NEXT:    ld.b8 %r11, [%rd1+10];
; DISABLED-NEXT:    ld.b8 %r12, [%rd1+11];
; DISABLED-NEXT:    ld.b8 %r13, [%rd1+12];
; DISABLED-NEXT:    ld.b8 %r14, [%rd1+13];
; DISABLED-NEXT:    ld.b8 %r15, [%rd1+14];
; DISABLED-NEXT:    ld.b8 %r16, [%rd1+15];
; DISABLED-NEXT:    add.s32 %r17, %r1, %r2;
; DISABLED-NEXT:    add.s32 %r18, %r17, %r3;
; DISABLED-NEXT:    add.s32 %r19, %r18, %r4;
; DISABLED-NEXT:    add.s32 %r20, %r19, %r5;
; DISABLED-NEXT:    add.s32 %r21, %r20, %r6;
; DISABLED-NEXT:    add.s32 %r22, %r21, %r7;
; DISABLED-NEXT:    add.s32 %r23, %r22, %r8;
; DISABLED-NEXT:    add.s32 %r24, %r23, %r9;
; DISABLED-NEXT:    add.s32 %r25, %r24, %r10;
; DISABLED-NEXT:    add.s32 %r26, %r25, %r11;
; DISABLED-NEXT:    add.s32 %r27, %r26, %r12;
; DISABLED-NEXT:    add.s32 %r28, %r27, %r13;
; DISABLED-NEXT:    add.s32 %r29, %r28, %r14;
; DISABLED-NEXT:    add.s32 %r30, %r29, %r15;
; DISABLED-NEXT:    add.s32 %r31, %r30, %r16;
; DISABLED-NEXT:    st.b32 [%rd2], %r31;
; DISABLED-NEXT:    ret;
  %val0 = load i8, ptr %ptr1, align 8
  %ptr1.1 = getelementptr inbounds i8, ptr %ptr1, i64 1
  %val1 = load i8, ptr %ptr1.1, align 1
  %ptr1.2 = getelementptr inbounds i8, ptr %ptr1, i64 2
  %val2 = load i8, ptr %ptr1.2, align 2
  %ptr1.3 = getelementptr inbounds i8, ptr %ptr1, i64 3
  %val3 = load i8, ptr %ptr1.3, align 1
  %ptr1.4 = getelementptr inbounds i8, ptr %ptr1, i64 4
  %val4 = load i8, ptr %ptr1.4, align 4
  %ptr1.5 = getelementptr inbounds i8, ptr %ptr1, i64 5
  %val5 = load i8, ptr %ptr1.5, align 1
  %ptr1.6 = getelementptr inbounds i8, ptr %ptr1, i64 6
  %val6 = load i8, ptr %ptr1.6, align 2
  %ptr1.7 = getelementptr inbounds i8, ptr %ptr1, i64 7
  %val7 = load i8, ptr %ptr1.7, align 1
  %ptr1.8 = getelementptr inbounds i8, ptr %ptr1, i64 8
  %val8 = load i8, ptr %ptr1.8, align 8
  %ptr1.9 = getelementptr inbounds i8, ptr %ptr1, i64 9
  %val9 = load i8, ptr %ptr1.9, align 1
  %ptr1.10 = getelementptr inbounds i8, ptr %ptr1, i64 10
  %val10 = load i8, ptr %ptr1.10, align 2
  %ptr1.11 = getelementptr inbounds i8, ptr %ptr1, i64 11
  %val11 = load i8, ptr %ptr1.11, align 1
  %ptr1.12 = getelementptr inbounds i8, ptr %ptr1, i64 12
  %val12 = load i8, ptr %ptr1.12, align 4
  %ptr1.13 = getelementptr inbounds i8, ptr %ptr1, i64 13
  %val13 = load i8, ptr %ptr1.13, align 1
  %ptr1.14 = getelementptr inbounds i8, ptr %ptr1, i64 14
  %val14 = load i8, ptr %ptr1.14, align 2
  %ptr1.15 = getelementptr inbounds i8, ptr %ptr1, i64 15
  %val15 = load i8, ptr %ptr1.15, align 1
  %lane0 = zext i8 %val0 to i32
  %lane1 = zext i8 %val1 to i32
  %lane2 = zext i8 %val2 to i32
  %lane3 = zext i8 %val3 to i32
  %lane4 = zext i8 %val4 to i32
  %lane5 = zext i8 %val5 to i32
  %lane6 = zext i8 %val6 to i32
  %lane7 = zext i8 %val7 to i32
  %lane8 = zext i8 %val8 to i32
  %lane9 = zext i8 %val9 to i32
  %lane10 = zext i8 %val10 to i32
  %lane11 = zext i8 %val11 to i32
  %lane12 = zext i8 %val12 to i32
  %lane13 = zext i8 %val13 to i32
  %lane14 = zext i8 %val14 to i32
  %lane15 = zext i8 %val15 to i32
  %red.1 = add i32 %lane0, %lane1
  %red.2 = add i32 %red.1, %lane2
  %red.3 = add i32 %red.2, %lane3
  %red.4 = add i32 %red.3, %lane4
  %red.5 = add i32 %red.4, %lane5
  %red.6 = add i32 %red.5, %lane6
  %red.7 = add i32 %red.6, %lane7
  %red.8 = add i32 %red.7, %lane8
  %red.9 = add i32 %red.8, %lane9
  %red.10 = add i32 %red.9, %lane10
  %red.11 = add i32 %red.10, %lane11
  %red.12 = add i32 %red.11, %lane12
  %red.13 = add i32 %red.12, %lane13
  %red.14 = add i32 %red.13, %lane14
  %red = add i32 %red.14, %lane15
  store i32 %red, ptr %ptr2, align 4
  ret void
}


define void @combine_v8i16(ptr noundef align 16 %ptr1, ptr noundef align 16 %ptr2) {
; ENABLED-LABEL: combine_v8i16(
; ENABLED:       {
; ENABLED-NEXT:    .reg .b16 %rs<9>;
; ENABLED-NEXT:    .reg .b32 %r<20>;
; ENABLED-NEXT:    .reg .b64 %rd<3>;
; ENABLED-EMPTY:
; ENABLED-NEXT:  // %bb.0:
; ENABLED-NEXT:    ld.param.b64 %rd1, [combine_v8i16_param_0];
; ENABLED-NEXT:    ld.v4.b32 {%r1, %r2, %r3, %r4}, [%rd1];
; ENABLED-NEXT:    mov.b32 {%rs1, %rs2}, %r4;
; ENABLED-NEXT:    mov.b32 {%rs3, %rs4}, %r3;
; ENABLED-NEXT:    mov.b32 {%rs5, %rs6}, %r2;
; ENABLED-NEXT:    mov.b32 {%rs7, %rs8}, %r1;
; ENABLED-NEXT:    ld.param.b64 %rd2, [combine_v8i16_param_1];
; ENABLED-NEXT:    cvt.u32.u16 %r5, %rs7;
; ENABLED-NEXT:    cvt.u32.u16 %r6, %rs8;
; ENABLED-NEXT:    cvt.u32.u16 %r7, %rs5;
; ENABLED-NEXT:    cvt.u32.u16 %r8, %rs6;
; ENABLED-NEXT:    cvt.u32.u16 %r9, %rs3;
; ENABLED-NEXT:    cvt.u32.u16 %r10, %rs4;
; ENABLED-NEXT:    cvt.u32.u16 %r11, %rs1;
; ENABLED-NEXT:    cvt.u32.u16 %r12, %rs2;
; ENABLED-NEXT:    add.s32 %r13, %r5, %r6;
; ENABLED-NEXT:    add.s32 %r14, %r13, %r7;
; ENABLED-NEXT:    add.s32 %r15, %r14, %r8;
; ENABLED-NEXT:    add.s32 %r16, %r15, %r9;
; ENABLED-NEXT:    add.s32 %r17, %r16, %r10;
; ENABLED-NEXT:    add.s32 %r18, %r17, %r11;
; ENABLED-NEXT:    add.s32 %r19, %r18, %r12;
; ENABLED-NEXT:    st.b32 [%rd2], %r19;
; ENABLED-NEXT:    ret;
;
; DISABLED-LABEL: combine_v8i16(
; DISABLED:       {
; DISABLED-NEXT:    .reg .b32 %r<16>;
; DISABLED-NEXT:    .reg .b64 %rd<3>;
; DISABLED-EMPTY:
; DISABLED-NEXT:  // %bb.0:
; DISABLED-NEXT:    ld.param.b64 %rd1, [combine_v8i16_param_0];
; DISABLED-NEXT:    ld.b16 %r1, [%rd1];
; DISABLED-NEXT:    ld.param.b64 %rd2, [combine_v8i16_param_1];
; DISABLED-NEXT:    ld.b16 %r2, [%rd1+2];
; DISABLED-NEXT:    ld.b16 %r3, [%rd1+4];
; DISABLED-NEXT:    ld.b16 %r4, [%rd1+6];
; DISABLED-NEXT:    ld.b16 %r5, [%rd1+8];
; DISABLED-NEXT:    ld.b16 %r6, [%rd1+10];
; DISABLED-NEXT:    ld.b16 %r7, [%rd1+12];
; DISABLED-NEXT:    ld.b16 %r8, [%rd1+14];
; DISABLED-NEXT:    add.s32 %r9, %r1, %r2;
; DISABLED-NEXT:    add.s32 %r10, %r9, %r3;
; DISABLED-NEXT:    add.s32 %r11, %r10, %r4;
; DISABLED-NEXT:    add.s32 %r12, %r11, %r5;
; DISABLED-NEXT:    add.s32 %r13, %r12, %r6;
; DISABLED-NEXT:    add.s32 %r14, %r13, %r7;
; DISABLED-NEXT:    add.s32 %r15, %r14, %r8;
; DISABLED-NEXT:    st.b32 [%rd2], %r15;
; DISABLED-NEXT:    ret;
  %val0 = load i16, ptr %ptr1, align 16
  %ptr1.1 = getelementptr inbounds i16, ptr %ptr1, i64 1
  %val1 = load i16, ptr %ptr1.1, align 2
  %ptr1.2 = getelementptr inbounds i16, ptr %ptr1, i64 2
  %val2 = load i16, ptr %ptr1.2, align 4
  %ptr1.3 = getelementptr inbounds i16, ptr %ptr1, i64 3
  %val3 = load i16, ptr %ptr1.3, align 2
  %ptr1.4 = getelementptr inbounds i16, ptr %ptr1, i64 4
  %val4 = load i16, ptr %ptr1.4, align 4
  %ptr1.5 = getelementptr inbounds i16, ptr %ptr1, i64 5
  %val5 = load i16, ptr %ptr1.5, align 2
  %ptr1.6 = getelementptr inbounds i16, ptr %ptr1, i64 6
  %val6 = load i16, ptr %ptr1.6, align 4
  %ptr1.7 = getelementptr inbounds i16, ptr %ptr1, i64 7
  %val7 = load i16, ptr %ptr1.7, align 2
  %lane0 = zext i16 %val0 to i32
  %lane1 = zext i16 %val1 to i32
  %lane2 = zext i16 %val2 to i32
  %lane3 = zext i16 %val3 to i32
  %lane4 = zext i16 %val4 to i32
  %lane5 = zext i16 %val5 to i32
  %lane6 = zext i16 %val6 to i32
  %lane7 = zext i16 %val7 to i32
  %red.1 = add i32 %lane0, %lane1
  %red.2 = add i32 %red.1, %lane2
  %red.3 = add i32 %red.2, %lane3
  %red.4 = add i32 %red.3, %lane4
  %red.5 = add i32 %red.4, %lane5
  %red.6 = add i32 %red.5, %lane6
  %red = add i32 %red.6, %lane7
  store i32 %red, ptr %ptr2, align 4
  ret void
}

define void @combine_v4i32(ptr noundef align 16 %ptr1, ptr noundef align 16 %ptr2) {
; ENABLED-LABEL: combine_v4i32(
; ENABLED:       {
; ENABLED-NEXT:    .reg .b32 %r<8>;
; ENABLED-NEXT:    .reg .b64 %rd<3>;
; ENABLED-EMPTY:
; ENABLED-NEXT:  // %bb.0:
; ENABLED-NEXT:    ld.param.b64 %rd1, [combine_v4i32_param_0];
; ENABLED-NEXT:    ld.v4.b32 {%r1, %r2, %r3, %r4}, [%rd1];
; ENABLED-NEXT:    ld.param.b64 %rd2, [combine_v4i32_param_1];
; ENABLED-NEXT:    add.s32 %r5, %r1, %r2;
; ENABLED-NEXT:    add.s32 %r6, %r5, %r3;
; ENABLED-NEXT:    add.s32 %r7, %r6, %r4;
; ENABLED-NEXT:    st.b32 [%rd2], %r7;
; ENABLED-NEXT:    ret;
;
; DISABLED-LABEL: combine_v4i32(
; DISABLED:       {
; DISABLED-NEXT:    .reg .b32 %r<8>;
; DISABLED-NEXT:    .reg .b64 %rd<3>;
; DISABLED-EMPTY:
; DISABLED-NEXT:  // %bb.0:
; DISABLED-NEXT:    ld.param.b64 %rd1, [combine_v4i32_param_0];
; DISABLED-NEXT:    ld.b32 %r1, [%rd1];
; DISABLED-NEXT:    ld.param.b64 %rd2, [combine_v4i32_param_1];
; DISABLED-NEXT:    ld.b32 %r2, [%rd1+4];
; DISABLED-NEXT:    ld.b32 %r3, [%rd1+8];
; DISABLED-NEXT:    ld.b32 %r4, [%rd1+12];
; DISABLED-NEXT:    add.s32 %r5, %r1, %r2;
; DISABLED-NEXT:    add.s32 %r6, %r5, %r3;
; DISABLED-NEXT:    add.s32 %r7, %r6, %r4;
; DISABLED-NEXT:    st.b32 [%rd2], %r7;
; DISABLED-NEXT:    ret;
  %val0 = load i32, ptr %ptr1, align 16
  %ptr1.1 = getelementptr inbounds i32, ptr %ptr1, i64 1
  %val1 = load i32, ptr %ptr1.1, align 4
  %ptr1.2 = getelementptr inbounds i32, ptr %ptr1, i64 2
  %val2 = load i32, ptr %ptr1.2, align 8
  %ptr1.3 = getelementptr inbounds i32, ptr %ptr1, i64 3
  %val3 = load i32, ptr %ptr1.3, align 4
  %red.1 = add i32 %val0, %val1
  %red.2 = add i32 %red.1, %val2
  %red = add i32 %red.2, %val3
  store i32 %red, ptr %ptr2, align 4
  ret void
}

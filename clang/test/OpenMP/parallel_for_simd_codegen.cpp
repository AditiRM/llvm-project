// RUN: %clang_cc1 -verify -fopenmp -fopenmp-version=45 -x c++ -triple x86_64-unknown-unknown -emit-llvm %s -fexceptions -fcxx-exceptions -o - | FileCheck %s --check-prefix=OMP45 --check-prefix=CHECK
// RUN: %clang_cc1 -fopenmp -fopenmp-version=45 -x c++ -std=c++11 -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp -fopenmp-version=45 -x c++ -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -debug-info-kind=limited -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 -verify -triple x86_64-apple-darwin10 -fopenmp -fopenmp-version=45 -fexceptions -fcxx-exceptions -debug-info-kind=line-tables-only -x c++ -emit-llvm %s -o - | FileCheck %s --check-prefix=TERM_DEBUG

// RUN: %clang_cc1 -verify -fopenmp -DOMP5 -x c++ -triple x86_64-unknown-unknown -emit-llvm %s -fexceptions -fcxx-exceptions -o - | FileCheck %s --check-prefix=OMP50 --check-prefix=CHECK
// RUN: %clang_cc1 -fopenmp -DOMP5 -x c++ -std=c++11 -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp -DOMP5 -x c++ -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -debug-info-kind=limited -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 -verify -triple x86_64-apple-darwin10 -fopenmp -DOMP5 -fexceptions -fcxx-exceptions -debug-info-kind=line-tables-only -x c++ -emit-llvm %s -o - | FileCheck %s --check-prefix=TERM_DEBUG

// RUN: %clang_cc1 -verify -fopenmp-simd -fopenmp-version=45 -x c++ -triple x86_64-unknown-unknown -emit-llvm %s -fexceptions -fcxx-exceptions -o - | FileCheck --check-prefix SIMD-ONLY0 %s
// RUN: %clang_cc1 -fopenmp-simd -fopenmp-version=45 -x c++ -std=c++11 -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp-simd -fopenmp-version=45 -x c++ -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -debug-info-kind=limited -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck --check-prefix SIMD-ONLY0 %s
// RUN: %clang_cc1 -verify -triple x86_64-apple-darwin10 -fopenmp-simd -fopenmp-version=45 -fexceptions -fcxx-exceptions -debug-info-kind=line-tables-only -x c++ -emit-llvm %s -o - | FileCheck --check-prefix SIMD-ONLY0 %s

// RUN: %clang_cc1 -verify -fopenmp-simd -DOMP5 -x c++ -triple x86_64-unknown-unknown -emit-llvm %s -fexceptions -fcxx-exceptions -o - | FileCheck --check-prefix SIMD-ONLY0 %s
// RUN: %clang_cc1 -fopenmp-simd -DOMP5 -x c++ -std=c++11 -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp-simd -DOMP5 -x c++ -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -debug-info-kind=limited -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck --check-prefix SIMD-ONLY0 %s
// RUN: %clang_cc1 -verify -triple x86_64-apple-darwin10 -fopenmp-simd -DOMP5 -fexceptions -fcxx-exceptions -debug-info-kind=line-tables-only -x c++ -emit-llvm %s -o - | FileCheck --check-prefix SIMD-ONLY0 %s
// expected-no-diagnostics
// SIMD-ONLY0-NOT: {{__kmpc|__tgt}}
#ifndef HEADER
#define HEADER

long long get_val() { extern void mayThrow(); mayThrow(); return 0; }
double *g_ptr;

// CHECK-LABEL: define {{.*void}} @{{.*}}simple{{.*}}(ptr noundef {{.+}}, ptr noundef {{.+}}, ptr noundef {{.+}}, ptr noundef {{.+}})
void simple(float *a, float *b, float *c, float *d) {
// CHECK: call void (ptr, i32, ptr, ...) @__kmpc_fork_call(
// CHECK: [[K0:%.+]] = call {{.*}}i64 @{{.*}}get_val
// CHECK-NEXT: store i64 [[K0]], ptr [[K_VAR:%[^,]+]]
// CHECK: call void (ptr, i32, ptr, ...) @__kmpc_fork_call(
// CHECK: store i32 12, ptr [[LIN_VAR:%[^,]+]]
// CHECK: call void (ptr, i32, ptr, ...) @__kmpc_fork_call(
// CHECK: call void (ptr, i32, ptr, ...) @__kmpc_fork_call(
// CHECK: call void (ptr, i32, ptr, ...) @__kmpc_fork_call(
// CHECK: call void (ptr, i32, ptr, ...) @__kmpc_fork_call(
// CHECK: store i32 -1, ptr [[A:%.+]],
// CHECK: call void (ptr, i32, ptr, ...) @__kmpc_fork_call(
// CHECK: store i32 -1, ptr [[R:%[^,]+]],
// CHECK: call void (ptr, i32, ptr, ...) @__kmpc_fork_call(
  #pragma omp parallel for simd
// CHECK: call void @__kmpc_for_static_init_4(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i32 1, i32 1)
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK: [[CMP:%.+]] = icmp sgt i32 [[UB_VAL]], 5
// CHECK: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// CHECK: [[TRUE]]:
// CHECK: br label %[[SWITCH:[^,]+]]
// CHECK: [[FALSE]]:
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK: br label %[[SWITCH]]
// CHECK: [[SWITCH]]:
// CHECK: [[UP:%.+]] = phi i32 [ 5, %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// CHECK: store i32 [[UP]], ptr [[UB]],
// CHECK: [[LB_VAL:%.+]] = load i32, ptr [[LB]],
// CHECK: store i32 [[LB_VAL]], ptr [[OMP_IV:%[^,]+]],

// CHECK: [[IV:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]]
// CHECK-NEXT: [[CMP:%.+]] = icmp sle i32 [[IV]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP]], label %[[SIMPLE_LOOP1_BODY:.+]], label %[[SIMPLE_LOOP1_END:[^,]+]]
  for (int i = 3; i < 32; i += 5) {
// CHECK: [[SIMPLE_LOOP1_BODY]]:
// Start of body: calculate i from IV:
// CHECK: [[IV1_1:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[CALC_I_1:%.+]] = mul nsw i32 [[IV1_1]], 5
// CHECK-NEXT: [[CALC_I_2:%.+]] = add nsw i32 3, [[CALC_I_1]]
// CHECK-NEXT: store i32 [[CALC_I_2]], ptr [[LC_I:.+]]
// ... loop body ...
// End of body: store into a[i]:
// CHECK: store float [[RESULT:%.+]], ptr
    a[i] = b[i] * c[i] * d[i];
// CHECK: [[IV1_2:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK-NEXT: [[ADD1_2:%.+]] = add nsw i32 [[IV1_2]], 1
// CHECK-NEXT: store i32 [[ADD1_2]], ptr [[OMP_IV]]
// br label %{{.+}}, !llvm.loop !{{.+}}
  }
// CHECK: [[SIMPLE_LOOP1_END]]:
// CHECK: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})

  long long k = get_val();

  #pragma omp parallel for simd linear(k : 3) schedule(dynamic)
// CHECK: [[K0LOAD:%.+]] = load i64, ptr [[K_VAR:%[^,]+]]
// CHECK-NEXT: store i64 [[K0LOAD]], ptr [[LIN0:%[^,]+]]

// CHECK: call void @__kmpc_dispatch_init_4(ptr {{.+}}, i32 %{{.+}}, i32 {{35|1073741859}}, i32 0, i32 8, i32 1, i32 1)
// CHECK: [[NEXT:%.+]] = call i32 @__kmpc_dispatch_next_4(ptr {{.+}}, i32 %{{.+}}, ptr %{{.+}}, ptr [[LB:%.+]], ptr [[UB:%.+]], ptr %{{.+}})
// CHECK: [[COND:%.+]] = icmp ne i32 [[NEXT]], 0
// CHECK: br i1 [[COND]], label %[[CONT:.+]], label %[[END:.+]]
// CHECK: [[CONT]]:
// CHECK: [[LB_VAL:%.+]] = load i32, ptr [[LB]],
// CHECK: store i32 [[LB_VAL]], ptr [[OMP_IV2:%[^,]+]],

// CHECK: [[IV2:%.+]] = load i32, ptr [[OMP_IV2]]{{.*}}!llvm.access.group
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]]{{.*}}!llvm.access.group
// CHECK-NEXT: [[CMP2:%.+]] = icmp sle i32 [[IV2]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP2]], label %[[SIMPLE_LOOP2_BODY:.+]], label %[[SIMPLE_LOOP2_END:[^,]+]]
  for (int i = 10; i > 1; i--) {
// CHECK: [[SIMPLE_LOOP2_BODY]]:
// Start of body: calculate i from IV:
// CHECK: [[IV2_0:%.+]] = load i32, ptr [[OMP_IV2]]{{.*}}!llvm.access.group
// FIXME: It is interesting, why the following "mul 1" was not constant folded?
// CHECK-NEXT: [[IV2_1:%.+]] = mul nsw i32 [[IV2_0]], 1
// CHECK-NEXT: [[LC_I_1:%.+]] = sub nsw i32 10, [[IV2_1]]
// CHECK-NEXT: store i32 [[LC_I_1]], ptr {{.+}}, !llvm.access.group
//
// CHECK-NEXT: [[LIN0_1:%.+]] = load i64, ptr [[LIN0]]{{.*}}!llvm.access.group
// CHECK-NEXT: [[IV2_2:%.+]] = load i32, ptr [[OMP_IV2]]{{.*}}!llvm.access.group
// CHECK-NEXT: [[LIN_MUL1:%.+]] = mul nsw i32 [[IV2_2]], 3
// CHECK-NEXT: [[LIN_EXT1:%.+]] = sext i32 [[LIN_MUL1]] to i64
// CHECK-NEXT: [[LIN_ADD1:%.+]] = add nsw i64 [[LIN0_1]], [[LIN_EXT1]]
// Update of the privatized version of linear variable!
// CHECK-NEXT: store i64 [[LIN_ADD1]], ptr [[K_PRIVATIZED:%[^,]+]]
    a[k]++;
    k = k + 3;
// CHECK: [[IV2_2:%.+]] = load i32, ptr [[OMP_IV2]]{{.*}}!llvm.access.group
// CHECK-NEXT: [[ADD2_2:%.+]] = add nsw i32 [[IV2_2]], 1
// CHECK-NEXT: store i32 [[ADD2_2]], ptr [[OMP_IV2]]{{.*}}!llvm.access.group
// br label {{.+}}, !llvm.loop ![[SIMPLE_LOOP2_ID]]
  }
// CHECK: [[SIMPLE_LOOP2_END]]:
//
// Update linear vars after loop, as the loop was operating on a private version.
// CHECK: [[LIN0_2:%.+]] = load i64, ptr [[K_PRIVATIZED]]
// CHECK-NEXT: store i64 [[LIN0_2]], ptr %{{.+}}

  int lin = 12;
  #pragma omp parallel for simd linear(lin : get_val()), linear(g_ptr)

// CHECK: alloca i32,
// Init linear private var.
// CHECK: [[LIN_VAR:%.+]] = load ptr, ptr %lin
// CHECK: [[LIN_LOAD:%.+]] = load i32, ptr [[LIN_VAR]]
// CHECK-NEXT: store i32 [[LIN_LOAD]], ptr [[LIN_START:%[^,]+]]
// Remember linear step.
// CHECK: [[CALL_VAL:%.+]] = invoke
// CHECK: store i64 [[CALL_VAL]], ptr [[LIN_STEP:%[^,]+]]

// CHECK: [[GLIN_LOAD:%.+]] = load ptr, ptr [[GLIN_VAR:%.+]],
// CHECK-NEXT: store ptr [[GLIN_LOAD]], ptr [[GLIN_START:%[^,]+]]

// CHECK: call void @__kmpc_for_static_init_8u(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i64 1, i64 1)
// CHECK: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// CHECK: [[CMP:%.+]] = icmp ugt i64 [[UB_VAL]], 3
// CHECK: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// CHECK: [[TRUE]]:
// CHECK: br label %[[SWITCH:[^,]+]]
// CHECK: [[FALSE]]:
// CHECK: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// CHECK: br label %[[SWITCH]]
// CHECK: [[SWITCH]]:
// CHECK: [[UP:%.+]] = phi i64 [ 3, %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// CHECK: store i64 [[UP]], ptr [[UB]],
// CHECK: [[LB_VAL:%.+]] = load i64, ptr [[LB]],
// CHECK: store i64 [[LB_VAL]], ptr [[OMP_IV3:%[^,]+]],

// CHECK: [[IV3:%.+]] = load i64, ptr [[OMP_IV3]]
// CHECK: [[UB_VAL:%.+]] = load i64, ptr [[UB]]
// CHECK-NEXT: [[CMP3:%.+]] = icmp ule i64 [[IV3]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP3]], label %[[SIMPLE_LOOP3_BODY:.+]], label %[[SIMPLE_LOOP3_END:[^,]+]]
  for (unsigned long long it = 2000; it >= 600; it-=400) {
// CHECK: [[SIMPLE_LOOP3_BODY]]:
// Start of body: calculate it from IV:
// CHECK: [[IV3_0:%.+]] = load i64, ptr [[OMP_IV3]]
// CHECK-NEXT: [[LC_IT_1:%.+]] = mul i64 [[IV3_0]], 400
// CHECK-NEXT: [[LC_IT_2:%.+]] = sub i64 2000, [[LC_IT_1]]
// CHECK-NEXT: store i64 [[LC_IT_2]], ptr {{.+}}
//
// Linear start and step are used to calculate current value of the linear variable.
// CHECK: [[LINSTART:.+]] = load i32, ptr [[LIN_START]]
// CHECK: [[LINSTEP:.+]] = load i64, ptr [[LIN_STEP]]
// CHECK-NOT: store i32 {{.+}}, ptr [[LIN_VAR]]
// CHECK: store i32 {{.+}}, ptr [[LIN_PRIV:%[^,]+]],
// CHECK: [[GLINSTART:.+]] = load ptr, ptr [[GLIN_START]]
// CHECK-NEXT: [[IV3_1:%.+]] = load i64, ptr [[OMP_IV3]]
// CHECK-NEXT: [[MUL:%.+]] = mul i64 [[IV3_1]], 1
// CHECK: [[GEP:%.+]] = getelementptr{{.*}}[[GLINSTART]]
// CHECK-NEXT: store ptr [[GEP]], ptr [[G_PTR_CUR:%[^,]+]]
    *g_ptr++ = 0.0;
// CHECK: [[GEP_VAL:%.+]] = load ptr, ptr [[G_PTR_CUR]]
// CHECK: store double{{.*}}[[GEP_VAL]]
    a[it + lin]++;
// CHECK: [[FLT_INC:%.+]] = fadd float
// CHECK-NEXT: store float [[FLT_INC]],
// CHECK: [[IV3_2:%.+]] = load i64, ptr [[OMP_IV3]]
// CHECK-NEXT: [[ADD3_2:%.+]] = add i64 [[IV3_2]], 1
// CHECK-NEXT: store i64 [[ADD3_2]], ptr [[OMP_IV3]]
  }
// CHECK: [[SIMPLE_LOOP3_END]]:
// CHECK: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})
//
// Linear start and step are used to calculate final value of the linear variables.
// CHECK: [[LIN:%.+]] = load i32, ptr [[LIN_PRIV]]
// CHECK: store i32 [[LIN]], ptr [[LIN_VAR]],
// CHECK: [[GLIN:%.+]] = load ptr, ptr [[G_PTR_CUR]]
// CHECK: store ptr [[GLIN]], ptr [[GLIN_VAR]],

  #pragma omp parallel for simd
// CHECK: call void @__kmpc_for_static_init_4(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i32 1, i32 1)
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK: [[CMP:%.+]] = icmp sgt i32 [[UB_VAL]], 3
// CHECK: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// CHECK: [[TRUE]]:
// CHECK: br label %[[SWITCH:[^,]+]]
// CHECK: [[FALSE]]:
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK: br label %[[SWITCH]]
// CHECK: [[SWITCH]]:
// CHECK: [[UP:%.+]] = phi i32 [ 3, %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// CHECK: store i32 [[UP]], ptr [[UB]],
// CHECK: [[LB_VAL:%.+]] = load i32, ptr [[LB]],
// CHECK: store i32 [[LB_VAL]], ptr [[OMP_IV4:%[^,]+]],

// CHECK: [[IV4:%.+]] = load i32, ptr [[OMP_IV4]]
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]]
// CHECK-NEXT: [[CMP4:%.+]] = icmp sle i32 [[IV4]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP4]], label %[[SIMPLE_LOOP4_BODY:.+]], label %[[SIMPLE_LOOP4_END:[^,]+]]
  for (short it = 6; it <= 20; it-=-4) {
// CHECK: [[SIMPLE_LOOP4_BODY]]:
// Start of body: calculate it from IV:
// CHECK: [[IV4_0:%.+]] = load i32, ptr [[OMP_IV4]]
// CHECK-NEXT: [[LC_IT_1:%.+]] = mul nsw i32 [[IV4_0]], 4
// CHECK-NEXT: [[LC_IT_2:%.+]] = add nsw i32 6, [[LC_IT_1]]
// CHECK-NEXT: [[LC_IT_3:%.+]] = trunc i32 [[LC_IT_2]] to i16
// CHECK-NEXT: store i16 [[LC_IT_3]], ptr

// CHECK: [[IV4_2:%.+]] = load i32, ptr [[OMP_IV4]]
// CHECK-NEXT: [[ADD4_2:%.+]] = add nsw i32 [[IV4_2]], 1
// CHECK-NEXT: store i32 [[ADD4_2]], ptr [[OMP_IV4]]
  }
// CHECK: [[SIMPLE_LOOP4_END]]:
// CHECK: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})

  #pragma omp parallel for simd
// CHECK: call void @__kmpc_for_static_init_4(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i32 1, i32 1)
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK: [[CMP:%.+]] = icmp sgt i32 [[UB_VAL]], 25
// CHECK: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// CHECK: [[TRUE]]:
// CHECK: br label %[[SWITCH:[^,]+]]
// CHECK: [[FALSE]]:
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK: br label %[[SWITCH]]
// CHECK: [[SWITCH]]:
// CHECK: [[UP:%.+]] = phi i32 [ 25, %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// CHECK: store i32 [[UP]], ptr [[UB]],
// CHECK: [[LB_VAL:%.+]] = load i32, ptr [[LB]],
// CHECK: store i32 [[LB_VAL]], ptr [[OMP_IV5:%[^,]+]],

// CHECK: [[IV5:%.+]] = load i32, ptr [[OMP_IV5]]
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]]
// CHECK-NEXT: [[CMP5:%.+]] = icmp sle i32 [[IV5]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP5]], label %[[SIMPLE_LOOP5_BODY:.+]], label %[[SIMPLE_LOOP5_END:[^,]+]]
  for (unsigned char it = 'z'; it >= 'a'; it+=-1) {
// CHECK: [[SIMPLE_LOOP5_BODY]]:
// Start of body: calculate it from IV:
// CHECK: [[IV5_0:%.+]] = load i32, ptr [[OMP_IV5]]
// CHECK-NEXT: [[IV5_1:%.+]] = mul nsw i32 [[IV5_0]], 1
// CHECK-NEXT: [[LC_IT_1:%.+]] = sub nsw i32 122, [[IV5_1]]
// CHECK-NEXT: [[LC_IT_2:%.+]] = trunc i32 [[LC_IT_1]] to i8
// CHECK-NEXT: store i8 [[LC_IT_2]], ptr {{.+}},

// CHECK: [[IV5_2:%.+]] = load i32, ptr [[OMP_IV5]]
// CHECK-NEXT: [[ADD5_2:%.+]] = add nsw i32 [[IV5_2]], 1
// CHECK-NEXT: store i32 [[ADD5_2]], ptr [[OMP_IV5]]
  }
// CHECK: [[SIMPLE_LOOP5_END]]:
// CHECK: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})

// CHECK-NOT: mul i32 %{{.+}}, 10
  #pragma omp parallel for simd
  for (unsigned i=100; i<10; i+=10) {
  }

  int A;
  {
  A = -1;
  #pragma omp parallel for simd lastprivate(A)
// CHECK: call void @__kmpc_for_static_init_8(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i64 1, i64 1)
// CHECK: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// CHECK: [[CMP:%.+]] = icmp sgt i64 [[UB_VAL]], 6
// CHECK: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// CHECK: [[TRUE]]:
// CHECK: br label %[[SWITCH:[^,]+]]
// CHECK: [[FALSE]]:
// CHECK: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// CHECK: br label %[[SWITCH]]
// CHECK: [[SWITCH]]:
// CHECK: [[UP:%.+]] = phi i64 [ 6, %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// CHECK: store i64 [[UP]], ptr [[UB]],
// CHECK: [[LB_VAL:%.+]] = load i64, ptr [[LB]],
// CHECK: store i64 [[LB_VAL]], ptr [[OMP_IV7:%[^,]+]],

// CHECK: br label %[[SIMD_LOOP7_COND:[^,]+]]
// CHECK: [[SIMD_LOOP7_COND]]:
// CHECK-NEXT: [[IV7:%.+]] = load i64, ptr [[OMP_IV7]]
// CHECK-NEXT: [[UB_VAL:%.+]] = load i64, ptr [[UB]]
// CHECK-NEXT: [[CMP7:%.+]] = icmp sle i64 [[IV7]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP7]], label %[[SIMPLE_LOOP7_BODY:.+]], label %[[SIMPLE_LOOP7_END:[^,]+]]
  for (long long i = -10; i < 10; i += 3) {
// CHECK: [[SIMPLE_LOOP7_BODY]]:
// Start of body: calculate i from IV:
// CHECK: [[IV7_0:%.+]] = load i64, ptr [[OMP_IV7]]
// CHECK-NEXT: [[LC_IT_1:%.+]] = mul nsw i64 [[IV7_0]], 3
// CHECK-NEXT: [[LC_IT_2:%.+]] = add nsw i64 -10, [[LC_IT_1]]
// CHECK-NEXT: store i64 [[LC_IT_2]], ptr [[LC:%[^,]+]],
// CHECK-NEXT: [[LC_VAL:%.+]] = load i64, ptr [[LC]]
// CHECK-NEXT: [[CONV:%.+]] = trunc i64 [[LC_VAL]] to i32
// CHECK-NEXT: store i32 [[CONV]], ptr [[A_PRIV:%[^,]+]],
    A = i;
// CHECK: [[IV7_2:%.+]] = load i64, ptr [[OMP_IV7]]
// CHECK-NEXT: [[ADD7_2:%.+]] = add nsw i64 [[IV7_2]], 1
// CHECK-NEXT: store i64 [[ADD7_2]], ptr [[OMP_IV7]]
  }
// CHECK: [[SIMPLE_LOOP7_END]]:
// CHECK: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})
// CHECK: load i32, ptr
// CHECK: icmp ne i32 %{{.+}}, 0
// CHECK: br i1 %{{.+}}, label
// CHECK: [[A_PRIV_VAL:%.+]] = load i32, ptr [[A_PRIV]],
// CHECK-NEXT: store i32 [[A_PRIV_VAL]], ptr %{{.+}},
// CHECK-NEXT: br label
  }
  int R;
  {
  R = -1;
// CHECK: store i32 1, ptr [[R_PRIV:%[^,]+]],
  #pragma omp parallel for simd reduction(*:R)
// CHECK: call void @__kmpc_for_static_init_8(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i64 1, i64 1)
// CHECK: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// CHECK: [[CMP:%.+]] = icmp sgt i64 [[UB_VAL]], 6
// CHECK: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// CHECK: [[TRUE]]:
// CHECK: br label %[[SWITCH:[^,]+]]
// CHECK: [[FALSE]]:
// CHECK: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// CHECK: br label %[[SWITCH]]
// CHECK: [[SWITCH]]:
// CHECK: [[UP:%.+]] = phi i64 [ 6, %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// CHECK: store i64 [[UP]], ptr [[UB]],
// CHECK: [[LB_VAL:%.+]] = load i64, ptr [[LB]],
// CHECK: store i64 [[LB_VAL]], ptr [[OMP_IV8:%[^,]+]],

// CHECK: br label %[[SIMD_LOOP8_COND:[^,]+]]
// CHECK: [[SIMD_LOOP8_COND]]:
// CHECK-NEXT: [[IV8:%.+]] = load i64, ptr [[OMP_IV8]]
// CHECK-NEXT: [[UB_VAL:%.+]] = load i64, ptr [[UB]]
// CHECK-NEXT: [[CMP8:%.+]] = icmp sle i64 [[IV8]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP8]], label %[[SIMPLE_LOOP8_BODY:.+]], label %[[SIMPLE_LOOP8_END:[^,]+]]
  for (long long i = -10; i < 10; i += 3) {
// CHECK: [[SIMPLE_LOOP8_BODY]]:
// Start of body: calculate i from IV:
// CHECK: [[IV8_0:%.+]] = load i64, ptr [[OMP_IV8]]
// CHECK-NEXT: [[LC_IT_1:%.+]] = mul nsw i64 [[IV8_0]], 3
// CHECK-NEXT: [[LC_IT_2:%.+]] = add nsw i64 -10, [[LC_IT_1]]
// CHECK-NEXT: store i64 [[LC_IT_2]], ptr [[LC:%[^,]+]],
// CHECK-NEXT: [[LC_VAL:%.+]] = load i64, ptr [[LC]]
// CHECK: store i32 %{{.+}}, ptr [[R_PRIV]],
    R *= i;
// CHECK: [[IV8_2:%.+]] = load i64, ptr [[OMP_IV8]]
// CHECK-NEXT: [[ADD8_2:%.+]] = add nsw i64 [[IV8_2]], 1
// CHECK-NEXT: store i64 [[ADD8_2]], ptr [[OMP_IV8]]
  }
// CHECK: [[SIMPLE_LOOP8_END]]:
// CHECK: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})
// CHECK: call i32 @__kmpc_reduce_nowait(
// CHECK: [[R_PRIV_VAL:%.+]] = load i32, ptr [[R_PRIV]],
// CHECK: [[RED:%.+]] = mul nsw i32 %{{.+}}, [[R_PRIV_VAL]]
// CHECK-NEXT: store i32 [[RED]], ptr %{{.+}},
// CHECK-NEXT: call void @__kmpc_end_reduce_nowait(
  }
}

template <class T, unsigned K> T tfoo(T a) { return a + K; }

template <typename T, unsigned N>
int templ1(T a, T *z) {
  #pragma omp parallel for simd collapse(N)
  for (int i = 0; i < N * 2; i++) {
    for (long long j = 0; j < (N + N + N + N); j += 2) {
      z[i + j] = a + tfoo<T, N>(i + j);
    }
  }
  return 0;
}

// Instatiation templ1<float,2>
// CHECK-LABEL: define {{.*i32}} @{{.*}}templ1{{.*}}(float noundef {{.+}}, ptr noundef {{.+}})
// CHECK: call void (ptr, i32, ptr, ...) @__kmpc_fork_call(
void inst_templ1() {
  float a;
  float z[100];
  templ1<float,2> (a, z);
}

// OMP50: call void @__kmpc_for_static_init_8(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i64 1, i64 1)
// OMP50: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// OMP50: [[CMP:%.+]] = icmp sgt i64 [[UB_VAL]], 15
// OMP50: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// OMP50: [[TRUE]]:
// OMP50: br label %[[SWITCH:[^,]+]]
// OMP50: [[FALSE]]:
// OMP50: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// OMP50: br label %[[SWITCH]]
// OMP50: [[SWITCH]]:
// OMP50: [[UP:%.+]] = phi i64 [ 15, %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// OMP50: store i64 [[UP]], ptr [[UB]],
// OMP50: [[LB_VAL:%.+]] = load i64, ptr [[LB]],
// OMP50: store i64 [[LB_VAL]], ptr [[T1_OMP_IV:%[^,]+]],

// ...
// OMP50: [[IV:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP50-NEXT: [[UB_VAL:%.+]] = load i64, ptr [[UB]]
// OMP50-NEXT: [[CMP1:%.+]] = icmp sle i64 [[IV]], [[UB_VAL]]
// OMP50-NEXT: br i1 [[CMP1]], label %[[T1_BODY:.+]], label %[[T1_END:[^,]+]]
// OMP50: [[T1_BODY]]:
// Loop counters i and j updates:
// OMP50: [[IV1:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP50-NEXT: [[I_1:%.+]] = sdiv i64 [[IV1]], 4
// OMP50-NEXT: [[I_1_MUL1:%.+]] = mul nsw i64 [[I_1]], 1
// OMP50-NEXT: [[I_1_ADD0:%.+]] = add nsw i64 0, [[I_1_MUL1]]
// OMP50-NEXT: [[I_2:%.+]] = trunc i64 [[I_1_ADD0]] to i32
// OMP50-NEXT: store i32 [[I_2]], ptr
// OMP50: [[IV2:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP50: [[IV2_1:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP50-NEXT: [[DIV_1:%.+]] = sdiv i64 [[IV2_1]], 4
// OMP50-NEXT: [[MUL_1:%.+]] = mul nsw i64 [[DIV_1]], 4
// OMP50-NEXT: [[J_1:%.+]] = sub nsw i64 [[IV2]], [[MUL_1]]
// OMP50-NEXT: [[J_2:%.+]] = mul nsw i64 [[J_1]], 2
// OMP50-NEXT: [[J_2_ADD0:%.+]] = add nsw i64 0, [[J_2]]
// OMP50-NEXT: store i64 [[J_2_ADD0]], ptr
// simd.for.inc:
// OMP50: [[IV3:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP50-NEXT: [[INC:%.+]] = add nsw i64 [[IV3]], 1
// OMP50-NEXT: store i64 [[INC]], ptr
// OMP50-NEXT: br label {{%.+}}
// OMP50: [[T1_END]]:
// OMP50: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})
// OMP50: ret void
//

typedef int MyIdx;

class IterDouble {
  double *Ptr;
public:
  IterDouble operator++ () const {
    IterDouble n;
    n.Ptr = Ptr + 1;
    return n;
  }
  bool operator < (const IterDouble &that) const {
    return Ptr < that.Ptr;
  }
  double & operator *() const {
    return *Ptr;
  }
  MyIdx operator - (const IterDouble &that) const {
    return (MyIdx) (Ptr - that.Ptr);
  }
  IterDouble operator + (int Delta) {
    IterDouble re;
    re.Ptr = Ptr + Delta;
    return re;
  }

  ///~IterDouble() {}
};

// CHECK-LABEL: define {{.*void}} @{{.*}}iter_simple{{.*}}
void iter_simple(IterDouble ia, IterDouble ib, IterDouble ic) {
//
// Calculate number of iterations before the loop body.
// CHECK: [[DIFF1:%.+]] = invoke {{.*}}i32 @{{.*}}IterDouble{{.*}}
// CHECK: [[DIFF2:%.+]] = sub nsw i32 [[DIFF1]], 1
// CHECK-NEXT: [[DIFF3:%.+]] = add nsw i32 [[DIFF2]], 1
// CHECK-NEXT: [[DIFF4:%.+]] = sdiv i32 [[DIFF3]], 1
// CHECK-NEXT: [[DIFF5:%.+]] = sub nsw i32 [[DIFF4]], 1
// CHECK-NEXT: store i32 [[DIFF5]], ptr [[OMP_LAST_IT:%[^,]+]]{{.+}}
  #pragma omp parallel for simd

// CHECK: call void @__kmpc_for_static_init_4(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i32 1, i32 1)
// CHECK-DAG: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK-DAG: [[OMP_LAST_IT_VAL:%.+]] = load i32, ptr [[OMP_LAST_IT]],
// CHECK: [[CMP:%.+]] = icmp sgt i32 [[UB_VAL]], [[OMP_LAST_IT_VAL]]
// CHECK: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// CHECK: [[TRUE]]:
// CHECK: [[OMP_LAST_IT_VAL:%.+]] = load i32, ptr [[OMP_LAST_IT]],
// CHECK: br label %[[SWITCH:[^,]+]]
// CHECK: [[FALSE]]:
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK: br label %[[SWITCH]]
// CHECK: [[SWITCH]]:
// CHECK: [[UP:%.+]] = phi i32 [ [[OMP_LAST_IT_VAL]], %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// CHECK: store i32 [[UP]], ptr [[UB]],
// CHECK: [[LB_VAL:%.+]] = load i32, ptr [[LB]],
// CHECK: store i32 [[LB_VAL]], ptr [[IT_OMP_IV:%[^,]+]],

// CHECK: [[IV:%.+]] = load i32, ptr [[IT_OMP_IV]]
// CHECK-NEXT: [[UB_VAL:%.+]] = load i32, ptr [[UB]]
// CHECK-NEXT: [[CMP:%.+]] = icmp sle i32 [[IV]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP]], label %[[IT_BODY:[^,]+]], label %[[IT_END:[^,]+]]
  for (IterDouble i = ia; i < ib; ++i) {
// CHECK: [[IT_BODY]]:
// Start of body: calculate i from index:
// CHECK: [[IV1:%.+]] = load i32, ptr [[IT_OMP_IV]]
// Call of operator+ (i, IV).
// CHECK: {{%.+}} = invoke {{.+}} @{{.*}}IterDouble{{.*}}
// ... loop body ...
   *i = *ic * 0.5;
// Float multiply and save result.
// CHECK: [[MULR:%.+]] = fmul double {{%.+}}, 5.000000e-01
// CHECK-NEXT: invoke {{.+}} @{{.*}}IterDouble{{.*}}
// CHECK: store double [[MULR:%.+]], ptr [[RESULT_ADDR:%.+]]
   ++ic;
//
// CHECK: [[IV2:%.+]] = load i32, ptr [[IT_OMP_IV]]
// CHECK-NEXT: [[ADD2:%.+]] = add nsw i32 [[IV2]], 1
// CHECK-NEXT: store i32 [[ADD2]], ptr [[IT_OMP_IV]]
// br label %{{.*}}, !llvm.loop ![[ITER_LOOP_ID]]
  }
// CHECK: [[IT_END]]:
// CHECK: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})
// CHECK: ret void
}


// CHECK-LABEL: define {{.*void}} @{{.*}}collapsed{{.*}}
void collapsed(float *a, float *b, float *c, float *d) {
  int i; // outer loop counter
  unsigned j; // middle loop couter, leads to unsigned icmp in loop header.
  // k declared in the loop init below
  short l; // inner loop counter
// CHECK: call void @__kmpc_for_static_init_4u(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i32 1, i32 1)
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK: [[CMP:%.+]] = icmp ugt i32 [[UB_VAL]], 119
// CHECK: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// CHECK: [[TRUE]]:
// CHECK: br label %[[SWITCH:[^,]+]]
// CHECK: [[FALSE]]:
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]],
// CHECK: br label %[[SWITCH]]
// CHECK: [[SWITCH]]:
// CHECK: [[UP:%.+]] = phi i32 [ 119, %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// CHECK: store i32 [[UP]], ptr [[UB]],
// CHECK: [[LB_VAL:%.+]] = load i32, ptr [[LB]],
// CHECK: store i32 [[LB_VAL]], ptr [[OMP_IV:%[^,]+]],
//
  #pragma omp parallel for simd collapse(4)

// CHECK: [[IV:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[UB_VAL:%.+]] = load i32, ptr [[UB]]
// CHECK-NEXT: [[CMP:%.+]] = icmp ule i32 [[IV]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP]], label %[[COLL1_BODY:[^,]+]], label %[[COLL1_END:[^,]+]]
  for (i = 1; i < 3; i++) // 2 iterations
    for (j = 2u; j < 5u; j++) //3 iterations
      for (int k = 3; k <= 6; k++) // 4 iterations
        for (l = 4; l < 9; ++l) // 5 iterations
        {
// CHECK: [[COLL1_BODY]]:
// Start of body: calculate i from index:
// CHECK: [[IV1:%.+]] = load i32, ptr [[OMP_IV]]
// Calculation of the loop counters values.
// CHECK: [[CALC_I_1:%.+]] = udiv i32 [[IV1]], 60
// CHECK-NEXT: [[CALC_I_1_MUL1:%.+]] = mul i32 [[CALC_I_1]], 1
// CHECK-NEXT: [[CALC_I_2:%.+]] = add i32 1, [[CALC_I_1_MUL1]]
// CHECK-NEXT: store i32 [[CALC_I_2]], ptr [[LC_I:.+]]

// CHECK: [[IV1_2:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[IV1_2_1:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK-NEXT: [[CALC_J_1:%.+]] = udiv i32 [[IV1_2_1]], 60
// CHECK-NEXT: [[MUL_1:%.+]] = mul i32 [[CALC_J_1]], 60
// CHECK-NEXT: [[SUB_3:%.+]] = sub i32 [[IV1_2]], [[MUL_1]]
// CHECK-NEXT: [[CALC_J_2:%.+]] = udiv i32 [[SUB_3]], 20
// CHECK-NEXT: [[CALC_J_2_MUL1:%.+]] = mul i32 [[CALC_J_2]], 1
// CHECK-NEXT: [[CALC_J_3:%.+]] = add i32 2, [[CALC_J_2_MUL1]]
// CHECK-NEXT: store i32 [[CALC_J_3]], ptr [[LC_J:.+]]

// CHECK: [[IV1_3:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[IV1_3_1:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK-NEXT: [[DIV_1:%.+]] = udiv i32 [[IV1_3_1]], 60
// CHECK-NEXT: [[MUL_2:%.+]] = mul i32 [[DIV_1]], 60
// CHECK-NEXT: [[ADD_3:%.+]] = sub i32 [[IV1_3]], [[MUL_2]]

// CHECK: [[IV1_4:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[IV1_4_1:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK-NEXT: [[DIV_2:%.+]] = udiv i32 [[IV1_4_1]], 60
// CHECK-NEXT: [[MUL_3:%.+]] = mul i32 [[DIV_2]], 60
// CHECK-NEXT: [[SUB_6:%.+]] = sub i32 [[IV1_4]], [[MUL_3]]
// CHECK-NEXT: [[DIV_3:%.+]] = udiv i32 [[SUB_6]], 20
// CHECK-NEXT: [[MUL_4:%.+]] = mul i32 [[DIV_3]], 20
// CHECK-NEXT: [[SUB_7:%.+]] = sub i32 [[ADD_3]], [[MUL_4]]
// CHECK-NEXT: [[DIV_4:%.+]] = udiv i32 [[SUB_7]], 5
// CHECK-NEXT: [[MUL_5:%.+]] = mul i32 [[DIV_4]], 1
// CHECK-NEXT: [[ADD_6:%.+]] = add i32 3, [[MUL_5]]
// CHECK-NEXT: store i32 [[ADD_6]], ptr [[LC_K:.+]]

// CHECK: [[IV1_5:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[IV1_5_1:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK-NEXT: [[DIV_5:%.+]] = udiv i32 [[IV1_5_1]], 60
// CHECK-NEXT: [[MUL_6:%.+]] = mul i32 [[DIV_5]], 60
// CHECK-NEXT: [[ADD_7:%.+]] = sub i32 [[IV1_5]], [[MUL_6]]

// CHECK: [[IV1_6:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[IV1_6_1:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK-NEXT: [[DIV_6:%.+]] = udiv i32 [[IV1_6_1]], 60
// CHECK-NEXT: [[MUL_7:%.+]] = mul i32 [[DIV_6]], 60
// CHECK-NEXT: [[SUB_10:%.+]] = sub i32 [[IV1_6]], [[MUL_7]]
// CHECK-NEXT: [[DIV_7:%.+]] = udiv i32 [[SUB_10]], 20
// CHECK-NEXT: [[MUL_8:%.+]] = mul i32 [[DIV_7]], 20
// CHECK-NEXT: [[ADD_9:%.+]] = sub i32 [[ADD_7]], [[MUL_8]]

// CHECK: [[IV1_7:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[IV1_7_1:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK-NEXT: [[DIV_8:%.+]] = udiv i32 [[IV1_7_1]], 60
// CHECK-NEXT: [[MUL_9:%.+]] = mul i32 [[DIV_8]], 60
// CHECK-NEXT: [[ADD_10:%.+]] = sub i32 [[IV1_7]], [[MUL_9]]

// CHECK: [[IV1_8:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK: [[IV1_8_1:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK-NEXT: [[DIV_3:%.+]] = udiv i32 [[IV1_8_1]], 60
// CHECK-NEXT: [[MUL_4:%.+]] = mul i32 [[DIV_3]], 60
// CHECK-NEXT: [[SUB_7:%.+]] = sub i32 [[IV1_8]], [[MUL_4]]
// CHECK-NEXT: [[DIV_4:%.+]] = udiv i32 [[SUB_7]], 20
// CHECK-NEXT: [[MUL_5:%.+]] = mul i32 [[DIV_4]], 20
// CHECK-NEXT: [[SUB_8:%.+]] = sub i32 [[ADD_10]], [[MUL_5]]
// CHECK-NEXT: [[DIV_5:%.+]] = udiv i32 [[SUB_8]], 5
// CHECK-NEXT: [[MUL_6:%.+]] = mul i32 [[DIV_5]], 5
// CHECK-NEXT: [[SUB_9:%.+]] = sub i32 [[ADD_9]], [[MUL_6]]
// CHECK-NEXT: [[MUL_6:%.+]] = mul i32 [[SUB_9]], 1
// CHECK-NEXT: [[CALC_L_2:%.+]] = add i32 4, [[MUL_6]]
// CHECK-NEXT: [[CALC_L_3:%.+]] = trunc i32 [[CALC_L_2]] to i16
// CHECK-NEXT: store i16 [[CALC_L_3]], ptr [[LC_L:.+]]
// ... loop body ...
// End of body: store into a[i]:
// CHECK: store float [[RESULT:%.+]], ptr [[RESULT_ADDR:%.+]]
    float res = b[j] * c[k];
    a[i] = res * d[l];
// CHECK: [[IV2:%.+]] = load i32, ptr [[OMP_IV]]
// CHECK-NEXT: [[ADD2:%.+]] = add i32 [[IV2]], 1
// CHECK-NEXT: store i32 [[ADD2]], ptr [[OMP_IV]]
// br label %{{[^,]+}}, !llvm.loop ![[COLL1_LOOP_ID]]
// CHECK: [[COLL1_END]]:
  }
// i,j,l are updated; k is not updated.
// CHECK: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})
// CHECK: store i32 3, ptr [[I:%[^,]+]]
// CHECK: store i32 5, ptr [[I:%[^,]+]]
// CHECK: store i16 9, ptr [[I:%[^,]+]]
// CHECK: ret void
}

extern char foo();
extern double globalfloat;

// CHECK-LABEL: define {{.*void}} @{{.*}}widened{{.*}}
void widened(float *a, float *b, float *c, float *d) {
  int i; // outer loop counter
  short j; // inner loop counter
  globalfloat = 1.0;
  int localint = 1;
// CHECK: store double {{.+}}, ptr [[GLOBALFLOAT:@.+]]
// Counter is widened to 64 bits.
// CHECK:     [[MUL:%.+]] = mul nsw i64 2, %{{.+}}
// CHECK-NEXT: [[SUB:%.+]] = sub nsw i64 [[MUL]], 1
// CHECK-NEXT: store i64 [[SUB]], ptr [[OMP_LAST_IT:%[^,]+]],
// CHECK: call void @__kmpc_for_static_init_8(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i64 1, i64 1)
// CHECK-DAG: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// CHECK-DAG: [[OMP_LAST_IT_VAL:%.+]] = load i64, ptr [[OMP_LAST_IT]],
// CHECK: [[CMP:%.+]] = icmp sgt i64 [[UB_VAL]], [[OMP_LAST_IT_VAL]]
// CHECK: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// CHECK: [[TRUE]]:
// CHECK: [[OMP_LAST_IT_VAL:%.+]] = load i64, ptr [[OMP_LAST_IT]],
// CHECK: br label %[[SWITCH:[^,]+]]
// CHECK: [[FALSE]]:
// CHECK: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// CHECK: br label %[[SWITCH]]
// CHECK: [[SWITCH]]:
// CHECK: [[UP:%.+]] = phi i64 [ [[OMP_LAST_IT_VAL]], %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// CHECK: store i64 [[UP]], ptr [[UB]],
// CHECK: [[LB_VAL:%.+]] = load i64, ptr [[LB]],
// CHECK: store i64 [[LB_VAL]], ptr [[OMP_IV:%[^,]+]],
//
  #pragma omp parallel for simd collapse(2) private(globalfloat, localint)

// CHECK: [[IV:%.+]] = load i64, ptr [[OMP_IV]]
// CHECK: [[UB_VAL:%.+]] = load i64, ptr [[UB]]
// CHECK-NEXT: [[CMP:%.+]] = icmp sle i64 [[IV]], [[UB_VAL]]
// CHECK-NEXT: br i1 [[CMP]], label %[[WIDE1_BODY:[^,]+]], label %[[WIDE1_END:[^,]+]]
  for (i = 1; i < 3; i++) // 2 iterations
    for (j = 0; j < foo(); j++) // foo() iterations
  {
// CHECK: [[WIDE1_BODY]]:
// Start of body: calculate i from index:
// CHECK: [[IV1:%.+]] = load i64, ptr [[OMP_IV]]
// Calculation of the loop counters values...
// CHECK: store i32 {{[^,]+}}, ptr [[LC_I:.+]]
// CHECK: [[IV1_2:%.+]] = load i64, ptr [[OMP_IV]]
// CHECK: store i16 {{[^,]+}}, ptr [[LC_J:.+]]
// ... loop body ...
//
// Here we expect store into private double var, not global
// CHECK-NOT: store double {{.+}}, ptr [[GLOBALFLOAT]]
    globalfloat = (float)j/i;
    float res = b[j] * c[j];
// Store into a[i]:
// CHECK: store float [[RESULT:%.+]], ptr [[RESULT_ADDR:%.+]]
    a[i] = res * d[i];
// Then there's a store into private var localint:
// CHECK: store i32 {{.+}}, ptr [[LOCALINT:%[^,]+]]
    localint = (int)j;
// CHECK: [[IV2:%.+]] = load i64, ptr [[OMP_IV]]
// CHECK-NEXT: [[ADD2:%.+]] = add nsw i64 [[IV2]], 1
// CHECK-NEXT: store i64 [[ADD2]], ptr [[OMP_IV]]
//
// br label %{{[^,]+}}, !llvm.loop ![[WIDE1_LOOP_ID]]
// CHECK: [[WIDE1_END]]:
  }
// i,j are updated.
// CHECK: store i32 3, ptr [[I:%[^,]+]]
// CHECK: store i16
//
// Here we expect store into original localint, not its privatized version.
// CHECK-NOT: store i32 {{.+}}, ptr [[LOCALINT]]
  localint = (int)j;
// CHECK: ret void
}

// CHECK-LABEL: if_clause
void if_clause(int a) {
  #pragma omp parallel for simd if(a) schedule(static, 1)
for (int i = 0; i < 10; ++i);
}
// CHECK: call void @__kmpc_for_static_init_4(
// OMP50: [[COND:%.+]] = trunc i8 %{{.+}} to i1
// OMP50: br i1 [[COND]], label {{%?}}[[THEN:.+]], label {{%?}}[[ELSE:.+]]

// OMP50: [[THEN]]:
// OMP45: br label {{.+}}, !llvm.loop ![[VECT:.+]]
// OMP50: br label {{.+}}, !llvm.loop ![[VECT:.+]]
// OMP50: [[ELSE]]:
// OMP50: br label {{.+}}, !llvm.loop ![[NOVECT:.+]]
// CHECK: call void @__kmpc_for_static_fini(

// OMP45: call void @__kmpc_for_static_init_8(ptr {{[^,]+}}, i32 %{{[^,]+}}, i32 34, ptr %{{[^,]+}}, ptr [[LB:%[^,]+]], ptr [[UB:%[^,]+]], ptr [[STRIDE:%[^,]+]], i64 1, i64 1)
// OMP45: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// OMP45: [[CMP:%.+]] = icmp sgt i64 [[UB_VAL]], 15
// OMP45: br i1 [[CMP]], label %[[TRUE:.+]], label %[[FALSE:[^,]+]]
// OMP45: [[TRUE]]:
// OMP45: br label %[[SWITCH:[^,]+]]
// OMP45: [[FALSE]]:
// OMP45: [[UB_VAL:%.+]] = load i64, ptr [[UB]],
// OMP45: br label %[[SWITCH]]
// OMP45: [[SWITCH]]:
// OMP45: [[UP:%.+]] = phi i64 [ 15, %[[TRUE]] ], [ [[UB_VAL]], %[[FALSE]] ]
// OMP45: store i64 [[UP]], ptr [[UB]],
// OMP45: [[LB_VAL:%.+]] = load i64, ptr [[LB]],
// OMP45: store i64 [[LB_VAL]], ptr [[T1_OMP_IV:%[^,]+]],

// ...
// OMP45: [[IV:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP45-NEXT: [[UB_VAL:%.+]] = load i64, ptr [[UB]]
// OMP45-NEXT: [[CMP1:%.+]] = icmp sle i64 [[IV]], [[UB_VAL]]
// OMP45-NEXT: br i1 [[CMP1]], label %[[T1_BODY:.+]], label %[[T1_END:[^,]+]]
// OMP45: [[T1_BODY]]:
// Loop counters i and j updates:
// OMP45: [[IV1:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP45-NEXT: [[I_1:%.+]] = sdiv i64 [[IV1]], 4
// OMP45-NEXT: [[I_1_MUL1:%.+]] = mul nsw i64 [[I_1]], 1
// OMP45-NEXT: [[I_1_ADD0:%.+]] = add nsw i64 0, [[I_1_MUL1]]
// OMP45-NEXT: [[I_2:%.+]] = trunc i64 [[I_1_ADD0]] to i32
// OMP45-NEXT: store i32 [[I_2]], ptr
// OMP45: [[IV2:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP45: [[IV2_1:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP45-NEXT: [[DIV_1:%.+]] = sdiv i64 [[IV2_1]], 4
// OMP45-NEXT: [[MUL_1:%.+]] = mul nsw i64 [[DIV_1]], 4
// OMP45-NEXT: [[J_1:%.+]] = sub nsw i64 [[IV2]], [[MUL_1]]
// OMP45-NEXT: [[J_2:%.+]] = mul nsw i64 [[J_1]], 2
// OMP45-NEXT: [[J_2_ADD0:%.+]] = add nsw i64 0, [[J_2]]
// OMP45-NEXT: store i64 [[J_2_ADD0]], ptr
// simd.for.inc:
// OMP45: [[IV3:%.+]] = load i64, ptr [[T1_OMP_IV]]
// OMP45-NEXT: [[INC:%.+]] = add nsw i64 [[IV3]], 1
// OMP45-NEXT: store i64 [[INC]], ptr
// OMP45-NEXT: br label {{%.+}}
// OMP45: [[T1_END]]:
// OMP45: call void @__kmpc_for_static_fini(ptr {{.+}}, i32 %{{.+}})
// OMP45: ret void

// OMP50-LABEL: parallel_simd_atomic
// OMP50: call i32 @__kmpc_global_thread_num
// OMP50: call void @__kmpc_push_num_threads
// OMP50: call void {{.*}} @__kmpc_fork_call
// OMP50-LABEL: define internal void @_Z20parallel_simd_atomici.omp_outlined
// OMP50: call void @__kmpc_for_static_init_4
// OMP50: omp.inner.for.body:
// OMP50: %{{[0-9]+}} = atomicrmw add ptr %{{[0-9]+}}, i32 1 monotonic, align 4, !llvm.access.group !{{[0-9]+}}

// OMP45-NOT: !{!"llvm.loop.vectorize.enable", i1 false}
// OMP45-DAG: ![[VECT]] = distinct !{![[VECT]], ![[PA:.+]], ![[VM:.+]]}
// OMP45-DAG: ![[PA]] = !{!"llvm.loop.parallel_accesses", !{{.+}}}
// OMP45-DAG: ![[VM]] = !{!"llvm.loop.vectorize.enable", i1 true}
// OMP45-NOT: !{!"llvm.loop.vectorize.enable", i1 false}
// OMP50-DAG: ![[VECT]] = distinct !{![[VECT]], ![[PA:.+]], ![[VM:.+]]}
// OMP50-DAG  ![[PA]] = !{!"llvm.loop.parallel_accesses", !{{.+}}}
// OMP50-DAG: ![[VM]] = !{!"llvm.loop.vectorize.enable", i1 true}
// OMP50-DAG: ![[NOVECT]] = distinct !{![[NOVECT]], ![[NOVM:.+]]}
// OMP50-DAG: ![[NOVM]] = !{!"llvm.loop.vectorize.enable", i1 false}

// TERM_DEBUG-LABEL: bar
int bar() { extern void mayThrow(); mayThrow(); return 0; };

// TERM_DEBUG-LABEL: parallel_simd
void parallel_simd(float *a) {
#pragma omp parallel for simd
  // TERM_DEBUG-NOT: __kmpc_global_thread_num
  // TERM_DEBUG:     invoke noundef i32 {{.*}}bar{{.*}}()
  // TERM_DEBUG:     unwind label %[[TERM_LPAD:[a-zA-Z0-9\.]+]],
  // TERM_DEBUG-NOT: __kmpc_global_thread_num
  // TERM_DEBUG:     [[TERM_LPAD]]
  // TERM_DEBUG:     call void @__clang_call_terminate
  // TERM_DEBUG:     unreachable
  for (unsigned i = 131071; i <= 2147483647; i += 127)
    a[i] += bar();
}
// TERM_DEBUG: !{{[0-9]+}} = !DILocation(line: [[@LINE-11]],
// TERM_DEBUG-NOT: line: 0,

#ifdef OMP5
void parallel_simd_atomic(int a) {
#pragma omp parallel for simd shared(a) num_threads(10)
  for (int i = 0; i < 100; i++) {
  #pragma omp atomic update
    a += 1;
  }
}
#endif // OMP5

#endif // HEADER


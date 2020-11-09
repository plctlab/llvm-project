// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x2_t test_vcreate_i8mf8x2 (vint8mf8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vcreate_i8mf8x2
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vcreate.nxv1i8x2.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_i8mf8x2(op1, op2);
}

vint8mf8x3_t test_vcreate_i8mf8x3 (vint8mf8_t op1, vint8mf8_t op2, vint8mf8_t op3) {
  // CHECK-LABEL: test_vcreate_i8mf8x3
  // CHECK: %{{.*}} = call <vscale x 3 x i8> @llvm.riscv.vcreate.nxv1i8x3.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_i8mf8x3(op1, op2, op3);
}

vint8mf8x4_t test_vcreate_i8mf8x4 (vint8mf8_t op1, vint8mf8_t op2, vint8mf8_t op3, vint8mf8_t op4) {
  // CHECK-LABEL: test_vcreate_i8mf8x4
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcreate.nxv1i8x4.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_i8mf8x4(op1, op2, op3, op4);
}

vint8mf8x5_t test_vcreate_i8mf8x5 (vint8mf8_t op1, vint8mf8_t op2, vint8mf8_t op3, vint8mf8_t op4, vint8mf8_t op5) {
  // CHECK-LABEL: test_vcreate_i8mf8x5
  // CHECK: %{{.*}} = call <vscale x 5 x i8> @llvm.riscv.vcreate.nxv1i8x5.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_i8mf8x5(op1, op2, op3, op4, op5);
}

vint8mf8x6_t test_vcreate_i8mf8x6 (vint8mf8_t op1, vint8mf8_t op2, vint8mf8_t op3, vint8mf8_t op4, vint8mf8_t op5, vint8mf8_t op6) {
  // CHECK-LABEL: test_vcreate_i8mf8x6
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vcreate.nxv1i8x6.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_i8mf8x6(op1, op2, op3, op4, op5, op6);
}

vint8mf8x7_t test_vcreate_i8mf8x7 (vint8mf8_t op1, vint8mf8_t op2, vint8mf8_t op3, vint8mf8_t op4, vint8mf8_t op5, vint8mf8_t op6, vint8mf8_t op7) {
  // CHECK-LABEL: test_vcreate_i8mf8x7
  // CHECK: %{{.*}} = call <vscale x 7 x i8> @llvm.riscv.vcreate.nxv1i8x7.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_i8mf8x7(op1, op2, op3, op4, op5, op6, op7);
}

vint8mf8x8_t test_vcreate_i8mf8x8 (vint8mf8_t op1, vint8mf8_t op2, vint8mf8_t op3, vint8mf8_t op4, vint8mf8_t op5, vint8mf8_t op6, vint8mf8_t op7, vint8mf8_t op8) {
  // CHECK-LABEL: test_vcreate_i8mf8x8
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcreate.nxv1i8x8.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_i8mf8x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint8mf4x2_t test_vcreate_i8mf4x2 (vint8mf4_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vcreate_i8mf4x2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcreate.nxv2i8x2.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_i8mf4x2(op1, op2);
}

vint8mf4x3_t test_vcreate_i8mf4x3 (vint8mf4_t op1, vint8mf4_t op2, vint8mf4_t op3) {
  // CHECK-LABEL: test_vcreate_i8mf4x3
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vcreate.nxv2i8x3.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_i8mf4x3(op1, op2, op3);
}

vint8mf4x4_t test_vcreate_i8mf4x4 (vint8mf4_t op1, vint8mf4_t op2, vint8mf4_t op3, vint8mf4_t op4) {
  // CHECK-LABEL: test_vcreate_i8mf4x4
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcreate.nxv2i8x4.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_i8mf4x4(op1, op2, op3, op4);
}

vint8mf4x5_t test_vcreate_i8mf4x5 (vint8mf4_t op1, vint8mf4_t op2, vint8mf4_t op3, vint8mf4_t op4, vint8mf4_t op5) {
  // CHECK-LABEL: test_vcreate_i8mf4x5
  // CHECK: %{{.*}} = call <vscale x 10 x i8> @llvm.riscv.vcreate.nxv2i8x5.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_i8mf4x5(op1, op2, op3, op4, op5);
}

vint8mf4x6_t test_vcreate_i8mf4x6 (vint8mf4_t op1, vint8mf4_t op2, vint8mf4_t op3, vint8mf4_t op4, vint8mf4_t op5, vint8mf4_t op6) {
  // CHECK-LABEL: test_vcreate_i8mf4x6
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vcreate.nxv2i8x6.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_i8mf4x6(op1, op2, op3, op4, op5, op6);
}

vint8mf4x7_t test_vcreate_i8mf4x7 (vint8mf4_t op1, vint8mf4_t op2, vint8mf4_t op3, vint8mf4_t op4, vint8mf4_t op5, vint8mf4_t op6, vint8mf4_t op7) {
  // CHECK-LABEL: test_vcreate_i8mf4x7
  // CHECK: %{{.*}} = call <vscale x 14 x i8> @llvm.riscv.vcreate.nxv2i8x7.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_i8mf4x7(op1, op2, op3, op4, op5, op6, op7);
}

vint8mf4x8_t test_vcreate_i8mf4x8 (vint8mf4_t op1, vint8mf4_t op2, vint8mf4_t op3, vint8mf4_t op4, vint8mf4_t op5, vint8mf4_t op6, vint8mf4_t op7, vint8mf4_t op8) {
  // CHECK-LABEL: test_vcreate_i8mf4x8
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcreate.nxv2i8x8.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_i8mf4x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint8mf2x2_t test_vcreate_i8mf2x2 (vint8mf2_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vcreate_i8mf2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcreate.nxv4i8x2.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_i8mf2x2(op1, op2);
}

vint8mf2x3_t test_vcreate_i8mf2x3 (vint8mf2_t op1, vint8mf2_t op2, vint8mf2_t op3) {
  // CHECK-LABEL: test_vcreate_i8mf2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vcreate.nxv4i8x3.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_i8mf2x3(op1, op2, op3);
}

vint8mf2x4_t test_vcreate_i8mf2x4 (vint8mf2_t op1, vint8mf2_t op2, vint8mf2_t op3, vint8mf2_t op4) {
  // CHECK-LABEL: test_vcreate_i8mf2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcreate.nxv4i8x4.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_i8mf2x4(op1, op2, op3, op4);
}

vint8mf2x5_t test_vcreate_i8mf2x5 (vint8mf2_t op1, vint8mf2_t op2, vint8mf2_t op3, vint8mf2_t op4, vint8mf2_t op5) {
  // CHECK-LABEL: test_vcreate_i8mf2x5
  // CHECK: %{{.*}} = call <vscale x 20 x i8> @llvm.riscv.vcreate.nxv4i8x5.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_i8mf2x5(op1, op2, op3, op4, op5);
}

vint8mf2x6_t test_vcreate_i8mf2x6 (vint8mf2_t op1, vint8mf2_t op2, vint8mf2_t op3, vint8mf2_t op4, vint8mf2_t op5, vint8mf2_t op6) {
  // CHECK-LABEL: test_vcreate_i8mf2x6
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vcreate.nxv4i8x6.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_i8mf2x6(op1, op2, op3, op4, op5, op6);
}

vint8mf2x7_t test_vcreate_i8mf2x7 (vint8mf2_t op1, vint8mf2_t op2, vint8mf2_t op3, vint8mf2_t op4, vint8mf2_t op5, vint8mf2_t op6, vint8mf2_t op7) {
  // CHECK-LABEL: test_vcreate_i8mf2x7
  // CHECK: %{{.*}} = call <vscale x 28 x i8> @llvm.riscv.vcreate.nxv4i8x7.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_i8mf2x7(op1, op2, op3, op4, op5, op6, op7);
}

vint8mf2x8_t test_vcreate_i8mf2x8 (vint8mf2_t op1, vint8mf2_t op2, vint8mf2_t op3, vint8mf2_t op4, vint8mf2_t op5, vint8mf2_t op6, vint8mf2_t op7, vint8mf2_t op8) {
  // CHECK-LABEL: test_vcreate_i8mf2x8
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcreate.nxv4i8x8.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_i8mf2x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint8m1x2_t test_vcreate_i8m1x2 (vint8m1_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vcreate_i8m1x2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcreate.nxv8i8x2.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_i8m1x2(op1, op2);
}

vint8m1x3_t test_vcreate_i8m1x3 (vint8m1_t op1, vint8m1_t op2, vint8m1_t op3) {
  // CHECK-LABEL: test_vcreate_i8m1x3
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vcreate.nxv8i8x3.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_i8m1x3(op1, op2, op3);
}

vint8m1x4_t test_vcreate_i8m1x4 (vint8m1_t op1, vint8m1_t op2, vint8m1_t op3, vint8m1_t op4) {
  // CHECK-LABEL: test_vcreate_i8m1x4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcreate.nxv8i8x4.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_i8m1x4(op1, op2, op3, op4);
}

vint8m1x5_t test_vcreate_i8m1x5 (vint8m1_t op1, vint8m1_t op2, vint8m1_t op3, vint8m1_t op4, vint8m1_t op5) {
  // CHECK-LABEL: test_vcreate_i8m1x5
  // CHECK: %{{.*}} = call <vscale x 40 x i8> @llvm.riscv.vcreate.nxv8i8x5.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_i8m1x5(op1, op2, op3, op4, op5);
}

vint8m1x6_t test_vcreate_i8m1x6 (vint8m1_t op1, vint8m1_t op2, vint8m1_t op3, vint8m1_t op4, vint8m1_t op5, vint8m1_t op6) {
  // CHECK-LABEL: test_vcreate_i8m1x6
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vcreate.nxv8i8x6.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_i8m1x6(op1, op2, op3, op4, op5, op6);
}

vint8m1x7_t test_vcreate_i8m1x7 (vint8m1_t op1, vint8m1_t op2, vint8m1_t op3, vint8m1_t op4, vint8m1_t op5, vint8m1_t op6, vint8m1_t op7) {
  // CHECK-LABEL: test_vcreate_i8m1x7
  // CHECK: %{{.*}} = call <vscale x 56 x i8> @llvm.riscv.vcreate.nxv8i8x7.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_i8m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vint8m1x8_t test_vcreate_i8m1x8 (vint8m1_t op1, vint8m1_t op2, vint8m1_t op3, vint8m1_t op4, vint8m1_t op5, vint8m1_t op6, vint8m1_t op7, vint8m1_t op8) {
  // CHECK-LABEL: test_vcreate_i8m1x8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcreate.nxv8i8x8.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_i8m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint8m2x2_t test_vcreate_i8m2x2 (vint8m2_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vcreate_i8m2x2
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcreate.nxv16i8x2.{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vcreate_i8m2x2(op1, op2);
}

vint8m2x3_t test_vcreate_i8m2x3 (vint8m2_t op1, vint8m2_t op2, vint8m2_t op3) {
  // CHECK-LABEL: test_vcreate_i8m2x3
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vcreate.nxv16i8x3.{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vcreate_i8m2x3(op1, op2, op3);
}

vint8m2x4_t test_vcreate_i8m2x4 (vint8m2_t op1, vint8m2_t op2, vint8m2_t op3, vint8m2_t op4) {
  // CHECK-LABEL: test_vcreate_i8m2x4
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcreate.nxv16i8x4.{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vcreate_i8m2x4(op1, op2, op3, op4);
}

vint8m4x2_t test_vcreate_i8m4x2 (vint8m4_t op1, vint8m4_t op2) {
  // CHECK-LABEL: test_vcreate_i8m4x2
  // CHECK: %{{.*}} = call <vscale x 54 x i8> @llvm.riscv.vcreate.nxv32i8x2.{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vcreate_i8m4x2(op1, op2);
}

vint16mf4x2_t test_vcreate_i16mf4x2 (vint16mf4_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vcreate_i16mf4x2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vcreate.nxv1i16x2.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_i16mf4x2(op1, op2);
}

vint16mf4x3_t test_vcreate_i16mf4x3 (vint16mf4_t op1, vint16mf4_t op2, vint16mf4_t op3) {
  // CHECK-LABEL: test_vcreate_i16mf4x3
  // CHECK: %{{.*}} = call <vscale x 3 x i16> @llvm.riscv.vcreate.nxv1i16x3.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_i16mf4x3(op1, op2, op3);
}

vint16mf4x4_t test_vcreate_i16mf4x4 (vint16mf4_t op1, vint16mf4_t op2, vint16mf4_t op3, vint16mf4_t op4) {
  // CHECK-LABEL: test_vcreate_i16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcreate.nxv1i16x4.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_i16mf4x4(op1, op2, op3, op4);
}

vint16mf4x5_t test_vcreate_i16mf4x5 (vint16mf4_t op1, vint16mf4_t op2, vint16mf4_t op3, vint16mf4_t op4, vint16mf4_t op5) {
  // CHECK-LABEL: test_vcreate_i16mf4x5
  // CHECK: %{{.*}} = call <vscale x 5 x i16> @llvm.riscv.vcreate.nxv1i16x5.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_i16mf4x5(op1, op2, op3, op4, op5);
}

vint16mf4x6_t test_vcreate_i16mf4x6 (vint16mf4_t op1, vint16mf4_t op2, vint16mf4_t op3, vint16mf4_t op4, vint16mf4_t op5, vint16mf4_t op6) {
  // CHECK-LABEL: test_vcreate_i16mf4x6
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vcreate.nxv1i16x6.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_i16mf4x6(op1, op2, op3, op4, op5, op6);
}

vint16mf4x7_t test_vcreate_i16mf4x7 (vint16mf4_t op1, vint16mf4_t op2, vint16mf4_t op3, vint16mf4_t op4, vint16mf4_t op5, vint16mf4_t op6, vint16mf4_t op7) {
  // CHECK-LABEL: test_vcreate_i16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vcreate.nxv1i16x7.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_i16mf4x7(op1, op2, op3, op4, op5, op6, op7);
}

vint16mf4x8_t test_vcreate_i16mf4x8 (vint16mf4_t op1, vint16mf4_t op2, vint16mf4_t op3, vint16mf4_t op4, vint16mf4_t op5, vint16mf4_t op6, vint16mf4_t op7, vint16mf4_t op8) {
  // CHECK-LABEL: test_vcreate_i16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcreate.nxv1i16x8.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_i16mf4x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint16mf2x2_t test_vcreate_i16mf2x2 (vint16mf2_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vcreate_i16mf2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcreate.nxv2i16x2.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_i16mf2x2(op1, op2);
}

vint16mf2x3_t test_vcreate_i16mf2x3 (vint16mf2_t op1, vint16mf2_t op2, vint16mf2_t op3) {
  // CHECK-LABEL: test_vcreate_i16mf2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vcreate.nxv2i16x3.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_i16mf2x3(op1, op2, op3);
}

vint16mf2x4_t test_vcreate_i16mf2x4 (vint16mf2_t op1, vint16mf2_t op2, vint16mf2_t op3, vint16mf2_t op4) {
  // CHECK-LABEL: test_vcreate_i16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcreate.nxv2i16x4.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_i16mf2x4(op1, op2, op3, op4);
}

vint16mf2x5_t test_vcreate_i16mf2x5 (vint16mf2_t op1, vint16mf2_t op2, vint16mf2_t op3, vint16mf2_t op4, vint16mf2_t op5) {
  // CHECK-LABEL: test_vcreate_i16mf2x5
  // CHECK: %{{.*}} = call <vscale x 10 x i16> @llvm.riscv.vcreate.nxv2i16x5.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_i16mf2x5(op1, op2, op3, op4, op5);
}

vint16mf2x6_t test_vcreate_i16mf2x6 (vint16mf2_t op1, vint16mf2_t op2, vint16mf2_t op3, vint16mf2_t op4, vint16mf2_t op5, vint16mf2_t op6) {
  // CHECK-LABEL: test_vcreate_i16mf2x6
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vcreate.nxv2i16x6.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_i16mf2x6(op1, op2, op3, op4, op5, op6);
}

vint16mf2x7_t test_vcreate_i16mf2x7 (vint16mf2_t op1, vint16mf2_t op2, vint16mf2_t op3, vint16mf2_t op4, vint16mf2_t op5, vint16mf2_t op6, vint16mf2_t op7) {
  // CHECK-LABEL: test_vcreate_i16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vcreate.nxv2i16x7.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_i16mf2x7(op1, op2, op3, op4, op5, op6, op7);
}

vint16mf2x8_t test_vcreate_i16mf2x8 (vint16mf2_t op1, vint16mf2_t op2, vint16mf2_t op3, vint16mf2_t op4, vint16mf2_t op5, vint16mf2_t op6, vint16mf2_t op7, vint16mf2_t op8) {
  // CHECK-LABEL: test_vcreate_i16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcreate.nxv2i16x8.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_i16mf2x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint16m1x2_t test_vcreate_i16m1x2 (vint16m1_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vcreate_i16m1x2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcreate.nxv4i16x2.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_i16m1x2(op1, op2);
}

vint16m1x3_t test_vcreate_i16m1x3 (vint16m1_t op1, vint16m1_t op2, vint16m1_t op3) {
  // CHECK-LABEL: test_vcreate_i16m1x3
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vcreate.nxv4i16x3.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_i16m1x3(op1, op2, op3);
}

vint16m1x4_t test_vcreate_i16m1x4 (vint16m1_t op1, vint16m1_t op2, vint16m1_t op3, vint16m1_t op4) {
  // CHECK-LABEL: test_vcreate_i16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcreate.nxv4i16x4.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_i16m1x4(op1, op2, op3, op4);
}

vint16m1x5_t test_vcreate_i16m1x5 (vint16m1_t op1, vint16m1_t op2, vint16m1_t op3, vint16m1_t op4, vint16m1_t op5) {
  // CHECK-LABEL: test_vcreate_i16m1x5
  // CHECK: %{{.*}} = call <vscale x 20 x i16> @llvm.riscv.vcreate.nxv4i16x5.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_i16m1x5(op1, op2, op3, op4, op5);
}

vint16m1x6_t test_vcreate_i16m1x6 (vint16m1_t op1, vint16m1_t op2, vint16m1_t op3, vint16m1_t op4, vint16m1_t op5, vint16m1_t op6) {
  // CHECK-LABEL: test_vcreate_i16m1x6
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vcreate.nxv4i16x6.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_i16m1x6(op1, op2, op3, op4, op5, op6);
}

vint16m1x7_t test_vcreate_i16m1x7 (vint16m1_t op1, vint16m1_t op2, vint16m1_t op3, vint16m1_t op4, vint16m1_t op5, vint16m1_t op6, vint16m1_t op7) {
  // CHECK-LABEL: test_vcreate_i16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vcreate.nxv4i16x7.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_i16m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vint16m1x8_t test_vcreate_i16m1x8 (vint16m1_t op1, vint16m1_t op2, vint16m1_t op3, vint16m1_t op4, vint16m1_t op5, vint16m1_t op6, vint16m1_t op7, vint16m1_t op8) {
  // CHECK-LABEL: test_vcreate_i16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcreate.nxv4i16x8.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_i16m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint16m2x2_t test_vcreate_i16m2x2 (vint16m2_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vcreate_i16m2x2
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcreate.nxv8i16x2.{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vcreate_i16m2x2(op1, op2);
}

vint16m2x3_t test_vcreate_i16m2x3 (vint16m2_t op1, vint16m2_t op2, vint16m2_t op3) {
  // CHECK-LABEL: test_vcreate_i16m2x3
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vcreate.nxv8i16x3.{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vcreate_i16m2x3(op1, op2, op3);
}

vint16m2x4_t test_vcreate_i16m2x4 (vint16m2_t op1, vint16m2_t op2, vint16m2_t op3, vint16m2_t op4) {
  // CHECK-LABEL: test_vcreate_i16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcreate.nxv8i16x4.{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vcreate_i16m2x4(op1, op2, op3, op4);
}

vint16m4x2_t test_vcreate_i16m4x2 (vint16m4_t op1, vint16m4_t op2) {
  // CHECK-LABEL: test_vcreate_i16m4x2
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcreate.nxv16i16x2.{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vcreate_i16m4x2(op1, op2);
}

vint32mf2x2_t test_vcreate_i32mf2x2 (vint32mf2_t op1, vint32mf2_t op2) {
  // CHECK-LABEL: test_vcreate_i32mf2x2
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vcreate.nxv1i32x2.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_i32mf2x2(op1, op2);
}

vint32mf2x3_t test_vcreate_i32mf2x3 (vint32mf2_t op1, vint32mf2_t op2, vint32mf2_t op3) {
  // CHECK-LABEL: test_vcreate_i32mf2x3
  // CHECK: %{{.*}} = call <vscale x 3 x i32> @llvm.riscv.vcreate.nxv1i32x3.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_i32mf2x3(op1, op2, op3);
}

vint32mf2x4_t test_vcreate_i32mf2x4 (vint32mf2_t op1, vint32mf2_t op2, vint32mf2_t op3, vint32mf2_t op4) {
  // CHECK-LABEL: test_vcreate_i32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcreate.nxv1i32x4.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_i32mf2x4(op1, op2, op3, op4);
}

vint32mf2x5_t test_vcreate_i32mf2x5 (vint32mf2_t op1, vint32mf2_t op2, vint32mf2_t op3, vint32mf2_t op4, vint32mf2_t op5) {
  // CHECK-LABEL: test_vcreate_i32mf2x5
  // CHECK: %{{.*}} = call <vscale x 5 x i32> @llvm.riscv.vcreate.nxv1i32x5.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_i32mf2x5(op1, op2, op3, op4, op5);
}

vint32mf2x6_t test_vcreate_i32mf2x6 (vint32mf2_t op1, vint32mf2_t op2, vint32mf2_t op3, vint32mf2_t op4, vint32mf2_t op5, vint32mf2_t op6) {
  // CHECK-LABEL: test_vcreate_i32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vcreate.nxv1i32x6.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_i32mf2x6(op1, op2, op3, op4, op5, op6);
}

vint32mf2x7_t test_vcreate_i32mf2x7 (vint32mf2_t op1, vint32mf2_t op2, vint32mf2_t op3, vint32mf2_t op4, vint32mf2_t op5, vint32mf2_t op6, vint32mf2_t op7) {
  // CHECK-LABEL: test_vcreate_i32mf2x7
  // CHECK: %{{.*}} = call <vscale x 7 x i32> @llvm.riscv.vcreate.nxv1i32x7.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_i32mf2x7(op1, op2, op3, op4, op5, op6, op7);
}

vint32mf2x8_t test_vcreate_i32mf2x8 (vint32mf2_t op1, vint32mf2_t op2, vint32mf2_t op3, vint32mf2_t op4, vint32mf2_t op5, vint32mf2_t op6, vint32mf2_t op7, vint32mf2_t op8) {
  // CHECK-LABEL: test_vcreate_i32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcreate.nxv1i32x8.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_i32mf2x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint32m1x2_t test_vcreate_i32m1x2 (vint32m1_t op1, vint32m1_t op2) {
  // CHECK-LABEL: test_vcreate_i32m1x2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcreate.nxv2i32x2.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_i32m1x2(op1, op2);
}

vint32m1x3_t test_vcreate_i32m1x3 (vint32m1_t op1, vint32m1_t op2, vint32m1_t op3) {
  // CHECK-LABEL: test_vcreate_i32m1x3
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vcreate.nxv2i32x3.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_i32m1x3(op1, op2, op3);
}

vint32m1x4_t test_vcreate_i32m1x4 (vint32m1_t op1, vint32m1_t op2, vint32m1_t op3, vint32m1_t op4) {
  // CHECK-LABEL: test_vcreate_i32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcreate.nxv2i32x4.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_i32m1x4(op1, op2, op3, op4);
}

vint32m1x5_t test_vcreate_i32m1x5 (vint32m1_t op1, vint32m1_t op2, vint32m1_t op3, vint32m1_t op4, vint32m1_t op5) {
  // CHECK-LABEL: test_vcreate_i32m1x5
  // CHECK: %{{.*}} = call <vscale x 10 x i32> @llvm.riscv.vcreate.nxv2i32x5.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_i32m1x5(op1, op2, op3, op4, op5);
}

vint32m1x6_t test_vcreate_i32m1x6 (vint32m1_t op1, vint32m1_t op2, vint32m1_t op3, vint32m1_t op4, vint32m1_t op5, vint32m1_t op6) {
  // CHECK-LABEL: test_vcreate_i32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vcreate.nxv2i32x6.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_i32m1x6(op1, op2, op3, op4, op5, op6);
}

vint32m1x7_t test_vcreate_i32m1x7 (vint32m1_t op1, vint32m1_t op2, vint32m1_t op3, vint32m1_t op4, vint32m1_t op5, vint32m1_t op6, vint32m1_t op7) {
  // CHECK-LABEL: test_vcreate_i32m1x7
  // CHECK: %{{.*}} = call <vscale x 14 x i32> @llvm.riscv.vcreate.nxv2i32x7.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_i32m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vint32m1x8_t test_vcreate_i32m1x8 (vint32m1_t op1, vint32m1_t op2, vint32m1_t op3, vint32m1_t op4, vint32m1_t op5, vint32m1_t op6, vint32m1_t op7, vint32m1_t op8) {
  // CHECK-LABEL: test_vcreate_i32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcreate.nxv2i32x8.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_i32m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint32m2x2_t test_vcreate_i32m2x2 (vint32m2_t op1, vint32m2_t op2) {
  // CHECK-LABEL: test_vcreate_i32m2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcreate.nxv4i32x2.{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vcreate_i32m2x2(op1, op2);
}

vint32m2x3_t test_vcreate_i32m2x3 (vint32m2_t op1, vint32m2_t op2, vint32m2_t op3) {
  // CHECK-LABEL: test_vcreate_i32m2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vcreate.nxv4i32x3.{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vcreate_i32m2x3(op1, op2, op3);
}

vint32m2x4_t test_vcreate_i32m2x4 (vint32m2_t op1, vint32m2_t op2, vint32m2_t op3, vint32m2_t op4) {
  // CHECK-LABEL: test_vcreate_i32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcreate.nxv4i32x4.{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vcreate_i32m2x4(op1, op2, op3, op4);
}

vint32m4x2_t test_vcreate_i32m4x2 (vint32m4_t op1, vint32m4_t op2) {
  // CHECK-LABEL: test_vcreate_i32m4x2
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcreate.nxv8i32x2.{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vcreate_i32m4x2(op1, op2);
}

vint64m1x2_t test_vcreate_i64m1x2 (vint64m1_t op1, vint64m1_t op2) {
  // CHECK-LABEL: test_vcreate_i64m1x2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vcreate.nxv1i64x2.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_i64m1x2(op1, op2);
}

vint64m1x3_t test_vcreate_i64m1x3 (vint64m1_t op1, vint64m1_t op2, vint64m1_t op3) {
  // CHECK-LABEL: test_vcreate_i64m1x3
  // CHECK: %{{.*}} = call <vscale x 3 x i64> @llvm.riscv.vcreate.nxv1i64x3.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_i64m1x3(op1, op2, op3);
}

vint64m1x4_t test_vcreate_i64m1x4 (vint64m1_t op1, vint64m1_t op2, vint64m1_t op3, vint64m1_t op4) {
  // CHECK-LABEL: test_vcreate_i64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcreate.nxv1i64x4.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_i64m1x4(op1, op2, op3, op4);
}

vint64m1x5_t test_vcreate_i64m1x5 (vint64m1_t op1, vint64m1_t op2, vint64m1_t op3, vint64m1_t op4, vint64m1_t op5) {
  // CHECK-LABEL: test_vcreate_i64m1x5
  // CHECK: %{{.*}} = call <vscale x 5 x i64> @llvm.riscv.vcreate.nxv1i64x5.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_i64m1x5(op1, op2, op3, op4, op5);
}

vint64m1x6_t test_vcreate_i64m1x6 (vint64m1_t op1, vint64m1_t op2, vint64m1_t op3, vint64m1_t op4, vint64m1_t op5, vint64m1_t op6) {
  // CHECK-LABEL: test_vcreate_i64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vcreate.nxv1i64x6.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_i64m1x6(op1, op2, op3, op4, op5, op6);
}

vint64m1x7_t test_vcreate_i64m1x7 (vint64m1_t op1, vint64m1_t op2, vint64m1_t op3, vint64m1_t op4, vint64m1_t op5, vint64m1_t op6, vint64m1_t op7) {
  // CHECK-LABEL: test_vcreate_i64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vcreate.nxv1i64x7.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_i64m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vint64m1x8_t test_vcreate_i64m1x8 (vint64m1_t op1, vint64m1_t op2, vint64m1_t op3, vint64m1_t op4, vint64m1_t op5, vint64m1_t op6, vint64m1_t op7, vint64m1_t op8) {
  // CHECK-LABEL: test_vcreate_i64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcreate.nxv1i64x8.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_i64m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vint64m2x2_t test_vcreate_i64m2x2 (vint64m2_t op1, vint64m2_t op2) {
  // CHECK-LABEL: test_vcreate_i64m2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcreate.nxv2i64x2.{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vcreate_i64m2x2(op1, op2);
}

vint64m2x3_t test_vcreate_i64m2x3 (vint64m2_t op1, vint64m2_t op2, vint64m2_t op3) {
  // CHECK-LABEL: test_vcreate_i64m2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vcreate.nxv2i64x3.{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vcreate_i64m2x3(op1, op2, op3);
}

vint64m2x4_t test_vcreate_i64m2x4 (vint64m2_t op1, vint64m2_t op2, vint64m2_t op3, vint64m2_t op4) {
  // CHECK-LABEL: test_vcreate_i64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcreate.nxv2i64x4.{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vcreate_i64m2x4(op1, op2, op3, op4);
}

vint64m4x2_t test_vcreate_i64m4x2 (vint64m4_t op1, vint64m4_t op2) {
  // CHECK-LABEL: test_vcreate_i64m4x2
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcreate.nxv4i64x2.{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vcreate_i64m4x2(op1, op2);
}

vuint8mf8x2_t test_vcreate_u8mf8x2 (vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vcreate_u8mf8x2
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vcreate.nxv1i8x2.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_u8mf8x2(op1, op2);
}

vuint8mf8x3_t test_vcreate_u8mf8x3 (vuint8mf8_t op1, vuint8mf8_t op2, vuint8mf8_t op3) {
  // CHECK-LABEL: test_vcreate_u8mf8x3
  // CHECK: %{{.*}} = call <vscale x 3 x i8> @llvm.riscv.vcreate.nxv1i8x3.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_u8mf8x3(op1, op2, op3);
}

vuint8mf8x4_t test_vcreate_u8mf8x4 (vuint8mf8_t op1, vuint8mf8_t op2, vuint8mf8_t op3, vuint8mf8_t op4) {
  // CHECK-LABEL: test_vcreate_u8mf8x4
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcreate.nxv1i8x4.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_u8mf8x4(op1, op2, op3, op4);
}

vuint8mf8x5_t test_vcreate_u8mf8x5 (vuint8mf8_t op1, vuint8mf8_t op2, vuint8mf8_t op3, vuint8mf8_t op4, vuint8mf8_t op5) {
  // CHECK-LABEL: test_vcreate_u8mf8x5
  // CHECK: %{{.*}} = call <vscale x 5 x i8> @llvm.riscv.vcreate.nxv1i8x5.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_u8mf8x5(op1, op2, op3, op4, op5);
}

vuint8mf8x6_t test_vcreate_u8mf8x6 (vuint8mf8_t op1, vuint8mf8_t op2, vuint8mf8_t op3, vuint8mf8_t op4, vuint8mf8_t op5, vuint8mf8_t op6) {
  // CHECK-LABEL: test_vcreate_u8mf8x6
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vcreate.nxv1i8x6.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_u8mf8x6(op1, op2, op3, op4, op5, op6);
}

vuint8mf8x7_t test_vcreate_u8mf8x7 (vuint8mf8_t op1, vuint8mf8_t op2, vuint8mf8_t op3, vuint8mf8_t op4, vuint8mf8_t op5, vuint8mf8_t op6, vuint8mf8_t op7) {
  // CHECK-LABEL: test_vcreate_u8mf8x7
  // CHECK: %{{.*}} = call <vscale x 7 x i8> @llvm.riscv.vcreate.nxv1i8x7.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_u8mf8x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint8mf8x8_t test_vcreate_u8mf8x8 (vuint8mf8_t op1, vuint8mf8_t op2, vuint8mf8_t op3, vuint8mf8_t op4, vuint8mf8_t op5, vuint8mf8_t op6, vuint8mf8_t op7, vuint8mf8_t op8) {
  // CHECK-LABEL: test_vcreate_u8mf8x8
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcreate.nxv1i8x8.{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcreate_u8mf8x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint8mf4x2_t test_vcreate_u8mf4x2 (vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vcreate_u8mf4x2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcreate.nxv2i8x2.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_u8mf4x2(op1, op2);
}

vuint8mf4x3_t test_vcreate_u8mf4x3 (vuint8mf4_t op1, vuint8mf4_t op2, vuint8mf4_t op3) {
  // CHECK-LABEL: test_vcreate_u8mf4x3
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vcreate.nxv2i8x3.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_u8mf4x3(op1, op2, op3);
}

vuint8mf4x4_t test_vcreate_u8mf4x4 (vuint8mf4_t op1, vuint8mf4_t op2, vuint8mf4_t op3, vuint8mf4_t op4) {
  // CHECK-LABEL: test_vcreate_u8mf4x4
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcreate.nxv2i8x4.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_u8mf4x4(op1, op2, op3, op4);
}

vuint8mf4x5_t test_vcreate_u8mf4x5 (vuint8mf4_t op1, vuint8mf4_t op2, vuint8mf4_t op3, vuint8mf4_t op4, vuint8mf4_t op5) {
  // CHECK-LABEL: test_vcreate_u8mf4x5
  // CHECK: %{{.*}} = call <vscale x 10 x i8> @llvm.riscv.vcreate.nxv2i8x5.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_u8mf4x5(op1, op2, op3, op4, op5);
}

vuint8mf4x6_t test_vcreate_u8mf4x6 (vuint8mf4_t op1, vuint8mf4_t op2, vuint8mf4_t op3, vuint8mf4_t op4, vuint8mf4_t op5, vuint8mf4_t op6) {
  // CHECK-LABEL: test_vcreate_u8mf4x6
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vcreate.nxv2i8x6.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_u8mf4x6(op1, op2, op3, op4, op5, op6);
}

vuint8mf4x7_t test_vcreate_u8mf4x7 (vuint8mf4_t op1, vuint8mf4_t op2, vuint8mf4_t op3, vuint8mf4_t op4, vuint8mf4_t op5, vuint8mf4_t op6, vuint8mf4_t op7) {
  // CHECK-LABEL: test_vcreate_u8mf4x7
  // CHECK: %{{.*}} = call <vscale x 14 x i8> @llvm.riscv.vcreate.nxv2i8x7.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_u8mf4x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint8mf4x8_t test_vcreate_u8mf4x8 (vuint8mf4_t op1, vuint8mf4_t op2, vuint8mf4_t op3, vuint8mf4_t op4, vuint8mf4_t op5, vuint8mf4_t op6, vuint8mf4_t op7, vuint8mf4_t op8) {
  // CHECK-LABEL: test_vcreate_u8mf4x8
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcreate.nxv2i8x8.{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcreate_u8mf4x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint8mf2x2_t test_vcreate_u8mf2x2 (vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vcreate_u8mf2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcreate.nxv4i8x2.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_u8mf2x2(op1, op2);
}

vuint8mf2x3_t test_vcreate_u8mf2x3 (vuint8mf2_t op1, vuint8mf2_t op2, vuint8mf2_t op3) {
  // CHECK-LABEL: test_vcreate_u8mf2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vcreate.nxv4i8x3.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_u8mf2x3(op1, op2, op3);
}

vuint8mf2x4_t test_vcreate_u8mf2x4 (vuint8mf2_t op1, vuint8mf2_t op2, vuint8mf2_t op3, vuint8mf2_t op4) {
  // CHECK-LABEL: test_vcreate_u8mf2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcreate.nxv4i8x4.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_u8mf2x4(op1, op2, op3, op4);
}

vuint8mf2x5_t test_vcreate_u8mf2x5 (vuint8mf2_t op1, vuint8mf2_t op2, vuint8mf2_t op3, vuint8mf2_t op4, vuint8mf2_t op5) {
  // CHECK-LABEL: test_vcreate_u8mf2x5
  // CHECK: %{{.*}} = call <vscale x 20 x i8> @llvm.riscv.vcreate.nxv4i8x5.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_u8mf2x5(op1, op2, op3, op4, op5);
}

vuint8mf2x6_t test_vcreate_u8mf2x6 (vuint8mf2_t op1, vuint8mf2_t op2, vuint8mf2_t op3, vuint8mf2_t op4, vuint8mf2_t op5, vuint8mf2_t op6) {
  // CHECK-LABEL: test_vcreate_u8mf2x6
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vcreate.nxv4i8x6.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_u8mf2x6(op1, op2, op3, op4, op5, op6);
}

vuint8mf2x7_t test_vcreate_u8mf2x7 (vuint8mf2_t op1, vuint8mf2_t op2, vuint8mf2_t op3, vuint8mf2_t op4, vuint8mf2_t op5, vuint8mf2_t op6, vuint8mf2_t op7) {
  // CHECK-LABEL: test_vcreate_u8mf2x7
  // CHECK: %{{.*}} = call <vscale x 28 x i8> @llvm.riscv.vcreate.nxv4i8x7.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_u8mf2x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint8mf2x8_t test_vcreate_u8mf2x8 (vuint8mf2_t op1, vuint8mf2_t op2, vuint8mf2_t op3, vuint8mf2_t op4, vuint8mf2_t op5, vuint8mf2_t op6, vuint8mf2_t op7, vuint8mf2_t op8) {
  // CHECK-LABEL: test_vcreate_u8mf2x8
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcreate.nxv4i8x8.{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcreate_u8mf2x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint8m1x2_t test_vcreate_u8m1x2 (vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vcreate_u8m1x2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcreate.nxv8i8x2.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_u8m1x2(op1, op2);
}

vuint8m1x3_t test_vcreate_u8m1x3 (vuint8m1_t op1, vuint8m1_t op2, vuint8m1_t op3) {
  // CHECK-LABEL: test_vcreate_u8m1x3
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vcreate.nxv8i8x3.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_u8m1x3(op1, op2, op3);
}

vuint8m1x4_t test_vcreate_u8m1x4 (vuint8m1_t op1, vuint8m1_t op2, vuint8m1_t op3, vuint8m1_t op4) {
  // CHECK-LABEL: test_vcreate_u8m1x4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcreate.nxv8i8x4.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_u8m1x4(op1, op2, op3, op4);
}

vuint8m1x5_t test_vcreate_u8m1x5 (vuint8m1_t op1, vuint8m1_t op2, vuint8m1_t op3, vuint8m1_t op4, vuint8m1_t op5) {
  // CHECK-LABEL: test_vcreate_u8m1x5
  // CHECK: %{{.*}} = call <vscale x 40 x i8> @llvm.riscv.vcreate.nxv8i8x5.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_u8m1x5(op1, op2, op3, op4, op5);
}

vuint8m1x6_t test_vcreate_u8m1x6 (vuint8m1_t op1, vuint8m1_t op2, vuint8m1_t op3, vuint8m1_t op4, vuint8m1_t op5, vuint8m1_t op6) {
  // CHECK-LABEL: test_vcreate_u8m1x6
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vcreate.nxv8i8x6.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_u8m1x6(op1, op2, op3, op4, op5, op6);
}

vuint8m1x7_t test_vcreate_u8m1x7 (vuint8m1_t op1, vuint8m1_t op2, vuint8m1_t op3, vuint8m1_t op4, vuint8m1_t op5, vuint8m1_t op6, vuint8m1_t op7) {
  // CHECK-LABEL: test_vcreate_u8m1x7
  // CHECK: %{{.*}} = call <vscale x 56 x i8> @llvm.riscv.vcreate.nxv8i8x7.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_u8m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint8m1x8_t test_vcreate_u8m1x8 (vuint8m1_t op1, vuint8m1_t op2, vuint8m1_t op3, vuint8m1_t op4, vuint8m1_t op5, vuint8m1_t op6, vuint8m1_t op7, vuint8m1_t op8) {
  // CHECK-LABEL: test_vcreate_u8m1x8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcreate.nxv8i8x8.{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcreate_u8m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint8m2x2_t test_vcreate_u8m2x2 (vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vcreate_u8m2x2
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcreate.nxv16i8x2.{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vcreate_u8m2x2(op1, op2);
}

vuint8m2x3_t test_vcreate_u8m2x3 (vuint8m2_t op1, vuint8m2_t op2, vuint8m2_t op3) {
  // CHECK-LABEL: test_vcreate_u8m2x3
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vcreate.nxv16i8x3.{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vcreate_u8m2x3(op1, op2, op3);
}

vuint8m2x4_t test_vcreate_u8m2x4 (vuint8m2_t op1, vuint8m2_t op2, vuint8m2_t op3, vuint8m2_t op4) {
  // CHECK-LABEL: test_vcreate_u8m2x4
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcreate.nxv16i8x4.{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vcreate_u8m2x4(op1, op2, op3, op4);
}

vuint8m4x2_t test_vcreate_u8m4x2 (vuint8m4_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vcreate_u8m4x2
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcreate.nxv32i8x2.{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vcreate_u8m4x2(op1, op2);
}

vuint16mf4x2_t test_vcreate_u16mf4x2 (vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vcreate_u16mf4x2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vcreate.nxv1i16x2.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_u16mf4x2(op1, op2);
}

vuint16mf4x3_t test_vcreate_u16mf4x3 (vuint16mf4_t op1, vuint16mf4_t op2, vuint16mf4_t op3) {
  // CHECK-LABEL: test_vcreate_u16mf4x3
  // CHECK: %{{.*}} = call <vscale x 3 x i16> @llvm.riscv.vcreate.nxv1i16x3.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_u16mf4x3(op1, op2, op3);
}

vuint16mf4x4_t test_vcreate_u16mf4x4 (vuint16mf4_t op1, vuint16mf4_t op2, vuint16mf4_t op3, vuint16mf4_t op4) {
  // CHECK-LABEL: test_vcreate_u16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcreate.nxv1i16x4.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_u16mf4x4(op1, op2, op3, op4);
}

vuint16mf4x5_t test_vcreate_u16mf4x5 (vuint16mf4_t op1, vuint16mf4_t op2, vuint16mf4_t op3, vuint16mf4_t op4, vuint16mf4_t op5) {
  // CHECK-LABEL: test_vcreate_u16mf4x5
  // CHECK: %{{.*}} = call <vscale x 5 x i16> @llvm.riscv.vcreate.nxv1i16x5.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_u16mf4x5(op1, op2, op3, op4, op5);
}

vuint16mf4x6_t test_vcreate_u16mf4x6 (vuint16mf4_t op1, vuint16mf4_t op2, vuint16mf4_t op3, vuint16mf4_t op4, vuint16mf4_t op5, vuint16mf4_t op6) {
  // CHECK-LABEL: test_vcreate_u16mf4x6
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vcreate.nxv1i16x6.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_u16mf4x6(op1, op2, op3, op4, op5, op6);
}

vuint16mf4x7_t test_vcreate_u16mf4x7 (vuint16mf4_t op1, vuint16mf4_t op2, vuint16mf4_t op3, vuint16mf4_t op4, vuint16mf4_t op5, vuint16mf4_t op6, vuint16mf4_t op7) {
  // CHECK-LABEL: test_vcreate_u16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vcreate.nxv1i16x7.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_u16mf4x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint16mf4x8_t test_vcreate_u16mf4x8 (vuint16mf4_t op1, vuint16mf4_t op2, vuint16mf4_t op3, vuint16mf4_t op4, vuint16mf4_t op5, vuint16mf4_t op6, vuint16mf4_t op7, vuint16mf4_t op8) {
  // CHECK-LABEL: test_vcreate_u16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcreate.nxv1i16x8.{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcreate_u16mf4x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint16mf2x2_t test_vcreate_u16mf2x2 (vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vcreate_u16mf2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcreate.nxv2i16x2.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_u16mf2x2(op1, op2);
}

vuint16mf2x3_t test_vcreate_u16mf2x3 (vuint16mf2_t op1, vuint16mf2_t op2, vuint16mf2_t op3) {
  // CHECK-LABEL: test_vcreate_u16mf2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vcreate.nxv2i16x3.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_u16mf2x3(op1, op2, op3);
}

vuint16mf2x4_t test_vcreate_u16mf2x4 (vuint16mf2_t op1, vuint16mf2_t op2, vuint16mf2_t op3, vuint16mf2_t op4) {
  // CHECK-LABEL: test_vcreate_u16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcreate.nxv2i16x4.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_u16mf2x4(op1, op2, op3, op4);
}

vuint16mf2x5_t test_vcreate_u16mf2x5 (vuint16mf2_t op1, vuint16mf2_t op2, vuint16mf2_t op3, vuint16mf2_t op4, vuint16mf2_t op5) {
  // CHECK-LABEL: test_vcreate_u16mf2x5
  // CHECK: %{{.*}} = call <vscale x 10 x i16> @llvm.riscv.vcreate.nxv2i16x5.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_u16mf2x5(op1, op2, op3, op4, op5);
}

vuint16mf2x6_t test_vcreate_u16mf2x6 (vuint16mf2_t op1, vuint16mf2_t op2, vuint16mf2_t op3, vuint16mf2_t op4, vuint16mf2_t op5, vuint16mf2_t op6) {
  // CHECK-LABEL: test_vcreate_u16mf2x6
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vcreate.nxv2i16x6.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_u16mf2x6(op1, op2, op3, op4, op5, op6);
}

vuint16mf2x7_t test_vcreate_u16mf2x7 (vuint16mf2_t op1, vuint16mf2_t op2, vuint16mf2_t op3, vuint16mf2_t op4, vuint16mf2_t op5, vuint16mf2_t op6, vuint16mf2_t op7) {
  // CHECK-LABEL: test_vcreate_u16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vcreate.nxv2i16x7.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_u16mf2x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint16mf2x8_t test_vcreate_u16mf2x8 (vuint16mf2_t op1, vuint16mf2_t op2, vuint16mf2_t op3, vuint16mf2_t op4, vuint16mf2_t op5, vuint16mf2_t op6, vuint16mf2_t op7, vuint16mf2_t op8) {
  // CHECK-LABEL: test_vcreate_u16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcreate.nxv2i16x8.{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcreate_u16mf2x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint16m1x2_t test_vcreate_u16m1x2 (vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vcreate_u16m1x2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcreate.nxv4i16x2.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_u16m1x2(op1, op2);
}

vuint16m1x3_t test_vcreate_u16m1x3 (vuint16m1_t op1, vuint16m1_t op2, vuint16m1_t op3) {
  // CHECK-LABEL: test_vcreate_u16m1x3
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vcreate.nxv4i16x3.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_u16m1x3(op1, op2, op3);
}

vuint16m1x4_t test_vcreate_u16m1x4 (vuint16m1_t op1, vuint16m1_t op2, vuint16m1_t op3, vuint16m1_t op4) {
  // CHECK-LABEL: test_vcreate_u16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcreate.nxv4i16x4.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_u16m1x4(op1, op2, op3, op4);
}

vuint16m1x5_t test_vcreate_u16m1x5 (vuint16m1_t op1, vuint16m1_t op2, vuint16m1_t op3, vuint16m1_t op4, vuint16m1_t op5) {
  // CHECK-LABEL: test_vcreate_u16m1x5
  // CHECK: %{{.*}} = call <vscale x 20 x i16> @llvm.riscv.vcreate.nxv4i16x5.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_u16m1x5(op1, op2, op3, op4, op5);
}

vuint16m1x6_t test_vcreate_u16m1x6 (vuint16m1_t op1, vuint16m1_t op2, vuint16m1_t op3, vuint16m1_t op4, vuint16m1_t op5, vuint16m1_t op6) {
  // CHECK-LABEL: test_vcreate_u16m1x6
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vcreate.nxv4i16x6.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_u16m1x6(op1, op2, op3, op4, op5, op6);
}

vuint16m1x7_t test_vcreate_u16m1x7 (vuint16m1_t op1, vuint16m1_t op2, vuint16m1_t op3, vuint16m1_t op4, vuint16m1_t op5, vuint16m1_t op6, vuint16m1_t op7) {
  // CHECK-LABEL: test_vcreate_u16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vcreate.nxv4i16x7.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_u16m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint16m1x8_t test_vcreate_u16m1x8 (vuint16m1_t op1, vuint16m1_t op2, vuint16m1_t op3, vuint16m1_t op4, vuint16m1_t op5, vuint16m1_t op6, vuint16m1_t op7, vuint16m1_t op8) {
  // CHECK-LABEL: test_vcreate_u16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcreate.nxv4i16x8.{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcreate_u16m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint16m2x2_t test_vcreate_u16m2x2 (vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vcreate_u16m2x2
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcreate.nxv8i16x2.{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vcreate_u16m2x2(op1, op2);
}

vuint16m2x3_t test_vcreate_u16m2x3 (vuint16m2_t op1, vuint16m2_t op2, vuint16m2_t op3) {
  // CHECK-LABEL: test_vcreate_u16m2x3
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vcreate.nxv8i16x3.{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vcreate_u16m2x3(op1, op2, op3);
}

vuint16m2x4_t test_vcreate_u16m2x4 (vuint16m2_t op1, vuint16m2_t op2, vuint16m2_t op3, vuint16m2_t op4) {
  // CHECK-LABEL: test_vcreate_u16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcreate.nxv8i16x4.{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vcreate_u16m2x4(op1, op2, op3, op4);
}

vuint16m4x2_t test_vcreate_u16m4x2 (vuint16m4_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vcreate_u16m4x2
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcreate.nxv16i16x2.{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vcreate_u16m4x2(op1, op2);
}

vuint32mf2x2_t test_vcreate_u32mf2x2 (vuint32mf2_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vcreate_u32mf2x2
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vcreate.nxv1i32x2.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_u32mf2x2(op1, op2);
}

vuint32mf2x3_t test_vcreate_u32mf2x3 (vuint32mf2_t op1, vuint32mf2_t op2, vuint32mf2_t op3) {
  // CHECK-LABEL: test_vcreate_u32mf2x3
  // CHECK: %{{.*}} = call <vscale x 3 x i32> @llvm.riscv.vcreate.nxv1i32x3.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_u32mf2x3(op1, op2, op3);
}

vuint32mf2x4_t test_vcreate_u32mf2x4 (vuint32mf2_t op1, vuint32mf2_t op2, vuint32mf2_t op3, vuint32mf2_t op4) {
  // CHECK-LABEL: test_vcreate_u32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcreate.nxv1i32x4.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_u32mf2x4(op1, op2, op3, op4);
}

vuint32mf2x5_t test_vcreate_u32mf2x5 (vuint32mf2_t op1, vuint32mf2_t op2, vuint32mf2_t op3, vuint32mf2_t op4, vuint32mf2_t op5) {
  // CHECK-LABEL: test_vcreate_u32mf2x5
  // CHECK: %{{.*}} = call <vscale x 5 x i32> @llvm.riscv.vcreate.nxv1i32x5.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_u32mf2x5(op1, op2, op3, op4, op5);
}

vuint32mf2x6_t test_vcreate_u32mf2x6 (vuint32mf2_t op1, vuint32mf2_t op2, vuint32mf2_t op3, vuint32mf2_t op4, vuint32mf2_t op5, vuint32mf2_t op6) {
  // CHECK-LABEL: test_vcreate_u32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vcreate.nxv1i32x6.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_u32mf2x6(op1, op2, op3, op4, op5, op6);
}

vuint32mf2x7_t test_vcreate_u32mf2x7 (vuint32mf2_t op1, vuint32mf2_t op2, vuint32mf2_t op3, vuint32mf2_t op4, vuint32mf2_t op5, vuint32mf2_t op6, vuint32mf2_t op7) {
  // CHECK-LABEL: test_vcreate_u32mf2x7
  // CHECK: %{{.*}} = call <vscale x 7 x i32> @llvm.riscv.vcreate.nxv1i32x7.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_u32mf2x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint32mf2x8_t test_vcreate_u32mf2x8 (vuint32mf2_t op1, vuint32mf2_t op2, vuint32mf2_t op3, vuint32mf2_t op4, vuint32mf2_t op5, vuint32mf2_t op6, vuint32mf2_t op7, vuint32mf2_t op8) {
  // CHECK-LABEL: test_vcreate_u32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcreate.nxv1i32x8.{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcreate_u32mf2x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint32m1x2_t test_vcreate_u32m1x2 (vuint32m1_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vcreate_u32m1x2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcreate.nxv2i32x2.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_u32m1x2(op1, op2);
}

vuint32m1x3_t test_vcreate_u32m1x3 (vuint32m1_t op1, vuint32m1_t op2, vuint32m1_t op3) {
  // CHECK-LABEL: test_vcreate_u32m1x3
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vcreate.nxv2i32x3.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_u32m1x3(op1, op2, op3);
}

vuint32m1x4_t test_vcreate_u32m1x4 (vuint32m1_t op1, vuint32m1_t op2, vuint32m1_t op3, vuint32m1_t op4) {
  // CHECK-LABEL: test_vcreate_u32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcreate.nxv2i32x4.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_u32m1x4(op1, op2, op3, op4);
}

vuint32m1x5_t test_vcreate_u32m1x5 (vuint32m1_t op1, vuint32m1_t op2, vuint32m1_t op3, vuint32m1_t op4, vuint32m1_t op5) {
  // CHECK-LABEL: test_vcreate_u32m1x5
  // CHECK: %{{.*}} = call <vscale x 10 x i32> @llvm.riscv.vcreate.nxv2i32x5.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_u32m1x5(op1, op2, op3, op4, op5);
}

vuint32m1x6_t test_vcreate_u32m1x6 (vuint32m1_t op1, vuint32m1_t op2, vuint32m1_t op3, vuint32m1_t op4, vuint32m1_t op5, vuint32m1_t op6) {
  // CHECK-LABEL: test_vcreate_u32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vcreate.nxv2i32x6.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_u32m1x6(op1, op2, op3, op4, op5, op6);
}

vuint32m1x7_t test_vcreate_u32m1x7 (vuint32m1_t op1, vuint32m1_t op2, vuint32m1_t op3, vuint32m1_t op4, vuint32m1_t op5, vuint32m1_t op6, vuint32m1_t op7) {
  // CHECK-LABEL: test_vcreate_u32m1x7
  // CHECK: %{{.*}} = call <vscale x 14 x i32> @llvm.riscv.vcreate.nxv2i32x7.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_u32m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint32m1x8_t test_vcreate_u32m1x8 (vuint32m1_t op1, vuint32m1_t op2, vuint32m1_t op3, vuint32m1_t op4, vuint32m1_t op5, vuint32m1_t op6, vuint32m1_t op7, vuint32m1_t op8) {
  // CHECK-LABEL: test_vcreate_u32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcreate.nxv2i32x8.{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcreate_u32m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint32m2x2_t test_vcreate_u32m2x2 (vuint32m2_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vcreate_u32m2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcreate.nxv4i32x2.{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vcreate_u32m2x2(op1, op2);
}

vuint32m2x3_t test_vcreate_u32m2x3 (vuint32m2_t op1, vuint32m2_t op2, vuint32m2_t op3) {
  // CHECK-LABEL: test_vcreate_u32m2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vcreate.nxv4i32x3.{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vcreate_u32m2x3(op1, op2, op3);
}

vuint32m2x4_t test_vcreate_u32m2x4 (vuint32m2_t op1, vuint32m2_t op2, vuint32m2_t op3, vuint32m2_t op4) {
  // CHECK-LABEL: test_vcreate_u32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcreate.nxv4i32x4.{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vcreate_u32m2x4(op1, op2, op3, op4);
}

vuint32m4x2_t test_vcreate_u32m4x2 (vuint32m4_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vcreate_u32m4x2
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcreate.nxv8i32x2.{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vcreate_u32m4x2(op1, op2);
}

vuint64m1x2_t test_vcreate_u64m1x2 (vuint64m1_t op1, vuint64m1_t op2) {
  // CHECK-LABEL: test_vcreate_u64m1x2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vcreate.nxv1i64x2.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_u64m1x2(op1, op2);
}

vuint64m1x3_t test_vcreate_u64m1x3 (vuint64m1_t op1, vuint64m1_t op2, vuint64m1_t op3) {
  // CHECK-LABEL: test_vcreate_u64m1x3
  // CHECK: %{{.*}} = call <vscale x 3 x i64> @llvm.riscv.vcreate.nxv1i64x3.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_u64m1x3(op1, op2, op3);
}

vuint64m1x4_t test_vcreate_u64m1x4 (vuint64m1_t op1, vuint64m1_t op2, vuint64m1_t op3, vuint64m1_t op4) {
  // CHECK-LABEL: test_vcreate_u64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcreate.nxv1i64x4.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_u64m1x4(op1, op2, op3, op4);
}

vuint64m1x5_t test_vcreate_u64m1x5 (vuint64m1_t op1, vuint64m1_t op2, vuint64m1_t op3, vuint64m1_t op4, vuint64m1_t op5) {
  // CHECK-LABEL: test_vcreate_u64m1x5
  // CHECK: %{{.*}} = call <vscale x 5 x i64> @llvm.riscv.vcreate.nxv1i64x5.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_u64m1x5(op1, op2, op3, op4, op5);
}

vuint64m1x6_t test_vcreate_u64m1x6 (vuint64m1_t op1, vuint64m1_t op2, vuint64m1_t op3, vuint64m1_t op4, vuint64m1_t op5, vuint64m1_t op6) {
  // CHECK-LABEL: test_vcreate_u64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vcreate.nxv1i64x6.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_u64m1x6(op1, op2, op3, op4, op5, op6);
}

vuint64m1x7_t test_vcreate_u64m1x7 (vuint64m1_t op1, vuint64m1_t op2, vuint64m1_t op3, vuint64m1_t op4, vuint64m1_t op5, vuint64m1_t op6, vuint64m1_t op7) {
  // CHECK-LABEL: test_vcreate_u64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vcreate.nxv1i64x7.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_u64m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vuint64m1x8_t test_vcreate_u64m1x8 (vuint64m1_t op1, vuint64m1_t op2, vuint64m1_t op3, vuint64m1_t op4, vuint64m1_t op5, vuint64m1_t op6, vuint64m1_t op7, vuint64m1_t op8) {
  // CHECK-LABEL: test_vcreate_u64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcreate.nxv1i64x8.{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcreate_u64m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vuint64m2x2_t test_vcreate_u64m2x2 (vuint64m2_t op1, vuint64m2_t op2) {
  // CHECK-LABEL: test_vcreate_u64m2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcreate.nxv2i64x2.{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vcreate_u64m2x2(op1, op2);
}

vuint64m2x3_t test_vcreate_u64m2x3 (vuint64m2_t op1, vuint64m2_t op2, vuint64m2_t op3) {
  // CHECK-LABEL: test_vcreate_u64m2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vcreate.nxv2i64x3.{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vcreate_u64m2x3(op1, op2, op3);
}

vuint64m2x4_t test_vcreate_u64m2x4 (vuint64m2_t op1, vuint64m2_t op2, vuint64m2_t op3, vuint64m2_t op4) {
  // CHECK-LABEL: test_vcreate_u64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcreate.nxv2i64x4.{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vcreate_u64m2x4(op1, op2, op3, op4);
}

vuint64m4x2_t test_vcreate_u64m4x2 (vuint64m4_t op1, vuint64m4_t op2) {
  // CHECK-LABEL: test_vcreate_u64m4x2
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcreate.nxv4i64x2.{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vcreate_u64m4x2(op1, op2);
}

vfloat16mf4x2_t test_vcreate_f16mf4x2 (vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vcreate_f16mf4x2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vcreate.nxv1f16x2.{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vcreate_f16mf4x2(op1, op2);
}

vfloat16mf4x3_t test_vcreate_f16mf4x3 (vfloat16mf4_t op1, vfloat16mf4_t op2, vfloat16mf4_t op3) {
  // CHECK-LABEL: test_vcreate_f16mf4x3
  // CHECK: %{{.*}} = call <vscale x 3 x half> @llvm.riscv.vcreate.nxv1f16x3.{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vcreate_f16mf4x3(op1, op2, op3);
}

vfloat16mf4x4_t test_vcreate_f16mf4x4 (vfloat16mf4_t op1, vfloat16mf4_t op2, vfloat16mf4_t op3, vfloat16mf4_t op4) {
  // CHECK-LABEL: test_vcreate_f16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vcreate.nxv1f16x4.{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vcreate_f16mf4x4(op1, op2, op3, op4);
}

vfloat16mf4x5_t test_vcreate_f16mf4x5 (vfloat16mf4_t op1, vfloat16mf4_t op2, vfloat16mf4_t op3, vfloat16mf4_t op4, vfloat16mf4_t op5) {
  // CHECK-LABEL: test_vcreate_f16mf4x5
  // CHECK: %{{.*}} = call <vscale x 5 x half> @llvm.riscv.vcreate.nxv1f16x5.{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vcreate_f16mf4x5(op1, op2, op3, op4, op5);
}

vfloat16mf4x6_t test_vcreate_f16mf4x6 (vfloat16mf4_t op1, vfloat16mf4_t op2, vfloat16mf4_t op3, vfloat16mf4_t op4, vfloat16mf4_t op5, vfloat16mf4_t op6) {
  // CHECK-LABEL: test_vcreate_f16mf4x6
  // CHECK: %{{.*}} = call <vscale x 6 x half> @llvm.riscv.vcreate.nxv1f16x6.{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vcreate_f16mf4x6(op1, op2, op3, op4, op5, op6);
}

vfloat16mf4x7_t test_vcreate_f16mf4x7 (vfloat16mf4_t op1, vfloat16mf4_t op2, vfloat16mf4_t op3, vfloat16mf4_t op4, vfloat16mf4_t op5, vfloat16mf4_t op6, vfloat16mf4_t op7) {
  // CHECK-LABEL: test_vcreate_f16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x half> @llvm.riscv.vcreate.nxv1f16x7.{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vcreate_f16mf4x7(op1, op2, op3, op4, op5, op6, op7);
}

vfloat16mf4x8_t test_vcreate_f16mf4x8 (vfloat16mf4_t op1, vfloat16mf4_t op2, vfloat16mf4_t op3, vfloat16mf4_t op4, vfloat16mf4_t op5, vfloat16mf4_t op6, vfloat16mf4_t op7, vfloat16mf4_t op8) {
  // CHECK-LABEL: test_vcreate_f16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vcreate.nxv1f16x8.{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vcreate_f16mf4x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vfloat16mf2x2_t test_vcreate_f16mf2x2 (vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vcreate_f16mf2x2
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vcreate.nxv2f16x2.{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vcreate_f16mf2x2(op1, op2);
}

vfloat16mf2x3_t test_vcreate_f16mf2x3 (vfloat16mf2_t op1, vfloat16mf2_t op2, vfloat16mf2_t op3) {
  // CHECK-LABEL: test_vcreate_f16mf2x3
  // CHECK: %{{.*}} = call <vscale x 6 x half> @llvm.riscv.vcreate.nxv2f16x3.{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vcreate_f16mf2x3(op1, op2, op3);
}

vfloat16mf2x4_t test_vcreate_f16mf2x4 (vfloat16mf2_t op1, vfloat16mf2_t op2, vfloat16mf2_t op3, vfloat16mf2_t op4) {
  // CHECK-LABEL: test_vcreate_f16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vcreate.nxv2f16x4.{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vcreate_f16mf2x4(op1, op2, op3, op4);
}

vfloat16mf2x5_t test_vcreate_f16mf2x5 (vfloat16mf2_t op1, vfloat16mf2_t op2, vfloat16mf2_t op3, vfloat16mf2_t op4, vfloat16mf2_t op5) {
  // CHECK-LABEL: test_vcreate_f16mf2x5
  // CHECK: %{{.*}} = call <vscale x 10 x half> @llvm.riscv.vcreate.nxv2f16x5.{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vcreate_f16mf2x5(op1, op2, op3, op4, op5);
}

vfloat16mf2x6_t test_vcreate_f16mf2x6 (vfloat16mf2_t op1, vfloat16mf2_t op2, vfloat16mf2_t op3, vfloat16mf2_t op4, vfloat16mf2_t op5, vfloat16mf2_t op6) {
  // CHECK-LABEL: test_vcreate_f16mf2x6
  // CHECK: %{{.*}} = call <vscale x 12 x half> @llvm.riscv.vcreate.nxv2f16x6.{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vcreate_f16mf2x6(op1, op2, op3, op4, op5, op6);
}

vfloat16mf2x7_t test_vcreate_f16mf2x7 (vfloat16mf2_t op1, vfloat16mf2_t op2, vfloat16mf2_t op3, vfloat16mf2_t op4, vfloat16mf2_t op5, vfloat16mf2_t op6, vfloat16mf2_t op7) {
  // CHECK-LABEL: test_vcreate_f16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x half> @llvm.riscv.vcreate.nxv2f16x7.{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vcreate_f16mf2x7(op1, op2, op3, op4, op5, op6, op7);
}

vfloat16mf2x8_t test_vcreate_f16mf2x8 (vfloat16mf2_t op1, vfloat16mf2_t op2, vfloat16mf2_t op3, vfloat16mf2_t op4, vfloat16mf2_t op5, vfloat16mf2_t op6, vfloat16mf2_t op7, vfloat16mf2_t op8) {
  // CHECK-LABEL: test_vcreate_f16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vcreate.nxv2f16x8.{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vcreate_f16mf2x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vfloat16m1x2_t test_vcreate_f16m1x2 (vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vcreate_f16m1x2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vcreate.nxv4f16x2.{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vcreate_f16m1x2(op1, op2);
}

vfloat16m1x3_t test_vcreate_f16m1x3 (vfloat16m1_t op1, vfloat16m1_t op2, vfloat16m1_t op3) {
  // CHECK-LABEL: test_vcreate_f16m1x3
  // CHECK: %{{.*}} = call <vscale x 12 x half> @llvm.riscv.vcreate.nxv4f16x3.{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vcreate_f16m1x3(op1, op2, op3);
}

vfloat16m1x4_t test_vcreate_f16m1x4 (vfloat16m1_t op1, vfloat16m1_t op2, vfloat16m1_t op3, vfloat16m1_t op4) {
  // CHECK-LABEL: test_vcreate_f16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vcreate.nxv4f16x4.{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vcreate_f16m1x4(op1, op2, op3, op4);
}

vfloat16m1x5_t test_vcreate_f16m1x5 (vfloat16m1_t op1, vfloat16m1_t op2, vfloat16m1_t op3, vfloat16m1_t op4, vfloat16m1_t op5) {
  // CHECK-LABEL: test_vcreate_f16m1x5
  // CHECK: %{{.*}} = call <vscale x 20 x half> @llvm.riscv.vcreate.nxv4f16x5.{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vcreate_f16m1x5(op1, op2, op3, op4, op5);
}

vfloat16m1x6_t test_vcreate_f16m1x6 (vfloat16m1_t op1, vfloat16m1_t op2, vfloat16m1_t op3, vfloat16m1_t op4, vfloat16m1_t op5, vfloat16m1_t op6) {
  // CHECK-LABEL: test_vcreate_f16m1x6
  // CHECK: %{{.*}} = call <vscale x 24 x half> @llvm.riscv.vcreate.nxv4f16x6.{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vcreate_f16m1x6(op1, op2, op3, op4, op5, op6);
}

vfloat16m1x7_t test_vcreate_f16m1x7 (vfloat16m1_t op1, vfloat16m1_t op2, vfloat16m1_t op3, vfloat16m1_t op4, vfloat16m1_t op5, vfloat16m1_t op6, vfloat16m1_t op7) {
  // CHECK-LABEL: test_vcreate_f16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x half> @llvm.riscv.vcreate.nxv4f16x7.{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vcreate_f16m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vfloat16m1x8_t test_vcreate_f16m1x8 (vfloat16m1_t op1, vfloat16m1_t op2, vfloat16m1_t op3, vfloat16m1_t op4, vfloat16m1_t op5, vfloat16m1_t op6, vfloat16m1_t op7, vfloat16m1_t op8) {
  // CHECK-LABEL: test_vcreate_f16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vcreate.nxv4f16x8.{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vcreate_f16m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vfloat16m2x2_t test_vcreate_f16m2x2 (vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vcreate_f16m2x2
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vcreate.nxv8f16x2.{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vcreate_f16m2x2(op1, op2);
}

vfloat16m2x3_t test_vcreate_f16m2x3 (vfloat16m2_t op1, vfloat16m2_t op2, vfloat16m2_t op3) {
  // CHECK-LABEL: test_vcreate_f16m2x3
  // CHECK: %{{.*}} = call <vscale x 24 x half> @llvm.riscv.vcreate.nxv8f16x3.{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vcreate_f16m2x3(op1, op2, op3);
}

vfloat16m2x4_t test_vcreate_f16m2x4 (vfloat16m2_t op1, vfloat16m2_t op2, vfloat16m2_t op3, vfloat16m2_t op4) {
  // CHECK-LABEL: test_vcreate_f16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vcreate.nxv8f16x4.{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vcreate_f16m2x4(op1, op2, op3, op4);
}

vfloat16m4x2_t test_vcreate_f16m4x2 (vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vcreate_f16m4x2
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vcreate.nxv16f16x2.{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vcreate_f16m4x2(op1, op2);
}

vfloat32mf2x2_t test_vcreate_f32mf2x2 (vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vcreate_f32mf2x2
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vcreate.nxv1f32x2.{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vcreate_f32mf2x2(op1, op2);
}

vfloat32mf2x3_t test_vcreate_f32mf2x3 (vfloat32mf2_t op1, vfloat32mf2_t op2, vfloat32mf2_t op3) {
  // CHECK-LABEL: test_vcreate_f32mf2x3
  // CHECK: %{{.*}} = call <vscale x 3 x float> @llvm.riscv.vcreate.nxv1f32x3.{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vcreate_f32mf2x3(op1, op2, op3);
}

vfloat32mf2x4_t test_vcreate_f32mf2x4 (vfloat32mf2_t op1, vfloat32mf2_t op2, vfloat32mf2_t op3, vfloat32mf2_t op4) {
  // CHECK-LABEL: test_vcreate_f32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vcreate.nxv1f32x4.{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vcreate_f32mf2x4(op1, op2, op3, op4);
}

vfloat32mf2x5_t test_vcreate_f32mf2x5 (vfloat32mf2_t op1, vfloat32mf2_t op2, vfloat32mf2_t op3, vfloat32mf2_t op4, vfloat32mf2_t op5) {
  // CHECK-LABEL: test_vcreate_f32mf2x5
  // CHECK: %{{.*}} = call <vscale x 5 x float> @llvm.riscv.vcreate.nxv1f32x5.{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vcreate_f32mf2x5(op1, op2, op3, op4, op5);
}

vfloat32mf2x6_t test_vcreate_f32mf2x6 (vfloat32mf2_t op1, vfloat32mf2_t op2, vfloat32mf2_t op3, vfloat32mf2_t op4, vfloat32mf2_t op5, vfloat32mf2_t op6) {
  // CHECK-LABEL: test_vcreate_f32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vcreate.nxv1f32x6.{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vcreate_f32mf2x6(op1, op2, op3, op4, op5, op6);
}

vfloat32mf2x7_t test_vcreate_f32mf2x7 (vfloat32mf2_t op1, vfloat32mf2_t op2, vfloat32mf2_t op3, vfloat32mf2_t op4, vfloat32mf2_t op5, vfloat32mf2_t op6, vfloat32mf2_t op7) {
  // CHECK-LABEL: test_vcreate_f32mf2x7
  // CHECK: %{{.*}} = call <vscale x 7 x float> @llvm.riscv.vcreate.nxv1f32x7.{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vcreate_f32mf2x7(op1, op2, op3, op4, op5, op6, op7);
}

vfloat32mf2x8_t test_vcreate_f32mf2x8 (vfloat32mf2_t op1, vfloat32mf2_t op2, vfloat32mf2_t op3, vfloat32mf2_t op4, vfloat32mf2_t op5, vfloat32mf2_t op6, vfloat32mf2_t op7, vfloat32mf2_t op8) {
  // CHECK-LABEL: test_vcreate_f32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vcreate.nxv1f32x8.{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vcreate_f32mf2x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vfloat32m1x2_t test_vcreate_f32m1x2 (vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vcreate_f32m1x2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vcreate.nxv2f32x2.{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vcreate_f32m1x2(op1, op2);
}

vfloat32m1x3_t test_vcreate_f32m1x3 (vfloat32m1_t op1, vfloat32m1_t op2, vfloat32m1_t op3) {
  // CHECK-LABEL: test_vcreate_f32m1x3
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vcreate.nxv2f32x3.{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vcreate_f32m1x3(op1, op2, op3);
}

vfloat32m1x4_t test_vcreate_f32m1x4 (vfloat32m1_t op1, vfloat32m1_t op2, vfloat32m1_t op3, vfloat32m1_t op4) {
  // CHECK-LABEL: test_vcreate_f32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vcreate.nxv2f32x4.{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vcreate_f32m1x4(op1, op2, op3, op4);
}

vfloat32m1x5_t test_vcreate_f32m1x5 (vfloat32m1_t op1, vfloat32m1_t op2, vfloat32m1_t op3, vfloat32m1_t op4, vfloat32m1_t op5) {
  // CHECK-LABEL: test_vcreate_f32m1x5
  // CHECK: %{{.*}} = call <vscale x 10 x float> @llvm.riscv.vcreate.nxv2f32x5.{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vcreate_f32m1x5(op1, op2, op3, op4, op5);
}

vfloat32m1x6_t test_vcreate_f32m1x6 (vfloat32m1_t op1, vfloat32m1_t op2, vfloat32m1_t op3, vfloat32m1_t op4, vfloat32m1_t op5, vfloat32m1_t op6) {
  // CHECK-LABEL: test_vcreate_f32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vcreate.nxv2f32x6.{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vcreate_f32m1x6(op1, op2, op3, op4, op5, op6);
}

vfloat32m1x7_t test_vcreate_f32m1x7 (vfloat32m1_t op1, vfloat32m1_t op2, vfloat32m1_t op3, vfloat32m1_t op4, vfloat32m1_t op5, vfloat32m1_t op6, vfloat32m1_t op7) {
  // CHECK-LABEL: test_vcreate_f32m1x7
  // CHECK: %{{.*}} = call <vscale x 14 x float> @llvm.riscv.vcreate.nxv2f32x7.{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vcreate_f32m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vfloat32m1x8_t test_vcreate_f32m1x8 (vfloat32m1_t op1, vfloat32m1_t op2, vfloat32m1_t op3, vfloat32m1_t op4, vfloat32m1_t op5, vfloat32m1_t op6, vfloat32m1_t op7, vfloat32m1_t op8) {
  // CHECK-LABEL: test_vcreate_f32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vcreate.nxv2f32x8.{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vcreate_f32m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vfloat32m2x2_t test_vcreate_f32m2x2 (vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vcreate_f32m2x2
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vcreate.nxv4f32x2.{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vcreate_f32m2x2(op1, op2);
}

vfloat32m2x3_t test_vcreate_f32m2x3 (vfloat32m2_t op1, vfloat32m2_t op2, vfloat32m2_t op3) {
  // CHECK-LABEL: test_vcreate_f32m2x3
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vcreate.nxv4f32x3.{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vcreate_f32m2x3(op1, op2, op3);
}

vfloat32m2x4_t test_vcreate_f32m2x4 (vfloat32m2_t op1, vfloat32m2_t op2, vfloat32m2_t op3, vfloat32m2_t op4) {
  // CHECK-LABEL: test_vcreate_f32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vcreate.nxv4f32x4.{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vcreate_f32m2x4(op1, op2, op3, op4);
}

vfloat32m4x2_t test_vcreate_f32m4x2 (vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vcreate_f32m4x2
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vcreate.nxv8f32x2.{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vcreate_f32m4x2(op1, op2);
}

vfloat64m1x2_t test_vcreate_f64m1x2 (vfloat64m1_t op1, vfloat64m1_t op2) {
  // CHECK-LABEL: test_vcreate_f64m1x2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vcreate.nxv1f32x2.{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vcreate_f64m1x2(op1, op2);
}

vfloat64m1x3_t test_vcreate_f64m1x3 (vfloat64m1_t op1, vfloat64m1_t op2, vfloat64m1_t op3) {
  // CHECK-LABEL: test_vcreate_f64m1x3
  // CHECK: %{{.*}} = call <vscale x 3 x double> @llvm.riscv.vcreate.nxv1f32x3.{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vcreate_f64m1x3(op1, op2, op3);
}

vfloat64m1x4_t test_vcreate_f64m1x4 (vfloat64m1_t op1, vfloat64m1_t op2, vfloat64m1_t op3, vfloat64m1_t op4) {
  // CHECK-LABEL: test_vcreate_f64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vcreate.nxv1f32x4.{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vcreate_f64m1x4(op1, op2, op3, op4);
}

vfloat64m1x5_t test_vcreate_f64m1x5 (vfloat64m1_t op1, vfloat64m1_t op2, vfloat64m1_t op3, vfloat64m1_t op4, vfloat64m1_t op5) {
  // CHECK-LABEL: test_vcreate_f64m1x5
  // CHECK: %{{.*}} = call <vscale x 5 x double> @llvm.riscv.vcreate.nxv1f32x5.{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vcreate_f64m1x5(op1, op2, op3, op4, op5);
}

vfloat64m1x6_t test_vcreate_f64m1x6 (vfloat64m1_t op1, vfloat64m1_t op2, vfloat64m1_t op3, vfloat64m1_t op4, vfloat64m1_t op5, vfloat64m1_t op6) {
  // CHECK-LABEL: test_vcreate_f64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vcreate.nxv1f32x6.{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vcreate_f64m1x6(op1, op2, op3, op4, op5, op6);
}

vfloat64m1x7_t test_vcreate_f64m1x7 (vfloat64m1_t op1, vfloat64m1_t op2, vfloat64m1_t op3, vfloat64m1_t op4, vfloat64m1_t op5, vfloat64m1_t op6, vfloat64m1_t op7) {
  // CHECK-LABEL: test_vcreate_f64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x double> @llvm.riscv.vcreate.nxv1f32x7.{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vcreate_f64m1x7(op1, op2, op3, op4, op5, op6, op7);
}

vfloat64m1x8_t test_vcreate_f64m1x8 (vfloat64m1_t op1, vfloat64m1_t op2, vfloat64m1_t op3, vfloat64m1_t op4, vfloat64m1_t op5, vfloat64m1_t op6, vfloat64m1_t op7, vfloat64m1_t op8) {
  // CHECK-LABEL: test_vcreate_f64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vcreate.nxv1f32x8.{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vcreate_f64m1x8(op1, op2, op3, op4, op5, op6, op7, op8);
}

vfloat64m2x2_t test_vcreate_f64m2x2 (vfloat64m2_t op1, vfloat64m2_t op2) {
  // CHECK-LABEL: test_vcreate_f64m2x2
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vcreate.nxv2f32x2.{{.*}}(<vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vcreate_f64m2x2(op1, op2);
}

vfloat64m2x3_t test_vcreate_f64m2x3 (vfloat64m2_t op1, vfloat64m2_t op2, vfloat64m2_t op3) {
  // CHECK-LABEL: test_vcreate_f64m2x3
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vcreate.nxv2f32x3.{{.*}}(<vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vcreate_f64m2x3(op1, op2, op3);
}

vfloat64m2x4_t test_vcreate_f64m2x4 (vfloat64m2_t op1, vfloat64m2_t op2, vfloat64m2_t op3, vfloat64m2_t op4) {
  // CHECK-LABEL: test_vcreate_f64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vcreate.nxv2f32x4.{{.*}}(<vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vcreate_f64m2x4(op1, op2, op3, op4);
}

vfloat64m4x2_t test_vcreate_f64m4x2 (vfloat64m4_t op1, vfloat64m4_t op2) {
  // CHECK-LABEL: test_vcreate_f64m4x2
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vcreate.nxv4f32x2.{{.*}}(<vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vcreate_f64m4x2(op1, op2);
}


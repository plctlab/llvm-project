// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1_t test_vsext_vf8_i64m1 (vint8mf8_t op1) {
  // CHECK-LABEL: test_vsext_vf8_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsext.vf8.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vsext_vf8_i64m1(op1);
}

vint64m2_t test_vsext_vf8_i64m2 (vint8mf4_t op1) {
  // CHECK-LABEL: test_vsext_vf8_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vsext.vf8.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vsext_vf8_i64m2(op1);
}

vint64m4_t test_vsext_vf8_i64m4 (vint8mf2_t op1) {
  // CHECK-LABEL: test_vsext_vf8_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vsext.vf8.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vsext_vf8_i64m4(op1);
}

vint64m8_t test_vsext_vf8_i64m8 (vint8m1_t op1) {
  // CHECK-LABEL: test_vsext_vf8_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vsext.vf8.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vsext_vf8_i64m8(op1);
}

vint64m1_t test_vsext_vf8_i64m1_m (vbool64_t mask, vint64m1_t maskedoff, vint8mf8_t op1) {
  // CHECK-LABEL: test_vsext_vf8_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsext.vf8.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vsext_vf8_i64m1_m(mask, maskedoff, op1);
}

vint64m2_t test_vsext_vf8_i64m2_m (vbool32_t mask, vint64m2_t maskedoff, vint8mf4_t op1) {
  // CHECK-LABEL: test_vsext_vf8_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vsext.vf8.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vsext_vf8_i64m2_m(mask, maskedoff, op1);
}

vint64m4_t test_vsext_vf8_i64m4_m (vbool16_t mask, vint64m4_t maskedoff, vint8mf2_t op1) {
  // CHECK-LABEL: test_vsext_vf8_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vsext.vf8.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vsext_vf8_i64m4_m(mask, maskedoff, op1);
}

vint64m8_t test_vsext_vf8_i64m8_m (vbool8_t mask, vint64m8_t maskedoff, vint8m1_t op1) {
  // CHECK-LABEL: test_vsext_vf8_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vsext.vf8.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vsext_vf8_i64m8_m(mask, maskedoff, op1);
}


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfcopy_v_f16mf4 (vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfcopy_v_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfcopy.v.{{.*}}nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}})
  return vfcopy_v_f16mf4(src);
}

vfloat16mf2_t test_vfcopy_v_f16mf2 (vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfcopy_v_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfcopy.v.{{.*}}nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}})
  return vfcopy_v_f16mf2(src);
}

vfloat16m1_t test_vfcopy_v_f16m1 (vfloat16m1_t src) {
  // CHECK-LABEL: test_vfcopy_v_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfcopy.v.{{.*}}nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}})
  return vfcopy_v_f16m1(src);
}

vfloat16m2_t test_vfcopy_v_f16m2 (vfloat16m2_t src) {
  // CHECK-LABEL: test_vfcopy_v_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfcopy.v.{{.*}}nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}})
  return vfcopy_v_f16m2(src);
}

vfloat16m4_t test_vfcopy_v_f16m4 (vfloat16m4_t src) {
  // CHECK-LABEL: test_vfcopy_v_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfcopy.v.{{.*}}nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}})
  return vfcopy_v_f16m4(src);
}

vfloat16m8_t test_vfcopy_v_f16m8 (vfloat16m8_t src) {
  // CHECK-LABEL: test_vfcopy_v_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfcopy.v.{{.*}}nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}})
  return vfcopy_v_f16m8(src);
}

vfloat32mf2_t test_vfcopy_v_f32mf2 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfcopy_v_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfcopy.v.{{.*}}nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}})
  return vfcopy_v_f32mf2(src);
}

vfloat32m1_t test_vfcopy_v_f32m1 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vfcopy_v_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfcopy.v.{{.*}}nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}})
  return vfcopy_v_f32m1(src);
}

vfloat32m2_t test_vfcopy_v_f32m2 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vfcopy_v_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfcopy.v.{{.*}}nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}})
  return vfcopy_v_f32m2(src);
}

vfloat32m4_t test_vfcopy_v_f32m4 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vfcopy_v_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfcopy.v.{{.*}}nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}})
  return vfcopy_v_f32m4(src);
}

vfloat32m8_t test_vfcopy_v_f32m8 (vfloat32m8_t src) {
  // CHECK-LABEL: test_vfcopy_v_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfcopy.v.{{.*}}nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}})
  return vfcopy_v_f32m8(src);
}

vfloat64m1_t test_vfcopy_v_f64m1 (vfloat64m1_t src) {
  // CHECK-LABEL: test_vfcopy_v_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfcopy.v.{{.*}}nxv1f64{{.*}}(<vscale x 1 x double> %{{.*}})
  return vfcopy_v_f64m1(src);
}

vfloat64m2_t test_vfcopy_v_f64m2 (vfloat64m2_t src) {
  // CHECK-LABEL: test_vfcopy_v_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfcopy.v.{{.*}}nxv2f64{{.*}}(<vscale x 2 x double> %{{.*}})
  return vfcopy_v_f64m2(src);
}

vfloat64m4_t test_vfcopy_v_f64m4 (vfloat64m4_t src) {
  // CHECK-LABEL: test_vfcopy_v_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfcopy.v.{{.*}}nxv4f64{{.*}}(<vscale x 4 x double> %{{.*}})
  return vfcopy_v_f64m4(src);
}

vfloat64m8_t test_vfcopy_v_f64m8 (vfloat64m8_t src) {
  // CHECK-LABEL: test_vfcopy_v_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfcopy.v.{{.*}}nxv8f64{{.*}}(<vscale x 8 x double> %{{.*}})
  return vfcopy_v_f64m8(src);
}


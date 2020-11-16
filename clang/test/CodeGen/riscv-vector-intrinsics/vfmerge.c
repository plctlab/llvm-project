// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfmerge_vfm_f16mf4 (vbool64_t mask, vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfmerge_vfm_f16mf4(mask, op1, op2);
}

vfloat16mf2_t test_vfmerge_vfm_f16mf2 (vbool32_t mask, vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfmerge_vfm_f16mf2(mask, op1, op2);
}

vfloat16m1_t test_vfmerge_vfm_f16m1 (vbool16_t mask, vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfmerge_vfm_f16m1(mask, op1, op2);
}

vfloat16m2_t test_vfmerge_vfm_f16m2 (vbool8_t mask, vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfmerge_vfm_f16m2(mask, op1, op2);
}

vfloat16m4_t test_vfmerge_vfm_f16m4 (vbool4_t mask, vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfmerge_vfm_f16m4(mask, op1, op2);
}

vfloat16m8_t test_vfmerge_vfm_f16m8 (vbool2_t mask, vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfmerge_vfm_f16m8(mask, op1, op2);
}

vfloat32mf2_t test_vfmerge_vfm_f32mf2 (vbool64_t mask, vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfmerge_vfm_f32mf2(mask, op1, op2);
}

vfloat32m1_t test_vfmerge_vfm_f32m1 (vbool32_t mask, vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfmerge_vfm_f32m1(mask, op1, op2);
}

vfloat32m2_t test_vfmerge_vfm_f32m2 (vbool16_t mask, vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfmerge_vfm_f32m2(mask, op1, op2);
}

vfloat32m4_t test_vfmerge_vfm_f32m4 (vbool8_t mask, vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfmerge_vfm_f32m4(mask, op1, op2);
}

vfloat32m8_t test_vfmerge_vfm_f32m8 (vbool4_t mask, vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfmerge_vfm_f32m8(mask, op1, op2);
}

vfloat64m1_t test_vfmerge_vfm_f64m1 (vbool64_t mask, vfloat64m1_t op1, float64_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, double %{{.*}})
  return vfmerge_vfm_f64m1(mask, op1, op2);
}

vfloat64m2_t test_vfmerge_vfm_f64m2 (vbool32_t mask, vfloat64m2_t op1, float64_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, double %{{.*}})
  return vfmerge_vfm_f64m2(mask, op1, op2);
}

vfloat64m4_t test_vfmerge_vfm_f64m4 (vbool16_t mask, vfloat64m4_t op1, float64_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, double %{{.*}})
  return vfmerge_vfm_f64m4(mask, op1, op2);
}

vfloat64m8_t test_vfmerge_vfm_f64m8 (vbool8_t mask, vfloat64m8_t op1, float64_t op2) {
  // CHECK-LABEL: test_vfmerge_vfm_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfmerge.vfm.mask.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}})
  return vfmerge_vfm_f64m8(mask, op1, op2);
}


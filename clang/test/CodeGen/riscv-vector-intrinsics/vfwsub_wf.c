// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat32mf2_t test_vfwsub_wf_f32mf2 (vfloat32mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32mf2(op1, op2);
}

vfloat32m1_t test_vfwsub_wf_f32m1 (vfloat32m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32m1(op1, op2);
}

vfloat32m2_t test_vfwsub_wf_f32m2 (vfloat32m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32m2(op1, op2);
}

vfloat32m4_t test_vfwsub_wf_f32m4 (vfloat32m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32m4(op1, op2);
}

vfloat32m8_t test_vfwsub_wf_f32m8 (vfloat32m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32m8(op1, op2);
}

vfloat64m1_t test_vfwsub_wf_f64m1 (vfloat64m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwsub.wf.{{.*}}nxv1f64{{.*}}(<vscale x 1 x double> %{{.*}}, float %{{.*}})
  return vfwsub_wf_f64m1(op1, op2);
}

vfloat64m2_t test_vfwsub_wf_f64m2 (vfloat64m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwsub.wf.{{.*}}nxv2f64{{.*}}(<vscale x 2 x double> %{{.*}}, float %{{.*}})
  return vfwsub_wf_f64m2(op1, op2);
}

vfloat64m4_t test_vfwsub_wf_f64m4 (vfloat64m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwsub.wf.{{.*}}nxv4f64{{.*}}(<vscale x 4 x double> %{{.*}}, float %{{.*}})
  return vfwsub_wf_f64m4(op1, op2);
}

vfloat64m8_t test_vfwsub_wf_f64m8 (vfloat64m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwsub.wf.{{.*}}nxv8f64{{.*}}(<vscale x 8 x double> %{{.*}}, float %{{.*}})
  return vfwsub_wf_f64m8(op1, op2);
}

vfloat32mf2_t test_vfwsub_wf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfwsub_wf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfwsub_wf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfwsub_wf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfwsub_wf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwsub.wf.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, half %{{.*}})
  return vfwsub_wf_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat64m1_t test_vfwsub_wf_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, vfloat64m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwsub.wf.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, float %{{.*}})
  return vfwsub_wf_f64m1_m(mask, maskedoff, op1, op2);
}

vfloat64m2_t test_vfwsub_wf_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, vfloat64m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwsub.wf.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, float %{{.*}})
  return vfwsub_wf_f64m2_m(mask, maskedoff, op1, op2);
}

vfloat64m4_t test_vfwsub_wf_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, vfloat64m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwsub.wf.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}}, float %{{.*}})
  return vfwsub_wf_f64m4_m(mask, maskedoff, op1, op2);
}

vfloat64m8_t test_vfwsub_wf_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, vfloat64m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwsub_wf_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwsub.wf.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}}, float %{{.*}})
  return vfwsub_wf_f64m8_m(mask, maskedoff, op1, op2);
}


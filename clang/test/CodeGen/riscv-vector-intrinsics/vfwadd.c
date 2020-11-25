// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat32mf2_t test_vfwadd_vv_f32mf2 (vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwadd.vv.{{.*}}nxv1f32{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfwadd_vv_f32mf2(op1, op2);
}

vfloat32mf2_t test_vfwadd_vf_f32mf2 (vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwadd.vf.{{.*}}nxv1f32{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32mf2(op1, op2);
}

vfloat32mf2_t test_vfwadd_wv_f32mf2 (vfloat32mf2_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwadd.wv.{{.*}}nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfwadd_wv_f32mf2(op1, op2);
}

vfloat32mf2_t test_vfwadd_wf_f32mf2 (vfloat32mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwadd.wf.{{.*}}nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32mf2(op1, op2);
}

vfloat32m1_t test_vfwadd_vv_f32m1 (vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwadd.vv.{{.*}}nxv2f32{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfwadd_vv_f32m1(op1, op2);
}

vfloat32m1_t test_vfwadd_vf_f32m1 (vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwadd.vf.{{.*}}nxv2f32{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32m1(op1, op2);
}

vfloat32m1_t test_vfwadd_wv_f32m1 (vfloat32m1_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwadd.wv.{{.*}}nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfwadd_wv_f32m1(op1, op2);
}

vfloat32m1_t test_vfwadd_wf_f32m1 (vfloat32m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwadd.wf.{{.*}}nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32m1(op1, op2);
}

vfloat32m2_t test_vfwadd_vv_f32m2 (vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwadd.vv.{{.*}}nxv4f32{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfwadd_vv_f32m2(op1, op2);
}

vfloat32m2_t test_vfwadd_vf_f32m2 (vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwadd.vf.{{.*}}nxv4f32{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32m2(op1, op2);
}

vfloat32m2_t test_vfwadd_wv_f32m2 (vfloat32m2_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwadd.wv.{{.*}}nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfwadd_wv_f32m2(op1, op2);
}

vfloat32m2_t test_vfwadd_wf_f32m2 (vfloat32m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwadd.wf.{{.*}}nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32m2(op1, op2);
}

vfloat32m4_t test_vfwadd_vv_f32m4 (vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwadd.vv.{{.*}}nxv8f32{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfwadd_vv_f32m4(op1, op2);
}

vfloat32m4_t test_vfwadd_vf_f32m4 (vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwadd.vf.{{.*}}nxv8f32{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32m4(op1, op2);
}

vfloat32m4_t test_vfwadd_wv_f32m4 (vfloat32m4_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwadd.wv.{{.*}}nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfwadd_wv_f32m4(op1, op2);
}

vfloat32m4_t test_vfwadd_wf_f32m4 (vfloat32m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwadd.wf.{{.*}}nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32m4(op1, op2);
}

vfloat32m8_t test_vfwadd_vv_f32m8 (vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwadd.vv.{{.*}}nxv16f32{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfwadd_vv_f32m8(op1, op2);
}

vfloat32m8_t test_vfwadd_vf_f32m8 (vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwadd.vf.{{.*}}nxv16f32{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32m8(op1, op2);
}

vfloat32m8_t test_vfwadd_wv_f32m8 (vfloat32m8_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwadd.wv.{{.*}}nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfwadd_wv_f32m8(op1, op2);
}

vfloat32m8_t test_vfwadd_wf_f32m8 (vfloat32m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwadd.wf.{{.*}}nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32m8(op1, op2);
}

vfloat64m1_t test_vfwadd_vv_f64m1 (vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwadd.vv.{{.*}}nxv1f64{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfwadd_vv_f64m1(op1, op2);
}

vfloat64m1_t test_vfwadd_vf_f64m1 (vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwadd.vf.{{.*}}nxv1f64{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfwadd_vf_f64m1(op1, op2);
}

vfloat64m1_t test_vfwadd_wv_f64m1 (vfloat64m1_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwadd.wv.{{.*}}nxv1f64{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfwadd_wv_f64m1(op1, op2);
}

vfloat64m1_t test_vfwadd_wf_f64m1 (vfloat64m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwadd.wf.{{.*}}nxv1f64{{.*}}(<vscale x 1 x double> %{{.*}}, float %{{.*}})
  return vfwadd_wf_f64m1(op1, op2);
}

vfloat64m2_t test_vfwadd_vv_f64m2 (vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwadd.vv.{{.*}}nxv2f64{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwadd_vv_f64m2(op1, op2);
}

vfloat64m2_t test_vfwadd_vf_f64m2 (vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwadd.vf.{{.*}}nxv2f64{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfwadd_vf_f64m2(op1, op2);
}

vfloat64m2_t test_vfwadd_wv_f64m2 (vfloat64m2_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwadd.wv.{{.*}}nxv2f64{{.*}}(<vscale x 2 x double> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwadd_wv_f64m2(op1, op2);
}

vfloat64m2_t test_vfwadd_wf_f64m2 (vfloat64m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwadd.wf.{{.*}}nxv2f64{{.*}}(<vscale x 2 x double> %{{.*}}, float %{{.*}})
  return vfwadd_wf_f64m2(op1, op2);
}

vfloat64m4_t test_vfwadd_vv_f64m4 (vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwadd.vv.{{.*}}nxv4f64{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfwadd_vv_f64m4(op1, op2);
}

vfloat64m4_t test_vfwadd_vf_f64m4 (vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwadd.vf.{{.*}}nxv4f64{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfwadd_vf_f64m4(op1, op2);
}

vfloat64m4_t test_vfwadd_wv_f64m4 (vfloat64m4_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwadd.wv.{{.*}}nxv4f64{{.*}}(<vscale x 4 x double> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfwadd_wv_f64m4(op1, op2);
}

vfloat64m4_t test_vfwadd_wf_f64m4 (vfloat64m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwadd.wf.{{.*}}nxv4f64{{.*}}(<vscale x 4 x double> %{{.*}}, float %{{.*}})
  return vfwadd_wf_f64m4(op1, op2);
}

vfloat64m8_t test_vfwadd_vv_f64m8 (vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwadd.vv.{{.*}}nxv8f64{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfwadd_vv_f64m8(op1, op2);
}

vfloat64m8_t test_vfwadd_vf_f64m8 (vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwadd.vf.{{.*}}nxv8f64{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfwadd_vf_f64m8(op1, op2);
}

vfloat64m8_t test_vfwadd_wv_f64m8 (vfloat64m8_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwadd.wv.{{.*}}nxv8f64{{.*}}(<vscale x 8 x double> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfwadd_wv_f64m8(op1, op2);
}

vfloat64m8_t test_vfwadd_wf_f64m8 (vfloat64m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwadd.wf.{{.*}}nxv8f64{{.*}}(<vscale x 8 x double> %{{.*}}, float %{{.*}})
  return vfwadd_wf_f64m8(op1, op2);
}

vfloat32mf2_t test_vfwadd_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwadd.vv.mask.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfwadd_vv_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfwadd_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwadd.vf.mask.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfwadd_wv_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwadd.wv.mask.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfwadd_wv_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfwadd_wf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfwadd.wf.mask.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfwadd_vv_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwadd.vv.mask.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfwadd_vv_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfwadd_vf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwadd.vf.mask.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfwadd_wv_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwadd.wv.mask.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfwadd_wv_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfwadd_wf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwadd.wf.mask.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfwadd_vv_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwadd.vv.mask.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfwadd_vv_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfwadd_vf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwadd.vf.mask.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfwadd_wv_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwadd.wv.mask.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfwadd_wv_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfwadd_wf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfwadd.wf.mask.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfwadd_vv_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwadd.vv.mask.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfwadd_vv_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfwadd_vf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwadd.vf.mask.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfwadd_wv_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwadd.wv.mask.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfwadd_wv_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfwadd_wf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfwadd.wf.mask.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfwadd_vv_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwadd.vv.mask.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfwadd_vv_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfwadd_vf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwadd.vf.mask.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfwadd_vf_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfwadd_wv_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwadd.wv.mask.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfwadd_wv_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfwadd_wf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfwadd.wf.mask.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, half %{{.*}})
  return vfwadd_wf_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat64m1_t test_vfwadd_vv_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwadd.vv.mask.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfwadd_vv_f64m1_m(mask, maskedoff, op1, op2);
}

vfloat64m1_t test_vfwadd_vf_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwadd.vf.mask.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfwadd_vf_f64m1_m(mask, maskedoff, op1, op2);
}

vfloat64m1_t test_vfwadd_wv_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, vfloat64m1_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwadd.wv.mask.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfwadd_wv_f64m1_m(mask, maskedoff, op1, op2);
}

vfloat64m1_t test_vfwadd_wf_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, vfloat64m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwadd.wf.mask.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, float %{{.*}})
  return vfwadd_wf_f64m1_m(mask, maskedoff, op1, op2);
}

vfloat64m2_t test_vfwadd_vv_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwadd.vv.mask.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwadd_vv_f64m2_m(mask, maskedoff, op1, op2);
}

vfloat64m2_t test_vfwadd_vf_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwadd.vf.mask.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfwadd_vf_f64m2_m(mask, maskedoff, op1, op2);
}

vfloat64m2_t test_vfwadd_wv_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, vfloat64m2_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwadd.wv.mask.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwadd_wv_f64m2_m(mask, maskedoff, op1, op2);
}

vfloat64m2_t test_vfwadd_wf_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, vfloat64m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfwadd.wf.mask.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, float %{{.*}})
  return vfwadd_wf_f64m2_m(mask, maskedoff, op1, op2);
}

vfloat64m4_t test_vfwadd_vv_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwadd.vv.mask.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfwadd_vv_f64m4_m(mask, maskedoff, op1, op2);
}

vfloat64m4_t test_vfwadd_vf_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwadd.vf.mask.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfwadd_vf_f64m4_m(mask, maskedoff, op1, op2);
}

vfloat64m4_t test_vfwadd_wv_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, vfloat64m4_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwadd.wv.mask.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfwadd_wv_f64m4_m(mask, maskedoff, op1, op2);
}

vfloat64m4_t test_vfwadd_wf_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, vfloat64m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfwadd.wf.mask.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}}, float %{{.*}})
  return vfwadd_wf_f64m4_m(mask, maskedoff, op1, op2);
}

vfloat64m8_t test_vfwadd_vv_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfwadd_vv_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwadd.vv.mask.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfwadd_vv_f64m8_m(mask, maskedoff, op1, op2);
}

vfloat64m8_t test_vfwadd_vf_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_vf_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwadd.vf.mask.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfwadd_vf_f64m8_m(mask, maskedoff, op1, op2);
}

vfloat64m8_t test_vfwadd_wv_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, vfloat64m8_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfwadd_wv_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwadd.wv.mask.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfwadd_wv_f64m8_m(mask, maskedoff, op1, op2);
}

vfloat64m8_t test_vfwadd_wf_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, vfloat64m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfwadd_wf_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfwadd.wf.mask.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}}, float %{{.*}})
  return vfwadd_wf_f64m8_m(mask, maskedoff, op1, op2);
}


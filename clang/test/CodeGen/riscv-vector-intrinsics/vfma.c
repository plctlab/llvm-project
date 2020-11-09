// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfma_vv_f16mf4 (vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfma_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfma.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfma_vv_f16mf4(acc, op1, op2);
}

vfloat16mf4_t test_vfma_vf_f16mf4 (vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfma_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfma.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfma_vf_f16mf4(acc, op1, op2);
}

vfloat16mf2_t test_vfma_vv_f16mf2 (vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfma_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfma.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfma_vv_f16mf2(acc, op1, op2);
}

vfloat16mf2_t test_vfma_vf_f16mf2 (vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfma_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfma.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfma_vf_f16mf2(acc, op1, op2);
}

vfloat16m1_t test_vfma_vv_f16m1 (vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfma_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfma.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfma_vv_f16m1(acc, op1, op2);
}

vfloat16m1_t test_vfma_vf_f16m1 (vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfma_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfma.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfma_vf_f16m1(acc, op1, op2);
}

vfloat16m2_t test_vfma_vv_f16m2 (vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfma_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfma.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfma_vv_f16m2(acc, op1, op2);
}

vfloat16m2_t test_vfma_vf_f16m2 (vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfma_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfma.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfma_vf_f16m2(acc, op1, op2);
}

vfloat16m4_t test_vfma_vv_f16m4 (vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfma_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfma.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfma_vv_f16m4(acc, op1, op2);
}

vfloat16m4_t test_vfma_vf_f16m4 (vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfma_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfma.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfma_vf_f16m4(acc, op1, op2);
}

vfloat16m8_t test_vfma_vv_f16m8 (vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfma_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfma.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfma_vv_f16m8(acc, op1, op2);
}

vfloat16m8_t test_vfma_vf_f16m8 (vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfma_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfma.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfma_vf_f16m8(acc, op1, op2);
}

vfloat32mf2_t test_vfma_vv_f32mf2 (vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfma_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfma.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfma_vv_f32mf2(acc, op1, op2);
}

vfloat32mf2_t test_vfma_vf_f32mf2 (vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfma_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfma.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfma_vf_f32mf2(acc, op1, op2);
}

vfloat32m1_t test_vfma_vv_f32m1 (vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfma_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfma.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfma_vv_f32m1(acc, op1, op2);
}

vfloat32m1_t test_vfma_vf_f32m1 (vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfma_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfma.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfma_vf_f32m1(acc, op1, op2);
}

vfloat32m2_t test_vfma_vv_f32m2 (vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfma_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfma.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfma_vv_f32m2(acc, op1, op2);
}

vfloat32m2_t test_vfma_vf_f32m2 (vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfma_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfma.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfma_vf_f32m2(acc, op1, op2);
}

vfloat32m4_t test_vfma_vv_f32m4 (vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfma_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfma.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfma_vv_f32m4(acc, op1, op2);
}

vfloat32m4_t test_vfma_vf_f32m4 (vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfma_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfma.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfma_vf_f32m4(acc, op1, op2);
}

vfloat32m8_t test_vfma_vv_f32m8 (vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfma_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfma.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfma_vv_f32m8(acc, op1, op2);
}

vfloat32m8_t test_vfma_vf_f32m8 (vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfma_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfma.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfma_vf_f32m8(acc, op1, op2);
}

vfloat64m1_t test_vfma_vv_f64m1 (vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  // CHECK-LABEL: test_vfma_vv_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfma.vv.nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfma_vv_f64m1(acc, op1, op2);
}

vfloat64m1_t test_vfma_vf_f64m1 (vfloat64m1_t acc, float64_t op1, vfloat64m1_t op2) {
  // CHECK-LABEL: test_vfma_vf_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfma.vf.nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}}, double %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfma_vf_f64m1(acc, op1, op2);
}

vfloat64m2_t test_vfma_vv_f64m2 (vfloat64m2_t acc, vfloat64m2_t op1, vfloat64m2_t op2) {
  // CHECK-LABEL: test_vfma_vv_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfma.vv.nxv2f32{{.*}}(<vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vfma_vv_f64m2(acc, op1, op2);
}

vfloat64m2_t test_vfma_vf_f64m2 (vfloat64m2_t acc, float64_t op1, vfloat64m2_t op2) {
  // CHECK-LABEL: test_vfma_vf_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfma.vf.nxv2f32{{.*}}(<vscale x 2 x double> %{{.*}}, double %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vfma_vf_f64m2(acc, op1, op2);
}

vfloat64m4_t test_vfma_vv_f64m4 (vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  // CHECK-LABEL: test_vfma_vv_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfma.vv.nxv4f32{{.*}}(<vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vfma_vv_f64m4(acc, op1, op2);
}

vfloat64m4_t test_vfma_vf_f64m4 (vfloat64m4_t acc, float64_t op1, vfloat64m4_t op2) {
  // CHECK-LABEL: test_vfma_vf_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfma.vf.nxv4f32{{.*}}(<vscale x 4 x double> %{{.*}}, double %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vfma_vf_f64m4(acc, op1, op2);
}

vfloat64m8_t test_vfma_vv_f64m8 (vfloat64m8_t acc, vfloat64m8_t op1, vfloat64m8_t op2) {
  // CHECK-LABEL: test_vfma_vv_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfma.vv.nxv8f32{{.*}}(<vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vfma_vv_f64m8(acc, op1, op2);
}

vfloat64m8_t test_vfma_vf_f64m8 (vfloat64m8_t acc, float64_t op1, vfloat64m8_t op2) {
  // CHECK-LABEL: test_vfma_vf_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfma.vf.nxv8f32{{.*}}(<vscale x 8 x double> %{{.*}}, double %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vfma_vf_f64m8(acc, op1, op2);
}


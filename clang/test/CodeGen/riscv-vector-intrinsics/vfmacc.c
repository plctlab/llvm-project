// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfmacc_vv_f16mf4 (vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmacc.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmacc_vv_f16mf4(acc, op1, op2);
}

vfloat16mf4_t test_vfmacc_vf_f16mf4 (vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmacc.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmacc_vf_f16mf4(acc, op1, op2);
}

vfloat16mf2_t test_vfmacc_vv_f16mf2 (vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmacc.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmacc_vv_f16mf2(acc, op1, op2);
}

vfloat16mf2_t test_vfmacc_vf_f16mf2 (vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmacc.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmacc_vf_f16mf2(acc, op1, op2);
}

vfloat16m1_t test_vfmacc_vv_f16m1 (vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmacc.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmacc_vv_f16m1(acc, op1, op2);
}

vfloat16m1_t test_vfmacc_vf_f16m1 (vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmacc.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmacc_vf_f16m1(acc, op1, op2);
}

vfloat16m2_t test_vfmacc_vv_f16m2 (vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmacc.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmacc_vv_f16m2(acc, op1, op2);
}

vfloat16m2_t test_vfmacc_vf_f16m2 (vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmacc.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmacc_vf_f16m2(acc, op1, op2);
}

vfloat16m4_t test_vfmacc_vv_f16m4 (vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmacc.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmacc_vv_f16m4(acc, op1, op2);
}

vfloat16m4_t test_vfmacc_vf_f16m4 (vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmacc.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmacc_vf_f16m4(acc, op1, op2);
}

vfloat16m8_t test_vfmacc_vv_f16m8 (vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmacc.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmacc_vv_f16m8(acc, op1, op2);
}

vfloat16m8_t test_vfmacc_vf_f16m8 (vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmacc.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmacc_vf_f16m8(acc, op1, op2);
}

vfloat32mf2_t test_vfmacc_vv_f32mf2 (vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmacc.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmacc_vv_f32mf2(acc, op1, op2);
}

vfloat32mf2_t test_vfmacc_vf_f32mf2 (vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmacc.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmacc_vf_f32mf2(acc, op1, op2);
}

vfloat32m1_t test_vfmacc_vv_f32m1 (vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmacc.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmacc_vv_f32m1(acc, op1, op2);
}

vfloat32m1_t test_vfmacc_vf_f32m1 (vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmacc.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmacc_vf_f32m1(acc, op1, op2);
}

vfloat32m2_t test_vfmacc_vv_f32m2 (vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmacc.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmacc_vv_f32m2(acc, op1, op2);
}

vfloat32m2_t test_vfmacc_vf_f32m2 (vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmacc.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmacc_vf_f32m2(acc, op1, op2);
}

vfloat32m4_t test_vfmacc_vv_f32m4 (vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmacc.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmacc_vv_f32m4(acc, op1, op2);
}

vfloat32m4_t test_vfmacc_vf_f32m4 (vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmacc.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmacc_vf_f32m4(acc, op1, op2);
}

vfloat32m8_t test_vfmacc_vv_f32m8 (vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmacc.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmacc_vv_f32m8(acc, op1, op2);
}

vfloat32m8_t test_vfmacc_vf_f32m8 (vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmacc.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmacc_vf_f32m8(acc, op1, op2);
}

vfloat16mf4_t test_vfnmacc_vv_f16mf4 (vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmacc.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmacc_vv_f16mf4(acc, op1, op2);
}

vfloat16mf4_t test_vfnmacc_vf_f16mf4 (vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmacc.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmacc_vf_f16mf4(acc, op1, op2);
}

vfloat16mf2_t test_vfnmacc_vv_f16mf2 (vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmacc.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmacc_vv_f16mf2(acc, op1, op2);
}

vfloat16mf2_t test_vfnmacc_vf_f16mf2 (vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmacc.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmacc_vf_f16mf2(acc, op1, op2);
}

vfloat16m1_t test_vfnmacc_vv_f16m1 (vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmacc.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmacc_vv_f16m1(acc, op1, op2);
}

vfloat16m1_t test_vfnmacc_vf_f16m1 (vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmacc.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmacc_vf_f16m1(acc, op1, op2);
}

vfloat16m2_t test_vfnmacc_vv_f16m2 (vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmacc.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmacc_vv_f16m2(acc, op1, op2);
}

vfloat16m2_t test_vfnmacc_vf_f16m2 (vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmacc.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmacc_vf_f16m2(acc, op1, op2);
}

vfloat16m4_t test_vfnmacc_vv_f16m4 (vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmacc.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmacc_vv_f16m4(acc, op1, op2);
}

vfloat16m4_t test_vfnmacc_vf_f16m4 (vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmacc.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmacc_vf_f16m4(acc, op1, op2);
}

vfloat16m8_t test_vfnmacc_vv_f16m8 (vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmacc.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmacc_vv_f16m8(acc, op1, op2);
}

vfloat16m8_t test_vfnmacc_vf_f16m8 (vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmacc.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmacc_vf_f16m8(acc, op1, op2);
}

vfloat32mf2_t test_vfnmacc_vv_f32mf2 (vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmacc.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmacc_vv_f32mf2(acc, op1, op2);
}

vfloat32mf2_t test_vfnmacc_vf_f32mf2 (vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmacc.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmacc_vf_f32mf2(acc, op1, op2);
}

vfloat32m1_t test_vfnmacc_vv_f32m1 (vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmacc.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmacc_vv_f32m1(acc, op1, op2);
}

vfloat32m1_t test_vfnmacc_vf_f32m1 (vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmacc.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmacc_vf_f32m1(acc, op1, op2);
}

vfloat32m2_t test_vfnmacc_vv_f32m2 (vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmacc.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmacc_vv_f32m2(acc, op1, op2);
}

vfloat32m2_t test_vfnmacc_vf_f32m2 (vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmacc.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmacc_vf_f32m2(acc, op1, op2);
}

vfloat32m4_t test_vfnmacc_vv_f32m4 (vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmacc.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmacc_vv_f32m4(acc, op1, op2);
}

vfloat32m4_t test_vfnmacc_vf_f32m4 (vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmacc.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmacc_vf_f32m4(acc, op1, op2);
}

vfloat32m8_t test_vfnmacc_vv_f32m8 (vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmacc.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmacc_vv_f32m8(acc, op1, op2);
}

vfloat32m8_t test_vfnmacc_vf_f32m8 (vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmacc.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmacc_vf_f32m8(acc, op1, op2);
}

vfloat16mf4_t test_vfmsac_vv_f16mf4 (vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmsac.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmsac_vv_f16mf4(acc, op1, op2);
}

vfloat16mf4_t test_vfmsac_vf_f16mf4 (vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmsac.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmsac_vf_f16mf4(acc, op1, op2);
}

vfloat16mf2_t test_vfmsac_vv_f16mf2 (vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmsac.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmsac_vv_f16mf2(acc, op1, op2);
}

vfloat16mf2_t test_vfmsac_vf_f16mf2 (vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmsac.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmsac_vf_f16mf2(acc, op1, op2);
}

vfloat16m1_t test_vfmsac_vv_f16m1 (vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmsac.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmsac_vv_f16m1(acc, op1, op2);
}

vfloat16m1_t test_vfmsac_vf_f16m1 (vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmsac.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmsac_vf_f16m1(acc, op1, op2);
}

vfloat16m2_t test_vfmsac_vv_f16m2 (vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmsac.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmsac_vv_f16m2(acc, op1, op2);
}

vfloat16m2_t test_vfmsac_vf_f16m2 (vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmsac.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmsac_vf_f16m2(acc, op1, op2);
}

vfloat16m4_t test_vfmsac_vv_f16m4 (vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmsac.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmsac_vv_f16m4(acc, op1, op2);
}

vfloat16m4_t test_vfmsac_vf_f16m4 (vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmsac.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmsac_vf_f16m4(acc, op1, op2);
}

vfloat16m8_t test_vfmsac_vv_f16m8 (vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmsac.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmsac_vv_f16m8(acc, op1, op2);
}

vfloat16m8_t test_vfmsac_vf_f16m8 (vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmsac.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmsac_vf_f16m8(acc, op1, op2);
}

vfloat32mf2_t test_vfmsac_vv_f32mf2 (vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmsac.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmsac_vv_f32mf2(acc, op1, op2);
}

vfloat32mf2_t test_vfmsac_vf_f32mf2 (vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmsac.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmsac_vf_f32mf2(acc, op1, op2);
}

vfloat32m1_t test_vfmsac_vv_f32m1 (vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmsac.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmsac_vv_f32m1(acc, op1, op2);
}

vfloat32m1_t test_vfmsac_vf_f32m1 (vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmsac.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmsac_vf_f32m1(acc, op1, op2);
}

vfloat32m2_t test_vfmsac_vv_f32m2 (vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmsac.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmsac_vv_f32m2(acc, op1, op2);
}

vfloat32m2_t test_vfmsac_vf_f32m2 (vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmsac.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmsac_vf_f32m2(acc, op1, op2);
}

vfloat32m4_t test_vfmsac_vv_f32m4 (vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmsac.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmsac_vv_f32m4(acc, op1, op2);
}

vfloat32m4_t test_vfmsac_vf_f32m4 (vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmsac.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmsac_vf_f32m4(acc, op1, op2);
}

vfloat32m8_t test_vfmsac_vv_f32m8 (vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmsac.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmsac_vv_f32m8(acc, op1, op2);
}

vfloat32m8_t test_vfmsac_vf_f32m8 (vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmsac.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmsac_vf_f32m8(acc, op1, op2);
}

vfloat16mf4_t test_vfmadd_vv_f16mf4 (vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmadd.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmadd_vv_f16mf4(acc, op1, op2);
}

vfloat16mf4_t test_vfmadd_vf_f16mf4 (vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmadd.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmadd_vf_f16mf4(acc, op1, op2);
}

vfloat16mf2_t test_vfmadd_vv_f16mf2 (vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmadd.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmadd_vv_f16mf2(acc, op1, op2);
}

vfloat16mf2_t test_vfmadd_vf_f16mf2 (vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmadd.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmadd_vf_f16mf2(acc, op1, op2);
}

vfloat16m1_t test_vfmadd_vv_f16m1 (vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmadd.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmadd_vv_f16m1(acc, op1, op2);
}

vfloat16m1_t test_vfmadd_vf_f16m1 (vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmadd.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmadd_vf_f16m1(acc, op1, op2);
}

vfloat16m2_t test_vfmadd_vv_f16m2 (vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmadd.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmadd_vv_f16m2(acc, op1, op2);
}

vfloat16m2_t test_vfmadd_vf_f16m2 (vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmadd.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmadd_vf_f16m2(acc, op1, op2);
}

vfloat16m4_t test_vfmadd_vv_f16m4 (vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmadd.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmadd_vv_f16m4(acc, op1, op2);
}

vfloat16m4_t test_vfmadd_vf_f16m4 (vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmadd.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmadd_vf_f16m4(acc, op1, op2);
}

vfloat16m8_t test_vfmadd_vv_f16m8 (vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmadd.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmadd_vv_f16m8(acc, op1, op2);
}

vfloat16m8_t test_vfmadd_vf_f16m8 (vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmadd.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmadd_vf_f16m8(acc, op1, op2);
}

vfloat32mf2_t test_vfmadd_vv_f32mf2 (vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmadd.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmadd_vv_f32mf2(acc, op1, op2);
}

vfloat32mf2_t test_vfmadd_vf_f32mf2 (vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmadd.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmadd_vf_f32mf2(acc, op1, op2);
}

vfloat32m1_t test_vfmadd_vv_f32m1 (vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmadd.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmadd_vv_f32m1(acc, op1, op2);
}

vfloat32m1_t test_vfmadd_vf_f32m1 (vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmadd.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmadd_vf_f32m1(acc, op1, op2);
}

vfloat32m2_t test_vfmadd_vv_f32m2 (vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmadd.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmadd_vv_f32m2(acc, op1, op2);
}

vfloat32m2_t test_vfmadd_vf_f32m2 (vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmadd.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmadd_vf_f32m2(acc, op1, op2);
}

vfloat32m4_t test_vfmadd_vv_f32m4 (vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmadd.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmadd_vv_f32m4(acc, op1, op2);
}

vfloat32m4_t test_vfmadd_vf_f32m4 (vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmadd.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmadd_vf_f32m4(acc, op1, op2);
}

vfloat32m8_t test_vfmadd_vv_f32m8 (vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmadd.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmadd_vv_f32m8(acc, op1, op2);
}

vfloat32m8_t test_vfmadd_vf_f32m8 (vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmadd.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmadd_vf_f32m8(acc, op1, op2);
}

vfloat16mf4_t test_vfnmadd_vv_f16mf4 (vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmadd.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmadd_vv_f16mf4(acc, op1, op2);
}

vfloat16mf4_t test_vfnmadd_vf_f16mf4 (vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmadd.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmadd_vf_f16mf4(acc, op1, op2);
}

vfloat16mf2_t test_vfnmadd_vv_f16mf2 (vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmadd.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmadd_vv_f16mf2(acc, op1, op2);
}

vfloat16mf2_t test_vfnmadd_vf_f16mf2 (vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmadd.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmadd_vf_f16mf2(acc, op1, op2);
}

vfloat16m1_t test_vfnmadd_vv_f16m1 (vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmadd.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmadd_vv_f16m1(acc, op1, op2);
}

vfloat16m1_t test_vfnmadd_vf_f16m1 (vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmadd.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmadd_vf_f16m1(acc, op1, op2);
}

vfloat16m2_t test_vfnmadd_vv_f16m2 (vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmadd.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmadd_vv_f16m2(acc, op1, op2);
}

vfloat16m2_t test_vfnmadd_vf_f16m2 (vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmadd.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmadd_vf_f16m2(acc, op1, op2);
}

vfloat16m4_t test_vfnmadd_vv_f16m4 (vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmadd.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmadd_vv_f16m4(acc, op1, op2);
}

vfloat16m4_t test_vfnmadd_vf_f16m4 (vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmadd.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmadd_vf_f16m4(acc, op1, op2);
}

vfloat16m8_t test_vfnmadd_vv_f16m8 (vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmadd.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmadd_vv_f16m8(acc, op1, op2);
}

vfloat16m8_t test_vfnmadd_vf_f16m8 (vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmadd.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmadd_vf_f16m8(acc, op1, op2);
}

vfloat32mf2_t test_vfnmadd_vv_f32mf2 (vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmadd.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmadd_vv_f32mf2(acc, op1, op2);
}

vfloat32mf2_t test_vfnmadd_vf_f32mf2 (vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmadd.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmadd_vf_f32mf2(acc, op1, op2);
}

vfloat32m1_t test_vfnmadd_vv_f32m1 (vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmadd.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmadd_vv_f32m1(acc, op1, op2);
}

vfloat32m1_t test_vfnmadd_vf_f32m1 (vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmadd.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmadd_vf_f32m1(acc, op1, op2);
}

vfloat32m2_t test_vfnmadd_vv_f32m2 (vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmadd.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmadd_vv_f32m2(acc, op1, op2);
}

vfloat32m2_t test_vfnmadd_vf_f32m2 (vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmadd.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmadd_vf_f32m2(acc, op1, op2);
}

vfloat32m4_t test_vfnmadd_vv_f32m4 (vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmadd.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmadd_vv_f32m4(acc, op1, op2);
}

vfloat32m4_t test_vfnmadd_vf_f32m4 (vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmadd.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmadd_vf_f32m4(acc, op1, op2);
}

vfloat32m8_t test_vfnmadd_vv_f32m8 (vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmadd.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmadd_vv_f32m8(acc, op1, op2);
}

vfloat32m8_t test_vfnmadd_vf_f32m8 (vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmadd.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmadd_vf_f32m8(acc, op1, op2);
}

vfloat16mf4_t test_vfmsub_vv_f16mf4 (vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmsub.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmsub_vv_f16mf4(acc, op1, op2);
}

vfloat16mf4_t test_vfmsub_vf_f16mf4 (vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmsub.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmsub_vf_f16mf4(acc, op1, op2);
}

vfloat16mf2_t test_vfmsub_vv_f16mf2 (vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmsub.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmsub_vv_f16mf2(acc, op1, op2);
}

vfloat16mf2_t test_vfmsub_vf_f16mf2 (vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmsub.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmsub_vf_f16mf2(acc, op1, op2);
}

vfloat16m1_t test_vfmsub_vv_f16m1 (vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmsub.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmsub_vv_f16m1(acc, op1, op2);
}

vfloat16m1_t test_vfmsub_vf_f16m1 (vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmsub.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmsub_vf_f16m1(acc, op1, op2);
}

vfloat16m2_t test_vfmsub_vv_f16m2 (vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmsub.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmsub_vv_f16m2(acc, op1, op2);
}

vfloat16m2_t test_vfmsub_vf_f16m2 (vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmsub.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmsub_vf_f16m2(acc, op1, op2);
}

vfloat16m4_t test_vfmsub_vv_f16m4 (vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmsub.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmsub_vv_f16m4(acc, op1, op2);
}

vfloat16m4_t test_vfmsub_vf_f16m4 (vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmsub.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmsub_vf_f16m4(acc, op1, op2);
}

vfloat16m8_t test_vfmsub_vv_f16m8 (vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmsub.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmsub_vv_f16m8(acc, op1, op2);
}

vfloat16m8_t test_vfmsub_vf_f16m8 (vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmsub.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmsub_vf_f16m8(acc, op1, op2);
}

vfloat32mf2_t test_vfmsub_vv_f32mf2 (vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmsub.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmsub_vv_f32mf2(acc, op1, op2);
}

vfloat32mf2_t test_vfmsub_vf_f32mf2 (vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmsub.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmsub_vf_f32mf2(acc, op1, op2);
}

vfloat32m1_t test_vfmsub_vv_f32m1 (vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmsub.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmsub_vv_f32m1(acc, op1, op2);
}

vfloat32m1_t test_vfmsub_vf_f32m1 (vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmsub.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmsub_vf_f32m1(acc, op1, op2);
}

vfloat32m2_t test_vfmsub_vv_f32m2 (vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmsub.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmsub_vv_f32m2(acc, op1, op2);
}

vfloat32m2_t test_vfmsub_vf_f32m2 (vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmsub.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmsub_vf_f32m2(acc, op1, op2);
}

vfloat32m4_t test_vfmsub_vv_f32m4 (vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmsub.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmsub_vv_f32m4(acc, op1, op2);
}

vfloat32m4_t test_vfmsub_vf_f32m4 (vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmsub.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmsub_vf_f32m4(acc, op1, op2);
}

vfloat32m8_t test_vfmsub_vv_f32m8 (vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmsub.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmsub_vv_f32m8(acc, op1, op2);
}

vfloat32m8_t test_vfmsub_vf_f32m8 (vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmsub.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmsub_vf_f32m8(acc, op1, op2);
}

vfloat16mf4_t test_vfnmsub_vv_f16mf4 (vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmsub.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmsub_vv_f16mf4(acc, op1, op2);
}

vfloat16mf4_t test_vfnmsub_vf_f16mf4 (vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmsub.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmsub_vf_f16mf4(acc, op1, op2);
}

vfloat16mf2_t test_vfnmsub_vv_f16mf2 (vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmsub.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmsub_vv_f16mf2(acc, op1, op2);
}

vfloat16mf2_t test_vfnmsub_vf_f16mf2 (vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmsub.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmsub_vf_f16mf2(acc, op1, op2);
}

vfloat16m1_t test_vfnmsub_vv_f16m1 (vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmsub.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmsub_vv_f16m1(acc, op1, op2);
}

vfloat16m1_t test_vfnmsub_vf_f16m1 (vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmsub.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmsub_vf_f16m1(acc, op1, op2);
}

vfloat16m2_t test_vfnmsub_vv_f16m2 (vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmsub.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmsub_vv_f16m2(acc, op1, op2);
}

vfloat16m2_t test_vfnmsub_vf_f16m2 (vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmsub.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmsub_vf_f16m2(acc, op1, op2);
}

vfloat16m4_t test_vfnmsub_vv_f16m4 (vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmsub.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmsub_vv_f16m4(acc, op1, op2);
}

vfloat16m4_t test_vfnmsub_vf_f16m4 (vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmsub.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmsub_vf_f16m4(acc, op1, op2);
}

vfloat16m8_t test_vfnmsub_vv_f16m8 (vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmsub.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmsub_vv_f16m8(acc, op1, op2);
}

vfloat16m8_t test_vfnmsub_vf_f16m8 (vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmsub.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmsub_vf_f16m8(acc, op1, op2);
}

vfloat32mf2_t test_vfnmsub_vv_f32mf2 (vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmsub.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmsub_vv_f32mf2(acc, op1, op2);
}

vfloat32mf2_t test_vfnmsub_vf_f32mf2 (vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmsub.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmsub_vf_f32mf2(acc, op1, op2);
}

vfloat32m1_t test_vfnmsub_vv_f32m1 (vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmsub.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmsub_vv_f32m1(acc, op1, op2);
}

vfloat32m1_t test_vfnmsub_vf_f32m1 (vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmsub.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmsub_vf_f32m1(acc, op1, op2);
}

vfloat32m2_t test_vfnmsub_vv_f32m2 (vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmsub.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmsub_vv_f32m2(acc, op1, op2);
}

vfloat32m2_t test_vfnmsub_vf_f32m2 (vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmsub.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmsub_vf_f32m2(acc, op1, op2);
}

vfloat32m4_t test_vfnmsub_vv_f32m4 (vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmsub.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmsub_vv_f32m4(acc, op1, op2);
}

vfloat32m4_t test_vfnmsub_vf_f32m4 (vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmsub.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmsub_vf_f32m4(acc, op1, op2);
}

vfloat32m8_t test_vfnmsub_vv_f32m8 (vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmsub.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmsub_vv_f32m8(acc, op1, op2);
}

vfloat32m8_t test_vfnmsub_vf_f32m8 (vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmsub.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmsub_vf_f32m8(acc, op1, op2);
}

vfloat16mf4_t test_vfmacc_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmacc.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmacc_vv_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfmacc_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmacc.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmacc_vf_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfmacc_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmacc.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmacc_vv_f16mf2_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfmacc_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmacc.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmacc_vf_f16mf2_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfmacc_vv_f16m1_m (vbool16_t mask, vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmacc.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmacc_vv_f16m1_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfmacc_vf_f16m1_m (vbool16_t mask, vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmacc.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmacc_vf_f16m1_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfmacc_vv_f16m2_m (vbool8_t mask, vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmacc.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmacc_vv_f16m2_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfmacc_vf_f16m2_m (vbool8_t mask, vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmacc.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmacc_vf_f16m2_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfmacc_vv_f16m4_m (vbool4_t mask, vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmacc.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmacc_vv_f16m4_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfmacc_vf_f16m4_m (vbool4_t mask, vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmacc.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmacc_vf_f16m4_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfmacc_vv_f16m8_m (vbool2_t mask, vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmacc.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmacc_vv_f16m8_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfmacc_vf_f16m8_m (vbool2_t mask, vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmacc.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmacc_vf_f16m8_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfmacc_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmacc.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmacc_vv_f32mf2_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfmacc_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmacc.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmacc_vf_f32mf2_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfmacc_vv_f32m1_m (vbool32_t mask, vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmacc.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmacc_vv_f32m1_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfmacc_vf_f32m1_m (vbool32_t mask, vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmacc.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmacc_vf_f32m1_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfmacc_vv_f32m2_m (vbool16_t mask, vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmacc.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmacc_vv_f32m2_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfmacc_vf_f32m2_m (vbool16_t mask, vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmacc.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmacc_vf_f32m2_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfmacc_vv_f32m4_m (vbool8_t mask, vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmacc.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmacc_vv_f32m4_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfmacc_vf_f32m4_m (vbool8_t mask, vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmacc.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmacc_vf_f32m4_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfmacc_vv_f32m8_m (vbool4_t mask, vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmacc_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmacc.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmacc_vv_f32m8_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfmacc_vf_f32m8_m (vbool4_t mask, vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmacc_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmacc.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmacc_vf_f32m8_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfnmacc_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmacc.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmacc_vv_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfnmacc_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmacc.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmacc_vf_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfnmacc_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmacc.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmacc_vv_f16mf2_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfnmacc_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmacc.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmacc_vf_f16mf2_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfnmacc_vv_f16m1_m (vbool16_t mask, vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmacc.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmacc_vv_f16m1_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfnmacc_vf_f16m1_m (vbool16_t mask, vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmacc.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmacc_vf_f16m1_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfnmacc_vv_f16m2_m (vbool8_t mask, vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmacc.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmacc_vv_f16m2_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfnmacc_vf_f16m2_m (vbool8_t mask, vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmacc.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmacc_vf_f16m2_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfnmacc_vv_f16m4_m (vbool4_t mask, vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmacc.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmacc_vv_f16m4_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfnmacc_vf_f16m4_m (vbool4_t mask, vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmacc.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmacc_vf_f16m4_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfnmacc_vv_f16m8_m (vbool2_t mask, vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmacc.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmacc_vv_f16m8_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfnmacc_vf_f16m8_m (vbool2_t mask, vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmacc.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmacc_vf_f16m8_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfnmacc_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmacc.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmacc_vv_f32mf2_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfnmacc_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmacc.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmacc_vf_f32mf2_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfnmacc_vv_f32m1_m (vbool32_t mask, vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmacc.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmacc_vv_f32m1_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfnmacc_vf_f32m1_m (vbool32_t mask, vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmacc.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmacc_vf_f32m1_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfnmacc_vv_f32m2_m (vbool16_t mask, vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmacc.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmacc_vv_f32m2_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfnmacc_vf_f32m2_m (vbool16_t mask, vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmacc.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmacc_vf_f32m2_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfnmacc_vv_f32m4_m (vbool8_t mask, vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmacc.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmacc_vv_f32m4_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfnmacc_vf_f32m4_m (vbool8_t mask, vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmacc.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmacc_vf_f32m4_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfnmacc_vv_f32m8_m (vbool4_t mask, vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmacc_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmacc.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmacc_vv_f32m8_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfnmacc_vf_f32m8_m (vbool4_t mask, vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmacc_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmacc.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmacc_vf_f32m8_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfmsac_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmsac.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmsac_vv_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfmsac_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmsac.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmsac_vf_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfmsac_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmsac.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmsac_vv_f16mf2_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfmsac_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmsac.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmsac_vf_f16mf2_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfmsac_vv_f16m1_m (vbool16_t mask, vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmsac.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmsac_vv_f16m1_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfmsac_vf_f16m1_m (vbool16_t mask, vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmsac.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmsac_vf_f16m1_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfmsac_vv_f16m2_m (vbool8_t mask, vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmsac.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmsac_vv_f16m2_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfmsac_vf_f16m2_m (vbool8_t mask, vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmsac.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmsac_vf_f16m2_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfmsac_vv_f16m4_m (vbool4_t mask, vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmsac.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmsac_vv_f16m4_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfmsac_vf_f16m4_m (vbool4_t mask, vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmsac.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmsac_vf_f16m4_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfmsac_vv_f16m8_m (vbool2_t mask, vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmsac.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmsac_vv_f16m8_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfmsac_vf_f16m8_m (vbool2_t mask, vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmsac.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmsac_vf_f16m8_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfmsac_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmsac.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmsac_vv_f32mf2_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfmsac_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmsac.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmsac_vf_f32mf2_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfmsac_vv_f32m1_m (vbool32_t mask, vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmsac.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmsac_vv_f32m1_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfmsac_vf_f32m1_m (vbool32_t mask, vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmsac.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmsac_vf_f32m1_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfmsac_vv_f32m2_m (vbool16_t mask, vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmsac.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmsac_vv_f32m2_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfmsac_vf_f32m2_m (vbool16_t mask, vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmsac.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmsac_vf_f32m2_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfmsac_vv_f32m4_m (vbool8_t mask, vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmsac.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmsac_vv_f32m4_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfmsac_vf_f32m4_m (vbool8_t mask, vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmsac.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmsac_vf_f32m4_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfmsac_vv_f32m8_m (vbool4_t mask, vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmsac_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmsac.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmsac_vv_f32m8_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfmsac_vf_f32m8_m (vbool4_t mask, vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmsac_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmsac.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmsac_vf_f32m8_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfmadd_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmadd.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmadd_vv_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfmadd_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmadd.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmadd_vf_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfmadd_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmadd.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmadd_vv_f16mf2_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfmadd_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmadd.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmadd_vf_f16mf2_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfmadd_vv_f16m1_m (vbool16_t mask, vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmadd.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmadd_vv_f16m1_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfmadd_vf_f16m1_m (vbool16_t mask, vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmadd.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmadd_vf_f16m1_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfmadd_vv_f16m2_m (vbool8_t mask, vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmadd.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmadd_vv_f16m2_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfmadd_vf_f16m2_m (vbool8_t mask, vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmadd.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmadd_vf_f16m2_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfmadd_vv_f16m4_m (vbool4_t mask, vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmadd.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmadd_vv_f16m4_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfmadd_vf_f16m4_m (vbool4_t mask, vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmadd.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmadd_vf_f16m4_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfmadd_vv_f16m8_m (vbool2_t mask, vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmadd.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmadd_vv_f16m8_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfmadd_vf_f16m8_m (vbool2_t mask, vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmadd.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmadd_vf_f16m8_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfmadd_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmadd.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmadd_vv_f32mf2_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfmadd_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmadd.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmadd_vf_f32mf2_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfmadd_vv_f32m1_m (vbool32_t mask, vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmadd.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmadd_vv_f32m1_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfmadd_vf_f32m1_m (vbool32_t mask, vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmadd.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmadd_vf_f32m1_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfmadd_vv_f32m2_m (vbool16_t mask, vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmadd.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmadd_vv_f32m2_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfmadd_vf_f32m2_m (vbool16_t mask, vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmadd.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmadd_vf_f32m2_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfmadd_vv_f32m4_m (vbool8_t mask, vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmadd.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmadd_vv_f32m4_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfmadd_vf_f32m4_m (vbool8_t mask, vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmadd.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmadd_vf_f32m4_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfmadd_vv_f32m8_m (vbool4_t mask, vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmadd_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmadd.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmadd_vv_f32m8_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfmadd_vf_f32m8_m (vbool4_t mask, vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmadd_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmadd.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmadd_vf_f32m8_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfnmadd_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmadd.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmadd_vv_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfnmadd_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmadd.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmadd_vf_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfnmadd_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmadd.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmadd_vv_f16mf2_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfnmadd_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmadd.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmadd_vf_f16mf2_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfnmadd_vv_f16m1_m (vbool16_t mask, vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmadd.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmadd_vv_f16m1_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfnmadd_vf_f16m1_m (vbool16_t mask, vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmadd.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmadd_vf_f16m1_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfnmadd_vv_f16m2_m (vbool8_t mask, vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmadd.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmadd_vv_f16m2_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfnmadd_vf_f16m2_m (vbool8_t mask, vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmadd.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmadd_vf_f16m2_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfnmadd_vv_f16m4_m (vbool4_t mask, vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmadd.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmadd_vv_f16m4_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfnmadd_vf_f16m4_m (vbool4_t mask, vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmadd.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmadd_vf_f16m4_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfnmadd_vv_f16m8_m (vbool2_t mask, vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmadd.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmadd_vv_f16m8_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfnmadd_vf_f16m8_m (vbool2_t mask, vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmadd.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmadd_vf_f16m8_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfnmadd_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmadd.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmadd_vv_f32mf2_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfnmadd_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmadd.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmadd_vf_f32mf2_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfnmadd_vv_f32m1_m (vbool32_t mask, vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmadd.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmadd_vv_f32m1_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfnmadd_vf_f32m1_m (vbool32_t mask, vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmadd.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmadd_vf_f32m1_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfnmadd_vv_f32m2_m (vbool16_t mask, vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmadd.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmadd_vv_f32m2_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfnmadd_vf_f32m2_m (vbool16_t mask, vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmadd.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmadd_vf_f32m2_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfnmadd_vv_f32m4_m (vbool8_t mask, vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmadd.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmadd_vv_f32m4_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfnmadd_vf_f32m4_m (vbool8_t mask, vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmadd.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmadd_vf_f32m4_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfnmadd_vv_f32m8_m (vbool4_t mask, vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmadd_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmadd.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmadd_vv_f32m8_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfnmadd_vf_f32m8_m (vbool4_t mask, vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmadd_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmadd.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmadd_vf_f32m8_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfmsub_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmsub.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmsub_vv_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfmsub_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmsub.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfmsub_vf_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfmsub_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmsub.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmsub_vv_f16mf2_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfmsub_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmsub.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfmsub_vf_f16mf2_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfmsub_vv_f16m1_m (vbool16_t mask, vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmsub.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmsub_vv_f16m1_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfmsub_vf_f16m1_m (vbool16_t mask, vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmsub.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfmsub_vf_f16m1_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfmsub_vv_f16m2_m (vbool8_t mask, vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmsub.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmsub_vv_f16m2_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfmsub_vf_f16m2_m (vbool8_t mask, vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmsub.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfmsub_vf_f16m2_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfmsub_vv_f16m4_m (vbool4_t mask, vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmsub.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmsub_vv_f16m4_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfmsub_vf_f16m4_m (vbool4_t mask, vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmsub.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfmsub_vf_f16m4_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfmsub_vv_f16m8_m (vbool2_t mask, vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmsub.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmsub_vv_f16m8_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfmsub_vf_f16m8_m (vbool2_t mask, vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmsub.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfmsub_vf_f16m8_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfmsub_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmsub.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmsub_vv_f32mf2_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfmsub_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmsub.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfmsub_vf_f32mf2_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfmsub_vv_f32m1_m (vbool32_t mask, vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmsub.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmsub_vv_f32m1_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfmsub_vf_f32m1_m (vbool32_t mask, vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmsub.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfmsub_vf_f32m1_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfmsub_vv_f32m2_m (vbool16_t mask, vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmsub.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmsub_vv_f32m2_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfmsub_vf_f32m2_m (vbool16_t mask, vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmsub.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfmsub_vf_f32m2_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfmsub_vv_f32m4_m (vbool8_t mask, vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmsub.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmsub_vv_f32m4_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfmsub_vf_f32m4_m (vbool8_t mask, vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmsub.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfmsub_vf_f32m4_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfmsub_vv_f32m8_m (vbool4_t mask, vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmsub_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmsub.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmsub_vv_f32m8_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfmsub_vf_f32m8_m (vbool4_t mask, vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfmsub_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmsub.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfmsub_vf_f32m8_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfnmsub_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmsub.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmsub_vv_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf4_t test_vfnmsub_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t acc, float16_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfnmsub.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfnmsub_vf_f16mf4_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfnmsub_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmsub.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmsub_vv_f16mf2_m(mask, acc, op1, op2);
}

vfloat16mf2_t test_vfnmsub_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t acc, float16_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfnmsub.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfnmsub_vf_f16mf2_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfnmsub_vv_f16m1_m (vbool16_t mask, vfloat16m1_t acc, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmsub.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmsub_vv_f16m1_m(mask, acc, op1, op2);
}

vfloat16m1_t test_vfnmsub_vf_f16m1_m (vbool16_t mask, vfloat16m1_t acc, float16_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfnmsub.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfnmsub_vf_f16m1_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfnmsub_vv_f16m2_m (vbool8_t mask, vfloat16m2_t acc, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmsub.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmsub_vv_f16m2_m(mask, acc, op1, op2);
}

vfloat16m2_t test_vfnmsub_vf_f16m2_m (vbool8_t mask, vfloat16m2_t acc, float16_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfnmsub.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfnmsub_vf_f16m2_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfnmsub_vv_f16m4_m (vbool4_t mask, vfloat16m4_t acc, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmsub.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmsub_vv_f16m4_m(mask, acc, op1, op2);
}

vfloat16m4_t test_vfnmsub_vf_f16m4_m (vbool4_t mask, vfloat16m4_t acc, float16_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfnmsub.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfnmsub_vf_f16m4_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfnmsub_vv_f16m8_m (vbool2_t mask, vfloat16m8_t acc, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmsub.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmsub_vv_f16m8_m(mask, acc, op1, op2);
}

vfloat16m8_t test_vfnmsub_vf_f16m8_m (vbool2_t mask, vfloat16m8_t acc, float16_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfnmsub.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfnmsub_vf_f16m8_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfnmsub_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmsub.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmsub_vv_f32mf2_m(mask, acc, op1, op2);
}

vfloat32mf2_t test_vfnmsub_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t acc, float32_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfnmsub.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfnmsub_vf_f32mf2_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfnmsub_vv_f32m1_m (vbool32_t mask, vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmsub.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmsub_vv_f32m1_m(mask, acc, op1, op2);
}

vfloat32m1_t test_vfnmsub_vf_f32m1_m (vbool32_t mask, vfloat32m1_t acc, float32_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmsub.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfnmsub_vf_f32m1_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfnmsub_vv_f32m2_m (vbool16_t mask, vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmsub.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmsub_vv_f32m2_m(mask, acc, op1, op2);
}

vfloat32m2_t test_vfnmsub_vf_f32m2_m (vbool16_t mask, vfloat32m2_t acc, float32_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmsub.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfnmsub_vf_f32m2_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfnmsub_vv_f32m4_m (vbool8_t mask, vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmsub.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmsub_vv_f32m4_m(mask, acc, op1, op2);
}

vfloat32m4_t test_vfnmsub_vf_f32m4_m (vbool8_t mask, vfloat32m4_t acc, float32_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmsub.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfnmsub_vf_f32m4_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfnmsub_vv_f32m8_m (vbool4_t mask, vfloat32m8_t acc, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmsub_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmsub.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmsub_vv_f32m8_m(mask, acc, op1, op2);
}

vfloat32m8_t test_vfnmsub_vf_f32m8_m (vbool4_t mask, vfloat32m8_t acc, float32_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfnmsub_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmsub.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfnmsub_vf_f32m8_m(mask, acc, op1, op2);
}


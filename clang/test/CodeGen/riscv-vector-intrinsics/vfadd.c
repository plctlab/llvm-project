// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfadd_vv_f16mf4 (vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfadd.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfadd_vv_f16mf4(op1, op2);
}

vfloat16mf4_t test_vfadd_vf_f16mf4 (vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfadd.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16mf4(op1, op2);
}

vfloat16mf2_t test_vfadd_vv_f16mf2 (vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfadd.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfadd_vv_f16mf2(op1, op2);
}

vfloat16mf2_t test_vfadd_vf_f16mf2 (vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfadd.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16mf2(op1, op2);
}

vfloat16m1_t test_vfadd_vv_f16m1 (vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfadd.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfadd_vv_f16m1(op1, op2);
}

vfloat16m1_t test_vfadd_vf_f16m1 (vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfadd.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16m1(op1, op2);
}

vfloat16m2_t test_vfadd_vv_f16m2 (vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfadd.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfadd_vv_f16m2(op1, op2);
}

vfloat16m2_t test_vfadd_vf_f16m2 (vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfadd.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16m2(op1, op2);
}

vfloat16m4_t test_vfadd_vv_f16m4 (vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfadd.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfadd_vv_f16m4(op1, op2);
}

vfloat16m4_t test_vfadd_vf_f16m4 (vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfadd.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16m4(op1, op2);
}

vfloat16m8_t test_vfadd_vv_f16m8 (vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfadd.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfadd_vv_f16m8(op1, op2);
}

vfloat16m8_t test_vfadd_vf_f16m8 (vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfadd.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16m8(op1, op2);
}

vfloat32mf2_t test_vfadd_vv_f32mf2 (vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfadd.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfadd_vv_f32mf2(op1, op2);
}

vfloat32mf2_t test_vfadd_vf_f32mf2 (vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfadd.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32mf2(op1, op2);
}

vfloat32m1_t test_vfadd_vv_f32m1 (vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfadd.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfadd_vv_f32m1(op1, op2);
}

vfloat32m1_t test_vfadd_vf_f32m1 (vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfadd.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32m1(op1, op2);
}

vfloat32m2_t test_vfadd_vv_f32m2 (vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfadd.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfadd_vv_f32m2(op1, op2);
}

vfloat32m2_t test_vfadd_vf_f32m2 (vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfadd.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32m2(op1, op2);
}

vfloat32m4_t test_vfadd_vv_f32m4 (vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfadd.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfadd_vv_f32m4(op1, op2);
}

vfloat32m4_t test_vfadd_vf_f32m4 (vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfadd.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32m4(op1, op2);
}

vfloat32m8_t test_vfadd_vv_f32m8 (vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfadd.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfadd_vv_f32m8(op1, op2);
}

vfloat32m8_t test_vfadd_vf_f32m8 (vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfadd.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32m8(op1, op2);
}

vfloat16mf4_t test_vfsub_vv_f16mf4 (vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsub.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfsub_vv_f16mf4(op1, op2);
}

vfloat16mf4_t test_vfsub_vf_f16mf4 (vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsub.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16mf4(op1, op2);
}

vfloat16mf2_t test_vfsub_vv_f16mf2 (vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsub.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfsub_vv_f16mf2(op1, op2);
}

vfloat16mf2_t test_vfsub_vf_f16mf2 (vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsub.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16mf2(op1, op2);
}

vfloat16m1_t test_vfsub_vv_f16m1 (vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsub.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfsub_vv_f16m1(op1, op2);
}

vfloat16m1_t test_vfsub_vf_f16m1 (vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsub.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16m1(op1, op2);
}

vfloat16m2_t test_vfsub_vv_f16m2 (vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsub.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfsub_vv_f16m2(op1, op2);
}

vfloat16m2_t test_vfsub_vf_f16m2 (vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsub.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16m2(op1, op2);
}

vfloat16m4_t test_vfsub_vv_f16m4 (vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsub.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfsub_vv_f16m4(op1, op2);
}

vfloat16m4_t test_vfsub_vf_f16m4 (vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsub.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16m4(op1, op2);
}

vfloat16m8_t test_vfsub_vv_f16m8 (vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsub.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfsub_vv_f16m8(op1, op2);
}

vfloat16m8_t test_vfsub_vf_f16m8 (vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsub.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16m8(op1, op2);
}

vfloat32mf2_t test_vfsub_vv_f32mf2 (vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsub.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfsub_vv_f32mf2(op1, op2);
}

vfloat32mf2_t test_vfsub_vf_f32mf2 (vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsub.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32mf2(op1, op2);
}

vfloat32m1_t test_vfsub_vv_f32m1 (vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsub.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfsub_vv_f32m1(op1, op2);
}

vfloat32m1_t test_vfsub_vf_f32m1 (vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsub.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32m1(op1, op2);
}

vfloat32m2_t test_vfsub_vv_f32m2 (vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsub.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfsub_vv_f32m2(op1, op2);
}

vfloat32m2_t test_vfsub_vf_f32m2 (vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsub.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32m2(op1, op2);
}

vfloat32m4_t test_vfsub_vv_f32m4 (vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsub.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfsub_vv_f32m4(op1, op2);
}

vfloat32m4_t test_vfsub_vf_f32m4 (vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsub.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32m4(op1, op2);
}

vfloat32m8_t test_vfsub_vv_f32m8 (vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsub.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfsub_vv_f32m8(op1, op2);
}

vfloat32m8_t test_vfsub_vf_f32m8 (vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsub.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32m8(op1, op2);
}

vfloat16mf4_t test_vfrsub_vf_f16mf4 (vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfrsub.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16mf4(op1, op2);
}

vfloat16mf2_t test_vfrsub_vf_f16mf2 (vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfrsub.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16mf2(op1, op2);
}

vfloat16m1_t test_vfrsub_vf_f16m1 (vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfrsub.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16m1(op1, op2);
}

vfloat16m2_t test_vfrsub_vf_f16m2 (vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfrsub.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16m2(op1, op2);
}

vfloat16m4_t test_vfrsub_vf_f16m4 (vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfrsub.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16m4(op1, op2);
}

vfloat16m8_t test_vfrsub_vf_f16m8 (vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfrsub.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16m8(op1, op2);
}

vfloat32mf2_t test_vfrsub_vf_f32mf2 (vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfrsub.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32mf2(op1, op2);
}

vfloat32m1_t test_vfrsub_vf_f32m1 (vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfrsub.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32m1(op1, op2);
}

vfloat32m2_t test_vfrsub_vf_f32m2 (vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfrsub.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32m2(op1, op2);
}

vfloat32m4_t test_vfrsub_vf_f32m4 (vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfrsub.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32m4(op1, op2);
}

vfloat32m8_t test_vfrsub_vf_f32m8 (vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfrsub.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32m8(op1, op2);
}

vfloat16mf4_t test_vfadd_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfadd.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfadd_vv_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf4_t test_vfadd_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfadd.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfadd_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfadd.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfadd_vv_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfadd_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfadd.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfadd_vv_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfadd.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfadd_vv_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfadd_vf_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfadd.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfadd_vv_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfadd.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfadd_vv_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfadd_vf_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfadd.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfadd_vv_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfadd.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfadd_vv_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfadd_vf_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfadd.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfadd_vv_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfadd.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfadd_vv_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfadd_vf_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfadd.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfadd_vf_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfadd_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfadd.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfadd_vv_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfadd_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfadd.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfadd_vv_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfadd.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfadd_vv_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfadd_vf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfadd.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfadd_vv_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfadd.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfadd_vv_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfadd_vf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfadd.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfadd_vv_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfadd.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfadd_vv_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfadd_vf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfadd.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfadd_vv_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfadd_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfadd.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfadd_vv_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfadd_vf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfadd_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfadd.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfadd_vf_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat16mf4_t test_vfsub_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsub.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfsub_vv_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf4_t test_vfsub_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsub.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfsub_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsub.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfsub_vv_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfsub_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsub.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfsub_vv_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsub.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfsub_vv_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfsub_vf_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsub.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfsub_vv_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsub.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfsub_vv_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfsub_vf_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsub.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfsub_vv_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsub.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfsub_vv_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfsub_vf_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsub.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfsub_vv_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsub.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfsub_vv_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfsub_vf_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsub.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfsub_vf_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfsub_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsub.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfsub_vv_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfsub_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsub.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfsub_vv_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsub.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfsub_vv_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfsub_vf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsub.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfsub_vv_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsub.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfsub_vv_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfsub_vf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsub.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfsub_vv_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsub.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfsub_vv_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfsub_vf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsub.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfsub_vv_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfsub_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsub.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfsub_vv_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfsub_vf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsub_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsub.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfsub_vf_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat16mf4_t test_vfrsub_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfrsub.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfrsub_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfrsub.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfrsub_vf_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfrsub.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfrsub_vf_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfrsub.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfrsub_vf_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfrsub.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfrsub_vf_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfrsub.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfrsub_vf_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfrsub_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfrsub.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfrsub_vf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfrsub.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfrsub_vf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfrsub.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfrsub_vf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfrsub.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfrsub_vf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfrsub_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfrsub.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfrsub_vf_f32m8_m(mask, maskedoff, op1, op2);
}


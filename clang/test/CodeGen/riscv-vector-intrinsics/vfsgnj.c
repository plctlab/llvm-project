// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfsgnj_vv_f16mf4 (vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnj.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfsgnj_vv_f16mf4(op1, op2);
}

vfloat16mf4_t test_vfsgnj_vf_f16mf4 (vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnj.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16mf4(op1, op2);
}

vfloat16mf2_t test_vfsgnj_vv_f16mf2 (vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnj.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfsgnj_vv_f16mf2(op1, op2);
}

vfloat16mf2_t test_vfsgnj_vf_f16mf2 (vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnj.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16mf2(op1, op2);
}

vfloat16m1_t test_vfsgnj_vv_f16m1 (vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnj.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfsgnj_vv_f16m1(op1, op2);
}

vfloat16m1_t test_vfsgnj_vf_f16m1 (vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnj.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16m1(op1, op2);
}

vfloat16m2_t test_vfsgnj_vv_f16m2 (vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnj.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfsgnj_vv_f16m2(op1, op2);
}

vfloat16m2_t test_vfsgnj_vf_f16m2 (vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnj.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16m2(op1, op2);
}

vfloat16m4_t test_vfsgnj_vv_f16m4 (vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnj.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfsgnj_vv_f16m4(op1, op2);
}

vfloat16m4_t test_vfsgnj_vf_f16m4 (vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnj.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16m4(op1, op2);
}

vfloat16m8_t test_vfsgnj_vv_f16m8 (vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnj.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfsgnj_vv_f16m8(op1, op2);
}

vfloat16m8_t test_vfsgnj_vf_f16m8 (vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnj.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16m8(op1, op2);
}

vfloat32mf2_t test_vfsgnj_vv_f32mf2 (vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnj.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfsgnj_vv_f32mf2(op1, op2);
}

vfloat32mf2_t test_vfsgnj_vf_f32mf2 (vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnj.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32mf2(op1, op2);
}

vfloat32m1_t test_vfsgnj_vv_f32m1 (vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnj.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfsgnj_vv_f32m1(op1, op2);
}

vfloat32m1_t test_vfsgnj_vf_f32m1 (vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnj.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32m1(op1, op2);
}

vfloat32m2_t test_vfsgnj_vv_f32m2 (vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnj.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfsgnj_vv_f32m2(op1, op2);
}

vfloat32m2_t test_vfsgnj_vf_f32m2 (vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnj.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32m2(op1, op2);
}

vfloat32m4_t test_vfsgnj_vv_f32m4 (vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnj.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfsgnj_vv_f32m4(op1, op2);
}

vfloat32m4_t test_vfsgnj_vf_f32m4 (vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnj.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32m4(op1, op2);
}

vfloat32m8_t test_vfsgnj_vv_f32m8 (vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnj.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfsgnj_vv_f32m8(op1, op2);
}

vfloat32m8_t test_vfsgnj_vf_f32m8 (vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnj.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32m8(op1, op2);
}

vfloat16mf4_t test_vfsgnjn_vv_f16mf4 (vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnjn.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfsgnjn_vv_f16mf4(op1, op2);
}

vfloat16mf4_t test_vfsgnjn_vf_f16mf4 (vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnjn.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16mf4(op1, op2);
}

vfloat16mf2_t test_vfsgnjn_vv_f16mf2 (vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnjn.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfsgnjn_vv_f16mf2(op1, op2);
}

vfloat16mf2_t test_vfsgnjn_vf_f16mf2 (vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnjn.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16mf2(op1, op2);
}

vfloat16m1_t test_vfsgnjn_vv_f16m1 (vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnjn.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfsgnjn_vv_f16m1(op1, op2);
}

vfloat16m1_t test_vfsgnjn_vf_f16m1 (vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnjn.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16m1(op1, op2);
}

vfloat16m2_t test_vfsgnjn_vv_f16m2 (vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnjn.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfsgnjn_vv_f16m2(op1, op2);
}

vfloat16m2_t test_vfsgnjn_vf_f16m2 (vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnjn.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16m2(op1, op2);
}

vfloat16m4_t test_vfsgnjn_vv_f16m4 (vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnjn.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfsgnjn_vv_f16m4(op1, op2);
}

vfloat16m4_t test_vfsgnjn_vf_f16m4 (vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnjn.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16m4(op1, op2);
}

vfloat16m8_t test_vfsgnjn_vv_f16m8 (vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnjn.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfsgnjn_vv_f16m8(op1, op2);
}

vfloat16m8_t test_vfsgnjn_vf_f16m8 (vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnjn.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16m8(op1, op2);
}

vfloat32mf2_t test_vfsgnjn_vv_f32mf2 (vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnjn.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfsgnjn_vv_f32mf2(op1, op2);
}

vfloat32mf2_t test_vfsgnjn_vf_f32mf2 (vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnjn.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32mf2(op1, op2);
}

vfloat32m1_t test_vfsgnjn_vv_f32m1 (vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnjn.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfsgnjn_vv_f32m1(op1, op2);
}

vfloat32m1_t test_vfsgnjn_vf_f32m1 (vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnjn.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32m1(op1, op2);
}

vfloat32m2_t test_vfsgnjn_vv_f32m2 (vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnjn.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfsgnjn_vv_f32m2(op1, op2);
}

vfloat32m2_t test_vfsgnjn_vf_f32m2 (vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnjn.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32m2(op1, op2);
}

vfloat32m4_t test_vfsgnjn_vv_f32m4 (vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnjn.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfsgnjn_vv_f32m4(op1, op2);
}

vfloat32m4_t test_vfsgnjn_vf_f32m4 (vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnjn.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32m4(op1, op2);
}

vfloat32m8_t test_vfsgnjn_vv_f32m8 (vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnjn.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfsgnjn_vv_f32m8(op1, op2);
}

vfloat32m8_t test_vfsgnjn_vf_f32m8 (vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnjn.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32m8(op1, op2);
}

vfloat16mf4_t test_vfsgnjx_vv_f16mf4 (vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnjx.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfsgnjx_vv_f16mf4(op1, op2);
}

vfloat16mf4_t test_vfsgnjx_vf_f16mf4 (vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnjx.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16mf4(op1, op2);
}

vfloat16mf2_t test_vfsgnjx_vv_f16mf2 (vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnjx.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfsgnjx_vv_f16mf2(op1, op2);
}

vfloat16mf2_t test_vfsgnjx_vf_f16mf2 (vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnjx.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16mf2(op1, op2);
}

vfloat16m1_t test_vfsgnjx_vv_f16m1 (vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnjx.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfsgnjx_vv_f16m1(op1, op2);
}

vfloat16m1_t test_vfsgnjx_vf_f16m1 (vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnjx.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16m1(op1, op2);
}

vfloat16m2_t test_vfsgnjx_vv_f16m2 (vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnjx.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfsgnjx_vv_f16m2(op1, op2);
}

vfloat16m2_t test_vfsgnjx_vf_f16m2 (vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnjx.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16m2(op1, op2);
}

vfloat16m4_t test_vfsgnjx_vv_f16m4 (vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnjx.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfsgnjx_vv_f16m4(op1, op2);
}

vfloat16m4_t test_vfsgnjx_vf_f16m4 (vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnjx.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16m4(op1, op2);
}

vfloat16m8_t test_vfsgnjx_vv_f16m8 (vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnjx.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfsgnjx_vv_f16m8(op1, op2);
}

vfloat16m8_t test_vfsgnjx_vf_f16m8 (vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnjx.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16m8(op1, op2);
}

vfloat32mf2_t test_vfsgnjx_vv_f32mf2 (vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnjx.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfsgnjx_vv_f32mf2(op1, op2);
}

vfloat32mf2_t test_vfsgnjx_vf_f32mf2 (vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnjx.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32mf2(op1, op2);
}

vfloat32m1_t test_vfsgnjx_vv_f32m1 (vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnjx.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfsgnjx_vv_f32m1(op1, op2);
}

vfloat32m1_t test_vfsgnjx_vf_f32m1 (vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnjx.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32m1(op1, op2);
}

vfloat32m2_t test_vfsgnjx_vv_f32m2 (vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnjx.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfsgnjx_vv_f32m2(op1, op2);
}

vfloat32m2_t test_vfsgnjx_vf_f32m2 (vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnjx.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32m2(op1, op2);
}

vfloat32m4_t test_vfsgnjx_vv_f32m4 (vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnjx.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfsgnjx_vv_f32m4(op1, op2);
}

vfloat32m4_t test_vfsgnjx_vf_f32m4 (vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnjx.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32m4(op1, op2);
}

vfloat32m8_t test_vfsgnjx_vv_f32m8 (vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnjx.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfsgnjx_vv_f32m8(op1, op2);
}

vfloat32m8_t test_vfsgnjx_vf_f32m8 (vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnjx.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32m8(op1, op2);
}

vfloat16mf4_t test_vfsgnj_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnj.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfsgnj_vv_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf4_t test_vfsgnj_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnj.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfsgnj_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnj.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfsgnj_vv_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfsgnj_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnj.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfsgnj_vv_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnj.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfsgnj_vv_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfsgnj_vf_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnj.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfsgnj_vv_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnj.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfsgnj_vv_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfsgnj_vf_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnj.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfsgnj_vv_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnj.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfsgnj_vv_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfsgnj_vf_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnj.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfsgnj_vv_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnj.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfsgnj_vv_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfsgnj_vf_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnj.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfsgnj_vf_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfsgnj_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnj.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfsgnj_vv_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfsgnj_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnj.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfsgnj_vv_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnj.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfsgnj_vv_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfsgnj_vf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnj.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfsgnj_vv_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnj.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfsgnj_vv_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfsgnj_vf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnj.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfsgnj_vv_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnj.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfsgnj_vv_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfsgnj_vf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnj.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfsgnj_vv_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfsgnj_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnj.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfsgnj_vv_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfsgnj_vf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnj_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnj.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfsgnj_vf_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat16mf4_t test_vfsgnjn_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnjn.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfsgnjn_vv_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf4_t test_vfsgnjn_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnjn.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfsgnjn_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnjn.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfsgnjn_vv_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfsgnjn_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnjn.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfsgnjn_vv_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnjn.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfsgnjn_vv_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfsgnjn_vf_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnjn.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfsgnjn_vv_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnjn.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfsgnjn_vv_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfsgnjn_vf_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnjn.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfsgnjn_vv_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnjn.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfsgnjn_vv_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfsgnjn_vf_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnjn.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfsgnjn_vv_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnjn.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfsgnjn_vv_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfsgnjn_vf_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnjn.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfsgnjn_vf_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfsgnjn_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnjn.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfsgnjn_vv_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfsgnjn_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnjn.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfsgnjn_vv_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnjn.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfsgnjn_vv_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfsgnjn_vf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnjn.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfsgnjn_vv_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnjn.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfsgnjn_vv_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfsgnjn_vf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnjn.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfsgnjn_vv_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnjn.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfsgnjn_vv_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfsgnjn_vf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnjn.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfsgnjn_vv_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnjn.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfsgnjn_vv_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfsgnjn_vf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjn_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnjn.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfsgnjn_vf_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat16mf4_t test_vfsgnjx_vv_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnjx.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfsgnjx_vv_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf4_t test_vfsgnjx_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsgnjx.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16mf4_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfsgnjx_vv_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnjx.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfsgnjx_vv_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16mf2_t test_vfsgnjx_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsgnjx.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16mf2_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfsgnjx_vv_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnjx.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfsgnjx_vv_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m1_t test_vfsgnjx_vf_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsgnjx.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16m1_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfsgnjx_vv_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnjx.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfsgnjx_vv_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m2_t test_vfsgnjx_vf_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsgnjx.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16m2_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfsgnjx_vv_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnjx.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfsgnjx_vv_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m4_t test_vfsgnjx_vf_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsgnjx.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16m4_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfsgnjx_vv_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnjx.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfsgnjx_vv_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat16m8_t test_vfsgnjx_vf_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsgnjx.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfsgnjx_vf_f16m8_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfsgnjx_vv_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnjx.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfsgnjx_vv_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32mf2_t test_vfsgnjx_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsgnjx.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32mf2_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfsgnjx_vv_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnjx.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfsgnjx_vv_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m1_t test_vfsgnjx_vf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsgnjx.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32m1_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfsgnjx_vv_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnjx.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfsgnjx_vv_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m2_t test_vfsgnjx_vf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsgnjx.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32m2_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfsgnjx_vv_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnjx.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfsgnjx_vv_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m4_t test_vfsgnjx_vf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsgnjx.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32m4_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfsgnjx_vv_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vv_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnjx.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfsgnjx_vv_f32m8_m(mask, maskedoff, op1, op2);
}

vfloat32m8_t test_vfsgnjx_vf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vfsgnjx_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsgnjx.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfsgnjx_vf_f32m8_m(mask, maskedoff, op1, op2);
}


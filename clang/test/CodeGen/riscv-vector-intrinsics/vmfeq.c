// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vbool64_t test_vmfeq_vv_f16mf4_b64 (vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vmfeq_vv_f16mf4_b64(op1, op2);
}

vbool64_t test_vmfeq_vf_f16mf4_b64 (vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16mf4_b64(op1, op2);
}

vbool32_t test_vmfeq_vv_f16mf2_b32 (vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vmfeq_vv_f16mf2_b32(op1, op2);
}

vbool32_t test_vmfeq_vf_f16mf2_b32 (vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16mf2_b32(op1, op2);
}

vbool16_t test_vmfeq_vv_f16m1_b16 (vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vmfeq_vv_f16m1_b16(op1, op2);
}

vbool16_t test_vmfeq_vf_f16m1_b16 (vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16m1_b16(op1, op2);
}

vbool8_t test_vmfeq_vv_f16m2_b8 (vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vmfeq_vv_f16m2_b8(op1, op2);
}

vbool8_t test_vmfeq_vf_f16m2_b8 (vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16m2_b8(op1, op2);
}

vbool4_t test_vmfeq_vv_f16m4_b4 (vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vmfeq_vv_f16m4_b4(op1, op2);
}

vbool4_t test_vmfeq_vf_f16m4_b4 (vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmfeq.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16m4_b4(op1, op2);
}

vbool2_t test_vmfeq_vv_f16m8_b2 (vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmfeq.vv.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vmfeq_vv_f16m8_b2(op1, op2);
}

vbool2_t test_vmfeq_vf_f16m8_b2 (vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmfeq.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16m8_b2(op1, op2);
}

vbool64_t test_vmfeq_vv_f32mf2_b64 (vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vmfeq_vv_f32mf2_b64(op1, op2);
}

vbool64_t test_vmfeq_vf_f32mf2_b64 (vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32mf2_b64(op1, op2);
}

vbool32_t test_vmfeq_vv_f32m1_b32 (vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vmfeq_vv_f32m1_b32(op1, op2);
}

vbool32_t test_vmfeq_vf_f32m1_b32 (vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32m1_b32(op1, op2);
}

vbool16_t test_vmfeq_vv_f32m2_b16 (vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vmfeq_vv_f32m2_b16(op1, op2);
}

vbool16_t test_vmfeq_vf_f32m2_b16 (vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32m2_b16(op1, op2);
}

vbool8_t test_vmfeq_vv_f32m4_b8 (vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vmfeq_vv_f32m4_b8(op1, op2);
}

vbool8_t test_vmfeq_vf_f32m4_b8 (vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32m4_b8(op1, op2);
}

vbool4_t test_vmfeq_vv_f32m8_b4 (vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vmfeq_vv_f32m8_b4(op1, op2);
}

vbool4_t test_vmfeq_vf_f32m8_b4 (vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmfeq.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32m8_b4(op1, op2);
}

vbool64_t test_vmfeq_vv_f64m1_b64 (vfloat64m1_t op1, vfloat64m1_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vmfeq_vv_f64m1_b64(op1, op2);
}

vbool64_t test_vmfeq_vf_f64m1_b64 (vfloat64m1_t op1, float64_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vf.nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}}, double %{{.*}})
  return vmfeq_vf_f64m1_b64(op1, op2);
}

vbool32_t test_vmfeq_vv_f64m2_b32 (vfloat64m2_t op1, vfloat64m2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.nxv2f32{{.*}}(<vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vmfeq_vv_f64m2_b32(op1, op2);
}

vbool32_t test_vmfeq_vf_f64m2_b32 (vfloat64m2_t op1, float64_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vf.nxv2f32{{.*}}(<vscale x 2 x double> %{{.*}}, double %{{.*}})
  return vmfeq_vf_f64m2_b32(op1, op2);
}

vbool16_t test_vmfeq_vv_f64m4_b16 (vfloat64m4_t op1, vfloat64m4_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.nxv4f32{{.*}}(<vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vmfeq_vv_f64m4_b16(op1, op2);
}

vbool16_t test_vmfeq_vf_f64m4_b16 (vfloat64m4_t op1, float64_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vf.nxv4f32{{.*}}(<vscale x 4 x double> %{{.*}}, double %{{.*}})
  return vmfeq_vf_f64m4_b16(op1, op2);
}

vbool8_t test_vmfeq_vv_f64m8_b8 (vfloat64m8_t op1, vfloat64m8_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.nxv8f32{{.*}}(<vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vmfeq_vv_f64m8_b8(op1, op2);
}

vbool8_t test_vmfeq_vf_f64m8_b8 (vfloat64m8_t op1, float64_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vf.nxv8f32{{.*}}(<vscale x 8 x double> %{{.*}}, double %{{.*}})
  return vmfeq_vf_f64m8_b8(op1, op2);
}

vbool64_t test_vmfeq_vv_f16mf4_b64_m (vbool64_t mask, vbool64_t maskedoff, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16mf4_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vmfeq_vv_f16mf4_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmfeq_vf_f16mf4_b64_m (vbool64_t mask, vbool64_t maskedoff, vfloat16mf4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16mf4_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16mf4_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmfeq_vv_f16mf2_b32_m (vbool32_t mask, vbool32_t maskedoff, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16mf2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vmfeq_vv_f16mf2_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmfeq_vf_f16mf2_b32_m (vbool32_t mask, vbool32_t maskedoff, vfloat16mf2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16mf2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16mf2_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmfeq_vv_f16m1_b16_m (vbool16_t mask, vbool16_t maskedoff, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16m1_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vmfeq_vv_f16m1_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmfeq_vf_f16m1_b16_m (vbool16_t mask, vbool16_t maskedoff, vfloat16m1_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16m1_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16m1_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmfeq_vv_f16m2_b8_m (vbool8_t mask, vbool8_t maskedoff, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16m2_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vmfeq_vv_f16m2_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmfeq_vf_f16m2_b8_m (vbool8_t mask, vbool8_t maskedoff, vfloat16m2_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16m2_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16m2_b8_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmfeq_vv_f16m4_b4_m (vbool4_t mask, vbool4_t maskedoff, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16m4_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vmfeq_vv_f16m4_b4_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmfeq_vf_f16m4_b4_m (vbool4_t mask, vbool4_t maskedoff, vfloat16m4_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16m4_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmfeq.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16m4_b4_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmfeq_vv_f16m8_b2_m (vbool2_t mask, vbool2_t maskedoff, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f16m8_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmfeq.vv.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vmfeq_vv_f16m8_b2_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmfeq_vf_f16m8_b2_m (vbool2_t mask, vbool2_t maskedoff, vfloat16m8_t op1, float16_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f16m8_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmfeq.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vmfeq_vf_f16m8_b2_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmfeq_vv_f32mf2_b64_m (vbool64_t mask, vbool64_t maskedoff, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32mf2_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vmfeq_vv_f32mf2_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmfeq_vf_f32mf2_b64_m (vbool64_t mask, vbool64_t maskedoff, vfloat32mf2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32mf2_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32mf2_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmfeq_vv_f32m1_b32_m (vbool32_t mask, vbool32_t maskedoff, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32m1_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vmfeq_vv_f32m1_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmfeq_vf_f32m1_b32_m (vbool32_t mask, vbool32_t maskedoff, vfloat32m1_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32m1_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32m1_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmfeq_vv_f32m2_b16_m (vbool16_t mask, vbool16_t maskedoff, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32m2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vmfeq_vv_f32m2_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmfeq_vf_f32m2_b16_m (vbool16_t mask, vbool16_t maskedoff, vfloat32m2_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32m2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32m2_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmfeq_vv_f32m4_b8_m (vbool8_t mask, vbool8_t maskedoff, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32m4_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vmfeq_vv_f32m4_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmfeq_vf_f32m4_b8_m (vbool8_t mask, vbool8_t maskedoff, vfloat32m4_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32m4_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32m4_b8_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmfeq_vv_f32m8_b4_m (vbool4_t mask, vbool4_t maskedoff, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f32m8_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vmfeq_vv_f32m8_b4_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmfeq_vf_f32m8_b4_m (vbool4_t mask, vbool4_t maskedoff, vfloat32m8_t op1, float32_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f32m8_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmfeq.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vmfeq_vf_f32m8_b4_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmfeq_vv_f64m1_b64_m (vbool64_t mask, vbool64_t maskedoff, vfloat64m1_t op1, vfloat64m1_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f64m1_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vmfeq_vv_f64m1_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmfeq_vf_f64m1_b64_m (vbool64_t mask, vbool64_t maskedoff, vfloat64m1_t op1, float64_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f64m1_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfeq.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, double %{{.*}})
  return vmfeq_vf_f64m1_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmfeq_vv_f64m2_b32_m (vbool32_t mask, vbool32_t maskedoff, vfloat64m2_t op1, vfloat64m2_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f64m2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vmfeq_vv_f64m2_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmfeq_vf_f64m2_b32_m (vbool32_t mask, vbool32_t maskedoff, vfloat64m2_t op1, float64_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f64m2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfeq.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, double %{{.*}})
  return vmfeq_vf_f64m2_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmfeq_vv_f64m4_b16_m (vbool16_t mask, vbool16_t maskedoff, vfloat64m4_t op1, vfloat64m4_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f64m4_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vmfeq_vv_f64m4_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmfeq_vf_f64m4_b16_m (vbool16_t mask, vbool16_t maskedoff, vfloat64m4_t op1, float64_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f64m4_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmfeq.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, double %{{.*}})
  return vmfeq_vf_f64m4_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmfeq_vv_f64m8_b8_m (vbool8_t mask, vbool8_t maskedoff, vfloat64m8_t op1, vfloat64m8_t op2) {
  // CHECK-LABEL: test_vmfeq_vv_f64m8_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vmfeq_vv_f64m8_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmfeq_vf_f64m8_b8_m (vbool8_t mask, vbool8_t maskedoff, vfloat64m8_t op1, float64_t op2) {
  // CHECK-LABEL: test_vmfeq_vf_f64m8_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmfeq.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}})
  return vmfeq_vf_f64m8_b8_m(mask, maskedoff, op1, op2);
}


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vmerge_vvm_f16mf4 (vbool64_t mask, vfloat16mf4_t op1, vfloat16mf4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vmerge.vvm.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vmerge_vvm_f16mf4(mask, op1, op2);
}

vfloat16mf2_t test_vmerge_vvm_f16mf2 (vbool32_t mask, vfloat16mf2_t op1, vfloat16mf2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vmerge.vvm.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vmerge_vvm_f16mf2(mask, op1, op2);
}

vfloat16m1_t test_vmerge_vvm_f16m1 (vbool16_t mask, vfloat16m1_t op1, vfloat16m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vmerge.vvm.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vmerge_vvm_f16m1(mask, op1, op2);
}

vfloat16m2_t test_vmerge_vvm_f16m2 (vbool8_t mask, vfloat16m2_t op1, vfloat16m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vmerge.vvm.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vmerge_vvm_f16m2(mask, op1, op2);
}

vfloat16m4_t test_vmerge_vvm_f16m4 (vbool4_t mask, vfloat16m4_t op1, vfloat16m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vmerge.vvm.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vmerge_vvm_f16m4(mask, op1, op2);
}

vfloat16m8_t test_vmerge_vvm_f16m8 (vbool2_t mask, vfloat16m8_t op1, vfloat16m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vmerge.vvm.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vmerge_vvm_f16m8(mask, op1, op2);
}

vfloat32mf2_t test_vmerge_vvm_f32mf2 (vbool64_t mask, vfloat32mf2_t op1, vfloat32mf2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vmerge.vvm.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vmerge_vvm_f32mf2(mask, op1, op2);
}

vfloat32m1_t test_vmerge_vvm_f32m1 (vbool32_t mask, vfloat32m1_t op1, vfloat32m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vmerge.vvm.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vmerge_vvm_f32m1(mask, op1, op2);
}

vfloat32m2_t test_vmerge_vvm_f32m2 (vbool16_t mask, vfloat32m2_t op1, vfloat32m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vmerge.vvm.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vmerge_vvm_f32m2(mask, op1, op2);
}

vfloat32m4_t test_vmerge_vvm_f32m4 (vbool8_t mask, vfloat32m4_t op1, vfloat32m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vmerge.vvm.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vmerge_vvm_f32m4(mask, op1, op2);
}

vfloat32m8_t test_vmerge_vvm_f32m8 (vbool4_t mask, vfloat32m8_t op1, vfloat32m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vmerge.vvm.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vmerge_vvm_f32m8(mask, op1, op2);
}

vfloat64m1_t test_vmerge_vvm_f64m1 (vbool64_t mask, vfloat64m1_t op1, vfloat64m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vmerge.vvm.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vmerge_vvm_f64m1(mask, op1, op2);
}

vfloat64m2_t test_vmerge_vvm_f64m2 (vbool32_t mask, vfloat64m2_t op1, vfloat64m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vmerge.vvm.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vmerge_vvm_f64m2(mask, op1, op2);
}

vfloat64m4_t test_vmerge_vvm_f64m4 (vbool16_t mask, vfloat64m4_t op1, vfloat64m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vmerge.vvm.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vmerge_vvm_f64m4(mask, op1, op2);
}

vfloat64m8_t test_vmerge_vvm_f64m8 (vbool8_t mask, vfloat64m8_t op1, vfloat64m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vmerge.vvm.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vmerge_vvm_f64m8(mask, op1, op2);
}

vint8mf8_t test_vmerge_vvm_i8mf8 (vbool64_t mask, vint8mf8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmerge.vvm.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vmerge_vvm_i8mf8(mask, op1, op2);
}

vint8mf8_t test_vmerge_vxm_i8mf8 (vbool64_t mask, vint8mf8_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmerge.vxm.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_i8mf8(mask, op1, op2);
}

vint8mf4_t test_vmerge_vvm_i8mf4 (vbool32_t mask, vint8mf4_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmerge.vvm.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vmerge_vvm_i8mf4(mask, op1, op2);
}

vint8mf4_t test_vmerge_vxm_i8mf4 (vbool32_t mask, vint8mf4_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmerge.vxm.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_i8mf4(mask, op1, op2);
}

vint8mf2_t test_vmerge_vvm_i8mf2 (vbool16_t mask, vint8mf2_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmerge.vvm.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vmerge_vvm_i8mf2(mask, op1, op2);
}

vint8mf2_t test_vmerge_vxm_i8mf2 (vbool16_t mask, vint8mf2_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmerge.vxm.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_i8mf2(mask, op1, op2);
}

vint8m1_t test_vmerge_vvm_i8m1 (vbool8_t mask, vint8m1_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmerge.vvm.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vmerge_vvm_i8m1(mask, op1, op2);
}

vint8m1_t test_vmerge_vxm_i8m1 (vbool8_t mask, vint8m1_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmerge.vxm.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_i8m1(mask, op1, op2);
}

vint8m2_t test_vmerge_vvm_i8m2 (vbool4_t mask, vint8m2_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmerge.vvm.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vmerge_vvm_i8m2(mask, op1, op2);
}

vint8m2_t test_vmerge_vxm_i8m2 (vbool4_t mask, vint8m2_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmerge.vxm.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_i8m2(mask, op1, op2);
}

vint8m4_t test_vmerge_vvm_i8m4 (vbool2_t mask, vint8m4_t op1, vint8m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmerge.vvm.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vmerge_vvm_i8m4(mask, op1, op2);
}

vint8m4_t test_vmerge_vxm_i8m4 (vbool2_t mask, vint8m4_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmerge.vxm.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_i8m4(mask, op1, op2);
}

vint8m8_t test_vmerge_vvm_i8m8 (vbool1_t mask, vint8m8_t op1, vint8m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmerge.vvm.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vmerge_vvm_i8m8(mask, op1, op2);
}

vint8m8_t test_vmerge_vxm_i8m8 (vbool1_t mask, vint8m8_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmerge.vxm.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_i8m8(mask, op1, op2);
}

vint16mf4_t test_vmerge_vvm_i16mf4 (vbool64_t mask, vint16mf4_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmerge.vvm.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vmerge_vvm_i16mf4(mask, op1, op2);
}

vint16mf4_t test_vmerge_vxm_i16mf4 (vbool64_t mask, vint16mf4_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmerge.vxm.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_i16mf4(mask, op1, op2);
}

vint16mf2_t test_vmerge_vvm_i16mf2 (vbool32_t mask, vint16mf2_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmerge.vvm.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vmerge_vvm_i16mf2(mask, op1, op2);
}

vint16mf2_t test_vmerge_vxm_i16mf2 (vbool32_t mask, vint16mf2_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmerge.vxm.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_i16mf2(mask, op1, op2);
}

vint16m1_t test_vmerge_vvm_i16m1 (vbool16_t mask, vint16m1_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmerge.vvm.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vmerge_vvm_i16m1(mask, op1, op2);
}

vint16m1_t test_vmerge_vxm_i16m1 (vbool16_t mask, vint16m1_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmerge.vxm.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_i16m1(mask, op1, op2);
}

vint16m2_t test_vmerge_vvm_i16m2 (vbool8_t mask, vint16m2_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmerge.vvm.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vmerge_vvm_i16m2(mask, op1, op2);
}

vint16m2_t test_vmerge_vxm_i16m2 (vbool8_t mask, vint16m2_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmerge.vxm.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_i16m2(mask, op1, op2);
}

vint16m4_t test_vmerge_vvm_i16m4 (vbool4_t mask, vint16m4_t op1, vint16m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmerge.vvm.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vmerge_vvm_i16m4(mask, op1, op2);
}

vint16m4_t test_vmerge_vxm_i16m4 (vbool4_t mask, vint16m4_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmerge.vxm.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_i16m4(mask, op1, op2);
}

vint16m8_t test_vmerge_vvm_i16m8 (vbool2_t mask, vint16m8_t op1, vint16m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmerge.vvm.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vmerge_vvm_i16m8(mask, op1, op2);
}

vint16m8_t test_vmerge_vxm_i16m8 (vbool2_t mask, vint16m8_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmerge.vxm.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_i16m8(mask, op1, op2);
}

vint32mf2_t test_vmerge_vvm_i32mf2 (vbool64_t mask, vint32mf2_t op1, vint32mf2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmerge.vvm.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vmerge_vvm_i32mf2(mask, op1, op2);
}

vint32mf2_t test_vmerge_vxm_i32mf2 (vbool64_t mask, vint32mf2_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmerge.vxm.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_i32mf2(mask, op1, op2);
}

vint32m1_t test_vmerge_vvm_i32m1 (vbool32_t mask, vint32m1_t op1, vint32m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmerge.vvm.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vmerge_vvm_i32m1(mask, op1, op2);
}

vint32m1_t test_vmerge_vxm_i32m1 (vbool32_t mask, vint32m1_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmerge.vxm.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_i32m1(mask, op1, op2);
}

vint32m2_t test_vmerge_vvm_i32m2 (vbool16_t mask, vint32m2_t op1, vint32m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmerge.vvm.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vmerge_vvm_i32m2(mask, op1, op2);
}

vint32m2_t test_vmerge_vxm_i32m2 (vbool16_t mask, vint32m2_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmerge.vxm.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_i32m2(mask, op1, op2);
}

vint32m4_t test_vmerge_vvm_i32m4 (vbool8_t mask, vint32m4_t op1, vint32m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmerge.vvm.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vmerge_vvm_i32m4(mask, op1, op2);
}

vint32m4_t test_vmerge_vxm_i32m4 (vbool8_t mask, vint32m4_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmerge.vxm.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_i32m4(mask, op1, op2);
}

vint32m8_t test_vmerge_vvm_i32m8 (vbool4_t mask, vint32m8_t op1, vint32m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmerge.vvm.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vmerge_vvm_i32m8(mask, op1, op2);
}

vint32m8_t test_vmerge_vxm_i32m8 (vbool4_t mask, vint32m8_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmerge.vxm.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_i32m8(mask, op1, op2);
}

vint64m1_t test_vmerge_vvm_i64m1 (vbool64_t mask, vint64m1_t op1, vint64m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmerge.vvm.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vmerge_vvm_i64m1(mask, op1, op2);
}

vint64m1_t test_vmerge_vxm_i64m1 (vbool64_t mask, vint64m1_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmerge.vxm.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmerge_vxm_i64m1(mask, op1, op2);
}

vint64m2_t test_vmerge_vvm_i64m2 (vbool32_t mask, vint64m2_t op1, vint64m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmerge.vvm.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vmerge_vvm_i64m2(mask, op1, op2);
}

vint64m2_t test_vmerge_vxm_i64m2 (vbool32_t mask, vint64m2_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmerge.vxm.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmerge_vxm_i64m2(mask, op1, op2);
}

vint64m4_t test_vmerge_vvm_i64m4 (vbool16_t mask, vint64m4_t op1, vint64m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmerge.vvm.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vmerge_vvm_i64m4(mask, op1, op2);
}

vint64m4_t test_vmerge_vxm_i64m4 (vbool16_t mask, vint64m4_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmerge.vxm.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmerge_vxm_i64m4(mask, op1, op2);
}

vint64m8_t test_vmerge_vvm_i64m8 (vbool8_t mask, vint64m8_t op1, vint64m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmerge.vvm.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vmerge_vvm_i64m8(mask, op1, op2);
}

vint64m8_t test_vmerge_vxm_i64m8 (vbool8_t mask, vint64m8_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmerge.vxm.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmerge_vxm_i64m8(mask, op1, op2);
}

vuint8mf8_t test_vmerge_vvm_u8mf8 (vbool64_t mask, vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmerge.vvm.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vmerge_vvm_u8mf8(mask, op1, op2);
}

vuint8mf8_t test_vmerge_vxm_u8mf8 (vbool64_t mask, vuint8mf8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmerge.vxm.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_u8mf8(mask, op1, op2);
}

vuint8mf4_t test_vmerge_vvm_u8mf4 (vbool32_t mask, vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmerge.vvm.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vmerge_vvm_u8mf4(mask, op1, op2);
}

vuint8mf4_t test_vmerge_vxm_u8mf4 (vbool32_t mask, vuint8mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmerge.vxm.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_u8mf4(mask, op1, op2);
}

vuint8mf2_t test_vmerge_vvm_u8mf2 (vbool16_t mask, vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmerge.vvm.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vmerge_vvm_u8mf2(mask, op1, op2);
}

vuint8mf2_t test_vmerge_vxm_u8mf2 (vbool16_t mask, vuint8mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmerge.vxm.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_u8mf2(mask, op1, op2);
}

vuint8m1_t test_vmerge_vvm_u8m1 (vbool8_t mask, vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmerge.vvm.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vmerge_vvm_u8m1(mask, op1, op2);
}

vuint8m1_t test_vmerge_vxm_u8m1 (vbool8_t mask, vuint8m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmerge.vxm.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_u8m1(mask, op1, op2);
}

vuint8m2_t test_vmerge_vvm_u8m2 (vbool4_t mask, vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmerge.vvm.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vmerge_vvm_u8m2(mask, op1, op2);
}

vuint8m2_t test_vmerge_vxm_u8m2 (vbool4_t mask, vuint8m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmerge.vxm.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_u8m2(mask, op1, op2);
}

vuint8m4_t test_vmerge_vvm_u8m4 (vbool2_t mask, vuint8m4_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmerge.vvm.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vmerge_vvm_u8m4(mask, op1, op2);
}

vuint8m4_t test_vmerge_vxm_u8m4 (vbool2_t mask, vuint8m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmerge.vxm.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_u8m4(mask, op1, op2);
}

vuint8m8_t test_vmerge_vvm_u8m8 (vbool1_t mask, vuint8m8_t op1, vuint8m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmerge.vvm.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vmerge_vvm_u8m8(mask, op1, op2);
}

vuint8m8_t test_vmerge_vxm_u8m8 (vbool1_t mask, vuint8m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmerge.vxm.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmerge_vxm_u8m8(mask, op1, op2);
}

vuint16mf4_t test_vmerge_vvm_u16mf4 (vbool64_t mask, vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmerge.vvm.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vmerge_vvm_u16mf4(mask, op1, op2);
}

vuint16mf4_t test_vmerge_vxm_u16mf4 (vbool64_t mask, vuint16mf4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmerge.vxm.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_u16mf4(mask, op1, op2);
}

vuint16mf2_t test_vmerge_vvm_u16mf2 (vbool32_t mask, vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmerge.vvm.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vmerge_vvm_u16mf2(mask, op1, op2);
}

vuint16mf2_t test_vmerge_vxm_u16mf2 (vbool32_t mask, vuint16mf2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmerge.vxm.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_u16mf2(mask, op1, op2);
}

vuint16m1_t test_vmerge_vvm_u16m1 (vbool16_t mask, vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmerge.vvm.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vmerge_vvm_u16m1(mask, op1, op2);
}

vuint16m1_t test_vmerge_vxm_u16m1 (vbool16_t mask, vuint16m1_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmerge.vxm.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_u16m1(mask, op1, op2);
}

vuint16m2_t test_vmerge_vvm_u16m2 (vbool8_t mask, vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmerge.vvm.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vmerge_vvm_u16m2(mask, op1, op2);
}

vuint16m2_t test_vmerge_vxm_u16m2 (vbool8_t mask, vuint16m2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmerge.vxm.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_u16m2(mask, op1, op2);
}

vuint16m4_t test_vmerge_vvm_u16m4 (vbool4_t mask, vuint16m4_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmerge.vvm.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vmerge_vvm_u16m4(mask, op1, op2);
}

vuint16m4_t test_vmerge_vxm_u16m4 (vbool4_t mask, vuint16m4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmerge.vxm.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_u16m4(mask, op1, op2);
}

vuint16m8_t test_vmerge_vvm_u16m8 (vbool2_t mask, vuint16m8_t op1, vuint16m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmerge.vvm.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vmerge_vvm_u16m8(mask, op1, op2);
}

vuint16m8_t test_vmerge_vxm_u16m8 (vbool2_t mask, vuint16m8_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmerge.vxm.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmerge_vxm_u16m8(mask, op1, op2);
}

vuint32mf2_t test_vmerge_vvm_u32mf2 (vbool64_t mask, vuint32mf2_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmerge.vvm.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vmerge_vvm_u32mf2(mask, op1, op2);
}

vuint32mf2_t test_vmerge_vxm_u32mf2 (vbool64_t mask, vuint32mf2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmerge.vxm.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_u32mf2(mask, op1, op2);
}

vuint32m1_t test_vmerge_vvm_u32m1 (vbool32_t mask, vuint32m1_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmerge.vvm.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vmerge_vvm_u32m1(mask, op1, op2);
}

vuint32m1_t test_vmerge_vxm_u32m1 (vbool32_t mask, vuint32m1_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmerge.vxm.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_u32m1(mask, op1, op2);
}

vuint32m2_t test_vmerge_vvm_u32m2 (vbool16_t mask, vuint32m2_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmerge.vvm.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vmerge_vvm_u32m2(mask, op1, op2);
}

vuint32m2_t test_vmerge_vxm_u32m2 (vbool16_t mask, vuint32m2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmerge.vxm.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_u32m2(mask, op1, op2);
}

vuint32m4_t test_vmerge_vvm_u32m4 (vbool8_t mask, vuint32m4_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmerge.vvm.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vmerge_vvm_u32m4(mask, op1, op2);
}

vuint32m4_t test_vmerge_vxm_u32m4 (vbool8_t mask, vuint32m4_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmerge.vxm.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_u32m4(mask, op1, op2);
}

vuint32m8_t test_vmerge_vvm_u32m8 (vbool4_t mask, vuint32m8_t op1, vuint32m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmerge.vvm.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vmerge_vvm_u32m8(mask, op1, op2);
}

vuint32m8_t test_vmerge_vxm_u32m8 (vbool4_t mask, vuint32m8_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmerge.vxm.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmerge_vxm_u32m8(mask, op1, op2);
}

vuint64m1_t test_vmerge_vvm_u64m1 (vbool64_t mask, vuint64m1_t op1, vuint64m1_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmerge.vvm.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vmerge_vvm_u64m1(mask, op1, op2);
}

vuint64m1_t test_vmerge_vxm_u64m1 (vbool64_t mask, vuint64m1_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmerge.vxm.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmerge_vxm_u64m1(mask, op1, op2);
}

vuint64m2_t test_vmerge_vvm_u64m2 (vbool32_t mask, vuint64m2_t op1, vuint64m2_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmerge.vvm.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vmerge_vvm_u64m2(mask, op1, op2);
}

vuint64m2_t test_vmerge_vxm_u64m2 (vbool32_t mask, vuint64m2_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmerge.vxm.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmerge_vxm_u64m2(mask, op1, op2);
}

vuint64m4_t test_vmerge_vvm_u64m4 (vbool16_t mask, vuint64m4_t op1, vuint64m4_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmerge.vvm.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vmerge_vvm_u64m4(mask, op1, op2);
}

vuint64m4_t test_vmerge_vxm_u64m4 (vbool16_t mask, vuint64m4_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmerge.vxm.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmerge_vxm_u64m4(mask, op1, op2);
}

vuint64m8_t test_vmerge_vvm_u64m8 (vbool8_t mask, vuint64m8_t op1, vuint64m8_t op2) {
  // CHECK-LABEL: test_vmerge_vvm_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmerge.vvm.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vmerge_vvm_u64m8(mask, op1, op2);
}

vuint64m8_t test_vmerge_vxm_u64m8 (vbool8_t mask, vuint64m8_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmerge_vxm_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmerge.vxm.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmerge_vxm_u64m8(mask, op1, op2);
}


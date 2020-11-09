// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vbool64_t test_vmadc_vvm_i8mf8_b64 (vint8mf8_t op1, vint8mf8_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vvm_i8mf8_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vxm_i8mf8_b64 (vint8mf8_t op1, int8_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vxm.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vxm_i8mf8_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vv_i8mf8_b64 (vint8mf8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vv.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vmadc_vv_i8mf8_b64(op1, op2);
}

vbool64_t test_vmadc_vx_i8mf8_b64 (vint8mf8_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vx.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_i8mf8_b64(op1, op2);
}

vbool32_t test_vmadc_vvm_i8mf4_b32 (vint8mf4_t op1, vint8mf4_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vvm_i8mf4_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vxm_i8mf4_b32 (vint8mf4_t op1, int8_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vxm.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vxm_i8mf4_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vv_i8mf4_b32 (vint8mf4_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vv.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vmadc_vv_i8mf4_b32(op1, op2);
}

vbool32_t test_vmadc_vx_i8mf4_b32 (vint8mf4_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vx.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_i8mf4_b32(op1, op2);
}

vbool16_t test_vmadc_vvm_i8mf2_b16 (vint8mf2_t op1, vint8mf2_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vvm_i8mf2_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vxm_i8mf2_b16 (vint8mf2_t op1, int8_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vxm.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vxm_i8mf2_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vv_i8mf2_b16 (vint8mf2_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vv.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vmadc_vv_i8mf2_b16(op1, op2);
}

vbool16_t test_vmadc_vx_i8mf2_b16 (vint8mf2_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vx.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_i8mf2_b16(op1, op2);
}

vbool8_t test_vmadc_vvm_i8m1_b8 (vint8m1_t op1, vint8m1_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vvm_i8m1_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vxm_i8m1_b8 (vint8m1_t op1, int8_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vxm.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vxm_i8m1_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vv_i8m1_b8 (vint8m1_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vv.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vmadc_vv_i8m1_b8(op1, op2);
}

vbool8_t test_vmadc_vx_i8m1_b8 (vint8m1_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vx.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_i8m1_b8(op1, op2);
}

vbool4_t test_vmadc_vvm_i8m2_b4 (vint8m2_t op1, vint8m2_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vvm_i8m2_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vxm_i8m2_b4 (vint8m2_t op1, int8_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vxm.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vxm_i8m2_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vv_i8m2_b4 (vint8m2_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vv.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vmadc_vv_i8m2_b4(op1, op2);
}

vbool4_t test_vmadc_vx_i8m2_b4 (vint8m2_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vx.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_i8m2_b4(op1, op2);
}

vbool2_t test_vmadc_vvm_i8m4_b2 (vint8m4_t op1, vint8m4_t op2, vbool2_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vmadc_vvm_i8m4_b2(op1, op2, carryin);
}

vbool2_t test_vmadc_vxm_i8m4_b2 (vint8m4_t op1, int8_t op2, vbool2_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vxm.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vmadc_vxm_i8m4_b2(op1, op2, carryin);
}

vbool2_t test_vmadc_vv_i8m4_b2 (vint8m4_t op1, vint8m4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vv.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vmadc_vv_i8m4_b2(op1, op2);
}

vbool2_t test_vmadc_vx_i8m4_b2 (vint8m4_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vx.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_i8m4_b2(op1, op2);
}

vbool1_t test_vmadc_vvm_i8m8_b1 (vint8m8_t op1, vint8m8_t op2, vbool1_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmadc.vvm.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return vmadc_vvm_i8m8_b1(op1, op2, carryin);
}

vbool1_t test_vmadc_vxm_i8m8_b1 (vint8m8_t op1, int8_t op2, vbool1_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmadc.vxm.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return vmadc_vxm_i8m8_b1(op1, op2, carryin);
}

vbool1_t test_vmadc_vv_i8m8_b1 (vint8m8_t op1, vint8m8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmadc.vv.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vmadc_vv_i8m8_b1(op1, op2);
}

vbool1_t test_vmadc_vx_i8m8_b1 (vint8m8_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmadc.vx.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_i8m8_b1(op1, op2);
}

vbool64_t test_vmadc_vvm_i16mf4_b64 (vint16mf4_t op1, vint16mf4_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vvm_i16mf4_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vxm_i16mf4_b64 (vint16mf4_t op1, int16_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vxm.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vxm_i16mf4_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vv_i16mf4_b64 (vint16mf4_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vv.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vmadc_vv_i16mf4_b64(op1, op2);
}

vbool64_t test_vmadc_vx_i16mf4_b64 (vint16mf4_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vx.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_i16mf4_b64(op1, op2);
}

vbool32_t test_vmadc_vvm_i16mf2_b32 (vint16mf2_t op1, vint16mf2_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vvm_i16mf2_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vxm_i16mf2_b32 (vint16mf2_t op1, int16_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vxm.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vxm_i16mf2_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vv_i16mf2_b32 (vint16mf2_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vv.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vmadc_vv_i16mf2_b32(op1, op2);
}

vbool32_t test_vmadc_vx_i16mf2_b32 (vint16mf2_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vx.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_i16mf2_b32(op1, op2);
}

vbool16_t test_vmadc_vvm_i16m1_b16 (vint16m1_t op1, vint16m1_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vvm_i16m1_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vxm_i16m1_b16 (vint16m1_t op1, int16_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vxm.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vxm_i16m1_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vv_i16m1_b16 (vint16m1_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vv.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vmadc_vv_i16m1_b16(op1, op2);
}

vbool16_t test_vmadc_vx_i16m1_b16 (vint16m1_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vx.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_i16m1_b16(op1, op2);
}

vbool8_t test_vmadc_vvm_i16m2_b8 (vint16m2_t op1, vint16m2_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vvm_i16m2_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vxm_i16m2_b8 (vint16m2_t op1, int16_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vxm.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vxm_i16m2_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vv_i16m2_b8 (vint16m2_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vv.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vmadc_vv_i16m2_b8(op1, op2);
}

vbool8_t test_vmadc_vx_i16m2_b8 (vint16m2_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vx.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_i16m2_b8(op1, op2);
}

vbool4_t test_vmadc_vvm_i16m4_b4 (vint16m4_t op1, vint16m4_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vvm_i16m4_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vxm_i16m4_b4 (vint16m4_t op1, int16_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vxm.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vxm_i16m4_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vv_i16m4_b4 (vint16m4_t op1, vint16m4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vv.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vmadc_vv_i16m4_b4(op1, op2);
}

vbool4_t test_vmadc_vx_i16m4_b4 (vint16m4_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vx.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_i16m4_b4(op1, op2);
}

vbool2_t test_vmadc_vvm_i16m8_b2 (vint16m8_t op1, vint16m8_t op2, vbool2_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vmadc_vvm_i16m8_b2(op1, op2, carryin);
}

vbool2_t test_vmadc_vxm_i16m8_b2 (vint16m8_t op1, int16_t op2, vbool2_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vxm.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vmadc_vxm_i16m8_b2(op1, op2, carryin);
}

vbool2_t test_vmadc_vv_i16m8_b2 (vint16m8_t op1, vint16m8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vv.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vmadc_vv_i16m8_b2(op1, op2);
}

vbool2_t test_vmadc_vx_i16m8_b2 (vint16m8_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vx.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_i16m8_b2(op1, op2);
}

vbool64_t test_vmadc_vvm_i32mf2_b64 (vint32mf2_t op1, vint32mf2_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vvm_i32mf2_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vxm_i32mf2_b64 (vint32mf2_t op1, int32_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vxm.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vxm_i32mf2_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vv_i32mf2_b64 (vint32mf2_t op1, vint32mf2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vv.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vmadc_vv_i32mf2_b64(op1, op2);
}

vbool64_t test_vmadc_vx_i32mf2_b64 (vint32mf2_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_i32mf2_b64(op1, op2);
}

vbool32_t test_vmadc_vvm_i32m1_b32 (vint32m1_t op1, vint32m1_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vvm_i32m1_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vxm_i32m1_b32 (vint32m1_t op1, int32_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vxm.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vxm_i32m1_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vv_i32m1_b32 (vint32m1_t op1, vint32m1_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vv.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vmadc_vv_i32m1_b32(op1, op2);
}

vbool32_t test_vmadc_vx_i32m1_b32 (vint32m1_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_i32m1_b32(op1, op2);
}

vbool16_t test_vmadc_vvm_i32m2_b16 (vint32m2_t op1, vint32m2_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vvm_i32m2_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vxm_i32m2_b16 (vint32m2_t op1, int32_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vxm.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vxm_i32m2_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vv_i32m2_b16 (vint32m2_t op1, vint32m2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vv.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vmadc_vv_i32m2_b16(op1, op2);
}

vbool16_t test_vmadc_vx_i32m2_b16 (vint32m2_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_i32m2_b16(op1, op2);
}

vbool8_t test_vmadc_vvm_i32m4_b8 (vint32m4_t op1, vint32m4_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vvm_i32m4_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vxm_i32m4_b8 (vint32m4_t op1, int32_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vxm.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vxm_i32m4_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vv_i32m4_b8 (vint32m4_t op1, vint32m4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vv.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vmadc_vv_i32m4_b8(op1, op2);
}

vbool8_t test_vmadc_vx_i32m4_b8 (vint32m4_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_i32m4_b8(op1, op2);
}

vbool4_t test_vmadc_vvm_i32m8_b4 (vint32m8_t op1, vint32m8_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vvm_i32m8_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vxm_i32m8_b4 (vint32m8_t op1, int32_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vxm.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vxm_i32m8_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vv_i32m8_b4 (vint32m8_t op1, vint32m8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vv.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vmadc_vv_i32m8_b4(op1, op2);
}

vbool4_t test_vmadc_vx_i32m8_b4 (vint32m8_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_i32m8_b4(op1, op2);
}

vbool64_t test_vmadc_vvm_i64m1_b64 (vint64m1_t op1, vint64m1_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vvm_i64m1_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vxm_i64m1_b64 (vint64m1_t op1, int64_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vxm.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vxm_i64m1_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vv_i64m1_b64 (vint64m1_t op1, vint64m1_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vv.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vmadc_vv_i64m1_b64(op1, op2);
}

vbool64_t test_vmadc_vx_i64m1_b64 (vint64m1_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmadc_vx_i64m1_b64(op1, op2);
}

vbool32_t test_vmadc_vvm_i64m2_b32 (vint64m2_t op1, vint64m2_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vvm_i64m2_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vxm_i64m2_b32 (vint64m2_t op1, int64_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vxm.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vxm_i64m2_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vv_i64m2_b32 (vint64m2_t op1, vint64m2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vv.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vmadc_vv_i64m2_b32(op1, op2);
}

vbool32_t test_vmadc_vx_i64m2_b32 (vint64m2_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmadc_vx_i64m2_b32(op1, op2);
}

vbool16_t test_vmadc_vvm_i64m4_b16 (vint64m4_t op1, vint64m4_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vvm_i64m4_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vxm_i64m4_b16 (vint64m4_t op1, int64_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vxm.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vxm_i64m4_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vv_i64m4_b16 (vint64m4_t op1, vint64m4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vv.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vmadc_vv_i64m4_b16(op1, op2);
}

vbool16_t test_vmadc_vx_i64m4_b16 (vint64m4_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmadc_vx_i64m4_b16(op1, op2);
}

vbool8_t test_vmadc_vvm_i64m8_b8 (vint64m8_t op1, vint64m8_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_i64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vvm_i64m8_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vxm_i64m8_b8 (vint64m8_t op1, int64_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_i64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vxm.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vxm_i64m8_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vv_i64m8_b8 (vint64m8_t op1, vint64m8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_i64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vv.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vmadc_vv_i64m8_b8(op1, op2);
}

vbool8_t test_vmadc_vx_i64m8_b8 (vint64m8_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmadc_vx_i64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmadc_vx_i64m8_b8(op1, op2);
}

vbool64_t test_vmadc_vvm_u8mf8_b64 (vuint8mf8_t op1, vuint8mf8_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vvm_u8mf8_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vxm_u8mf8_b64 (vuint8mf8_t op1, uint8_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vxm.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vxm_u8mf8_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vv_u8mf8_b64 (vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vv.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vmadc_vv_u8mf8_b64(op1, op2);
}

vbool64_t test_vmadc_vx_u8mf8_b64 (vuint8mf8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vx.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_u8mf8_b64(op1, op2);
}

vbool32_t test_vmadc_vvm_u8mf4_b32 (vuint8mf4_t op1, vuint8mf4_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vvm_u8mf4_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vxm_u8mf4_b32 (vuint8mf4_t op1, uint8_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vxm.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vxm_u8mf4_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vv_u8mf4_b32 (vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vv.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vmadc_vv_u8mf4_b32(op1, op2);
}

vbool32_t test_vmadc_vx_u8mf4_b32 (vuint8mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vx.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_u8mf4_b32(op1, op2);
}

vbool16_t test_vmadc_vvm_u8mf2_b16 (vuint8mf2_t op1, vuint8mf2_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vvm_u8mf2_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vxm_u8mf2_b16 (vuint8mf2_t op1, uint8_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vxm.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vxm_u8mf2_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vv_u8mf2_b16 (vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vv.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vmadc_vv_u8mf2_b16(op1, op2);
}

vbool16_t test_vmadc_vx_u8mf2_b16 (vuint8mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vx.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_u8mf2_b16(op1, op2);
}

vbool8_t test_vmadc_vvm_u8m1_b8 (vuint8m1_t op1, vuint8m1_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vvm_u8m1_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vxm_u8m1_b8 (vuint8m1_t op1, uint8_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vxm.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vxm_u8m1_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vv_u8m1_b8 (vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vv.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vmadc_vv_u8m1_b8(op1, op2);
}

vbool8_t test_vmadc_vx_u8m1_b8 (vuint8m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vx.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_u8m1_b8(op1, op2);
}

vbool4_t test_vmadc_vvm_u8m2_b4 (vuint8m2_t op1, vuint8m2_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vvm_u8m2_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vxm_u8m2_b4 (vuint8m2_t op1, uint8_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vxm.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vxm_u8m2_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vv_u8m2_b4 (vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vv.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vmadc_vv_u8m2_b4(op1, op2);
}

vbool4_t test_vmadc_vx_u8m2_b4 (vuint8m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vx.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_u8m2_b4(op1, op2);
}

vbool2_t test_vmadc_vvm_u8m4_b2 (vuint8m4_t op1, vuint8m4_t op2, vbool2_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vmadc_vvm_u8m4_b2(op1, op2, carryin);
}

vbool2_t test_vmadc_vxm_u8m4_b2 (vuint8m4_t op1, uint8_t op2, vbool2_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vxm.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vmadc_vxm_u8m4_b2(op1, op2, carryin);
}

vbool2_t test_vmadc_vv_u8m4_b2 (vuint8m4_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vv.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vmadc_vv_u8m4_b2(op1, op2);
}

vbool2_t test_vmadc_vx_u8m4_b2 (vuint8m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vx.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_u8m4_b2(op1, op2);
}

vbool1_t test_vmadc_vvm_u8m8_b1 (vuint8m8_t op1, vuint8m8_t op2, vbool1_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmadc.vvm.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return vmadc_vvm_u8m8_b1(op1, op2, carryin);
}

vbool1_t test_vmadc_vxm_u8m8_b1 (vuint8m8_t op1, uint8_t op2, vbool1_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmadc.vxm.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return vmadc_vxm_u8m8_b1(op1, op2, carryin);
}

vbool1_t test_vmadc_vv_u8m8_b1 (vuint8m8_t op1, vuint8m8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmadc.vv.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vmadc_vv_u8m8_b1(op1, op2);
}

vbool1_t test_vmadc_vx_u8m8_b1 (vuint8m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmadc.vx.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmadc_vx_u8m8_b1(op1, op2);
}

vbool64_t test_vmadc_vvm_u16mf4_b64 (vuint16mf4_t op1, vuint16mf4_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vvm_u16mf4_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vxm_u16mf4_b64 (vuint16mf4_t op1, uint16_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vxm.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vxm_u16mf4_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vv_u16mf4_b64 (vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vv.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vmadc_vv_u16mf4_b64(op1, op2);
}

vbool64_t test_vmadc_vx_u16mf4_b64 (vuint16mf4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vx.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_u16mf4_b64(op1, op2);
}

vbool32_t test_vmadc_vvm_u16mf2_b32 (vuint16mf2_t op1, vuint16mf2_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vvm_u16mf2_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vxm_u16mf2_b32 (vuint16mf2_t op1, uint16_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vxm.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vxm_u16mf2_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vv_u16mf2_b32 (vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vv.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vmadc_vv_u16mf2_b32(op1, op2);
}

vbool32_t test_vmadc_vx_u16mf2_b32 (vuint16mf2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vx.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_u16mf2_b32(op1, op2);
}

vbool16_t test_vmadc_vvm_u16m1_b16 (vuint16m1_t op1, vuint16m1_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vvm_u16m1_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vxm_u16m1_b16 (vuint16m1_t op1, uint16_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vxm.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vxm_u16m1_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vv_u16m1_b16 (vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vv.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vmadc_vv_u16m1_b16(op1, op2);
}

vbool16_t test_vmadc_vx_u16m1_b16 (vuint16m1_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vx.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_u16m1_b16(op1, op2);
}

vbool8_t test_vmadc_vvm_u16m2_b8 (vuint16m2_t op1, vuint16m2_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vvm_u16m2_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vxm_u16m2_b8 (vuint16m2_t op1, uint16_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vxm.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vxm_u16m2_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vv_u16m2_b8 (vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vv.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vmadc_vv_u16m2_b8(op1, op2);
}

vbool8_t test_vmadc_vx_u16m2_b8 (vuint16m2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vx.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_u16m2_b8(op1, op2);
}

vbool4_t test_vmadc_vvm_u16m4_b4 (vuint16m4_t op1, vuint16m4_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vvm_u16m4_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vxm_u16m4_b4 (vuint16m4_t op1, uint16_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vxm.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vxm_u16m4_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vv_u16m4_b4 (vuint16m4_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vv.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vmadc_vv_u16m4_b4(op1, op2);
}

vbool4_t test_vmadc_vx_u16m4_b4 (vuint16m4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vx.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_u16m4_b4(op1, op2);
}

vbool2_t test_vmadc_vvm_u16m8_b2 (vuint16m8_t op1, vuint16m8_t op2, vbool2_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vmadc_vvm_u16m8_b2(op1, op2, carryin);
}

vbool2_t test_vmadc_vxm_u16m8_b2 (vuint16m8_t op1, uint16_t op2, vbool2_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vxm.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vmadc_vxm_u16m8_b2(op1, op2, carryin);
}

vbool2_t test_vmadc_vv_u16m8_b2 (vuint16m8_t op1, vuint16m8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vv.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vmadc_vv_u16m8_b2(op1, op2);
}

vbool2_t test_vmadc_vx_u16m8_b2 (vuint16m8_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmadc.vx.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmadc_vx_u16m8_b2(op1, op2);
}

vbool64_t test_vmadc_vvm_u32mf2_b64 (vuint32mf2_t op1, vuint32mf2_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vvm_u32mf2_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vxm_u32mf2_b64 (vuint32mf2_t op1, uint32_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vxm.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vxm_u32mf2_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vv_u32mf2_b64 (vuint32mf2_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vv.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vmadc_vv_u32mf2_b64(op1, op2);
}

vbool64_t test_vmadc_vx_u32mf2_b64 (vuint32mf2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_u32mf2_b64(op1, op2);
}

vbool32_t test_vmadc_vvm_u32m1_b32 (vuint32m1_t op1, vuint32m1_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vvm_u32m1_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vxm_u32m1_b32 (vuint32m1_t op1, uint32_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vxm.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vxm_u32m1_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vv_u32m1_b32 (vuint32m1_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vv.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vmadc_vv_u32m1_b32(op1, op2);
}

vbool32_t test_vmadc_vx_u32m1_b32 (vuint32m1_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_u32m1_b32(op1, op2);
}

vbool16_t test_vmadc_vvm_u32m2_b16 (vuint32m2_t op1, vuint32m2_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vvm_u32m2_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vxm_u32m2_b16 (vuint32m2_t op1, uint32_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vxm.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vxm_u32m2_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vv_u32m2_b16 (vuint32m2_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vv.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vmadc_vv_u32m2_b16(op1, op2);
}

vbool16_t test_vmadc_vx_u32m2_b16 (vuint32m2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_u32m2_b16(op1, op2);
}

vbool8_t test_vmadc_vvm_u32m4_b8 (vuint32m4_t op1, vuint32m4_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vvm_u32m4_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vxm_u32m4_b8 (vuint32m4_t op1, uint32_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vxm.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vxm_u32m4_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vv_u32m4_b8 (vuint32m4_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vv.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vmadc_vv_u32m4_b8(op1, op2);
}

vbool8_t test_vmadc_vx_u32m4_b8 (vuint32m4_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_u32m4_b8(op1, op2);
}

vbool4_t test_vmadc_vvm_u32m8_b4 (vuint32m8_t op1, vuint32m8_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vvm_u32m8_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vxm_u32m8_b4 (vuint32m8_t op1, uint32_t op2, vbool4_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vxm.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmadc_vxm_u32m8_b4(op1, op2, carryin);
}

vbool4_t test_vmadc_vv_u32m8_b4 (vuint32m8_t op1, vuint32m8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vv.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vmadc_vv_u32m8_b4(op1, op2);
}

vbool4_t test_vmadc_vx_u32m8_b4 (vuint32m8_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmadc.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmadc_vx_u32m8_b4(op1, op2);
}

vbool64_t test_vmadc_vvm_u64m1_b64 (vuint64m1_t op1, vuint64m1_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vvm_u64m1_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vxm_u64m1_b64 (vuint64m1_t op1, uint64_t op2, vbool64_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vxm.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmadc_vxm_u64m1_b64(op1, op2, carryin);
}

vbool64_t test_vmadc_vv_u64m1_b64 (vuint64m1_t op1, vuint64m1_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vv.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vmadc_vv_u64m1_b64(op1, op2);
}

vbool64_t test_vmadc_vx_u64m1_b64 (vuint64m1_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmadc.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmadc_vx_u64m1_b64(op1, op2);
}

vbool32_t test_vmadc_vvm_u64m2_b32 (vuint64m2_t op1, vuint64m2_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vvm_u64m2_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vxm_u64m2_b32 (vuint64m2_t op1, uint64_t op2, vbool32_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vxm.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmadc_vxm_u64m2_b32(op1, op2, carryin);
}

vbool32_t test_vmadc_vv_u64m2_b32 (vuint64m2_t op1, vuint64m2_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vv.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vmadc_vv_u64m2_b32(op1, op2);
}

vbool32_t test_vmadc_vx_u64m2_b32 (vuint64m2_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmadc.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmadc_vx_u64m2_b32(op1, op2);
}

vbool16_t test_vmadc_vvm_u64m4_b16 (vuint64m4_t op1, vuint64m4_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vvm_u64m4_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vxm_u64m4_b16 (vuint64m4_t op1, uint64_t op2, vbool16_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vxm.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmadc_vxm_u64m4_b16(op1, op2, carryin);
}

vbool16_t test_vmadc_vv_u64m4_b16 (vuint64m4_t op1, vuint64m4_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vv.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vmadc_vv_u64m4_b16(op1, op2);
}

vbool16_t test_vmadc_vx_u64m4_b16 (vuint64m4_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmadc.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmadc_vx_u64m4_b16(op1, op2);
}

vbool8_t test_vmadc_vvm_u64m8_b8 (vuint64m8_t op1, vuint64m8_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vvm_u64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vvm_u64m8_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vxm_u64m8_b8 (vuint64m8_t op1, uint64_t op2, vbool8_t carryin) {
  // CHECK-LABEL: test_vmadc_vxm_u64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vxm.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmadc_vxm_u64m8_b8(op1, op2, carryin);
}

vbool8_t test_vmadc_vv_u64m8_b8 (vuint64m8_t op1, vuint64m8_t op2) {
  // CHECK-LABEL: test_vmadc_vv_u64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vv.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vmadc_vv_u64m8_b8(op1, op2);
}

vbool8_t test_vmadc_vx_u64m8_b8 (vuint64m8_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmadc_vx_u64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmadc.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmadc_vx_u64m8_b8(op1, op2);
}


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vbool64_t test_vmslt_vv_i8mf8_b64 (vint8mf8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vv.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vmslt_vv_i8mf8_b64(op1, op2);
}

vbool64_t test_vmslt_vx_i8mf8_b64 (vint8mf8_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vx.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8mf8_b64(op1, op2);
}

vbool32_t test_vmslt_vv_i8mf4_b32 (vint8mf4_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vv.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vmslt_vv_i8mf4_b32(op1, op2);
}

vbool32_t test_vmslt_vx_i8mf4_b32 (vint8mf4_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vx.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8mf4_b32(op1, op2);
}

vbool16_t test_vmslt_vv_i8mf2_b16 (vint8mf2_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vv.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vmslt_vv_i8mf2_b16(op1, op2);
}

vbool16_t test_vmslt_vx_i8mf2_b16 (vint8mf2_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vx.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8mf2_b16(op1, op2);
}

vbool8_t test_vmslt_vv_i8m1_b8 (vint8m1_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vv.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vmslt_vv_i8m1_b8(op1, op2);
}

vbool8_t test_vmslt_vx_i8m1_b8 (vint8m1_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vx.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8m1_b8(op1, op2);
}

vbool4_t test_vmslt_vv_i8m2_b4 (vint8m2_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vv.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vmslt_vv_i8m2_b4(op1, op2);
}

vbool4_t test_vmslt_vx_i8m2_b4 (vint8m2_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vx.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8m2_b4(op1, op2);
}

vbool2_t test_vmslt_vv_i8m4_b2 (vint8m4_t op1, vint8m4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmslt.vv.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vmslt_vv_i8m4_b2(op1, op2);
}

vbool2_t test_vmslt_vx_i8m4_b2 (vint8m4_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmslt.vx.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8m4_b2(op1, op2);
}

vbool1_t test_vmslt_vv_i8m8_b1 (vint8m8_t op1, vint8m8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmslt.vv.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vmslt_vv_i8m8_b1(op1, op2);
}

vbool1_t test_vmslt_vx_i8m8_b1 (vint8m8_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmslt.vx.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8m8_b1(op1, op2);
}

vbool64_t test_vmslt_vv_i16mf4_b64 (vint16mf4_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vv.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vmslt_vv_i16mf4_b64(op1, op2);
}

vbool64_t test_vmslt_vx_i16mf4_b64 (vint16mf4_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vx.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16mf4_b64(op1, op2);
}

vbool32_t test_vmslt_vv_i16mf2_b32 (vint16mf2_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vv.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vmslt_vv_i16mf2_b32(op1, op2);
}

vbool32_t test_vmslt_vx_i16mf2_b32 (vint16mf2_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vx.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16mf2_b32(op1, op2);
}

vbool16_t test_vmslt_vv_i16m1_b16 (vint16m1_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vv.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vmslt_vv_i16m1_b16(op1, op2);
}

vbool16_t test_vmslt_vx_i16m1_b16 (vint16m1_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vx.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16m1_b16(op1, op2);
}

vbool8_t test_vmslt_vv_i16m2_b8 (vint16m2_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vv.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vmslt_vv_i16m2_b8(op1, op2);
}

vbool8_t test_vmslt_vx_i16m2_b8 (vint16m2_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vx.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16m2_b8(op1, op2);
}

vbool4_t test_vmslt_vv_i16m4_b4 (vint16m4_t op1, vint16m4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vv.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vmslt_vv_i16m4_b4(op1, op2);
}

vbool4_t test_vmslt_vx_i16m4_b4 (vint16m4_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vx.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16m4_b4(op1, op2);
}

vbool2_t test_vmslt_vv_i16m8_b2 (vint16m8_t op1, vint16m8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmslt.vv.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vmslt_vv_i16m8_b2(op1, op2);
}

vbool2_t test_vmslt_vx_i16m8_b2 (vint16m8_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmslt.vx.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16m8_b2(op1, op2);
}

vbool64_t test_vmslt_vv_i32mf2_b64 (vint32mf2_t op1, vint32mf2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vv.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vmslt_vv_i32mf2_b64(op1, op2);
}

vbool64_t test_vmslt_vx_i32mf2_b64 (vint32mf2_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32mf2_b64(op1, op2);
}

vbool32_t test_vmslt_vv_i32m1_b32 (vint32m1_t op1, vint32m1_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vv.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vmslt_vv_i32m1_b32(op1, op2);
}

vbool32_t test_vmslt_vx_i32m1_b32 (vint32m1_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32m1_b32(op1, op2);
}

vbool16_t test_vmslt_vv_i32m2_b16 (vint32m2_t op1, vint32m2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vv.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vmslt_vv_i32m2_b16(op1, op2);
}

vbool16_t test_vmslt_vx_i32m2_b16 (vint32m2_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32m2_b16(op1, op2);
}

vbool8_t test_vmslt_vv_i32m4_b8 (vint32m4_t op1, vint32m4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vv.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vmslt_vv_i32m4_b8(op1, op2);
}

vbool8_t test_vmslt_vx_i32m4_b8 (vint32m4_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32m4_b8(op1, op2);
}

vbool4_t test_vmslt_vv_i32m8_b4 (vint32m8_t op1, vint32m8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vv.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vmslt_vv_i32m8_b4(op1, op2);
}

vbool4_t test_vmslt_vx_i32m8_b4 (vint32m8_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32m8_b4(op1, op2);
}

vbool64_t test_vmslt_vv_i64m1_b64 (vint64m1_t op1, vint64m1_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vv.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vmslt_vv_i64m1_b64(op1, op2);
}

vbool64_t test_vmslt_vx_i64m1_b64 (vint64m1_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmslt_vx_i64m1_b64(op1, op2);
}

vbool32_t test_vmslt_vv_i64m2_b32 (vint64m2_t op1, vint64m2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vv.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vmslt_vv_i64m2_b32(op1, op2);
}

vbool32_t test_vmslt_vx_i64m2_b32 (vint64m2_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmslt_vx_i64m2_b32(op1, op2);
}

vbool16_t test_vmslt_vv_i64m4_b16 (vint64m4_t op1, vint64m4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vv.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vmslt_vv_i64m4_b16(op1, op2);
}

vbool16_t test_vmslt_vx_i64m4_b16 (vint64m4_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmslt_vx_i64m4_b16(op1, op2);
}

vbool8_t test_vmslt_vv_i64m8_b8 (vint64m8_t op1, vint64m8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vv.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vmslt_vv_i64m8_b8(op1, op2);
}

vbool8_t test_vmslt_vx_i64m8_b8 (vint64m8_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmslt_vx_i64m8_b8(op1, op2);
}

vbool64_t test_vmslt_vv_i8mf8_b64_m (vbool64_t mask, vbool64_t maskedoff, vint8mf8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8mf8_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vv.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vmslt_vv_i8mf8_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmslt_vx_i8mf8_b64_m (vbool64_t mask, vbool64_t maskedoff, vint8mf8_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8mf8_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vx.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8mf8_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmslt_vv_i8mf4_b32_m (vbool32_t mask, vbool32_t maskedoff, vint8mf4_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8mf4_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vv.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vmslt_vv_i8mf4_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmslt_vx_i8mf4_b32_m (vbool32_t mask, vbool32_t maskedoff, vint8mf4_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8mf4_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vx.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8mf4_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmslt_vv_i8mf2_b16_m (vbool16_t mask, vbool16_t maskedoff, vint8mf2_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8mf2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vv.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vmslt_vv_i8mf2_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmslt_vx_i8mf2_b16_m (vbool16_t mask, vbool16_t maskedoff, vint8mf2_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8mf2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vx.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8mf2_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmslt_vv_i8m1_b8_m (vbool8_t mask, vbool8_t maskedoff, vint8m1_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8m1_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vv.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vmslt_vv_i8m1_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmslt_vx_i8m1_b8_m (vbool8_t mask, vbool8_t maskedoff, vint8m1_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8m1_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vx.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8m1_b8_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmslt_vv_i8m2_b4_m (vbool4_t mask, vbool4_t maskedoff, vint8m2_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8m2_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vv.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vmslt_vv_i8m2_b4_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmslt_vx_i8m2_b4_m (vbool4_t mask, vbool4_t maskedoff, vint8m2_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8m2_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vx.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8m2_b4_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmslt_vv_i8m4_b2_m (vbool2_t mask, vbool2_t maskedoff, vint8m4_t op1, vint8m4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8m4_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmslt.vv.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vmslt_vv_i8m4_b2_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmslt_vx_i8m4_b2_m (vbool2_t mask, vbool2_t maskedoff, vint8m4_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8m4_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmslt.vx.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8m4_b2_m(mask, maskedoff, op1, op2);
}

vbool1_t test_vmslt_vv_i8m8_b1_m (vbool1_t mask, vbool1_t maskedoff, vint8m8_t op1, vint8m8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i8m8_b1_m
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmslt.vv.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vmslt_vv_i8m8_b1_m(mask, maskedoff, op1, op2);
}

vbool1_t test_vmslt_vx_i8m8_b1_m (vbool1_t mask, vbool1_t maskedoff, vint8m8_t op1, int8_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i8m8_b1_m
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmslt.vx.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmslt_vx_i8m8_b1_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmslt_vv_i16mf4_b64_m (vbool64_t mask, vbool64_t maskedoff, vint16mf4_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16mf4_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vv.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vmslt_vv_i16mf4_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmslt_vx_i16mf4_b64_m (vbool64_t mask, vbool64_t maskedoff, vint16mf4_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16mf4_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vx.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16mf4_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmslt_vv_i16mf2_b32_m (vbool32_t mask, vbool32_t maskedoff, vint16mf2_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16mf2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vv.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vmslt_vv_i16mf2_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmslt_vx_i16mf2_b32_m (vbool32_t mask, vbool32_t maskedoff, vint16mf2_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16mf2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vx.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16mf2_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmslt_vv_i16m1_b16_m (vbool16_t mask, vbool16_t maskedoff, vint16m1_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16m1_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vv.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vmslt_vv_i16m1_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmslt_vx_i16m1_b16_m (vbool16_t mask, vbool16_t maskedoff, vint16m1_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16m1_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vx.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16m1_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmslt_vv_i16m2_b8_m (vbool8_t mask, vbool8_t maskedoff, vint16m2_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16m2_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vv.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vmslt_vv_i16m2_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmslt_vx_i16m2_b8_m (vbool8_t mask, vbool8_t maskedoff, vint16m2_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16m2_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vx.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16m2_b8_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmslt_vv_i16m4_b4_m (vbool4_t mask, vbool4_t maskedoff, vint16m4_t op1, vint16m4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16m4_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vv.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vmslt_vv_i16m4_b4_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmslt_vx_i16m4_b4_m (vbool4_t mask, vbool4_t maskedoff, vint16m4_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16m4_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vx.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16m4_b4_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmslt_vv_i16m8_b2_m (vbool2_t mask, vbool2_t maskedoff, vint16m8_t op1, vint16m8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i16m8_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmslt.vv.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vmslt_vv_i16m8_b2_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmslt_vx_i16m8_b2_m (vbool2_t mask, vbool2_t maskedoff, vint16m8_t op1, int16_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i16m8_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmslt.vx.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmslt_vx_i16m8_b2_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmslt_vv_i32mf2_b64_m (vbool64_t mask, vbool64_t maskedoff, vint32mf2_t op1, vint32mf2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32mf2_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vv.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vmslt_vv_i32mf2_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmslt_vx_i32mf2_b64_m (vbool64_t mask, vbool64_t maskedoff, vint32mf2_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32mf2_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vx.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32mf2_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmslt_vv_i32m1_b32_m (vbool32_t mask, vbool32_t maskedoff, vint32m1_t op1, vint32m1_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32m1_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vv.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vmslt_vv_i32m1_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmslt_vx_i32m1_b32_m (vbool32_t mask, vbool32_t maskedoff, vint32m1_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32m1_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vx.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32m1_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmslt_vv_i32m2_b16_m (vbool16_t mask, vbool16_t maskedoff, vint32m2_t op1, vint32m2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32m2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vv.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vmslt_vv_i32m2_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmslt_vx_i32m2_b16_m (vbool16_t mask, vbool16_t maskedoff, vint32m2_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32m2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vx.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32m2_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmslt_vv_i32m4_b8_m (vbool8_t mask, vbool8_t maskedoff, vint32m4_t op1, vint32m4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32m4_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vv.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vmslt_vv_i32m4_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmslt_vx_i32m4_b8_m (vbool8_t mask, vbool8_t maskedoff, vint32m4_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32m4_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vx.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32m4_b8_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmslt_vv_i32m8_b4_m (vbool4_t mask, vbool4_t maskedoff, vint32m8_t op1, vint32m8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i32m8_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vv.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vmslt_vv_i32m8_b4_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmslt_vx_i32m8_b4_m (vbool4_t mask, vbool4_t maskedoff, vint32m8_t op1, int32_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i32m8_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmslt.vx.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmslt_vx_i32m8_b4_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmslt_vv_i64m1_b64_m (vbool64_t mask, vbool64_t maskedoff, vint64m1_t op1, vint64m1_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i64m1_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vv.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vmslt_vv_i64m1_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmslt_vx_i64m1_b64_m (vbool64_t mask, vbool64_t maskedoff, vint64m1_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i64m1_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmslt.vx.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmslt_vx_i64m1_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmslt_vv_i64m2_b32_m (vbool32_t mask, vbool32_t maskedoff, vint64m2_t op1, vint64m2_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i64m2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vv.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vmslt_vv_i64m2_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmslt_vx_i64m2_b32_m (vbool32_t mask, vbool32_t maskedoff, vint64m2_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i64m2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmslt.vx.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmslt_vx_i64m2_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmslt_vv_i64m4_b16_m (vbool16_t mask, vbool16_t maskedoff, vint64m4_t op1, vint64m4_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i64m4_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vv.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vmslt_vv_i64m4_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmslt_vx_i64m4_b16_m (vbool16_t mask, vbool16_t maskedoff, vint64m4_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i64m4_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmslt.vx.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmslt_vx_i64m4_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmslt_vv_i64m8_b8_m (vbool8_t mask, vbool8_t maskedoff, vint64m8_t op1, vint64m8_t op2) {
  // CHECK-LABEL: test_vmslt_vv_i64m8_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vv.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vmslt_vv_i64m8_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmslt_vx_i64m8_b8_m (vbool8_t mask, vbool8_t maskedoff, vint64m8_t op1, int64_t op2) {
  // CHECK-LABEL: test_vmslt_vx_i64m8_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmslt.vx.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmslt_vx_i64m8_b8_m(mask, maskedoff, op1, op2);
}


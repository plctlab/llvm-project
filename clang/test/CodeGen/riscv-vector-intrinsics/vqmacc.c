// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2_t test_vqmacc_vv_i32mf2 (vint32mf2_t acc, vint8mf8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmacc.vv.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmacc_vv_i32mf2(acc, op1, op2);
}

vint32mf2_t test_vqmacc_vx_i32mf2 (vint32mf2_t acc, int8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmacc.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmacc_vx_i32mf2(acc, op1, op2);
}

vint32m1_t test_vqmacc_vv_i32m1 (vint32m1_t acc, vint8mf4_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmacc.vv.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmacc_vv_i32m1(acc, op1, op2);
}

vint32m1_t test_vqmacc_vx_i32m1 (vint32m1_t acc, int8_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmacc.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmacc_vx_i32m1(acc, op1, op2);
}

vint32m2_t test_vqmacc_vv_i32m2 (vint32m2_t acc, vint8mf2_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmacc.vv.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmacc_vv_i32m2(acc, op1, op2);
}

vint32m2_t test_vqmacc_vx_i32m2 (vint32m2_t acc, int8_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmacc.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmacc_vx_i32m2(acc, op1, op2);
}

vint32m4_t test_vqmacc_vv_i32m4 (vint32m4_t acc, vint8m1_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmacc.vv.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmacc_vv_i32m4(acc, op1, op2);
}

vint32m4_t test_vqmacc_vx_i32m4 (vint32m4_t acc, int8_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmacc.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmacc_vx_i32m4(acc, op1, op2);
}

vint32m8_t test_vqmacc_vv_i32m8 (vint32m8_t acc, vint8m2_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmacc.vv.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmacc_vv_i32m8(acc, op1, op2);
}

vint32m8_t test_vqmacc_vx_i32m8 (vint32m8_t acc, int8_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmacc.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmacc_vx_i32m8(acc, op1, op2);
}

vint64m1_t test_vqmacc_vv_i64m1 (vint64m1_t acc, vint16mf4_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmacc.vv.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmacc_vv_i64m1(acc, op1, op2);
}

vint64m1_t test_vqmacc_vx_i64m1 (vint64m1_t acc, int16_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmacc.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmacc_vx_i64m1(acc, op1, op2);
}

vint64m2_t test_vqmacc_vv_i64m2 (vint64m2_t acc, vint16mf2_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmacc.vv.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmacc_vv_i64m2(acc, op1, op2);
}

vint64m2_t test_vqmacc_vx_i64m2 (vint64m2_t acc, int16_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmacc.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmacc_vx_i64m2(acc, op1, op2);
}

vint64m4_t test_vqmacc_vv_i64m4 (vint64m4_t acc, vint16m1_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmacc.vv.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmacc_vv_i64m4(acc, op1, op2);
}

vint64m4_t test_vqmacc_vx_i64m4 (vint64m4_t acc, int16_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmacc.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmacc_vx_i64m4(acc, op1, op2);
}

vint64m8_t test_vqmacc_vv_i64m8 (vint64m8_t acc, vint16m2_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmacc.vv.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmacc_vv_i64m8(acc, op1, op2);
}

vint64m8_t test_vqmacc_vx_i64m8 (vint64m8_t acc, int16_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmacc.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmacc_vx_i64m8(acc, op1, op2);
}

vint32mf2_t test_vqmacc_vv_i32mf2_m (vbool64_t mask, vint32mf2_t acc, vint8mf8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmacc.vv.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmacc_vv_i32mf2_m(mask, acc, op1, op2);
}

vint32mf2_t test_vqmacc_vx_i32mf2_m (vbool64_t mask, vint32mf2_t acc, int8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmacc.vx.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmacc_vx_i32mf2_m(mask, acc, op1, op2);
}

vint32m1_t test_vqmacc_vv_i32m1_m (vbool32_t mask, vint32m1_t acc, vint8mf4_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmacc.vv.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmacc_vv_i32m1_m(mask, acc, op1, op2);
}

vint32m1_t test_vqmacc_vx_i32m1_m (vbool32_t mask, vint32m1_t acc, int8_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmacc.vx.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmacc_vx_i32m1_m(mask, acc, op1, op2);
}

vint32m2_t test_vqmacc_vv_i32m2_m (vbool16_t mask, vint32m2_t acc, vint8mf2_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmacc.vv.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmacc_vv_i32m2_m(mask, acc, op1, op2);
}

vint32m2_t test_vqmacc_vx_i32m2_m (vbool16_t mask, vint32m2_t acc, int8_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmacc.vx.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmacc_vx_i32m2_m(mask, acc, op1, op2);
}

vint32m4_t test_vqmacc_vv_i32m4_m (vbool8_t mask, vint32m4_t acc, vint8m1_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmacc.vv.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmacc_vv_i32m4_m(mask, acc, op1, op2);
}

vint32m4_t test_vqmacc_vx_i32m4_m (vbool8_t mask, vint32m4_t acc, int8_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmacc.vx.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmacc_vx_i32m4_m(mask, acc, op1, op2);
}

vint32m8_t test_vqmacc_vv_i32m8_m (vbool4_t mask, vint32m8_t acc, vint8m2_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmacc.vv.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmacc_vv_i32m8_m(mask, acc, op1, op2);
}

vint32m8_t test_vqmacc_vx_i32m8_m (vbool4_t mask, vint32m8_t acc, int8_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmacc.vx.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmacc_vx_i32m8_m(mask, acc, op1, op2);
}

vint64m1_t test_vqmacc_vv_i64m1_m (vbool64_t mask, vint64m1_t acc, vint16mf4_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmacc.vv.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmacc_vv_i64m1_m(mask, acc, op1, op2);
}

vint64m1_t test_vqmacc_vx_i64m1_m (vbool64_t mask, vint64m1_t acc, int16_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmacc.vx.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmacc_vx_i64m1_m(mask, acc, op1, op2);
}

vint64m2_t test_vqmacc_vv_i64m2_m (vbool32_t mask, vint64m2_t acc, vint16mf2_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmacc.vv.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmacc_vv_i64m2_m(mask, acc, op1, op2);
}

vint64m2_t test_vqmacc_vx_i64m2_m (vbool32_t mask, vint64m2_t acc, int16_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmacc.vx.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmacc_vx_i64m2_m(mask, acc, op1, op2);
}

vint64m4_t test_vqmacc_vv_i64m4_m (vbool16_t mask, vint64m4_t acc, vint16m1_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmacc.vv.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmacc_vv_i64m4_m(mask, acc, op1, op2);
}

vint64m4_t test_vqmacc_vx_i64m4_m (vbool16_t mask, vint64m4_t acc, int16_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmacc.vx.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmacc_vx_i64m4_m(mask, acc, op1, op2);
}

vint64m8_t test_vqmacc_vv_i64m8_m (vbool8_t mask, vint64m8_t acc, vint16m2_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vqmacc_vv_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmacc.vv.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmacc_vv_i64m8_m(mask, acc, op1, op2);
}

vint64m8_t test_vqmacc_vx_i64m8_m (vbool8_t mask, vint64m8_t acc, int16_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vqmacc_vx_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmacc.vx.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmacc_vx_i64m8_m(mask, acc, op1, op2);
}


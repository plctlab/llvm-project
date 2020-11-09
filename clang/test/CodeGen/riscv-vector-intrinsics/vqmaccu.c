// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint32mf2_t test_vqmaccu_vv_u32mf2 (vuint32mf2_t acc, vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmaccu.vv.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmaccu_vv_u32mf2(acc, op1, op2);
}

vuint32mf2_t test_vqmaccu_vx_u32mf2 (vuint32mf2_t acc, uint8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmaccu.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmaccu_vx_u32mf2(acc, op1, op2);
}

vuint32m1_t test_vqmaccu_vv_u32m1 (vuint32m1_t acc, vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmaccu.vv.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmaccu_vv_u32m1(acc, op1, op2);
}

vuint32m1_t test_vqmaccu_vx_u32m1 (vuint32m1_t acc, uint8_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmaccu.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmaccu_vx_u32m1(acc, op1, op2);
}

vuint32m2_t test_vqmaccu_vv_u32m2 (vuint32m2_t acc, vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmaccu.vv.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmaccu_vv_u32m2(acc, op1, op2);
}

vuint32m2_t test_vqmaccu_vx_u32m2 (vuint32m2_t acc, uint8_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmaccu.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmaccu_vx_u32m2(acc, op1, op2);
}

vuint32m4_t test_vqmaccu_vv_u32m4 (vuint32m4_t acc, vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmaccu.vv.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmaccu_vv_u32m4(acc, op1, op2);
}

vuint32m4_t test_vqmaccu_vx_u32m4 (vuint32m4_t acc, uint8_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmaccu.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmaccu_vx_u32m4(acc, op1, op2);
}

vuint32m8_t test_vqmaccu_vv_u32m8 (vuint32m8_t acc, vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmaccu.vv.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmaccu_vv_u32m8(acc, op1, op2);
}

vuint32m8_t test_vqmaccu_vx_u32m8 (vuint32m8_t acc, uint8_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmaccu.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmaccu_vx_u32m8(acc, op1, op2);
}

vuint64m1_t test_vqmaccu_vv_u64m1 (vuint64m1_t acc, vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmaccu.vv.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmaccu_vv_u64m1(acc, op1, op2);
}

vuint64m1_t test_vqmaccu_vx_u64m1 (vuint64m1_t acc, uint16_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmaccu.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmaccu_vx_u64m1(acc, op1, op2);
}

vuint64m2_t test_vqmaccu_vv_u64m2 (vuint64m2_t acc, vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmaccu.vv.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmaccu_vv_u64m2(acc, op1, op2);
}

vuint64m2_t test_vqmaccu_vx_u64m2 (vuint64m2_t acc, uint16_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmaccu.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmaccu_vx_u64m2(acc, op1, op2);
}

vuint64m4_t test_vqmaccu_vv_u64m4 (vuint64m4_t acc, vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmaccu.vv.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmaccu_vv_u64m4(acc, op1, op2);
}

vuint64m4_t test_vqmaccu_vx_u64m4 (vuint64m4_t acc, uint16_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmaccu.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmaccu_vx_u64m4(acc, op1, op2);
}

vuint64m8_t test_vqmaccu_vv_u64m8 (vuint64m8_t acc, vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmaccu.vv.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmaccu_vv_u64m8(acc, op1, op2);
}

vuint64m8_t test_vqmaccu_vx_u64m8 (vuint64m8_t acc, uint16_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmaccu.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmaccu_vx_u64m8(acc, op1, op2);
}

vuint32mf2_t test_vqmaccu_vv_u32mf2_m (vbool64_t mask, vuint32mf2_t acc, vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmaccu.vv.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmaccu_vv_u32mf2_m(mask, acc, op1, op2);
}

vuint32mf2_t test_vqmaccu_vx_u32mf2_m (vbool64_t mask, vuint32mf2_t acc, uint8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmaccu.vx.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmaccu_vx_u32mf2_m(mask, acc, op1, op2);
}

vuint32m1_t test_vqmaccu_vv_u32m1_m (vbool32_t mask, vuint32m1_t acc, vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmaccu.vv.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmaccu_vv_u32m1_m(mask, acc, op1, op2);
}

vuint32m1_t test_vqmaccu_vx_u32m1_m (vbool32_t mask, vuint32m1_t acc, uint8_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmaccu.vx.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmaccu_vx_u32m1_m(mask, acc, op1, op2);
}

vuint32m2_t test_vqmaccu_vv_u32m2_m (vbool16_t mask, vuint32m2_t acc, vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmaccu.vv.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmaccu_vv_u32m2_m(mask, acc, op1, op2);
}

vuint32m2_t test_vqmaccu_vx_u32m2_m (vbool16_t mask, vuint32m2_t acc, uint8_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmaccu.vx.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmaccu_vx_u32m2_m(mask, acc, op1, op2);
}

vuint32m4_t test_vqmaccu_vv_u32m4_m (vbool8_t mask, vuint32m4_t acc, vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmaccu.vv.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmaccu_vv_u32m4_m(mask, acc, op1, op2);
}

vuint32m4_t test_vqmaccu_vx_u32m4_m (vbool8_t mask, vuint32m4_t acc, uint8_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmaccu.vx.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmaccu_vx_u32m4_m(mask, acc, op1, op2);
}

vuint32m8_t test_vqmaccu_vv_u32m8_m (vbool4_t mask, vuint32m8_t acc, vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmaccu.vv.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmaccu_vv_u32m8_m(mask, acc, op1, op2);
}

vuint32m8_t test_vqmaccu_vx_u32m8_m (vbool4_t mask, vuint32m8_t acc, uint8_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmaccu.vx.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmaccu_vx_u32m8_m(mask, acc, op1, op2);
}

vuint64m1_t test_vqmaccu_vv_u64m1_m (vbool64_t mask, vuint64m1_t acc, vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmaccu.vv.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmaccu_vv_u64m1_m(mask, acc, op1, op2);
}

vuint64m1_t test_vqmaccu_vx_u64m1_m (vbool64_t mask, vuint64m1_t acc, uint16_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmaccu.vx.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmaccu_vx_u64m1_m(mask, acc, op1, op2);
}

vuint64m2_t test_vqmaccu_vv_u64m2_m (vbool32_t mask, vuint64m2_t acc, vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmaccu.vv.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmaccu_vv_u64m2_m(mask, acc, op1, op2);
}

vuint64m2_t test_vqmaccu_vx_u64m2_m (vbool32_t mask, vuint64m2_t acc, uint16_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmaccu.vx.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmaccu_vx_u64m2_m(mask, acc, op1, op2);
}

vuint64m4_t test_vqmaccu_vv_u64m4_m (vbool16_t mask, vuint64m4_t acc, vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmaccu.vv.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmaccu_vv_u64m4_m(mask, acc, op1, op2);
}

vuint64m4_t test_vqmaccu_vx_u64m4_m (vbool16_t mask, vuint64m4_t acc, uint16_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmaccu.vx.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmaccu_vx_u64m4_m(mask, acc, op1, op2);
}

vuint64m8_t test_vqmaccu_vv_u64m8_m (vbool8_t mask, vuint64m8_t acc, vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vv_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmaccu.vv.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmaccu_vv_u64m8_m(mask, acc, op1, op2);
}

vuint64m8_t test_vqmaccu_vx_u64m8_m (vbool8_t mask, vuint64m8_t acc, uint16_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vqmaccu_vx_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmaccu.vx.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmaccu_vx_u64m8_m(mask, acc, op1, op2);
}


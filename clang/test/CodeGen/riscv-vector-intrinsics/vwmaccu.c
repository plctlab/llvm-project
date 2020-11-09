// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint16mf4_t test_vwmaccu_vv_u16mf4 (vuint16mf4_t acc, vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwmaccu.vv.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vwmaccu_vv_u16mf4(acc, op1, op2);
}

vuint16mf4_t test_vwmaccu_vx_u16mf4 (vuint16mf4_t acc, uint8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwmaccu.vx.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vwmaccu_vx_u16mf4(acc, op1, op2);
}

vuint16mf2_t test_vwmaccu_vv_u16mf2 (vuint16mf2_t acc, vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwmaccu.vv.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vwmaccu_vv_u16mf2(acc, op1, op2);
}

vuint16mf2_t test_vwmaccu_vx_u16mf2 (vuint16mf2_t acc, uint8_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwmaccu.vx.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vwmaccu_vx_u16mf2(acc, op1, op2);
}

vuint16m1_t test_vwmaccu_vv_u16m1 (vuint16m1_t acc, vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwmaccu.vv.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vwmaccu_vv_u16m1(acc, op1, op2);
}

vuint16m1_t test_vwmaccu_vx_u16m1 (vuint16m1_t acc, uint8_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwmaccu.vx.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vwmaccu_vx_u16m1(acc, op1, op2);
}

vuint16m2_t test_vwmaccu_vv_u16m2 (vuint16m2_t acc, vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwmaccu.vv.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vwmaccu_vv_u16m2(acc, op1, op2);
}

vuint16m2_t test_vwmaccu_vx_u16m2 (vuint16m2_t acc, uint8_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwmaccu.vx.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vwmaccu_vx_u16m2(acc, op1, op2);
}

vuint16m4_t test_vwmaccu_vv_u16m4 (vuint16m4_t acc, vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwmaccu.vv.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vwmaccu_vv_u16m4(acc, op1, op2);
}

vuint16m4_t test_vwmaccu_vx_u16m4 (vuint16m4_t acc, uint8_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwmaccu.vx.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vwmaccu_vx_u16m4(acc, op1, op2);
}

vuint16m8_t test_vwmaccu_vv_u16m8 (vuint16m8_t acc, vuint8m4_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwmaccu.vv.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vwmaccu_vv_u16m8(acc, op1, op2);
}

vuint16m8_t test_vwmaccu_vx_u16m8 (vuint16m8_t acc, uint8_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwmaccu.vx.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vwmaccu_vx_u16m8(acc, op1, op2);
}

vuint32mf2_t test_vwmaccu_vv_u32mf2 (vuint32mf2_t acc, vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwmaccu.vv.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vwmaccu_vv_u32mf2(acc, op1, op2);
}

vuint32mf2_t test_vwmaccu_vx_u32mf2 (vuint32mf2_t acc, uint16_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwmaccu.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vwmaccu_vx_u32mf2(acc, op1, op2);
}

vuint32m1_t test_vwmaccu_vv_u32m1 (vuint32m1_t acc, vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwmaccu.vv.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vwmaccu_vv_u32m1(acc, op1, op2);
}

vuint32m1_t test_vwmaccu_vx_u32m1 (vuint32m1_t acc, uint16_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwmaccu.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vwmaccu_vx_u32m1(acc, op1, op2);
}

vuint32m2_t test_vwmaccu_vv_u32m2 (vuint32m2_t acc, vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwmaccu.vv.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vwmaccu_vv_u32m2(acc, op1, op2);
}

vuint32m2_t test_vwmaccu_vx_u32m2 (vuint32m2_t acc, uint16_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwmaccu.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vwmaccu_vx_u32m2(acc, op1, op2);
}

vuint32m4_t test_vwmaccu_vv_u32m4 (vuint32m4_t acc, vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwmaccu.vv.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vwmaccu_vv_u32m4(acc, op1, op2);
}

vuint32m4_t test_vwmaccu_vx_u32m4 (vuint32m4_t acc, uint16_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwmaccu.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vwmaccu_vx_u32m4(acc, op1, op2);
}

vuint32m8_t test_vwmaccu_vv_u32m8 (vuint32m8_t acc, vuint16m4_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwmaccu.vv.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vwmaccu_vv_u32m8(acc, op1, op2);
}

vuint32m8_t test_vwmaccu_vx_u32m8 (vuint32m8_t acc, uint16_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwmaccu.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vwmaccu_vx_u32m8(acc, op1, op2);
}

vuint64m1_t test_vwmaccu_vv_u64m1 (vuint64m1_t acc, vuint32mf2_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwmaccu.vv.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vwmaccu_vv_u64m1(acc, op1, op2);
}

vuint64m1_t test_vwmaccu_vx_u64m1 (vuint64m1_t acc, uint32_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwmaccu.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vwmaccu_vx_u64m1(acc, op1, op2);
}

vuint64m2_t test_vwmaccu_vv_u64m2 (vuint64m2_t acc, vuint32m1_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwmaccu.vv.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vwmaccu_vv_u64m2(acc, op1, op2);
}

vuint64m2_t test_vwmaccu_vx_u64m2 (vuint64m2_t acc, uint32_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwmaccu.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vwmaccu_vx_u64m2(acc, op1, op2);
}

vuint64m4_t test_vwmaccu_vv_u64m4 (vuint64m4_t acc, vuint32m2_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwmaccu.vv.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vwmaccu_vv_u64m4(acc, op1, op2);
}

vuint64m4_t test_vwmaccu_vx_u64m4 (vuint64m4_t acc, uint32_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwmaccu.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vwmaccu_vx_u64m4(acc, op1, op2);
}

vuint64m8_t test_vwmaccu_vv_u64m8 (vuint64m8_t acc, vuint32m4_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwmaccu.vv.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vwmaccu_vv_u64m8(acc, op1, op2);
}

vuint64m8_t test_vwmaccu_vx_u64m8 (vuint64m8_t acc, uint32_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwmaccu.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vwmaccu_vx_u64m8(acc, op1, op2);
}

vuint16mf4_t test_vwmaccu_vv_u16mf4_m (vbool64_t mask, vuint16mf4_t acc, vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwmaccu.vv.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vwmaccu_vv_u16mf4_m(mask, acc, op1, op2);
}

vuint16mf4_t test_vwmaccu_vx_u16mf4_m (vbool64_t mask, vuint16mf4_t acc, uint8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwmaccu.vx.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vwmaccu_vx_u16mf4_m(mask, acc, op1, op2);
}

vuint16mf2_t test_vwmaccu_vv_u16mf2_m (vbool32_t mask, vuint16mf2_t acc, vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwmaccu.vv.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vwmaccu_vv_u16mf2_m(mask, acc, op1, op2);
}

vuint16mf2_t test_vwmaccu_vx_u16mf2_m (vbool32_t mask, vuint16mf2_t acc, uint8_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwmaccu.vx.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vwmaccu_vx_u16mf2_m(mask, acc, op1, op2);
}

vuint16m1_t test_vwmaccu_vv_u16m1_m (vbool16_t mask, vuint16m1_t acc, vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwmaccu.vv.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vwmaccu_vv_u16m1_m(mask, acc, op1, op2);
}

vuint16m1_t test_vwmaccu_vx_u16m1_m (vbool16_t mask, vuint16m1_t acc, uint8_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwmaccu.vx.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vwmaccu_vx_u16m1_m(mask, acc, op1, op2);
}

vuint16m2_t test_vwmaccu_vv_u16m2_m (vbool8_t mask, vuint16m2_t acc, vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwmaccu.vv.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vwmaccu_vv_u16m2_m(mask, acc, op1, op2);
}

vuint16m2_t test_vwmaccu_vx_u16m2_m (vbool8_t mask, vuint16m2_t acc, uint8_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwmaccu.vx.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vwmaccu_vx_u16m2_m(mask, acc, op1, op2);
}

vuint16m4_t test_vwmaccu_vv_u16m4_m (vbool4_t mask, vuint16m4_t acc, vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwmaccu.vv.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vwmaccu_vv_u16m4_m(mask, acc, op1, op2);
}

vuint16m4_t test_vwmaccu_vx_u16m4_m (vbool4_t mask, vuint16m4_t acc, uint8_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwmaccu.vx.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vwmaccu_vx_u16m4_m(mask, acc, op1, op2);
}

vuint16m8_t test_vwmaccu_vv_u16m8_m (vbool2_t mask, vuint16m8_t acc, vuint8m4_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwmaccu.vv.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vwmaccu_vv_u16m8_m(mask, acc, op1, op2);
}

vuint16m8_t test_vwmaccu_vx_u16m8_m (vbool2_t mask, vuint16m8_t acc, uint8_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwmaccu.vx.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i8 %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vwmaccu_vx_u16m8_m(mask, acc, op1, op2);
}

vuint32mf2_t test_vwmaccu_vv_u32mf2_m (vbool64_t mask, vuint32mf2_t acc, vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwmaccu.vv.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vwmaccu_vv_u32mf2_m(mask, acc, op1, op2);
}

vuint32mf2_t test_vwmaccu_vx_u32mf2_m (vbool64_t mask, vuint32mf2_t acc, uint16_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwmaccu.vx.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vwmaccu_vx_u32mf2_m(mask, acc, op1, op2);
}

vuint32m1_t test_vwmaccu_vv_u32m1_m (vbool32_t mask, vuint32m1_t acc, vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwmaccu.vv.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vwmaccu_vv_u32m1_m(mask, acc, op1, op2);
}

vuint32m1_t test_vwmaccu_vx_u32m1_m (vbool32_t mask, vuint32m1_t acc, uint16_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwmaccu.vx.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vwmaccu_vx_u32m1_m(mask, acc, op1, op2);
}

vuint32m2_t test_vwmaccu_vv_u32m2_m (vbool16_t mask, vuint32m2_t acc, vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwmaccu.vv.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vwmaccu_vv_u32m2_m(mask, acc, op1, op2);
}

vuint32m2_t test_vwmaccu_vx_u32m2_m (vbool16_t mask, vuint32m2_t acc, uint16_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwmaccu.vx.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vwmaccu_vx_u32m2_m(mask, acc, op1, op2);
}

vuint32m4_t test_vwmaccu_vv_u32m4_m (vbool8_t mask, vuint32m4_t acc, vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwmaccu.vv.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vwmaccu_vv_u32m4_m(mask, acc, op1, op2);
}

vuint32m4_t test_vwmaccu_vx_u32m4_m (vbool8_t mask, vuint32m4_t acc, uint16_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwmaccu.vx.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vwmaccu_vx_u32m4_m(mask, acc, op1, op2);
}

vuint32m8_t test_vwmaccu_vv_u32m8_m (vbool4_t mask, vuint32m8_t acc, vuint16m4_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwmaccu.vv.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vwmaccu_vv_u32m8_m(mask, acc, op1, op2);
}

vuint32m8_t test_vwmaccu_vx_u32m8_m (vbool4_t mask, vuint32m8_t acc, uint16_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwmaccu.vx.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i16 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vwmaccu_vx_u32m8_m(mask, acc, op1, op2);
}

vuint64m1_t test_vwmaccu_vv_u64m1_m (vbool64_t mask, vuint64m1_t acc, vuint32mf2_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwmaccu.vv.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vwmaccu_vv_u64m1_m(mask, acc, op1, op2);
}

vuint64m1_t test_vwmaccu_vx_u64m1_m (vbool64_t mask, vuint64m1_t acc, uint32_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwmaccu.vx.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vwmaccu_vx_u64m1_m(mask, acc, op1, op2);
}

vuint64m2_t test_vwmaccu_vv_u64m2_m (vbool32_t mask, vuint64m2_t acc, vuint32m1_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwmaccu.vv.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vwmaccu_vv_u64m2_m(mask, acc, op1, op2);
}

vuint64m2_t test_vwmaccu_vx_u64m2_m (vbool32_t mask, vuint64m2_t acc, uint32_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwmaccu.vx.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vwmaccu_vx_u64m2_m(mask, acc, op1, op2);
}

vuint64m4_t test_vwmaccu_vv_u64m4_m (vbool16_t mask, vuint64m4_t acc, vuint32m2_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwmaccu.vv.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vwmaccu_vv_u64m4_m(mask, acc, op1, op2);
}

vuint64m4_t test_vwmaccu_vx_u64m4_m (vbool16_t mask, vuint64m4_t acc, uint32_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwmaccu.vx.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vwmaccu_vx_u64m4_m(mask, acc, op1, op2);
}

vuint64m8_t test_vwmaccu_vv_u64m8_m (vbool8_t mask, vuint64m8_t acc, vuint32m4_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vv_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwmaccu.vv.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vwmaccu_vv_u64m8_m(mask, acc, op1, op2);
}

vuint64m8_t test_vwmaccu_vx_u64m8_m (vbool8_t mask, vuint64m8_t acc, uint32_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vwmaccu_vx_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwmaccu.vx.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vwmaccu_vx_u64m8_m(mask, acc, op1, op2);
}


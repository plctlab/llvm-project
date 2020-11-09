// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint8mf8_t test_vasubu_vv_u8mf8 (vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vasubu.vv.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vasubu_vv_u8mf8(op1, op2);
}

vuint8mf8_t test_vasubu_vx_u8mf8 (vuint8mf8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vasubu.vx.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8mf8(op1, op2);
}

vuint8mf4_t test_vasubu_vv_u8mf4 (vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vasubu.vv.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vasubu_vv_u8mf4(op1, op2);
}

vuint8mf4_t test_vasubu_vx_u8mf4 (vuint8mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vasubu.vx.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8mf4(op1, op2);
}

vuint8mf2_t test_vasubu_vv_u8mf2 (vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vasubu.vv.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vasubu_vv_u8mf2(op1, op2);
}

vuint8mf2_t test_vasubu_vx_u8mf2 (vuint8mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vasubu.vx.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8mf2(op1, op2);
}

vuint8m1_t test_vasubu_vv_u8m1 (vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vasubu.vv.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vasubu_vv_u8m1(op1, op2);
}

vuint8m1_t test_vasubu_vx_u8m1 (vuint8m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vasubu.vx.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8m1(op1, op2);
}

vuint8m2_t test_vasubu_vv_u8m2 (vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vasubu.vv.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vasubu_vv_u8m2(op1, op2);
}

vuint8m2_t test_vasubu_vx_u8m2 (vuint8m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vasubu.vx.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8m2(op1, op2);
}

vuint8m4_t test_vasubu_vv_u8m4 (vuint8m4_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vasubu.vv.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vasubu_vv_u8m4(op1, op2);
}

vuint8m4_t test_vasubu_vx_u8m4 (vuint8m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vasubu.vx.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8m4(op1, op2);
}

vuint8m8_t test_vasubu_vv_u8m8 (vuint8m8_t op1, vuint8m8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vasubu.vv.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vasubu_vv_u8m8(op1, op2);
}

vuint8m8_t test_vasubu_vx_u8m8 (vuint8m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vasubu.vx.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8m8(op1, op2);
}

vuint16mf4_t test_vasubu_vv_u16mf4 (vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vasubu.vv.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vasubu_vv_u16mf4(op1, op2);
}

vuint16mf4_t test_vasubu_vx_u16mf4 (vuint16mf4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vasubu.vx.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16mf4(op1, op2);
}

vuint16mf2_t test_vasubu_vv_u16mf2 (vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vasubu.vv.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vasubu_vv_u16mf2(op1, op2);
}

vuint16mf2_t test_vasubu_vx_u16mf2 (vuint16mf2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vasubu.vx.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16mf2(op1, op2);
}

vuint16m1_t test_vasubu_vv_u16m1 (vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vasubu.vv.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vasubu_vv_u16m1(op1, op2);
}

vuint16m1_t test_vasubu_vx_u16m1 (vuint16m1_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vasubu.vx.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16m1(op1, op2);
}

vuint16m2_t test_vasubu_vv_u16m2 (vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vasubu.vv.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vasubu_vv_u16m2(op1, op2);
}

vuint16m2_t test_vasubu_vx_u16m2 (vuint16m2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vasubu.vx.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16m2(op1, op2);
}

vuint16m4_t test_vasubu_vv_u16m4 (vuint16m4_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vasubu.vv.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vasubu_vv_u16m4(op1, op2);
}

vuint16m4_t test_vasubu_vx_u16m4 (vuint16m4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vasubu.vx.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16m4(op1, op2);
}

vuint16m8_t test_vasubu_vv_u16m8 (vuint16m8_t op1, vuint16m8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vasubu.vv.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vasubu_vv_u16m8(op1, op2);
}

vuint16m8_t test_vasubu_vx_u16m8 (vuint16m8_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vasubu.vx.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16m8(op1, op2);
}

vuint32mf2_t test_vasubu_vv_u32mf2 (vuint32mf2_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vasubu.vv.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vasubu_vv_u32mf2(op1, op2);
}

vuint32mf2_t test_vasubu_vx_u32mf2 (vuint32mf2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vasubu.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32mf2(op1, op2);
}

vuint32m1_t test_vasubu_vv_u32m1 (vuint32m1_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vasubu.vv.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vasubu_vv_u32m1(op1, op2);
}

vuint32m1_t test_vasubu_vx_u32m1 (vuint32m1_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vasubu.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32m1(op1, op2);
}

vuint32m2_t test_vasubu_vv_u32m2 (vuint32m2_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vasubu.vv.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vasubu_vv_u32m2(op1, op2);
}

vuint32m2_t test_vasubu_vx_u32m2 (vuint32m2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vasubu.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32m2(op1, op2);
}

vuint32m4_t test_vasubu_vv_u32m4 (vuint32m4_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vasubu.vv.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vasubu_vv_u32m4(op1, op2);
}

vuint32m4_t test_vasubu_vx_u32m4 (vuint32m4_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vasubu.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32m4(op1, op2);
}

vuint32m8_t test_vasubu_vv_u32m8 (vuint32m8_t op1, vuint32m8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vasubu.vv.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vasubu_vv_u32m8(op1, op2);
}

vuint32m8_t test_vasubu_vx_u32m8 (vuint32m8_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vasubu.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32m8(op1, op2);
}

vuint64m1_t test_vasubu_vv_u64m1 (vuint64m1_t op1, vuint64m1_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vasubu.vv.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vasubu_vv_u64m1(op1, op2);
}

vuint64m1_t test_vasubu_vx_u64m1 (vuint64m1_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vasubu.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vasubu_vx_u64m1(op1, op2);
}

vuint64m2_t test_vasubu_vv_u64m2 (vuint64m2_t op1, vuint64m2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vasubu.vv.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vasubu_vv_u64m2(op1, op2);
}

vuint64m2_t test_vasubu_vx_u64m2 (vuint64m2_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vasubu.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vasubu_vx_u64m2(op1, op2);
}

vuint64m4_t test_vasubu_vv_u64m4 (vuint64m4_t op1, vuint64m4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vasubu.vv.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vasubu_vv_u64m4(op1, op2);
}

vuint64m4_t test_vasubu_vx_u64m4 (vuint64m4_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vasubu.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vasubu_vx_u64m4(op1, op2);
}

vuint64m8_t test_vasubu_vv_u64m8 (vuint64m8_t op1, vuint64m8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vasubu.vv.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vasubu_vv_u64m8(op1, op2);
}

vuint64m8_t test_vasubu_vx_u64m8 (vuint64m8_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vasubu.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vasubu_vx_u64m8(op1, op2);
}

vuint8mf8_t test_vasubu_vv_u8mf8_m (vbool64_t mask, vuint8mf8_t maskedoff, vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vasubu.vv.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vasubu_vv_u8mf8_m(mask, maskedoff, op1, op2);
}

vuint8mf8_t test_vasubu_vx_u8mf8_m (vbool64_t mask, vuint8mf8_t maskedoff, vuint8mf8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vasubu.vx.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8mf8_m(mask, maskedoff, op1, op2);
}

vuint8mf4_t test_vasubu_vv_u8mf4_m (vbool32_t mask, vuint8mf4_t maskedoff, vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vasubu.vv.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vasubu_vv_u8mf4_m(mask, maskedoff, op1, op2);
}

vuint8mf4_t test_vasubu_vx_u8mf4_m (vbool32_t mask, vuint8mf4_t maskedoff, vuint8mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vasubu.vx.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8mf4_m(mask, maskedoff, op1, op2);
}

vuint8mf2_t test_vasubu_vv_u8mf2_m (vbool16_t mask, vuint8mf2_t maskedoff, vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vasubu.vv.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vasubu_vv_u8mf2_m(mask, maskedoff, op1, op2);
}

vuint8mf2_t test_vasubu_vx_u8mf2_m (vbool16_t mask, vuint8mf2_t maskedoff, vuint8mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vasubu.vx.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8mf2_m(mask, maskedoff, op1, op2);
}

vuint8m1_t test_vasubu_vv_u8m1_m (vbool8_t mask, vuint8m1_t maskedoff, vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vasubu.vv.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vasubu_vv_u8m1_m(mask, maskedoff, op1, op2);
}

vuint8m1_t test_vasubu_vx_u8m1_m (vbool8_t mask, vuint8m1_t maskedoff, vuint8m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vasubu.vx.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8m1_m(mask, maskedoff, op1, op2);
}

vuint8m2_t test_vasubu_vv_u8m2_m (vbool4_t mask, vuint8m2_t maskedoff, vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vasubu.vv.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vasubu_vv_u8m2_m(mask, maskedoff, op1, op2);
}

vuint8m2_t test_vasubu_vx_u8m2_m (vbool4_t mask, vuint8m2_t maskedoff, vuint8m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vasubu.vx.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8m2_m(mask, maskedoff, op1, op2);
}

vuint8m4_t test_vasubu_vv_u8m4_m (vbool2_t mask, vuint8m4_t maskedoff, vuint8m4_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vasubu.vv.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vasubu_vv_u8m4_m(mask, maskedoff, op1, op2);
}

vuint8m4_t test_vasubu_vx_u8m4_m (vbool2_t mask, vuint8m4_t maskedoff, vuint8m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vasubu.vx.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8m4_m(mask, maskedoff, op1, op2);
}

vuint8m8_t test_vasubu_vv_u8m8_m (vbool1_t mask, vuint8m8_t maskedoff, vuint8m8_t op1, vuint8m8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u8m8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vasubu.vv.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vasubu_vv_u8m8_m(mask, maskedoff, op1, op2);
}

vuint8m8_t test_vasubu_vx_u8m8_m (vbool1_t mask, vuint8m8_t maskedoff, vuint8m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u8m8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vasubu.vx.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vasubu_vx_u8m8_m(mask, maskedoff, op1, op2);
}

vuint16mf4_t test_vasubu_vv_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vasubu.vv.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vasubu_vv_u16mf4_m(mask, maskedoff, op1, op2);
}

vuint16mf4_t test_vasubu_vx_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, vuint16mf4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vasubu.vx.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16mf4_m(mask, maskedoff, op1, op2);
}

vuint16mf2_t test_vasubu_vv_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vasubu.vv.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vasubu_vv_u16mf2_m(mask, maskedoff, op1, op2);
}

vuint16mf2_t test_vasubu_vx_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, vuint16mf2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vasubu.vx.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16mf2_m(mask, maskedoff, op1, op2);
}

vuint16m1_t test_vasubu_vv_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vasubu.vv.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vasubu_vv_u16m1_m(mask, maskedoff, op1, op2);
}

vuint16m1_t test_vasubu_vx_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, vuint16m1_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vasubu.vx.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16m1_m(mask, maskedoff, op1, op2);
}

vuint16m2_t test_vasubu_vv_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vasubu.vv.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vasubu_vv_u16m2_m(mask, maskedoff, op1, op2);
}

vuint16m2_t test_vasubu_vx_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, vuint16m2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vasubu.vx.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16m2_m(mask, maskedoff, op1, op2);
}

vuint16m4_t test_vasubu_vv_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, vuint16m4_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vasubu.vv.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vasubu_vv_u16m4_m(mask, maskedoff, op1, op2);
}

vuint16m4_t test_vasubu_vx_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, vuint16m4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vasubu.vx.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16m4_m(mask, maskedoff, op1, op2);
}

vuint16m8_t test_vasubu_vv_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff, vuint16m8_t op1, vuint16m8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vasubu.vv.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vasubu_vv_u16m8_m(mask, maskedoff, op1, op2);
}

vuint16m8_t test_vasubu_vx_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff, vuint16m8_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vasubu.vx.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vasubu_vx_u16m8_m(mask, maskedoff, op1, op2);
}

vuint32mf2_t test_vasubu_vv_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, vuint32mf2_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vasubu.vv.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vasubu_vv_u32mf2_m(mask, maskedoff, op1, op2);
}

vuint32mf2_t test_vasubu_vx_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, vuint32mf2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vasubu.vx.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32mf2_m(mask, maskedoff, op1, op2);
}

vuint32m1_t test_vasubu_vv_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, vuint32m1_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vasubu.vv.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vasubu_vv_u32m1_m(mask, maskedoff, op1, op2);
}

vuint32m1_t test_vasubu_vx_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, vuint32m1_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vasubu.vx.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32m1_m(mask, maskedoff, op1, op2);
}

vuint32m2_t test_vasubu_vv_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, vuint32m2_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vasubu.vv.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vasubu_vv_u32m2_m(mask, maskedoff, op1, op2);
}

vuint32m2_t test_vasubu_vx_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, vuint32m2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vasubu.vx.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32m2_m(mask, maskedoff, op1, op2);
}

vuint32m4_t test_vasubu_vv_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, vuint32m4_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vasubu.vv.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vasubu_vv_u32m4_m(mask, maskedoff, op1, op2);
}

vuint32m4_t test_vasubu_vx_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, vuint32m4_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vasubu.vx.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32m4_m(mask, maskedoff, op1, op2);
}

vuint32m8_t test_vasubu_vv_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, vuint32m8_t op1, vuint32m8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vasubu.vv.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vasubu_vv_u32m8_m(mask, maskedoff, op1, op2);
}

vuint32m8_t test_vasubu_vx_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, vuint32m8_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vasubu.vx.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vasubu_vx_u32m8_m(mask, maskedoff, op1, op2);
}

vuint64m1_t test_vasubu_vv_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t op1, vuint64m1_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vasubu.vv.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vasubu_vv_u64m1_m(mask, maskedoff, op1, op2);
}

vuint64m1_t test_vasubu_vx_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vasubu.vx.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vasubu_vx_u64m1_m(mask, maskedoff, op1, op2);
}

vuint64m2_t test_vasubu_vv_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t op1, vuint64m2_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vasubu.vv.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vasubu_vv_u64m2_m(mask, maskedoff, op1, op2);
}

vuint64m2_t test_vasubu_vx_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vasubu.vx.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vasubu_vx_u64m2_m(mask, maskedoff, op1, op2);
}

vuint64m4_t test_vasubu_vv_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t op1, vuint64m4_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vasubu.vv.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vasubu_vv_u64m4_m(mask, maskedoff, op1, op2);
}

vuint64m4_t test_vasubu_vx_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vasubu.vx.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vasubu_vx_u64m4_m(mask, maskedoff, op1, op2);
}

vuint64m8_t test_vasubu_vv_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t op1, vuint64m8_t op2) {
  // CHECK-LABEL: test_vasubu_vv_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vasubu.vv.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vasubu_vv_u64m8_m(mask, maskedoff, op1, op2);
}

vuint64m8_t test_vasubu_vx_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vasubu_vx_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vasubu.vx.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vasubu_vx_u64m8_m(mask, maskedoff, op1, op2);
}


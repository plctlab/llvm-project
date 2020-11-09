// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint8mf8_t test_viota_m_u8mf8 (vbool64_t op1) {
  // CHECK-LABEL: test_viota_m_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.viota.{{.*}}(<vscale x 1 x i1> %{{.*}})
  return viota_m_u8mf8(op1);
}

vuint8mf4_t test_viota_m_u8mf4 (vbool32_t op1) {
  // CHECK-LABEL: test_viota_m_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.viota.{{.*}}(<vscale x 2 x i1> %{{.*}})
  return viota_m_u8mf4(op1);
}

vuint8mf2_t test_viota_m_u8mf2 (vbool16_t op1) {
  // CHECK-LABEL: test_viota_m_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.viota.{{.*}}(<vscale x 4 x i1> %{{.*}})
  return viota_m_u8mf2(op1);
}

vuint8m1_t test_viota_m_u8m1 (vbool8_t op1) {
  // CHECK-LABEL: test_viota_m_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.viota.{{.*}}(<vscale x 8 x i1> %{{.*}})
  return viota_m_u8m1(op1);
}

vuint8m2_t test_viota_m_u8m2 (vbool4_t op1) {
  // CHECK-LABEL: test_viota_m_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.viota.{{.*}}(<vscale x 16 x i1> %{{.*}})
  return viota_m_u8m2(op1);
}

vuint8m4_t test_viota_m_u8m4 (vbool2_t op1) {
  // CHECK-LABEL: test_viota_m_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.viota.{{.*}}(<vscale x 32 x i1> %{{.*}})
  return viota_m_u8m4(op1);
}

vuint8m8_t test_viota_m_u8m8 (vbool1_t op1) {
  // CHECK-LABEL: test_viota_m_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.viota.{{.*}}(<vscale x 64 x i1> %{{.*}})
  return viota_m_u8m8(op1);
}

vuint16mf4_t test_viota_m_u16mf4 (vbool64_t op1) {
  // CHECK-LABEL: test_viota_m_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.viota.{{.*}}(<vscale x 1 x i1> %{{.*}})
  return viota_m_u16mf4(op1);
}

vuint16mf2_t test_viota_m_u16mf2 (vbool32_t op1) {
  // CHECK-LABEL: test_viota_m_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.viota.{{.*}}(<vscale x 2 x i1> %{{.*}})
  return viota_m_u16mf2(op1);
}

vuint16m1_t test_viota_m_u16m1 (vbool16_t op1) {
  // CHECK-LABEL: test_viota_m_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.viota.{{.*}}(<vscale x 4 x i1> %{{.*}})
  return viota_m_u16m1(op1);
}

vuint16m2_t test_viota_m_u16m2 (vbool8_t op1) {
  // CHECK-LABEL: test_viota_m_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.viota.{{.*}}(<vscale x 8 x i1> %{{.*}})
  return viota_m_u16m2(op1);
}

vuint16m4_t test_viota_m_u16m4 (vbool4_t op1) {
  // CHECK-LABEL: test_viota_m_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.viota.{{.*}}(<vscale x 16 x i1> %{{.*}})
  return viota_m_u16m4(op1);
}

vuint16m8_t test_viota_m_u16m8 (vbool2_t op1) {
  // CHECK-LABEL: test_viota_m_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.viota.{{.*}}(<vscale x 32 x i1> %{{.*}})
  return viota_m_u16m8(op1);
}

vuint32mf2_t test_viota_m_u32mf2 (vbool64_t op1) {
  // CHECK-LABEL: test_viota_m_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.viota.{{.*}}(<vscale x 1 x i1> %{{.*}})
  return viota_m_u32mf2(op1);
}

vuint32m1_t test_viota_m_u32m1 (vbool32_t op1) {
  // CHECK-LABEL: test_viota_m_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.viota.{{.*}}(<vscale x 2 x i1> %{{.*}})
  return viota_m_u32m1(op1);
}

vuint32m2_t test_viota_m_u32m2 (vbool16_t op1) {
  // CHECK-LABEL: test_viota_m_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.viota.{{.*}}(<vscale x 4 x i1> %{{.*}})
  return viota_m_u32m2(op1);
}

vuint32m4_t test_viota_m_u32m4 (vbool8_t op1) {
  // CHECK-LABEL: test_viota_m_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.viota.{{.*}}(<vscale x 8 x i1> %{{.*}})
  return viota_m_u32m4(op1);
}

vuint32m8_t test_viota_m_u32m8 (vbool4_t op1) {
  // CHECK-LABEL: test_viota_m_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.viota.{{.*}}(<vscale x 16 x i1> %{{.*}})
  return viota_m_u32m8(op1);
}

vuint64m1_t test_viota_m_u64m1 (vbool64_t op1) {
  // CHECK-LABEL: test_viota_m_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.viota.{{.*}}(<vscale x 1 x i1> %{{.*}})
  return viota_m_u64m1(op1);
}

vuint64m2_t test_viota_m_u64m2 (vbool32_t op1) {
  // CHECK-LABEL: test_viota_m_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.viota.{{.*}}(<vscale x 2 x i1> %{{.*}})
  return viota_m_u64m2(op1);
}

vuint64m4_t test_viota_m_u64m4 (vbool16_t op1) {
  // CHECK-LABEL: test_viota_m_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.viota.{{.*}}(<vscale x 4 x i1> %{{.*}})
  return viota_m_u64m4(op1);
}

vuint64m8_t test_viota_m_u64m8 (vbool8_t op1) {
  // CHECK-LABEL: test_viota_m_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.viota.{{.*}}(<vscale x 8 x i1> %{{.*}})
  return viota_m_u64m8(op1);
}

vuint8mf8_t test_viota_m_u8mf8_m (vbool64_t mask, vuint8mf8_t maskedoff, vbool64_t op1) {
  // CHECK-LABEL: test_viota_m_u8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.viota.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return viota_m_u8mf8_m(mask, maskedoff, op1);
}

vuint8mf4_t test_viota_m_u8mf4_m (vbool32_t mask, vuint8mf4_t maskedoff, vbool32_t op1) {
  // CHECK-LABEL: test_viota_m_u8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.viota.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return viota_m_u8mf4_m(mask, maskedoff, op1);
}

vuint8mf2_t test_viota_m_u8mf2_m (vbool16_t mask, vuint8mf2_t maskedoff, vbool16_t op1) {
  // CHECK-LABEL: test_viota_m_u8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.viota.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return viota_m_u8mf2_m(mask, maskedoff, op1);
}

vuint8m1_t test_viota_m_u8m1_m (vbool8_t mask, vuint8m1_t maskedoff, vbool8_t op1) {
  // CHECK-LABEL: test_viota_m_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.viota.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return viota_m_u8m1_m(mask, maskedoff, op1);
}

vuint8m2_t test_viota_m_u8m2_m (vbool4_t mask, vuint8m2_t maskedoff, vbool4_t op1) {
  // CHECK-LABEL: test_viota_m_u8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.viota.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return viota_m_u8m2_m(mask, maskedoff, op1);
}

vuint8m4_t test_viota_m_u8m4_m (vbool2_t mask, vuint8m4_t maskedoff, vbool2_t op1) {
  // CHECK-LABEL: test_viota_m_u8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.viota.mask.{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return viota_m_u8m4_m(mask, maskedoff, op1);
}

vuint8m8_t test_viota_m_u8m8_m (vbool1_t mask, vuint8m8_t maskedoff, vbool1_t op1) {
  // CHECK-LABEL: test_viota_m_u8m8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.viota.mask.{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return viota_m_u8m8_m(mask, maskedoff, op1);
}

vuint16mf4_t test_viota_m_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, vbool64_t op1) {
  // CHECK-LABEL: test_viota_m_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.viota.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return viota_m_u16mf4_m(mask, maskedoff, op1);
}

vuint16mf2_t test_viota_m_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, vbool32_t op1) {
  // CHECK-LABEL: test_viota_m_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.viota.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return viota_m_u16mf2_m(mask, maskedoff, op1);
}

vuint16m1_t test_viota_m_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, vbool16_t op1) {
  // CHECK-LABEL: test_viota_m_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.viota.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return viota_m_u16m1_m(mask, maskedoff, op1);
}

vuint16m2_t test_viota_m_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, vbool8_t op1) {
  // CHECK-LABEL: test_viota_m_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.viota.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return viota_m_u16m2_m(mask, maskedoff, op1);
}

vuint16m4_t test_viota_m_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, vbool4_t op1) {
  // CHECK-LABEL: test_viota_m_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.viota.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return viota_m_u16m4_m(mask, maskedoff, op1);
}

vuint16m8_t test_viota_m_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff, vbool2_t op1) {
  // CHECK-LABEL: test_viota_m_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.viota.mask.{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return viota_m_u16m8_m(mask, maskedoff, op1);
}

vuint32mf2_t test_viota_m_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, vbool64_t op1) {
  // CHECK-LABEL: test_viota_m_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.viota.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return viota_m_u32mf2_m(mask, maskedoff, op1);
}

vuint32m1_t test_viota_m_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, vbool32_t op1) {
  // CHECK-LABEL: test_viota_m_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.viota.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return viota_m_u32m1_m(mask, maskedoff, op1);
}

vuint32m2_t test_viota_m_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, vbool16_t op1) {
  // CHECK-LABEL: test_viota_m_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.viota.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return viota_m_u32m2_m(mask, maskedoff, op1);
}

vuint32m4_t test_viota_m_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, vbool8_t op1) {
  // CHECK-LABEL: test_viota_m_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.viota.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return viota_m_u32m4_m(mask, maskedoff, op1);
}

vuint32m8_t test_viota_m_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, vbool4_t op1) {
  // CHECK-LABEL: test_viota_m_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.viota.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return viota_m_u32m8_m(mask, maskedoff, op1);
}

vuint64m1_t test_viota_m_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff, vbool64_t op1) {
  // CHECK-LABEL: test_viota_m_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.viota.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return viota_m_u64m1_m(mask, maskedoff, op1);
}

vuint64m2_t test_viota_m_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff, vbool32_t op1) {
  // CHECK-LABEL: test_viota_m_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.viota.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return viota_m_u64m2_m(mask, maskedoff, op1);
}

vuint64m4_t test_viota_m_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff, vbool16_t op1) {
  // CHECK-LABEL: test_viota_m_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.viota.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return viota_m_u64m4_m(mask, maskedoff, op1);
}

vuint64m8_t test_viota_m_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff, vbool8_t op1) {
  // CHECK-LABEL: test_viota_m_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.viota.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return viota_m_u64m8_m(mask, maskedoff, op1);
}


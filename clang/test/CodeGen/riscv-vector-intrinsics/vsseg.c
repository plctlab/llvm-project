// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsseg2e8_v_i8mf8x2 (int8_t *base, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8mf8x2
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf8x4 (int8_t *base, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf8x4
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf8x5 (int8_t *base, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf8x5
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_i8mf8x6 (int8_t *base, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_i8mf8x6
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_i8mf8x7 (int8_t *base, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_i8mf8x7
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_i8mf8x8 (int8_t *base, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_i8mf8x8
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8mf4x2 (int8_t *base, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8mf4x2
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_i8mf4x3 (int8_t *base, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_i8mf4x3
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf4x4 (int8_t *base, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf4x4
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf4x5 (int8_t *base, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_i8mf4x6 (int8_t *base, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_i8mf4x6
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_i8mf4x7 (int8_t *base, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_i8mf4x7
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_i8mf4x8 (int8_t *base, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_i8mf4x8
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8mf2x2 (int8_t *base, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8mf2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_i8mf2x3 (int8_t *base, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_i8mf2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf2x4 (int8_t *base, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf2x5 (int8_t *base, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_i8mf2x6 (int8_t *base, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_i8mf2x6
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_i8mf2x7 (int8_t *base, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_i8mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_i8mf2x8 (int8_t *base, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_i8mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8m1x2 (int8_t *base, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8m1x2
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_i8m1x3 (int8_t *base, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_i8m1x3
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8m1x4 (int8_t *base, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8m1x5 (int8_t *base, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_i8m1x6 (int8_t *base, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_i8m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_i8m1x7 (int8_t *base, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_i8m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_i8m1x8 (int8_t *base, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_i8m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8m2x2 (int8_t *base, vint8m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8m2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_i8m2x3 (int8_t *base, vint8m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_i8m2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8m2x4 (int8_t *base, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8m2x4
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8m4x2 (int8_t *base, vint8m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8m4x2
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16mf4x2 (int16_t *base, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16mf4x2
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_i16mf4x4 (int16_t *base, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_i16mf4x4
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16mf4x5 (int16_t *base, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_i16mf4x6 (int16_t *base, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_i16mf4x6
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16mf4x7 (int16_t *base, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16mf4x7
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16mf4x8 (int16_t *base, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16mf4x8
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16mf2x2 (int16_t *base, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16mf2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_i16mf2x3 (int16_t *base, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_i16mf2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_i16mf2x4 (int16_t *base, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_i16mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16mf2x5 (int16_t *base, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_i16mf2x6 (int16_t *base, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_i16mf2x6
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16mf2x7 (int16_t *base, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16mf2x8 (int16_t *base, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16m1x2 (int16_t *base, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16m1x2
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_i16m1x3 (int16_t *base, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_i16m1x3
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_i16m1x4 (int16_t *base, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_i16m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16m1x5 (int16_t *base, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_i16m1x6 (int16_t *base, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_i16m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16m1x7 (int16_t *base, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16m1x8 (int16_t *base, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16m2x2 (int16_t *base, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16m2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_i16m2x3 (int16_t *base, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_i16m2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_i16m2x4 (int16_t *base, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_i16m2x4
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16m4x2 (int16_t *base, vint16m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16m4x2
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_i32mf2x2 (int32_t *base, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_i32mf2x2
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_i32mf2x4 (int32_t *base, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_i32mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_i32mf2x5 (int32_t *base, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_i32mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_i32mf2x6 (int32_t *base, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_i32mf2x6
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_i32mf2x7 (int32_t *base, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_i32mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_i32mf2x8 (int32_t *base, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_i32mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_i32m1x2 (int32_t *base, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_i32m1x2
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_i32m1x3 (int32_t *base, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_i32m1x3
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_i32m1x4 (int32_t *base, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_i32m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_i32m1x5 (int32_t *base, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_i32m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_i32m1x6 (int32_t *base, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_i32m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_i32m1x7 (int32_t *base, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_i32m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_i32m1x8 (int32_t *base, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_i32m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_i32m2x2 (int32_t *base, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_i32m2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_i32m2x3 (int32_t *base, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_i32m2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_i32m2x4 (int32_t *base, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_i32m2x4
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_i32m4x2 (int32_t *base, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_i32m4x2
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_i64m1x2 (int64_t *base, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_i64m1x2
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_i64m1x4 (int64_t *base, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_i64m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e64_v_i64m1x5 (int64_t *base, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e64_v_i64m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_i64m1x6 (int64_t *base, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_i64m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e64_v_i64m1x7 (int64_t *base, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e64_v_i64m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e64_v_i64m1x8 (int64_t *base, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e64_v_i64m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_i64m2x2 (int64_t *base, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_i64m2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e64_v_i64m2x3 (int64_t *base, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e64_v_i64m2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_i64m2x4 (int64_t *base, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_i64m2x4
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_i64m4x2 (int64_t *base, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_i64m4x2
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8mf8x2 (uint8_t *base, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8mf8x2
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf8x4 (uint8_t *base, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf8x4
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf8x5 (uint8_t *base, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf8x5
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_u8mf8x6 (uint8_t *base, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_u8mf8x6
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_u8mf8x7 (uint8_t *base, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_u8mf8x7
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_u8mf8x8 (uint8_t *base, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_u8mf8x8
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8mf4x2 (uint8_t *base, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8mf4x2
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_u8mf4x3 (uint8_t *base, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_u8mf4x3
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf4x4 (uint8_t *base, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf4x4
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf4x5 (uint8_t *base, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_u8mf4x6 (uint8_t *base, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_u8mf4x6
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_u8mf4x7 (uint8_t *base, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_u8mf4x7
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_u8mf4x8 (uint8_t *base, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_u8mf4x8
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8mf2x2 (uint8_t *base, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8mf2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_u8mf2x3 (uint8_t *base, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_u8mf2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf2x4 (uint8_t *base, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf2x5 (uint8_t *base, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_u8mf2x6 (uint8_t *base, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_u8mf2x6
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_u8mf2x7 (uint8_t *base, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_u8mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_u8mf2x8 (uint8_t *base, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_u8mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8m1x2 (uint8_t *base, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8m1x2
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_u8m1x3 (uint8_t *base, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_u8m1x3
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8m1x4 (uint8_t *base, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8m1x5 (uint8_t *base, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_u8m1x6 (uint8_t *base, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_u8m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_u8m1x7 (uint8_t *base, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_u8m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_u8m1x8 (uint8_t *base, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_u8m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8m2x2 (uint8_t *base, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8m2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_u8m2x3 (uint8_t *base, vuint8m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_u8m2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8m2x4 (uint8_t *base, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8m2x4
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8m4x2 (uint8_t *base, vuint8m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8m4x2
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16mf4x2 (uint16_t *base, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16mf4x2
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_u16mf4x4 (uint16_t *base, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_u16mf4x4
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16mf4x5 (uint16_t *base, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_u16mf4x6 (uint16_t *base, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_u16mf4x6
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16mf4x7 (uint16_t *base, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16mf4x7
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16mf4x8 (uint16_t *base, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16mf4x8
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16mf2x2 (uint16_t *base, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16mf2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_u16mf2x3 (uint16_t *base, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_u16mf2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_u16mf2x4 (uint16_t *base, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_u16mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16mf2x5 (uint16_t *base, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_u16mf2x6 (uint16_t *base, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_u16mf2x6
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16mf2x7 (uint16_t *base, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16mf2x8 (uint16_t *base, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16m1x2 (uint16_t *base, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16m1x2
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_u16m1x3 (uint16_t *base, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_u16m1x3
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_u16m1x4 (uint16_t *base, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_u16m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16m1x5 (uint16_t *base, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_u16m1x6 (uint16_t *base, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_u16m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16m1x7 (uint16_t *base, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16m1x8 (uint16_t *base, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16m2x2 (uint16_t *base, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16m2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_u16m2x3 (uint16_t *base, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_u16m2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_u16m2x4 (uint16_t *base, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_u16m2x4
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16m4x2 (uint16_t *base, vuint16m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16m4x2
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_u32mf2x2 (uint32_t *base, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_u32mf2x2
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_u32mf2x4 (uint32_t *base, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_u32mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_u32mf2x5 (uint32_t *base, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_u32mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_u32mf2x6 (uint32_t *base, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_u32mf2x6
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_u32mf2x7 (uint32_t *base, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_u32mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_u32mf2x8 (uint32_t *base, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_u32mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_u32m1x2 (uint32_t *base, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_u32m1x2
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_u32m1x3 (uint32_t *base, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_u32m1x3
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_u32m1x4 (uint32_t *base, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_u32m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_u32m1x5 (uint32_t *base, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_u32m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_u32m1x6 (uint32_t *base, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_u32m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_u32m1x7 (uint32_t *base, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_u32m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_u32m1x8 (uint32_t *base, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_u32m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_u32m2x2 (uint32_t *base, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_u32m2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_u32m2x3 (uint32_t *base, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_u32m2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_u32m2x4 (uint32_t *base, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_u32m2x4
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_u32m4x2 (uint32_t *base, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_u32m4x2
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_u64m1x2 (uint64_t *base, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_u64m1x2
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_u64m1x4 (uint64_t *base, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_u64m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e64_v_u64m1x5 (uint64_t *base, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e64_v_u64m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_u64m1x6 (uint64_t *base, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_u64m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e64_v_u64m1x7 (uint64_t *base, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e64_v_u64m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e64_v_u64m1x8 (uint64_t *base, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e64_v_u64m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_u64m2x2 (uint64_t *base, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_u64m2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e64_v_u64m2x3 (uint64_t *base, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e64_v_u64m2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_u64m2x4 (uint64_t *base, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_u64m2x4
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_u64m4x2 (uint64_t *base, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_u64m4x2
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_f16mf4x2 (float16_t *base, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_f16mf4x2
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_f16mf4x4 (float16_t *base, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_f16mf4x4
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16mf4x5 (float16_t *base, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_f16mf4x6 (float16_t *base, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_f16mf4x6
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16mf4x7 (float16_t *base, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16mf4x7
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16mf4x8 (float16_t *base, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16mf4x8
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_f16mf2x2 (float16_t *base, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_f16mf2x2
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_f16mf2x3 (float16_t *base, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_f16mf2x3
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_f16mf2x4 (float16_t *base, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_f16mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16mf2x5 (float16_t *base, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_f16mf2x6 (float16_t *base, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_f16mf2x6
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16mf2x7 (float16_t *base, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16mf2x8 (float16_t *base, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_f16m1x2 (float16_t *base, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_f16m1x2
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_f16m1x3 (float16_t *base, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_f16m1x3
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_f16m1x4 (float16_t *base, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_f16m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16m1x5 (float16_t *base, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_f16m1x6 (float16_t *base, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_f16m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16m1x7 (float16_t *base, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16m1x8 (float16_t *base, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_f32mf2x2 (float32_t *base, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_f32mf2x2
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_f32mf2x4 (float32_t *base, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_f32mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_f32mf2x5 (float32_t *base, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_f32mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_f32mf2x6 (float32_t *base, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_f32mf2x6
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_f32mf2x7 (float32_t *base, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_f32mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_f32mf2x8 (float32_t *base, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_f32mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_f32m1x2 (float32_t *base, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_f32m1x2
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_f32m1x3 (float32_t *base, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_f32m1x3
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_f32m1x4 (float32_t *base, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_f32m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_f32m1x5 (float32_t *base, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_f32m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_f32m1x6 (float32_t *base, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_f32m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_f32m1x7 (float32_t *base, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_f32m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_f32m1x8 (float32_t *base, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_f32m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_f64m1x2 (float64_t *base, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_f64m1x2
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_f64m1x4 (float64_t *base, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_f64m1x4
  // CHECK: ret void
  return;
}

void test_vsseg5e64_v_f64m1x5 (float64_t *base, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e64_v_f64m1x5
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_f64m1x6 (float64_t *base, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_f64m1x6
  // CHECK: ret void
  return;
}

void test_vsseg7e64_v_f64m1x7 (float64_t *base, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e64_v_f64m1x7
  // CHECK: ret void
  return;
}

void test_vsseg8e64_v_f64m1x8 (float64_t *base, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e64_v_f64m1x8
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8mf8x2_m (vbool64_t mask, int8_t *base, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf8x4_m (vbool64_t mask, int8_t *base, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf8x5_m (vbool64_t mask, int8_t *base, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_i8mf8x6_m (vbool64_t mask, int8_t *base, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_i8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_i8mf8x7_m (vbool64_t mask, int8_t *base, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_i8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_i8mf8x8_m (vbool64_t mask, int8_t *base, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_i8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8mf4x2_m (vbool32_t mask, int8_t *base, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_i8mf4x3_m (vbool32_t mask, int8_t *base, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_i8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf4x4_m (vbool32_t mask, int8_t *base, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf4x5_m (vbool32_t mask, int8_t *base, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_i8mf4x6_m (vbool32_t mask, int8_t *base, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_i8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_i8mf4x7_m (vbool32_t mask, int8_t *base, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_i8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_i8mf4x8_m (vbool32_t mask, int8_t *base, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_i8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8mf2x2_m (vbool16_t mask, int8_t *base, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_i8mf2x3_m (vbool16_t mask, int8_t *base, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_i8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf2x4_m (vbool16_t mask, int8_t *base, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf2x5_m (vbool16_t mask, int8_t *base, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_i8mf2x6_m (vbool16_t mask, int8_t *base, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_i8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_i8mf2x7_m (vbool16_t mask, int8_t *base, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_i8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_i8mf2x8_m (vbool16_t mask, int8_t *base, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_i8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8m1x2_m (vbool8_t mask, int8_t *base, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_i8m1x3_m (vbool8_t mask, int8_t *base, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_i8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8m1x4_m (vbool8_t mask, int8_t *base, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8m1x5_m (vbool8_t mask, int8_t *base, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_i8m1x6_m (vbool8_t mask, int8_t *base, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_i8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_i8m1x7_m (vbool8_t mask, int8_t *base, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_i8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_i8m1x8_m (vbool8_t mask, int8_t *base, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_i8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8m2x2_m (vbool4_t mask, int8_t *base, vint8m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8m2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_i8m2x3_m (vbool4_t mask, int8_t *base, vint8m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_i8m2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8m2x4_m (vbool4_t mask, int8_t *base, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8m2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_i8m4x2_m (vbool2_t mask, int8_t *base, vint8m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_i8m4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16mf4x2_m (vbool64_t mask, int16_t *base, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_i16mf4x4_m (vbool64_t mask, int16_t *base, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_i16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16mf4x5_m (vbool64_t mask, int16_t *base, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_i16mf4x6_m (vbool64_t mask, int16_t *base, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_i16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16mf4x7_m (vbool64_t mask, int16_t *base, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16mf4x8_m (vbool64_t mask, int16_t *base, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16mf2x2_m (vbool32_t mask, int16_t *base, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_i16mf2x3_m (vbool32_t mask, int16_t *base, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_i16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_i16mf2x4_m (vbool32_t mask, int16_t *base, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_i16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16mf2x5_m (vbool32_t mask, int16_t *base, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_i16mf2x6_m (vbool32_t mask, int16_t *base, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_i16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16mf2x7_m (vbool32_t mask, int16_t *base, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16mf2x8_m (vbool32_t mask, int16_t *base, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16m1x2_m (vbool16_t mask, int16_t *base, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_i16m1x3_m (vbool16_t mask, int16_t *base, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_i16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_i16m1x4_m (vbool16_t mask, int16_t *base, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_i16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16m1x5_m (vbool16_t mask, int16_t *base, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_i16m1x6_m (vbool16_t mask, int16_t *base, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_i16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16m1x7_m (vbool16_t mask, int16_t *base, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16m1x8_m (vbool16_t mask, int16_t *base, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16m2x2_m (vbool8_t mask, int16_t *base, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_i16m2x3_m (vbool8_t mask, int16_t *base, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_i16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_i16m2x4_m (vbool8_t mask, int16_t *base, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_i16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_i16m4x2_m (vbool4_t mask, int16_t *base, vint16m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_i16m4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_i32mf2x2_m (vbool64_t mask, int32_t *base, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_i32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_i32mf2x4_m (vbool64_t mask, int32_t *base, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_i32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_i32mf2x5_m (vbool64_t mask, int32_t *base, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_i32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_i32mf2x6_m (vbool64_t mask, int32_t *base, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_i32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_i32mf2x7_m (vbool64_t mask, int32_t *base, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_i32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_i32mf2x8_m (vbool64_t mask, int32_t *base, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_i32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_i32m1x2_m (vbool32_t mask, int32_t *base, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_i32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_i32m1x3_m (vbool32_t mask, int32_t *base, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_i32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_i32m1x4_m (vbool32_t mask, int32_t *base, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_i32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_i32m1x5_m (vbool32_t mask, int32_t *base, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_i32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_i32m1x6_m (vbool32_t mask, int32_t *base, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_i32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_i32m1x7_m (vbool32_t mask, int32_t *base, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_i32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_i32m1x8_m (vbool32_t mask, int32_t *base, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_i32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_i32m2x2_m (vbool16_t mask, int32_t *base, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_i32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_i32m2x3_m (vbool16_t mask, int32_t *base, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_i32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_i32m2x4_m (vbool16_t mask, int32_t *base, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_i32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_i32m4x2_m (vbool8_t mask, int32_t *base, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_i32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_i64m1x2_m (vbool64_t mask, int64_t *base, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_i64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_i64m1x4_m (vbool64_t mask, int64_t *base, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_i64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e64_v_i64m1x5_m (vbool64_t mask, int64_t *base, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e64_v_i64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_i64m1x6_m (vbool64_t mask, int64_t *base, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_i64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e64_v_i64m1x7_m (vbool64_t mask, int64_t *base, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e64_v_i64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e64_v_i64m1x8_m (vbool64_t mask, int64_t *base, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e64_v_i64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_i64m2x2_m (vbool32_t mask, int64_t *base, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_i64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e64_v_i64m2x3_m (vbool32_t mask, int64_t *base, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e64_v_i64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_i64m2x4_m (vbool32_t mask, int64_t *base, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_i64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_i64m4x2_m (vbool16_t mask, int64_t *base, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_i64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8mf8x2_m (vbool64_t mask, uint8_t *base, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf8x4_m (vbool64_t mask, uint8_t *base, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf8x5_m (vbool64_t mask, uint8_t *base, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_u8mf8x6_m (vbool64_t mask, uint8_t *base, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_u8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_u8mf8x7_m (vbool64_t mask, uint8_t *base, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_u8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_u8mf8x8_m (vbool64_t mask, uint8_t *base, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_u8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8mf4x2_m (vbool32_t mask, uint8_t *base, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_u8mf4x3_m (vbool32_t mask, uint8_t *base, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_u8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf4x4_m (vbool32_t mask, uint8_t *base, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf4x5_m (vbool32_t mask, uint8_t *base, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_u8mf4x6_m (vbool32_t mask, uint8_t *base, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_u8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_u8mf4x7_m (vbool32_t mask, uint8_t *base, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_u8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_u8mf4x8_m (vbool32_t mask, uint8_t *base, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_u8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8mf2x2_m (vbool16_t mask, uint8_t *base, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_u8mf2x3_m (vbool16_t mask, uint8_t *base, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_u8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf2x4_m (vbool16_t mask, uint8_t *base, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf2x5_m (vbool16_t mask, uint8_t *base, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_u8mf2x6_m (vbool16_t mask, uint8_t *base, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_u8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_u8mf2x7_m (vbool16_t mask, uint8_t *base, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_u8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_u8mf2x8_m (vbool16_t mask, uint8_t *base, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_u8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8m1x2_m (vbool8_t mask, uint8_t *base, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_u8m1x3_m (vbool8_t mask, uint8_t *base, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_u8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8m1x4_m (vbool8_t mask, uint8_t *base, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8m1x5_m (vbool8_t mask, uint8_t *base, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e8_v_u8m1x6_m (vbool8_t mask, uint8_t *base, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e8_v_u8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e8_v_u8m1x7_m (vbool8_t mask, uint8_t *base, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e8_v_u8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e8_v_u8m1x8_m (vbool8_t mask, uint8_t *base, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e8_v_u8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8m2x2_m (vbool4_t mask, uint8_t *base, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8m2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e8_v_u8m2x3_m (vbool4_t mask, uint8_t *base, vuint8m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e8_v_u8m2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8m2x4_m (vbool4_t mask, uint8_t *base, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8m2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg2e8_v_u8m4x2_m (vbool2_t mask, uint8_t *base, vuint8m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e8_v_u8m4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16mf4x2_m (vbool64_t mask, uint16_t *base, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_u16mf4x4_m (vbool64_t mask, uint16_t *base, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_u16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16mf4x5_m (vbool64_t mask, uint16_t *base, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_u16mf4x6_m (vbool64_t mask, uint16_t *base, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_u16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16mf4x7_m (vbool64_t mask, uint16_t *base, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16mf4x8_m (vbool64_t mask, uint16_t *base, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16mf2x2_m (vbool32_t mask, uint16_t *base, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_u16mf2x3_m (vbool32_t mask, uint16_t *base, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_u16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_u16mf2x4_m (vbool32_t mask, uint16_t *base, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_u16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16mf2x5_m (vbool32_t mask, uint16_t *base, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_u16mf2x6_m (vbool32_t mask, uint16_t *base, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_u16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16mf2x7_m (vbool32_t mask, uint16_t *base, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16mf2x8_m (vbool32_t mask, uint16_t *base, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16m1x2_m (vbool16_t mask, uint16_t *base, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_u16m1x3_m (vbool16_t mask, uint16_t *base, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_u16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_u16m1x4_m (vbool16_t mask, uint16_t *base, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_u16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16m1x5_m (vbool16_t mask, uint16_t *base, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_u16m1x6_m (vbool16_t mask, uint16_t *base, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_u16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16m1x7_m (vbool16_t mask, uint16_t *base, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16m1x8_m (vbool16_t mask, uint16_t *base, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16m2x2_m (vbool8_t mask, uint16_t *base, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_u16m2x3_m (vbool8_t mask, uint16_t *base, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_u16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_u16m2x4_m (vbool8_t mask, uint16_t *base, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_u16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_u16m4x2_m (vbool4_t mask, uint16_t *base, vuint16m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_u16m4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_u32mf2x2_m (vbool64_t mask, uint32_t *base, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_u32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_u32mf2x4_m (vbool64_t mask, uint32_t *base, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_u32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_u32mf2x5_m (vbool64_t mask, uint32_t *base, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_u32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_u32mf2x6_m (vbool64_t mask, uint32_t *base, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_u32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_u32mf2x7_m (vbool64_t mask, uint32_t *base, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_u32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_u32mf2x8_m (vbool64_t mask, uint32_t *base, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_u32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_u32m1x2_m (vbool32_t mask, uint32_t *base, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_u32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_u32m1x3_m (vbool32_t mask, uint32_t *base, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_u32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_u32m1x4_m (vbool32_t mask, uint32_t *base, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_u32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_u32m1x5_m (vbool32_t mask, uint32_t *base, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_u32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_u32m1x6_m (vbool32_t mask, uint32_t *base, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_u32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_u32m1x7_m (vbool32_t mask, uint32_t *base, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_u32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_u32m1x8_m (vbool32_t mask, uint32_t *base, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_u32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_u32m2x2_m (vbool16_t mask, uint32_t *base, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_u32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_u32m2x3_m (vbool16_t mask, uint32_t *base, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_u32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_u32m2x4_m (vbool16_t mask, uint32_t *base, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_u32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_u32m4x2_m (vbool8_t mask, uint32_t *base, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_u32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_u64m1x2_m (vbool64_t mask, uint64_t *base, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_u64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_u64m1x4_m (vbool64_t mask, uint64_t *base, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_u64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e64_v_u64m1x5_m (vbool64_t mask, uint64_t *base, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e64_v_u64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_u64m1x6_m (vbool64_t mask, uint64_t *base, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_u64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e64_v_u64m1x7_m (vbool64_t mask, uint64_t *base, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e64_v_u64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e64_v_u64m1x8_m (vbool64_t mask, uint64_t *base, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e64_v_u64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_u64m2x2_m (vbool32_t mask, uint64_t *base, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_u64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e64_v_u64m2x3_m (vbool32_t mask, uint64_t *base, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsseg3e64_v_u64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_u64m2x4_m (vbool32_t mask, uint64_t *base, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_u64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_u64m4x2_m (vbool16_t mask, uint64_t *base, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_u64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_f16mf4x2_m (vbool64_t mask, float16_t *base, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_f16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_f16mf4x4_m (vbool64_t mask, float16_t *base, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_f16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16mf4x5_m (vbool64_t mask, float16_t *base, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_f16mf4x6_m (vbool64_t mask, float16_t *base, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_f16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16mf4x7_m (vbool64_t mask, float16_t *base, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16mf4x8_m (vbool64_t mask, float16_t *base, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_f16mf2x2_m (vbool32_t mask, float16_t *base, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_f16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_f16mf2x3_m (vbool32_t mask, float16_t *base, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_f16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_f16mf2x4_m (vbool32_t mask, float16_t *base, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_f16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16mf2x5_m (vbool32_t mask, float16_t *base, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_f16mf2x6_m (vbool32_t mask, float16_t *base, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_f16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16mf2x7_m (vbool32_t mask, float16_t *base, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16mf2x8_m (vbool32_t mask, float16_t *base, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e16_v_f16m1x2_m (vbool16_t mask, float16_t *base, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e16_v_f16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e16_v_f16m1x3_m (vbool16_t mask, float16_t *base, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e16_v_f16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e16_v_f16m1x4_m (vbool16_t mask, float16_t *base, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e16_v_f16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16m1x5_m (vbool16_t mask, float16_t *base, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e16_v_f16m1x6_m (vbool16_t mask, float16_t *base, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e16_v_f16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16m1x7_m (vbool16_t mask, float16_t *base, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16m1x8_m (vbool16_t mask, float16_t *base, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_f32mf2x2_m (vbool64_t mask, float32_t *base, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_f32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_f32mf2x4_m (vbool64_t mask, float32_t *base, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_f32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_f32mf2x5_m (vbool64_t mask, float32_t *base, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_f32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_f32mf2x6_m (vbool64_t mask, float32_t *base, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_f32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_f32mf2x7_m (vbool64_t mask, float32_t *base, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_f32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_f32mf2x8_m (vbool64_t mask, float32_t *base, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_f32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e32_v_f32m1x2_m (vbool32_t mask, float32_t *base, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e32_v_f32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg3e32_v_f32m1x3_m (vbool32_t mask, float32_t *base, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsseg3e32_v_f32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsseg4e32_v_f32m1x4_m (vbool32_t mask, float32_t *base, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e32_v_f32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e32_v_f32m1x5_m (vbool32_t mask, float32_t *base, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e32_v_f32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e32_v_f32m1x6_m (vbool32_t mask, float32_t *base, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e32_v_f32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e32_v_f32m1x7_m (vbool32_t mask, float32_t *base, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e32_v_f32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e32_v_f32m1x8_m (vbool32_t mask, float32_t *base, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e32_v_f32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg2e64_v_f64m1x2_m (vbool64_t mask, float64_t *base, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsseg2e64_v_f64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsseg4e64_v_f64m1x4_m (vbool64_t mask, float64_t *base, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e64_v_f64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg5e64_v_f64m1x5_m (vbool64_t mask, float64_t *base, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e64_v_f64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_f64m1x6_m (vbool64_t mask, float64_t *base, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_f64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg7e64_v_f64m1x7_m (vbool64_t mask, float64_t *base, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e64_v_f64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg8e64_v_f64m1x8_m (vbool64_t mask, float64_t *base, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e64_v_f64m1x8_m
  // CHECK: ret void
  return;
}


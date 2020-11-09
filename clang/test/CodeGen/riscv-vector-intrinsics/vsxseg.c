// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsxseg2ei8_v_i8mf8x2 (int8_t *base, vuint8mf8_t bindex, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8mf8x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8mf8x4 (int8_t *base, vuint8mf8_t bindex, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8mf8x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i8mf8x5 (int8_t *base, vuint8mf8_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i8mf8x6 (int8_t *base, vuint8mf8_t bindex, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i8mf8x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i8mf8x7 (int8_t *base, vuint8mf8_t bindex, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i8mf8x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i8mf8x8 (int8_t *base, vuint8mf8_t bindex, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i8mf8x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8mf4x2 (int8_t *base, vuint8mf4_t bindex, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i8mf4x3 (int8_t *base, vuint8mf4_t bindex, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i8mf4x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8mf4x4 (int8_t *base, vuint8mf4_t bindex, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i8mf4x5 (int8_t *base, vuint8mf4_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i8mf4x6 (int8_t *base, vuint8mf4_t bindex, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i8mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i8mf4x7 (int8_t *base, vuint8mf4_t bindex, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i8mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i8mf4x8 (int8_t *base, vuint8mf4_t bindex, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i8mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8mf2x2 (int8_t *base, vuint8mf2_t bindex, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i8mf2x3 (int8_t *base, vuint8mf2_t bindex, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i8mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8mf2x4 (int8_t *base, vuint8mf2_t bindex, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i8mf2x5 (int8_t *base, vuint8mf2_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i8mf2x6 (int8_t *base, vuint8mf2_t bindex, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i8mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i8mf2x7 (int8_t *base, vuint8mf2_t bindex, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i8mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i8mf2x8 (int8_t *base, vuint8mf2_t bindex, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i8mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8m1x2 (int8_t *base, vuint8m1_t bindex, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i8m1x3 (int8_t *base, vuint8m1_t bindex, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i8m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8m1x4 (int8_t *base, vuint8m1_t bindex, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i8m1x5 (int8_t *base, vuint8m1_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i8m1x6 (int8_t *base, vuint8m1_t bindex, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i8m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i8m1x7 (int8_t *base, vuint8m1_t bindex, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i8m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i8m1x8 (int8_t *base, vuint8m1_t bindex, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i8m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8m2x2 (int8_t *base, vuint8m2_t bindex, vint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i8m2x3 (int8_t *base, vuint8m2_t bindex, vint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i8m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8m2x4 (int8_t *base, vuint8m2_t bindex, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8m4x2 (int8_t *base, vuint8m4_t bindex, vint8m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8mf8x2 (int8_t *base, vuint16mf4_t bindex, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8mf8x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8mf8x4 (int8_t *base, vuint16mf4_t bindex, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8mf8x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i8mf8x5 (int8_t *base, vuint16mf4_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i8mf8x6 (int8_t *base, vuint16mf4_t bindex, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i8mf8x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i8mf8x7 (int8_t *base, vuint16mf4_t bindex, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i8mf8x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i8mf8x8 (int8_t *base, vuint16mf4_t bindex, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i8mf8x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8mf4x2 (int8_t *base, vuint16mf2_t bindex, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i8mf4x3 (int8_t *base, vuint16mf2_t bindex, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i8mf4x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8mf4x4 (int8_t *base, vuint16mf2_t bindex, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i8mf4x5 (int8_t *base, vuint16mf2_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i8mf4x6 (int8_t *base, vuint16mf2_t bindex, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i8mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i8mf4x7 (int8_t *base, vuint16mf2_t bindex, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i8mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i8mf4x8 (int8_t *base, vuint16mf2_t bindex, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i8mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8mf2x2 (int8_t *base, vuint16m1_t bindex, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i8mf2x3 (int8_t *base, vuint16m1_t bindex, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i8mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8mf2x4 (int8_t *base, vuint16m1_t bindex, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i8mf2x5 (int8_t *base, vuint16m1_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i8mf2x6 (int8_t *base, vuint16m1_t bindex, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i8mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i8mf2x7 (int8_t *base, vuint16m1_t bindex, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i8mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i8mf2x8 (int8_t *base, vuint16m1_t bindex, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i8mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8m1x2 (int8_t *base, vuint16m2_t bindex, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i8m1x3 (int8_t *base, vuint16m2_t bindex, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i8m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8m1x4 (int8_t *base, vuint16m2_t bindex, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i8m1x5 (int8_t *base, vuint16m2_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i8m1x6 (int8_t *base, vuint16m2_t bindex, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i8m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i8m1x7 (int8_t *base, vuint16m2_t bindex, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i8m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i8m1x8 (int8_t *base, vuint16m2_t bindex, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i8m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8m2x2 (int8_t *base, vuint16m4_t bindex, vint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i8m2x3 (int8_t *base, vuint16m4_t bindex, vint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i8m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8m2x4 (int8_t *base, vuint16m4_t bindex, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8m4x2 (int8_t *base, vuint16m8_t bindex, vint8m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8mf8x2 (int8_t *base, vuint32mf2_t bindex, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8mf8x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8mf8x4 (int8_t *base, vuint32mf2_t bindex, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8mf8x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf8x5 (int8_t *base, vuint32mf2_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i8mf8x6 (int8_t *base, vuint32mf2_t bindex, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i8mf8x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i8mf8x7 (int8_t *base, vuint32mf2_t bindex, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i8mf8x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i8mf8x8 (int8_t *base, vuint32mf2_t bindex, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i8mf8x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8mf4x2 (int8_t *base, vuint32m1_t bindex, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i8mf4x3 (int8_t *base, vuint32m1_t bindex, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i8mf4x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8mf4x4 (int8_t *base, vuint32m1_t bindex, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf4x5 (int8_t *base, vuint32m1_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i8mf4x6 (int8_t *base, vuint32m1_t bindex, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i8mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i8mf4x7 (int8_t *base, vuint32m1_t bindex, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i8mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i8mf4x8 (int8_t *base, vuint32m1_t bindex, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i8mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8mf2x2 (int8_t *base, vuint32m2_t bindex, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i8mf2x3 (int8_t *base, vuint32m2_t bindex, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i8mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8mf2x4 (int8_t *base, vuint32m2_t bindex, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf2x5 (int8_t *base, vuint32m2_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i8mf2x6 (int8_t *base, vuint32m2_t bindex, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i8mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i8mf2x7 (int8_t *base, vuint32m2_t bindex, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i8mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i8mf2x8 (int8_t *base, vuint32m2_t bindex, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i8mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8m1x2 (int8_t *base, vuint32m4_t bindex, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i8m1x3 (int8_t *base, vuint32m4_t bindex, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i8m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8m1x4 (int8_t *base, vuint32m4_t bindex, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8m1x5 (int8_t *base, vuint32m4_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i8m1x6 (int8_t *base, vuint32m4_t bindex, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i8m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i8m1x7 (int8_t *base, vuint32m4_t bindex, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i8m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i8m1x8 (int8_t *base, vuint32m4_t bindex, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i8m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8m2x2 (int8_t *base, vuint32m8_t bindex, vint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i8m2x3 (int8_t *base, vuint32m8_t bindex, vint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i8m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8m2x4 (int8_t *base, vuint32m8_t bindex, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i8mf8x2 (int8_t *base, vuint64m1_t bindex, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i8mf8x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i8mf8x4 (int8_t *base, vuint64m1_t bindex, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i8mf8x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i8mf8x5 (int8_t *base, vuint64m1_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i8mf8x6 (int8_t *base, vuint64m1_t bindex, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i8mf8x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i8mf8x7 (int8_t *base, vuint64m1_t bindex, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i8mf8x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i8mf8x8 (int8_t *base, vuint64m1_t bindex, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i8mf8x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i8mf4x2 (int8_t *base, vuint64m2_t bindex, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i8mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i8mf4x3 (int8_t *base, vuint64m2_t bindex, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i8mf4x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i8mf4x4 (int8_t *base, vuint64m2_t bindex, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i8mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i8mf4x5 (int8_t *base, vuint64m2_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i8mf4x6 (int8_t *base, vuint64m2_t bindex, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i8mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i8mf4x7 (int8_t *base, vuint64m2_t bindex, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i8mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i8mf4x8 (int8_t *base, vuint64m2_t bindex, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i8mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i8mf2x2 (int8_t *base, vuint64m4_t bindex, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i8mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i8mf2x3 (int8_t *base, vuint64m4_t bindex, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i8mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i8mf2x4 (int8_t *base, vuint64m4_t bindex, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i8mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i8mf2x5 (int8_t *base, vuint64m4_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i8mf2x6 (int8_t *base, vuint64m4_t bindex, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i8mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i8mf2x7 (int8_t *base, vuint64m4_t bindex, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i8mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i8mf2x8 (int8_t *base, vuint64m4_t bindex, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i8mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i8m1x2 (int8_t *base, vuint64m8_t bindex, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i8m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i8m1x3 (int8_t *base, vuint64m8_t bindex, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i8m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i8m1x4 (int8_t *base, vuint64m8_t bindex, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i8m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i8m1x5 (int8_t *base, vuint64m8_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i8m1x6 (int8_t *base, vuint64m8_t bindex, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i8m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i8m1x7 (int8_t *base, vuint64m8_t bindex, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i8m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i8m1x8 (int8_t *base, vuint64m8_t bindex, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i8m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16mf4x2 (int16_t *base, vuint8mf8_t bindex, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i16mf4x4 (int16_t *base, vuint8mf8_t bindex, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i16mf4x5 (int16_t *base, vuint8mf8_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i16mf4x6 (int16_t *base, vuint8mf8_t bindex, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i16mf4x7 (int16_t *base, vuint8mf8_t bindex, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i16mf4x8 (int16_t *base, vuint8mf8_t bindex, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16mf2x2 (int16_t *base, vuint8mf4_t bindex, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i16mf2x3 (int16_t *base, vuint8mf4_t bindex, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i16mf2x4 (int16_t *base, vuint8mf4_t bindex, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i16mf2x5 (int16_t *base, vuint8mf4_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i16mf2x6 (int16_t *base, vuint8mf4_t bindex, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i16mf2x7 (int16_t *base, vuint8mf4_t bindex, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i16mf2x8 (int16_t *base, vuint8mf4_t bindex, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16m1x2 (int16_t *base, vuint8mf2_t bindex, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i16m1x3 (int16_t *base, vuint8mf2_t bindex, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i16m1x4 (int16_t *base, vuint8mf2_t bindex, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i16m1x5 (int16_t *base, vuint8mf2_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i16m1x6 (int16_t *base, vuint8mf2_t bindex, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i16m1x7 (int16_t *base, vuint8mf2_t bindex, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i16m1x8 (int16_t *base, vuint8mf2_t bindex, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16m2x2 (int16_t *base, vuint8m1_t bindex, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i16m2x3 (int16_t *base, vuint8m1_t bindex, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i16m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i16m2x4 (int16_t *base, vuint8m1_t bindex, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i16m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16m4x2 (int16_t *base, vuint8m2_t bindex, vint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16mf4x2 (int16_t *base, vuint16mf4_t bindex, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i16mf4x4 (int16_t *base, vuint16mf4_t bindex, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i16mf4x5 (int16_t *base, vuint16mf4_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i16mf4x6 (int16_t *base, vuint16mf4_t bindex, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i16mf4x7 (int16_t *base, vuint16mf4_t bindex, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i16mf4x8 (int16_t *base, vuint16mf4_t bindex, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16mf2x2 (int16_t *base, vuint16mf2_t bindex, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i16mf2x3 (int16_t *base, vuint16mf2_t bindex, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i16mf2x4 (int16_t *base, vuint16mf2_t bindex, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i16mf2x5 (int16_t *base, vuint16mf2_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i16mf2x6 (int16_t *base, vuint16mf2_t bindex, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i16mf2x7 (int16_t *base, vuint16mf2_t bindex, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i16mf2x8 (int16_t *base, vuint16mf2_t bindex, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16m1x2 (int16_t *base, vuint16m1_t bindex, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i16m1x3 (int16_t *base, vuint16m1_t bindex, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i16m1x4 (int16_t *base, vuint16m1_t bindex, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i16m1x5 (int16_t *base, vuint16m1_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i16m1x6 (int16_t *base, vuint16m1_t bindex, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i16m1x7 (int16_t *base, vuint16m1_t bindex, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i16m1x8 (int16_t *base, vuint16m1_t bindex, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16m2x2 (int16_t *base, vuint16m2_t bindex, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i16m2x3 (int16_t *base, vuint16m2_t bindex, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i16m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i16m2x4 (int16_t *base, vuint16m2_t bindex, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i16m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16m4x2 (int16_t *base, vuint16m4_t bindex, vint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16mf4x2 (int16_t *base, vuint32mf2_t bindex, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i16mf4x4 (int16_t *base, vuint32mf2_t bindex, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16mf4x5 (int16_t *base, vuint32mf2_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i16mf4x6 (int16_t *base, vuint32mf2_t bindex, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i16mf4x7 (int16_t *base, vuint32mf2_t bindex, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i16mf4x8 (int16_t *base, vuint32mf2_t bindex, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16mf2x2 (int16_t *base, vuint32m1_t bindex, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i16mf2x3 (int16_t *base, vuint32m1_t bindex, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i16mf2x4 (int16_t *base, vuint32m1_t bindex, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16mf2x5 (int16_t *base, vuint32m1_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i16mf2x6 (int16_t *base, vuint32m1_t bindex, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i16mf2x7 (int16_t *base, vuint32m1_t bindex, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i16mf2x8 (int16_t *base, vuint32m1_t bindex, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16m1x2 (int16_t *base, vuint32m2_t bindex, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i16m1x3 (int16_t *base, vuint32m2_t bindex, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i16m1x4 (int16_t *base, vuint32m2_t bindex, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16m1x5 (int16_t *base, vuint32m2_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i16m1x6 (int16_t *base, vuint32m2_t bindex, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i16m1x7 (int16_t *base, vuint32m2_t bindex, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i16m1x8 (int16_t *base, vuint32m2_t bindex, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16m2x2 (int16_t *base, vuint32m4_t bindex, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i16m2x3 (int16_t *base, vuint32m4_t bindex, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i16m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i16m2x4 (int16_t *base, vuint32m4_t bindex, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i16m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16m4x2 (int16_t *base, vuint32m8_t bindex, vint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i16mf4x2 (int16_t *base, vuint64m1_t bindex, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i16mf4x4 (int16_t *base, vuint64m1_t bindex, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i16mf4x5 (int16_t *base, vuint64m1_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i16mf4x6 (int16_t *base, vuint64m1_t bindex, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i16mf4x7 (int16_t *base, vuint64m1_t bindex, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i16mf4x8 (int16_t *base, vuint64m1_t bindex, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i16mf2x2 (int16_t *base, vuint64m2_t bindex, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i16mf2x3 (int16_t *base, vuint64m2_t bindex, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i16mf2x4 (int16_t *base, vuint64m2_t bindex, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i16mf2x5 (int16_t *base, vuint64m2_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i16mf2x6 (int16_t *base, vuint64m2_t bindex, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i16mf2x7 (int16_t *base, vuint64m2_t bindex, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i16mf2x8 (int16_t *base, vuint64m2_t bindex, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i16m1x2 (int16_t *base, vuint64m4_t bindex, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i16m1x3 (int16_t *base, vuint64m4_t bindex, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i16m1x4 (int16_t *base, vuint64m4_t bindex, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i16m1x5 (int16_t *base, vuint64m4_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i16m1x6 (int16_t *base, vuint64m4_t bindex, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i16m1x7 (int16_t *base, vuint64m4_t bindex, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i16m1x8 (int16_t *base, vuint64m4_t bindex, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i16m2x2 (int16_t *base, vuint64m8_t bindex, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i16m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i16m2x3 (int16_t *base, vuint64m8_t bindex, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i16m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i16m2x4 (int16_t *base, vuint64m8_t bindex, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i16m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i32mf2x2 (int32_t *base, vuint8mf8_t bindex, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i32mf2x4 (int32_t *base, vuint8mf8_t bindex, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i32mf2x5 (int32_t *base, vuint8mf8_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i32mf2x6 (int32_t *base, vuint8mf8_t bindex, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i32mf2x7 (int32_t *base, vuint8mf8_t bindex, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i32mf2x8 (int32_t *base, vuint8mf8_t bindex, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i32m1x2 (int32_t *base, vuint8mf4_t bindex, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i32m1x3 (int32_t *base, vuint8mf4_t bindex, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i32m1x4 (int32_t *base, vuint8mf4_t bindex, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i32m1x5 (int32_t *base, vuint8mf4_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i32m1x6 (int32_t *base, vuint8mf4_t bindex, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i32m1x7 (int32_t *base, vuint8mf4_t bindex, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i32m1x8 (int32_t *base, vuint8mf4_t bindex, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i32m2x2 (int32_t *base, vuint8mf2_t bindex, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i32m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i32m2x3 (int32_t *base, vuint8mf2_t bindex, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i32m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i32m2x4 (int32_t *base, vuint8mf2_t bindex, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i32m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i32m4x2 (int32_t *base, vuint8m1_t bindex, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i32m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i32mf2x2 (int32_t *base, vuint16mf4_t bindex, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i32mf2x4 (int32_t *base, vuint16mf4_t bindex, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i32mf2x5 (int32_t *base, vuint16mf4_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i32mf2x6 (int32_t *base, vuint16mf4_t bindex, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i32mf2x7 (int32_t *base, vuint16mf4_t bindex, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i32mf2x8 (int32_t *base, vuint16mf4_t bindex, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i32m1x2 (int32_t *base, vuint16mf2_t bindex, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i32m1x3 (int32_t *base, vuint16mf2_t bindex, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i32m1x4 (int32_t *base, vuint16mf2_t bindex, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i32m1x5 (int32_t *base, vuint16mf2_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i32m1x6 (int32_t *base, vuint16mf2_t bindex, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i32m1x7 (int32_t *base, vuint16mf2_t bindex, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i32m1x8 (int32_t *base, vuint16mf2_t bindex, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i32m2x2 (int32_t *base, vuint16m1_t bindex, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i32m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i32m2x3 (int32_t *base, vuint16m1_t bindex, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i32m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i32m2x4 (int32_t *base, vuint16m1_t bindex, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i32m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i32m4x2 (int32_t *base, vuint16m2_t bindex, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i32m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i32mf2x2 (int32_t *base, vuint32mf2_t bindex, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i32mf2x4 (int32_t *base, vuint32mf2_t bindex, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i32mf2x5 (int32_t *base, vuint32mf2_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i32mf2x6 (int32_t *base, vuint32mf2_t bindex, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i32mf2x7 (int32_t *base, vuint32mf2_t bindex, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i32mf2x8 (int32_t *base, vuint32mf2_t bindex, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i32m1x2 (int32_t *base, vuint32m1_t bindex, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i32m1x3 (int32_t *base, vuint32m1_t bindex, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i32m1x4 (int32_t *base, vuint32m1_t bindex, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i32m1x5 (int32_t *base, vuint32m1_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i32m1x6 (int32_t *base, vuint32m1_t bindex, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i32m1x7 (int32_t *base, vuint32m1_t bindex, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i32m1x8 (int32_t *base, vuint32m1_t bindex, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i32m2x2 (int32_t *base, vuint32m2_t bindex, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i32m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i32m2x3 (int32_t *base, vuint32m2_t bindex, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i32m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i32m2x4 (int32_t *base, vuint32m2_t bindex, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i32m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i32m4x2 (int32_t *base, vuint32m4_t bindex, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i32m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i32mf2x2 (int32_t *base, vuint64m1_t bindex, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i32mf2x4 (int32_t *base, vuint64m1_t bindex, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i32mf2x5 (int32_t *base, vuint64m1_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i32mf2x6 (int32_t *base, vuint64m1_t bindex, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i32mf2x7 (int32_t *base, vuint64m1_t bindex, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i32mf2x8 (int32_t *base, vuint64m1_t bindex, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i32m1x2 (int32_t *base, vuint64m2_t bindex, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i32m1x3 (int32_t *base, vuint64m2_t bindex, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i32m1x4 (int32_t *base, vuint64m2_t bindex, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i32m1x5 (int32_t *base, vuint64m2_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i32m1x6 (int32_t *base, vuint64m2_t bindex, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i32m1x7 (int32_t *base, vuint64m2_t bindex, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i32m1x8 (int32_t *base, vuint64m2_t bindex, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i32m2x2 (int32_t *base, vuint64m4_t bindex, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i32m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i32m2x3 (int32_t *base, vuint64m4_t bindex, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i32m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i32m2x4 (int32_t *base, vuint64m4_t bindex, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i32m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i32m4x2 (int32_t *base, vuint64m8_t bindex, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i32m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i64m1x2 (int64_t *base, vuint8mf8_t bindex, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i64m1x4 (int64_t *base, vuint8mf8_t bindex, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i64m1x5 (int64_t *base, vuint8mf8_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i64m1x6 (int64_t *base, vuint8mf8_t bindex, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i64m1x7 (int64_t *base, vuint8mf8_t bindex, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i64m1x8 (int64_t *base, vuint8mf8_t bindex, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i64m2x2 (int64_t *base, vuint8mf4_t bindex, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i64m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i64m2x3 (int64_t *base, vuint8mf4_t bindex, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i64m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i64m2x4 (int64_t *base, vuint8mf4_t bindex, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i64m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i64m4x2 (int64_t *base, vuint8mf2_t bindex, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i64m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i64m1x2 (int64_t *base, vuint16mf4_t bindex, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i64m1x4 (int64_t *base, vuint16mf4_t bindex, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i64m1x5 (int64_t *base, vuint16mf4_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i64m1x6 (int64_t *base, vuint16mf4_t bindex, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i64m1x7 (int64_t *base, vuint16mf4_t bindex, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i64m1x8 (int64_t *base, vuint16mf4_t bindex, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i64m2x2 (int64_t *base, vuint16mf2_t bindex, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i64m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i64m2x3 (int64_t *base, vuint16mf2_t bindex, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i64m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i64m2x4 (int64_t *base, vuint16mf2_t bindex, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i64m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i64m4x2 (int64_t *base, vuint16m1_t bindex, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i64m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i64m1x2 (int64_t *base, vuint32mf2_t bindex, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i64m1x4 (int64_t *base, vuint32mf2_t bindex, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i64m1x5 (int64_t *base, vuint32mf2_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i64m1x6 (int64_t *base, vuint32mf2_t bindex, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i64m1x7 (int64_t *base, vuint32mf2_t bindex, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i64m1x8 (int64_t *base, vuint32mf2_t bindex, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i64m2x2 (int64_t *base, vuint32m1_t bindex, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i64m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i64m2x3 (int64_t *base, vuint32m1_t bindex, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i64m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i64m2x4 (int64_t *base, vuint32m1_t bindex, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i64m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i64m4x2 (int64_t *base, vuint32m2_t bindex, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i64m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i64m1x2 (int64_t *base, vuint64m1_t bindex, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i64m1x4 (int64_t *base, vuint64m1_t bindex, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i64m1x5 (int64_t *base, vuint64m1_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i64m1x6 (int64_t *base, vuint64m1_t bindex, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i64m1x7 (int64_t *base, vuint64m1_t bindex, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i64m1x8 (int64_t *base, vuint64m1_t bindex, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i64m2x2 (int64_t *base, vuint64m2_t bindex, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i64m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i64m2x3 (int64_t *base, vuint64m2_t bindex, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i64m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i64m2x4 (int64_t *base, vuint64m2_t bindex, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i64m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i64m4x2 (int64_t *base, vuint64m4_t bindex, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i64m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8mf8x2 (uint8_t *base, vuint8mf8_t bindex, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8mf8x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8mf8x4 (uint8_t *base, vuint8mf8_t bindex, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8mf8x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u8mf8x5 (uint8_t *base, vuint8mf8_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u8mf8x6 (uint8_t *base, vuint8mf8_t bindex, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u8mf8x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u8mf8x7 (uint8_t *base, vuint8mf8_t bindex, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u8mf8x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u8mf8x8 (uint8_t *base, vuint8mf8_t bindex, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u8mf8x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8mf4x2 (uint8_t *base, vuint8mf4_t bindex, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u8mf4x3 (uint8_t *base, vuint8mf4_t bindex, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u8mf4x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8mf4x4 (uint8_t *base, vuint8mf4_t bindex, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u8mf4x5 (uint8_t *base, vuint8mf4_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u8mf4x6 (uint8_t *base, vuint8mf4_t bindex, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u8mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u8mf4x7 (uint8_t *base, vuint8mf4_t bindex, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u8mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u8mf4x8 (uint8_t *base, vuint8mf4_t bindex, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u8mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8mf2x2 (uint8_t *base, vuint8mf2_t bindex, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u8mf2x3 (uint8_t *base, vuint8mf2_t bindex, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u8mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8mf2x4 (uint8_t *base, vuint8mf2_t bindex, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u8mf2x5 (uint8_t *base, vuint8mf2_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u8mf2x6 (uint8_t *base, vuint8mf2_t bindex, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u8mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u8mf2x7 (uint8_t *base, vuint8mf2_t bindex, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u8mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u8mf2x8 (uint8_t *base, vuint8mf2_t bindex, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u8mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8m1x2 (uint8_t *base, vuint8m1_t bindex, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u8m1x3 (uint8_t *base, vuint8m1_t bindex, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u8m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8m1x4 (uint8_t *base, vuint8m1_t bindex, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u8m1x5 (uint8_t *base, vuint8m1_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u8m1x6 (uint8_t *base, vuint8m1_t bindex, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u8m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u8m1x7 (uint8_t *base, vuint8m1_t bindex, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u8m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u8m1x8 (uint8_t *base, vuint8m1_t bindex, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u8m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8m2x2 (uint8_t *base, vuint8m2_t bindex, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u8m2x3 (uint8_t *base, vuint8m2_t bindex, vuint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u8m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8m2x4 (uint8_t *base, vuint8m2_t bindex, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8m4x2 (uint8_t *base, vuint8m4_t bindex, vuint8m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8mf8x2 (uint8_t *base, vuint16mf4_t bindex, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8mf8x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8mf8x4 (uint8_t *base, vuint16mf4_t bindex, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8mf8x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u8mf8x5 (uint8_t *base, vuint16mf4_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u8mf8x6 (uint8_t *base, vuint16mf4_t bindex, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u8mf8x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u8mf8x7 (uint8_t *base, vuint16mf4_t bindex, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u8mf8x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u8mf8x8 (uint8_t *base, vuint16mf4_t bindex, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u8mf8x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8mf4x2 (uint8_t *base, vuint16mf2_t bindex, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u8mf4x3 (uint8_t *base, vuint16mf2_t bindex, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u8mf4x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8mf4x4 (uint8_t *base, vuint16mf2_t bindex, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u8mf4x5 (uint8_t *base, vuint16mf2_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u8mf4x6 (uint8_t *base, vuint16mf2_t bindex, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u8mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u8mf4x7 (uint8_t *base, vuint16mf2_t bindex, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u8mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u8mf4x8 (uint8_t *base, vuint16mf2_t bindex, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u8mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8mf2x2 (uint8_t *base, vuint16m1_t bindex, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u8mf2x3 (uint8_t *base, vuint16m1_t bindex, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u8mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8mf2x4 (uint8_t *base, vuint16m1_t bindex, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u8mf2x5 (uint8_t *base, vuint16m1_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u8mf2x6 (uint8_t *base, vuint16m1_t bindex, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u8mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u8mf2x7 (uint8_t *base, vuint16m1_t bindex, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u8mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u8mf2x8 (uint8_t *base, vuint16m1_t bindex, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u8mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8m1x2 (uint8_t *base, vuint16m2_t bindex, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u8m1x3 (uint8_t *base, vuint16m2_t bindex, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u8m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8m1x4 (uint8_t *base, vuint16m2_t bindex, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u8m1x5 (uint8_t *base, vuint16m2_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u8m1x6 (uint8_t *base, vuint16m2_t bindex, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u8m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u8m1x7 (uint8_t *base, vuint16m2_t bindex, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u8m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u8m1x8 (uint8_t *base, vuint16m2_t bindex, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u8m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8m2x2 (uint8_t *base, vuint16m4_t bindex, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u8m2x3 (uint8_t *base, vuint16m4_t bindex, vuint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u8m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8m2x4 (uint8_t *base, vuint16m4_t bindex, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8m4x2 (uint8_t *base, vuint16m8_t bindex, vuint8m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8mf8x2 (uint8_t *base, vuint32mf2_t bindex, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8mf8x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8mf8x4 (uint8_t *base, vuint32mf2_t bindex, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8mf8x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf8x5 (uint8_t *base, vuint32mf2_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u8mf8x6 (uint8_t *base, vuint32mf2_t bindex, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u8mf8x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u8mf8x7 (uint8_t *base, vuint32mf2_t bindex, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u8mf8x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u8mf8x8 (uint8_t *base, vuint32mf2_t bindex, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u8mf8x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8mf4x2 (uint8_t *base, vuint32m1_t bindex, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u8mf4x3 (uint8_t *base, vuint32m1_t bindex, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u8mf4x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8mf4x4 (uint8_t *base, vuint32m1_t bindex, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf4x5 (uint8_t *base, vuint32m1_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u8mf4x6 (uint8_t *base, vuint32m1_t bindex, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u8mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u8mf4x7 (uint8_t *base, vuint32m1_t bindex, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u8mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u8mf4x8 (uint8_t *base, vuint32m1_t bindex, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u8mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8mf2x2 (uint8_t *base, vuint32m2_t bindex, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u8mf2x3 (uint8_t *base, vuint32m2_t bindex, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u8mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8mf2x4 (uint8_t *base, vuint32m2_t bindex, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf2x5 (uint8_t *base, vuint32m2_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u8mf2x6 (uint8_t *base, vuint32m2_t bindex, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u8mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u8mf2x7 (uint8_t *base, vuint32m2_t bindex, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u8mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u8mf2x8 (uint8_t *base, vuint32m2_t bindex, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u8mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8m1x2 (uint8_t *base, vuint32m4_t bindex, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u8m1x3 (uint8_t *base, vuint32m4_t bindex, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u8m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8m1x4 (uint8_t *base, vuint32m4_t bindex, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8m1x5 (uint8_t *base, vuint32m4_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u8m1x6 (uint8_t *base, vuint32m4_t bindex, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u8m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u8m1x7 (uint8_t *base, vuint32m4_t bindex, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u8m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u8m1x8 (uint8_t *base, vuint32m4_t bindex, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u8m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8m2x2 (uint8_t *base, vuint32m8_t bindex, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u8m2x3 (uint8_t *base, vuint32m8_t bindex, vuint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u8m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8m2x4 (uint8_t *base, vuint32m8_t bindex, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u8mf8x2 (uint8_t *base, vuint64m1_t bindex, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u8mf8x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u8mf8x4 (uint8_t *base, vuint64m1_t bindex, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u8mf8x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u8mf8x5 (uint8_t *base, vuint64m1_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u8mf8x6 (uint8_t *base, vuint64m1_t bindex, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u8mf8x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u8mf8x7 (uint8_t *base, vuint64m1_t bindex, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u8mf8x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u8mf8x8 (uint8_t *base, vuint64m1_t bindex, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u8mf8x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u8mf4x2 (uint8_t *base, vuint64m2_t bindex, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u8mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u8mf4x3 (uint8_t *base, vuint64m2_t bindex, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u8mf4x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u8mf4x4 (uint8_t *base, vuint64m2_t bindex, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u8mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u8mf4x5 (uint8_t *base, vuint64m2_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u8mf4x6 (uint8_t *base, vuint64m2_t bindex, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u8mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u8mf4x7 (uint8_t *base, vuint64m2_t bindex, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u8mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u8mf4x8 (uint8_t *base, vuint64m2_t bindex, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u8mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u8mf2x2 (uint8_t *base, vuint64m4_t bindex, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u8mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u8mf2x3 (uint8_t *base, vuint64m4_t bindex, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u8mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u8mf2x4 (uint8_t *base, vuint64m4_t bindex, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u8mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u8mf2x5 (uint8_t *base, vuint64m4_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u8mf2x6 (uint8_t *base, vuint64m4_t bindex, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u8mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u8mf2x7 (uint8_t *base, vuint64m4_t bindex, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u8mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u8mf2x8 (uint8_t *base, vuint64m4_t bindex, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u8mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u8m1x2 (uint8_t *base, vuint64m8_t bindex, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u8m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u8m1x3 (uint8_t *base, vuint64m8_t bindex, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u8m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u8m1x4 (uint8_t *base, vuint64m8_t bindex, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u8m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u8m1x5 (uint8_t *base, vuint64m8_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u8m1x6 (uint8_t *base, vuint64m8_t bindex, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u8m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u8m1x7 (uint8_t *base, vuint64m8_t bindex, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u8m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u8m1x8 (uint8_t *base, vuint64m8_t bindex, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u8m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16mf4x2 (uint16_t *base, vuint8mf8_t bindex, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u16mf4x4 (uint16_t *base, vuint8mf8_t bindex, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u16mf4x5 (uint16_t *base, vuint8mf8_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u16mf4x6 (uint16_t *base, vuint8mf8_t bindex, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u16mf4x7 (uint16_t *base, vuint8mf8_t bindex, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u16mf4x8 (uint16_t *base, vuint8mf8_t bindex, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16mf2x2 (uint16_t *base, vuint8mf4_t bindex, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u16mf2x3 (uint16_t *base, vuint8mf4_t bindex, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u16mf2x4 (uint16_t *base, vuint8mf4_t bindex, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u16mf2x5 (uint16_t *base, vuint8mf4_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u16mf2x6 (uint16_t *base, vuint8mf4_t bindex, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u16mf2x7 (uint16_t *base, vuint8mf4_t bindex, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u16mf2x8 (uint16_t *base, vuint8mf4_t bindex, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16m1x2 (uint16_t *base, vuint8mf2_t bindex, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u16m1x3 (uint16_t *base, vuint8mf2_t bindex, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u16m1x4 (uint16_t *base, vuint8mf2_t bindex, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u16m1x5 (uint16_t *base, vuint8mf2_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u16m1x6 (uint16_t *base, vuint8mf2_t bindex, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u16m1x7 (uint16_t *base, vuint8mf2_t bindex, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u16m1x8 (uint16_t *base, vuint8mf2_t bindex, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16m2x2 (uint16_t *base, vuint8m1_t bindex, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u16m2x3 (uint16_t *base, vuint8m1_t bindex, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u16m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u16m2x4 (uint16_t *base, vuint8m1_t bindex, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u16m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16m4x2 (uint16_t *base, vuint8m2_t bindex, vuint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16mf4x2 (uint16_t *base, vuint16mf4_t bindex, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u16mf4x4 (uint16_t *base, vuint16mf4_t bindex, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u16mf4x5 (uint16_t *base, vuint16mf4_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u16mf4x6 (uint16_t *base, vuint16mf4_t bindex, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u16mf4x7 (uint16_t *base, vuint16mf4_t bindex, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u16mf4x8 (uint16_t *base, vuint16mf4_t bindex, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16mf2x2 (uint16_t *base, vuint16mf2_t bindex, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u16mf2x3 (uint16_t *base, vuint16mf2_t bindex, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u16mf2x4 (uint16_t *base, vuint16mf2_t bindex, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u16mf2x5 (uint16_t *base, vuint16mf2_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u16mf2x6 (uint16_t *base, vuint16mf2_t bindex, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u16mf2x7 (uint16_t *base, vuint16mf2_t bindex, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u16mf2x8 (uint16_t *base, vuint16mf2_t bindex, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16m1x2 (uint16_t *base, vuint16m1_t bindex, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u16m1x3 (uint16_t *base, vuint16m1_t bindex, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u16m1x4 (uint16_t *base, vuint16m1_t bindex, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u16m1x5 (uint16_t *base, vuint16m1_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u16m1x6 (uint16_t *base, vuint16m1_t bindex, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u16m1x7 (uint16_t *base, vuint16m1_t bindex, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u16m1x8 (uint16_t *base, vuint16m1_t bindex, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16m2x2 (uint16_t *base, vuint16m2_t bindex, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u16m2x3 (uint16_t *base, vuint16m2_t bindex, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u16m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u16m2x4 (uint16_t *base, vuint16m2_t bindex, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u16m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16m4x2 (uint16_t *base, vuint16m4_t bindex, vuint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16mf4x2 (uint16_t *base, vuint32mf2_t bindex, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u16mf4x4 (uint16_t *base, vuint32mf2_t bindex, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16mf4x5 (uint16_t *base, vuint32mf2_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u16mf4x6 (uint16_t *base, vuint32mf2_t bindex, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u16mf4x7 (uint16_t *base, vuint32mf2_t bindex, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u16mf4x8 (uint16_t *base, vuint32mf2_t bindex, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16mf2x2 (uint16_t *base, vuint32m1_t bindex, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u16mf2x3 (uint16_t *base, vuint32m1_t bindex, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u16mf2x4 (uint16_t *base, vuint32m1_t bindex, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16mf2x5 (uint16_t *base, vuint32m1_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u16mf2x6 (uint16_t *base, vuint32m1_t bindex, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u16mf2x7 (uint16_t *base, vuint32m1_t bindex, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u16mf2x8 (uint16_t *base, vuint32m1_t bindex, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16m1x2 (uint16_t *base, vuint32m2_t bindex, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u16m1x3 (uint16_t *base, vuint32m2_t bindex, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u16m1x4 (uint16_t *base, vuint32m2_t bindex, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16m1x5 (uint16_t *base, vuint32m2_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u16m1x6 (uint16_t *base, vuint32m2_t bindex, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u16m1x7 (uint16_t *base, vuint32m2_t bindex, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u16m1x8 (uint16_t *base, vuint32m2_t bindex, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16m2x2 (uint16_t *base, vuint32m4_t bindex, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u16m2x3 (uint16_t *base, vuint32m4_t bindex, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u16m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u16m2x4 (uint16_t *base, vuint32m4_t bindex, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u16m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16m4x2 (uint16_t *base, vuint32m8_t bindex, vuint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u16mf4x2 (uint16_t *base, vuint64m1_t bindex, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u16mf4x4 (uint16_t *base, vuint64m1_t bindex, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u16mf4x5 (uint16_t *base, vuint64m1_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u16mf4x6 (uint16_t *base, vuint64m1_t bindex, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u16mf4x7 (uint16_t *base, vuint64m1_t bindex, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u16mf4x8 (uint16_t *base, vuint64m1_t bindex, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u16mf2x2 (uint16_t *base, vuint64m2_t bindex, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u16mf2x3 (uint16_t *base, vuint64m2_t bindex, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u16mf2x4 (uint16_t *base, vuint64m2_t bindex, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u16mf2x5 (uint16_t *base, vuint64m2_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u16mf2x6 (uint16_t *base, vuint64m2_t bindex, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u16mf2x7 (uint16_t *base, vuint64m2_t bindex, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u16mf2x8 (uint16_t *base, vuint64m2_t bindex, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u16m1x2 (uint16_t *base, vuint64m4_t bindex, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u16m1x3 (uint16_t *base, vuint64m4_t bindex, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u16m1x4 (uint16_t *base, vuint64m4_t bindex, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u16m1x5 (uint16_t *base, vuint64m4_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u16m1x6 (uint16_t *base, vuint64m4_t bindex, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u16m1x7 (uint16_t *base, vuint64m4_t bindex, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u16m1x8 (uint16_t *base, vuint64m4_t bindex, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u16m2x2 (uint16_t *base, vuint64m8_t bindex, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u16m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u16m2x3 (uint16_t *base, vuint64m8_t bindex, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u16m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u16m2x4 (uint16_t *base, vuint64m8_t bindex, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u16m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u32mf2x2 (uint32_t *base, vuint8mf8_t bindex, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u32mf2x4 (uint32_t *base, vuint8mf8_t bindex, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u32mf2x5 (uint32_t *base, vuint8mf8_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u32mf2x6 (uint32_t *base, vuint8mf8_t bindex, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u32mf2x7 (uint32_t *base, vuint8mf8_t bindex, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u32mf2x8 (uint32_t *base, vuint8mf8_t bindex, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u32m1x2 (uint32_t *base, vuint8mf4_t bindex, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u32m1x3 (uint32_t *base, vuint8mf4_t bindex, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u32m1x4 (uint32_t *base, vuint8mf4_t bindex, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u32m1x5 (uint32_t *base, vuint8mf4_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u32m1x6 (uint32_t *base, vuint8mf4_t bindex, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u32m1x7 (uint32_t *base, vuint8mf4_t bindex, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u32m1x8 (uint32_t *base, vuint8mf4_t bindex, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u32m2x2 (uint32_t *base, vuint8mf2_t bindex, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u32m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u32m2x3 (uint32_t *base, vuint8mf2_t bindex, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u32m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u32m2x4 (uint32_t *base, vuint8mf2_t bindex, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u32m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u32m4x2 (uint32_t *base, vuint8m1_t bindex, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u32m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u32mf2x2 (uint32_t *base, vuint16mf4_t bindex, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u32mf2x4 (uint32_t *base, vuint16mf4_t bindex, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u32mf2x5 (uint32_t *base, vuint16mf4_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u32mf2x6 (uint32_t *base, vuint16mf4_t bindex, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u32mf2x7 (uint32_t *base, vuint16mf4_t bindex, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u32mf2x8 (uint32_t *base, vuint16mf4_t bindex, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u32m1x2 (uint32_t *base, vuint16mf2_t bindex, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u32m1x3 (uint32_t *base, vuint16mf2_t bindex, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u32m1x4 (uint32_t *base, vuint16mf2_t bindex, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u32m1x5 (uint32_t *base, vuint16mf2_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u32m1x6 (uint32_t *base, vuint16mf2_t bindex, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u32m1x7 (uint32_t *base, vuint16mf2_t bindex, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u32m1x8 (uint32_t *base, vuint16mf2_t bindex, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u32m2x2 (uint32_t *base, vuint16m1_t bindex, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u32m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u32m2x3 (uint32_t *base, vuint16m1_t bindex, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u32m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u32m2x4 (uint32_t *base, vuint16m1_t bindex, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u32m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u32m4x2 (uint32_t *base, vuint16m2_t bindex, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u32m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u32mf2x2 (uint32_t *base, vuint32mf2_t bindex, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u32mf2x4 (uint32_t *base, vuint32mf2_t bindex, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u32mf2x5 (uint32_t *base, vuint32mf2_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u32mf2x6 (uint32_t *base, vuint32mf2_t bindex, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u32mf2x7 (uint32_t *base, vuint32mf2_t bindex, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u32mf2x8 (uint32_t *base, vuint32mf2_t bindex, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u32m1x2 (uint32_t *base, vuint32m1_t bindex, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u32m1x3 (uint32_t *base, vuint32m1_t bindex, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u32m1x4 (uint32_t *base, vuint32m1_t bindex, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u32m1x5 (uint32_t *base, vuint32m1_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u32m1x6 (uint32_t *base, vuint32m1_t bindex, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u32m1x7 (uint32_t *base, vuint32m1_t bindex, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u32m1x8 (uint32_t *base, vuint32m1_t bindex, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u32m2x2 (uint32_t *base, vuint32m2_t bindex, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u32m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u32m2x3 (uint32_t *base, vuint32m2_t bindex, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u32m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u32m2x4 (uint32_t *base, vuint32m2_t bindex, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u32m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u32m4x2 (uint32_t *base, vuint32m4_t bindex, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u32m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u32mf2x2 (uint32_t *base, vuint64m1_t bindex, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u32mf2x4 (uint32_t *base, vuint64m1_t bindex, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u32mf2x5 (uint32_t *base, vuint64m1_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u32mf2x6 (uint32_t *base, vuint64m1_t bindex, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u32mf2x7 (uint32_t *base, vuint64m1_t bindex, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u32mf2x8 (uint32_t *base, vuint64m1_t bindex, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u32m1x2 (uint32_t *base, vuint64m2_t bindex, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u32m1x3 (uint32_t *base, vuint64m2_t bindex, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u32m1x4 (uint32_t *base, vuint64m2_t bindex, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u32m1x5 (uint32_t *base, vuint64m2_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u32m1x6 (uint32_t *base, vuint64m2_t bindex, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u32m1x7 (uint32_t *base, vuint64m2_t bindex, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u32m1x8 (uint32_t *base, vuint64m2_t bindex, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u32m2x2 (uint32_t *base, vuint64m4_t bindex, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u32m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u32m2x3 (uint32_t *base, vuint64m4_t bindex, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u32m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u32m2x4 (uint32_t *base, vuint64m4_t bindex, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u32m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u32m4x2 (uint32_t *base, vuint64m8_t bindex, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u32m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u64m1x2 (uint64_t *base, vuint8mf8_t bindex, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u64m1x4 (uint64_t *base, vuint8mf8_t bindex, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u64m1x5 (uint64_t *base, vuint8mf8_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u64m1x6 (uint64_t *base, vuint8mf8_t bindex, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u64m1x7 (uint64_t *base, vuint8mf8_t bindex, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u64m1x8 (uint64_t *base, vuint8mf8_t bindex, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u64m2x2 (uint64_t *base, vuint8mf4_t bindex, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u64m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u64m2x3 (uint64_t *base, vuint8mf4_t bindex, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u64m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u64m2x4 (uint64_t *base, vuint8mf4_t bindex, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u64m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u64m4x2 (uint64_t *base, vuint8mf2_t bindex, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u64m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u64m1x2 (uint64_t *base, vuint16mf4_t bindex, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u64m1x4 (uint64_t *base, vuint16mf4_t bindex, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u64m1x5 (uint64_t *base, vuint16mf4_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u64m1x6 (uint64_t *base, vuint16mf4_t bindex, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u64m1x7 (uint64_t *base, vuint16mf4_t bindex, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u64m1x8 (uint64_t *base, vuint16mf4_t bindex, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u64m2x2 (uint64_t *base, vuint16mf2_t bindex, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u64m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u64m2x3 (uint64_t *base, vuint16mf2_t bindex, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u64m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u64m2x4 (uint64_t *base, vuint16mf2_t bindex, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u64m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u64m4x2 (uint64_t *base, vuint16m1_t bindex, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u64m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u64m1x2 (uint64_t *base, vuint32mf2_t bindex, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u64m1x4 (uint64_t *base, vuint32mf2_t bindex, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u64m1x5 (uint64_t *base, vuint32mf2_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u64m1x6 (uint64_t *base, vuint32mf2_t bindex, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u64m1x7 (uint64_t *base, vuint32mf2_t bindex, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u64m1x8 (uint64_t *base, vuint32mf2_t bindex, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u64m2x2 (uint64_t *base, vuint32m1_t bindex, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u64m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u64m2x3 (uint64_t *base, vuint32m1_t bindex, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u64m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u64m2x4 (uint64_t *base, vuint32m1_t bindex, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u64m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u64m4x2 (uint64_t *base, vuint32m2_t bindex, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u64m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u64m1x2 (uint64_t *base, vuint64m1_t bindex, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u64m1x4 (uint64_t *base, vuint64m1_t bindex, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u64m1x5 (uint64_t *base, vuint64m1_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u64m1x6 (uint64_t *base, vuint64m1_t bindex, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u64m1x7 (uint64_t *base, vuint64m1_t bindex, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u64m1x8 (uint64_t *base, vuint64m1_t bindex, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u64m2x2 (uint64_t *base, vuint64m2_t bindex, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u64m2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u64m2x3 (uint64_t *base, vuint64m2_t bindex, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u64m2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u64m2x4 (uint64_t *base, vuint64m2_t bindex, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u64m2x4
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u64m4x2 (uint64_t *base, vuint64m4_t bindex, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u64m4x2
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f16mf4x2 (float16_t *base, vuint8mf8_t bindex, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f16mf4x4 (float16_t *base, vuint8mf8_t bindex, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f16mf4x5 (float16_t *base, vuint8mf8_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f16mf4x6 (float16_t *base, vuint8mf8_t bindex, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f16mf4x7 (float16_t *base, vuint8mf8_t bindex, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f16mf4x8 (float16_t *base, vuint8mf8_t bindex, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f16mf2x2 (float16_t *base, vuint8mf4_t bindex, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_f16mf2x3 (float16_t *base, vuint8mf4_t bindex, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_f16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f16mf2x4 (float16_t *base, vuint8mf4_t bindex, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f16mf2x5 (float16_t *base, vuint8mf4_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f16mf2x6 (float16_t *base, vuint8mf4_t bindex, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f16mf2x7 (float16_t *base, vuint8mf4_t bindex, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f16mf2x8 (float16_t *base, vuint8mf4_t bindex, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f16m1x2 (float16_t *base, vuint8mf2_t bindex, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_f16m1x3 (float16_t *base, vuint8mf2_t bindex, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_f16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f16m1x4 (float16_t *base, vuint8mf2_t bindex, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f16m1x5 (float16_t *base, vuint8mf2_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f16m1x6 (float16_t *base, vuint8mf2_t bindex, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f16m1x7 (float16_t *base, vuint8mf2_t bindex, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f16m1x8 (float16_t *base, vuint8mf2_t bindex, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f16mf4x2 (float16_t *base, vuint16mf4_t bindex, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f16mf4x4 (float16_t *base, vuint16mf4_t bindex, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f16mf4x5 (float16_t *base, vuint16mf4_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f16mf4x6 (float16_t *base, vuint16mf4_t bindex, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f16mf4x7 (float16_t *base, vuint16mf4_t bindex, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f16mf4x8 (float16_t *base, vuint16mf4_t bindex, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f16mf2x2 (float16_t *base, vuint16mf2_t bindex, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_f16mf2x3 (float16_t *base, vuint16mf2_t bindex, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_f16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f16mf2x4 (float16_t *base, vuint16mf2_t bindex, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f16mf2x5 (float16_t *base, vuint16mf2_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f16mf2x6 (float16_t *base, vuint16mf2_t bindex, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f16mf2x7 (float16_t *base, vuint16mf2_t bindex, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f16mf2x8 (float16_t *base, vuint16mf2_t bindex, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f16m1x2 (float16_t *base, vuint16m1_t bindex, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_f16m1x3 (float16_t *base, vuint16m1_t bindex, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_f16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f16m1x4 (float16_t *base, vuint16m1_t bindex, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f16m1x5 (float16_t *base, vuint16m1_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f16m1x6 (float16_t *base, vuint16m1_t bindex, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f16m1x7 (float16_t *base, vuint16m1_t bindex, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f16m1x8 (float16_t *base, vuint16m1_t bindex, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f16mf4x2 (float16_t *base, vuint32mf2_t bindex, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f16mf4x4 (float16_t *base, vuint32mf2_t bindex, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16mf4x5 (float16_t *base, vuint32mf2_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f16mf4x6 (float16_t *base, vuint32mf2_t bindex, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f16mf4x7 (float16_t *base, vuint32mf2_t bindex, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f16mf4x8 (float16_t *base, vuint32mf2_t bindex, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f16mf2x2 (float16_t *base, vuint32m1_t bindex, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_f16mf2x3 (float16_t *base, vuint32m1_t bindex, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_f16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f16mf2x4 (float16_t *base, vuint32m1_t bindex, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16mf2x5 (float16_t *base, vuint32m1_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f16mf2x6 (float16_t *base, vuint32m1_t bindex, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f16mf2x7 (float16_t *base, vuint32m1_t bindex, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f16mf2x8 (float16_t *base, vuint32m1_t bindex, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f16m1x2 (float16_t *base, vuint32m2_t bindex, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_f16m1x3 (float16_t *base, vuint32m2_t bindex, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_f16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f16m1x4 (float16_t *base, vuint32m2_t bindex, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16m1x5 (float16_t *base, vuint32m2_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f16m1x6 (float16_t *base, vuint32m2_t bindex, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f16m1x7 (float16_t *base, vuint32m2_t bindex, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f16m1x8 (float16_t *base, vuint32m2_t bindex, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f16mf4x2 (float16_t *base, vuint64m1_t bindex, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f16mf4x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f16mf4x4 (float16_t *base, vuint64m1_t bindex, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f16mf4x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f16mf4x5 (float16_t *base, vuint64m1_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f16mf4x6 (float16_t *base, vuint64m1_t bindex, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f16mf4x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f16mf4x7 (float16_t *base, vuint64m1_t bindex, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f16mf4x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f16mf4x8 (float16_t *base, vuint64m1_t bindex, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f16mf4x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f16mf2x2 (float16_t *base, vuint64m2_t bindex, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f16mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_f16mf2x3 (float16_t *base, vuint64m2_t bindex, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_f16mf2x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f16mf2x4 (float16_t *base, vuint64m2_t bindex, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f16mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f16mf2x5 (float16_t *base, vuint64m2_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f16mf2x6 (float16_t *base, vuint64m2_t bindex, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f16mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f16mf2x7 (float16_t *base, vuint64m2_t bindex, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f16mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f16mf2x8 (float16_t *base, vuint64m2_t bindex, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f16mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f16m1x2 (float16_t *base, vuint64m4_t bindex, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f16m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_f16m1x3 (float16_t *base, vuint64m4_t bindex, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_f16m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f16m1x4 (float16_t *base, vuint64m4_t bindex, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f16m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f16m1x5 (float16_t *base, vuint64m4_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f16m1x6 (float16_t *base, vuint64m4_t bindex, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f16m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f16m1x7 (float16_t *base, vuint64m4_t bindex, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f16m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f16m1x8 (float16_t *base, vuint64m4_t bindex, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f16m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f32mf2x2 (float32_t *base, vuint8mf8_t bindex, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f32mf2x4 (float32_t *base, vuint8mf8_t bindex, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f32mf2x5 (float32_t *base, vuint8mf8_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f32mf2x6 (float32_t *base, vuint8mf8_t bindex, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f32mf2x7 (float32_t *base, vuint8mf8_t bindex, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f32mf2x8 (float32_t *base, vuint8mf8_t bindex, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f32m1x2 (float32_t *base, vuint8mf4_t bindex, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_f32m1x3 (float32_t *base, vuint8mf4_t bindex, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_f32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f32m1x4 (float32_t *base, vuint8mf4_t bindex, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f32m1x5 (float32_t *base, vuint8mf4_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f32m1x6 (float32_t *base, vuint8mf4_t bindex, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f32m1x7 (float32_t *base, vuint8mf4_t bindex, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f32m1x8 (float32_t *base, vuint8mf4_t bindex, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f32mf2x2 (float32_t *base, vuint16mf4_t bindex, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f32mf2x4 (float32_t *base, vuint16mf4_t bindex, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f32mf2x5 (float32_t *base, vuint16mf4_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f32mf2x6 (float32_t *base, vuint16mf4_t bindex, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f32mf2x7 (float32_t *base, vuint16mf4_t bindex, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f32mf2x8 (float32_t *base, vuint16mf4_t bindex, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f32m1x2 (float32_t *base, vuint16mf2_t bindex, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_f32m1x3 (float32_t *base, vuint16mf2_t bindex, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_f32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f32m1x4 (float32_t *base, vuint16mf2_t bindex, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f32m1x5 (float32_t *base, vuint16mf2_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f32m1x6 (float32_t *base, vuint16mf2_t bindex, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f32m1x7 (float32_t *base, vuint16mf2_t bindex, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f32m1x8 (float32_t *base, vuint16mf2_t bindex, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f32mf2x2 (float32_t *base, vuint32mf2_t bindex, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f32mf2x4 (float32_t *base, vuint32mf2_t bindex, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f32mf2x5 (float32_t *base, vuint32mf2_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f32mf2x6 (float32_t *base, vuint32mf2_t bindex, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f32mf2x7 (float32_t *base, vuint32mf2_t bindex, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f32mf2x8 (float32_t *base, vuint32mf2_t bindex, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f32m1x2 (float32_t *base, vuint32m1_t bindex, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_f32m1x3 (float32_t *base, vuint32m1_t bindex, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_f32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f32m1x4 (float32_t *base, vuint32m1_t bindex, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f32m1x5 (float32_t *base, vuint32m1_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f32m1x6 (float32_t *base, vuint32m1_t bindex, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f32m1x7 (float32_t *base, vuint32m1_t bindex, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f32m1x8 (float32_t *base, vuint32m1_t bindex, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f32mf2x2 (float32_t *base, vuint64m1_t bindex, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f32mf2x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f32mf2x4 (float32_t *base, vuint64m1_t bindex, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f32mf2x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f32mf2x5 (float32_t *base, vuint64m1_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f32mf2x6 (float32_t *base, vuint64m1_t bindex, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f32mf2x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f32mf2x7 (float32_t *base, vuint64m1_t bindex, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f32mf2x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f32mf2x8 (float32_t *base, vuint64m1_t bindex, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f32mf2x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f32m1x2 (float32_t *base, vuint64m2_t bindex, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f32m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_f32m1x3 (float32_t *base, vuint64m2_t bindex, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_f32m1x3
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f32m1x4 (float32_t *base, vuint64m2_t bindex, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f32m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f32m1x5 (float32_t *base, vuint64m2_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f32m1x6 (float32_t *base, vuint64m2_t bindex, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f32m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f32m1x7 (float32_t *base, vuint64m2_t bindex, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f32m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f32m1x8 (float32_t *base, vuint64m2_t bindex, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f32m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f64m1x2 (float64_t *base, vuint8mf8_t bindex, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f64m1x4 (float64_t *base, vuint8mf8_t bindex, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f64m1x5 (float64_t *base, vuint8mf8_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f64m1x6 (float64_t *base, vuint8mf8_t bindex, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f64m1x7 (float64_t *base, vuint8mf8_t bindex, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f64m1x8 (float64_t *base, vuint8mf8_t bindex, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f64m1x2 (float64_t *base, vuint16mf4_t bindex, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f64m1x4 (float64_t *base, vuint16mf4_t bindex, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f64m1x5 (float64_t *base, vuint16mf4_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f64m1x6 (float64_t *base, vuint16mf4_t bindex, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f64m1x7 (float64_t *base, vuint16mf4_t bindex, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f64m1x8 (float64_t *base, vuint16mf4_t bindex, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f64m1x2 (float64_t *base, vuint32mf2_t bindex, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f64m1x4 (float64_t *base, vuint32mf2_t bindex, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f64m1x5 (float64_t *base, vuint32mf2_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f64m1x6 (float64_t *base, vuint32mf2_t bindex, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f64m1x7 (float64_t *base, vuint32mf2_t bindex, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f64m1x8 (float64_t *base, vuint32mf2_t bindex, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f64m1x2 (float64_t *base, vuint64m1_t bindex, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f64m1x2
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f64m1x4 (float64_t *base, vuint64m1_t bindex, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f64m1x4
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f64m1x5 (float64_t *base, vuint64m1_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f64m1x6 (float64_t *base, vuint64m1_t bindex, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f64m1x6
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f64m1x7 (float64_t *base, vuint64m1_t bindex, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f64m1x7
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f64m1x8 (float64_t *base, vuint64m1_t bindex, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f64m1x8
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8mf8x2_m (vbool64_t mask, int8_t *base, vuint8mf8_t bindex, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8mf8x4_m (vbool64_t mask, int8_t *base, vuint8mf8_t bindex, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i8mf8x5_m (vbool64_t mask, int8_t *base, vuint8mf8_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i8mf8x6_m (vbool64_t mask, int8_t *base, vuint8mf8_t bindex, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i8mf8x7_m (vbool64_t mask, int8_t *base, vuint8mf8_t bindex, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i8mf8x8_m (vbool64_t mask, int8_t *base, vuint8mf8_t bindex, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8mf4x2_m (vbool32_t mask, int8_t *base, vuint8mf4_t bindex, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i8mf4x3_m (vbool32_t mask, int8_t *base, vuint8mf4_t bindex, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8mf4x4_m (vbool32_t mask, int8_t *base, vuint8mf4_t bindex, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i8mf4x5_m (vbool32_t mask, int8_t *base, vuint8mf4_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i8mf4x6_m (vbool32_t mask, int8_t *base, vuint8mf4_t bindex, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i8mf4x7_m (vbool32_t mask, int8_t *base, vuint8mf4_t bindex, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i8mf4x8_m (vbool32_t mask, int8_t *base, vuint8mf4_t bindex, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8mf2x2_m (vbool16_t mask, int8_t *base, vuint8mf2_t bindex, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i8mf2x3_m (vbool16_t mask, int8_t *base, vuint8mf2_t bindex, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8mf2x4_m (vbool16_t mask, int8_t *base, vuint8mf2_t bindex, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i8mf2x5_m (vbool16_t mask, int8_t *base, vuint8mf2_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i8mf2x6_m (vbool16_t mask, int8_t *base, vuint8mf2_t bindex, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i8mf2x7_m (vbool16_t mask, int8_t *base, vuint8mf2_t bindex, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i8mf2x8_m (vbool16_t mask, int8_t *base, vuint8mf2_t bindex, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8m1x2_m (vbool8_t mask, int8_t *base, vuint8m1_t bindex, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i8m1x3_m (vbool8_t mask, int8_t *base, vuint8m1_t bindex, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8m1x4_m (vbool8_t mask, int8_t *base, vuint8m1_t bindex, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i8m1x5_m (vbool8_t mask, int8_t *base, vuint8m1_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i8m1x6_m (vbool8_t mask, int8_t *base, vuint8m1_t bindex, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i8m1x7_m (vbool8_t mask, int8_t *base, vuint8m1_t bindex, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i8m1x8_m (vbool8_t mask, int8_t *base, vuint8m1_t bindex, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8m2x2_m (vbool4_t mask, int8_t *base, vuint8m2_t bindex, vint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i8m2x3_m (vbool4_t mask, int8_t *base, vuint8m2_t bindex, vint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i8m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i8m2x4_m (vbool4_t mask, int8_t *base, vuint8m2_t bindex, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i8m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i8m4x2_m (vbool2_t mask, int8_t *base, vuint8m4_t bindex, vint8m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i8m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8mf8x2_m (vbool64_t mask, int8_t *base, vuint16mf4_t bindex, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8mf8x4_m (vbool64_t mask, int8_t *base, vuint16mf4_t bindex, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i8mf8x5_m (vbool64_t mask, int8_t *base, vuint16mf4_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i8mf8x6_m (vbool64_t mask, int8_t *base, vuint16mf4_t bindex, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i8mf8x7_m (vbool64_t mask, int8_t *base, vuint16mf4_t bindex, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i8mf8x8_m (vbool64_t mask, int8_t *base, vuint16mf4_t bindex, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8mf4x2_m (vbool32_t mask, int8_t *base, vuint16mf2_t bindex, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i8mf4x3_m (vbool32_t mask, int8_t *base, vuint16mf2_t bindex, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8mf4x4_m (vbool32_t mask, int8_t *base, vuint16mf2_t bindex, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i8mf4x5_m (vbool32_t mask, int8_t *base, vuint16mf2_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i8mf4x6_m (vbool32_t mask, int8_t *base, vuint16mf2_t bindex, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i8mf4x7_m (vbool32_t mask, int8_t *base, vuint16mf2_t bindex, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i8mf4x8_m (vbool32_t mask, int8_t *base, vuint16mf2_t bindex, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8mf2x2_m (vbool16_t mask, int8_t *base, vuint16m1_t bindex, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i8mf2x3_m (vbool16_t mask, int8_t *base, vuint16m1_t bindex, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8mf2x4_m (vbool16_t mask, int8_t *base, vuint16m1_t bindex, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i8mf2x5_m (vbool16_t mask, int8_t *base, vuint16m1_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i8mf2x6_m (vbool16_t mask, int8_t *base, vuint16m1_t bindex, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i8mf2x7_m (vbool16_t mask, int8_t *base, vuint16m1_t bindex, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i8mf2x8_m (vbool16_t mask, int8_t *base, vuint16m1_t bindex, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8m1x2_m (vbool8_t mask, int8_t *base, vuint16m2_t bindex, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i8m1x3_m (vbool8_t mask, int8_t *base, vuint16m2_t bindex, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8m1x4_m (vbool8_t mask, int8_t *base, vuint16m2_t bindex, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i8m1x5_m (vbool8_t mask, int8_t *base, vuint16m2_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i8m1x6_m (vbool8_t mask, int8_t *base, vuint16m2_t bindex, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i8m1x7_m (vbool8_t mask, int8_t *base, vuint16m2_t bindex, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i8m1x8_m (vbool8_t mask, int8_t *base, vuint16m2_t bindex, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8m2x2_m (vbool4_t mask, int8_t *base, vuint16m4_t bindex, vint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i8m2x3_m (vbool4_t mask, int8_t *base, vuint16m4_t bindex, vint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i8m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i8m2x4_m (vbool4_t mask, int8_t *base, vuint16m4_t bindex, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i8m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i8m4x2_m (vbool2_t mask, int8_t *base, vuint16m8_t bindex, vint8m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i8m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8mf8x2_m (vbool64_t mask, int8_t *base, vuint32mf2_t bindex, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8mf8x4_m (vbool64_t mask, int8_t *base, vuint32mf2_t bindex, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf8x5_m (vbool64_t mask, int8_t *base, vuint32mf2_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i8mf8x6_m (vbool64_t mask, int8_t *base, vuint32mf2_t bindex, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i8mf8x7_m (vbool64_t mask, int8_t *base, vuint32mf2_t bindex, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i8mf8x8_m (vbool64_t mask, int8_t *base, vuint32mf2_t bindex, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8mf4x2_m (vbool32_t mask, int8_t *base, vuint32m1_t bindex, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i8mf4x3_m (vbool32_t mask, int8_t *base, vuint32m1_t bindex, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8mf4x4_m (vbool32_t mask, int8_t *base, vuint32m1_t bindex, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf4x5_m (vbool32_t mask, int8_t *base, vuint32m1_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i8mf4x6_m (vbool32_t mask, int8_t *base, vuint32m1_t bindex, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i8mf4x7_m (vbool32_t mask, int8_t *base, vuint32m1_t bindex, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i8mf4x8_m (vbool32_t mask, int8_t *base, vuint32m1_t bindex, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8mf2x2_m (vbool16_t mask, int8_t *base, vuint32m2_t bindex, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i8mf2x3_m (vbool16_t mask, int8_t *base, vuint32m2_t bindex, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8mf2x4_m (vbool16_t mask, int8_t *base, vuint32m2_t bindex, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf2x5_m (vbool16_t mask, int8_t *base, vuint32m2_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i8mf2x6_m (vbool16_t mask, int8_t *base, vuint32m2_t bindex, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i8mf2x7_m (vbool16_t mask, int8_t *base, vuint32m2_t bindex, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i8mf2x8_m (vbool16_t mask, int8_t *base, vuint32m2_t bindex, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8m1x2_m (vbool8_t mask, int8_t *base, vuint32m4_t bindex, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i8m1x3_m (vbool8_t mask, int8_t *base, vuint32m4_t bindex, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8m1x4_m (vbool8_t mask, int8_t *base, vuint32m4_t bindex, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8m1x5_m (vbool8_t mask, int8_t *base, vuint32m4_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i8m1x6_m (vbool8_t mask, int8_t *base, vuint32m4_t bindex, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i8m1x7_m (vbool8_t mask, int8_t *base, vuint32m4_t bindex, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i8m1x8_m (vbool8_t mask, int8_t *base, vuint32m4_t bindex, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i8m2x2_m (vbool4_t mask, int8_t *base, vuint32m8_t bindex, vint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i8m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i8m2x3_m (vbool4_t mask, int8_t *base, vuint32m8_t bindex, vint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i8m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i8m2x4_m (vbool4_t mask, int8_t *base, vuint32m8_t bindex, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i8m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i8mf8x2_m (vbool64_t mask, int8_t *base, vuint64m1_t bindex, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i8mf8x4_m (vbool64_t mask, int8_t *base, vuint64m1_t bindex, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i8mf8x5_m (vbool64_t mask, int8_t *base, vuint64m1_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i8mf8x6_m (vbool64_t mask, int8_t *base, vuint64m1_t bindex, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i8mf8x7_m (vbool64_t mask, int8_t *base, vuint64m1_t bindex, vint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i8mf8x8_m (vbool64_t mask, int8_t *base, vuint64m1_t bindex, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i8mf4x2_m (vbool32_t mask, int8_t *base, vuint64m2_t bindex, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i8mf4x3_m (vbool32_t mask, int8_t *base, vuint64m2_t bindex, vint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i8mf4x4_m (vbool32_t mask, int8_t *base, vuint64m2_t bindex, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i8mf4x5_m (vbool32_t mask, int8_t *base, vuint64m2_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i8mf4x6_m (vbool32_t mask, int8_t *base, vuint64m2_t bindex, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i8mf4x7_m (vbool32_t mask, int8_t *base, vuint64m2_t bindex, vint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i8mf4x8_m (vbool32_t mask, int8_t *base, vuint64m2_t bindex, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i8mf2x2_m (vbool16_t mask, int8_t *base, vuint64m4_t bindex, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i8mf2x3_m (vbool16_t mask, int8_t *base, vuint64m4_t bindex, vint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i8mf2x4_m (vbool16_t mask, int8_t *base, vuint64m4_t bindex, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i8mf2x5_m (vbool16_t mask, int8_t *base, vuint64m4_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i8mf2x6_m (vbool16_t mask, int8_t *base, vuint64m4_t bindex, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i8mf2x7_m (vbool16_t mask, int8_t *base, vuint64m4_t bindex, vint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i8mf2x8_m (vbool16_t mask, int8_t *base, vuint64m4_t bindex, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i8m1x2_m (vbool8_t mask, int8_t *base, vuint64m8_t bindex, vint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i8m1x3_m (vbool8_t mask, int8_t *base, vuint64m8_t bindex, vint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i8m1x4_m (vbool8_t mask, int8_t *base, vuint64m8_t bindex, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i8m1x5_m (vbool8_t mask, int8_t *base, vuint64m8_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i8m1x6_m (vbool8_t mask, int8_t *base, vuint64m8_t bindex, vint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i8m1x7_m (vbool8_t mask, int8_t *base, vuint64m8_t bindex, vint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i8m1x8_m (vbool8_t mask, int8_t *base, vuint64m8_t bindex, vint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16mf4x2_m (vbool64_t mask, int16_t *base, vuint8mf8_t bindex, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i16mf4x4_m (vbool64_t mask, int16_t *base, vuint8mf8_t bindex, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i16mf4x5_m (vbool64_t mask, int16_t *base, vuint8mf8_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i16mf4x6_m (vbool64_t mask, int16_t *base, vuint8mf8_t bindex, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i16mf4x7_m (vbool64_t mask, int16_t *base, vuint8mf8_t bindex, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i16mf4x8_m (vbool64_t mask, int16_t *base, vuint8mf8_t bindex, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16mf2x2_m (vbool32_t mask, int16_t *base, vuint8mf4_t bindex, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i16mf2x3_m (vbool32_t mask, int16_t *base, vuint8mf4_t bindex, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i16mf2x4_m (vbool32_t mask, int16_t *base, vuint8mf4_t bindex, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i16mf2x5_m (vbool32_t mask, int16_t *base, vuint8mf4_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i16mf2x6_m (vbool32_t mask, int16_t *base, vuint8mf4_t bindex, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i16mf2x7_m (vbool32_t mask, int16_t *base, vuint8mf4_t bindex, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i16mf2x8_m (vbool32_t mask, int16_t *base, vuint8mf4_t bindex, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16m1x2_m (vbool16_t mask, int16_t *base, vuint8mf2_t bindex, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i16m1x3_m (vbool16_t mask, int16_t *base, vuint8mf2_t bindex, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i16m1x4_m (vbool16_t mask, int16_t *base, vuint8mf2_t bindex, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i16m1x5_m (vbool16_t mask, int16_t *base, vuint8mf2_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i16m1x6_m (vbool16_t mask, int16_t *base, vuint8mf2_t bindex, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i16m1x7_m (vbool16_t mask, int16_t *base, vuint8mf2_t bindex, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i16m1x8_m (vbool16_t mask, int16_t *base, vuint8mf2_t bindex, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16m2x2_m (vbool8_t mask, int16_t *base, vuint8m1_t bindex, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i16m2x3_m (vbool8_t mask, int16_t *base, vuint8m1_t bindex, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i16m2x4_m (vbool8_t mask, int16_t *base, vuint8m1_t bindex, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i16m4x2_m (vbool4_t mask, int16_t *base, vuint8m2_t bindex, vint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i16m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16mf4x2_m (vbool64_t mask, int16_t *base, vuint16mf4_t bindex, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i16mf4x4_m (vbool64_t mask, int16_t *base, vuint16mf4_t bindex, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i16mf4x5_m (vbool64_t mask, int16_t *base, vuint16mf4_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i16mf4x6_m (vbool64_t mask, int16_t *base, vuint16mf4_t bindex, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i16mf4x7_m (vbool64_t mask, int16_t *base, vuint16mf4_t bindex, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i16mf4x8_m (vbool64_t mask, int16_t *base, vuint16mf4_t bindex, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16mf2x2_m (vbool32_t mask, int16_t *base, vuint16mf2_t bindex, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i16mf2x3_m (vbool32_t mask, int16_t *base, vuint16mf2_t bindex, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i16mf2x4_m (vbool32_t mask, int16_t *base, vuint16mf2_t bindex, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i16mf2x5_m (vbool32_t mask, int16_t *base, vuint16mf2_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i16mf2x6_m (vbool32_t mask, int16_t *base, vuint16mf2_t bindex, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i16mf2x7_m (vbool32_t mask, int16_t *base, vuint16mf2_t bindex, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i16mf2x8_m (vbool32_t mask, int16_t *base, vuint16mf2_t bindex, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16m1x2_m (vbool16_t mask, int16_t *base, vuint16m1_t bindex, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i16m1x3_m (vbool16_t mask, int16_t *base, vuint16m1_t bindex, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i16m1x4_m (vbool16_t mask, int16_t *base, vuint16m1_t bindex, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i16m1x5_m (vbool16_t mask, int16_t *base, vuint16m1_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i16m1x6_m (vbool16_t mask, int16_t *base, vuint16m1_t bindex, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i16m1x7_m (vbool16_t mask, int16_t *base, vuint16m1_t bindex, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i16m1x8_m (vbool16_t mask, int16_t *base, vuint16m1_t bindex, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16m2x2_m (vbool8_t mask, int16_t *base, vuint16m2_t bindex, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i16m2x3_m (vbool8_t mask, int16_t *base, vuint16m2_t bindex, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i16m2x4_m (vbool8_t mask, int16_t *base, vuint16m2_t bindex, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i16m4x2_m (vbool4_t mask, int16_t *base, vuint16m4_t bindex, vint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i16m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16mf4x2_m (vbool64_t mask, int16_t *base, vuint32mf2_t bindex, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i16mf4x4_m (vbool64_t mask, int16_t *base, vuint32mf2_t bindex, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16mf4x5_m (vbool64_t mask, int16_t *base, vuint32mf2_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i16mf4x6_m (vbool64_t mask, int16_t *base, vuint32mf2_t bindex, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i16mf4x7_m (vbool64_t mask, int16_t *base, vuint32mf2_t bindex, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i16mf4x8_m (vbool64_t mask, int16_t *base, vuint32mf2_t bindex, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16mf2x2_m (vbool32_t mask, int16_t *base, vuint32m1_t bindex, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i16mf2x3_m (vbool32_t mask, int16_t *base, vuint32m1_t bindex, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i16mf2x4_m (vbool32_t mask, int16_t *base, vuint32m1_t bindex, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16mf2x5_m (vbool32_t mask, int16_t *base, vuint32m1_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i16mf2x6_m (vbool32_t mask, int16_t *base, vuint32m1_t bindex, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i16mf2x7_m (vbool32_t mask, int16_t *base, vuint32m1_t bindex, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i16mf2x8_m (vbool32_t mask, int16_t *base, vuint32m1_t bindex, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16m1x2_m (vbool16_t mask, int16_t *base, vuint32m2_t bindex, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i16m1x3_m (vbool16_t mask, int16_t *base, vuint32m2_t bindex, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i16m1x4_m (vbool16_t mask, int16_t *base, vuint32m2_t bindex, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16m1x5_m (vbool16_t mask, int16_t *base, vuint32m2_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i16m1x6_m (vbool16_t mask, int16_t *base, vuint32m2_t bindex, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i16m1x7_m (vbool16_t mask, int16_t *base, vuint32m2_t bindex, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i16m1x8_m (vbool16_t mask, int16_t *base, vuint32m2_t bindex, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16m2x2_m (vbool8_t mask, int16_t *base, vuint32m4_t bindex, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i16m2x3_m (vbool8_t mask, int16_t *base, vuint32m4_t bindex, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i16m2x4_m (vbool8_t mask, int16_t *base, vuint32m4_t bindex, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i16m4x2_m (vbool4_t mask, int16_t *base, vuint32m8_t bindex, vint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i16m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i16mf4x2_m (vbool64_t mask, int16_t *base, vuint64m1_t bindex, vint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i16mf4x4_m (vbool64_t mask, int16_t *base, vuint64m1_t bindex, vint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i16mf4x5_m (vbool64_t mask, int16_t *base, vuint64m1_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i16mf4x6_m (vbool64_t mask, int16_t *base, vuint64m1_t bindex, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i16mf4x7_m (vbool64_t mask, int16_t *base, vuint64m1_t bindex, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i16mf4x8_m (vbool64_t mask, int16_t *base, vuint64m1_t bindex, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i16mf2x2_m (vbool32_t mask, int16_t *base, vuint64m2_t bindex, vint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i16mf2x3_m (vbool32_t mask, int16_t *base, vuint64m2_t bindex, vint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i16mf2x4_m (vbool32_t mask, int16_t *base, vuint64m2_t bindex, vint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i16mf2x5_m (vbool32_t mask, int16_t *base, vuint64m2_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i16mf2x6_m (vbool32_t mask, int16_t *base, vuint64m2_t bindex, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i16mf2x7_m (vbool32_t mask, int16_t *base, vuint64m2_t bindex, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i16mf2x8_m (vbool32_t mask, int16_t *base, vuint64m2_t bindex, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i16m1x2_m (vbool16_t mask, int16_t *base, vuint64m4_t bindex, vint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i16m1x3_m (vbool16_t mask, int16_t *base, vuint64m4_t bindex, vint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i16m1x4_m (vbool16_t mask, int16_t *base, vuint64m4_t bindex, vint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i16m1x5_m (vbool16_t mask, int16_t *base, vuint64m4_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i16m1x6_m (vbool16_t mask, int16_t *base, vuint64m4_t bindex, vint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i16m1x7_m (vbool16_t mask, int16_t *base, vuint64m4_t bindex, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i16m1x8_m (vbool16_t mask, int16_t *base, vuint64m4_t bindex, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i16m2x2_m (vbool8_t mask, int16_t *base, vuint64m8_t bindex, vint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i16m2x3_m (vbool8_t mask, int16_t *base, vuint64m8_t bindex, vint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i16m2x4_m (vbool8_t mask, int16_t *base, vuint64m8_t bindex, vint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i32mf2x2_m (vbool64_t mask, int32_t *base, vuint8mf8_t bindex, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i32mf2x4_m (vbool64_t mask, int32_t *base, vuint8mf8_t bindex, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i32mf2x5_m (vbool64_t mask, int32_t *base, vuint8mf8_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i32mf2x6_m (vbool64_t mask, int32_t *base, vuint8mf8_t bindex, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i32mf2x7_m (vbool64_t mask, int32_t *base, vuint8mf8_t bindex, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i32mf2x8_m (vbool64_t mask, int32_t *base, vuint8mf8_t bindex, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i32m1x2_m (vbool32_t mask, int32_t *base, vuint8mf4_t bindex, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i32m1x3_m (vbool32_t mask, int32_t *base, vuint8mf4_t bindex, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i32m1x4_m (vbool32_t mask, int32_t *base, vuint8mf4_t bindex, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i32m1x5_m (vbool32_t mask, int32_t *base, vuint8mf4_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i32m1x6_m (vbool32_t mask, int32_t *base, vuint8mf4_t bindex, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i32m1x7_m (vbool32_t mask, int32_t *base, vuint8mf4_t bindex, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i32m1x8_m (vbool32_t mask, int32_t *base, vuint8mf4_t bindex, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i32m2x2_m (vbool16_t mask, int32_t *base, vuint8mf2_t bindex, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i32m2x3_m (vbool16_t mask, int32_t *base, vuint8mf2_t bindex, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i32m2x4_m (vbool16_t mask, int32_t *base, vuint8mf2_t bindex, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i32m4x2_m (vbool8_t mask, int32_t *base, vuint8m1_t bindex, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i32mf2x2_m (vbool64_t mask, int32_t *base, vuint16mf4_t bindex, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i32mf2x4_m (vbool64_t mask, int32_t *base, vuint16mf4_t bindex, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i32mf2x5_m (vbool64_t mask, int32_t *base, vuint16mf4_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i32mf2x6_m (vbool64_t mask, int32_t *base, vuint16mf4_t bindex, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i32mf2x7_m (vbool64_t mask, int32_t *base, vuint16mf4_t bindex, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i32mf2x8_m (vbool64_t mask, int32_t *base, vuint16mf4_t bindex, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i32m1x2_m (vbool32_t mask, int32_t *base, vuint16mf2_t bindex, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i32m1x3_m (vbool32_t mask, int32_t *base, vuint16mf2_t bindex, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i32m1x4_m (vbool32_t mask, int32_t *base, vuint16mf2_t bindex, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i32m1x5_m (vbool32_t mask, int32_t *base, vuint16mf2_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i32m1x6_m (vbool32_t mask, int32_t *base, vuint16mf2_t bindex, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i32m1x7_m (vbool32_t mask, int32_t *base, vuint16mf2_t bindex, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i32m1x8_m (vbool32_t mask, int32_t *base, vuint16mf2_t bindex, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i32m2x2_m (vbool16_t mask, int32_t *base, vuint16m1_t bindex, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i32m2x3_m (vbool16_t mask, int32_t *base, vuint16m1_t bindex, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i32m2x4_m (vbool16_t mask, int32_t *base, vuint16m1_t bindex, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i32m4x2_m (vbool8_t mask, int32_t *base, vuint16m2_t bindex, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i32mf2x2_m (vbool64_t mask, int32_t *base, vuint32mf2_t bindex, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i32mf2x4_m (vbool64_t mask, int32_t *base, vuint32mf2_t bindex, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i32mf2x5_m (vbool64_t mask, int32_t *base, vuint32mf2_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i32mf2x6_m (vbool64_t mask, int32_t *base, vuint32mf2_t bindex, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i32mf2x7_m (vbool64_t mask, int32_t *base, vuint32mf2_t bindex, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i32mf2x8_m (vbool64_t mask, int32_t *base, vuint32mf2_t bindex, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i32m1x2_m (vbool32_t mask, int32_t *base, vuint32m1_t bindex, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i32m1x3_m (vbool32_t mask, int32_t *base, vuint32m1_t bindex, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i32m1x4_m (vbool32_t mask, int32_t *base, vuint32m1_t bindex, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i32m1x5_m (vbool32_t mask, int32_t *base, vuint32m1_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i32m1x6_m (vbool32_t mask, int32_t *base, vuint32m1_t bindex, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i32m1x7_m (vbool32_t mask, int32_t *base, vuint32m1_t bindex, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i32m1x8_m (vbool32_t mask, int32_t *base, vuint32m1_t bindex, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i32m2x2_m (vbool16_t mask, int32_t *base, vuint32m2_t bindex, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i32m2x3_m (vbool16_t mask, int32_t *base, vuint32m2_t bindex, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i32m2x4_m (vbool16_t mask, int32_t *base, vuint32m2_t bindex, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i32m4x2_m (vbool8_t mask, int32_t *base, vuint32m4_t bindex, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i32mf2x2_m (vbool64_t mask, int32_t *base, vuint64m1_t bindex, vint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i32mf2x4_m (vbool64_t mask, int32_t *base, vuint64m1_t bindex, vint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i32mf2x5_m (vbool64_t mask, int32_t *base, vuint64m1_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i32mf2x6_m (vbool64_t mask, int32_t *base, vuint64m1_t bindex, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i32mf2x7_m (vbool64_t mask, int32_t *base, vuint64m1_t bindex, vint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i32mf2x8_m (vbool64_t mask, int32_t *base, vuint64m1_t bindex, vint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i32m1x2_m (vbool32_t mask, int32_t *base, vuint64m2_t bindex, vint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i32m1x3_m (vbool32_t mask, int32_t *base, vuint64m2_t bindex, vint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i32m1x4_m (vbool32_t mask, int32_t *base, vuint64m2_t bindex, vint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i32m1x5_m (vbool32_t mask, int32_t *base, vuint64m2_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i32m1x6_m (vbool32_t mask, int32_t *base, vuint64m2_t bindex, vint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i32m1x7_m (vbool32_t mask, int32_t *base, vuint64m2_t bindex, vint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i32m1x8_m (vbool32_t mask, int32_t *base, vuint64m2_t bindex, vint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i32m2x2_m (vbool16_t mask, int32_t *base, vuint64m4_t bindex, vint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i32m2x3_m (vbool16_t mask, int32_t *base, vuint64m4_t bindex, vint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i32m2x4_m (vbool16_t mask, int32_t *base, vuint64m4_t bindex, vint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i32m4x2_m (vbool8_t mask, int32_t *base, vuint64m8_t bindex, vint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i64m1x2_m (vbool64_t mask, int64_t *base, vuint8mf8_t bindex, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i64m1x4_m (vbool64_t mask, int64_t *base, vuint8mf8_t bindex, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_i64m1x5_m (vbool64_t mask, int64_t *base, vuint8mf8_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_i64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_i64m1x6_m (vbool64_t mask, int64_t *base, vuint8mf8_t bindex, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_i64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_i64m1x7_m (vbool64_t mask, int64_t *base, vuint8mf8_t bindex, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_i64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_i64m1x8_m (vbool64_t mask, int64_t *base, vuint8mf8_t bindex, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_i64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i64m2x2_m (vbool32_t mask, int64_t *base, vuint8mf4_t bindex, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_i64m2x3_m (vbool32_t mask, int64_t *base, vuint8mf4_t bindex, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_i64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_i64m2x4_m (vbool32_t mask, int64_t *base, vuint8mf4_t bindex, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_i64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_i64m4x2_m (vbool16_t mask, int64_t *base, vuint8mf2_t bindex, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_i64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i64m1x2_m (vbool64_t mask, int64_t *base, vuint16mf4_t bindex, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i64m1x4_m (vbool64_t mask, int64_t *base, vuint16mf4_t bindex, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_i64m1x5_m (vbool64_t mask, int64_t *base, vuint16mf4_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_i64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_i64m1x6_m (vbool64_t mask, int64_t *base, vuint16mf4_t bindex, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_i64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_i64m1x7_m (vbool64_t mask, int64_t *base, vuint16mf4_t bindex, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_i64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_i64m1x8_m (vbool64_t mask, int64_t *base, vuint16mf4_t bindex, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_i64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i64m2x2_m (vbool32_t mask, int64_t *base, vuint16mf2_t bindex, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_i64m2x3_m (vbool32_t mask, int64_t *base, vuint16mf2_t bindex, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_i64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_i64m2x4_m (vbool32_t mask, int64_t *base, vuint16mf2_t bindex, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_i64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_i64m4x2_m (vbool16_t mask, int64_t *base, vuint16m1_t bindex, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_i64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i64m1x2_m (vbool64_t mask, int64_t *base, vuint32mf2_t bindex, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i64m1x4_m (vbool64_t mask, int64_t *base, vuint32mf2_t bindex, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i64m1x5_m (vbool64_t mask, int64_t *base, vuint32mf2_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_i64m1x6_m (vbool64_t mask, int64_t *base, vuint32mf2_t bindex, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_i64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_i64m1x7_m (vbool64_t mask, int64_t *base, vuint32mf2_t bindex, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_i64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_i64m1x8_m (vbool64_t mask, int64_t *base, vuint32mf2_t bindex, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_i64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i64m2x2_m (vbool32_t mask, int64_t *base, vuint32m1_t bindex, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_i64m2x3_m (vbool32_t mask, int64_t *base, vuint32m1_t bindex, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_i64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_i64m2x4_m (vbool32_t mask, int64_t *base, vuint32m1_t bindex, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_i64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_i64m4x2_m (vbool16_t mask, int64_t *base, vuint32m2_t bindex, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_i64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i64m1x2_m (vbool64_t mask, int64_t *base, vuint64m1_t bindex, vint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i64m1x4_m (vbool64_t mask, int64_t *base, vuint64m1_t bindex, vint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_i64m1x5_m (vbool64_t mask, int64_t *base, vuint64m1_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_i64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_i64m1x6_m (vbool64_t mask, int64_t *base, vuint64m1_t bindex, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_i64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_i64m1x7_m (vbool64_t mask, int64_t *base, vuint64m1_t bindex, vint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_i64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_i64m1x8_m (vbool64_t mask, int64_t *base, vuint64m1_t bindex, vint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_i64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i64m2x2_m (vbool32_t mask, int64_t *base, vuint64m2_t bindex, vint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_i64m2x3_m (vbool32_t mask, int64_t *base, vuint64m2_t bindex, vint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_i64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_i64m2x4_m (vbool32_t mask, int64_t *base, vuint64m2_t bindex, vint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_i64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_i64m4x2_m (vbool16_t mask, int64_t *base, vuint64m4_t bindex, vint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_i64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8mf8x2_m (vbool64_t mask, uint8_t *base, vuint8mf8_t bindex, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8mf8x4_m (vbool64_t mask, uint8_t *base, vuint8mf8_t bindex, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u8mf8x5_m (vbool64_t mask, uint8_t *base, vuint8mf8_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u8mf8x6_m (vbool64_t mask, uint8_t *base, vuint8mf8_t bindex, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u8mf8x7_m (vbool64_t mask, uint8_t *base, vuint8mf8_t bindex, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u8mf8x8_m (vbool64_t mask, uint8_t *base, vuint8mf8_t bindex, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8mf4x2_m (vbool32_t mask, uint8_t *base, vuint8mf4_t bindex, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u8mf4x3_m (vbool32_t mask, uint8_t *base, vuint8mf4_t bindex, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8mf4x4_m (vbool32_t mask, uint8_t *base, vuint8mf4_t bindex, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u8mf4x5_m (vbool32_t mask, uint8_t *base, vuint8mf4_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u8mf4x6_m (vbool32_t mask, uint8_t *base, vuint8mf4_t bindex, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u8mf4x7_m (vbool32_t mask, uint8_t *base, vuint8mf4_t bindex, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u8mf4x8_m (vbool32_t mask, uint8_t *base, vuint8mf4_t bindex, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8mf2x2_m (vbool16_t mask, uint8_t *base, vuint8mf2_t bindex, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u8mf2x3_m (vbool16_t mask, uint8_t *base, vuint8mf2_t bindex, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8mf2x4_m (vbool16_t mask, uint8_t *base, vuint8mf2_t bindex, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u8mf2x5_m (vbool16_t mask, uint8_t *base, vuint8mf2_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u8mf2x6_m (vbool16_t mask, uint8_t *base, vuint8mf2_t bindex, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u8mf2x7_m (vbool16_t mask, uint8_t *base, vuint8mf2_t bindex, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u8mf2x8_m (vbool16_t mask, uint8_t *base, vuint8mf2_t bindex, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8m1x2_m (vbool8_t mask, uint8_t *base, vuint8m1_t bindex, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u8m1x3_m (vbool8_t mask, uint8_t *base, vuint8m1_t bindex, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8m1x4_m (vbool8_t mask, uint8_t *base, vuint8m1_t bindex, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u8m1x5_m (vbool8_t mask, uint8_t *base, vuint8m1_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u8m1x6_m (vbool8_t mask, uint8_t *base, vuint8m1_t bindex, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u8m1x7_m (vbool8_t mask, uint8_t *base, vuint8m1_t bindex, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u8m1x8_m (vbool8_t mask, uint8_t *base, vuint8m1_t bindex, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8m2x2_m (vbool4_t mask, uint8_t *base, vuint8m2_t bindex, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u8m2x3_m (vbool4_t mask, uint8_t *base, vuint8m2_t bindex, vuint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u8m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u8m2x4_m (vbool4_t mask, uint8_t *base, vuint8m2_t bindex, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u8m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u8m4x2_m (vbool2_t mask, uint8_t *base, vuint8m4_t bindex, vuint8m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u8m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8mf8x2_m (vbool64_t mask, uint8_t *base, vuint16mf4_t bindex, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8mf8x4_m (vbool64_t mask, uint8_t *base, vuint16mf4_t bindex, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u8mf8x5_m (vbool64_t mask, uint8_t *base, vuint16mf4_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u8mf8x6_m (vbool64_t mask, uint8_t *base, vuint16mf4_t bindex, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u8mf8x7_m (vbool64_t mask, uint8_t *base, vuint16mf4_t bindex, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u8mf8x8_m (vbool64_t mask, uint8_t *base, vuint16mf4_t bindex, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8mf4x2_m (vbool32_t mask, uint8_t *base, vuint16mf2_t bindex, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u8mf4x3_m (vbool32_t mask, uint8_t *base, vuint16mf2_t bindex, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8mf4x4_m (vbool32_t mask, uint8_t *base, vuint16mf2_t bindex, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u8mf4x5_m (vbool32_t mask, uint8_t *base, vuint16mf2_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u8mf4x6_m (vbool32_t mask, uint8_t *base, vuint16mf2_t bindex, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u8mf4x7_m (vbool32_t mask, uint8_t *base, vuint16mf2_t bindex, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u8mf4x8_m (vbool32_t mask, uint8_t *base, vuint16mf2_t bindex, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8mf2x2_m (vbool16_t mask, uint8_t *base, vuint16m1_t bindex, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u8mf2x3_m (vbool16_t mask, uint8_t *base, vuint16m1_t bindex, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8mf2x4_m (vbool16_t mask, uint8_t *base, vuint16m1_t bindex, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u8mf2x5_m (vbool16_t mask, uint8_t *base, vuint16m1_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u8mf2x6_m (vbool16_t mask, uint8_t *base, vuint16m1_t bindex, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u8mf2x7_m (vbool16_t mask, uint8_t *base, vuint16m1_t bindex, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u8mf2x8_m (vbool16_t mask, uint8_t *base, vuint16m1_t bindex, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8m1x2_m (vbool8_t mask, uint8_t *base, vuint16m2_t bindex, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u8m1x3_m (vbool8_t mask, uint8_t *base, vuint16m2_t bindex, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8m1x4_m (vbool8_t mask, uint8_t *base, vuint16m2_t bindex, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u8m1x5_m (vbool8_t mask, uint8_t *base, vuint16m2_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u8m1x6_m (vbool8_t mask, uint8_t *base, vuint16m2_t bindex, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u8m1x7_m (vbool8_t mask, uint8_t *base, vuint16m2_t bindex, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u8m1x8_m (vbool8_t mask, uint8_t *base, vuint16m2_t bindex, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8m2x2_m (vbool4_t mask, uint8_t *base, vuint16m4_t bindex, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u8m2x3_m (vbool4_t mask, uint8_t *base, vuint16m4_t bindex, vuint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u8m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u8m2x4_m (vbool4_t mask, uint8_t *base, vuint16m4_t bindex, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u8m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u8m4x2_m (vbool2_t mask, uint8_t *base, vuint16m8_t bindex, vuint8m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u8m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8mf8x2_m (vbool64_t mask, uint8_t *base, vuint32mf2_t bindex, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8mf8x4_m (vbool64_t mask, uint8_t *base, vuint32mf2_t bindex, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf8x5_m (vbool64_t mask, uint8_t *base, vuint32mf2_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u8mf8x6_m (vbool64_t mask, uint8_t *base, vuint32mf2_t bindex, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u8mf8x7_m (vbool64_t mask, uint8_t *base, vuint32mf2_t bindex, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u8mf8x8_m (vbool64_t mask, uint8_t *base, vuint32mf2_t bindex, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8mf4x2_m (vbool32_t mask, uint8_t *base, vuint32m1_t bindex, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u8mf4x3_m (vbool32_t mask, uint8_t *base, vuint32m1_t bindex, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8mf4x4_m (vbool32_t mask, uint8_t *base, vuint32m1_t bindex, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf4x5_m (vbool32_t mask, uint8_t *base, vuint32m1_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u8mf4x6_m (vbool32_t mask, uint8_t *base, vuint32m1_t bindex, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u8mf4x7_m (vbool32_t mask, uint8_t *base, vuint32m1_t bindex, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u8mf4x8_m (vbool32_t mask, uint8_t *base, vuint32m1_t bindex, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8mf2x2_m (vbool16_t mask, uint8_t *base, vuint32m2_t bindex, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u8mf2x3_m (vbool16_t mask, uint8_t *base, vuint32m2_t bindex, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8mf2x4_m (vbool16_t mask, uint8_t *base, vuint32m2_t bindex, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf2x5_m (vbool16_t mask, uint8_t *base, vuint32m2_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u8mf2x6_m (vbool16_t mask, uint8_t *base, vuint32m2_t bindex, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u8mf2x7_m (vbool16_t mask, uint8_t *base, vuint32m2_t bindex, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u8mf2x8_m (vbool16_t mask, uint8_t *base, vuint32m2_t bindex, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8m1x2_m (vbool8_t mask, uint8_t *base, vuint32m4_t bindex, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u8m1x3_m (vbool8_t mask, uint8_t *base, vuint32m4_t bindex, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8m1x4_m (vbool8_t mask, uint8_t *base, vuint32m4_t bindex, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8m1x5_m (vbool8_t mask, uint8_t *base, vuint32m4_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u8m1x6_m (vbool8_t mask, uint8_t *base, vuint32m4_t bindex, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u8m1x7_m (vbool8_t mask, uint8_t *base, vuint32m4_t bindex, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u8m1x8_m (vbool8_t mask, uint8_t *base, vuint32m4_t bindex, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u8m2x2_m (vbool4_t mask, uint8_t *base, vuint32m8_t bindex, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u8m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u8m2x3_m (vbool4_t mask, uint8_t *base, vuint32m8_t bindex, vuint8m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u8m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u8m2x4_m (vbool4_t mask, uint8_t *base, vuint32m8_t bindex, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u8m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u8mf8x2_m (vbool64_t mask, uint8_t *base, vuint64m1_t bindex, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u8mf8x4_m (vbool64_t mask, uint8_t *base, vuint64m1_t bindex, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u8mf8x5_m (vbool64_t mask, uint8_t *base, vuint64m1_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u8mf8x6_m (vbool64_t mask, uint8_t *base, vuint64m1_t bindex, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u8mf8x7_m (vbool64_t mask, uint8_t *base, vuint64m1_t bindex, vuint8mf8x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u8mf8x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u8mf8x8_m (vbool64_t mask, uint8_t *base, vuint64m1_t bindex, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u8mf4x2_m (vbool32_t mask, uint8_t *base, vuint64m2_t bindex, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u8mf4x3_m (vbool32_t mask, uint8_t *base, vuint64m2_t bindex, vuint8mf4x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u8mf4x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u8mf4x4_m (vbool32_t mask, uint8_t *base, vuint64m2_t bindex, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u8mf4x5_m (vbool32_t mask, uint8_t *base, vuint64m2_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u8mf4x6_m (vbool32_t mask, uint8_t *base, vuint64m2_t bindex, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u8mf4x7_m (vbool32_t mask, uint8_t *base, vuint64m2_t bindex, vuint8mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u8mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u8mf4x8_m (vbool32_t mask, uint8_t *base, vuint64m2_t bindex, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u8mf2x2_m (vbool16_t mask, uint8_t *base, vuint64m4_t bindex, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u8mf2x3_m (vbool16_t mask, uint8_t *base, vuint64m4_t bindex, vuint8mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u8mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u8mf2x4_m (vbool16_t mask, uint8_t *base, vuint64m4_t bindex, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u8mf2x5_m (vbool16_t mask, uint8_t *base, vuint64m4_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u8mf2x6_m (vbool16_t mask, uint8_t *base, vuint64m4_t bindex, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u8mf2x7_m (vbool16_t mask, uint8_t *base, vuint64m4_t bindex, vuint8mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u8mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u8mf2x8_m (vbool16_t mask, uint8_t *base, vuint64m4_t bindex, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u8m1x2_m (vbool8_t mask, uint8_t *base, vuint64m8_t bindex, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u8m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u8m1x3_m (vbool8_t mask, uint8_t *base, vuint64m8_t bindex, vuint8m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u8m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u8m1x4_m (vbool8_t mask, uint8_t *base, vuint64m8_t bindex, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u8m1x5_m (vbool8_t mask, uint8_t *base, vuint64m8_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u8m1x6_m (vbool8_t mask, uint8_t *base, vuint64m8_t bindex, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u8m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u8m1x7_m (vbool8_t mask, uint8_t *base, vuint64m8_t bindex, vuint8m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u8m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u8m1x8_m (vbool8_t mask, uint8_t *base, vuint64m8_t bindex, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u8m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16mf4x2_m (vbool64_t mask, uint16_t *base, vuint8mf8_t bindex, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u16mf4x4_m (vbool64_t mask, uint16_t *base, vuint8mf8_t bindex, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u16mf4x5_m (vbool64_t mask, uint16_t *base, vuint8mf8_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u16mf4x6_m (vbool64_t mask, uint16_t *base, vuint8mf8_t bindex, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u16mf4x7_m (vbool64_t mask, uint16_t *base, vuint8mf8_t bindex, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u16mf4x8_m (vbool64_t mask, uint16_t *base, vuint8mf8_t bindex, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16mf2x2_m (vbool32_t mask, uint16_t *base, vuint8mf4_t bindex, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u16mf2x3_m (vbool32_t mask, uint16_t *base, vuint8mf4_t bindex, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u16mf2x4_m (vbool32_t mask, uint16_t *base, vuint8mf4_t bindex, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u16mf2x5_m (vbool32_t mask, uint16_t *base, vuint8mf4_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u16mf2x6_m (vbool32_t mask, uint16_t *base, vuint8mf4_t bindex, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u16mf2x7_m (vbool32_t mask, uint16_t *base, vuint8mf4_t bindex, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u16mf2x8_m (vbool32_t mask, uint16_t *base, vuint8mf4_t bindex, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16m1x2_m (vbool16_t mask, uint16_t *base, vuint8mf2_t bindex, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u16m1x3_m (vbool16_t mask, uint16_t *base, vuint8mf2_t bindex, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u16m1x4_m (vbool16_t mask, uint16_t *base, vuint8mf2_t bindex, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u16m1x5_m (vbool16_t mask, uint16_t *base, vuint8mf2_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u16m1x6_m (vbool16_t mask, uint16_t *base, vuint8mf2_t bindex, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u16m1x7_m (vbool16_t mask, uint16_t *base, vuint8mf2_t bindex, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u16m1x8_m (vbool16_t mask, uint16_t *base, vuint8mf2_t bindex, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16m2x2_m (vbool8_t mask, uint16_t *base, vuint8m1_t bindex, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u16m2x3_m (vbool8_t mask, uint16_t *base, vuint8m1_t bindex, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u16m2x4_m (vbool8_t mask, uint16_t *base, vuint8m1_t bindex, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u16m4x2_m (vbool4_t mask, uint16_t *base, vuint8m2_t bindex, vuint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u16m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16mf4x2_m (vbool64_t mask, uint16_t *base, vuint16mf4_t bindex, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u16mf4x4_m (vbool64_t mask, uint16_t *base, vuint16mf4_t bindex, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u16mf4x5_m (vbool64_t mask, uint16_t *base, vuint16mf4_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u16mf4x6_m (vbool64_t mask, uint16_t *base, vuint16mf4_t bindex, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u16mf4x7_m (vbool64_t mask, uint16_t *base, vuint16mf4_t bindex, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u16mf4x8_m (vbool64_t mask, uint16_t *base, vuint16mf4_t bindex, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16mf2x2_m (vbool32_t mask, uint16_t *base, vuint16mf2_t bindex, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u16mf2x3_m (vbool32_t mask, uint16_t *base, vuint16mf2_t bindex, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u16mf2x4_m (vbool32_t mask, uint16_t *base, vuint16mf2_t bindex, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u16mf2x5_m (vbool32_t mask, uint16_t *base, vuint16mf2_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u16mf2x6_m (vbool32_t mask, uint16_t *base, vuint16mf2_t bindex, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u16mf2x7_m (vbool32_t mask, uint16_t *base, vuint16mf2_t bindex, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u16mf2x8_m (vbool32_t mask, uint16_t *base, vuint16mf2_t bindex, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16m1x2_m (vbool16_t mask, uint16_t *base, vuint16m1_t bindex, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u16m1x3_m (vbool16_t mask, uint16_t *base, vuint16m1_t bindex, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u16m1x4_m (vbool16_t mask, uint16_t *base, vuint16m1_t bindex, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u16m1x5_m (vbool16_t mask, uint16_t *base, vuint16m1_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u16m1x6_m (vbool16_t mask, uint16_t *base, vuint16m1_t bindex, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u16m1x7_m (vbool16_t mask, uint16_t *base, vuint16m1_t bindex, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u16m1x8_m (vbool16_t mask, uint16_t *base, vuint16m1_t bindex, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16m2x2_m (vbool8_t mask, uint16_t *base, vuint16m2_t bindex, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u16m2x3_m (vbool8_t mask, uint16_t *base, vuint16m2_t bindex, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u16m2x4_m (vbool8_t mask, uint16_t *base, vuint16m2_t bindex, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u16m4x2_m (vbool4_t mask, uint16_t *base, vuint16m4_t bindex, vuint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u16m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16mf4x2_m (vbool64_t mask, uint16_t *base, vuint32mf2_t bindex, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u16mf4x4_m (vbool64_t mask, uint16_t *base, vuint32mf2_t bindex, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16mf4x5_m (vbool64_t mask, uint16_t *base, vuint32mf2_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u16mf4x6_m (vbool64_t mask, uint16_t *base, vuint32mf2_t bindex, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u16mf4x7_m (vbool64_t mask, uint16_t *base, vuint32mf2_t bindex, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u16mf4x8_m (vbool64_t mask, uint16_t *base, vuint32mf2_t bindex, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16mf2x2_m (vbool32_t mask, uint16_t *base, vuint32m1_t bindex, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u16mf2x3_m (vbool32_t mask, uint16_t *base, vuint32m1_t bindex, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u16mf2x4_m (vbool32_t mask, uint16_t *base, vuint32m1_t bindex, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16mf2x5_m (vbool32_t mask, uint16_t *base, vuint32m1_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u16mf2x6_m (vbool32_t mask, uint16_t *base, vuint32m1_t bindex, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u16mf2x7_m (vbool32_t mask, uint16_t *base, vuint32m1_t bindex, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u16mf2x8_m (vbool32_t mask, uint16_t *base, vuint32m1_t bindex, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16m1x2_m (vbool16_t mask, uint16_t *base, vuint32m2_t bindex, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u16m1x3_m (vbool16_t mask, uint16_t *base, vuint32m2_t bindex, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u16m1x4_m (vbool16_t mask, uint16_t *base, vuint32m2_t bindex, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16m1x5_m (vbool16_t mask, uint16_t *base, vuint32m2_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u16m1x6_m (vbool16_t mask, uint16_t *base, vuint32m2_t bindex, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u16m1x7_m (vbool16_t mask, uint16_t *base, vuint32m2_t bindex, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u16m1x8_m (vbool16_t mask, uint16_t *base, vuint32m2_t bindex, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16m2x2_m (vbool8_t mask, uint16_t *base, vuint32m4_t bindex, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u16m2x3_m (vbool8_t mask, uint16_t *base, vuint32m4_t bindex, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u16m2x4_m (vbool8_t mask, uint16_t *base, vuint32m4_t bindex, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u16m4x2_m (vbool4_t mask, uint16_t *base, vuint32m8_t bindex, vuint16m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u16m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u16mf4x2_m (vbool64_t mask, uint16_t *base, vuint64m1_t bindex, vuint16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u16mf4x4_m (vbool64_t mask, uint16_t *base, vuint64m1_t bindex, vuint16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u16mf4x5_m (vbool64_t mask, uint16_t *base, vuint64m1_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u16mf4x6_m (vbool64_t mask, uint16_t *base, vuint64m1_t bindex, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u16mf4x7_m (vbool64_t mask, uint16_t *base, vuint64m1_t bindex, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u16mf4x8_m (vbool64_t mask, uint16_t *base, vuint64m1_t bindex, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u16mf2x2_m (vbool32_t mask, uint16_t *base, vuint64m2_t bindex, vuint16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u16mf2x3_m (vbool32_t mask, uint16_t *base, vuint64m2_t bindex, vuint16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u16mf2x4_m (vbool32_t mask, uint16_t *base, vuint64m2_t bindex, vuint16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u16mf2x5_m (vbool32_t mask, uint16_t *base, vuint64m2_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u16mf2x6_m (vbool32_t mask, uint16_t *base, vuint64m2_t bindex, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u16mf2x7_m (vbool32_t mask, uint16_t *base, vuint64m2_t bindex, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u16mf2x8_m (vbool32_t mask, uint16_t *base, vuint64m2_t bindex, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u16m1x2_m (vbool16_t mask, uint16_t *base, vuint64m4_t bindex, vuint16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u16m1x3_m (vbool16_t mask, uint16_t *base, vuint64m4_t bindex, vuint16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u16m1x4_m (vbool16_t mask, uint16_t *base, vuint64m4_t bindex, vuint16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u16m1x5_m (vbool16_t mask, uint16_t *base, vuint64m4_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u16m1x6_m (vbool16_t mask, uint16_t *base, vuint64m4_t bindex, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u16m1x7_m (vbool16_t mask, uint16_t *base, vuint64m4_t bindex, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u16m1x8_m (vbool16_t mask, uint16_t *base, vuint64m4_t bindex, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u16m2x2_m (vbool8_t mask, uint16_t *base, vuint64m8_t bindex, vuint16m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u16m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u16m2x3_m (vbool8_t mask, uint16_t *base, vuint64m8_t bindex, vuint16m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u16m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u16m2x4_m (vbool8_t mask, uint16_t *base, vuint64m8_t bindex, vuint16m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u16m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u32mf2x2_m (vbool64_t mask, uint32_t *base, vuint8mf8_t bindex, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u32mf2x4_m (vbool64_t mask, uint32_t *base, vuint8mf8_t bindex, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u32mf2x5_m (vbool64_t mask, uint32_t *base, vuint8mf8_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u32mf2x6_m (vbool64_t mask, uint32_t *base, vuint8mf8_t bindex, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u32mf2x7_m (vbool64_t mask, uint32_t *base, vuint8mf8_t bindex, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u32mf2x8_m (vbool64_t mask, uint32_t *base, vuint8mf8_t bindex, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u32m1x2_m (vbool32_t mask, uint32_t *base, vuint8mf4_t bindex, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u32m1x3_m (vbool32_t mask, uint32_t *base, vuint8mf4_t bindex, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u32m1x4_m (vbool32_t mask, uint32_t *base, vuint8mf4_t bindex, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u32m1x5_m (vbool32_t mask, uint32_t *base, vuint8mf4_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u32m1x6_m (vbool32_t mask, uint32_t *base, vuint8mf4_t bindex, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u32m1x7_m (vbool32_t mask, uint32_t *base, vuint8mf4_t bindex, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u32m1x8_m (vbool32_t mask, uint32_t *base, vuint8mf4_t bindex, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u32m2x2_m (vbool16_t mask, uint32_t *base, vuint8mf2_t bindex, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u32m2x3_m (vbool16_t mask, uint32_t *base, vuint8mf2_t bindex, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u32m2x4_m (vbool16_t mask, uint32_t *base, vuint8mf2_t bindex, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u32m4x2_m (vbool8_t mask, uint32_t *base, vuint8m1_t bindex, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u32mf2x2_m (vbool64_t mask, uint32_t *base, vuint16mf4_t bindex, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u32mf2x4_m (vbool64_t mask, uint32_t *base, vuint16mf4_t bindex, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u32mf2x5_m (vbool64_t mask, uint32_t *base, vuint16mf4_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u32mf2x6_m (vbool64_t mask, uint32_t *base, vuint16mf4_t bindex, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u32mf2x7_m (vbool64_t mask, uint32_t *base, vuint16mf4_t bindex, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u32mf2x8_m (vbool64_t mask, uint32_t *base, vuint16mf4_t bindex, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u32m1x2_m (vbool32_t mask, uint32_t *base, vuint16mf2_t bindex, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u32m1x3_m (vbool32_t mask, uint32_t *base, vuint16mf2_t bindex, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u32m1x4_m (vbool32_t mask, uint32_t *base, vuint16mf2_t bindex, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u32m1x5_m (vbool32_t mask, uint32_t *base, vuint16mf2_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u32m1x6_m (vbool32_t mask, uint32_t *base, vuint16mf2_t bindex, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u32m1x7_m (vbool32_t mask, uint32_t *base, vuint16mf2_t bindex, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u32m1x8_m (vbool32_t mask, uint32_t *base, vuint16mf2_t bindex, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u32m2x2_m (vbool16_t mask, uint32_t *base, vuint16m1_t bindex, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u32m2x3_m (vbool16_t mask, uint32_t *base, vuint16m1_t bindex, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u32m2x4_m (vbool16_t mask, uint32_t *base, vuint16m1_t bindex, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u32m4x2_m (vbool8_t mask, uint32_t *base, vuint16m2_t bindex, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u32mf2x2_m (vbool64_t mask, uint32_t *base, vuint32mf2_t bindex, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u32mf2x4_m (vbool64_t mask, uint32_t *base, vuint32mf2_t bindex, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u32mf2x5_m (vbool64_t mask, uint32_t *base, vuint32mf2_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u32mf2x6_m (vbool64_t mask, uint32_t *base, vuint32mf2_t bindex, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u32mf2x7_m (vbool64_t mask, uint32_t *base, vuint32mf2_t bindex, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u32mf2x8_m (vbool64_t mask, uint32_t *base, vuint32mf2_t bindex, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u32m1x2_m (vbool32_t mask, uint32_t *base, vuint32m1_t bindex, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u32m1x3_m (vbool32_t mask, uint32_t *base, vuint32m1_t bindex, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u32m1x4_m (vbool32_t mask, uint32_t *base, vuint32m1_t bindex, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u32m1x5_m (vbool32_t mask, uint32_t *base, vuint32m1_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u32m1x6_m (vbool32_t mask, uint32_t *base, vuint32m1_t bindex, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u32m1x7_m (vbool32_t mask, uint32_t *base, vuint32m1_t bindex, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u32m1x8_m (vbool32_t mask, uint32_t *base, vuint32m1_t bindex, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u32m2x2_m (vbool16_t mask, uint32_t *base, vuint32m2_t bindex, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u32m2x3_m (vbool16_t mask, uint32_t *base, vuint32m2_t bindex, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u32m2x4_m (vbool16_t mask, uint32_t *base, vuint32m2_t bindex, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u32m4x2_m (vbool8_t mask, uint32_t *base, vuint32m4_t bindex, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u32mf2x2_m (vbool64_t mask, uint32_t *base, vuint64m1_t bindex, vuint32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u32mf2x4_m (vbool64_t mask, uint32_t *base, vuint64m1_t bindex, vuint32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u32mf2x5_m (vbool64_t mask, uint32_t *base, vuint64m1_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u32mf2x6_m (vbool64_t mask, uint32_t *base, vuint64m1_t bindex, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u32mf2x7_m (vbool64_t mask, uint32_t *base, vuint64m1_t bindex, vuint32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u32mf2x8_m (vbool64_t mask, uint32_t *base, vuint64m1_t bindex, vuint32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u32m1x2_m (vbool32_t mask, uint32_t *base, vuint64m2_t bindex, vuint32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u32m1x3_m (vbool32_t mask, uint32_t *base, vuint64m2_t bindex, vuint32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u32m1x4_m (vbool32_t mask, uint32_t *base, vuint64m2_t bindex, vuint32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u32m1x5_m (vbool32_t mask, uint32_t *base, vuint64m2_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u32m1x6_m (vbool32_t mask, uint32_t *base, vuint64m2_t bindex, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u32m1x7_m (vbool32_t mask, uint32_t *base, vuint64m2_t bindex, vuint32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u32m1x8_m (vbool32_t mask, uint32_t *base, vuint64m2_t bindex, vuint32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u32m2x2_m (vbool16_t mask, uint32_t *base, vuint64m4_t bindex, vuint32m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u32m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u32m2x3_m (vbool16_t mask, uint32_t *base, vuint64m4_t bindex, vuint32m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u32m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u32m2x4_m (vbool16_t mask, uint32_t *base, vuint64m4_t bindex, vuint32m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u32m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u32m4x2_m (vbool8_t mask, uint32_t *base, vuint64m8_t bindex, vuint32m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u32m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u64m1x2_m (vbool64_t mask, uint64_t *base, vuint8mf8_t bindex, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u64m1x4_m (vbool64_t mask, uint64_t *base, vuint8mf8_t bindex, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_u64m1x5_m (vbool64_t mask, uint64_t *base, vuint8mf8_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_u64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_u64m1x6_m (vbool64_t mask, uint64_t *base, vuint8mf8_t bindex, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_u64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_u64m1x7_m (vbool64_t mask, uint64_t *base, vuint8mf8_t bindex, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_u64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_u64m1x8_m (vbool64_t mask, uint64_t *base, vuint8mf8_t bindex, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_u64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u64m2x2_m (vbool32_t mask, uint64_t *base, vuint8mf4_t bindex, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_u64m2x3_m (vbool32_t mask, uint64_t *base, vuint8mf4_t bindex, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_u64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_u64m2x4_m (vbool32_t mask, uint64_t *base, vuint8mf4_t bindex, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_u64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_u64m4x2_m (vbool16_t mask, uint64_t *base, vuint8mf2_t bindex, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_u64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u64m1x2_m (vbool64_t mask, uint64_t *base, vuint16mf4_t bindex, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u64m1x4_m (vbool64_t mask, uint64_t *base, vuint16mf4_t bindex, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_u64m1x5_m (vbool64_t mask, uint64_t *base, vuint16mf4_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_u64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_u64m1x6_m (vbool64_t mask, uint64_t *base, vuint16mf4_t bindex, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_u64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_u64m1x7_m (vbool64_t mask, uint64_t *base, vuint16mf4_t bindex, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_u64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_u64m1x8_m (vbool64_t mask, uint64_t *base, vuint16mf4_t bindex, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_u64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u64m2x2_m (vbool32_t mask, uint64_t *base, vuint16mf2_t bindex, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_u64m2x3_m (vbool32_t mask, uint64_t *base, vuint16mf2_t bindex, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_u64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_u64m2x4_m (vbool32_t mask, uint64_t *base, vuint16mf2_t bindex, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_u64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_u64m4x2_m (vbool16_t mask, uint64_t *base, vuint16m1_t bindex, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_u64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u64m1x2_m (vbool64_t mask, uint64_t *base, vuint32mf2_t bindex, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u64m1x4_m (vbool64_t mask, uint64_t *base, vuint32mf2_t bindex, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u64m1x5_m (vbool64_t mask, uint64_t *base, vuint32mf2_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_u64m1x6_m (vbool64_t mask, uint64_t *base, vuint32mf2_t bindex, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_u64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_u64m1x7_m (vbool64_t mask, uint64_t *base, vuint32mf2_t bindex, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_u64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_u64m1x8_m (vbool64_t mask, uint64_t *base, vuint32mf2_t bindex, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_u64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u64m2x2_m (vbool32_t mask, uint64_t *base, vuint32m1_t bindex, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_u64m2x3_m (vbool32_t mask, uint64_t *base, vuint32m1_t bindex, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_u64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_u64m2x4_m (vbool32_t mask, uint64_t *base, vuint32m1_t bindex, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_u64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_u64m4x2_m (vbool16_t mask, uint64_t *base, vuint32m2_t bindex, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_u64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u64m1x2_m (vbool64_t mask, uint64_t *base, vuint64m1_t bindex, vuint64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u64m1x4_m (vbool64_t mask, uint64_t *base, vuint64m1_t bindex, vuint64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_u64m1x5_m (vbool64_t mask, uint64_t *base, vuint64m1_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_u64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_u64m1x6_m (vbool64_t mask, uint64_t *base, vuint64m1_t bindex, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_u64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_u64m1x7_m (vbool64_t mask, uint64_t *base, vuint64m1_t bindex, vuint64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_u64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_u64m1x8_m (vbool64_t mask, uint64_t *base, vuint64m1_t bindex, vuint64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_u64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u64m2x2_m (vbool32_t mask, uint64_t *base, vuint64m2_t bindex, vuint64m2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u64m2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_u64m2x3_m (vbool32_t mask, uint64_t *base, vuint64m2_t bindex, vuint64m2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_u64m2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_u64m2x4_m (vbool32_t mask, uint64_t *base, vuint64m2_t bindex, vuint64m2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_u64m2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_u64m4x2_m (vbool16_t mask, uint64_t *base, vuint64m4_t bindex, vuint64m4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_u64m4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f16mf4x2_m (vbool64_t mask, float16_t *base, vuint8mf8_t bindex, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f16mf4x4_m (vbool64_t mask, float16_t *base, vuint8mf8_t bindex, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f16mf4x5_m (vbool64_t mask, float16_t *base, vuint8mf8_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f16mf4x6_m (vbool64_t mask, float16_t *base, vuint8mf8_t bindex, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f16mf4x7_m (vbool64_t mask, float16_t *base, vuint8mf8_t bindex, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f16mf4x8_m (vbool64_t mask, float16_t *base, vuint8mf8_t bindex, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f16mf2x2_m (vbool32_t mask, float16_t *base, vuint8mf4_t bindex, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_f16mf2x3_m (vbool32_t mask, float16_t *base, vuint8mf4_t bindex, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_f16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f16mf2x4_m (vbool32_t mask, float16_t *base, vuint8mf4_t bindex, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f16mf2x5_m (vbool32_t mask, float16_t *base, vuint8mf4_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f16mf2x6_m (vbool32_t mask, float16_t *base, vuint8mf4_t bindex, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f16mf2x7_m (vbool32_t mask, float16_t *base, vuint8mf4_t bindex, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f16mf2x8_m (vbool32_t mask, float16_t *base, vuint8mf4_t bindex, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f16m1x2_m (vbool16_t mask, float16_t *base, vuint8mf2_t bindex, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_f16m1x3_m (vbool16_t mask, float16_t *base, vuint8mf2_t bindex, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_f16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f16m1x4_m (vbool16_t mask, float16_t *base, vuint8mf2_t bindex, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f16m1x5_m (vbool16_t mask, float16_t *base, vuint8mf2_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f16m1x6_m (vbool16_t mask, float16_t *base, vuint8mf2_t bindex, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f16m1x7_m (vbool16_t mask, float16_t *base, vuint8mf2_t bindex, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f16m1x8_m (vbool16_t mask, float16_t *base, vuint8mf2_t bindex, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f16mf4x2_m (vbool64_t mask, float16_t *base, vuint16mf4_t bindex, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f16mf4x4_m (vbool64_t mask, float16_t *base, vuint16mf4_t bindex, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f16mf4x5_m (vbool64_t mask, float16_t *base, vuint16mf4_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f16mf4x6_m (vbool64_t mask, float16_t *base, vuint16mf4_t bindex, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f16mf4x7_m (vbool64_t mask, float16_t *base, vuint16mf4_t bindex, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f16mf4x8_m (vbool64_t mask, float16_t *base, vuint16mf4_t bindex, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f16mf2x2_m (vbool32_t mask, float16_t *base, vuint16mf2_t bindex, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_f16mf2x3_m (vbool32_t mask, float16_t *base, vuint16mf2_t bindex, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_f16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f16mf2x4_m (vbool32_t mask, float16_t *base, vuint16mf2_t bindex, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f16mf2x5_m (vbool32_t mask, float16_t *base, vuint16mf2_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f16mf2x6_m (vbool32_t mask, float16_t *base, vuint16mf2_t bindex, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f16mf2x7_m (vbool32_t mask, float16_t *base, vuint16mf2_t bindex, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f16mf2x8_m (vbool32_t mask, float16_t *base, vuint16mf2_t bindex, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f16m1x2_m (vbool16_t mask, float16_t *base, vuint16m1_t bindex, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_f16m1x3_m (vbool16_t mask, float16_t *base, vuint16m1_t bindex, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_f16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f16m1x4_m (vbool16_t mask, float16_t *base, vuint16m1_t bindex, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f16m1x5_m (vbool16_t mask, float16_t *base, vuint16m1_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f16m1x6_m (vbool16_t mask, float16_t *base, vuint16m1_t bindex, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f16m1x7_m (vbool16_t mask, float16_t *base, vuint16m1_t bindex, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f16m1x8_m (vbool16_t mask, float16_t *base, vuint16m1_t bindex, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f16mf4x2_m (vbool64_t mask, float16_t *base, vuint32mf2_t bindex, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f16mf4x4_m (vbool64_t mask, float16_t *base, vuint32mf2_t bindex, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16mf4x5_m (vbool64_t mask, float16_t *base, vuint32mf2_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f16mf4x6_m (vbool64_t mask, float16_t *base, vuint32mf2_t bindex, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f16mf4x7_m (vbool64_t mask, float16_t *base, vuint32mf2_t bindex, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f16mf4x8_m (vbool64_t mask, float16_t *base, vuint32mf2_t bindex, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f16mf2x2_m (vbool32_t mask, float16_t *base, vuint32m1_t bindex, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_f16mf2x3_m (vbool32_t mask, float16_t *base, vuint32m1_t bindex, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_f16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f16mf2x4_m (vbool32_t mask, float16_t *base, vuint32m1_t bindex, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16mf2x5_m (vbool32_t mask, float16_t *base, vuint32m1_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f16mf2x6_m (vbool32_t mask, float16_t *base, vuint32m1_t bindex, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f16mf2x7_m (vbool32_t mask, float16_t *base, vuint32m1_t bindex, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f16mf2x8_m (vbool32_t mask, float16_t *base, vuint32m1_t bindex, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f16m1x2_m (vbool16_t mask, float16_t *base, vuint32m2_t bindex, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_f16m1x3_m (vbool16_t mask, float16_t *base, vuint32m2_t bindex, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_f16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f16m1x4_m (vbool16_t mask, float16_t *base, vuint32m2_t bindex, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16m1x5_m (vbool16_t mask, float16_t *base, vuint32m2_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f16m1x6_m (vbool16_t mask, float16_t *base, vuint32m2_t bindex, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f16m1x7_m (vbool16_t mask, float16_t *base, vuint32m2_t bindex, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f16m1x8_m (vbool16_t mask, float16_t *base, vuint32m2_t bindex, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f16mf4x2_m (vbool64_t mask, float16_t *base, vuint64m1_t bindex, vfloat16mf4x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f16mf4x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f16mf4x4_m (vbool64_t mask, float16_t *base, vuint64m1_t bindex, vfloat16mf4x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f16mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f16mf4x5_m (vbool64_t mask, float16_t *base, vuint64m1_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f16mf4x6_m (vbool64_t mask, float16_t *base, vuint64m1_t bindex, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f16mf4x7_m (vbool64_t mask, float16_t *base, vuint64m1_t bindex, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f16mf4x8_m (vbool64_t mask, float16_t *base, vuint64m1_t bindex, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f16mf2x2_m (vbool32_t mask, float16_t *base, vuint64m2_t bindex, vfloat16mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f16mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_f16mf2x3_m (vbool32_t mask, float16_t *base, vuint64m2_t bindex, vfloat16mf2x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_f16mf2x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f16mf2x4_m (vbool32_t mask, float16_t *base, vuint64m2_t bindex, vfloat16mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f16mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f16mf2x5_m (vbool32_t mask, float16_t *base, vuint64m2_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f16mf2x6_m (vbool32_t mask, float16_t *base, vuint64m2_t bindex, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f16mf2x7_m (vbool32_t mask, float16_t *base, vuint64m2_t bindex, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f16mf2x8_m (vbool32_t mask, float16_t *base, vuint64m2_t bindex, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f16m1x2_m (vbool16_t mask, float16_t *base, vuint64m4_t bindex, vfloat16m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f16m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_f16m1x3_m (vbool16_t mask, float16_t *base, vuint64m4_t bindex, vfloat16m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_f16m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f16m1x4_m (vbool16_t mask, float16_t *base, vuint64m4_t bindex, vfloat16m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f16m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f16m1x5_m (vbool16_t mask, float16_t *base, vuint64m4_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f16m1x6_m (vbool16_t mask, float16_t *base, vuint64m4_t bindex, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f16m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f16m1x7_m (vbool16_t mask, float16_t *base, vuint64m4_t bindex, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f16m1x8_m (vbool16_t mask, float16_t *base, vuint64m4_t bindex, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f32mf2x2_m (vbool64_t mask, float32_t *base, vuint8mf8_t bindex, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f32mf2x4_m (vbool64_t mask, float32_t *base, vuint8mf8_t bindex, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f32mf2x5_m (vbool64_t mask, float32_t *base, vuint8mf8_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f32mf2x6_m (vbool64_t mask, float32_t *base, vuint8mf8_t bindex, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f32mf2x7_m (vbool64_t mask, float32_t *base, vuint8mf8_t bindex, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f32mf2x8_m (vbool64_t mask, float32_t *base, vuint8mf8_t bindex, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f32m1x2_m (vbool32_t mask, float32_t *base, vuint8mf4_t bindex, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei8_v_f32m1x3_m (vbool32_t mask, float32_t *base, vuint8mf4_t bindex, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei8_v_f32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f32m1x4_m (vbool32_t mask, float32_t *base, vuint8mf4_t bindex, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f32m1x5_m (vbool32_t mask, float32_t *base, vuint8mf4_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f32m1x6_m (vbool32_t mask, float32_t *base, vuint8mf4_t bindex, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f32m1x7_m (vbool32_t mask, float32_t *base, vuint8mf4_t bindex, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f32m1x8_m (vbool32_t mask, float32_t *base, vuint8mf4_t bindex, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f32mf2x2_m (vbool64_t mask, float32_t *base, vuint16mf4_t bindex, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f32mf2x4_m (vbool64_t mask, float32_t *base, vuint16mf4_t bindex, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f32mf2x5_m (vbool64_t mask, float32_t *base, vuint16mf4_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f32mf2x6_m (vbool64_t mask, float32_t *base, vuint16mf4_t bindex, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f32mf2x7_m (vbool64_t mask, float32_t *base, vuint16mf4_t bindex, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f32mf2x8_m (vbool64_t mask, float32_t *base, vuint16mf4_t bindex, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f32m1x2_m (vbool32_t mask, float32_t *base, vuint16mf2_t bindex, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei16_v_f32m1x3_m (vbool32_t mask, float32_t *base, vuint16mf2_t bindex, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei16_v_f32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f32m1x4_m (vbool32_t mask, float32_t *base, vuint16mf2_t bindex, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f32m1x5_m (vbool32_t mask, float32_t *base, vuint16mf2_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f32m1x6_m (vbool32_t mask, float32_t *base, vuint16mf2_t bindex, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f32m1x7_m (vbool32_t mask, float32_t *base, vuint16mf2_t bindex, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f32m1x8_m (vbool32_t mask, float32_t *base, vuint16mf2_t bindex, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f32mf2x2_m (vbool64_t mask, float32_t *base, vuint32mf2_t bindex, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f32mf2x4_m (vbool64_t mask, float32_t *base, vuint32mf2_t bindex, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f32mf2x5_m (vbool64_t mask, float32_t *base, vuint32mf2_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f32mf2x6_m (vbool64_t mask, float32_t *base, vuint32mf2_t bindex, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f32mf2x7_m (vbool64_t mask, float32_t *base, vuint32mf2_t bindex, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f32mf2x8_m (vbool64_t mask, float32_t *base, vuint32mf2_t bindex, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f32m1x2_m (vbool32_t mask, float32_t *base, vuint32m1_t bindex, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei32_v_f32m1x3_m (vbool32_t mask, float32_t *base, vuint32m1_t bindex, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei32_v_f32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f32m1x4_m (vbool32_t mask, float32_t *base, vuint32m1_t bindex, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f32m1x5_m (vbool32_t mask, float32_t *base, vuint32m1_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f32m1x6_m (vbool32_t mask, float32_t *base, vuint32m1_t bindex, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f32m1x7_m (vbool32_t mask, float32_t *base, vuint32m1_t bindex, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f32m1x8_m (vbool32_t mask, float32_t *base, vuint32m1_t bindex, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f32mf2x2_m (vbool64_t mask, float32_t *base, vuint64m1_t bindex, vfloat32mf2x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f32mf2x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f32mf2x4_m (vbool64_t mask, float32_t *base, vuint64m1_t bindex, vfloat32mf2x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f32mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f32mf2x5_m (vbool64_t mask, float32_t *base, vuint64m1_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f32mf2x6_m (vbool64_t mask, float32_t *base, vuint64m1_t bindex, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f32mf2x7_m (vbool64_t mask, float32_t *base, vuint64m1_t bindex, vfloat32mf2x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f32mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f32mf2x8_m (vbool64_t mask, float32_t *base, vuint64m1_t bindex, vfloat32mf2x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f32mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f32m1x2_m (vbool32_t mask, float32_t *base, vuint64m2_t bindex, vfloat32m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f32m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg3ei64_v_f32m1x3_m (vbool32_t mask, float32_t *base, vuint64m2_t bindex, vfloat32m1x3_t value) {
  // CHECK-LABEL: test_vsxseg3ei64_v_f32m1x3_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f32m1x4_m (vbool32_t mask, float32_t *base, vuint64m2_t bindex, vfloat32m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f32m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f32m1x5_m (vbool32_t mask, float32_t *base, vuint64m2_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f32m1x6_m (vbool32_t mask, float32_t *base, vuint64m2_t bindex, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f32m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f32m1x7_m (vbool32_t mask, float32_t *base, vuint64m2_t bindex, vfloat32m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f32m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f32m1x8_m (vbool32_t mask, float32_t *base, vuint64m2_t bindex, vfloat32m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f32m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei8_v_f64m1x2_m (vbool64_t mask, float64_t *base, vuint8mf8_t bindex, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei8_v_f64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei8_v_f64m1x4_m (vbool64_t mask, float64_t *base, vuint8mf8_t bindex, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei8_v_f64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei8_v_f64m1x5_m (vbool64_t mask, float64_t *base, vuint8mf8_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei8_v_f64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei8_v_f64m1x6_m (vbool64_t mask, float64_t *base, vuint8mf8_t bindex, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei8_v_f64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei8_v_f64m1x7_m (vbool64_t mask, float64_t *base, vuint8mf8_t bindex, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei8_v_f64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei8_v_f64m1x8_m (vbool64_t mask, float64_t *base, vuint8mf8_t bindex, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei8_v_f64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei16_v_f64m1x2_m (vbool64_t mask, float64_t *base, vuint16mf4_t bindex, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei16_v_f64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei16_v_f64m1x4_m (vbool64_t mask, float64_t *base, vuint16mf4_t bindex, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei16_v_f64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei16_v_f64m1x5_m (vbool64_t mask, float64_t *base, vuint16mf4_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei16_v_f64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei16_v_f64m1x6_m (vbool64_t mask, float64_t *base, vuint16mf4_t bindex, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei16_v_f64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei16_v_f64m1x7_m (vbool64_t mask, float64_t *base, vuint16mf4_t bindex, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei16_v_f64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei16_v_f64m1x8_m (vbool64_t mask, float64_t *base, vuint16mf4_t bindex, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei16_v_f64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei32_v_f64m1x2_m (vbool64_t mask, float64_t *base, vuint32mf2_t bindex, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei32_v_f64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei32_v_f64m1x4_m (vbool64_t mask, float64_t *base, vuint32mf2_t bindex, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei32_v_f64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f64m1x5_m (vbool64_t mask, float64_t *base, vuint32mf2_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei32_v_f64m1x6_m (vbool64_t mask, float64_t *base, vuint32mf2_t bindex, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei32_v_f64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei32_v_f64m1x7_m (vbool64_t mask, float64_t *base, vuint32mf2_t bindex, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei32_v_f64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei32_v_f64m1x8_m (vbool64_t mask, float64_t *base, vuint32mf2_t bindex, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei32_v_f64m1x8_m
  // CHECK: ret void
  return;
}

void test_vsxseg2ei64_v_f64m1x2_m (vbool64_t mask, float64_t *base, vuint64m1_t bindex, vfloat64m1x2_t value) {
  // CHECK-LABEL: test_vsxseg2ei64_v_f64m1x2_m
  // CHECK: ret void
  return;
}

void test_vsxseg4ei64_v_f64m1x4_m (vbool64_t mask, float64_t *base, vuint64m1_t bindex, vfloat64m1x4_t value) {
  // CHECK-LABEL: test_vsxseg4ei64_v_f64m1x4_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei64_v_f64m1x5_m (vbool64_t mask, float64_t *base, vuint64m1_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei64_v_f64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg6ei64_v_f64m1x6_m (vbool64_t mask, float64_t *base, vuint64m1_t bindex, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsxseg6ei64_v_f64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsxseg7ei64_v_f64m1x7_m (vbool64_t mask, float64_t *base, vuint64m1_t bindex, vfloat64m1x7_t value) {
  // CHECK-LABEL: test_vsxseg7ei64_v_f64m1x7_m
  // CHECK: ret void
  return;
}

void test_vsxseg8ei64_v_f64m1x8_m (vbool64_t mask, float64_t *base, vuint64m1_t bindex, vfloat64m1x8_t value) {
  // CHECK-LABEL: test_vsxseg8ei64_v_f64m1x8_m
  // CHECK: ret void
  return;
}


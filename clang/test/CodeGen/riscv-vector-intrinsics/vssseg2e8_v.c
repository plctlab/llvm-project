// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vssseg2e8_v_i8mf8x2 (int8_t *base, int64_t *bstride, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8mf8x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8mf4x2 (int8_t *base, int64_t *bstride, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8mf4x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8mf2x2 (int8_t *base, int64_t *bstride, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8mf2x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8m1x2 (int8_t *base, int64_t *bstride, vint8m1x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8m1x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8m2x2 (int8_t *base, int64_t *bstride, vint8m2x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8m2x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8m4x2 (int8_t *base, int64_t *bstride, vint8m4x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8m4x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8mf8x2 (uint8_t *base, int64_t *bstride, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8mf8x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8mf4x2 (uint8_t *base, int64_t *bstride, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8mf4x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8mf2x2 (uint8_t *base, int64_t *bstride, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8mf2x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8m1x2 (uint8_t *base, int64_t *bstride, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8m1x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8m2x2 (uint8_t *base, int64_t *bstride, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8m2x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8m4x2 (uint8_t *base, int64_t *bstride, vuint8m4x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8m4x2
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8mf8x2_m (vbool64_t mask, int8_t *base, int64_t *bstride, vint8mf8x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8mf4x2_m (vbool32_t mask, int8_t *base, int64_t *bstride, vint8mf4x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8mf2x2_m (vbool16_t mask, int8_t *base, int64_t *bstride, vint8mf2x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8m1x2_m (vbool8_t mask, int8_t *base, int64_t *bstride, vint8m1x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8m1x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8m2x2_m (vbool4_t mask, int8_t *base, int64_t *bstride, vint8m2x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8m2x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_i8m4x2_m (vbool2_t mask, int8_t *base, int64_t *bstride, vint8m4x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_i8m4x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8mf8x2_m (vbool64_t mask, uint8_t *base, int64_t *bstride, vuint8mf8x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8mf8x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8mf4x2_m (vbool32_t mask, uint8_t *base, int64_t *bstride, vuint8mf4x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8mf4x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8mf2x2_m (vbool16_t mask, uint8_t *base, int64_t *bstride, vuint8mf2x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8mf2x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8m1x2_m (vbool8_t mask, uint8_t *base, int64_t *bstride, vuint8m1x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8m1x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8m2x2_m (vbool4_t mask, uint8_t *base, int64_t *bstride, vuint8m2x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8m2x2_m
  // CHECK: ret void
  return;
}

void test_vssseg2e8_v_u8m4x2_m (vbool2_t mask, uint8_t *base, int64_t *bstride, vuint8m4x2_t value) {
  // CHECK-LABEL: test_vssseg2e8_v_u8m4x2_m
  // CHECK: ret void
  return;
}


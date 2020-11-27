// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vssseg8e8_v_i8mf8x8 (int8_t *base, int64_t *bstride, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_i8mf8x8
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_i8mf4x8 (int8_t *base, int64_t *bstride, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_i8mf4x8
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_i8mf2x8 (int8_t *base, int64_t *bstride, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_i8mf2x8
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_i8m1x8 (int8_t *base, int64_t *bstride, vint8m1x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_i8m1x8
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_u8mf8x8 (uint8_t *base, int64_t *bstride, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_u8mf8x8
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_u8mf4x8 (uint8_t *base, int64_t *bstride, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_u8mf4x8
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_u8mf2x8 (uint8_t *base, int64_t *bstride, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_u8mf2x8
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_u8m1x8 (uint8_t *base, int64_t *bstride, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_u8m1x8
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_i8mf8x8_m (vbool64_t mask, int8_t *base, int64_t *bstride, vint8mf8x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_i8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_i8mf4x8_m (vbool32_t mask, int8_t *base, int64_t *bstride, vint8mf4x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_i8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_i8mf2x8_m (vbool16_t mask, int8_t *base, int64_t *bstride, vint8mf2x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_i8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_i8m1x8_m (vbool8_t mask, int8_t *base, int64_t *bstride, vint8m1x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_i8m1x8_m
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_u8mf8x8_m (vbool64_t mask, uint8_t *base, int64_t *bstride, vuint8mf8x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_u8mf8x8_m
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_u8mf4x8_m (vbool32_t mask, uint8_t *base, int64_t *bstride, vuint8mf4x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_u8mf4x8_m
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_u8mf2x8_m (vbool16_t mask, uint8_t *base, int64_t *bstride, vuint8mf2x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_u8mf2x8_m
  // CHECK: ret void
  return;
}

void test_vssseg8e8_v_u8m1x8_m (vbool8_t mask, uint8_t *base, int64_t *bstride, vuint8m1x8_t value) {
  // CHECK-LABEL: test_vssseg8e8_v_u8m1x8_m
  // CHECK: ret void
  return;
}


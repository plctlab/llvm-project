// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vssseg6e8_v_i8mf8x6 (int8_t *base, int64_t *bstride, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_i8mf8x6
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_i8mf4x6 (int8_t *base, int64_t *bstride, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_i8mf4x6
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_i8mf2x6 (int8_t *base, int64_t *bstride, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_i8mf2x6
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_i8m1x6 (int8_t *base, int64_t *bstride, vint8m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_i8m1x6
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_u8mf8x6 (uint8_t *base, int64_t *bstride, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_u8mf8x6
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_u8mf4x6 (uint8_t *base, int64_t *bstride, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_u8mf4x6
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_u8mf2x6 (uint8_t *base, int64_t *bstride, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_u8mf2x6
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_u8m1x6 (uint8_t *base, int64_t *bstride, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_u8m1x6
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_i8mf8x6_m (vbool64_t mask, int8_t *base, int64_t *bstride, vint8mf8x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_i8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_i8mf4x6_m (vbool32_t mask, int8_t *base, int64_t *bstride, vint8mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_i8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_i8mf2x6_m (vbool16_t mask, int8_t *base, int64_t *bstride, vint8mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_i8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_i8m1x6_m (vbool8_t mask, int8_t *base, int64_t *bstride, vint8m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_i8m1x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_u8mf8x6_m (vbool64_t mask, uint8_t *base, int64_t *bstride, vuint8mf8x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_u8mf8x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_u8mf4x6_m (vbool32_t mask, uint8_t *base, int64_t *bstride, vuint8mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_u8mf4x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_u8mf2x6_m (vbool16_t mask, uint8_t *base, int64_t *bstride, vuint8mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_u8mf2x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e8_v_u8m1x6_m (vbool8_t mask, uint8_t *base, int64_t *bstride, vuint8m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e8_v_u8m1x6_m
  // CHECK: ret void
  return;
}


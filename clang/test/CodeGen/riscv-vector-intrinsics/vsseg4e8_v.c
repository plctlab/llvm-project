// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsseg4e8_v_i8mf8x4 (int8_t *base, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf8x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf4x4 (int8_t *base, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf4x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf2x4 (int8_t *base, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8m1x4 (int8_t *base, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8m1x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8m2x4 (int8_t *base, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8m2x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf8x4 (uint8_t *base, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf8x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf4x4 (uint8_t *base, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf4x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf2x4 (uint8_t *base, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf2x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8m1x4 (uint8_t *base, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8m1x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8m2x4 (uint8_t *base, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8m2x4
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf8x4_m (vbool64_t mask, int8_t *base, vint8mf8x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf4x4_m (vbool32_t mask, int8_t *base, vint8mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8mf2x4_m (vbool16_t mask, int8_t *base, vint8mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8m1x4_m (vbool8_t mask, int8_t *base, vint8m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_i8m2x4_m (vbool4_t mask, int8_t *base, vint8m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_i8m2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf8x4_m (vbool64_t mask, uint8_t *base, vuint8mf8x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf8x4_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf4x4_m (vbool32_t mask, uint8_t *base, vuint8mf4x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf4x4_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8mf2x4_m (vbool16_t mask, uint8_t *base, vuint8mf2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8mf2x4_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8m1x4_m (vbool8_t mask, uint8_t *base, vuint8m1x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8m1x4_m
  // CHECK: ret void
  return;
}

void test_vsseg4e8_v_u8m2x4_m (vbool4_t mask, uint8_t *base, vuint8m2x4_t value) {
  // CHECK-LABEL: test_vsseg4e8_v_u8m2x4_m
  // CHECK: ret void
  return;
}


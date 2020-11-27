// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsseg5e8_v_i8mf8x5 (int8_t *base, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf8x5
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf4x5 (int8_t *base, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf2x5 (int8_t *base, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8m1x5 (int8_t *base, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8m1x5
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf8x5 (uint8_t *base, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf8x5
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf4x5 (uint8_t *base, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf2x5 (uint8_t *base, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8m1x5 (uint8_t *base, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8m1x5
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf8x5_m (vbool64_t mask, int8_t *base, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf4x5_m (vbool32_t mask, int8_t *base, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8mf2x5_m (vbool16_t mask, int8_t *base, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_i8m1x5_m (vbool8_t mask, int8_t *base, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_i8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf8x5_m (vbool64_t mask, uint8_t *base, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf4x5_m (vbool32_t mask, uint8_t *base, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8mf2x5_m (vbool16_t mask, uint8_t *base, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e8_v_u8m1x5_m (vbool8_t mask, uint8_t *base, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e8_v_u8m1x5_m
  // CHECK: ret void
  return;
}


// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsse8_v_i8mf8 (int8_t *base, int64_t *bstride, vint8mf8_t value) {
  // CHECK-LABEL: test_vsse8_v_i8mf8
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8mf4 (int8_t *base, int64_t *bstride, vint8mf4_t value) {
  // CHECK-LABEL: test_vsse8_v_i8mf4
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8mf2 (int8_t *base, int64_t *bstride, vint8mf2_t value) {
  // CHECK-LABEL: test_vsse8_v_i8mf2
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8m1 (int8_t *base, int64_t *bstride, vint8m1_t value) {
  // CHECK-LABEL: test_vsse8_v_i8m1
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8m2 (int8_t *base, int64_t *bstride, vint8m2_t value) {
  // CHECK-LABEL: test_vsse8_v_i8m2
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8m4 (int8_t *base, int64_t *bstride, vint8m4_t value) {
  // CHECK-LABEL: test_vsse8_v_i8m4
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8m8 (int8_t *base, int64_t *bstride, vint8m8_t value) {
  // CHECK-LABEL: test_vsse8_v_i8m8
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8mf8 (uint8_t *base, int64_t *bstride, vuint8mf8_t value) {
  // CHECK-LABEL: test_vsse8_v_u8mf8
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8mf4 (uint8_t *base, int64_t *bstride, vuint8mf4_t value) {
  // CHECK-LABEL: test_vsse8_v_u8mf4
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8mf2 (uint8_t *base, int64_t *bstride, vuint8mf2_t value) {
  // CHECK-LABEL: test_vsse8_v_u8mf2
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8m1 (uint8_t *base, int64_t *bstride, vuint8m1_t value) {
  // CHECK-LABEL: test_vsse8_v_u8m1
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8m2 (uint8_t *base, int64_t *bstride, vuint8m2_t value) {
  // CHECK-LABEL: test_vsse8_v_u8m2
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8m4 (uint8_t *base, int64_t *bstride, vuint8m4_t value) {
  // CHECK-LABEL: test_vsse8_v_u8m4
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8m8 (uint8_t *base, int64_t *bstride, vuint8m8_t value) {
  // CHECK-LABEL: test_vsse8_v_u8m8
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8mf8_m (vbool64_t mask, int8_t *base, int64_t *bstride, vint8mf8_t value) {
  // CHECK-LABEL: test_vsse8_v_i8mf8_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8mf4_m (vbool32_t mask, int8_t *base, int64_t *bstride, vint8mf4_t value) {
  // CHECK-LABEL: test_vsse8_v_i8mf4_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8mf2_m (vbool16_t mask, int8_t *base, int64_t *bstride, vint8mf2_t value) {
  // CHECK-LABEL: test_vsse8_v_i8mf2_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8m1_m (vbool8_t mask, int8_t *base, int64_t *bstride, vint8m1_t value) {
  // CHECK-LABEL: test_vsse8_v_i8m1_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8m2_m (vbool4_t mask, int8_t *base, int64_t *bstride, vint8m2_t value) {
  // CHECK-LABEL: test_vsse8_v_i8m2_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8m4_m (vbool2_t mask, int8_t *base, int64_t *bstride, vint8m4_t value) {
  // CHECK-LABEL: test_vsse8_v_i8m4_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_i8m8_m (vbool1_t mask, int8_t *base, int64_t *bstride, vint8m8_t value) {
  // CHECK-LABEL: test_vsse8_v_i8m8_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8mf8_m (vbool64_t mask, uint8_t *base, int64_t *bstride, vuint8mf8_t value) {
  // CHECK-LABEL: test_vsse8_v_u8mf8_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8mf4_m (vbool32_t mask, uint8_t *base, int64_t *bstride, vuint8mf4_t value) {
  // CHECK-LABEL: test_vsse8_v_u8mf4_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8mf2_m (vbool16_t mask, uint8_t *base, int64_t *bstride, vuint8mf2_t value) {
  // CHECK-LABEL: test_vsse8_v_u8mf2_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8m1_m (vbool8_t mask, uint8_t *base, int64_t *bstride, vuint8m1_t value) {
  // CHECK-LABEL: test_vsse8_v_u8m1_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8m2_m (vbool4_t mask, uint8_t *base, int64_t *bstride, vuint8m2_t value) {
  // CHECK-LABEL: test_vsse8_v_u8m2_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8m4_m (vbool2_t mask, uint8_t *base, int64_t *bstride, vuint8m4_t value) {
  // CHECK-LABEL: test_vsse8_v_u8m4_m
  // CHECK: ret void
  return;
}

void test_vsse8_v_u8m8_m (vbool1_t mask, uint8_t *base, int64_t *bstride, vuint8m8_t value) {
  // CHECK-LABEL: test_vsse8_v_u8m8_m
  // CHECK: ret void
  return;
}


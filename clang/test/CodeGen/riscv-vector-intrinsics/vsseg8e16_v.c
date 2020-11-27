// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsseg8e16_v_i16mf4x8 (int16_t *base, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16mf4x8
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16mf2x8 (int16_t *base, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16m1x8 (int16_t *base, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16m1x8
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16mf4x8 (uint16_t *base, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16mf4x8
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16mf2x8 (uint16_t *base, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16m1x8 (uint16_t *base, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16m1x8
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16mf4x8 (float16_t *base, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16mf4x8
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16mf2x8 (float16_t *base, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16mf2x8
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16m1x8 (float16_t *base, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16m1x8
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16mf4x8_m (vbool64_t mask, int16_t *base, vint16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16mf2x8_m (vbool32_t mask, int16_t *base, vint16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_i16m1x8_m (vbool16_t mask, int16_t *base, vint16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_i16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16mf4x8_m (vbool64_t mask, uint16_t *base, vuint16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16mf2x8_m (vbool32_t mask, uint16_t *base, vuint16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_u16m1x8_m (vbool16_t mask, uint16_t *base, vuint16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_u16m1x8_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16mf4x8_m (vbool64_t mask, float16_t *base, vfloat16mf4x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16mf4x8_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16mf2x8_m (vbool32_t mask, float16_t *base, vfloat16mf2x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16mf2x8_m
  // CHECK: ret void
  return;
}

void test_vsseg8e16_v_f16m1x8_m (vbool16_t mask, float16_t *base, vfloat16m1x8_t value) {
  // CHECK-LABEL: test_vsseg8e16_v_f16m1x8_m
  // CHECK: ret void
  return;
}


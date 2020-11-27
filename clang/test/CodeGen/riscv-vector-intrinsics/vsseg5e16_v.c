// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsseg5e16_v_i16mf4x5 (int16_t *base, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16mf2x5 (int16_t *base, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16m1x5 (int16_t *base, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16m1x5
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16mf4x5 (uint16_t *base, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16mf2x5 (uint16_t *base, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16m1x5 (uint16_t *base, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16m1x5
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16mf4x5 (float16_t *base, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16mf4x5
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16mf2x5 (float16_t *base, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16mf2x5
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16m1x5 (float16_t *base, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16m1x5
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16mf4x5_m (vbool64_t mask, int16_t *base, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16mf2x5_m (vbool32_t mask, int16_t *base, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_i16m1x5_m (vbool16_t mask, int16_t *base, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_i16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16mf4x5_m (vbool64_t mask, uint16_t *base, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16mf2x5_m (vbool32_t mask, uint16_t *base, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_u16m1x5_m (vbool16_t mask, uint16_t *base, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_u16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16mf4x5_m (vbool64_t mask, float16_t *base, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16mf2x5_m (vbool32_t mask, float16_t *base, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsseg5e16_v_f16m1x5_m (vbool16_t mask, float16_t *base, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsseg5e16_v_f16m1x5_m
  // CHECK: ret void
  return;
}


// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsseg7e16_v_i16mf4x7 (int16_t *base, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16mf4x7
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16mf2x7 (int16_t *base, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16m1x7 (int16_t *base, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16m1x7
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16mf4x7 (uint16_t *base, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16mf4x7
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16mf2x7 (uint16_t *base, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16m1x7 (uint16_t *base, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16m1x7
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16mf4x7 (float16_t *base, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16mf4x7
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16mf2x7 (float16_t *base, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16mf2x7
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16m1x7 (float16_t *base, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16m1x7
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16mf4x7_m (vbool64_t mask, int16_t *base, vint16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16mf2x7_m (vbool32_t mask, int16_t *base, vint16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_i16m1x7_m (vbool16_t mask, int16_t *base, vint16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_i16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16mf4x7_m (vbool64_t mask, uint16_t *base, vuint16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16mf2x7_m (vbool32_t mask, uint16_t *base, vuint16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_u16m1x7_m (vbool16_t mask, uint16_t *base, vuint16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_u16m1x7_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16mf4x7_m (vbool64_t mask, float16_t *base, vfloat16mf4x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16mf4x7_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16mf2x7_m (vbool32_t mask, float16_t *base, vfloat16mf2x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16mf2x7_m
  // CHECK: ret void
  return;
}

void test_vsseg7e16_v_f16m1x7_m (vbool16_t mask, float16_t *base, vfloat16m1x7_t value) {
  // CHECK-LABEL: test_vsseg7e16_v_f16m1x7_m
  // CHECK: ret void
  return;
}


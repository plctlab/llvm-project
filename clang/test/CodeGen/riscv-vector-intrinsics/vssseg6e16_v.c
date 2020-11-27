// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vssseg6e16_v_i16mf4x6 (int16_t *base, int64_t *bstride, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_i16mf4x6
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_i16mf2x6 (int16_t *base, int64_t *bstride, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_i16mf2x6
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_i16m1x6 (int16_t *base, int64_t *bstride, vint16m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_i16m1x6
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_u16mf4x6 (uint16_t *base, int64_t *bstride, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_u16mf4x6
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_u16mf2x6 (uint16_t *base, int64_t *bstride, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_u16mf2x6
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_u16m1x6 (uint16_t *base, int64_t *bstride, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_u16m1x6
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_f16mf4x6 (float16_t *base, int64_t *bstride, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_f16mf4x6
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_f16mf2x6 (float16_t *base, int64_t *bstride, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_f16mf2x6
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_f16m1x6 (float16_t *base, int64_t *bstride, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_f16m1x6
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_i16mf4x6_m (vbool64_t mask, int16_t *base, int64_t *bstride, vint16mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_i16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_i16mf2x6_m (vbool32_t mask, int16_t *base, int64_t *bstride, vint16mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_i16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_i16m1x6_m (vbool16_t mask, int16_t *base, int64_t *bstride, vint16m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_i16m1x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_u16mf4x6_m (vbool64_t mask, uint16_t *base, int64_t *bstride, vuint16mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_u16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_u16mf2x6_m (vbool32_t mask, uint16_t *base, int64_t *bstride, vuint16mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_u16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_u16m1x6_m (vbool16_t mask, uint16_t *base, int64_t *bstride, vuint16m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_u16m1x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_f16mf4x6_m (vbool64_t mask, float16_t *base, int64_t *bstride, vfloat16mf4x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_f16mf4x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_f16mf2x6_m (vbool32_t mask, float16_t *base, int64_t *bstride, vfloat16mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_f16mf2x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e16_v_f16m1x6_m (vbool16_t mask, float16_t *base, int64_t *bstride, vfloat16m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e16_v_f16m1x6_m
  // CHECK: ret void
  return;
}


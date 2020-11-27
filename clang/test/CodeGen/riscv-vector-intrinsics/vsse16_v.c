// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsse16_v_i16mf4 (int16_t *base, int64_t *bstride, vint16mf4_t value) {
  // CHECK-LABEL: test_vsse16_v_i16mf4
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16mf2 (int16_t *base, int64_t *bstride, vint16mf2_t value) {
  // CHECK-LABEL: test_vsse16_v_i16mf2
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16m1 (int16_t *base, int64_t *bstride, vint16m1_t value) {
  // CHECK-LABEL: test_vsse16_v_i16m1
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16m2 (int16_t *base, int64_t *bstride, vint16m2_t value) {
  // CHECK-LABEL: test_vsse16_v_i16m2
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16m4 (int16_t *base, int64_t *bstride, vint16m4_t value) {
  // CHECK-LABEL: test_vsse16_v_i16m4
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16m8 (int16_t *base, int64_t *bstride, vint16m8_t value) {
  // CHECK-LABEL: test_vsse16_v_i16m8
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16mf4 (uint16_t *base, int64_t *bstride, vuint16mf4_t value) {
  // CHECK-LABEL: test_vsse16_v_u16mf4
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16mf2 (uint16_t *base, int64_t *bstride, vuint16mf2_t value) {
  // CHECK-LABEL: test_vsse16_v_u16mf2
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16m1 (uint16_t *base, int64_t *bstride, vuint16m1_t value) {
  // CHECK-LABEL: test_vsse16_v_u16m1
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16m2 (uint16_t *base, int64_t *bstride, vuint16m2_t value) {
  // CHECK-LABEL: test_vsse16_v_u16m2
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16m4 (uint16_t *base, int64_t *bstride, vuint16m4_t value) {
  // CHECK-LABEL: test_vsse16_v_u16m4
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16m8 (uint16_t *base, int64_t *bstride, vuint16m8_t value) {
  // CHECK-LABEL: test_vsse16_v_u16m8
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16mf4 (float16_t *base, int64_t *bstride, vfloat16mf4_t value) {
  // CHECK-LABEL: test_vsse16_v_f16mf4
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16mf2 (float16_t *base, int64_t *bstride, vfloat16mf2_t value) {
  // CHECK-LABEL: test_vsse16_v_f16mf2
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16m1 (float16_t *base, int64_t *bstride, vfloat16m1_t value) {
  // CHECK-LABEL: test_vsse16_v_f16m1
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16m2 (float16_t *base, int64_t *bstride, vfloat16m2_t value) {
  // CHECK-LABEL: test_vsse16_v_f16m2
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16m4 (float16_t *base, int64_t *bstride, vfloat16m4_t value) {
  // CHECK-LABEL: test_vsse16_v_f16m4
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16m8 (float16_t *base, int64_t *bstride, vfloat16m8_t value) {
  // CHECK-LABEL: test_vsse16_v_f16m8
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16mf4_m (vbool64_t mask, int16_t *base, int64_t *bstride, vint16mf4_t value) {
  // CHECK-LABEL: test_vsse16_v_i16mf4_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16mf2_m (vbool32_t mask, int16_t *base, int64_t *bstride, vint16mf2_t value) {
  // CHECK-LABEL: test_vsse16_v_i16mf2_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16m1_m (vbool16_t mask, int16_t *base, int64_t *bstride, vint16m1_t value) {
  // CHECK-LABEL: test_vsse16_v_i16m1_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16m2_m (vbool8_t mask, int16_t *base, int64_t *bstride, vint16m2_t value) {
  // CHECK-LABEL: test_vsse16_v_i16m2_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16m4_m (vbool4_t mask, int16_t *base, int64_t *bstride, vint16m4_t value) {
  // CHECK-LABEL: test_vsse16_v_i16m4_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_i16m8_m (vbool2_t mask, int16_t *base, int64_t *bstride, vint16m8_t value) {
  // CHECK-LABEL: test_vsse16_v_i16m8_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16mf4_m (vbool64_t mask, uint16_t *base, int64_t *bstride, vuint16mf4_t value) {
  // CHECK-LABEL: test_vsse16_v_u16mf4_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16mf2_m (vbool32_t mask, uint16_t *base, int64_t *bstride, vuint16mf2_t value) {
  // CHECK-LABEL: test_vsse16_v_u16mf2_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16m1_m (vbool16_t mask, uint16_t *base, int64_t *bstride, vuint16m1_t value) {
  // CHECK-LABEL: test_vsse16_v_u16m1_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16m2_m (vbool8_t mask, uint16_t *base, int64_t *bstride, vuint16m2_t value) {
  // CHECK-LABEL: test_vsse16_v_u16m2_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16m4_m (vbool4_t mask, uint16_t *base, int64_t *bstride, vuint16m4_t value) {
  // CHECK-LABEL: test_vsse16_v_u16m4_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_u16m8_m (vbool2_t mask, uint16_t *base, int64_t *bstride, vuint16m8_t value) {
  // CHECK-LABEL: test_vsse16_v_u16m8_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16mf4_m (vbool64_t mask, float16_t *base, int64_t *bstride, vfloat16mf4_t value) {
  // CHECK-LABEL: test_vsse16_v_f16mf4_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16mf2_m (vbool32_t mask, float16_t *base, int64_t *bstride, vfloat16mf2_t value) {
  // CHECK-LABEL: test_vsse16_v_f16mf2_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16m1_m (vbool16_t mask, float16_t *base, int64_t *bstride, vfloat16m1_t value) {
  // CHECK-LABEL: test_vsse16_v_f16m1_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16m2_m (vbool8_t mask, float16_t *base, int64_t *bstride, vfloat16m2_t value) {
  // CHECK-LABEL: test_vsse16_v_f16m2_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16m4_m (vbool4_t mask, float16_t *base, int64_t *bstride, vfloat16m4_t value) {
  // CHECK-LABEL: test_vsse16_v_f16m4_m
  // CHECK: ret void
  return;
}

void test_vsse16_v_f16m8_m (vbool2_t mask, float16_t *base, int64_t *bstride, vfloat16m8_t value) {
  // CHECK-LABEL: test_vsse16_v_f16m8_m
  // CHECK: ret void
  return;
}


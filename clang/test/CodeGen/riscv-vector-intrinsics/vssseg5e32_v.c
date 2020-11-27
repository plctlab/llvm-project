// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vssseg5e32_v_i32mf2x5 (int32_t *base, int64_t *bstride, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_i32mf2x5
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_i32m1x5 (int32_t *base, int64_t *bstride, vint32m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_i32m1x5
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_u32mf2x5 (uint32_t *base, int64_t *bstride, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_u32mf2x5
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_u32m1x5 (uint32_t *base, int64_t *bstride, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_u32m1x5
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_f32mf2x5 (float32_t *base, int64_t *bstride, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_f32mf2x5
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_f32m1x5 (float32_t *base, int64_t *bstride, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_f32m1x5
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_i32mf2x5_m (vbool64_t mask, int32_t *base, int64_t *bstride, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_i32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_i32m1x5_m (vbool32_t mask, int32_t *base, int64_t *bstride, vint32m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_i32m1x5_m
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_u32mf2x5_m (vbool64_t mask, uint32_t *base, int64_t *bstride, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_u32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_u32m1x5_m (vbool32_t mask, uint32_t *base, int64_t *bstride, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_u32m1x5_m
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_f32mf2x5_m (vbool64_t mask, float32_t *base, int64_t *bstride, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_f32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vssseg5e32_v_f32m1x5_m (vbool32_t mask, float32_t *base, int64_t *bstride, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e32_v_f32m1x5_m
  // CHECK: ret void
  return;
}


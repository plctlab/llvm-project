// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vssseg6e32_v_i32mf2x6 (int32_t *base, int64_t *bstride, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_i32mf2x6
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_i32m1x6 (int32_t *base, int64_t *bstride, vint32m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_i32m1x6
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_u32mf2x6 (uint32_t *base, int64_t *bstride, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_u32mf2x6
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_u32m1x6 (uint32_t *base, int64_t *bstride, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_u32m1x6
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_f32mf2x6 (float32_t *base, int64_t *bstride, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_f32mf2x6
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_f32m1x6 (float32_t *base, int64_t *bstride, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_f32m1x6
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_i32mf2x6_m (vbool64_t mask, int32_t *base, int64_t *bstride, vint32mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_i32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_i32m1x6_m (vbool32_t mask, int32_t *base, int64_t *bstride, vint32m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_i32m1x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_u32mf2x6_m (vbool64_t mask, uint32_t *base, int64_t *bstride, vuint32mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_u32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_u32m1x6_m (vbool32_t mask, uint32_t *base, int64_t *bstride, vuint32m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_u32m1x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_f32mf2x6_m (vbool64_t mask, float32_t *base, int64_t *bstride, vfloat32mf2x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_f32mf2x6_m
  // CHECK: ret void
  return;
}

void test_vssseg6e32_v_f32m1x6_m (vbool32_t mask, float32_t *base, int64_t *bstride, vfloat32m1x6_t value) {
  // CHECK-LABEL: test_vssseg6e32_v_f32m1x6_m
  // CHECK: ret void
  return;
}


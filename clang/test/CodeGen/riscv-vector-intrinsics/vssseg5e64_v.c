// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vssseg5e64_v_i64m1x5 (int64_t *base, int64_t *bstride, vint64m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e64_v_i64m1x5
  // CHECK: ret void
  return;
}

void test_vssseg5e64_v_u64m1x5 (uint64_t *base, int64_t *bstride, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e64_v_u64m1x5
  // CHECK: ret void
  return;
}

void test_vssseg5e64_v_f64m1x5 (float64_t *base, int64_t *bstride, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e64_v_f64m1x5
  // CHECK: ret void
  return;
}

void test_vssseg5e64_v_i64m1x5_m (vbool64_t mask, int64_t *base, int64_t *bstride, vint64m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e64_v_i64m1x5_m
  // CHECK: ret void
  return;
}

void test_vssseg5e64_v_u64m1x5_m (vbool64_t mask, uint64_t *base, int64_t *bstride, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e64_v_u64m1x5_m
  // CHECK: ret void
  return;
}

void test_vssseg5e64_v_f64m1x5_m (vbool64_t mask, float64_t *base, int64_t *bstride, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vssseg5e64_v_f64m1x5_m
  // CHECK: ret void
  return;
}


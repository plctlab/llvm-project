// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsseg6e64_v_i64m1x6 (int64_t *base, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_i64m1x6
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_u64m1x6 (uint64_t *base, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_u64m1x6
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_f64m1x6 (float64_t *base, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_f64m1x6
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_i64m1x6_m (vbool64_t mask, int64_t *base, vint64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_i64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_u64m1x6_m (vbool64_t mask, uint64_t *base, vuint64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_u64m1x6_m
  // CHECK: ret void
  return;
}

void test_vsseg6e64_v_f64m1x6_m (vbool64_t mask, float64_t *base, vfloat64m1x6_t value) {
  // CHECK-LABEL: test_vsseg6e64_v_f64m1x6_m
  // CHECK: ret void
  return;
}


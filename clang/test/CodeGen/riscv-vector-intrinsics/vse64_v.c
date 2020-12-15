// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vse64_v_i64m1 (int64_t *base, vint64m1_t value) {
  // CHECK-LABEL: test_vse64_v_i64m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i64{{.*}}(i64* %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vse64_v_i64m1(base, value);
}

void test_vse64_v_i64m2 (int64_t *base, vint64m2_t value) {
  // CHECK-LABEL: test_vse64_v_i64m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i64{{.*}}(i64* %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vse64_v_i64m2(base, value);
}

void test_vse64_v_i64m4 (int64_t *base, vint64m4_t value) {
  // CHECK-LABEL: test_vse64_v_i64m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i64{{.*}}(i64* %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vse64_v_i64m4(base, value);
}

void test_vse64_v_i64m8 (int64_t *base, vint64m8_t value) {
  // CHECK-LABEL: test_vse64_v_i64m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i64{{.*}}(i64* %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vse64_v_i64m8(base, value);
}

void test_vse64_v_u64m1 (uint64_t *base, vuint64m1_t value) {
  // CHECK-LABEL: test_vse64_v_u64m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i64{{.*}}(i64* %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vse64_v_u64m1(base, value);
}

void test_vse64_v_u64m2 (uint64_t *base, vuint64m2_t value) {
  // CHECK-LABEL: test_vse64_v_u64m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i64{{.*}}(i64* %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vse64_v_u64m2(base, value);
}

void test_vse64_v_u64m4 (uint64_t *base, vuint64m4_t value) {
  // CHECK-LABEL: test_vse64_v_u64m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i64{{.*}}(i64* %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vse64_v_u64m4(base, value);
}

void test_vse64_v_u64m8 (uint64_t *base, vuint64m8_t value) {
  // CHECK-LABEL: test_vse64_v_u64m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i64{{.*}}(i64* %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vse64_v_u64m8(base, value);
}

void test_vse64_v_f64m1 (float64_t *base, vfloat64m1_t value) {
  // CHECK-LABEL: test_vse64_v_f64m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1f64{{.*}}(double* %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vse64_v_f64m1(base, value);
}

void test_vse64_v_f64m2 (float64_t *base, vfloat64m2_t value) {
  // CHECK-LABEL: test_vse64_v_f64m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2f64{{.*}}(double* %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vse64_v_f64m2(base, value);
}

void test_vse64_v_f64m4 (float64_t *base, vfloat64m4_t value) {
  // CHECK-LABEL: test_vse64_v_f64m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4f64{{.*}}(double* %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vse64_v_f64m4(base, value);
}

void test_vse64_v_f64m8 (float64_t *base, vfloat64m8_t value) {
  // CHECK-LABEL: test_vse64_v_f64m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8f64{{.*}}(double* %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vse64_v_f64m8(base, value);
}

void test_vse64_v_i64m1_m (vbool64_t mask, int64_t *base, vint64m1_t value) {
  // CHECK-LABEL: test_vse64_v_i64m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, i64* %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vse64_v_i64m1_m(mask, base, value);
}

void test_vse64_v_i64m2_m (vbool32_t mask, int64_t *base, vint64m2_t value) {
  // CHECK-LABEL: test_vse64_v_i64m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, i64* %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vse64_v_i64m2_m(mask, base, value);
}

void test_vse64_v_i64m4_m (vbool16_t mask, int64_t *base, vint64m4_t value) {
  // CHECK-LABEL: test_vse64_v_i64m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, i64* %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vse64_v_i64m4_m(mask, base, value);
}

void test_vse64_v_i64m8_m (vbool8_t mask, int64_t *base, vint64m8_t value) {
  // CHECK-LABEL: test_vse64_v_i64m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, i64* %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vse64_v_i64m8_m(mask, base, value);
}

void test_vse64_v_u64m1_m (vbool64_t mask, uint64_t *base, vuint64m1_t value) {
  // CHECK-LABEL: test_vse64_v_u64m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, i64* %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vse64_v_u64m1_m(mask, base, value);
}

void test_vse64_v_u64m2_m (vbool32_t mask, uint64_t *base, vuint64m2_t value) {
  // CHECK-LABEL: test_vse64_v_u64m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, i64* %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vse64_v_u64m2_m(mask, base, value);
}

void test_vse64_v_u64m4_m (vbool16_t mask, uint64_t *base, vuint64m4_t value) {
  // CHECK-LABEL: test_vse64_v_u64m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, i64* %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vse64_v_u64m4_m(mask, base, value);
}

void test_vse64_v_u64m8_m (vbool8_t mask, uint64_t *base, vuint64m8_t value) {
  // CHECK-LABEL: test_vse64_v_u64m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, i64* %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vse64_v_u64m8_m(mask, base, value);
}

void test_vse64_v_f64m1_m (vbool64_t mask, float64_t *base, vfloat64m1_t value) {
  // CHECK-LABEL: test_vse64_v_f64m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, double* %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vse64_v_f64m1_m(mask, base, value);
}

void test_vse64_v_f64m2_m (vbool32_t mask, float64_t *base, vfloat64m2_t value) {
  // CHECK-LABEL: test_vse64_v_f64m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, double* %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vse64_v_f64m2_m(mask, base, value);
}

void test_vse64_v_f64m4_m (vbool16_t mask, float64_t *base, vfloat64m4_t value) {
  // CHECK-LABEL: test_vse64_v_f64m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, double* %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vse64_v_f64m4_m(mask, base, value);
}

void test_vse64_v_f64m8_m (vbool8_t mask, float64_t *base, vfloat64m8_t value) {
  // CHECK-LABEL: test_vse64_v_f64m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, double* %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vse64_v_f64m8_m(mask, base, value);
}


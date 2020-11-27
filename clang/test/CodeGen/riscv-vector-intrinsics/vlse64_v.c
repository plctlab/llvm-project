// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1_t test_vlse64_v_i64m1 (int64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vload.{{.*}}nxv1i64{{.*}}(i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_i64m1(base, *bstride);
}

vint64m2_t test_vlse64_v_i64m2 (int64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vload.{{.*}}nxv2i64{{.*}}(i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_i64m2(base, *bstride);
}

vint64m4_t test_vlse64_v_i64m4 (int64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vload.{{.*}}nxv4i64{{.*}}(i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_i64m4(base, *bstride);
}

vint64m8_t test_vlse64_v_i64m8 (int64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vload.{{.*}}nxv8i64{{.*}}(i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_i64m8(base, *bstride);
}

vuint64m1_t test_vlse64_v_u64m1 (uint64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vload.{{.*}}nxv1i64{{.*}}(i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_u64m1(base, *bstride);
}

vuint64m2_t test_vlse64_v_u64m2 (uint64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vload.{{.*}}nxv2i64{{.*}}(i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_u64m2(base, *bstride);
}

vuint64m4_t test_vlse64_v_u64m4 (uint64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vload.{{.*}}nxv4i64{{.*}}(i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_u64m4(base, *bstride);
}

vuint64m8_t test_vlse64_v_u64m8 (uint64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vload.{{.*}}nxv8i64{{.*}}(i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_u64m8(base, *bstride);
}

vfloat64m1_t test_vlse64_v_f64m1 (float64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vload.{{.*}}nxv1f64{{.*}}(double* %{{.*}}, i64 %{{.*}})
  return vlse64_v_f64m1(base, *bstride);
}

vfloat64m2_t test_vlse64_v_f64m2 (float64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vload.{{.*}}nxv2f64{{.*}}(double* %{{.*}}, i64 %{{.*}})
  return vlse64_v_f64m2(base, *bstride);
}

vfloat64m4_t test_vlse64_v_f64m4 (float64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vload.{{.*}}nxv4f64{{.*}}(double* %{{.*}}, i64 %{{.*}})
  return vlse64_v_f64m4(base, *bstride);
}

vfloat64m8_t test_vlse64_v_f64m8 (float64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vload.{{.*}}nxv8f64{{.*}}(double* %{{.*}}, i64 %{{.*}})
  return vlse64_v_f64m8(base, *bstride);
}

vint64m1_t test_vlse64_v_i64m1_m (vbool64_t mask, vint64m1_t maskedoff, int64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vload.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_i64m1_m(mask, maskedoff, base, *bstride);
}

vint64m2_t test_vlse64_v_i64m2_m (vbool32_t mask, vint64m2_t maskedoff, int64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vload.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_i64m2_m(mask, maskedoff, base, *bstride);
}

vint64m4_t test_vlse64_v_i64m4_m (vbool16_t mask, vint64m4_t maskedoff, int64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vload.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_i64m4_m(mask, maskedoff, base, *bstride);
}

vint64m8_t test_vlse64_v_i64m8_m (vbool8_t mask, vint64m8_t maskedoff, int64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vload.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_i64m8_m(mask, maskedoff, base, *bstride);
}

vuint64m1_t test_vlse64_v_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff, uint64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vload.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_u64m1_m(mask, maskedoff, base, *bstride);
}

vuint64m2_t test_vlse64_v_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff, uint64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vload.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_u64m2_m(mask, maskedoff, base, *bstride);
}

vuint64m4_t test_vlse64_v_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff, uint64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vload.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_u64m4_m(mask, maskedoff, base, *bstride);
}

vuint64m8_t test_vlse64_v_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff, uint64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vload.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64* %{{.*}}, i64 %{{.*}})
  return vlse64_v_u64m8_m(mask, maskedoff, base, *bstride);
}

vfloat64m1_t test_vlse64_v_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, float64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vload.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, double* %{{.*}}, i64 %{{.*}})
  return vlse64_v_f64m1_m(mask, maskedoff, base, *bstride);
}

vfloat64m2_t test_vlse64_v_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, float64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vload.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, double* %{{.*}}, i64 %{{.*}})
  return vlse64_v_f64m2_m(mask, maskedoff, base, *bstride);
}

vfloat64m4_t test_vlse64_v_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, float64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vload.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, double* %{{.*}}, i64 %{{.*}})
  return vlse64_v_f64m4_m(mask, maskedoff, base, *bstride);
}

vfloat64m8_t test_vlse64_v_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, float64_t *base, int64_t *bstride) {
  // CHECK-LABEL: test_vlse64_v_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vload.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double* %{{.*}}, i64 %{{.*}})
  return vlse64_v_f64m8_m(mask, maskedoff, base, *bstride);
}


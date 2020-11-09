// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x7_t test_vlseg7e64_v_i64m1x7 (int64_t *base) {
  // CHECK-LABEL: test_vlseg7e64_v_i64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vlseg7e64.v.nxv1i64x7.{{.*}}(i64 %{{.*}})
  return vlseg7e64_v_i64m1x7(*base);
}

vuint64m1x7_t test_vlseg7e64_v_u64m1x7 (uint64_t *base) {
  // CHECK-LABEL: test_vlseg7e64_v_u64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vlseg7e64.v.nxv1i64x7.{{.*}}(i64 %{{.*}})
  return vlseg7e64_v_u64m1x7(*base);
}

vfloat64m1x7_t test_vlseg7e64_v_f64m1x7 (float64_t *base) {
  // CHECK-LABEL: test_vlseg7e64_v_f64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x double> @llvm.riscv.vlseg7e64.v.nxv1f32x7.{{.*}}(double %{{.*}})
  return vlseg7e64_v_f64m1x7(*base);
}

vint64m1x7_t test_vlseg7e64_v_i64m1x7_m (vbool64_t mask, vint64m1x7_t maskedoff, int64_t *base) {
  // CHECK-LABEL: test_vlseg7e64_v_i64m1x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vlseg7e64.v.nxv1i64x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg7e64_v_i64m1x7_m(mask, maskedoff, *base);
}

vuint64m1x7_t test_vlseg7e64_v_u64m1x7_m (vbool64_t mask, vuint64m1x7_t maskedoff, uint64_t *base) {
  // CHECK-LABEL: test_vlseg7e64_v_u64m1x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vlseg7e64.v.nxv1i64x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg7e64_v_u64m1x7_m(mask, maskedoff, *base);
}

vfloat64m1x7_t test_vlseg7e64_v_f64m1x7_m (vbool64_t mask, vfloat64m1x7_t maskedoff, float64_t *base) {
  // CHECK-LABEL: test_vlseg7e64_v_f64m1x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x double> @llvm.riscv.vlseg7e64.v.nxv1f32x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x double> %{{.*}}, double %{{.*}})
  return vlseg7e64_v_f64m1x7_m(mask, maskedoff, *base);
}


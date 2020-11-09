// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x5_t test_vlseg5e64ff_v_i64m1x5 (int64_t *base) {
  // CHECK-LABEL: test_vlseg5e64ff_v_i64m1x5
  // CHECK: %{{.*}} = call <vscale x 5 x i64> @llvm.riscv.vlseg5e64ff.v.nxv1i64x5.{{.*}}(i64 %{{.*}})
  return vlseg5e64ff_v_i64m1x5(*base);
}

vuint64m1x5_t test_vlseg5e64ff_v_u64m1x5 (uint64_t *base) {
  // CHECK-LABEL: test_vlseg5e64ff_v_u64m1x5
  // CHECK: %{{.*}} = call <vscale x 5 x i64> @llvm.riscv.vlseg5e64ff.v.nxv1i64x5.{{.*}}(i64 %{{.*}})
  return vlseg5e64ff_v_u64m1x5(*base);
}

vfloat64m1x5_t test_vlseg5e64ff_v_f64m1x5 (float64_t *base) {
  // CHECK-LABEL: test_vlseg5e64ff_v_f64m1x5
  // CHECK: %{{.*}} = call <vscale x 5 x double> @llvm.riscv.vlseg5e64ff.v.nxv1f32x5.{{.*}}(double %{{.*}})
  return vlseg5e64ff_v_f64m1x5(*base);
}

vint64m1x5_t test_vlseg5e64ff_v_i64m1x5_m (vbool64_t mask, vint64m1x5_t maskedoff, int64_t *base) {
  // CHECK-LABEL: test_vlseg5e64ff_v_i64m1x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x i64> @llvm.riscv.vlseg5e64ff.v.nxv1i64x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg5e64ff_v_i64m1x5_m(mask, maskedoff, *base);
}

vuint64m1x5_t test_vlseg5e64ff_v_u64m1x5_m (vbool64_t mask, vuint64m1x5_t maskedoff, uint64_t *base) {
  // CHECK-LABEL: test_vlseg5e64ff_v_u64m1x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x i64> @llvm.riscv.vlseg5e64ff.v.nxv1i64x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg5e64ff_v_u64m1x5_m(mask, maskedoff, *base);
}

vfloat64m1x5_t test_vlseg5e64ff_v_f64m1x5_m (vbool64_t mask, vfloat64m1x5_t maskedoff, float64_t *base) {
  // CHECK-LABEL: test_vlseg5e64ff_v_f64m1x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x double> @llvm.riscv.vlseg5e64ff.v.nxv1f32x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x double> %{{.*}}, double %{{.*}})
  return vlseg5e64ff_v_f64m1x5_m(mask, maskedoff, *base);
}


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x8_t test_vlseg8e64ff_v_i64m1x8 (int64_t *base) {
  // CHECK-LABEL: test_vlseg8e64ff_v_i64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlseg8e64ff.v.nxv1i64x8.{{.*}}(i64 %{{.*}})
  return vlseg8e64ff_v_i64m1x8(*base);
}

vuint64m1x8_t test_vlseg8e64ff_v_u64m1x8 (uint64_t *base) {
  // CHECK-LABEL: test_vlseg8e64ff_v_u64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlseg8e64ff.v.nxv1i64x8.{{.*}}(i64 %{{.*}})
  return vlseg8e64ff_v_u64m1x8(*base);
}

vfloat64m1x8_t test_vlseg8e64ff_v_f64m1x8 (float64_t *base) {
  // CHECK-LABEL: test_vlseg8e64ff_v_f64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlseg8e64ff.v.nxv1f32x8.{{.*}}(double %{{.*}})
  return vlseg8e64ff_v_f64m1x8(*base);
}

vint64m1x8_t test_vlseg8e64ff_v_i64m1x8_m (vbool64_t mask, vint64m1x8_t maskedoff, int64_t *base) {
  // CHECK-LABEL: test_vlseg8e64ff_v_i64m1x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlseg8e64ff.v.nxv1i64x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg8e64ff_v_i64m1x8_m(mask, maskedoff, *base);
}

vuint64m1x8_t test_vlseg8e64ff_v_u64m1x8_m (vbool64_t mask, vuint64m1x8_t maskedoff, uint64_t *base) {
  // CHECK-LABEL: test_vlseg8e64ff_v_u64m1x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlseg8e64ff.v.nxv1i64x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg8e64ff_v_u64m1x8_m(mask, maskedoff, *base);
}

vfloat64m1x8_t test_vlseg8e64ff_v_f64m1x8_m (vbool64_t mask, vfloat64m1x8_t maskedoff, float64_t *base) {
  // CHECK-LABEL: test_vlseg8e64ff_v_f64m1x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlseg8e64ff.v.nxv1f32x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}})
  return vlseg8e64ff_v_f64m1x8_m(mask, maskedoff, *base);
}


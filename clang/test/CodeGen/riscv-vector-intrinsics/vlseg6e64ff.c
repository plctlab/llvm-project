// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x6_t test_vlseg6e64ff_v_i64m1x6 (int64_t *base) {
  // CHECK-LABEL: test_vlseg6e64ff_v_i64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlseg6e64ff.v.nxv1i64x6.{{.*}}(i64 %{{.*}})
  return vlseg6e64ff_v_i64m1x6(*base);
}

vuint64m1x6_t test_vlseg6e64ff_v_u64m1x6 (uint64_t *base) {
  // CHECK-LABEL: test_vlseg6e64ff_v_u64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlseg6e64ff.v.nxv1i64x6.{{.*}}(i64 %{{.*}})
  return vlseg6e64ff_v_u64m1x6(*base);
}

vfloat64m1x6_t test_vlseg6e64ff_v_f64m1x6 (float64_t *base) {
  // CHECK-LABEL: test_vlseg6e64ff_v_f64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vlseg6e64ff.v.nxv1f32x6.{{.*}}(double %{{.*}})
  return vlseg6e64ff_v_f64m1x6(*base);
}

vint64m1x6_t test_vlseg6e64ff_v_i64m1x6_m (vbool64_t mask, vint64m1x6_t maskedoff, int64_t *base) {
  // CHECK-LABEL: test_vlseg6e64ff_v_i64m1x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlseg6e64ff.v.nxv1i64x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg6e64ff_v_i64m1x6_m(mask, maskedoff, *base);
}

vuint64m1x6_t test_vlseg6e64ff_v_u64m1x6_m (vbool64_t mask, vuint64m1x6_t maskedoff, uint64_t *base) {
  // CHECK-LABEL: test_vlseg6e64ff_v_u64m1x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlseg6e64ff.v.nxv1i64x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg6e64ff_v_u64m1x6_m(mask, maskedoff, *base);
}

vfloat64m1x6_t test_vlseg6e64ff_v_f64m1x6_m (vbool64_t mask, vfloat64m1x6_t maskedoff, float64_t *base) {
  // CHECK-LABEL: test_vlseg6e64ff_v_f64m1x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vlseg6e64ff.v.nxv1f32x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x double> %{{.*}}, double %{{.*}})
  return vlseg6e64ff_v_f64m1x6_m(mask, maskedoff, *base);
}


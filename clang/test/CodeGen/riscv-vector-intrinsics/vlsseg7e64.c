// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x7_t test_vlsseg7e64_v_i64m1x7 (int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e64_v_i64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vlsseg7e64.v.nxv1i64x7.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg7e64_v_i64m1x7(*base, bstride);
}

vuint64m1x7_t test_vlsseg7e64_v_u64m1x7 (uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e64_v_u64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vlsseg7e64.v.nxv1i64x7.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg7e64_v_u64m1x7(*base, bstride);
}

vfloat64m1x7_t test_vlsseg7e64_v_f64m1x7 (float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e64_v_f64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x double> @llvm.riscv.vlsseg7e64.v.nxv1f32x7.{{.*}}(double %{{.*}}, i64 %{{.*}})
  return vlsseg7e64_v_f64m1x7(*base, bstride);
}

vint64m1x7_t test_vlsseg7e64_v_i64m1x7_m (vbool64_t mask, vint64m1x7_t maskedoff, int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e64_v_i64m1x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vlsseg7e64.v.nxv1i64x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg7e64_v_i64m1x7_m(mask, maskedoff, *base, bstride);
}

vuint64m1x7_t test_vlsseg7e64_v_u64m1x7_m (vbool64_t mask, vuint64m1x7_t maskedoff, uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e64_v_u64m1x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vlsseg7e64.v.nxv1i64x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg7e64_v_u64m1x7_m(mask, maskedoff, *base, bstride);
}

vfloat64m1x7_t test_vlsseg7e64_v_f64m1x7_m (vbool64_t mask, vfloat64m1x7_t maskedoff, float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e64_v_f64m1x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x double> @llvm.riscv.vlsseg7e64.v.nxv1f32x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x double> %{{.*}}, double %{{.*}}, i64 %{{.*}})
  return vlsseg7e64_v_f64m1x7_m(mask, maskedoff, *base, bstride);
}


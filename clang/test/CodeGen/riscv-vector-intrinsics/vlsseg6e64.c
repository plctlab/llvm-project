// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x6_t test_vlsseg6e64_v_i64m1x6 (int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e64_v_i64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlsseg6e64.v.nxv1i64x6.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg6e64_v_i64m1x6(*base, bstride);
}

vuint64m1x6_t test_vlsseg6e64_v_u64m1x6 (uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e64_v_u64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlsseg6e64.v.nxv1i64x6.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg6e64_v_u64m1x6(*base, bstride);
}

vfloat64m1x6_t test_vlsseg6e64_v_f64m1x6 (float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e64_v_f64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vlsseg6e64.v.nxv1f32x6.{{.*}}(double %{{.*}}, i64 %{{.*}})
  return vlsseg6e64_v_f64m1x6(*base, bstride);
}

vint64m1x6_t test_vlsseg6e64_v_i64m1x6_m (vbool64_t mask, vint64m1x6_t maskedoff, int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e64_v_i64m1x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlsseg6e64.v.nxv1i64x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg6e64_v_i64m1x6_m(mask, maskedoff, *base, bstride);
}

vuint64m1x6_t test_vlsseg6e64_v_u64m1x6_m (vbool64_t mask, vuint64m1x6_t maskedoff, uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e64_v_u64m1x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlsseg6e64.v.nxv1i64x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg6e64_v_u64m1x6_m(mask, maskedoff, *base, bstride);
}

vfloat64m1x6_t test_vlsseg6e64_v_f64m1x6_m (vbool64_t mask, vfloat64m1x6_t maskedoff, float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e64_v_f64m1x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vlsseg6e64.v.nxv1f32x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x double> %{{.*}}, double %{{.*}}, i64 %{{.*}})
  return vlsseg6e64_v_f64m1x6_m(mask, maskedoff, *base, bstride);
}


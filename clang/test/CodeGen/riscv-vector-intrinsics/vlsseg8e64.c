// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x8_t test_vlsseg8e64_v_i64m1x8 (int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e64_v_i64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlsseg8e64.v.nxv1i64x8.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg8e64_v_i64m1x8(*base, bstride);
}

vuint64m1x8_t test_vlsseg8e64_v_u64m1x8 (uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e64_v_u64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlsseg8e64.v.nxv1i64x8.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg8e64_v_u64m1x8(*base, bstride);
}

vfloat64m1x8_t test_vlsseg8e64_v_f64m1x8 (float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e64_v_f64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlsseg8e64.v.nxv1f32x8.{{.*}}(double %{{.*}}, i64 %{{.*}})
  return vlsseg8e64_v_f64m1x8(*base, bstride);
}

vint64m1x8_t test_vlsseg8e64_v_i64m1x8_m (vbool64_t mask, vint64m1x8_t maskedoff, int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e64_v_i64m1x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlsseg8e64.v.nxv1i64x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg8e64_v_i64m1x8_m(mask, maskedoff, *base, bstride);
}

vuint64m1x8_t test_vlsseg8e64_v_u64m1x8_m (vbool64_t mask, vuint64m1x8_t maskedoff, uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e64_v_u64m1x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlsseg8e64.v.nxv1i64x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg8e64_v_u64m1x8_m(mask, maskedoff, *base, bstride);
}

vfloat64m1x8_t test_vlsseg8e64_v_f64m1x8_m (vbool64_t mask, vfloat64m1x8_t maskedoff, float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e64_v_f64m1x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlsseg8e64.v.nxv1f32x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}}, i64 %{{.*}})
  return vlsseg8e64_v_f64m1x8_m(mask, maskedoff, *base, bstride);
}


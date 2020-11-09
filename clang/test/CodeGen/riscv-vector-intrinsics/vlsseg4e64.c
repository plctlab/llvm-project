// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x4_t test_vlsseg4e64_v_i64m1x4 (int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_i64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlsseg4e64.v.nxv1i64x4.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_i64m1x4(*base, bstride);
}

vint64m2x4_t test_vlsseg4e64_v_i64m2x4 (int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_i64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlsseg4e64.v.nxv2i64x4.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_i64m2x4(*base, bstride);
}

vuint64m1x4_t test_vlsseg4e64_v_u64m1x4 (uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_u64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlsseg4e64.v.nxv1i64x4.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_u64m1x4(*base, bstride);
}

vuint64m2x4_t test_vlsseg4e64_v_u64m2x4 (uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_u64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlsseg4e64.v.nxv2i64x4.{{.*}}(i64 %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_u64m2x4(*base, bstride);
}

vfloat64m1x4_t test_vlsseg4e64_v_f64m1x4 (float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_f64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vlsseg4e64.v.nxv1f32x4.{{.*}}(double %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_f64m1x4(*base, bstride);
}

vfloat64m2x4_t test_vlsseg4e64_v_f64m2x4 (float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_f64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlsseg4e64.v.nxv2f32x4.{{.*}}(double %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_f64m2x4(*base, bstride);
}

vint64m1x4_t test_vlsseg4e64_v_i64m1x4_m (vbool64_t mask, vint64m1x4_t maskedoff, int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_i64m1x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlsseg4e64.v.nxv1i64x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_i64m1x4_m(mask, maskedoff, *base, bstride);
}

vint64m2x4_t test_vlsseg4e64_v_i64m2x4_m (vbool32_t mask, vint64m2x4_t maskedoff, int64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_i64m2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlsseg4e64.v.nxv2i64x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_i64m2x4_m(mask, maskedoff, *base, bstride);
}

vuint64m1x4_t test_vlsseg4e64_v_u64m1x4_m (vbool64_t mask, vuint64m1x4_t maskedoff, uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_u64m1x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlsseg4e64.v.nxv1i64x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_u64m1x4_m(mask, maskedoff, *base, bstride);
}

vuint64m2x4_t test_vlsseg4e64_v_u64m2x4_m (vbool32_t mask, vuint64m2x4_t maskedoff, uint64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_u64m2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlsseg4e64.v.nxv2i64x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_u64m2x4_m(mask, maskedoff, *base, bstride);
}

vfloat64m1x4_t test_vlsseg4e64_v_f64m1x4_m (vbool64_t mask, vfloat64m1x4_t maskedoff, float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_f64m1x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vlsseg4e64.v.nxv1f32x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, double %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_f64m1x4_m(mask, maskedoff, *base, bstride);
}

vfloat64m2x4_t test_vlsseg4e64_v_f64m2x4_m (vbool32_t mask, vfloat64m2x4_t maskedoff, float64_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e64_v_f64m2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlsseg4e64.v.nxv2f32x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}}, i64 %{{.*}})
  return vlsseg4e64_v_f64m2x4_m(mask, maskedoff, *base, bstride);
}


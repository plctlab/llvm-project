// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x3_t test_vlseg3e64ff_v_i64m1x3 (int64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_i64m1x3
  // CHECK: %{{.*}} = call <vscale x 3 x i64> @llvm.riscv.vlseg3e64ff.v.nxv1i64x3.{{.*}}(i64 %{{.*}})
  return vlseg3e64ff_v_i64m1x3(*base);
}

vint64m2x3_t test_vlseg3e64ff_v_i64m2x3 (int64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_i64m2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlseg3e64ff.v.nxv2i64x3.{{.*}}(i64 %{{.*}})
  return vlseg3e64ff_v_i64m2x3(*base);
}

vuint64m1x3_t test_vlseg3e64ff_v_u64m1x3 (uint64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_u64m1x3
  // CHECK: %{{.*}} = call <vscale x 3 x i64> @llvm.riscv.vlseg3e64ff.v.nxv1i64x3.{{.*}}(i64 %{{.*}})
  return vlseg3e64ff_v_u64m1x3(*base);
}

vuint64m2x3_t test_vlseg3e64ff_v_u64m2x3 (uint64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_u64m2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlseg3e64ff.v.nxv2i64x3.{{.*}}(i64 %{{.*}})
  return vlseg3e64ff_v_u64m2x3(*base);
}

vfloat64m1x3_t test_vlseg3e64ff_v_f64m1x3 (float64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_f64m1x3
  // CHECK: %{{.*}} = call <vscale x 3 x double> @llvm.riscv.vlseg3e64ff.v.nxv1f32x3.{{.*}}(double %{{.*}})
  return vlseg3e64ff_v_f64m1x3(*base);
}

vfloat64m2x3_t test_vlseg3e64ff_v_f64m2x3 (float64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_f64m2x3
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vlseg3e64ff.v.nxv2f32x3.{{.*}}(double %{{.*}})
  return vlseg3e64ff_v_f64m2x3(*base);
}

vint64m1x3_t test_vlseg3e64ff_v_i64m1x3_m (vbool64_t mask, vint64m1x3_t maskedoff, int64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_i64m1x3_m
  // CHECK: %{{.*}} = call <vscale x 3 x i64> @llvm.riscv.vlseg3e64ff.v.nxv1i64x3.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 3 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg3e64ff_v_i64m1x3_m(mask, maskedoff, *base);
}

vint64m2x3_t test_vlseg3e64ff_v_i64m2x3_m (vbool32_t mask, vint64m2x3_t maskedoff, int64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_i64m2x3_m
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlseg3e64ff.v.nxv2i64x3.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 6 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg3e64ff_v_i64m2x3_m(mask, maskedoff, *base);
}

vuint64m1x3_t test_vlseg3e64ff_v_u64m1x3_m (vbool64_t mask, vuint64m1x3_t maskedoff, uint64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_u64m1x3_m
  // CHECK: %{{.*}} = call <vscale x 3 x i64> @llvm.riscv.vlseg3e64ff.v.nxv1i64x3.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 3 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg3e64ff_v_u64m1x3_m(mask, maskedoff, *base);
}

vuint64m2x3_t test_vlseg3e64ff_v_u64m2x3_m (vbool32_t mask, vuint64m2x3_t maskedoff, uint64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_u64m2x3_m
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vlseg3e64ff.v.nxv2i64x3.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 6 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg3e64ff_v_u64m2x3_m(mask, maskedoff, *base);
}

vfloat64m1x3_t test_vlseg3e64ff_v_f64m1x3_m (vbool64_t mask, vfloat64m1x3_t maskedoff, float64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_f64m1x3_m
  // CHECK: %{{.*}} = call <vscale x 3 x double> @llvm.riscv.vlseg3e64ff.v.nxv1f32x3.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 3 x double> %{{.*}}, double %{{.*}})
  return vlseg3e64ff_v_f64m1x3_m(mask, maskedoff, *base);
}

vfloat64m2x3_t test_vlseg3e64ff_v_f64m2x3_m (vbool32_t mask, vfloat64m2x3_t maskedoff, float64_t *base) {
  // CHECK-LABEL: test_vlseg3e64ff_v_f64m2x3_m
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vlseg3e64ff.v.nxv2f32x3.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 6 x double> %{{.*}}, double %{{.*}})
  return vlseg3e64ff_v_f64m2x3_m(mask, maskedoff, *base);
}


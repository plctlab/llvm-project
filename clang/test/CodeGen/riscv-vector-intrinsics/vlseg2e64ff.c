// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint64m1x2_t test_vlseg2e64ff_v_i64m1x2 (int64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_i64m1x2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vlseg2e64ff.v.nxv1i64x2.{{.*}}(i64 %{{.*}})
  return vlseg2e64ff_v_i64m1x2(*base);
}

vint64m2x2_t test_vlseg2e64ff_v_i64m2x2 (int64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_i64m2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlseg2e64ff.v.nxv2i64x2.{{.*}}(i64 %{{.*}})
  return vlseg2e64ff_v_i64m2x2(*base);
}

vint64m4x2_t test_vlseg2e64ff_v_i64m4x2 (int64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_i64m4x2
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlseg2e64ff.v.nxv4i64x2.{{.*}}(i64 %{{.*}})
  return vlseg2e64ff_v_i64m4x2(*base);
}

vuint64m1x2_t test_vlseg2e64ff_v_u64m1x2 (uint64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_u64m1x2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vlseg2e64ff.v.nxv1i64x2.{{.*}}(i64 %{{.*}})
  return vlseg2e64ff_v_u64m1x2(*base);
}

vuint64m2x2_t test_vlseg2e64ff_v_u64m2x2 (uint64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_u64m2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlseg2e64ff.v.nxv2i64x2.{{.*}}(i64 %{{.*}})
  return vlseg2e64ff_v_u64m2x2(*base);
}

vuint64m4x2_t test_vlseg2e64ff_v_u64m4x2 (uint64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_u64m4x2
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlseg2e64ff.v.nxv4i64x2.{{.*}}(i64 %{{.*}})
  return vlseg2e64ff_v_u64m4x2(*base);
}

vfloat64m1x2_t test_vlseg2e64ff_v_f64m1x2 (float64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_f64m1x2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vlseg2e64ff.v.nxv1f32x2.{{.*}}(double %{{.*}})
  return vlseg2e64ff_v_f64m1x2(*base);
}

vfloat64m2x2_t test_vlseg2e64ff_v_f64m2x2 (float64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_f64m2x2
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vlseg2e64ff.v.nxv2f32x2.{{.*}}(double %{{.*}})
  return vlseg2e64ff_v_f64m2x2(*base);
}

vfloat64m4x2_t test_vlseg2e64ff_v_f64m4x2 (float64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_f64m4x2
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlseg2e64ff.v.nxv4f32x2.{{.*}}(double %{{.*}})
  return vlseg2e64ff_v_f64m4x2(*base);
}

vint64m1x2_t test_vlseg2e64ff_v_i64m1x2_m (vbool64_t mask, vint64m1x2_t maskedoff, int64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_i64m1x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vlseg2e64ff.v.nxv1i64x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg2e64ff_v_i64m1x2_m(mask, maskedoff, *base);
}

vint64m2x2_t test_vlseg2e64ff_v_i64m2x2_m (vbool32_t mask, vint64m2x2_t maskedoff, int64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_i64m2x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlseg2e64ff.v.nxv2i64x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg2e64ff_v_i64m2x2_m(mask, maskedoff, *base);
}

vint64m4x2_t test_vlseg2e64ff_v_i64m4x2_m (vbool16_t mask, vint64m4x2_t maskedoff, int64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_i64m4x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlseg2e64ff.v.nxv4i64x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg2e64ff_v_i64m4x2_m(mask, maskedoff, *base);
}

vuint64m1x2_t test_vlseg2e64ff_v_u64m1x2_m (vbool64_t mask, vuint64m1x2_t maskedoff, uint64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_u64m1x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vlseg2e64ff.v.nxv1i64x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg2e64ff_v_u64m1x2_m(mask, maskedoff, *base);
}

vuint64m2x2_t test_vlseg2e64ff_v_u64m2x2_m (vbool32_t mask, vuint64m2x2_t maskedoff, uint64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_u64m2x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlseg2e64ff.v.nxv2i64x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg2e64ff_v_u64m2x2_m(mask, maskedoff, *base);
}

vuint64m4x2_t test_vlseg2e64ff_v_u64m4x2_m (vbool16_t mask, vuint64m4x2_t maskedoff, uint64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_u64m4x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlseg2e64ff.v.nxv4i64x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vlseg2e64ff_v_u64m4x2_m(mask, maskedoff, *base);
}

vfloat64m1x2_t test_vlseg2e64ff_v_f64m1x2_m (vbool64_t mask, vfloat64m1x2_t maskedoff, float64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_f64m1x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vlseg2e64ff.v.nxv1f32x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, double %{{.*}})
  return vlseg2e64ff_v_f64m1x2_m(mask, maskedoff, *base);
}

vfloat64m2x2_t test_vlseg2e64ff_v_f64m2x2_m (vbool32_t mask, vfloat64m2x2_t maskedoff, float64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_f64m2x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vlseg2e64ff.v.nxv2f32x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, double %{{.*}})
  return vlseg2e64ff_v_f64m2x2_m(mask, maskedoff, *base);
}

vfloat64m4x2_t test_vlseg2e64ff_v_f64m4x2_m (vbool16_t mask, vfloat64m4x2_t maskedoff, float64_t *base) {
  // CHECK-LABEL: test_vlseg2e64ff_v_f64m4x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlseg2e64ff.v.nxv4f32x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}})
  return vlseg2e64ff_v_f64m4x2_m(mask, maskedoff, *base);
}


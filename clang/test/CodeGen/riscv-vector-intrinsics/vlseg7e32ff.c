// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2x7_t test_vlseg7e32ff_v_i32mf2x7 (int32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_i32mf2x7
  // CHECK: %{{.*}} = call <vscale x 7 x i32> @llvm.riscv.vlseg7e32ff.v.nxv1i32x7.{{.*}}(i32 %{{.*}})
  return vlseg7e32ff_v_i32mf2x7(*base);
}

vint32m1x7_t test_vlseg7e32ff_v_i32m1x7 (int32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_i32m1x7
  // CHECK: %{{.*}} = call <vscale x 14 x i32> @llvm.riscv.vlseg7e32ff.v.nxv2i32x7.{{.*}}(i32 %{{.*}})
  return vlseg7e32ff_v_i32m1x7(*base);
}

vuint32mf2x7_t test_vlseg7e32ff_v_u32mf2x7 (uint32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_u32mf2x7
  // CHECK: %{{.*}} = call <vscale x 7 x i32> @llvm.riscv.vlseg7e32ff.v.nxv1i32x7.{{.*}}(i32 %{{.*}})
  return vlseg7e32ff_v_u32mf2x7(*base);
}

vuint32m1x7_t test_vlseg7e32ff_v_u32m1x7 (uint32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_u32m1x7
  // CHECK: %{{.*}} = call <vscale x 14 x i32> @llvm.riscv.vlseg7e32ff.v.nxv2i32x7.{{.*}}(i32 %{{.*}})
  return vlseg7e32ff_v_u32m1x7(*base);
}

vfloat32mf2x7_t test_vlseg7e32ff_v_f32mf2x7 (float32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_f32mf2x7
  // CHECK: %{{.*}} = call <vscale x 7 x float> @llvm.riscv.vlseg7e32ff.v.nxv1f32x7.{{.*}}(float %{{.*}})
  return vlseg7e32ff_v_f32mf2x7(*base);
}

vfloat32m1x7_t test_vlseg7e32ff_v_f32m1x7 (float32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_f32m1x7
  // CHECK: %{{.*}} = call <vscale x 14 x float> @llvm.riscv.vlseg7e32ff.v.nxv2f32x7.{{.*}}(float %{{.*}})
  return vlseg7e32ff_v_f32m1x7(*base);
}

vint32mf2x7_t test_vlseg7e32ff_v_i32mf2x7_m (vbool64_t mask, vint32mf2x7_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_i32mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i32> @llvm.riscv.vlseg7e32ff.v.nxv1i32x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg7e32ff_v_i32mf2x7_m(mask, maskedoff, *base);
}

vint32m1x7_t test_vlseg7e32ff_v_i32m1x7_m (vbool32_t mask, vint32m1x7_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_i32m1x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x i32> @llvm.riscv.vlseg7e32ff.v.nxv2i32x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg7e32ff_v_i32m1x7_m(mask, maskedoff, *base);
}

vuint32mf2x7_t test_vlseg7e32ff_v_u32mf2x7_m (vbool64_t mask, vuint32mf2x7_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_u32mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i32> @llvm.riscv.vlseg7e32ff.v.nxv1i32x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg7e32ff_v_u32mf2x7_m(mask, maskedoff, *base);
}

vuint32m1x7_t test_vlseg7e32ff_v_u32m1x7_m (vbool32_t mask, vuint32m1x7_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_u32m1x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x i32> @llvm.riscv.vlseg7e32ff.v.nxv2i32x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg7e32ff_v_u32m1x7_m(mask, maskedoff, *base);
}

vfloat32mf2x7_t test_vlseg7e32ff_v_f32mf2x7_m (vbool64_t mask, vfloat32mf2x7_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_f32mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x float> @llvm.riscv.vlseg7e32ff.v.nxv1f32x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x float> %{{.*}}, float %{{.*}})
  return vlseg7e32ff_v_f32mf2x7_m(mask, maskedoff, *base);
}

vfloat32m1x7_t test_vlseg7e32ff_v_f32m1x7_m (vbool32_t mask, vfloat32m1x7_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vlseg7e32ff_v_f32m1x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x float> @llvm.riscv.vlseg7e32ff.v.nxv2f32x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x float> %{{.*}}, float %{{.*}})
  return vlseg7e32ff_v_f32m1x7_m(mask, maskedoff, *base);
}


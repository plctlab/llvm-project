// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2x5_t test_vlseg5e32_v_i32mf2x5 (int32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_i32mf2x5
  // CHECK: %{{.*}} = call <vscale x 5 x i32> @llvm.riscv.vlseg5e32.v.nxv1i32x5.{{.*}}(i32 %{{.*}})
  return vlseg5e32_v_i32mf2x5(*base);
}

vint32m1x5_t test_vlseg5e32_v_i32m1x5 (int32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_i32m1x5
  // CHECK: %{{.*}} = call <vscale x 10 x i32> @llvm.riscv.vlseg5e32.v.nxv2i32x5.{{.*}}(i32 %{{.*}})
  return vlseg5e32_v_i32m1x5(*base);
}

vuint32mf2x5_t test_vlseg5e32_v_u32mf2x5 (uint32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_u32mf2x5
  // CHECK: %{{.*}} = call <vscale x 5 x i32> @llvm.riscv.vlseg5e32.v.nxv1i32x5.{{.*}}(i32 %{{.*}})
  return vlseg5e32_v_u32mf2x5(*base);
}

vuint32m1x5_t test_vlseg5e32_v_u32m1x5 (uint32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_u32m1x5
  // CHECK: %{{.*}} = call <vscale x 10 x i32> @llvm.riscv.vlseg5e32.v.nxv2i32x5.{{.*}}(i32 %{{.*}})
  return vlseg5e32_v_u32m1x5(*base);
}

vfloat32mf2x5_t test_vlseg5e32_v_f32mf2x5 (float32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_f32mf2x5
  // CHECK: %{{.*}} = call <vscale x 5 x float> @llvm.riscv.vlseg5e32.v.nxv1f32x5.{{.*}}(float %{{.*}})
  return vlseg5e32_v_f32mf2x5(*base);
}

vfloat32m1x5_t test_vlseg5e32_v_f32m1x5 (float32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_f32m1x5
  // CHECK: %{{.*}} = call <vscale x 10 x float> @llvm.riscv.vlseg5e32.v.nxv2f32x5.{{.*}}(float %{{.*}})
  return vlseg5e32_v_f32m1x5(*base);
}

vint32mf2x5_t test_vlseg5e32_v_i32mf2x5_m (vbool64_t mask, vint32mf2x5_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_i32mf2x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x i32> @llvm.riscv.vlseg5e32.v.nxv1i32x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg5e32_v_i32mf2x5_m(mask, maskedoff, *base);
}

vint32m1x5_t test_vlseg5e32_v_i32m1x5_m (vbool32_t mask, vint32m1x5_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_i32m1x5_m
  // CHECK: %{{.*}} = call <vscale x 10 x i32> @llvm.riscv.vlseg5e32.v.nxv2i32x5.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 10 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg5e32_v_i32m1x5_m(mask, maskedoff, *base);
}

vuint32mf2x5_t test_vlseg5e32_v_u32mf2x5_m (vbool64_t mask, vuint32mf2x5_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_u32mf2x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x i32> @llvm.riscv.vlseg5e32.v.nxv1i32x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg5e32_v_u32mf2x5_m(mask, maskedoff, *base);
}

vuint32m1x5_t test_vlseg5e32_v_u32m1x5_m (vbool32_t mask, vuint32m1x5_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_u32m1x5_m
  // CHECK: %{{.*}} = call <vscale x 10 x i32> @llvm.riscv.vlseg5e32.v.nxv2i32x5.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 10 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg5e32_v_u32m1x5_m(mask, maskedoff, *base);
}

vfloat32mf2x5_t test_vlseg5e32_v_f32mf2x5_m (vbool64_t mask, vfloat32mf2x5_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_f32mf2x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x float> @llvm.riscv.vlseg5e32.v.nxv1f32x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x float> %{{.*}}, float %{{.*}})
  return vlseg5e32_v_f32mf2x5_m(mask, maskedoff, *base);
}

vfloat32m1x5_t test_vlseg5e32_v_f32m1x5_m (vbool32_t mask, vfloat32m1x5_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vlseg5e32_v_f32m1x5_m
  // CHECK: %{{.*}} = call <vscale x 10 x float> @llvm.riscv.vlseg5e32.v.nxv2f32x5.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 10 x float> %{{.*}}, float %{{.*}})
  return vlseg5e32_v_f32m1x5_m(mask, maskedoff, *base);
}


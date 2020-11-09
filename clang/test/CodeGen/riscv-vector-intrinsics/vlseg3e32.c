// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2x3_t test_vlseg3e32_v_i32mf2x3 (int32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_i32mf2x3
  // CHECK: %{{.*}} = call <vscale x 3 x i32> @llvm.riscv.vlseg3e32.v.nxv1i32x3.{{.*}}(i32 %{{.*}})
  return vlseg3e32_v_i32mf2x3(*base);
}

vint32m1x3_t test_vlseg3e32_v_i32m1x3 (int32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_i32m1x3
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlseg3e32.v.nxv2i32x3.{{.*}}(i32 %{{.*}})
  return vlseg3e32_v_i32m1x3(*base);
}

vint32m2x3_t test_vlseg3e32_v_i32m2x3 (int32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_i32m2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlseg3e32.v.nxv4i32x3.{{.*}}(i32 %{{.*}})
  return vlseg3e32_v_i32m2x3(*base);
}

vuint32mf2x3_t test_vlseg3e32_v_u32mf2x3 (uint32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_u32mf2x3
  // CHECK: %{{.*}} = call <vscale x 3 x i32> @llvm.riscv.vlseg3e32.v.nxv1i32x3.{{.*}}(i32 %{{.*}})
  return vlseg3e32_v_u32mf2x3(*base);
}

vuint32m1x3_t test_vlseg3e32_v_u32m1x3 (uint32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_u32m1x3
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlseg3e32.v.nxv2i32x3.{{.*}}(i32 %{{.*}})
  return vlseg3e32_v_u32m1x3(*base);
}

vuint32m2x3_t test_vlseg3e32_v_u32m2x3 (uint32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_u32m2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlseg3e32.v.nxv4i32x3.{{.*}}(i32 %{{.*}})
  return vlseg3e32_v_u32m2x3(*base);
}

vfloat32mf2x3_t test_vlseg3e32_v_f32mf2x3 (float32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_f32mf2x3
  // CHECK: %{{.*}} = call <vscale x 3 x float> @llvm.riscv.vlseg3e32.v.nxv1f32x3.{{.*}}(float %{{.*}})
  return vlseg3e32_v_f32mf2x3(*base);
}

vfloat32m1x3_t test_vlseg3e32_v_f32m1x3 (float32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_f32m1x3
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vlseg3e32.v.nxv2f32x3.{{.*}}(float %{{.*}})
  return vlseg3e32_v_f32m1x3(*base);
}

vfloat32m2x3_t test_vlseg3e32_v_f32m2x3 (float32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_f32m2x3
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vlseg3e32.v.nxv4f32x3.{{.*}}(float %{{.*}})
  return vlseg3e32_v_f32m2x3(*base);
}

vint32mf2x3_t test_vlseg3e32_v_i32mf2x3_m (vbool64_t mask, vint32mf2x3_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_i32mf2x3_m
  // CHECK: %{{.*}} = call <vscale x 3 x i32> @llvm.riscv.vlseg3e32.v.nxv1i32x3.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 3 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg3e32_v_i32mf2x3_m(mask, maskedoff, *base);
}

vint32m1x3_t test_vlseg3e32_v_i32m1x3_m (vbool32_t mask, vint32m1x3_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_i32m1x3_m
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlseg3e32.v.nxv2i32x3.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 6 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg3e32_v_i32m1x3_m(mask, maskedoff, *base);
}

vint32m2x3_t test_vlseg3e32_v_i32m2x3_m (vbool16_t mask, vint32m2x3_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_i32m2x3_m
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlseg3e32.v.nxv4i32x3.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 12 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg3e32_v_i32m2x3_m(mask, maskedoff, *base);
}

vuint32mf2x3_t test_vlseg3e32_v_u32mf2x3_m (vbool64_t mask, vuint32mf2x3_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_u32mf2x3_m
  // CHECK: %{{.*}} = call <vscale x 3 x i32> @llvm.riscv.vlseg3e32.v.nxv1i32x3.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 3 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg3e32_v_u32mf2x3_m(mask, maskedoff, *base);
}

vuint32m1x3_t test_vlseg3e32_v_u32m1x3_m (vbool32_t mask, vuint32m1x3_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_u32m1x3_m
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlseg3e32.v.nxv2i32x3.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 6 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg3e32_v_u32m1x3_m(mask, maskedoff, *base);
}

vuint32m2x3_t test_vlseg3e32_v_u32m2x3_m (vbool16_t mask, vuint32m2x3_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_u32m2x3_m
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlseg3e32.v.nxv4i32x3.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 12 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg3e32_v_u32m2x3_m(mask, maskedoff, *base);
}

vfloat32mf2x3_t test_vlseg3e32_v_f32mf2x3_m (vbool64_t mask, vfloat32mf2x3_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_f32mf2x3_m
  // CHECK: %{{.*}} = call <vscale x 3 x float> @llvm.riscv.vlseg3e32.v.nxv1f32x3.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 3 x float> %{{.*}}, float %{{.*}})
  return vlseg3e32_v_f32mf2x3_m(mask, maskedoff, *base);
}

vfloat32m1x3_t test_vlseg3e32_v_f32m1x3_m (vbool32_t mask, vfloat32m1x3_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_f32m1x3_m
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vlseg3e32.v.nxv2f32x3.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 6 x float> %{{.*}}, float %{{.*}})
  return vlseg3e32_v_f32m1x3_m(mask, maskedoff, *base);
}

vfloat32m2x3_t test_vlseg3e32_v_f32m2x3_m (vbool16_t mask, vfloat32m2x3_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vlseg3e32_v_f32m2x3_m
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vlseg3e32.v.nxv4f32x3.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 12 x float> %{{.*}}, float %{{.*}})
  return vlseg3e32_v_f32m2x3_m(mask, maskedoff, *base);
}


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2x2_t test_vlsseg2e32_v_i32mf2x2 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_i32mf2x2
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlsseg2e32.v.nxv1i32x2.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_i32mf2x2(*base, bstride);
}

vint32m1x2_t test_vlsseg2e32_v_i32m1x2 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_i32m1x2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlsseg2e32.v.nxv2i32x2.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_i32m1x2(*base, bstride);
}

vint32m2x2_t test_vlsseg2e32_v_i32m2x2 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_i32m2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg2e32.v.nxv4i32x2.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_i32m2x2(*base, bstride);
}

vint32m4x2_t test_vlsseg2e32_v_i32m4x2 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_i32m4x2
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg2e32.v.nxv8i32x2.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_i32m4x2(*base, bstride);
}

vuint32mf2x2_t test_vlsseg2e32_v_u32mf2x2 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_u32mf2x2
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlsseg2e32.v.nxv1i32x2.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_u32mf2x2(*base, bstride);
}

vuint32m1x2_t test_vlsseg2e32_v_u32m1x2 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_u32m1x2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlsseg2e32.v.nxv2i32x2.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_u32m1x2(*base, bstride);
}

vuint32m2x2_t test_vlsseg2e32_v_u32m2x2 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_u32m2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg2e32.v.nxv4i32x2.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_u32m2x2(*base, bstride);
}

vuint32m4x2_t test_vlsseg2e32_v_u32m4x2 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_u32m4x2
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg2e32.v.nxv8i32x2.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_u32m4x2(*base, bstride);
}

vfloat32mf2x2_t test_vlsseg2e32_v_f32mf2x2 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_f32mf2x2
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vlsseg2e32.v.nxv1f32x2.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_f32mf2x2(*base, bstride);
}

vfloat32m1x2_t test_vlsseg2e32_v_f32m1x2 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_f32m1x2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlsseg2e32.v.nxv2f32x2.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_f32m1x2(*base, bstride);
}

vfloat32m2x2_t test_vlsseg2e32_v_f32m2x2 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_f32m2x2
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlsseg2e32.v.nxv4f32x2.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_f32m2x2(*base, bstride);
}

vfloat32m4x2_t test_vlsseg2e32_v_f32m4x2 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_f32m4x2
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlsseg2e32.v.nxv8f32x2.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_f32m4x2(*base, bstride);
}

vint32mf2x2_t test_vlsseg2e32_v_i32mf2x2_m (vbool64_t mask, vint32mf2x2_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_i32mf2x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlsseg2e32.v.nxv1i32x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_i32mf2x2_m(mask, maskedoff, *base, bstride);
}

vint32m1x2_t test_vlsseg2e32_v_i32m1x2_m (vbool32_t mask, vint32m1x2_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_i32m1x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlsseg2e32.v.nxv2i32x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_i32m1x2_m(mask, maskedoff, *base, bstride);
}

vint32m2x2_t test_vlsseg2e32_v_i32m2x2_m (vbool16_t mask, vint32m2x2_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_i32m2x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg2e32.v.nxv4i32x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_i32m2x2_m(mask, maskedoff, *base, bstride);
}

vint32m4x2_t test_vlsseg2e32_v_i32m4x2_m (vbool8_t mask, vint32m4x2_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_i32m4x2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg2e32.v.nxv8i32x2.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_i32m4x2_m(mask, maskedoff, *base, bstride);
}

vuint32mf2x2_t test_vlsseg2e32_v_u32mf2x2_m (vbool64_t mask, vuint32mf2x2_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_u32mf2x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlsseg2e32.v.nxv1i32x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_u32mf2x2_m(mask, maskedoff, *base, bstride);
}

vuint32m1x2_t test_vlsseg2e32_v_u32m1x2_m (vbool32_t mask, vuint32m1x2_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_u32m1x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlsseg2e32.v.nxv2i32x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_u32m1x2_m(mask, maskedoff, *base, bstride);
}

vuint32m2x2_t test_vlsseg2e32_v_u32m2x2_m (vbool16_t mask, vuint32m2x2_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_u32m2x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg2e32.v.nxv4i32x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_u32m2x2_m(mask, maskedoff, *base, bstride);
}

vuint32m4x2_t test_vlsseg2e32_v_u32m4x2_m (vbool8_t mask, vuint32m4x2_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_u32m4x2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg2e32.v.nxv8i32x2.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_u32m4x2_m(mask, maskedoff, *base, bstride);
}

vfloat32mf2x2_t test_vlsseg2e32_v_f32mf2x2_m (vbool64_t mask, vfloat32mf2x2_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_f32mf2x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vlsseg2e32.v.nxv1f32x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_f32mf2x2_m(mask, maskedoff, *base, bstride);
}

vfloat32m1x2_t test_vlsseg2e32_v_f32m1x2_m (vbool32_t mask, vfloat32m1x2_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_f32m1x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlsseg2e32.v.nxv2f32x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_f32m1x2_m(mask, maskedoff, *base, bstride);
}

vfloat32m2x2_t test_vlsseg2e32_v_f32m2x2_m (vbool16_t mask, vfloat32m2x2_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_f32m2x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlsseg2e32.v.nxv4f32x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_f32m2x2_m(mask, maskedoff, *base, bstride);
}

vfloat32m4x2_t test_vlsseg2e32_v_f32m4x2_m (vbool8_t mask, vfloat32m4x2_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg2e32_v_f32m4x2_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlsseg2e32.v.nxv8f32x2.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg2e32_v_f32m4x2_m(mask, maskedoff, *base, bstride);
}


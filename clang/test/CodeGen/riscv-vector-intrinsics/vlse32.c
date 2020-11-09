// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2_t test_vlse32_v_i32mf2 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vlse32.v.nxv1i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32mf2(*base, bstride);
}

vint32m1_t test_vlse32_v_i32m1 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlse32.v.nxv2i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32m1(*base, bstride);
}

vint32m2_t test_vlse32_v_i32m2 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlse32.v.nxv4i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32m2(*base, bstride);
}

vint32m4_t test_vlse32_v_i32m4 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlse32.v.nxv8i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32m4(*base, bstride);
}

vint32m8_t test_vlse32_v_i32m8 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlse32.v.nxv16i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32m8(*base, bstride);
}

vuint32mf2_t test_vlse32_v_u32mf2 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vlse32.v.nxv1i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32mf2(*base, bstride);
}

vuint32m1_t test_vlse32_v_u32m1 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlse32.v.nxv2i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32m1(*base, bstride);
}

vuint32m2_t test_vlse32_v_u32m2 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlse32.v.nxv4i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32m2(*base, bstride);
}

vuint32m4_t test_vlse32_v_u32m4 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlse32.v.nxv8i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32m4(*base, bstride);
}

vuint32m8_t test_vlse32_v_u32m8 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlse32.v.nxv16i32{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32m8(*base, bstride);
}

vfloat32mf2_t test_vlse32_v_f32mf2 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vlse32.v.nxv1f32{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32mf2(*base, bstride);
}

vfloat32m1_t test_vlse32_v_f32m1 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vlse32.v.nxv2f32{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32m1(*base, bstride);
}

vfloat32m2_t test_vlse32_v_f32m2 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlse32.v.nxv4f32{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32m2(*base, bstride);
}

vfloat32m4_t test_vlse32_v_f32m4 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlse32.v.nxv8f32{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32m4(*base, bstride);
}

vfloat32m8_t test_vlse32_v_f32m8 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlse32.v.nxv16f32{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32m8(*base, bstride);
}

vint32mf2_t test_vlse32_v_i32mf2_m (vbool64_t mask, vint32mf2_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vlse32.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32mf2_m(mask, maskedoff, *base, bstride);
}

vint32m1_t test_vlse32_v_i32m1_m (vbool32_t mask, vint32m1_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlse32.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32m1_m(mask, maskedoff, *base, bstride);
}

vint32m2_t test_vlse32_v_i32m2_m (vbool16_t mask, vint32m2_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlse32.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32m2_m(mask, maskedoff, *base, bstride);
}

vint32m4_t test_vlse32_v_i32m4_m (vbool8_t mask, vint32m4_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlse32.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32m4_m(mask, maskedoff, *base, bstride);
}

vint32m8_t test_vlse32_v_i32m8_m (vbool4_t mask, vint32m8_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlse32.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_i32m8_m(mask, maskedoff, *base, bstride);
}

vuint32mf2_t test_vlse32_v_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vlse32.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32mf2_m(mask, maskedoff, *base, bstride);
}

vuint32m1_t test_vlse32_v_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlse32.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32m1_m(mask, maskedoff, *base, bstride);
}

vuint32m2_t test_vlse32_v_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlse32.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32m2_m(mask, maskedoff, *base, bstride);
}

vuint32m4_t test_vlse32_v_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlse32.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32m4_m(mask, maskedoff, *base, bstride);
}

vuint32m8_t test_vlse32_v_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlse32.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlse32_v_u32m8_m(mask, maskedoff, *base, bstride);
}

vfloat32mf2_t test_vlse32_v_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vlse32.v.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32mf2_m(mask, maskedoff, *base, bstride);
}

vfloat32m1_t test_vlse32_v_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vlse32.v.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32m1_m(mask, maskedoff, *base, bstride);
}

vfloat32m2_t test_vlse32_v_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlse32.v.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32m2_m(mask, maskedoff, *base, bstride);
}

vfloat32m4_t test_vlse32_v_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlse32.v.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32m4_m(mask, maskedoff, *base, bstride);
}

vfloat32m8_t test_vlse32_v_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse32_v_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlse32.v.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlse32_v_f32m8_m(mask, maskedoff, *base, bstride);
}


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2x4_t test_vlsseg4e32_v_i32mf2x4 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_i32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlsseg4e32.v.nxv1i32x4.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_i32mf2x4(*base, bstride);
}

vint32m1x4_t test_vlsseg4e32_v_i32m1x4 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_i32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg4e32.v.nxv2i32x4.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_i32m1x4(*base, bstride);
}

vint32m2x4_t test_vlsseg4e32_v_i32m2x4 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_i32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg4e32.v.nxv4i32x4.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_i32m2x4(*base, bstride);
}

vuint32mf2x4_t test_vlsseg4e32_v_u32mf2x4 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_u32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlsseg4e32.v.nxv1i32x4.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_u32mf2x4(*base, bstride);
}

vuint32m1x4_t test_vlsseg4e32_v_u32m1x4 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_u32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg4e32.v.nxv2i32x4.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_u32m1x4(*base, bstride);
}

vuint32m2x4_t test_vlsseg4e32_v_u32m2x4 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_u32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg4e32.v.nxv4i32x4.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_u32m2x4(*base, bstride);
}

vfloat32mf2x4_t test_vlsseg4e32_v_f32mf2x4 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_f32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlsseg4e32.v.nxv1f32x4.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_f32mf2x4(*base, bstride);
}

vfloat32m1x4_t test_vlsseg4e32_v_f32m1x4 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_f32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlsseg4e32.v.nxv2f32x4.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_f32m1x4(*base, bstride);
}

vfloat32m2x4_t test_vlsseg4e32_v_f32m2x4 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_f32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlsseg4e32.v.nxv4f32x4.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_f32m2x4(*base, bstride);
}

vint32mf2x4_t test_vlsseg4e32_v_i32mf2x4_m (vbool64_t mask, vint32mf2x4_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_i32mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlsseg4e32.v.nxv1i32x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_i32mf2x4_m(mask, maskedoff, *base, bstride);
}

vint32m1x4_t test_vlsseg4e32_v_i32m1x4_m (vbool32_t mask, vint32m1x4_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_i32m1x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg4e32.v.nxv2i32x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_i32m1x4_m(mask, maskedoff, *base, bstride);
}

vint32m2x4_t test_vlsseg4e32_v_i32m2x4_m (vbool16_t mask, vint32m2x4_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_i32m2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg4e32.v.nxv4i32x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_i32m2x4_m(mask, maskedoff, *base, bstride);
}

vuint32mf2x4_t test_vlsseg4e32_v_u32mf2x4_m (vbool64_t mask, vuint32mf2x4_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_u32mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlsseg4e32.v.nxv1i32x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_u32mf2x4_m(mask, maskedoff, *base, bstride);
}

vuint32m1x4_t test_vlsseg4e32_v_u32m1x4_m (vbool32_t mask, vuint32m1x4_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_u32m1x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg4e32.v.nxv2i32x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_u32m1x4_m(mask, maskedoff, *base, bstride);
}

vuint32m2x4_t test_vlsseg4e32_v_u32m2x4_m (vbool16_t mask, vuint32m2x4_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_u32m2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg4e32.v.nxv4i32x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_u32m2x4_m(mask, maskedoff, *base, bstride);
}

vfloat32mf2x4_t test_vlsseg4e32_v_f32mf2x4_m (vbool64_t mask, vfloat32mf2x4_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_f32mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlsseg4e32.v.nxv1f32x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_f32mf2x4_m(mask, maskedoff, *base, bstride);
}

vfloat32m1x4_t test_vlsseg4e32_v_f32m1x4_m (vbool32_t mask, vfloat32m1x4_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_f32m1x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlsseg4e32.v.nxv2f32x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_f32m1x4_m(mask, maskedoff, *base, bstride);
}

vfloat32m2x4_t test_vlsseg4e32_v_f32m2x4_m (vbool16_t mask, vfloat32m2x4_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e32_v_f32m2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlsseg4e32.v.nxv4f32x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg4e32_v_f32m2x4_m(mask, maskedoff, *base, bstride);
}


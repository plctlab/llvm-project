// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2x8_t test_vlsseg8e32_v_i32mf2x8 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_i32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg8e32.v.nxv1i32x8.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_i32mf2x8(*base, bstride);
}

vint32m1x8_t test_vlsseg8e32_v_i32m1x8 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_i32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg8e32.v.nxv2i32x8.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_i32m1x8(*base, bstride);
}

vuint32mf2x8_t test_vlsseg8e32_v_u32mf2x8 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_u32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg8e32.v.nxv1i32x8.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_u32mf2x8(*base, bstride);
}

vuint32m1x8_t test_vlsseg8e32_v_u32m1x8 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_u32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg8e32.v.nxv2i32x8.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_u32m1x8(*base, bstride);
}

vfloat32mf2x8_t test_vlsseg8e32_v_f32mf2x8 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_f32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlsseg8e32.v.nxv1f32x8.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_f32mf2x8(*base, bstride);
}

vfloat32m1x8_t test_vlsseg8e32_v_f32m1x8 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_f32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlsseg8e32.v.nxv2f32x8.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_f32m1x8(*base, bstride);
}

vint32mf2x8_t test_vlsseg8e32_v_i32mf2x8_m (vbool64_t mask, vint32mf2x8_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_i32mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg8e32.v.nxv1i32x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_i32mf2x8_m(mask, maskedoff, *base, bstride);
}

vint32m1x8_t test_vlsseg8e32_v_i32m1x8_m (vbool32_t mask, vint32m1x8_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_i32m1x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg8e32.v.nxv2i32x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_i32m1x8_m(mask, maskedoff, *base, bstride);
}

vuint32mf2x8_t test_vlsseg8e32_v_u32mf2x8_m (vbool64_t mask, vuint32mf2x8_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_u32mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlsseg8e32.v.nxv1i32x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_u32mf2x8_m(mask, maskedoff, *base, bstride);
}

vuint32m1x8_t test_vlsseg8e32_v_u32m1x8_m (vbool32_t mask, vuint32m1x8_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_u32m1x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlsseg8e32.v.nxv2i32x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_u32m1x8_m(mask, maskedoff, *base, bstride);
}

vfloat32mf2x8_t test_vlsseg8e32_v_f32mf2x8_m (vbool64_t mask, vfloat32mf2x8_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_f32mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlsseg8e32.v.nxv1f32x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_f32mf2x8_m(mask, maskedoff, *base, bstride);
}

vfloat32m1x8_t test_vlsseg8e32_v_f32m1x8_m (vbool32_t mask, vfloat32m1x8_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg8e32_v_f32m1x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlsseg8e32.v.nxv2f32x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg8e32_v_f32m1x8_m(mask, maskedoff, *base, bstride);
}


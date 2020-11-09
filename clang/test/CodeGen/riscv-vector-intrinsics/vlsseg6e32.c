// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2x6_t test_vlsseg6e32_v_i32mf2x6 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_i32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlsseg6e32.v.nxv1i32x6.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_i32mf2x6(*base, bstride);
}

vint32m1x6_t test_vlsseg6e32_v_i32m1x6 (int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_i32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlsseg6e32.v.nxv2i32x6.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_i32m1x6(*base, bstride);
}

vuint32mf2x6_t test_vlsseg6e32_v_u32mf2x6 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_u32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlsseg6e32.v.nxv1i32x6.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_u32mf2x6(*base, bstride);
}

vuint32m1x6_t test_vlsseg6e32_v_u32m1x6 (uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_u32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlsseg6e32.v.nxv2i32x6.{{.*}}(i32 %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_u32m1x6(*base, bstride);
}

vfloat32mf2x6_t test_vlsseg6e32_v_f32mf2x6 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_f32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vlsseg6e32.v.nxv1f32x6.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_f32mf2x6(*base, bstride);
}

vfloat32m1x6_t test_vlsseg6e32_v_f32m1x6 (float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_f32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vlsseg6e32.v.nxv2f32x6.{{.*}}(float %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_f32m1x6(*base, bstride);
}

vint32mf2x6_t test_vlsseg6e32_v_i32mf2x6_m (vbool64_t mask, vint32mf2x6_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_i32mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlsseg6e32.v.nxv1i32x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_i32mf2x6_m(mask, maskedoff, *base, bstride);
}

vint32m1x6_t test_vlsseg6e32_v_i32m1x6_m (vbool32_t mask, vint32m1x6_t maskedoff, int32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_i32m1x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlsseg6e32.v.nxv2i32x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_i32m1x6_m(mask, maskedoff, *base, bstride);
}

vuint32mf2x6_t test_vlsseg6e32_v_u32mf2x6_m (vbool64_t mask, vuint32mf2x6_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_u32mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlsseg6e32.v.nxv1i32x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_u32mf2x6_m(mask, maskedoff, *base, bstride);
}

vuint32m1x6_t test_vlsseg6e32_v_u32m1x6_m (vbool32_t mask, vuint32m1x6_t maskedoff, uint32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_u32m1x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlsseg6e32.v.nxv2i32x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x i32> %{{.*}}, i32 %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_u32m1x6_m(mask, maskedoff, *base, bstride);
}

vfloat32mf2x6_t test_vlsseg6e32_v_f32mf2x6_m (vbool64_t mask, vfloat32mf2x6_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_f32mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vlsseg6e32.v.nxv1f32x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_f32mf2x6_m(mask, maskedoff, *base, bstride);
}

vfloat32m1x6_t test_vlsseg6e32_v_f32m1x6_m (vbool32_t mask, vfloat32m1x6_t maskedoff, float32_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e32_v_f32m1x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vlsseg6e32.v.nxv2f32x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x float> %{{.*}}, float %{{.*}}, i64 %{{.*}})
  return vlsseg6e32_v_f32m1x6_m(mask, maskedoff, *base, bstride);
}


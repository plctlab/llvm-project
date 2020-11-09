// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2x6_t test_vlseg6e32ff_v_i32mf2x6 (int32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_i32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlseg6e32ff.v.nxv1i32x6.{{.*}}(i32 %{{.*}})
  return vlseg6e32ff_v_i32mf2x6(*base);
}

vint32m1x6_t test_vlseg6e32ff_v_i32m1x6 (int32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_i32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlseg6e32ff.v.nxv2i32x6.{{.*}}(i32 %{{.*}})
  return vlseg6e32ff_v_i32m1x6(*base);
}

vuint32mf2x6_t test_vlseg6e32ff_v_u32mf2x6 (uint32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_u32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlseg6e32ff.v.nxv1i32x6.{{.*}}(i32 %{{.*}})
  return vlseg6e32ff_v_u32mf2x6(*base);
}

vuint32m1x6_t test_vlseg6e32ff_v_u32m1x6 (uint32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_u32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlseg6e32ff.v.nxv2i32x6.{{.*}}(i32 %{{.*}})
  return vlseg6e32ff_v_u32m1x6(*base);
}

vfloat32mf2x6_t test_vlseg6e32ff_v_f32mf2x6 (float32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_f32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vlseg6e32ff.v.nxv1f32x6.{{.*}}(float %{{.*}})
  return vlseg6e32ff_v_f32mf2x6(*base);
}

vfloat32m1x6_t test_vlseg6e32ff_v_f32m1x6 (float32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_f32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vlseg6e32ff.v.nxv2f32x6.{{.*}}(float %{{.*}})
  return vlseg6e32ff_v_f32m1x6(*base);
}

vint32mf2x6_t test_vlseg6e32ff_v_i32mf2x6_m (vbool64_t mask, vint32mf2x6_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_i32mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlseg6e32ff.v.nxv1i32x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg6e32ff_v_i32mf2x6_m(mask, maskedoff, *base);
}

vint32m1x6_t test_vlseg6e32ff_v_i32m1x6_m (vbool32_t mask, vint32m1x6_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_i32m1x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlseg6e32ff.v.nxv2i32x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg6e32ff_v_i32m1x6_m(mask, maskedoff, *base);
}

vuint32mf2x6_t test_vlseg6e32ff_v_u32mf2x6_m (vbool64_t mask, vuint32mf2x6_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_u32mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vlseg6e32ff.v.nxv1i32x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg6e32ff_v_u32mf2x6_m(mask, maskedoff, *base);
}

vuint32m1x6_t test_vlseg6e32ff_v_u32m1x6_m (vbool32_t mask, vuint32m1x6_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_u32m1x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vlseg6e32ff.v.nxv2i32x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x i32> %{{.*}}, i32 %{{.*}})
  return vlseg6e32ff_v_u32m1x6_m(mask, maskedoff, *base);
}

vfloat32mf2x6_t test_vlseg6e32ff_v_f32mf2x6_m (vbool64_t mask, vfloat32mf2x6_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_f32mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vlseg6e32ff.v.nxv1f32x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x float> %{{.*}}, float %{{.*}})
  return vlseg6e32ff_v_f32mf2x6_m(mask, maskedoff, *base);
}

vfloat32m1x6_t test_vlseg6e32ff_v_f32m1x6_m (vbool32_t mask, vfloat32m1x6_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vlseg6e32ff_v_f32m1x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vlseg6e32ff.v.nxv2f32x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x float> %{{.*}}, float %{{.*}})
  return vlseg6e32ff_v_f32m1x6_m(mask, maskedoff, *base);
}


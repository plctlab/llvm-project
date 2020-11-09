// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2_t test_vle32ff_v_i32mf2 (int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vle32ff.v.nxv1i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_i32mf2(*base);
}

vint32m1_t test_vle32ff_v_i32m1 (int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vle32ff.v.nxv2i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_i32m1(*base);
}

vint32m2_t test_vle32ff_v_i32m2 (int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vle32ff.v.nxv4i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_i32m2(*base);
}

vint32m4_t test_vle32ff_v_i32m4 (int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vle32ff.v.nxv8i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_i32m4(*base);
}

vint32m8_t test_vle32ff_v_i32m8 (int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vle32ff.v.nxv16i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_i32m8(*base);
}

vuint32mf2_t test_vle32ff_v_u32mf2 (uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vle32ff.v.nxv1i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_u32mf2(*base);
}

vuint32m1_t test_vle32ff_v_u32m1 (uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vle32ff.v.nxv2i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_u32m1(*base);
}

vuint32m2_t test_vle32ff_v_u32m2 (uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vle32ff.v.nxv4i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_u32m2(*base);
}

vuint32m4_t test_vle32ff_v_u32m4 (uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vle32ff.v.nxv8i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_u32m4(*base);
}

vuint32m8_t test_vle32ff_v_u32m8 (uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vle32ff.v.nxv16i32{{.*}}(i32 %{{.*}})
  return vle32ff_v_u32m8(*base);
}

vfloat32mf2_t test_vle32ff_v_f32mf2 (float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vle32ff.v.nxv1f32{{.*}}(float %{{.*}})
  return vle32ff_v_f32mf2(*base);
}

vfloat32m1_t test_vle32ff_v_f32m1 (float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vle32ff.v.nxv2f32{{.*}}(float %{{.*}})
  return vle32ff_v_f32m1(*base);
}

vfloat32m2_t test_vle32ff_v_f32m2 (float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vle32ff.v.nxv4f32{{.*}}(float %{{.*}})
  return vle32ff_v_f32m2(*base);
}

vfloat32m4_t test_vle32ff_v_f32m4 (float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vle32ff.v.nxv8f32{{.*}}(float %{{.*}})
  return vle32ff_v_f32m4(*base);
}

vfloat32m8_t test_vle32ff_v_f32m8 (float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vle32ff.v.nxv16f32{{.*}}(float %{{.*}})
  return vle32ff_v_f32m8(*base);
}

vint32mf2_t test_vle32ff_v_i32mf2_m (vbool64_t mask, vint32mf2_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vle32ff.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_i32mf2_m(mask, maskedoff, *base);
}

vint32m1_t test_vle32ff_v_i32m1_m (vbool32_t mask, vint32m1_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vle32ff.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_i32m1_m(mask, maskedoff, *base);
}

vint32m2_t test_vle32ff_v_i32m2_m (vbool16_t mask, vint32m2_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vle32ff.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_i32m2_m(mask, maskedoff, *base);
}

vint32m4_t test_vle32ff_v_i32m4_m (vbool8_t mask, vint32m4_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vle32ff.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_i32m4_m(mask, maskedoff, *base);
}

vint32m8_t test_vle32ff_v_i32m8_m (vbool4_t mask, vint32m8_t maskedoff, int32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vle32ff.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_i32m8_m(mask, maskedoff, *base);
}

vuint32mf2_t test_vle32ff_v_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vle32ff.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_u32mf2_m(mask, maskedoff, *base);
}

vuint32m1_t test_vle32ff_v_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vle32ff.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_u32m1_m(mask, maskedoff, *base);
}

vuint32m2_t test_vle32ff_v_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vle32ff.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_u32m2_m(mask, maskedoff, *base);
}

vuint32m4_t test_vle32ff_v_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vle32ff.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_u32m4_m(mask, maskedoff, *base);
}

vuint32m8_t test_vle32ff_v_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, uint32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vle32ff.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vle32ff_v_u32m8_m(mask, maskedoff, *base);
}

vfloat32mf2_t test_vle32ff_v_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vle32ff.v.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vle32ff_v_f32mf2_m(mask, maskedoff, *base);
}

vfloat32m1_t test_vle32ff_v_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vle32ff.v.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vle32ff_v_f32m1_m(mask, maskedoff, *base);
}

vfloat32m2_t test_vle32ff_v_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vle32ff.v.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vle32ff_v_f32m2_m(mask, maskedoff, *base);
}

vfloat32m4_t test_vle32ff_v_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vle32ff.v.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vle32ff_v_f32m4_m(mask, maskedoff, *base);
}

vfloat32m8_t test_vle32ff_v_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, float32_t *base) {
  // CHECK-LABEL: test_vle32ff_v_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vle32ff.v.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vle32ff_v_f32m8_m(mask, maskedoff, *base);
}


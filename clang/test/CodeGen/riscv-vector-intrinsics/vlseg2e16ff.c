// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4x2_t test_vlseg2e16ff_v_i16mf4x2 (int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16mf4x2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vlseg2e16ff.v.nxv1i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_i16mf4x2(*base);
}

vint16mf2x2_t test_vlseg2e16ff_v_i16mf2x2 (int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16mf2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlseg2e16ff.v.nxv2i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_i16mf2x2(*base);
}

vint16m1x2_t test_vlseg2e16ff_v_i16m1x2 (int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16m1x2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg2e16ff.v.nxv4i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_i16m1x2(*base);
}

vint16m2x2_t test_vlseg2e16ff_v_i16m2x2 (int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16m2x2
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg2e16ff.v.nxv8i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_i16m2x2(*base);
}

vint16m4x2_t test_vlseg2e16ff_v_i16m4x2 (int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16m4x2
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg2e16ff.v.nxv16i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_i16m4x2(*base);
}

vuint16mf4x2_t test_vlseg2e16ff_v_u16mf4x2 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16mf4x2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vlseg2e16ff.v.nxv1i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_u16mf4x2(*base);
}

vuint16mf2x2_t test_vlseg2e16ff_v_u16mf2x2 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16mf2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlseg2e16ff.v.nxv2i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_u16mf2x2(*base);
}

vuint16m1x2_t test_vlseg2e16ff_v_u16m1x2 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16m1x2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg2e16ff.v.nxv4i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_u16m1x2(*base);
}

vuint16m2x2_t test_vlseg2e16ff_v_u16m2x2 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16m2x2
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg2e16ff.v.nxv8i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_u16m2x2(*base);
}

vuint16m4x2_t test_vlseg2e16ff_v_u16m4x2 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16m4x2
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg2e16ff.v.nxv16i16x2.{{.*}}(i16 %{{.*}})
  return vlseg2e16ff_v_u16m4x2(*base);
}

vfloat16mf4x2_t test_vlseg2e16ff_v_f16mf4x2 (float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16mf4x2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vlseg2e16ff.v.nxv1f16x2.{{.*}}(half %{{.*}})
  return vlseg2e16ff_v_f16mf4x2(*base);
}

vfloat16mf2x2_t test_vlseg2e16ff_v_f16mf2x2 (float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16mf2x2
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vlseg2e16ff.v.nxv2f16x2.{{.*}}(half %{{.*}})
  return vlseg2e16ff_v_f16mf2x2(*base);
}

vfloat16m1x2_t test_vlseg2e16ff_v_f16m1x2 (float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16m1x2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlseg2e16ff.v.nxv4f16x2.{{.*}}(half %{{.*}})
  return vlseg2e16ff_v_f16m1x2(*base);
}

vfloat16m2x2_t test_vlseg2e16ff_v_f16m2x2 (float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16m2x2
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlseg2e16ff.v.nxv8f16x2.{{.*}}(half %{{.*}})
  return vlseg2e16ff_v_f16m2x2(*base);
}

vfloat16m4x2_t test_vlseg2e16ff_v_f16m4x2 (float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16m4x2
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlseg2e16ff.v.nxv16f16x2.{{.*}}(half %{{.*}})
  return vlseg2e16ff_v_f16m4x2(*base);
}

vint16mf4x2_t test_vlseg2e16ff_v_i16mf4x2_m (vbool64_t mask, vint16mf4x2_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16mf4x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vlseg2e16ff.v.nxv1i16x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_i16mf4x2_m(mask, maskedoff, *base);
}

vint16mf2x2_t test_vlseg2e16ff_v_i16mf2x2_m (vbool32_t mask, vint16mf2x2_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16mf2x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlseg2e16ff.v.nxv2i16x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_i16mf2x2_m(mask, maskedoff, *base);
}

vint16m1x2_t test_vlseg2e16ff_v_i16m1x2_m (vbool16_t mask, vint16m1x2_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16m1x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg2e16ff.v.nxv4i16x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_i16m1x2_m(mask, maskedoff, *base);
}

vint16m2x2_t test_vlseg2e16ff_v_i16m2x2_m (vbool8_t mask, vint16m2x2_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16m2x2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg2e16ff.v.nxv8i16x2.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_i16m2x2_m(mask, maskedoff, *base);
}

vint16m4x2_t test_vlseg2e16ff_v_i16m4x2_m (vbool4_t mask, vint16m4x2_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_i16m4x2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg2e16ff.v.nxv16i16x2.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_i16m4x2_m(mask, maskedoff, *base);
}

vuint16mf4x2_t test_vlseg2e16ff_v_u16mf4x2_m (vbool64_t mask, vuint16mf4x2_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16mf4x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vlseg2e16ff.v.nxv1i16x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_u16mf4x2_m(mask, maskedoff, *base);
}

vuint16mf2x2_t test_vlseg2e16ff_v_u16mf2x2_m (vbool32_t mask, vuint16mf2x2_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16mf2x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlseg2e16ff.v.nxv2i16x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_u16mf2x2_m(mask, maskedoff, *base);
}

vuint16m1x2_t test_vlseg2e16ff_v_u16m1x2_m (vbool16_t mask, vuint16m1x2_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16m1x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg2e16ff.v.nxv4i16x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_u16m1x2_m(mask, maskedoff, *base);
}

vuint16m2x2_t test_vlseg2e16ff_v_u16m2x2_m (vbool8_t mask, vuint16m2x2_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16m2x2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg2e16ff.v.nxv8i16x2.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_u16m2x2_m(mask, maskedoff, *base);
}

vuint16m4x2_t test_vlseg2e16ff_v_u16m4x2_m (vbool4_t mask, vuint16m4x2_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_u16m4x2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg2e16ff.v.nxv16i16x2.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg2e16ff_v_u16m4x2_m(mask, maskedoff, *base);
}

vfloat16mf4x2_t test_vlseg2e16ff_v_f16mf4x2_m (vbool64_t mask, vfloat16mf4x2_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16mf4x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vlseg2e16ff.v.nxv1f16x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vlseg2e16ff_v_f16mf4x2_m(mask, maskedoff, *base);
}

vfloat16mf2x2_t test_vlseg2e16ff_v_f16mf2x2_m (vbool32_t mask, vfloat16mf2x2_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16mf2x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vlseg2e16ff.v.nxv2f16x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vlseg2e16ff_v_f16mf2x2_m(mask, maskedoff, *base);
}

vfloat16m1x2_t test_vlseg2e16ff_v_f16m1x2_m (vbool16_t mask, vfloat16m1x2_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16m1x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlseg2e16ff.v.nxv4f16x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vlseg2e16ff_v_f16m1x2_m(mask, maskedoff, *base);
}

vfloat16m2x2_t test_vlseg2e16ff_v_f16m2x2_m (vbool8_t mask, vfloat16m2x2_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16m2x2_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlseg2e16ff.v.nxv8f16x2.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vlseg2e16ff_v_f16m2x2_m(mask, maskedoff, *base);
}

vfloat16m4x2_t test_vlseg2e16ff_v_f16m4x2_m (vbool4_t mask, vfloat16m4x2_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg2e16ff_v_f16m4x2_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlseg2e16ff.v.nxv16f16x2.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vlseg2e16ff_v_f16m4x2_m(mask, maskedoff, *base);
}


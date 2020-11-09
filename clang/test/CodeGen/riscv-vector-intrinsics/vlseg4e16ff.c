// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4x4_t test_vlseg4e16ff_v_i16mf4x4 (int16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_i16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlseg4e16ff.v.nxv1i16x4.{{.*}}(i16 %{{.*}})
  return vlseg4e16ff_v_i16mf4x4(*base);
}

vint16mf2x4_t test_vlseg4e16ff_v_i16mf2x4 (int16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_i16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg4e16ff.v.nxv2i16x4.{{.*}}(i16 %{{.*}})
  return vlseg4e16ff_v_i16mf2x4(*base);
}

vint16m1x4_t test_vlseg4e16ff_v_i16m1x4 (int16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_i16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg4e16ff.v.nxv4i16x4.{{.*}}(i16 %{{.*}})
  return vlseg4e16ff_v_i16m1x4(*base);
}

vint16m2x4_t test_vlseg4e16ff_v_i16m2x4 (int16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_i16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg4e16ff.v.nxv8i16x4.{{.*}}(i16 %{{.*}})
  return vlseg4e16ff_v_i16m2x4(*base);
}

vuint16mf4x4_t test_vlseg4e16ff_v_u16mf4x4 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_u16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlseg4e16ff.v.nxv1i16x4.{{.*}}(i16 %{{.*}})
  return vlseg4e16ff_v_u16mf4x4(*base);
}

vuint16mf2x4_t test_vlseg4e16ff_v_u16mf2x4 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_u16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg4e16ff.v.nxv2i16x4.{{.*}}(i16 %{{.*}})
  return vlseg4e16ff_v_u16mf2x4(*base);
}

vuint16m1x4_t test_vlseg4e16ff_v_u16m1x4 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_u16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg4e16ff.v.nxv4i16x4.{{.*}}(i16 %{{.*}})
  return vlseg4e16ff_v_u16m1x4(*base);
}

vuint16m2x4_t test_vlseg4e16ff_v_u16m2x4 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_u16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg4e16ff.v.nxv8i16x4.{{.*}}(i16 %{{.*}})
  return vlseg4e16ff_v_u16m2x4(*base);
}

vfloat16mf4x4_t test_vlseg4e16ff_v_f16mf4x4 (float16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_f16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vlseg4e16ff.v.nxv1f16x4.{{.*}}(half %{{.*}})
  return vlseg4e16ff_v_f16mf4x4(*base);
}

vfloat16mf2x4_t test_vlseg4e16ff_v_f16mf2x4 (float16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_f16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlseg4e16ff.v.nxv2f16x4.{{.*}}(half %{{.*}})
  return vlseg4e16ff_v_f16mf2x4(*base);
}

vfloat16m1x4_t test_vlseg4e16ff_v_f16m1x4 (float16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_f16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlseg4e16ff.v.nxv4f16x4.{{.*}}(half %{{.*}})
  return vlseg4e16ff_v_f16m1x4(*base);
}

vfloat16m2x4_t test_vlseg4e16ff_v_f16m2x4 (float16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_f16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlseg4e16ff.v.nxv8f16x4.{{.*}}(half %{{.*}})
  return vlseg4e16ff_v_f16m2x4(*base);
}

vint16mf4x4_t test_vlseg4e16ff_v_i16mf4x4_m (vbool64_t mask, vint16mf4x4_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_i16mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlseg4e16ff.v.nxv1i16x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg4e16ff_v_i16mf4x4_m(mask, maskedoff, *base);
}

vint16mf2x4_t test_vlseg4e16ff_v_i16mf2x4_m (vbool32_t mask, vint16mf2x4_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_i16mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg4e16ff.v.nxv2i16x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg4e16ff_v_i16mf2x4_m(mask, maskedoff, *base);
}

vint16m1x4_t test_vlseg4e16ff_v_i16m1x4_m (vbool16_t mask, vint16m1x4_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_i16m1x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg4e16ff.v.nxv4i16x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg4e16ff_v_i16m1x4_m(mask, maskedoff, *base);
}

vint16m2x4_t test_vlseg4e16ff_v_i16m2x4_m (vbool8_t mask, vint16m2x4_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_i16m2x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg4e16ff.v.nxv8i16x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg4e16ff_v_i16m2x4_m(mask, maskedoff, *base);
}

vuint16mf4x4_t test_vlseg4e16ff_v_u16mf4x4_m (vbool64_t mask, vuint16mf4x4_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_u16mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlseg4e16ff.v.nxv1i16x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg4e16ff_v_u16mf4x4_m(mask, maskedoff, *base);
}

vuint16mf2x4_t test_vlseg4e16ff_v_u16mf2x4_m (vbool32_t mask, vuint16mf2x4_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_u16mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg4e16ff.v.nxv2i16x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg4e16ff_v_u16mf2x4_m(mask, maskedoff, *base);
}

vuint16m1x4_t test_vlseg4e16ff_v_u16m1x4_m (vbool16_t mask, vuint16m1x4_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_u16m1x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg4e16ff.v.nxv4i16x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg4e16ff_v_u16m1x4_m(mask, maskedoff, *base);
}

vuint16m2x4_t test_vlseg4e16ff_v_u16m2x4_m (vbool8_t mask, vuint16m2x4_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_u16m2x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg4e16ff.v.nxv8i16x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg4e16ff_v_u16m2x4_m(mask, maskedoff, *base);
}

vfloat16mf4x4_t test_vlseg4e16ff_v_f16mf4x4_m (vbool64_t mask, vfloat16mf4x4_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_f16mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vlseg4e16ff.v.nxv1f16x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vlseg4e16ff_v_f16mf4x4_m(mask, maskedoff, *base);
}

vfloat16mf2x4_t test_vlseg4e16ff_v_f16mf2x4_m (vbool32_t mask, vfloat16mf2x4_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_f16mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlseg4e16ff.v.nxv2f16x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vlseg4e16ff_v_f16mf2x4_m(mask, maskedoff, *base);
}

vfloat16m1x4_t test_vlseg4e16ff_v_f16m1x4_m (vbool16_t mask, vfloat16m1x4_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_f16m1x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlseg4e16ff.v.nxv4f16x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vlseg4e16ff_v_f16m1x4_m(mask, maskedoff, *base);
}

vfloat16m2x4_t test_vlseg4e16ff_v_f16m2x4_m (vbool8_t mask, vfloat16m2x4_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg4e16ff_v_f16m2x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlseg4e16ff.v.nxv8f16x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vlseg4e16ff_v_f16m2x4_m(mask, maskedoff, *base);
}


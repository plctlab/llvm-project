// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4x8_t test_vlseg8e16ff_v_i16mf4x8 (int16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_i16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg8e16ff.v.nxv1i16x8.{{.*}}(i16 %{{.*}})
  return vlseg8e16ff_v_i16mf4x8(*base);
}

vint16mf2x8_t test_vlseg8e16ff_v_i16mf2x8 (int16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_i16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg8e16ff.v.nxv2i16x8.{{.*}}(i16 %{{.*}})
  return vlseg8e16ff_v_i16mf2x8(*base);
}

vint16m1x8_t test_vlseg8e16ff_v_i16m1x8 (int16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_i16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg8e16ff.v.nxv4i16x8.{{.*}}(i16 %{{.*}})
  return vlseg8e16ff_v_i16m1x8(*base);
}

vuint16mf4x8_t test_vlseg8e16ff_v_u16mf4x8 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_u16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg8e16ff.v.nxv1i16x8.{{.*}}(i16 %{{.*}})
  return vlseg8e16ff_v_u16mf4x8(*base);
}

vuint16mf2x8_t test_vlseg8e16ff_v_u16mf2x8 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_u16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg8e16ff.v.nxv2i16x8.{{.*}}(i16 %{{.*}})
  return vlseg8e16ff_v_u16mf2x8(*base);
}

vuint16m1x8_t test_vlseg8e16ff_v_u16m1x8 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_u16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg8e16ff.v.nxv4i16x8.{{.*}}(i16 %{{.*}})
  return vlseg8e16ff_v_u16m1x8(*base);
}

vfloat16mf4x8_t test_vlseg8e16ff_v_f16mf4x8 (float16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_f16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlseg8e16ff.v.nxv1f16x8.{{.*}}(half %{{.*}})
  return vlseg8e16ff_v_f16mf4x8(*base);
}

vfloat16mf2x8_t test_vlseg8e16ff_v_f16mf2x8 (float16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_f16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlseg8e16ff.v.nxv2f16x8.{{.*}}(half %{{.*}})
  return vlseg8e16ff_v_f16mf2x8(*base);
}

vfloat16m1x8_t test_vlseg8e16ff_v_f16m1x8 (float16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_f16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlseg8e16ff.v.nxv4f16x8.{{.*}}(half %{{.*}})
  return vlseg8e16ff_v_f16m1x8(*base);
}

vint16mf4x8_t test_vlseg8e16ff_v_i16mf4x8_m (vbool64_t mask, vint16mf4x8_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_i16mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg8e16ff.v.nxv1i16x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg8e16ff_v_i16mf4x8_m(mask, maskedoff, *base);
}

vint16mf2x8_t test_vlseg8e16ff_v_i16mf2x8_m (vbool32_t mask, vint16mf2x8_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_i16mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg8e16ff.v.nxv2i16x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg8e16ff_v_i16mf2x8_m(mask, maskedoff, *base);
}

vint16m1x8_t test_vlseg8e16ff_v_i16m1x8_m (vbool16_t mask, vint16m1x8_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_i16m1x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg8e16ff.v.nxv4i16x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg8e16ff_v_i16m1x8_m(mask, maskedoff, *base);
}

vuint16mf4x8_t test_vlseg8e16ff_v_u16mf4x8_m (vbool64_t mask, vuint16mf4x8_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_u16mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlseg8e16ff.v.nxv1i16x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg8e16ff_v_u16mf4x8_m(mask, maskedoff, *base);
}

vuint16mf2x8_t test_vlseg8e16ff_v_u16mf2x8_m (vbool32_t mask, vuint16mf2x8_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_u16mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlseg8e16ff.v.nxv2i16x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg8e16ff_v_u16mf2x8_m(mask, maskedoff, *base);
}

vuint16m1x8_t test_vlseg8e16ff_v_u16m1x8_m (vbool16_t mask, vuint16m1x8_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_u16m1x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlseg8e16ff.v.nxv4i16x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg8e16ff_v_u16m1x8_m(mask, maskedoff, *base);
}

vfloat16mf4x8_t test_vlseg8e16ff_v_f16mf4x8_m (vbool64_t mask, vfloat16mf4x8_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_f16mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlseg8e16ff.v.nxv1f16x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vlseg8e16ff_v_f16mf4x8_m(mask, maskedoff, *base);
}

vfloat16mf2x8_t test_vlseg8e16ff_v_f16mf2x8_m (vbool32_t mask, vfloat16mf2x8_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_f16mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlseg8e16ff.v.nxv2f16x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vlseg8e16ff_v_f16mf2x8_m(mask, maskedoff, *base);
}

vfloat16m1x8_t test_vlseg8e16ff_v_f16m1x8_m (vbool16_t mask, vfloat16m1x8_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg8e16ff_v_f16m1x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlseg8e16ff.v.nxv4f16x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vlseg8e16ff_v_f16m1x8_m(mask, maskedoff, *base);
}


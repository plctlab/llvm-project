// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4x5_t test_vlseg5e16_v_i16mf4x5 (int16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_i16mf4x5
  // CHECK: %{{.*}} = call <vscale x 5 x i16> @llvm.riscv.vlseg5e16.v.nxv1i16x5.{{.*}}(i16 %{{.*}})
  return vlseg5e16_v_i16mf4x5(*base);
}

vint16mf2x5_t test_vlseg5e16_v_i16mf2x5 (int16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_i16mf2x5
  // CHECK: %{{.*}} = call <vscale x 10 x i16> @llvm.riscv.vlseg5e16.v.nxv2i16x5.{{.*}}(i16 %{{.*}})
  return vlseg5e16_v_i16mf2x5(*base);
}

vint16m1x5_t test_vlseg5e16_v_i16m1x5 (int16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_i16m1x5
  // CHECK: %{{.*}} = call <vscale x 20 x i16> @llvm.riscv.vlseg5e16.v.nxv4i16x5.{{.*}}(i16 %{{.*}})
  return vlseg5e16_v_i16m1x5(*base);
}

vuint16mf4x5_t test_vlseg5e16_v_u16mf4x5 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_u16mf4x5
  // CHECK: %{{.*}} = call <vscale x 5 x i16> @llvm.riscv.vlseg5e16.v.nxv1i16x5.{{.*}}(i16 %{{.*}})
  return vlseg5e16_v_u16mf4x5(*base);
}

vuint16mf2x5_t test_vlseg5e16_v_u16mf2x5 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_u16mf2x5
  // CHECK: %{{.*}} = call <vscale x 10 x i16> @llvm.riscv.vlseg5e16.v.nxv2i16x5.{{.*}}(i16 %{{.*}})
  return vlseg5e16_v_u16mf2x5(*base);
}

vuint16m1x5_t test_vlseg5e16_v_u16m1x5 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_u16m1x5
  // CHECK: %{{.*}} = call <vscale x 20 x i16> @llvm.riscv.vlseg5e16.v.nxv4i16x5.{{.*}}(i16 %{{.*}})
  return vlseg5e16_v_u16m1x5(*base);
}

vfloat16mf4x5_t test_vlseg5e16_v_f16mf4x5 (float16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_f16mf4x5
  // CHECK: %{{.*}} = call <vscale x 5 x half> @llvm.riscv.vlseg5e16.v.nxv1f16x5.{{.*}}(half %{{.*}})
  return vlseg5e16_v_f16mf4x5(*base);
}

vfloat16mf2x5_t test_vlseg5e16_v_f16mf2x5 (float16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_f16mf2x5
  // CHECK: %{{.*}} = call <vscale x 10 x half> @llvm.riscv.vlseg5e16.v.nxv2f16x5.{{.*}}(half %{{.*}})
  return vlseg5e16_v_f16mf2x5(*base);
}

vfloat16m1x5_t test_vlseg5e16_v_f16m1x5 (float16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_f16m1x5
  // CHECK: %{{.*}} = call <vscale x 20 x half> @llvm.riscv.vlseg5e16.v.nxv4f16x5.{{.*}}(half %{{.*}})
  return vlseg5e16_v_f16m1x5(*base);
}

vint16mf4x5_t test_vlseg5e16_v_i16mf4x5_m (vbool64_t mask, vint16mf4x5_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_i16mf4x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x i16> @llvm.riscv.vlseg5e16.v.nxv1i16x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg5e16_v_i16mf4x5_m(mask, maskedoff, *base);
}

vint16mf2x5_t test_vlseg5e16_v_i16mf2x5_m (vbool32_t mask, vint16mf2x5_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_i16mf2x5_m
  // CHECK: %{{.*}} = call <vscale x 10 x i16> @llvm.riscv.vlseg5e16.v.nxv2i16x5.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 10 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg5e16_v_i16mf2x5_m(mask, maskedoff, *base);
}

vint16m1x5_t test_vlseg5e16_v_i16m1x5_m (vbool16_t mask, vint16m1x5_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_i16m1x5_m
  // CHECK: %{{.*}} = call <vscale x 20 x i16> @llvm.riscv.vlseg5e16.v.nxv4i16x5.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 20 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg5e16_v_i16m1x5_m(mask, maskedoff, *base);
}

vuint16mf4x5_t test_vlseg5e16_v_u16mf4x5_m (vbool64_t mask, vuint16mf4x5_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_u16mf4x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x i16> @llvm.riscv.vlseg5e16.v.nxv1i16x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg5e16_v_u16mf4x5_m(mask, maskedoff, *base);
}

vuint16mf2x5_t test_vlseg5e16_v_u16mf2x5_m (vbool32_t mask, vuint16mf2x5_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_u16mf2x5_m
  // CHECK: %{{.*}} = call <vscale x 10 x i16> @llvm.riscv.vlseg5e16.v.nxv2i16x5.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 10 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg5e16_v_u16mf2x5_m(mask, maskedoff, *base);
}

vuint16m1x5_t test_vlseg5e16_v_u16m1x5_m (vbool16_t mask, vuint16m1x5_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_u16m1x5_m
  // CHECK: %{{.*}} = call <vscale x 20 x i16> @llvm.riscv.vlseg5e16.v.nxv4i16x5.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 20 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg5e16_v_u16m1x5_m(mask, maskedoff, *base);
}

vfloat16mf4x5_t test_vlseg5e16_v_f16mf4x5_m (vbool64_t mask, vfloat16mf4x5_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_f16mf4x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x half> @llvm.riscv.vlseg5e16.v.nxv1f16x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x half> %{{.*}}, half %{{.*}})
  return vlseg5e16_v_f16mf4x5_m(mask, maskedoff, *base);
}

vfloat16mf2x5_t test_vlseg5e16_v_f16mf2x5_m (vbool32_t mask, vfloat16mf2x5_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_f16mf2x5_m
  // CHECK: %{{.*}} = call <vscale x 10 x half> @llvm.riscv.vlseg5e16.v.nxv2f16x5.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 10 x half> %{{.*}}, half %{{.*}})
  return vlseg5e16_v_f16mf2x5_m(mask, maskedoff, *base);
}

vfloat16m1x5_t test_vlseg5e16_v_f16m1x5_m (vbool16_t mask, vfloat16m1x5_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg5e16_v_f16m1x5_m
  // CHECK: %{{.*}} = call <vscale x 20 x half> @llvm.riscv.vlseg5e16.v.nxv4f16x5.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 20 x half> %{{.*}}, half %{{.*}})
  return vlseg5e16_v_f16m1x5_m(mask, maskedoff, *base);
}


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4x7_t test_vlseg7e16ff_v_i16mf4x7 (int16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_i16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vlseg7e16ff.v.nxv1i16x7.{{.*}}(i16 %{{.*}})
  return vlseg7e16ff_v_i16mf4x7(*base);
}

vint16mf2x7_t test_vlseg7e16ff_v_i16mf2x7 (int16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_i16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vlseg7e16ff.v.nxv2i16x7.{{.*}}(i16 %{{.*}})
  return vlseg7e16ff_v_i16mf2x7(*base);
}

vint16m1x7_t test_vlseg7e16ff_v_i16m1x7 (int16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_i16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vlseg7e16ff.v.nxv4i16x7.{{.*}}(i16 %{{.*}})
  return vlseg7e16ff_v_i16m1x7(*base);
}

vuint16mf4x7_t test_vlseg7e16ff_v_u16mf4x7 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_u16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vlseg7e16ff.v.nxv1i16x7.{{.*}}(i16 %{{.*}})
  return vlseg7e16ff_v_u16mf4x7(*base);
}

vuint16mf2x7_t test_vlseg7e16ff_v_u16mf2x7 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_u16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vlseg7e16ff.v.nxv2i16x7.{{.*}}(i16 %{{.*}})
  return vlseg7e16ff_v_u16mf2x7(*base);
}

vuint16m1x7_t test_vlseg7e16ff_v_u16m1x7 (uint16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_u16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vlseg7e16ff.v.nxv4i16x7.{{.*}}(i16 %{{.*}})
  return vlseg7e16ff_v_u16m1x7(*base);
}

vfloat16mf4x7_t test_vlseg7e16ff_v_f16mf4x7 (float16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_f16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x half> @llvm.riscv.vlseg7e16ff.v.nxv1f16x7.{{.*}}(half %{{.*}})
  return vlseg7e16ff_v_f16mf4x7(*base);
}

vfloat16mf2x7_t test_vlseg7e16ff_v_f16mf2x7 (float16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_f16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x half> @llvm.riscv.vlseg7e16ff.v.nxv2f16x7.{{.*}}(half %{{.*}})
  return vlseg7e16ff_v_f16mf2x7(*base);
}

vfloat16m1x7_t test_vlseg7e16ff_v_f16m1x7 (float16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_f16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x half> @llvm.riscv.vlseg7e16ff.v.nxv4f16x7.{{.*}}(half %{{.*}})
  return vlseg7e16ff_v_f16m1x7(*base);
}

vint16mf4x7_t test_vlseg7e16ff_v_i16mf4x7_m (vbool64_t mask, vint16mf4x7_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_i16mf4x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vlseg7e16ff.v.nxv1i16x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg7e16ff_v_i16mf4x7_m(mask, maskedoff, *base);
}

vint16mf2x7_t test_vlseg7e16ff_v_i16mf2x7_m (vbool32_t mask, vint16mf2x7_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_i16mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vlseg7e16ff.v.nxv2i16x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg7e16ff_v_i16mf2x7_m(mask, maskedoff, *base);
}

vint16m1x7_t test_vlseg7e16ff_v_i16m1x7_m (vbool16_t mask, vint16m1x7_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_i16m1x7_m
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vlseg7e16ff.v.nxv4i16x7.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 28 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg7e16ff_v_i16m1x7_m(mask, maskedoff, *base);
}

vuint16mf4x7_t test_vlseg7e16ff_v_u16mf4x7_m (vbool64_t mask, vuint16mf4x7_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_u16mf4x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vlseg7e16ff.v.nxv1i16x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg7e16ff_v_u16mf4x7_m(mask, maskedoff, *base);
}

vuint16mf2x7_t test_vlseg7e16ff_v_u16mf2x7_m (vbool32_t mask, vuint16mf2x7_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_u16mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vlseg7e16ff.v.nxv2i16x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg7e16ff_v_u16mf2x7_m(mask, maskedoff, *base);
}

vuint16m1x7_t test_vlseg7e16ff_v_u16m1x7_m (vbool16_t mask, vuint16m1x7_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_u16m1x7_m
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vlseg7e16ff.v.nxv4i16x7.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 28 x i16> %{{.*}}, i16 %{{.*}})
  return vlseg7e16ff_v_u16m1x7_m(mask, maskedoff, *base);
}

vfloat16mf4x7_t test_vlseg7e16ff_v_f16mf4x7_m (vbool64_t mask, vfloat16mf4x7_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_f16mf4x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x half> @llvm.riscv.vlseg7e16ff.v.nxv1f16x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x half> %{{.*}}, half %{{.*}})
  return vlseg7e16ff_v_f16mf4x7_m(mask, maskedoff, *base);
}

vfloat16mf2x7_t test_vlseg7e16ff_v_f16mf2x7_m (vbool32_t mask, vfloat16mf2x7_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_f16mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x half> @llvm.riscv.vlseg7e16ff.v.nxv2f16x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x half> %{{.*}}, half %{{.*}})
  return vlseg7e16ff_v_f16mf2x7_m(mask, maskedoff, *base);
}

vfloat16m1x7_t test_vlseg7e16ff_v_f16m1x7_m (vbool16_t mask, vfloat16m1x7_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vlseg7e16ff_v_f16m1x7_m
  // CHECK: %{{.*}} = call <vscale x 28 x half> @llvm.riscv.vlseg7e16ff.v.nxv4f16x7.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 28 x half> %{{.*}}, half %{{.*}})
  return vlseg7e16ff_v_f16m1x7_m(mask, maskedoff, *base);
}


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4x7_t test_vlsseg7e16_v_i16mf4x7 (int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_i16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vlsseg7e16.v.nxv1i16x7.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_i16mf4x7(*base, bstride);
}

vint16mf2x7_t test_vlsseg7e16_v_i16mf2x7 (int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_i16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vlsseg7e16.v.nxv2i16x7.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_i16mf2x7(*base, bstride);
}

vint16m1x7_t test_vlsseg7e16_v_i16m1x7 (int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_i16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vlsseg7e16.v.nxv4i16x7.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_i16m1x7(*base, bstride);
}

vuint16mf4x7_t test_vlsseg7e16_v_u16mf4x7 (uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_u16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vlsseg7e16.v.nxv1i16x7.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_u16mf4x7(*base, bstride);
}

vuint16mf2x7_t test_vlsseg7e16_v_u16mf2x7 (uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_u16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vlsseg7e16.v.nxv2i16x7.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_u16mf2x7(*base, bstride);
}

vuint16m1x7_t test_vlsseg7e16_v_u16m1x7 (uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_u16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vlsseg7e16.v.nxv4i16x7.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_u16m1x7(*base, bstride);
}

vfloat16mf4x7_t test_vlsseg7e16_v_f16mf4x7 (float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_f16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x half> @llvm.riscv.vlsseg7e16.v.nxv1f16x7.{{.*}}(half %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_f16mf4x7(*base, bstride);
}

vfloat16mf2x7_t test_vlsseg7e16_v_f16mf2x7 (float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_f16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x half> @llvm.riscv.vlsseg7e16.v.nxv2f16x7.{{.*}}(half %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_f16mf2x7(*base, bstride);
}

vfloat16m1x7_t test_vlsseg7e16_v_f16m1x7 (float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_f16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x half> @llvm.riscv.vlsseg7e16.v.nxv4f16x7.{{.*}}(half %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_f16m1x7(*base, bstride);
}

vint16mf4x7_t test_vlsseg7e16_v_i16mf4x7_m (vbool64_t mask, vint16mf4x7_t maskedoff, int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_i16mf4x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vlsseg7e16.v.nxv1i16x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_i16mf4x7_m(mask, maskedoff, *base, bstride);
}

vint16mf2x7_t test_vlsseg7e16_v_i16mf2x7_m (vbool32_t mask, vint16mf2x7_t maskedoff, int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_i16mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vlsseg7e16.v.nxv2i16x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_i16mf2x7_m(mask, maskedoff, *base, bstride);
}

vint16m1x7_t test_vlsseg7e16_v_i16m1x7_m (vbool16_t mask, vint16m1x7_t maskedoff, int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_i16m1x7_m
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vlsseg7e16.v.nxv4i16x7.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 28 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_i16m1x7_m(mask, maskedoff, *base, bstride);
}

vuint16mf4x7_t test_vlsseg7e16_v_u16mf4x7_m (vbool64_t mask, vuint16mf4x7_t maskedoff, uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_u16mf4x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vlsseg7e16.v.nxv1i16x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_u16mf4x7_m(mask, maskedoff, *base, bstride);
}

vuint16mf2x7_t test_vlsseg7e16_v_u16mf2x7_m (vbool32_t mask, vuint16mf2x7_t maskedoff, uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_u16mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vlsseg7e16.v.nxv2i16x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_u16mf2x7_m(mask, maskedoff, *base, bstride);
}

vuint16m1x7_t test_vlsseg7e16_v_u16m1x7_m (vbool16_t mask, vuint16m1x7_t maskedoff, uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_u16m1x7_m
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vlsseg7e16.v.nxv4i16x7.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 28 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_u16m1x7_m(mask, maskedoff, *base, bstride);
}

vfloat16mf4x7_t test_vlsseg7e16_v_f16mf4x7_m (vbool64_t mask, vfloat16mf4x7_t maskedoff, float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_f16mf4x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x half> @llvm.riscv.vlsseg7e16.v.nxv1f16x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x half> %{{.*}}, half %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_f16mf4x7_m(mask, maskedoff, *base, bstride);
}

vfloat16mf2x7_t test_vlsseg7e16_v_f16mf2x7_m (vbool32_t mask, vfloat16mf2x7_t maskedoff, float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_f16mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x half> @llvm.riscv.vlsseg7e16.v.nxv2f16x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x half> %{{.*}}, half %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_f16mf2x7_m(mask, maskedoff, *base, bstride);
}

vfloat16m1x7_t test_vlsseg7e16_v_f16m1x7_m (vbool16_t mask, vfloat16m1x7_t maskedoff, float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg7e16_v_f16m1x7_m
  // CHECK: %{{.*}} = call <vscale x 28 x half> @llvm.riscv.vlsseg7e16.v.nxv4f16x7.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 28 x half> %{{.*}}, half %{{.*}}, i64 %{{.*}})
  return vlsseg7e16_v_f16m1x7_m(mask, maskedoff, *base, bstride);
}


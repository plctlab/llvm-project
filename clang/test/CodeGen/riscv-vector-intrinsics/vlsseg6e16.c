// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4x6_t test_vlsseg6e16_v_i16mf4x6 (int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_i16mf4x6
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vlsseg6e16.v.nxv1i16x6.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_i16mf4x6(*base, bstride);
}

vint16mf2x6_t test_vlsseg6e16_v_i16mf2x6 (int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_i16mf2x6
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vlsseg6e16.v.nxv2i16x6.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_i16mf2x6(*base, bstride);
}

vint16m1x6_t test_vlsseg6e16_v_i16m1x6 (int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_i16m1x6
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vlsseg6e16.v.nxv4i16x6.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_i16m1x6(*base, bstride);
}

vuint16mf4x6_t test_vlsseg6e16_v_u16mf4x6 (uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_u16mf4x6
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vlsseg6e16.v.nxv1i16x6.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_u16mf4x6(*base, bstride);
}

vuint16mf2x6_t test_vlsseg6e16_v_u16mf2x6 (uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_u16mf2x6
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vlsseg6e16.v.nxv2i16x6.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_u16mf2x6(*base, bstride);
}

vuint16m1x6_t test_vlsseg6e16_v_u16m1x6 (uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_u16m1x6
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vlsseg6e16.v.nxv4i16x6.{{.*}}(i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_u16m1x6(*base, bstride);
}

vfloat16mf4x6_t test_vlsseg6e16_v_f16mf4x6 (float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_f16mf4x6
  // CHECK: %{{.*}} = call <vscale x 6 x half> @llvm.riscv.vlsseg6e16.v.nxv1f16x6.{{.*}}(half %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_f16mf4x6(*base, bstride);
}

vfloat16mf2x6_t test_vlsseg6e16_v_f16mf2x6 (float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_f16mf2x6
  // CHECK: %{{.*}} = call <vscale x 12 x half> @llvm.riscv.vlsseg6e16.v.nxv2f16x6.{{.*}}(half %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_f16mf2x6(*base, bstride);
}

vfloat16m1x6_t test_vlsseg6e16_v_f16m1x6 (float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_f16m1x6
  // CHECK: %{{.*}} = call <vscale x 24 x half> @llvm.riscv.vlsseg6e16.v.nxv4f16x6.{{.*}}(half %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_f16m1x6(*base, bstride);
}

vint16mf4x6_t test_vlsseg6e16_v_i16mf4x6_m (vbool64_t mask, vint16mf4x6_t maskedoff, int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_i16mf4x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vlsseg6e16.v.nxv1i16x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_i16mf4x6_m(mask, maskedoff, *base, bstride);
}

vint16mf2x6_t test_vlsseg6e16_v_i16mf2x6_m (vbool32_t mask, vint16mf2x6_t maskedoff, int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_i16mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vlsseg6e16.v.nxv2i16x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_i16mf2x6_m(mask, maskedoff, *base, bstride);
}

vint16m1x6_t test_vlsseg6e16_v_i16m1x6_m (vbool16_t mask, vint16m1x6_t maskedoff, int16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_i16m1x6_m
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vlsseg6e16.v.nxv4i16x6.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 24 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_i16m1x6_m(mask, maskedoff, *base, bstride);
}

vuint16mf4x6_t test_vlsseg6e16_v_u16mf4x6_m (vbool64_t mask, vuint16mf4x6_t maskedoff, uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_u16mf4x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vlsseg6e16.v.nxv1i16x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_u16mf4x6_m(mask, maskedoff, *base, bstride);
}

vuint16mf2x6_t test_vlsseg6e16_v_u16mf2x6_m (vbool32_t mask, vuint16mf2x6_t maskedoff, uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_u16mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vlsseg6e16.v.nxv2i16x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_u16mf2x6_m(mask, maskedoff, *base, bstride);
}

vuint16m1x6_t test_vlsseg6e16_v_u16m1x6_m (vbool16_t mask, vuint16m1x6_t maskedoff, uint16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_u16m1x6_m
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vlsseg6e16.v.nxv4i16x6.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 24 x i16> %{{.*}}, i16 %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_u16m1x6_m(mask, maskedoff, *base, bstride);
}

vfloat16mf4x6_t test_vlsseg6e16_v_f16mf4x6_m (vbool64_t mask, vfloat16mf4x6_t maskedoff, float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_f16mf4x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x half> @llvm.riscv.vlsseg6e16.v.nxv1f16x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x half> %{{.*}}, half %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_f16mf4x6_m(mask, maskedoff, *base, bstride);
}

vfloat16mf2x6_t test_vlsseg6e16_v_f16mf2x6_m (vbool32_t mask, vfloat16mf2x6_t maskedoff, float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_f16mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x half> @llvm.riscv.vlsseg6e16.v.nxv2f16x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x half> %{{.*}}, half %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_f16mf2x6_m(mask, maskedoff, *base, bstride);
}

vfloat16m1x6_t test_vlsseg6e16_v_f16m1x6_m (vbool16_t mask, vfloat16m1x6_t maskedoff, float16_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg6e16_v_f16m1x6_m
  // CHECK: %{{.*}} = call <vscale x 24 x half> @llvm.riscv.vlsseg6e16.v.nxv4f16x6.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 24 x half> %{{.*}}, half %{{.*}}, i64 %{{.*}})
  return vlsseg6e16_v_f16m1x6_m(mask, maskedoff, *base, bstride);
}


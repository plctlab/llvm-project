// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x4_t test_vlsseg4e8_v_i8mf8x4 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8mf8x4
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlsseg4e8.v.nxv1i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8mf8x4(*base, bstride);
}

vint8mf4x4_t test_vlsseg4e8_v_i8mf4x4 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8mf4x4
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlsseg4e8.v.nxv2i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8mf4x4(*base, bstride);
}

vint8mf2x4_t test_vlsseg4e8_v_i8mf2x4 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8mf2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlsseg4e8.v.nxv4i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8mf2x4(*base, bstride);
}

vint8m1x4_t test_vlsseg4e8_v_i8m1x4 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8m1x4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlsseg4e8.v.nxv8i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8m1x4(*base, bstride);
}

vint8m2x4_t test_vlsseg4e8_v_i8m2x4 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8m2x4
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlsseg4e8.v.nxv16i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8m2x4(*base, bstride);
}

vuint8mf8x4_t test_vlsseg4e8_v_u8mf8x4 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8mf8x4
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlsseg4e8.v.nxv1i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8mf8x4(*base, bstride);
}

vuint8mf4x4_t test_vlsseg4e8_v_u8mf4x4 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8mf4x4
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlsseg4e8.v.nxv2i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8mf4x4(*base, bstride);
}

vuint8mf2x4_t test_vlsseg4e8_v_u8mf2x4 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8mf2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlsseg4e8.v.nxv4i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8mf2x4(*base, bstride);
}

vuint8m1x4_t test_vlsseg4e8_v_u8m1x4 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8m1x4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlsseg4e8.v.nxv8i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8m1x4(*base, bstride);
}

vuint8m2x4_t test_vlsseg4e8_v_u8m2x4 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8m2x4
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlsseg4e8.v.nxv16i8x4.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8m2x4(*base, bstride);
}

vint8mf8x4_t test_vlsseg4e8_v_i8mf8x4_m (vbool64_t mask, vint8mf8x4_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8mf8x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlsseg4e8.v.nxv1i8x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8mf8x4_m(mask, maskedoff, *base, bstride);
}

vint8mf4x4_t test_vlsseg4e8_v_i8mf4x4_m (vbool32_t mask, vint8mf4x4_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlsseg4e8.v.nxv2i8x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8mf4x4_m(mask, maskedoff, *base, bstride);
}

vint8mf2x4_t test_vlsseg4e8_v_i8mf2x4_m (vbool16_t mask, vint8mf2x4_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlsseg4e8.v.nxv4i8x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8mf2x4_m(mask, maskedoff, *base, bstride);
}

vint8m1x4_t test_vlsseg4e8_v_i8m1x4_m (vbool8_t mask, vint8m1x4_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8m1x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlsseg4e8.v.nxv8i8x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8m1x4_m(mask, maskedoff, *base, bstride);
}

vint8m2x4_t test_vlsseg4e8_v_i8m2x4_m (vbool4_t mask, vint8m2x4_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_i8m2x4_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlsseg4e8.v.nxv16i8x4.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_i8m2x4_m(mask, maskedoff, *base, bstride);
}

vuint8mf8x4_t test_vlsseg4e8_v_u8mf8x4_m (vbool64_t mask, vuint8mf8x4_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8mf8x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlsseg4e8.v.nxv1i8x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8mf8x4_m(mask, maskedoff, *base, bstride);
}

vuint8mf4x4_t test_vlsseg4e8_v_u8mf4x4_m (vbool32_t mask, vuint8mf4x4_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlsseg4e8.v.nxv2i8x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8mf4x4_m(mask, maskedoff, *base, bstride);
}

vuint8mf2x4_t test_vlsseg4e8_v_u8mf2x4_m (vbool16_t mask, vuint8mf2x4_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlsseg4e8.v.nxv4i8x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8mf2x4_m(mask, maskedoff, *base, bstride);
}

vuint8m1x4_t test_vlsseg4e8_v_u8m1x4_m (vbool8_t mask, vuint8m1x4_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8m1x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlsseg4e8.v.nxv8i8x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8m1x4_m(mask, maskedoff, *base, bstride);
}

vuint8m2x4_t test_vlsseg4e8_v_u8m2x4_m (vbool4_t mask, vuint8m2x4_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg4e8_v_u8m2x4_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlsseg4e8.v.nxv16i8x4.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg4e8_v_u8m2x4_m(mask, maskedoff, *base, bstride);
}


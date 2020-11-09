// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x3_t test_vlsseg3e8_v_i8mf8x3 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8mf8x3
  // CHECK: %{{.*}} = call <vscale x 3 x i8> @llvm.riscv.vlsseg3e8.v.nxv1i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8mf8x3(*base, bstride);
}

vint8mf4x3_t test_vlsseg3e8_v_i8mf4x3 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8mf4x3
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vlsseg3e8.v.nxv2i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8mf4x3(*base, bstride);
}

vint8mf2x3_t test_vlsseg3e8_v_i8mf2x3 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8mf2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vlsseg3e8.v.nxv4i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8mf2x3(*base, bstride);
}

vint8m1x3_t test_vlsseg3e8_v_i8m1x3 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8m1x3
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vlsseg3e8.v.nxv8i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8m1x3(*base, bstride);
}

vint8m2x3_t test_vlsseg3e8_v_i8m2x3 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8m2x3
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vlsseg3e8.v.nxv16i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8m2x3(*base, bstride);
}

vuint8mf8x3_t test_vlsseg3e8_v_u8mf8x3 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8mf8x3
  // CHECK: %{{.*}} = call <vscale x 3 x i8> @llvm.riscv.vlsseg3e8.v.nxv1i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8mf8x3(*base, bstride);
}

vuint8mf4x3_t test_vlsseg3e8_v_u8mf4x3 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8mf4x3
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vlsseg3e8.v.nxv2i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8mf4x3(*base, bstride);
}

vuint8mf2x3_t test_vlsseg3e8_v_u8mf2x3 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8mf2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vlsseg3e8.v.nxv4i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8mf2x3(*base, bstride);
}

vuint8m1x3_t test_vlsseg3e8_v_u8m1x3 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8m1x3
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vlsseg3e8.v.nxv8i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8m1x3(*base, bstride);
}

vuint8m2x3_t test_vlsseg3e8_v_u8m2x3 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8m2x3
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vlsseg3e8.v.nxv16i8x3.{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8m2x3(*base, bstride);
}

vint8mf8x3_t test_vlsseg3e8_v_i8mf8x3_m (vbool64_t mask, vint8mf8x3_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8mf8x3_m
  // CHECK: %{{.*}} = call <vscale x 3 x i8> @llvm.riscv.vlsseg3e8.v.nxv1i8x3.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 3 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8mf8x3_m(mask, maskedoff, *base, bstride);
}

vint8mf4x3_t test_vlsseg3e8_v_i8mf4x3_m (vbool32_t mask, vint8mf4x3_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8mf4x3_m
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vlsseg3e8.v.nxv2i8x3.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 6 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8mf4x3_m(mask, maskedoff, *base, bstride);
}

vint8mf2x3_t test_vlsseg3e8_v_i8mf2x3_m (vbool16_t mask, vint8mf2x3_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8mf2x3_m
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vlsseg3e8.v.nxv4i8x3.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 12 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8mf2x3_m(mask, maskedoff, *base, bstride);
}

vint8m1x3_t test_vlsseg3e8_v_i8m1x3_m (vbool8_t mask, vint8m1x3_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8m1x3_m
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vlsseg3e8.v.nxv8i8x3.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 24 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8m1x3_m(mask, maskedoff, *base, bstride);
}

vint8m2x3_t test_vlsseg3e8_v_i8m2x3_m (vbool4_t mask, vint8m2x3_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_i8m2x3_m
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vlsseg3e8.v.nxv16i8x3.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 48 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_i8m2x3_m(mask, maskedoff, *base, bstride);
}

vuint8mf8x3_t test_vlsseg3e8_v_u8mf8x3_m (vbool64_t mask, vuint8mf8x3_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8mf8x3_m
  // CHECK: %{{.*}} = call <vscale x 3 x i8> @llvm.riscv.vlsseg3e8.v.nxv1i8x3.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 3 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8mf8x3_m(mask, maskedoff, *base, bstride);
}

vuint8mf4x3_t test_vlsseg3e8_v_u8mf4x3_m (vbool32_t mask, vuint8mf4x3_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8mf4x3_m
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vlsseg3e8.v.nxv2i8x3.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 6 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8mf4x3_m(mask, maskedoff, *base, bstride);
}

vuint8mf2x3_t test_vlsseg3e8_v_u8mf2x3_m (vbool16_t mask, vuint8mf2x3_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8mf2x3_m
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vlsseg3e8.v.nxv4i8x3.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 12 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8mf2x3_m(mask, maskedoff, *base, bstride);
}

vuint8m1x3_t test_vlsseg3e8_v_u8m1x3_m (vbool8_t mask, vuint8m1x3_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8m1x3_m
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vlsseg3e8.v.nxv8i8x3.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 24 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8m1x3_m(mask, maskedoff, *base, bstride);
}

vuint8m2x3_t test_vlsseg3e8_v_u8m2x3_m (vbool4_t mask, vuint8m2x3_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlsseg3e8_v_u8m2x3_m
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vlsseg3e8.v.nxv16i8x3.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 48 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlsseg3e8_v_u8m2x3_m(mask, maskedoff, *base, bstride);
}


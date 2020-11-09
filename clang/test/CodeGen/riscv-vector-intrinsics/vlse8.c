// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vlse8_v_i8mf8 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vlse8.v.nxv1i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8mf8(*base, bstride);
}

vint8mf4_t test_vlse8_v_i8mf4 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlse8.v.nxv2i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8mf4(*base, bstride);
}

vint8mf2_t test_vlse8_v_i8mf2 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlse8.v.nxv4i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8mf2(*base, bstride);
}

vint8m1_t test_vlse8_v_i8m1 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlse8.v.nxv8i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8m1(*base, bstride);
}

vint8m2_t test_vlse8_v_i8m2 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlse8.v.nxv16i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8m2(*base, bstride);
}

vint8m4_t test_vlse8_v_i8m4 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlse8.v.nxv32i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8m4(*base, bstride);
}

vint8m8_t test_vlse8_v_i8m8 (int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlse8.v.nxv64i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8m8(*base, bstride);
}

vuint8mf8_t test_vlse8_v_u8mf8 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vlse8.v.nxv1i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8mf8(*base, bstride);
}

vuint8mf4_t test_vlse8_v_u8mf4 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlse8.v.nxv2i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8mf4(*base, bstride);
}

vuint8mf2_t test_vlse8_v_u8mf2 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlse8.v.nxv4i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8mf2(*base, bstride);
}

vuint8m1_t test_vlse8_v_u8m1 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlse8.v.nxv8i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8m1(*base, bstride);
}

vuint8m2_t test_vlse8_v_u8m2 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlse8.v.nxv16i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8m2(*base, bstride);
}

vuint8m4_t test_vlse8_v_u8m4 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlse8.v.nxv32i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8m4(*base, bstride);
}

vuint8m8_t test_vlse8_v_u8m8 (uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlse8.v.nxv64i8{{.*}}(i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8m8(*base, bstride);
}

vint8mf8_t test_vlse8_v_i8mf8_m (vbool64_t mask, vint8mf8_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vlse8.v.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8mf8_m(mask, maskedoff, *base, bstride);
}

vint8mf4_t test_vlse8_v_i8mf4_m (vbool32_t mask, vint8mf4_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlse8.v.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8mf4_m(mask, maskedoff, *base, bstride);
}

vint8mf2_t test_vlse8_v_i8mf2_m (vbool16_t mask, vint8mf2_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlse8.v.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8mf2_m(mask, maskedoff, *base, bstride);
}

vint8m1_t test_vlse8_v_i8m1_m (vbool8_t mask, vint8m1_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlse8.v.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8m1_m(mask, maskedoff, *base, bstride);
}

vint8m2_t test_vlse8_v_i8m2_m (vbool4_t mask, vint8m2_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlse8.v.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8m2_m(mask, maskedoff, *base, bstride);
}

vint8m4_t test_vlse8_v_i8m4_m (vbool2_t mask, vint8m4_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlse8.v.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8m4_m(mask, maskedoff, *base, bstride);
}

vint8m8_t test_vlse8_v_i8m8_m (vbool1_t mask, vint8m8_t maskedoff, int8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_i8m8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlse8.v.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_i8m8_m(mask, maskedoff, *base, bstride);
}

vuint8mf8_t test_vlse8_v_u8mf8_m (vbool64_t mask, vuint8mf8_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vlse8.v.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8mf8_m(mask, maskedoff, *base, bstride);
}

vuint8mf4_t test_vlse8_v_u8mf4_m (vbool32_t mask, vuint8mf4_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlse8.v.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8mf4_m(mask, maskedoff, *base, bstride);
}

vuint8mf2_t test_vlse8_v_u8mf2_m (vbool16_t mask, vuint8mf2_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlse8.v.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8mf2_m(mask, maskedoff, *base, bstride);
}

vuint8m1_t test_vlse8_v_u8m1_m (vbool8_t mask, vuint8m1_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlse8.v.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8m1_m(mask, maskedoff, *base, bstride);
}

vuint8m2_t test_vlse8_v_u8m2_m (vbool4_t mask, vuint8m2_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlse8.v.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8m2_m(mask, maskedoff, *base, bstride);
}

vuint8m4_t test_vlse8_v_u8m4_m (vbool2_t mask, vuint8m4_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlse8.v.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8m4_m(mask, maskedoff, *base, bstride);
}

vuint8m8_t test_vlse8_v_u8m8_m (vbool1_t mask, vuint8m8_t maskedoff, uint8_t *base, ptrdiff_t bstride) {
  // CHECK-LABEL: test_vlse8_v_u8m8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlse8.v.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, i64 %{{.*}})
  return vlse8_v_u8m8_m(mask, maskedoff, *base, bstride);
}


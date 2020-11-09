// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x2_t test_vlseg2e8_v_i8mf8x2 (int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8mf8x2
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlseg2e8.v.nxv1i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_i8mf8x2(*base);
}

vint8mf4x2_t test_vlseg2e8_v_i8mf4x2 (int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8mf4x2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlseg2e8.v.nxv2i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_i8mf4x2(*base);
}

vint8mf2x2_t test_vlseg2e8_v_i8mf2x2 (int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8mf2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlseg2e8.v.nxv4i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_i8mf2x2(*base);
}

vint8m1x2_t test_vlseg2e8_v_i8m1x2 (int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8m1x2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlseg2e8.v.nxv8i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_i8m1x2(*base);
}

vint8m2x2_t test_vlseg2e8_v_i8m2x2 (int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8m2x2
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlseg2e8.v.nxv16i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_i8m2x2(*base);
}

vint8m4x2_t test_vlseg2e8_v_i8m4x2 (int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8m4x2
  // CHECK: %{{.*}} = call <vscale x 54 x i8> @llvm.riscv.vlseg2e8.v.nxv32i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_i8m4x2(*base);
}

vuint8mf8x2_t test_vlseg2e8_v_u8mf8x2 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8mf8x2
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlseg2e8.v.nxv1i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_u8mf8x2(*base);
}

vuint8mf4x2_t test_vlseg2e8_v_u8mf4x2 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8mf4x2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlseg2e8.v.nxv2i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_u8mf4x2(*base);
}

vuint8mf2x2_t test_vlseg2e8_v_u8mf2x2 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8mf2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlseg2e8.v.nxv4i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_u8mf2x2(*base);
}

vuint8m1x2_t test_vlseg2e8_v_u8m1x2 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8m1x2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlseg2e8.v.nxv8i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_u8m1x2(*base);
}

vuint8m2x2_t test_vlseg2e8_v_u8m2x2 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8m2x2
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlseg2e8.v.nxv16i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_u8m2x2(*base);
}

vuint8m4x2_t test_vlseg2e8_v_u8m4x2 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8m4x2
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlseg2e8.v.nxv32i8x2.{{.*}}(i8 %{{.*}})
  return vlseg2e8_v_u8m4x2(*base);
}

vint8mf8x2_t test_vlseg2e8_v_i8mf8x2_m (vbool64_t mask, vint8mf8x2_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8mf8x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlseg2e8.v.nxv1i8x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_i8mf8x2_m(mask, maskedoff, *base);
}

vint8mf4x2_t test_vlseg2e8_v_i8mf4x2_m (vbool32_t mask, vint8mf4x2_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8mf4x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlseg2e8.v.nxv2i8x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_i8mf4x2_m(mask, maskedoff, *base);
}

vint8mf2x2_t test_vlseg2e8_v_i8mf2x2_m (vbool16_t mask, vint8mf2x2_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8mf2x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlseg2e8.v.nxv4i8x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_i8mf2x2_m(mask, maskedoff, *base);
}

vint8m1x2_t test_vlseg2e8_v_i8m1x2_m (vbool8_t mask, vint8m1x2_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8m1x2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlseg2e8.v.nxv8i8x2.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_i8m1x2_m(mask, maskedoff, *base);
}

vint8m2x2_t test_vlseg2e8_v_i8m2x2_m (vbool4_t mask, vint8m2x2_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8m2x2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlseg2e8.v.nxv16i8x2.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_i8m2x2_m(mask, maskedoff, *base);
}

vint8m4x2_t test_vlseg2e8_v_i8m4x2_m (vbool2_t mask, vint8m4x2_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_i8m4x2_m
  // CHECK: %{{.*}} = call <vscale x 54 x i8> @llvm.riscv.vlseg2e8.v.nxv32i8x2.mask.{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 54 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_i8m4x2_m(mask, maskedoff, *base);
}

vuint8mf8x2_t test_vlseg2e8_v_u8mf8x2_m (vbool64_t mask, vuint8mf8x2_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8mf8x2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlseg2e8.v.nxv1i8x2.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_u8mf8x2_m(mask, maskedoff, *base);
}

vuint8mf4x2_t test_vlseg2e8_v_u8mf4x2_m (vbool32_t mask, vuint8mf4x2_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8mf4x2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlseg2e8.v.nxv2i8x2.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_u8mf4x2_m(mask, maskedoff, *base);
}

vuint8mf2x2_t test_vlseg2e8_v_u8mf2x2_m (vbool16_t mask, vuint8mf2x2_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8mf2x2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlseg2e8.v.nxv4i8x2.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_u8mf2x2_m(mask, maskedoff, *base);
}

vuint8m1x2_t test_vlseg2e8_v_u8m1x2_m (vbool8_t mask, vuint8m1x2_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8m1x2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlseg2e8.v.nxv8i8x2.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_u8m1x2_m(mask, maskedoff, *base);
}

vuint8m2x2_t test_vlseg2e8_v_u8m2x2_m (vbool4_t mask, vuint8m2x2_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8m2x2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlseg2e8.v.nxv16i8x2.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_u8m2x2_m(mask, maskedoff, *base);
}

vuint8m4x2_t test_vlseg2e8_v_u8m4x2_m (vbool2_t mask, vuint8m4x2_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg2e8_v_u8m4x2_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlseg2e8.v.nxv32i8x2.mask.{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg2e8_v_u8m4x2_m(mask, maskedoff, *base);
}


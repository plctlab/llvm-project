// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x7_t test_vlseg7e8_v_i8mf8x7 (int8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_i8mf8x7
  // CHECK: %{{.*}} = call <vscale x 7 x i8> @llvm.riscv.vlseg7e8.v.nxv1i8x7.{{.*}}(i8 %{{.*}})
  return vlseg7e8_v_i8mf8x7(*base);
}

vint8mf4x7_t test_vlseg7e8_v_i8mf4x7 (int8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_i8mf4x7
  // CHECK: %{{.*}} = call <vscale x 14 x i8> @llvm.riscv.vlseg7e8.v.nxv2i8x7.{{.*}}(i8 %{{.*}})
  return vlseg7e8_v_i8mf4x7(*base);
}

vint8mf2x7_t test_vlseg7e8_v_i8mf2x7 (int8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_i8mf2x7
  // CHECK: %{{.*}} = call <vscale x 28 x i8> @llvm.riscv.vlseg7e8.v.nxv4i8x7.{{.*}}(i8 %{{.*}})
  return vlseg7e8_v_i8mf2x7(*base);
}

vint8m1x7_t test_vlseg7e8_v_i8m1x7 (int8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_i8m1x7
  // CHECK: %{{.*}} = call <vscale x 56 x i8> @llvm.riscv.vlseg7e8.v.nxv8i8x7.{{.*}}(i8 %{{.*}})
  return vlseg7e8_v_i8m1x7(*base);
}

vuint8mf8x7_t test_vlseg7e8_v_u8mf8x7 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_u8mf8x7
  // CHECK: %{{.*}} = call <vscale x 7 x i8> @llvm.riscv.vlseg7e8.v.nxv1i8x7.{{.*}}(i8 %{{.*}})
  return vlseg7e8_v_u8mf8x7(*base);
}

vuint8mf4x7_t test_vlseg7e8_v_u8mf4x7 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_u8mf4x7
  // CHECK: %{{.*}} = call <vscale x 14 x i8> @llvm.riscv.vlseg7e8.v.nxv2i8x7.{{.*}}(i8 %{{.*}})
  return vlseg7e8_v_u8mf4x7(*base);
}

vuint8mf2x7_t test_vlseg7e8_v_u8mf2x7 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_u8mf2x7
  // CHECK: %{{.*}} = call <vscale x 28 x i8> @llvm.riscv.vlseg7e8.v.nxv4i8x7.{{.*}}(i8 %{{.*}})
  return vlseg7e8_v_u8mf2x7(*base);
}

vuint8m1x7_t test_vlseg7e8_v_u8m1x7 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_u8m1x7
  // CHECK: %{{.*}} = call <vscale x 56 x i8> @llvm.riscv.vlseg7e8.v.nxv8i8x7.{{.*}}(i8 %{{.*}})
  return vlseg7e8_v_u8m1x7(*base);
}

vint8mf8x7_t test_vlseg7e8_v_i8mf8x7_m (vbool64_t mask, vint8mf8x7_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_i8mf8x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i8> @llvm.riscv.vlseg7e8.v.nxv1i8x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg7e8_v_i8mf8x7_m(mask, maskedoff, *base);
}

vint8mf4x7_t test_vlseg7e8_v_i8mf4x7_m (vbool32_t mask, vint8mf4x7_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_i8mf4x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x i8> @llvm.riscv.vlseg7e8.v.nxv2i8x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg7e8_v_i8mf4x7_m(mask, maskedoff, *base);
}

vint8mf2x7_t test_vlseg7e8_v_i8mf2x7_m (vbool16_t mask, vint8mf2x7_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_i8mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 28 x i8> @llvm.riscv.vlseg7e8.v.nxv4i8x7.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 28 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg7e8_v_i8mf2x7_m(mask, maskedoff, *base);
}

vint8m1x7_t test_vlseg7e8_v_i8m1x7_m (vbool8_t mask, vint8m1x7_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_i8m1x7_m
  // CHECK: %{{.*}} = call <vscale x 56 x i8> @llvm.riscv.vlseg7e8.v.nxv8i8x7.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 56 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg7e8_v_i8m1x7_m(mask, maskedoff, *base);
}

vuint8mf8x7_t test_vlseg7e8_v_u8mf8x7_m (vbool64_t mask, vuint8mf8x7_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_u8mf8x7_m
  // CHECK: %{{.*}} = call <vscale x 7 x i8> @llvm.riscv.vlseg7e8.v.nxv1i8x7.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 7 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg7e8_v_u8mf8x7_m(mask, maskedoff, *base);
}

vuint8mf4x7_t test_vlseg7e8_v_u8mf4x7_m (vbool32_t mask, vuint8mf4x7_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_u8mf4x7_m
  // CHECK: %{{.*}} = call <vscale x 14 x i8> @llvm.riscv.vlseg7e8.v.nxv2i8x7.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 14 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg7e8_v_u8mf4x7_m(mask, maskedoff, *base);
}

vuint8mf2x7_t test_vlseg7e8_v_u8mf2x7_m (vbool16_t mask, vuint8mf2x7_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_u8mf2x7_m
  // CHECK: %{{.*}} = call <vscale x 28 x i8> @llvm.riscv.vlseg7e8.v.nxv4i8x7.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 28 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg7e8_v_u8mf2x7_m(mask, maskedoff, *base);
}

vuint8m1x7_t test_vlseg7e8_v_u8m1x7_m (vbool8_t mask, vuint8m1x7_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg7e8_v_u8m1x7_m
  // CHECK: %{{.*}} = call <vscale x 56 x i8> @llvm.riscv.vlseg7e8.v.nxv8i8x7.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 56 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg7e8_v_u8m1x7_m(mask, maskedoff, *base);
}


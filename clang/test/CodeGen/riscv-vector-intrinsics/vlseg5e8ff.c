// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x5_t test_vlseg5e8ff_v_i8mf8x5 (int8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_i8mf8x5
  // CHECK: %{{.*}} = call <vscale x 5 x i8> @llvm.riscv.vlseg5e8ff.v.nxv1i8x5.{{.*}}(i8 %{{.*}})
  return vlseg5e8ff_v_i8mf8x5(*base);
}

vint8mf4x5_t test_vlseg5e8ff_v_i8mf4x5 (int8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_i8mf4x5
  // CHECK: %{{.*}} = call <vscale x 10 x i8> @llvm.riscv.vlseg5e8ff.v.nxv2i8x5.{{.*}}(i8 %{{.*}})
  return vlseg5e8ff_v_i8mf4x5(*base);
}

vint8mf2x5_t test_vlseg5e8ff_v_i8mf2x5 (int8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_i8mf2x5
  // CHECK: %{{.*}} = call <vscale x 20 x i8> @llvm.riscv.vlseg5e8ff.v.nxv4i8x5.{{.*}}(i8 %{{.*}})
  return vlseg5e8ff_v_i8mf2x5(*base);
}

vint8m1x5_t test_vlseg5e8ff_v_i8m1x5 (int8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_i8m1x5
  // CHECK: %{{.*}} = call <vscale x 40 x i8> @llvm.riscv.vlseg5e8ff.v.nxv8i8x5.{{.*}}(i8 %{{.*}})
  return vlseg5e8ff_v_i8m1x5(*base);
}

vuint8mf8x5_t test_vlseg5e8ff_v_u8mf8x5 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_u8mf8x5
  // CHECK: %{{.*}} = call <vscale x 5 x i8> @llvm.riscv.vlseg5e8ff.v.nxv1i8x5.{{.*}}(i8 %{{.*}})
  return vlseg5e8ff_v_u8mf8x5(*base);
}

vuint8mf4x5_t test_vlseg5e8ff_v_u8mf4x5 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_u8mf4x5
  // CHECK: %{{.*}} = call <vscale x 10 x i8> @llvm.riscv.vlseg5e8ff.v.nxv2i8x5.{{.*}}(i8 %{{.*}})
  return vlseg5e8ff_v_u8mf4x5(*base);
}

vuint8mf2x5_t test_vlseg5e8ff_v_u8mf2x5 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_u8mf2x5
  // CHECK: %{{.*}} = call <vscale x 20 x i8> @llvm.riscv.vlseg5e8ff.v.nxv4i8x5.{{.*}}(i8 %{{.*}})
  return vlseg5e8ff_v_u8mf2x5(*base);
}

vuint8m1x5_t test_vlseg5e8ff_v_u8m1x5 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_u8m1x5
  // CHECK: %{{.*}} = call <vscale x 40 x i8> @llvm.riscv.vlseg5e8ff.v.nxv8i8x5.{{.*}}(i8 %{{.*}})
  return vlseg5e8ff_v_u8m1x5(*base);
}

vint8mf8x5_t test_vlseg5e8ff_v_i8mf8x5_m (vbool64_t mask, vint8mf8x5_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_i8mf8x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x i8> @llvm.riscv.vlseg5e8ff.v.nxv1i8x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg5e8ff_v_i8mf8x5_m(mask, maskedoff, *base);
}

vint8mf4x5_t test_vlseg5e8ff_v_i8mf4x5_m (vbool32_t mask, vint8mf4x5_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_i8mf4x5_m
  // CHECK: %{{.*}} = call <vscale x 10 x i8> @llvm.riscv.vlseg5e8ff.v.nxv2i8x5.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 10 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg5e8ff_v_i8mf4x5_m(mask, maskedoff, *base);
}

vint8mf2x5_t test_vlseg5e8ff_v_i8mf2x5_m (vbool16_t mask, vint8mf2x5_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_i8mf2x5_m
  // CHECK: %{{.*}} = call <vscale x 20 x i8> @llvm.riscv.vlseg5e8ff.v.nxv4i8x5.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 20 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg5e8ff_v_i8mf2x5_m(mask, maskedoff, *base);
}

vint8m1x5_t test_vlseg5e8ff_v_i8m1x5_m (vbool8_t mask, vint8m1x5_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_i8m1x5_m
  // CHECK: %{{.*}} = call <vscale x 40 x i8> @llvm.riscv.vlseg5e8ff.v.nxv8i8x5.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 40 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg5e8ff_v_i8m1x5_m(mask, maskedoff, *base);
}

vuint8mf8x5_t test_vlseg5e8ff_v_u8mf8x5_m (vbool64_t mask, vuint8mf8x5_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_u8mf8x5_m
  // CHECK: %{{.*}} = call <vscale x 5 x i8> @llvm.riscv.vlseg5e8ff.v.nxv1i8x5.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 5 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg5e8ff_v_u8mf8x5_m(mask, maskedoff, *base);
}

vuint8mf4x5_t test_vlseg5e8ff_v_u8mf4x5_m (vbool32_t mask, vuint8mf4x5_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_u8mf4x5_m
  // CHECK: %{{.*}} = call <vscale x 10 x i8> @llvm.riscv.vlseg5e8ff.v.nxv2i8x5.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 10 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg5e8ff_v_u8mf4x5_m(mask, maskedoff, *base);
}

vuint8mf2x5_t test_vlseg5e8ff_v_u8mf2x5_m (vbool16_t mask, vuint8mf2x5_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_u8mf2x5_m
  // CHECK: %{{.*}} = call <vscale x 20 x i8> @llvm.riscv.vlseg5e8ff.v.nxv4i8x5.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 20 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg5e8ff_v_u8mf2x5_m(mask, maskedoff, *base);
}

vuint8m1x5_t test_vlseg5e8ff_v_u8m1x5_m (vbool8_t mask, vuint8m1x5_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg5e8ff_v_u8m1x5_m
  // CHECK: %{{.*}} = call <vscale x 40 x i8> @llvm.riscv.vlseg5e8ff.v.nxv8i8x5.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 40 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg5e8ff_v_u8m1x5_m(mask, maskedoff, *base);
}


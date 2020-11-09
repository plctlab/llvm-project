// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x8_t test_vlseg8e8ff_v_i8mf8x8 (int8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_i8mf8x8
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlseg8e8ff.v.nxv1i8x8.{{.*}}(i8 %{{.*}})
  return vlseg8e8ff_v_i8mf8x8(*base);
}

vint8mf4x8_t test_vlseg8e8ff_v_i8mf4x8 (int8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_i8mf4x8
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlseg8e8ff.v.nxv2i8x8.{{.*}}(i8 %{{.*}})
  return vlseg8e8ff_v_i8mf4x8(*base);
}

vint8mf2x8_t test_vlseg8e8ff_v_i8mf2x8 (int8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_i8mf2x8
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlseg8e8ff.v.nxv4i8x8.{{.*}}(i8 %{{.*}})
  return vlseg8e8ff_v_i8mf2x8(*base);
}

vint8m1x8_t test_vlseg8e8ff_v_i8m1x8 (int8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_i8m1x8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlseg8e8ff.v.nxv8i8x8.{{.*}}(i8 %{{.*}})
  return vlseg8e8ff_v_i8m1x8(*base);
}

vuint8mf8x8_t test_vlseg8e8ff_v_u8mf8x8 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_u8mf8x8
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlseg8e8ff.v.nxv1i8x8.{{.*}}(i8 %{{.*}})
  return vlseg8e8ff_v_u8mf8x8(*base);
}

vuint8mf4x8_t test_vlseg8e8ff_v_u8mf4x8 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_u8mf4x8
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlseg8e8ff.v.nxv2i8x8.{{.*}}(i8 %{{.*}})
  return vlseg8e8ff_v_u8mf4x8(*base);
}

vuint8mf2x8_t test_vlseg8e8ff_v_u8mf2x8 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_u8mf2x8
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlseg8e8ff.v.nxv4i8x8.{{.*}}(i8 %{{.*}})
  return vlseg8e8ff_v_u8mf2x8(*base);
}

vuint8m1x8_t test_vlseg8e8ff_v_u8m1x8 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_u8m1x8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlseg8e8ff.v.nxv8i8x8.{{.*}}(i8 %{{.*}})
  return vlseg8e8ff_v_u8m1x8(*base);
}

vint8mf8x8_t test_vlseg8e8ff_v_i8mf8x8_m (vbool64_t mask, vint8mf8x8_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_i8mf8x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlseg8e8ff.v.nxv1i8x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg8e8ff_v_i8mf8x8_m(mask, maskedoff, *base);
}

vint8mf4x8_t test_vlseg8e8ff_v_i8mf4x8_m (vbool32_t mask, vint8mf4x8_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_i8mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlseg8e8ff.v.nxv2i8x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg8e8ff_v_i8mf4x8_m(mask, maskedoff, *base);
}

vint8mf2x8_t test_vlseg8e8ff_v_i8mf2x8_m (vbool16_t mask, vint8mf2x8_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_i8mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlseg8e8ff.v.nxv4i8x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg8e8ff_v_i8mf2x8_m(mask, maskedoff, *base);
}

vint8m1x8_t test_vlseg8e8ff_v_i8m1x8_m (vbool8_t mask, vint8m1x8_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_i8m1x8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlseg8e8ff.v.nxv8i8x8.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg8e8ff_v_i8m1x8_m(mask, maskedoff, *base);
}

vuint8mf8x8_t test_vlseg8e8ff_v_u8mf8x8_m (vbool64_t mask, vuint8mf8x8_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_u8mf8x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlseg8e8ff.v.nxv1i8x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg8e8ff_v_u8mf8x8_m(mask, maskedoff, *base);
}

vuint8mf4x8_t test_vlseg8e8ff_v_u8mf4x8_m (vbool32_t mask, vuint8mf4x8_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_u8mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlseg8e8ff.v.nxv2i8x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg8e8ff_v_u8mf4x8_m(mask, maskedoff, *base);
}

vuint8mf2x8_t test_vlseg8e8ff_v_u8mf2x8_m (vbool16_t mask, vuint8mf2x8_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_u8mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlseg8e8ff.v.nxv4i8x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg8e8ff_v_u8mf2x8_m(mask, maskedoff, *base);
}

vuint8m1x8_t test_vlseg8e8ff_v_u8m1x8_m (vbool8_t mask, vuint8m1x8_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg8e8ff_v_u8m1x8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlseg8e8ff.v.nxv8i8x8.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg8e8ff_v_u8m1x8_m(mask, maskedoff, *base);
}


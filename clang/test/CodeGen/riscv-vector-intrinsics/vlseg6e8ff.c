// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x6_t test_vlseg6e8ff_v_i8mf8x6 (int8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_i8mf8x6
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vlseg6e8ff.v.nxv1i8x6.{{.*}}(i8 %{{.*}})
  return vlseg6e8ff_v_i8mf8x6(*base);
}

vint8mf4x6_t test_vlseg6e8ff_v_i8mf4x6 (int8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_i8mf4x6
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vlseg6e8ff.v.nxv2i8x6.{{.*}}(i8 %{{.*}})
  return vlseg6e8ff_v_i8mf4x6(*base);
}

vint8mf2x6_t test_vlseg6e8ff_v_i8mf2x6 (int8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_i8mf2x6
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vlseg6e8ff.v.nxv4i8x6.{{.*}}(i8 %{{.*}})
  return vlseg6e8ff_v_i8mf2x6(*base);
}

vint8m1x6_t test_vlseg6e8ff_v_i8m1x6 (int8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_i8m1x6
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vlseg6e8ff.v.nxv8i8x6.{{.*}}(i8 %{{.*}})
  return vlseg6e8ff_v_i8m1x6(*base);
}

vuint8mf8x6_t test_vlseg6e8ff_v_u8mf8x6 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_u8mf8x6
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vlseg6e8ff.v.nxv1i8x6.{{.*}}(i8 %{{.*}})
  return vlseg6e8ff_v_u8mf8x6(*base);
}

vuint8mf4x6_t test_vlseg6e8ff_v_u8mf4x6 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_u8mf4x6
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vlseg6e8ff.v.nxv2i8x6.{{.*}}(i8 %{{.*}})
  return vlseg6e8ff_v_u8mf4x6(*base);
}

vuint8mf2x6_t test_vlseg6e8ff_v_u8mf2x6 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_u8mf2x6
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vlseg6e8ff.v.nxv4i8x6.{{.*}}(i8 %{{.*}})
  return vlseg6e8ff_v_u8mf2x6(*base);
}

vuint8m1x6_t test_vlseg6e8ff_v_u8m1x6 (uint8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_u8m1x6
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vlseg6e8ff.v.nxv8i8x6.{{.*}}(i8 %{{.*}})
  return vlseg6e8ff_v_u8m1x6(*base);
}

vint8mf8x6_t test_vlseg6e8ff_v_i8mf8x6_m (vbool64_t mask, vint8mf8x6_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_i8mf8x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vlseg6e8ff.v.nxv1i8x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg6e8ff_v_i8mf8x6_m(mask, maskedoff, *base);
}

vint8mf4x6_t test_vlseg6e8ff_v_i8mf4x6_m (vbool32_t mask, vint8mf4x6_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_i8mf4x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vlseg6e8ff.v.nxv2i8x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg6e8ff_v_i8mf4x6_m(mask, maskedoff, *base);
}

vint8mf2x6_t test_vlseg6e8ff_v_i8mf2x6_m (vbool16_t mask, vint8mf2x6_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_i8mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vlseg6e8ff.v.nxv4i8x6.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 24 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg6e8ff_v_i8mf2x6_m(mask, maskedoff, *base);
}

vint8m1x6_t test_vlseg6e8ff_v_i8m1x6_m (vbool8_t mask, vint8m1x6_t maskedoff, int8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_i8m1x6_m
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vlseg6e8ff.v.nxv8i8x6.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 48 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg6e8ff_v_i8m1x6_m(mask, maskedoff, *base);
}

vuint8mf8x6_t test_vlseg6e8ff_v_u8mf8x6_m (vbool64_t mask, vuint8mf8x6_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_u8mf8x6_m
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vlseg6e8ff.v.nxv1i8x6.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 6 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg6e8ff_v_u8mf8x6_m(mask, maskedoff, *base);
}

vuint8mf4x6_t test_vlseg6e8ff_v_u8mf4x6_m (vbool32_t mask, vuint8mf4x6_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_u8mf4x6_m
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vlseg6e8ff.v.nxv2i8x6.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 12 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg6e8ff_v_u8mf4x6_m(mask, maskedoff, *base);
}

vuint8mf2x6_t test_vlseg6e8ff_v_u8mf2x6_m (vbool16_t mask, vuint8mf2x6_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_u8mf2x6_m
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vlseg6e8ff.v.nxv4i8x6.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 24 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg6e8ff_v_u8mf2x6_m(mask, maskedoff, *base);
}

vuint8m1x6_t test_vlseg6e8ff_v_u8m1x6_m (vbool8_t mask, vuint8m1x6_t maskedoff, uint8_t *base) {
  // CHECK-LABEL: test_vlseg6e8ff_v_u8m1x6_m
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vlseg6e8ff.v.nxv8i8x6.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 48 x i8> %{{.*}}, i8 %{{.*}})
  return vlseg6e8ff_v_u8m1x6_m(mask, maskedoff, *base);
}


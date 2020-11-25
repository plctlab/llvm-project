// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v  -fallow-half-arguments-and-returns -fnative-half-type  -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4_t test_vle16_v_i16mf4 (int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vload.nxv1i16{{.*}}(i16* %{{.*}})
  return vle16_v_i16mf4(base);
}

vint16mf2_t test_vle16_v_i16mf2 (int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vload.nxv2i16{{.*}}(i16* %{{.*}})
  return vle16_v_i16mf2(base);
}

vint16m1_t test_vle16_v_i16m1 (int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vload.nxv4i16{{.*}}(i16* %{{.*}})
  return vle16_v_i16m1(base);
}

vint16m2_t test_vle16_v_i16m2 (int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vload.nxv8i16{{.*}}(i16* %{{.*}})
  return vle16_v_i16m2(base);
}

vint16m4_t test_vle16_v_i16m4 (int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vload.nxv16i16{{.*}}(i16* %{{.*}})
  return vle16_v_i16m4(base);
}

vint16m8_t test_vle16_v_i16m8 (int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vload.nxv32i16{{.*}}(i16* %{{.*}})
  return vle16_v_i16m8(base);
}

vuint16mf4_t test_vle16_v_u16mf4 (uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vload.nxv1i16{{.*}}(i16* %{{.*}})
  return vle16_v_u16mf4(base);
}

vuint16mf2_t test_vle16_v_u16mf2 (uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vload.nxv2i16{{.*}}(i16* %{{.*}})
  return vle16_v_u16mf2(base);
}

vuint16m1_t test_vle16_v_u16m1 (uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vload.nxv4i16{{.*}}(i16* %{{.*}})
  return vle16_v_u16m1(base);
}

vuint16m2_t test_vle16_v_u16m2 (uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vload.nxv8i16{{.*}}(i16* %{{.*}})
  return vle16_v_u16m2(base);
}

vuint16m4_t test_vle16_v_u16m4 (uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vload.nxv16i16{{.*}}(i16* %{{.*}})
  return vle16_v_u16m4(base);
}

vuint16m8_t test_vle16_v_u16m8 (uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vload.nxv32i16{{.*}}(i16* %{{.*}})
  return vle16_v_u16m8(base);
}

vfloat16mf4_t test_vle16_v_f16mf4 (float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vload.nxv1f16{{.*}}(half* %{{.*}})
  return vle16_v_f16mf4(base);
}

vfloat16mf2_t test_vle16_v_f16mf2 (float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vload.nxv2f16{{.*}}(half* %{{.*}})
  return vle16_v_f16mf2(base);
}

vfloat16m1_t test_vle16_v_f16m1 (float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vload.nxv4f16{{.*}}(half* %{{.*}})
  return vle16_v_f16m1(base);
}

vfloat16m2_t test_vle16_v_f16m2 (float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vload.nxv8f16{{.*}}(half* %{{.*}})
  return vle16_v_f16m2(base);
}

vfloat16m4_t test_vle16_v_f16m4 (float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vload.nxv16f16{{.*}}(half* %{{.*}})
  return vle16_v_f16m4(base);
}

vfloat16m8_t test_vle16_v_f16m8 (float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vload.nxv32f16{{.*}}(half* %{{.*}})
  return vle16_v_f16m8(base);
}

vint16mf4_t test_vle16_v_i16mf4_m (vbool64_t mask, vint16mf4_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vload.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_i16mf4_m(mask, maskedoff, base);
}

vint16mf2_t test_vle16_v_i16mf2_m (vbool32_t mask, vint16mf2_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vload.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_i16mf2_m(mask, maskedoff, base);
}

vint16m1_t test_vle16_v_i16m1_m (vbool16_t mask, vint16m1_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vload.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_i16m1_m(mask, maskedoff, base);
}

vint16m2_t test_vle16_v_i16m2_m (vbool8_t mask, vint16m2_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vload.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_i16m2_m(mask, maskedoff, base);
}

vint16m4_t test_vle16_v_i16m4_m (vbool4_t mask, vint16m4_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vload.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_i16m4_m(mask, maskedoff, base);
}

vint16m8_t test_vle16_v_i16m8_m (vbool2_t mask, vint16m8_t maskedoff, int16_t *base) {
  // CHECK-LABEL: test_vle16_v_i16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vload.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_i16m8_m(mask, maskedoff, base);
}

vuint16mf4_t test_vle16_v_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vload.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_u16mf4_m(mask, maskedoff, base);
}

vuint16mf2_t test_vle16_v_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vload.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_u16mf2_m(mask, maskedoff, base);
}

vuint16m1_t test_vle16_v_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vload.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_u16m1_m(mask, maskedoff, base);
}

vuint16m2_t test_vle16_v_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vload.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_u16m2_m(mask, maskedoff, base);
}

vuint16m4_t test_vle16_v_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vload.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_u16m4_m(mask, maskedoff, base);
}

vuint16m8_t test_vle16_v_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff, uint16_t *base) {
  // CHECK-LABEL: test_vle16_v_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vload.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16* %{{.*}})
  return vle16_v_u16m8_m(mask, maskedoff, base);
}

vfloat16mf4_t test_vle16_v_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vload.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half* %{{.*}})
  return vle16_v_f16mf4_m(mask, maskedoff, base);
}

vfloat16mf2_t test_vle16_v_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vload.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half* %{{.*}})
  return vle16_v_f16mf2_m(mask, maskedoff, base);
}

vfloat16m1_t test_vle16_v_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vload.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half* %{{.*}})
  return vle16_v_f16m1_m(mask, maskedoff, base);
}

vfloat16m2_t test_vle16_v_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vload.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half* %{{.*}})
  return vle16_v_f16m2_m(mask, maskedoff, base);
}

vfloat16m4_t test_vle16_v_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vload.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half* %{{.*}})
  return vle16_v_f16m4_m(mask, maskedoff, base);
}

vfloat16m8_t test_vle16_v_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, float16_t *base) {
  // CHECK-LABEL: test_vle16_v_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vload.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half* %{{.*}})
  return vle16_v_f16m8_m(mask, maskedoff, base);
}


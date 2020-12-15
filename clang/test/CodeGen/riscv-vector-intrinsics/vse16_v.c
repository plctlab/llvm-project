// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vse16_v_i16mf4 (int16_t *base, vint16mf4_t value) {
  // CHECK-LABEL: test_vse16_v_i16mf4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i16{{.*}}(i16* %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vse16_v_i16mf4(base, value);
}

void test_vse16_v_i16mf2 (int16_t *base, vint16mf2_t value) {
  // CHECK-LABEL: test_vse16_v_i16mf2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i16{{.*}}(i16* %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vse16_v_i16mf2(base, value);
}

void test_vse16_v_i16m1 (int16_t *base, vint16m1_t value) {
  // CHECK-LABEL: test_vse16_v_i16m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i16{{.*}}(i16* %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vse16_v_i16m1(base, value);
}

void test_vse16_v_i16m2 (int16_t *base, vint16m2_t value) {
  // CHECK-LABEL: test_vse16_v_i16m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i16{{.*}}(i16* %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vse16_v_i16m2(base, value);
}

void test_vse16_v_i16m4 (int16_t *base, vint16m4_t value) {
  // CHECK-LABEL: test_vse16_v_i16m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i16{{.*}}(i16* %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vse16_v_i16m4(base, value);
}

void test_vse16_v_i16m8 (int16_t *base, vint16m8_t value) {
  // CHECK-LABEL: test_vse16_v_i16m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32i16{{.*}}(i16* %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vse16_v_i16m8(base, value);
}

void test_vse16_v_u16mf4 (uint16_t *base, vuint16mf4_t value) {
  // CHECK-LABEL: test_vse16_v_u16mf4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i16{{.*}}(i16* %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vse16_v_u16mf4(base, value);
}

void test_vse16_v_u16mf2 (uint16_t *base, vuint16mf2_t value) {
  // CHECK-LABEL: test_vse16_v_u16mf2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i16{{.*}}(i16* %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vse16_v_u16mf2(base, value);
}

void test_vse16_v_u16m1 (uint16_t *base, vuint16m1_t value) {
  // CHECK-LABEL: test_vse16_v_u16m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i16{{.*}}(i16* %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vse16_v_u16m1(base, value);
}

void test_vse16_v_u16m2 (uint16_t *base, vuint16m2_t value) {
  // CHECK-LABEL: test_vse16_v_u16m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i16{{.*}}(i16* %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vse16_v_u16m2(base, value);
}

void test_vse16_v_u16m4 (uint16_t *base, vuint16m4_t value) {
  // CHECK-LABEL: test_vse16_v_u16m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i16{{.*}}(i16* %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vse16_v_u16m4(base, value);
}

void test_vse16_v_u16m8 (uint16_t *base, vuint16m8_t value) {
  // CHECK-LABEL: test_vse16_v_u16m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32i16{{.*}}(i16* %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vse16_v_u16m8(base, value);
}

void test_vse16_v_f16mf4 (float16_t *base, vfloat16mf4_t value) {
  // CHECK-LABEL: test_vse16_v_f16mf4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1f16{{.*}}(half* %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vse16_v_f16mf4(base, value);
}

void test_vse16_v_f16mf2 (float16_t *base, vfloat16mf2_t value) {
  // CHECK-LABEL: test_vse16_v_f16mf2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2f16{{.*}}(half* %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vse16_v_f16mf2(base, value);
}

void test_vse16_v_f16m1 (float16_t *base, vfloat16m1_t value) {
  // CHECK-LABEL: test_vse16_v_f16m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4f16{{.*}}(half* %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vse16_v_f16m1(base, value);
}

void test_vse16_v_f16m2 (float16_t *base, vfloat16m2_t value) {
  // CHECK-LABEL: test_vse16_v_f16m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8f16{{.*}}(half* %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vse16_v_f16m2(base, value);
}

void test_vse16_v_f16m4 (float16_t *base, vfloat16m4_t value) {
  // CHECK-LABEL: test_vse16_v_f16m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16f16{{.*}}(half* %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vse16_v_f16m4(base, value);
}

void test_vse16_v_f16m8 (float16_t *base, vfloat16m8_t value) {
  // CHECK-LABEL: test_vse16_v_f16m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32f16{{.*}}(half* %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vse16_v_f16m8(base, value);
}

void test_vse16_v_i16mf4_m (vbool64_t mask, int16_t *base, vint16mf4_t value) {
  // CHECK-LABEL: test_vse16_v_i16mf4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vse16_v_i16mf4_m(mask, base, value);
}

void test_vse16_v_i16mf2_m (vbool32_t mask, int16_t *base, vint16mf2_t value) {
  // CHECK-LABEL: test_vse16_v_i16mf2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vse16_v_i16mf2_m(mask, base, value);
}

void test_vse16_v_i16m1_m (vbool16_t mask, int16_t *base, vint16m1_t value) {
  // CHECK-LABEL: test_vse16_v_i16m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vse16_v_i16m1_m(mask, base, value);
}

void test_vse16_v_i16m2_m (vbool8_t mask, int16_t *base, vint16m2_t value) {
  // CHECK-LABEL: test_vse16_v_i16m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vse16_v_i16m2_m(mask, base, value);
}

void test_vse16_v_i16m4_m (vbool4_t mask, int16_t *base, vint16m4_t value) {
  // CHECK-LABEL: test_vse16_v_i16m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vse16_v_i16m4_m(mask, base, value);
}

void test_vse16_v_i16m8_m (vbool2_t mask, int16_t *base, vint16m8_t value) {
  // CHECK-LABEL: test_vse16_v_i16m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vse16_v_i16m8_m(mask, base, value);
}

void test_vse16_v_u16mf4_m (vbool64_t mask, uint16_t *base, vuint16mf4_t value) {
  // CHECK-LABEL: test_vse16_v_u16mf4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vse16_v_u16mf4_m(mask, base, value);
}

void test_vse16_v_u16mf2_m (vbool32_t mask, uint16_t *base, vuint16mf2_t value) {
  // CHECK-LABEL: test_vse16_v_u16mf2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vse16_v_u16mf2_m(mask, base, value);
}

void test_vse16_v_u16m1_m (vbool16_t mask, uint16_t *base, vuint16m1_t value) {
  // CHECK-LABEL: test_vse16_v_u16m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vse16_v_u16m1_m(mask, base, value);
}

void test_vse16_v_u16m2_m (vbool8_t mask, uint16_t *base, vuint16m2_t value) {
  // CHECK-LABEL: test_vse16_v_u16m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vse16_v_u16m2_m(mask, base, value);
}

void test_vse16_v_u16m4_m (vbool4_t mask, uint16_t *base, vuint16m4_t value) {
  // CHECK-LABEL: test_vse16_v_u16m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vse16_v_u16m4_m(mask, base, value);
}

void test_vse16_v_u16m8_m (vbool2_t mask, uint16_t *base, vuint16m8_t value) {
  // CHECK-LABEL: test_vse16_v_u16m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, i16* %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vse16_v_u16m8_m(mask, base, value);
}

void test_vse16_v_f16mf4_m (vbool64_t mask, float16_t *base, vfloat16mf4_t value) {
  // CHECK-LABEL: test_vse16_v_f16mf4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, half* %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vse16_v_f16mf4_m(mask, base, value);
}

void test_vse16_v_f16mf2_m (vbool32_t mask, float16_t *base, vfloat16mf2_t value) {
  // CHECK-LABEL: test_vse16_v_f16mf2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, half* %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vse16_v_f16mf2_m(mask, base, value);
}

void test_vse16_v_f16m1_m (vbool16_t mask, float16_t *base, vfloat16m1_t value) {
  // CHECK-LABEL: test_vse16_v_f16m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, half* %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vse16_v_f16m1_m(mask, base, value);
}

void test_vse16_v_f16m2_m (vbool8_t mask, float16_t *base, vfloat16m2_t value) {
  // CHECK-LABEL: test_vse16_v_f16m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, half* %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vse16_v_f16m2_m(mask, base, value);
}

void test_vse16_v_f16m4_m (vbool4_t mask, float16_t *base, vfloat16m4_t value) {
  // CHECK-LABEL: test_vse16_v_f16m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, half* %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vse16_v_f16m4_m(mask, base, value);
}

void test_vse16_v_f16m8_m (vbool2_t mask, float16_t *base, vfloat16m8_t value) {
  // CHECK-LABEL: test_vse16_v_f16m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, half* %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vse16_v_f16m8_m(mask, base, value);
}


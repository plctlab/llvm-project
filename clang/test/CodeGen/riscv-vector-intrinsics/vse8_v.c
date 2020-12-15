// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vse8_v_i8mf8 (int8_t *base, vint8mf8_t value) {
  // CHECK-LABEL: test_vse8_v_i8mf8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i8{{.*}}(i8* %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vse8_v_i8mf8(base, value);
}

void test_vse8_v_i8mf4 (int8_t *base, vint8mf4_t value) {
  // CHECK-LABEL: test_vse8_v_i8mf4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i8{{.*}}(i8* %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vse8_v_i8mf4(base, value);
}

void test_vse8_v_i8mf2 (int8_t *base, vint8mf2_t value) {
  // CHECK-LABEL: test_vse8_v_i8mf2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i8{{.*}}(i8* %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vse8_v_i8mf2(base, value);
}

void test_vse8_v_i8m1 (int8_t *base, vint8m1_t value) {
  // CHECK-LABEL: test_vse8_v_i8m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i8{{.*}}(i8* %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vse8_v_i8m1(base, value);
}

void test_vse8_v_i8m2 (int8_t *base, vint8m2_t value) {
  // CHECK-LABEL: test_vse8_v_i8m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i8{{.*}}(i8* %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vse8_v_i8m2(base, value);
}

void test_vse8_v_i8m4 (int8_t *base, vint8m4_t value) {
  // CHECK-LABEL: test_vse8_v_i8m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32i8{{.*}}(i8* %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vse8_v_i8m4(base, value);
}

void test_vse8_v_i8m8 (int8_t *base, vint8m8_t value) {
  // CHECK-LABEL: test_vse8_v_i8m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv64i8{{.*}}(i8* %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vse8_v_i8m8(base, value);
}

void test_vse8_v_u8mf8 (uint8_t *base, vuint8mf8_t value) {
  // CHECK-LABEL: test_vse8_v_u8mf8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i8{{.*}}(i8* %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vse8_v_u8mf8(base, value);
}

void test_vse8_v_u8mf4 (uint8_t *base, vuint8mf4_t value) {
  // CHECK-LABEL: test_vse8_v_u8mf4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i8{{.*}}(i8* %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vse8_v_u8mf4(base, value);
}

void test_vse8_v_u8mf2 (uint8_t *base, vuint8mf2_t value) {
  // CHECK-LABEL: test_vse8_v_u8mf2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i8{{.*}}(i8* %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vse8_v_u8mf2(base, value);
}

void test_vse8_v_u8m1 (uint8_t *base, vuint8m1_t value) {
  // CHECK-LABEL: test_vse8_v_u8m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i8{{.*}}(i8* %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vse8_v_u8m1(base, value);
}

void test_vse8_v_u8m2 (uint8_t *base, vuint8m2_t value) {
  // CHECK-LABEL: test_vse8_v_u8m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i8{{.*}}(i8* %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vse8_v_u8m2(base, value);
}

void test_vse8_v_u8m4 (uint8_t *base, vuint8m4_t value) {
  // CHECK-LABEL: test_vse8_v_u8m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32i8{{.*}}(i8* %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vse8_v_u8m4(base, value);
}

void test_vse8_v_u8m8 (uint8_t *base, vuint8m8_t value) {
  // CHECK-LABEL: test_vse8_v_u8m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv64i8{{.*}}(i8* %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vse8_v_u8m8(base, value);
}

void test_vse8_v_i8mf8_m (vbool64_t mask, int8_t *base, vint8mf8_t value) {
  // CHECK-LABEL: test_vse8_v_i8mf8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vse8_v_i8mf8_m(mask, base, value);
}

void test_vse8_v_i8mf4_m (vbool32_t mask, int8_t *base, vint8mf4_t value) {
  // CHECK-LABEL: test_vse8_v_i8mf4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vse8_v_i8mf4_m(mask, base, value);
}

void test_vse8_v_i8mf2_m (vbool16_t mask, int8_t *base, vint8mf2_t value) {
  // CHECK-LABEL: test_vse8_v_i8mf2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vse8_v_i8mf2_m(mask, base, value);
}

void test_vse8_v_i8m1_m (vbool8_t mask, int8_t *base, vint8m1_t value) {
  // CHECK-LABEL: test_vse8_v_i8m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vse8_v_i8m1_m(mask, base, value);
}

void test_vse8_v_i8m2_m (vbool4_t mask, int8_t *base, vint8m2_t value) {
  // CHECK-LABEL: test_vse8_v_i8m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vse8_v_i8m2_m(mask, base, value);
}

void test_vse8_v_i8m4_m (vbool2_t mask, int8_t *base, vint8m4_t value) {
  // CHECK-LABEL: test_vse8_v_i8m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vse8_v_i8m4_m(mask, base, value);
}

void test_vse8_v_i8m8_m (vbool1_t mask, int8_t *base, vint8m8_t value) {
  // CHECK-LABEL: test_vse8_v_i8m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vse8_v_i8m8_m(mask, base, value);
}

void test_vse8_v_u8mf8_m (vbool64_t mask, uint8_t *base, vuint8mf8_t value) {
  // CHECK-LABEL: test_vse8_v_u8mf8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vse8_v_u8mf8_m(mask, base, value);
}

void test_vse8_v_u8mf4_m (vbool32_t mask, uint8_t *base, vuint8mf4_t value) {
  // CHECK-LABEL: test_vse8_v_u8mf4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vse8_v_u8mf4_m(mask, base, value);
}

void test_vse8_v_u8mf2_m (vbool16_t mask, uint8_t *base, vuint8mf2_t value) {
  // CHECK-LABEL: test_vse8_v_u8mf2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vse8_v_u8mf2_m(mask, base, value);
}

void test_vse8_v_u8m1_m (vbool8_t mask, uint8_t *base, vuint8m1_t value) {
  // CHECK-LABEL: test_vse8_v_u8m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vse8_v_u8m1_m(mask, base, value);
}

void test_vse8_v_u8m2_m (vbool4_t mask, uint8_t *base, vuint8m2_t value) {
  // CHECK-LABEL: test_vse8_v_u8m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vse8_v_u8m2_m(mask, base, value);
}

void test_vse8_v_u8m4_m (vbool2_t mask, uint8_t *base, vuint8m4_t value) {
  // CHECK-LABEL: test_vse8_v_u8m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vse8_v_u8m4_m(mask, base, value);
}

void test_vse8_v_u8m8_m (vbool1_t mask, uint8_t *base, vuint8m8_t value) {
  // CHECK-LABEL: test_vse8_v_u8m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, i8* %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vse8_v_u8m8_m(mask, base, value);
}


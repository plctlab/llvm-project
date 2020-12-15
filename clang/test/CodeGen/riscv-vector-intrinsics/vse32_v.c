// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vse32_v_i32mf2 (int32_t *base, vint32mf2_t value) {
  // CHECK-LABEL: test_vse32_v_i32mf2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i32{{.*}}(i32* %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vse32_v_i32mf2(base, value);
}

void test_vse32_v_i32m1 (int32_t *base, vint32m1_t value) {
  // CHECK-LABEL: test_vse32_v_i32m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i32{{.*}}(i32* %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vse32_v_i32m1(base, value);
}

void test_vse32_v_i32m2 (int32_t *base, vint32m2_t value) {
  // CHECK-LABEL: test_vse32_v_i32m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i32{{.*}}(i32* %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vse32_v_i32m2(base, value);
}

void test_vse32_v_i32m4 (int32_t *base, vint32m4_t value) {
  // CHECK-LABEL: test_vse32_v_i32m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i32{{.*}}(i32* %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vse32_v_i32m4(base, value);
}

void test_vse32_v_i32m8 (int32_t *base, vint32m8_t value) {
  // CHECK-LABEL: test_vse32_v_i32m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i32{{.*}}(i32* %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vse32_v_i32m8(base, value);
}

void test_vse32_v_u32mf2 (uint32_t *base, vuint32mf2_t value) {
  // CHECK-LABEL: test_vse32_v_u32mf2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i32{{.*}}(i32* %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vse32_v_u32mf2(base, value);
}

void test_vse32_v_u32m1 (uint32_t *base, vuint32m1_t value) {
  // CHECK-LABEL: test_vse32_v_u32m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i32{{.*}}(i32* %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vse32_v_u32m1(base, value);
}

void test_vse32_v_u32m2 (uint32_t *base, vuint32m2_t value) {
  // CHECK-LABEL: test_vse32_v_u32m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i32{{.*}}(i32* %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vse32_v_u32m2(base, value);
}

void test_vse32_v_u32m4 (uint32_t *base, vuint32m4_t value) {
  // CHECK-LABEL: test_vse32_v_u32m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i32{{.*}}(i32* %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vse32_v_u32m4(base, value);
}

void test_vse32_v_u32m8 (uint32_t *base, vuint32m8_t value) {
  // CHECK-LABEL: test_vse32_v_u32m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i32{{.*}}(i32* %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vse32_v_u32m8(base, value);
}

void test_vse32_v_f32mf2 (float32_t *base, vfloat32mf2_t value) {
  // CHECK-LABEL: test_vse32_v_f32mf2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1f32{{.*}}(float* %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vse32_v_f32mf2(base, value);
}

void test_vse32_v_f32m1 (float32_t *base, vfloat32m1_t value) {
  // CHECK-LABEL: test_vse32_v_f32m1
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2f32{{.*}}(float* %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vse32_v_f32m1(base, value);
}

void test_vse32_v_f32m2 (float32_t *base, vfloat32m2_t value) {
  // CHECK-LABEL: test_vse32_v_f32m2
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4f32{{.*}}(float* %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vse32_v_f32m2(base, value);
}

void test_vse32_v_f32m4 (float32_t *base, vfloat32m4_t value) {
  // CHECK-LABEL: test_vse32_v_f32m4
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8f32{{.*}}(float* %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vse32_v_f32m4(base, value);
}

void test_vse32_v_f32m8 (float32_t *base, vfloat32m8_t value) {
  // CHECK-LABEL: test_vse32_v_f32m8
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16f32{{.*}}(float* %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vse32_v_f32m8(base, value);
}

void test_vse32_v_i32mf2_m (vbool64_t mask, int32_t *base, vint32mf2_t value) {
  // CHECK-LABEL: test_vse32_v_i32mf2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vse32_v_i32mf2_m(mask, base, value);
}

void test_vse32_v_i32m1_m (vbool32_t mask, int32_t *base, vint32m1_t value) {
  // CHECK-LABEL: test_vse32_v_i32m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vse32_v_i32m1_m(mask, base, value);
}

void test_vse32_v_i32m2_m (vbool16_t mask, int32_t *base, vint32m2_t value) {
  // CHECK-LABEL: test_vse32_v_i32m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vse32_v_i32m2_m(mask, base, value);
}

void test_vse32_v_i32m4_m (vbool8_t mask, int32_t *base, vint32m4_t value) {
  // CHECK-LABEL: test_vse32_v_i32m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vse32_v_i32m4_m(mask, base, value);
}

void test_vse32_v_i32m8_m (vbool4_t mask, int32_t *base, vint32m8_t value) {
  // CHECK-LABEL: test_vse32_v_i32m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vse32_v_i32m8_m(mask, base, value);
}

void test_vse32_v_u32mf2_m (vbool64_t mask, uint32_t *base, vuint32mf2_t value) {
  // CHECK-LABEL: test_vse32_v_u32mf2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vse32_v_u32mf2_m(mask, base, value);
}

void test_vse32_v_u32m1_m (vbool32_t mask, uint32_t *base, vuint32m1_t value) {
  // CHECK-LABEL: test_vse32_v_u32m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vse32_v_u32m1_m(mask, base, value);
}

void test_vse32_v_u32m2_m (vbool16_t mask, uint32_t *base, vuint32m2_t value) {
  // CHECK-LABEL: test_vse32_v_u32m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vse32_v_u32m2_m(mask, base, value);
}

void test_vse32_v_u32m4_m (vbool8_t mask, uint32_t *base, vuint32m4_t value) {
  // CHECK-LABEL: test_vse32_v_u32m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vse32_v_u32m4_m(mask, base, value);
}

void test_vse32_v_u32m8_m (vbool4_t mask, uint32_t *base, vuint32m8_t value) {
  // CHECK-LABEL: test_vse32_v_u32m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, i32* %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vse32_v_u32m8_m(mask, base, value);
}

void test_vse32_v_f32mf2_m (vbool64_t mask, float32_t *base, vfloat32mf2_t value) {
  // CHECK-LABEL: test_vse32_v_f32mf2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, float* %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vse32_v_f32mf2_m(mask, base, value);
}

void test_vse32_v_f32m1_m (vbool32_t mask, float32_t *base, vfloat32m1_t value) {
  // CHECK-LABEL: test_vse32_v_f32m1_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, float* %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vse32_v_f32m1_m(mask, base, value);
}

void test_vse32_v_f32m2_m (vbool16_t mask, float32_t *base, vfloat32m2_t value) {
  // CHECK-LABEL: test_vse32_v_f32m2_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, float* %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vse32_v_f32m2_m(mask, base, value);
}

void test_vse32_v_f32m4_m (vbool8_t mask, float32_t *base, vfloat32m4_t value) {
  // CHECK-LABEL: test_vse32_v_f32m4_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, float* %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vse32_v_f32m4_m(mask, base, value);
}

void test_vse32_v_f32m8_m (vbool4_t mask, float32_t *base, vfloat32m8_t value) {
  // CHECK-LABEL: test_vse32_v_f32m8_m
  // CHECK:call void @llvm.riscv.vstore{{.*}}p0{{.*}}.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, float* %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vse32_v_f32m8_m(mask, base, value);
}


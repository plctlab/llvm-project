// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

float16_t test_vfmv_f_s_f16mf4_f16 (vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16mf4_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.{{.*}}nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}})
  return vfmv_f_s_f16mf4_f16(src);
}

float16_t test_vfmv_f_s_f16mf2_f16 (vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16mf2_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.{{.*}}nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}})
  return vfmv_f_s_f16mf2_f16(src);
}

float16_t test_vfmv_f_s_f16m1_f16 (vfloat16m1_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16m1_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.{{.*}}nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}})
  return vfmv_f_s_f16m1_f16(src);
}

float16_t test_vfmv_f_s_f16m2_f16 (vfloat16m2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16m2_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.{{.*}}nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}})
  return vfmv_f_s_f16m2_f16(src);
}

float16_t test_vfmv_f_s_f16m4_f16 (vfloat16m4_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16m4_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.{{.*}}nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}})
  return vfmv_f_s_f16m4_f16(src);
}

float16_t test_vfmv_f_s_f16m8_f16 (vfloat16m8_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16m8_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.{{.*}}nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}})
  return vfmv_f_s_f16m8_f16(src);
}

float32_t test_vfmv_f_s_f32mf2_f32 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32mf2_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.{{.*}}nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}})
  return vfmv_f_s_f32mf2_f32(src);
}

float32_t test_vfmv_f_s_f32m1_f32 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32m1_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.{{.*}}nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}})
  return vfmv_f_s_f32m1_f32(src);
}

float32_t test_vfmv_f_s_f32m2_f32 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32m2_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.{{.*}}nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}})
  return vfmv_f_s_f32m2_f32(src);
}

float32_t test_vfmv_f_s_f32m4_f32 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32m4_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.{{.*}}nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}})
  return vfmv_f_s_f32m4_f32(src);
}

float32_t test_vfmv_f_s_f32m8_f32 (vfloat32m8_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32m8_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.{{.*}}nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}})
  return vfmv_f_s_f32m8_f32(src);
}

float64_t test_vfmv_f_s_f64m1_f64 (vfloat64m1_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f64m1_f64
  // CHECK: %{{.*}} = call double @llvm.riscv.vfmv.f.s.{{.*}}nxv1f64{{.*}}(<vscale x 1 x double> %{{.*}})
  return vfmv_f_s_f64m1_f64(src);
}

float64_t test_vfmv_f_s_f64m2_f64 (vfloat64m2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f64m2_f64
  // CHECK: %{{.*}} = call double @llvm.riscv.vfmv.f.s.{{.*}}nxv2f64{{.*}}(<vscale x 2 x double> %{{.*}})
  return vfmv_f_s_f64m2_f64(src);
}

float64_t test_vfmv_f_s_f64m4_f64 (vfloat64m4_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f64m4_f64
  // CHECK: %{{.*}} = call double @llvm.riscv.vfmv.f.s.{{.*}}nxv4f64{{.*}}(<vscale x 4 x double> %{{.*}})
  return vfmv_f_s_f64m4_f64(src);
}

float64_t test_vfmv_f_s_f64m8_f64 (vfloat64m8_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f64m8_f64
  // CHECK: %{{.*}} = call double @llvm.riscv.vfmv.f.s.{{.*}}nxv8f64{{.*}}(<vscale x 8 x double> %{{.*}})
  return vfmv_f_s_f64m8_f64(src);
}


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfmv_v_f_f16mf4 (float16_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmv.v.f.nxv1f16{{.*}}(half %{{.*}})
  return vfmv_v_f_f16mf4(src);
}

vfloat16mf2_t test_vfmv_v_f_f16mf2 (float16_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmv.v.f.nxv2f16{{.*}}(half %{{.*}})
  return vfmv_v_f_f16mf2(src);
}

vfloat16m1_t test_vfmv_v_f_f16m1 (float16_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmv.v.f.nxv4f16{{.*}}(half %{{.*}})
  return vfmv_v_f_f16m1(src);
}

vfloat16m2_t test_vfmv_v_f_f16m2 (float16_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmv.v.f.nxv8f16{{.*}}(half %{{.*}})
  return vfmv_v_f_f16m2(src);
}

vfloat16m4_t test_vfmv_v_f_f16m4 (float16_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmv.v.f.nxv16f16{{.*}}(half %{{.*}})
  return vfmv_v_f_f16m4(src);
}

vfloat16m8_t test_vfmv_v_f_f16m8 (float16_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmv.v.f.nxv32f16{{.*}}(half %{{.*}})
  return vfmv_v_f_f16m8(src);
}

vfloat32mf2_t test_vfmv_v_f_f32mf2 (float32_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmv.v.f.nxv1f32{{.*}}(float %{{.*}})
  return vfmv_v_f_f32mf2(src);
}

vfloat32m1_t test_vfmv_v_f_f32m1 (float32_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmv.v.f.nxv2f32{{.*}}(float %{{.*}})
  return vfmv_v_f_f32m1(src);
}

vfloat32m2_t test_vfmv_v_f_f32m2 (float32_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmv.v.f.nxv4f32{{.*}}(float %{{.*}})
  return vfmv_v_f_f32m2(src);
}

vfloat32m4_t test_vfmv_v_f_f32m4 (float32_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmv.v.f.nxv8f32{{.*}}(float %{{.*}})
  return vfmv_v_f_f32m4(src);
}

vfloat32m8_t test_vfmv_v_f_f32m8 (float32_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmv.v.f.nxv16f32{{.*}}(float %{{.*}})
  return vfmv_v_f_f32m8(src);
}

vfloat64m1_t test_vfmv_v_f_f64m1 (float64_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfmv.v.f.nxv1f32{{.*}}(double %{{.*}})
  return vfmv_v_f_f64m1(src);
}

vfloat64m2_t test_vfmv_v_f_f64m2 (float64_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfmv.v.f.nxv2f32{{.*}}(double %{{.*}})
  return vfmv_v_f_f64m2(src);
}

vfloat64m4_t test_vfmv_v_f_f64m4 (float64_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfmv.v.f.nxv4f32{{.*}}(double %{{.*}})
  return vfmv_v_f_f64m4(src);
}

vfloat64m8_t test_vfmv_v_f_f64m8 (float64_t src) {
  // CHECK-LABEL: test_vfmv_v_f_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfmv.v.f.nxv8f32{{.*}}(double %{{.*}})
  return vfmv_v_f_f64m8(src);
}

float16_t test_vfmv_f_s_f16mf4_f16 (vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16mf4_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}})
  return vfmv_f_s_f16mf4_f16(src);
}

vfloat16mf4_t test_vfmv_s_f_f16mf4 (vfloat16mf4_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmv.s.f.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16mf4(dst, src);
}

float16_t test_vfmv_f_s_f16mf2_f16 (vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16mf2_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}})
  return vfmv_f_s_f16mf2_f16(src);
}

vfloat16mf2_t test_vfmv_s_f_f16mf2 (vfloat16mf2_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmv.s.f.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16mf2(dst, src);
}

float16_t test_vfmv_f_s_f16m1_f16 (vfloat16m1_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16m1_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}})
  return vfmv_f_s_f16m1_f16(src);
}

vfloat16m1_t test_vfmv_s_f_f16m1 (vfloat16m1_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmv.s.f.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16m1(dst, src);
}

float16_t test_vfmv_f_s_f16m2_f16 (vfloat16m2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16m2_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}})
  return vfmv_f_s_f16m2_f16(src);
}

vfloat16m2_t test_vfmv_s_f_f16m2 (vfloat16m2_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmv.s.f.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16m2(dst, src);
}

float16_t test_vfmv_f_s_f16m4_f16 (vfloat16m4_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16m4_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}})
  return vfmv_f_s_f16m4_f16(src);
}

vfloat16m4_t test_vfmv_s_f_f16m4 (vfloat16m4_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmv.s.f.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16m4(dst, src);
}

float16_t test_vfmv_f_s_f16m8_f16 (vfloat16m8_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f16m8_f16
  // CHECK: %{{.*}} = call half @llvm.riscv.vfmv.f.s.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}})
  return vfmv_f_s_f16m8_f16(src);
}

vfloat16m8_t test_vfmv_s_f_f16m8 (vfloat16m8_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmv.s.f.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16m8(dst, src);
}

float32_t test_vfmv_f_s_f32mf2_f32 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32mf2_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}})
  return vfmv_f_s_f32mf2_f32(src);
}

vfloat32mf2_t test_vfmv_s_f_f32mf2 (vfloat32mf2_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmv.s.f.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32mf2(dst, src);
}

float32_t test_vfmv_f_s_f32m1_f32 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32m1_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}})
  return vfmv_f_s_f32m1_f32(src);
}

vfloat32m1_t test_vfmv_s_f_f32m1 (vfloat32m1_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmv.s.f.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32m1(dst, src);
}

float32_t test_vfmv_f_s_f32m2_f32 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32m2_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}})
  return vfmv_f_s_f32m2_f32(src);
}

vfloat32m2_t test_vfmv_s_f_f32m2 (vfloat32m2_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmv.s.f.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32m2(dst, src);
}

float32_t test_vfmv_f_s_f32m4_f32 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32m4_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}})
  return vfmv_f_s_f32m4_f32(src);
}

vfloat32m4_t test_vfmv_s_f_f32m4 (vfloat32m4_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmv.s.f.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32m4(dst, src);
}

float32_t test_vfmv_f_s_f32m8_f32 (vfloat32m8_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f32m8_f32
  // CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}})
  return vfmv_f_s_f32m8_f32(src);
}

vfloat32m8_t test_vfmv_s_f_f32m8 (vfloat32m8_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmv.s.f.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32m8(dst, src);
}

float64_t test_vfmv_f_s_f64m1_f64 (vfloat64m1_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f64m1_f64
  // CHECK: %{{.*}} = call double @llvm.riscv.vfmv.f.s.nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}})
  return vfmv_f_s_f64m1_f64(src);
}

vfloat64m1_t test_vfmv_s_f_f64m1 (vfloat64m1_t dst, float64_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfmv.s.f.nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}}, double %{{.*}})
  return vfmv_s_f_f64m1(dst, src);
}

float64_t test_vfmv_f_s_f64m2_f64 (vfloat64m2_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f64m2_f64
  // CHECK: %{{.*}} = call double @llvm.riscv.vfmv.f.s.nxv2f32{{.*}}(<vscale x 2 x double> %{{.*}})
  return vfmv_f_s_f64m2_f64(src);
}

vfloat64m2_t test_vfmv_s_f_f64m2 (vfloat64m2_t dst, float64_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfmv.s.f.nxv2f32{{.*}}(<vscale x 2 x double> %{{.*}}, double %{{.*}})
  return vfmv_s_f_f64m2(dst, src);
}

float64_t test_vfmv_f_s_f64m4_f64 (vfloat64m4_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f64m4_f64
  // CHECK: %{{.*}} = call double @llvm.riscv.vfmv.f.s.nxv4f32{{.*}}(<vscale x 4 x double> %{{.*}})
  return vfmv_f_s_f64m4_f64(src);
}

vfloat64m4_t test_vfmv_s_f_f64m4 (vfloat64m4_t dst, float64_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfmv.s.f.nxv4f32{{.*}}(<vscale x 4 x double> %{{.*}}, double %{{.*}})
  return vfmv_s_f_f64m4(dst, src);
}

float64_t test_vfmv_f_s_f64m8_f64 (vfloat64m8_t src) {
  // CHECK-LABEL: test_vfmv_f_s_f64m8_f64
  // CHECK: %{{.*}} = call double @llvm.riscv.vfmv.f.s.nxv8f32{{.*}}(<vscale x 8 x double> %{{.*}})
  return vfmv_f_s_f64m8_f64(src);
}

vfloat64m8_t test_vfmv_s_f_f64m8 (vfloat64m8_t dst, float64_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfmv.s.f.nxv8f32{{.*}}(<vscale x 8 x double> %{{.*}}, double %{{.*}})
  return vfmv_s_f_f64m8(dst, src);
}


// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfmv_s_f_f16mf4 (vfloat16mf4_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfmv.s.f.{{.*}}nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16mf4(dst, src);
}

vfloat16mf2_t test_vfmv_s_f_f16mf2 (vfloat16mf2_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfmv.s.f.{{.*}}nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16mf2(dst, src);
}

vfloat16m1_t test_vfmv_s_f_f16m1 (vfloat16m1_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfmv.s.f.{{.*}}nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16m1(dst, src);
}

vfloat16m2_t test_vfmv_s_f_f16m2 (vfloat16m2_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfmv.s.f.{{.*}}nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16m2(dst, src);
}

vfloat16m4_t test_vfmv_s_f_f16m4 (vfloat16m4_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfmv.s.f.{{.*}}nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16m4(dst, src);
}

vfloat16m8_t test_vfmv_s_f_f16m8 (vfloat16m8_t dst, float16_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfmv.s.f.{{.*}}nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfmv_s_f_f16m8(dst, src);
}

vfloat32mf2_t test_vfmv_s_f_f32mf2 (vfloat32mf2_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfmv.s.f.{{.*}}nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32mf2(dst, src);
}

vfloat32m1_t test_vfmv_s_f_f32m1 (vfloat32m1_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmv.s.f.{{.*}}nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32m1(dst, src);
}

vfloat32m2_t test_vfmv_s_f_f32m2 (vfloat32m2_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfmv.s.f.{{.*}}nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32m2(dst, src);
}

vfloat32m4_t test_vfmv_s_f_f32m4 (vfloat32m4_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfmv.s.f.{{.*}}nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32m4(dst, src);
}

vfloat32m8_t test_vfmv_s_f_f32m8 (vfloat32m8_t dst, float32_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfmv.s.f.{{.*}}nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfmv_s_f_f32m8(dst, src);
}

vfloat64m1_t test_vfmv_s_f_f64m1 (vfloat64m1_t dst, float64_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfmv.s.f.{{.*}}nxv1f64{{.*}}(<vscale x 1 x double> %{{.*}}, double %{{.*}})
  return vfmv_s_f_f64m1(dst, src);
}

vfloat64m2_t test_vfmv_s_f_f64m2 (vfloat64m2_t dst, float64_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfmv.s.f.{{.*}}nxv2f64{{.*}}(<vscale x 2 x double> %{{.*}}, double %{{.*}})
  return vfmv_s_f_f64m2(dst, src);
}

vfloat64m4_t test_vfmv_s_f_f64m4 (vfloat64m4_t dst, float64_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfmv.s.f.{{.*}}nxv4f64{{.*}}(<vscale x 4 x double> %{{.*}}, double %{{.*}})
  return vfmv_s_f_f64m4(dst, src);
}

vfloat64m8_t test_vfmv_s_f_f64m8 (vfloat64m8_t dst, float64_t src) {
  // CHECK-LABEL: test_vfmv_s_f_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfmv.s.f.{{.*}}nxv8f64{{.*}}(<vscale x 8 x double> %{{.*}}, double %{{.*}})
  return vfmv_s_f_f64m8(dst, src);
}


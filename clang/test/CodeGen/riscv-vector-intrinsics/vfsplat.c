// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfsplat_s_f16mf4 (float16_t src) {
  // CHECK-LABEL: test_vfsplat_s_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfsplat.s.nxv1f16{{.*}}(half %{{.*}})
  return vfsplat_s_f16mf4(src);
}

vfloat16mf2_t test_vfsplat_s_f16mf2 (float16_t src) {
  // CHECK-LABEL: test_vfsplat_s_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfsplat.s.nxv2f16{{.*}}(half %{{.*}})
  return vfsplat_s_f16mf2(src);
}

vfloat16m1_t test_vfsplat_s_f16m1 (float16_t src) {
  // CHECK-LABEL: test_vfsplat_s_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfsplat.s.nxv4f16{{.*}}(half %{{.*}})
  return vfsplat_s_f16m1(src);
}

vfloat16m2_t test_vfsplat_s_f16m2 (float16_t src) {
  // CHECK-LABEL: test_vfsplat_s_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfsplat.s.nxv8f16{{.*}}(half %{{.*}})
  return vfsplat_s_f16m2(src);
}

vfloat16m4_t test_vfsplat_s_f16m4 (float16_t src) {
  // CHECK-LABEL: test_vfsplat_s_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfsplat.s.nxv16f16{{.*}}(half %{{.*}})
  return vfsplat_s_f16m4(src);
}

vfloat16m8_t test_vfsplat_s_f16m8 (float16_t src) {
  // CHECK-LABEL: test_vfsplat_s_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfsplat.s.nxv32f16{{.*}}(half %{{.*}})
  return vfsplat_s_f16m8(src);
}

vfloat32mf2_t test_vfsplat_s_f32mf2 (float32_t src) {
  // CHECK-LABEL: test_vfsplat_s_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfsplat.s.nxv1f32{{.*}}(float %{{.*}})
  return vfsplat_s_f32mf2(src);
}

vfloat32m1_t test_vfsplat_s_f32m1 (float32_t src) {
  // CHECK-LABEL: test_vfsplat_s_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsplat.s.nxv2f32{{.*}}(float %{{.*}})
  return vfsplat_s_f32m1(src);
}

vfloat32m2_t test_vfsplat_s_f32m2 (float32_t src) {
  // CHECK-LABEL: test_vfsplat_s_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfsplat.s.nxv4f32{{.*}}(float %{{.*}})
  return vfsplat_s_f32m2(src);
}

vfloat32m4_t test_vfsplat_s_f32m4 (float32_t src) {
  // CHECK-LABEL: test_vfsplat_s_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfsplat.s.nxv8f32{{.*}}(float %{{.*}})
  return vfsplat_s_f32m4(src);
}

vfloat32m8_t test_vfsplat_s_f32m8 (float32_t src) {
  // CHECK-LABEL: test_vfsplat_s_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfsplat.s.nxv16f32{{.*}}(float %{{.*}})
  return vfsplat_s_f32m8(src);
}

vfloat64m1_t test_vfsplat_s_f64m1 (float64_t src) {
  // CHECK-LABEL: test_vfsplat_s_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfsplat.s.nxv1f32{{.*}}(double %{{.*}})
  return vfsplat_s_f64m1(src);
}

vfloat64m2_t test_vfsplat_s_f64m2 (float64_t src) {
  // CHECK-LABEL: test_vfsplat_s_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfsplat.s.nxv2f32{{.*}}(double %{{.*}})
  return vfsplat_s_f64m2(src);
}

vfloat64m4_t test_vfsplat_s_f64m4 (float64_t src) {
  // CHECK-LABEL: test_vfsplat_s_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfsplat.s.nxv4f32{{.*}}(double %{{.*}})
  return vfsplat_s_f64m4(src);
}

vfloat64m8_t test_vfsplat_s_f64m8 (float64_t src) {
  // CHECK-LABEL: test_vfsplat_s_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfsplat.s.nxv8f32{{.*}}(double %{{.*}})
  return vfsplat_s_f64m8(src);
}


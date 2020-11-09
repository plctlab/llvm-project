// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfslide1down_vf_f16mf4 (vfloat16mf4_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfslide1down.vf.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16mf4(src, value);
}

vfloat16mf2_t test_vfslide1down_vf_f16mf2 (vfloat16mf2_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfslide1down.vf.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16mf2(src, value);
}

vfloat16m1_t test_vfslide1down_vf_f16m1 (vfloat16m1_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfslide1down.vf.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16m1(src, value);
}

vfloat16m2_t test_vfslide1down_vf_f16m2 (vfloat16m2_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfslide1down.vf.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16m2(src, value);
}

vfloat16m4_t test_vfslide1down_vf_f16m4 (vfloat16m4_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfslide1down.vf.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16m4(src, value);
}

vfloat16m8_t test_vfslide1down_vf_f16m8 (vfloat16m8_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfslide1down.vf.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16m8(src, value);
}

vfloat32mf2_t test_vfslide1down_vf_f32mf2 (vfloat32mf2_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfslide1down.vf.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32mf2(src, value);
}

vfloat32m1_t test_vfslide1down_vf_f32m1 (vfloat32m1_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfslide1down.vf.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32m1(src, value);
}

vfloat32m2_t test_vfslide1down_vf_f32m2 (vfloat32m2_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfslide1down.vf.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32m2(src, value);
}

vfloat32m4_t test_vfslide1down_vf_f32m4 (vfloat32m4_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfslide1down.vf.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32m4(src, value);
}

vfloat32m8_t test_vfslide1down_vf_f32m8 (vfloat32m8_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfslide1down.vf.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32m8(src, value);
}

vfloat64m1_t test_vfslide1down_vf_f64m1 (vfloat64m1_t src, float64_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfslide1down.vf.nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}}, double %{{.*}})
  return vfslide1down_vf_f64m1(src, value);
}

vfloat64m2_t test_vfslide1down_vf_f64m2 (vfloat64m2_t src, float64_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfslide1down.vf.nxv2f32{{.*}}(<vscale x 2 x double> %{{.*}}, double %{{.*}})
  return vfslide1down_vf_f64m2(src, value);
}

vfloat64m4_t test_vfslide1down_vf_f64m4 (vfloat64m4_t src, float64_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfslide1down.vf.nxv4f32{{.*}}(<vscale x 4 x double> %{{.*}}, double %{{.*}})
  return vfslide1down_vf_f64m4(src, value);
}

vfloat64m8_t test_vfslide1down_vf_f64m8 (vfloat64m8_t src, float64_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfslide1down.vf.nxv8f32{{.*}}(<vscale x 8 x double> %{{.*}}, double %{{.*}})
  return vfslide1down_vf_f64m8(src, value);
}

vfloat16mf4_t test_vfslide1down_vf_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfslide1down.vf.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16mf4_m(mask, maskedoff, src, value);
}

vfloat16mf2_t test_vfslide1down_vf_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfslide1down.vf.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16mf2_m(mask, maskedoff, src, value);
}

vfloat16m1_t test_vfslide1down_vf_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfslide1down.vf.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16m1_m(mask, maskedoff, src, value);
}

vfloat16m2_t test_vfslide1down_vf_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfslide1down.vf.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16m2_m(mask, maskedoff, src, value);
}

vfloat16m4_t test_vfslide1down_vf_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfslide1down.vf.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16m4_m(mask, maskedoff, src, value);
}

vfloat16m8_t test_vfslide1down_vf_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t src, float16_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfslide1down.vf.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}})
  return vfslide1down_vf_f16m8_m(mask, maskedoff, src, value);
}

vfloat32mf2_t test_vfslide1down_vf_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfslide1down.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32mf2_m(mask, maskedoff, src, value);
}

vfloat32m1_t test_vfslide1down_vf_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfslide1down.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32m1_m(mask, maskedoff, src, value);
}

vfloat32m2_t test_vfslide1down_vf_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfslide1down.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32m2_m(mask, maskedoff, src, value);
}

vfloat32m4_t test_vfslide1down_vf_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfslide1down.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32m4_m(mask, maskedoff, src, value);
}

vfloat32m8_t test_vfslide1down_vf_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t src, float32_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfslide1down.vf.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}})
  return vfslide1down_vf_f32m8_m(mask, maskedoff, src, value);
}

vfloat64m1_t test_vfslide1down_vf_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, vfloat64m1_t src, float64_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfslide1down.vf.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, double %{{.*}})
  return vfslide1down_vf_f64m1_m(mask, maskedoff, src, value);
}

vfloat64m2_t test_vfslide1down_vf_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, vfloat64m2_t src, float64_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfslide1down.vf.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, double %{{.*}})
  return vfslide1down_vf_f64m2_m(mask, maskedoff, src, value);
}

vfloat64m4_t test_vfslide1down_vf_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, vfloat64m4_t src, float64_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfslide1down.vf.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}}, double %{{.*}})
  return vfslide1down_vf_f64m4_m(mask, maskedoff, src, value);
}

vfloat64m8_t test_vfslide1down_vf_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, vfloat64m8_t src, float64_t value) {
  // CHECK-LABEL: test_vfslide1down_vf_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfslide1down.vf.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}})
  return vfslide1down_vf_f64m8_m(mask, maskedoff, src, value);
}


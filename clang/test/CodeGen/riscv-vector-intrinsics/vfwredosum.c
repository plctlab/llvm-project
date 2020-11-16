// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat32m1_t test_vfwredosum_vs_f16mf4_f32m1 (vfloat32m1_t dst, vfloat16mf4_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16mf4_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.{{.*}}nxv1f16{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16mf4_f32m1(dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16mf2_f32m1 (vfloat32m1_t dst, vfloat16mf2_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16mf2_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.{{.*}}nxv2f16{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16mf2_f32m1(dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16m1_f32m1 (vfloat32m1_t dst, vfloat16m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16m1_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.{{.*}}nxv4f16{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16m1_f32m1(dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16m2_f32m1 (vfloat32m1_t dst, vfloat16m2_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16m2_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.{{.*}}nxv8f16{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16m2_f32m1(dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16m4_f32m1 (vfloat32m1_t dst, vfloat16m4_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16m4_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.{{.*}}nxv16f16{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16m4_f32m1(dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16m8_f32m1 (vfloat32m1_t dst, vfloat16m8_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16m8_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.{{.*}}nxv32f16{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16m8_f32m1(dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32mf2_f64m1 (vfloat64m1_t dst, vfloat32mf2_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32mf2_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.{{.*}}nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32mf2_f64m1(dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32m1_f64m1 (vfloat64m1_t dst, vfloat32m1_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32m1_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.{{.*}}nxv2f32{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32m1_f64m1(dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32m2_f64m1 (vfloat64m1_t dst, vfloat32m2_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32m2_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.{{.*}}nxv4f32{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32m2_f64m1(dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32m4_f64m1 (vfloat64m1_t dst, vfloat32m4_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32m4_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.{{.*}}nxv8f32{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32m4_f64m1(dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32m8_f64m1 (vfloat64m1_t dst, vfloat32m8_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32m8_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.{{.*}}nxv16f32{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32m8_f64m1(dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16mf4_f32m1_m (vbool64_t mask, vfloat32m1_t dst, vfloat16mf4_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16mf4_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16mf4_f32m1_m(mask, dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16mf2_f32m1_m (vbool32_t mask, vfloat32m1_t dst, vfloat16mf2_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16mf2_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16mf2_f32m1_m(mask, dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16m1_f32m1_m (vbool16_t mask, vfloat32m1_t dst, vfloat16m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16m1_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16m1_f32m1_m(mask, dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16m2_f32m1_m (vbool8_t mask, vfloat32m1_t dst, vfloat16m2_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16m2_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16m2_f32m1_m(mask, dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16m4_f32m1_m (vbool4_t mask, vfloat32m1_t dst, vfloat16m4_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16m4_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16m4_f32m1_m(mask, dst, vector, scalar);
}

vfloat32m1_t test_vfwredosum_vs_f16m8_f32m1_m (vbool2_t mask, vfloat32m1_t dst, vfloat16m8_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f16m8_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwredosum_vs_f16m8_f32m1_m(mask, dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32mf2_f64m1_m (vbool64_t mask, vfloat64m1_t dst, vfloat32mf2_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32mf2_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32mf2_f64m1_m(mask, dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32m1_f64m1_m (vbool32_t mask, vfloat64m1_t dst, vfloat32m1_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32m1_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32m1_f64m1_m(mask, dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32m2_f64m1_m (vbool16_t mask, vfloat64m1_t dst, vfloat32m2_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32m2_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32m2_f64m1_m(mask, dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32m4_f64m1_m (vbool8_t mask, vfloat64m1_t dst, vfloat32m4_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32m4_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32m4_f64m1_m(mask, dst, vector, scalar);
}

vfloat64m1_t test_vfwredosum_vs_f32m8_f64m1_m (vbool4_t mask, vfloat64m1_t dst, vfloat32m8_t vector, vfloat64m1_t scalar) {
  // CHECK-LABEL: test_vfwredosum_vs_f32m8_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfwredosum.vs.mask.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfwredosum_vs_f32m8_f64m1_m(mask, dst, vector, scalar);
}


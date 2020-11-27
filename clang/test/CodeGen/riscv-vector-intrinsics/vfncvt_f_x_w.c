// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vfncvt_f_x_w_f16mf4 (vint32mf2_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv1f16{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vfncvt_f_x_w_f16mf4(src);
}

vfloat16mf2_t test_vfncvt_f_x_w_f16mf2 (vint32m1_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv2f16{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vfncvt_f_x_w_f16mf2(src);
}

vfloat16m1_t test_vfncvt_f_x_w_f16m1 (vint32m2_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv4f16{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vfncvt_f_x_w_f16m1(src);
}

vfloat16m2_t test_vfncvt_f_x_w_f16m2 (vint32m4_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv8f16{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vfncvt_f_x_w_f16m2(src);
}

vfloat16m4_t test_vfncvt_f_x_w_f16m4 (vint32m8_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv16f16{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vfncvt_f_x_w_f16m4(src);
}

vfloat32mf2_t test_vfncvt_f_x_w_f32mf2 (vint64m1_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vfncvt_f_x_w_f32mf2(src);
}

vfloat32m1_t test_vfncvt_f_x_w_f32m1 (vint64m2_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vfncvt_f_x_w_f32m1(src);
}

vfloat32m2_t test_vfncvt_f_x_w_f32m2 (vint64m4_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vfncvt_f_x_w_f32m2(src);
}

vfloat32m4_t test_vfncvt_f_x_w_f32m4 (vint64m8_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vfncvt_f_x_w_f32m4(src);
}

vfloat16mf4_t test_vfncvt_f_x_w_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vint32mf2_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vfncvt_f_x_w_f16mf4_m(mask, maskedoff, src);
}

vfloat16mf2_t test_vfncvt_f_x_w_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vint32m1_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vfncvt_f_x_w_f16mf2_m(mask, maskedoff, src);
}

vfloat16m1_t test_vfncvt_f_x_w_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vint32m2_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vfncvt_f_x_w_f16m1_m(mask, maskedoff, src);
}

vfloat16m2_t test_vfncvt_f_x_w_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vint32m4_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vfncvt_f_x_w_f16m2_m(mask, maskedoff, src);
}

vfloat16m4_t test_vfncvt_f_x_w_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vint32m8_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vfncvt_f_x_w_f16m4_m(mask, maskedoff, src);
}

vfloat32mf2_t test_vfncvt_f_x_w_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vint64m1_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vfncvt_f_x_w_f32mf2_m(mask, maskedoff, src);
}

vfloat32m1_t test_vfncvt_f_x_w_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vint64m2_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vfncvt_f_x_w_f32m1_m(mask, maskedoff, src);
}

vfloat32m2_t test_vfncvt_f_x_w_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vint64m4_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vfncvt_f_x_w_f32m2_m(mask, maskedoff, src);
}

vfloat32m4_t test_vfncvt_f_x_w_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vint64m8_t src) {
  // CHECK-LABEL: test_vfncvt_f_x_w_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfncvt.f.x.w.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vfncvt_f_x_w_f32m4_m(mask, maskedoff, src);
}


// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2_t test_vfwcvt_x_f_v_i32mf2 (vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv1i32{{.*}}(<vscale x 1 x half> %{{.*}})
  return vfwcvt_x_f_v_i32mf2(src);
}

vint32m1_t test_vfwcvt_x_f_v_i32m1 (vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv2i32{{.*}}(<vscale x 2 x half> %{{.*}})
  return vfwcvt_x_f_v_i32m1(src);
}

vint32m2_t test_vfwcvt_x_f_v_i32m2 (vfloat16m1_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv4i32{{.*}}(<vscale x 4 x half> %{{.*}})
  return vfwcvt_x_f_v_i32m2(src);
}

vint32m4_t test_vfwcvt_x_f_v_i32m4 (vfloat16m2_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv8i32{{.*}}(<vscale x 8 x half> %{{.*}})
  return vfwcvt_x_f_v_i32m4(src);
}

vint32m8_t test_vfwcvt_x_f_v_i32m8 (vfloat16m4_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv16i32{{.*}}(<vscale x 16 x half> %{{.*}})
  return vfwcvt_x_f_v_i32m8(src);
}

vint64m1_t test_vfwcvt_x_f_v_i64m1 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv1i64{{.*}}(<vscale x 1 x float> %{{.*}})
  return vfwcvt_x_f_v_i64m1(src);
}

vint64m2_t test_vfwcvt_x_f_v_i64m2 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv2i64{{.*}}(<vscale x 2 x float> %{{.*}})
  return vfwcvt_x_f_v_i64m2(src);
}

vint64m4_t test_vfwcvt_x_f_v_i64m4 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv4i64{{.*}}(<vscale x 4 x float> %{{.*}})
  return vfwcvt_x_f_v_i64m4(src);
}

vint64m8_t test_vfwcvt_x_f_v_i64m8 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv8i64{{.*}}(<vscale x 8 x float> %{{.*}})
  return vfwcvt_x_f_v_i64m8(src);
}

vint32mf2_t test_vfwcvt_x_f_v_i32mf2_m (vbool64_t mask, vint32mf2_t maskedoff, vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfwcvt_x_f_v_i32mf2_m(mask, maskedoff, src);
}

vint32m1_t test_vfwcvt_x_f_v_i32m1_m (vbool32_t mask, vint32m1_t maskedoff, vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfwcvt_x_f_v_i32m1_m(mask, maskedoff, src);
}

vint32m2_t test_vfwcvt_x_f_v_i32m2_m (vbool16_t mask, vint32m2_t maskedoff, vfloat16m1_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfwcvt_x_f_v_i32m2_m(mask, maskedoff, src);
}

vint32m4_t test_vfwcvt_x_f_v_i32m4_m (vbool8_t mask, vint32m4_t maskedoff, vfloat16m2_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfwcvt_x_f_v_i32m4_m(mask, maskedoff, src);
}

vint32m8_t test_vfwcvt_x_f_v_i32m8_m (vbool4_t mask, vint32m8_t maskedoff, vfloat16m4_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfwcvt_x_f_v_i32m8_m(mask, maskedoff, src);
}

vint64m1_t test_vfwcvt_x_f_v_i64m1_m (vbool64_t mask, vint64m1_t maskedoff, vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfwcvt_x_f_v_i64m1_m(mask, maskedoff, src);
}

vint64m2_t test_vfwcvt_x_f_v_i64m2_m (vbool32_t mask, vint64m2_t maskedoff, vfloat32m1_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfwcvt_x_f_v_i64m2_m(mask, maskedoff, src);
}

vint64m4_t test_vfwcvt_x_f_v_i64m4_m (vbool16_t mask, vint64m4_t maskedoff, vfloat32m2_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfwcvt_x_f_v_i64m4_m(mask, maskedoff, src);
}

vint64m8_t test_vfwcvt_x_f_v_i64m8_m (vbool8_t mask, vint64m8_t maskedoff, vfloat32m4_t src) {
  // CHECK-LABEL: test_vfwcvt_x_f_v_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfwcvt.x.f.v.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfwcvt_x_f_v_i64m8_m(mask, maskedoff, src);
}


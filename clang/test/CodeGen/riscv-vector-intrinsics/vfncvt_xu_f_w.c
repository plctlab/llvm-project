// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint16mf4_t test_vfncvt_xu_f_w_u16mf4 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv1i16{{.*}}(<vscale x 1 x float> %{{.*}})
  return vfncvt_xu_f_w_u16mf4(src);
}

vuint16mf2_t test_vfncvt_xu_f_w_u16mf2 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv2i16{{.*}}(<vscale x 2 x float> %{{.*}})
  return vfncvt_xu_f_w_u16mf2(src);
}

vuint16m1_t test_vfncvt_xu_f_w_u16m1 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv4i16{{.*}}(<vscale x 4 x float> %{{.*}})
  return vfncvt_xu_f_w_u16m1(src);
}

vuint16m2_t test_vfncvt_xu_f_w_u16m2 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv8i16{{.*}}(<vscale x 8 x float> %{{.*}})
  return vfncvt_xu_f_w_u16m2(src);
}

vuint16m4_t test_vfncvt_xu_f_w_u16m4 (vfloat32m8_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv16i16{{.*}}(<vscale x 16 x float> %{{.*}})
  return vfncvt_xu_f_w_u16m4(src);
}

vuint32mf2_t test_vfncvt_xu_f_w_u32mf2 (vfloat64m1_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv1i32{{.*}}(<vscale x 1 x double> %{{.*}})
  return vfncvt_xu_f_w_u32mf2(src);
}

vuint32m1_t test_vfncvt_xu_f_w_u32m1 (vfloat64m2_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv2i32{{.*}}(<vscale x 2 x double> %{{.*}})
  return vfncvt_xu_f_w_u32m1(src);
}

vuint32m2_t test_vfncvt_xu_f_w_u32m2 (vfloat64m4_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv4i32{{.*}}(<vscale x 4 x double> %{{.*}})
  return vfncvt_xu_f_w_u32m2(src);
}

vuint32m4_t test_vfncvt_xu_f_w_u32m4 (vfloat64m8_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv8i32{{.*}}(<vscale x 8 x double> %{{.*}})
  return vfncvt_xu_f_w_u32m4(src);
}

vuint16mf4_t test_vfncvt_xu_f_w_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfncvt_xu_f_w_u16mf4_m(mask, maskedoff, src);
}

vuint16mf2_t test_vfncvt_xu_f_w_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, vfloat32m1_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfncvt_xu_f_w_u16mf2_m(mask, maskedoff, src);
}

vuint16m1_t test_vfncvt_xu_f_w_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, vfloat32m2_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfncvt_xu_f_w_u16m1_m(mask, maskedoff, src);
}

vuint16m2_t test_vfncvt_xu_f_w_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, vfloat32m4_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfncvt_xu_f_w_u16m2_m(mask, maskedoff, src);
}

vuint16m4_t test_vfncvt_xu_f_w_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, vfloat32m8_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfncvt_xu_f_w_u16m4_m(mask, maskedoff, src);
}

vuint32mf2_t test_vfncvt_xu_f_w_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, vfloat64m1_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfncvt_xu_f_w_u32mf2_m(mask, maskedoff, src);
}

vuint32m1_t test_vfncvt_xu_f_w_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, vfloat64m2_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vfncvt_xu_f_w_u32m1_m(mask, maskedoff, src);
}

vuint32m2_t test_vfncvt_xu_f_w_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, vfloat64m4_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vfncvt_xu_f_w_u32m2_m(mask, maskedoff, src);
}

vuint32m4_t test_vfncvt_xu_f_w_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, vfloat64m8_t src) {
  // CHECK-LABEL: test_vfncvt_xu_f_w_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfncvt.xu.f.w.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vfncvt_xu_f_w_u32m4_m(mask, maskedoff, src);
}


// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4_t test_vfcvt_x_f_v_i16mf4 (vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv1i16{{.*}}(<vscale x 1 x half> %{{.*}})
  return vfcvt_x_f_v_i16mf4(src);
}

vint16mf4_t test_vfcvt_rtz_x_f_v_i16mf4 (vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv1i16{{.*}}(<vscale x 1 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16mf4(src);
}

vint16mf2_t test_vfcvt_x_f_v_i16mf2 (vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv2i16{{.*}}(<vscale x 2 x half> %{{.*}})
  return vfcvt_x_f_v_i16mf2(src);
}

vint16mf2_t test_vfcvt_rtz_x_f_v_i16mf2 (vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv2i16{{.*}}(<vscale x 2 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16mf2(src);
}

vint16m1_t test_vfcvt_x_f_v_i16m1 (vfloat16m1_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv4i16{{.*}}(<vscale x 4 x half> %{{.*}})
  return vfcvt_x_f_v_i16m1(src);
}

vint16m1_t test_vfcvt_rtz_x_f_v_i16m1 (vfloat16m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv4i16{{.*}}(<vscale x 4 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16m1(src);
}

vint16m2_t test_vfcvt_x_f_v_i16m2 (vfloat16m2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv8i16{{.*}}(<vscale x 8 x half> %{{.*}})
  return vfcvt_x_f_v_i16m2(src);
}

vint16m2_t test_vfcvt_rtz_x_f_v_i16m2 (vfloat16m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv8i16{{.*}}(<vscale x 8 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16m2(src);
}

vint16m4_t test_vfcvt_x_f_v_i16m4 (vfloat16m4_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv16i16{{.*}}(<vscale x 16 x half> %{{.*}})
  return vfcvt_x_f_v_i16m4(src);
}

vint16m4_t test_vfcvt_rtz_x_f_v_i16m4 (vfloat16m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv16i16{{.*}}(<vscale x 16 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16m4(src);
}

vint16m8_t test_vfcvt_x_f_v_i16m8 (vfloat16m8_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv32i16{{.*}}(<vscale x 32 x half> %{{.*}})
  return vfcvt_x_f_v_i16m8(src);
}

vint16m8_t test_vfcvt_rtz_x_f_v_i16m8 (vfloat16m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv32i16{{.*}}(<vscale x 32 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16m8(src);
}

vuint16mf4_t test_vfcvt_xu_f_v_u16mf4 (vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv1i16{{.*}}(<vscale x 1 x half> %{{.*}})
  return vfcvt_xu_f_v_u16mf4(src);
}

vuint16mf4_t test_vfcvt_rtz_xu_f_v_u16mf4 (vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv1i16{{.*}}(<vscale x 1 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16mf4(src);
}

vuint16mf2_t test_vfcvt_xu_f_v_u16mf2 (vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv2i16{{.*}}(<vscale x 2 x half> %{{.*}})
  return vfcvt_xu_f_v_u16mf2(src);
}

vuint16mf2_t test_vfcvt_rtz_xu_f_v_u16mf2 (vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv2i16{{.*}}(<vscale x 2 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16mf2(src);
}

vuint16m1_t test_vfcvt_xu_f_v_u16m1 (vfloat16m1_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv4i16{{.*}}(<vscale x 4 x half> %{{.*}})
  return vfcvt_xu_f_v_u16m1(src);
}

vuint16m1_t test_vfcvt_rtz_xu_f_v_u16m1 (vfloat16m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv4i16{{.*}}(<vscale x 4 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16m1(src);
}

vuint16m2_t test_vfcvt_xu_f_v_u16m2 (vfloat16m2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv8i16{{.*}}(<vscale x 8 x half> %{{.*}})
  return vfcvt_xu_f_v_u16m2(src);
}

vuint16m2_t test_vfcvt_rtz_xu_f_v_u16m2 (vfloat16m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv8i16{{.*}}(<vscale x 8 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16m2(src);
}

vuint16m4_t test_vfcvt_xu_f_v_u16m4 (vfloat16m4_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv16i16{{.*}}(<vscale x 16 x half> %{{.*}})
  return vfcvt_xu_f_v_u16m4(src);
}

vuint16m4_t test_vfcvt_rtz_xu_f_v_u16m4 (vfloat16m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv16i16{{.*}}(<vscale x 16 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16m4(src);
}

vuint16m8_t test_vfcvt_xu_f_v_u16m8 (vfloat16m8_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv32i16{{.*}}(<vscale x 32 x half> %{{.*}})
  return vfcvt_xu_f_v_u16m8(src);
}

vuint16m8_t test_vfcvt_rtz_xu_f_v_u16m8 (vfloat16m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv32i16{{.*}}(<vscale x 32 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16m8(src);
}

vfloat16mf4_t test_vfcvt_f_x_v_f16mf4 (vint16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv1f16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vfcvt_f_x_v_f16mf4(src);
}

vfloat16mf2_t test_vfcvt_f_x_v_f16mf2 (vint16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv2f16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vfcvt_f_x_v_f16mf2(src);
}

vfloat16m1_t test_vfcvt_f_x_v_f16m1 (vint16m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv4f16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vfcvt_f_x_v_f16m1(src);
}

vfloat16m2_t test_vfcvt_f_x_v_f16m2 (vint16m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv8f16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vfcvt_f_x_v_f16m2(src);
}

vfloat16m4_t test_vfcvt_f_x_v_f16m4 (vint16m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv16f16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vfcvt_f_x_v_f16m4(src);
}

vfloat16m8_t test_vfcvt_f_x_v_f16m8 (vint16m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv32f16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vfcvt_f_x_v_f16m8(src);
}

vfloat16mf4_t test_vfcvt_f_xu_v_f16mf4 (vuint16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv1f16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16mf4(src);
}

vfloat16mf2_t test_vfcvt_f_xu_v_f16mf2 (vuint16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv2f16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16mf2(src);
}

vfloat16m1_t test_vfcvt_f_xu_v_f16m1 (vuint16m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv4f16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16m1(src);
}

vfloat16m2_t test_vfcvt_f_xu_v_f16m2 (vuint16m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv8f16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16m2(src);
}

vfloat16m4_t test_vfcvt_f_xu_v_f16m4 (vuint16m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv16f16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16m4(src);
}

vfloat16m8_t test_vfcvt_f_xu_v_f16m8 (vuint16m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv32f16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16m8(src);
}

vint32mf2_t test_vfcvt_x_f_v_i32mf2 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv1i32{{.*}}(<vscale x 1 x float> %{{.*}})
  return vfcvt_x_f_v_i32mf2(src);
}

vint32mf2_t test_vfcvt_rtz_x_f_v_i32mf2 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv1i32{{.*}}(<vscale x 1 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32mf2(src);
}

vint32m1_t test_vfcvt_x_f_v_i32m1 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv2i32{{.*}}(<vscale x 2 x float> %{{.*}})
  return vfcvt_x_f_v_i32m1(src);
}

vint32m1_t test_vfcvt_rtz_x_f_v_i32m1 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv2i32{{.*}}(<vscale x 2 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32m1(src);
}

vint32m2_t test_vfcvt_x_f_v_i32m2 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv4i32{{.*}}(<vscale x 4 x float> %{{.*}})
  return vfcvt_x_f_v_i32m2(src);
}

vint32m2_t test_vfcvt_rtz_x_f_v_i32m2 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv4i32{{.*}}(<vscale x 4 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32m2(src);
}

vint32m4_t test_vfcvt_x_f_v_i32m4 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv8i32{{.*}}(<vscale x 8 x float> %{{.*}})
  return vfcvt_x_f_v_i32m4(src);
}

vint32m4_t test_vfcvt_rtz_x_f_v_i32m4 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv8i32{{.*}}(<vscale x 8 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32m4(src);
}

vint32m8_t test_vfcvt_x_f_v_i32m8 (vfloat32m8_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv16i32{{.*}}(<vscale x 16 x float> %{{.*}})
  return vfcvt_x_f_v_i32m8(src);
}

vint32m8_t test_vfcvt_rtz_x_f_v_i32m8 (vfloat32m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv16i32{{.*}}(<vscale x 16 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32m8(src);
}

vuint32mf2_t test_vfcvt_xu_f_v_u32mf2 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv1i32{{.*}}(<vscale x 1 x float> %{{.*}})
  return vfcvt_xu_f_v_u32mf2(src);
}

vuint32mf2_t test_vfcvt_rtz_xu_f_v_u32mf2 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv1i32{{.*}}(<vscale x 1 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32mf2(src);
}

vuint32m1_t test_vfcvt_xu_f_v_u32m1 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv2i32{{.*}}(<vscale x 2 x float> %{{.*}})
  return vfcvt_xu_f_v_u32m1(src);
}

vuint32m1_t test_vfcvt_rtz_xu_f_v_u32m1 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv2i32{{.*}}(<vscale x 2 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32m1(src);
}

vuint32m2_t test_vfcvt_xu_f_v_u32m2 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv4i32{{.*}}(<vscale x 4 x float> %{{.*}})
  return vfcvt_xu_f_v_u32m2(src);
}

vuint32m2_t test_vfcvt_rtz_xu_f_v_u32m2 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv4i32{{.*}}(<vscale x 4 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32m2(src);
}

vuint32m4_t test_vfcvt_xu_f_v_u32m4 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv8i32{{.*}}(<vscale x 8 x float> %{{.*}})
  return vfcvt_xu_f_v_u32m4(src);
}

vuint32m4_t test_vfcvt_rtz_xu_f_v_u32m4 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv8i32{{.*}}(<vscale x 8 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32m4(src);
}

vuint32m8_t test_vfcvt_xu_f_v_u32m8 (vfloat32m8_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv16i32{{.*}}(<vscale x 16 x float> %{{.*}})
  return vfcvt_xu_f_v_u32m8(src);
}

vuint32m8_t test_vfcvt_rtz_xu_f_v_u32m8 (vfloat32m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv16i32{{.*}}(<vscale x 16 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32m8(src);
}

vfloat32mf2_t test_vfcvt_f_x_v_f32mf2 (vint32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vfcvt_f_x_v_f32mf2(src);
}

vfloat32m1_t test_vfcvt_f_x_v_f32m1 (vint32m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vfcvt_f_x_v_f32m1(src);
}

vfloat32m2_t test_vfcvt_f_x_v_f32m2 (vint32m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vfcvt_f_x_v_f32m2(src);
}

vfloat32m4_t test_vfcvt_f_x_v_f32m4 (vint32m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vfcvt_f_x_v_f32m4(src);
}

vfloat32m8_t test_vfcvt_f_x_v_f32m8 (vint32m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vfcvt_f_x_v_f32m8(src);
}

vfloat32mf2_t test_vfcvt_f_xu_v_f32mf2 (vuint32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32mf2(src);
}

vfloat32m1_t test_vfcvt_f_xu_v_f32m1 (vuint32m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32m1(src);
}

vfloat32m2_t test_vfcvt_f_xu_v_f32m2 (vuint32m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32m2(src);
}

vfloat32m4_t test_vfcvt_f_xu_v_f32m4 (vuint32m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32m4(src);
}

vfloat32m8_t test_vfcvt_f_xu_v_f32m8 (vuint32m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32m8(src);
}

vint64m1_t test_vfcvt_x_f_v_i64m1 (vfloat64m1_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv1i64{{.*}}(<vscale x 1 x double> %{{.*}})
  return vfcvt_x_f_v_i64m1(src);
}

vint64m1_t test_vfcvt_rtz_x_f_v_i64m1 (vfloat64m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv1i64{{.*}}(<vscale x 1 x double> %{{.*}})
  return vfcvt_rtz_x_f_v_i64m1(src);
}

vint64m2_t test_vfcvt_x_f_v_i64m2 (vfloat64m2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv2i64{{.*}}(<vscale x 2 x double> %{{.*}})
  return vfcvt_x_f_v_i64m2(src);
}

vint64m2_t test_vfcvt_rtz_x_f_v_i64m2 (vfloat64m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv2i64{{.*}}(<vscale x 2 x double> %{{.*}})
  return vfcvt_rtz_x_f_v_i64m2(src);
}

vint64m4_t test_vfcvt_x_f_v_i64m4 (vfloat64m4_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv4i64{{.*}}(<vscale x 4 x double> %{{.*}})
  return vfcvt_x_f_v_i64m4(src);
}

vint64m4_t test_vfcvt_rtz_x_f_v_i64m4 (vfloat64m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv4i64{{.*}}(<vscale x 4 x double> %{{.*}})
  return vfcvt_rtz_x_f_v_i64m4(src);
}

vint64m8_t test_vfcvt_x_f_v_i64m8 (vfloat64m8_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfcvt.x.f.v.{{.*}}nxv8i64{{.*}}(<vscale x 8 x double> %{{.*}})
  return vfcvt_x_f_v_i64m8(src);
}

vint64m8_t test_vfcvt_rtz_x_f_v_i64m8 (vfloat64m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.{{.*}}nxv8i64{{.*}}(<vscale x 8 x double> %{{.*}})
  return vfcvt_rtz_x_f_v_i64m8(src);
}

vuint64m1_t test_vfcvt_xu_f_v_u64m1 (vfloat64m1_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv1i64{{.*}}(<vscale x 1 x double> %{{.*}})
  return vfcvt_xu_f_v_u64m1(src);
}

vuint64m1_t test_vfcvt_rtz_xu_f_v_u64m1 (vfloat64m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv1i64{{.*}}(<vscale x 1 x double> %{{.*}})
  return vfcvt_rtz_xu_f_v_u64m1(src);
}

vuint64m2_t test_vfcvt_xu_f_v_u64m2 (vfloat64m2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv2i64{{.*}}(<vscale x 2 x double> %{{.*}})
  return vfcvt_xu_f_v_u64m2(src);
}

vuint64m2_t test_vfcvt_rtz_xu_f_v_u64m2 (vfloat64m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv2i64{{.*}}(<vscale x 2 x double> %{{.*}})
  return vfcvt_rtz_xu_f_v_u64m2(src);
}

vuint64m4_t test_vfcvt_xu_f_v_u64m4 (vfloat64m4_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv4i64{{.*}}(<vscale x 4 x double> %{{.*}})
  return vfcvt_xu_f_v_u64m4(src);
}

vuint64m4_t test_vfcvt_rtz_xu_f_v_u64m4 (vfloat64m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv4i64{{.*}}(<vscale x 4 x double> %{{.*}})
  return vfcvt_rtz_xu_f_v_u64m4(src);
}

vuint64m8_t test_vfcvt_xu_f_v_u64m8 (vfloat64m8_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfcvt.xu.f.v.{{.*}}nxv8i64{{.*}}(<vscale x 8 x double> %{{.*}})
  return vfcvt_xu_f_v_u64m8(src);
}

vuint64m8_t test_vfcvt_rtz_xu_f_v_u64m8 (vfloat64m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.{{.*}}nxv8i64{{.*}}(<vscale x 8 x double> %{{.*}})
  return vfcvt_rtz_xu_f_v_u64m8(src);
}

vfloat64m1_t test_vfcvt_f_x_v_f64m1 (vint64m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vfcvt_f_x_v_f64m1(src);
}

vfloat64m2_t test_vfcvt_f_x_v_f64m2 (vint64m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vfcvt_f_x_v_f64m2(src);
}

vfloat64m4_t test_vfcvt_f_x_v_f64m4 (vint64m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vfcvt_f_x_v_f64m4(src);
}

vfloat64m8_t test_vfcvt_f_x_v_f64m8 (vint64m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfcvt.f.x.v.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vfcvt_f_x_v_f64m8(src);
}

vfloat64m1_t test_vfcvt_f_xu_v_f64m1 (vuint64m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vfcvt_f_xu_v_f64m1(src);
}

vfloat64m2_t test_vfcvt_f_xu_v_f64m2 (vuint64m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vfcvt_f_xu_v_f64m2(src);
}

vfloat64m4_t test_vfcvt_f_xu_v_f64m4 (vuint64m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vfcvt_f_xu_v_f64m4(src);
}

vfloat64m8_t test_vfcvt_f_xu_v_f64m8 (vuint64m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfcvt.f.xu.v.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vfcvt_f_xu_v_f64m8(src);
}

vint16mf4_t test_vfcvt_x_f_v_i16mf4_m (vbool64_t mask, vint16mf4_t maskedoff, vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfcvt_x_f_v_i16mf4_m(mask, maskedoff, src);
}

vint16mf4_t test_vfcvt_rtz_x_f_v_i16mf4_m (vbool64_t mask, vint16mf4_t maskedoff, vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16mf4_m(mask, maskedoff, src);
}

vint16mf2_t test_vfcvt_x_f_v_i16mf2_m (vbool32_t mask, vint16mf2_t maskedoff, vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfcvt_x_f_v_i16mf2_m(mask, maskedoff, src);
}

vint16mf2_t test_vfcvt_rtz_x_f_v_i16mf2_m (vbool32_t mask, vint16mf2_t maskedoff, vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16mf2_m(mask, maskedoff, src);
}

vint16m1_t test_vfcvt_x_f_v_i16m1_m (vbool16_t mask, vint16m1_t maskedoff, vfloat16m1_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfcvt_x_f_v_i16m1_m(mask, maskedoff, src);
}

vint16m1_t test_vfcvt_rtz_x_f_v_i16m1_m (vbool16_t mask, vint16m1_t maskedoff, vfloat16m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16m1_m(mask, maskedoff, src);
}

vint16m2_t test_vfcvt_x_f_v_i16m2_m (vbool8_t mask, vint16m2_t maskedoff, vfloat16m2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfcvt_x_f_v_i16m2_m(mask, maskedoff, src);
}

vint16m2_t test_vfcvt_rtz_x_f_v_i16m2_m (vbool8_t mask, vint16m2_t maskedoff, vfloat16m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16m2_m(mask, maskedoff, src);
}

vint16m4_t test_vfcvt_x_f_v_i16m4_m (vbool4_t mask, vint16m4_t maskedoff, vfloat16m4_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfcvt_x_f_v_i16m4_m(mask, maskedoff, src);
}

vint16m4_t test_vfcvt_rtz_x_f_v_i16m4_m (vbool4_t mask, vint16m4_t maskedoff, vfloat16m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16m4_m(mask, maskedoff, src);
}

vint16m8_t test_vfcvt_x_f_v_i16m8_m (vbool2_t mask, vint16m8_t maskedoff, vfloat16m8_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfcvt_x_f_v_i16m8_m(mask, maskedoff, src);
}

vint16m8_t test_vfcvt_rtz_x_f_v_i16m8_m (vbool2_t mask, vint16m8_t maskedoff, vfloat16m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfcvt_rtz_x_f_v_i16m8_m(mask, maskedoff, src);
}

vuint16mf4_t test_vfcvt_xu_f_v_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfcvt_xu_f_v_u16mf4_m(mask, maskedoff, src);
}

vuint16mf4_t test_vfcvt_rtz_xu_f_v_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, vfloat16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16mf4_m(mask, maskedoff, src);
}

vuint16mf2_t test_vfcvt_xu_f_v_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfcvt_xu_f_v_u16mf2_m(mask, maskedoff, src);
}

vuint16mf2_t test_vfcvt_rtz_xu_f_v_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, vfloat16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16mf2_m(mask, maskedoff, src);
}

vuint16m1_t test_vfcvt_xu_f_v_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, vfloat16m1_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfcvt_xu_f_v_u16m1_m(mask, maskedoff, src);
}

vuint16m1_t test_vfcvt_rtz_xu_f_v_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, vfloat16m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16m1_m(mask, maskedoff, src);
}

vuint16m2_t test_vfcvt_xu_f_v_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, vfloat16m2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfcvt_xu_f_v_u16m2_m(mask, maskedoff, src);
}

vuint16m2_t test_vfcvt_rtz_xu_f_v_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, vfloat16m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16m2_m(mask, maskedoff, src);
}

vuint16m4_t test_vfcvt_xu_f_v_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, vfloat16m4_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfcvt_xu_f_v_u16m4_m(mask, maskedoff, src);
}

vuint16m4_t test_vfcvt_rtz_xu_f_v_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, vfloat16m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16m4_m(mask, maskedoff, src);
}

vuint16m8_t test_vfcvt_xu_f_v_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff, vfloat16m8_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfcvt_xu_f_v_u16m8_m(mask, maskedoff, src);
}

vuint16m8_t test_vfcvt_rtz_xu_f_v_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff, vfloat16m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vfcvt_rtz_xu_f_v_u16m8_m(mask, maskedoff, src);
}

vfloat16mf4_t test_vfcvt_f_x_v_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vint16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vfcvt_f_x_v_f16mf4_m(mask, maskedoff, src);
}

vfloat16mf2_t test_vfcvt_f_x_v_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vint16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vfcvt_f_x_v_f16mf2_m(mask, maskedoff, src);
}

vfloat16m1_t test_vfcvt_f_x_v_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vint16m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vfcvt_f_x_v_f16m1_m(mask, maskedoff, src);
}

vfloat16m2_t test_vfcvt_f_x_v_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vint16m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vfcvt_f_x_v_f16m2_m(mask, maskedoff, src);
}

vfloat16m4_t test_vfcvt_f_x_v_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vint16m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vfcvt_f_x_v_f16m4_m(mask, maskedoff, src);
}

vfloat16m8_t test_vfcvt_f_x_v_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vint16m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vfcvt_f_x_v_f16m8_m(mask, maskedoff, src);
}

vfloat16mf4_t test_vfcvt_f_xu_v_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, vuint16mf4_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16mf4_m(mask, maskedoff, src);
}

vfloat16mf2_t test_vfcvt_f_xu_v_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, vuint16mf2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16mf2_m(mask, maskedoff, src);
}

vfloat16m1_t test_vfcvt_f_xu_v_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, vuint16m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16m1_m(mask, maskedoff, src);
}

vfloat16m2_t test_vfcvt_f_xu_v_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, vuint16m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16m2_m(mask, maskedoff, src);
}

vfloat16m4_t test_vfcvt_f_xu_v_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, vuint16m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16m4_m(mask, maskedoff, src);
}

vfloat16m8_t test_vfcvt_f_xu_v_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, vuint16m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vfcvt_f_xu_v_f16m8_m(mask, maskedoff, src);
}

vint32mf2_t test_vfcvt_x_f_v_i32mf2_m (vbool64_t mask, vint32mf2_t maskedoff, vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfcvt_x_f_v_i32mf2_m(mask, maskedoff, src);
}

vint32mf2_t test_vfcvt_rtz_x_f_v_i32mf2_m (vbool64_t mask, vint32mf2_t maskedoff, vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32mf2_m(mask, maskedoff, src);
}

vint32m1_t test_vfcvt_x_f_v_i32m1_m (vbool32_t mask, vint32m1_t maskedoff, vfloat32m1_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfcvt_x_f_v_i32m1_m(mask, maskedoff, src);
}

vint32m1_t test_vfcvt_rtz_x_f_v_i32m1_m (vbool32_t mask, vint32m1_t maskedoff, vfloat32m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32m1_m(mask, maskedoff, src);
}

vint32m2_t test_vfcvt_x_f_v_i32m2_m (vbool16_t mask, vint32m2_t maskedoff, vfloat32m2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfcvt_x_f_v_i32m2_m(mask, maskedoff, src);
}

vint32m2_t test_vfcvt_rtz_x_f_v_i32m2_m (vbool16_t mask, vint32m2_t maskedoff, vfloat32m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32m2_m(mask, maskedoff, src);
}

vint32m4_t test_vfcvt_x_f_v_i32m4_m (vbool8_t mask, vint32m4_t maskedoff, vfloat32m4_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfcvt_x_f_v_i32m4_m(mask, maskedoff, src);
}

vint32m4_t test_vfcvt_rtz_x_f_v_i32m4_m (vbool8_t mask, vint32m4_t maskedoff, vfloat32m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32m4_m(mask, maskedoff, src);
}

vint32m8_t test_vfcvt_x_f_v_i32m8_m (vbool4_t mask, vint32m8_t maskedoff, vfloat32m8_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfcvt_x_f_v_i32m8_m(mask, maskedoff, src);
}

vint32m8_t test_vfcvt_rtz_x_f_v_i32m8_m (vbool4_t mask, vint32m8_t maskedoff, vfloat32m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfcvt_rtz_x_f_v_i32m8_m(mask, maskedoff, src);
}

vuint32mf2_t test_vfcvt_xu_f_v_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfcvt_xu_f_v_u32mf2_m(mask, maskedoff, src);
}

vuint32mf2_t test_vfcvt_rtz_xu_f_v_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, vfloat32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32mf2_m(mask, maskedoff, src);
}

vuint32m1_t test_vfcvt_xu_f_v_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, vfloat32m1_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfcvt_xu_f_v_u32m1_m(mask, maskedoff, src);
}

vuint32m1_t test_vfcvt_rtz_xu_f_v_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, vfloat32m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32m1_m(mask, maskedoff, src);
}

vuint32m2_t test_vfcvt_xu_f_v_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, vfloat32m2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfcvt_xu_f_v_u32m2_m(mask, maskedoff, src);
}

vuint32m2_t test_vfcvt_rtz_xu_f_v_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, vfloat32m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32m2_m(mask, maskedoff, src);
}

vuint32m4_t test_vfcvt_xu_f_v_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, vfloat32m4_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfcvt_xu_f_v_u32m4_m(mask, maskedoff, src);
}

vuint32m4_t test_vfcvt_rtz_xu_f_v_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, vfloat32m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32m4_m(mask, maskedoff, src);
}

vuint32m8_t test_vfcvt_xu_f_v_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, vfloat32m8_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfcvt_xu_f_v_u32m8_m(mask, maskedoff, src);
}

vuint32m8_t test_vfcvt_rtz_xu_f_v_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, vfloat32m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vfcvt_rtz_xu_f_v_u32m8_m(mask, maskedoff, src);
}

vfloat32mf2_t test_vfcvt_f_x_v_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vint32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vfcvt_f_x_v_f32mf2_m(mask, maskedoff, src);
}

vfloat32m1_t test_vfcvt_f_x_v_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vint32m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vfcvt_f_x_v_f32m1_m(mask, maskedoff, src);
}

vfloat32m2_t test_vfcvt_f_x_v_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vint32m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vfcvt_f_x_v_f32m2_m(mask, maskedoff, src);
}

vfloat32m4_t test_vfcvt_f_x_v_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vint32m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vfcvt_f_x_v_f32m4_m(mask, maskedoff, src);
}

vfloat32m8_t test_vfcvt_f_x_v_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vint32m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vfcvt_f_x_v_f32m8_m(mask, maskedoff, src);
}

vfloat32mf2_t test_vfcvt_f_xu_v_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, vuint32mf2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32mf2_m(mask, maskedoff, src);
}

vfloat32m1_t test_vfcvt_f_xu_v_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, vuint32m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32m1_m(mask, maskedoff, src);
}

vfloat32m2_t test_vfcvt_f_xu_v_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, vuint32m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32m2_m(mask, maskedoff, src);
}

vfloat32m4_t test_vfcvt_f_xu_v_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, vuint32m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32m4_m(mask, maskedoff, src);
}

vfloat32m8_t test_vfcvt_f_xu_v_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, vuint32m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vfcvt_f_xu_v_f32m8_m(mask, maskedoff, src);
}

vint64m1_t test_vfcvt_x_f_v_i64m1_m (vbool64_t mask, vint64m1_t maskedoff, vfloat64m1_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfcvt_x_f_v_i64m1_m(mask, maskedoff, src);
}

vint64m1_t test_vfcvt_rtz_x_f_v_i64m1_m (vbool64_t mask, vint64m1_t maskedoff, vfloat64m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfcvt_rtz_x_f_v_i64m1_m(mask, maskedoff, src);
}

vint64m2_t test_vfcvt_x_f_v_i64m2_m (vbool32_t mask, vint64m2_t maskedoff, vfloat64m2_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vfcvt_x_f_v_i64m2_m(mask, maskedoff, src);
}

vint64m2_t test_vfcvt_rtz_x_f_v_i64m2_m (vbool32_t mask, vint64m2_t maskedoff, vfloat64m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vfcvt_rtz_x_f_v_i64m2_m(mask, maskedoff, src);
}

vint64m4_t test_vfcvt_x_f_v_i64m4_m (vbool16_t mask, vint64m4_t maskedoff, vfloat64m4_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vfcvt_x_f_v_i64m4_m(mask, maskedoff, src);
}

vint64m4_t test_vfcvt_rtz_x_f_v_i64m4_m (vbool16_t mask, vint64m4_t maskedoff, vfloat64m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vfcvt_rtz_x_f_v_i64m4_m(mask, maskedoff, src);
}

vint64m8_t test_vfcvt_x_f_v_i64m8_m (vbool8_t mask, vint64m8_t maskedoff, vfloat64m8_t src) {
  // CHECK-LABEL: test_vfcvt_x_f_v_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfcvt.x.f.v.mask.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vfcvt_x_f_v_i64m8_m(mask, maskedoff, src);
}

vint64m8_t test_vfcvt_rtz_x_f_v_i64m8_m (vbool8_t mask, vint64m8_t maskedoff, vfloat64m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_x_f_v_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.mask.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vfcvt_rtz_x_f_v_i64m8_m(mask, maskedoff, src);
}

vuint64m1_t test_vfcvt_xu_f_v_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff, vfloat64m1_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfcvt_xu_f_v_u64m1_m(mask, maskedoff, src);
}

vuint64m1_t test_vfcvt_rtz_xu_f_v_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff, vfloat64m1_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vfcvt_rtz_xu_f_v_u64m1_m(mask, maskedoff, src);
}

vuint64m2_t test_vfcvt_xu_f_v_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff, vfloat64m2_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vfcvt_xu_f_v_u64m2_m(mask, maskedoff, src);
}

vuint64m2_t test_vfcvt_rtz_xu_f_v_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff, vfloat64m2_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vfcvt_rtz_xu_f_v_u64m2_m(mask, maskedoff, src);
}

vuint64m4_t test_vfcvt_xu_f_v_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff, vfloat64m4_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vfcvt_xu_f_v_u64m4_m(mask, maskedoff, src);
}

vuint64m4_t test_vfcvt_rtz_xu_f_v_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff, vfloat64m4_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vfcvt_rtz_xu_f_v_u64m4_m(mask, maskedoff, src);
}

vuint64m8_t test_vfcvt_xu_f_v_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff, vfloat64m8_t src) {
  // CHECK-LABEL: test_vfcvt_xu_f_v_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfcvt.xu.f.v.mask.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vfcvt_xu_f_v_u64m8_m(mask, maskedoff, src);
}

vuint64m8_t test_vfcvt_rtz_xu_f_v_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff, vfloat64m8_t src) {
  // CHECK-LABEL: test_vfcvt_rtz_xu_f_v_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vfcvt_rtz_xu_f_v_u64m8_m(mask, maskedoff, src);
}

vfloat64m1_t test_vfcvt_f_x_v_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, vint64m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vfcvt_f_x_v_f64m1_m(mask, maskedoff, src);
}

vfloat64m2_t test_vfcvt_f_x_v_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, vint64m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vfcvt_f_x_v_f64m2_m(mask, maskedoff, src);
}

vfloat64m4_t test_vfcvt_f_x_v_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, vint64m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vfcvt_f_x_v_f64m4_m(mask, maskedoff, src);
}

vfloat64m8_t test_vfcvt_f_x_v_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, vint64m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_x_v_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfcvt.f.x.v.mask.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vfcvt_f_x_v_f64m8_m(mask, maskedoff, src);
}

vfloat64m1_t test_vfcvt_f_xu_v_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, vuint64m1_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv1f64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vfcvt_f_xu_v_f64m1_m(mask, maskedoff, src);
}

vfloat64m2_t test_vfcvt_f_xu_v_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, vuint64m2_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv2f64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vfcvt_f_xu_v_f64m2_m(mask, maskedoff, src);
}

vfloat64m4_t test_vfcvt_f_xu_v_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, vuint64m4_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv4f64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vfcvt_f_xu_v_f64m4_m(mask, maskedoff, src);
}

vfloat64m8_t test_vfcvt_f_xu_v_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, vuint64m8_t src) {
  // CHECK-LABEL: test_vfcvt_f_xu_v_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfcvt.f.xu.v.mask.{{.*}}nxv8f64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vfcvt_f_xu_v_f64m8_m(mask, maskedoff, src);
}


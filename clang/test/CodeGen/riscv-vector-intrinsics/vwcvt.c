// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16mf4_t test_vwcvt_x_x_v_i16mf4 (vint8mf8_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwcvt.x.x.v.nxv1i16{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vwcvt_x_x_v_i16mf4(src);
}

vint16mf2_t test_vwcvt_x_x_v_i16mf2 (vint8mf4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwcvt.x.x.v.nxv2i16{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vwcvt_x_x_v_i16mf2(src);
}

vint16m1_t test_vwcvt_x_x_v_i16m1 (vint8mf2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwcvt.x.x.v.nxv4i16{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vwcvt_x_x_v_i16m1(src);
}

vint16m2_t test_vwcvt_x_x_v_i16m2 (vint8m1_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwcvt.x.x.v.nxv8i16{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vwcvt_x_x_v_i16m2(src);
}

vint16m4_t test_vwcvt_x_x_v_i16m4 (vint8m2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwcvt.x.x.v.nxv16i16{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vwcvt_x_x_v_i16m4(src);
}

vint16m8_t test_vwcvt_x_x_v_i16m8 (vint8m4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwcvt.x.x.v.nxv32i16{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vwcvt_x_x_v_i16m8(src);
}

vint32mf2_t test_vwcvt_x_x_v_i32mf2 (vint16mf4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwcvt.x.x.v.nxv1i32{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vwcvt_x_x_v_i32mf2(src);
}

vint32m1_t test_vwcvt_x_x_v_i32m1 (vint16mf2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwcvt.x.x.v.nxv2i32{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vwcvt_x_x_v_i32m1(src);
}

vint32m2_t test_vwcvt_x_x_v_i32m2 (vint16m1_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwcvt.x.x.v.nxv4i32{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vwcvt_x_x_v_i32m2(src);
}

vint32m4_t test_vwcvt_x_x_v_i32m4 (vint16m2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwcvt.x.x.v.nxv8i32{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vwcvt_x_x_v_i32m4(src);
}

vint32m8_t test_vwcvt_x_x_v_i32m8 (vint16m4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwcvt.x.x.v.nxv16i32{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vwcvt_x_x_v_i32m8(src);
}

vint64m1_t test_vwcvt_x_x_v_i64m1 (vint32mf2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwcvt.x.x.v.nxv1i64{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vwcvt_x_x_v_i64m1(src);
}

vint64m2_t test_vwcvt_x_x_v_i64m2 (vint32m1_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwcvt.x.x.v.nxv2i64{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vwcvt_x_x_v_i64m2(src);
}

vint64m4_t test_vwcvt_x_x_v_i64m4 (vint32m2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwcvt.x.x.v.nxv4i64{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vwcvt_x_x_v_i64m4(src);
}

vint64m8_t test_vwcvt_x_x_v_i64m8 (vint32m4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwcvt.x.x.v.nxv8i64{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vwcvt_x_x_v_i64m8(src);
}

vint16mf4_t test_vwcvt_x_x_v_i16mf4_m (vbool64_t mask, vint16mf4_t maskedoff, vint8mf8_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwcvt.x.x.v.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vwcvt_x_x_v_i16mf4_m(mask, maskedoff, src);
}

vint16mf2_t test_vwcvt_x_x_v_i16mf2_m (vbool32_t mask, vint16mf2_t maskedoff, vint8mf4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwcvt.x.x.v.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vwcvt_x_x_v_i16mf2_m(mask, maskedoff, src);
}

vint16m1_t test_vwcvt_x_x_v_i16m1_m (vbool16_t mask, vint16m1_t maskedoff, vint8mf2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwcvt.x.x.v.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vwcvt_x_x_v_i16m1_m(mask, maskedoff, src);
}

vint16m2_t test_vwcvt_x_x_v_i16m2_m (vbool8_t mask, vint16m2_t maskedoff, vint8m1_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwcvt.x.x.v.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vwcvt_x_x_v_i16m2_m(mask, maskedoff, src);
}

vint16m4_t test_vwcvt_x_x_v_i16m4_m (vbool4_t mask, vint16m4_t maskedoff, vint8m2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwcvt.x.x.v.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vwcvt_x_x_v_i16m4_m(mask, maskedoff, src);
}

vint16m8_t test_vwcvt_x_x_v_i16m8_m (vbool2_t mask, vint16m8_t maskedoff, vint8m4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwcvt.x.x.v.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vwcvt_x_x_v_i16m8_m(mask, maskedoff, src);
}

vint32mf2_t test_vwcvt_x_x_v_i32mf2_m (vbool64_t mask, vint32mf2_t maskedoff, vint16mf4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwcvt.x.x.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vwcvt_x_x_v_i32mf2_m(mask, maskedoff, src);
}

vint32m1_t test_vwcvt_x_x_v_i32m1_m (vbool32_t mask, vint32m1_t maskedoff, vint16mf2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwcvt.x.x.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vwcvt_x_x_v_i32m1_m(mask, maskedoff, src);
}

vint32m2_t test_vwcvt_x_x_v_i32m2_m (vbool16_t mask, vint32m2_t maskedoff, vint16m1_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwcvt.x.x.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vwcvt_x_x_v_i32m2_m(mask, maskedoff, src);
}

vint32m4_t test_vwcvt_x_x_v_i32m4_m (vbool8_t mask, vint32m4_t maskedoff, vint16m2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwcvt.x.x.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vwcvt_x_x_v_i32m4_m(mask, maskedoff, src);
}

vint32m8_t test_vwcvt_x_x_v_i32m8_m (vbool4_t mask, vint32m8_t maskedoff, vint16m4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwcvt.x.x.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vwcvt_x_x_v_i32m8_m(mask, maskedoff, src);
}

vint64m1_t test_vwcvt_x_x_v_i64m1_m (vbool64_t mask, vint64m1_t maskedoff, vint32mf2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwcvt.x.x.v.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vwcvt_x_x_v_i64m1_m(mask, maskedoff, src);
}

vint64m2_t test_vwcvt_x_x_v_i64m2_m (vbool32_t mask, vint64m2_t maskedoff, vint32m1_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwcvt.x.x.v.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vwcvt_x_x_v_i64m2_m(mask, maskedoff, src);
}

vint64m4_t test_vwcvt_x_x_v_i64m4_m (vbool16_t mask, vint64m4_t maskedoff, vint32m2_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwcvt.x.x.v.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vwcvt_x_x_v_i64m4_m(mask, maskedoff, src);
}

vint64m8_t test_vwcvt_x_x_v_i64m8_m (vbool8_t mask, vint64m8_t maskedoff, vint32m4_t src) {
  // CHECK-LABEL: test_vwcvt_x_x_v_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwcvt.x.x.v.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vwcvt_x_x_v_i64m8_m(mask, maskedoff, src);
}


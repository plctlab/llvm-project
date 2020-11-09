// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint16mf4_t test_vwcvtu_x_x_v_u16mf4 (vuint8mf8_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwcvtu.x.x.v.nxv1i16{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16mf4(src);
}

vuint16mf2_t test_vwcvtu_x_x_v_u16mf2 (vuint8mf4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwcvtu.x.x.v.nxv2i16{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16mf2(src);
}

vuint16m1_t test_vwcvtu_x_x_v_u16m1 (vuint8mf2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwcvtu.x.x.v.nxv4i16{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16m1(src);
}

vuint16m2_t test_vwcvtu_x_x_v_u16m2 (vuint8m1_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwcvtu.x.x.v.nxv8i16{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16m2(src);
}

vuint16m4_t test_vwcvtu_x_x_v_u16m4 (vuint8m2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwcvtu.x.x.v.nxv16i16{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16m4(src);
}

vuint16m8_t test_vwcvtu_x_x_v_u16m8 (vuint8m4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwcvtu.x.x.v.nxv32i16{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16m8(src);
}

vuint32mf2_t test_vwcvtu_x_x_v_u32mf2 (vuint16mf4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwcvtu.x.x.v.nxv1i32{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32mf2(src);
}

vuint32m1_t test_vwcvtu_x_x_v_u32m1 (vuint16mf2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwcvtu.x.x.v.nxv2i32{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32m1(src);
}

vuint32m2_t test_vwcvtu_x_x_v_u32m2 (vuint16m1_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwcvtu.x.x.v.nxv4i32{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32m2(src);
}

vuint32m4_t test_vwcvtu_x_x_v_u32m4 (vuint16m2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwcvtu.x.x.v.nxv8i32{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32m4(src);
}

vuint32m8_t test_vwcvtu_x_x_v_u32m8 (vuint16m4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwcvtu.x.x.v.nxv16i32{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32m8(src);
}

vuint64m1_t test_vwcvtu_x_x_v_u64m1 (vuint32mf2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwcvtu.x.x.v.nxv1i64{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vwcvtu_x_x_v_u64m1(src);
}

vuint64m2_t test_vwcvtu_x_x_v_u64m2 (vuint32m1_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwcvtu.x.x.v.nxv2i64{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vwcvtu_x_x_v_u64m2(src);
}

vuint64m4_t test_vwcvtu_x_x_v_u64m4 (vuint32m2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwcvtu.x.x.v.nxv4i64{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vwcvtu_x_x_v_u64m4(src);
}

vuint64m8_t test_vwcvtu_x_x_v_u64m8 (vuint32m4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwcvtu.x.x.v.nxv8i64{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vwcvtu_x_x_v_u64m8(src);
}

vuint16mf4_t test_vwcvtu_x_x_v_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, vuint8mf8_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwcvtu.x.x.v.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16mf4_m(mask, maskedoff, src);
}

vuint16mf2_t test_vwcvtu_x_x_v_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, vuint8mf4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwcvtu.x.x.v.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16mf2_m(mask, maskedoff, src);
}

vuint16m1_t test_vwcvtu_x_x_v_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, vuint8mf2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwcvtu.x.x.v.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16m1_m(mask, maskedoff, src);
}

vuint16m2_t test_vwcvtu_x_x_v_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, vuint8m1_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwcvtu.x.x.v.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16m2_m(mask, maskedoff, src);
}

vuint16m4_t test_vwcvtu_x_x_v_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, vuint8m2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwcvtu.x.x.v.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16m4_m(mask, maskedoff, src);
}

vuint16m8_t test_vwcvtu_x_x_v_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff, vuint8m4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwcvtu.x.x.v.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vwcvtu_x_x_v_u16m8_m(mask, maskedoff, src);
}

vuint32mf2_t test_vwcvtu_x_x_v_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, vuint16mf4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwcvtu.x.x.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32mf2_m(mask, maskedoff, src);
}

vuint32m1_t test_vwcvtu_x_x_v_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, vuint16mf2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwcvtu.x.x.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32m1_m(mask, maskedoff, src);
}

vuint32m2_t test_vwcvtu_x_x_v_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, vuint16m1_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwcvtu.x.x.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32m2_m(mask, maskedoff, src);
}

vuint32m4_t test_vwcvtu_x_x_v_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, vuint16m2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwcvtu.x.x.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32m4_m(mask, maskedoff, src);
}

vuint32m8_t test_vwcvtu_x_x_v_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, vuint16m4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwcvtu.x.x.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vwcvtu_x_x_v_u32m8_m(mask, maskedoff, src);
}

vuint64m1_t test_vwcvtu_x_x_v_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff, vuint32mf2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwcvtu.x.x.v.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vwcvtu_x_x_v_u64m1_m(mask, maskedoff, src);
}

vuint64m2_t test_vwcvtu_x_x_v_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff, vuint32m1_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwcvtu.x.x.v.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vwcvtu_x_x_v_u64m2_m(mask, maskedoff, src);
}

vuint64m4_t test_vwcvtu_x_x_v_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff, vuint32m2_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwcvtu.x.x.v.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vwcvtu_x_x_v_u64m4_m(mask, maskedoff, src);
}

vuint64m8_t test_vwcvtu_x_x_v_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff, vuint32m4_t src) {
  // CHECK-LABEL: test_vwcvtu_x_x_v_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwcvtu.x.x.v.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vwcvtu_x_x_v_u64m8_m(mask, maskedoff, src);
}


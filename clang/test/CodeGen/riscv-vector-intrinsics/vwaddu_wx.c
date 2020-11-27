// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint16mf4_t test_vwaddu_wx_u16mf4 (vuint16mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16mf4(op1, op2);
}

vuint16mf2_t test_vwaddu_wx_u16mf2 (vuint16mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16mf2(op1, op2);
}

vuint16m1_t test_vwaddu_wx_u16m1 (vuint16m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16m1(op1, op2);
}

vuint16m2_t test_vwaddu_wx_u16m2 (vuint16m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16m2(op1, op2);
}

vuint16m4_t test_vwaddu_wx_u16m4 (vuint16m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16m4(op1, op2);
}

vuint16m8_t test_vwaddu_wx_u16m8 (vuint16m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16m8(op1, op2);
}

vuint32mf2_t test_vwaddu_wx_u32mf2 (vuint32mf2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32mf2(op1, op2);
}

vuint32m1_t test_vwaddu_wx_u32m1 (vuint32m1_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32m1(op1, op2);
}

vuint32m2_t test_vwaddu_wx_u32m2 (vuint32m2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32m2(op1, op2);
}

vuint32m4_t test_vwaddu_wx_u32m4 (vuint32m4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32m4(op1, op2);
}

vuint32m8_t test_vwaddu_wx_u32m8 (vuint32m8_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32m8(op1, op2);
}

vuint64m1_t test_vwaddu_wx_u64m1 (vuint64m1_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwaddu.wx.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i32 %{{.*}})
  return vwaddu_wx_u64m1(op1, op2);
}

vuint64m2_t test_vwaddu_wx_u64m2 (vuint64m2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwaddu.wx.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i32 %{{.*}})
  return vwaddu_wx_u64m2(op1, op2);
}

vuint64m4_t test_vwaddu_wx_u64m4 (vuint64m4_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwaddu.wx.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i32 %{{.*}})
  return vwaddu_wx_u64m4(op1, op2);
}

vuint64m8_t test_vwaddu_wx_u64m8 (vuint64m8_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwaddu.wx.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i32 %{{.*}})
  return vwaddu_wx_u64m8(op1, op2);
}

vuint16mf4_t test_vwaddu_wx_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, vuint16mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16mf4_m(mask, maskedoff, op1, op2);
}

vuint16mf2_t test_vwaddu_wx_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, vuint16mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16mf2_m(mask, maskedoff, op1, op2);
}

vuint16m1_t test_vwaddu_wx_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, vuint16m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16m1_m(mask, maskedoff, op1, op2);
}

vuint16m2_t test_vwaddu_wx_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, vuint16m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16m2_m(mask, maskedoff, op1, op2);
}

vuint16m4_t test_vwaddu_wx_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, vuint16m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16m4_m(mask, maskedoff, op1, op2);
}

vuint16m8_t test_vwaddu_wx_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff, vuint16m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vwaddu.wx.{{.*}}nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i8 %{{.*}})
  return vwaddu_wx_u16m8_m(mask, maskedoff, op1, op2);
}

vuint32mf2_t test_vwaddu_wx_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, vuint32mf2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32mf2_m(mask, maskedoff, op1, op2);
}

vuint32m1_t test_vwaddu_wx_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, vuint32m1_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32m1_m(mask, maskedoff, op1, op2);
}

vuint32m2_t test_vwaddu_wx_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, vuint32m2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32m2_m(mask, maskedoff, op1, op2);
}

vuint32m4_t test_vwaddu_wx_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, vuint32m4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32m4_m(mask, maskedoff, op1, op2);
}

vuint32m8_t test_vwaddu_wx_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, vuint32m8_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vwaddu.wx.{{.*}}nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i16 %{{.*}})
  return vwaddu_wx_u32m8_m(mask, maskedoff, op1, op2);
}

vuint64m1_t test_vwaddu_wx_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwaddu.wx.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i32 %{{.*}})
  return vwaddu_wx_u64m1_m(mask, maskedoff, op1, op2);
}

vuint64m2_t test_vwaddu_wx_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwaddu.wx.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i32 %{{.*}})
  return vwaddu_wx_u64m2_m(mask, maskedoff, op1, op2);
}

vuint64m4_t test_vwaddu_wx_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vwaddu.wx.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i32 %{{.*}})
  return vwaddu_wx_u64m4_m(mask, maskedoff, op1, op2);
}

vuint64m8_t test_vwaddu_wx_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vwaddu_wx_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwaddu.wx.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i32 %{{.*}})
  return vwaddu_wx_u64m8_m(mask, maskedoff, op1, op2);
}


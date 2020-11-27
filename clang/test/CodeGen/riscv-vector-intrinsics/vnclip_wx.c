// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vnclip_wx_i8mf8 (vint16mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv1i8{{.*}}(<vscale x 1 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8mf8(op1, op2);
}

vint8mf4_t test_vnclip_wx_i8mf4 (vint16mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv2i8{{.*}}(<vscale x 2 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8mf4(op1, op2);
}

vint8mf2_t test_vnclip_wx_i8mf2 (vint16m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv4i8{{.*}}(<vscale x 4 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8mf2(op1, op2);
}

vint8m1_t test_vnclip_wx_i8m1 (vint16m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv8i8{{.*}}(<vscale x 8 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8m1(op1, op2);
}

vint8m2_t test_vnclip_wx_i8m2 (vint16m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv16i8{{.*}}(<vscale x 16 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8m2(op1, op2);
}

vint8m4_t test_vnclip_wx_i8m4 (vint16m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv32i8{{.*}}(<vscale x 32 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8m4(op1, op2);
}

vint16mf4_t test_vnclip_wx_i16mf4 (vint32mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16mf4(op1, op2);
}

vint16mf2_t test_vnclip_wx_i16mf2 (vint32m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16mf2(op1, op2);
}

vint16m1_t test_vnclip_wx_i16m1 (vint32m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16m1(op1, op2);
}

vint16m2_t test_vnclip_wx_i16m2 (vint32m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16m2(op1, op2);
}

vint16m4_t test_vnclip_wx_i16m4 (vint32m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16m4(op1, op2);
}

vint32mf2_t test_vnclip_wx_i32mf2 (vint64m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vnclip.wx.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i64> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i32mf2(op1, op2);
}

vint32m1_t test_vnclip_wx_i32m1 (vint64m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vnclip.wx.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i64> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i32m1(op1, op2);
}

vint32m2_t test_vnclip_wx_i32m2 (vint64m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vnclip.wx.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i64> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i32m2(op1, op2);
}

vint32m4_t test_vnclip_wx_i32m4 (vint64m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vnclip.wx.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i64> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i32m4(op1, op2);
}

vint8mf8_t test_vnclip_wx_i8mf8_m (vbool64_t mask, vint8mf8_t maskedoff, vint16mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8mf8_m(mask, maskedoff, op1, op2);
}

vint8mf4_t test_vnclip_wx_i8mf4_m (vbool32_t mask, vint8mf4_t maskedoff, vint16mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8mf4_m(mask, maskedoff, op1, op2);
}

vint8mf2_t test_vnclip_wx_i8mf2_m (vbool16_t mask, vint8mf2_t maskedoff, vint16m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8mf2_m(mask, maskedoff, op1, op2);
}

vint8m1_t test_vnclip_wx_i8m1_m (vbool8_t mask, vint8m1_t maskedoff, vint16m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8m1_m(mask, maskedoff, op1, op2);
}

vint8m2_t test_vnclip_wx_i8m2_m (vbool4_t mask, vint8m2_t maskedoff, vint16m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8m2_m(mask, maskedoff, op1, op2);
}

vint8m4_t test_vnclip_wx_i8m4_m (vbool2_t mask, vint8m4_t maskedoff, vint16m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vnclip.wx.{{.*}}nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i8m4_m(mask, maskedoff, op1, op2);
}

vint16mf4_t test_vnclip_wx_i16mf4_m (vbool64_t mask, vint16mf4_t maskedoff, vint32mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16mf4_m(mask, maskedoff, op1, op2);
}

vint16mf2_t test_vnclip_wx_i16mf2_m (vbool32_t mask, vint16mf2_t maskedoff, vint32m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16mf2_m(mask, maskedoff, op1, op2);
}

vint16m1_t test_vnclip_wx_i16m1_m (vbool16_t mask, vint16m1_t maskedoff, vint32m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16m1_m(mask, maskedoff, op1, op2);
}

vint16m2_t test_vnclip_wx_i16m2_m (vbool8_t mask, vint16m2_t maskedoff, vint32m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16m2_m(mask, maskedoff, op1, op2);
}

vint16m4_t test_vnclip_wx_i16m4_m (vbool4_t mask, vint16m4_t maskedoff, vint32m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vnclip.wx.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i16m4_m(mask, maskedoff, op1, op2);
}

vint32mf2_t test_vnclip_wx_i32mf2_m (vbool64_t mask, vint32mf2_t maskedoff, vint64m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vnclip.wx.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i32mf2_m(mask, maskedoff, op1, op2);
}

vint32m1_t test_vnclip_wx_i32m1_m (vbool32_t mask, vint32m1_t maskedoff, vint64m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vnclip.wx.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i32m1_m(mask, maskedoff, op1, op2);
}

vint32m2_t test_vnclip_wx_i32m2_m (vbool16_t mask, vint32m2_t maskedoff, vint64m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vnclip.wx.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i32m2_m(mask, maskedoff, op1, op2);
}

vint32m4_t test_vnclip_wx_i32m4_m (vbool8_t mask, vint32m4_t maskedoff, vint64m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vnclip_wx_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vnclip.wx.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i8 %{{.*}})
  return vnclip_wx_i32m4_m(mask, maskedoff, op1, op2);
}


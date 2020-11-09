// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2_t test_vqmaccus_vx_i32mf2 (vint32mf2_t acc, uint8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmaccus.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmaccus_vx_i32mf2(acc, op1, op2);
}

vint32m1_t test_vqmaccus_vx_i32m1 (vint32m1_t acc, uint8_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmaccus.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmaccus_vx_i32m1(acc, op1, op2);
}

vint32m2_t test_vqmaccus_vx_i32m2 (vint32m2_t acc, uint8_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmaccus.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmaccus_vx_i32m2(acc, op1, op2);
}

vint32m4_t test_vqmaccus_vx_i32m4 (vint32m4_t acc, uint8_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmaccus.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmaccus_vx_i32m4(acc, op1, op2);
}

vint32m8_t test_vqmaccus_vx_i32m8 (vint32m8_t acc, uint8_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmaccus.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmaccus_vx_i32m8(acc, op1, op2);
}

vint64m1_t test_vqmaccus_vx_i64m1 (vint64m1_t acc, uint16_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmaccus.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmaccus_vx_i64m1(acc, op1, op2);
}

vint64m2_t test_vqmaccus_vx_i64m2 (vint64m2_t acc, uint16_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmaccus.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmaccus_vx_i64m2(acc, op1, op2);
}

vint64m4_t test_vqmaccus_vx_i64m4 (vint64m4_t acc, uint16_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmaccus.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmaccus_vx_i64m4(acc, op1, op2);
}

vint64m8_t test_vqmaccus_vx_i64m8 (vint64m8_t acc, uint16_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmaccus.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmaccus_vx_i64m8(acc, op1, op2);
}

vint32mf2_t test_vqmaccus_vx_i32mf2_m (vbool64_t mask, vint32mf2_t acc, uint8_t op1, vint8mf8_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vqmaccus.vx.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vqmaccus_vx_i32mf2_m(mask, acc, op1, op2);
}

vint32m1_t test_vqmaccus_vx_i32m1_m (vbool32_t mask, vint32m1_t acc, uint8_t op1, vint8mf4_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vqmaccus.vx.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vqmaccus_vx_i32m1_m(mask, acc, op1, op2);
}

vint32m2_t test_vqmaccus_vx_i32m2_m (vbool16_t mask, vint32m2_t acc, uint8_t op1, vint8mf2_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vqmaccus.vx.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vqmaccus_vx_i32m2_m(mask, acc, op1, op2);
}

vint32m4_t test_vqmaccus_vx_i32m4_m (vbool8_t mask, vint32m4_t acc, uint8_t op1, vint8m1_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmaccus.vx.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vqmaccus_vx_i32m4_m(mask, acc, op1, op2);
}

vint32m8_t test_vqmaccus_vx_i32m8_m (vbool4_t mask, vint32m8_t acc, uint8_t op1, vint8m2_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vqmaccus.vx.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vqmaccus_vx_i32m8_m(mask, acc, op1, op2);
}

vint64m1_t test_vqmaccus_vx_i64m1_m (vbool64_t mask, vint64m1_t acc, uint16_t op1, vint16mf4_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vqmaccus.vx.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vqmaccus_vx_i64m1_m(mask, acc, op1, op2);
}

vint64m2_t test_vqmaccus_vx_i64m2_m (vbool32_t mask, vint64m2_t acc, uint16_t op1, vint16mf2_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vqmaccus.vx.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vqmaccus_vx_i64m2_m(mask, acc, op1, op2);
}

vint64m4_t test_vqmaccus_vx_i64m4_m (vbool16_t mask, vint64m4_t acc, uint16_t op1, vint16m1_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vqmaccus.vx.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vqmaccus_vx_i64m4_m(mask, acc, op1, op2);
}

vint64m8_t test_vqmaccus_vx_i64m8_m (vbool8_t mask, vint64m8_t acc, uint16_t op1, vint16m2_t op2) {
  // CHECK-LABEL: test_vqmaccus_vx_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vqmaccus.vx.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vqmaccus_vx_i64m8_m(mask, acc, op1, op2);
}


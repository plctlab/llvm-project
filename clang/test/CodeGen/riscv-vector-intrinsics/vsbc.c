// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vsbc_vvm_i8mf8 (vint8mf8_t op1, vint8mf8_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vsbc.vvm.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vvm_i8mf8(op1, op2, borrowin);
}

vint8mf8_t test_vsbc_vxm_i8mf8 (vint8mf8_t op1, int8_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vsbc.vxm.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vxm_i8mf8(op1, op2, borrowin);
}

vint8mf4_t test_vsbc_vvm_i8mf4 (vint8mf4_t op1, vint8mf4_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vsbc.vvm.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vvm_i8mf4(op1, op2, borrowin);
}

vint8mf4_t test_vsbc_vxm_i8mf4 (vint8mf4_t op1, int8_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vsbc.vxm.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vxm_i8mf4(op1, op2, borrowin);
}

vint8mf2_t test_vsbc_vvm_i8mf2 (vint8mf2_t op1, vint8mf2_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vsbc.vvm.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vvm_i8mf2(op1, op2, borrowin);
}

vint8mf2_t test_vsbc_vxm_i8mf2 (vint8mf2_t op1, int8_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vsbc.vxm.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vxm_i8mf2(op1, op2, borrowin);
}

vint8m1_t test_vsbc_vvm_i8m1 (vint8m1_t op1, vint8m1_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vsbc.vvm.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vvm_i8m1(op1, op2, borrowin);
}

vint8m1_t test_vsbc_vxm_i8m1 (vint8m1_t op1, int8_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vsbc.vxm.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vxm_i8m1(op1, op2, borrowin);
}

vint8m2_t test_vsbc_vvm_i8m2 (vint8m2_t op1, vint8m2_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vsbc.vvm.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vvm_i8m2(op1, op2, borrowin);
}

vint8m2_t test_vsbc_vxm_i8m2 (vint8m2_t op1, int8_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vsbc.vxm.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vxm_i8m2(op1, op2, borrowin);
}

vint8m4_t test_vsbc_vvm_i8m4 (vint8m4_t op1, vint8m4_t op2, vbool2_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vsbc.vvm.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vsbc_vvm_i8m4(op1, op2, borrowin);
}

vint8m4_t test_vsbc_vxm_i8m4 (vint8m4_t op1, int8_t op2, vbool2_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vsbc.vxm.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vsbc_vxm_i8m4(op1, op2, borrowin);
}

vint8m8_t test_vsbc_vvm_i8m8 (vint8m8_t op1, vint8m8_t op2, vbool1_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vsbc.vvm.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return vsbc_vvm_i8m8(op1, op2, borrowin);
}

vint8m8_t test_vsbc_vxm_i8m8 (vint8m8_t op1, int8_t op2, vbool1_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vsbc.vxm.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return vsbc_vxm_i8m8(op1, op2, borrowin);
}

vint16mf4_t test_vsbc_vvm_i16mf4 (vint16mf4_t op1, vint16mf4_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vsbc.vvm.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vvm_i16mf4(op1, op2, borrowin);
}

vint16mf4_t test_vsbc_vxm_i16mf4 (vint16mf4_t op1, int16_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vsbc.vxm.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vxm_i16mf4(op1, op2, borrowin);
}

vint16mf2_t test_vsbc_vvm_i16mf2 (vint16mf2_t op1, vint16mf2_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vsbc.vvm.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vvm_i16mf2(op1, op2, borrowin);
}

vint16mf2_t test_vsbc_vxm_i16mf2 (vint16mf2_t op1, int16_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vsbc.vxm.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vxm_i16mf2(op1, op2, borrowin);
}

vint16m1_t test_vsbc_vvm_i16m1 (vint16m1_t op1, vint16m1_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vsbc.vvm.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vvm_i16m1(op1, op2, borrowin);
}

vint16m1_t test_vsbc_vxm_i16m1 (vint16m1_t op1, int16_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vsbc.vxm.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vxm_i16m1(op1, op2, borrowin);
}

vint16m2_t test_vsbc_vvm_i16m2 (vint16m2_t op1, vint16m2_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vsbc.vvm.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vvm_i16m2(op1, op2, borrowin);
}

vint16m2_t test_vsbc_vxm_i16m2 (vint16m2_t op1, int16_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vsbc.vxm.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vxm_i16m2(op1, op2, borrowin);
}

vint16m4_t test_vsbc_vvm_i16m4 (vint16m4_t op1, vint16m4_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vsbc.vvm.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vvm_i16m4(op1, op2, borrowin);
}

vint16m4_t test_vsbc_vxm_i16m4 (vint16m4_t op1, int16_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vsbc.vxm.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vxm_i16m4(op1, op2, borrowin);
}

vint16m8_t test_vsbc_vvm_i16m8 (vint16m8_t op1, vint16m8_t op2, vbool2_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vsbc.vvm.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vsbc_vvm_i16m8(op1, op2, borrowin);
}

vint16m8_t test_vsbc_vxm_i16m8 (vint16m8_t op1, int16_t op2, vbool2_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vsbc.vxm.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vsbc_vxm_i16m8(op1, op2, borrowin);
}

vint32mf2_t test_vsbc_vvm_i32mf2 (vint32mf2_t op1, vint32mf2_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vsbc.vvm.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vvm_i32mf2(op1, op2, borrowin);
}

vint32mf2_t test_vsbc_vxm_i32mf2 (vint32mf2_t op1, int32_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vsbc.vxm.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vxm_i32mf2(op1, op2, borrowin);
}

vint32m1_t test_vsbc_vvm_i32m1 (vint32m1_t op1, vint32m1_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vsbc.vvm.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vvm_i32m1(op1, op2, borrowin);
}

vint32m1_t test_vsbc_vxm_i32m1 (vint32m1_t op1, int32_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vsbc.vxm.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vxm_i32m1(op1, op2, borrowin);
}

vint32m2_t test_vsbc_vvm_i32m2 (vint32m2_t op1, vint32m2_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vsbc.vvm.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vvm_i32m2(op1, op2, borrowin);
}

vint32m2_t test_vsbc_vxm_i32m2 (vint32m2_t op1, int32_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vsbc.vxm.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vxm_i32m2(op1, op2, borrowin);
}

vint32m4_t test_vsbc_vvm_i32m4 (vint32m4_t op1, vint32m4_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vsbc.vvm.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vvm_i32m4(op1, op2, borrowin);
}

vint32m4_t test_vsbc_vxm_i32m4 (vint32m4_t op1, int32_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vsbc.vxm.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vxm_i32m4(op1, op2, borrowin);
}

vint32m8_t test_vsbc_vvm_i32m8 (vint32m8_t op1, vint32m8_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vsbc.vvm.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vvm_i32m8(op1, op2, borrowin);
}

vint32m8_t test_vsbc_vxm_i32m8 (vint32m8_t op1, int32_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vsbc.vxm.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vxm_i32m8(op1, op2, borrowin);
}

vint64m1_t test_vsbc_vvm_i64m1 (vint64m1_t op1, vint64m1_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsbc.vvm.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vvm_i64m1(op1, op2, borrowin);
}

vint64m1_t test_vsbc_vxm_i64m1 (vint64m1_t op1, int64_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsbc.vxm.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vxm_i64m1(op1, op2, borrowin);
}

vint64m2_t test_vsbc_vvm_i64m2 (vint64m2_t op1, vint64m2_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vsbc.vvm.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vvm_i64m2(op1, op2, borrowin);
}

vint64m2_t test_vsbc_vxm_i64m2 (vint64m2_t op1, int64_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vsbc.vxm.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vxm_i64m2(op1, op2, borrowin);
}

vint64m4_t test_vsbc_vvm_i64m4 (vint64m4_t op1, vint64m4_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vsbc.vvm.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vvm_i64m4(op1, op2, borrowin);
}

vint64m4_t test_vsbc_vxm_i64m4 (vint64m4_t op1, int64_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vsbc.vxm.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vxm_i64m4(op1, op2, borrowin);
}

vint64m8_t test_vsbc_vvm_i64m8 (vint64m8_t op1, vint64m8_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vsbc.vvm.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vvm_i64m8(op1, op2, borrowin);
}

vint64m8_t test_vsbc_vxm_i64m8 (vint64m8_t op1, int64_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vsbc.vxm.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vxm_i64m8(op1, op2, borrowin);
}

vuint8mf8_t test_vsbc_vvm_u8mf8 (vuint8mf8_t op1, vuint8mf8_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vsbc.vvm.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vvm_u8mf8(op1, op2, borrowin);
}

vuint8mf8_t test_vsbc_vxm_u8mf8 (vuint8mf8_t op1, uint8_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vsbc.vxm.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vxm_u8mf8(op1, op2, borrowin);
}

vuint8mf4_t test_vsbc_vvm_u8mf4 (vuint8mf4_t op1, vuint8mf4_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vsbc.vvm.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vvm_u8mf4(op1, op2, borrowin);
}

vuint8mf4_t test_vsbc_vxm_u8mf4 (vuint8mf4_t op1, uint8_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vsbc.vxm.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vxm_u8mf4(op1, op2, borrowin);
}

vuint8mf2_t test_vsbc_vvm_u8mf2 (vuint8mf2_t op1, vuint8mf2_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vsbc.vvm.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vvm_u8mf2(op1, op2, borrowin);
}

vuint8mf2_t test_vsbc_vxm_u8mf2 (vuint8mf2_t op1, uint8_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vsbc.vxm.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vxm_u8mf2(op1, op2, borrowin);
}

vuint8m1_t test_vsbc_vvm_u8m1 (vuint8m1_t op1, vuint8m1_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vsbc.vvm.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vvm_u8m1(op1, op2, borrowin);
}

vuint8m1_t test_vsbc_vxm_u8m1 (vuint8m1_t op1, uint8_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vsbc.vxm.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vxm_u8m1(op1, op2, borrowin);
}

vuint8m2_t test_vsbc_vvm_u8m2 (vuint8m2_t op1, vuint8m2_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vsbc.vvm.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vvm_u8m2(op1, op2, borrowin);
}

vuint8m2_t test_vsbc_vxm_u8m2 (vuint8m2_t op1, uint8_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vsbc.vxm.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vxm_u8m2(op1, op2, borrowin);
}

vuint8m4_t test_vsbc_vvm_u8m4 (vuint8m4_t op1, vuint8m4_t op2, vbool2_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vsbc.vvm.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vsbc_vvm_u8m4(op1, op2, borrowin);
}

vuint8m4_t test_vsbc_vxm_u8m4 (vuint8m4_t op1, uint8_t op2, vbool2_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vsbc.vxm.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vsbc_vxm_u8m4(op1, op2, borrowin);
}

vuint8m8_t test_vsbc_vvm_u8m8 (vuint8m8_t op1, vuint8m8_t op2, vbool1_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vsbc.vvm.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return vsbc_vvm_u8m8(op1, op2, borrowin);
}

vuint8m8_t test_vsbc_vxm_u8m8 (vuint8m8_t op1, uint8_t op2, vbool1_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vsbc.vxm.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return vsbc_vxm_u8m8(op1, op2, borrowin);
}

vuint16mf4_t test_vsbc_vvm_u16mf4 (vuint16mf4_t op1, vuint16mf4_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vsbc.vvm.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vvm_u16mf4(op1, op2, borrowin);
}

vuint16mf4_t test_vsbc_vxm_u16mf4 (vuint16mf4_t op1, uint16_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vsbc.vxm.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vxm_u16mf4(op1, op2, borrowin);
}

vuint16mf2_t test_vsbc_vvm_u16mf2 (vuint16mf2_t op1, vuint16mf2_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vsbc.vvm.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vvm_u16mf2(op1, op2, borrowin);
}

vuint16mf2_t test_vsbc_vxm_u16mf2 (vuint16mf2_t op1, uint16_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vsbc.vxm.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vxm_u16mf2(op1, op2, borrowin);
}

vuint16m1_t test_vsbc_vvm_u16m1 (vuint16m1_t op1, vuint16m1_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vsbc.vvm.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vvm_u16m1(op1, op2, borrowin);
}

vuint16m1_t test_vsbc_vxm_u16m1 (vuint16m1_t op1, uint16_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vsbc.vxm.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vxm_u16m1(op1, op2, borrowin);
}

vuint16m2_t test_vsbc_vvm_u16m2 (vuint16m2_t op1, vuint16m2_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vsbc.vvm.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vvm_u16m2(op1, op2, borrowin);
}

vuint16m2_t test_vsbc_vxm_u16m2 (vuint16m2_t op1, uint16_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vsbc.vxm.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vxm_u16m2(op1, op2, borrowin);
}

vuint16m4_t test_vsbc_vvm_u16m4 (vuint16m4_t op1, vuint16m4_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vsbc.vvm.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vvm_u16m4(op1, op2, borrowin);
}

vuint16m4_t test_vsbc_vxm_u16m4 (vuint16m4_t op1, uint16_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vsbc.vxm.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vxm_u16m4(op1, op2, borrowin);
}

vuint16m8_t test_vsbc_vvm_u16m8 (vuint16m8_t op1, vuint16m8_t op2, vbool2_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vsbc.vvm.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vsbc_vvm_u16m8(op1, op2, borrowin);
}

vuint16m8_t test_vsbc_vxm_u16m8 (vuint16m8_t op1, uint16_t op2, vbool2_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vsbc.vxm.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vsbc_vxm_u16m8(op1, op2, borrowin);
}

vuint32mf2_t test_vsbc_vvm_u32mf2 (vuint32mf2_t op1, vuint32mf2_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vsbc.vvm.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vvm_u32mf2(op1, op2, borrowin);
}

vuint32mf2_t test_vsbc_vxm_u32mf2 (vuint32mf2_t op1, uint32_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vsbc.vxm.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vxm_u32mf2(op1, op2, borrowin);
}

vuint32m1_t test_vsbc_vvm_u32m1 (vuint32m1_t op1, vuint32m1_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vsbc.vvm.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vvm_u32m1(op1, op2, borrowin);
}

vuint32m1_t test_vsbc_vxm_u32m1 (vuint32m1_t op1, uint32_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vsbc.vxm.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vxm_u32m1(op1, op2, borrowin);
}

vuint32m2_t test_vsbc_vvm_u32m2 (vuint32m2_t op1, vuint32m2_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vsbc.vvm.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vvm_u32m2(op1, op2, borrowin);
}

vuint32m2_t test_vsbc_vxm_u32m2 (vuint32m2_t op1, uint32_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vsbc.vxm.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vxm_u32m2(op1, op2, borrowin);
}

vuint32m4_t test_vsbc_vvm_u32m4 (vuint32m4_t op1, vuint32m4_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vsbc.vvm.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vvm_u32m4(op1, op2, borrowin);
}

vuint32m4_t test_vsbc_vxm_u32m4 (vuint32m4_t op1, uint32_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vsbc.vxm.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vxm_u32m4(op1, op2, borrowin);
}

vuint32m8_t test_vsbc_vvm_u32m8 (vuint32m8_t op1, vuint32m8_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vsbc.vvm.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vvm_u32m8(op1, op2, borrowin);
}

vuint32m8_t test_vsbc_vxm_u32m8 (vuint32m8_t op1, uint32_t op2, vbool4_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vsbc.vxm.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vsbc_vxm_u32m8(op1, op2, borrowin);
}

vuint64m1_t test_vsbc_vvm_u64m1 (vuint64m1_t op1, vuint64m1_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsbc.vvm.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vvm_u64m1(op1, op2, borrowin);
}

vuint64m1_t test_vsbc_vxm_u64m1 (vuint64m1_t op1, uint64_t op2, vbool64_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsbc.vxm.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vsbc_vxm_u64m1(op1, op2, borrowin);
}

vuint64m2_t test_vsbc_vvm_u64m2 (vuint64m2_t op1, vuint64m2_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vsbc.vvm.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vvm_u64m2(op1, op2, borrowin);
}

vuint64m2_t test_vsbc_vxm_u64m2 (vuint64m2_t op1, uint64_t op2, vbool32_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vsbc.vxm.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vsbc_vxm_u64m2(op1, op2, borrowin);
}

vuint64m4_t test_vsbc_vvm_u64m4 (vuint64m4_t op1, vuint64m4_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vsbc.vvm.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vvm_u64m4(op1, op2, borrowin);
}

vuint64m4_t test_vsbc_vxm_u64m4 (vuint64m4_t op1, uint64_t op2, vbool16_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vsbc.vxm.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vsbc_vxm_u64m4(op1, op2, borrowin);
}

vuint64m8_t test_vsbc_vvm_u64m8 (vuint64m8_t op1, vuint64m8_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vvm_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vsbc.vvm.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vvm_u64m8(op1, op2, borrowin);
}

vuint64m8_t test_vsbc_vxm_u64m8 (vuint64m8_t op1, uint64_t op2, vbool8_t borrowin) {
  // CHECK-LABEL: test_vsbc_vxm_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vsbc.vxm.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vsbc_vxm_u64m8(op1, op2, borrowin);
}


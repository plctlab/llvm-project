// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -O3 -emit-llvm  %s -o - |  FileCheck %s
#include <riscv_vector.h>
vint8m1_t test_vadd_vv_i8m1 (vint8m1_t op1, vint8m1_t op2, size_t vl) {
  // CHECK-LABEL: test_vadd_vv_i8m1
  // CHECK: %{{.*}} = tail call i64 @llvm.riscv.vsetvl(i64 %vl, i64 0)
  // CHECK: %{{.*}} = tail call <vscale x 8 x i8> @llvm.riscv.vadd.vv.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}) 
  return vadd_vv_i8m1_vl(op1, op2, vl);
}

vint8m2_t test_vadd_vv_i8m2_m_vl(vbool4_t mask, vint8m2_t maskedoff, vint8m2_t op1, vint8m2_t op2, size_t vl) {
  // CHECK-LABEL: test_vadd_vv_i8m2_m_vl
  // CHECK: %{{.*}} = tail call i64 @llvm.riscv.vsetvl(i64 %vl, i64 1) 
  // CHECK: %{{.*}} = tail call <vscale x 16 x i8> @llvm.riscv.vadd.vv.mask.nxv16i8.nxv16i1(<vscale x 16 x i1> %mask, <vscale x 16 x i8> %maskedoff, <vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2) #2
  return vadd_vv_i8m2_m_vl (mask, maskedoff, op1, op2, vl);
}

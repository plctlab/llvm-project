// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <riscv_vector.h>

vint8m1_t __attribute__((noinline)) testmax8 (vbool8_t mask, vint8m1_t op1, vint8m1_t op2) {
  return   vmerge_vvm_i8m1(mask, op1, op2);
}

vfloat64m1_t __attribute__((noinline)) testmax (vbool64_t mask, vfloat64m1_t op1, double op2) {
  return vfmerge_vfm_f64m1(mask, op1, op2);
}

//CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmerge.vvm.nxv8i8.nxv8i1(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}) 
//CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfmerge.vfm.nxv1f64.nxv1i1.f64(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, double %{{.*}}) 

vuint64m1_t __attribute__((noinline)) testvmerge_vxm_u64m1 (vbool64_t mask, vuint64m1_t op1, uint64_t op2) {
  return vmerge_vxm_u64m1 (mask, op1, op2);
}

vfloat64m1_t __attribute__((noinline)) testvmerge_vvm_f64m1 (vbool64_t mask, vfloat64m1_t op1, vfloat64m1_t op2) {
   return vmerge_vvm_f64m1(mask, op1, op2);
}

//CHECK:  %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmerge.vxm.nxv1i64.nxv1i1.i64(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}}) 
//CHECK:  %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vmerge.vvm.nxv1f64.nxv1i1(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}) 

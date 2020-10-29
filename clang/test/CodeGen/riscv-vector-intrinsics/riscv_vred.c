// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <riscv_vector.h>


vint16m1_t __attribute__((noinline)) testvredsum_vs_i16m1_i16m1( vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  return vredsum_vs_i16m1_i16m1(dst, vector, scalar);
}

vint16m1_t __attribute__((noinline)) testvredmin_vs_i16m1_i16m1 ( vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  return vredmin_vs_i16m1_i16m1 (dst, vector, scalar);
}

vint16m1_t __attribute__((noinline)) testvredmax_vs_i16m1_i16m1 ( vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  return vredmax_vs_i16m1_i16m1 (dst, vector, scalar);
}

vfloat32m1_t __attribute__((noinline)) testvfredsum_vs_f32m1_f32m1 (vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
   return  vfredsum_vs_f32m1_f32m1(dst, vector, scalar);
}


//CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv4i16.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) 
//CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmin.vs.nxv4i16.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) 
//CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.nxv4i16.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) 
//CEHCK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfredsum.vs.nxv2f32.nxv2f32(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}) 


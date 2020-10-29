// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <riscv_vector.h>


vfloat32m1_t __attribute__((noinline)) testvfsqrt_v_f32m1 (vfloat32m1_t op1) {
   return  vfsqrt_v_f32m1(op1);
}

//CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfsqrt.v.nxv2f32(<vscale x 2 x float> %{{.*}}) 

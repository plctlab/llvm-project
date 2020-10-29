// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

#include <riscv_vector.h>



vint32m4_t  __attribute__((noinline)) testvqmaccus_vx_i32m4 (vint32m4_t acc, uint8_t op1, vint8m1_t op2) {
  return vqmaccus_vx_i32m4 (acc, op1, op2);
}

//CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vqmaccus.vx.nxv8i32.i8.nxv8i8(<vscale x 8 x i32> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i8> %{{.*}})



// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <riscv_vector.h>

vint32m1_t __attribute__((noinline)) testmax8(int32_t src) {
  return vmv_v_x_i32m1(src);
}

//CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmv.v.x.nxv2i32.i32(i32 %{{.*}}) 

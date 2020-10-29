// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <riscv_vector.h>

int32_t __attribute__((noinline)) testmax8(vint32m1_t src) {
  return vmv_x_s_i32m1_i32(src);
}

//CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.i32.nxv2i32(<vscale x 2 x i32> %{{.*}}) 

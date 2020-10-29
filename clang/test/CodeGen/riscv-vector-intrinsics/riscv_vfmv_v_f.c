// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <riscv_vector.h>

vfloat32m1_t  __attribute__((noinline)) testmax8(float src) {
  return vfmv_v_f_f32m1(src);
}


//CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmv.v.f.nxv2f32.f32(float %{{.*}})

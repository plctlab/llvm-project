// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

#include <riscv_vector.h>

float __attribute__((noinline)) testmax8(vfloat32m1_t src) {
  return vfmv_f_s_f32m1_f32(src);
}

//CHECK: %{{.*}} = call float @llvm.riscv.vfmv.f.s.f32.nxv2f32(<vscale x 2 x float> %{{.*}})

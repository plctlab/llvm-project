// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <riscv_vector.h>

vint16m1_t  __attribute__((noinline)) reinterpret_i8_i16(vint8m1_t value1) {
  return vreinterpret_v_i16m1_i8m1(value1);
}
//CHECK: %{{.*}} = bitcast <vscale x 8 x i8> %{{.*}} to <vscale x 4 x i16>


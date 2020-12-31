// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <riscv_vector.h>

vint32m1_t testmax8 () {
  return vundefined_i32m1();
}

// CHECK: ret <vscale x 2 x i32> undef


// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

size_t test_vreadvl () {
  // CHECK-LABEL: test_vreadvl
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vreadvl.{{.*}}()
  return vreadvl(();
}


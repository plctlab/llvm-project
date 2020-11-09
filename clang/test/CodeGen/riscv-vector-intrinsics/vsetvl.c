// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

size_t test_vsetvl_e8mf8 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e8mf8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e8mf8.{{.*}}(i64 %{{.*}})
  return vsetvl_e8mf8(avl);
}

size_t test_vsetvl_e8mf4 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e8mf4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e8mf4.{{.*}}(i64 %{{.*}})
  return vsetvl_e8mf4(avl);
}

size_t test_vsetvl_e8mf2 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e8mf2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e8mf2.{{.*}}(i64 %{{.*}})
  return vsetvl_e8mf2(avl);
}

size_t test_vsetvl_e8m1 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e8m1
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e8m1.{{.*}}(i64 %{{.*}})
  return vsetvl_e8m1(avl);
}

size_t test_vsetvl_e8m2 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e8m2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e8m2.{{.*}}(i64 %{{.*}})
  return vsetvl_e8m2(avl);
}

size_t test_vsetvl_e8m4 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e8m4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e8m4.{{.*}}(i64 %{{.*}})
  return vsetvl_e8m4(avl);
}

size_t test_vsetvl_e8m8 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e8m8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e8m8.{{.*}}(i64 %{{.*}})
  return vsetvl_e8m8(avl);
}

size_t test_vsetvl_e16mf4 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e16mf4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e16mf4.{{.*}}(i64 %{{.*}})
  return vsetvl_e16mf4(avl);
}

size_t test_vsetvl_e16mf2 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e16mf2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e16mf2.{{.*}}(i64 %{{.*}})
  return vsetvl_e16mf2(avl);
}

size_t test_vsetvl_e16m1 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e16m1
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e16m1.{{.*}}(i64 %{{.*}})
  return vsetvl_e16m1(avl);
}

size_t test_vsetvl_e16m2 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e16m2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e16m2.{{.*}}(i64 %{{.*}})
  return vsetvl_e16m2(avl);
}

size_t test_vsetvl_e16m4 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e16m4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e16m4.{{.*}}(i64 %{{.*}})
  return vsetvl_e16m4(avl);
}

size_t test_vsetvl_e16m8 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e16m8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e16m8.{{.*}}(i64 %{{.*}})
  return vsetvl_e16m8(avl);
}

size_t test_vsetvl_e32mf2 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e32mf2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e32mf2.{{.*}}(i64 %{{.*}})
  return vsetvl_e32mf2(avl);
}

size_t test_vsetvl_e32m1 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e32m1
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e32m1.{{.*}}(i64 %{{.*}})
  return vsetvl_e32m1(avl);
}

size_t test_vsetvl_e32m2 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e32m2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e32m2.{{.*}}(i64 %{{.*}})
  return vsetvl_e32m2(avl);
}

size_t test_vsetvl_e32m4 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e32m4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e32m4.{{.*}}(i64 %{{.*}})
  return vsetvl_e32m4(avl);
}

size_t test_vsetvl_e32m8 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e32m8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e32m8.{{.*}}(i64 %{{.*}})
  return vsetvl_e32m8(avl);
}

size_t test_vsetvl_e64m1 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e64m1
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e64m1.{{.*}}(i64 %{{.*}})
  return vsetvl_e64m1(avl);
}

size_t test_vsetvl_e64m2 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e64m2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e64m2.{{.*}}(i64 %{{.*}})
  return vsetvl_e64m2(avl);
}

size_t test_vsetvl_e64m4 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e64m4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e64m4.{{.*}}(i64 %{{.*}})
  return vsetvl_e64m4(avl);
}

size_t test_vsetvl_e64m8 (size_t avl) {
  // CHECK-LABEL: test_vsetvl_e64m8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl.e64m8.{{.*}}(i64 %{{.*}})
  return vsetvl_e64m8(avl);
}


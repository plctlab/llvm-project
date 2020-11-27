// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

size_t test_vsetvlmax_e8mf8 () {
  // CHECK-LABEL: test_vsetvlmax_e8mf8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e8mf8();
}

size_t test_vsetvlmax_e8mf4 () {
  // CHECK-LABEL: test_vsetvlmax_e8mf4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e8mf4();
}

size_t test_vsetvlmax_e8mf2 () {
  // CHECK-LABEL: test_vsetvlmax_e8mf2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e8mf2();
}

size_t test_vsetvlmax_e8m1 () {
  // CHECK-LABEL: test_vsetvlmax_e8m1
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e8m1();
}

size_t test_vsetvlmax_e8m2 () {
  // CHECK-LABEL: test_vsetvlmax_e8m2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e8m2();
}

size_t test_vsetvlmax_e8m4 () {
  // CHECK-LABEL: test_vsetvlmax_e8m4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e8m4();
}

size_t test_vsetvlmax_e8m8 () {
  // CHECK-LABEL: test_vsetvlmax_e8m8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e8m8();
}

size_t test_vsetvlmax_e16mf4 () {
  // CHECK-LABEL: test_vsetvlmax_e16mf4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e16mf4();
}

size_t test_vsetvlmax_e16mf2 () {
  // CHECK-LABEL: test_vsetvlmax_e16mf2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e16mf2();
}

size_t test_vsetvlmax_e16m1 () {
  // CHECK-LABEL: test_vsetvlmax_e16m1
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e16m1();
}

size_t test_vsetvlmax_e16m2 () {
  // CHECK-LABEL: test_vsetvlmax_e16m2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e16m2();
}

size_t test_vsetvlmax_e16m4 () {
  // CHECK-LABEL: test_vsetvlmax_e16m4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e16m4();
}

size_t test_vsetvlmax_e16m8 () {
  // CHECK-LABEL: test_vsetvlmax_e16m8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e16m8();
}

size_t test_vsetvlmax_e32mf2 () {
  // CHECK-LABEL: test_vsetvlmax_e32mf2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e32mf2();
}

size_t test_vsetvlmax_e32m1 () {
  // CHECK-LABEL: test_vsetvlmax_e32m1
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e32m1();
}

size_t test_vsetvlmax_e32m2 () {
  // CHECK-LABEL: test_vsetvlmax_e32m2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e32m2();
}

size_t test_vsetvlmax_e32m4 () {
  // CHECK-LABEL: test_vsetvlmax_e32m4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e32m4();
}

size_t test_vsetvlmax_e32m8 () {
  // CHECK-LABEL: test_vsetvlmax_e32m8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e32m8();
}

size_t test_vsetvlmax_e64m1 () {
  // CHECK-LABEL: test_vsetvlmax_e64m1
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e64m1();
}

size_t test_vsetvlmax_e64m2 () {
  // CHECK-LABEL: test_vsetvlmax_e64m2
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e64m2();
}

size_t test_vsetvlmax_e64m4 () {
  // CHECK-LABEL: test_vsetvlmax_e64m4
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e64m4();
}

size_t test_vsetvlmax_e64m8 () {
  // CHECK-LABEL: test_vsetvlmax_e64m8
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vsetvl(i64 {{.*}}, i64 {{.*}})
  return vsetvlmax_e64m8();
}


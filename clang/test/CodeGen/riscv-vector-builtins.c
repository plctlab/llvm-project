// RUN: %clang_cc1 -triple riscv32 -O1 -emit-llvm %s -o - \
// RUN:   | FileCheck %s -check-prefix=RV32V

// This test shows that `vsetvl_e8m1' is appropriately expanded to `vsetvl'.

#include <riscv_vector.h>

_VL_T test_vsetvl_e8m1(size_t rvl) {
  // RV32V: %call = tail call fastcc i32 @vsetvl_e8m1(i32 %rvl)
  // RV32V: ret i32 %call
    return vsetvl_e8m1(rvl);
}

// RV32V:   %0 = tail call i32 @llvm.riscv.vsetvl(i32 %avl, i32 9)



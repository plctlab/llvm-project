// RUN: %clang_cc1 -triple riscv32 -target-feature +experimental-k -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV32ZKN

// Fixme: delete this line when rvintrin.h is available. 
#define RVINTRIN_RV32

#include <rvkintrin.h>

// RV32ZKN-LABEL: i32 @test_rv_sm3p0(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv_sm3p0(i32 [[TMP0]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
long test_rv_sm3p0(long rs1){
    return _rv_sm3p0(rs1);
}

// RV32ZKN-LABEL: i32 @test_rv_sm3p1(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv_sm3p1(i32 [[TMP0]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
long test_rv_sm3p1(long rs1){
    return _rv_sm3p1(rs1);
}

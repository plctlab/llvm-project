// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-k -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV64ZKN

// Fixme: delete this line when rvintrin.h is available. 
#define RVINTRIN_RV64

#include <rvkintrin.h>

// RV64ZKN-LABEL: i64 @test_rv_sm3p0(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv_sm3p0(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
long test_rv_sm3p0(long rs1){
    return _rv_sm3p0(rs1);
}

// RV64ZKN-LABEL: i64 @test_rv_sm3p1(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv_sm3p1(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
long test_rv_sm3p1(long rs1){
    return _rv_sm3p1(rs1);
}

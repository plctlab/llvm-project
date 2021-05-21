// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-zksed -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV64ZKN

// Fixme: delete this line when rvintrin.h is available. 
#define RVINTRIN_RV64

#include <rvkintrin.h>

// RV32ZKN-LABEL: i64 @test_rv_sm4ks(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i64, align 4
// RV32ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i64 [[RS2:%.*]], i64* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i64, i64* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv_sm4ks(i64 [[TMP0]], i64 [[TMP1]], i64 0)
// RV32ZKN-NEXT:  ret i64 [[CALL]]
long test_rv_sm4ks(long rs1, long rs2){
    return _rv_sm4ks(rs1, rs2, 0);
}

// RV32ZKN-LABEL: i64 @test_rv_sm4ed(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i64, align 4
// RV32ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i64 [[RS2:%.*]], i64* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i64, i64* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv_sm4ed(i64 [[TMP0]], i64 [[TMP1]], i64 0)
// RV32ZKN-NEXT:  ret i64 [[CALL]]
long test_rv_sm4ed (long rs1, long rs2){
    return _rv_sm4ed (rs1, rs2, 0);
}

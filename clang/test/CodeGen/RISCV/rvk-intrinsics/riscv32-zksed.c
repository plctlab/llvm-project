// RUN: %clang_cc1 -triple riscv32 -target-feature +experimental-k -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV32ZKN

// Fixme: delete this line when rvintrin.h is available. 
#define RVINTRIN_RV32

#include <rvkintrin.h>

// RV32ZKN-LABEL: i32 @test_rv_sm4ks(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv_sm4ks(i32 [[TMP0]], i32 [[TMP1]], i8 zeroext 0)
// RV32ZKN-NEXT:  ret i32 [[CALL]]
long test_rv_sm4ks(long rs1, long rs2){
    return _rv_sm4ks(rs1, rs2, 0);
}

// RV32ZKN-LABEL: i32 @test_rv_sm4ed(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv_sm4ed(i32 [[TMP0]], i32 [[TMP1]], i8 zeroext 0)
// RV32ZKN-NEXT:  ret i32 [[CALL]]
long test_rv_sm4ed (long rs1, long rs2){
    return _rv_sm4ed (rs1, rs2, 0);
}

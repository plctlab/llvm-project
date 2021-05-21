// RUN: %clang_cc1 -triple riscv32 -target-feature +experimental-zkne -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV32ZKN

// Fixme: delete this line when rvintrin.h is available. 
#define RVINTRIN_RV32

#include <rvkintrin.h>

// RV32ZKN-LABEL: i32 @test_rv32_aes32esi(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_aes32esi(i32 [[TMP0]], i32 [[TMP1]], i8 zeroext 3)
// RV32ZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_aes32esi(int32_t rs1, int32_t rs2){
    return _rv32_aes32esi(rs1,rs2,3);
}

// RV32ZKN-LABEL: i32 @test_rv32_aes32esmi(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_aes32esmi(i32 [[TMP0]], i32 [[TMP1]], i8 zeroext 3)
// RV32ZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_aes32esmi(int32_t rs1, int32_t rs2){
    return _rv32_aes32esmi(rs1,rs2,3);
}

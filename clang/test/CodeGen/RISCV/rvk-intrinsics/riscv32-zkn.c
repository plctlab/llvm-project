// RUN: %clang_cc1 -triple riscv32 -target-feature +experimental-k -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RVZKN

#include <rvkintrin.h>

// RVZKN-LABEL: i32 @test_rv32_sha512sig0l(
// RVZKN-NEXT:  entry:
// RVZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sig0l(i32 [[TMP0]], i32 [[TMP1]])
// RVZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sig0l(int32_t rs1, int32_t rs2){
    return _rv32_sha512sig0l(rs1,rs2);
}

// RVZKN-LABEL: i32 @test_rv32_sha512sig0h(
// RVZKN-NEXT:  entry:
// RVZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sig0h(i32 [[TMP0]], i32 [[TMP1]])
// RVZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sig0h(int32_t rs1, int32_t rs2){
    return _rv32_sha512sig0h(rs1,rs2);
}

// RVZKN-LABEL: i32 @test_rv32_sha512sig1h(
// RVZKN-NEXT:  entry:
// RVZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sig1h(i32 [[TMP0]], i32 [[TMP1]])
// RVZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sig1h(int32_t rs1, int32_t rs2){
    return _rv32_sha512sig1h(rs1,rs2);
}

// RVZKN-LABEL: i32 @test_rv32_sha512sig1l(
// RVZKN-NEXT:  entry:
// RVZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sig1l(i32 [[TMP0]], i32 [[TMP1]])
// RVZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sig1l(int32_t rs1, int32_t rs2){
    return _rv32_sha512sig1l(rs1,rs2);
}

// RVZKN-LABEL: i32 @test_rv32_sha512sum0r(
// RVZKN-NEXT:  entry:
// RVZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sum0r(i32 [[TMP0]], i32 [[TMP1]])
// RVZKN-NEXT:  ret i32 [[CALL]]
long test_rv32_sha512sum0r(int32_t rs1,int32_t rs2){
    return _rv32_sha512sum0r(rs1,rs2);
}


// RVZKN-LABEL: i32 @test_rv32_sha512sum1r(
// RVZKN-NEXT:  entry:
// RVZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RVZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RVZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RVZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sum1r(i32 [[TMP0]], i32 [[TMP1]])
// RVZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sum1r(int32_t rs1, int32_t rs2){
    return _rv32_sha512sum1r(rs1, rs2);
}
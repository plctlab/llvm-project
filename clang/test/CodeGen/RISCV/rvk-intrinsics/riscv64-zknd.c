// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-zknd -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV64ZKN

// Fixme: delete this line when rvintrin.h is available. 
#define RVINTRIN_RV64

#include <rvkintrin.h>

// RV64ZKN-LABEL: i64 @test_rv64_aes64dsm(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  store i64 [[RS2:%.*]], i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP1:%.*]] = load i64, i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_aes64dsm(i64 [[TMP0]], i64 [[TMP1]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_aes64dsm(int64_t rs1, int64_t rs2){
    return _rv64_aes64dsm(rs1,rs2);
}

// RV64ZKN-LABEL: i64 @test_rv64_aes64ds(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  store i64 [[RS2:%.*]], i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP1:%.*]] = load i64, i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_aes64ds(i64 [[TMP0]], i64 [[TMP1]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_aes64ds(int64_t rs1, int64_t rs2){
    return _rv64_aes64ds(rs1,rs2);
}

// RV64ZKN-LABEL: i64 @test_rv64_aes64im(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_aes64im(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_aes64im(int64_t rs1){
    return _rv64_aes64im(rs1);
}

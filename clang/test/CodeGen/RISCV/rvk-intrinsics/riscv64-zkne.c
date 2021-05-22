// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-k -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV64ZKN

// Fixme: delete this line when rvintrin.h is available. 
#define RVINTRIN_RV64

#include <rvkintrin.h>

// RV64ZKN-LABEL: i64 @test_rv64_aes64es(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  store i64 [[RS2:%.*]], i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP1:%.*]] = load i64, i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_aes64es(i64 [[TMP0]], i64 [[TMP1]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_aes64es(int64_t rs1, int64_t rs2){
    return _rv64_aes64es(rs1,rs2);
}

// RV64ZKN-LABEL: i64 @test_rv64_aes64esm(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  store i64 [[RS2:%.*]], i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP1:%.*]] = load i64, i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_aes64esm(i64 [[TMP0]], i64 [[TMP1]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_aes64esm(int64_t rs1, int64_t rs2){
    return _rv64_aes64esm(rs1,rs2);
}

// RV64ZKN-LABEL: i64 @test_rv64_aes64ks1i(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_aes64ks1i(i64 [[TMP0]], i64 0)
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_aes64ks1i(int64_t rs1){
    return _rv64_aes64ks1i(rs1,0);
}

// RV64ZKN-LABEL: i64 @test_rv64_aes64ks2(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  store i64 [[RS2:%.*]], i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP1:%.*]] = load i64, i64* [[RS2_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_aes64ks2(i64 [[TMP0]], i64 [[TMP1]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_aes64ks2(int64_t rs1, int64_t rs2){
    return _rv64_aes64ks2(rs1, rs2);
}

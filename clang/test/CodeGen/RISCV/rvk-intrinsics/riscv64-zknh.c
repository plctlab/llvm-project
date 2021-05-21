// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-zknh -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV64ZKN

// Fixme: delete this line when rvintrin.h is available. 
#define RVINTRIN_RV64

#include <rvkintrin.h>

// RV64ZKN-LABEL: i64 @test_rv64_sha512sig0(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_sha512sig0(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_sha512sig0(int64_t rs1){
    return _rv64_sha512sig0(rs1);
}

// RV64ZKN-LABEL: i64 @test_rv64_sha512sig1(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_sha512sig1(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_sha512sig1(int64_t rs1){
    return _rv64_sha512sig1(rs1);
}

// RV64ZKN-LABEL: i64 @test_rv64_sha512sum0(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_sha512sum0(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_sha512sum0(int64_t rs1){
    return _rv64_sha512sum0(rs1);
}

// RV64ZKN-LABEL: i64 @test_rv64_sha512sum1(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv64_sha512sum1(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
int64_t test_rv64_sha512sum1(int64_t rs1){
    return _rv64_sha512sum1(rs1);
}

// RV64ZKN-LABEL: i64 @test_rv_sha256sig0(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv_sha256sig0(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
long test_rv_sha256sig0(long rs1){
    return _rv_sha256sig0(rs1);
}

// RV64ZKN-LABEL: i64 @test_rv_sha256sig1(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv_sha256sig1(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
long test_rv_sha256sig1(long rs1){
    return _rv_sha256sig1(rs1);
}

// RV64ZKN-LABEL: i64 @test_rv_sha256sum0(
// RV64ZKN-NEXT:  entry:
// RV64ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i64, align 8
// RV64ZKN-NEXT:  store i64 [[RS1:%.*]], i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[TMP0:%.*]] = load i64, i64* [[RS1_ADDR]], align 8
// RV64ZKN-NEXT:  [[CALL:%.*]] = call i64 @_rv_sha256sum0(i64 [[TMP0]])
// RV64ZKN-NEXT:  ret i64 [[CALL]]
long test_rv_sha256sum0(long rs1){
    return _rv_sha256sum0(rs1);
}

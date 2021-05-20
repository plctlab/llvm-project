// RUN: %clang_cc1 -triple riscv32 -target-feature +experimental-k -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV32ZKN

// Fixme: delete this line when rvintrin.h is available. 
#define RVINTRIN_RV32

#include <rvkintrin.h>

// RV32ZKN-LABEL: i32 @test_rv32_aes32dsi(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_aes32dsi(i32 [[TMP0]], i32 [[TMP1]], i8 zeroext 3)
// RV32ZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_aes32dsi(int32_t rs1, int32_t rs2){
    return _rv32_aes32dsi(rs1,rs2,3);
}

// RV32ZKN-LABEL: i32 @test_rv32_aes32dsmi(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_aes32dsmi(i32 [[TMP0]], i32 [[TMP1]], i8 zeroext 3)
// RV32ZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_aes32dsmi(int32_t rs1, int32_t rs2){
    return _rv32_aes32dsmi(rs1,rs2,3);
}

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

// RV32ZKN-LABEL: i32 @test_rv32_sha512sig0l(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sig0l(i32 [[TMP0]], i32 [[TMP1]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sig0l(int32_t rs1, int32_t rs2){
    return _rv32_sha512sig0l(rs1,rs2);
}

// RV32ZKN-LABEL: i32 @test_rv32_sha512sig0h(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sig0h(i32 [[TMP0]], i32 [[TMP1]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sig0h(int32_t rs1, int32_t rs2){
    return _rv32_sha512sig0h(rs1,rs2);
}

// RV32ZKN-LABEL: i32 @test_rv32_sha512sig1h(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sig1h(i32 [[TMP0]], i32 [[TMP1]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sig1h(int32_t rs1, int32_t rs2){
    return _rv32_sha512sig1h(rs1,rs2);
}

// RV32ZKN-LABEL: i32 @test_rv32_sha512sig1l(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sig1l(i32 [[TMP0]], i32 [[TMP1]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sig1l(int32_t rs1, int32_t rs2){
    return _rv32_sha512sig1l(rs1,rs2);
}

// RV32ZKN-LABEL: i32 @test_rv32_sha512sum0r(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sum0r(i32 [[TMP0]], i32 [[TMP1]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
long test_rv32_sha512sum0r(int32_t rs1,int32_t rs2){
    return _rv32_sha512sum0r(rs1,rs2);
}


// RV32ZKN-LABEL: i32 @test_rv32_sha512sum1r(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  [[RS2_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  store i32 [[RS2:%.*]], i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP1:%.*]] = load i32, i32* [[RS2_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv32_sha512sum1r(i32 [[TMP0]], i32 [[TMP1]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
int32_t test_rv32_sha512sum1r(int32_t rs1, int32_t rs2){
    return _rv32_sha512sum1r(rs1, rs2);
}

// RV32ZKN-LABEL: i32 @test_rv_sha256sig0(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv_sha256sig0(i32 [[TMP0]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
long test_rv_sha256sig0(long rs1){
    return _rv_sha256sig0(rs1);
}

// RV32ZKN-LABEL: i32 @test_rv_sha256sig1(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv_sha256sig1(i32 [[TMP0]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
long test_rv_sha256sig1(long rs1){
    return _rv_sha256sig1(rs1);
}

// RV32ZKN-LABEL: i32 @test_rv_sha256sum0(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv_sha256sum0(i32 [[TMP0]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
long test_rv_sha256sum0(long rs1){
    return _rv_sha256sum0(rs1);
}

// RV32ZKN-LABEL: i32 @test_rv_sha256sum1(
// RV32ZKN-NEXT:  entry:
// RV32ZKN-NEXT:  [[RS1_ADDR:%.*]] = alloca i32, align 4
// RV32ZKN-NEXT:  store i32 [[RS1:%.*]], i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[TMP0:%.*]] = load i32, i32* [[RS1_ADDR]], align 4
// RV32ZKN-NEXT:  [[CALL:%.*]] = call i32 @_rv_sha256sum1(i32 [[TMP0]])
// RV32ZKN-NEXT:  ret i32 [[CALL]]
long test_rv_sha256sum1(long rs1){
    return _rv_sha256sum1(rs1);
}

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

// long test_rv_sm4ks(long rs1, long rs2){
//     return _rv_sm4ks(rs1, rs2, 0);
// }

// long test_rv_sm4ed (long rs1, long rs2, uint8_t bs){
//     return _rv_sm4ed (rs1, rs2, 0);
// }

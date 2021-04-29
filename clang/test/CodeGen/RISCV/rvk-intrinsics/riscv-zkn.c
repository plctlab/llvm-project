// RUN: %clang_cc1 -triple riscv32 -target-feature +experimental-k -emit-llvm %s -o - \
// RUN:     | FileCheck %s  -check-prefix=RV32ZKN

#include <rvkintrin.h>

long test_rv_sha256sig0(long rs1){
    return _rv_sha256sig0(rs1);
}

long test_rv_sha256sig1(long rs1){
    return _rv_sha256sig1(rs1);
}

long test_rv_sha256sum0(long rs1){
    return _rv_sha256sum0(rs1);
}

long test_rv_sha256sum1(long rs1){
    return _rv_sha256sum1(rs1);
}

long test_rv_sm3p0(long rs1){
    return _rv_sm3p0(rs1);
}

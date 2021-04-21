; RUN: llc -mtriple=riscv64 -mattr=+experimental-zksh -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IK

declare i64 @llvm.riscv.sm3p0(i64);

define i64 @sm3p0(i64 %a) nounwind {
; RV64IK-LABEL: sm3p0
; RV64IK: # %bb.0:
; RV64IK-NEXT: sm3p0 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sm3p0(i64 %a)
    ret i64 %val
}

declare i64 @llvm.riscv.sm3p1(i64);

define i64 @sm3p1(i64 %a) nounwind {
; RV64IK-LABEL: sm3p1
; RV64IK: # %bb.0:
; RV64IK-NEXT: sm3p1 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sm3p1(i64 %a)
    ret i64 %val
}

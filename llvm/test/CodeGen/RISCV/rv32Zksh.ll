; RUN: llc -mtriple=riscv32 -mattr=+experimental-zksh -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IK

declare i32 @llvm.riscv.sm3p0(i32);

define i32 @sm3p0(i32 %a) nounwind {
; RV32IK-LABEL: sm3p0
; RV32IK: # %bb.0:
; RV32IK-NEXT: sm3p0 a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sm3p0(i32 %a)
    ret i32 %val
}

declare i32 @llvm.riscv.sm3p1(i32);

define i32 @sm3p1(i32 %a) nounwind {
; RV32IK-LABEL: sm3p1
; RV32IK: # %bb.0:
; RV32IK-NEXT: sm3p1 a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sm3p1(i32 %a)
    ret i32 %val
}

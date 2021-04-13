; RUN: llc -mtriple=riscv32 -mattr=+experimental-k -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IK

declare i32 @llvm.riscv.sha512sig0l(i32, i32);

define i32 @sha512sig0l(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: sha512sig0l
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha512sig0l a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha512sig0l(i32 %a, i32 %b)
    ret i32 %val
}

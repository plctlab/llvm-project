; RUN: llc -mtriple=riscv32 -mattr=+experimental-k -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IK

declare i32 @llvm.riscv.getnoise();

define i32 @getnoise() nounwind {
; RV32IK-LABEL: getnoise
; RV32IK: # %bb.0:
; RV32IK-NEXT: getnoise a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.getnoise()
    ret i32 %val
}

declare i32 @llvm.riscv.pollentropy();

define i32 @pollentropy() nounwind {
; RV32IK-LABEL: pollentropy
; RV32IK: # %bb.0:
; RV32IK-NEXT: pollentropy a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.pollentropy()
    ret i32 %val
}

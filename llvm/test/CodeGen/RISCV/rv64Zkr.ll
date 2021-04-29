; RUN: llc -mtriple=riscv64 -mattr=+experimental-k -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IK

declare i64 @llvm.riscv.getnoise();

define i64 @getnoise() nounwind {
; RV64IK-LABEL: getnoise
; RV64IK: # %bb.0:
; RV64IK-NEXT: getnoise a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.getnoise()
    ret i64 %val
}

declare i64 @llvm.riscv.pollentropy();

define i64 @pollentropy() nounwind {
; RV64IK-LABEL: pollentropy
; RV64IK: # %bb.0:
; RV64IK-NEXT: pollentropy a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.pollentropy()
    ret i64 %val
}

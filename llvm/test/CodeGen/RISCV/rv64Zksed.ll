; RUN: llc -mtriple=riscv64 -mattr=+experimental-zksed -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IK

declare i64 @llvm.riscv.sm4ks(i64, i64, i8);

define i64 @sm4ks(i64 %a, i64 %b) nounwind {
; RV64IK-LABEL: sm4ks
; RV64IK: # %bb.0:
; RV64IK-NEXT: sm4ks a{{[0-9]+}}, a{{[0-9]+}}, 0
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sm4ks(i64 %a, i64 %b, i8 0)
    ret i64 %val
}

declare i64 @llvm.riscv.sm4ed(i64, i64, i8);

define i64 @sm4ed(i64 %a, i64 %b) nounwind {
; RV64IK-LABEL: sm4ed
; RV64IK: # %bb.0:
; RV64IK-NEXT: sm4ed a{{[0-9]+}}, a{{[0-9]+}}, 1
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sm4ed(i64 %a, i64 %b, i8 1)
    ret i64 %val
}

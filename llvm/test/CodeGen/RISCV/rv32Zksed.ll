; RUN: llc -mtriple=riscv32 -mattr=+experimental-zksed -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IK

declare i32 @llvm.riscv.sm4ks(i32, i32, i8);

define i32 @sm4ks(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: sm4ks
; RV32IK: # %bb.0:
; RV32IK-NEXT: sm4ks a{{[0-9]+}}, a{{[0-9]+}}, 2
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sm4ks(i32 %a, i32 %b, i8 2)
    ret i32 %val
}

declare i32 @llvm.riscv.sm4ed(i32, i32, i8);

define i32 @sm4ed(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: sm4ed
; RV32IK: # %bb.0:
; RV32IK-NEXT: sm4ed a{{[0-9]+}}, a{{[0-9]+}}, 3
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sm4ed(i32 %a, i32 %b, i8 3)
    ret i32 %val
}

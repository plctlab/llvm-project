; RUN: llc -mtriple=riscv64 -mattr=+experimental-k -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IK

declare i64 @llvm.riscv.sha512sig0(i64);

define i64 @sha512sig0(i64 %a) nounwind {
; RV64IK-LABEL: sha512sig0
; RV64IK: # %bb.0:
; RV64IK-NEXT: sha512sig0 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sha512sig0(i64 %a)
    ret i64 %val
}

declare i64 @llvm.riscv.sha512sig1(i64);

define i64 @sha512sig1(i64 %a) nounwind {
; RV64IK-LABEL: sha512sig1
; RV64IK: # %bb.0:
; RV64IK-NEXT: sha512sig1 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sha512sig1(i64 %a)
    ret i64 %val
}

declare i64 @llvm.riscv.sha512sum0(i64);

define i64 @sha512sum0(i64 %a) nounwind {
; RV64IK-LABEL: sha512sum0
; RV64IK: # %bb.0:
; RV64IK-NEXT: sha512sum0 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sha512sum0(i64 %a)
    ret i64 %val
}

declare i64 @llvm.riscv.sha512sum1(i64);

define i64 @sha512sum1(i64 %a) nounwind {
; RV64IK-LABEL: sha512sum1
; RV64IK: # %bb.0:
; RV64IK-NEXT: sha512sum1 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sha512sum1(i64 %a)
    ret i64 %val
}

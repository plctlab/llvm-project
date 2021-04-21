; RUN: llc -mtriple=riscv64 -mattr=+experimental-k -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IK

declare i64 @llvm.riscv.aes64es(i64, i64);

define i64 @aes64es(i64 %a, i64 %b) nounwind {
; RV64IK-LABEL: aes64es
; RV64IK: # %bb.0:
; RV64IK-NEXT: aes64es a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.aes64es(i64 %a, i64 %b)
    ret i64 %val
}

declare i64 @llvm.riscv.aes64esm(i64, i64);

define i64 @aes64esm(i64 %a, i64 %b) nounwind {
; RV64IK-LABEL: aes64esm
; RV64IK: # %bb.0:
; RV64IK-NEXT: aes64esm a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.aes64esm(i64 %a, i64 %b)
    ret i64 %val
}

declare i64 @llvm.riscv.aes64ds(i64, i64);

define i64 @aes64ds(i64 %a, i64 %b) nounwind {
; RV64IK-LABEL: aes64ds
; RV64IK: # %bb.0:
; RV64IK-NEXT: aes64ds a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.aes64ds(i64 %a, i64 %b)
    ret i64 %val
}

declare i64 @llvm.riscv.aes64dsm(i64, i64);

define i64 @aes64dsm(i64 %a, i64 %b) nounwind {
; RV64IK-LABEL: aes64dsm
; RV64IK: # %bb.0:
; RV64IK-NEXT: aes64dsm a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.aes64dsm(i64 %a, i64 %b)
    ret i64 %val
}

declare i64 @llvm.riscv.aes64ks2(i64, i64);

define i64 @aes64ks2(i64 %a, i64 %b) nounwind {
; RV64IK-LABEL: aes64ks2
; RV64IK: # %bb.0:
; RV64IK-NEXT: aes64ks2 a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.aes64ks2(i64 %a, i64 %b)
    ret i64 %val
}

declare i64 @llvm.riscv.aes64im(i64);

define i64 @aes64im(i64 %a) nounwind {
; RV64IK-LABEL: aes64im
; RV64IK: # %bb.0:
; RV64IK-NEXT: aes64im a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.aes64im(i64 %a)
    ret i64 %val
}

declare i64 @llvm.riscv.sha256sig0(i64);

define i64 @sha256sig0(i64 %a) nounwind {
; RV64IK-LABEL: sha256sig0
; RV64IK: # %bb.0:
; RV64IK-NEXT: sha256sig0 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sha256sig0(i64 %a)
    ret i64 %val
}

declare i64 @llvm.riscv.sha256sig1(i64);

define i64 @sha256sig1(i64 %a) nounwind {
; RV64IK-LABEL: sha256sig1
; RV64IK: # %bb.0:
; RV64IK-NEXT: sha256sig1 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sha256sig1(i64 %a)
    ret i64 %val
}

declare i64 @llvm.riscv.sha256sum0(i64);

define i64 @sha256sum0(i64 %a) nounwind {
; RV64IK-LABEL: sha256sum0
; RV64IK: # %bb.0:
; RV64IK-NEXT: sha256sum0 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sha256sum0(i64 %a)
    ret i64 %val
}

declare i64 @llvm.riscv.sha256sum1(i64);

define i64 @sha256sum1(i64 %a) nounwind {
; RV64IK-LABEL: sha256sum1
; RV64IK: # %bb.0:
; RV64IK-NEXT: sha256sum1 a{{[0-9]+}}, a{{[0-9]+}}
; RV64IK-NEXT: ret
    %val = call i64 @llvm.riscv.sha256sum1(i64 %a)
    ret i64 %val
}

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

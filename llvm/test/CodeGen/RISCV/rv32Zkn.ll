; RUN: llc -mtriple=riscv32 -mattr=+experimental-k -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IK

declare i32 @llvm.riscv.aes32dsi(i32, i32, i32);

define i32 @aes32dsi(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: aes32dsi
; RV32IK: # %bb.0:
; RV32IK-NEXT: aes32dsi a{{[0-9]+}}, a{{[0-9]+}}, 0
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.aes32dsi(i32 %a, i32 %b, i32 0)
    ret i32 %val
}

declare i32 @llvm.riscv.aes32dsmi(i32, i32, i32);

define i32 @aes32dsmi(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: aes32dsmi
; RV32IK: # %bb.0:
; RV32IK-NEXT: aes32dsmi a{{[0-9]+}}, a{{[0-9]+}}, 1
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.aes32dsmi(i32 %a, i32 %b, i32 1)
    ret i32 %val
}

declare i32 @llvm.riscv.aes32esi(i32, i32, i32);

define i32 @aes32esi(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: aes32esi
; RV32IK: # %bb.0:
; RV32IK-NEXT: aes32esi a{{[0-9]+}}, a{{[0-9]+}}, 2
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.aes32esi(i32 %a, i32 %b, i32 2)
    ret i32 %val
}

declare i32 @llvm.riscv.aes32esmi(i32, i32, i32);

define i32 @aes32esmi(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: aes32esmi
; RV32IK: # %bb.0:
; RV32IK-NEXT: aes32esmi a{{[0-9]+}}, a{{[0-9]+}}, 3
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.aes32esmi(i32 %a, i32 %b, i32 3)
    ret i32 %val
}

declare i32 @llvm.riscv.sha256sig0(i32);

define i32 @sha256sig0(i32 %a) nounwind {
; RV32IK-LABEL: sha256sig0
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha256sig0 a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha256sig0(i32 %a)
    ret i32 %val
}

declare i32 @llvm.riscv.sha256sig1(i32);

define i32 @sha256sig1(i32 %a) nounwind {
; RV32IK-LABEL: sha256sig1
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha256sig1 a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha256sig1(i32 %a)
    ret i32 %val
}

declare i32 @llvm.riscv.sha256sum0(i32);

define i32 @sha256sum0(i32 %a) nounwind {
; RV32IK-LABEL: sha256sum0
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha256sum0 a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha256sum0(i32 %a)
    ret i32 %val
}

declare i32 @llvm.riscv.sha256sum1(i32);

define i32 @sha256sum1(i32 %a) nounwind {
; RV32IK-LABEL: sha256sum1
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha256sum1 a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha256sum1(i32 %a)
    ret i32 %val
}

declare i32 @llvm.riscv.sha512sig0l(i32, i32);

define i32 @sha512sig0l(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: sha512sig0l
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha512sig0l a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha512sig0l(i32 %a, i32 %b)
    ret i32 %val
}

declare i32 @llvm.riscv.sha512sig0h(i32, i32);

define i32 @sha512sig0h(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: sha512sig0h
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha512sig0h a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha512sig0h(i32 %a, i32 %b)
    ret i32 %val
}

declare i32 @llvm.riscv.sha512sig1l(i32, i32);

define i32 @sha512sig1l(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: sha512sig1l
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha512sig1l a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha512sig1l(i32 %a, i32 %b)
    ret i32 %val
}

declare i32 @llvm.riscv.sha512sig1h(i32, i32);

define i32 @sha512sig1h(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: sha512sig1h
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha512sig1h a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha512sig1h(i32 %a, i32 %b)
    ret i32 %val
}

declare i32 @llvm.riscv.sha512sum0r(i32, i32);

define i32 @sha512sum0r(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: sha512sum0r
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha512sum0r a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha512sum0r(i32 %a, i32 %b)
    ret i32 %val
}

declare i32 @llvm.riscv.sha512sum1r(i32, i32);

define i32 @sha512sum1r(i32 %a, i32 %b) nounwind {
; RV32IK-LABEL: sha512sum1r
; RV32IK: # %bb.0:
; RV32IK-NEXT: sha512sum1r a{{[0-9]+}}, a{{[0-9]+}}, a{{[0-9]+}}
; RV32IK-NEXT: ret
    %val = call i32 @llvm.riscv.sha512sum1r(i32 %a, i32 %b)
    ret i32 %val
}

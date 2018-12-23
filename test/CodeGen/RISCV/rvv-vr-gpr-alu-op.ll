; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc -mtriple=riscv32 -mattr=+v -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IV

declare i32 @llvm.riscv.setvl(i32)
declare <scalable 1 x i32> @llvm.riscv.vadd(<scalable 1 x i32>, <scalable 1 x i32>, i32)
declare <scalable 1 x i32> @llvm.riscv.vlw(i32*, i32)
declare i32 @llvm.riscv.vmpopcnt(<scalable 1 x i32>, i32)
declare i32 @llvm.riscv.vmfirst(<scalable 1 x i32>, i32)

; R[0..n] = A[0..n]
define i32 @foo(i32 %n, i32* %A) {
; RV32IV-LABEL: foo:
; RV32IV:       # %bb.0:
; RV32IV-NEXT:    vconfig 96
; RV32IV-NEXT:    vsetvl a0, a0
; RV32IV-NEXT:    vlw v0, 0(a1)
; RV32IV-NEXT:    vmfirst a0, v0
; RV32IV-NEXT:    vmpop a1, v0
; RV32IV-NEXT:    add a0, a1, a0
; RV32IV-NEXT:    vconfig 1
; RV32IV-NEXT:    ret
	%vl = call i32 @llvm.riscv.setvl(i32 %n)
	%v.A = call <scalable 1 x i32> @llvm.riscv.vlw(i32* %A, i32 %vl)
	%popcnt = call i32 @llvm.riscv.vmpopcnt(<scalable 1 x i32> %v.A, i32 %vl)
	%first = call i32 @llvm.riscv.vmfirst(<scalable 1 x i32> %v.A, i32 %vl)
	%sum = add i32 %popcnt, %first
	ret i32 %sum
}

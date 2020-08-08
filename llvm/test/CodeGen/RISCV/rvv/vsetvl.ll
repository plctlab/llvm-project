; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare i64 @llvm.riscv.vsetvl(i64, i64);
define i64 @vsetvl_e8m1(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e8m1
; CHECK: vsetvl a0, a0, zero
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 0)
ret i64 %a
}


define i64 @vsetvl_e8m2(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e8m2
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 1)
ret i64 %a
}


define i64 @vsetvl_e8m4(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e8m4
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 2)
ret i64 %a
}


define i64 @vsetvl_e8m8(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e8m8
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 3)
ret i64 %a
}


define i64 @vsetvl_e16m1(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e16m1
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 4)
ret i64 %a
}


define i64 @vsetvl_e16m2(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e16m2
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 5)
ret i64 %a
}


define i64 @vsetvl_e16m4(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e16m4
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 6)
ret i64 %a
}


define i64 @vsetvl_e16m8(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e16m8
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 7)
ret i64 %a
}

define i64 @vsetvl_e32m2(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e32m2
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 9)
ret i64 %a
}


define i64 @vsetvl_e32m4(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e32m4
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 10)
ret i64 %a
}


define i64 @vsetvl_e32m8(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e32m8
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 11)
ret i64 %a
}


define i64 @vsetvl_e64m1(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e64m1
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 12)
ret i64 %a
}


define i64 @vsetvl_e64m2(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e64m2
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 13)
ret i64 %a
}


define i64 @vsetvl_e64m4(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e64m4
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 14)
ret i64 %a
}


define i64 @vsetvl_e64m8(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e64m8
; CHECK: vsetvl a0, a0, a1
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 15)
ret i64 %a
}


; RUN: llc -mtriple=riscv64 -mattr=+experimental-v -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare i64 @llvm.riscv.vsetvl(i64, i64);
define i64 @vsetvl_e8m1(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e8m1
; CHECK: vsetvli	a0, a0, e8,m1,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 0)
ret i64 %a
}


define i64 @vsetvl_e8m2(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e8m2
; CHECK: a0, a0, e8,m2,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 1)
ret i64 %a
}


define i64 @vsetvl_e8m4(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e8m4
; CHECK: a0, a0, e8,m4,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 2)
ret i64 %a
}


define i64 @vsetvl_e8m8(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e8m8
; CHECK: a0, a0, e8,m8,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 3)
ret i64 %a
}


define i64 @vsetvl_e16m1(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e16m1
; CHECK: a0, a0, e16,m1,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 4)
ret i64 %a
}


define i64 @vsetvl_e16m2(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e16m2
; CHECK: a0, a0, e16,m2,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 5)
ret i64 %a
}


define i64 @vsetvl_e16m4(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e16m4
; CHECK: a0, a0, e16,m4,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 6)
ret i64 %a
}


define i64 @vsetvl_e16m8(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e16m8
; CHECK: a0, a0, e16,m8,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 7)
ret i64 %a
}

define i64 @vsetvl_e32m2(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e32m2
; CHECK: vsetvli	a0, a0, e32,m2,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 9)
ret i64 %a
}


define i64 @vsetvl_e32m4(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e32m4
; CHECK: vsetvli	a0, a0, e32,m4,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 10)
ret i64 %a
}


define i64 @vsetvl_e32m8(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e32m8
; CHECK: vsetvli	a0, a0, e32,m8,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 11)
ret i64 %a
}


define i64 @vsetvl_e64m1(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e64m1
; CHECK: vsetvli	a0, a0, e64,m1,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 12)
ret i64 %a
}


define i64 @vsetvl_e64m2(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e64m2
; CHECK: vsetvli	a0, a0, e64,m2,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 13)
ret i64 %a
}


define i64 @vsetvl_e64m4(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e64m4
; CHECK: vsetvli	a0, a0, e64,m4,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 14)
ret i64 %a
}


define i64 @vsetvl_e64m8(i64 %0) {
entry:
; CHECK-LABEL: vsetvl_e64m8
; CHECK: vsetvli	a0, a0, e64,m8,tu,mu
; CHECK: ret 
%a =  tail call i64 @llvm.riscv.vsetvl(i64 %0, i64 15)
ret i64 %a
}


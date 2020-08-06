; RUN: llc -mtriple=riscv64 -mattr=+v -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 8 x i8> @llvm.riscv.vle8.v.i8m8.p0i8(i8*);
define <vscale x 8 x i8> @vle8_v_i8m8(i8* %0) {
entry:
; CHECK-LABEL: vle8_v_i8m8
; CHECK: vle8.v v0, 0(a0)
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vle8.v.i8m8.p0i8(i8* %0)
ret <vscale x 8 x i8> %a
}
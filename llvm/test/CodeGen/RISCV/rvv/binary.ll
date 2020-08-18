; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 8 x i8> @llvm.riscv.vadd.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vadd_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vadd_vv_i8m1
; CHECK: vadd.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vadd.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}



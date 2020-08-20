; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 4 x i8> @llvm.riscv.vnsrl.wv(<vscale x 4 x i16>, <vscale x 4 x i8>);
define <vscale x 4 x i8> @vnsrl_wv(<vscale x 4 x i16> %0, <vscale x 4 x i8> %1) {
entry:
; CHECK-LABEL: vnsrl_wv
; CHECK: vnsrl.wv	v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i8> @llvm.riscv.vnsrl.wv(<vscale x 4 x i16> %0, <vscale x 4 x i8> %1)
ret <vscale x 4 x i8> %a
}
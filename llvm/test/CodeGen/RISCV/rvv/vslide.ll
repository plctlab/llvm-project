; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 4 x i16> @llvm.riscv.vslideup.vx(<vscale x 4 x i16>, <vscale x 4 x i16>, i64);
define <vscale x 4 x i16> @vslide.vx(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, i64 %2) {
entry:
; CHECK-LABEL: vslide.vx
; CHECK: vslideup.vx v16, v17, a0
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vslideup.vx(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, i64 %2)
ret <vscale x 4 x i16> %a
}
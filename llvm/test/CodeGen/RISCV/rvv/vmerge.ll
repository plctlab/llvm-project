; RUN: llc -mtriple=riscv64 -mattr=+experimental-v -mattr=+m,+f,+d,+a,+c < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x double> @llvm.riscv.vfmerge.vfm.f64m1(<vscale x 1 x i1>, <vscale x 1 x double>, double);
define <vscale x 1 x double> @vfmerge_vfm_f64m1(<vscale x 1 x i1> %0, <vscale x 1 x double> %1, double %2) {
entry:
; CHECK-LABEL: vfmerge_vfm_f64m1
; CHECK: fmv.d.x ft0, a0
; CHECK: vfmerge.vfm v16, v16, ft0, v0
%a =  tail call <vscale x 1 x double> @llvm.riscv.vfmerge.vfm.f64m1(<vscale x 1 x i1> %0, <vscale x 1 x double> %1, double %2)
ret <vscale x 1 x double> %a
}


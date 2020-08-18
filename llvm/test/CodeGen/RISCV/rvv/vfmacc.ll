; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 2 x float> @llvm.riscv.vfmacc.vf(<vscale x 2 x float>, float, <vscale x 2 x float>);
define <vscale x 2 x float> @vfmacc_vf_i32m1(<vscale x 2 x float> %0, <vscale x 2 x float> %1, float %2) {
entry:
; CHECK-LABEL: vfmacc_vf_i32m1
; CHECK: fmv.w.x ft0, a0
; CHECK: vfmacc.vf v16, ft0, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x float> @llvm.riscv.vfmacc.vf(<vscale x 2 x float> %0, float %2, <vscale x 2 x float> %1)
ret <vscale x 2 x float> %a
}
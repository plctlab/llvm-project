; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 4 x i16> @llvm.riscv.vfncvt.x.f.w.i16m1(<vscale x 4 x float>);
define <vscale x 4 x i16> @vfncvt_x_f_w_i16m1(<vscale x 4 x float> %0) {
entry:
; CHECK: vfncvt.x.f.w    v25, v16
; CHECK: vmv1r.v v16, v25
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vfncvt.x.f.w.i16m1(<vscale x 4 x float> %0)
ret <vscale x 4 x i16> %a
}

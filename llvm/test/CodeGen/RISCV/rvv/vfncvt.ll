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

declare <vscale x 8 x double> @llvm.riscv.vfwcvt.f.f.v.f64m8(<vscale x 8 x float>);
define <vscale x 8 x double> @vfwcvt_f_f_v_f64m8(<vscale x 8 x float> %0) {
entry:
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vfwcvt.f.f.v    v8, v16
; CHECK: vmv8r.v v16, v8 
%a =  tail call <vscale x 8 x double> @llvm.riscv.vfwcvt.f.f.v.f64m8(<vscale x 8 x float> %0)
ret <vscale x 8 x double> %a
}

declare <vscale x 4 x float> @llvm.riscv.vfncvt.f.xu.w.f32m2(<vscale x 4 x i64>);
define <vscale x 4 x float> @vfncvt_f_xu_w_f32m2(<vscale x 4 x i64> %0) {
entry:
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vfncvt.f.xu.w   v26, v16
; CHECK: vmv2r.v v16, v26
%a =  tail call <vscale x 4 x float> @llvm.riscv.vfncvt.f.xu.w.f32m2(<vscale x 4 x i64> %0)
ret <vscale x 4 x float> %a
}


; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv1i64.nxv1f64(<vscale x 1 x double>);
define <vscale x 1 x i64> @vfcvt_rtz_x_f_v_i64m1(<vscale x 1 x double> %0) {
entry:
; CHECK: vfcvt.rtz.x.f.v v16, v16
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv1i64.nxv1f64(<vscale x 1 x double> %0)
ret <vscale x 1 x i64> %a
}

declare <vscale x 32 x half> @llvm.riscv.vfcvt.f.x.v.f16m8(<vscale x 32 x i16>);
define <vscale x 32 x half> @vfcvt_f_x_v_f16m8(<vscale x 32 x i16> %0) {
entry:
; CHECK: vfcvt.f.x.v v16, v16
%a =  tail call <vscale x 32 x half> @llvm.riscv.vfcvt.f.x.v.f16m8(<vscale x 32 x i16> %0)
ret <vscale x 32 x half> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vfcvt.xu.f.v.u32m4(<vscale x 8 x float>);
define <vscale x 8 x i32> @vfcvt_xu_f_v_u32m4(<vscale x 8 x float> %0) {
entry:
; CHECK: vfcvt.xu.f.v    v16, v16 
%a =  tail call <vscale x 8 x i32> @llvm.riscv.vfcvt.xu.f.v.u32m4(<vscale x 8 x float> %0)
ret <vscale x 8 x i32> %a
}


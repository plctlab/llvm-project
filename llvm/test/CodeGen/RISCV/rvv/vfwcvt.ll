; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 2 x i64> @llvm.riscv.vfwcvt.x.f.v.i64m2(<vscale x 2 x float>);
define <vscale x 2 x i64> @vfwcvt_x_f_v_i64m2(<vscale x 2 x float> %0) {
entry:
; CHECK-LABEL: vfwcvt_x_f_v_i64m2
; CHECK: vfwcvt.x.f.v    v26, v16
; CHECK: vmv2r.v v16, v26
%a =  tail call <vscale x 2 x i64> @llvm.riscv.vfwcvt.x.f.v.i64m2(<vscale x 2 x float> %0)
ret <vscale x 2 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vfwcvt.xu.f.v.u64m2(<vscale x 2 x float>);
define <vscale x 2 x i64> @vfwcvt_xu_f_v_u64m2(<vscale x 2 x float> %0) {
entry:
; CHECK-LABEL: vfwcvt_xu_f_v_u64m2
; CHECK: vfwcvt.xu.f.v    v26, v16
; CHECK: vmv2r.v v16, v26
%a =  tail call <vscale x 2 x i64> @llvm.riscv.vfwcvt.xu.f.v.u64m2(<vscale x 2 x float> %0)
ret <vscale x 2 x i64> %a
}


declare <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m8(<vscale x 8 x float>);
define <vscale x 8 x i64> @vfwcvt_rtz_x_f_v_i64m8(<vscale x 8 x float> %0) {
entry:
; CHECK-LABEL: vfwcvt_rtz_x_f_v_i64m8
; CHECK: vfwcvt.rtz.x.f.v        v8, v16
; CHECK: vmv8r.v v16, v8
%a =  tail call <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m8(<vscale x 8 x float> %0)
ret <vscale x 8 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.u64m8(<vscale x 8 x float>);
define <vscale x 8 x i64> @vfwcvt_rtz_xu_f_v_u64m8(<vscale x 8 x float> %0) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u64m8
; CHECK: vfwcvt.rtz.xu.f.v        v8, v16
; CHECK: vmv8r.v v16, v8
%a =  tail call <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.u64m8(<vscale x 8 x float> %0)
ret <vscale x 8 x i64> %a
}


declare <vscale x 8 x double> @llvm.riscv.vfwcvt.f.x.v.f64m8(<vscale x 8 x i32>);
define <vscale x 8 x double> @vfwcvt_f_x_v_f64m8(<vscale x 8 x i32> %0) {
entry:
; CHECK-LABEL: vfwcvt_f_x_v_f64m8
; CHECK: vfwcvt.f.x.v    v8, v16
; CHECK: vmv8r.v v16, v8
%a =  tail call <vscale x 8 x double> @llvm.riscv.vfwcvt.f.x.v.f64m8(<vscale x 8 x i32> %0)
ret <vscale x 8 x double> %a
}

declare <vscale x 1 x double> @llvm.riscv.vfwcvt.f.xu.v.f64m1(<vscale x 1 x i32>);
define <vscale x 1 x double> @vfwcvt_f_xu_v_f64m1(<vscale x 1 x i32> %0) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f64m1
; CHECK: vfwcvt.f.xu.v   v25, v16
; CHECK: vmv1r.v v16, v25
%a =  tail call <vscale x 1 x double> @llvm.riscv.vfwcvt.f.xu.v.f64m1(<vscale x 1 x i32> %0)
ret <vscale x 1 x double> %a
}


declare <vscale x 4 x double> @llvm.riscv.vfwcvt.f.f.v.f64m4(<vscale x 4 x float>);
define <vscale x 4 x double> @vfwcvt_f_f_v_f64m4(<vscale x 4 x float> %0) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f64m4
; CHECK: vfwcvt.f.f.v    v28, v16
; CHECK: vmv4r.v v16, v28
%a =  tail call <vscale x 4 x double> @llvm.riscv.vfwcvt.f.f.v.f64m4(<vscale x 4 x float> %0)
ret <vscale x 4 x double> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vwcvt.x.x.v.i32m2(<vscale x 4 x i16>);
define <vscale x 4 x i32> @vwcvt_x_x_v_i32m2(<vscale x 4 x i16> %0) {
entry:
; CHECK: vwadd.vx        v26, v16, zero
; CHECK: vmv2r.v v16, v26
%a =  tail call <vscale x 4 x i32> @llvm.riscv.vwcvt.x.x.v.i32m2(<vscale x 4 x i16> %0)
ret <vscale x 4 x i32> %a
}


declare <vscale x 4 x i32> @llvm.riscv.vwcvt.x.x.v.mask.nxv4i32.nxv4i1.nxv4i16(<vscale x 4 x i1>, <vscale x 4 x i32>, <vscale x 4 x i16>);
define <vscale x 4 x i32> @vwcvt_x_x_v_i32m2_mask(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i16> %2) {
entry:
; CHECK:  vwcvt.x.x.v v16, v18, v0.t
%a =  tail call <vscale x 4 x i32> @llvm.riscv.vwcvt.x.x.v.mask.nxv4i32.nxv4i1.nxv4i16(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i16> %2)
ret <vscale x 4 x i32> %a
}


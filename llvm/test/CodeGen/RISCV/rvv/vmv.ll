; RUN: llc -mtriple=riscv64 -mattr=+experimental-v -mattr=+m,+f,+d,+a,+c < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare i8 @llvm.riscv.vmv.x.s(<vscale x 64 x i8>);
define i8 @vmv_x_s(<vscale x 64 x i8> %0) {
entry:
; CHECK-LABEL: vmv_x_s
; CHECK: vmv.x.s	a0, v16
; CHECK: ret 
%a =  tail call i8 @llvm.riscv.vmv.x.s(<vscale x 64 x i8> %0)
ret i8 %a
}

declare <vscale x 64 x i8> @llvm.riscv.vmv.s.x(<vscale x 64 x i8>, i64);
define <vscale x 64 x i8> @vmv_s_x(<vscale x 64 x i8> %0, i64 %1) {
entry:
; CHECK-LABEL: vmv_s_x
; CHECK: vmv.s.x v16, a0
; CHECK: ret 
%a =  tail call <vscale x 64 x i8> @llvm.riscv.vmv.s.x(<vscale x 64 x i8> %0, i64 %1)
ret <vscale x 64 x i8> %a
}

declare <vscale x 8 x float> @llvm.riscv.vfmv.s.f(<vscale x 8 x float>, float);
define <vscale x 8 x float> @vmv_s_f(<vscale x 8 x float> %0, float %1) {
entry:
; CHECK-LABEL: vmv_s_f
; CHECK: fmv.w.x ft0, a0
; CHECK: vfmv.s.f	v16, ft0
; CHECK: ret 
%a =  tail call <vscale x 8 x float> @llvm.riscv.vfmv.s.f(<vscale x 8 x float> %0, float %1)
ret <vscale x 8 x float> %a
}

declare <vscale x 8 x double> @llvm.riscv.vfmv.v.f.f64m8(double);
define <vscale x 8 x double> @vfmv_v_f_f64m8(double %0) {
entry:
; CHECK-LABEL: vfmv_v_f_f64m8
; CHECK: fmv.d.x ft0, a0
; CHECK: vfmv.v.f        v16, ft0
%a =  tail call <vscale x 8 x double> @llvm.riscv.vfmv.v.f.f64m8(double %0)
ret <vscale x 8 x double> %a
}

declare double @llvm.riscv.vfmv.f.s.f64m8(<vscale x 8 x double>);
define double @vfmv_f_s_f64m8(<vscale x 8 x double> %0) {
entry:
; CHECK-LABEL: vfmv_f_s_f64m8
; CHECK: vfmv.f.s        ft0, v16
; CHECK: fmv.x.d a0, ft0
%a =  tail call double @llvm.riscv.vfmv.f.s.f64m8(<vscale x 8 x double> %0)
ret double %a
}


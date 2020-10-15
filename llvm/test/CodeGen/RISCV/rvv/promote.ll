; RUN: llc -mtriple=riscv64 -mattr=+experimental-v,+f,+experimental-zfh < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 8 x i8> @llvm.riscv.vmv.v.x(i8);
define <vscale x 8 x i8> @vmv_v_x(i8 %0) {
entry:
; CHECK-LABEL: vmv_v_x
; CHECK: slli	a0, a0, 56
; CHECK: srai	a0, a0, 56
; CHECK: vmv.v.x	v16, a0
; CHECK: ret
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vmv.v.x(i8 %0)
ret <vscale x 8 x i8> %a
}

declare i8 @llvm.riscv.vmv.x.s(<vscale x 64 x i8>);
define i8 @vmv_v_s(<vscale x 64 x i8> %0) {
entry:
; CHECK-LABEL: vmv_v_s
; CHECK: vmv.x.s a0, v16
; CHECK: ret 
%a =  tail call i8 @llvm.riscv.vmv.x.s(<vscale x 64 x i8> %0)
ret i8 %a
}

declare <vscale x 8 x i8> @llvm.riscv.vxor.vx(<vscale x 8 x i8>, i8);
define <vscale x 8 x i8> @vxor_vx_i8m1(<vscale x 8 x i8> %0, i8 %1) {
entry:
; CHECK-LABEL: vxor_vx_i8m1
; CHECK: slli	a0, a0, 56
; CHECK: srai	a0, a0, 56
; CHECK: vxor.vx v16, v16, a0
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vxor.vx(<vscale x 8 x i8> %0, i8 %1)
ret <vscale x 8 x i8> %a
}

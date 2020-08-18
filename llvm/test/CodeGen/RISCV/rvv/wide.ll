; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 8 x i16> @llvm.riscv.vwadd.vv.i8m8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i16> @vwadd_vv_i8m8() {
entry:
; CHECK-LABEL: vwadd_vv_i8m8
; CHECK: vwadd.vv v16, v25, v25
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vwadd.vv.i8m8(<vscale x 8 x i8> undef, <vscale x 8 x i8> undef)
ret <vscale x 8 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vwadd.vv.mask.i8m8(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i16> @vwadd_vv_mask_i8m8() {
entry:
; CHECK-LABEL: vwadd_vv_mask_i8m8
; CHECK: vwadd.vv v16, v25, v25, v0.t
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vwadd.vv.mask.i8m8(<vscale x 8 x i1> undef, <vscale x 8 x i16> undef, <vscale x 8 x i8> undef, <vscale x 8 x i8> undef)
ret <vscale x 8 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vwadd.vx.i8m8(<vscale x 8 x i8>, i64);
define <vscale x 8 x i16> @vwadd_vx_i8m8() {
entry:
; CHECK-LABEL: vwadd_vx_i8m8
; CHECK: vwadd.vx	v16, v25, a0
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vwadd.vx.i8m8(<vscale x 8 x i8> undef, i64 undef)
ret <vscale x 8 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vwadd.vx.mask.i8m8(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x i8>, i64);
define <vscale x 8 x i16> @vwadd_vx_mask_i8m8() {
entry:
; CHECK-LABEL: vwadd_vx_mask_i8m8
; CHECK: vwadd.vx	v16, v25, a0, v0.t
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vwadd.vx.mask.i8m8(<vscale x 8 x i1> undef, <vscale x 8 x i16> undef, <vscale x 8 x i8> undef, i64 undef)
ret <vscale x 8 x i16> %a
}
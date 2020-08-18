; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 8 x i16> @llvm.riscv.vwadd.vv.i8m8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i16> @vwadd_vv_i8m8() {
entry:
; CHECK-LABEL: vadd_vv_i8m8
; CHECK: vadd.vv v16, v16, v24
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vwadd.vv.i8m8(<vscale x 8 x i8> undef, <vscale x 8 x i8> undef)
ret <vscale x 8 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vwadd.vv.mask.i8m8(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i16> @vwadd_vv_mask_i8m8() {
entry:
; CHECK-LABEL: vadd_vv_i8m8
; CHECK: vadd.vv v16, v16, v24
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vwadd.vv.mask.i8m8(<vscale x 8 x i1> undef, <vscale x 8 x i16> undef, <vscale x 8 x i8> undef, <vscale x 8 x i8> undef)
ret <vscale x 8 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vwadd.vx.i8m8(<vscale x 8 x i8>, i64);
define <vscale x 8 x i16> @vwadd_vx_i8m8() {
entry:
; CHECK-LABEL: vadd_vv_i8m8
; CHECK: vadd.vv v16, v16, v24
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vwadd.vx.i8m8(<vscale x 8 x i8> undef, i64 undef)
ret <vscale x 8 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vwadd.vx.mask.i8m8(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x i8>, i64);
define <vscale x 8 x i16> @vwadd_vx_mask_i8m8() {
entry:
; CHECK-LABEL: vadd_vv_i8m8
; CHECK: vadd.vv v16, v16, v24
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vwadd.vx.mask.i8m8(<vscale x 8 x i1> undef, <vscale x 8 x i16> undef, <vscale x 8 x i8> undef, i64 undef)
ret <vscale x 8 x i16> %a
}
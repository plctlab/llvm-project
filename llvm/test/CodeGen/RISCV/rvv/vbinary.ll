; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 64 x i8> @llvm.riscv.vadd.vv.i8m8(<vscale x 64 x i8>, <vscale x 64 x i8>);
define <vscale x 64 x i8> @vadd_vv_i8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1) {
entry:
; CHECK-LABEL: vadd_vv_i8m8
; CHECK: vadd.vv v16, v16, v24
; CHECK: ret 
%a =  tail call <vscale x 64 x i8> @llvm.riscv.vadd.vv.i8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1)
ret <vscale x 64 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vadd.vv.mask.i8m2(<vscale x 16 x i1>, <vscale x 16 x i8>, <vscale x 16 x i8>, <vscale x 16 x i8>);
define <vscale x 16 x i8> @vadd_vv_mask_i8m2(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i8> %2, <vscale x 16 x i8> %3) {
entry:
; CHECK-LABEL: vadd_vv_mask_i8m2
; CHECK: vadd.vv v16, v18, v20, v0.t
; CHECK: ret 
%a =  tail call <vscale x 16 x i8> @llvm.riscv.vadd.vv.mask.i8m2(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i8> %2, <vscale x 16 x i8> %3)
ret <vscale x 16 x i8> %a
}
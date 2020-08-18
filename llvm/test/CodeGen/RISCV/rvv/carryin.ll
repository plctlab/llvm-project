; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 8 x i16> @llvm.riscv.vadc.vvm.i8m8(<vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i1>);
define <vscale x 8 x i16> @vadc_vvm_i8m8(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2) {
entry:
; CHECK-LABEL: vadc_vvm_i8m8
; CHECK: vadc.vvm	v16, v18, v0, v0
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vadc.vvm.i8m8(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2)
ret <vscale x 8 x i16> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i8m8(<vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmadc_vvm_i8m8(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2) {
entry:
; CHECK-LABEL: vmadc_vvm_i8m8
; CHECK: vmadc.vvm	v25, v18, v0, v0
; CHECK: ret 
%a =  tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i8m8(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2)
ret <vscale x 8 x i1> %a
}
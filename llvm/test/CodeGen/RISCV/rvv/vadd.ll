; RUN: llc -mtriple=riscv64 -mattr=+v -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 8 x i8> @llvm.riscv.vadd.vv.i8m1(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vadd_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vadd_vv_i8m1
; CHECK: vadd.vv v0, v0, v1
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vadd.vv.i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vadd.vv.i16m1(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vadd_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vadd_vv_i16m1
; CHECK: vadd.vv v0, v0, v1
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vadd.vv.i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}
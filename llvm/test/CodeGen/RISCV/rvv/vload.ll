; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 8 x i8> @llvm.riscv.vload.i8(i8*);
define <vscale x 8 x i8> @vle8_v_i8m1(i8* %0) {
entry:
; CHECK-LABEL: vle8_v_i8m1
; CHECK: vle8.v v16, (a0)
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vload.i8(i8* %0)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vload.i16(i16*);
define <vscale x 4 x i16> @vle16_v_i16m1(i16* %0) {
entry:
; CHECK-LABEL: vle16_v_i16m1
; CHECK: vle16.v v16, (a0)
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vload.i16(i16* %0)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vload.i32(i32*);
define <vscale x 2 x i32> @vle32_v_i32m1(i32* %0) {
entry:
; CHECK-LABEL: vle32_v_i32m1
; CHECK: vle32.v v16, (a0)
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vload.i32(i32* %0)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vload.i64(i64*);
define <vscale x 1 x i64> @vle64_v_i64m1(i64* %0) {
entry:
; CHECK-LABEL: vle64_v_i64m1
; CHECK: vle64.v v16, (a0)
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vload.i64(i64* %0)
ret <vscale x 1 x i64> %a
}

declare <vscale x 4 x half> @llvm.riscv.vload.f16(half*);
define <vscale x 4 x half> @vle16_v_f16m1(half* %0) {
entry:
; CHECK-LABEL: vle16_v_f16m1
; CHECK: vle16.v v16, (a0)
; CHECK: ret 
%a =  tail call <vscale x 4 x half> @llvm.riscv.vload.f16(half* %0)
ret <vscale x 4 x half> %a
}

declare <vscale x 2 x float> @llvm.riscv.vload.f32(float*);
define <vscale x 2 x float> @vle32_v_f32m1(float* %0) {
entry:
; CHECK-LABEL: vle32_v_f32m1
; CHECK: vle32.v v16, (a0)
; CHECK: ret 
%a =  tail call <vscale x 2 x float> @llvm.riscv.vload.f32(float* %0)
ret <vscale x 2 x float> %a
}

declare <vscale x 1 x double> @llvm.riscv.vload.f64(double*);
define <vscale x 1 x double> @vle64_v_f64m1(double* %0) {
entry:
; CHECK-LABEL: vle64_v_f64m1
; CHECK: vle64.v v16, (a0)
; CHECK: ret 
%a =  tail call <vscale x 1 x double> @llvm.riscv.vload.f64(double* %0)
ret <vscale x 1 x double> %a
}
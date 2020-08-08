; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare void @llvm.riscv.vstore.i8(i8*, <vscale x 8 x i8>);
define void @vse8_v_i8m1(i8* %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vse8_v_i8m1
; CHECK: vse8.v v16, (a0)
; CHECK: ret 
tail call void @llvm.riscv.vstore.i8(i8* %0, <vscale x 8 x i8> %1)
ret void
}

declare void @llvm.riscv.vstore.i16(i16*, <vscale x 4 x i16>);
define void @vse16_v_i16m1(i16* %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vse16_v_i16m1
; CHECK: vse16.v v16, (a0)
; CHECK: ret 
tail call void @llvm.riscv.vstore.i16(i16* %0, <vscale x 4 x i16> %1)
ret void
}

declare void @llvm.riscv.vstore.i32(i32*, <vscale x 2 x i32>);
define void @vse32_v_i32m1(i32* %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vse32_v_i32m1
; CHECK: vse32.v v16, (a0)
; CHECK: ret 
tail call void @llvm.riscv.vstore.i32(i32* %0, <vscale x 2 x i32> %1)
ret void
}

declare void @llvm.riscv.vstore.i64(i64*, <vscale x 1 x i64>);
define void @vse64_v_i64m1(i64* %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vse64_v_i64m1
; CHECK: vse64.v v16, (a0)
; CHECK: ret 
tail call void @llvm.riscv.vstore.i64(i64* %0, <vscale x 1 x i64> %1)
ret void
}

declare void @llvm.riscv.vstore.f16(half*, <vscale x 4 x half>);
define void @vse16_v_f16m1(half* %0, <vscale x 4 x half> %1) {
entry:
; CHECK-LABEL: vse16_v_f16m1
; CHECK: vse16.v v16, (a0)
; CHECK: ret 
tail call void @llvm.riscv.vstore.f16(half* %0, <vscale x 4 x half> %1)
ret void
}

declare void @llvm.riscv.vstore.f32(float*, <vscale x 2 x float>);
define void @vse32_v_f32m1(float* %0, <vscale x 2 x float> %1) {
entry:
; CHECK-LABEL: vse32_v_f32m1
; CHECK: vse32.v v16, (a0)
; CHECK: ret 
tail call void @llvm.riscv.vstore.f32(float* %0, <vscale x 2 x float> %1)
ret void
}

declare void @llvm.riscv.vstore.f64(double*, <vscale x 1 x double>);
define void @vse64_v_f64m1(double* %0, <vscale x 1 x double> %1) {
entry:
; CHECK-LABEL: vse64_v_f64m1
; CHECK: vse64.v v16, (a0)
; CHECK: ret 
tail call void @llvm.riscv.vstore.f64(double* %0, <vscale x 1 x double> %1)
ret void
}
; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vwmaccsu_vx_i16mf4(<vscale x 1 x i16> %acc, i8 %op1, <vscale x 1 x i8> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i16mf4
; vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vwmaccsu.vx.nxv1i16.i8.nxv1i8(<vscale x 1 x i16> %acc, i8 %op1, <vscale x 1 x i8> %op2)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vwmaccsu_vx_i16mf2(<vscale x 2 x i16> %acc, i8 %op1, <vscale x 2 x i8> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i16mf2
; vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vwmaccsu.vx.nxv2i16.i8.nxv2i8(<vscale x 2 x i16> %acc, i8 %op1, <vscale x 2 x i8> %op2)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vwmaccsu_vx_i16m1(<vscale x 4 x i16> %acc, i8 %op1, <vscale x 4 x i8> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i16m1
; vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vwmaccsu.vx.nxv4i16.i8.nxv4i8(<vscale x 4 x i16> %acc, i8 %op1, <vscale x 4 x i8> %op2)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vwmaccsu_vx_i16m2(<vscale x 8 x i16> %acc, i8 %op1, <vscale x 8 x i8> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i16m2
; vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vwmaccsu.vx.nxv8i16.i8.nxv8i8(<vscale x 8 x i16> %acc, i8 %op1, <vscale x 8 x i8> %op2)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vwmaccsu_vx_i16m4(<vscale x 16 x i16> %acc, i8 %op1, <vscale x 16 x i8> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i16m4
; vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vwmaccsu.vx.nxv16i16.i8.nxv16i8(<vscale x 16 x i16> %acc, i8 %op1, <vscale x 16 x i8> %op2)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vwmaccsu_vx_i16m8(<vscale x 32 x i16> %acc, i8 %op1, <vscale x 32 x i8> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i16m8
; vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vwmaccsu.vx.nxv32i16.i8.nxv32i8(<vscale x 32 x i16> %acc, i8 %op1, <vscale x 32 x i8> %op2)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vwmaccsu_vx_i32mf2(<vscale x 1 x i32> %acc, i16 %op1, <vscale x 1 x i16> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i32mf2
; vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vwmaccsu.vx.nxv1i32.i16.nxv1i16(<vscale x 1 x i32> %acc, i16 %op1, <vscale x 1 x i16> %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vwmaccsu_vx_i32m1(<vscale x 2 x i32> %acc, i16 %op1, <vscale x 2 x i16> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i32m1
; vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vwmaccsu.vx.nxv2i32.i16.nxv2i16(<vscale x 2 x i32> %acc, i16 %op1, <vscale x 2 x i16> %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vwmaccsu_vx_i32m2(<vscale x 4 x i32> %acc, i16 %op1, <vscale x 4 x i16> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i32m2
; vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vwmaccsu.vx.nxv4i32.i16.nxv4i16(<vscale x 4 x i32> %acc, i16 %op1, <vscale x 4 x i16> %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vwmaccsu_vx_i32m4(<vscale x 8 x i32> %acc, i16 %op1, <vscale x 8 x i16> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i32m4
; vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vwmaccsu.vx.nxv8i32.i16.nxv8i16(<vscale x 8 x i32> %acc, i16 %op1, <vscale x 8 x i16> %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vwmaccsu_vx_i32m8(<vscale x 16 x i32> %acc, i16 %op1, <vscale x 16 x i16> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i32m8
; vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vwmaccsu.vx.nxv16i32.i16.nxv16i16(<vscale x 16 x i32> %acc, i16 %op1, <vscale x 16 x i16> %op2)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vwmaccsu_vx_i64m1(<vscale x 1 x i64> %acc, i32 %op1, <vscale x 1 x i32> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i64m1
; vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vwmaccsu.vx.nxv1i64.i32.nxv1i32(<vscale x 1 x i64> %acc, i32 %op1, <vscale x 1 x i32> %op2)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vwmaccsu_vx_i64m2(<vscale x 2 x i64> %acc, i32 %op1, <vscale x 2 x i32> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i64m2
; vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vwmaccsu.vx.nxv2i64.i32.nxv2i32(<vscale x 2 x i64> %acc, i32 %op1, <vscale x 2 x i32> %op2)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vwmaccsu_vx_i64m4(<vscale x 4 x i64> %acc, i32 %op1, <vscale x 4 x i32> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i64m4
; vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vwmaccsu.vx.nxv4i64.i32.nxv4i32(<vscale x 4 x i64> %acc, i32 %op1, <vscale x 4 x i32> %op2)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vwmaccsu_vx_i64m8(<vscale x 8 x i64> %acc, i32 %op1, <vscale x 8 x i32> %op2) {
entry:
; CHECK-LABEL: vwmaccsu_vx_i64m8
; vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vwmaccsu.vx {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vwmaccsu.vx.nxv8i64.i32.nxv8i32(<vscale x 8 x i64> %acc, i32 %op1, <vscale x 8 x i32> %op2)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vwmaccsu.vx.nxv8i16.i8.nxv8i8(<vscale x 8 x i16>, i8, <vscale x 8 x i8>)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vwmaccsu.vx.nxv2i64.i32.nxv2i32(<vscale x 2 x i64>, i32, <vscale x 2 x i32>)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vwmaccsu.vx.nxv1i64.i32.nxv1i32(<vscale x 1 x i64>, i32, <vscale x 1 x i32>)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vwmaccsu.vx.nxv32i16.i8.nxv32i8(<vscale x 32 x i16>, i8, <vscale x 32 x i8>)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vwmaccsu.vx.nxv8i64.i32.nxv8i32(<vscale x 8 x i64>, i32, <vscale x 8 x i32>)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vwmaccsu.vx.nxv8i32.i16.nxv8i16(<vscale x 8 x i32>, i16, <vscale x 8 x i16>)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vwmaccsu.vx.nxv16i16.i8.nxv16i8(<vscale x 16 x i16>, i8, <vscale x 16 x i8>)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vwmaccsu.vx.nxv4i16.i8.nxv4i8(<vscale x 4 x i16>, i8, <vscale x 4 x i8>)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vwmaccsu.vx.nxv2i32.i16.nxv2i16(<vscale x 2 x i32>, i16, <vscale x 2 x i16>)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vwmaccsu.vx.nxv16i32.i16.nxv16i16(<vscale x 16 x i32>, i16, <vscale x 16 x i16>)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vwmaccsu.vx.nxv2i16.i8.nxv2i8(<vscale x 2 x i16>, i8, <vscale x 2 x i8>)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vwmaccsu.vx.nxv1i32.i16.nxv1i16(<vscale x 1 x i32>, i16, <vscale x 1 x i16>)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vwmaccsu.vx.nxv4i64.i32.nxv4i32(<vscale x 4 x i64>, i32, <vscale x 4 x i32>)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vwmaccsu.vx.nxv4i32.i16.nxv4i16(<vscale x 4 x i32>, i16, <vscale x 4 x i16>)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vwmaccsu.vx.nxv1i16.i8.nxv1i8(<vscale x 1 x i16>, i8, <vscale x 1 x i8>)

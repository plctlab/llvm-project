; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vwaddu_wx_u16mf4(<vscale x 1 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u16mf4
; vsetvli zero, zero, e8,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vwaddu.wx.nxv1i16.i8(<vscale x 1 x i16> %op1, i8 %op2)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vwaddu_wx_u16mf2(<vscale x 2 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u16mf2
; vsetvli zero, zero, e8,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vwaddu.wx.nxv2i16.i8(<vscale x 2 x i16> %op1, i8 %op2)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vwaddu_wx_u16m1(<vscale x 4 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u16m1
; vsetvli zero, zero, e8,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vwaddu.wx.nxv4i16.i8(<vscale x 4 x i16> %op1, i8 %op2)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vwaddu_wx_u16m2(<vscale x 8 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u16m2
; vsetvli zero, zero, e8,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vwaddu.wx.nxv8i16.i8(<vscale x 8 x i16> %op1, i8 %op2)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vwaddu_wx_u16m4(<vscale x 16 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u16m4
; vsetvli zero, zero, e8,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vwaddu.wx.nxv16i16.i8(<vscale x 16 x i16> %op1, i8 %op2)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vwaddu_wx_u16m8(<vscale x 32 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u16m8
; vsetvli zero, zero, e8,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vwaddu.wx.nxv32i16.i8(<vscale x 32 x i16> %op1, i8 %op2)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vwaddu_wx_u32mf2(<vscale x 1 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u32mf2
; vsetvli zero, zero, e16,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vwaddu.wx.nxv1i32.i16(<vscale x 1 x i32> %op1, i16 %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vwaddu_wx_u32m1(<vscale x 2 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u32m1
; vsetvli zero, zero, e16,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vwaddu.wx.nxv2i32.i16(<vscale x 2 x i32> %op1, i16 %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vwaddu_wx_u32m2(<vscale x 4 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u32m2
; vsetvli zero, zero, e16,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vwaddu.wx.nxv4i32.i16(<vscale x 4 x i32> %op1, i16 %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vwaddu_wx_u32m4(<vscale x 8 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u32m4
; vsetvli zero, zero, e16,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vwaddu.wx.nxv8i32.i16(<vscale x 8 x i32> %op1, i16 %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vwaddu_wx_u32m8(<vscale x 16 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u32m8
; vsetvli zero, zero, e16,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vwaddu.wx.nxv16i32.i16(<vscale x 16 x i32> %op1, i16 %op2)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vwaddu_wx_u64m1(<vscale x 1 x i64> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u64m1
; vsetvli zero, zero, e32,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vwaddu.wx.nxv1i64.i32(<vscale x 1 x i64> %op1, i32 %op2)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vwaddu_wx_u64m2(<vscale x 2 x i64> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u64m2
; vsetvli zero, zero, e32,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vwaddu.wx.nxv2i64.i32(<vscale x 2 x i64> %op1, i32 %op2)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vwaddu_wx_u64m4(<vscale x 4 x i64> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u64m4
; vsetvli zero, zero, e32,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vwaddu.wx.nxv4i64.i32(<vscale x 4 x i64> %op1, i32 %op2)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vwaddu_wx_u64m8(<vscale x 8 x i64> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vwaddu_wx_u64m8
; vsetvli zero, zero, e32,tu,mu
; CHECK: vwaddu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vwaddu.wx.nxv8i64.i32(<vscale x 8 x i64> %op1, i32 %op2)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vwaddu.wx.nxv1i16.i8(<vscale x 1 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vwaddu.wx.nxv16i32.i16(<vscale x 16 x i32>, i16)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vwaddu.wx.nxv1i32.i16(<vscale x 1 x i32>, i16)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vwaddu.wx.nxv1i64.i32(<vscale x 1 x i64>, i32)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vwaddu.wx.nxv2i16.i8(<vscale x 2 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vwaddu.wx.nxv8i64.i32(<vscale x 8 x i64>, i32)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vwaddu.wx.nxv2i32.i16(<vscale x 2 x i32>, i16)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vwaddu.wx.nxv8i16.i8(<vscale x 8 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vwaddu.wx.nxv16i16.i8(<vscale x 16 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vwaddu.wx.nxv8i32.i16(<vscale x 8 x i32>, i16)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vwaddu.wx.nxv2i64.i32(<vscale x 2 x i64>, i32)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vwaddu.wx.nxv4i64.i32(<vscale x 4 x i64>, i32)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vwaddu.wx.nxv32i16.i8(<vscale x 32 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vwaddu.wx.nxv4i32.i16(<vscale x 4 x i32>, i16)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vwaddu.wx.nxv4i16.i8(<vscale x 4 x i16>, i8)

; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vwsub_wx_i16mf4(<vscale x 1 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i16mf4
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vwsub.wx.nxv1i16.i8(<vscale x 1 x i16> %op1, i8 %op2)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vwsub_wx_i16mf2(<vscale x 2 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i16mf2
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vwsub.wx.nxv2i16.i8(<vscale x 2 x i16> %op1, i8 %op2)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vwsub_wx_i16m1(<vscale x 4 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i16m1
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vwsub.wx.nxv4i16.i8(<vscale x 4 x i16> %op1, i8 %op2)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vwsub_wx_i16m2(<vscale x 8 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i16m2
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vwsub.wx.nxv8i16.i8(<vscale x 8 x i16> %op1, i8 %op2)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vwsub_wx_i16m4(<vscale x 16 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i16m4
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vwsub.wx.nxv16i16.i8(<vscale x 16 x i16> %op1, i8 %op2)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vwsub_wx_i16m8(<vscale x 32 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i16m8
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vwsub.wx.nxv32i16.i8(<vscale x 32 x i16> %op1, i8 %op2)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vwsub_wx_i32mf2(<vscale x 1 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i32mf2
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vwsub.wx.nxv1i32.i16(<vscale x 1 x i32> %op1, i16 %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vwsub_wx_i32m1(<vscale x 2 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i32m1
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vwsub.wx.nxv2i32.i16(<vscale x 2 x i32> %op1, i16 %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vwsub_wx_i32m2(<vscale x 4 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i32m2
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vwsub.wx.nxv4i32.i16(<vscale x 4 x i32> %op1, i16 %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vwsub_wx_i32m4(<vscale x 8 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i32m4
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vwsub.wx.nxv8i32.i16(<vscale x 8 x i32> %op1, i16 %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vwsub_wx_i32m8(<vscale x 16 x i32> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i32m8
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vwsub.wx.nxv16i32.i16(<vscale x 16 x i32> %op1, i16 %op2)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vwsub_wx_i64m1(<vscale x 1 x i64> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i64m1
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vwsub.wx.nxv1i64.i32(<vscale x 1 x i64> %op1, i32 %op2)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vwsub_wx_i64m2(<vscale x 2 x i64> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i64m2
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vwsub.wx.nxv2i64.i32(<vscale x 2 x i64> %op1, i32 %op2)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vwsub_wx_i64m4(<vscale x 4 x i64> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i64m4
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vwsub.wx.nxv4i64.i32(<vscale x 4 x i64> %op1, i32 %op2)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vwsub_wx_i64m8(<vscale x 8 x i64> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vwsub_wx_i64m8
; CHECK: vwsub.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vwsub.wx.nxv8i64.i32(<vscale x 8 x i64> %op1, i32 %op2)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vwsub.wx.nxv16i16.i8(<vscale x 16 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vwsub.wx.nxv2i16.i8(<vscale x 2 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vwsub.wx.nxv1i32.i16(<vscale x 1 x i32>, i16)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vwsub.wx.nxv16i32.i16(<vscale x 16 x i32>, i16)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vwsub.wx.nxv4i16.i8(<vscale x 4 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vwsub.wx.nxv1i16.i8(<vscale x 1 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vwsub.wx.nxv2i32.i16(<vscale x 2 x i32>, i16)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vwsub.wx.nxv32i16.i8(<vscale x 32 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vwsub.wx.nxv8i16.i8(<vscale x 8 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vwsub.wx.nxv1i64.i32(<vscale x 1 x i64>, i32)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vwsub.wx.nxv2i64.i32(<vscale x 2 x i64>, i32)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vwsub.wx.nxv4i64.i32(<vscale x 4 x i64>, i32)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vwsub.wx.nxv8i32.i16(<vscale x 8 x i32>, i16)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vwsub.wx.nxv8i64.i32(<vscale x 8 x i64>, i32)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vwsub.wx.nxv4i32.i16(<vscale x 4 x i32>, i16)

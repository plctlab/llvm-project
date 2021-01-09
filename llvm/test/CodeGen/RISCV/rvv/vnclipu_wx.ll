; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vnclipu_wx_u8mf8(<vscale x 1 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u8mf8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vnclipu.wx.nxv1i8.nxv1i16.i8(<vscale x 1 x i16> %op1, i8 %op2)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vnclipu_wx_u8mf4(<vscale x 2 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u8mf4
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vnclipu.wx.nxv2i8.nxv2i16.i8(<vscale x 2 x i16> %op1, i8 %op2)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vnclipu_wx_u8mf2(<vscale x 4 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u8mf2
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vnclipu.wx.nxv4i8.nxv4i16.i8(<vscale x 4 x i16> %op1, i8 %op2)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vnclipu_wx_u8m1(<vscale x 8 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u8m1
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vnclipu.wx.nxv8i8.nxv8i16.i8(<vscale x 8 x i16> %op1, i8 %op2)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vnclipu_wx_u8m2(<vscale x 16 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u8m2
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vnclipu.wx.nxv16i8.nxv16i16.i8(<vscale x 16 x i16> %op1, i8 %op2)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vnclipu_wx_u8m4(<vscale x 32 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u8m4
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vnclipu.wx.nxv32i8.nxv32i16.i8(<vscale x 32 x i16> %op1, i8 %op2)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vnclipu_wx_u16mf4(<vscale x 1 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u16mf4
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vnclipu.wx.nxv1i16.nxv1i32.i8(<vscale x 1 x i32> %op1, i8 %op2)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vnclipu_wx_u16mf2(<vscale x 2 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u16mf2
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vnclipu.wx.nxv2i16.nxv2i32.i8(<vscale x 2 x i32> %op1, i8 %op2)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vnclipu_wx_u16m1(<vscale x 4 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u16m1
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vnclipu.wx.nxv4i16.nxv4i32.i8(<vscale x 4 x i32> %op1, i8 %op2)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vnclipu_wx_u16m2(<vscale x 8 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u16m2
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vnclipu.wx.nxv8i16.nxv8i32.i8(<vscale x 8 x i32> %op1, i8 %op2)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vnclipu_wx_u16m4(<vscale x 16 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u16m4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vnclipu.wx.nxv16i16.nxv16i32.i8(<vscale x 16 x i32> %op1, i8 %op2)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vnclipu_wx_u32mf2(<vscale x 1 x i64> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vnclipu.wx.nxv1i32.nxv1i64.i8(<vscale x 1 x i64> %op1, i8 %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vnclipu_wx_u32m1(<vscale x 2 x i64> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vnclipu.wx.nxv2i32.nxv2i64.i8(<vscale x 2 x i64> %op1, i8 %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vnclipu_wx_u32m2(<vscale x 4 x i64> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vnclipu.wx.nxv4i32.nxv4i64.i8(<vscale x 4 x i64> %op1, i8 %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vnclipu_wx_u32m4(<vscale x 8 x i64> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vnclipu_wx_u32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vnclipu.wx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vnclipu.wx.nxv8i32.nxv8i64.i8(<vscale x 8 x i64> %op1, i8 %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vnclipu.wx.nxv16i8.nxv16i16.i8(<vscale x 16 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vnclipu.wx.nxv4i8.nxv4i16.i8(<vscale x 4 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vnclipu.wx.nxv8i32.nxv8i64.i8(<vscale x 8 x i64>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vnclipu.wx.nxv2i16.nxv2i32.i8(<vscale x 2 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vnclipu.wx.nxv8i16.nxv8i32.i8(<vscale x 8 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vnclipu.wx.nxv1i8.nxv1i16.i8(<vscale x 1 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vnclipu.wx.nxv32i8.nxv32i16.i8(<vscale x 32 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vnclipu.wx.nxv16i16.nxv16i32.i8(<vscale x 16 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vnclipu.wx.nxv1i16.nxv1i32.i8(<vscale x 1 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vnclipu.wx.nxv4i32.nxv4i64.i8(<vscale x 4 x i64>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vnclipu.wx.nxv2i8.nxv2i16.i8(<vscale x 2 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vnclipu.wx.nxv8i8.nxv8i16.i8(<vscale x 8 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vnclipu.wx.nxv4i16.nxv4i32.i8(<vscale x 4 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vnclipu.wx.nxv1i32.nxv1i64.i8(<vscale x 1 x i64>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vnclipu.wx.nxv2i32.nxv2i64.i8(<vscale x 2 x i64>, i8)

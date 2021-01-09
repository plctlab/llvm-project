; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vssrl_vx_u8mf8(<vscale x 1 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u8mf8
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vssrl.vx.nxv1i8.i8(<vscale x 1 x i8> %op1, i8 %op2)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vssrl_vx_u8mf4(<vscale x 2 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u8mf4
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vssrl.vx.nxv2i8.i8(<vscale x 2 x i8> %op1, i8 %op2)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vssrl_vx_u8mf2(<vscale x 4 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u8mf2
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vssrl.vx.nxv4i8.i8(<vscale x 4 x i8> %op1, i8 %op2)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vssrl_vx_u8m1(<vscale x 8 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u8m1
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vssrl.vx.nxv8i8.i8(<vscale x 8 x i8> %op1, i8 %op2)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vssrl_vx_u8m2(<vscale x 16 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u8m2
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vssrl.vx.nxv16i8.i8(<vscale x 16 x i8> %op1, i8 %op2)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vssrl_vx_u8m4(<vscale x 32 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u8m4
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vssrl.vx.nxv32i8.i8(<vscale x 32 x i8> %op1, i8 %op2)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vssrl_vx_u8m8(<vscale x 64 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u8m8
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vssrl.vx.nxv64i8.i8(<vscale x 64 x i8> %op1, i8 %op2)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vssrl_vx_u16mf4(<vscale x 1 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u16mf4
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vssrl.vx.nxv1i16.i8(<vscale x 1 x i16> %op1, i8 %op2)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vssrl_vx_u16mf2(<vscale x 2 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u16mf2
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vssrl.vx.nxv2i16.i8(<vscale x 2 x i16> %op1, i8 %op2)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vssrl_vx_u16m1(<vscale x 4 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u16m1
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vssrl.vx.nxv4i16.i8(<vscale x 4 x i16> %op1, i8 %op2)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vssrl_vx_u16m2(<vscale x 8 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u16m2
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vssrl.vx.nxv8i16.i8(<vscale x 8 x i16> %op1, i8 %op2)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vssrl_vx_u16m4(<vscale x 16 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u16m4
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vssrl.vx.nxv16i16.i8(<vscale x 16 x i16> %op1, i8 %op2)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vssrl_vx_u16m8(<vscale x 32 x i16> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u16m8
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vssrl.vx.nxv32i16.i8(<vscale x 32 x i16> %op1, i8 %op2)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vssrl_vx_u32mf2(<vscale x 1 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u32mf2
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vssrl.vx.nxv1i32.i8(<vscale x 1 x i32> %op1, i8 %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vssrl_vx_u32m1(<vscale x 2 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u32m1
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vssrl.vx.nxv2i32.i8(<vscale x 2 x i32> %op1, i8 %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vssrl_vx_u32m2(<vscale x 4 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u32m2
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vssrl.vx.nxv4i32.i8(<vscale x 4 x i32> %op1, i8 %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vssrl_vx_u32m4(<vscale x 8 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u32m4
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vssrl.vx.nxv8i32.i8(<vscale x 8 x i32> %op1, i8 %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vssrl_vx_u32m8(<vscale x 16 x i32> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u32m8
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vssrl.vx.nxv16i32.i8(<vscale x 16 x i32> %op1, i8 %op2)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vssrl_vx_u64m1(<vscale x 1 x i64> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u64m1
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vssrl.vx.nxv1i64.i8(<vscale x 1 x i64> %op1, i8 %op2)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vssrl_vx_u64m2(<vscale x 2 x i64> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u64m2
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vssrl.vx.nxv2i64.i8(<vscale x 2 x i64> %op1, i8 %op2)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vssrl_vx_u64m4(<vscale x 4 x i64> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u64m4
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vssrl.vx.nxv4i64.i8(<vscale x 4 x i64> %op1, i8 %op2)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vssrl_vx_u64m8(<vscale x 8 x i64> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vssrl_vx_u64m8
; CHECK: vssrl.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vssrl.vx.nxv8i64.i8(<vscale x 8 x i64> %op1, i8 %op2)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vssrl.vx.nxv16i8.i8(<vscale x 16 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vssrl.vx.nxv8i16.i8(<vscale x 8 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vssrl.vx.nxv4i64.i8(<vscale x 4 x i64>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vssrl.vx.nxv2i8.i8(<vscale x 2 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vssrl.vx.nxv16i32.i8(<vscale x 16 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vssrl.vx.nxv4i32.i8(<vscale x 4 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vssrl.vx.nxv4i8.i8(<vscale x 4 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vssrl.vx.nxv2i16.i8(<vscale x 2 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vssrl.vx.nxv8i32.i8(<vscale x 8 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vssrl.vx.nxv1i64.i8(<vscale x 1 x i64>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vssrl.vx.nxv1i16.i8(<vscale x 1 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vssrl.vx.nxv32i16.i8(<vscale x 32 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vssrl.vx.nxv16i16.i8(<vscale x 16 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vssrl.vx.nxv32i8.i8(<vscale x 32 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 64 x i8> @llvm.riscv.vssrl.vx.nxv64i8.i8(<vscale x 64 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vssrl.vx.nxv4i16.i8(<vscale x 4 x i16>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vssrl.vx.nxv2i64.i8(<vscale x 2 x i64>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vssrl.vx.nxv1i8.i8(<vscale x 1 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vssrl.vx.nxv1i32.i8(<vscale x 1 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vssrl.vx.nxv8i8.i8(<vscale x 8 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vssrl.vx.nxv2i32.i8(<vscale x 2 x i32>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vssrl.vx.nxv8i64.i8(<vscale x 8 x i64>, i8)

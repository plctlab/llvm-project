; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vslideup_vx_i8mf8(<vscale x 1 x i8> %dst, <vscale x 1 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i8mf8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vslideup.vx.nxv1i8.i64(<vscale x 1 x i8> %dst, <vscale x 1 x i8> %src, i64 %offset)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vslideup_vx_i8mf4(<vscale x 2 x i8> %dst, <vscale x 2 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i8mf4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vslideup.vx.nxv2i8.i64(<vscale x 2 x i8> %dst, <vscale x 2 x i8> %src, i64 %offset)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vslideup_vx_i8mf2(<vscale x 4 x i8> %dst, <vscale x 4 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i8mf2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vslideup.vx.nxv4i8.i64(<vscale x 4 x i8> %dst, <vscale x 4 x i8> %src, i64 %offset)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vslideup_vx_i8m1(<vscale x 8 x i8> %dst, <vscale x 8 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i8m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vslideup.vx.nxv8i8.i64(<vscale x 8 x i8> %dst, <vscale x 8 x i8> %src, i64 %offset)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vslideup_vx_i8m2(<vscale x 16 x i8> %dst, <vscale x 16 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i8m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vslideup.vx.nxv16i8.i64(<vscale x 16 x i8> %dst, <vscale x 16 x i8> %src, i64 %offset)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vslideup_vx_i8m4(<vscale x 32 x i8> %dst, <vscale x 32 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i8m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vslideup.vx.nxv32i8.i64(<vscale x 32 x i8> %dst, <vscale x 32 x i8> %src, i64 %offset)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vslideup_vx_i8m8(<vscale x 64 x i8> %dst, <vscale x 64 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i8m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vslideup.vx.nxv64i8.i64(<vscale x 64 x i8> %dst, <vscale x 64 x i8> %src, i64 %offset)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vslideup_vx_i16mf4(<vscale x 1 x i16> %dst, <vscale x 1 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i16mf4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vslideup.vx.nxv1i16.i64(<vscale x 1 x i16> %dst, <vscale x 1 x i16> %src, i64 %offset)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vslideup_vx_i16mf2(<vscale x 2 x i16> %dst, <vscale x 2 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i16mf2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vslideup.vx.nxv2i16.i64(<vscale x 2 x i16> %dst, <vscale x 2 x i16> %src, i64 %offset)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vslideup_vx_i16m1(<vscale x 4 x i16> %dst, <vscale x 4 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i16m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vslideup.vx.nxv4i16.i64(<vscale x 4 x i16> %dst, <vscale x 4 x i16> %src, i64 %offset)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vslideup_vx_i16m2(<vscale x 8 x i16> %dst, <vscale x 8 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i16m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vslideup.vx.nxv8i16.i64(<vscale x 8 x i16> %dst, <vscale x 8 x i16> %src, i64 %offset)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vslideup_vx_i16m4(<vscale x 16 x i16> %dst, <vscale x 16 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i16m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vslideup.vx.nxv16i16.i64(<vscale x 16 x i16> %dst, <vscale x 16 x i16> %src, i64 %offset)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vslideup_vx_i16m8(<vscale x 32 x i16> %dst, <vscale x 32 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i16m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vslideup.vx.nxv32i16.i64(<vscale x 32 x i16> %dst, <vscale x 32 x i16> %src, i64 %offset)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vslideup_vx_i32mf2(<vscale x 1 x i32> %dst, <vscale x 1 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i32mf2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vslideup.vx.nxv1i32.i64(<vscale x 1 x i32> %dst, <vscale x 1 x i32> %src, i64 %offset)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vslideup_vx_i32m1(<vscale x 2 x i32> %dst, <vscale x 2 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i32m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vslideup.vx.nxv2i32.i64(<vscale x 2 x i32> %dst, <vscale x 2 x i32> %src, i64 %offset)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vslideup_vx_i32m2(<vscale x 4 x i32> %dst, <vscale x 4 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i32m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vslideup.vx.nxv4i32.i64(<vscale x 4 x i32> %dst, <vscale x 4 x i32> %src, i64 %offset)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vslideup_vx_i32m4(<vscale x 8 x i32> %dst, <vscale x 8 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i32m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vslideup.vx.nxv8i32.i64(<vscale x 8 x i32> %dst, <vscale x 8 x i32> %src, i64 %offset)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vslideup_vx_i32m8(<vscale x 16 x i32> %dst, <vscale x 16 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i32m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vslideup.vx.nxv16i32.i64(<vscale x 16 x i32> %dst, <vscale x 16 x i32> %src, i64 %offset)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vslideup_vx_i64m1(<vscale x 1 x i64> %dst, <vscale x 1 x i64> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i64m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vslideup.vx.nxv1i64.i64(<vscale x 1 x i64> %dst, <vscale x 1 x i64> %src, i64 %offset)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vslideup_vx_i64m2(<vscale x 2 x i64> %dst, <vscale x 2 x i64> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i64m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vslideup.vx.nxv2i64.i64(<vscale x 2 x i64> %dst, <vscale x 2 x i64> %src, i64 %offset)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vslideup_vx_i64m4(<vscale x 4 x i64> %dst, <vscale x 4 x i64> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i64m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vslideup.vx.nxv4i64.i64(<vscale x 4 x i64> %dst, <vscale x 4 x i64> %src, i64 %offset)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vslideup_vx_i64m8(<vscale x 8 x i64> %dst, <vscale x 8 x i64> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_i64m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vslideup.vx.nxv8i64.i64(<vscale x 8 x i64> %dst, <vscale x 8 x i64> %src, i64 %offset)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vslideup_vx_u8mf8(<vscale x 1 x i8> %dst, <vscale x 1 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u8mf8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vslideup.vx.nxv1i8.i64(<vscale x 1 x i8> %dst, <vscale x 1 x i8> %src, i64 %offset)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vslideup_vx_u8mf4(<vscale x 2 x i8> %dst, <vscale x 2 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u8mf4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vslideup.vx.nxv2i8.i64(<vscale x 2 x i8> %dst, <vscale x 2 x i8> %src, i64 %offset)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vslideup_vx_u8mf2(<vscale x 4 x i8> %dst, <vscale x 4 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u8mf2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vslideup.vx.nxv4i8.i64(<vscale x 4 x i8> %dst, <vscale x 4 x i8> %src, i64 %offset)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vslideup_vx_u8m1(<vscale x 8 x i8> %dst, <vscale x 8 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u8m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vslideup.vx.nxv8i8.i64(<vscale x 8 x i8> %dst, <vscale x 8 x i8> %src, i64 %offset)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vslideup_vx_u8m2(<vscale x 16 x i8> %dst, <vscale x 16 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u8m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vslideup.vx.nxv16i8.i64(<vscale x 16 x i8> %dst, <vscale x 16 x i8> %src, i64 %offset)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vslideup_vx_u8m4(<vscale x 32 x i8> %dst, <vscale x 32 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u8m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vslideup.vx.nxv32i8.i64(<vscale x 32 x i8> %dst, <vscale x 32 x i8> %src, i64 %offset)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vslideup_vx_u8m8(<vscale x 64 x i8> %dst, <vscale x 64 x i8> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u8m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vslideup.vx.nxv64i8.i64(<vscale x 64 x i8> %dst, <vscale x 64 x i8> %src, i64 %offset)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vslideup_vx_u16mf4(<vscale x 1 x i16> %dst, <vscale x 1 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u16mf4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vslideup.vx.nxv1i16.i64(<vscale x 1 x i16> %dst, <vscale x 1 x i16> %src, i64 %offset)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vslideup_vx_u16mf2(<vscale x 2 x i16> %dst, <vscale x 2 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u16mf2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vslideup.vx.nxv2i16.i64(<vscale x 2 x i16> %dst, <vscale x 2 x i16> %src, i64 %offset)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vslideup_vx_u16m1(<vscale x 4 x i16> %dst, <vscale x 4 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u16m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vslideup.vx.nxv4i16.i64(<vscale x 4 x i16> %dst, <vscale x 4 x i16> %src, i64 %offset)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vslideup_vx_u16m2(<vscale x 8 x i16> %dst, <vscale x 8 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u16m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vslideup.vx.nxv8i16.i64(<vscale x 8 x i16> %dst, <vscale x 8 x i16> %src, i64 %offset)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vslideup_vx_u16m4(<vscale x 16 x i16> %dst, <vscale x 16 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u16m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vslideup.vx.nxv16i16.i64(<vscale x 16 x i16> %dst, <vscale x 16 x i16> %src, i64 %offset)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vslideup_vx_u16m8(<vscale x 32 x i16> %dst, <vscale x 32 x i16> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u16m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vslideup.vx.nxv32i16.i64(<vscale x 32 x i16> %dst, <vscale x 32 x i16> %src, i64 %offset)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vslideup_vx_u32mf2(<vscale x 1 x i32> %dst, <vscale x 1 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u32mf2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vslideup.vx.nxv1i32.i64(<vscale x 1 x i32> %dst, <vscale x 1 x i32> %src, i64 %offset)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vslideup_vx_u32m1(<vscale x 2 x i32> %dst, <vscale x 2 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u32m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vslideup.vx.nxv2i32.i64(<vscale x 2 x i32> %dst, <vscale x 2 x i32> %src, i64 %offset)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vslideup_vx_u32m2(<vscale x 4 x i32> %dst, <vscale x 4 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u32m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vslideup.vx.nxv4i32.i64(<vscale x 4 x i32> %dst, <vscale x 4 x i32> %src, i64 %offset)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vslideup_vx_u32m4(<vscale x 8 x i32> %dst, <vscale x 8 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u32m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vslideup.vx.nxv8i32.i64(<vscale x 8 x i32> %dst, <vscale x 8 x i32> %src, i64 %offset)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vslideup_vx_u32m8(<vscale x 16 x i32> %dst, <vscale x 16 x i32> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u32m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vslideup.vx.nxv16i32.i64(<vscale x 16 x i32> %dst, <vscale x 16 x i32> %src, i64 %offset)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vslideup_vx_u64m1(<vscale x 1 x i64> %dst, <vscale x 1 x i64> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u64m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vslideup.vx.nxv1i64.i64(<vscale x 1 x i64> %dst, <vscale x 1 x i64> %src, i64 %offset)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vslideup_vx_u64m2(<vscale x 2 x i64> %dst, <vscale x 2 x i64> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u64m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vslideup.vx.nxv2i64.i64(<vscale x 2 x i64> %dst, <vscale x 2 x i64> %src, i64 %offset)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vslideup_vx_u64m4(<vscale x 4 x i64> %dst, <vscale x 4 x i64> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u64m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vslideup.vx.nxv4i64.i64(<vscale x 4 x i64> %dst, <vscale x 4 x i64> %src, i64 %offset)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vslideup_vx_u64m8(<vscale x 8 x i64> %dst, <vscale x 8 x i64> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_u64m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vslideup.vx.nxv8i64.i64(<vscale x 8 x i64> %dst, <vscale x 8 x i64> %src, i64 %offset)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x half> @test_vslideup_vx_f16mf4(<vscale x 1 x half> %dst, <vscale x 1 x half> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f16mf4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x half> @llvm.riscv.vslideup.vx.nxv1f16.i64(<vscale x 1 x half> %dst, <vscale x 1 x half> %src, i64 %offset)
  ret <vscale x 1 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x half> @test_vslideup_vx_f16mf2(<vscale x 2 x half> %dst, <vscale x 2 x half> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f16mf2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x half> @llvm.riscv.vslideup.vx.nxv2f16.i64(<vscale x 2 x half> %dst, <vscale x 2 x half> %src, i64 %offset)
  ret <vscale x 2 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vslideup_vx_f16m1(<vscale x 4 x half> %dst, <vscale x 4 x half> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f16m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vslideup.vx.nxv4f16.i64(<vscale x 4 x half> %dst, <vscale x 4 x half> %src, i64 %offset)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x half> @test_vslideup_vx_f16m2(<vscale x 8 x half> %dst, <vscale x 8 x half> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f16m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x half> @llvm.riscv.vslideup.vx.nxv8f16.i64(<vscale x 8 x half> %dst, <vscale x 8 x half> %src, i64 %offset)
  ret <vscale x 8 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x half> @test_vslideup_vx_f16m4(<vscale x 16 x half> %dst, <vscale x 16 x half> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f16m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x half> @llvm.riscv.vslideup.vx.nxv16f16.i64(<vscale x 16 x half> %dst, <vscale x 16 x half> %src, i64 %offset)
  ret <vscale x 16 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x half> @test_vslideup_vx_f16m8(<vscale x 32 x half> %dst, <vscale x 32 x half> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f16m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x half> @llvm.riscv.vslideup.vx.nxv32f16.i64(<vscale x 32 x half> %dst, <vscale x 32 x half> %src, i64 %offset)
  ret <vscale x 32 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x float> @test_vslideup_vx_f32mf2(<vscale x 1 x float> %dst, <vscale x 1 x float> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f32mf2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x float> @llvm.riscv.vslideup.vx.nxv1f32.i64(<vscale x 1 x float> %dst, <vscale x 1 x float> %src, i64 %offset)
  ret <vscale x 1 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vslideup_vx_f32m1(<vscale x 2 x float> %dst, <vscale x 2 x float> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f32m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vslideup.vx.nxv2f32.i64(<vscale x 2 x float> %dst, <vscale x 2 x float> %src, i64 %offset)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x float> @test_vslideup_vx_f32m2(<vscale x 4 x float> %dst, <vscale x 4 x float> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f32m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x float> @llvm.riscv.vslideup.vx.nxv4f32.i64(<vscale x 4 x float> %dst, <vscale x 4 x float> %src, i64 %offset)
  ret <vscale x 4 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x float> @test_vslideup_vx_f32m4(<vscale x 8 x float> %dst, <vscale x 8 x float> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f32m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x float> @llvm.riscv.vslideup.vx.nxv8f32.i64(<vscale x 8 x float> %dst, <vscale x 8 x float> %src, i64 %offset)
  ret <vscale x 8 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x float> @test_vslideup_vx_f32m8(<vscale x 16 x float> %dst, <vscale x 16 x float> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f32m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x float> @llvm.riscv.vslideup.vx.nxv16f32.i64(<vscale x 16 x float> %dst, <vscale x 16 x float> %src, i64 %offset)
  ret <vscale x 16 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vslideup_vx_f64m1(<vscale x 1 x double> %dst, <vscale x 1 x double> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f64m1
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vslideup.vx.nxv1f64.i64(<vscale x 1 x double> %dst, <vscale x 1 x double> %src, i64 %offset)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x double> @test_vslideup_vx_f64m2(<vscale x 2 x double> %dst, <vscale x 2 x double> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f64m2
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x double> @llvm.riscv.vslideup.vx.nxv2f64.i64(<vscale x 2 x double> %dst, <vscale x 2 x double> %src, i64 %offset)
  ret <vscale x 2 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x double> @test_vslideup_vx_f64m4(<vscale x 4 x double> %dst, <vscale x 4 x double> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f64m4
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x double> @llvm.riscv.vslideup.vx.nxv4f64.i64(<vscale x 4 x double> %dst, <vscale x 4 x double> %src, i64 %offset)
  ret <vscale x 4 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x double> @test_vslideup_vx_f64m8(<vscale x 8 x double> %dst, <vscale x 8 x double> %src, i64 %offset) {
entry:
; CHECK-LABEL: vslideup_vx_f64m8
; CHECK: vslideup.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x double> @llvm.riscv.vslideup.vx.nxv8f64.i64(<vscale x 8 x double> %dst, <vscale x 8 x double> %src, i64 %offset)
  ret <vscale x 8 x double> %call
}

; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vslideup.vx.nxv16i32.i64(<vscale x 16 x i32>, <vscale x 16 x i32>, i64)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vslideup.vx.nxv16i16.i64(<vscale x 16 x i16>, <vscale x 16 x i16>, i64)
; Function Attrs: nounwind
declare <vscale x 4 x double> @llvm.riscv.vslideup.vx.nxv4f64.i64(<vscale x 4 x double>, <vscale x 4 x double>, i64)
; Function Attrs: nounwind
declare <vscale x 64 x i8> @llvm.riscv.vslideup.vx.nxv64i8.i64(<vscale x 64 x i8>, <vscale x 64 x i8>, i64)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vslideup.vx.nxv1i8.i64(<vscale x 1 x i8>, <vscale x 1 x i8>, i64)
; Function Attrs: nounwind
declare <vscale x 2 x half> @llvm.riscv.vslideup.vx.nxv2f16.i64(<vscale x 2 x half>, <vscale x 2 x half>, i64)
; Function Attrs: nounwind
declare <vscale x 1 x half> @llvm.riscv.vslideup.vx.nxv1f16.i64(<vscale x 1 x half>, <vscale x 1 x half>, i64)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vslideup.vx.nxv2i32.i64(<vscale x 2 x i32>, <vscale x 2 x i32>, i64)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vslideup.vx.nxv1i32.i64(<vscale x 1 x i32>, <vscale x 1 x i32>, i64)
; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vslideup.vx.nxv16i8.i64(<vscale x 16 x i8>, <vscale x 16 x i8>, i64)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vslideup.vx.nxv2i16.i64(<vscale x 2 x i16>, <vscale x 2 x i16>, i64)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vslideup.vx.nxv32i16.i64(<vscale x 32 x i16>, <vscale x 32 x i16>, i64)
; Function Attrs: nounwind
declare <vscale x 8 x half> @llvm.riscv.vslideup.vx.nxv8f16.i64(<vscale x 8 x half>, <vscale x 8 x half>, i64)
; Function Attrs: nounwind
declare <vscale x 8 x double> @llvm.riscv.vslideup.vx.nxv8f64.i64(<vscale x 8 x double>, <vscale x 8 x double>, i64)
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vslideup.vx.nxv8i8.i64(<vscale x 8 x i8>, <vscale x 8 x i8>, i64)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vslideup.vx.nxv2i8.i64(<vscale x 2 x i8>, <vscale x 2 x i8>, i64)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vslideup.vx.nxv8i16.i64(<vscale x 8 x i16>, <vscale x 8 x i16>, i64)
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vslideup.vx.nxv32i8.i64(<vscale x 32 x i8>, <vscale x 32 x i8>, i64)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vslideup.vx.nxv8i32.i64(<vscale x 8 x i32>, <vscale x 8 x i32>, i64)
; Function Attrs: nounwind
declare <vscale x 16 x half> @llvm.riscv.vslideup.vx.nxv16f16.i64(<vscale x 16 x half>, <vscale x 16 x half>, i64)
; Function Attrs: nounwind
declare <vscale x 1 x float> @llvm.riscv.vslideup.vx.nxv1f32.i64(<vscale x 1 x float>, <vscale x 1 x float>, i64)
; Function Attrs: nounwind
declare <vscale x 32 x half> @llvm.riscv.vslideup.vx.nxv32f16.i64(<vscale x 32 x half>, <vscale x 32 x half>, i64)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vslideup.vx.nxv4i32.i64(<vscale x 4 x i32>, <vscale x 4 x i32>, i64)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vslideup.vx.nxv4i8.i64(<vscale x 4 x i8>, <vscale x 4 x i8>, i64)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vslideup.vx.nxv4i16.i64(<vscale x 4 x i16>, <vscale x 4 x i16>, i64)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vslideup.vx.nxv4f16.i64(<vscale x 4 x half>, <vscale x 4 x half>, i64)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vslideup.vx.nxv2i64.i64(<vscale x 2 x i64>, <vscale x 2 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vslideup.vx.nxv1f64.i64(<vscale x 1 x double>, <vscale x 1 x double>, i64)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vslideup.vx.nxv1i16.i64(<vscale x 1 x i16>, <vscale x 1 x i16>, i64)
; Function Attrs: nounwind
declare <vscale x 8 x float> @llvm.riscv.vslideup.vx.nxv8f32.i64(<vscale x 8 x float>, <vscale x 8 x float>, i64)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vslideup.vx.nxv4i64.i64(<vscale x 4 x i64>, <vscale x 4 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vslideup.vx.nxv1i64.i64(<vscale x 1 x i64>, <vscale x 1 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 2 x double> @llvm.riscv.vslideup.vx.nxv2f64.i64(<vscale x 2 x double>, <vscale x 2 x double>, i64)
; Function Attrs: nounwind
declare <vscale x 16 x float> @llvm.riscv.vslideup.vx.nxv16f32.i64(<vscale x 16 x float>, <vscale x 16 x float>, i64)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vslideup.vx.nxv8i64.i64(<vscale x 8 x i64>, <vscale x 8 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 4 x float> @llvm.riscv.vslideup.vx.nxv4f32.i64(<vscale x 4 x float>, <vscale x 4 x float>, i64)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vslideup.vx.nxv2f32.i64(<vscale x 2 x float>, <vscale x 2 x float>, i64)

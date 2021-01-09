; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vadc_vxm_i8mf8(<vscale x 1 x i8> %op1, i8 %op2, <vscale x 1 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i8mf8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vadc.vxm.nxv1i8.i8.nxv1i1(<vscale x 1 x i8> %op1, i8 %op2, <vscale x 1 x i1> %carryin)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vadc_vxm_i8mf4(<vscale x 2 x i8> %op1, i8 %op2, <vscale x 2 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i8mf4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vadc.vxm.nxv2i8.i8.nxv2i1(<vscale x 2 x i8> %op1, i8 %op2, <vscale x 2 x i1> %carryin)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vadc_vxm_i8mf2(<vscale x 4 x i8> %op1, i8 %op2, <vscale x 4 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i8mf2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vadc.vxm.nxv4i8.i8.nxv4i1(<vscale x 4 x i8> %op1, i8 %op2, <vscale x 4 x i1> %carryin)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vadc_vxm_i8m1(<vscale x 8 x i8> %op1, i8 %op2, <vscale x 8 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i8m1
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vadc.vxm.nxv8i8.i8.nxv8i1(<vscale x 8 x i8> %op1, i8 %op2, <vscale x 8 x i1> %carryin)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vadc_vxm_i8m2(<vscale x 16 x i8> %op1, i8 %op2, <vscale x 16 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i8m2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vadc.vxm.nxv16i8.i8.nxv16i1(<vscale x 16 x i8> %op1, i8 %op2, <vscale x 16 x i1> %carryin)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vadc_vxm_i8m4(<vscale x 32 x i8> %op1, i8 %op2, <vscale x 32 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i8m4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vadc.vxm.nxv32i8.i8.nxv32i1(<vscale x 32 x i8> %op1, i8 %op2, <vscale x 32 x i1> %carryin)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vadc_vxm_i8m8(<vscale x 64 x i8> %op1, i8 %op2, <vscale x 64 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i8m8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vadc.vxm.nxv64i8.i8.nxv64i1(<vscale x 64 x i8> %op1, i8 %op2, <vscale x 64 x i1> %carryin)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vadc_vxm_i16mf4(<vscale x 1 x i16> %op1, i16 %op2, <vscale x 1 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i16mf4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vadc.vxm.nxv1i16.i16.nxv1i1(<vscale x 1 x i16> %op1, i16 %op2, <vscale x 1 x i1> %carryin)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vadc_vxm_i16mf2(<vscale x 2 x i16> %op1, i16 %op2, <vscale x 2 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i16mf2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vadc.vxm.nxv2i16.i16.nxv2i1(<vscale x 2 x i16> %op1, i16 %op2, <vscale x 2 x i1> %carryin)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vadc_vxm_i16m1(<vscale x 4 x i16> %op1, i16 %op2, <vscale x 4 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i16m1
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vadc.vxm.nxv4i16.i16.nxv4i1(<vscale x 4 x i16> %op1, i16 %op2, <vscale x 4 x i1> %carryin)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vadc_vxm_i16m2(<vscale x 8 x i16> %op1, i16 %op2, <vscale x 8 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i16m2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vadc.vxm.nxv8i16.i16.nxv8i1(<vscale x 8 x i16> %op1, i16 %op2, <vscale x 8 x i1> %carryin)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vadc_vxm_i16m4(<vscale x 16 x i16> %op1, i16 %op2, <vscale x 16 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i16m4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vadc.vxm.nxv16i16.i16.nxv16i1(<vscale x 16 x i16> %op1, i16 %op2, <vscale x 16 x i1> %carryin)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vadc_vxm_i16m8(<vscale x 32 x i16> %op1, i16 %op2, <vscale x 32 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i16m8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vadc.vxm.nxv32i16.i16.nxv32i1(<vscale x 32 x i16> %op1, i16 %op2, <vscale x 32 x i1> %carryin)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vadc_vxm_i32mf2(<vscale x 1 x i32> %op1, i32 %op2, <vscale x 1 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i32mf2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vadc.vxm.nxv1i32.i32.nxv1i1(<vscale x 1 x i32> %op1, i32 %op2, <vscale x 1 x i1> %carryin)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vadc_vxm_i32m1(<vscale x 2 x i32> %op1, i32 %op2, <vscale x 2 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i32m1
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vadc.vxm.nxv2i32.i32.nxv2i1(<vscale x 2 x i32> %op1, i32 %op2, <vscale x 2 x i1> %carryin)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vadc_vxm_i32m2(<vscale x 4 x i32> %op1, i32 %op2, <vscale x 4 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i32m2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vadc.vxm.nxv4i32.i32.nxv4i1(<vscale x 4 x i32> %op1, i32 %op2, <vscale x 4 x i1> %carryin)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vadc_vxm_i32m4(<vscale x 8 x i32> %op1, i32 %op2, <vscale x 8 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i32m4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vadc.vxm.nxv8i32.i32.nxv8i1(<vscale x 8 x i32> %op1, i32 %op2, <vscale x 8 x i1> %carryin)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vadc_vxm_i32m8(<vscale x 16 x i32> %op1, i32 %op2, <vscale x 16 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i32m8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vadc.vxm.nxv16i32.i32.nxv16i1(<vscale x 16 x i32> %op1, i32 %op2, <vscale x 16 x i1> %carryin)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vadc_vxm_i64m1(<vscale x 1 x i64> %op1, i64 %op2, <vscale x 1 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i64m1
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vadc.vxm.nxv1i64.i64.nxv1i1(<vscale x 1 x i64> %op1, i64 %op2, <vscale x 1 x i1> %carryin)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vadc_vxm_i64m2(<vscale x 2 x i64> %op1, i64 %op2, <vscale x 2 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i64m2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vadc.vxm.nxv2i64.i64.nxv2i1(<vscale x 2 x i64> %op1, i64 %op2, <vscale x 2 x i1> %carryin)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vadc_vxm_i64m4(<vscale x 4 x i64> %op1, i64 %op2, <vscale x 4 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i64m4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vadc.vxm.nxv4i64.i64.nxv4i1(<vscale x 4 x i64> %op1, i64 %op2, <vscale x 4 x i1> %carryin)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vadc_vxm_i64m8(<vscale x 8 x i64> %op1, i64 %op2, <vscale x 8 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_i64m8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vadc.vxm.nxv8i64.i64.nxv8i1(<vscale x 8 x i64> %op1, i64 %op2, <vscale x 8 x i1> %carryin)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vadc_vxm_u8mf8(<vscale x 1 x i8> %op1, i8 %op2, <vscale x 1 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u8mf8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vadc.vxm.nxv1i8.i8.nxv1i1(<vscale x 1 x i8> %op1, i8 %op2, <vscale x 1 x i1> %carryin)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vadc_vxm_u8mf4(<vscale x 2 x i8> %op1, i8 %op2, <vscale x 2 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u8mf4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vadc.vxm.nxv2i8.i8.nxv2i1(<vscale x 2 x i8> %op1, i8 %op2, <vscale x 2 x i1> %carryin)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vadc_vxm_u8mf2(<vscale x 4 x i8> %op1, i8 %op2, <vscale x 4 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u8mf2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vadc.vxm.nxv4i8.i8.nxv4i1(<vscale x 4 x i8> %op1, i8 %op2, <vscale x 4 x i1> %carryin)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vadc_vxm_u8m1(<vscale x 8 x i8> %op1, i8 %op2, <vscale x 8 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u8m1
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vadc.vxm.nxv8i8.i8.nxv8i1(<vscale x 8 x i8> %op1, i8 %op2, <vscale x 8 x i1> %carryin)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vadc_vxm_u8m2(<vscale x 16 x i8> %op1, i8 %op2, <vscale x 16 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u8m2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vadc.vxm.nxv16i8.i8.nxv16i1(<vscale x 16 x i8> %op1, i8 %op2, <vscale x 16 x i1> %carryin)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vadc_vxm_u8m4(<vscale x 32 x i8> %op1, i8 %op2, <vscale x 32 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u8m4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vadc.vxm.nxv32i8.i8.nxv32i1(<vscale x 32 x i8> %op1, i8 %op2, <vscale x 32 x i1> %carryin)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vadc_vxm_u8m8(<vscale x 64 x i8> %op1, i8 %op2, <vscale x 64 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u8m8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vadc.vxm.nxv64i8.i8.nxv64i1(<vscale x 64 x i8> %op1, i8 %op2, <vscale x 64 x i1> %carryin)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vadc_vxm_u16mf4(<vscale x 1 x i16> %op1, i16 %op2, <vscale x 1 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u16mf4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vadc.vxm.nxv1i16.i16.nxv1i1(<vscale x 1 x i16> %op1, i16 %op2, <vscale x 1 x i1> %carryin)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vadc_vxm_u16mf2(<vscale x 2 x i16> %op1, i16 %op2, <vscale x 2 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u16mf2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vadc.vxm.nxv2i16.i16.nxv2i1(<vscale x 2 x i16> %op1, i16 %op2, <vscale x 2 x i1> %carryin)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vadc_vxm_u16m1(<vscale x 4 x i16> %op1, i16 %op2, <vscale x 4 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u16m1
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vadc.vxm.nxv4i16.i16.nxv4i1(<vscale x 4 x i16> %op1, i16 %op2, <vscale x 4 x i1> %carryin)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vadc_vxm_u16m2(<vscale x 8 x i16> %op1, i16 %op2, <vscale x 8 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u16m2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vadc.vxm.nxv8i16.i16.nxv8i1(<vscale x 8 x i16> %op1, i16 %op2, <vscale x 8 x i1> %carryin)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vadc_vxm_u16m4(<vscale x 16 x i16> %op1, i16 %op2, <vscale x 16 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u16m4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vadc.vxm.nxv16i16.i16.nxv16i1(<vscale x 16 x i16> %op1, i16 %op2, <vscale x 16 x i1> %carryin)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vadc_vxm_u16m8(<vscale x 32 x i16> %op1, i16 %op2, <vscale x 32 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u16m8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vadc.vxm.nxv32i16.i16.nxv32i1(<vscale x 32 x i16> %op1, i16 %op2, <vscale x 32 x i1> %carryin)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vadc_vxm_u32mf2(<vscale x 1 x i32> %op1, i32 %op2, <vscale x 1 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u32mf2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vadc.vxm.nxv1i32.i32.nxv1i1(<vscale x 1 x i32> %op1, i32 %op2, <vscale x 1 x i1> %carryin)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vadc_vxm_u32m1(<vscale x 2 x i32> %op1, i32 %op2, <vscale x 2 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u32m1
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vadc.vxm.nxv2i32.i32.nxv2i1(<vscale x 2 x i32> %op1, i32 %op2, <vscale x 2 x i1> %carryin)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vadc_vxm_u32m2(<vscale x 4 x i32> %op1, i32 %op2, <vscale x 4 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u32m2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vadc.vxm.nxv4i32.i32.nxv4i1(<vscale x 4 x i32> %op1, i32 %op2, <vscale x 4 x i1> %carryin)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vadc_vxm_u32m4(<vscale x 8 x i32> %op1, i32 %op2, <vscale x 8 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u32m4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vadc.vxm.nxv8i32.i32.nxv8i1(<vscale x 8 x i32> %op1, i32 %op2, <vscale x 8 x i1> %carryin)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vadc_vxm_u32m8(<vscale x 16 x i32> %op1, i32 %op2, <vscale x 16 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u32m8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vadc.vxm.nxv16i32.i32.nxv16i1(<vscale x 16 x i32> %op1, i32 %op2, <vscale x 16 x i1> %carryin)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vadc_vxm_u64m1(<vscale x 1 x i64> %op1, i64 %op2, <vscale x 1 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u64m1
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vadc.vxm.nxv1i64.i64.nxv1i1(<vscale x 1 x i64> %op1, i64 %op2, <vscale x 1 x i1> %carryin)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vadc_vxm_u64m2(<vscale x 2 x i64> %op1, i64 %op2, <vscale x 2 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u64m2
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vadc.vxm.nxv2i64.i64.nxv2i1(<vscale x 2 x i64> %op1, i64 %op2, <vscale x 2 x i1> %carryin)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vadc_vxm_u64m4(<vscale x 4 x i64> %op1, i64 %op2, <vscale x 4 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u64m4
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vadc.vxm.nxv4i64.i64.nxv4i1(<vscale x 4 x i64> %op1, i64 %op2, <vscale x 4 x i1> %carryin)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vadc_vxm_u64m8(<vscale x 8 x i64> %op1, i64 %op2, <vscale x 8 x i1> %carryin) {
entry:
; CHECK-LABEL: vadc_vxm_u64m8
; CHECK: vadc.vxm {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vadc.vxm.nxv8i64.i64.nxv8i1(<vscale x 8 x i64> %op1, i64 %op2, <vscale x 8 x i1> %carryin)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vadc.vxm.nxv8i8.i8.nxv8i1(<vscale x 8 x i8>, i8, <vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vadc.vxm.nxv1i16.i16.nxv1i1(<vscale x 1 x i16>, i16, <vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vadc.vxm.nxv1i8.i8.nxv1i1(<vscale x 1 x i8>, i8, <vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vadc.vxm.nxv4i16.i16.nxv4i1(<vscale x 4 x i16>, i16, <vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vadc.vxm.nxv8i32.i32.nxv8i1(<vscale x 8 x i32>, i32, <vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 64 x i8> @llvm.riscv.vadc.vxm.nxv64i8.i8.nxv64i1(<vscale x 64 x i8>, i8, <vscale x 64 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vadc.vxm.nxv1i64.i64.nxv1i1(<vscale x 1 x i64>, i64, <vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vadc.vxm.nxv4i64.i64.nxv4i1(<vscale x 4 x i64>, i64, <vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vadc.vxm.nxv16i32.i32.nxv16i1(<vscale x 16 x i32>, i32, <vscale x 16 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vadc.vxm.nxv4i8.i8.nxv4i1(<vscale x 4 x i8>, i8, <vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vadc.vxm.nxv2i8.i8.nxv2i1(<vscale x 2 x i8>, i8, <vscale x 2 x i1>)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vadc.vxm.nxv16i16.i16.nxv16i1(<vscale x 16 x i16>, i16, <vscale x 16 x i1>)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vadc.vxm.nxv32i16.i16.nxv32i1(<vscale x 32 x i16>, i16, <vscale x 32 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vadc.vxm.nxv2i32.i32.nxv2i1(<vscale x 2 x i32>, i32, <vscale x 2 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vadc.vxm.nxv1i32.i32.nxv1i1(<vscale x 1 x i32>, i32, <vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vadc.vxm.nxv2i64.i64.nxv2i1(<vscale x 2 x i64>, i64, <vscale x 2 x i1>)
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vadc.vxm.nxv32i8.i8.nxv32i1(<vscale x 32 x i8>, i8, <vscale x 32 x i1>)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vadc.vxm.nxv8i16.i16.nxv8i1(<vscale x 8 x i16>, i16, <vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vadc.vxm.nxv8i64.i64.nxv8i1(<vscale x 8 x i64>, i64, <vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vadc.vxm.nxv16i8.i8.nxv16i1(<vscale x 16 x i8>, i8, <vscale x 16 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vadc.vxm.nxv4i32.i32.nxv4i1(<vscale x 4 x i32>, i32, <vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vadc.vxm.nxv2i16.i16.nxv2i1(<vscale x 2 x i16>, i16, <vscale x 2 x i1>)

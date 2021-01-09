; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_viota_m_u8mf8(<vscale x 1 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u8mf8
  %call = tail call <vscale x 1 x i8> @llvm.riscv.viota.m.nxv1i8.nxv1i1(<vscale x 1 x i1> %op1)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_viota_m_u8mf4(<vscale x 2 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u8mf4
  %call = tail call <vscale x 2 x i8> @llvm.riscv.viota.m.nxv2i8.nxv2i1(<vscale x 2 x i1> %op1)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_viota_m_u8mf2(<vscale x 4 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u8mf2
  %call = tail call <vscale x 4 x i8> @llvm.riscv.viota.m.nxv4i8.nxv4i1(<vscale x 4 x i1> %op1)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_viota_m_u8m1(<vscale x 8 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u8m1
  %call = tail call <vscale x 8 x i8> @llvm.riscv.viota.m.nxv8i8.nxv8i1(<vscale x 8 x i1> %op1)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_viota_m_u8m2(<vscale x 16 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u8m2
  %call = tail call <vscale x 16 x i8> @llvm.riscv.viota.m.nxv16i8.nxv16i1(<vscale x 16 x i1> %op1)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_viota_m_u8m4(<vscale x 32 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u8m4
  %call = tail call <vscale x 32 x i8> @llvm.riscv.viota.m.nxv32i8.nxv32i1(<vscale x 32 x i1> %op1)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_viota_m_u8m8(<vscale x 64 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u8m8
  %call = tail call <vscale x 64 x i8> @llvm.riscv.viota.m.nxv64i8.nxv64i1(<vscale x 64 x i1> %op1)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_viota_m_u16mf4(<vscale x 1 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u16mf4
  %call = tail call <vscale x 1 x i16> @llvm.riscv.viota.m.nxv1i16.nxv1i1(<vscale x 1 x i1> %op1)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_viota_m_u16mf2(<vscale x 2 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u16mf2
  %call = tail call <vscale x 2 x i16> @llvm.riscv.viota.m.nxv2i16.nxv2i1(<vscale x 2 x i1> %op1)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_viota_m_u16m1(<vscale x 4 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u16m1
  %call = tail call <vscale x 4 x i16> @llvm.riscv.viota.m.nxv4i16.nxv4i1(<vscale x 4 x i1> %op1)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_viota_m_u16m2(<vscale x 8 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u16m2
  %call = tail call <vscale x 8 x i16> @llvm.riscv.viota.m.nxv8i16.nxv8i1(<vscale x 8 x i1> %op1)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_viota_m_u16m4(<vscale x 16 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u16m4
  %call = tail call <vscale x 16 x i16> @llvm.riscv.viota.m.nxv16i16.nxv16i1(<vscale x 16 x i1> %op1)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_viota_m_u16m8(<vscale x 32 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u16m8
  %call = tail call <vscale x 32 x i16> @llvm.riscv.viota.m.nxv32i16.nxv32i1(<vscale x 32 x i1> %op1)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_viota_m_u32mf2(<vscale x 1 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u32mf2
  %call = tail call <vscale x 1 x i32> @llvm.riscv.viota.m.nxv1i32.nxv1i1(<vscale x 1 x i1> %op1)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_viota_m_u32m1(<vscale x 2 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u32m1
  %call = tail call <vscale x 2 x i32> @llvm.riscv.viota.m.nxv2i32.nxv2i1(<vscale x 2 x i1> %op1)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_viota_m_u32m2(<vscale x 4 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u32m2
  %call = tail call <vscale x 4 x i32> @llvm.riscv.viota.m.nxv4i32.nxv4i1(<vscale x 4 x i1> %op1)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_viota_m_u32m4(<vscale x 8 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u32m4
  %call = tail call <vscale x 8 x i32> @llvm.riscv.viota.m.nxv8i32.nxv8i1(<vscale x 8 x i1> %op1)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_viota_m_u32m8(<vscale x 16 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u32m8
  %call = tail call <vscale x 16 x i32> @llvm.riscv.viota.m.nxv16i32.nxv16i1(<vscale x 16 x i1> %op1)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_viota_m_u64m1(<vscale x 1 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u64m1
  %call = tail call <vscale x 1 x i64> @llvm.riscv.viota.m.nxv1i64.nxv1i1(<vscale x 1 x i1> %op1)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_viota_m_u64m2(<vscale x 2 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u64m2
  %call = tail call <vscale x 2 x i64> @llvm.riscv.viota.m.nxv2i64.nxv2i1(<vscale x 2 x i1> %op1)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_viota_m_u64m4(<vscale x 4 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u64m4
  %call = tail call <vscale x 4 x i64> @llvm.riscv.viota.m.nxv4i64.nxv4i1(<vscale x 4 x i1> %op1)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_viota_m_u64m8(<vscale x 8 x i1> %op1) {
entry:
; CHECK-LABEL: viota_m_u64m8
  %call = tail call <vscale x 8 x i64> @llvm.riscv.viota.m.nxv8i64.nxv8i1(<vscale x 8 x i1> %op1)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.viota.m.nxv8i16.nxv8i1(<vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.viota.m.nxv2i32.nxv2i1(<vscale x 2 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.viota.m.nxv1i8.nxv1i1(<vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.viota.m.nxv8i64.nxv8i1(<vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.viota.m.nxv1i64.nxv1i1(<vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.viota.m.nxv1i32.nxv1i1(<vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.viota.m.nxv2i8.nxv2i1(<vscale x 2 x i1>)
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.viota.m.nxv8i8.nxv8i1(<vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.viota.m.nxv4i16.nxv4i1(<vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.viota.m.nxv16i16.nxv16i1(<vscale x 16 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.viota.m.nxv1i16.nxv1i1(<vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.viota.m.nxv2i16.nxv2i1(<vscale x 2 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.viota.m.nxv4i32.nxv4i1(<vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.viota.m.nxv4i64.nxv4i1(<vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.viota.m.nxv16i32.nxv16i1(<vscale x 16 x i1>)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.viota.m.nxv32i16.nxv32i1(<vscale x 32 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.viota.m.nxv4i8.nxv4i1(<vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 64 x i8> @llvm.riscv.viota.m.nxv64i8.nxv64i1(<vscale x 64 x i1>)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.viota.m.nxv8i32.nxv8i1(<vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.viota.m.nxv16i8.nxv16i1(<vscale x 16 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.viota.m.nxv2i64.nxv2i1(<vscale x 2 x i1>)
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.viota.m.nxv32i8.nxv32i1(<vscale x 32 x i1>)

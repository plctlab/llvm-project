; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vqmaccu_vv_u32mf2(<vscale x 1 x i32> %acc, <vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2) {
entry:
; CHECK-LABEL: vqmaccu_vv_u32mf2
; CHECK: vqmaccu.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vqmaccu.vv.nxv1i32.nxv1i8(<vscale x 1 x i32> %acc, <vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vqmaccu_vv_u32m1(<vscale x 2 x i32> %acc, <vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2) {
entry:
; CHECK-LABEL: vqmaccu_vv_u32m1
; CHECK: vqmaccu.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vqmaccu.vv.nxv2i32.nxv2i8(<vscale x 2 x i32> %acc, <vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vqmaccu_vv_u32m2(<vscale x 4 x i32> %acc, <vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2) {
entry:
; CHECK-LABEL: vqmaccu_vv_u32m2
; CHECK: vqmaccu.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vqmaccu.vv.nxv4i32.nxv4i8(<vscale x 4 x i32> %acc, <vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vqmaccu_vv_u32m4(<vscale x 8 x i32> %acc, <vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2) {
entry:
; CHECK-LABEL: vqmaccu_vv_u32m4
; CHECK: vqmaccu.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vqmaccu.vv.nxv8i32.nxv8i8(<vscale x 8 x i32> %acc, <vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vqmaccu_vv_u32m8(<vscale x 16 x i32> %acc, <vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2) {
entry:
; CHECK-LABEL: vqmaccu_vv_u32m8
; CHECK: vqmaccu.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vqmaccu.vv.nxv16i32.nxv16i8(<vscale x 16 x i32> %acc, <vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vqmaccu_vv_u64m1(<vscale x 1 x i64> %acc, <vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2) {
entry:
; CHECK-LABEL: vqmaccu_vv_u64m1
; CHECK: vqmaccu.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vqmaccu.vv.nxv1i64.nxv1i16(<vscale x 1 x i64> %acc, <vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vqmaccu_vv_u64m2(<vscale x 2 x i64> %acc, <vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2) {
entry:
; CHECK-LABEL: vqmaccu_vv_u64m2
; CHECK: vqmaccu.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vqmaccu.vv.nxv2i64.nxv2i16(<vscale x 2 x i64> %acc, <vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vqmaccu_vv_u64m4(<vscale x 4 x i64> %acc, <vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2) {
entry:
; CHECK-LABEL: vqmaccu_vv_u64m4
; CHECK: vqmaccu.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vqmaccu.vv.nxv4i64.nxv4i16(<vscale x 4 x i64> %acc, <vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vqmaccu_vv_u64m8(<vscale x 8 x i64> %acc, <vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2) {
entry:
; CHECK-LABEL: vqmaccu_vv_u64m8
; CHECK: vqmaccu.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vqmaccu.vv.nxv8i64.nxv8i16(<vscale x 8 x i64> %acc, <vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vqmaccu.vv.nxv2i32.nxv2i8(<vscale x 2 x i32>, <vscale x 2 x i8>, <vscale x 2 x i8>)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vqmaccu.vv.nxv4i32.nxv4i8(<vscale x 4 x i32>, <vscale x 4 x i8>, <vscale x 4 x i8>)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vqmaccu.vv.nxv8i64.nxv8i16(<vscale x 8 x i64>, <vscale x 8 x i16>, <vscale x 8 x i16>)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vqmaccu.vv.nxv16i32.nxv16i8(<vscale x 16 x i32>, <vscale x 16 x i8>, <vscale x 16 x i8>)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vqmaccu.vv.nxv8i32.nxv8i8(<vscale x 8 x i32>, <vscale x 8 x i8>, <vscale x 8 x i8>)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vqmaccu.vv.nxv4i64.nxv4i16(<vscale x 4 x i64>, <vscale x 4 x i16>, <vscale x 4 x i16>)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vqmaccu.vv.nxv1i64.nxv1i16(<vscale x 1 x i64>, <vscale x 1 x i16>, <vscale x 1 x i16>)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vqmaccu.vv.nxv1i32.nxv1i8(<vscale x 1 x i32>, <vscale x 1 x i8>, <vscale x 1 x i8>)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vqmaccu.vv.nxv2i64.nxv2i16(<vscale x 2 x i64>, <vscale x 2 x i16>, <vscale x 2 x i16>)

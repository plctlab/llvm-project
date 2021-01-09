; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vnsra_wv_i8mf8(<vscale x 1 x i16> %op1, <vscale x 1 x i8> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i8mf8
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vnsra.wv.nxv1i8.nxv1i16(<vscale x 1 x i16> %op1, <vscale x 1 x i8> %op2)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vnsra_wv_i8mf4(<vscale x 2 x i16> %op1, <vscale x 2 x i8> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i8mf4
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vnsra.wv.nxv2i8.nxv2i16(<vscale x 2 x i16> %op1, <vscale x 2 x i8> %op2)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vnsra_wv_i8mf2(<vscale x 4 x i16> %op1, <vscale x 4 x i8> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i8mf2
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vnsra.wv.nxv4i8.nxv4i16(<vscale x 4 x i16> %op1, <vscale x 4 x i8> %op2)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vnsra_wv_i8m1(<vscale x 8 x i16> %op1, <vscale x 8 x i8> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i8m1
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vnsra.wv.nxv8i8.nxv8i16(<vscale x 8 x i16> %op1, <vscale x 8 x i8> %op2)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vnsra_wv_i8m2(<vscale x 16 x i16> %op1, <vscale x 16 x i8> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i8m2
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vnsra.wv.nxv16i8.nxv16i16(<vscale x 16 x i16> %op1, <vscale x 16 x i8> %op2)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vnsra_wv_i8m4(<vscale x 32 x i16> %op1, <vscale x 32 x i8> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i8m4
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vnsra.wv.nxv32i8.nxv32i16(<vscale x 32 x i16> %op1, <vscale x 32 x i8> %op2)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vnsra_wv_i16mf4(<vscale x 1 x i32> %op1, <vscale x 1 x i16> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i16mf4
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vnsra.wv.nxv1i16.nxv1i32(<vscale x 1 x i32> %op1, <vscale x 1 x i16> %op2)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vnsra_wv_i16mf2(<vscale x 2 x i32> %op1, <vscale x 2 x i16> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i16mf2
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vnsra.wv.nxv2i16.nxv2i32(<vscale x 2 x i32> %op1, <vscale x 2 x i16> %op2)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vnsra_wv_i16m1(<vscale x 4 x i32> %op1, <vscale x 4 x i16> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i16m1
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vnsra.wv.nxv4i16.nxv4i32(<vscale x 4 x i32> %op1, <vscale x 4 x i16> %op2)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vnsra_wv_i16m2(<vscale x 8 x i32> %op1, <vscale x 8 x i16> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i16m2
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vnsra.wv.nxv8i16.nxv8i32(<vscale x 8 x i32> %op1, <vscale x 8 x i16> %op2)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vnsra_wv_i16m4(<vscale x 16 x i32> %op1, <vscale x 16 x i16> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i16m4
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vnsra.wv.nxv16i16.nxv16i32(<vscale x 16 x i32> %op1, <vscale x 16 x i16> %op2)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vnsra_wv_i32mf2(<vscale x 1 x i64> %op1, <vscale x 1 x i32> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i32mf2
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vnsra.wv.nxv1i32.nxv1i64(<vscale x 1 x i64> %op1, <vscale x 1 x i32> %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vnsra_wv_i32m1(<vscale x 2 x i64> %op1, <vscale x 2 x i32> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i32m1
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vnsra.wv.nxv2i32.nxv2i64(<vscale x 2 x i64> %op1, <vscale x 2 x i32> %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vnsra_wv_i32m2(<vscale x 4 x i64> %op1, <vscale x 4 x i32> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i32m2
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vnsra.wv.nxv4i32.nxv4i64(<vscale x 4 x i64> %op1, <vscale x 4 x i32> %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vnsra_wv_i32m4(<vscale x 8 x i64> %op1, <vscale x 8 x i32> %op2) {
entry:
; CHECK-LABEL: vnsra_wv_i32m4
; CHECK: vnsra.wv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vnsra.wv.nxv8i32.nxv8i64(<vscale x 8 x i64> %op1, <vscale x 8 x i32> %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vnsra.wv.nxv2i32.nxv2i64(<vscale x 2 x i64>, <vscale x 2 x i32>)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vnsra.wv.nxv8i32.nxv8i64(<vscale x 8 x i64>, <vscale x 8 x i32>)
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vnsra.wv.nxv8i8.nxv8i16(<vscale x 8 x i16>, <vscale x 8 x i8>)
; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vnsra.wv.nxv16i8.nxv16i16(<vscale x 16 x i16>, <vscale x 16 x i8>)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vnsra.wv.nxv8i16.nxv8i32(<vscale x 8 x i32>, <vscale x 8 x i16>)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vnsra.wv.nxv2i8.nxv2i16(<vscale x 2 x i16>, <vscale x 2 x i8>)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vnsra.wv.nxv2i16.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i16>)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vnsra.wv.nxv4i16.nxv4i32(<vscale x 4 x i32>, <vscale x 4 x i16>)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vnsra.wv.nxv4i8.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i8>)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vnsra.wv.nxv1i32.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i32>)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vnsra.wv.nxv1i16.nxv1i32(<vscale x 1 x i32>, <vscale x 1 x i16>)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vnsra.wv.nxv4i32.nxv4i64(<vscale x 4 x i64>, <vscale x 4 x i32>)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vnsra.wv.nxv16i16.nxv16i32(<vscale x 16 x i32>, <vscale x 16 x i16>)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vnsra.wv.nxv1i8.nxv1i16(<vscale x 1 x i16>, <vscale x 1 x i8>)
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vnsra.wv.nxv32i8.nxv32i16(<vscale x 32 x i16>, <vscale x 32 x i8>)

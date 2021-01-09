; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x half> @test_vmerge_vvm_f16mf4(<vscale x 1 x i1> %mask, <vscale x 1 x half> %op1, <vscale x 1 x half> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f16mf4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x half> @llvm.riscv.vmerge.vvm.nxv1f16.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x half> %op1, <vscale x 1 x half> %op2)
  ret <vscale x 1 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x half> @test_vmerge_vvm_f16mf2(<vscale x 2 x i1> %mask, <vscale x 2 x half> %op1, <vscale x 2 x half> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f16mf2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x half> @llvm.riscv.vmerge.vvm.nxv2f16.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x half> %op1, <vscale x 2 x half> %op2)
  ret <vscale x 2 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vmerge_vvm_f16m1(<vscale x 4 x i1> %mask, <vscale x 4 x half> %op1, <vscale x 4 x half> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f16m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vmerge.vvm.nxv4f16.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x half> %op1, <vscale x 4 x half> %op2)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x half> @test_vmerge_vvm_f16m2(<vscale x 8 x i1> %mask, <vscale x 8 x half> %op1, <vscale x 8 x half> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f16m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x half> @llvm.riscv.vmerge.vvm.nxv8f16.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x half> %op1, <vscale x 8 x half> %op2)
  ret <vscale x 8 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x half> @test_vmerge_vvm_f16m4(<vscale x 16 x i1> %mask, <vscale x 16 x half> %op1, <vscale x 16 x half> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f16m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x half> @llvm.riscv.vmerge.vvm.nxv16f16.nxv16i1(<vscale x 16 x i1> %mask, <vscale x 16 x half> %op1, <vscale x 16 x half> %op2)
  ret <vscale x 16 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x half> @test_vmerge_vvm_f16m8(<vscale x 32 x i1> %mask, <vscale x 32 x half> %op1, <vscale x 32 x half> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f16m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x half> @llvm.riscv.vmerge.vvm.nxv32f16.nxv32i1(<vscale x 32 x i1> %mask, <vscale x 32 x half> %op1, <vscale x 32 x half> %op2)
  ret <vscale x 32 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x float> @test_vmerge_vvm_f32mf2(<vscale x 1 x i1> %mask, <vscale x 1 x float> %op1, <vscale x 1 x float> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f32mf2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x float> @llvm.riscv.vmerge.vvm.nxv1f32.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x float> %op1, <vscale x 1 x float> %op2)
  ret <vscale x 1 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vmerge_vvm_f32m1(<vscale x 2 x i1> %mask, <vscale x 2 x float> %op1, <vscale x 2 x float> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f32m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vmerge.vvm.nxv2f32.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x float> %op1, <vscale x 2 x float> %op2)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x float> @test_vmerge_vvm_f32m2(<vscale x 4 x i1> %mask, <vscale x 4 x float> %op1, <vscale x 4 x float> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f32m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x float> @llvm.riscv.vmerge.vvm.nxv4f32.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x float> %op1, <vscale x 4 x float> %op2)
  ret <vscale x 4 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x float> @test_vmerge_vvm_f32m4(<vscale x 8 x i1> %mask, <vscale x 8 x float> %op1, <vscale x 8 x float> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f32m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x float> @llvm.riscv.vmerge.vvm.nxv8f32.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x float> %op1, <vscale x 8 x float> %op2)
  ret <vscale x 8 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x float> @test_vmerge_vvm_f32m8(<vscale x 16 x i1> %mask, <vscale x 16 x float> %op1, <vscale x 16 x float> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f32m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x float> @llvm.riscv.vmerge.vvm.nxv16f32.nxv16i1(<vscale x 16 x i1> %mask, <vscale x 16 x float> %op1, <vscale x 16 x float> %op2)
  ret <vscale x 16 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vmerge_vvm_f64m1(<vscale x 1 x i1> %mask, <vscale x 1 x double> %op1, <vscale x 1 x double> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f64m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vmerge.vvm.nxv1f64.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x double> %op1, <vscale x 1 x double> %op2)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x double> @test_vmerge_vvm_f64m2(<vscale x 2 x i1> %mask, <vscale x 2 x double> %op1, <vscale x 2 x double> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f64m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x double> @llvm.riscv.vmerge.vvm.nxv2f64.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x double> %op1, <vscale x 2 x double> %op2)
  ret <vscale x 2 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x double> @test_vmerge_vvm_f64m4(<vscale x 4 x i1> %mask, <vscale x 4 x double> %op1, <vscale x 4 x double> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f64m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x double> @llvm.riscv.vmerge.vvm.nxv4f64.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x double> %op1, <vscale x 4 x double> %op2)
  ret <vscale x 4 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x double> @test_vmerge_vvm_f64m8(<vscale x 8 x i1> %mask, <vscale x 8 x double> %op1, <vscale x 8 x double> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_f64m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x double> @llvm.riscv.vmerge.vvm.nxv8f64.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x double> %op1, <vscale x 8 x double> %op2)
  ret <vscale x 8 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vmerge_vvm_i8mf8(<vscale x 1 x i1> %mask, <vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i8mf8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vmerge.vvm.nxv1i8.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vmerge_vvm_i8mf4(<vscale x 2 x i1> %mask, <vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i8mf4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vmerge.vvm.nxv2i8.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vmerge_vvm_i8mf2(<vscale x 4 x i1> %mask, <vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i8mf2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vmerge.vvm.nxv4i8.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vmerge_vvm_i8m1(<vscale x 8 x i1> %mask, <vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i8m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vmerge.vvm.nxv8i8.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vmerge_vvm_i8m2(<vscale x 16 x i1> %mask, <vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i8m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vmerge.vvm.nxv16i8.nxv16i1(<vscale x 16 x i1> %mask, <vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vmerge_vvm_i8m4(<vscale x 32 x i1> %mask, <vscale x 32 x i8> %op1, <vscale x 32 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i8m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vmerge.vvm.nxv32i8.nxv32i1(<vscale x 32 x i1> %mask, <vscale x 32 x i8> %op1, <vscale x 32 x i8> %op2)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vmerge_vvm_i8m8(<vscale x 64 x i1> %mask, <vscale x 64 x i8> %op1, <vscale x 64 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i8m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vmerge.vvm.nxv64i8.nxv64i1(<vscale x 64 x i1> %mask, <vscale x 64 x i8> %op1, <vscale x 64 x i8> %op2)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vmerge_vvm_i16mf4(<vscale x 1 x i1> %mask, <vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i16mf4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vmerge.vvm.nxv1i16.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vmerge_vvm_i16mf2(<vscale x 2 x i1> %mask, <vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i16mf2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vmerge.vvm.nxv2i16.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vmerge_vvm_i16m1(<vscale x 4 x i1> %mask, <vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i16m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vmerge.vvm.nxv4i16.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vmerge_vvm_i16m2(<vscale x 8 x i1> %mask, <vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i16m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vmerge.vvm.nxv8i16.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vmerge_vvm_i16m4(<vscale x 16 x i1> %mask, <vscale x 16 x i16> %op1, <vscale x 16 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i16m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vmerge.vvm.nxv16i16.nxv16i1(<vscale x 16 x i1> %mask, <vscale x 16 x i16> %op1, <vscale x 16 x i16> %op2)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vmerge_vvm_i16m8(<vscale x 32 x i1> %mask, <vscale x 32 x i16> %op1, <vscale x 32 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i16m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vmerge.vvm.nxv32i16.nxv32i1(<vscale x 32 x i1> %mask, <vscale x 32 x i16> %op1, <vscale x 32 x i16> %op2)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vmerge_vvm_i32mf2(<vscale x 1 x i1> %mask, <vscale x 1 x i32> %op1, <vscale x 1 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i32mf2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vmerge.vvm.nxv1i32.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x i32> %op1, <vscale x 1 x i32> %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vmerge_vvm_i32m1(<vscale x 2 x i1> %mask, <vscale x 2 x i32> %op1, <vscale x 2 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i32m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vmerge.vvm.nxv2i32.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x i32> %op1, <vscale x 2 x i32> %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vmerge_vvm_i32m2(<vscale x 4 x i1> %mask, <vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i32m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vmerge.vvm.nxv4i32.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vmerge_vvm_i32m4(<vscale x 8 x i1> %mask, <vscale x 8 x i32> %op1, <vscale x 8 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i32m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vmerge.vvm.nxv8i32.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x i32> %op1, <vscale x 8 x i32> %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vmerge_vvm_i32m8(<vscale x 16 x i1> %mask, <vscale x 16 x i32> %op1, <vscale x 16 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i32m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vmerge.vvm.nxv16i32.nxv16i1(<vscale x 16 x i1> %mask, <vscale x 16 x i32> %op1, <vscale x 16 x i32> %op2)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vmerge_vvm_i64m1(<vscale x 1 x i1> %mask, <vscale x 1 x i64> %op1, <vscale x 1 x i64> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i64m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vmerge.vvm.nxv1i64.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x i64> %op1, <vscale x 1 x i64> %op2)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vmerge_vvm_i64m2(<vscale x 2 x i1> %mask, <vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i64m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vmerge.vvm.nxv2i64.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vmerge_vvm_i64m4(<vscale x 4 x i1> %mask, <vscale x 4 x i64> %op1, <vscale x 4 x i64> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i64m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vmerge.vvm.nxv4i64.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x i64> %op1, <vscale x 4 x i64> %op2)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vmerge_vvm_i64m8(<vscale x 8 x i1> %mask, <vscale x 8 x i64> %op1, <vscale x 8 x i64> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_i64m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vmerge.vvm.nxv8i64.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x i64> %op1, <vscale x 8 x i64> %op2)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vmerge_vvm_u8mf8(<vscale x 1 x i1> %mask, <vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u8mf8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vmerge.vvm.nxv1i8.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vmerge_vvm_u8mf4(<vscale x 2 x i1> %mask, <vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u8mf4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vmerge.vvm.nxv2i8.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vmerge_vvm_u8mf2(<vscale x 4 x i1> %mask, <vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u8mf2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vmerge.vvm.nxv4i8.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vmerge_vvm_u8m1(<vscale x 8 x i1> %mask, <vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u8m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vmerge.vvm.nxv8i8.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vmerge_vvm_u8m2(<vscale x 16 x i1> %mask, <vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u8m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vmerge.vvm.nxv16i8.nxv16i1(<vscale x 16 x i1> %mask, <vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vmerge_vvm_u8m4(<vscale x 32 x i1> %mask, <vscale x 32 x i8> %op1, <vscale x 32 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u8m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vmerge.vvm.nxv32i8.nxv32i1(<vscale x 32 x i1> %mask, <vscale x 32 x i8> %op1, <vscale x 32 x i8> %op2)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vmerge_vvm_u8m8(<vscale x 64 x i1> %mask, <vscale x 64 x i8> %op1, <vscale x 64 x i8> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u8m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vmerge.vvm.nxv64i8.nxv64i1(<vscale x 64 x i1> %mask, <vscale x 64 x i8> %op1, <vscale x 64 x i8> %op2)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vmerge_vvm_u16mf4(<vscale x 1 x i1> %mask, <vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u16mf4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vmerge.vvm.nxv1i16.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vmerge_vvm_u16mf2(<vscale x 2 x i1> %mask, <vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u16mf2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vmerge.vvm.nxv2i16.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vmerge_vvm_u16m1(<vscale x 4 x i1> %mask, <vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u16m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vmerge.vvm.nxv4i16.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vmerge_vvm_u16m2(<vscale x 8 x i1> %mask, <vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u16m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vmerge.vvm.nxv8i16.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vmerge_vvm_u16m4(<vscale x 16 x i1> %mask, <vscale x 16 x i16> %op1, <vscale x 16 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u16m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vmerge.vvm.nxv16i16.nxv16i1(<vscale x 16 x i1> %mask, <vscale x 16 x i16> %op1, <vscale x 16 x i16> %op2)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vmerge_vvm_u16m8(<vscale x 32 x i1> %mask, <vscale x 32 x i16> %op1, <vscale x 32 x i16> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u16m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vmerge.vvm.nxv32i16.nxv32i1(<vscale x 32 x i1> %mask, <vscale x 32 x i16> %op1, <vscale x 32 x i16> %op2)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vmerge_vvm_u32mf2(<vscale x 1 x i1> %mask, <vscale x 1 x i32> %op1, <vscale x 1 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u32mf2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vmerge.vvm.nxv1i32.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x i32> %op1, <vscale x 1 x i32> %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vmerge_vvm_u32m1(<vscale x 2 x i1> %mask, <vscale x 2 x i32> %op1, <vscale x 2 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u32m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vmerge.vvm.nxv2i32.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x i32> %op1, <vscale x 2 x i32> %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vmerge_vvm_u32m2(<vscale x 4 x i1> %mask, <vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u32m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vmerge.vvm.nxv4i32.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vmerge_vvm_u32m4(<vscale x 8 x i1> %mask, <vscale x 8 x i32> %op1, <vscale x 8 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u32m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vmerge.vvm.nxv8i32.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x i32> %op1, <vscale x 8 x i32> %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vmerge_vvm_u32m8(<vscale x 16 x i1> %mask, <vscale x 16 x i32> %op1, <vscale x 16 x i32> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u32m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vmerge.vvm.nxv16i32.nxv16i1(<vscale x 16 x i1> %mask, <vscale x 16 x i32> %op1, <vscale x 16 x i32> %op2)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vmerge_vvm_u64m1(<vscale x 1 x i1> %mask, <vscale x 1 x i64> %op1, <vscale x 1 x i64> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u64m1
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vmerge.vvm.nxv1i64.nxv1i1(<vscale x 1 x i1> %mask, <vscale x 1 x i64> %op1, <vscale x 1 x i64> %op2)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vmerge_vvm_u64m2(<vscale x 2 x i1> %mask, <vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u64m2
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vmerge.vvm.nxv2i64.nxv2i1(<vscale x 2 x i1> %mask, <vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vmerge_vvm_u64m4(<vscale x 4 x i1> %mask, <vscale x 4 x i64> %op1, <vscale x 4 x i64> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u64m4
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vmerge.vvm.nxv4i64.nxv4i1(<vscale x 4 x i1> %mask, <vscale x 4 x i64> %op1, <vscale x 4 x i64> %op2)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vmerge_vvm_u64m8(<vscale x 8 x i1> %mask, <vscale x 8 x i64> %op1, <vscale x 8 x i64> %op2) {
entry:
; CHECK-LABEL: vmerge_vvm_u64m8
; CHECK: vmerge.vvm {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vmerge.vvm.nxv8i64.nxv8i1(<vscale x 8 x i1> %mask, <vscale x 8 x i64> %op1, <vscale x 8 x i64> %op2)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 1 x half> @llvm.riscv.vmerge.vvm.nxv1f16.nxv1i1(<vscale x 1 x i1>, <vscale x 1 x half>, <vscale x 1 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x float> @llvm.riscv.vmerge.vvm.nxv4f32.nxv4i1(<vscale x 4 x i1>, <vscale x 4 x float>, <vscale x 4 x float>)
; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vmerge.vvm.nxv16i8.nxv16i1(<vscale x 16 x i1>, <vscale x 16 x i8>, <vscale x 16 x i8>)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vmerge.vvm.nxv1i16.nxv1i1(<vscale x 1 x i1>, <vscale x 1 x i16>, <vscale x 1 x i16>)
; Function Attrs: nounwind
declare <vscale x 1 x float> @llvm.riscv.vmerge.vvm.nxv1f32.nxv1i1(<vscale x 1 x i1>, <vscale x 1 x float>, <vscale x 1 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vmerge.vvm.nxv1f64.nxv1i1(<vscale x 1 x i1>, <vscale x 1 x double>, <vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vmerge.vvm.nxv8i8.nxv8i1(<vscale x 8 x i1>, <vscale x 8 x i8>, <vscale x 8 x i8>)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vmerge.vvm.nxv8i16.nxv8i1(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x i16>)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vmerge.vvm.nxv2i64.nxv2i1(<vscale x 2 x i1>, <vscale x 2 x i64>, <vscale x 2 x i64>)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vmerge.vvm.nxv1i8.nxv1i1(<vscale x 1 x i1>, <vscale x 1 x i8>, <vscale x 1 x i8>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vmerge.vvm.nxv2f32.nxv2i1(<vscale x 2 x i1>, <vscale x 2 x float>, <vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vmerge.vvm.nxv16i16.nxv16i1(<vscale x 16 x i1>, <vscale x 16 x i16>, <vscale x 16 x i16>)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vmerge.vvm.nxv4i8.nxv4i1(<vscale x 4 x i1>, <vscale x 4 x i8>, <vscale x 4 x i8>)
; Function Attrs: nounwind
declare <vscale x 8 x half> @llvm.riscv.vmerge.vvm.nxv8f16.nxv8i1(<vscale x 8 x i1>, <vscale x 8 x half>, <vscale x 8 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vmerge.vvm.nxv4i32.nxv4i1(<vscale x 4 x i1>, <vscale x 4 x i32>, <vscale x 4 x i32>)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vmerge.vvm.nxv8i32.nxv8i1(<vscale x 8 x i1>, <vscale x 8 x i32>, <vscale x 8 x i32>)
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vmerge.vvm.nxv32i8.nxv32i1(<vscale x 32 x i1>, <vscale x 32 x i8>, <vscale x 32 x i8>)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vmerge.vvm.nxv8i64.nxv8i1(<vscale x 8 x i1>, <vscale x 8 x i64>, <vscale x 8 x i64>)
; Function Attrs: nounwind
declare <vscale x 2 x half> @llvm.riscv.vmerge.vvm.nxv2f16.nxv2i1(<vscale x 2 x i1>, <vscale x 2 x half>, <vscale x 2 x half>)
; Function Attrs: nounwind
declare <vscale x 16 x float> @llvm.riscv.vmerge.vvm.nxv16f32.nxv16i1(<vscale x 16 x i1>, <vscale x 16 x float>, <vscale x 16 x float>)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vmerge.vvm.nxv16i32.nxv16i1(<vscale x 16 x i1>, <vscale x 16 x i32>, <vscale x 16 x i32>)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vmerge.vvm.nxv32i16.nxv32i1(<vscale x 32 x i1>, <vscale x 32 x i16>, <vscale x 32 x i16>)
; Function Attrs: nounwind
declare <vscale x 4 x double> @llvm.riscv.vmerge.vvm.nxv4f64.nxv4i1(<vscale x 4 x i1>, <vscale x 4 x double>, <vscale x 4 x double>)
; Function Attrs: nounwind
declare <vscale x 32 x half> @llvm.riscv.vmerge.vvm.nxv32f16.nxv32i1(<vscale x 32 x i1>, <vscale x 32 x half>, <vscale x 32 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x float> @llvm.riscv.vmerge.vvm.nxv8f32.nxv8i1(<vscale x 8 x i1>, <vscale x 8 x float>, <vscale x 8 x float>)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vmerge.vvm.nxv4i64.nxv4i1(<vscale x 4 x i1>, <vscale x 4 x i64>, <vscale x 4 x i64>)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vmerge.vvm.nxv1i32.nxv1i1(<vscale x 1 x i1>, <vscale x 1 x i32>, <vscale x 1 x i32>)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vmerge.vvm.nxv2i8.nxv2i1(<vscale x 2 x i1>, <vscale x 2 x i8>, <vscale x 2 x i8>)
; Function Attrs: nounwind
declare <vscale x 16 x half> @llvm.riscv.vmerge.vvm.nxv16f16.nxv16i1(<vscale x 16 x i1>, <vscale x 16 x half>, <vscale x 16 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vmerge.vvm.nxv4f16.nxv4i1(<vscale x 4 x i1>, <vscale x 4 x half>, <vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x double> @llvm.riscv.vmerge.vvm.nxv8f64.nxv8i1(<vscale x 8 x i1>, <vscale x 8 x double>, <vscale x 8 x double>)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vmerge.vvm.nxv1i64.nxv1i1(<vscale x 1 x i1>, <vscale x 1 x i64>, <vscale x 1 x i64>)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vmerge.vvm.nxv2i16.nxv2i1(<vscale x 2 x i1>, <vscale x 2 x i16>, <vscale x 2 x i16>)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vmerge.vvm.nxv4i16.nxv4i1(<vscale x 4 x i1>, <vscale x 4 x i16>, <vscale x 4 x i16>)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vmerge.vvm.nxv2i32.nxv2i1(<vscale x 2 x i1>, <vscale x 2 x i32>, <vscale x 2 x i32>)
; Function Attrs: nounwind
declare <vscale x 64 x i8> @llvm.riscv.vmerge.vvm.nxv64i8.nxv64i1(<vscale x 64 x i1>, <vscale x 64 x i8>, <vscale x 64 x i8>)
; Function Attrs: nounwind
declare <vscale x 2 x double> @llvm.riscv.vmerge.vvm.nxv2f64.nxv2i1(<vscale x 2 x i1>, <vscale x 2 x double>, <vscale x 2 x double>)

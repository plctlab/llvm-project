; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x half> @test_vfadd_vv_f16mf4(<vscale x 1 x half> %op1, <vscale x 1 x half> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f16mf4
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x half> @llvm.riscv.vfadd.vv.nxv1f16(<vscale x 1 x half> %op1, <vscale x 1 x half> %op2)
  ret <vscale x 1 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x half> @test_vfadd_vv_f16mf2(<vscale x 2 x half> %op1, <vscale x 2 x half> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f16mf2
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x half> @llvm.riscv.vfadd.vv.nxv2f16(<vscale x 2 x half> %op1, <vscale x 2 x half> %op2)
  ret <vscale x 2 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfadd_vv_f16m1(<vscale x 4 x half> %op1, <vscale x 4 x half> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f16m1
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfadd.vv.nxv4f16(<vscale x 4 x half> %op1, <vscale x 4 x half> %op2)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x half> @test_vfadd_vv_f16m2(<vscale x 8 x half> %op1, <vscale x 8 x half> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f16m2
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x half> @llvm.riscv.vfadd.vv.nxv8f16(<vscale x 8 x half> %op1, <vscale x 8 x half> %op2)
  ret <vscale x 8 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x half> @test_vfadd_vv_f16m4(<vscale x 16 x half> %op1, <vscale x 16 x half> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f16m4
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x half> @llvm.riscv.vfadd.vv.nxv16f16(<vscale x 16 x half> %op1, <vscale x 16 x half> %op2)
  ret <vscale x 16 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x half> @test_vfadd_vv_f16m8(<vscale x 32 x half> %op1, <vscale x 32 x half> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f16m8
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x half> @llvm.riscv.vfadd.vv.nxv32f16(<vscale x 32 x half> %op1, <vscale x 32 x half> %op2)
  ret <vscale x 32 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x float> @test_vfadd_vv_f32mf2(<vscale x 1 x float> %op1, <vscale x 1 x float> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f32mf2
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.nxv1f32(<vscale x 1 x float> %op1, <vscale x 1 x float> %op2)
  ret <vscale x 1 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfadd_vv_f32m1(<vscale x 2 x float> %op1, <vscale x 2 x float> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f32m1
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfadd.vv.nxv2f32(<vscale x 2 x float> %op1, <vscale x 2 x float> %op2)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x float> @test_vfadd_vv_f32m2(<vscale x 4 x float> %op1, <vscale x 4 x float> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f32m2
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x float> @llvm.riscv.vfadd.vv.nxv4f32(<vscale x 4 x float> %op1, <vscale x 4 x float> %op2)
  ret <vscale x 4 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x float> @test_vfadd_vv_f32m4(<vscale x 8 x float> %op1, <vscale x 8 x float> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f32m4
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x float> @llvm.riscv.vfadd.vv.nxv8f32(<vscale x 8 x float> %op1, <vscale x 8 x float> %op2)
  ret <vscale x 8 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x float> @test_vfadd_vv_f32m8(<vscale x 16 x float> %op1, <vscale x 16 x float> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f32m8
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x float> @llvm.riscv.vfadd.vv.nxv16f32(<vscale x 16 x float> %op1, <vscale x 16 x float> %op2)
  ret <vscale x 16 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vfadd_vv_f64m1(<vscale x 1 x double> %op1, <vscale x 1 x double> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f64m1
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vfadd.vv.nxv1f64(<vscale x 1 x double> %op1, <vscale x 1 x double> %op2)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x double> @test_vfadd_vv_f64m2(<vscale x 2 x double> %op1, <vscale x 2 x double> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f64m2
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x double> @llvm.riscv.vfadd.vv.nxv2f64(<vscale x 2 x double> %op1, <vscale x 2 x double> %op2)
  ret <vscale x 2 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x double> @test_vfadd_vv_f64m4(<vscale x 4 x double> %op1, <vscale x 4 x double> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f64m4
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x double> @llvm.riscv.vfadd.vv.nxv4f64(<vscale x 4 x double> %op1, <vscale x 4 x double> %op2)
  ret <vscale x 4 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x double> @test_vfadd_vv_f64m8(<vscale x 8 x double> %op1, <vscale x 8 x double> %op2) {
entry:
; CHECK-LABEL: vfadd_vv_f64m8
; CHECK: vfadd.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x double> @llvm.riscv.vfadd.vv.nxv8f64(<vscale x 8 x double> %op1, <vscale x 8 x double> %op2)
  ret <vscale x 8 x double> %call
}

; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vfadd.vv.nxv1f64(<vscale x 1 x double>, <vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 16 x float> @llvm.riscv.vfadd.vv.nxv16f32(<vscale x 16 x float>, <vscale x 16 x float>)
; Function Attrs: nounwind
declare <vscale x 8 x half> @llvm.riscv.vfadd.vv.nxv8f16(<vscale x 8 x half>, <vscale x 8 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x double> @llvm.riscv.vfadd.vv.nxv8f64(<vscale x 8 x double>, <vscale x 8 x double>)
; Function Attrs: nounwind
declare <vscale x 16 x half> @llvm.riscv.vfadd.vv.nxv16f16(<vscale x 16 x half>, <vscale x 16 x half>)
; Function Attrs: nounwind
declare <vscale x 2 x double> @llvm.riscv.vfadd.vv.nxv2f64(<vscale x 2 x double>, <vscale x 2 x double>)
; Function Attrs: nounwind
declare <vscale x 4 x float> @llvm.riscv.vfadd.vv.nxv4f32(<vscale x 4 x float>, <vscale x 4 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x float> @llvm.riscv.vfadd.vv.nxv1f32(<vscale x 1 x float>, <vscale x 1 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x half> @llvm.riscv.vfadd.vv.nxv1f16(<vscale x 1 x half>, <vscale x 1 x half>)
; Function Attrs: nounwind
declare <vscale x 32 x half> @llvm.riscv.vfadd.vv.nxv32f16(<vscale x 32 x half>, <vscale x 32 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x double> @llvm.riscv.vfadd.vv.nxv4f64(<vscale x 4 x double>, <vscale x 4 x double>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfadd.vv.nxv4f16(<vscale x 4 x half>, <vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfadd.vv.nxv2f32(<vscale x 2 x float>, <vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 2 x half> @llvm.riscv.vfadd.vv.nxv2f16(<vscale x 2 x half>, <vscale x 2 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x float> @llvm.riscv.vfadd.vv.nxv8f32(<vscale x 8 x float>, <vscale x 8 x float>)

; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x half> @test_vfsgnjn_vv_f16mf4(<vscale x 1 x half> %op1, <vscale x 1 x half> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f16mf4
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x half> @llvm.riscv.vfsgnjn.vv.nxv1f16(<vscale x 1 x half> %op1, <vscale x 1 x half> %op2)
  ret <vscale x 1 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x half> @test_vfsgnjn_vv_f16mf2(<vscale x 2 x half> %op1, <vscale x 2 x half> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f16mf2
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x half> @llvm.riscv.vfsgnjn.vv.nxv2f16(<vscale x 2 x half> %op1, <vscale x 2 x half> %op2)
  ret <vscale x 2 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfsgnjn_vv_f16m1(<vscale x 4 x half> %op1, <vscale x 4 x half> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f16m1
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfsgnjn.vv.nxv4f16(<vscale x 4 x half> %op1, <vscale x 4 x half> %op2)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x half> @test_vfsgnjn_vv_f16m2(<vscale x 8 x half> %op1, <vscale x 8 x half> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f16m2
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x half> @llvm.riscv.vfsgnjn.vv.nxv8f16(<vscale x 8 x half> %op1, <vscale x 8 x half> %op2)
  ret <vscale x 8 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x half> @test_vfsgnjn_vv_f16m4(<vscale x 16 x half> %op1, <vscale x 16 x half> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f16m4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x half> @llvm.riscv.vfsgnjn.vv.nxv16f16(<vscale x 16 x half> %op1, <vscale x 16 x half> %op2)
  ret <vscale x 16 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x half> @test_vfsgnjn_vv_f16m8(<vscale x 32 x half> %op1, <vscale x 32 x half> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f16m8
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x half> @llvm.riscv.vfsgnjn.vv.nxv32f16(<vscale x 32 x half> %op1, <vscale x 32 x half> %op2)
  ret <vscale x 32 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x float> @test_vfsgnjn_vv_f32mf2(<vscale x 1 x float> %op1, <vscale x 1 x float> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x float> @llvm.riscv.vfsgnjn.vv.nxv1f32(<vscale x 1 x float> %op1, <vscale x 1 x float> %op2)
  ret <vscale x 1 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfsgnjn_vv_f32m1(<vscale x 2 x float> %op1, <vscale x 2 x float> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfsgnjn.vv.nxv2f32(<vscale x 2 x float> %op1, <vscale x 2 x float> %op2)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x float> @test_vfsgnjn_vv_f32m2(<vscale x 4 x float> %op1, <vscale x 4 x float> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x float> @llvm.riscv.vfsgnjn.vv.nxv4f32(<vscale x 4 x float> %op1, <vscale x 4 x float> %op2)
  ret <vscale x 4 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x float> @test_vfsgnjn_vv_f32m4(<vscale x 8 x float> %op1, <vscale x 8 x float> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x float> @llvm.riscv.vfsgnjn.vv.nxv8f32(<vscale x 8 x float> %op1, <vscale x 8 x float> %op2)
  ret <vscale x 8 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x float> @test_vfsgnjn_vv_f32m8(<vscale x 16 x float> %op1, <vscale x 16 x float> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f32m8
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x float> @llvm.riscv.vfsgnjn.vv.nxv16f32(<vscale x 16 x float> %op1, <vscale x 16 x float> %op2)
  ret <vscale x 16 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vfsgnjn_vv_f64m1(<vscale x 1 x double> %op1, <vscale x 1 x double> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f64m1
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vfsgnjn.vv.nxv1f64(<vscale x 1 x double> %op1, <vscale x 1 x double> %op2)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x double> @test_vfsgnjn_vv_f64m2(<vscale x 2 x double> %op1, <vscale x 2 x double> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f64m2
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x double> @llvm.riscv.vfsgnjn.vv.nxv2f64(<vscale x 2 x double> %op1, <vscale x 2 x double> %op2)
  ret <vscale x 2 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x double> @test_vfsgnjn_vv_f64m4(<vscale x 4 x double> %op1, <vscale x 4 x double> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f64m4
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x double> @llvm.riscv.vfsgnjn.vv.nxv4f64(<vscale x 4 x double> %op1, <vscale x 4 x double> %op2)
  ret <vscale x 4 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x double> @test_vfsgnjn_vv_f64m8(<vscale x 8 x double> %op1, <vscale x 8 x double> %op2) {
entry:
; CHECK-LABEL: vfsgnjn_vv_f64m8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vfsgnjn.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x double> @llvm.riscv.vfsgnjn.vv.nxv8f64(<vscale x 8 x double> %op1, <vscale x 8 x double> %op2)
  ret <vscale x 8 x double> %call
}

; Function Attrs: nounwind
declare <vscale x 2 x double> @llvm.riscv.vfsgnjn.vv.nxv2f64(<vscale x 2 x double>, <vscale x 2 x double>)
; Function Attrs: nounwind
declare <vscale x 1 x float> @llvm.riscv.vfsgnjn.vv.nxv1f32(<vscale x 1 x float>, <vscale x 1 x float>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfsgnjn.vv.nxv2f32(<vscale x 2 x float>, <vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 8 x float> @llvm.riscv.vfsgnjn.vv.nxv8f32(<vscale x 8 x float>, <vscale x 8 x float>)
; Function Attrs: nounwind
declare <vscale x 32 x half> @llvm.riscv.vfsgnjn.vv.nxv32f16(<vscale x 32 x half>, <vscale x 32 x half>)
; Function Attrs: nounwind
declare <vscale x 16 x float> @llvm.riscv.vfsgnjn.vv.nxv16f32(<vscale x 16 x float>, <vscale x 16 x float>)
; Function Attrs: nounwind
declare <vscale x 2 x half> @llvm.riscv.vfsgnjn.vv.nxv2f16(<vscale x 2 x half>, <vscale x 2 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x float> @llvm.riscv.vfsgnjn.vv.nxv4f32(<vscale x 4 x float>, <vscale x 4 x float>)
; Function Attrs: nounwind
declare <vscale x 8 x half> @llvm.riscv.vfsgnjn.vv.nxv8f16(<vscale x 8 x half>, <vscale x 8 x half>)
; Function Attrs: nounwind
declare <vscale x 1 x half> @llvm.riscv.vfsgnjn.vv.nxv1f16(<vscale x 1 x half>, <vscale x 1 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x double> @llvm.riscv.vfsgnjn.vv.nxv4f64(<vscale x 4 x double>, <vscale x 4 x double>)
; Function Attrs: nounwind
declare <vscale x 16 x half> @llvm.riscv.vfsgnjn.vv.nxv16f16(<vscale x 16 x half>, <vscale x 16 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x double> @llvm.riscv.vfsgnjn.vv.nxv8f64(<vscale x 8 x double>, <vscale x 8 x double>)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vfsgnjn.vv.nxv1f64(<vscale x 1 x double>, <vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfsgnjn.vv.nxv4f16(<vscale x 4 x half>, <vscale x 4 x half>)

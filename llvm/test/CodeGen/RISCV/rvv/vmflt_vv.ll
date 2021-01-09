; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmflt_vv_f16mf4_b64(<vscale x 1 x half> %op1, <vscale x 1 x half> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f16mf4_b64
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmflt.vv.nxv1i1.nxv1f16(<vscale x 1 x half> %op1, <vscale x 1 x half> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmflt_vv_f16mf2_b32(<vscale x 2 x half> %op1, <vscale x 2 x half> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f16mf2_b32
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmflt.vv.nxv2i1.nxv2f16(<vscale x 2 x half> %op1, <vscale x 2 x half> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmflt_vv_f16m1_b16(<vscale x 4 x half> %op1, <vscale x 4 x half> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f16m1_b16
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmflt.vv.nxv4i1.nxv4f16(<vscale x 4 x half> %op1, <vscale x 4 x half> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmflt_vv_f16m2_b8(<vscale x 8 x half> %op1, <vscale x 8 x half> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f16m2_b8
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmflt.vv.nxv8i1.nxv8f16(<vscale x 8 x half> %op1, <vscale x 8 x half> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmflt_vv_f16m4_b4(<vscale x 16 x half> %op1, <vscale x 16 x half> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f16m4_b4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmflt.vv.nxv16i1.nxv16f16(<vscale x 16 x half> %op1, <vscale x 16 x half> %op2)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i1> @test_vmflt_vv_f16m8_b2(<vscale x 32 x half> %op1, <vscale x 32 x half> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f16m8_b2
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i1> @llvm.riscv.vmflt.vv.nxv32i1.nxv32f16(<vscale x 32 x half> %op1, <vscale x 32 x half> %op2)
  ret <vscale x 32 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmflt_vv_f32mf2_b64(<vscale x 1 x float> %op1, <vscale x 1 x float> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f32mf2_b64
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmflt.vv.nxv1i1.nxv1f32(<vscale x 1 x float> %op1, <vscale x 1 x float> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmflt_vv_f32m1_b32(<vscale x 2 x float> %op1, <vscale x 2 x float> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f32m1_b32
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmflt.vv.nxv2i1.nxv2f32(<vscale x 2 x float> %op1, <vscale x 2 x float> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmflt_vv_f32m2_b16(<vscale x 4 x float> %op1, <vscale x 4 x float> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f32m2_b16
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmflt.vv.nxv4i1.nxv4f32(<vscale x 4 x float> %op1, <vscale x 4 x float> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmflt_vv_f32m4_b8(<vscale x 8 x float> %op1, <vscale x 8 x float> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f32m4_b8
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmflt.vv.nxv8i1.nxv8f32(<vscale x 8 x float> %op1, <vscale x 8 x float> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmflt_vv_f32m8_b4(<vscale x 16 x float> %op1, <vscale x 16 x float> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f32m8_b4
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmflt.vv.nxv16i1.nxv16f32(<vscale x 16 x float> %op1, <vscale x 16 x float> %op2)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmflt_vv_f64m1_b64(<vscale x 1 x double> %op1, <vscale x 1 x double> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f64m1_b64
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmflt.vv.nxv1i1.nxv1f64(<vscale x 1 x double> %op1, <vscale x 1 x double> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmflt_vv_f64m2_b32(<vscale x 2 x double> %op1, <vscale x 2 x double> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f64m2_b32
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmflt.vv.nxv2i1.nxv2f64(<vscale x 2 x double> %op1, <vscale x 2 x double> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmflt_vv_f64m4_b16(<vscale x 4 x double> %op1, <vscale x 4 x double> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f64m4_b16
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmflt.vv.nxv4i1.nxv4f64(<vscale x 4 x double> %op1, <vscale x 4 x double> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmflt_vv_f64m8_b8(<vscale x 8 x double> %op1, <vscale x 8 x double> %op2) {
entry:
; CHECK-LABEL: vmflt_vv_f64m8_b8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vmflt.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmflt.vv.nxv8i1.nxv8f64(<vscale x 8 x double> %op1, <vscale x 8 x double> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: nounwind
declare <vscale x 1 x i1> @llvm.riscv.vmflt.vv.nxv1i1.nxv1f16(<vscale x 1 x half>, <vscale x 1 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x i1> @llvm.riscv.vmflt.vv.nxv8i1.nxv8f16(<vscale x 8 x half>, <vscale x 8 x half>)
; Function Attrs: nounwind
declare <vscale x 1 x i1> @llvm.riscv.vmflt.vv.nxv1i1.nxv1f32(<vscale x 1 x float>, <vscale x 1 x float>)
; Function Attrs: nounwind
declare <vscale x 2 x i1> @llvm.riscv.vmflt.vv.nxv2i1.nxv2f64(<vscale x 2 x double>, <vscale x 2 x double>)
; Function Attrs: nounwind
declare <vscale x 32 x i1> @llvm.riscv.vmflt.vv.nxv32i1.nxv32f16(<vscale x 32 x half>, <vscale x 32 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x i1> @llvm.riscv.vmflt.vv.nxv4i1.nxv4f32(<vscale x 4 x float>, <vscale x 4 x float>)
; Function Attrs: nounwind
declare <vscale x 8 x i1> @llvm.riscv.vmflt.vv.nxv8i1.nxv8f64(<vscale x 8 x double>, <vscale x 8 x double>)
; Function Attrs: nounwind
declare <vscale x 1 x i1> @llvm.riscv.vmflt.vv.nxv1i1.nxv1f64(<vscale x 1 x double>, <vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 16 x i1> @llvm.riscv.vmflt.vv.nxv16i1.nxv16f16(<vscale x 16 x half>, <vscale x 16 x half>)
; Function Attrs: nounwind
declare <vscale x 2 x i1> @llvm.riscv.vmflt.vv.nxv2i1.nxv2f16(<vscale x 2 x half>, <vscale x 2 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x i1> @llvm.riscv.vmflt.vv.nxv4i1.nxv4f16(<vscale x 4 x half>, <vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 16 x i1> @llvm.riscv.vmflt.vv.nxv16i1.nxv16f32(<vscale x 16 x float>, <vscale x 16 x float>)
; Function Attrs: nounwind
declare <vscale x 2 x i1> @llvm.riscv.vmflt.vv.nxv2i1.nxv2f32(<vscale x 2 x float>, <vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 4 x i1> @llvm.riscv.vmflt.vv.nxv4i1.nxv4f64(<vscale x 4 x double>, <vscale x 4 x double>)
; Function Attrs: nounwind
declare <vscale x 8 x i1> @llvm.riscv.vmflt.vv.nxv8i1.nxv8f32(<vscale x 8 x float>, <vscale x 8 x float>)

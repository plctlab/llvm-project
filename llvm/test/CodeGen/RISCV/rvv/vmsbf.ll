; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i1> @test_vmsbf_m_b1(<vscale x 64 x i1> %op1) {
entry:
; CHECK-LABEL: vmsbf_m_b1
; CHECK: vmsbf.m {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 64 x i1> @llvm.riscv.vmsbf.m.nxv64i1(<vscale x 64 x i1> %op1)
  ret <vscale x 64 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i1> @test_vmsbf_m_b2(<vscale x 32 x i1> %op1) {
entry:
; CHECK-LABEL: vmsbf_m_b2
; CHECK: vmsbf.m {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 32 x i1> @llvm.riscv.vmsbf.m.nxv32i1(<vscale x 32 x i1> %op1)
  ret <vscale x 32 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmsbf_m_b4(<vscale x 16 x i1> %op1) {
entry:
; CHECK-LABEL: vmsbf_m_b4
; CHECK: vmsbf.m {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmsbf.m.nxv16i1(<vscale x 16 x i1> %op1)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmsbf_m_b8(<vscale x 8 x i1> %op1) {
entry:
; CHECK-LABEL: vmsbf_m_b8
; CHECK: vmsbf.m {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmsbf.m.nxv8i1(<vscale x 8 x i1> %op1)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmsbf_m_b16(<vscale x 4 x i1> %op1) {
entry:
; CHECK-LABEL: vmsbf_m_b16
; CHECK: vmsbf.m {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmsbf.m.nxv4i1(<vscale x 4 x i1> %op1)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmsbf_m_b32(<vscale x 2 x i1> %op1) {
entry:
; CHECK-LABEL: vmsbf_m_b32
; CHECK: vmsbf.m {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmsbf.m.nxv2i1(<vscale x 2 x i1> %op1)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmsbf_m_b64(<vscale x 1 x i1> %op1) {
entry:
; CHECK-LABEL: vmsbf_m_b64
; CHECK: vmsbf.m {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmsbf.m.nxv1i1(<vscale x 1 x i1> %op1)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: nounwind
declare <vscale x 16 x i1> @llvm.riscv.vmsbf.m.nxv16i1(<vscale x 16 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i1> @llvm.riscv.vmsbf.m.nxv4i1(<vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i1> @llvm.riscv.vmsbf.m.nxv2i1(<vscale x 2 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i1> @llvm.riscv.vmsbf.m.nxv1i1(<vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 8 x i1> @llvm.riscv.vmsbf.m.nxv8i1(<vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 64 x i1> @llvm.riscv.vmsbf.m.nxv64i1(<vscale x 64 x i1>)
; Function Attrs: nounwind
declare <vscale x 32 x i1> @llvm.riscv.vmsbf.m.nxv32i1(<vscale x 32 x i1>)

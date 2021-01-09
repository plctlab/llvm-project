; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i1> @test_vmxor_mm_b1(<vscale x 64 x i1> %op1, <vscale x 64 x i1> %op2) {
entry:
; CHECK-LABEL: vmxor_mm_b1
; CHECK: vmclr.m {{v[0-9]+}}
  %call = tail call <vscale x 64 x i1> @llvm.riscv.vmxor.mm.nxv64i1(<vscale x 64 x i1> %op1, <vscale x 64 x i1> %op2)
  ret <vscale x 64 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i1> @test_vmxor_mm_b2(<vscale x 32 x i1> %op1, <vscale x 32 x i1> %op2) {
entry:
; CHECK-LABEL: vmxor_mm_b2
; CHECK: vmclr.m {{v[0-9]+}}
  %call = tail call <vscale x 32 x i1> @llvm.riscv.vmxor.mm.nxv32i1(<vscale x 32 x i1> %op1, <vscale x 32 x i1> %op2)
  ret <vscale x 32 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmxor_mm_b4(<vscale x 16 x i1> %op1, <vscale x 16 x i1> %op2) {
entry:
; CHECK-LABEL: vmxor_mm_b4
; CHECK: vmclr.m {{v[0-9]+}}
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmxor.mm.nxv16i1(<vscale x 16 x i1> %op1, <vscale x 16 x i1> %op2)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmxor_mm_b8(<vscale x 8 x i1> %op1, <vscale x 8 x i1> %op2) {
entry:
; CHECK-LABEL: vmxor_mm_b8
; CHECK: vmclr.m {{v[0-9]+}}
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmxor.mm.nxv8i1(<vscale x 8 x i1> %op1, <vscale x 8 x i1> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmxor_mm_b16(<vscale x 4 x i1> %op1, <vscale x 4 x i1> %op2) {
entry:
; CHECK-LABEL: vmxor_mm_b16
; CHECK: vmclr.m {{v[0-9]+}}
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmxor.mm.nxv4i1(<vscale x 4 x i1> %op1, <vscale x 4 x i1> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmxor_mm_b32(<vscale x 2 x i1> %op1, <vscale x 2 x i1> %op2) {
entry:
; CHECK-LABEL: vmxor_mm_b32
; CHECK: vmclr.m {{v[0-9]+}}
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmxor.mm.nxv2i1(<vscale x 2 x i1> %op1, <vscale x 2 x i1> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmxor_mm_b64(<vscale x 1 x i1> %op1, <vscale x 1 x i1> %op2) {
entry:
; CHECK-LABEL: vmxor_mm_b64
; CHECK: vmclr.m {{v[0-9]+}}
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmxor.mm.nxv1i1(<vscale x 1 x i1> %op1, <vscale x 1 x i1> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: nounwind
declare <vscale x 64 x i1> @llvm.riscv.vmxor.mm.nxv64i1(<vscale x 64 x i1>, <vscale x 64 x i1>)
; Function Attrs: nounwind
declare <vscale x 8 x i1> @llvm.riscv.vmxor.mm.nxv8i1(<vscale x 8 x i1>, <vscale x 8 x i1>)
; Function Attrs: nounwind
declare <vscale x 4 x i1> @llvm.riscv.vmxor.mm.nxv4i1(<vscale x 4 x i1>, <vscale x 4 x i1>)
; Function Attrs: nounwind
declare <vscale x 1 x i1> @llvm.riscv.vmxor.mm.nxv1i1(<vscale x 1 x i1>, <vscale x 1 x i1>)
; Function Attrs: nounwind
declare <vscale x 16 x i1> @llvm.riscv.vmxor.mm.nxv16i1(<vscale x 16 x i1>, <vscale x 16 x i1>)
; Function Attrs: nounwind
declare <vscale x 2 x i1> @llvm.riscv.vmxor.mm.nxv2i1(<vscale x 2 x i1>, <vscale x 2 x i1>)
; Function Attrs: nounwind
declare <vscale x 32 x i1> @llvm.riscv.vmxor.mm.nxv32i1(<vscale x 32 x i1>, <vscale x 32 x i1>)

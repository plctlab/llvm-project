; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define i64 @test_vfirst_m_b1(<vscale x 64 x i1> %op1) {
entry:
; CHECK-LABEL: vfirst_m_b1
  %call = tail call i64 @llvm.riscv.vfirst.m.nxv64i1(<vscale x 64 x i1> %op1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vfirst_m_b2(<vscale x 32 x i1> %op1) {
entry:
; CHECK-LABEL: vfirst_m_b2
  %call = tail call i64 @llvm.riscv.vfirst.m.nxv32i1(<vscale x 32 x i1> %op1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vfirst_m_b4(<vscale x 16 x i1> %op1) {
entry:
; CHECK-LABEL: vfirst_m_b4
  %call = tail call i64 @llvm.riscv.vfirst.m.nxv16i1(<vscale x 16 x i1> %op1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vfirst_m_b8(<vscale x 8 x i1> %op1) {
entry:
; CHECK-LABEL: vfirst_m_b8
  %call = tail call i64 @llvm.riscv.vfirst.m.nxv8i1(<vscale x 8 x i1> %op1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vfirst_m_b16(<vscale x 4 x i1> %op1) {
entry:
; CHECK-LABEL: vfirst_m_b16
  %call = tail call i64 @llvm.riscv.vfirst.m.nxv4i1(<vscale x 4 x i1> %op1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vfirst_m_b32(<vscale x 2 x i1> %op1) {
entry:
; CHECK-LABEL: vfirst_m_b32
  %call = tail call i64 @llvm.riscv.vfirst.m.nxv2i1(<vscale x 2 x i1> %op1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vfirst_m_b64(<vscale x 1 x i1> %op1) {
entry:
; CHECK-LABEL: vfirst_m_b64
  %call = tail call i64 @llvm.riscv.vfirst.m.nxv1i1(<vscale x 1 x i1> %op1)
  ret i64 %call
}

; Function Attrs: nounwind
declare i64 @llvm.riscv.vfirst.m.nxv64i1(<vscale x 64 x i1>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vfirst.m.nxv1i1(<vscale x 1 x i1>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vfirst.m.nxv2i1(<vscale x 2 x i1>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vfirst.m.nxv8i1(<vscale x 8 x i1>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vfirst.m.nxv32i1(<vscale x 32 x i1>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vfirst.m.nxv4i1(<vscale x 4 x i1>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vfirst.m.nxv16i1(<vscale x 16 x i1>)

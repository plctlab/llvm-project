; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfredosum_vs_f16mf4_f16m1(<vscale x 4 x half> %dst, <vscale x 1 x half> %vector, <vscale x 4 x half> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f16mf4_f16m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv1f16(<vscale x 4 x half> %dst, <vscale x 1 x half> %vector, <vscale x 4 x half> %scalar)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfredosum_vs_f16mf2_f16m1(<vscale x 4 x half> %dst, <vscale x 2 x half> %vector, <vscale x 4 x half> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f16mf2_f16m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv2f16(<vscale x 4 x half> %dst, <vscale x 2 x half> %vector, <vscale x 4 x half> %scalar)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfredosum_vs_f16m1_f16m1(<vscale x 4 x half> %dst, <vscale x 4 x half> %vector, <vscale x 4 x half> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f16m1_f16m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv4f16(<vscale x 4 x half> %dst, <vscale x 4 x half> %vector, <vscale x 4 x half> %scalar)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfredosum_vs_f16m2_f16m1(<vscale x 4 x half> %dst, <vscale x 8 x half> %vector, <vscale x 4 x half> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f16m2_f16m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv8f16(<vscale x 4 x half> %dst, <vscale x 8 x half> %vector, <vscale x 4 x half> %scalar)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfredosum_vs_f16m4_f16m1(<vscale x 4 x half> %dst, <vscale x 16 x half> %vector, <vscale x 4 x half> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f16m4_f16m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv16f16(<vscale x 4 x half> %dst, <vscale x 16 x half> %vector, <vscale x 4 x half> %scalar)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfredosum_vs_f16m8_f16m1(<vscale x 4 x half> %dst, <vscale x 32 x half> %vector, <vscale x 4 x half> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f16m8_f16m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv32f16(<vscale x 4 x half> %dst, <vscale x 32 x half> %vector, <vscale x 4 x half> %scalar)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfredosum_vs_f32mf2_f32m1(<vscale x 2 x float> %dst, <vscale x 1 x float> %vector, <vscale x 2 x float> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f32mf2_f32m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv1f32(<vscale x 2 x float> %dst, <vscale x 1 x float> %vector, <vscale x 2 x float> %scalar)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfredosum_vs_f32m1_f32m1(<vscale x 2 x float> %dst, <vscale x 2 x float> %vector, <vscale x 2 x float> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f32m1_f32m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv2f32(<vscale x 2 x float> %dst, <vscale x 2 x float> %vector, <vscale x 2 x float> %scalar)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfredosum_vs_f32m2_f32m1(<vscale x 2 x float> %dst, <vscale x 4 x float> %vector, <vscale x 2 x float> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f32m2_f32m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv4f32(<vscale x 2 x float> %dst, <vscale x 4 x float> %vector, <vscale x 2 x float> %scalar)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfredosum_vs_f32m4_f32m1(<vscale x 2 x float> %dst, <vscale x 8 x float> %vector, <vscale x 2 x float> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f32m4_f32m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv8f32(<vscale x 2 x float> %dst, <vscale x 8 x float> %vector, <vscale x 2 x float> %scalar)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfredosum_vs_f32m8_f32m1(<vscale x 2 x float> %dst, <vscale x 16 x float> %vector, <vscale x 2 x float> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f32m8_f32m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv16f32(<vscale x 2 x float> %dst, <vscale x 16 x float> %vector, <vscale x 2 x float> %scalar)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vfredosum_vs_f64m1_f64m1(<vscale x 1 x double> %dst, <vscale x 1 x double> %vector, <vscale x 1 x double> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f64m1_f64m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vfredosum.vs.nxv1f64.nxv1f64(<vscale x 1 x double> %dst, <vscale x 1 x double> %vector, <vscale x 1 x double> %scalar)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vfredosum_vs_f64m2_f64m1(<vscale x 1 x double> %dst, <vscale x 2 x double> %vector, <vscale x 1 x double> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f64m2_f64m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vfredosum.vs.nxv1f64.nxv2f64(<vscale x 1 x double> %dst, <vscale x 2 x double> %vector, <vscale x 1 x double> %scalar)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vfredosum_vs_f64m4_f64m1(<vscale x 1 x double> %dst, <vscale x 4 x double> %vector, <vscale x 1 x double> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f64m4_f64m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vfredosum.vs.nxv1f64.nxv4f64(<vscale x 1 x double> %dst, <vscale x 4 x double> %vector, <vscale x 1 x double> %scalar)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vfredosum_vs_f64m8_f64m1(<vscale x 1 x double> %dst, <vscale x 8 x double> %vector, <vscale x 1 x double> %scalar) {
entry:
; CHECK-LABEL: vfredosum_vs_f64m8_f64m1
; CHECK: vfredosum.vs {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vfredosum.vs.nxv1f64.nxv8f64(<vscale x 1 x double> %dst, <vscale x 8 x double> %vector, <vscale x 1 x double> %scalar)
  ret <vscale x 1 x double> %call
}

; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv1f16(<vscale x 4 x half>, <vscale x 1 x half>, <vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vfredosum.vs.nxv1f64.nxv8f64(<vscale x 1 x double>, <vscale x 8 x double>, <vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv16f32(<vscale x 2 x float>, <vscale x 16 x float>, <vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv32f16(<vscale x 4 x half>, <vscale x 32 x half>, <vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv2f16(<vscale x 4 x half>, <vscale x 2 x half>, <vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vfredosum.vs.nxv1f64.nxv1f64(<vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv4f16(<vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv4f32(<vscale x 2 x float>, <vscale x 4 x float>, <vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv16f16(<vscale x 4 x half>, <vscale x 16 x half>, <vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv8f32(<vscale x 2 x float>, <vscale x 8 x float>, <vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vfredosum.vs.nxv1f64.nxv2f64(<vscale x 1 x double>, <vscale x 2 x double>, <vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv1f32(<vscale x 2 x float>, <vscale x 1 x float>, <vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vfredosum.vs.nxv1f64.nxv4f64(<vscale x 1 x double>, <vscale x 4 x double>, <vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32.nxv2f32(<vscale x 2 x float>, <vscale x 2 x float>, <vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16.nxv8f16(<vscale x 4 x half>, <vscale x 8 x half>, <vscale x 4 x half>)

; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vle32_v_i32mf2(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_i32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vload.nxv1i32.p0i32(i32* %base)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vle32_v_i32m1(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_i32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vload.nxv2i32.p0i32(i32* %base)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vle32_v_i32m2(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_i32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vload.nxv4i32.p0i32(i32* %base)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vle32_v_i32m4(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_i32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vload.nxv8i32.p0i32(i32* %base)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vle32_v_i32m8(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_i32m8
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vload.nxv16i32.p0i32(i32* %base)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vle32_v_u32mf2(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_u32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vload.nxv1i32.p0i32(i32* %base)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vle32_v_u32m1(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_u32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vload.nxv2i32.p0i32(i32* %base)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vle32_v_u32m2(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_u32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vload.nxv4i32.p0i32(i32* %base)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vle32_v_u32m4(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_u32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vload.nxv8i32.p0i32(i32* %base)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vle32_v_u32m8(i32* %base) {
entry:
; CHECK-LABEL: vle32_v_u32m8
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vload.nxv16i32.p0i32(i32* %base)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x float> @test_vle32_v_f32mf2(float* %base) {
entry:
; CHECK-LABEL: vle32_v_f32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x float> @llvm.riscv.vload.nxv1f32.p0f32(float* %base)
  ret <vscale x 1 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vle32_v_f32m1(float* %base) {
entry:
; CHECK-LABEL: vle32_v_f32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x float> @llvm.riscv.vload.nxv2f32.p0f32(float* %base)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x float> @test_vle32_v_f32m2(float* %base) {
entry:
; CHECK-LABEL: vle32_v_f32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x float> @llvm.riscv.vload.nxv4f32.p0f32(float* %base)
  ret <vscale x 4 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x float> @test_vle32_v_f32m4(float* %base) {
entry:
; CHECK-LABEL: vle32_v_f32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x float> @llvm.riscv.vload.nxv8f32.p0f32(float* %base)
  ret <vscale x 8 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x float> @test_vle32_v_f32m8(float* %base) {
entry:
; CHECK-LABEL: vle32_v_f32m8
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vle32.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 16 x float> @llvm.riscv.vload.nxv16f32.p0f32(float* %base)
  ret <vscale x 16 x float> %call
}

; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vload.nxv1i32.p0i32(i32*)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vload.nxv4i32.p0i32(i32*)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vload.nxv16i32.p0i32(i32*)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vload.nxv8i32.p0i32(i32*)
; Function Attrs: nounwind
declare <vscale x 4 x float> @llvm.riscv.vload.nxv4f32.p0f32(float*)
; Function Attrs: nounwind
declare <vscale x 8 x float> @llvm.riscv.vload.nxv8f32.p0f32(float*)
; Function Attrs: nounwind
declare <vscale x 16 x float> @llvm.riscv.vload.nxv16f32.p0f32(float*)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vload.nxv2f32.p0f32(float*)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vload.nxv2i32.p0i32(i32*)
; Function Attrs: nounwind
declare <vscale x 1 x float> @llvm.riscv.vload.nxv1f32.p0f32(float*)

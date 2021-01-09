; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vle16_v_i16mf4(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_i16mf4
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vload.nxv1i16.p0i16(i16* %base)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vle16_v_i16mf2(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_i16mf2
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vload.nxv2i16.p0i16(i16* %base)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vle16_v_i16m1(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_i16m1
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vload.nxv4i16.p0i16(i16* %base)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vle16_v_i16m2(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_i16m2
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vload.nxv8i16.p0i16(i16* %base)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vle16_v_i16m4(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_i16m4
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vload.nxv16i16.p0i16(i16* %base)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vle16_v_i16m8(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_i16m8
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vload.nxv32i16.p0i16(i16* %base)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vle16_v_u16mf4(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_u16mf4
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vload.nxv1i16.p0i16(i16* %base)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vle16_v_u16mf2(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_u16mf2
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vload.nxv2i16.p0i16(i16* %base)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vle16_v_u16m1(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_u16m1
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vload.nxv4i16.p0i16(i16* %base)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vle16_v_u16m2(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_u16m2
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vload.nxv8i16.p0i16(i16* %base)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vle16_v_u16m4(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_u16m4
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vload.nxv16i16.p0i16(i16* %base)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vle16_v_u16m8(i16* %base) {
entry:
; CHECK-LABEL: vle16_v_u16m8
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vload.nxv32i16.p0i16(i16* %base)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x half> @test_vle16_v_f16mf4(half* %base) {
entry:
; CHECK-LABEL: vle16_v_f16mf4
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x half> @llvm.riscv.vload.nxv1f16.p0f16(half* %base)
  ret <vscale x 1 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x half> @test_vle16_v_f16mf2(half* %base) {
entry:
; CHECK-LABEL: vle16_v_f16mf2
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x half> @llvm.riscv.vload.nxv2f16.p0f16(half* %base)
  ret <vscale x 2 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vle16_v_f16m1(half* %base) {
entry:
; CHECK-LABEL: vle16_v_f16m1
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x half> @llvm.riscv.vload.nxv4f16.p0f16(half* %base)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x half> @test_vle16_v_f16m2(half* %base) {
entry:
; CHECK-LABEL: vle16_v_f16m2
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x half> @llvm.riscv.vload.nxv8f16.p0f16(half* %base)
  ret <vscale x 8 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x half> @test_vle16_v_f16m4(half* %base) {
entry:
; CHECK-LABEL: vle16_v_f16m4
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 16 x half> @llvm.riscv.vload.nxv16f16.p0f16(half* %base)
  ret <vscale x 16 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x half> @test_vle16_v_f16m8(half* %base) {
entry:
; CHECK-LABEL: vle16_v_f16m8
; CHECK: vle16.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 32 x half> @llvm.riscv.vload.nxv32f16.p0f16(half* %base)
  ret <vscale x 32 x half> %call
}

; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vload.nxv8i16.p0i16(i16*)
; Function Attrs: nounwind
declare <vscale x 2 x half> @llvm.riscv.vload.nxv2f16.p0f16(half*)
; Function Attrs: nounwind
declare <vscale x 8 x half> @llvm.riscv.vload.nxv8f16.p0f16(half*)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vload.nxv4f16.p0f16(half*)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vload.nxv2i16.p0i16(i16*)
; Function Attrs: nounwind
declare <vscale x 32 x half> @llvm.riscv.vload.nxv32f16.p0f16(half*)
; Function Attrs: nounwind
declare <vscale x 16 x half> @llvm.riscv.vload.nxv16f16.p0f16(half*)
; Function Attrs: nounwind
declare <vscale x 1 x half> @llvm.riscv.vload.nxv1f16.p0f16(half*)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vload.nxv4i16.p0i16(i16*)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vload.nxv1i16.p0i16(i16*)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vload.nxv16i16.p0i16(i16*)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vload.nxv32i16.p0i16(i16*)

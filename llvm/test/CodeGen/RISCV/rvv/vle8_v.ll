; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vle8_v_i8mf8(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_i8mf8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vload.nxv1i8.p0i8(i8* %base)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vle8_v_i8mf4(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_i8mf4
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vload.nxv2i8.p0i8(i8* %base)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vle8_v_i8mf2(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_i8mf2
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vload.nxv4i8.p0i8(i8* %base)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vle8_v_i8m1(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_i8m1
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vload.nxv8i8.p0i8(i8* %base)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vle8_v_i8m2(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_i8m2
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vload.nxv16i8.p0i8(i8* %base)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vle8_v_i8m4(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_i8m4
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vload.nxv32i8.p0i8(i8* %base)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vle8_v_i8m8(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_i8m8
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vload.nxv64i8.p0i8(i8* %base)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vle8_v_u8mf8(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_u8mf8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vload.nxv1i8.p0i8(i8* %base)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vle8_v_u8mf4(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_u8mf4
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vload.nxv2i8.p0i8(i8* %base)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vle8_v_u8mf2(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_u8mf2
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vload.nxv4i8.p0i8(i8* %base)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vle8_v_u8m1(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_u8m1
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vload.nxv8i8.p0i8(i8* %base)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vle8_v_u8m2(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_u8m2
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vload.nxv16i8.p0i8(i8* %base)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vle8_v_u8m4(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_u8m4
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vload.nxv32i8.p0i8(i8* %base)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vle8_v_u8m8(i8* %base) {
entry:
; CHECK-LABEL: vle8_v_u8m8
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK: vle8.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vload.nxv64i8.p0i8(i8* %base)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vload.nxv32i8.p0i8(i8*)
; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vload.nxv16i8.p0i8(i8*)
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vload.nxv8i8.p0i8(i8*)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vload.nxv4i8.p0i8(i8*)
; Function Attrs: nounwind
declare <vscale x 64 x i8> @llvm.riscv.vload.nxv64i8.p0i8(i8*)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vload.nxv1i8.p0i8(i8*)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vload.nxv2i8.p0i8(i8*)

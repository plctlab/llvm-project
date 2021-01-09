; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vid_v_u8mf8() {
entry:
; CHECK-LABEL: vid_v_u8mf8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vid.v.nxv1i8()
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vid_v_u8mf4() {
entry:
; CHECK-LABEL: vid_v_u8mf4
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vid.v.nxv2i8()
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vid_v_u8mf2() {
entry:
; CHECK-LABEL: vid_v_u8mf2
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vid.v.nxv4i8()
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vid_v_u8m1() {
entry:
; CHECK-LABEL: vid_v_u8m1
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vid.v.nxv8i8()
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vid_v_u8m2() {
entry:
; CHECK-LABEL: vid_v_u8m2
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vid.v.nxv16i8()
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vid_v_u8m4() {
entry:
; CHECK-LABEL: vid_v_u8m4
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vid.v.nxv32i8()
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vid_v_u8m8() {
entry:
; CHECK-LABEL: vid_v_u8m8
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vid.v.nxv64i8()
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vid_v_u16mf4() {
entry:
; CHECK-LABEL: vid_v_u16mf4
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vid.v.nxv1i16()
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vid_v_u16mf2() {
entry:
; CHECK-LABEL: vid_v_u16mf2
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vid.v.nxv2i16()
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vid_v_u16m1() {
entry:
; CHECK-LABEL: vid_v_u16m1
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vid.v.nxv4i16()
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vid_v_u16m2() {
entry:
; CHECK-LABEL: vid_v_u16m2
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vid.v.nxv8i16()
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vid_v_u16m4() {
entry:
; CHECK-LABEL: vid_v_u16m4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vid.v.nxv16i16()
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vid_v_u16m8() {
entry:
; CHECK-LABEL: vid_v_u16m8
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vid.v.nxv32i16()
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vid_v_u32mf2() {
entry:
; CHECK-LABEL: vid_v_u32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vid.v.nxv1i32()
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vid_v_u32m1() {
entry:
; CHECK-LABEL: vid_v_u32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vid.v.nxv2i32()
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vid_v_u32m2() {
entry:
; CHECK-LABEL: vid_v_u32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vid.v.nxv4i32()
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vid_v_u32m4() {
entry:
; CHECK-LABEL: vid_v_u32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vid.v.nxv8i32()
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vid_v_u32m8() {
entry:
; CHECK-LABEL: vid_v_u32m8
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vid.v.nxv16i32()
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vid_v_u64m1() {
entry:
; CHECK-LABEL: vid_v_u64m1
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vid.v.nxv1i64()
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vid_v_u64m2() {
entry:
; CHECK-LABEL: vid_v_u64m2
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vid.v.nxv2i64()
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vid_v_u64m4() {
entry:
; CHECK-LABEL: vid_v_u64m4
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vid.v.nxv4i64()
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vid_v_u64m8() {
entry:
; CHECK-LABEL: vid_v_u64m8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vid.v {{v[0-9]+}}
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vid.v.nxv8i64()
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vid.v.nxv16i8()
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vid.v.nxv8i8()
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vid.v.nxv2i8()
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vid.v.nxv8i16()
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vid.v.nxv8i64()
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vid.v.nxv1i8()
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vid.v.nxv16i32()
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vid.v.nxv32i8()
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vid.v.nxv4i8()
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vid.v.nxv2i32()
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vid.v.nxv1i64()
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vid.v.nxv1i32()
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vid.v.nxv4i64()
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vid.v.nxv4i16()
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vid.v.nxv32i16()
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vid.v.nxv16i16()
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vid.v.nxv8i32()
; Function Attrs: nounwind
declare <vscale x 64 x i8> @llvm.riscv.vid.v.nxv64i8()
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vid.v.nxv1i16()
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vid.v.nxv2i16()
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vid.v.nxv4i32()
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vid.v.nxv2i64()

; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_i8mf8_i8(<vscale x 1 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i8mf8_i8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv1i8(<vscale x 1 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_i8mf4_i8(<vscale x 2 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i8mf4_i8
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv2i8(<vscale x 2 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_i8mf2_i8(<vscale x 4 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i8mf2_i8
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv4i8(<vscale x 4 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_i8m1_i8(<vscale x 8 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i8m1_i8
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv8i8(<vscale x 8 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_i8m2_i8(<vscale x 16 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i8m2_i8
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv16i8(<vscale x 16 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_i8m4_i8(<vscale x 32 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i8m4_i8
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv32i8(<vscale x 32 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_i8m8_i8(<vscale x 64 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i8m8_i8
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv64i8(<vscale x 64 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_i16mf4_i16(<vscale x 1 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i16mf4_i16
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv1i16(<vscale x 1 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_i16mf2_i16(<vscale x 2 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i16mf2_i16
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv2i16(<vscale x 2 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_i16m1_i16(<vscale x 4 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i16m1_i16
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv4i16(<vscale x 4 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_i16m2_i16(<vscale x 8 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i16m2_i16
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv8i16(<vscale x 8 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_i16m4_i16(<vscale x 16 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i16m4_i16
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv16i16(<vscale x 16 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_i16m8_i16(<vscale x 32 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i16m8_i16
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv32i16(<vscale x 32 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_i32mf2_i32(<vscale x 1 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i32mf2_i32
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv1i32(<vscale x 1 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_i32m1_i32(<vscale x 2 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i32m1_i32
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv2i32(<vscale x 2 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_i32m2_i32(<vscale x 4 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i32m2_i32
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv4i32(<vscale x 4 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_i32m4_i32(<vscale x 8 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i32m4_i32
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv8i32(<vscale x 8 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_i32m8_i32(<vscale x 16 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i32m8_i32
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv16i32(<vscale x 16 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vmv_x_s_i64m1_i64(<vscale x 1 x i64> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i64m1_i64
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i64 @llvm.riscv.vmv.x.s.i64.nxv1i64(<vscale x 1 x i64> %src)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vmv_x_s_i64m2_i64(<vscale x 2 x i64> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i64m2_i64
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i64 @llvm.riscv.vmv.x.s.i64.nxv2i64(<vscale x 2 x i64> %src)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vmv_x_s_i64m4_i64(<vscale x 4 x i64> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i64m4_i64
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i64 @llvm.riscv.vmv.x.s.i64.nxv4i64(<vscale x 4 x i64> %src)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vmv_x_s_i64m8_i64(<vscale x 8 x i64> %src) {
entry:
; CHECK-LABEL: vmv_x_s_i64m8_i64
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i64 @llvm.riscv.vmv.x.s.i64.nxv8i64(<vscale x 8 x i64> %src)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_u8mf8_u8(<vscale x 1 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u8mf8_u8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv1i8(<vscale x 1 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_u8mf4_u8(<vscale x 2 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u8mf4_u8
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv2i8(<vscale x 2 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_u8mf2_u8(<vscale x 4 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u8mf2_u8
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv4i8(<vscale x 4 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_u8m1_u8(<vscale x 8 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u8m1_u8
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv8i8(<vscale x 8 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_u8m2_u8(<vscale x 16 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u8m2_u8
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv16i8(<vscale x 16 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_u8m4_u8(<vscale x 32 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u8m4_u8
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv32i8(<vscale x 32 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i8 @test_vmv_x_s_u8m8_u8(<vscale x 64 x i8> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u8m8_u8
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i8 @llvm.riscv.vmv.x.s.i8.nxv64i8(<vscale x 64 x i8> %src)
  ret i8 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_u16mf4_u16(<vscale x 1 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u16mf4_u16
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv1i16(<vscale x 1 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_u16mf2_u16(<vscale x 2 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u16mf2_u16
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv2i16(<vscale x 2 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_u16m1_u16(<vscale x 4 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u16m1_u16
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv4i16(<vscale x 4 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_u16m2_u16(<vscale x 8 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u16m2_u16
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv8i16(<vscale x 8 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_u16m4_u16(<vscale x 16 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u16m4_u16
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv16i16(<vscale x 16 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i16 @test_vmv_x_s_u16m8_u16(<vscale x 32 x i16> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u16m8_u16
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i16 @llvm.riscv.vmv.x.s.i16.nxv32i16(<vscale x 32 x i16> %src)
  ret i16 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_u32mf2_u32(<vscale x 1 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u32mf2_u32
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv1i32(<vscale x 1 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_u32m1_u32(<vscale x 2 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u32m1_u32
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv2i32(<vscale x 2 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_u32m2_u32(<vscale x 4 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u32m2_u32
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv4i32(<vscale x 4 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_u32m4_u32(<vscale x 8 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u32m4_u32
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv8i32(<vscale x 8 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i32 @test_vmv_x_s_u32m8_u32(<vscale x 16 x i32> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u32m8_u32
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i32 @llvm.riscv.vmv.x.s.i32.nxv16i32(<vscale x 16 x i32> %src)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vmv_x_s_u64m1_u64(<vscale x 1 x i64> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u64m1_u64
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i64 @llvm.riscv.vmv.x.s.i64.nxv1i64(<vscale x 1 x i64> %src)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vmv_x_s_u64m2_u64(<vscale x 2 x i64> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u64m2_u64
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i64 @llvm.riscv.vmv.x.s.i64.nxv2i64(<vscale x 2 x i64> %src)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vmv_x_s_u64m4_u64(<vscale x 4 x i64> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u64m4_u64
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i64 @llvm.riscv.vmv.x.s.i64.nxv4i64(<vscale x 4 x i64> %src)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vmv_x_s_u64m8_u64(<vscale x 8 x i64> %src) {
entry:
; CHECK-LABEL: vmv_x_s_u64m8_u64
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vmv.x.s {{a[0-9]+}}, {{v[0-9]+}}
  %call = tail call i64 @llvm.riscv.vmv.x.s.i64.nxv8i64(<vscale x 8 x i64> %src)
  ret i64 %call
}

; Function Attrs: nounwind
declare i16 @llvm.riscv.vmv.x.s.i16.nxv1i16(<vscale x 1 x i16>)
; Function Attrs: nounwind
declare i16 @llvm.riscv.vmv.x.s.i16.nxv32i16(<vscale x 32 x i16>)
; Function Attrs: nounwind
declare i8 @llvm.riscv.vmv.x.s.i8.nxv32i8(<vscale x 32 x i8>)
; Function Attrs: nounwind
declare i16 @llvm.riscv.vmv.x.s.i16.nxv2i16(<vscale x 2 x i16>)
; Function Attrs: nounwind
declare i32 @llvm.riscv.vmv.x.s.i32.nxv1i32(<vscale x 1 x i32>)
; Function Attrs: nounwind
declare i8 @llvm.riscv.vmv.x.s.i8.nxv64i8(<vscale x 64 x i8>)
; Function Attrs: nounwind
declare i16 @llvm.riscv.vmv.x.s.i16.nxv16i16(<vscale x 16 x i16>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vmv.x.s.i64.nxv1i64(<vscale x 1 x i64>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vmv.x.s.i64.nxv8i64(<vscale x 8 x i64>)
; Function Attrs: nounwind
declare i16 @llvm.riscv.vmv.x.s.i16.nxv8i16(<vscale x 8 x i16>)
; Function Attrs: nounwind
declare i8 @llvm.riscv.vmv.x.s.i8.nxv8i8(<vscale x 8 x i8>)
; Function Attrs: nounwind
declare i16 @llvm.riscv.vmv.x.s.i16.nxv4i16(<vscale x 4 x i16>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vmv.x.s.i64.nxv2i64(<vscale x 2 x i64>)
; Function Attrs: nounwind
declare i32 @llvm.riscv.vmv.x.s.i32.nxv4i32(<vscale x 4 x i32>)
; Function Attrs: nounwind
declare i32 @llvm.riscv.vmv.x.s.i32.nxv16i32(<vscale x 16 x i32>)
; Function Attrs: nounwind
declare i32 @llvm.riscv.vmv.x.s.i32.nxv2i32(<vscale x 2 x i32>)
; Function Attrs: nounwind
declare i8 @llvm.riscv.vmv.x.s.i8.nxv16i8(<vscale x 16 x i8>)
; Function Attrs: nounwind
declare i64 @llvm.riscv.vmv.x.s.i64.nxv4i64(<vscale x 4 x i64>)
; Function Attrs: nounwind
declare i32 @llvm.riscv.vmv.x.s.i32.nxv8i32(<vscale x 8 x i32>)
; Function Attrs: nounwind
declare i8 @llvm.riscv.vmv.x.s.i8.nxv2i8(<vscale x 2 x i8>)
; Function Attrs: nounwind
declare i8 @llvm.riscv.vmv.x.s.i8.nxv4i8(<vscale x 4 x i8>)
; Function Attrs: nounwind
declare i8 @llvm.riscv.vmv.x.s.i8.nxv1i8(<vscale x 1 x i8>)

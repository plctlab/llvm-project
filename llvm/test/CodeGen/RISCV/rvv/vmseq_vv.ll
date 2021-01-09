; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmseq_vv_i8mf8_b64(<vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i8mf8_b64
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i8(<vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmseq_vv_i8mf4_b32(<vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i8mf4_b32
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i8(<vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmseq_vv_i8mf2_b16(<vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i8mf2_b16
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i8(<vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmseq_vv_i8m1_b8(<vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i8m1_b8
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i8(<vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmseq_vv_i8m2_b4(<vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i8m2_b4
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmseq.vv.nxv16i1.nxv16i8(<vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i1> @test_vmseq_vv_i8m4_b2(<vscale x 32 x i8> %op1, <vscale x 32 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i8m4_b2
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i1> @llvm.riscv.vmseq.vv.nxv32i1.nxv32i8(<vscale x 32 x i8> %op1, <vscale x 32 x i8> %op2)
  ret <vscale x 32 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i1> @test_vmseq_vv_i8m8_b1(<vscale x 64 x i8> %op1, <vscale x 64 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i8m8_b1
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i1> @llvm.riscv.vmseq.vv.nxv64i1.nxv64i8(<vscale x 64 x i8> %op1, <vscale x 64 x i8> %op2)
  ret <vscale x 64 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmseq_vv_i16mf4_b64(<vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i16mf4_b64
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i16(<vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmseq_vv_i16mf2_b32(<vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i16mf2_b32
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i16(<vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmseq_vv_i16m1_b16(<vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i16m1_b16
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i16(<vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmseq_vv_i16m2_b8(<vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i16m2_b8
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i16(<vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmseq_vv_i16m4_b4(<vscale x 16 x i16> %op1, <vscale x 16 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i16m4_b4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmseq.vv.nxv16i1.nxv16i16(<vscale x 16 x i16> %op1, <vscale x 16 x i16> %op2)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i1> @test_vmseq_vv_i16m8_b2(<vscale x 32 x i16> %op1, <vscale x 32 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i16m8_b2
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i1> @llvm.riscv.vmseq.vv.nxv32i1.nxv32i16(<vscale x 32 x i16> %op1, <vscale x 32 x i16> %op2)
  ret <vscale x 32 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmseq_vv_i32mf2_b64(<vscale x 1 x i32> %op1, <vscale x 1 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i32mf2_b64
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i32(<vscale x 1 x i32> %op1, <vscale x 1 x i32> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmseq_vv_i32m1_b32(<vscale x 2 x i32> %op1, <vscale x 2 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i32m1_b32
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i32(<vscale x 2 x i32> %op1, <vscale x 2 x i32> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmseq_vv_i32m2_b16(<vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i32m2_b16
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i32(<vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmseq_vv_i32m4_b8(<vscale x 8 x i32> %op1, <vscale x 8 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i32m4_b8
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i32(<vscale x 8 x i32> %op1, <vscale x 8 x i32> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmseq_vv_i32m8_b4(<vscale x 16 x i32> %op1, <vscale x 16 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i32m8_b4
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmseq.vv.nxv16i1.nxv16i32(<vscale x 16 x i32> %op1, <vscale x 16 x i32> %op2)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmseq_vv_i64m1_b64(<vscale x 1 x i64> %op1, <vscale x 1 x i64> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i64m1_b64
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i64(<vscale x 1 x i64> %op1, <vscale x 1 x i64> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmseq_vv_i64m2_b32(<vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i64m2_b32
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i64(<vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmseq_vv_i64m4_b16(<vscale x 4 x i64> %op1, <vscale x 4 x i64> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i64m4_b16
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i64(<vscale x 4 x i64> %op1, <vscale x 4 x i64> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmseq_vv_i64m8_b8(<vscale x 8 x i64> %op1, <vscale x 8 x i64> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_i64m8_b8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i64(<vscale x 8 x i64> %op1, <vscale x 8 x i64> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmseq_vv_u8mf8_b64(<vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u8mf8_b64
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i8(<vscale x 1 x i8> %op1, <vscale x 1 x i8> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmseq_vv_u8mf4_b32(<vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u8mf4_b32
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i8(<vscale x 2 x i8> %op1, <vscale x 2 x i8> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmseq_vv_u8mf2_b16(<vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u8mf2_b16
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i8(<vscale x 4 x i8> %op1, <vscale x 4 x i8> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmseq_vv_u8m1_b8(<vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u8m1_b8
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i8(<vscale x 8 x i8> %op1, <vscale x 8 x i8> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmseq_vv_u8m2_b4(<vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u8m2_b4
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmseq.vv.nxv16i1.nxv16i8(<vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i1> @test_vmseq_vv_u8m4_b2(<vscale x 32 x i8> %op1, <vscale x 32 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u8m4_b2
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i1> @llvm.riscv.vmseq.vv.nxv32i1.nxv32i8(<vscale x 32 x i8> %op1, <vscale x 32 x i8> %op2)
  ret <vscale x 32 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i1> @test_vmseq_vv_u8m8_b1(<vscale x 64 x i8> %op1, <vscale x 64 x i8> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u8m8_b1
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i1> @llvm.riscv.vmseq.vv.nxv64i1.nxv64i8(<vscale x 64 x i8> %op1, <vscale x 64 x i8> %op2)
  ret <vscale x 64 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmseq_vv_u16mf4_b64(<vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u16mf4_b64
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i16(<vscale x 1 x i16> %op1, <vscale x 1 x i16> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmseq_vv_u16mf2_b32(<vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u16mf2_b32
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i16(<vscale x 2 x i16> %op1, <vscale x 2 x i16> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmseq_vv_u16m1_b16(<vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u16m1_b16
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i16(<vscale x 4 x i16> %op1, <vscale x 4 x i16> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmseq_vv_u16m2_b8(<vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u16m2_b8
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i16(<vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmseq_vv_u16m4_b4(<vscale x 16 x i16> %op1, <vscale x 16 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u16m4_b4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmseq.vv.nxv16i1.nxv16i16(<vscale x 16 x i16> %op1, <vscale x 16 x i16> %op2)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i1> @test_vmseq_vv_u16m8_b2(<vscale x 32 x i16> %op1, <vscale x 32 x i16> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u16m8_b2
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i1> @llvm.riscv.vmseq.vv.nxv32i1.nxv32i16(<vscale x 32 x i16> %op1, <vscale x 32 x i16> %op2)
  ret <vscale x 32 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmseq_vv_u32mf2_b64(<vscale x 1 x i32> %op1, <vscale x 1 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u32mf2_b64
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i32(<vscale x 1 x i32> %op1, <vscale x 1 x i32> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmseq_vv_u32m1_b32(<vscale x 2 x i32> %op1, <vscale x 2 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u32m1_b32
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i32(<vscale x 2 x i32> %op1, <vscale x 2 x i32> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmseq_vv_u32m2_b16(<vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u32m2_b16
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i32(<vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmseq_vv_u32m4_b8(<vscale x 8 x i32> %op1, <vscale x 8 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u32m4_b8
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i32(<vscale x 8 x i32> %op1, <vscale x 8 x i32> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i1> @test_vmseq_vv_u32m8_b4(<vscale x 16 x i32> %op1, <vscale x 16 x i32> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u32m8_b4
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i1> @llvm.riscv.vmseq.vv.nxv16i1.nxv16i32(<vscale x 16 x i32> %op1, <vscale x 16 x i32> %op2)
  ret <vscale x 16 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i1> @test_vmseq_vv_u64m1_b64(<vscale x 1 x i64> %op1, <vscale x 1 x i64> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u64m1_b64
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i64(<vscale x 1 x i64> %op1, <vscale x 1 x i64> %op2)
  ret <vscale x 1 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i1> @test_vmseq_vv_u64m2_b32(<vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u64m2_b32
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i64(<vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2)
  ret <vscale x 2 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i1> @test_vmseq_vv_u64m4_b16(<vscale x 4 x i64> %op1, <vscale x 4 x i64> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u64m4_b16
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i64(<vscale x 4 x i64> %op1, <vscale x 4 x i64> %op2)
  ret <vscale x 4 x i1> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i1> @test_vmseq_vv_u64m8_b8(<vscale x 8 x i64> %op1, <vscale x 8 x i64> %op2) {
entry:
; CHECK-LABEL: vmseq_vv_u64m8_b8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vmseq.vv {{v[0-9]+}}, {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i64(<vscale x 8 x i64> %op1, <vscale x 8 x i64> %op2)
  ret <vscale x 8 x i1> %call
}

; Function Attrs: nounwind
declare <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i32(<vscale x 8 x i32>, <vscale x 8 x i32>)
; Function Attrs: nounwind
declare <vscale x 32 x i1> @llvm.riscv.vmseq.vv.nxv32i1.nxv32i8(<vscale x 32 x i8>, <vscale x 32 x i8>)
; Function Attrs: nounwind
declare <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i32(<vscale x 4 x i32>, <vscale x 4 x i32>)
; Function Attrs: nounwind
declare <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>)
; Function Attrs: nounwind
declare <vscale x 64 x i1> @llvm.riscv.vmseq.vv.nxv64i1.nxv64i8(<vscale x 64 x i8>, <vscale x 64 x i8>)
; Function Attrs: nounwind
declare <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i16(<vscale x 1 x i16>, <vscale x 1 x i16>)
; Function Attrs: nounwind
declare <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i32(<vscale x 1 x i32>, <vscale x 1 x i32>)
; Function Attrs: nounwind
declare <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i16(<vscale x 2 x i16>, <vscale x 2 x i16>)
; Function Attrs: nounwind
declare <vscale x 16 x i1> @llvm.riscv.vmseq.vv.nxv16i1.nxv16i8(<vscale x 16 x i8>, <vscale x 16 x i8>)
; Function Attrs: nounwind
declare <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>)
; Function Attrs: nounwind
declare <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>)
; Function Attrs: nounwind
declare <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i64(<vscale x 2 x i64>, <vscale x 2 x i64>)
; Function Attrs: nounwind
declare <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i64(<vscale x 4 x i64>, <vscale x 4 x i64>)
; Function Attrs: nounwind
declare <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>)
; Function Attrs: nounwind
declare <vscale x 4 x i1> @llvm.riscv.vmseq.vv.nxv4i1.nxv4i8(<vscale x 4 x i8>, <vscale x 4 x i8>)
; Function Attrs: nounwind
declare <vscale x 32 x i1> @llvm.riscv.vmseq.vv.nxv32i1.nxv32i16(<vscale x 32 x i16>, <vscale x 32 x i16>)
; Function Attrs: nounwind
declare <vscale x 16 x i1> @llvm.riscv.vmseq.vv.nxv16i1.nxv16i32(<vscale x 16 x i32>, <vscale x 16 x i32>)
; Function Attrs: nounwind
declare <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i64(<vscale x 8 x i64>, <vscale x 8 x i64>)
; Function Attrs: nounwind
declare <vscale x 16 x i1> @llvm.riscv.vmseq.vv.nxv16i1.nxv16i16(<vscale x 16 x i16>, <vscale x 16 x i16>)
; Function Attrs: nounwind
declare <vscale x 2 x i1> @llvm.riscv.vmseq.vv.nxv2i1.nxv2i8(<vscale x 2 x i8>, <vscale x 2 x i8>)
; Function Attrs: nounwind
declare <vscale x 8 x i1> @llvm.riscv.vmseq.vv.nxv8i1.nxv8i16(<vscale x 8 x i16>, <vscale x 8 x i16>)
; Function Attrs: nounwind
declare <vscale x 1 x i1> @llvm.riscv.vmseq.vv.nxv1i1.nxv1i8(<vscale x 1 x i8>, <vscale x 1 x i8>)

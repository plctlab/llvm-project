; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.u8mf8.b64(<vscale x 1 x i8>, i8);
define <vscale x 1 x i1> @vmsleu_vx_u8mf8_b64(<vscale x 1 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8mf8_b64
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.u8mf8.b64(<vscale x 1 x i8> %0, i8 %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.u8mf4.b32(<vscale x 2 x i8>, i8);
define <vscale x 2 x i1> @vmsleu_vx_u8mf4_b32(<vscale x 2 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8mf4_b32
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.u8mf4.b32(<vscale x 2 x i8> %0, i8 %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.u8mf2.b16(<vscale x 4 x i8>, i8);
define <vscale x 4 x i1> @vmsleu_vx_u8mf2_b16(<vscale x 4 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8mf2_b16
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.u8mf2.b16(<vscale x 4 x i8> %0, i8 %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.u8m1.b8(<vscale x 8 x i8>, i8);
define <vscale x 8 x i1> @vmsleu_vx_u8m1_b8(<vscale x 8 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8m1_b8
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.u8m1.b8(<vscale x 8 x i8> %0, i8 %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.u8m2.b4(<vscale x 16 x i8>, i8);
define <vscale x 16 x i1> @vmsleu_vx_u8m2_b4(<vscale x 16 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8m2_b4
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.u8m2.b4(<vscale x 16 x i8> %0, i8 %1)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmsleu.vx.u8m4.b2(<vscale x 32 x i8>, i8);
define <vscale x 32 x i1> @vmsleu_vx_u8m4_b2(<vscale x 32 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8m4_b2
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmsleu.vx.u8m4.b2(<vscale x 32 x i8> %0, i8 %1)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 64 x i1> @llvm.riscv.vmsleu.vx.u8m8.b1(<vscale x 64 x i8>, i8);
define <vscale x 64 x i1> @vmsleu_vx_u8m8_b1(<vscale x 64 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8m8_b1
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i1> @llvm.riscv.vmsleu.vx.u8m8.b1(<vscale x 64 x i8> %0, i8 %1)
  ret <vscale x 64 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.u16mf4.b64(<vscale x 1 x i16>, i16);
define <vscale x 1 x i1> @vmsleu_vx_u16mf4_b64(<vscale x 1 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16mf4_b64
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.u16mf4.b64(<vscale x 1 x i16> %0, i16 %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.u16mf2.b32(<vscale x 2 x i16>, i16);
define <vscale x 2 x i1> @vmsleu_vx_u16mf2_b32(<vscale x 2 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16mf2_b32
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.u16mf2.b32(<vscale x 2 x i16> %0, i16 %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.u16m1.b16(<vscale x 4 x i16>, i16);
define <vscale x 4 x i1> @vmsleu_vx_u16m1_b16(<vscale x 4 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16m1_b16
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.u16m1.b16(<vscale x 4 x i16> %0, i16 %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.u16m2.b8(<vscale x 8 x i16>, i16);
define <vscale x 8 x i1> @vmsleu_vx_u16m2_b8(<vscale x 8 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16m2_b8
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.u16m2.b8(<vscale x 8 x i16> %0, i16 %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.u16m4.b4(<vscale x 16 x i16>, i16);
define <vscale x 16 x i1> @vmsleu_vx_u16m4_b4(<vscale x 16 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16m4_b4
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.u16m4.b4(<vscale x 16 x i16> %0, i16 %1)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmsleu.vx.u16m8.b2(<vscale x 32 x i16>, i16);
define <vscale x 32 x i1> @vmsleu_vx_u16m8_b2(<vscale x 32 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16m8_b2
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmsleu.vx.u16m8.b2(<vscale x 32 x i16> %0, i16 %1)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.u32mf2.b64(<vscale x 1 x i32>, i32);
define <vscale x 1 x i1> @vmsleu_vx_u32mf2_b64(<vscale x 1 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32mf2_b64
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.u32mf2.b64(<vscale x 1 x i32> %0, i32 %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.u32m1.b32(<vscale x 2 x i32>, i32);
define <vscale x 2 x i1> @vmsleu_vx_u32m1_b32(<vscale x 2 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32m1_b32
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.u32m1.b32(<vscale x 2 x i32> %0, i32 %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.u32m2.b16(<vscale x 4 x i32>, i32);
define <vscale x 4 x i1> @vmsleu_vx_u32m2_b16(<vscale x 4 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32m2_b16
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.u32m2.b16(<vscale x 4 x i32> %0, i32 %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.u32m4.b8(<vscale x 8 x i32>, i32);
define <vscale x 8 x i1> @vmsleu_vx_u32m4_b8(<vscale x 8 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32m4_b8
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.u32m4.b8(<vscale x 8 x i32> %0, i32 %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.u32m8.b4(<vscale x 16 x i32>, i32);
define <vscale x 16 x i1> @vmsleu_vx_u32m8_b4(<vscale x 16 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32m8_b4
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.u32m8.b4(<vscale x 16 x i32> %0, i32 %1)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.u64m1.b64(<vscale x 1 x i64>, i64);
define <vscale x 1 x i1> @vmsleu_vx_u64m1_b64(<vscale x 1 x i64> %0, i64 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u64m1_b64
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.u64m1.b64(<vscale x 1 x i64> %0, i64 %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.u64m2.b32(<vscale x 2 x i64>, i64);
define <vscale x 2 x i1> @vmsleu_vx_u64m2_b32(<vscale x 2 x i64> %0, i64 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u64m2_b32
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.u64m2.b32(<vscale x 2 x i64> %0, i64 %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.u64m4.b16(<vscale x 4 x i64>, i64);
define <vscale x 4 x i1> @vmsleu_vx_u64m4_b16(<vscale x 4 x i64> %0, i64 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u64m4_b16
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.u64m4.b16(<vscale x 4 x i64> %0, i64 %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.u64m8.b8(<vscale x 8 x i64>, i64);
define <vscale x 8 x i1> @vmsleu_vx_u64m8_b8(<vscale x 8 x i64> %0, i64 %1) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u64m8_b8
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.u64m8.b8(<vscale x 8 x i64> %0, i64 %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.mask.u8mf8.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x i8>, i8);
define <vscale x 1 x i1> @vmsleu_vx_u8mf8_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8mf8_b64_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.mask.u8mf8.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i8> %2, i8 %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.mask.u8mf4.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x i8>, i8);
define <vscale x 2 x i1> @vmsleu_vx_u8mf4_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8mf4_b32_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.mask.u8mf4.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i8> %2, i8 %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.mask.u8mf2.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x i8>, i8);
define <vscale x 4 x i1> @vmsleu_vx_u8mf2_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8mf2_b16_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.mask.u8mf2.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i8> %2, i8 %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.mask.u8m1.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x i8>, i8);
define <vscale x 8 x i1> @vmsleu_vx_u8m1_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8m1_b8_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.mask.u8m1.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i8> %2, i8 %3)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.mask.u8m2.b4(<vscale x 16 x i1>, <vscale x 16 x i1>, <vscale x 16 x i8>, i8);
define <vscale x 16 x i1> @vmsleu_vx_u8m2_b4_m(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8m2_b4_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.mask.u8m2.b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i8> %2, i8 %3)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmsleu.vx.mask.u8m4.b2(<vscale x 32 x i1>, <vscale x 32 x i1>, <vscale x 32 x i8>, i8);
define <vscale x 32 x i1> @vmsleu_vx_u8m4_b2_m(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8m4_b2_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmsleu.vx.mask.u8m4.b2(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x i8> %2, i8 %3)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 64 x i1> @llvm.riscv.vmsleu.vx.mask.u8m8.b1(<vscale x 64 x i1>, <vscale x 64 x i1>, <vscale x 64 x i8>, i8);
define <vscale x 64 x i1> @vmsleu_vx_u8m8_b1_m(<vscale x 64 x i1> %0, <vscale x 64 x i1> %1, <vscale x 64 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u8m8_b1_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 64 x i1> @llvm.riscv.vmsleu.vx.mask.u8m8.b1(<vscale x 64 x i1> %0, <vscale x 64 x i1> %1, <vscale x 64 x i8> %2, i8 %3)
  ret <vscale x 64 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.mask.u16mf4.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x i16>, i16);
define <vscale x 1 x i1> @vmsleu_vx_u16mf4_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16mf4_b64_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.mask.u16mf4.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i16> %2, i16 %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.mask.u16mf2.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x i16>, i16);
define <vscale x 2 x i1> @vmsleu_vx_u16mf2_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16mf2_b32_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.mask.u16mf2.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i16> %2, i16 %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.mask.u16m1.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x i16>, i16);
define <vscale x 4 x i1> @vmsleu_vx_u16m1_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16m1_b16_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.mask.u16m1.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i16> %2, i16 %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.mask.u16m2.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x i16>, i16);
define <vscale x 8 x i1> @vmsleu_vx_u16m2_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16m2_b8_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.mask.u16m2.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i16> %2, i16 %3)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.mask.u16m4.b4(<vscale x 16 x i1>, <vscale x 16 x i1>, <vscale x 16 x i16>, i16);
define <vscale x 16 x i1> @vmsleu_vx_u16m4_b4_m(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16m4_b4_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.mask.u16m4.b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i16> %2, i16 %3)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmsleu.vx.mask.u16m8.b2(<vscale x 32 x i1>, <vscale x 32 x i1>, <vscale x 32 x i16>, i16);
define <vscale x 32 x i1> @vmsleu_vx_u16m8_b2_m(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u16m8_b2_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmsleu.vx.mask.u16m8.b2(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x i16> %2, i16 %3)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.mask.u32mf2.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x i32>, i32);
define <vscale x 1 x i1> @vmsleu_vx_u32mf2_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32mf2_b64_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.mask.u32mf2.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i32> %2, i32 %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.mask.u32m1.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x i32>, i32);
define <vscale x 2 x i1> @vmsleu_vx_u32m1_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32m1_b32_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.mask.u32m1.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i32> %2, i32 %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.mask.u32m2.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x i32>, i32);
define <vscale x 4 x i1> @vmsleu_vx_u32m2_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32m2_b16_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.mask.u32m2.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i32> %2, i32 %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.mask.u32m4.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x i32>, i32);
define <vscale x 8 x i1> @vmsleu_vx_u32m4_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32m4_b8_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.mask.u32m4.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i32> %2, i32 %3)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.mask.u32m8.b4(<vscale x 16 x i1>, <vscale x 16 x i1>, <vscale x 16 x i32>, i32);
define <vscale x 16 x i1> @vmsleu_vx_u32m8_b4_m(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u32m8_b4_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsleu.vx.mask.u32m8.b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i32> %2, i32 %3)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.mask.u64m1.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x i64>, i64);
define <vscale x 1 x i1> @vmsleu_vx_u64m1_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i64> %2, i64 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u64m1_b64_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsleu.vx.mask.u64m1.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i64> %2, i64 %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.mask.u64m2.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x i64>, i64);
define <vscale x 2 x i1> @vmsleu_vx_u64m2_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i64> %2, i64 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u64m2_b32_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsleu.vx.mask.u64m2.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i64> %2, i64 %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.mask.u64m4.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x i64>, i64);
define <vscale x 4 x i1> @vmsleu_vx_u64m4_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i64> %2, i64 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u64m4_b16_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsleu.vx.mask.u64m4.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i64> %2, i64 %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.mask.u64m8.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x i64>, i64);
define <vscale x 8 x i1> @vmsleu_vx_u64m8_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i64> %2, i64 %3) {
entry:
  ; CHECK-LABEL: vmsleu_vx_u64m8_b8_m
  ; CHECK: vmsleu.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsleu.vx.mask.u64m8.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i64> %2, i64 %3)
  ret <vscale x 8 x i1> %a
}


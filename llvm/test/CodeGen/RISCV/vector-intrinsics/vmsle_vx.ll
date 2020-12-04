; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i1> @llvm.riscv.vmsle.vx.i8mf8.b64(<vscale x 1 x i8>, i8);
define <vscale x 1 x i1> @vmsle_vx_i8mf8_b64(<vscale x 1 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8mf8_b64
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsle.vx.i8mf8.b64(<vscale x 1 x i8> %0, i8 %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsle.vx.i8mf4.b32(<vscale x 2 x i8>, i8);
define <vscale x 2 x i1> @vmsle_vx_i8mf4_b32(<vscale x 2 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8mf4_b32
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsle.vx.i8mf4.b32(<vscale x 2 x i8> %0, i8 %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsle.vx.i8mf2.b16(<vscale x 4 x i8>, i8);
define <vscale x 4 x i1> @vmsle_vx_i8mf2_b16(<vscale x 4 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8mf2_b16
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsle.vx.i8mf2.b16(<vscale x 4 x i8> %0, i8 %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsle.vx.i8m1.b8(<vscale x 8 x i8>, i8);
define <vscale x 8 x i1> @vmsle_vx_i8m1_b8(<vscale x 8 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8m1_b8
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsle.vx.i8m1.b8(<vscale x 8 x i8> %0, i8 %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsle.vx.i8m2.b4(<vscale x 16 x i8>, i8);
define <vscale x 16 x i1> @vmsle_vx_i8m2_b4(<vscale x 16 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8m2_b4
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsle.vx.i8m2.b4(<vscale x 16 x i8> %0, i8 %1)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmsle.vx.i8m4.b2(<vscale x 32 x i8>, i8);
define <vscale x 32 x i1> @vmsle_vx_i8m4_b2(<vscale x 32 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8m4_b2
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmsle.vx.i8m4.b2(<vscale x 32 x i8> %0, i8 %1)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 64 x i1> @llvm.riscv.vmsle.vx.i8m8.b1(<vscale x 64 x i8>, i8);
define <vscale x 64 x i1> @vmsle_vx_i8m8_b1(<vscale x 64 x i8> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8m8_b1
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i1> @llvm.riscv.vmsle.vx.i8m8.b1(<vscale x 64 x i8> %0, i8 %1)
  ret <vscale x 64 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsle.vx.i16mf4.b64(<vscale x 1 x i16>, i16);
define <vscale x 1 x i1> @vmsle_vx_i16mf4_b64(<vscale x 1 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16mf4_b64
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsle.vx.i16mf4.b64(<vscale x 1 x i16> %0, i16 %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsle.vx.i16mf2.b32(<vscale x 2 x i16>, i16);
define <vscale x 2 x i1> @vmsle_vx_i16mf2_b32(<vscale x 2 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16mf2_b32
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsle.vx.i16mf2.b32(<vscale x 2 x i16> %0, i16 %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsle.vx.i16m1.b16(<vscale x 4 x i16>, i16);
define <vscale x 4 x i1> @vmsle_vx_i16m1_b16(<vscale x 4 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16m1_b16
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsle.vx.i16m1.b16(<vscale x 4 x i16> %0, i16 %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsle.vx.i16m2.b8(<vscale x 8 x i16>, i16);
define <vscale x 8 x i1> @vmsle_vx_i16m2_b8(<vscale x 8 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16m2_b8
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsle.vx.i16m2.b8(<vscale x 8 x i16> %0, i16 %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsle.vx.i16m4.b4(<vscale x 16 x i16>, i16);
define <vscale x 16 x i1> @vmsle_vx_i16m4_b4(<vscale x 16 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16m4_b4
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsle.vx.i16m4.b4(<vscale x 16 x i16> %0, i16 %1)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmsle.vx.i16m8.b2(<vscale x 32 x i16>, i16);
define <vscale x 32 x i1> @vmsle_vx_i16m8_b2(<vscale x 32 x i16> %0, i16 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16m8_b2
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmsle.vx.i16m8.b2(<vscale x 32 x i16> %0, i16 %1)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsle.vx.i32mf2.b64(<vscale x 1 x i32>, i32);
define <vscale x 1 x i1> @vmsle_vx_i32mf2_b64(<vscale x 1 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32mf2_b64
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsle.vx.i32mf2.b64(<vscale x 1 x i32> %0, i32 %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsle.vx.i32m1.b32(<vscale x 2 x i32>, i32);
define <vscale x 2 x i1> @vmsle_vx_i32m1_b32(<vscale x 2 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32m1_b32
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsle.vx.i32m1.b32(<vscale x 2 x i32> %0, i32 %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsle.vx.i32m2.b16(<vscale x 4 x i32>, i32);
define <vscale x 4 x i1> @vmsle_vx_i32m2_b16(<vscale x 4 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32m2_b16
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsle.vx.i32m2.b16(<vscale x 4 x i32> %0, i32 %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsle.vx.i32m4.b8(<vscale x 8 x i32>, i32);
define <vscale x 8 x i1> @vmsle_vx_i32m4_b8(<vscale x 8 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32m4_b8
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsle.vx.i32m4.b8(<vscale x 8 x i32> %0, i32 %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsle.vx.i32m8.b4(<vscale x 16 x i32>, i32);
define <vscale x 16 x i1> @vmsle_vx_i32m8_b4(<vscale x 16 x i32> %0, i32 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32m8_b4
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsle.vx.i32m8.b4(<vscale x 16 x i32> %0, i32 %1)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsle.vx.i64m1.b64(<vscale x 1 x i64>, i64);
define <vscale x 1 x i1> @vmsle_vx_i64m1_b64(<vscale x 1 x i64> %0, i64 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i64m1_b64
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsle.vx.i64m1.b64(<vscale x 1 x i64> %0, i64 %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsle.vx.i64m2.b32(<vscale x 2 x i64>, i64);
define <vscale x 2 x i1> @vmsle_vx_i64m2_b32(<vscale x 2 x i64> %0, i64 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i64m2_b32
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsle.vx.i64m2.b32(<vscale x 2 x i64> %0, i64 %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsle.vx.i64m4.b16(<vscale x 4 x i64>, i64);
define <vscale x 4 x i1> @vmsle_vx_i64m4_b16(<vscale x 4 x i64> %0, i64 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i64m4_b16
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsle.vx.i64m4.b16(<vscale x 4 x i64> %0, i64 %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsle.vx.i64m8.b8(<vscale x 8 x i64>, i64);
define <vscale x 8 x i1> @vmsle_vx_i64m8_b8(<vscale x 8 x i64> %0, i64 %1) {
entry:
  ; CHECK-LABEL: vmsle_vx_i64m8_b8
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsle.vx.i64m8.b8(<vscale x 8 x i64> %0, i64 %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsle.vx.mask.i8mf8.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x i8>, i8);
define <vscale x 1 x i1> @vmsle_vx_i8mf8_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8mf8_b64_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsle.vx.mask.i8mf8.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i8> %2, i8 %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsle.vx.mask.i8mf4.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x i8>, i8);
define <vscale x 2 x i1> @vmsle_vx_i8mf4_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8mf4_b32_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsle.vx.mask.i8mf4.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i8> %2, i8 %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsle.vx.mask.i8mf2.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x i8>, i8);
define <vscale x 4 x i1> @vmsle_vx_i8mf2_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8mf2_b16_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsle.vx.mask.i8mf2.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i8> %2, i8 %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsle.vx.mask.i8m1.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x i8>, i8);
define <vscale x 8 x i1> @vmsle_vx_i8m1_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8m1_b8_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsle.vx.mask.i8m1.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i8> %2, i8 %3)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsle.vx.mask.i8m2.b4(<vscale x 16 x i1>, <vscale x 16 x i1>, <vscale x 16 x i8>, i8);
define <vscale x 16 x i1> @vmsle_vx_i8m2_b4_m(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8m2_b4_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsle.vx.mask.i8m2.b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i8> %2, i8 %3)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmsle.vx.mask.i8m4.b2(<vscale x 32 x i1>, <vscale x 32 x i1>, <vscale x 32 x i8>, i8);
define <vscale x 32 x i1> @vmsle_vx_i8m4_b2_m(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8m4_b2_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmsle.vx.mask.i8m4.b2(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x i8> %2, i8 %3)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 64 x i1> @llvm.riscv.vmsle.vx.mask.i8m8.b1(<vscale x 64 x i1>, <vscale x 64 x i1>, <vscale x 64 x i8>, i8);
define <vscale x 64 x i1> @vmsle_vx_i8m8_b1_m(<vscale x 64 x i1> %0, <vscale x 64 x i1> %1, <vscale x 64 x i8> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i8m8_b1_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 64 x i1> @llvm.riscv.vmsle.vx.mask.i8m8.b1(<vscale x 64 x i1> %0, <vscale x 64 x i1> %1, <vscale x 64 x i8> %2, i8 %3)
  ret <vscale x 64 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsle.vx.mask.i16mf4.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x i16>, i16);
define <vscale x 1 x i1> @vmsle_vx_i16mf4_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16mf4_b64_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsle.vx.mask.i16mf4.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i16> %2, i16 %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsle.vx.mask.i16mf2.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x i16>, i16);
define <vscale x 2 x i1> @vmsle_vx_i16mf2_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16mf2_b32_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsle.vx.mask.i16mf2.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i16> %2, i16 %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsle.vx.mask.i16m1.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x i16>, i16);
define <vscale x 4 x i1> @vmsle_vx_i16m1_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16m1_b16_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsle.vx.mask.i16m1.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i16> %2, i16 %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsle.vx.mask.i16m2.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x i16>, i16);
define <vscale x 8 x i1> @vmsle_vx_i16m2_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16m2_b8_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsle.vx.mask.i16m2.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i16> %2, i16 %3)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsle.vx.mask.i16m4.b4(<vscale x 16 x i1>, <vscale x 16 x i1>, <vscale x 16 x i16>, i16);
define <vscale x 16 x i1> @vmsle_vx_i16m4_b4_m(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16m4_b4_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsle.vx.mask.i16m4.b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i16> %2, i16 %3)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmsle.vx.mask.i16m8.b2(<vscale x 32 x i1>, <vscale x 32 x i1>, <vscale x 32 x i16>, i16);
define <vscale x 32 x i1> @vmsle_vx_i16m8_b2_m(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x i16> %2, i16 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i16m8_b2_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmsle.vx.mask.i16m8.b2(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x i16> %2, i16 %3)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsle.vx.mask.i32mf2.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x i32>, i32);
define <vscale x 1 x i1> @vmsle_vx_i32mf2_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32mf2_b64_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsle.vx.mask.i32mf2.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i32> %2, i32 %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsle.vx.mask.i32m1.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x i32>, i32);
define <vscale x 2 x i1> @vmsle_vx_i32m1_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32m1_b32_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsle.vx.mask.i32m1.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i32> %2, i32 %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsle.vx.mask.i32m2.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x i32>, i32);
define <vscale x 4 x i1> @vmsle_vx_i32m2_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32m2_b16_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsle.vx.mask.i32m2.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i32> %2, i32 %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsle.vx.mask.i32m4.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x i32>, i32);
define <vscale x 8 x i1> @vmsle_vx_i32m4_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32m4_b8_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsle.vx.mask.i32m4.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i32> %2, i32 %3)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmsle.vx.mask.i32m8.b4(<vscale x 16 x i1>, <vscale x 16 x i1>, <vscale x 16 x i32>, i32);
define <vscale x 16 x i1> @vmsle_vx_i32m8_b4_m(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i32> %2, i32 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i32m8_b4_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmsle.vx.mask.i32m8.b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x i32> %2, i32 %3)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmsle.vx.mask.i64m1.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x i64>, i64);
define <vscale x 1 x i1> @vmsle_vx_i64m1_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i64> %2, i64 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i64m1_b64_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmsle.vx.mask.i64m1.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x i64> %2, i64 %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmsle.vx.mask.i64m2.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x i64>, i64);
define <vscale x 2 x i1> @vmsle_vx_i64m2_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i64> %2, i64 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i64m2_b32_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmsle.vx.mask.i64m2.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x i64> %2, i64 %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmsle.vx.mask.i64m4.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x i64>, i64);
define <vscale x 4 x i1> @vmsle_vx_i64m4_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i64> %2, i64 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i64m4_b16_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmsle.vx.mask.i64m4.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i64> %2, i64 %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmsle.vx.mask.i64m8.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x i64>, i64);
define <vscale x 8 x i1> @vmsle_vx_i64m8_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i64> %2, i64 %3) {
entry:
  ; CHECK-LABEL: vmsle_vx_i64m8_b8_m
  ; CHECK: vmsle.vx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmsle.vx.mask.i64m8.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x i64> %2, i64 %3)
  ret <vscale x 8 x i1> %a
}


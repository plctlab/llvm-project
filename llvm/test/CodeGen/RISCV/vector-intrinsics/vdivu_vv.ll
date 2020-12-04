; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i8> @llvm.riscv.vdivu.vv.u8mf8(<vscale x 1 x i8>, <vscale x 1 x i8>);
define <vscale x 1 x i8> @vdivu_vv_u8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8mf8
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vdivu.vv.u8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vdivu.vv.u8mf4(<vscale x 2 x i8>, <vscale x 2 x i8>);
define <vscale x 2 x i8> @vdivu_vv_u8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8mf4
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vdivu.vv.u8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vdivu.vv.u8mf2(<vscale x 4 x i8>, <vscale x 4 x i8>);
define <vscale x 4 x i8> @vdivu_vv_u8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8mf2
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vdivu.vv.u8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vdivu.vv.u8m1(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vdivu_vv_u8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8m1
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vdivu.vv.u8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vdivu.vv.u8m2(<vscale x 16 x i8>, <vscale x 16 x i8>);
define <vscale x 16 x i8> @vdivu_vv_u8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8m2
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vdivu.vv.u8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vdivu.vv.u8m4(<vscale x 32 x i8>, <vscale x 32 x i8>);
define <vscale x 32 x i8> @vdivu_vv_u8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8m4
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vdivu.vv.u8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vdivu.vv.u8m8(<vscale x 64 x i8>, <vscale x 64 x i8>);
define <vscale x 64 x i8> @vdivu_vv_u8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8m8
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vdivu.vv.u8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1)
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vdivu.vv.u16mf4(<vscale x 1 x i16>, <vscale x 1 x i16>);
define <vscale x 1 x i16> @vdivu_vv_u16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16mf4
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vdivu.vv.u16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vdivu.vv.u16mf2(<vscale x 2 x i16>, <vscale x 2 x i16>);
define <vscale x 2 x i16> @vdivu_vv_u16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16mf2
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vdivu.vv.u16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vdivu.vv.u16m1(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vdivu_vv_u16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16m1
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vdivu.vv.u16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vdivu.vv.u16m2(<vscale x 8 x i16>, <vscale x 8 x i16>);
define <vscale x 8 x i16> @vdivu_vv_u16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16m2
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vdivu.vv.u16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vdivu.vv.u16m4(<vscale x 16 x i16>, <vscale x 16 x i16>);
define <vscale x 16 x i16> @vdivu_vv_u16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16m4
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vdivu.vv.u16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vdivu.vv.u16m8(<vscale x 32 x i16>, <vscale x 32 x i16>);
define <vscale x 32 x i16> @vdivu_vv_u16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16m8
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vdivu.vv.u16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vdivu.vv.u32mf2(<vscale x 1 x i32>, <vscale x 1 x i32>);
define <vscale x 1 x i32> @vdivu_vv_u32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32mf2
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vdivu.vv.u32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vdivu.vv.u32m1(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vdivu_vv_u32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32m1
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vdivu.vv.u32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vdivu.vv.u32m2(<vscale x 4 x i32>, <vscale x 4 x i32>);
define <vscale x 4 x i32> @vdivu_vv_u32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32m2
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vdivu.vv.u32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vdivu.vv.u32m4(<vscale x 8 x i32>, <vscale x 8 x i32>);
define <vscale x 8 x i32> @vdivu_vv_u32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32m4
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vdivu.vv.u32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vdivu.vv.u32m8(<vscale x 16 x i32>, <vscale x 16 x i32>);
define <vscale x 16 x i32> @vdivu_vv_u32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32m8
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vdivu.vv.u32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vdivu.vv.u64m1(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vdivu_vv_u64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u64m1
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vdivu.vv.u64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vdivu.vv.u64m2(<vscale x 2 x i64>, <vscale x 2 x i64>);
define <vscale x 2 x i64> @vdivu_vv_u64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u64m2
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vdivu.vv.u64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vdivu.vv.u64m4(<vscale x 4 x i64>, <vscale x 4 x i64>);
define <vscale x 4 x i64> @vdivu_vv_u64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u64m4
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vdivu.vv.u64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vdivu.vv.u64m8(<vscale x 8 x i64>, <vscale x 8 x i64>);
define <vscale x 8 x i64> @vdivu_vv_u64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1) {
entry:
  ; CHECK-LABEL: vdivu_vv_u64m8
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vdivu.vv.u64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1)
  ret <vscale x 8 x i64> %a
}

declare <vscale x 1 x i8> @llvm.riscv.vdivu.vv.mask.u8mf8(<vscale x 1 x i1>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>);
define <vscale x 1 x i8> @vdivu_vv_u8mf8_m(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1, <vscale x 1 x i8> %2, <vscale x 1 x i8> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8mf8_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vdivu.vv.mask.u8mf8(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1, <vscale x 1 x i8> %2, <vscale x 1 x i8> %3)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vdivu.vv.mask.u8mf4(<vscale x 2 x i1>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>);
define <vscale x 2 x i8> @vdivu_vv_u8mf4_m(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1, <vscale x 2 x i8> %2, <vscale x 2 x i8> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8mf4_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vdivu.vv.mask.u8mf4(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1, <vscale x 2 x i8> %2, <vscale x 2 x i8> %3)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vdivu.vv.mask.u8mf2(<vscale x 4 x i1>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>);
define <vscale x 4 x i8> @vdivu_vv_u8mf2_m(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1, <vscale x 4 x i8> %2, <vscale x 4 x i8> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8mf2_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vdivu.vv.mask.u8mf2(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1, <vscale x 4 x i8> %2, <vscale x 4 x i8> %3)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vdivu.vv.mask.u8m1(<vscale x 8 x i1>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vdivu_vv_u8m1_m(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1, <vscale x 8 x i8> %2, <vscale x 8 x i8> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8m1_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vdivu.vv.mask.u8m1(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1, <vscale x 8 x i8> %2, <vscale x 8 x i8> %3)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vdivu.vv.mask.u8m2(<vscale x 16 x i1>, <vscale x 16 x i8>, <vscale x 16 x i8>, <vscale x 16 x i8>);
define <vscale x 16 x i8> @vdivu_vv_u8m2_m(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i8> %2, <vscale x 16 x i8> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8m2_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vdivu.vv.mask.u8m2(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i8> %2, <vscale x 16 x i8> %3)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vdivu.vv.mask.u8m4(<vscale x 32 x i1>, <vscale x 32 x i8>, <vscale x 32 x i8>, <vscale x 32 x i8>);
define <vscale x 32 x i8> @vdivu_vv_u8m4_m(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1, <vscale x 32 x i8> %2, <vscale x 32 x i8> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8m4_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vdivu.vv.mask.u8m4(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1, <vscale x 32 x i8> %2, <vscale x 32 x i8> %3)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vdivu.vv.mask.u8m8(<vscale x 64 x i1>, <vscale x 64 x i8>, <vscale x 64 x i8>, <vscale x 64 x i8>);
define <vscale x 64 x i8> @vdivu_vv_u8m8_m(<vscale x 64 x i1> %0, <vscale x 64 x i8> %1, <vscale x 64 x i8> %2, <vscale x 64 x i8> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u8m8_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vdivu.vv.mask.u8m8(<vscale x 64 x i1> %0, <vscale x 64 x i8> %1, <vscale x 64 x i8> %2, <vscale x 64 x i8> %3)
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vdivu.vv.mask.u16mf4(<vscale x 1 x i1>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>);
define <vscale x 1 x i16> @vdivu_vv_u16mf4_m(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x i16> %2, <vscale x 1 x i16> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16mf4_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vdivu.vv.mask.u16mf4(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x i16> %2, <vscale x 1 x i16> %3)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vdivu.vv.mask.u16mf2(<vscale x 2 x i1>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>);
define <vscale x 2 x i16> @vdivu_vv_u16mf2_m(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x i16> %2, <vscale x 2 x i16> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16mf2_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vdivu.vv.mask.u16mf2(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x i16> %2, <vscale x 2 x i16> %3)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vdivu.vv.mask.u16m1(<vscale x 4 x i1>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vdivu_vv_u16m1_m(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x i16> %2, <vscale x 4 x i16> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16m1_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vdivu.vv.mask.u16m1(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x i16> %2, <vscale x 4 x i16> %3)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vdivu.vv.mask.u16m2(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>);
define <vscale x 8 x i16> @vdivu_vv_u16m2_m(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x i16> %2, <vscale x 8 x i16> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16m2_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vdivu.vv.mask.u16m2(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x i16> %2, <vscale x 8 x i16> %3)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vdivu.vv.mask.u16m4(<vscale x 16 x i1>, <vscale x 16 x i16>, <vscale x 16 x i16>, <vscale x 16 x i16>);
define <vscale x 16 x i16> @vdivu_vv_u16m4_m(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x i16> %2, <vscale x 16 x i16> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16m4_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vdivu.vv.mask.u16m4(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x i16> %2, <vscale x 16 x i16> %3)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vdivu.vv.mask.u16m8(<vscale x 32 x i1>, <vscale x 32 x i16>, <vscale x 32 x i16>, <vscale x 32 x i16>);
define <vscale x 32 x i16> @vdivu_vv_u16m8_m(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1, <vscale x 32 x i16> %2, <vscale x 32 x i16> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u16m8_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vdivu.vv.mask.u16m8(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1, <vscale x 32 x i16> %2, <vscale x 32 x i16> %3)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vdivu.vv.mask.u32mf2(<vscale x 1 x i1>, <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>);
define <vscale x 1 x i32> @vdivu_vv_u32mf2_m(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x i32> %2, <vscale x 1 x i32> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32mf2_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vdivu.vv.mask.u32mf2(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x i32> %2, <vscale x 1 x i32> %3)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vdivu.vv.mask.u32m1(<vscale x 2 x i1>, <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vdivu_vv_u32m1_m(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x i32> %2, <vscale x 2 x i32> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32m1_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vdivu.vv.mask.u32m1(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x i32> %2, <vscale x 2 x i32> %3)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vdivu.vv.mask.u32m2(<vscale x 4 x i1>, <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>);
define <vscale x 4 x i32> @vdivu_vv_u32m2_m(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i32> %2, <vscale x 4 x i32> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32m2_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vdivu.vv.mask.u32m2(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i32> %2, <vscale x 4 x i32> %3)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vdivu.vv.mask.u32m4(<vscale x 8 x i1>, <vscale x 8 x i32>, <vscale x 8 x i32>, <vscale x 8 x i32>);
define <vscale x 8 x i32> @vdivu_vv_u32m4_m(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x i32> %2, <vscale x 8 x i32> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32m4_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vdivu.vv.mask.u32m4(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x i32> %2, <vscale x 8 x i32> %3)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vdivu.vv.mask.u32m8(<vscale x 16 x i1>, <vscale x 16 x i32>, <vscale x 16 x i32>, <vscale x 16 x i32>);
define <vscale x 16 x i32> @vdivu_vv_u32m8_m(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x i32> %2, <vscale x 16 x i32> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u32m8_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vdivu.vv.mask.u32m8(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x i32> %2, <vscale x 16 x i32> %3)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vdivu.vv.mask.u64m1(<vscale x 1 x i1>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vdivu_vv_u64m1_m(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x i64> %2, <vscale x 1 x i64> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u64m1_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vdivu.vv.mask.u64m1(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x i64> %2, <vscale x 1 x i64> %3)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vdivu.vv.mask.u64m2(<vscale x 2 x i1>, <vscale x 2 x i64>, <vscale x 2 x i64>, <vscale x 2 x i64>);
define <vscale x 2 x i64> @vdivu_vv_u64m2_m(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x i64> %2, <vscale x 2 x i64> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u64m2_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vdivu.vv.mask.u64m2(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x i64> %2, <vscale x 2 x i64> %3)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vdivu.vv.mask.u64m4(<vscale x 4 x i1>, <vscale x 4 x i64>, <vscale x 4 x i64>, <vscale x 4 x i64>);
define <vscale x 4 x i64> @vdivu_vv_u64m4_m(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x i64> %2, <vscale x 4 x i64> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u64m4_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vdivu.vv.mask.u64m4(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x i64> %2, <vscale x 4 x i64> %3)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vdivu.vv.mask.u64m8(<vscale x 8 x i1>, <vscale x 8 x i64>, <vscale x 8 x i64>, <vscale x 8 x i64>);
define <vscale x 8 x i64> @vdivu_vv_u64m8_m(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x i64> %2, <vscale x 8 x i64> %3) {
entry:
  ; CHECK-LABEL: vdivu_vv_u64m8_m
  ; CHECK: vdivu.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vdivu.vv.mask.u64m8(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x i64> %2, <vscale x 8 x i64> %3)
  ret <vscale x 8 x i64> %a
}


; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i8> @llvm.riscv.vand.vv.i8mf8(<vscale x 1 x i8>, <vscale x 1 x i8>);
define <vscale x 1 x i8> @vand_vv_i8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i8mf8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vand.vv.i8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vand.vv.i8mf4(<vscale x 2 x i8>, <vscale x 2 x i8>);
define <vscale x 2 x i8> @vand_vv_i8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i8mf4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vand.vv.i8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vand.vv.i8mf2(<vscale x 4 x i8>, <vscale x 4 x i8>);
define <vscale x 4 x i8> @vand_vv_i8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i8mf2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vand.vv.i8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vand.vv.i8m1(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vand_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i8m1
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vand.vv.i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vand.vv.i8m2(<vscale x 16 x i8>, <vscale x 16 x i8>);
define <vscale x 16 x i8> @vand_vv_i8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i8m2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vand.vv.i8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vand.vv.i8m4(<vscale x 32 x i8>, <vscale x 32 x i8>);
define <vscale x 32 x i8> @vand_vv_i8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i8m4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vand.vv.i8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vand.vv.i8m8(<vscale x 64 x i8>, <vscale x 64 x i8>);
define <vscale x 64 x i8> @vand_vv_i8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i8m8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vand.vv.i8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1)
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vand.vv.i16mf4(<vscale x 1 x i16>, <vscale x 1 x i16>);
define <vscale x 1 x i16> @vand_vv_i16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i16mf4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vand.vv.i16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vand.vv.i16mf2(<vscale x 2 x i16>, <vscale x 2 x i16>);
define <vscale x 2 x i16> @vand_vv_i16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i16mf2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vand.vv.i16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vand.vv.i16m1(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vand_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i16m1
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vand.vv.i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vand.vv.i16m2(<vscale x 8 x i16>, <vscale x 8 x i16>);
define <vscale x 8 x i16> @vand_vv_i16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i16m2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vand.vv.i16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vand.vv.i16m4(<vscale x 16 x i16>, <vscale x 16 x i16>);
define <vscale x 16 x i16> @vand_vv_i16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i16m4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vand.vv.i16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vand.vv.i16m8(<vscale x 32 x i16>, <vscale x 32 x i16>);
define <vscale x 32 x i16> @vand_vv_i16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i16m8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vand.vv.i16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vand.vv.i32mf2(<vscale x 1 x i32>, <vscale x 1 x i32>);
define <vscale x 1 x i32> @vand_vv_i32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i32mf2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vand.vv.i32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vand.vv.i32m1(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vand_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i32m1
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vand.vv.i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vand.vv.i32m2(<vscale x 4 x i32>, <vscale x 4 x i32>);
define <vscale x 4 x i32> @vand_vv_i32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i32m2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vand.vv.i32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vand.vv.i32m4(<vscale x 8 x i32>, <vscale x 8 x i32>);
define <vscale x 8 x i32> @vand_vv_i32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i32m4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vand.vv.i32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vand.vv.i32m8(<vscale x 16 x i32>, <vscale x 16 x i32>);
define <vscale x 16 x i32> @vand_vv_i32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i32m8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vand.vv.i32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vand.vv.i64m1(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vand_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i64m1
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vand.vv.i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vand.vv.i64m2(<vscale x 2 x i64>, <vscale x 2 x i64>);
define <vscale x 2 x i64> @vand_vv_i64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i64m2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vand.vv.i64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vand.vv.i64m4(<vscale x 4 x i64>, <vscale x 4 x i64>);
define <vscale x 4 x i64> @vand_vv_i64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i64m4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vand.vv.i64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vand.vv.i64m8(<vscale x 8 x i64>, <vscale x 8 x i64>);
define <vscale x 8 x i64> @vand_vv_i64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1) {
entry:
  ; CHECK-LABEL: vand_vv_i64m8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vand.vv.i64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1)
  ret <vscale x 8 x i64> %a
}

declare <vscale x 1 x i8> @llvm.riscv.vand.vv.u8mf8(<vscale x 1 x i8>, <vscale x 1 x i8>);
define <vscale x 1 x i8> @vand_vv_u8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u8mf8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vand.vv.u8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vand.vv.u8mf4(<vscale x 2 x i8>, <vscale x 2 x i8>);
define <vscale x 2 x i8> @vand_vv_u8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u8mf4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vand.vv.u8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vand.vv.u8mf2(<vscale x 4 x i8>, <vscale x 4 x i8>);
define <vscale x 4 x i8> @vand_vv_u8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u8mf2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vand.vv.u8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vand.vv.u8m1(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vand_vv_u8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u8m1
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vand.vv.u8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vand.vv.u8m2(<vscale x 16 x i8>, <vscale x 16 x i8>);
define <vscale x 16 x i8> @vand_vv_u8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u8m2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vand.vv.u8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vand.vv.u8m4(<vscale x 32 x i8>, <vscale x 32 x i8>);
define <vscale x 32 x i8> @vand_vv_u8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u8m4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vand.vv.u8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vand.vv.u8m8(<vscale x 64 x i8>, <vscale x 64 x i8>);
define <vscale x 64 x i8> @vand_vv_u8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u8m8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vand.vv.u8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1)
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vand.vv.u16mf4(<vscale x 1 x i16>, <vscale x 1 x i16>);
define <vscale x 1 x i16> @vand_vv_u16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u16mf4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vand.vv.u16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vand.vv.u16mf2(<vscale x 2 x i16>, <vscale x 2 x i16>);
define <vscale x 2 x i16> @vand_vv_u16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u16mf2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vand.vv.u16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vand.vv.u16m1(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vand_vv_u16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u16m1
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vand.vv.u16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vand.vv.u16m2(<vscale x 8 x i16>, <vscale x 8 x i16>);
define <vscale x 8 x i16> @vand_vv_u16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u16m2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vand.vv.u16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vand.vv.u16m4(<vscale x 16 x i16>, <vscale x 16 x i16>);
define <vscale x 16 x i16> @vand_vv_u16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u16m4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vand.vv.u16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vand.vv.u16m8(<vscale x 32 x i16>, <vscale x 32 x i16>);
define <vscale x 32 x i16> @vand_vv_u16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u16m8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vand.vv.u16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vand.vv.u32mf2(<vscale x 1 x i32>, <vscale x 1 x i32>);
define <vscale x 1 x i32> @vand_vv_u32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u32mf2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vand.vv.u32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vand.vv.u32m1(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vand_vv_u32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u32m1
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vand.vv.u32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vand.vv.u32m2(<vscale x 4 x i32>, <vscale x 4 x i32>);
define <vscale x 4 x i32> @vand_vv_u32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u32m2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vand.vv.u32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vand.vv.u32m4(<vscale x 8 x i32>, <vscale x 8 x i32>);
define <vscale x 8 x i32> @vand_vv_u32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u32m4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vand.vv.u32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vand.vv.u32m8(<vscale x 16 x i32>, <vscale x 16 x i32>);
define <vscale x 16 x i32> @vand_vv_u32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u32m8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vand.vv.u32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vand.vv.u64m1(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vand_vv_u64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u64m1
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vand.vv.u64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vand.vv.u64m2(<vscale x 2 x i64>, <vscale x 2 x i64>);
define <vscale x 2 x i64> @vand_vv_u64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u64m2
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vand.vv.u64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vand.vv.u64m4(<vscale x 4 x i64>, <vscale x 4 x i64>);
define <vscale x 4 x i64> @vand_vv_u64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u64m4
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vand.vv.u64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vand.vv.u64m8(<vscale x 8 x i64>, <vscale x 8 x i64>);
define <vscale x 8 x i64> @vand_vv_u64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1) {
entry:
  ; CHECK-LABEL: vand_vv_u64m8
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vand.vv.u64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1)
  ret <vscale x 8 x i64> %a
}

declare <vscale x 1 x i8> @llvm.riscv.vand.vv.mask.i8mf8(<vscale x 1 x i1>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>);
define <vscale x 1 x i8> @vand_vv_i8mf8_m(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1, <vscale x 1 x i8> %2, <vscale x 1 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i8mf8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vand.vv.mask.i8mf8(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1, <vscale x 1 x i8> %2, <vscale x 1 x i8> %3)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vand.vv.mask.i8mf4(<vscale x 2 x i1>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>);
define <vscale x 2 x i8> @vand_vv_i8mf4_m(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1, <vscale x 2 x i8> %2, <vscale x 2 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i8mf4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vand.vv.mask.i8mf4(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1, <vscale x 2 x i8> %2, <vscale x 2 x i8> %3)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vand.vv.mask.i8mf2(<vscale x 4 x i1>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>);
define <vscale x 4 x i8> @vand_vv_i8mf2_m(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1, <vscale x 4 x i8> %2, <vscale x 4 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i8mf2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vand.vv.mask.i8mf2(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1, <vscale x 4 x i8> %2, <vscale x 4 x i8> %3)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vand.vv.mask.i8m1(<vscale x 8 x i1>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vand_vv_i8m1_m(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1, <vscale x 8 x i8> %2, <vscale x 8 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i8m1_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vand.vv.mask.i8m1(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1, <vscale x 8 x i8> %2, <vscale x 8 x i8> %3)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vand.vv.mask.i8m2(<vscale x 16 x i1>, <vscale x 16 x i8>, <vscale x 16 x i8>, <vscale x 16 x i8>);
define <vscale x 16 x i8> @vand_vv_i8m2_m(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i8> %2, <vscale x 16 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i8m2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vand.vv.mask.i8m2(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i8> %2, <vscale x 16 x i8> %3)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vand.vv.mask.i8m4(<vscale x 32 x i1>, <vscale x 32 x i8>, <vscale x 32 x i8>, <vscale x 32 x i8>);
define <vscale x 32 x i8> @vand_vv_i8m4_m(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1, <vscale x 32 x i8> %2, <vscale x 32 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i8m4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vand.vv.mask.i8m4(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1, <vscale x 32 x i8> %2, <vscale x 32 x i8> %3)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vand.vv.mask.i8m8(<vscale x 64 x i1>, <vscale x 64 x i8>, <vscale x 64 x i8>, <vscale x 64 x i8>);
define <vscale x 64 x i8> @vand_vv_i8m8_m(<vscale x 64 x i1> %0, <vscale x 64 x i8> %1, <vscale x 64 x i8> %2, <vscale x 64 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i8m8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vand.vv.mask.i8m8(<vscale x 64 x i1> %0, <vscale x 64 x i8> %1, <vscale x 64 x i8> %2, <vscale x 64 x i8> %3)
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vand.vv.mask.i16mf4(<vscale x 1 x i1>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>);
define <vscale x 1 x i16> @vand_vv_i16mf4_m(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x i16> %2, <vscale x 1 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i16mf4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vand.vv.mask.i16mf4(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x i16> %2, <vscale x 1 x i16> %3)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vand.vv.mask.i16mf2(<vscale x 2 x i1>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>);
define <vscale x 2 x i16> @vand_vv_i16mf2_m(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x i16> %2, <vscale x 2 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i16mf2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vand.vv.mask.i16mf2(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x i16> %2, <vscale x 2 x i16> %3)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vand.vv.mask.i16m1(<vscale x 4 x i1>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vand_vv_i16m1_m(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x i16> %2, <vscale x 4 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i16m1_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vand.vv.mask.i16m1(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x i16> %2, <vscale x 4 x i16> %3)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vand.vv.mask.i16m2(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>);
define <vscale x 8 x i16> @vand_vv_i16m2_m(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x i16> %2, <vscale x 8 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i16m2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vand.vv.mask.i16m2(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x i16> %2, <vscale x 8 x i16> %3)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vand.vv.mask.i16m4(<vscale x 16 x i1>, <vscale x 16 x i16>, <vscale x 16 x i16>, <vscale x 16 x i16>);
define <vscale x 16 x i16> @vand_vv_i16m4_m(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x i16> %2, <vscale x 16 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i16m4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vand.vv.mask.i16m4(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x i16> %2, <vscale x 16 x i16> %3)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vand.vv.mask.i16m8(<vscale x 32 x i1>, <vscale x 32 x i16>, <vscale x 32 x i16>, <vscale x 32 x i16>);
define <vscale x 32 x i16> @vand_vv_i16m8_m(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1, <vscale x 32 x i16> %2, <vscale x 32 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i16m8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vand.vv.mask.i16m8(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1, <vscale x 32 x i16> %2, <vscale x 32 x i16> %3)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vand.vv.mask.i32mf2(<vscale x 1 x i1>, <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>);
define <vscale x 1 x i32> @vand_vv_i32mf2_m(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x i32> %2, <vscale x 1 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i32mf2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vand.vv.mask.i32mf2(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x i32> %2, <vscale x 1 x i32> %3)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vand.vv.mask.i32m1(<vscale x 2 x i1>, <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vand_vv_i32m1_m(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x i32> %2, <vscale x 2 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i32m1_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vand.vv.mask.i32m1(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x i32> %2, <vscale x 2 x i32> %3)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vand.vv.mask.i32m2(<vscale x 4 x i1>, <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>);
define <vscale x 4 x i32> @vand_vv_i32m2_m(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i32> %2, <vscale x 4 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i32m2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vand.vv.mask.i32m2(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i32> %2, <vscale x 4 x i32> %3)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vand.vv.mask.i32m4(<vscale x 8 x i1>, <vscale x 8 x i32>, <vscale x 8 x i32>, <vscale x 8 x i32>);
define <vscale x 8 x i32> @vand_vv_i32m4_m(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x i32> %2, <vscale x 8 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i32m4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vand.vv.mask.i32m4(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x i32> %2, <vscale x 8 x i32> %3)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vand.vv.mask.i32m8(<vscale x 16 x i1>, <vscale x 16 x i32>, <vscale x 16 x i32>, <vscale x 16 x i32>);
define <vscale x 16 x i32> @vand_vv_i32m8_m(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x i32> %2, <vscale x 16 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i32m8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vand.vv.mask.i32m8(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x i32> %2, <vscale x 16 x i32> %3)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vand.vv.mask.i64m1(<vscale x 1 x i1>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vand_vv_i64m1_m(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x i64> %2, <vscale x 1 x i64> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i64m1_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vand.vv.mask.i64m1(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x i64> %2, <vscale x 1 x i64> %3)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vand.vv.mask.i64m2(<vscale x 2 x i1>, <vscale x 2 x i64>, <vscale x 2 x i64>, <vscale x 2 x i64>);
define <vscale x 2 x i64> @vand_vv_i64m2_m(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x i64> %2, <vscale x 2 x i64> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i64m2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vand.vv.mask.i64m2(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x i64> %2, <vscale x 2 x i64> %3)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vand.vv.mask.i64m4(<vscale x 4 x i1>, <vscale x 4 x i64>, <vscale x 4 x i64>, <vscale x 4 x i64>);
define <vscale x 4 x i64> @vand_vv_i64m4_m(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x i64> %2, <vscale x 4 x i64> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i64m4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vand.vv.mask.i64m4(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x i64> %2, <vscale x 4 x i64> %3)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vand.vv.mask.i64m8(<vscale x 8 x i1>, <vscale x 8 x i64>, <vscale x 8 x i64>, <vscale x 8 x i64>);
define <vscale x 8 x i64> @vand_vv_i64m8_m(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x i64> %2, <vscale x 8 x i64> %3) {
entry:
  ; CHECK-LABEL: vand_vv_i64m8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vand.vv.mask.i64m8(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x i64> %2, <vscale x 8 x i64> %3)
  ret <vscale x 8 x i64> %a
}

declare <vscale x 1 x i8> @llvm.riscv.vand.vv.mask.u8mf8(<vscale x 1 x i1>, <vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i8>);
define <vscale x 1 x i8> @vand_vv_u8mf8_m(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1, <vscale x 1 x i8> %2, <vscale x 1 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u8mf8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vand.vv.mask.u8mf8(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1, <vscale x 1 x i8> %2, <vscale x 1 x i8> %3)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vand.vv.mask.u8mf4(<vscale x 2 x i1>, <vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i8>);
define <vscale x 2 x i8> @vand_vv_u8mf4_m(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1, <vscale x 2 x i8> %2, <vscale x 2 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u8mf4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vand.vv.mask.u8mf4(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1, <vscale x 2 x i8> %2, <vscale x 2 x i8> %3)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vand.vv.mask.u8mf2(<vscale x 4 x i1>, <vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i8>);
define <vscale x 4 x i8> @vand_vv_u8mf2_m(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1, <vscale x 4 x i8> %2, <vscale x 4 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u8mf2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vand.vv.mask.u8mf2(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1, <vscale x 4 x i8> %2, <vscale x 4 x i8> %3)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vand.vv.mask.u8m1(<vscale x 8 x i1>, <vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vand_vv_u8m1_m(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1, <vscale x 8 x i8> %2, <vscale x 8 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u8m1_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vand.vv.mask.u8m1(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1, <vscale x 8 x i8> %2, <vscale x 8 x i8> %3)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vand.vv.mask.u8m2(<vscale x 16 x i1>, <vscale x 16 x i8>, <vscale x 16 x i8>, <vscale x 16 x i8>);
define <vscale x 16 x i8> @vand_vv_u8m2_m(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i8> %2, <vscale x 16 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u8m2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vand.vv.mask.u8m2(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i8> %2, <vscale x 16 x i8> %3)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vand.vv.mask.u8m4(<vscale x 32 x i1>, <vscale x 32 x i8>, <vscale x 32 x i8>, <vscale x 32 x i8>);
define <vscale x 32 x i8> @vand_vv_u8m4_m(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1, <vscale x 32 x i8> %2, <vscale x 32 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u8m4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vand.vv.mask.u8m4(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1, <vscale x 32 x i8> %2, <vscale x 32 x i8> %3)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vand.vv.mask.u8m8(<vscale x 64 x i1>, <vscale x 64 x i8>, <vscale x 64 x i8>, <vscale x 64 x i8>);
define <vscale x 64 x i8> @vand_vv_u8m8_m(<vscale x 64 x i1> %0, <vscale x 64 x i8> %1, <vscale x 64 x i8> %2, <vscale x 64 x i8> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u8m8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vand.vv.mask.u8m8(<vscale x 64 x i1> %0, <vscale x 64 x i8> %1, <vscale x 64 x i8> %2, <vscale x 64 x i8> %3)
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vand.vv.mask.u16mf4(<vscale x 1 x i1>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>);
define <vscale x 1 x i16> @vand_vv_u16mf4_m(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x i16> %2, <vscale x 1 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u16mf4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vand.vv.mask.u16mf4(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x i16> %2, <vscale x 1 x i16> %3)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vand.vv.mask.u16mf2(<vscale x 2 x i1>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>);
define <vscale x 2 x i16> @vand_vv_u16mf2_m(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x i16> %2, <vscale x 2 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u16mf2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vand.vv.mask.u16mf2(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x i16> %2, <vscale x 2 x i16> %3)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vand.vv.mask.u16m1(<vscale x 4 x i1>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vand_vv_u16m1_m(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x i16> %2, <vscale x 4 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u16m1_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vand.vv.mask.u16m1(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x i16> %2, <vscale x 4 x i16> %3)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vand.vv.mask.u16m2(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i16>);
define <vscale x 8 x i16> @vand_vv_u16m2_m(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x i16> %2, <vscale x 8 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u16m2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vand.vv.mask.u16m2(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x i16> %2, <vscale x 8 x i16> %3)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vand.vv.mask.u16m4(<vscale x 16 x i1>, <vscale x 16 x i16>, <vscale x 16 x i16>, <vscale x 16 x i16>);
define <vscale x 16 x i16> @vand_vv_u16m4_m(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x i16> %2, <vscale x 16 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u16m4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vand.vv.mask.u16m4(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x i16> %2, <vscale x 16 x i16> %3)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vand.vv.mask.u16m8(<vscale x 32 x i1>, <vscale x 32 x i16>, <vscale x 32 x i16>, <vscale x 32 x i16>);
define <vscale x 32 x i16> @vand_vv_u16m8_m(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1, <vscale x 32 x i16> %2, <vscale x 32 x i16> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u16m8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vand.vv.mask.u16m8(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1, <vscale x 32 x i16> %2, <vscale x 32 x i16> %3)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vand.vv.mask.u32mf2(<vscale x 1 x i1>, <vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i32>);
define <vscale x 1 x i32> @vand_vv_u32mf2_m(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x i32> %2, <vscale x 1 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u32mf2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vand.vv.mask.u32mf2(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x i32> %2, <vscale x 1 x i32> %3)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vand.vv.mask.u32m1(<vscale x 2 x i1>, <vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vand_vv_u32m1_m(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x i32> %2, <vscale x 2 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u32m1_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vand.vv.mask.u32m1(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x i32> %2, <vscale x 2 x i32> %3)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vand.vv.mask.u32m2(<vscale x 4 x i1>, <vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i32>);
define <vscale x 4 x i32> @vand_vv_u32m2_m(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i32> %2, <vscale x 4 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u32m2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vand.vv.mask.u32m2(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i32> %2, <vscale x 4 x i32> %3)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vand.vv.mask.u32m4(<vscale x 8 x i1>, <vscale x 8 x i32>, <vscale x 8 x i32>, <vscale x 8 x i32>);
define <vscale x 8 x i32> @vand_vv_u32m4_m(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x i32> %2, <vscale x 8 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u32m4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vand.vv.mask.u32m4(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x i32> %2, <vscale x 8 x i32> %3)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vand.vv.mask.u32m8(<vscale x 16 x i1>, <vscale x 16 x i32>, <vscale x 16 x i32>, <vscale x 16 x i32>);
define <vscale x 16 x i32> @vand_vv_u32m8_m(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x i32> %2, <vscale x 16 x i32> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u32m8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vand.vv.mask.u32m8(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x i32> %2, <vscale x 16 x i32> %3)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vand.vv.mask.u64m1(<vscale x 1 x i1>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vand_vv_u64m1_m(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x i64> %2, <vscale x 1 x i64> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u64m1_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vand.vv.mask.u64m1(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x i64> %2, <vscale x 1 x i64> %3)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vand.vv.mask.u64m2(<vscale x 2 x i1>, <vscale x 2 x i64>, <vscale x 2 x i64>, <vscale x 2 x i64>);
define <vscale x 2 x i64> @vand_vv_u64m2_m(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x i64> %2, <vscale x 2 x i64> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u64m2_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vand.vv.mask.u64m2(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x i64> %2, <vscale x 2 x i64> %3)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vand.vv.mask.u64m4(<vscale x 4 x i1>, <vscale x 4 x i64>, <vscale x 4 x i64>, <vscale x 4 x i64>);
define <vscale x 4 x i64> @vand_vv_u64m4_m(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x i64> %2, <vscale x 4 x i64> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u64m4_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vand.vv.mask.u64m4(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x i64> %2, <vscale x 4 x i64> %3)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vand.vv.mask.u64m8(<vscale x 8 x i1>, <vscale x 8 x i64>, <vscale x 8 x i64>, <vscale x 8 x i64>);
define <vscale x 8 x i64> @vand_vv_u64m8_m(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x i64> %2, <vscale x 8 x i64> %3) {
entry:
  ; CHECK-LABEL: vand_vv_u64m8_m
  ; CHECK: vand.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vand.vv.mask.u64m8(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x i64> %2, <vscale x 8 x i64> %3)
  ret <vscale x 8 x i64> %a
}


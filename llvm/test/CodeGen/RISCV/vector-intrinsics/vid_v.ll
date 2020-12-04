; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i8> @llvm.riscv.vid.v.u8mf8();
define <vscale x 1 x i8> @vid_v_u8mf8() {
entry:
  ; CHECK-LABEL: vid_v_u8mf8
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vid.v.u8mf8()
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vid.v.u8mf4();
define <vscale x 2 x i8> @vid_v_u8mf4() {
entry:
  ; CHECK-LABEL: vid_v_u8mf4
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vid.v.u8mf4()
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vid.v.u8mf2();
define <vscale x 4 x i8> @vid_v_u8mf2() {
entry:
  ; CHECK-LABEL: vid_v_u8mf2
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vid.v.u8mf2()
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vid.v.u8m1();
define <vscale x 8 x i8> @vid_v_u8m1() {
entry:
  ; CHECK-LABEL: vid_v_u8m1
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vid.v.u8m1()
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vid.v.u8m2();
define <vscale x 16 x i8> @vid_v_u8m2() {
entry:
  ; CHECK-LABEL: vid_v_u8m2
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vid.v.u8m2()
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vid.v.u8m4();
define <vscale x 32 x i8> @vid_v_u8m4() {
entry:
  ; CHECK-LABEL: vid_v_u8m4
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vid.v.u8m4()
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vid.v.u8m8();
define <vscale x 64 x i8> @vid_v_u8m8() {
entry:
  ; CHECK-LABEL: vid_v_u8m8
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vid.v.u8m8()
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vid.v.u16mf4();
define <vscale x 1 x i16> @vid_v_u16mf4() {
entry:
  ; CHECK-LABEL: vid_v_u16mf4
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vid.v.u16mf4()
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vid.v.u16mf2();
define <vscale x 2 x i16> @vid_v_u16mf2() {
entry:
  ; CHECK-LABEL: vid_v_u16mf2
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vid.v.u16mf2()
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vid.v.u16m1();
define <vscale x 4 x i16> @vid_v_u16m1() {
entry:
  ; CHECK-LABEL: vid_v_u16m1
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vid.v.u16m1()
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vid.v.u16m2();
define <vscale x 8 x i16> @vid_v_u16m2() {
entry:
  ; CHECK-LABEL: vid_v_u16m2
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vid.v.u16m2()
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vid.v.u16m4();
define <vscale x 16 x i16> @vid_v_u16m4() {
entry:
  ; CHECK-LABEL: vid_v_u16m4
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vid.v.u16m4()
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vid.v.u16m8();
define <vscale x 32 x i16> @vid_v_u16m8() {
entry:
  ; CHECK-LABEL: vid_v_u16m8
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vid.v.u16m8()
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vid.v.u32mf2();
define <vscale x 1 x i32> @vid_v_u32mf2() {
entry:
  ; CHECK-LABEL: vid_v_u32mf2
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vid.v.u32mf2()
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vid.v.u32m1();
define <vscale x 2 x i32> @vid_v_u32m1() {
entry:
  ; CHECK-LABEL: vid_v_u32m1
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vid.v.u32m1()
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vid.v.u32m2();
define <vscale x 4 x i32> @vid_v_u32m2() {
entry:
  ; CHECK-LABEL: vid_v_u32m2
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vid.v.u32m2()
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vid.v.u32m4();
define <vscale x 8 x i32> @vid_v_u32m4() {
entry:
  ; CHECK-LABEL: vid_v_u32m4
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vid.v.u32m4()
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vid.v.u32m8();
define <vscale x 16 x i32> @vid_v_u32m8() {
entry:
  ; CHECK-LABEL: vid_v_u32m8
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vid.v.u32m8()
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vid.v.u64m1();
define <vscale x 1 x i64> @vid_v_u64m1() {
entry:
  ; CHECK-LABEL: vid_v_u64m1
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vid.v.u64m1()
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vid.v.u64m2();
define <vscale x 2 x i64> @vid_v_u64m2() {
entry:
  ; CHECK-LABEL: vid_v_u64m2
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vid.v.u64m2()
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vid.v.u64m4();
define <vscale x 4 x i64> @vid_v_u64m4() {
entry:
  ; CHECK-LABEL: vid_v_u64m4
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vid.v.u64m4()
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vid.v.u64m8();
define <vscale x 8 x i64> @vid_v_u64m8() {
entry:
  ; CHECK-LABEL: vid_v_u64m8
  ; CHECK: vid.v v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vid.v.u64m8()
  ret <vscale x 8 x i64> %a
}

declare <vscale x 1 x i8> @llvm.riscv.vid.v.mask.u8mf8(<vscale x 1 x i1>, <vscale x 1 x i8>);
define <vscale x 1 x i8> @vid_v_u8mf8_m(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1) {
entry:
  ; CHECK-LABEL: vid_v_u8mf8_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vid.v.mask.u8mf8(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vid.v.mask.u8mf4(<vscale x 2 x i1>, <vscale x 2 x i8>);
define <vscale x 2 x i8> @vid_v_u8mf4_m(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1) {
entry:
  ; CHECK-LABEL: vid_v_u8mf4_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vid.v.mask.u8mf4(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vid.v.mask.u8mf2(<vscale x 4 x i1>, <vscale x 4 x i8>);
define <vscale x 4 x i8> @vid_v_u8mf2_m(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1) {
entry:
  ; CHECK-LABEL: vid_v_u8mf2_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vid.v.mask.u8mf2(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vid.v.mask.u8m1(<vscale x 8 x i1>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vid_v_u8m1_m(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1) {
entry:
  ; CHECK-LABEL: vid_v_u8m1_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vid.v.mask.u8m1(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vid.v.mask.u8m2(<vscale x 16 x i1>, <vscale x 16 x i8>);
define <vscale x 16 x i8> @vid_v_u8m2_m(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1) {
entry:
  ; CHECK-LABEL: vid_v_u8m2_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vid.v.mask.u8m2(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vid.v.mask.u8m4(<vscale x 32 x i1>, <vscale x 32 x i8>);
define <vscale x 32 x i8> @vid_v_u8m4_m(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1) {
entry:
  ; CHECK-LABEL: vid_v_u8m4_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vid.v.mask.u8m4(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vid.v.mask.u8m8(<vscale x 64 x i1>, <vscale x 64 x i8>);
define <vscale x 64 x i8> @vid_v_u8m8_m(<vscale x 64 x i1> %0, <vscale x 64 x i8> %1) {
entry:
  ; CHECK-LABEL: vid_v_u8m8_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vid.v.mask.u8m8(<vscale x 64 x i1> %0, <vscale x 64 x i8> %1)
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vid.v.mask.u16mf4(<vscale x 1 x i1>, <vscale x 1 x i16>);
define <vscale x 1 x i16> @vid_v_u16mf4_m(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1) {
entry:
  ; CHECK-LABEL: vid_v_u16mf4_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vid.v.mask.u16mf4(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vid.v.mask.u16mf2(<vscale x 2 x i1>, <vscale x 2 x i16>);
define <vscale x 2 x i16> @vid_v_u16mf2_m(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1) {
entry:
  ; CHECK-LABEL: vid_v_u16mf2_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vid.v.mask.u16mf2(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vid.v.mask.u16m1(<vscale x 4 x i1>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vid_v_u16m1_m(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1) {
entry:
  ; CHECK-LABEL: vid_v_u16m1_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vid.v.mask.u16m1(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vid.v.mask.u16m2(<vscale x 8 x i1>, <vscale x 8 x i16>);
define <vscale x 8 x i16> @vid_v_u16m2_m(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1) {
entry:
  ; CHECK-LABEL: vid_v_u16m2_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vid.v.mask.u16m2(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vid.v.mask.u16m4(<vscale x 16 x i1>, <vscale x 16 x i16>);
define <vscale x 16 x i16> @vid_v_u16m4_m(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1) {
entry:
  ; CHECK-LABEL: vid_v_u16m4_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vid.v.mask.u16m4(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vid.v.mask.u16m8(<vscale x 32 x i1>, <vscale x 32 x i16>);
define <vscale x 32 x i16> @vid_v_u16m8_m(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1) {
entry:
  ; CHECK-LABEL: vid_v_u16m8_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vid.v.mask.u16m8(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vid.v.mask.u32mf2(<vscale x 1 x i1>, <vscale x 1 x i32>);
define <vscale x 1 x i32> @vid_v_u32mf2_m(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1) {
entry:
  ; CHECK-LABEL: vid_v_u32mf2_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vid.v.mask.u32mf2(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vid.v.mask.u32m1(<vscale x 2 x i1>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vid_v_u32m1_m(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1) {
entry:
  ; CHECK-LABEL: vid_v_u32m1_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vid.v.mask.u32m1(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vid.v.mask.u32m2(<vscale x 4 x i1>, <vscale x 4 x i32>);
define <vscale x 4 x i32> @vid_v_u32m2_m(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1) {
entry:
  ; CHECK-LABEL: vid_v_u32m2_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vid.v.mask.u32m2(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vid.v.mask.u32m4(<vscale x 8 x i1>, <vscale x 8 x i32>);
define <vscale x 8 x i32> @vid_v_u32m4_m(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1) {
entry:
  ; CHECK-LABEL: vid_v_u32m4_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vid.v.mask.u32m4(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vid.v.mask.u32m8(<vscale x 16 x i1>, <vscale x 16 x i32>);
define <vscale x 16 x i32> @vid_v_u32m8_m(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1) {
entry:
  ; CHECK-LABEL: vid_v_u32m8_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vid.v.mask.u32m8(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vid.v.mask.u64m1(<vscale x 1 x i1>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vid_v_u64m1_m(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1) {
entry:
  ; CHECK-LABEL: vid_v_u64m1_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vid.v.mask.u64m1(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vid.v.mask.u64m2(<vscale x 2 x i1>, <vscale x 2 x i64>);
define <vscale x 2 x i64> @vid_v_u64m2_m(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1) {
entry:
  ; CHECK-LABEL: vid_v_u64m2_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vid.v.mask.u64m2(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vid.v.mask.u64m4(<vscale x 4 x i1>, <vscale x 4 x i64>);
define <vscale x 4 x i64> @vid_v_u64m4_m(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1) {
entry:
  ; CHECK-LABEL: vid_v_u64m4_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vid.v.mask.u64m4(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vid.v.mask.u64m8(<vscale x 8 x i1>, <vscale x 8 x i64>);
define <vscale x 8 x i64> @vid_v_u64m8_m(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1) {
entry:
  ; CHECK-LABEL: vid_v_u64m8_m
  ; CHECK: vid.v v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vid.v.mask.u64m8(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1)
  ret <vscale x 8 x i64> %a
}


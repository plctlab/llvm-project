; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i8> @llvm.riscv.vnclipu.wx.u8mf8(<vscale x 1 x i16>, i8);
define <vscale x 1 x i8> @vnclipu_wx_u8mf8(<vscale x 1 x i16> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8mf8
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vnclipu.wx.u8mf8(<vscale x 1 x i16> %0, i8 %1)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vnclipu.wx.u8mf4(<vscale x 2 x i16>, i8);
define <vscale x 2 x i8> @vnclipu_wx_u8mf4(<vscale x 2 x i16> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8mf4
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vnclipu.wx.u8mf4(<vscale x 2 x i16> %0, i8 %1)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vnclipu.wx.u8mf2(<vscale x 4 x i16>, i8);
define <vscale x 4 x i8> @vnclipu_wx_u8mf2(<vscale x 4 x i16> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8mf2
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vnclipu.wx.u8mf2(<vscale x 4 x i16> %0, i8 %1)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vnclipu.wx.u8m1(<vscale x 8 x i16>, i8);
define <vscale x 8 x i8> @vnclipu_wx_u8m1(<vscale x 8 x i16> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8m1
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vnclipu.wx.u8m1(<vscale x 8 x i16> %0, i8 %1)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vnclipu.wx.u8m2(<vscale x 16 x i16>, i8);
define <vscale x 16 x i8> @vnclipu_wx_u8m2(<vscale x 16 x i16> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8m2
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vnclipu.wx.u8m2(<vscale x 16 x i16> %0, i8 %1)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vnclipu.wx.u8m4(<vscale x 32 x i16>, i8);
define <vscale x 32 x i8> @vnclipu_wx_u8m4(<vscale x 32 x i16> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8m4
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vnclipu.wx.u8m4(<vscale x 32 x i16> %0, i8 %1)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vnclipu.wx.u16mf4(<vscale x 1 x i32>, i8);
define <vscale x 1 x i16> @vnclipu_wx_u16mf4(<vscale x 1 x i32> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16mf4
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vnclipu.wx.u16mf4(<vscale x 1 x i32> %0, i8 %1)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vnclipu.wx.u16mf2(<vscale x 2 x i32>, i8);
define <vscale x 2 x i16> @vnclipu_wx_u16mf2(<vscale x 2 x i32> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16mf2
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vnclipu.wx.u16mf2(<vscale x 2 x i32> %0, i8 %1)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vnclipu.wx.u16m1(<vscale x 4 x i32>, i8);
define <vscale x 4 x i16> @vnclipu_wx_u16m1(<vscale x 4 x i32> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16m1
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vnclipu.wx.u16m1(<vscale x 4 x i32> %0, i8 %1)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vnclipu.wx.u16m2(<vscale x 8 x i32>, i8);
define <vscale x 8 x i16> @vnclipu_wx_u16m2(<vscale x 8 x i32> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16m2
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vnclipu.wx.u16m2(<vscale x 8 x i32> %0, i8 %1)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vnclipu.wx.u16m4(<vscale x 16 x i32>, i8);
define <vscale x 16 x i16> @vnclipu_wx_u16m4(<vscale x 16 x i32> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16m4
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vnclipu.wx.u16m4(<vscale x 16 x i32> %0, i8 %1)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vnclipu.wx.u32mf2(<vscale x 1 x i64>, i8);
define <vscale x 1 x i32> @vnclipu_wx_u32mf2(<vscale x 1 x i64> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u32mf2
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vnclipu.wx.u32mf2(<vscale x 1 x i64> %0, i8 %1)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vnclipu.wx.u32m1(<vscale x 2 x i64>, i8);
define <vscale x 2 x i32> @vnclipu_wx_u32m1(<vscale x 2 x i64> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u32m1
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vnclipu.wx.u32m1(<vscale x 2 x i64> %0, i8 %1)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vnclipu.wx.u32m2(<vscale x 4 x i64>, i8);
define <vscale x 4 x i32> @vnclipu_wx_u32m2(<vscale x 4 x i64> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u32m2
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vnclipu.wx.u32m2(<vscale x 4 x i64> %0, i8 %1)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vnclipu.wx.u32m4(<vscale x 8 x i64>, i8);
define <vscale x 8 x i32> @vnclipu_wx_u32m4(<vscale x 8 x i64> %0, i8 %1) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u32m4
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vnclipu.wx.u32m4(<vscale x 8 x i64> %0, i8 %1)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 1 x i8> @llvm.riscv.vnclipu.wx.mask.u8mf8(<vscale x 1 x i1>, <vscale x 1 x i8>, <vscale x 1 x i16>, i8);
define <vscale x 1 x i8> @vnclipu_wx_u8mf8_m(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1, <vscale x 1 x i16> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8mf8_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vnclipu.wx.mask.u8mf8(<vscale x 1 x i1> %0, <vscale x 1 x i8> %1, <vscale x 1 x i16> %2, i8 %3)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vnclipu.wx.mask.u8mf4(<vscale x 2 x i1>, <vscale x 2 x i8>, <vscale x 2 x i16>, i8);
define <vscale x 2 x i8> @vnclipu_wx_u8mf4_m(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1, <vscale x 2 x i16> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8mf4_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vnclipu.wx.mask.u8mf4(<vscale x 2 x i1> %0, <vscale x 2 x i8> %1, <vscale x 2 x i16> %2, i8 %3)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vnclipu.wx.mask.u8mf2(<vscale x 4 x i1>, <vscale x 4 x i8>, <vscale x 4 x i16>, i8);
define <vscale x 4 x i8> @vnclipu_wx_u8mf2_m(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1, <vscale x 4 x i16> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8mf2_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vnclipu.wx.mask.u8mf2(<vscale x 4 x i1> %0, <vscale x 4 x i8> %1, <vscale x 4 x i16> %2, i8 %3)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vnclipu.wx.mask.u8m1(<vscale x 8 x i1>, <vscale x 8 x i8>, <vscale x 8 x i16>, i8);
define <vscale x 8 x i8> @vnclipu_wx_u8m1_m(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1, <vscale x 8 x i16> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8m1_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vnclipu.wx.mask.u8m1(<vscale x 8 x i1> %0, <vscale x 8 x i8> %1, <vscale x 8 x i16> %2, i8 %3)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vnclipu.wx.mask.u8m2(<vscale x 16 x i1>, <vscale x 16 x i8>, <vscale x 16 x i16>, i8);
define <vscale x 16 x i8> @vnclipu_wx_u8m2_m(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i16> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8m2_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vnclipu.wx.mask.u8m2(<vscale x 16 x i1> %0, <vscale x 16 x i8> %1, <vscale x 16 x i16> %2, i8 %3)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vnclipu.wx.mask.u8m4(<vscale x 32 x i1>, <vscale x 32 x i8>, <vscale x 32 x i16>, i8);
define <vscale x 32 x i8> @vnclipu_wx_u8m4_m(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1, <vscale x 32 x i16> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u8m4_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vnclipu.wx.mask.u8m4(<vscale x 32 x i1> %0, <vscale x 32 x i8> %1, <vscale x 32 x i16> %2, i8 %3)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vnclipu.wx.mask.u16mf4(<vscale x 1 x i1>, <vscale x 1 x i16>, <vscale x 1 x i32>, i8);
define <vscale x 1 x i16> @vnclipu_wx_u16mf4_m(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x i32> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16mf4_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vnclipu.wx.mask.u16mf4(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x i32> %2, i8 %3)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vnclipu.wx.mask.u16mf2(<vscale x 2 x i1>, <vscale x 2 x i16>, <vscale x 2 x i32>, i8);
define <vscale x 2 x i16> @vnclipu_wx_u16mf2_m(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x i32> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16mf2_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vnclipu.wx.mask.u16mf2(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x i32> %2, i8 %3)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vnclipu.wx.mask.u16m1(<vscale x 4 x i1>, <vscale x 4 x i16>, <vscale x 4 x i32>, i8);
define <vscale x 4 x i16> @vnclipu_wx_u16m1_m(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x i32> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16m1_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vnclipu.wx.mask.u16m1(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x i32> %2, i8 %3)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vnclipu.wx.mask.u16m2(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x i32>, i8);
define <vscale x 8 x i16> @vnclipu_wx_u16m2_m(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x i32> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16m2_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vnclipu.wx.mask.u16m2(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x i32> %2, i8 %3)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vnclipu.wx.mask.u16m4(<vscale x 16 x i1>, <vscale x 16 x i16>, <vscale x 16 x i32>, i8);
define <vscale x 16 x i16> @vnclipu_wx_u16m4_m(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x i32> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u16m4_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vnclipu.wx.mask.u16m4(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x i32> %2, i8 %3)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vnclipu.wx.mask.u32mf2(<vscale x 1 x i1>, <vscale x 1 x i32>, <vscale x 1 x i64>, i8);
define <vscale x 1 x i32> @vnclipu_wx_u32mf2_m(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x i64> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u32mf2_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vnclipu.wx.mask.u32mf2(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x i64> %2, i8 %3)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vnclipu.wx.mask.u32m1(<vscale x 2 x i1>, <vscale x 2 x i32>, <vscale x 2 x i64>, i8);
define <vscale x 2 x i32> @vnclipu_wx_u32m1_m(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x i64> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u32m1_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vnclipu.wx.mask.u32m1(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x i64> %2, i8 %3)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vnclipu.wx.mask.u32m2(<vscale x 4 x i1>, <vscale x 4 x i32>, <vscale x 4 x i64>, i8);
define <vscale x 4 x i32> @vnclipu_wx_u32m2_m(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i64> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u32m2_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vnclipu.wx.mask.u32m2(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x i64> %2, i8 %3)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vnclipu.wx.mask.u32m4(<vscale x 8 x i1>, <vscale x 8 x i32>, <vscale x 8 x i64>, i8);
define <vscale x 8 x i32> @vnclipu_wx_u32m4_m(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x i64> %2, i8 %3) {
entry:
  ; CHECK-LABEL: vnclipu_wx_u32m4_m
  ; CHECK: vnclipu.wx v{{.*}}, v{{.*}}, a{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vnclipu.wx.mask.u32m4(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x i64> %2, i8 %3)
  ret <vscale x 8 x i32> %a
}


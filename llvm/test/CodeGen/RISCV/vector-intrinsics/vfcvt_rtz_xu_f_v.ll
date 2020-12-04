; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16mf4(<vscale x 1 x half>);
define <vscale x 1 x i16> @vfcvt_rtz_xu_f_v_u16mf4(<vscale x 1 x half> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16mf4
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16mf4(<vscale x 1 x half> %0)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16mf2(<vscale x 2 x half>);
define <vscale x 2 x i16> @vfcvt_rtz_xu_f_v_u16mf2(<vscale x 2 x half> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16mf2
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16mf2(<vscale x 2 x half> %0)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16m1(<vscale x 4 x half>);
define <vscale x 4 x i16> @vfcvt_rtz_xu_f_v_u16m1(<vscale x 4 x half> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16m1
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16m1(<vscale x 4 x half> %0)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16m2(<vscale x 8 x half>);
define <vscale x 8 x i16> @vfcvt_rtz_xu_f_v_u16m2(<vscale x 8 x half> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16m2
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16m2(<vscale x 8 x half> %0)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16m4(<vscale x 16 x half>);
define <vscale x 16 x i16> @vfcvt_rtz_xu_f_v_u16m4(<vscale x 16 x half> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16m4
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16m4(<vscale x 16 x half> %0)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16m8(<vscale x 32 x half>);
define <vscale x 32 x i16> @vfcvt_rtz_xu_f_v_u16m8(<vscale x 32 x half> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16m8
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.u16m8(<vscale x 32 x half> %0)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32mf2(<vscale x 1 x float>);
define <vscale x 1 x i32> @vfcvt_rtz_xu_f_v_u32mf2(<vscale x 1 x float> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32mf2
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32mf2(<vscale x 1 x float> %0)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32m1(<vscale x 2 x float>);
define <vscale x 2 x i32> @vfcvt_rtz_xu_f_v_u32m1(<vscale x 2 x float> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32m1
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32m1(<vscale x 2 x float> %0)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32m2(<vscale x 4 x float>);
define <vscale x 4 x i32> @vfcvt_rtz_xu_f_v_u32m2(<vscale x 4 x float> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32m2
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32m2(<vscale x 4 x float> %0)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32m4(<vscale x 8 x float>);
define <vscale x 8 x i32> @vfcvt_rtz_xu_f_v_u32m4(<vscale x 8 x float> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32m4
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32m4(<vscale x 8 x float> %0)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32m8(<vscale x 16 x float>);
define <vscale x 16 x i32> @vfcvt_rtz_xu_f_v_u32m8(<vscale x 16 x float> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32m8
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.u32m8(<vscale x 16 x float> %0)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.u64m1(<vscale x 1 x double>);
define <vscale x 1 x i64> @vfcvt_rtz_xu_f_v_u64m1(<vscale x 1 x double> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u64m1
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.u64m1(<vscale x 1 x double> %0)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.u64m2(<vscale x 2 x double>);
define <vscale x 2 x i64> @vfcvt_rtz_xu_f_v_u64m2(<vscale x 2 x double> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u64m2
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.u64m2(<vscale x 2 x double> %0)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.u64m4(<vscale x 4 x double>);
define <vscale x 4 x i64> @vfcvt_rtz_xu_f_v_u64m4(<vscale x 4 x double> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u64m4
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.u64m4(<vscale x 4 x double> %0)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.u64m8(<vscale x 8 x double>);
define <vscale x 8 x i64> @vfcvt_rtz_xu_f_v_u64m8(<vscale x 8 x double> %0) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u64m8
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.u64m8(<vscale x 8 x double> %0)
  ret <vscale x 8 x i64> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16mf4(<vscale x 1 x i1>, <vscale x 1 x i16>, <vscale x 1 x half>);
define <vscale x 1 x i16> @vfcvt_rtz_xu_f_v_u16mf4_m(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x half> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16mf4_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16mf4(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x half> %2)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16mf2(<vscale x 2 x i1>, <vscale x 2 x i16>, <vscale x 2 x half>);
define <vscale x 2 x i16> @vfcvt_rtz_xu_f_v_u16mf2_m(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x half> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16mf2_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16mf2(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x half> %2)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16m1(<vscale x 4 x i1>, <vscale x 4 x i16>, <vscale x 4 x half>);
define <vscale x 4 x i16> @vfcvt_rtz_xu_f_v_u16m1_m(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x half> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16m1_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16m1(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x half> %2)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16m2(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x half>);
define <vscale x 8 x i16> @vfcvt_rtz_xu_f_v_u16m2_m(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x half> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16m2_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16m2(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x half> %2)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16m4(<vscale x 16 x i1>, <vscale x 16 x i16>, <vscale x 16 x half>);
define <vscale x 16 x i16> @vfcvt_rtz_xu_f_v_u16m4_m(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x half> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16m4_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16m4(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x half> %2)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16m8(<vscale x 32 x i1>, <vscale x 32 x i16>, <vscale x 32 x half>);
define <vscale x 32 x i16> @vfcvt_rtz_xu_f_v_u16m8_m(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1, <vscale x 32 x half> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u16m8_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u16m8(<vscale x 32 x i1> %0, <vscale x 32 x i16> %1, <vscale x 32 x half> %2)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32mf2(<vscale x 1 x i1>, <vscale x 1 x i32>, <vscale x 1 x float>);
define <vscale x 1 x i32> @vfcvt_rtz_xu_f_v_u32mf2_m(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x float> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32mf2_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32mf2(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x float> %2)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32m1(<vscale x 2 x i1>, <vscale x 2 x i32>, <vscale x 2 x float>);
define <vscale x 2 x i32> @vfcvt_rtz_xu_f_v_u32m1_m(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x float> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32m1_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32m1(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x float> %2)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32m2(<vscale x 4 x i1>, <vscale x 4 x i32>, <vscale x 4 x float>);
define <vscale x 4 x i32> @vfcvt_rtz_xu_f_v_u32m2_m(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x float> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32m2_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32m2(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x float> %2)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32m4(<vscale x 8 x i1>, <vscale x 8 x i32>, <vscale x 8 x float>);
define <vscale x 8 x i32> @vfcvt_rtz_xu_f_v_u32m4_m(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x float> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32m4_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32m4(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x float> %2)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32m8(<vscale x 16 x i1>, <vscale x 16 x i32>, <vscale x 16 x float>);
define <vscale x 16 x i32> @vfcvt_rtz_xu_f_v_u32m8_m(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x float> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u32m8_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u32m8(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x float> %2)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u64m1(<vscale x 1 x i1>, <vscale x 1 x i64>, <vscale x 1 x double>);
define <vscale x 1 x i64> @vfcvt_rtz_xu_f_v_u64m1_m(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x double> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u64m1_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u64m1(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x double> %2)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u64m2(<vscale x 2 x i1>, <vscale x 2 x i64>, <vscale x 2 x double>);
define <vscale x 2 x i64> @vfcvt_rtz_xu_f_v_u64m2_m(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x double> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u64m2_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u64m2(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x double> %2)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u64m4(<vscale x 4 x i1>, <vscale x 4 x i64>, <vscale x 4 x double>);
define <vscale x 4 x i64> @vfcvt_rtz_xu_f_v_u64m4_m(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x double> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u64m4_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u64m4(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x double> %2)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u64m8(<vscale x 8 x i1>, <vscale x 8 x i64>, <vscale x 8 x double>);
define <vscale x 8 x i64> @vfcvt_rtz_xu_f_v_u64m8_m(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x double> %2) {
entry:
  ; CHECK-LABEL: vfcvt_rtz_xu_f_v_u64m8_m
  ; CHECK: vfcvt.rtz.xu.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.xu.f.v.mask.u64m8(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x double> %2)
  ret <vscale x 8 x i64> %a
}


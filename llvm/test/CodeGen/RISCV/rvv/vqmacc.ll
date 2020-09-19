; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s


declare <vscale x 8 x i32> @llvm.riscv.vqmacc.vv.i32m4(<vscale x 8 x i32>, <vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i32> @vqmacc_vv_i32m4(<vscale x 8 x i32> %0, <vscale x 8 x i8> %1, <vscale x 8 x i8> %2) {
entry:
; CHECK-LABEL: vqmacc_vv_i32m4
; CHECK: vqmacc.vv       v16, v20, v21
%a =  tail call <vscale x 8 x i32> @llvm.riscv.vqmacc.vv.i32m4(<vscale x 8 x i32> %0, <vscale x 8 x i8> %1, <vscale x 8 x i8> %2)
ret <vscale x 8 x i32> %a
}


declare <vscale x 4 x i64> @llvm.riscv.vqmaccus.vx.nxv4i64.i16.nxv4i16(<vscale x 4 x i64>, i16 , <vscale x 4 x i16>);
define <vscale x 4 x i64> @vqmaccus_vx_i64m4(<vscale x 4 x i64> %0,  i16 %1, <vscale x 4 x i16> %2) {
entry:
; CHECK-LABEL: vqmaccus_vx_i64m4
; CHECK: vqmaccus.vx     v16, a0, v20
%a =  tail call <vscale x 4 x i64> @llvm.riscv.vqmaccus.vx.nxv4i64.i16.nxv4i16(<vscale x 4 x i64> %0, i16 %1, <vscale x 4 x i16> %2)
ret <vscale x 4 x i64> %a
}


; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 4 x i16> @llvm.riscv.vredsum.vs(<vscale x 4 x i16>, <vscale x 2 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vredsum_vs(<vscale x 4 x i16> %0, <vscale x 2 x i16> %1, <vscale x 4 x i16> %2) {
entry:
; CHECK-LABEL: vredsum_vs
; CHECK: vredsum.vs	v16, v17, v18
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vredsum.vs(<vscale x 4 x i16> %0, <vscale x 2 x i16> %1, <vscale x 4 x i16> %2)
ret <vscale x 4 x i16> %a
}
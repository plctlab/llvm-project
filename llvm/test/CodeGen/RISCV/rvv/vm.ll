; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 4 x i1> @llvm.riscv.vmseq.vv(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i1> @vmseq_vv(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vmseq_vv
; CHECK: vmseq.vv	v0, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmseq.vv.mask(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i1> @vmseq_vv_mask(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i16> %2, <vscale x 4 x i16> %3) {
entry:
; CHECK-LABEL: vmseq_vv_mask
; CHECK: 	vmv1r.v	v25, v0
; CHECK:	vmseq.vv	v25, v16, v17, v0.t
; CHECK:	vmv1r.v	v0, v25
; CHECK: ret 
%a =  tail call <vscale x 4 x i1> @llvm.riscv.vmseq.vv.mask(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x i16> %2, <vscale x 4 x i16> %3)
ret <vscale x 4 x i1> %a
}
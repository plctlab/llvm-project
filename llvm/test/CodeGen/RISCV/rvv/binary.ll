; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 8 x i8> @llvm.riscv.vadd.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vadd_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vadd_vv_i8m1
; CHECK: vadd.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vadd.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vadd.vv.i16m1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vadd_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vadd_vv_i16m1
; CHECK: vadd.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vadd.vv.i16m1.nxv4i16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vadd.vv.i32m1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vadd_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vadd_vv_i32m1
; CHECK: vadd.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vadd.vv.i32m1.nxv2i32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vadd.vv.i64m1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vadd_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vadd_vv_i64m1
; CHECK: vadd.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vadd.vv.i64m1.nxv1i64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
ret <vscale x 1 x i64> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vsub.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vsub_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vsub_vv_i8m1
; CHECK: vsub.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vsub.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vsub.vv.i16m1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vsub_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vsub_vv_i16m1
; CHECK: vsub.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vsub.vv.i16m1.nxv4i16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vsub.vv.i32m1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vsub_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vsub_vv_i32m1
; CHECK: vsub.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vsub.vv.i32m1.nxv2i32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vsub.vv.i64m1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vsub_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vsub_vv_i64m1
; CHECK: vsub.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vsub.vv.i64m1.nxv1i64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
ret <vscale x 1 x i64> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vmul.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vmul_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vmul_vv_i8m1
; CHECK: vmul.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vmul.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vmul.vv.i16m1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vmul_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vmul_vv_i16m1
; CHECK: vmul.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vmul.vv.i16m1.nxv4i16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vmul.vv.i32m1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vmul_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vmul_vv_i32m1
; CHECK: vmul.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vmul.vv.i32m1.nxv2i32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vmul.vv.i64m1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vmul_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vmul_vv_i64m1
; CHECK: vmul.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vmul.vv.i64m1.nxv1i64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
ret <vscale x 1 x i64> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vdiv.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vdiv_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vdiv_vv_i8m1
; CHECK: vdiv.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vdiv.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vdiv.vv.i16m1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vdiv_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vdiv_vv_i16m1
; CHECK: vdiv.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vdiv.vv.i16m1.nxv4i16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vdiv.vv.i32m1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vdiv_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vdiv_vv_i32m1
; CHECK: vdiv.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vdiv.vv.i32m1.nxv2i32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vdiv.vv.i64m1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vdiv_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vdiv_vv_i64m1
; CHECK: vdiv.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vdiv.vv.i64m1.nxv1i64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
ret <vscale x 1 x i64> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vor.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vor_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vor_vv_i8m1
; CHECK: vor.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vor.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vor.vv.i16m1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vor_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vor_vv_i16m1
; CHECK: vor.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vor.vv.i16m1.nxv4i16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vor.vv.i32m1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vor_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vor_vv_i32m1
; CHECK: vor.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vor.vv.i32m1.nxv2i32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vor.vv.i64m1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vor_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vor_vv_i64m1
; CHECK: vor.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vor.vv.i64m1.nxv1i64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
ret <vscale x 1 x i64> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vxor.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vxor_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vxor_vv_i8m1
; CHECK: vxor.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vxor.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vxor.vv.i16m1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vxor_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vxor_vv_i16m1
; CHECK: vxor.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vxor.vv.i16m1.nxv4i16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vxor.vv.i32m1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vxor_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vxor_vv_i32m1
; CHECK: vxor.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vxor.vv.i32m1.nxv2i32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vxor.vv.i64m1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vxor_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vxor_vv_i64m1
; CHECK: vxor.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vxor.vv.i64m1.nxv1i64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
ret <vscale x 1 x i64> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vand.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vand_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vand_vv_i8m1
; CHECK: vand.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vand.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vand.vv.i16m1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vand_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vand_vv_i16m1
; CHECK: vand.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vand.vv.i16m1.nxv4i16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vand.vv.i32m1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vand_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vand_vv_i32m1
; CHECK: vand.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vand.vv.i32m1.nxv2i32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vand.vv.i64m1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vand_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vand_vv_i64m1
; CHECK: vand.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vand.vv.i64m1.nxv1i64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
ret <vscale x 1 x i64> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vmseq.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vmseq_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vmseq_vv_i8m1
; CHECK: vmseq.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vmseq.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vmseq.vv.i16m1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vmseq_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vmseq_vv_i16m1
; CHECK: vmseq.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vmseq.vv.i16m1.nxv4i16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vmseq.vv.i32m1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vmseq_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vmseq_vv_i32m1
; CHECK: vmseq.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vmseq.vv.i32m1.nxv2i32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vmseq.vv.i64m1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vmseq_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vmseq_vv_i64m1
; CHECK: vmseq.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vmseq.vv.i64m1.nxv1i64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
ret <vscale x 1 x i64> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vmsle.vv.i8m1.nxv8i8(<vscale x 8 x i8>, <vscale x 8 x i8>);
define <vscale x 8 x i8> @vmsle_vv_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1) {
entry:
; CHECK-LABEL: vmsle_vv_i8m1
; CHECK: vmsle.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 8 x i8> @llvm.riscv.vmsle.vv.i8m1.nxv8i8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1)
ret <vscale x 8 x i8> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vmsle.vv.i16m1.nxv4i16(<vscale x 4 x i16>, <vscale x 4 x i16>);
define <vscale x 4 x i16> @vmsle_vv_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1) {
entry:
; CHECK-LABEL: vmsle_vv_i16m1
; CHECK: vmsle.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 4 x i16> @llvm.riscv.vmsle.vv.i16m1.nxv4i16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1)
ret <vscale x 4 x i16> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vmsle.vv.i32m1.nxv2i32(<vscale x 2 x i32>, <vscale x 2 x i32>);
define <vscale x 2 x i32> @vmsle_vv_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1) {
entry:
; CHECK-LABEL: vmsle_vv_i32m1
; CHECK: vmsle.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x i32> @llvm.riscv.vmsle.vv.i32m1.nxv2i32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1)
ret <vscale x 2 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vmsle.vv.i64m1.nxv1i64(<vscale x 1 x i64>, <vscale x 1 x i64>);
define <vscale x 1 x i64> @vmsle_vv_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1) {
entry:
; CHECK-LABEL: vmsle_vv_i64m1
; CHECK: vmsle.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 1 x i64> @llvm.riscv.vmsle.vv.i64m1.nxv1i64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1)
ret <vscale x 1 x i64> %a
}


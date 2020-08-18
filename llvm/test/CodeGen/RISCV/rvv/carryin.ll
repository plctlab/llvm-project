declare <vscale x 8 x i16> @llvm.riscv.vadc.vvm.i8m8(<vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i1>);
define <vscale x 8 x i16> @vwadd_vx_mask_i8m8() {
entry:
; CHECK-LABEL: vadd_vv_i8m8
; CHECK: vadd.vv v16, v16, v24
; CHECK: ret 
%a =  tail call <vscale x 8 x i16> @llvm.riscv.vadc.vvm.i8m8(<vscale x 8 x i16> undef, <vscale x 8 x i16> undef, <vscale x 8 x i1> undef)
ret <vscale x 8 x i16> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i8m8(<vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vwadd_vx__i8m8() {
entry:
; CHECK-LABEL: vadd_vv_i8m8
; CHECK: vadd.vv v16, v16, v24
; CHECK: ret 
%a =  tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i8m8(<vscale x 8 x i16> undef, <vscale x 8 x i16> undef, <vscale x 8 x i1> undef)
ret <vscale x 8 x i1> %a
}
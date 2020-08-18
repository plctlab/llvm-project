declare <vscale x 2 x float> @llvm.riscv.vfmacc.vf(<vscale x 2 x float>, float, <vscale x 2 x float>);
define <vscale x 2 x float> @vadd_vv_i32m1(<vscale x 2 x float> %0, <vscale x 2 x float> %1, float %2) {
entry:
; CHECK-LABEL: vadd_vv_i32m1
; CHECK: vadd.vv v16, v16, v17
; CHECK: ret 
%a =  tail call <vscale x 2 x float> @llvm.riscv.vfmacc.vf(<vscale x 2 x float> %0, float %2, <vscale x 2 x float> %1)
ret <vscale x 2 x float> %a
}
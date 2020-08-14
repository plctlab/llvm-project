//===- IntrinsicsRISCV.td - Defines RISCV intrinsics -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines all of the RISCV-specific intrinsics.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Atomics

// Atomic Intrinsics have multiple versions for different access widths, which
// all follow one of the following signatures (depending on how many arguments
// they require). We carefully instantiate only specific versions of these for
// specific integer widths, rather than using `llvm_anyint_ty`.
//
// In fact, as these intrinsics take `llvm_anyptr_ty`, the given names are the
// canonical names, and the intrinsics used in the code will have a name
// suffixed with the pointer type they are specialised for (denoted `<p>` in the
// names below), in order to avoid type conflicts.

let TargetPrefix = "riscv" in {

  // T @llvm.<name>.T.<p>(any*, T, T, T imm);
  class MaskedAtomicRMWFourArg<LLVMType itype>
      : Intrinsic<[itype], [llvm_anyptr_ty, itype, itype, itype],
                  [IntrArgMemOnly, NoCapture<ArgIndex<0>>, ImmArg<ArgIndex<3>>]>;
  // T @llvm.<name>.T.<p>(any*, T, T, T, T imm);
  class MaskedAtomicRMWFiveArg<LLVMType itype>
      : Intrinsic<[itype], [llvm_anyptr_ty, itype, itype, itype, itype],
                  [IntrArgMemOnly, NoCapture<ArgIndex<0>>, ImmArg<ArgIndex<4>>]>;

  // We define 32-bit and 64-bit variants of the above, where T stands for i32
  // or i64 respectively:
  multiclass MaskedAtomicRMWFourArgIntrinsics {
    // i32 @llvm.<name>.i32.<p>(any*, i32, i32, i32 imm);
    def _i32 : MaskedAtomicRMWFourArg<llvm_i32_ty>;
    // i64 @llvm.<name>.i32.<p>(any*, i64, i64, i64 imm);
    def _i64 : MaskedAtomicRMWFourArg<llvm_i64_ty>;
  }

  multiclass MaskedAtomicRMWFiveArgIntrinsics {
    // i32 @llvm.<name>.i32.<p>(any*, i32, i32, i32, i32 imm);
    def _i32 : MaskedAtomicRMWFiveArg<llvm_i32_ty>;
    // i64 @llvm.<name>.i64.<p>(any*, i64, i64, i64, i64 imm);
    def _i64 : MaskedAtomicRMWFiveArg<llvm_i64_ty>;
  }

  // @llvm.riscv.masked.atomicrmw.*.{i32,i64}.<p>(...)
  defm int_riscv_masked_atomicrmw_xchg : MaskedAtomicRMWFourArgIntrinsics;
  defm int_riscv_masked_atomicrmw_add : MaskedAtomicRMWFourArgIntrinsics;
  defm int_riscv_masked_atomicrmw_sub : MaskedAtomicRMWFourArgIntrinsics;
  defm int_riscv_masked_atomicrmw_nand : MaskedAtomicRMWFourArgIntrinsics;
  // Signed min and max need an extra operand to do sign extension with.
  defm int_riscv_masked_atomicrmw_max : MaskedAtomicRMWFiveArgIntrinsics;
  defm int_riscv_masked_atomicrmw_min : MaskedAtomicRMWFiveArgIntrinsics;
  // Unsigned min and max don't need the extra operand.
  defm int_riscv_masked_atomicrmw_umax : MaskedAtomicRMWFourArgIntrinsics;
  defm int_riscv_masked_atomicrmw_umin : MaskedAtomicRMWFourArgIntrinsics;

  // @llvm.riscv.masked.cmpxchg.{i32,i64}.<p>(...)
  defm int_riscv_masked_cmpxchg : MaskedAtomicRMWFiveArgIntrinsics;

class V_VV : Intrinsic<[ llvm_anyvector_ty ],
                     [ LLVMMatchType<0>, LLVMMatchType<0> ],
                     [ IntrNoMem ]>;

class W_VV : Intrinsic<[ llvm_anyvector_ty ],
                            [ llvm_anyvector_ty, LLVMMatchType<1> ],
                            [ IntrNoMem ]>;

class V_WV : Intrinsic<[ llvm_anyvector_ty ],
                            [ llvm_anyvector_ty, LLVMMatchType<0> ],
                            [ IntrNoMem ]>;

class V_WX : Intrinsic<[ llvm_anyvector_ty ],
                       [ llvm_anyvector_ty, llvm_anyint_ty],
                       [ IntrNoMem ]>;

class V_WX_mask : Intrinsic<[ llvm_anyvector_ty ],
                            [ llvm_anyvector_ty, LLVMMatchType<0>, 
                              llvm_anyvector_ty, llvm_anyint_ty ],
                            [ IntrNoMem ]>;

class W_WV : Intrinsic<[ llvm_anyvector_ty ],
                            [ LLVMMatchType<0>, llvm_anyvector_ty ],
                            [ IntrNoMem ]>;

class V_VV_mask : Intrinsic<[ llvm_anyvector_ty ],
                         [ llvm_anyvector_ty, LLVMMatchType<0>, 
                           LLVMMatchType<0>, LLVMMatchType<0> ],
                         [ IntrNoMem ]>;

class W_VV_mask : Intrinsic<[ llvm_anyvector_ty ],
                         [ llvm_anyvector_ty, LLVMMatchType<0>, 
                           llvm_anyvector_ty, LLVMMatchType<2> ],
                         [ IntrNoMem ]>;

class V_WV_mask : Intrinsic<[ llvm_anyvector_ty ],
                         [ llvm_anyvector_ty, LLVMMatchType<0>, 
                           llvm_anyvector_ty, LLVMMatchType<0> ],
                         [ IntrNoMem ]>;

class W_WV_mask : Intrinsic<[ llvm_anyvector_ty ],
                         [ llvm_anyvector_ty, LLVMMatchType<0>, 
                           LLVMMatchType<0>, llvm_anyvector_ty ],
                         [ IntrNoMem ]>;

class V_VX : Intrinsic<[ llvm_anyvector_ty ],
                     [ llvm_anyvector_ty, llvm_anyint_ty ],
                     [ IntrNoMem ]>;

class W_VX : Intrinsic<[ llvm_anyvector_ty ],
                     [ llvm_anyvector_ty, llvm_anyint_ty ],
                     [ IntrNoMem ]>;

class W_VF : Intrinsic<[ llvm_anyvector_ty ],
                     [ llvm_anyvector_ty, llvm_anyfloat_ty ],
                     [ IntrNoMem ]>;

class W_VF_mask : Intrinsic<[ llvm_anyvector_ty ],
                            [ llvm_anyvector_ty, LLVMMatchType<0>,
                              llvm_anyvector_ty, llvm_anyfloat_ty ],
                            [ IntrNoMem ]>;

class V_VX_mask : Intrinsic<[ llvm_anyvector_ty ],
                            [ llvm_anyvector_ty, LLVMMatchType<0>,
                              LLVMMatchType<0>, llvm_anyint_ty ],
                            [ IntrNoMem ]>;

class W_VX_mask : Intrinsic<[ llvm_anyvector_ty ],
                            [ llvm_anyvector_ty, LLVMMatchType<0>,
                              llvm_anyvector_ty, llvm_anyint_ty ],
                            [ IntrNoMem ]>;

class V_VF : Intrinsic<[ llvm_anyvector_ty ],
                     [ LLVMMatchType<0>, llvm_anyfloat_ty ],
                     [ IntrNoMem ]>;

class V_VF_mask : Intrinsic< [llvm_anyvector_ty ],
                             [ llvm_anyvector_ty, LLVMMatchType<0>,
                               LLVMMatchType<0>, llvm_anyfloat_ty ],
                             [ IntrNoMem ]>;

class V_VVV : Intrinsic<[ llvm_anyvector_ty ],
                        [ LLVMMatchType<0>, LLVMMatchType<0>, LLVMMatchType<0> ],
                        [ IntrNoMem ]>;

class V_VVV_mask : Intrinsic<[ llvm_anyvector_ty ],
                        [ llvm_anyvector_ty, LLVMMatchType<0>, 
                        LLVMMatchType<0>, LLVMMatchType<0> ],
                        [ IntrNoMem ]>;

class V_VVX : Intrinsic<[ llvm_anyvector_ty ],
                        [ LLVMMatchType<0>, llvm_anyint_ty, LLVMMatchType<0> ],
                        [ IntrNoMem ]>;

class V_VVX_mask : Intrinsic<[ llvm_anyvector_ty ],
                             [ llvm_anyvector_ty, LLVMMatchType<0>, 
                               llvm_anyint_ty, LLVMMatchType<0> ],
                             [ IntrNoMem ]>;

class V_VVF : Intrinsic<[ llvm_anyvector_ty ],
                        [ llvm_anyvector_ty, llvm_anyfloat_ty, llvm_anyvector_ty ],
                        [ IntrNoMem ]>;

class V_VVF_mask : Intrinsic<[ llvm_anyvector_ty ],
                             [ llvm_anyvector_ty, LLVMMatchType<0>, 
                               llvm_anyfloat_ty, LLVMMatchType<0> ],
                             [ IntrNoMem ]>;

class W_V : Intrinsic<[ llvm_anyvector_ty ],
                           [ llvm_anyvector_ty ],
                           [ IntrNoMem ]>;

class W_V_mask : Intrinsic<[ llvm_anyvector_ty ],
                                [ llvm_anyvector_ty, LLVMMatchType<0>, llvm_anyvector_ty],
                                [ IntrNoMem ]>;

class V_VVM : Intrinsic<[ llvm_anyvector_ty ],
                        [ LLVMMatchType<0>, LLVMMatchType<0>, llvm_anyvector_ty],
                        [ IntrNoMem ]>;

class V_VXM : Intrinsic<[ llvm_anyvector_ty ],
                             [ LLVMMatchType<0>, llvm_anyvector_ty, llvm_anyint_ty ],
                             [ IntrNoMem ]>;

class M_VV : Intrinsic<[ llvm_anyvector_ty ],
                       [ llvm_anyvector_ty, llvm_anyvector_ty ],
                       [ IntrNoMem ]>;

class M_VV_mask : Intrinsic<[ llvm_anyvector_ty ],
                            [ LLVMMatchType<0>, LLVMMatchType<0>, 
                            llvm_anyvector_ty, LLVMMatchType<0> ],
                            [ IntrNoMem ]>;

class M_VVM : Intrinsic<[ llvm_anyvector_ty ],
                        [ llvm_anyvector_ty, LLVMMatchType<1>, LLVMMatchType<0>],
                        [ IntrNoMem ]>;

class M_VX : Intrinsic<[ llvm_anyvector_ty ],
                       [ llvm_anyvector_ty, llvm_anyint_ty ],
                       [ IntrNoMem ]>;

class M_VX_mask : Intrinsic<[ llvm_anyvector_ty ],
                            [ LLVMMatchType<0>, LLVMMatchType<0>, 
                            llvm_anyvector_ty, llvm_anyint_ty ],
                            [ IntrNoMem ]>;

class M_VF : Intrinsic<[ llvm_anyvector_ty ],
                       [ llvm_anyvector_ty, llvm_anyfloat_ty ],
                       [ IntrNoMem ]>;

class M_VF_mask : Intrinsic<[ llvm_anyvector_ty ],
                            [ LLVMMatchType<0>, LLVMMatchType<0>, 
                            llvm_anyvector_ty, llvm_anyfloat_ty ],
                            [ IntrNoMem ]>;

class M_VXM : Intrinsic<[ llvm_anyvector_ty ],
                        [ llvm_anyvector_ty, llvm_any_ty, LLVMMatchType<0>],
                        [ IntrNoMem ]>;

class V_V : Intrinsic<[ llvm_anyvector_ty ],
                      [ LLVMMatchType<0> ],
                      [ IntrNoMem ]>;

class V_V_mask : Intrinsic<[ llvm_anyvector_ty ],
                      [ llvm_anyvector_ty, LLVMMatchType<0>, LLVMMatchType<0> ],
                      [ IntrNoMem ]>;

class W_WVV : Intrinsic<[ llvm_anyvector_ty ],
                        [ LLVMMatchType<0>, llvm_anyvector_ty, LLVMMatchType<1> ],
                        [ IntrNoMem ]>;

class W_WVV_mask : Intrinsic<[ llvm_anyvector_ty ],
                        [ llvm_anyvector_ty, LLVMMatchType<0>, llvm_anyvector_ty, LLVMMatchType<2> ],
                        [ IntrNoMem ]>;

class W_WVX : Intrinsic<[ llvm_anyvector_ty ],
                        [ LLVMMatchType<0>, llvm_anyint_ty, llvm_anyvector_ty ],
                        [ IntrNoMem ]>;

class W_WVF : Intrinsic<[ llvm_anyvector_ty ],
                        [ LLVMMatchType<0>, llvm_anyfloat_ty, llvm_anyvector_ty ],
                        [ IntrNoMem ]>;

class W_WVX_mask : Intrinsic<[ llvm_anyvector_ty ],
                             [ llvm_anyvector_ty, LLVMMatchType<0>, 
                             llvm_anyint_ty, llvm_anyvector_ty],
                             [ IntrNoMem ]>;

class W_WVF_mask : Intrinsic<[ llvm_anyvector_ty ],
                             [ llvm_anyvector_ty, LLVMMatchType<0>, 
                             llvm_anyfloat_ty, llvm_anyvector_ty],
                             [ IntrNoMem ]>;


multiclass Binary_int_vv {
  def "int_riscv_" # NAME # "_vv" : V_VV;
  def "int_riscv_" # NAME # "_vv_mask" : V_VV_mask;
}

multiclass Binary_int_vx {
  def "int_riscv_" # NAME # "_vx" : V_VX;
  def "int_riscv_" # NAME # "_vx_mask" : V_VX_mask;
}

multiclass Binary_int {
  defm NAME : Binary_int_vv;
  defm NAME : Binary_int_vx;
}

// Vector Integer Arithmetic Functions
defm vadd : Binary_int;
defm vsub : Binary_int;
defm vrsub : Binary_int_vx;

multiclass Binary_w_vv {
  def "int_riscv_" # NAME # "_vv" : W_VV;
  def "int_riscv_" # NAME # "_vv_mask" : W_VV_mask;
}

multiclass Binary_w_vx {
  def "int_riscv_" # NAME # "_vx" : W_VX;
  def "int_riscv_" # NAME # "_vx_mask" : W_VX_mask;
}

multiclass Binary_w_wx {
  def "int_riscv_" # NAME # "_wx" : V_VX;
  def "int_riscv_" # NAME # "_wx_mask" : V_VX_mask;
}

multiclass Binary_w_wv {
  def "int_riscv_" # NAME # "_wv" : W_WV;
  def "int_riscv_" # NAME # "_wv_mask" : W_WV_mask;
}

multiclass Binary_w_vf {
  def "int_riscv_" # NAME # "_vf" : W_VF;
  def "int_riscv_" # NAME # "_vf_mask" : W_VF_mask;
}

multiclass Binary_w_wf {
  def "int_riscv_" # NAME # "_wf" : V_VF;
  def "int_riscv_" # NAME # "_wf_mask" : V_VF_mask;
}

multiclass Binary_int_wide {
  defm NAME : Binary_w_wv;
  defm NAME : Binary_w_vx;
  defm NAME : Binary_w_wx;
  defm NAME : Binary_w_vv;
}

// Vector Widening Integer Add/Subtract Functions
defm vwadd : Binary_int_wide;
defm vwaddu : Binary_int_wide;
defm vwsub : Binary_int_wide;
defm vwsubu : Binary_int_wide;

multiclass Extension_int {
  def "int_riscv_" # NAME : W_V;
  def "int_riscv_" # NAME # "_mask" : W_V_mask;
}

// Vector Integer Extension Functions
defm vsext : Extension_int;
defm vzext : Extension_int;

multiclass carry_int_vm {
  def "int_riscv_" # NAME # "_vvm" : M_VVM;
  def "int_riscv_" # NAME # "_vv" : M_VV;
  def "int_riscv_" # NAME # "_vxm" : M_VXM;
}

multiclass carry_int {
  def "int_riscv_" # NAME # "_vvm" : V_VVM;
  def "int_riscv_" # NAME # "_vxm" : V_VXM;
}

// Vector Integer Add-with-Carry / Subtract-with-Borrow Functions
defm vadc : carry_int;
defm vmadc : carry_int_vm;
defm vsbc : carry_int;
defm vmsbc : carry_int_vm;


// Vector Bitwise Logical Functions
defm vand : Binary_int;
defm vor : Binary_int;
defm vxor : Binary_int;
def "int_riscv_vnot_v" : V_V; // todo

// Vector Single-Width Bit Shift Functioans
defm vsll : Binary_int;
defm vsrl : Binary_int;
defm vsra : Binary_int;

multiclass Binary_int_narrow {
  defm NAME : Binary_w_wv;
  defm NAME : Binary_w_wx;
}
// Vector Narrowing Integer Right Shift Functions
defm vnsrl : Binary_int_narrow;
defm vnsra : Binary_int_narrow;


multiclass Binary_int_comparison {
  def "int_riscv_" # NAME # "_vv" : M_VV;
  def "int_riscv_" # NAME # "_vv_mask" : M_VV_mask;
  def "int_riscv_" # NAME # "_vx" : M_VX;
  def "int_riscv_" # NAME # "_vx_mask" : M_VX_mask;
}

// Vector Integer Comparison Functions
defm vmseq : Binary_int_comparison;
defm vmsne : Binary_int_comparison;
defm vmslt : Binary_int_comparison;
defm vmsltu : Binary_int_comparison;
defm vmsle : Binary_int_comparison;
defm vmsleu : Binary_int_comparison;
defm vmsgt : Binary_int_comparison;
defm vmsgtu : Binary_int_comparison;
defm vmsge : Binary_int_comparison;
defm vmsgeu : Binary_int_comparison;


// Vector Integer Min/Max Functions
defm vmin : Binary_int;
defm vminu : Binary_int;
defm vmax : Binary_int;
defm vmaxu : Binary_int;

// Vector Single-Width Integer Multiply Functions
defm vmulh : Binary_int;
defm vmul : Binary_int;
defm vmulhu : Binary_int;
defm vmulhsu : Binary_int;

// Vector Integer Divide Functions
defm vdiv : Binary_int;
defm vdivu : Binary_int;
defm vrem : Binary_int;
defm vremu : Binary_int;

multiclass Binary_int_wide_mul {
  defm NAME : Binary_w_vv;
  defm NAME : Binary_w_vx;
}
// Vector Widening Integer Multiply Functions
defm vwmul : Binary_int_wide_mul;
defm vwmulu : Binary_int_wide_mul;
defm vmmulsu : Binary_int_wide_mul;

multiclass Ternary_int {
  def "int_riscv_" # NAME # "_vv" : V_VVV;
  def "int_riscv_" # NAME # "_vv_mask" : V_VVV_mask;
  def "int_riscv_" # NAME # "_vx" : V_VVX;
  def "int_riscv_" # NAME # "_vx_mask" : V_VVX_mask;
}
// Vector Single-Width Integer Multiply-Add Functions
defm vmacc : Ternary_int;
defm vnmacc : Ternary_int;
defm vnmsac : Ternary_int;
defm vmadd : Ternary_int;
defm vnmsub : Ternary_int;

multiclass Ternary_int_wide {
  def "int_riscv_" # NAME # "_vv" : W_WVV;
  def "int_riscv_" # NAME # "_vv_mask" : W_WVV_mask;
  def "int_riscv_" # NAME # "_vx" : W_WVX;
  def "int_riscv_" # NAME # "_vx_mask" : W_WVX_mask;
}
// Vector Widening Integer Multiply-Add Functions
defm vwmacc : Ternary_int_wide;
defm vwmaccu : Ternary_int_wide;
defm vwmaccsu : Ternary_int_wide;
defm vwmaccus : Ternary_int_wide;

multiclass Merge {
  def "int_riscv_" # NAME # "_vv" : V_VV_mask;
  def "int_riscv_" # NAME # "_vx" : V_VX_mask;
}
// Vector Integer Merge Functions
defm vmerge : Merge;

// Vector Integer Move Functions
def int_riscv_vmv_v_x : Intrinsic< [ llvm_anyvector_ty ],
                                  [ llvm_anyint_ty ],
                                  [ IntrNoMem ]>;
def int_riscv_vmv_v_v : V_V;

// Vector Single-Width Saturating Add and Subtract Functions
defm vsadd : Binary_int;
defm vsaddu : Binary_int;
defm vssub : Binary_int;
defm vssubu : Binary_int;

// Vector Single-Width Averaging Add and Subtract Functions
defm vaadd : Binary_int;
defm vaaddu : Binary_int;
defm vasub : Binary_int;
defm vasubu : Binary_int;

// Vector Single-Width Fractional Multiply with Rounding and Saturation Functions
defm vsmul : Binary_int;

// Vector Single-Width Scaling Shift Functions
defm vssrl : Binary_int;
defm vssra : Binary_int;

multiclass Narrowing {
  def "int_riscv_" # NAME # "_wv" : V_WV;
  def "int_riscv_" # NAME # "_wv_mask" : V_WV_mask;
  def "int_riscv_" # NAME # "_wx" : V_WX;
  def "int_riscv_" # NAME # "_wx_mask" : V_WX_mask;
}
// Vector Narrowing Fixed-Point Clip Functions
defm vnclip : Narrowing;

multiclass Binary_float {
  def "int_riscv_" # NAME # "_vv" : V_VV;
  def "int_riscv_" # NAME # "_vv_mask" : V_VV_mask;
  def "int_riscv_" # NAME # "_vf" : V_VF;
  def "int_riscv_" # NAME # "_vf_mask" : V_VF_mask;
}
// Vector Single-Width Floating-Point Add/Subtract Functions
defm vfadd : Binary_float;
defm vfsub : Binary_float;
def "int_riscv_vfrsub_vf" : V_VF;
def "int_riscv_vfrsub_vf_mask" : V_VF_mask;

// Vector Widening Floating-Point Add/Subtract Functions
multiclass Binary_float_wide {
  defm NAME : Binary_w_vv;
  defm NAME : Binary_w_vf;
  defm NAME : Binary_w_wf;
  defm NAME : Binary_w_wv;
}

defm vfwadd : Binary_float_wide;
defm vfwsub : Binary_float_wide;

// Vector Single-Width Floating-Point Multiply/Divide Functions
defm vfmul : Binary_float;
defm vfdiv : Binary_float;
def "int_riscv_vfrdiv_vf" : V_VF;
def "int_riscv_vfrdiv_vf_mask" : V_VF_mask;


// Vector Widening Floating-Point Multiply Functions
defm vfwmul :Binary_w_vv;
defm vfwmul : Binary_w_vf;

multiclass Ternary_float {
  def "int_riscv_" # NAME # "_vv" : V_VVV;
  def "int_riscv_" # NAME # "_vv_mask" : V_VVV_mask;
  def "int_riscv_" # NAME # "_vf" : V_VVF;
  def "int_riscv_" # NAME # "_vf_mask" : V_VVF_mask;
}
// Vector Single-Width Floating-Point Fused Multiply-Add Functions
defm vfmacc : Ternary_float;
defm vfnmacc : Ternary_float;
defm vfmsac : Ternary_float;
defm vfnmsac : Ternary_float;
defm vfmadd : Ternary_float;
defm vfnmadd : Ternary_float;
defm vfmsub : Ternary_float;
defm vfnmsub : Ternary_float;

multiclass Ternary_float_wide {
  def "int_riscv_" # NAME # "_vv" : W_WVV;
  def "int_riscv_" # NAME # "_vv_mask" : W_WVV_mask;
  def "int_riscv_" # NAME # "_vf" : W_WVF;
  def "int_riscv_" # NAME # "_vf_mask" : W_WVF_mask;
}
// Vector Widening Floating-Point Add/Subtract Functions
defm vfwmacc : Ternary_float_wide;
defm vfwnmacc : Ternary_float_wide;
defm vfwmsac : Ternary_float_wide;
defm vfwnmsac : Ternary_float_wide;

// Vector Floating-Point Square-Root Functions
def "int_riscv_vfsqrt_v" : V_V;
def "int_riscv_vfsqrt_v_mask" : V_V_mask;

// Vector Floating-Point MIN/MAX Functions
defm vfmin : Binary_float;
defm vfmax : Binary_float;

// Vector Floating-Point Sign-Injection Functions
defm vfsgnj : Binary_float;
defm vfsgnjn : Binary_float;
defm vfsgnjx : Binary_float;

multiclass Binary_float_vm {
  def "int_riscv_" # NAME # "_vv" : M_VV;
  def "int_riscv_" # NAME # "_vv_mask" : M_VV_mask;
  def "int_riscv_" # NAME # "_vf" : M_VF;
  def "int_riscv_" # NAME # "_vf_mask" : M_VF_mask;
}
// Vector Floating-Point Compare Functions
defm vmfeq : Binary_float_vm;
defm vmfne : Binary_float_vm;
defm vmflt : Binary_float_vm;
defm vmfle : Binary_float_vm;
defm vmfgt : Binary_float_vm;
defm vmfge : Binary_float_vm;

// Loads
multiclass Vload {

  def ""              : Intrinsic<[ llvm_anyvector_ty ],
                                  [ llvm_anyptr_ty ],
                                  [ IntrReadMem ]>;
  // def "_strided"      : Intrinsic<[ llvm_anyvector_ty ],
  //                                 [ LLVMPointerType<LLVMMatchType<0>>,
  //                                   llvm_i64_ty, llvm_i64_ty ],
  //                                 [ NoCapture<0>, IntrReadMem ]>;
  // def "_indexed"      : Intrinsic<[ llvm_anyvector_ty ],
  //                                 [ LLVMPointerType<LLVMMatchType<0>>,
  //                                   llvm_anyvector_ty, llvm_i64_ty ],
  //                                 [ NoCapture<0>, IntrReadMem ]>;
  // def "_mask"         : Intrinsic<[ llvm_anyvector_ty ],
  //                                 [ LLVMMatchType<0>,
  //                                   LLVMPointerType<LLVMMatchType<0>>,
  //                                   llvm_anyvector_ty, llvm_i64_ty ],
  //                                 [ NoCapture<0>, IntrReadMem ]>;
  // def "_strided_mask" : Intrinsic<[ llvm_anyvector_ty ],
  //                                 [ LLVMMatchType<0>,
  //                                   LLVMPointerType<LLVMMatchType<0>>,
  //                                   llvm_i64_ty, llvm_anyvector_ty,
  //                                   llvm_i64_ty ],
  //                                 [ NoCapture<0>, IntrReadMem ]>;
  // def "_indexed_mask" : Intrinsic<[ llvm_anyvector_ty ],
  //                                 [ LLVMMatchType<0>,
  //                                   LLVMPointerType<LLVMMatchType<0>>,
  //                                   llvm_anyvector_ty, llvm_anyvector_ty,
  //                                   llvm_i64_ty ],
  //                                 [ NoCapture<0>, IntrReadMem ]>;
}

defm int_riscv_vload : Vload;

// Stores
multiclass Vstore {
  def ""              : Intrinsic<[],
                                  [ llvm_anyptr_ty,
                                    llvm_anyvector_ty],
                                  [ IntrWriteMem ]>;
  // def "_strided"      : Intrinsic<[],
  //                                 [ llvm_anyvector_ty,
  //                                   LLVMPointerType<llvm_any_ty>,
  //                                   llvm_i64_ty, llvm_i64_ty ],
  //                                 [ NoCapture<1>, IntrWriteMem ]>;
  // def "_indexed"      : Intrinsic<[],
  //                                 [ llvm_anyvector_ty,
  //                                   LLVMPointerType<LLVMMatchType<0>>,
  //                                   llvm_anyvector_ty, llvm_i64_ty ],
  //                                 [ NoCapture<1>, IntrWriteMem ]>;
  // def "_mask"         : Intrinsic<[],
  //                                 [ llvm_anyvector_ty,
  //                                   LLVMPointerType<LLVMMatchType<0>>,
  //                                   llvm_anyvector_ty, llvm_i64_ty ],
  //                                 [ NoCapture<1>, IntrWriteMem ]>;
  // def "_strided_mask" : Intrinsic<[],
  //                                 [ llvm_anyvector_ty,
  //                                   LLVMPointerType<LLVMMatchType<0>>,
  //                                   llvm_i64_ty, llvm_anyvector_ty,
  //                                   llvm_i64_ty ],
  //                                 [ NoCapture<1>, IntrWriteMem ]>;
  // def "_indexed_mask" : Intrinsic<[],
  //                                 [ llvm_anyvector_ty,
  //                                   LLVMPointerType<LLVMMatchType<0>>,
  //                                   llvm_anyvector_ty, llvm_anyvector_ty,
  //                                   llvm_i64_ty ],
  //                                 [ NoCapture<1>, IntrWriteMem ]>;
}

defm int_riscv_vstore : Vstore;

def int_riscv_vsetvl  : Intrinsic<[llvm_i64_ty], [
    /* requested vector length */  llvm_i64_ty,
    /* vtype */                    llvm_i64_ty], [ IntrNoMem ]>;

} // TargetPrefix = "riscv"


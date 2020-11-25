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

} // TargetPrefix = "riscv"

//===----------------------------------------------------------------------===//
// Vector Extension

// Derived from EPI's implementation.
class RVVIntrinsic {
  // These intrinsics may accept illegal integer values in their llvm_any_ty
  // operand, so they have to be extended. If set to zero then the intrinsic
  // does not have any operand that must be extended.
  Intrinsic IntrinsicID = !cast<Intrinsic>(NAME);
  bits<4> ExtendOperand = 0;
}

// 'F'  -> floating-point scalar
// 'M'  -> mask vector
// 'V'  -> vector
// 'Va' -> another vector, different type
// 'W'  -> widened vector
// 'X'  -> integer scalar

let TargetPrefix = "riscv" in {

class INT_V : Intrinsic<[llvm_anyvector_ty], [], [IntrNoMem]>;

class INT_V_MASK : Intrinsic<[llvm_anyvector_ty],
                             [llvm_anyvector_ty, LLVMMatchType<0>],
                             [IntrNoMem]>;

class INT_X_V : Intrinsic<[llvm_anyint_ty], [llvm_anyvector_ty], [IntrNoMem]>;

class INT_F_V : Intrinsic<[llvm_anyfloat_ty], [llvm_anyvector_ty], [IntrNoMem]>;

class INT_X_M : Intrinsic<[llvm_i64_ty], [llvm_anyvector_ty], [IntrNoMem]>;

class INT_X_M_MASK : Intrinsic<[llvm_i64_ty],
                               [llvm_anyvector_ty, LLVMMatchType<0>],
                               [IntrNoMem]>;

class INT_V_V : Intrinsic<[llvm_anyvector_ty], [LLVMMatchType<0>], [IntrNoMem]>;

class INT_V_V_MASK : Intrinsic<[llvm_anyvector_ty],
                               [llvm_anyvector_ty, LLVMMatchType<0>,
                                LLVMMatchType<0>],
                               [IntrNoMem]>;

class INT_V_Va : Intrinsic<[llvm_anyvector_ty], [llvm_anyvector_ty], [IntrNoMem]>;

class INT_V_Va_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 llvm_anyvector_ty],
                                [IntrNoMem]>;

class INT_V_X : Intrinsic<[llvm_anyvector_ty], [llvm_anyint_ty], [IntrNoMem]>,
                RVVIntrinsic { let ExtendOperand = 1; }

class INT_V_F : Intrinsic<[llvm_anyvector_ty], [llvm_anyfloat_ty], [IntrNoMem]>;

class INT_V_VV : Intrinsic<[llvm_anyvector_ty],
                           [LLVMMatchType<0>, LLVMMatchType<0>],
                           [IntrNoMem]>;

class INT_V_VV_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 LLVMMatchType<0>, LLVMMatchType<0>],
                                [IntrNoMem]>;

class INT_V_VX : Intrinsic<[llvm_anyvector_ty],
                           [LLVMMatchType<0>, llvm_anyint_ty],
                           [IntrNoMem]>,
                 RVVIntrinsic { let ExtendOperand = 2; }

class INT_V_VX_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 LLVMMatchType<0>, llvm_anyint_ty],
                                [IntrNoMem]>,
                      RVVIntrinsic { let ExtendOperand = 4; }

class INT_V_VVa : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, llvm_anyvector_ty],
                            [IntrNoMem]>;

class INT_V_VVa_MASK : Intrinsic<[llvm_anyvector_ty],
                                 [llvm_anyvector_ty, LLVMMatchType<0>,
                                  LLVMMatchType<0>, llvm_anyvector_ty],
                                 [IntrNoMem]>;

class INT_V_VF : Intrinsic<[llvm_anyvector_ty],
                           [LLVMMatchType<0>, llvm_anyfloat_ty],
                           [IntrNoMem]>;

class INT_V_VF_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 LLVMMatchType<0>, llvm_anyfloat_ty],
                                [IntrNoMem]>;

class INT_V_WV : Intrinsic<[llvm_anyvector_ty],
                           [llvm_anyvector_ty, LLVMMatchType<0>],
                           [IntrNoMem]>;

class INT_V_WV_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 llvm_anyvector_ty, LLVMMatchType<0>],
                                [IntrNoMem]>;

class INT_V_WX : Intrinsic<[llvm_anyvector_ty],
                           [llvm_anyvector_ty, llvm_anyint_ty],
                           [IntrNoMem]>,
                 RVVIntrinsic { let ExtendOperand = 2; }

class INT_V_WX_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 llvm_anyvector_ty, llvm_anyint_ty],
                                [IntrNoMem]>,
                      RVVIntrinsic { let ExtendOperand = 4; }

class INT_V_VVV : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, LLVMMatchType<0>,
                             LLVMMatchType<0>],
                            [IntrNoMem]>;

class INT_V_VVV_MASK : Intrinsic<[llvm_anyvector_ty],
                                 [llvm_anyvector_ty, LLVMMatchType<0>,
                                  LLVMMatchType<0>, LLVMMatchType<0>],
                                 [IntrNoMem]>;

class INT_V_VXV : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, llvm_anyint_ty,
                             LLVMMatchType<0>],
                            [IntrNoMem]>,
                  RVVIntrinsic { let ExtendOperand = 2; }

class INT_V_VXV_MASK : Intrinsic<[llvm_anyvector_ty],
                                 [llvm_anyvector_ty, LLVMMatchType<0>,
                                  llvm_anyint_ty, LLVMMatchType<0>],
                                 [IntrNoMem]>,
                       RVVIntrinsic { let ExtendOperand = 3; }

class INT_V_VVX : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, LLVMMatchType<0>,
                             llvm_anyint_ty],
                            [IntrNoMem]>,
                  RVVIntrinsic { let ExtendOperand = 3; }

class INT_V_VVX_MASK : Intrinsic<[llvm_anyvector_ty],
                                 [llvm_anyvector_ty, LLVMMatchType<0>,
                                  LLVMMatchType<0>, llvm_anyint_ty],
                                 [IntrNoMem]>,
                       RVVIntrinsic { let ExtendOperand = 4; }

class INT_V_VFV : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, llvm_anyfloat_ty,
                             LLVMMatchType<0>],
                            [IntrNoMem]>;

class INT_V_VFV_MASK : Intrinsic<[llvm_anyvector_ty],
                                 [llvm_anyvector_ty, LLVMMatchType<0>,
                                  llvm_anyfloat_ty, LLVMMatchType<0>],
                                 [IntrNoMem]>;

class INT_V_VVM : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, LLVMMatchType<0>,
                             llvm_anyvector_ty],
                            [IntrNoMem]>;

class INT_V_VXM : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, llvm_anyint_ty,
                             llvm_anyvector_ty],
                            [IntrNoMem]>,
                  RVVIntrinsic { let ExtendOperand = 2; }

class INT_V_MVV : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             LLVMMatchType<0>],
                            [IntrNoMem]>;

class INT_V_MVX : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             llvm_anyint_ty],
                            [IntrNoMem]>,
                  RVVIntrinsic { let ExtendOperand = 3; }

class INT_V_MVF : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             llvm_anyfloat_ty],
                            [IntrNoMem]>;

class INT_V_VVaV : Intrinsic<[llvm_anyvector_ty],
                             [LLVMMatchType<0>, llvm_anyvector_ty,
                              LLVMMatchType<0>],
                             [IntrNoMem]>;

class INT_V_VVaV_MASK : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyvector_ty, LLVMMatchType<0>,
                                   llvm_anyvector_ty, LLVMMatchType<0>],
                                  [IntrNoMem]>;

class INT_W_VV : Intrinsic<[llvm_anyvector_ty],
                           [llvm_anyvector_ty, LLVMMatchType<1>],
                           [IntrNoMem]>;

class INT_W_VV_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 llvm_anyvector_ty, LLVMMatchType<2>],
                                [IntrNoMem]>;

class INT_W_WV : Intrinsic<[llvm_anyvector_ty],
                           [LLVMMatchType<0>, llvm_anyvector_ty],
                           [IntrNoMem]>;
                        
class INT_W_WV_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 LLVMMatchType<0>, llvm_anyvector_ty],
                                [IntrNoMem]>;

class INT_W_VX : Intrinsic<[llvm_anyvector_ty],
                           [llvm_anyvector_ty, llvm_anyint_ty],
                           [IntrNoMem]>,
                 RVVIntrinsic { let ExtendOperand = 2; }

class INT_W_VX_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 llvm_anyvector_ty, llvm_anyint_ty],
                                [IntrNoMem]>,
                      RVVIntrinsic { let ExtendOperand = 4; }

class INT_W_VF : Intrinsic<[llvm_anyvector_ty],
                           [llvm_anyvector_ty, llvm_anyfloat_ty],
                           [IntrNoMem]>;

class INT_W_VF_MASK : Intrinsic<[llvm_anyvector_ty],
                                [llvm_anyvector_ty, LLVMMatchType<0>,
                                 llvm_anyvector_ty, llvm_anyfloat_ty],
                                [IntrNoMem]>;

class INT_W_WVV : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, llvm_anyvector_ty,
                             LLVMMatchType<1>],
                            [IntrNoMem]>;

class INT_W_WVV_MASK : Intrinsic<[llvm_anyvector_ty],
                                 [llvm_anyvector_ty, LLVMMatchType<0>,
                                  llvm_anyvector_ty, LLVMMatchType<2>],
                                 [IntrNoMem]>;

class INT_W_WVX : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, llvm_anyint_ty,
                             llvm_anyvector_ty],
                            [IntrNoMem]>,
                  RVVIntrinsic { let ExtendOperand = 2; }

class INT_W_WVF : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, llvm_anyfloat_ty,
                             llvm_anyvector_ty],
                            [IntrNoMem]>;

class INT_W_WVX_MASK : Intrinsic<[llvm_anyvector_ty],
                                 [llvm_anyvector_ty, LLVMMatchType<0>,
                                 llvm_anyint_ty, llvm_anyvector_ty],
                                 [IntrNoMem]>,
                       RVVIntrinsic { let ExtendOperand = 3; }

class INT_W_WVF_MASK : Intrinsic<[llvm_anyvector_ty],
                                 [llvm_anyvector_ty, LLVMMatchType<0>,
                                 llvm_anyfloat_ty, llvm_anyvector_ty],
                                 [IntrNoMem]>;

class INT_M_VV : Intrinsic<[llvm_anyvector_ty],
                           [llvm_anyvector_ty,  LLVMMatchType<1>],
                           [IntrNoMem]>;

class INT_M_VV_MASK : Intrinsic<[llvm_anyvector_ty],
                                [LLVMMatchType<0>, LLVMMatchType<0>,
                                llvm_anyvector_ty, llvm_anyvector_ty],
                                [IntrNoMem]>;

class INT_M_VX : Intrinsic<[llvm_anyvector_ty],
                           [llvm_anyvector_ty, llvm_anyint_ty],
                           [IntrNoMem]>,
                 RVVIntrinsic { let ExtendOperand = 2; }

class INT_M_VX_MASK : Intrinsic<[llvm_anyvector_ty],
                                [LLVMMatchType<0>, LLVMMatchType<0>,
                                llvm_anyvector_ty, llvm_anyint_ty],
                                [IntrNoMem]>,
                      RVVIntrinsic { let ExtendOperand = 4; }

class INT_M_VF : Intrinsic<[llvm_anyvector_ty],
                           [llvm_anyvector_ty, llvm_anyfloat_ty],
                           [IntrNoMem]>;

class INT_M_VF_MASK : Intrinsic<[llvm_anyvector_ty],
                                [LLVMMatchType<0>, LLVMMatchType<0>,
                                 llvm_anyvector_ty, llvm_anyfloat_ty],
                                [IntrNoMem]>;

class INT_M_VVM : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<1>,
                             LLVMMatchType<0>],
                            [IntrNoMem]>;

class INT_M_VXM : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, llvm_any_ty, LLVMMatchType<0>],
                            [IntrNoMem]>;

multiclass INT_RISCV_V {
  def "int_riscv_" # NAME # "_v" : INT_V;
  def "int_riscv_" # NAME # "_v_mask" : INT_V_MASK;
}

multiclass INT_RISCV_X_M {
  def "int_riscv_" # NAME # "_m" : INT_X_M;
  def "int_riscv_" # NAME # "_m_mask" : INT_X_M_MASK;
}

multiclass INT_RISCV_V_V {
  def "int_riscv_" # NAME # "_v" : INT_V_V;
  def "int_riscv_" # NAME # "_v_mask" : INT_V_V_MASK;
}

multiclass INT_RISCV_V_Va {
  def "int_riscv_" # NAME : INT_V_Va;
  def "int_riscv_" # NAME # "_mask" : INT_V_Va_MASK;
}

multiclass INT_RISCV_V_W {
  def "int_riscv_" # NAME # "_w" : INT_V_Va;
  def "int_riscv_" # NAME # "_w_mask" : INT_V_Va_MASK;
}

multiclass INT_RISCV_V_F {
  def "int_riscv_" # NAME # "_v_f" : INT_V_F;
}

multiclass INT_RISCV_V_V_X {
  def "int_riscv_" # NAME # "_v_v" : INT_V_V;
  def "int_riscv_" # NAME # "_v_x" : INT_V_X;
}

multiclass INT_RISCV_W_V {
  def "int_riscv_" # NAME # "_v" : INT_V_Va;
  def "int_riscv_" # NAME # "_v_mask" : INT_V_Va_MASK;
}

multiclass INT_RISCV_V_VV {
  def "int_riscv_" # NAME # "_vv" : INT_V_VV;
  def "int_riscv_" # NAME # "_vv_mask" : INT_V_VV_MASK;
}

multiclass INT_RISCV_V_VX {
  def "int_riscv_" # NAME # "_vx" : INT_V_VX;
  def "int_riscv_" # NAME # "_vx_mask" : INT_V_VX_MASK;
}

multiclass INT_RISCV_V_VVa {
  def "int_riscv_" # NAME # "_vv" : INT_V_VVa;
  def "int_riscv_" # NAME # "_vv_mask" : INT_V_VVa_MASK;
}

multiclass INT_RISCV_V_VF {
  def "int_riscv_" # NAME # "_vf" : INT_V_VF;
  def "int_riscv_" # NAME # "_vf_mask" : INT_V_VF_MASK;
}

multiclass INT_RISCV_V_VS {
  def "int_riscv_" # NAME # "_vs" : INT_V_VVaV;
  def "int_riscv_" # NAME # "_vs_mask" : INT_V_VVaV_MASK;
}

multiclass INT_RISCV_V_WV {
  def "int_riscv_" # NAME # "_wv" : INT_V_WV;
  def "int_riscv_" # NAME # "_wv_mask" : INT_V_WV_MASK;
}

multiclass INT_RISCV_V_WX {
  def "int_riscv_" # NAME # "_wx" : INT_V_WX;
  def "int_riscv_" # NAME # "_wx_mask" : INT_V_WX_MASK;
}

multiclass INT_RISCV_V_VVV {
  def "int_riscv_" # NAME # "_vv" : INT_V_VVV;
  def "int_riscv_" # NAME # "_vv_mask" : INT_V_VVV_MASK;
}

multiclass INT_RISCV_V_VVX {
  def "int_riscv_" # NAME # "_vx" : INT_V_VVX;
  def "int_riscv_" # NAME # "_vx_mask" : INT_V_VVX_MASK;
}

multiclass INT_RISCV_V_VXV {
  def "int_riscv_" # NAME # "_vx" : INT_V_VXV;
  def "int_riscv_" # NAME # "_vx_mask" : INT_V_VXV_MASK;
}

multiclass INT_RISCV_V_VFV {
  def "int_riscv_" # NAME # "_vf" : INT_V_VFV;
  def "int_riscv_" # NAME # "_vf_mask" : INT_V_VFV_MASK;
}

multiclass INT_RISCV_V_VVM_VXM {
  def "int_riscv_" # NAME # "_vvm" : INT_V_VVM;
  def "int_riscv_" # NAME # "_vxm" : INT_V_VXM;
}

multiclass INT_RISCV_V_VM {
  def "int_riscv_" # NAME # "_vm" : INT_V_MVV;
}

multiclass INT_RISCV_V_MVV_MVX {
  def "int_riscv_" # NAME # "_vvm" : INT_V_MVV;
  def "int_riscv_" # NAME # "_vxm" : INT_V_MVX;
}

multiclass INT_RISCV_V_MVF {
  def "int_riscv_" # NAME # "_vfm" : INT_V_MVF;
}

multiclass INT_RISCV_W_VV {
  def "int_riscv_" # NAME # "_vv" : INT_W_VV;
  def "int_riscv_" # NAME # "_vv_mask" : INT_W_VV_MASK;
}

multiclass INT_RISCV_W_VX {
  def "int_riscv_" # NAME # "_vx" : INT_W_VX;
  def "int_riscv_" # NAME # "_vx_mask" : INT_W_VX_MASK;
}

multiclass INT_RISCV_W_VF {
  def "int_riscv_" # NAME # "_vf" : INT_W_VF;
  def "int_riscv_" # NAME # "_vf_mask" : INT_W_VF_MASK;
}

multiclass INT_RISCV_W_WV {
  def "int_riscv_" # NAME # "_wv" : INT_W_WV;
  def "int_riscv_" # NAME # "_wv_mask" : INT_W_WV_MASK;
}

multiclass INT_RISCV_W_WX {
  def "int_riscv_" # NAME # "_wx" : INT_V_VX;
  def "int_riscv_" # NAME # "_wx_mask" : INT_V_VX_MASK;
}

multiclass INT_RISCV_W_WF {
  def "int_riscv_" # NAME # "_wf" : INT_V_VF;
  def "int_riscv_" # NAME # "_wf_mask" : INT_V_VF_MASK;
}

multiclass INT_RISCV_W_WVV {
  def "int_riscv_" # NAME # "_vv" : INT_W_WVV;
  def "int_riscv_" # NAME # "_vv_mask" : INT_W_WVV_MASK;
}

multiclass INT_RISCV_W_WVX {
  def "int_riscv_" # NAME # "_vx" : INT_W_WVX;
  def "int_riscv_" # NAME # "_vx_mask" : INT_W_WVX_MASK;
}

multiclass INT_RISCV_W_WVF {
  def "int_riscv_" # NAME # "_vf" : INT_W_WVF;
  def "int_riscv_" # NAME # "_vf_mask" : INT_W_WVF_MASK;
}

multiclass INT_RISCV_M_M {
  def "int_riscv_" # NAME # "_m" : INT_V_V;
  def "int_riscv_" # NAME # "_m_mask" : INT_V_VVV;
}

multiclass INT_RISCV_M_VV {
  def "int_riscv_" # NAME # "_vv" : INT_M_VV;
  def "int_riscv_" # NAME # "_vv_mask" : INT_M_VV_MASK;
}

multiclass INT_RISCV_M_VX {
  def "int_riscv_" # NAME # "_vx" : INT_M_VX;
  def "int_riscv_" # NAME # "_vx_mask" : INT_M_VX_MASK;
}

multiclass INT_RISCV_M_VF {
  def "int_riscv_" # NAME # "_vf" : INT_M_VF;
  def "int_riscv_" # NAME # "_vf_mask" : INT_M_VF_MASK;
}

multiclass INT_RISCV_M_MM {
  def "int_riscv_" # NAME # "_mm" : INT_V_VV;
}

multiclass INT_RISCV_M_VVM_VXM {
  def "int_riscv_" # NAME # "_vvm" : INT_M_VVM;
  def "int_riscv_" # NAME # "_vxm" : INT_M_VXM;
  def "int_riscv_" # NAME # "_vv" : INT_M_VV;
  def "int_riscv_" # NAME # "_vx" : INT_M_VX;
}

multiclass INT_RISCV_V_VV_VX : INT_RISCV_V_VV, INT_RISCV_V_VX;
multiclass INT_RISCV_V_VV_VF : INT_RISCV_V_VV, INT_RISCV_V_VF;
multiclass INT_RISCV_V_WV_WX : INT_RISCV_V_WV, INT_RISCV_V_WX;
multiclass INT_RISCV_V_VVa_VX : INT_RISCV_V_VVa, INT_RISCV_V_VX;
multiclass INT_RISCV_V_VVV_VXV : INT_RISCV_V_VVV, INT_RISCV_V_VXV;
multiclass INT_RISCV_V_VVV_VFV : INT_RISCV_V_VVV, INT_RISCV_V_VFV;

multiclass INT_RISCV_W_VV_VX : INT_RISCV_W_VV, INT_RISCV_W_VX;
multiclass INT_RISCV_W_VV_VF : INT_RISCV_W_VV, INT_RISCV_W_VF;
multiclass INT_RISCV_W_WV_WX : INT_RISCV_W_WV, INT_RISCV_W_WX;
multiclass INT_RISCV_W_WV_WF : INT_RISCV_W_WV, INT_RISCV_W_WF;
multiclass INT_RISCV_W_VV_VX_WV_WX : INT_RISCV_W_VV_VX, INT_RISCV_W_WV_WX;
multiclass INT_RISCV_W_VV_VF_WV_WF : INT_RISCV_W_VV_VF, INT_RISCV_W_WV_WF;
multiclass INT_RISCV_W_WVV_WVX : INT_RISCV_W_WVV, INT_RISCV_W_WVX;
multiclass INT_RISCV_W_WVV_WVF : INT_RISCV_W_WVV, INT_RISCV_W_WVF;

multiclass INT_RISCV_M_VV_VX : INT_RISCV_M_VV, INT_RISCV_M_VX;
multiclass INT_RISCV_M_VV_VF : INT_RISCV_M_VV, INT_RISCV_M_VF;

// 6. Configuration-Setting Instructions
def int_riscv_vsetvl  : Intrinsic<[llvm_i64_ty], [
    /* requested vector length */  llvm_i64_ty,
    /* vtype */                    llvm_i64_ty], [IntrNoMem,  IntrHasSideEffects]>;

// 7. Vector Loads and Stores
multiclass Vload {
  def ""              : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyptr_ty],
                                  [IntrReadMem]>;
  def "_strided"      : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyptr_ty, llvm_i64_ty],
                                  [IntrReadMem]>;
  def "_indexed"      : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyptr_ty, llvm_anyvector_ty],
                                  [IntrReadMem]>;
  def "_mask"         : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyvector_ty, LLVMMatchType<0>,
                                   llvm_anyptr_ty],
                                  [IntrReadMem]>;
  def "_strided_mask" : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyvector_ty, LLVMMatchType<0>,
                                   llvm_anyptr_ty, llvm_i64_ty],
                                  [IntrReadMem]>;
  def "_indexed_mask" : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyvector_ty, LLVMMatchType<0>,
                                   llvm_anyptr_ty, llvm_anyvector_ty],
                                  [IntrReadMem]>;
}
defm int_riscv_vload : Vload;

multiclass Vstore {
  def ""              : Intrinsic<[],
                                  [llvm_anyptr_ty, llvm_anyvector_ty],
                                  [IntrWriteMem]>;
  def "_strided"      : Intrinsic<[],
                                  [llvm_anyptr_ty, llvm_i64_ty,
                                   llvm_anyvector_ty],
                                  [IntrWriteMem]>;
  def "_mask"         : Intrinsic<[],
                                  [llvm_anyvector_ty, llvm_anyptr_ty,
                                   llvm_anyvector_ty],
                                  [IntrWriteMem]>;
  def "_indexed"      : Intrinsic<[],
                                  [llvm_anyvector_ty,
                                   LLVMPointerType<LLVMMatchType<0>>,
                                   llvm_anyvector_ty, llvm_i64_ty],
                                  [IntrWriteMem]>;
  def "_strided_mask" : Intrinsic<[],
                                  [llvm_anyptr_ty, llvm_i64_ty,
                                   llvm_anyvector_ty],
                                  [IntrWriteMem]>;
  def "_indexed_mask" : Intrinsic<[],
                                  [llvm_anyvector_ty, llvm_anyptr_ty,
                                   llvm_anyvector_ty, llvm_anyvector_ty],
                                  [IntrWriteMem]>;
}
defm int_riscv_vstore : Vstore;

// 8. Vector AMO Operations (Zvamo)
multiclass INT_RISCV_W_XVW {
  foreach I = ["ei8", "ei16", "ei32", "ei64"] in {
    def "int_riscv_"#NAME#I#"_v"
      : Intrinsic<[llvm_anyvector_ty],
                  [llvm_anyptr_ty, llvm_anyvector_ty, LLVMMatchType<0>],
                  [IntrReadMem, IntrWriteMem]>;
    def "int_riscv_"#NAME#I#"_v_mask"
      : Intrinsic<[llvm_anyvector_ty],
                  [llvm_anyvector_ty, llvm_anyptr_ty,
                   llvm_anyvector_ty, LLVMMatchType<0>],
                  [IntrReadMem, IntrWriteMem]>;
  }
}

defm vamoswap : INT_RISCV_W_XVW;
defm vamoadd : INT_RISCV_W_XVW;
defm vamoxor : INT_RISCV_W_XVW;
defm vamoand : INT_RISCV_W_XVW;
defm vamoor : INT_RISCV_W_XVW;
defm vamomin : INT_RISCV_W_XVW;
defm vamomax : INT_RISCV_W_XVW;
defm vamominu : INT_RISCV_W_XVW;
defm vamomaxu : INT_RISCV_W_XVW;

// 12.1. Vector Single-Width Integer Add and Subtract
defm vadd : INT_RISCV_V_VV_VX;
defm vsub : INT_RISCV_V_VV_VX;
defm vrsub : INT_RISCV_V_VX;

// 12.2. Vector Widening Integer Add/Subtract
defm vwadd : INT_RISCV_W_VV_VX_WV_WX;
defm vwaddu : INT_RISCV_W_VV_VX_WV_WX;
defm vwsub : INT_RISCV_W_VV_VX_WV_WX;
defm vwsubu : INT_RISCV_W_VV_VX_WV_WX;

// 12.3. Vector Integer Extension
defm vsext_vf2 : INT_RISCV_V_Va;
defm vsext_vf4 : INT_RISCV_V_Va;
defm vsext_vf8 : INT_RISCV_V_Va;
defm vzext_vf2 : INT_RISCV_V_Va;
defm vzext_vf4 : INT_RISCV_V_Va;
defm vzext_vf8 : INT_RISCV_V_Va;

// 12.4. Vector Integer Add-with-Carry/Subtract-with-Borrow Instructions
defm vadc : INT_RISCV_V_VVM_VXM;
defm vmadc : INT_RISCV_M_VVM_VXM;
defm vsbc : INT_RISCV_V_VVM_VXM;
defm vmsbc : INT_RISCV_M_VVM_VXM;

// 12.5. Vector Bitwise Logical Instructions
defm vand : INT_RISCV_V_VV_VX;
defm vor : INT_RISCV_V_VV_VX;
defm vxor : INT_RISCV_V_VV_VX;

// 12.6. Vector Single-Width Bit Shift Instructions
defm vsll : INT_RISCV_V_VV_VX;
defm vsrl : INT_RISCV_V_VV_VX;
defm vsra : INT_RISCV_V_VV_VX;

// 12.7. Vector Narrowing Integer Right Shift Instructions
defm vnsrl : INT_RISCV_V_WV_WX;
defm vnsra : INT_RISCV_V_WV_WX;

// 12.8. Vector Integer Comparison Instructions
defm vmseq : INT_RISCV_M_VV_VX;
defm vmsne : INT_RISCV_M_VV_VX;
defm vmslt : INT_RISCV_M_VV_VX;
defm vmsltu : INT_RISCV_M_VV_VX;
defm vmsle : INT_RISCV_M_VV_VX;
defm vmsleu : INT_RISCV_M_VV_VX;
defm vmsgt : INT_RISCV_M_VV_VX;
defm vmsgtu : INT_RISCV_M_VV_VX;
defm vmsge : INT_RISCV_M_VV_VX;
defm vmsgeu : INT_RISCV_M_VV_VX;

// 12.9. Vector Integer Min/Max Instructions
defm vmin : INT_RISCV_V_VV_VX;
defm vminu : INT_RISCV_V_VV_VX;
defm vmax : INT_RISCV_V_VV_VX;
defm vmaxu : INT_RISCV_V_VV_VX;

// 12.10. Vector Single-Width Integer Multiply Instructions
defm vmulh : INT_RISCV_V_VV_VX;
defm vmul : INT_RISCV_V_VV_VX;
defm vmulhu : INT_RISCV_V_VV_VX;
defm vmulhsu : INT_RISCV_V_VV_VX;

// 12.11. Vector Integer Divide Instructions
defm vdiv : INT_RISCV_V_VV_VX;
defm vdivu : INT_RISCV_V_VV_VX;
defm vrem : INT_RISCV_V_VV_VX;
defm vremu : INT_RISCV_V_VV_VX;

// 12.12. Vector Widening Integer Multiply Instructions
defm vwmul : INT_RISCV_W_VV_VX;
defm vwmulu : INT_RISCV_W_VV_VX;
defm vwmulsu : INT_RISCV_W_VV_VX;

// 12.13. Vector Single-Width Integer Multiply-Add Instructions
defm vmacc : INT_RISCV_V_VVV_VXV;
defm vnmsac : INT_RISCV_V_VVV_VXV;
defm vmadd : INT_RISCV_V_VVV_VXV;
defm vnmsub : INT_RISCV_V_VVV_VXV;

// 12.14. Vector Widening Integer Multiply-Add Instructions
defm vwmacc : INT_RISCV_W_WVV_WVX;
defm vwmaccu : INT_RISCV_W_WVV_WVX;
defm vwmaccsu : INT_RISCV_W_WVV_WVX;
defm vwmaccus : INT_RISCV_W_WVX;

// 12.15. Vector Quad-Widening Integer Multiply-Add Instructions
defm vqmacc : INT_RISCV_W_WVV_WVX;
defm vqmaccu : INT_RISCV_W_WVV_WVX;
defm vqmaccsu : INT_RISCV_W_WVV_WVX;
defm vqmaccus : INT_RISCV_W_WVX;

// 12.16. Vector Integer Merge Instructions
defm vmerge : INT_RISCV_V_MVV_MVX;

// 12.17. Vector Integer Move Instructions
defm vmv : INT_RISCV_V_V_X;

// 13.1. Vector Single-Width Saturating Add and Subtract
defm vsadd : INT_RISCV_V_VV_VX;
defm vsaddu : INT_RISCV_V_VV_VX;
defm vssub : INT_RISCV_V_VV_VX;
defm vssubu : INT_RISCV_V_VV_VX;

// 13.2. Vector Single-Width Averaging Add and Subtract
defm vaadd : INT_RISCV_V_VV_VX;
defm vaaddu : INT_RISCV_V_VV_VX;
defm vasub : INT_RISCV_V_VV_VX;
defm vasubu : INT_RISCV_V_VV_VX;

// 13.3. Vector Single-Width Fractional Multiply with Rounding and Saturation
defm vsmul : INT_RISCV_V_VV_VX;

// 13.4. Vector Single-Width Scaling Shift Instructions
defm vssrl : INT_RISCV_V_VV_VX;
defm vssra : INT_RISCV_V_VV_VX;

// 13.5. Vector Narrowing Fixed-Point Clip Instructions
defm vnclip : INT_RISCV_V_WV_WX;
defm vnclipu : INT_RISCV_V_WV_WX;

// 14.2. Vector Single-Width Floating-Point Add/Subtract Instructions
defm vfadd : INT_RISCV_V_VV_VF;
defm vfsub : INT_RISCV_V_VV_VF;
defm vfrsub : INT_RISCV_V_VF;

// 14.3. Vector Widening Floating-Point Add/Subtract Instructions
defm vfwadd : INT_RISCV_W_VV_VF_WV_WF;
defm vfwsub : INT_RISCV_W_VV_VF_WV_WF;

// 14.4. Vector Single-Width Floating-Point Multiply/Divide Instructions
defm vfmul : INT_RISCV_V_VV_VF;
defm vfdiv : INT_RISCV_V_VV_VF;
defm vfrdiv : INT_RISCV_V_VF;

// 14.5. Vector Widening Floating-Point Multiply
defm vfwmul :INT_RISCV_W_VV;
defm vfwmul : INT_RISCV_W_VF;

// 14.6. Vector Single-Width Floating-Point Fused Multiply-Add Instructions
defm vfmacc : INT_RISCV_V_VVV_VFV;
defm vfnmacc : INT_RISCV_V_VVV_VFV;
defm vfmsac : INT_RISCV_V_VVV_VFV;
defm vfnmsac : INT_RISCV_V_VVV_VFV;
defm vfmadd : INT_RISCV_V_VVV_VFV;
defm vfnmadd : INT_RISCV_V_VVV_VFV;
defm vfmsub : INT_RISCV_V_VVV_VFV;
defm vfnmsub : INT_RISCV_V_VVV_VFV;

// 14.7. Vector Widening Floating-Point Fused MultiplyAdd Instructions
defm vfwmacc : INT_RISCV_W_WVV_WVF;
defm vfwnmacc : INT_RISCV_W_WVV_WVF;
defm vfwmsac : INT_RISCV_W_WVV_WVF;
defm vfwnmsac : INT_RISCV_W_WVV_WVF;

// 14.8. Vector Floating-Point Square-Root Instruction
defm vfsqrt : INT_RISCV_V_V;

// 14.9. Vector Floating-Point MIN/MAX Instructions
defm vfmin : INT_RISCV_V_VV_VF;
defm vfmax : INT_RISCV_V_VV_VF;

// 14.10. Vector Floating-Point Sign-Injection Instructions
defm vfsgnj : INT_RISCV_V_VV_VF;
defm vfsgnjn : INT_RISCV_V_VV_VF;
defm vfsgnjx : INT_RISCV_V_VV_VF;

// 14.11. Vector Floating-Point Compare Instructions
defm vmfeq : INT_RISCV_M_VV_VF;
defm vmfne : INT_RISCV_M_VV_VF;
defm vmflt : INT_RISCV_M_VV_VF;
defm vmfle : INT_RISCV_M_VV_VF;
defm vmfgt : INT_RISCV_M_VV_VF;
defm vmfge : INT_RISCV_M_VV_VF;

// 14.12. Vector Floating-Point Classify Instruction
defm vfclass_v : INT_RISCV_V_Va;

// 14.13. Vector Floating-Point Merge Instruction
defm vfmerge : INT_RISCV_V_MVF;

// 14.14. Vector Floating-Point Move Instruction
defm vfmv : INT_RISCV_V_F;

// 14.15. Single-Width Floating-Point/Integer TypeConvert Instructions
defm vfcvt_x_f : INT_RISCV_W_V;
defm vfcvt_rtz_x_f : INT_RISCV_W_V;
defm vfcvt_xu_f : INT_RISCV_W_V;
defm vfcvt_rtz_xu_f : INT_RISCV_W_V;
defm vfcvt_f_x : INT_RISCV_W_V;
defm vfcvt_f_xu : INT_RISCV_W_V;
defm vwcvt_x_x : INT_RISCV_W_V;
defm vwcvtu_x_x : INT_RISCV_W_V;

// 14.16. Widening Floating-Point/Integer Type-Convert Instructions
defm vfwcvt_x_f : INT_RISCV_W_V;
defm vfwcvt_f_x : INT_RISCV_W_V;
defm vfwcvt_rtz_x_f : INT_RISCV_W_V;
defm vfwcvt_rtz_xu_f : INT_RISCV_W_V;
defm vfwcvt_f_xu : INT_RISCV_W_V;
defm vfwcvt_f_f : INT_RISCV_W_V;
defm vfwcvt_xu_f : INT_RISCV_W_V;

// 14.17. Narrowing Floating-Point/Integer Type-Convert Instructions
defm vfncvt_x_f : INT_RISCV_V_W;
defm vfncvt_f_x : INT_RISCV_V_W;
defm vfncvt_rtz_x_f : INT_RISCV_V_W;
defm vfncvt_rtz_xu_f : INT_RISCV_V_W;
defm vfncvt_f_xu : INT_RISCV_V_W;
defm vfncvt_f_f : INT_RISCV_V_W;
defm vfncvt_xu_f : INT_RISCV_V_W;
defm vfncvt_rod_f_f : INT_RISCV_V_W;

// 15.1. Vector Single-Width Integer Reduction Instructions
defm vredsum : INT_RISCV_V_VS;
defm vredmax : INT_RISCV_V_VS;
defm vredmaxu : INT_RISCV_V_VS;
defm vredmin : INT_RISCV_V_VS;
defm vredminu : INT_RISCV_V_VS;
defm vredand : INT_RISCV_V_VS;
defm vredor : INT_RISCV_V_VS;
defm vredxor : INT_RISCV_V_VS;

// 15.2. Vector Widening Integer Reduction Instructions
defm vwredsum : INT_RISCV_V_VS;
defm vwredsumu : INT_RISCV_V_VS;

// 15.3. Vector Single-Width Floating-Point Reduction Instructions
defm vfredosum : INT_RISCV_V_VS;
defm vfredsum : INT_RISCV_V_VS;
defm vfredmax : INT_RISCV_V_VS;
defm vfredmin : INT_RISCV_V_VS;

// 15.4. Vector Widening Floating-Point Reduction Instructions
defm vfwredosum : INT_RISCV_V_VS;
defm vfwredsum : INT_RISCV_V_VS;

// 16.1. Vector Mask-Register Logical Instructions
defm vmand : INT_RISCV_M_MM;
defm vmnand : INT_RISCV_M_MM;
defm vmandnot : INT_RISCV_M_MM;
defm vmxor : INT_RISCV_M_MM;
defm vmor : INT_RISCV_M_MM;
defm vmnor : INT_RISCV_M_MM;
defm vmornot : INT_RISCV_M_MM;
defm vmxnor : INT_RISCV_M_MM;

// 16.2. Vector mask population count vpopc
defm vpopc : INT_RISCV_X_M;

// 16.3. vfirst find-first-set mask bit
defm vfirst : INT_RISCV_X_M;

// 16.4. vmsbf.m set-before-first mask bit
defm vmsbf : INT_RISCV_M_M;

// 16.5. vmsif.m set-including-first mask bit
defm vmsif : INT_RISCV_M_M;

// 16.6. vmsof.m set-only-first mask bit
defm vmsof : INT_RISCV_M_M;

// 16.8. Vector Iota Instruction
defm viota_m : INT_RISCV_V_Va;

// 16.9. Vector Element Index Instruction
defm vid : INT_RISCV_V;

// 17.1. Integer Scalar Move Instructions
def int_riscv_vmv_x_s : INT_X_V;
def int_riscv_vmv_s_x : INT_V_VX;

// 17.2. Floating-Point Scalar Move Instructions
def int_riscv_vfmv_f_s : INT_F_V;
def int_riscv_vfmv_s_f : INT_V_VF;

// 17.3. Vector Slide Instructions
defm vslideup : INT_RISCV_V_VVX;
defm vslidedown : INT_RISCV_V_VVX;
defm vslide1up : INT_RISCV_V_VX;
defm vslide1down : INT_RISCV_V_VX;
defm vfslide1up : INT_RISCV_V_VF;
defm vfslide1down : INT_RISCV_V_VF;

// 17.4. Vector Register Gather Instruction
defm vrgather : INT_RISCV_V_VVa_VX;

// 17.5. Vector Compress Instruction
defm vcompress : INT_RISCV_V_VM;

// 17.6. Whole Vector Register Move
// 19.3. Vector Integer Dot-Product Instruction
// 19.4. Vector Floating-Point Dot Product Instruction

// Reinterpret Cast Conversion Functions
def int_riscv_vreinterpret_v : INT_V_Va;

} // TargetPrefix = "riscv"


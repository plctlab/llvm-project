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

let TargetPrefix = "riscv" in {

class V_VV : Intrinsic<[llvm_anyvector_ty],
                       [LLVMMatchType<0>, LLVMMatchType<0>],
                       [IntrNoMem]>, RVVIntrinsic;

class V_VV_mask : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             LLVMMatchType<0>, LLVMMatchType<0>],
                            [IntrNoMem]>, RVVIntrinsic;

class W_VV : Intrinsic<[llvm_anyvector_ty],
                       [llvm_anyvector_ty, LLVMMatchType<1>],
                       [IntrNoMem]>, RVVIntrinsic;

class W_VV_mask : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             llvm_anyvector_ty, LLVMMatchType<2>],
                            [IntrNoMem]>, RVVIntrinsic;

class V_WV : Intrinsic<[llvm_anyvector_ty],
                       [llvm_anyvector_ty, LLVMMatchType<0>],
                       [IntrNoMem]>, RVVIntrinsic;

class V_WV_mask : Intrinsic<[llvm_anyvector_ty],
                         [llvm_anyvector_ty, LLVMMatchType<0>,
                          llvm_anyvector_ty, LLVMMatchType<0>],
                         [IntrNoMem]>, RVVIntrinsic;

class V_WX : Intrinsic<[llvm_anyvector_ty],
                       [llvm_anyvector_ty, llvm_anyint_ty],
                       [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 2;
}

class V_WX_mask : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             llvm_anyvector_ty, llvm_anyint_ty],
                            [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 4;
}

class W_WV : Intrinsic<[llvm_anyvector_ty],
                       [LLVMMatchType<0>, llvm_anyvector_ty],
                       [IntrNoMem]>, RVVIntrinsic;
                        
class W_WV_mask : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             LLVMMatchType<0>, llvm_anyvector_ty],
                            [IntrNoMem]>, RVVIntrinsic;

class V_VX : Intrinsic<[llvm_anyvector_ty],
                       [LLVMMatchType<0>, llvm_anyint_ty],
                       [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 2;
}

class V_VX_mask : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             LLVMMatchType<0>, llvm_anyint_ty],
                            [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 4;
}

class W_VX : Intrinsic<[llvm_anyvector_ty],
                       [llvm_anyvector_ty, llvm_anyint_ty],
                       [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 2;
}

class W_VX_mask : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             llvm_anyvector_ty, llvm_anyint_ty],
                            [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 4;
}

class W_VF : Intrinsic<[llvm_anyvector_ty],
                       [llvm_anyvector_ty, llvm_anyfloat_ty],
                       [IntrNoMem]>, RVVIntrinsic;

class W_VF_mask : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             llvm_anyvector_ty, llvm_anyfloat_ty],
                            [IntrNoMem]>, RVVIntrinsic;

class V_VF : Intrinsic<[llvm_anyvector_ty],
                       [LLVMMatchType<0>, llvm_anyfloat_ty],
                       [IntrNoMem]>, RVVIntrinsic;

class V_VF_mask : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             LLVMMatchType<0>, llvm_anyfloat_ty],
                            [IntrNoMem]>, RVVIntrinsic;

class V_VVV : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, LLVMMatchType<0>, LLVMMatchType<0>],
                        [IntrNoMem]>, RVVIntrinsic;

class V_VVV_mask : Intrinsic<[llvm_anyvector_ty],
                             [llvm_anyvector_ty, LLVMMatchType<0>,
                              LLVMMatchType<0>, LLVMMatchType<0>],
                             [IntrNoMem]>, RVVIntrinsic;

class V_VVX : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, llvm_anyint_ty, LLVMMatchType<0>],
                        [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 2;
}

class V_VVX_mask : Intrinsic<[llvm_anyvector_ty],
                             [llvm_anyvector_ty, LLVMMatchType<0>,
                              llvm_anyint_ty, LLVMMatchType<0>],
                             [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 3;
}

class V_VVZ : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, LLVMMatchType<0>, llvm_anyint_ty],
                        [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 3;
}

class V_VVZ_mask : Intrinsic<[llvm_anyvector_ty],
                             [llvm_anyvector_ty, LLVMMatchType<0>,
                              LLVMMatchType<0>, llvm_anyint_ty],
                             [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 4;
}

class V_VVF : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, llvm_anyfloat_ty, LLVMMatchType<0>],
                        [IntrNoMem]>, RVVIntrinsic;

class V_VVF_mask : Intrinsic<[llvm_anyvector_ty],
                             [llvm_anyvector_ty, LLVMMatchType<0>,
                              llvm_anyfloat_ty, LLVMMatchType<0>],
                             [IntrNoMem]>, RVVIntrinsic;

class W_V : Intrinsic<[llvm_anyvector_ty],
                      [llvm_anyvector_ty],
                      [IntrNoMem]>, RVVIntrinsic;

class W_V_mask : Intrinsic<[llvm_anyvector_ty],
                           [llvm_anyvector_ty, LLVMMatchType<0>,
                            llvm_anyvector_ty],
                           [IntrNoMem]>, RVVIntrinsic;

class V_VVM : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, LLVMMatchType<0>, llvm_anyvector_ty],
                        [IntrNoMem]>, RVVIntrinsic;

class V_VXM : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, llvm_anyint_ty, llvm_anyvector_ty],
                        [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 2;
}

class M_VV : Intrinsic<[llvm_anyvector_ty],
                       [llvm_anyvector_ty,  LLVMMatchType<1>],
                       [IntrNoMem]>, RVVIntrinsic;

class M_VV_mask : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, LLVMMatchType<0>,
                            llvm_anyvector_ty, llvm_anyvector_ty],
                            [IntrNoMem]>, RVVIntrinsic;

class M_VVM : Intrinsic<[llvm_anyvector_ty],
                        [llvm_anyvector_ty, LLVMMatchType<1>, LLVMMatchType<0>],
                        [IntrNoMem]>, RVVIntrinsic;

class M_VX : Intrinsic<[llvm_anyvector_ty],
                       [llvm_anyvector_ty, llvm_anyint_ty],
                       [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 2;
}

class M_VX_mask : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, LLVMMatchType<0>,
                            llvm_anyvector_ty, llvm_anyint_ty],
                            [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 4;
}

class M_VF : Intrinsic<[llvm_anyvector_ty],
                       [llvm_anyvector_ty, llvm_anyfloat_ty],
                       [IntrNoMem]>, RVVIntrinsic;

class M_VF_mask : Intrinsic<[llvm_anyvector_ty],
                            [LLVMMatchType<0>, LLVMMatchType<0>,
                            llvm_anyvector_ty, llvm_anyfloat_ty],
                            [IntrNoMem]>, RVVIntrinsic;

class M_VXM : Intrinsic<[llvm_anyvector_ty],
                        [llvm_anyvector_ty, llvm_any_ty, LLVMMatchType<0>],
                        [IntrNoMem]>, RVVIntrinsic;

class V_V : Intrinsic<[llvm_anyvector_ty],
                      [LLVMMatchType<0>],
                      [IntrNoMem]>, RVVIntrinsic;

class V_V_mask : Intrinsic<[llvm_anyvector_ty],
                      [llvm_anyvector_ty, LLVMMatchType<0>, LLVMMatchType<0>],
                      [IntrNoMem]>, RVVIntrinsic;

class W_WVV : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, llvm_anyvector_ty, LLVMMatchType<1>],
                        [IntrNoMem]>, RVVIntrinsic;

class W_WVV_mask : Intrinsic<[llvm_anyvector_ty],
                             [llvm_anyvector_ty, LLVMMatchType<0>,
                              llvm_anyvector_ty, LLVMMatchType<2>],
                             [IntrNoMem]>, RVVIntrinsic;

class W_WVX : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, llvm_anyint_ty, llvm_anyvector_ty],
                        [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 2;
}

class W_WVF : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, llvm_anyfloat_ty, llvm_anyvector_ty],
                        [IntrNoMem]>, RVVIntrinsic;

class W_WVX_mask : Intrinsic<[llvm_anyvector_ty],
                             [llvm_anyvector_ty, LLVMMatchType<0>,
                             llvm_anyint_ty, llvm_anyvector_ty],
                             [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 3;
}

class W_WVF_mask : Intrinsic<[llvm_anyvector_ty],
                             [llvm_anyvector_ty, LLVMMatchType<0>,
                             llvm_anyfloat_ty, llvm_anyvector_ty],
                             [IntrNoMem]>, RVVIntrinsic;

class V_MVV : Intrinsic<[llvm_anyvector_ty],
                        [llvm_anyvector_ty, LLVMMatchType<0>, LLVMMatchType<0>],
                        [IntrNoMem]>, RVVIntrinsic;

class V_MVX : Intrinsic<[llvm_anyvector_ty],
                        [llvm_anyvector_ty, LLVMMatchType<0>, llvm_anyint_ty],
                        [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 3;
}

class V_V1 : Intrinsic<[llvm_anyvector_ty], [llvm_anyvector_ty], [IntrNoMem]>,
             RVVIntrinsic;

class V_V1_mask : Intrinsic<[llvm_anyvector_ty],
                            [llvm_anyvector_ty, LLVMMatchType<0>,
                             llvm_anyvector_ty],
                            [IntrNoMem]>, RVVIntrinsic;

class V_VRV : Intrinsic<[llvm_anyvector_ty],
                        [LLVMMatchType<0>, llvm_anyvector_ty, LLVMMatchType<0>],
                        [IntrNoMem]>, RVVIntrinsic;

class V_VRV_mask : Intrinsic<[llvm_anyvector_ty],
                             [llvm_anyvector_ty, LLVMMatchType<0>,
                              llvm_anyvector_ty, LLVMMatchType<0>],
                             [IntrNoMem]>, RVVIntrinsic;

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
                                  [llvm_anyvector_ty,
                                   LLVMPointerType<LLVMMatchType<0>>,
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

// 12.1. Vector Single-Width Integer Add and Subtract
multiclass Binary_int_vv {
  def "int_riscv_" # NAME # "_vv" : V_VV;
  def "int_riscv_" # NAME # "_vv_mask" : V_VV_mask;
}

multiclass Binary_int_vx {
  def "int_riscv_" # NAME # "_vx" : V_VX;
  def "int_riscv_" # NAME # "_vx_mask" : V_VX_mask;
}

multiclass Binary_int_vv_vx {
  defm NAME : Binary_int_vv;
  defm NAME : Binary_int_vx;
}
defm vadd : Binary_int_vv_vx;
defm vsub : Binary_int_vv_vx;
defm vrsub : Binary_int_vx;

multiclass Binary_w_vv {
  def "int_riscv_" # NAME # "_vv" : W_VV;
  def "int_riscv_" # NAME # "_vv_mask" : W_VV_mask;
}

multiclass Binary_w_vx {
  def "int_riscv_" # NAME # "_vx" : W_VX;
  def "int_riscv_" # NAME # "_vx_mask" : W_VX_mask;
}

multiclass Binary_v_wv {
  def "int_riscv_" # NAME # "_wv" : V_WV;
  def "int_riscv_" # NAME # "_wv_mask" : V_WV_mask;
}

multiclass Binary_v_wx {
  def "int_riscv_" # NAME # "_wx" : V_WX;
  def "int_riscv_" # NAME # "_wx_mask" : V_WX_mask;
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

// 12.2. Vector Widening Integer Add/Subtract
multiclass Binary_int_wide {
  defm NAME : Binary_w_wv;
  defm NAME : Binary_w_vx;
  defm NAME : Binary_w_wx;
  defm NAME : Binary_w_vv;
}
defm vwadd : Binary_int_wide;
defm vwaddu : Binary_int_wide;
defm vwsub : Binary_int_wide;
defm vwsubu : Binary_int_wide;

// 12.3. Vector Integer Extension
multiclass Extension_int {
  def "int_riscv_" # NAME : W_V;
  def "int_riscv_" # NAME # "_mask" : W_V_mask;
}
defm vsext : Extension_int;
defm vzext : Extension_int;

// 12.4. Vector Integer Add-with-Carry/Subtract-with-Borrow Instructions
multiclass carry_int_vm {
  def "int_riscv_" # NAME # "_vvm" : M_VVM;
  def "int_riscv_" # NAME # "_vv" : M_VV;
  def "int_riscv_" # NAME # "_vxm" : M_VXM;
}
multiclass carry_int {
  def "int_riscv_" # NAME # "_vvm" : V_VVM;
  def "int_riscv_" # NAME # "_vxm" : V_VXM;
}
defm vadc : carry_int;
defm vmadc : carry_int_vm;
defm vsbc : carry_int;
defm vmsbc : carry_int_vm;

// 12.5. Vector Bitwise Logical Instructions
defm vand : Binary_int_vv_vx;
defm vor : Binary_int_vv_vx;
defm vxor : Binary_int_vv_vx;
def "int_riscv_vnot_v" : V_V; // todo

// 12.6. Vector Single-Width Bit Shift Instructions
defm vsll : Binary_int_vv_vx;
defm vsrl : Binary_int_vv_vx;
defm vsra : Binary_int_vv_vx;

// 12.7. Vector Narrowing Integer Right Shift Instructions
multiclass Binary_int_narrow {
  defm NAME : Binary_v_wv;
  defm NAME : Binary_v_wx;
}
defm vnsrl : Binary_int_narrow;
defm vnsra : Binary_int_narrow;

// 12.8. Vector Integer Comparison Instructions
multiclass Binary_int_comparison {
  def "int_riscv_" # NAME # "_vv" : M_VV;
  def "int_riscv_" # NAME # "_vv_mask" : M_VV_mask;
  def "int_riscv_" # NAME # "_vx" : M_VX;
  def "int_riscv_" # NAME # "_vx_mask" : M_VX_mask;
}
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

// 12.9. Vector Integer Min/Max Instructions
defm vmin : Binary_int_vv_vx;
defm vminu : Binary_int_vv_vx;
defm vmax : Binary_int_vv_vx;
defm vmaxu : Binary_int_vv_vx;

// 12.10. Vector Single-Width Integer Multiply Instructions
defm vmulh : Binary_int_vv_vx;
defm vmul : Binary_int_vv_vx;
defm vmulhu : Binary_int_vv_vx;
defm vmulhsu : Binary_int_vv_vx;

// 12.11. Vector Integer Divide Instructions
defm vdiv : Binary_int_vv_vx;
defm vdivu : Binary_int_vv_vx;
defm vrem : Binary_int_vv_vx;
defm vremu : Binary_int_vv_vx;

// 12.12. Vector Widening Integer Multiply Instructions
multiclass Binary_int_wide_mul {
  defm NAME : Binary_w_vv;
  defm NAME : Binary_w_vx;
}
defm vwmul : Binary_int_wide_mul;
defm vwmulu : Binary_int_wide_mul;
defm vwmulsu : Binary_int_wide_mul;

// 12.13. Vector Single-Width Integer Multiply-Add Instructions
multiclass Ternary_int_v_vvx_vvv {
  def "int_riscv_" # NAME # "_vv" : V_VVV;
  def "int_riscv_" # NAME # "_vv_mask" : V_VVV_mask;
  def "int_riscv_" # NAME # "_vx" : V_VVX;
  def "int_riscv_" # NAME # "_vx_mask" : V_VVX_mask;
}
defm vmacc : Ternary_int_v_vvx_vvv;
defm vnmsac : Ternary_int_v_vvx_vvv;
defm vmadd : Ternary_int_v_vvx_vvv;
defm vnmsub : Ternary_int_v_vvx_vvv;

// 12.14. Vector Widening Integer Multiply-Add Instructions
multiclass Ternary_int_wide {
  def "int_riscv_" # NAME # "_vv" : W_WVV;
  def "int_riscv_" # NAME # "_vv_mask" : W_WVV_mask;
  def "int_riscv_" # NAME # "_vx" : W_WVX;
  def "int_riscv_" # NAME # "_vx_mask" : W_WVX_mask;
}
multiclass Ternary_int_wide_w_vx {
  def "int_riscv_" # NAME # "_vx" : W_WVX;
  def "int_riscv_" # NAME # "_vx_mask" : W_WVX_mask;
}
defm vwmacc : Ternary_int_wide;
defm vwmaccu : Ternary_int_wide;
defm vwmaccsu : Ternary_int_wide;
defm vwmaccus : Ternary_int_wide_w_vx;

// 12.15. Vector Quad-Widening Integer Multiply-Add Instructions
defm vqmacc : Ternary_int_wide;
defm vqmaccu : Ternary_int_wide;
defm vqmaccsu : Ternary_int_wide;
defm vqmaccus : Ternary_int_wide_w_vx;

// 12.16. Vector Integer Merge Instructions
multiclass Merge {
  def "int_riscv_" # NAME # "_vvm" : V_MVV;
  def "int_riscv_" # NAME # "_vxm" : V_MVX;
}
defm vmerge : Merge;

// 12.17. Vector Integer Move Instructions
def int_riscv_vmv_v_x : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyint_ty],
                                  [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 1;
}
def int_riscv_vmv_v_v : V_V;

// 13.1. Vector Single-Width Saturating Add and Subtract
defm vsadd : Binary_int_vv_vx;
defm vsaddu : Binary_int_vv_vx;
defm vssub : Binary_int_vv_vx;
defm vssubu : Binary_int_vv_vx;

// 13.2. Vector Single-Width Averaging Add and Subtract
defm vaadd : Binary_int_vv_vx;
defm vaaddu : Binary_int_vv_vx;
defm vasub : Binary_int_vv_vx;
defm vasubu : Binary_int_vv_vx;

// 13.3. Vector Single-Width Fractional Multiply with Rounding and Saturation
defm vsmul : Binary_int_vv_vx;

// 13.4. Vector Single-Width Scaling Shift Instructions
defm vssrl : Binary_int_vv_vx;
defm vssra : Binary_int_vv_vx;

// 13.5. Vector Narrowing Fixed-Point Clip Instructions
multiclass Narrowing {
  def "int_riscv_" # NAME # "_wv" : V_WV;
  def "int_riscv_" # NAME # "_wv_mask" : V_WV_mask;
  def "int_riscv_" # NAME # "_wx" : V_WX;
  def "int_riscv_" # NAME # "_wx_mask" : V_WX_mask;
}
defm vnclip : Narrowing;
defm vnclipu : Narrowing;

// 14.2. Vector Single-Width Floating-Point Add/Subtract Instructions
multiclass Binary_float_v_vv_vf {
  def "int_riscv_" # NAME # "_vv" : V_VV;
  def "int_riscv_" # NAME # "_vv_mask" : V_VV_mask;
  def "int_riscv_" # NAME # "_vf" : V_VF;
  def "int_riscv_" # NAME # "_vf_mask" : V_VF_mask;
}
defm vfadd : Binary_float_v_vv_vf;
defm vfsub : Binary_float_v_vv_vf;
def "int_riscv_vfrsub_vf" : V_VF;
def "int_riscv_vfrsub_vf_mask" : V_VF_mask;

// 14.3. Vector Widening Floating-Point Add/Subtract Instructions
multiclass Binary_float_wide {
  defm NAME : Binary_w_vv;
  defm NAME : Binary_w_vf;
  defm NAME : Binary_w_wf;
  defm NAME : Binary_w_wv;
}
defm vfwadd : Binary_float_wide;
defm vfwsub : Binary_float_wide;

// 14.4. Vector Single-Width Floating-Point Multiply/Divide Instructions
defm vfmul : Binary_float_v_vv_vf;
defm vfdiv : Binary_float_v_vv_vf;
def "int_riscv_vfrdiv_vf" : V_VF;
def "int_riscv_vfrdiv_vf_mask" : V_VF_mask;

// 14.5. Vector Widening Floating-Point Multiply
defm vfwmul :Binary_w_vv;
defm vfwmul : Binary_w_vf;

// 14.6. Vector Single-Width Floating-Point Fused Multiply-Add Instructions
multiclass Ternary_float_v_vv_vf {
  def "int_riscv_" # NAME # "_vv" : V_VVV;
  def "int_riscv_" # NAME # "_vv_mask" : V_VVV_mask;
  def "int_riscv_" # NAME # "_vf" : V_VVF;
  def "int_riscv_" # NAME # "_vf_mask" : V_VVF_mask;
}
defm vfmacc : Ternary_float_v_vv_vf;
defm vfnmacc : Ternary_float_v_vv_vf;
defm vfmsac : Ternary_float_v_vv_vf;
defm vfnmsac : Ternary_float_v_vv_vf;
defm vfmadd : Ternary_float_v_vv_vf;
defm vfnmadd : Ternary_float_v_vv_vf;
defm vfmsub : Ternary_float_v_vv_vf;
defm vfnmsub : Ternary_float_v_vv_vf;

// 14.7. Vector Widening Floating-Point Fused MultiplyAdd Instructions
multiclass Ternary_float_wide {
  def "int_riscv_" # NAME # "_vv" : W_WVV;
  def "int_riscv_" # NAME # "_vv_mask" : W_WVV_mask;
  def "int_riscv_" # NAME # "_vf" : W_WVF;
  def "int_riscv_" # NAME # "_vf_mask" : W_WVF_mask;
}
defm vfwmacc : Ternary_float_wide;
defm vfwnmacc : Ternary_float_wide;
defm vfwmsac : Ternary_float_wide;
defm vfwnmsac : Ternary_float_wide;

// 14.8. Vector Floating-Point Square-Root Instruction
def "int_riscv_vfsqrt_v" : V_V;
def "int_riscv_vfsqrt_v_mask" : V_V_mask;

// 14.9. Vector Floating-Point MIN/MAX Instructions
defm vfmin : Binary_float_v_vv_vf;
defm vfmax : Binary_float_v_vv_vf;

// 14.10. Vector Floating-Point Sign-Injection Instructions
defm vfsgnj : Binary_float_v_vv_vf;
defm vfsgnjn : Binary_float_v_vv_vf;
defm vfsgnjx : Binary_float_v_vv_vf;

// 14.11. Vector Floating-Point Compare Instructions
multiclass Binary_float_vm {
  def "int_riscv_" # NAME # "_vv" : M_VV;
  def "int_riscv_" # NAME # "_vv_mask" : M_VV_mask;
  def "int_riscv_" # NAME # "_vf" : M_VF;
  def "int_riscv_" # NAME # "_vf_mask" : M_VF_mask;
}
defm vmfeq : Binary_float_vm;
defm vmfne : Binary_float_vm;
defm vmflt : Binary_float_vm;
defm vmfle : Binary_float_vm;
defm vmfgt : Binary_float_vm;
defm vmfge : Binary_float_vm;

// 14.12. Vector Floating-Point Classify Instruction
def int_riscv_vfclass_v : Intrinsic<[llvm_anyvector_ty], [llvm_anyvector_ty],
                                    [IntrNoMem]>;
def int_riscv_vfclass_v_mask : Intrinsic<[llvm_anyvector_ty],
                                         [llvm_anyvector_ty, llvm_anyvector_ty,
                                          llvm_anyvector_ty],
                                         [IntrNoMem]>;

// 14.13. Vector Floating-Point Merge Instruction
def int_riscv_vfmerge_vvm : Intrinsic<[llvm_anyvector_ty],
                                      [llvm_anyvector_ty, LLVMMatchType<0>,
                                       LLVMMatchType<0>],
                                      [IntrNoMem]>;
def int_riscv_vfmerge_vfm : Intrinsic<[llvm_anyvector_ty],
                                      [llvm_anyvector_ty, LLVMMatchType<0>,
                                       llvm_anyfloat_ty],
                                      [IntrNoMem]>, RVVIntrinsic;

// 14.14. Vector Floating-Point Move Instruction
def int_riscv_vfmv_v_f : Intrinsic<[llvm_anyvector_ty], [llvm_anyfloat_ty],
                                   [IntrNoMem]>, RVVIntrinsic;

// 14.15. Single-Width Floating-Point/Integer TypeConvert Instructions
multiclass Unary_V_V1 {
  def "int_riscv_" # NAME # "_v" : V_V1;
  def "int_riscv_" # NAME # "_v_mask" : V_V1_mask;
}
defm vfcvt_x_f : Unary_V_V1;
defm vfcvt_rtz_x_f : Unary_V_V1;
defm vfcvt_xu_f : Unary_V_V1;
defm vfcvt_rtz_xu_f : Unary_V_V1;
defm vfcvt_f_x : Unary_V_V1;
defm vfcvt_f_xu : Unary_V_V1;
defm vwcvt_x_x : Unary_V_V1;
defm vwcvtu_x_x : Unary_V_V1;

// 14.16. Widening Floating-Point/Integer Type-Convert Instructions
defm vfwcvt_x_f : Unary_V_V1;
defm vfwcvt_f_x : Unary_V_V1;
defm vfwcvt_rtz_x_f : Unary_V_V1;
defm vfwcvt_rtz_xu_f : Unary_V_V1;
defm vfwcvt_f_xu : Unary_V_V1;
defm vfwcvt_f_f : Unary_V_V1;
defm vfwcvt_xu_f : Unary_V_V1;

// 14.17. Narrowing Floating-Point/Integer Type-Convert Instructions
multiclass Unary_n_V_V1 {
  def "int_riscv_" # NAME # "_w" : V_V1;
  def "int_riscv_" # NAME # "_w_mask" : V_V1_mask;
}
defm vfncvt_x_f : Unary_n_V_V1;
defm vfncvt_f_x : Unary_n_V_V1;
defm vfncvt_rtz_x_f : Unary_n_V_V1;
defm vfncvt_rtz_xu_f : Unary_n_V_V1;
defm vfncvt_f_xu : Unary_n_V_V1;
defm vfncvt_f_f : Unary_n_V_V1;
defm vfncvt_xu_f : Unary_n_V_V1;
defm vfncvt_rod_f_f : Unary_n_V_V1;

// 15.1. Vector Single-Width Integer Reduction Instructions
multiclass Reduction_v_vrv {
  def "int_riscv_" # NAME # "_vs" : V_VRV;
  def "int_riscv_" # NAME # "_vs_mask" : V_VRV_mask;
}
defm vredsum : Reduction_v_vrv;
defm vredmax : Reduction_v_vrv;
defm vredmaxu : Reduction_v_vrv;
defm vredmin : Reduction_v_vrv;
defm vredminu : Reduction_v_vrv;
defm vredand : Reduction_v_vrv;
defm vredor : Reduction_v_vrv;
defm vredxor : Reduction_v_vrv;

// 15.2. Vector Widening Integer Reduction Instructions
defm vwredsum : Reduction_v_vrv;
defm vwredsumu : Reduction_v_vrv;

// 15.3. Vector Single-Width Floating-Point Reduction Instructions
defm vfredosum : Reduction_v_vrv;
defm vfredsum : Reduction_v_vrv;
defm vfredmax : Reduction_v_vrv;
defm vfredmin : Reduction_v_vrv;

// 15.4. Vector Widening Floating-Point Reduction Instructions
defm vfwredosum : Reduction_v_vrv;
defm vfwredsum : Reduction_v_vrv;

// 16.1. Vector Mask-Register Logical Instructions
def int_riscv_vmand_mm : V_VV;
def int_riscv_vmnand_mm : V_VV;
def int_riscv_vmandnot_mm : V_VV;
def int_riscv_vmxor_mm : V_VV;
def int_riscv_vmor_mm : V_VV;
def int_riscv_vmnor_mm : V_VV;
def int_riscv_vmornot_mm : V_VV;
def int_riscv_vmxnor_mm : V_VV;
def int_riscv_vmmv_m : V_V;
def int_riscv_vmnot_m : V_V;

// 16.2. Vector mask population count vpopc
def int_riscv_vpopc_m : Intrinsic<[llvm_i64_ty],
                                  [llvm_anyvector_ty],
                                  [IntrNoMem]>;
def int_riscv_vpopc_m_mask : Intrinsic<[llvm_i64_ty],
                                       [llvm_anyvector_ty, llvm_anyvector_ty],
                                       [IntrNoMem]>;

// 16.3. vfirst find-first-set mask bit
def int_riscv_vfirst_m : Intrinsic<[llvm_i64_ty],
                                   [llvm_anyvector_ty],
                                   [IntrNoMem]>;
def int_riscv_vfirst_m_mask : Intrinsic<[llvm_i64_ty],
                                        [llvm_anyvector_ty, llvm_anyvector_ty],
                                        [IntrNoMem]>;

// 16.4. vmsbf.m set-before-first mask bit
def int_riscv_vmsbf_m : V_V;
def int_riscv_vmsbf_m_mask : V_VVV;

// 16.5. vmsif.m set-including-first mask bit
def int_riscv_vmsif_m : V_V;
def int_riscv_vmsif_m_mask : V_VVV;

// 16.6. vmsof.m set-only-first mask bit
def int_riscv_vmsof_m : V_V;
def int_riscv_vmsof_m_mask : V_VVV;

// 16.8. Vector Iota Instruction
def int_riscv_viota_m : V_V1;
def int_riscv_viota_m_mask : V_V1_mask;

// 16.9. Vector Element Index Instruction
def int_riscv_vid_v : Intrinsic<[llvm_anyvector_ty],
                                [],
                                [IntrNoMem]>;

def int_riscv_vid_v_mask : Intrinsic<[llvm_anyvector_ty],
                                     [llvm_anyvector_ty, llvm_anyvector_ty],
                                     [IntrNoMem]>;

// 17.1. Integer Scalar Move Instructions
def int_riscv_vmv_x_s : Intrinsic<[llvm_anyint_ty],
                                  [llvm_anyvector_ty],
                                  [IntrNoMem]>, RVVIntrinsic;
def int_riscv_vmv_s_x : Intrinsic<[llvm_anyvector_ty],
                                  [llvm_anyvector_ty, llvm_anyint_ty],
                                  [IntrNoMem]>, RVVIntrinsic {
  let ExtendOperand = 2;
}

// 17.2. Floating-Point Scalar Move Instructions
def int_riscv_vfmv_f_s : Intrinsic<[llvm_anyfloat_ty],
                                   [llvm_anyvector_ty],
                                   [IntrNoMem]>;
def int_riscv_vfmv_s_f : Intrinsic<[llvm_anyvector_ty],
                                   [llvm_anyvector_ty, llvm_anyfloat_ty],
                                   [IntrNoMem]>, RVVIntrinsic;

// 17.3. Vector Slide Instructions
multiclass Ternary_int_v_vvz {
  def "int_riscv_" # NAME # "_vx" : V_VVZ;
  def "int_riscv_" # NAME # "_vx_mask" : V_VVZ_mask;
}
multiclass Binary_float_v_vf {
  def "int_riscv_" # NAME # "_vf" : V_VF;
  def "int_riscv_" # NAME # "_vf_mask" : V_VF_mask;
}
defm vslideup : Ternary_int_v_vvz;
defm vslidedown : Ternary_int_v_vvz;
defm vslide1up : Binary_int_vx;
defm vslide1down : Binary_int_vx;
defm vfslide1up : Binary_float_v_vf;
defm vfslide1down : Binary_float_v_vf;

// 17.4. Vector Register Gather Instruction
defm vrgather : Binary_int_vv_vx;

// 17.5. Vector Compress Instruction
def int_riscv_vcompress_vm : Intrinsic<[llvm_anyvector_ty],
                                       [llvm_anyvector_ty, LLVMMatchType<0>,
                                        LLVMMatchType<0>],
                                       [IntrNoMem]>;

// 17.6. Whole Vector Register Move
// 19.3. Vector Integer Dot-Product Instruction
// 19.4. Vector Floating-Point Dot Product Instruction

// Reinterpret Cast Conversion Functions
def int_riscv_vreinterpret_v : V_V1;

} // TargetPrefix = "riscv"


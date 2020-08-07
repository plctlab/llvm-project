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

multiclass Binary_vv {
  def "int_riscv_" # NAME : Intrinsic<[ llvm_anyvector_ty ],
                                              [ LLVMMatchType<0>, LLVMMatchType<0> ],
                                              [ IntrNoMem ]>;
  // TODO: mask type
}

multiclass Binary_vx {
  def "int_riscv_" # NAME : Intrinsic<[ llvm_anyvector_ty ],
                                              [ LLVMMatchType<0>, llvm_anyint_ty ],
                                              [ IntrNoMem ]>;
  // TODO: mask type
}

multiclass Binary_vf {
  def "int_riscv_" # NAME : Intrinsic<[ llvm_anyvector_ty ],
                                      [ LLVMMatchType<0>, llvm_anyfloat_ty ],
                                      [ IntrNoMem ]>;
}

defm vadd_vv : Binary_vv;
defm vfadd_vv : Binary_vv;
defm vsub_vv : Binary_vv;
defm vfsub_vv : Binary_vv;
defm vmul_vv : Binary_vv;
defm vfmul_vv : Binary_vv;
defm vdiv_vv : Binary_vv;
defm vfdiv_vv : Binary_vv;
defm vand_vv : Binary_vv;
defm vor_vv : Binary_vv;
defm vxor_vv : Binary_vv;
defm vmseq_vv : Binary_vv;
defm vmsne_vv : Binary_vv;
defm vmslt_vv : Binary_vv;
defm vmsltu_vv : Binary_vv;
defm vmsgt_vv : Binary_vv;
defm vmsgtu_vv : Binary_vv;
defm vmsle_vv : Binary_vv;
defm vmsleu_vv : Binary_vv;
defm vmsge_vv : Binary_vv;
defm vmsgeu_vv : Binary_vv;
defm vmfeq_vv : Binary_vv;
defm vmfne_vv : Binary_vv;
defm vmflt_vv : Binary_vv;
defm vmfgt_vv : Binary_vv;
defm vmfle_vv : Binary_vv;
defm vmfge_vv : Binary_vv;
defm vmin_vv : Binary_vv;
defm vminu_vv : Binary_vv;
defm vmax_vv : Binary_vv;
defm vmaxu_vv : Binary_vv;

defm vadd_vx : Binary_vx;
defm vfadd_vx : Binary_vf;
defm vsub_vx : Binary_vx;
defm vfsub_vx : Binary_vf;
defm vmul_vx : Binary_vx;
defm vfmul_vx : Binary_vf;
defm vdiv_vx :Binary_vx;
defm vfdiv_vx : Binary_vf;
defm vsll_vx : Binary_vx;
defm vsrl_vx : Binary_vx;
defm vsra_vx : Binary_vx;
defm vmseq : Binary_vx;


multiclass Vload {
  def ""  : Intrinsic<[ llvm_anyvector_ty ],
                      [ LLVMPointerType<LLVMMatchType<0>> ],
                      [ IntrReadMem ]>;
    // TODO stride, indexed 
}

defm int_riscv_vload : Vload;

multiclass Vstore {
  def "" : Intrinsic<[],
                    [ LLVMPointerType<llvm_anyvector_ty>,
                      llvm_anyvector_ty ],
                      [ IntrWriteMem ]>;
  // TODO stride, indexed
}

defm int_riscv_vstore : Vstore;

def int_riscv_vmv_x_s : Intrinsic< [ llvm_anyint_ty ],
                                 [ llvm_anyvector_ty ],
                                 [ IntrNoMem ] >;

def int_riscv_vfmv_f_s : Intrinsic< [ llvm_anyfloat_ty ],
                                  [ llvm_anyvector_ty ],
                                  [ IntrNoMem ]>;
} // TargetPrefix = "riscv"


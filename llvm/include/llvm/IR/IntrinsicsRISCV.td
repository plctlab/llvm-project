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


def llvm_nxv1i32_ty    : LLVMType<nxv1i32>;  // scalable 1 x i32
def llvm_nxv1f32_ty    : LLVMType<nxv1f32>;
def llvm_nxv8f32_ty    : LLVMType<nxv8f32>;


def llvm_fptr32_ty : LLVMPointerType<llvm_float_ty>;

let TargetPrefix = "riscv" in {

  // T @llvm.<name>.T.<p>(any*, T, T, T imm);
  class MaskedAtomicRMWFourArg<LLVMType itype>
      : Intrinsic<[itype], [llvm_anyptr_ty, itype, itype, itype],
                  [IntrArgMemOnly, NoCapture<0>, ImmArg<3>]>;
  // T @llvm.<name>.T.<p>(any*, T, T, T, T imm);
  class MaskedAtomicRMWFiveArg<LLVMType itype>
      : Intrinsic<[itype], [llvm_anyptr_ty, itype, itype, itype, itype],
                  [IntrArgMemOnly, NoCapture<0>, ImmArg<4>]>;

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

//===----------------------------------------------------------------------===//
// Vector extension

def int_riscv_vsetvl : Intrinsic<[llvm_anyint_ty],
                                 [llvm_anyint_ty, llvm_anyint_ty],
                                 [IntrNoMem]>;

def int_riscv_vadd : Intrinsic<[llvm_nxv1i32_ty],
                               [llvm_nxv1i32_ty, llvm_nxv1i32_ty],
                               [IntrNoMem]>;

def int_riscv_vsub : Intrinsic<[llvm_nxv1i32_ty],
                               [llvm_nxv1i32_ty, llvm_nxv1i32_ty],
                               [IntrNoMem]>;


def int_riscv_vmul : Intrinsic<[llvm_nxv1i32_ty],
                               [llvm_nxv1i32_ty, llvm_nxv1i32_ty],
                               [IntrNoMem]>;


def int_riscv_vand : Intrinsic<[llvm_nxv1i32_ty],
                               [llvm_nxv1i32_ty, llvm_nxv1i32_ty],
                               [IntrNoMem]>;


def int_riscv_vor : Intrinsic<[llvm_nxv1i32_ty],
                               [llvm_nxv1i32_ty, llvm_nxv1i32_ty],
                               [IntrNoMem]>;

def int_riscv_vxor : Intrinsic<[llvm_nxv1i32_ty],
                               [llvm_nxv1i32_ty, llvm_nxv1i32_ty],
                               [IntrNoMem]>;

def int_riscv_vle32_v_f32m1
    : Intrinsic<[llvm_nxv1f32_ty], [llvm_fptr32_ty], [IntrReadMem]>;

def int_riscv_vle32_v_f32m8
    : Intrinsic<[llvm_nxv8f32_ty], [llvm_fptr32_ty], [IntrReadMem]>;

def int_riscv_vse32_v_f32m1
    : Intrinsic<[], [llvm_nxv1f32_ty, llvm_fptr32_ty], [IntrWriteMem]>;

def int_riscv_vse32_v_f32m8
    : Intrinsic<[], [llvm_nxv8f32_ty, llvm_fptr32_ty], [IntrWriteMem]>;

def int_riscv_vfmacc_vf_f32m1
    : Intrinsic<[llvm_nxv1f32_ty],
                [llvm_nxv1f32_ty, llvm_float_ty, llvm_nxv1f32_ty],
                [IntrNoMem]>;

def int_riscv_vfmacc_vf_f32m8
    : Intrinsic<[llvm_nxv8f32_ty],
                [llvm_nxv8f32_ty, llvm_float_ty, llvm_nxv8f32_ty],
                [IntrNoMem]>;

def int_riscv_vfmv_f_s_f32m1_f32
    : Intrinsic<[llvm_float_ty],
                [llvm_nxv1f32_ty],
                [IntrNoMem]>;
	

def int_riscv_vmpopcnt : Intrinsic<[llvm_i32_ty],
                               [llvm_nxv1i32_ty],
                               [IntrNoMem]>;

def int_riscv_vmfirst : Intrinsic<[llvm_i32_ty],
                               [llvm_nxv1i32_ty],
                               [IntrNoMem]>;

} // TargetPrefix = "riscv"

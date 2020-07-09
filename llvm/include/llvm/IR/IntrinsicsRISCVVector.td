//===--- IntrinsicsRISCVVector.td - RISC-V Vector compiler interface-------===//
//
//  Part of the LLVM Project, under the Apache License v2.0 with LLVM
//  Exceptions. See https://llvm.org/LICENSE.txt for license information.
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

class RISCVIntrinsic<string name, list<string> proto, string props> {
  // Intrinsic's name, which may contain one or more of the following
  // format specifiers:
  //   %b -> Type of vector's elements , represented by a single character.
  //     i.e. i, u and f.
  // 
  //   %s -> SEW, e.g. 8, 16 and 32.
  // 
  //   %l -> LMUL, represented by characters in lower case.
  //      e.g. 1, 2, f2 and f4.
  //
  //   %L -> LMUL, represented by characters in upper case.
  //      e.g. 1, 2, F2 and F4.
  //
  //   %t -> Size of Tuple.
  //      e.g. 1, 2, 3, and 4.
  // 
  // The emitter will enumerate all possible values for those specifiers,
  // if occurred.
  string Name = name;

  // Types of returned value and parameters.
  //
  // Grammar for type specification:
  //
  // type_spec
  //   : 'v' { void }
  //   | 'q' { vector }
  //   | 'e' { dependent type }
  //   | '*' { llvm_anyptr_ty }
  //   | integer
  //   | floating_point
  //   ;
  // 
  // integer
  //   : 'ia' { llvm_anyint_ty }
  //   | 'i' ('8' | '16' | '32' | '64') { llvm_ixx_ty }
  //   ;
  // 
  // floating_point
  //   : 'fa' { llvm_anyfloat_ty }
  //   | 'f16' { llvm_half_ty }
  //   | 'f32' { llvm_float_ty }
  //   | 'f64' { llvm_double_ty }
  //   ;
  list<string> Prototype = proto;

  // If true, emit both masked and unmasked functions.
  bit MayMask = 0;

  // If true, add 'maskedoff' to the function's parameters.
  bit MaskedOff = 0;

  // If true, emit functions with and without 'vl'.
  bit HasVL = 0;

  // if not empty, use it as the function's body.
  code Body = [{}];

  // Properties of the intrinsic, specificied by a string of
  // characters from the following ones;
  //   n -> IntrNoMem
  //   r -> IntrReadMem
  //   w -> IntrWriteMem
  //   s -> IntrHasSideEffects
  string Properties = props;
}

def : RISCVIntrinsic<"vsetvl", ["ia", "ia", "ia"], "ns">;

def : RISCVIntrinsic<"vle%s_v_%b%sm%l", ["q", "*"], "r">;

def : RISCVIntrinsic<"vse%s_v_%b%sm%l", ["v", "*", "q"], "w">;

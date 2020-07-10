//===--- riscv_vector.td - RISC-V Vector compiler interface
//-----------------===//
//
//  Part of the LLVM Project, under the Apache License v2.0 with LLVM
//  Exceptions. See https://llvm.org/LICENSE.txt for license information.
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

class RISCVBuiltin<string name, list<string> prototype, string attrs> {
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
  //   : prefix* base_type postfix*
  //   ;
  // prefix
  //   : 'U' # unsigned
  //   ;
  // base_type
  //   : 'v' # void
  //   | 'b' # bool
  //   | 'c' # char
  //   | 's' # int16_t
  //   | 'i' # int32_t
  //   | 'l' # int64_t
  //   | 'h' # float16_t
  //   | 'f' # float
  //   | 'd' # double
  //   | 'z' # size_t
  //   | 'e' # type that depends on the context
  //   | 'q' # vector
  //   ;
  // postfix
  //   : '*' # pointer
  //   | '&' # reference
  //   | 'C' # const
  //   | 'D' # volatile
  //   ;
  list<string> Prototype = prototype;

  // Possible specifiers for attributes:
  //   n -> nothrow
  //   r -> noreturn
  //   U -> pure
  //   c -> const
  string Attributes = attrs;

  // If true, emit both masked and unmasked functions.
  bit MayMask = 0;

  // If true, add 'maskedoff' to the function's parameters.
  bit MaskedOff = 0;

  // If true, emit functions with and without 'vl'.
  bit HasVL = 0;

  // If not empty, use it as the function's body.
  code Body = [{}];

  // If true, emit declarations in riscv_vector.h.
  bit GenIntrinsic = 1;

  // If true, emit declarations in riscv_vector.inc.
  bit GenBuiltin = 1;
}

let GenBuiltin = 0 in {
  def : RISCVBuiltin<"vsetvl_e%sm%l", ["z", "z"], "n"> {
    let Body = [{ return __builtin_riscv_vsetvl(arg1, (_E%s | _M%L)); }];
  }
}

let GenIntrinsic = 0 in {
  def : RISCVBuiltin<"vsetvl", ["z", "z", "z"], "n">;
}

def : RISCVBuiltin<"vle%s_v_%b%sm%l", ["q", "eC*"], "n">;
def : RISCVBuiltin<"vse%s_v_%b%sm%l", ["v", "e*", "q"], "n">;

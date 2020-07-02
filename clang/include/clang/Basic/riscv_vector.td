//===--- riscv_vector.td - RISC-V Vector compiler interface
//-----------------===//
//
//  Part of the LLVM Project, under the Apache License v2.0 with LLVM
//  Exceptions. See https://llvm.org/LICENSE.txt for license information.
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

class RISCVBuiltin<string inst, list<string> prototype, string type_range,
                   string name = ""> {
  string Instruction = inst;
  list<string> Prototype = prototype;
  string TypeRange = type_range;
  bit MayMask = 0;
  bit MaskedOff = 0;
  bit HasVL = 0;
  bit HasSideEffects = 0;
  list<int> LMUL = [1, 2, 4, 8];
  string IntrinsicName = name;
  bit BasePolymorphic = 0;
  bit SEWPolymorphic = 0;
  bit LMULPolymorphic = 0;
  bit TuplePolymorphic = 0;
  code Body = [{}];
}

let SEWPolymorphic = 1, LMULPolymorphic = 1 in {
  def : RISCVBuiltin<"vsetvl_e%s%l", ["z", "z","z", "z"], "n"> {
      let Body = [{ return __builtin_riscv_vsetvl(arg1, (_E%s | _%L)); }];
  }
}

let BasePolymorphic = 1,
    SEWPolymorphic = 1, LMULPolymorphic = 1 in {
  def : RISCVBuiltin<"vle%s_v_%b%s%l", ["q", "eC*"], "n">;
  def : RISCVBuiltin<"vse%s_v_%b%s%l", ["v", "eC*", "q"], "n">;
}

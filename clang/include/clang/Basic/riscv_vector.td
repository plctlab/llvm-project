//===--- RISCVVector.td - RISC-V Vector compiler interface
//-----------------===//
//
//  Part of the LLVM Project, under the Apache License v2.0 with LLVM
//  Exceptions. See https://llvm.org/LICENSE.txt for license information.
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
/*
class RISCVBuiltin<string suffix, string prototype,
                 string type_range>
{
  string Suffix = suffix;
  string Prototype = prototype;
  string TypeRange = type_range;

  bit HasMask = 1;;
  bit HasVL = 1;
  bit HasMergeOperand = 1;
  bit HasSideEffects = 0;
  list<int> LMUL = [1, 2, 4, 8];
   
}

//===----------------------------------------------------------------------===//
// Builtin definitions.
//===----------------------------------------------------------------------===//
let HasVL = 0, HasMask = 0, HasSideEffects = 1, LMUL = [1] in
{
  def vsetvl : RISCVBuiltin<"", "iii", "n">;
}

let HasVL = 0, HasMask = 0, HasSideEffects = 1, LMUL = [2] in
{
  def vsetvl : RISCVBuiltin<"", "iii", "n">;
}

let HasVL = 0, HasMask = 0, HasSideEffects = 1, LMUL = [4] in
{
  def vsetvl : RISCVBuiltin<"", "iii", "n">;
}

let HasVL = 0, HasMask = 0, HasSideEffects = 1, LMUL = [8] in
{
  def vsetvl : RISCVBuiltin<"", "iii", "n">;
}

def vadd : RISCVBuiltin<"v", "vvv", "csil">;
def vsub : RISCVnBuiltin<"v", "vvv", "csil">;

let HasMergeOperand = 0 in
{
  def vfmadd : RISCVBuiltin<"v", "vvvv", "fd">;
  def vfmacc : RISCVBuiltin<"v", "vvvv", "fd">;
}
*/

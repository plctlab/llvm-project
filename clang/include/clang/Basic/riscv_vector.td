//==--- riscv_vector.td - RISC-V Vector Definitions -----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the TableGen definitions from which the RISC-V vector
// header file will be generated. It is also used to generate clang CodeGen
// snippet.
//
//===----------------------------------------------------------------------===//

class ScalarTypeInfo<string name, string value, int size> {
  // The type name used in intrinsic.
  string Name = name;
  // The type specifier string used in builtin function info, see the
  // description in Builtins.def.
  string Value = value;
  // The type size in bits.
  int Size = size;
}

class VectorTypeInfo<string name, string value, string bool_value,
                     ScalarTypeInfo elem_type, string mask> {
  // The type name used in intrinsic.
  string Name = name;
  // The type specifier string used in builtin function info, see the
  // description in Builtins.def.
  string Value = value;
  // The corresponding bool vector type specifier string.
  string BoolValue = bool_value;
  // Scalar element type.
  ScalarTypeInfo ElemType = elem_type;
  // Standard element width.
  int SEW = elem_type.Size;
  // The corresponding mask type.
  string Mask = mask;
  // The corresponding vector type with LMUL=1.
  string LMUL1Type = elem_type.Name#"m1";
}

class MaskTypeInfo<string name, string value> {
  // The type name used in intrinsic.
  string Name = name;
  // The type specifier string used in builtin function info, see the
  // description in Builtins.def.
  string Value = value;
}

class VectorTypeInfoPair<VectorTypeInfo first, VectorTypeInfo second> {
  VectorTypeInfo First = first;
  VectorTypeInfo Second = second;
}

// Helper class to get the corresponding unsigned integer vector type string.
class IntToUnsigned<VectorTypeInfo integer> {
  string Result =
    !cast<VectorTypeInfo>(!subst("i", "u", !cast<string>(integer))).Value;
}

class FloatToUnsigned<VectorTypeInfo float> {
  string Result = !cast<VectorTypeInfo>(!cond(
                        !eq(float.Name, "f16mf4") : "u16mf4",
                        !eq(float.Name, "f16mf2") : "u16mf2",
                        !eq(float.Name, "f16m1") : "u16m1",
                        !eq(float.Name, "f16m2") : "u16m2",
                        !eq(float.Name, "f16m4") : "u16m4",
                        !eq(float.Name, "f16m8") : "u16m8",
                        !eq(float.Name, "f32mf2") : "u32mf2",
                        !eq(float.Name, "f32m1") : "u32m1",
                        !eq(float.Name, "f32m2") : "u32m2",
                        !eq(float.Name, "f32m4") : "u32m4",
                        !eq(float.Name, "f32m8") : "u32m8",
                        !eq(float.Name, "f64m1") : "u64m1",
                        !eq(float.Name, "f64m2") : "u64m2",
                        !eq(float.Name, "f64m4") : "u64m4",
                        !eq(float.Name, "f64m8") : "u64m8")).Value;
}

class ComputeVectorNum<int shift_size, string lmul> {
  int VectorLength = !cond(!eq(lmul, "mf8") : !sra(64, 3),
                           !eq(lmul, "mf4") : !sra(64, 2),
                           !eq(lmul, "mf2") : !sra(64, 1),
                           !eq(lmul, "m1") : 64,
                           !eq(lmul, "m2") : !shl(64, 1),
                           !eq(lmul, "m4") : !shl(64, 2),
                           !eq(lmul, "m8") : !shl(64, 3));
  int Result = !sra(VectorLength, shift_size);
}

// Helper class to compute mask type.
class ComputeMaskType<int VectorNum> {
  string Result = !cond(!eq(VectorNum, 1) : "b64",
                     !eq(VectorNum, 2) : "b32",
                     !eq(VectorNum, 4) : "b16",
                     !eq(VectorNum, 8) : "b8",
                     !eq(VectorNum, 16) : "b4",
                     !eq(VectorNum, 32) : "b2",
                     !eq(VectorNum, 64) : "b1");
}

//===----------------------------------------------------------------------===//
// Define record sets used for iteration.
//===----------------------------------------------------------------------===//

defset list<ScalarTypeInfo> AllScalarType = {
  def i8 : ScalarTypeInfo<"i8", "Sc", 8>;
  def u8 : ScalarTypeInfo<"u8", "Uc", 8>;
  def i16 : ScalarTypeInfo<"i16", "s", 16>;
  def u16 : ScalarTypeInfo<"u16", "Us", 16>;
  def i32 : ScalarTypeInfo<"i32", "i", 32>;
  def u32 : ScalarTypeInfo<"u32", "Ui", 32>;
  def i64 : ScalarTypeInfo<"i64", "Wi", 64>;
  def u64 : ScalarTypeInfo<"u64", "UWi", 64>;
  def f16 : ScalarTypeInfo<"f16", "h", 16>;
  def f32 : ScalarTypeInfo<"f32", "f", 32>;
  def f64 : ScalarTypeInfo<"f64", "d", 64>;
}

defset list<MaskTypeInfo> AllMaskType = {
  def b1 : MaskTypeInfo<"b1", "q64b">;
  def b2 : MaskTypeInfo<"b2", "q32b">;
  def b4 : MaskTypeInfo<"b4", "q16b">;
  def b8 : MaskTypeInfo<"b8", "q8b">;
  def b16 : MaskTypeInfo<"b16", "q4b">;
  def b32 : MaskTypeInfo<"b32", "q2b">;
  def b64 : MaskTypeInfo<"b64", "q1b">;
}

defset list<VectorTypeInfo> AllVectorType = {
  defset list<VectorTypeInfo> AllIntVectorType = {
    defset list<VectorTypeInfo> AllSignedVectorType = {
      foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<3, lmul>.Result;
        defvar MaskType = ComputeMaskType<VectorNum>.Result;
        def i8#lmul : VectorTypeInfo<"i8"#lmul, "q"#VectorNum#"c",
                                     "q"#VectorNum#"b", i8, MaskType>;
      }
      foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<4, lmul>.Result;
        defvar MaskType = ComputeMaskType<VectorNum>.Result;
        def i16#lmul : VectorTypeInfo<"i16"#lmul, "q"#VectorNum#"s",
                                      "q"#VectorNum#"b", i16, MaskType>;
      }
      foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<5, lmul>.Result;
        defvar MaskType = ComputeMaskType<VectorNum>.Result;
        def i32#lmul : VectorTypeInfo<"i32"#lmul, "q"#VectorNum#"i",
                                      "q"#VectorNum#"b", i32, MaskType>;
      }
      foreach lmul = ["m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<6, lmul>.Result;
        defvar MaskType = ComputeMaskType<VectorNum>.Result;
        def i64#lmul : VectorTypeInfo<"i64"#lmul, "q"#VectorNum#"Wi",
                                      "q"#VectorNum#"b", i64, MaskType>;
      }
    } // defset list<VectorTypeInfo> AllSignedVectorType
    defset list<VectorTypeInfo> AllUnsignedVectorType = {
      foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<3, lmul>.Result;
        defvar MaskType = ComputeMaskType<VectorNum>.Result;
        def u8#lmul : VectorTypeInfo<"u8"#lmul, "q"#VectorNum#"Uc",
                                     "q"#VectorNum#"b", u8, MaskType>;
      }
      foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<4, lmul>.Result;
        defvar MaskType = ComputeMaskType<VectorNum>.Result;
        def u16#lmul : VectorTypeInfo<"u16"#lmul, "q"#VectorNum#"Us",
                                      "q"#VectorNum#"b", u16, MaskType>;
      }
      foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<5, lmul>.Result;
        defvar MaskType = ComputeMaskType<VectorNum>.Result;
        def u32#lmul : VectorTypeInfo<"u32"#lmul, "q"#VectorNum#"Ui",
                                      "q"#VectorNum#"b", u32, MaskType>;
      }
      foreach lmul = ["m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<6, lmul>.Result;
        defvar MaskType = ComputeMaskType<VectorNum>.Result;
        def u64#lmul : VectorTypeInfo<"u64"#lmul, "q"#VectorNum#"UWi",
                                      "q"#VectorNum#"b", u64, MaskType>;
      }
    } // defset list<VectorTypeInfo> AllUnsignedVectorType
  } // defset list<VectorTypeInfo> AllIntVectorType

  defset list<VectorTypeInfo> AllFloatVectorType = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      defvar VectorNum = ComputeVectorNum<4, lmul>.Result;
      defvar MaskType = ComputeMaskType<VectorNum>.Result;
      def f16#lmul : VectorTypeInfo<"f16"#lmul, "q"#VectorNum#"h",
                                    "q"#VectorNum#"b", f16, MaskType>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      defvar VectorNum = ComputeVectorNum<5, lmul>.Result;
      defvar MaskType = ComputeMaskType<VectorNum>.Result;
      def f32#lmul : VectorTypeInfo<"f32"#lmul, "q"#VectorNum#"f",
                                    "q"#VectorNum#"b", f32, MaskType>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      defvar VectorNum = ComputeVectorNum<6, lmul>.Result;
      defvar MaskType = ComputeMaskType<VectorNum>.Result;
      def f64#lmul : VectorTypeInfo<"f64"#lmul, "q"#VectorNum#"d",
                                    "q"#VectorNum#"b", f64, MaskType>;
    }
  } // defset list<VectorTypeInfo> AllFloatVectorType
} // defset list<VectorTypeInfo> AllVectorType

defset list<VectorTypeInfoPair> AllWideM1Vector = {
  defset list<VectorTypeInfoPair> AllWideM1SignedVector = {
    foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>(i8#lmul),
                               !cast<VectorTypeInfo>("i16m1")>;
    }
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>(i16#lmul),
                               !cast<VectorTypeInfo>("i32m1")>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>(i32#lmul),
                               !cast<VectorTypeInfo>("i64m1")>;
    }
  }

  defset list<VectorTypeInfoPair> AllWideM1UnsignedVector = {
    foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("u8"#lmul),
                               !cast<VectorTypeInfo>("u16m1")>;
    }
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("u16"#lmul),
                               !cast<VectorTypeInfo>("u32m1")>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in { 
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("u32"#lmul),
                               !cast<VectorTypeInfo>("u64m1")>;
    }
  }

  defset list<VectorTypeInfoPair> AllWideM1FloatVector = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("f16"#lmul),
                               !cast<VectorTypeInfo>("f32m1")>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("f32"#lmul),
                               !cast<VectorTypeInfo>("f64m1")>;
    }
  }
}

defset list<VectorTypeInfoPair> AllIntPairSEWx2 = {
  defset list<VectorTypeInfoPair> AllSignedPairSEWx2 = {
    def : VectorTypeInfoPair<i8mf8,  i16mf4>;
    def : VectorTypeInfoPair<i8mf4,  i16mf2>;
    def : VectorTypeInfoPair<i8mf2,  i16m1>;
    def : VectorTypeInfoPair<i8m1,   i16m2>;
    def : VectorTypeInfoPair<i8m2,   i16m4>;
    def : VectorTypeInfoPair<i8m4,   i16m8>;
    def : VectorTypeInfoPair<i16mf4, i32mf2>;
    def : VectorTypeInfoPair<i16mf2, i32m1>;
    def : VectorTypeInfoPair<i16m1,  i32m2>;
    def : VectorTypeInfoPair<i16m2,  i32m4>;
    def : VectorTypeInfoPair<i16m4,  i32m8>;
    def : VectorTypeInfoPair<i32mf2, i64m1>;
    def : VectorTypeInfoPair<i32m1,  i64m2>;
    def : VectorTypeInfoPair<i32m2,  i64m4>;
    def : VectorTypeInfoPair<i32m4,  i64m8>;
  }
  defset list<VectorTypeInfoPair> AllUnsignedPairSEWx2 = {
    def : VectorTypeInfoPair<u8mf8,  u16mf4>;
    def : VectorTypeInfoPair<u8mf4,  u16mf2>;
    def : VectorTypeInfoPair<u8mf2,  u16m1>;
    def : VectorTypeInfoPair<u8m1,   u16m2>;
    def : VectorTypeInfoPair<u8m2,   u16m4>;
    def : VectorTypeInfoPair<u8m4,   u16m8>;
    def : VectorTypeInfoPair<u16mf4, u32mf2>;
    def : VectorTypeInfoPair<u16mf2, u32m1>;
    def : VectorTypeInfoPair<u16m1,  u32m2>;
    def : VectorTypeInfoPair<u16m2,  u32m4>;
    def : VectorTypeInfoPair<u16m4,  u32m8>;
    def : VectorTypeInfoPair<u32mf2, u64m1>;
    def : VectorTypeInfoPair<u32m1,  u64m2>;
    def : VectorTypeInfoPair<u32m2,  u64m4>;
    def : VectorTypeInfoPair<u32m4,  u64m8>;
  }
} // defset list<VectorTypeInfoPair> AllIntPairSEWx2

defset list<VectorTypeInfoPair> AllIntPairSEWx4 = {
  defset list<VectorTypeInfoPair> AllSignedPairSEWx4 = {
    def : VectorTypeInfoPair<i8mf8,  i32mf2>;
    def : VectorTypeInfoPair<i8mf4,  i32m1>;
    def : VectorTypeInfoPair<i8mf2,  i32m2>;
    def : VectorTypeInfoPair<i8m1,   i32m4>;
    def : VectorTypeInfoPair<i8m2,   i32m8>;
    def : VectorTypeInfoPair<i16mf4, i64m1>;
    def : VectorTypeInfoPair<i16mf2, i64m2>;
    def : VectorTypeInfoPair<i16m1,  i64m4>;
    def : VectorTypeInfoPair<i16m2,  i64m8>;
  }
  defset list<VectorTypeInfoPair> AllUnsignedPairSEWx4 = {
    def : VectorTypeInfoPair<u8mf8,  u32mf2>;
    def : VectorTypeInfoPair<u8mf4,  u32m1>;
    def : VectorTypeInfoPair<u8mf2,  u32m2>;
    def : VectorTypeInfoPair<u8m1,   u32m4>;
    def : VectorTypeInfoPair<u8m2,   u32m8>;
    def : VectorTypeInfoPair<u16mf4, u64m1>;
    def : VectorTypeInfoPair<u16mf2, u64m2>;
    def : VectorTypeInfoPair<u16m1,  u64m4>;
    def : VectorTypeInfoPair<u16m2,  u64m8>;
  }
} // defset list<VectorTypeInfoPair> AllIntPairSEWx4

defset list<VectorTypeInfoPair> AllIntPairSEWx8 = {
  defset list<VectorTypeInfoPair> AllSignedPairSEWx8 = {
    def : VectorTypeInfoPair<i8mf8, i64m1>;
    def : VectorTypeInfoPair<i8mf4, i64m2>;
    def : VectorTypeInfoPair<i8mf2, i64m4>;
    def : VectorTypeInfoPair<i8m1,  i64m8>;
  }
  defset list<VectorTypeInfoPair> AllUnsignedPairSEWx8 = {
    def : VectorTypeInfoPair<u8mf8, u64m1>;
    def : VectorTypeInfoPair<u8mf4, u64m2>;
    def : VectorTypeInfoPair<u8mf2, u64m4>;
    def : VectorTypeInfoPair<u8m1,  u64m8>;
  }
} // defset list<VectorTypeInfoPair> AllIntPairSEWx8

defset list<VectorTypeInfoPair> AllIntPairSEW32 = {
  // 1:4
  def : VectorTypeInfoPair<u8mf8,  i32mf2>;
  def : VectorTypeInfoPair<u8mf4,  i32m1>;
  def : VectorTypeInfoPair<u8mf2,  i32m2>;
  def : VectorTypeInfoPair<u8m1,   i32m4>;
  def : VectorTypeInfoPair<u8m2,   i32m8>;
  // 1:2
  def : VectorTypeInfoPair<u16mf4, i32mf2>;
  def : VectorTypeInfoPair<u16mf2, i32m1>;
  def : VectorTypeInfoPair<u16m1,  i32m2>;
  def : VectorTypeInfoPair<u16m2,  i32m4>;
  def : VectorTypeInfoPair<u16m4,  i32m8>;
  // 1:1
  def : VectorTypeInfoPair<u32mf2, i32mf2>;
  def : VectorTypeInfoPair<u32m1,  i32m1>;
  def : VectorTypeInfoPair<u32m2,  i32m2>;
  def : VectorTypeInfoPair<u32m4,  i32m4>;
  def : VectorTypeInfoPair<u32m8,  i32m8>;
  // 2:1
  def : VectorTypeInfoPair<u64m1,  i32mf2>;
  def : VectorTypeInfoPair<u64m2,  i32m1>;
  def : VectorTypeInfoPair<u64m4,  i32m2>;
  def : VectorTypeInfoPair<u64m8,  i32m4>;
  // 1:4
  def : VectorTypeInfoPair<u8mf8,  u32mf2>;
  def : VectorTypeInfoPair<u8mf4,  u32m1>;
  def : VectorTypeInfoPair<u8mf2,  u32m2>;
  def : VectorTypeInfoPair<u8m1,   u32m4>;
  def : VectorTypeInfoPair<u8m2,   u32m8>;
  // 1:2
  def : VectorTypeInfoPair<u16mf4, u32mf2>;
  def : VectorTypeInfoPair<u16mf2, u32m1>;
  def : VectorTypeInfoPair<u16m1,  u32m2>;
  def : VectorTypeInfoPair<u16m2,  u32m4>;
  def : VectorTypeInfoPair<u16m4,  u32m8>;
  // 1:1
  def : VectorTypeInfoPair<u32mf2, u32mf2>;
  def : VectorTypeInfoPair<u32m1,  u32m1>;
  def : VectorTypeInfoPair<u32m2,  u32m2>;
  def : VectorTypeInfoPair<u32m4,  u32m4>;
  def : VectorTypeInfoPair<u32m8,  u32m8>;
  // 2:1
  def : VectorTypeInfoPair<u64m1,  u32mf2>;
  def : VectorTypeInfoPair<u64m2,  u32m1>;
  def : VectorTypeInfoPair<u64m4,  u32m2>;
  def : VectorTypeInfoPair<u64m8,  u32m4>;
}

defset list<VectorTypeInfoPair> AllFloatPairSEW32 = {
  // 1:4
  def : VectorTypeInfoPair<u8mf8,  f32mf2>;
  def : VectorTypeInfoPair<u8mf4,  f32m1>;
  def : VectorTypeInfoPair<u8mf2,  f32m2>;
  def : VectorTypeInfoPair<u8m1,   f32m4>;
  def : VectorTypeInfoPair<u8m2,   f32m8>;
  // 1:2
  def : VectorTypeInfoPair<u16mf4, f32mf2>;
  def : VectorTypeInfoPair<u16mf2, f32m1>;
  def : VectorTypeInfoPair<u16m1,  f32m2>;
  def : VectorTypeInfoPair<u16m2,  f32m4>;
  def : VectorTypeInfoPair<u16m4,  f32m8>;
  // 1:1
  def : VectorTypeInfoPair<u32mf2, f32mf2>;
  def : VectorTypeInfoPair<u32m1,  f32m1>;
  def : VectorTypeInfoPair<u32m2,  f32m2>;
  def : VectorTypeInfoPair<u32m4,  f32m4>;
  def : VectorTypeInfoPair<u32m8,  f32m8>;
  // 2:1
  def : VectorTypeInfoPair<u64m1,  f32mf2>;
  def : VectorTypeInfoPair<u64m2,  f32m1>;
  def : VectorTypeInfoPair<u64m4,  f32m2>;
  def : VectorTypeInfoPair<u64m8,  f32m4>;
}

defset list<VectorTypeInfoPair> AllIntPairSEW64 = {
  // 1:8
  def : VectorTypeInfoPair<u8mf8,  i64m1>;
  def : VectorTypeInfoPair<u8mf4,  i64m2>;
  def : VectorTypeInfoPair<u8mf2,  i64m4>;
  def : VectorTypeInfoPair<u8m1,   i64m8>;
  // 1:4
  def : VectorTypeInfoPair<u16mf4, i64m1>;
  def : VectorTypeInfoPair<u16mf2, i64m2>;
  def : VectorTypeInfoPair<u16m1,  i64m4>;
  def : VectorTypeInfoPair<u16m2,  i64m8>;
  // 1:2
  def : VectorTypeInfoPair<u32mf2, i64m1>;
  def : VectorTypeInfoPair<u32m1,  i64m2>;
  def : VectorTypeInfoPair<u32m2,  i64m4>;
  def : VectorTypeInfoPair<u32m4,  i64m8>;
  // 1:1
  def : VectorTypeInfoPair<u64m1,  i64m1>;
  def : VectorTypeInfoPair<u64m2,  i64m2>;
  def : VectorTypeInfoPair<u64m4,  i64m4>;
  def : VectorTypeInfoPair<u64m8,  i64m8>;
  // 1:8
  def : VectorTypeInfoPair<u8mf8,  u64m1>;
  def : VectorTypeInfoPair<u8mf4,  u64m2>;
  def : VectorTypeInfoPair<u8mf2,  u64m4>;
  def : VectorTypeInfoPair<u8m1,   u64m8>;
  // 1:4
  def : VectorTypeInfoPair<u16mf4, u64m1>;
  def : VectorTypeInfoPair<u16mf2, u64m2>;
  def : VectorTypeInfoPair<u16m1,  u64m4>;
  def : VectorTypeInfoPair<u16m2,  u64m8>;
  // 1:2
  def : VectorTypeInfoPair<u32mf2, u64m1>;
  def : VectorTypeInfoPair<u32m1,  u64m2>;
  def : VectorTypeInfoPair<u32m2,  u64m4>;
  def : VectorTypeInfoPair<u32m4,  u64m8>;
  // 1:1
  def : VectorTypeInfoPair<u64m1,  u64m1>;
  def : VectorTypeInfoPair<u64m2,  u64m2>;
  def : VectorTypeInfoPair<u64m4,  u64m4>;
  def : VectorTypeInfoPair<u64m8,  u64m8>;
}

defset list<VectorTypeInfoPair> AllFloatPairSEW64 = {
  // 1:8
  def : VectorTypeInfoPair<u8mf8,  f64m1>;
  def : VectorTypeInfoPair<u8mf4,  f64m2>;
  def : VectorTypeInfoPair<u8mf2,  f64m4>;
  def : VectorTypeInfoPair<u8m1,   f64m8>;
  // 1:4
  def : VectorTypeInfoPair<u16mf4, f64m1>;
  def : VectorTypeInfoPair<u16mf2, f64m2>;
  def : VectorTypeInfoPair<u16m1,  f64m4>;
  def : VectorTypeInfoPair<u16m2,  f64m8>;
  // 1:2
  def : VectorTypeInfoPair<u32mf2, f64m1>;
  def : VectorTypeInfoPair<u32m1,  f64m2>;
  def : VectorTypeInfoPair<u32m2,  f64m4>;
  def : VectorTypeInfoPair<u32m4,  f64m8>;
  // 1:1
  def : VectorTypeInfoPair<u64m1,  f64m1>;
  def : VectorTypeInfoPair<u64m2,  f64m2>;
  def : VectorTypeInfoPair<u64m4,  f64m4>;
  def : VectorTypeInfoPair<u64m8,  f64m8>;
}

defset list<VectorTypeInfoPair> AllIntFloatPair = {
  defset list<VectorTypeInfoPair> AllSignedFloatPair = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("i16"#lmul),
                               !cast<VectorTypeInfo>("f16"#lmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("i32"#lmul),
                               !cast<VectorTypeInfo>("f32"#lmul)>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("i64"#lmul),
                               !cast<VectorTypeInfo>("f64"#lmul)>;
    }
  }
  defset list<VectorTypeInfoPair> AllUnsignedFloatPair = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("u16"#lmul),
                               !cast<VectorTypeInfo>("f16"#lmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("u32"#lmul),
                               !cast<VectorTypeInfo>("f32"#lmul)>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def : VectorTypeInfoPair<!cast<VectorTypeInfo>("u64"#lmul),
                               !cast<VectorTypeInfo>("f64"#lmul)>;
    }
  }
} // defset list<VectorTypeInfoPair> AllIntFloatPair

defset list<VectorTypeInfoPair> AllFloatPairSEWx2 = {
  def : VectorTypeInfoPair<f16mf4, f32mf2>;
  def : VectorTypeInfoPair<f16mf2, f32m1>;
  def : VectorTypeInfoPair<f16m1,  f32m2>;
  def : VectorTypeInfoPair<f16m2,  f32m4>;
  def : VectorTypeInfoPair<f16m4,  f32m8>;
  def : VectorTypeInfoPair<f32mf2, f64m1>;
  def : VectorTypeInfoPair<f32m1,  f64m2>;
  def : VectorTypeInfoPair<f32m2,  f64m4>;
  def : VectorTypeInfoPair<f32m4,  f64m8>;
}

defset list<VectorTypeInfoPair> AllFloatIntPairSEWx2 = {
  defset list<VectorTypeInfoPair> AllFloatSignedPairSEWx2 = {
    def : VectorTypeInfoPair<f16mf4, i32mf2>;
    def : VectorTypeInfoPair<f16mf2, i32m1>;
    def : VectorTypeInfoPair<f16m1,  i32m2>;
    def : VectorTypeInfoPair<f16m2,  i32m4>;
    def : VectorTypeInfoPair<f16m4,  i32m8>;
    def : VectorTypeInfoPair<f32mf2, i64m1>;
    def : VectorTypeInfoPair<f32m1,  i64m2>;
    def : VectorTypeInfoPair<f32m2,  i64m4>;
    def : VectorTypeInfoPair<f32m4,  i64m8>;
  }
  defset list<VectorTypeInfoPair> AllFloatUnsignedPairSEWx2 = {
    def : VectorTypeInfoPair<f16mf4, u32mf2>;
    def : VectorTypeInfoPair<f16mf2, u32m1>;
    def : VectorTypeInfoPair<f16m1,  u32m2>;
    def : VectorTypeInfoPair<f16m2,  u32m4>;
    def : VectorTypeInfoPair<f16m4,  u32m8>;
    def : VectorTypeInfoPair<f32mf2, u64m1>;
    def : VectorTypeInfoPair<f32m1,  u64m2>;
    def : VectorTypeInfoPair<f32m2,  u64m4>;
    def : VectorTypeInfoPair<f32m4,  u64m8>;
  }
} // defset list<VectorTypeInfoPair> AllFloatIntPairSEWx2

defset list<VectorTypeInfoPair> AllIntFloatPairSEWx2 = {
  defset list<VectorTypeInfoPair> AllSignedFloatPairSEWx2 = {
    def : VectorTypeInfoPair<i16mf4, f32mf2>;
    def : VectorTypeInfoPair<i16mf2, f32m1>;
    def : VectorTypeInfoPair<i16m1,  f32m2>;
    def : VectorTypeInfoPair<i16m2,  f32m4>;
    def : VectorTypeInfoPair<i16m4,  f32m8>;
    def : VectorTypeInfoPair<i32mf2, f64m1>;
    def : VectorTypeInfoPair<i32m1,  f64m2>;
    def : VectorTypeInfoPair<i32m2,  f64m4>;
    def : VectorTypeInfoPair<i32m4,  f64m8>;
  }
  defset list<VectorTypeInfoPair> AllUnsignedFloatPairSEWx2 = {
    def : VectorTypeInfoPair<u16mf4, f32mf2>;
    def : VectorTypeInfoPair<u16mf2, f32m1>;
    def : VectorTypeInfoPair<u16m1,  f32m2>;
    def : VectorTypeInfoPair<u16m2,  f32m4>;
    def : VectorTypeInfoPair<u16m4,  f32m8>;
    def : VectorTypeInfoPair<u32mf2, f64m1>;
    def : VectorTypeInfoPair<u32m1,  f64m2>;
    def : VectorTypeInfoPair<u32m2,  f64m4>;
    def : VectorTypeInfoPair<u32m4,  f64m8>;
  }
 
  defset list<VectorTypeInfoPair> AllUnsignedSEW8FloatPairSEWx2 = {
    def : VectorTypeInfoPair<u8mf8, f16mf4>;
    def : VectorTypeInfoPair<u8mf4, f16mf2>;
    def : VectorTypeInfoPair<u8mf2, f16m1>;
    def : VectorTypeInfoPair<u8m1,  f16m2>;
    def : VectorTypeInfoPair<u8m2,  f16m4>;
    def : VectorTypeInfoPair<u8m4,  f16m8>;
  }
} // defset list<VectorTypeInfoPair> AllIntFloatPairSEWx2

defset list<VectorTypeInfoPair> AllUnsignedSEWFloatPairSEWx4 = {
  defset list<VectorTypeInfoPair> AllUnsignedSEW8FloatPairSEWx4 = {
    def : VectorTypeInfoPair<u8mf8, f32mf2>;
    def : VectorTypeInfoPair<u8mf4, f32m1>;
    def : VectorTypeInfoPair<u8mf2, f32m2>;
    def : VectorTypeInfoPair<u8m1,  f32m4>;
    def : VectorTypeInfoPair<u8m2,  f32m8>;
  }

  defset list<VectorTypeInfoPair> AllUnsignedSEW16FloatPairSEWx4 = {
    def : VectorTypeInfoPair<u16mf4, f64m1>;
    def : VectorTypeInfoPair<u16mf2, f64m2>;
    def : VectorTypeInfoPair<u16m1,  f64m4>;
    def : VectorTypeInfoPair<u16m2,  f64m8>;
  }
} // defset list<VectorTypeInfoPair> AllUnsignedSEWFloatPairSEWx4

defset list<VectorTypeInfoPair> AllIntSEW8FloatPairSEWx8 = {
  defset list<VectorTypeInfoPair> AllUnsignedSEW8FloatPairSEWx8 = {
    def : VectorTypeInfoPair<u8mf8, f64m1>;
    def : VectorTypeInfoPair<u8mf4, f64m2>;
    def : VectorTypeInfoPair<u8mf2, f64m4>;
    def : VectorTypeInfoPair<u8m1, f64m8>;
  }
} //defset list<VectorTypeInfoPair> AllIntSEW8FloatPairSEWx8

defset list<VectorTypeInfoPair> AllFloatSEWSignedPairSEWx2 = {
  defset list<VectorTypeInfoPair> AllFloatSEW16SignedPairSEWx2 = {
    def : VectorTypeInfoPair<f16mf4, u32mf2>;
    def : VectorTypeInfoPair<f16mf2, u32m1>;
    def : VectorTypeInfoPair<f16m1, u32m2>;
    def : VectorTypeInfoPair<f16m2, u32m4>;
    def : VectorTypeInfoPair<f16m4, u32m8>;
  }
  
  defset list<VectorTypeInfoPair> AllFloatSEW32SignedPairSEWx2 = {
    def : VectorTypeInfoPair<f32mf2, u64m1>;
    def : VectorTypeInfoPair<f32m1, u64m2>;
    def : VectorTypeInfoPair<f32m2, u64m4>;
    def : VectorTypeInfoPair<f32m4, u64m8>;
  }
} //defset list<VectorTypeInfoPair> AllFloatSEWSignedPairSEWx2

defset list<VectorTypeInfoPair> AllFloatSEWSignedPairSEWx4 = {
  defset list<VectorTypeInfoPair> AllFloatSEW16SignedPairSEWx4 = {
    def : VectorTypeInfoPair<f16mf4, u64m1>;
    def : VectorTypeInfoPair<f16mf2, u64m2>;
    def : VectorTypeInfoPair<f16m1, u64m4>;
    def : VectorTypeInfoPair<f16m2, u64m8>;
  }
}
//===----------------------------------------------------------------------===//
// Types
//===----------------------------------------------------------------------===//

class VType<string name, int elen, string lmul, int nf> {
  string VTypeName = name;
  int ELEN = elen;
  string LMUL = lmul;
  int NF = nf;
} 

// 8-bits
foreach I = ["mf8", "mf4", "mf2", "m1"]  in {
  foreach NF = [2, 3, 4, 5, 6, 7, 8] in {
    def "vint8"#I#"x"#NF#"_t" : VType<"vint8"#I#"x"#NF#"_t", 8, I, NF>;
    def "vuint8"#I#"x"#NF#"_t" : VType<"vuint8"#I#"x"#NF#"_t", 8, I, NF>;
  }
}

foreach I = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
  def "vint8"#I#"_t" : VType<"vint8"#I#"_t", 8, I, 1>;
  def "vuint8"#I#"_t" : VType<"vuint8"#I#"_t", 8, I, 1>;
}

// 16-bits
foreach I = ["mf4", "mf2", "m1"]  in {
  foreach NF = [2, 3, 4, 5, 6, 7, 8] in {
    def "vint16"#I#"x"#NF#"_t" : VType<"vint16"#I#"x"#NF#"_t", 16, I, NF>;
    def "vuint16"#I#"x"#NF#"_t" : VType<"vuint16"#I#"x"#NF#"_t", 16, I, NF>;
    def "vfloat16"#I#"x"#NF#"_t" : VType<"vfloat16"#I#"x"#NF#"_t", 16, I, NF>;
  }
}

foreach I = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
  def "vint16"#I#"_t" : VType<"vint16"#I#"_t", 16, I, 1>;
  def "vuint16"#I#"_t" : VType<"vuint16"#I#"_t", 16, I, 1>;
  def "vfloat16"#I#"_t" : VType<"vfloat16"#I#"_t", 16, I, 1>;
}

// 32-bits
foreach I = ["mf2", "m1"]  in {
  foreach NF = [2, 3, 4, 5, 6, 7, 8] in {
    def "vint32"#I#"x"#NF#"_t" : VType<"vint32"#I#"x"#NF#"_t", 32, I, NF>;
    def "vuint32"#I#"x"#NF#"_t" : VType<"vuint32"#I#"x"#NF#"_t", 32, I, NF>;
    def "vfloat32"#I#"x"#NF#"_t" : VType<"vfloat32"#I#"x"#NF#"_t", 32, I, NF>;
  }
}

foreach I = ["mf2", "m1", "m2", "m4", "m8"] in {
  def "vint32"#I#"_t" : VType<"vint32"#I#"_t", 32, I, 1>;
  def "vuint32"#I#"_t" : VType<"vuint32"#I#"_t", 32, I, 1>;
  def "vfloat32"#I#"_t" : VType<"vfloat32"#I#"_t", 32, I, 1>;
}

// 64-bits
foreach I = ["m1"]  in {
  foreach NF = [2, 3, 4, 5, 6, 7, 8] in {
    def "vint64"#I#"x"#NF#"_t" : VType<"vint64"#I#"x"#NF#"_t", 64, I, NF>;
    def "vuint64"#I#"x"#NF#"_t" : VType<"vuint64"#I#"x"#NF#"_t", 64, I, NF>;
    def "vfloat64"#I#"x"#NF#"_t" : VType<"vfloat64"#I#"x"#NF#"_t", 64, I, NF>;
  }
}

foreach I = ["m1", "m2", "m4", "m8"] in {
  def "vint64"#I#"_t" : VType<"vint64"#I#"_t", 64, I, 1>;
  def "vuint64"#I#"_t" : VType<"vuint64"#I#"_t", 64, I, 1>;
  def "vfloat64"#I#"_t" : VType<"vfloat64"#I#"_t", 64, I, 1>;
}


foreach I = [8, 16, 32, 64]  in {
  // segment load/store type of m2
  foreach NF = [2, 3, 4] in {
    def "vint"#I#"m2"#"x"#NF#"_t" : VType<"vint"#I#"m2"#"x"#NF#"_t", I, "m2", NF>;
    def "vuint"#I#"m2"#"x"#NF#"_t" : VType<"vuint"#I#"m2"#"x"#NF#"_t", I, "m2", NF>;
  }
  // segment load/store type of m4
  def "vint"#I#"m4"#"x2_t" : VType<"vint"#I#"m4"#"x2_t", I, "m4", 2>;
  def "vuint"#I#"m4"#"x2_t" : VType<"vuint"#I#"m4"#"x2_t", I, "m4", 2>;
}


//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

class Inst<string name, list<string> types, string inf, string suf,
           int is_mask, list<int> anytype_operands, code definition = ""> {
  string IntrinsicName = name;
  list<string> BuiltinStr = types;
  string Infix = inf;
  string Suffix = suf;
  // The list of indexes for the overload type. Use '-1' to refer to result
  // type, '0' to refer to the first argument type and so on. This is used
  // to generate clang builtin codegen snippet. The given indexes must be
  // consisted with llvm/include/llvm/IR/IntrinsicsRISCV.td. For an example,
  // the index list of
  //   class V_VX : Intrinsic<[ llvm_anyvector_ty ],
  //                          [ LLVMMatchType<0>, llvm_anyint_ty ],
  //                          [ IntrNoMem ]>;
  // should be:
  //   [-1, 1]
  list<int> AnyTypeOperands = anytype_operands;
  int Mask = is_mask;
  // If not empty, the emitter will use it to define the intrinsic function.
  // Otherwise, the emitter will generate intrinsic in the default way.
  code CustomDef = definition;
  // Should emit BUILTIN macro. Set to false if the intrinsic function can
  // be implemented by other existing builtin functions.
  bit ShouldEmitBuiltin = 1;
} 

// Unary operation.
multiclass UnaryMaskOff<string name, string result_type, string arg1_type,
                        string infix, string suffix, string mask_type,
                        list<int> anytype_operands,
                        list<int> mask_anytype_operands> {
  def NAME#infix#suffix : Inst<name, [result_type, arg1_type], infix, suffix,
                               0, anytype_operands>;
}

multiclass UnaryMaskOn<string name, string result_type, string arg1_type,
                       string infix, string suffix, string mask_type,
                       list<int> anytype_operands,
                       list<int> mask_anytype_operands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_type, mask_type,
                                       result_type, arg1_type], infix, suffix,
                                       1, mask_anytype_operands>;
}

multiclass Unary<string name, string result_type, string arg1_type,
                 string infix, string suffix, string mask_type,
                 list<int> anytype_operands, list<int> mask_anytype_operands>
  : UnaryMaskOff<name, result_type, arg1_type, infix, suffix, mask_type,
                 anytype_operands, mask_anytype_operands>,
    UnaryMaskOn<name, result_type, arg1_type, infix, suffix, mask_type,
                anytype_operands, mask_anytype_operands>;

multiclass UnaryNoMaskedOff<string name, string result_type, string arg1_type,
                            string infix, string suffix, string mask_type,
                            list<int> anytype_operands,
                            list<int> mask_anytype_operands>
  : UnaryMaskOff<name, result_type, arg1_type, infix, suffix, mask_type,
                 anytype_operands, mask_anytype_operands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_type, mask_type, arg1_type],
                                       infix, suffix, 1, mask_anytype_operands>;
}

// Binary operation.
multiclass BinaryMaskOff<string name, string result_type, string arg1_type, 
                         string arg2_type, string infix, string suffix,
                         string mask_type, list<int> anytype_operands,
                         list<int> mask_anytype_operands> {
  def NAME#infix#suffix : Inst<name, [result_type, arg1_type, arg2_type],
                               infix, suffix, 0, anytype_operands>;
}

multiclass BinaryMaskOn<string name, string result_type, string arg1_type, 
                        string arg2_type, string infix, string suffix,
                        string mask_type, list<int> anytype_operands,
                        list<int> mask_anytype_operands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_type, mask_type,
                                       result_type, arg1_type, arg2_type],
                                       infix, suffix, 1, mask_anytype_operands>;
}

multiclass Binary<string name, string result_type, string arg1_type, 
                  string arg2_type, string infix, string suffix,
                  string mask_type, list<int> anytype_operands,
                  list<int> mask_anytype_operands>
  : BinaryMaskOff<name, result_type, arg1_type, arg2_type, infix, suffix,
                  mask_type, anytype_operands, mask_anytype_operands>,
    BinaryMaskOn<name, result_type, arg1_type, arg2_type, infix, suffix,
                 mask_type, anytype_operands, mask_anytype_operands>;

// Ternary operation.
multiclass TernaryMaskOff<string name, string result_type, string arg1_type,
                          string arg2_type, string arg3_type, string infix,
                          string suffix, string mask_type,
                          list<int> anytype_operands,
                          list<int> mask_anytype_operands> {
  def NAME#infix#suffix : Inst<name, [result_type, arg1_type, arg2_type,
                               arg3_type], infix, suffix, 0, anytype_operands>;
}

multiclass TernaryMaskOn<string name, string result_type, string arg1_type,
                         string arg2_type, string arg3_type, string infix,
                         string suffix, string mask_type,
                         list<int> anytype_operands,
                         list<int> mask_anytype_operands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_type, mask_type, arg1_type,
                                       arg2_type, arg3_type],
                                       infix, suffix, 1, mask_anytype_operands>;
}

multiclass Ternary<string name, string result_type, string arg1_type,
                   string arg2_type, string arg3_type, string infix,
                   string suffix, string mask_type,
                   list<int> anytype_operands,
                   list<int> mask_anytype_operands>
  : TernaryMaskOff<name, result_type, arg1_type, arg2_type, arg3_type, infix,
                   suffix, mask_type, anytype_operands, mask_anytype_operands>,
    TernaryMaskOn<name, result_type, arg1_type, arg2_type, arg3_type, infix,
                  suffix, mask_type, anytype_operands, mask_anytype_operands>;

// vint*m*_t vop_v_v_i*m* (vint*m*_t src)
// vint*m*_t vop_v_x_i*m* (int*_t src)
multiclass int_unary_v_v_v_x {
  foreach I = AllIntVectorType in {
    defm NAME : UnaryMaskOff<NAME, I.Value, I.Value, "_v_v", I.Name, "",
                             [-1], []>;
    defm NAME : UnaryMaskOff<NAME, I.Value, I.ElemType.Value, "_v_x",
                             I.Name, "", [-1, 0], []>;
  }
}

// vuint*m*_t vop_m_u*m* (vbool*_t op1);
// vuint*m*_t vop_m_u*m*_m (vbool*_t mask, vuint*m*_t maskedoff, vbool*_t op1);
multiclass unsigned_unary_v_m {
  foreach I = AllUnsignedVectorType in {
    defm NAME : Unary<NAME, I.Value, I.BoolValue, "_m", I.Name, I.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
}

// unsigned long vop_m_b* (vbool*_t op1);
// unsigned long vop_m_b*_m (vbool*_t mask, vbool*_t op1);
multiclass unsgined_unary_x_m {
  foreach I = AllMaskType in {
    defm NAME : UnaryNoMaskedOff<NAME, "ULi", I.Value, "_m", I.Name, I.Value,
                                 [0], [0]>;
  }
}

// long vop_m_b* (vbool*_t op1);
// long vop_m_b*_m (vbool*_t mask, vbool*_t op1);
multiclass sgined_unary_x_m {
  foreach I = AllMaskType in {
    defm NAME : UnaryNoMaskedOff<NAME, "Li", I.Value, "_m", I.Name, I.Value,
                                 [0], [0]>;
  }
}

// vbool*_t vop_m_b* (vbool*_t op1);
// vbool*_t vop_m_b*_m (vbool*_t mask, vbool*_t maskedoff, vbool*_t op1);
multiclass bool_unary_m_m {
  foreach I = AllMaskType in {
    defm NAME : Unary<NAME, I.Value, I.Value, "_m", I.Name, I.Value,
                      [-1], [-1]>;
  }
}

// vint*m*_t vop_vx_i*m* (vint*m*_t op1, int*m*_t op2);
// vuint*m*_t vop_vx_i*m* (vuint*m*_t op1, uint*_t op2);
// vint*m*_t vop_vx_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                           vint*m*_t op1, int*m*_t op2);
// vuint*m*_t vop_vx_i*m*_m (vbool*_t mask, vuint*m*_t maskedoff,
//                           vuint*m*_t op1, uint*m*_t op2);
multiclass int_binary_v_vx {
  foreach I = AllIntVectorType in {
      defm NAME : Binary<NAME, I.Value, I.Value, I.ElemType.Value, "_vx",
                         I.Name, I.BoolValue, [-1, 1], [-1, 0, 3]>;
  }
}

// vint*m*_t vop_vv_i*m* (vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_vx_i*m* (vint*m*_t op1, int*_t op2);
// vint*m*_t vop_vv_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_vx_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, int*_t op2);
multiclass signed_binary_v_vv_vx {
  foreach I = AllSignedVectorType in {
    defm NAME : Binary<NAME, I.Value, I.Value, I.Value, "_vv", I.Name,
                       I.BoolValue, [-1], [-1, 0]>;
    defm NAME : Binary<NAME, I.Value, I.Value, I.ElemType.Value, "_vx",
                       I.Name, I.BoolValue, [-1, 1], [-1, 0, 3]>;
  }
}

// vuint*m*_t vop_vv_i*m* (vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vx_i*m* (vuint*m*_t op1, uint*_t op2);
// vuint*m*_t vop_vv_i*m*_m (vbool*_t mask, vuint*m*_t maskedoff,
//                           vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vx_i*m*_m (vbool*_t mask, vuint*m*_t maskedoff,
//                           vuint*m*_t op1, uint*_t op2);
multiclass unsigned_binary_v_vv_vx {
  foreach I = AllUnsignedVectorType in {
    defm NAME : Binary<NAME, I.Value, I.Value, I.Value, "_vv", I.Name,
                       I.BoolValue, [-1], [-1, 0]>;
    defm NAME : Binary<NAME, I.Value, I.Value, I.ElemType.Value, "_vx",
                       I.Name, I.BoolValue, [-1, 1], [-1, 0, 3]>;
  }
}

// Both signed and unsigned types.
multiclass int_binary_v_vv_vx : signed_binary_v_vv_vx, unsigned_binary_v_vv_vx;

// vint*m*_t vop_vv_i*m* (vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_vx_i*m* (vint*m*_t op1, uint8_t op2);
// vint*m*_t vop_vv_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_vx_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, uint8_t op2);
multiclass signed_binary_v_vv_vx_u8 {
  foreach I = AllSignedVectorType in {
    defm NAME : Binary<NAME, I.Value, I.Value, IntToUnsigned<I>.Result, "_vv",
                       I.Name, I.BoolValue, [-1], [-1, 0]>;
    defm NAME : Binary<NAME, I.Value, I.Value, "Uc", "_vx", I.Name,
                       I.BoolValue, [-1, 1], [-1, 0, 3]>;
  }
}

// vuint*m*_t vop_vv_i*m* (vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vx_i*m* (vuint*m*_t op1, uint8_t op2);
// vuint*m*_t vop_vv_i*m*_m (vbool*_t mask, vuint*m*_t maskedoff,
//                           vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vx_i*m*_m (vbool*_t mask, vuint*m*_t maskedoff,
//                           vuint*m*_t op1, uint8_t op2);
multiclass unsigned_binary_v_vv_vx_u8 {
  foreach I = AllUnsignedVectorType in {
    defm NAME : Binary<NAME, I.Value, I.Value, I.Value, "_vv", I.Name,
                       I.BoolValue, [-1], [-1, 0]>;
    defm NAME : Binary<NAME, I.Value, I.Value, "Uc", "_vx", I.Name,
                       I.BoolValue, [-1, 1], [-1, 0, 3]>;
  }
}

// vint*m*_t vop_vv_i*m* (vint*m*_t op1, vuint*m*_t op2);
// vint*m*_t vop_vv_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, vuint*m*_t op2);
multiclass all_binary_v_vv_vx_z {
  foreach I = AllIntVectorType in {
    defm NAME : Binary<NAME, I.Value, I.Value, IntToUnsigned<I>.Result,
                       "_vv", I.Name, I.BoolValue, [-1, 1], [-1, 0, 3]>;
    defm NAME : Binary<NAME, I.Value, I.Value, "z", "_vx", I.Name,
                       I.BoolValue, [-1, 1], [-1, 0, 3]>;
  }
  foreach I = AllFloatVectorType in {
    defm NAME : Binary<NAME, I.Value, I.Value, FloatToUnsigned<I>.Result,
                       "_vv", I.Name, I.BoolValue, [-1, 1], [-1, 0, 3]>;
    defm NAME : Binary<NAME, I.Value, I.Value, "z", "_vx", I.Name,
                       I.BoolValue, [-1, 1], [-1, 0, 3]>;
  }
}

// Both signed and unsigned types.
multiclass int_binary_v_vv_vx_u8 :
  signed_binary_v_vv_vx_u8, unsigned_binary_v_vv_vx_u8;

// vbool*_t vop_vx_i*m*_b* (vint*m*_t op1, int*_t op2);
// vbool*_t vop_vx_i*m*_b*_m (vbool*_t mask, vbool*_t maskedoff,
//                            vint*m*_t op1, int*_t op2);
multiclass signed_binary_m_vx {
  foreach I = AllSignedVectorType in {
    defm NAME : Binary<NAME, I.BoolValue, I.Value, I.ElemType.Value, "_vx",
                       I.Name#"_"#I.Mask, I.BoolValue,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

// vbool*_t vop_vx_u*m*_b* (vuint*m*_t op1, uint*_t op2);
// vbool*_t vop_vx_u*m*_b*_m (vbool*_t mask, vbool*_t maskedoff,
//                            vuint*m*_t op1, uint*_t op2);
multiclass unsigned_binary_m_vx {
  foreach I = AllUnsignedVectorType in {
    defm NAME : Binary<NAME, I.BoolValue, I.Value, I.ElemType.Value, "_vx",
                       I.Name#"_"#I.Mask, I.BoolValue,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

// vbool*_t vop_vv_i*m*_b* (vint*m*_t op1, vint*m*_t op2);
// vbool*_t vop_vx_i*m*_b* (vint*m*_t op1, int*_t op2);
// vbool*_t vop_vv_i*m*_b*_m (vbool*_t mask, vbool*_t maskedoff,
//                            vint*m*_t op1, vint*m*_t op2);
// vbool*_t vop_vx_i*m*_b*_m (vbool*_t mask, vbool*_t maskedoff,
//                            vint*m*_t op1, int*_t op2);
multiclass signed_binary_m_vv_vx {
  foreach I = AllSignedVectorType in {
    defm NAME : Binary<NAME, I.BoolValue, I.Value, I.Value, "_vv",
                       I.Name#"_"#I.Mask, I.BoolValue,
                       [-1, 0], [-1, 2, 3]>;
    defm NAME : Binary<NAME, I.BoolValue, I.Value, I.ElemType.Value, "_vx",
                       I.Name#"_"#I.Mask, I.BoolValue,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

// vbool*_t vop_vv_u*m*_b* (vuint*m*_t op1, vuint*m*_t op2);
// vbool*_t vop_vx_u*m*_b* (vuint*m*_t op1, uint*_t op2);
// vbool*_t vop_vv_u*m*_b*_m (vbool*_t mask, vbool*_t maskedoff,
//                            vuint*m*_t op1, vuint*m*_t op2);
// vbool*_t vop_vx_u*m*_b*_m (vbool*_t mask, vbool*_t maskedoff,
//                            vuint*m*_t op1, uint*_t op2);
multiclass unsigned_binary_m_vv_vx {
  foreach I = AllUnsignedVectorType in {
    defm NAME : Binary<NAME, I.BoolValue, I.Value, I.Value, "_vv",
                       I.Name#"_"#I.Mask, I.BoolValue,
                       [-1, 0], [-1, 2, 3]>;
    defm NAME : Binary<NAME, I.BoolValue, I.Value, I.ElemType.Value, "_vx",
                       I.Name#"_"#I.Mask, I.BoolValue,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

// Both signed and unsigned types.
multiclass int_binary_m_vv_vx : signed_binary_m_vv_vx, unsigned_binary_m_vv_vx;

// vint*m*_t vop_wv_i*m* (vint*m*_t op1, vuint*m*_t op2)
// vint*m*_t vop_wx_i*m* (vint*m*_t op1, uint8_t op2)
// vint*m*_t vop_wv_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, vuint*m*_t op2)
// vint*m*_t vop_wx_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, uint8_t op2)
multiclass signed_binary_v_wv_wx{
  foreach I = AllSignedPairSEWx2 in {
    defm NAME : Binary<NAME, I.First.Value, I.Second.Value,
                       I.First.Value, "_wv", I.First.Name,
                       I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;
            
    defm NAME : Binary<NAME, I.First.Value, I.Second.Value,
                       "Uc", "_wx",
                       I.First.Name, I.Second.BoolValue,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

// vuint*m*_t vop_wv_u*m* (vuint*m*_t op1, vuint*m*_t op2)
// vuint*m*_t vop_wx_u*m* (vuint*m*_t op1, uint8_t op2)
// vuint*m*_t vop_wv_u*m*_m (vbool*_t mask, vuint*m*_t maskedoff,
//                           vuint*m*_t op1, vuint*m*_t op2)
// vuint*m*_t vop_wx_u*m*_m (vbool*_t mask, vuint*m*_t maskedoff,
//                           vuint*m*_t op1, uint8_t op2)
multiclass unsigned_binary_v_wv_wx{
  foreach I = AllUnsignedPairSEWx2 in {
    defm NAME : Binary<NAME, I.First.Value, I.Second.Value,
                       I.First.Value, "_wv", I.First.Name,
                       I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;
            
    defm NAME : Binary<NAME, I.First.Value, I.Second.Value,
                       "Uc", "_wx",
                       I.First.Name, I.Second.BoolValue,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

// vint*m*_t vop_vv_i*m* (vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_vx_i*m* (vint*m*_t op1, int*_t op2);
// vint*m*_t vop_vv_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_vx_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, int*_t op2);
multiclass signed_binary_w_vv_vx {
  foreach I = AllSignedPairSEWx2 in {
    defm NAME : Binary<NAME, I.Second.Value, I.First.Value,
                       I.First.Value, "_vv", I.Second.Name,
                       I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;

    defm NAME : Binary<NAME, I.Second.Value, I.First.Value,
                       I.First.ElemType.Value, "_vx",
                       I.Second.Name, I.Second.BoolValue,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

// vint*m*_t vop_wv_i*m* (vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_wx_i*m* (vint*m*_t op1, int*_t op2);
// vint*m*_t vop_wv_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_wx_i*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                          vint*m*_t op1, int*_t op2);
multiclass signed_binary_w_wv_wx {
  foreach I = AllSignedPairSEWx2 in {
    defm NAME : Binary<NAME, I.Second.Value, I.Second.Value,
                       I.First.Value, "_wv", I.Second.Name,
                       I.Second.BoolValue, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : Binary<NAME, I.Second.Value, I.Second.Value,
                       I.First.ElemType.Value, "_wx",
                       I.Second.Name, I.Second.BoolValue,
                       [-1, 1], [-1, 0, 3]>;
  }
}

multiclass signed_binary_w_vv_vx_wv_wx :
  signed_binary_w_vv_vx, signed_binary_w_wv_wx;

// vuint*m*_t vop_vv_u*m* (vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vx_u*m* (vuint*m*_t op1, uint*_t op2);
// vuint*m*_t vop_vv_u*m*_m (vbool*_t mask, vuint*m*_t maskedoff,
//                           vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vx_u*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                           vuint*m*_t op1, uint*_t op2);
multiclass unsigned_binary_w_vv_vx {
  foreach I = AllUnsignedPairSEWx2 in {
    defm NAME : Binary<NAME, I.Second.Value, I.First.Value,
                       I.First.Value, "_vv", I.Second.Name,
                       I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;
    defm NAME : Binary<NAME, I.Second.Value, I.First.Value,
                       I.First.ElemType.Value, "_vx",
                       I.Second.Name, I.Second.BoolValue,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

// vuint*m*_t vop_wv_u*m* (vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_wx_u*m* (vuint*m*_t op1, uint*_t op2);
// vuint*m*_t vop_wv_u*m*_m (vbool*_t mask, vuint*m*_t maskedoff,
//                           vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_wx_u*m*_m (vbool*_t mask, vint*m*_t maskedoff,
//                           vuint*m*_t op1, uint*_t op2);
multiclass unsigned_binary_w_wv_wx {
  foreach I = AllUnsignedPairSEWx2 in {
    defm NAME : Binary<NAME, I.Second.Value, I.Second.Value,
                       I.First.Value, "_wv", I.Second.Name,
                       I.Second.BoolValue, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : Binary<NAME, I.Second.Value, I.Second.Value,
                       I.First.ElemType.Value, "_wx",
                       I.Second.Name, I.Second.BoolValue,
                       [-1, 1], [-1, 0, 3]>;
  }    
}

multiclass unsigned_binary_w_vv_vx_wv_wx :
  unsigned_binary_w_vv_vx, unsigned_binary_w_wv_wx;

// vbool*_t vop_mm_b* (vbool*_t op1, vbool*_t op2);
multiclass bool_binary_m_mm {
  foreach I = AllMaskType in {
    defm NAME : BinaryMaskOff<NAME, I.Value, I.Value, I.Value, "_mm",
                              I.Name, "", [-1], []>;
  }
}

// vint*m*_t vop_vvm_i*m* (vint*m*_t op1, vint*m*_t op2, vbool*_t carryin);
// vint*m*_t vop_vxm_i*m* (vint*m*_t op1, int*_t op2, vbool*_t carryin);
multiclass int_ternary_v_vvm_vxm {
  foreach I = AllIntVectorType in {
    defm NAME : TernaryMaskOff<NAME, I.Value, I.Value, I.Value, I.BoolValue,
                               "_vvm", I.Name, "", [-1, 2], []>;
    defm NAME : TernaryMaskOff<NAME, I.Value, I.Value, I.ElemType.Value,
                               I.BoolValue, "_vxm", I.Name, "", [-1, 1, 2], []>;
  }
}

// vint*m*_t vop_vv_i*m* (vint*m*_t acc, vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_vx_i*m* (vint*m*_t acc, int*_t op1, vint*m*_t op2);
// vint*m*_t vop_vv_i*m*_m (vbool*_t, vint*m*_t acc, vint*m*_t op1,
//                          vint*m*_t op2);
// vint*m*_t vop_vx_i*m*_m (vbool*_t, vint*m*_t acc, int*_t op1, vint*m*_t op2);
multiclass int_ternary_v_vx_vv {
  foreach I = AllIntVectorType in {
    defm NAME : Ternary<NAME, I.Value, I.Value, I.Value, I.Value, "_vv",
                        I.Name, I.BoolValue, [-1], [-1, 0]>;
    defm NAME : Ternary<NAME, I.Value, I.Value, I.ElemType.Value, I.Value,
                        "_vx", I.Name, I.BoolValue, [-1, 1], [-1, 0, 2]>;
  }
}

// vint*m*_t vop_vs_i*m*_i*m* (vint*m*_t dst, vint*m*_t vector,
//                             vint*m*_t scalar);
// vint*m*_t vop_vs_i*m*_i*m*_m (vbool*_t mask, vint*m*_t dst,
//                               vint*m*_t vector, vint*m*_t scalar);
multiclass int_ternary_v_vs {
  foreach I = AllIntVectorType in {
    defvar LMUL1Type = !cast<VectorTypeInfo>(I.LMUL1Type);
    defm NAME : Ternary<NAME, LMUL1Type.Value, LMUL1Type.Value, I.Value,
                        LMUL1Type.Value, "_vs",
                        I.Name#"_"#LMUL1Type.Name,
                        I.BoolValue, [-1, 1], [-1, 0, 2]>;
  }
}

// vint*m1_t vop_vs_i*m*_i*m1 (vint*m1_t dst, vint*m*_t vector,
//                             vint*m1_t scalar);
// vint*m1_t vop_vs_i*m*_i*m1_m (vbool*_t mask, vint*m1_t dst,
//                               vint*m*_t vector, vint*m1_t scalar);
multiclass signed_ternary_w_vs {
  foreach I = AllWideM1SignedVector in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.Value, I.Second.Value, "_vs",
                        I.First.Name#"_"#I.Second.Name,
                        I.First.BoolValue, [-1, 1], [-1, 0, 2]>;
  }
}

// vuint*m1_t vop_vs_u*m*_u*m1 (vuint*m1_t dst, vuint*m*_t vector,
//                              vuint*m1_t scalar);
// vuint*m1_t vop_vs_u*m*_u*m1_m (vbool*_t mask, vuint*m1_t dst,
//                                vuint*m*_t vector, vuint*m1_t scalar);
multiclass unsigned_ternary_w_vs {
  foreach I = AllWideM1UnsignedVector in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.Value, I.Second.Value, "_vs",
                        I.First.Name#"_"#I.Second.Name,
                        I.First.BoolValue, [-1, 1], [-1, 0, 2]>;
  }
}

// vint*m*_t vop_vv_i*m* (vint*m*_t acc, vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_vv_i*m*_m (vbool*_t mask, vint*m*_t acc, vint*m*_t op1,
//                          vint*m*_t op2);
multiclass signed_ternary_w_vv {
  foreach I = AllSignedPairSEWx2 in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.Value, I.First.Value, "_vv",
                        I.Second.Name, I.Second.BoolValue,
                        [-1, 1], [-1, 0, 2]>;
  }
}

// vint*m*_t vop_vx_i*m* (vint*m*_t acc, uint*_t op1, vint*m*_t op2);
// vint*m*_t vop_vx_i*m*_m (vbool*_t mask, vint*m*_t acc, uint*_t op1,
//                          vint*m*_t op2);
multiclass signed_ternary_w_vx {
  foreach I = AllSignedPairSEWx2 in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.ElemType.Value, I.First.Value,
                        "_vx", I.Second.Name, I.Second.BoolValue,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass signed_ternary_w_vv_vx : signed_ternary_w_vv, signed_ternary_w_vx;

// vuint*m*_t vop_vv_u*m* (vuint*m*_t acc, vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vx_u*m* (vuint*m*_t acc, uint*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vv_u*m*_m (vbool*_t mask, vuint*m*_t acc, vuint*m*_t op1,
//                           vuint*m*_t op2);
// vuint*m*_t vop_vx_u*m*_m (vbool*_t mask, vuint*m*_t acc, uint*_t op1,
//                           vuint*m*_t op2);
multiclass unsigned_ternary_w_vv_vx {
  foreach I = AllUnsignedPairSEWx2 in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.Value, I.First.Value, "_vv",
                        I.Second.Name, I.Second.BoolValue,
                        [-1, 1], [-1, 0, 2]>;
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.ElemType.Value, I.First.Value,
                        "_vx", I.Second.Name, I.Second.BoolValue,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

// vint*m*_t vop_vv_i*m* (vint*m*_t acc, vint*m*_t op1, vint*m*_t op2);
// vint*m*_t vop_vv_i*m*_m (vbool*_t mask, vint*m*_t acc, vint*m*_t op1,
//                          vint*m*_t op2);
multiclass signed_ternary_qw_vv {
  foreach I = AllSignedPairSEWx4 in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.Value, I.First.Value, "_vv",
                        I.Second.Name, I.Second.BoolValue,
                        [-1, 1], [-1, 0, 2]>;
  }
}

// vint*m*_t vop_vx_i*m* (vint*m*_t acc, uint*_t op1, vint*m*_t op2);
// vint*m*_t vop_vx_i*m*_m (vbool*_t mask, vint*m*_t acc, uint*_t op1,
//                          vint*m*_t op2);
multiclass signed_ternary_qw_vx {
  foreach I = AllSignedPairSEWx4 in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.ElemType.Value, I.First.Value,
                        "_vx", I.Second.Name, I.Second.BoolValue,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass signed_ternary_qw_vv_vx : signed_ternary_qw_vv, signed_ternary_qw_vx;

// vuint*m*_t vop_vv_u*m* (vuint*m*_t acc, vuint*m*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vx_u*m* (vuint*m*_t acc, uint*_t op1, vuint*m*_t op2);
// vuint*m*_t vop_vv_u*m*_m (vbool*_t mask, vuint*m*_t acc, vuint*m*_t op1,
//                           vuint*m*_t op2);
// vuint*m*_t vop_vx_u*m*_m (vbool*_t mask, vuint*m*_t acc, uint*_t op1,
//                           vuint*m*_t op2);
multiclass unsigned_ternary_qw_vv_vx {
  foreach I = AllUnsignedPairSEWx4 in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.Value, I.First.Value, "_vv",
                        I.Second.Name, I.Second.BoolValue,
                        [-1, 1], [-1, 0, 2]>;
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.ElemType.Value, I.First.Value,
                        "_vx", I.Second.Name, I.Second.BoolValue,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

// vint*m*_t vop_vm_i*m* (vbool*_t mask, vint*m*_t maskedoff, vint*m*_t src);
multiclass all_ternary_v_vm {
  foreach I = AllVectorType in {
    defm NAME : TernaryMaskOff<NAME, I.Value, I.BoolValue, I.Value, I.Value,
                               "_vm", I.Name, I.BoolValue, [-1, 0], []>;
  }
}

// vfloat*m*_t vop_v_f*m* (vfloat*m*_t op1);
// vfloat*m*_t vop_v_f*m*_m (vbool*_t mask, vfloat*m*_t maskedoff,
//                           vfloat*m*_t op1);
multiclass float_unary_v_v {
  foreach I = AllFloatVectorType in {
    defm NAME : Unary<NAME, I.Value, I.Value, "_v", I.Name, I.BoolValue,
                      [-1], [-1, 0]>;
  }
}

multiclass float_unary_v_va {
  foreach I = AllFloatVectorType in {
    defm NAME : Unary<NAME, I.Value, I.Value, "_v", I.Name, I.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
}

// vfloat*m*_t vop_v_f_f*m* (float*_t src);
multiclass float_unary_v_f {
  foreach I = AllFloatVectorType in {
    defm NAME : UnaryMaskOff<NAME, I.Value, I.ElemType.Value, "_v_f",
                             I.Name, "", [-1, 0], []>;
  }
}

// vfloat*m*_t vop_vv_f*m* (vfloat*m*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_vv_f*m*_m (vbool*_t mask, vfloat*m*_t maskedoff,
//                            vfloat*m*_t op1, vfloat*m*_t op2);
multiclass float_binary_v_vv {
  foreach I = AllFloatVectorType in {
    defm NAME : Binary<NAME, I.Value, I.Value, I.Value, "_vv",
                       I.Name, I.BoolValue, [-1], [-1, 0]>;
  }
}

// vfloat*m*_t vop_vf_f*m* (vfloat*m*_t op1, float*_t op2);
// vfloat*m*_t vop_vf_f*m*_m (vbool*_t mask, vfloat*m*_t maskedoff,
//                            vfloat*m*_t op1, float*_t op2);
multiclass float_binary_v_vf {
  foreach I = AllFloatVectorType in {
    defm NAME : Binary<NAME, I.Value, I.Value, I.ElemType.Value, "_vf",
                       I.Name, I.BoolValue, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass float_binary_v_vv_vf : float_binary_v_vv, float_binary_v_vf;

// vbool*_t vop_vv_f*m*_b* (vfloat*m*_t op1, vfloat*m*_t op2);
// vbool*_t vop_vv_f*m*_b*_m (vbool*_t mask, vbool*_t maskedoff,
//                            vfloat*m*_t op1, vfloat*m*_t op2);
multiclass float_binary_m_vv {
  foreach I = AllFloatVectorType in {
    defm NAME : Binary<NAME, I.BoolValue, I.Value, I.Value, "_vv",
                       I.Name#"_"#I.Mask, I.BoolValue,
                       [-1, 0], [-1, 2, 3]>;
  }
}

// vbool*_t vop_vf_f*m*_b* (vfloat*m*_t op1, float*_t op2);
// vbool*_t vop_vf_f*m*_b*_m (vbool*_t mask, vbool*_t maskedoff,
//                            vfloat*m*_t op1, float*_t op2);
multiclass float_binary_m_vf {
  foreach I = AllFloatVectorType in {
    defm NAME : Binary<NAME, I.BoolValue, I.Value, I.ElemType.Value, "_vf",
                       I.Name#"_"#I.Mask, I.BoolValue,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass float_binary_m_vv_vf : float_binary_m_vv, float_binary_m_vf;

// vfloat*m*_t vop_vv_f*m* (vfloat*m*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_vf_f*m* (vfloat*m*_t op1, float*_t op2);
// vfloat*m*_t vop_vv_f*m*_m (vbool*_t mask, vfloat*m*_t maskedoff,
//                            vfloat*m*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_vf_f*m*_m (vbool*_t mask, vfloat*m*_t maskedoff,
//                            vfloat*m*_t op1, float*_t op2);
multiclass float_binary_w_vv_vf {
  foreach I = AllFloatPairSEWx2 in {
    defm NAME : Binary<NAME, I.Second.Value, I.First.Value,
                       I.First.Value, "_vv", I.Second.Name,
                       I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;

    defm NAME : Binary<NAME, I.Second.Value, I.First.Value,
                       I.First.ElemType.Value, "_vf",
                       I.Second.Name, I.Second.BoolValue,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

// vfloat*m*_t vop_wv_f*m* (vfloat*m*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_wf_f*m* (vfloat*m*_t op1, float*_t op2);
// vfloat*m*_t vop_wv_f*m*_m (vbool*_t mask, vfloat*m*_t maskedoff,
//                            vfloat*m*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_wf_f*m*_m (vbool*_t mask, vfloat*m*_t maskedoff,
//                            vfloat*m*_t op1, float*_t op2);
multiclass float_binary_w_wv_wf {
  foreach I = AllFloatPairSEWx2 in {
    defm NAME : Binary<NAME, I.Second.Value, I.Second.Value,
                       I.First.Value, "_wv", I.Second.Name,
                       I.Second.BoolValue, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : Binary<NAME, I.Second.Value, I.Second.Value,
                       I.First.ElemType.Value, "_wf",
                       I.Second.Name, I.Second.BoolValue,
                       [-1, 1], [-1, 0, 3]>;
  }
}

multiclass float_binary_w_vv_vf_wv_wf :
  float_binary_w_vv_vf, float_binary_w_wv_wf;

// vfloat*m*_t vop_vs_f*m*_f*m* (vfloat*m*_t dst, vfloat*m*_t vector,
//                               vfloat*m*_t scalar);
// vfloat*m*_t vop_vs_f*m*_f*m*_m (vbool*_t mask, vfloat*m*_t dst,
//                                 vfloat*m*_t vector, vfloat*m*_t scalar);
multiclass float_ternary_v_vs {
  foreach I = AllFloatVectorType in {
    defvar LMUL1Type = !cast<VectorTypeInfo>(I.LMUL1Type);
    defm NAME : Ternary<NAME, LMUL1Type.Value, LMUL1Type.Value, I.Value,
                        LMUL1Type.Value, "_vs",
                        I.Name#"_"#LMUL1Type.Name, I.BoolValue,
                        [-1, 1], [-1, 0, 2]>;
  }
}

// vfloat*m*_t vop_vv_f*m* (vfloat*m*_t acc, vfloat*m*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_vf_f*m* (vfloat*m*_t acc, float*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_vv_f*m*_m (vbool*_t mask, vfloat*m*_t acc,
//                            vfloat*m*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_vf_f*m*_m (vbool*_t mask, vfloat*m*_t acc, float*_t op1,
//                            vfloat*m*_t op2);
multiclass float_ternary_v_vv_vf {
  foreach I = AllFloatVectorType in {
    defm NAME : Ternary<NAME, I.Value, I.Value, I.Value, I.Value, "_vv", I.Name,
                        I.BoolValue, [-1], [-1, 0]>;
    defm NAME : Ternary<NAME, I.Value, I.Value, I.ElemType.Value, I.Value,
                        "_vf", I.Name, I.BoolValue, [-1, 1], [-1, 0, 2]>;
  }
}

// vfloat*m*_t vop_vv_f*m* (vfloat*m*_t acc, vfloat*m*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_vf_f*m* (vfloat*m*_t acc, float*_t op1, vfloat*m*_t op2);
// vfloat*m*_t vop_vv_f*m*_m (vbool*_t mask, vfloat*m*_t acc, vfloat*m*_t op1,
//                            vfloat*m*_t op2);
// vfloat*m*_t vop_vf_f*m*_m (vbool*_t mask, vfloat*m*_t acc, float*_t op1,
//                            vfloat*m*_t op2);
multiclass float_ternary_w_vv_vf {
  foreach I = AllFloatPairSEWx2 in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.Value, I.First.Value, "_vv",
                        I.Second.Name, I.Second.BoolValue,
                        [-1, 1], [-1, 0, 2]>;
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.ElemType.Value, I.First.Value,
                        "_vf", I.Second.Name, I.Second.BoolValue,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

// vfloat*m1_t vop_vs_f*m*_f*m1 (vfloat*m1_t dst, vfloat*m*_t vector,
//                               vfloat*m1_t scalar);
// vfloat*m1_t vop_vs_f*m*_f*m1_m (vbool*_t mask, vfloat*m1_t dst,
//                                 vfloat*m*_t vector, vfloat*m1_t scalar);
multiclass float_ternary_w_vs {
  foreach I = AllWideM1FloatVector in {
    defm NAME : Ternary<NAME, I.Second.Value, I.Second.Value,
                        I.First.Value, I.Second.Value, "_vs",
                        I.First.Name#"_"#I.Second.Name,
                        I.Second.Mask, [-1, 1], [-1, 0, 2]>;
  }
}

// 6. Configuration-Setting Instructions
multiclass vsetvl {
  foreach suffix = ["e8mf8", "e8mf4", "e8mf2", "e8m1", "e8m2", "e8m4", "e8m8",
                    "e16mf4", "e16mf2", "e16m1", "e16m2", "e16m4", "e16m8",
                    "e32mf2", "e32m1", "e32m2", "e32m4", "e32m8",
                    "e64m1", "e64m2", "e64m4", "e64m8"] in {
    def NAME#suffix : Inst<"vsetvl", ["z", "z", "z"], "", suffix, 0, [-1]>;
  }
}
defm : vsetvl;

// 7. Vector Loads and Stores
multiclass load_store {
  foreach I = AllVectorType in {
    def "vle"#I.SEW#"_v"#I.Name : Inst<"vle"#I.SEW,
      [I.Value, I.ElemType.Value#"C*"], "_v", I.Name, 0, [-1, 0]>;
    def "vle"#I.SEW#"_v"#I.Name#"_mask" : Inst<"vle"#I.SEW,
      [I.Value, I.BoolValue, I.Value, I.ElemType.Value#"C*"], "_v", I.Name, 1, [-1, 0, 2]>;
    def "vse"#I.SEW#"_v"#I.Name : Inst<"vse"#I.SEW,
      ["v", I.ElemType.Value#"*", I.Value], "_v", I.Name, 0, [0, 1]>;
    def "vse"#I.SEW#"_v"#I.Name#"_mask" : Inst<"vse"#I.SEW,
      ["v", I.BoolValue, I.ElemType.Value#"C*", I.Value], "_v", I.Name, 1, [0, 1, 2]>;
    def "vlse"#I.SEW#"_v"#I.Name : Inst<"vlse"#I.SEW,
      [I.Value, I.ElemType.Value#"C*", "Y"], "_v", I.Name, 0, [-1, 0]>;
    def "vlse"#I.SEW#"_v"#I.Name#"_mask" : Inst<"vlse"#I.SEW,
      [I.Value, I.BoolValue, I.Value, I.ElemType.Value#"C*", "Y"], "_v", I.Name, 1, [-1, 0, 2]>;
    def "vsse"#I.SEW#"_v"#I.Name : Inst<"vsse"#I.SEW,
      ["v", I.ElemType.Value#"*", "Y", I.Value], "_v", I.Name, 0, [0, 2]>;
    def "vsse"#I.SEW#"_v"#I.Name#"_mask" : Inst<"vsse"#I.SEW,
      ["v", I.BoolValue, I.ElemType.Value#"*", "Y", I.Value], "_v", I.Name, 1, [0, 1, 2]>;
    // def "vlxei"#I.SEW#"_v"#I.Name : Inst<"vlxei"#I.SEW,
    //   [I.Value, I.ElemType.Value#"C*", !cast<VectorTypeInfo>(!subst("i", "u", !cast<string>(I))).Value],
    //    "_v", I.Name, 0, [-1, 0, 1]>;
    // def "vlxei"#I.SEW#"_v"#I.Name#"_mask" : Inst<"vlxei"#I.SEW,
    //   [I.Value, I.BoolValue, I.Value, I.ElemType.Value#"C*", !cast<VectorTypeInfo>(!subst("i", "u", !cast<string>(I))).Value],
    //    "_v", I.Name, 1, [-1, 0, 2, 3]>;
    // def "vsxei"#I.SEW#"_v"#I.Name : Inst<"vsxei"#I.SEW,
    //   ["v", I.ElemType.Value#"C*", !cast<VectorTypeInfo>(!subst("i", "u", !cast<string>(I))).Value, I.Value],
    //   "_v", I.Name, 0, [0, 2, 3]>;
    // def "vsxei"#I.SEW#"_v"#I.Name#"_mask" : Inst<"vsxei"#I.SEW,
    //   ["v", I.BoolValue, I.ElemType.Value#"C*", !cast<VectorTypeInfo>(!subst("i", "u", !cast<string>(I))).Value,
    //   I.Value], "_v", I.Name, 1, [0, 1, 2, 3]>;
  }

  foreach I = AllIntVectorType in {
    def "vlxei"#I.SEW#"_v"#I.Name : Inst<"vlxei"#I.SEW,
       [I.Value, I.ElemType.Value#"C*", !cast<VectorTypeInfo>(!subst("i", "u", !cast<string>(I))).Value],
        "_v", I.Name, 0, [-1, 0, 1]>;
  }
  
  foreach I = AllFloatVectorType in {
    def "vlxei"#I.SEW#"_v"#I.Name : Inst<"vlxei"#I.SEW,
       [I.Value, I.ElemType.Value#"C*", FloatToUnsigned<I>.Result],
        "_v", I.Name, 0, [-1, 0, 1]>;
  }
  
  foreach I = !listconcat(AllIntPairSEWx2, AllIntPairSEWx4, AllIntPairSEWx8, 
                          AllUnsignedSEW8FloatPairSEWx2, AllUnsignedSEWFloatPairSEWx4,
                          AllUnsignedSEW8FloatPairSEWx8, AllUnsignedFloatPairSEWx2) in {
    def "vlxei"#I.First.SEW#"_v_"#I.Second.Name
      : Inst<"vlxei"#I.First.SEW, [I.Second.Value,
             I.Second.ElemType.Value#"C*", I.First.Value],
             "_v", I.Second.Name, 0, [-1, 0, 1]>;
  }
  
  foreach I = !listconcat(AllSignedPairSEWx2, AllSignedPairSEWx4,
                          AllSignedPairSEWx8, AllFloatSEWSignedPairSEWx2,
                          AllFloatSEWSignedPairSEWx4, AllUnsignedPairSEWx4,
                          AllUnsignedPairSEWx8) in {
    def "vlxei"#I.Second.SEW#"_v_"#I.First.Name
      : Inst<"vlxei"#I.Second.SEW, [I.First.Value,
             I.First.ElemType.Value#"C*", !subst("i", "u", I.Second.Value)],
             "_v", I.First.Name, 0, [-1, 0, 1]>;
  } 
 
}
defm : load_store;

// 8. Vector AMO Operations (Zvamo)
multiclass vamo {
  foreach I = !listconcat(AllIntPairSEW32, AllIntPairSEW64, AllFloatPairSEW32,
                          AllFloatPairSEW64) in {
    def NAME#"ei"#I.First.SEW#"_v_"#I.Second.Name
      : Inst<NAME#"ei"#I.First.SEW, [I.Second.Value,
             I.Second.ElemType.Value#"C*", I.First.Value, I.Second.Value],
             "_v", I.Second.Name, 0, [-1, 0, 1]>;
    def NAME#"ei"#I.First.SEW#"_v_"#I.Second.Name#"_mask"
      : Inst<NAME#"ei"#I.First.SEW, [I.Second.Value, I.Second.BoolValue,
             I.Second.ElemType.Value#"C*", I.First.Value, I.Second.Value],
             "_v", I.Second.Name, 1, [-1, 0, 1, 2]>;
  }
}

defm vamoswap : vamo;
defm vamoadd : vamo;
defm vamoxor : vamo;
defm vamoand : vamo;
defm vamoor : vamo;
defm vamomin : vamo;
defm vamomax : vamo;
defm vamominu : vamo;
defm vamomaxu : vamo;

// 12.1. Vector Single-Width Integer Add and Subtract
defm vadd : int_binary_v_vv_vx;
defm vsub : int_binary_v_vv_vx;
defm vrsub : int_binary_v_vx;

// 12.2. Vector Widening Integer Add/Subtract
defm vwadd : signed_binary_w_vv_vx_wv_wx;
defm vwsub : signed_binary_w_vv_vx_wv_wx;
defm vwaddu : unsigned_binary_w_vv_vx_wv_wx;
defm vwsubu : unsigned_binary_w_vv_vx_wv_wx;

// 12.3. Vector Integer Extension
multiclass signed_unary_vfn {
  foreach I = AllSignedPairSEWx2 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_vf2",
                      I.Second.Name, I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;
  }
  foreach I = AllSignedPairSEWx4 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_vf4",
                      I.Second.Name, I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;
  }
  foreach I = AllSignedPairSEWx8 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_vf8",
                      I.Second.Name, I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;
  }
}

multiclass unsigned_unary_vfn {
  foreach I = AllUnsignedPairSEWx2 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_vf2",
                      I.Second.Name, I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;
  }
  foreach I = AllUnsignedPairSEWx4 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_vf4",
                      I.Second.Name, I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;
  }
  foreach I = AllUnsignedPairSEWx8 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_vf8",
                      I.Second.Name, I.Second.BoolValue, [-1, 0], [-1, 0, 2]>;
  }
}

defm vsext : signed_unary_vfn;
defm vzext : unsigned_unary_vfn;

// 12.4. Vector Integer Add-with-Carry/Subtract-with-Borrow Instructions
defm vadc : int_ternary_v_vvm_vxm;
defm vsbc : int_ternary_v_vvm_vxm;
// TODO:
// defm vmadc :
// defm vmsbc :

// 12.5. Vector Bitwise Logical Instructions
defm vand : int_binary_v_vv_vx;
defm vxor : int_binary_v_vv_vx;
defm vor : int_binary_v_vv_vx;
let ShouldEmitBuiltin = 0 in {
  foreach I = AllIntVectorType in {
    def "vnot_v"#I.Name : Inst<"vnot", [I.Value, I.Value], "_v",
                                     I.Name, 0, [-1],
                                     "vxor_vx_"#I.Name#"(ARG0, -1)">;
    def "vnot_v"#I.Name#"_mask" :
      Inst<"vnot", [I.Value, I.BoolValue, I.Value, I.Value], "_v",
           I.Name, 1, [-1], "vxor_vx_"#I.Name#"_m(ARG0, ARG1, ARG2, -1)">;
  }
}

// 12.6. Vector Single-Width Bit Shift Instructions
defm vsll : int_binary_v_vv_vx_u8;
defm vsrl : unsigned_binary_v_vv_vx_u8;
defm vsra : signed_binary_v_vv_vx_u8;

// 12.7. Vector Narrowing Integer Right Shift Instructions
defm vnsrl : unsigned_binary_v_wv_wx;
defm vnsra : signed_binary_v_wv_wx;

// 12.8. Vector Integer Comparison Instructions
defm vmseq : int_binary_m_vv_vx;
defm vmsne : int_binary_m_vv_vx;
defm vmslt : signed_binary_m_vv_vx;
defm vmsltu : unsigned_binary_m_vv_vx;
defm vmsle : signed_binary_m_vv_vx;
defm vmsleu : unsigned_binary_m_vv_vx;
defm vmsgt : signed_binary_m_vx;
defm vmsgtu : unsigned_binary_m_vx;
//defm vmsge : signed_binary_m_vv_vx;
// defm vmsgeu : unsigned_binary_m_vv_vx;
let ShouldEmitBuiltin = 0 in {
  foreach I = AllSignedVectorType in {
    def "vmsge_vv"#I.Name#"_"#I.Mask : Inst<"vmsge",
           [I.BoolValue, I.Value, I.Value], "_vv",
           I.Name#"_"#I.Mask, 0, [-1],
           "vmsle_vv_"#I.Name#"_"#I.Mask#"(ARG1, ARG0)">;

    def "vmsgt_vv"#I.Name#"_"#I.Mask : Inst<"vmsgt",
           [I.BoolValue, I.Value, I.Value], "_vv",
           I.Name#"_"#I.Mask, 0, [-1],
           "vmslt_vv_"#I.Name#"_"#I.Mask#"(ARG1, ARG0)">;
  }
  foreach I = AllUnsignedVectorType in {
    def "vmsgeu_vv"#I.Name#"_"#I.Mask : Inst<"vmsgeu",
           [I.BoolValue, I.Value, I.Value], "_vv",
           I.Name#"_"#I.Mask, 0, [-1],
           "vmsleu_vv_"#I.Name#"_"#I.Mask#"(ARG1, ARG0)">;

    def "vmsgtu_vv"#I.Name#"_"#I.Mask : Inst<"vmsgtu",
           [I.BoolValue, I.Value, I.Value], "_vv",
           I.Name#"_"#I.Mask, 0, [-1],
           "vmsltu_vv_"#I.Name#"_"#I.Mask#"(ARG1, ARG0)">;
  }
}

// 12.9. Vector Integer Min/Max Instructions
defm vmin : signed_binary_v_vv_vx;
defm vminu : unsigned_binary_v_vv_vx;
defm vmax : signed_binary_v_vv_vx;
defm vmaxu : unsigned_binary_v_vv_vx;

// 12.10. Vector Single-Width Integer Multiply Instructions
defm vmul : int_binary_v_vv_vx;
defm vmulh : signed_binary_v_vv_vx;
defm vmulhu : unsigned_binary_v_vv_vx;
defm vmulhsu : signed_binary_v_vv_vx;

// 12.11. Vector Integer Divide Instructions
defm vdiv : signed_binary_v_vv_vx;
defm vdivu : unsigned_binary_v_vv_vx;
defm vrem : signed_binary_v_vv_vx;
defm vremu : unsigned_binary_v_vv_vx;

// 12.12. Vector Widening Integer Multiply Instructions
defm vwmul : signed_binary_w_vv_vx;
defm vwmulu : unsigned_binary_w_vv_vx;
defm vwmulsu : signed_binary_w_vv_vx;

// 12.13. Vector Single-Width Integer Multiply-Add Instructions
defm vmacc : int_ternary_v_vx_vv;
defm vnmsac : int_ternary_v_vx_vv;
defm vmadd : int_ternary_v_vx_vv;
defm vnmsub : int_ternary_v_vx_vv;

// 12.14. Vector Widening Integer Multiply-Add Instructions
defm vwmacc : signed_ternary_w_vv_vx;
defm vwmaccu : unsigned_ternary_w_vv_vx;
defm vwmaccsu : signed_ternary_w_vv_vx;
defm vwmaccus : signed_ternary_w_vx;

// 12.15. Vector Quad-Widening Integer Multiply-Add Instructions (Extension Zvqmac)
defm vqmacc : signed_ternary_qw_vv_vx;
defm vqmaccu : unsigned_ternary_qw_vv_vx;
defm vqmaccsu : signed_ternary_qw_vv_vx;
defm vqmaccus : signed_ternary_qw_vx;

// 12.16. Vector Integer Merge Instructions
multiclass int_vmerge_vvm_vxm {
  foreach I = AllIntVectorType in {
    defm NAME : TernaryMaskOff<NAME, I.Value, I.BoolValue, I.Value, I.Value,
                               "_vvm", I.Name, "", [-1, 0], []>;
    defm NAME : TernaryMaskOff<NAME, I.Value, I.BoolValue, I.Value,
                               I.ElemType.Value, "_vxm", I.Name, "",
                               [-1, 0, 2], []>;
  }
}
defm vmerge : int_vmerge_vvm_vxm;

// 12.17. Vector Integer Move Instructions
defm vmv : int_unary_v_v_v_x;

// 13.1. Vector Single-Width Saturating Add and Subtract
defm vsadd : signed_binary_v_vv_vx;
defm vsaddu : unsigned_binary_v_vv_vx;
defm vssub : signed_binary_v_vv_vx;
defm vssubu : unsigned_binary_v_vv_vx;

// 13.2. Vector Single-Width Averaging Add and Subtract
defm vaadd : signed_binary_v_vv_vx;
defm vaaddu : unsigned_binary_v_vv_vx;
defm vasub : signed_binary_v_vv_vx;
defm vasubu : unsigned_binary_v_vv_vx; 

// 13.3. Vector Single-Width Fractional Multiply with Rounding and Saturation
defm vsmul : signed_binary_v_vv_vx;

// 13.4. Vector Single-Width Scaling Shift Instructions
defm vssrl : unsigned_binary_v_vv_vx_u8;
defm vssra : signed_binary_v_vv_vx_u8;

// 13.5. Vector Narrowing Fixed-Point Clip Instructions
defm vnclip : signed_binary_v_wv_wx;
defm vnclipu : unsigned_binary_v_wv_wx;

// 14.2. Vector Single-Width Floating-Point Add/Subtract Instructions
defm vfadd : float_binary_v_vv_vf;
defm vfsub : float_binary_v_vv_vf;
defm vfrsub : float_binary_v_vf;

// 14.3. Vector Widening Floating-Point Add/Subtract Instructions
defm vfwadd : float_binary_w_vv_vf_wv_wf;
defm vfwsub : float_binary_w_vv_vf_wv_wf;

// 14.4. Vector Single-Width Floating-Point Multiply/Divide Instructions
defm vfmul : float_binary_v_vv_vf;
defm vfdiv : float_binary_v_vv_vf;
defm vfrdiv : float_binary_v_vf;

// 14.5. Vector Widening Floating-Point Multiply
defm vfwmul : float_binary_w_vv_vf;

// 14.6. Vector Single-Width Floating-Point Fused Multiply-Add Instructions
defm vfmacc : float_ternary_v_vv_vf;
defm vfnmacc : float_ternary_v_vv_vf;
defm vfmsac : float_ternary_v_vv_vf;
defm vfmadd : float_ternary_v_vv_vf;
defm vfnmadd : float_ternary_v_vv_vf;
defm vfmsub : float_ternary_v_vv_vf;
defm vfnmsub : float_ternary_v_vv_vf;

// 14.7. Vector Widening Floating-Point Fused MultiplyAdd Instructions
defm vfwmacc : float_ternary_w_vv_vf;
defm vfwnmacc : float_ternary_w_vv_vf;
defm vfwmsac : float_ternary_w_vv_vf;
defm vfwnmsac : float_ternary_w_vv_vf;

// 14.8. Vector Floating-Point Square-Root Instruction
defm vfsqrt : float_unary_v_v;

// 14.9. Vector Floating-Point MIN/MAX Instructions
defm vfmin : float_binary_v_vv_vf;
defm vfmax : float_binary_v_vv_vf;

// 14.10. Vector Floating-Point Sign-Injection Instructions
defm vfsgnj : float_binary_v_vv_vf;
defm vfsgnjn : float_binary_v_vv_vf;
defm vfsgnjx : float_binary_v_vv_vf;

// 14.11. Vector Floating-Point Compare Instructions
defm vmfeq : float_binary_m_vv_vf;
defm vmfne : float_binary_m_vv_vf;
defm vmflt : float_binary_m_vv_vf;
defm vmfle : float_binary_m_vv_vf;
defm vmfgt : float_binary_m_vf;
defm vmfge : float_binary_m_vf;
let ShouldEmitBuiltin = 0 in {
  foreach I = AllFloatVectorType in {
    def "vmfge_vv"#I.Name#"_"#I.Mask : Inst<"vmfge",
           [I.BoolValue, I.Value, I.Value], "_vv",
           I.Name#"_"#I.Mask, 0, [-1],
           "vmfle_vv_"#I.Name#"_"#I.Mask#"(ARG1, ARG0)">;

    def "vmfgt_vv"#I.Name#"_"#I.Mask : Inst<"vmfgt",
           [I.BoolValue, I.Value, I.Value], "_vv",
           I.Name#"_"#I.Mask, 0, [-1],
           "vmflt_vv_"#I.Name#"_"#I.Mask#"(ARG1, ARG0)">;
  }
}

// 14.12. Vector Floating-Point Classify Instruction
defm vfclass : float_unary_v_va;

// 14.13. Vector Floating-Point Merge Instruction
multiclass float_vmerge_vvm {
  foreach I = AllFloatVectorType in {
    defm NAME : TernaryMaskOff<NAME, I.Value, I.BoolValue, I.Value, I.Value,
                               "_vvm", I.Name, "", [-1, 0], []>;
  }
}
defm vmerge : float_vmerge_vvm;
multiclass float_vmerge_vfm {
  foreach I = AllFloatVectorType in {
    defm NAME : TernaryMaskOff<NAME, I.Value, I.BoolValue, I.Value,
                               I.ElemType.Value, "_vfm", I.Name, "",
                               [-1, 0, 2], []>;
  }
}
defm vfmerge : float_vmerge_vfm;

// 14.14. Vector Floating-Point Move Instruction
defm vfmv : float_unary_v_f;

// 14.15. Single-Width Floating-Point/Integer TypeConvert Instructions
multiclass vfcvt {
  foreach I = AllSignedFloatPair in {
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value, "_x_f_v",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value, "_rtz_x_f_v",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_f_x_v",
                      I.Second.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
  foreach I = AllUnsignedFloatPair in {
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value, "_xu_f_v",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value, "_rtz_xu_f_v",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_f_xu_v",
                      I.Second.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
}
defm vfcvt : vfcvt;

// 14.16. Widening Floating-Point/Integer Type-Convert Instructions
multiclass vfwcvt {
  foreach I = AllFloatSignedPairSEWx2 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_x_f_v",
                      I.Second.Name, I.Second.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value,
                      "_rtz_x_f_v", I.Second.Name, I.Second.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
  foreach I = AllFloatUnsignedPairSEWx2 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_xu_f_v",
                      I.Second.Name, I.Second.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value,
                      "_rtz_xu_f_v", I.Second.Name, I.Second.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = AllSignedFloatPairSEWx2 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_f_x_v",
                      I.Second.Name, I.Second.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = AllUnsignedFloatPairSEWx2 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_f_xu_v",
                      I.Second.Name, I.Second.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
  
  foreach I = AllFloatPairSEWx2 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_f_f_v",
                      I.Second.Name, I.Second.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
}
defm vfwcvt : vfwcvt;

multiclass vwcvt {
  foreach I = AllSignedPairSEWx2 in {
    defm NAME : Unary<NAME, I.Second.Value, I.First.Value, "_x_x_v",
                      I.Second.Name, I.Second.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
}
defm vwcvt : vwcvt;

multiclass vwcvtu {
  foreach I = AllUnsignedPairSEWx2 in {
    defm NAME : Unary<NAME,  I.Second.Value, I.First.Value, "_x_x_v",
                      I.Second.Name, I.Second.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
}
defm vwcvtu : vwcvtu;

// 14.17. Narrowing Floating-Point/Integer Type-Convert Instructions
multiclass vfncvt {
  foreach I = AllSignedFloatPairSEWx2 in {
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value, "_x_f_w",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value,
                      "_rtz_x_f_w",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
  foreach I = AllUnsignedFloatPairSEWx2 in {
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value, "_xu_f_w",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value,
                      "_rtz_xu_f_w",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = AllFloatSignedPairSEWx2 in {
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value, "_f_x_w",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = AllFloatUnsignedPairSEWx2 in {
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value, "_f_xu_w",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = AllFloatPairSEWx2 in {
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value, "_f_f_w",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : Unary<NAME, I.First.Value, I.Second.Value,
                      "_rod_f_f_w",
                      I.First.Name, I.First.BoolValue,
                      [-1, 0], [-1, 0, 2]>;
  }
}
defm vfncvt : vfncvt;

// 15.1. Vector Single-Width Integer Reduction Instructions
defm vredsum : int_ternary_v_vs;
defm vredmax : int_ternary_v_vs;
defm vredmaxu : int_ternary_v_vs;
defm vredmin : int_ternary_v_vs;
defm vredminu : int_ternary_v_vs;
defm vredand : int_ternary_v_vs;
defm vredor : int_ternary_v_vs;
defm vredxor : int_ternary_v_vs;

// 15.2. Vector Widening Integer Reduction Instructions
defm vwredsum : signed_ternary_w_vs;
defm vwredsumu : unsigned_ternary_w_vs;

// 15.3. Vector Single-Width Floating-Point Reduction Instructions
defm vfredsum : float_ternary_v_vs;
defm vfredosum : float_ternary_v_vs;
defm vfredmax : float_ternary_v_vs;
defm vfredmin : float_ternary_v_vs;

// 15.4. Vector Widening Floating-Point Reduction Instructions
defm vfwredosum : signed_ternary_w_vs;
defm vfwredsum : signed_ternary_w_vs;

// 16.1. Vector Mask-Register Logical Instructions
defm vmand : bool_binary_m_mm;
defm vmnand : bool_binary_m_mm;
defm vmandnot : bool_binary_m_mm;
defm vmxor : bool_binary_m_mm;
defm vmor : bool_binary_m_mm;
defm vmnor : bool_binary_m_mm;
defm vmornot : bool_binary_m_mm;
defm vmxnor : bool_binary_m_mm;

// TODO:
// vmmv.m vd, vs => vmand.mm vd, vs, vs
// defm vmmv : ;
// vmclr.m vd => vmxor.mm vd, vd, vd
// defm vmclr : ;
// vmset.m vd => vmxnor.mm vd, vd, vd
// defm vmset : ;
// vmnot.m vd, vs => vmnand.mm vd, vs, vs
// defm vmnot : ;

// 16.2. Vector mask population count vpopc
defm vpopc : unsgined_unary_x_m;

// 16.3. vfirst find-first-set mask bit
defm vfirst : sgined_unary_x_m;

// 16.4. vmsbf.m set-before-first mask bit
defm vmsbf : bool_unary_m_m;

// 16.5. vmsif.m set-including-first mask bit
defm vmsif : bool_unary_m_m;

// 16.6. vmsof.m set-only-first mask bit
defm vmsof : bool_unary_m_m;

// 16.8. Vector Iota Instruction
defm viota : unsigned_unary_v_m;

// 16.9. Vector Element Index Instruction
// vuint*m*_t vop_v_u*m* ();
// vuint*m*_t vop_v_u*m*_m (vbool*_t mask, vuint*m*_t maskedoff);
foreach I = AllUnsignedVectorType in {
  def "vid_v_"#I.Name : Inst<"vid", [I.Value], "_v", I.Name, 0, [-1]>;
  def "vid_v_"#I.Name#"_m" : Inst<"vid", [I.Value, I.BoolValue, I.Value],
                                  "_v", I.Name, 1, [-1, 0]>;
}

// 17.1. Integer Scalar Move Instructions
multiclass vmv_x_s_s_x {
  foreach I = AllIntVectorType in {
    defm NAME : UnaryMaskOff<NAME, I.ElemType.Value, I.Value, "_x_s",
                             I.Name#"_"#I.ElemType.Name, "",
                             [-1, 0], []>;
    defm NAME : BinaryMaskOff<NAME, I.Value, I.Value, I.ElemType.Value, "_s_x",
                              I.Name, "",
                              [-1, 1], []>;
  }
}
defm vmv : vmv_x_s_s_x;

// 17.2. Floating-Point Scalar Move Instructions
multiclass vfmv_f_s_s_f {
  foreach I = AllFloatVectorType in {
    defm NAME : UnaryMaskOff<NAME, I.ElemType.Value, I.Value, "_f_s",
                             I.Name#"_"#I.ElemType.Name, "",
                             [-1, 0], []>;
    defm NAME : BinaryMaskOff<NAME, I.Value, I.Value, I.ElemType.Value, "_s_f",
                              I.Name, "",
                              [-1, 1], []>;
  }
}
defm vfmv : vfmv_f_s_s_f;

// 17.3.1. Vector Slideup Instructions
multiclass vslide {
  foreach I = AllVectorType in {
    defm NAME : Ternary<NAME, I.Value, I.Value, I.Value, "z", "_vx", I.Name,
                        I.BoolValue, [-1, 2], [-1, 0, 3]>;
  }
}
defm vslideup : vslide;

// 17.3.2. Vector Slidedown Instructions
defm vslidedown : vslide;

// 17.3.3. Vector Slide1up
defm vslide1up : int_binary_v_vx;
defm vfslide1up : float_binary_v_vf;

// 17.3.4. Vector Slide1down Instruction
defm vslide1down : int_binary_v_vx;
defm vfslide1down : float_binary_v_vf;

// 17.4. Vector Register Gather Instruction
defm vrgather : all_binary_v_vv_vx_z;

// 17.5. Vector Compress Instruction
defm vcompress : all_ternary_v_vm;

// 17.6. Whole Vector Register Move
// 19.3. Vector Integer Dot-Product Instruction
// 19.4. Vector Floating-Point Dot Product Instruction

// Reinterpret Cast Conversion Functions
multiclass reinterpret {
  foreach I = AllSignedVectorType in {
    defm NAME : UnaryMaskOff<NAME, I.Value, IntToUnsigned<I>.Result, "_v",
                             !subst("i", "u", I.Name)#"_"#I.Name,
                             "", [-1, 0], []>;
    defm NAME : UnaryMaskOff<NAME, IntToUnsigned<I>.Result, I.Value, "_v",
                             I.Name#"_"#!subst("i", "u", I.Name),
                             "", [-1, 0], []>; 
  }
  foreach I = AllIntFloatPair in {
    defm NAME : UnaryMaskOff<NAME, I.First.Value, I.Second.Value, "_v",
                             I.First.Name#"_"#I.Second.Name, "",
                             [-1, 0], []>;
    defm NAME : UnaryMaskOff<NAME, I.Second.Value, I.First.Value, "_v",
                             I.Second.Name#"_"#I.First.Name, "",
                             [-1, 0], []>;
  }

  defm NAME : UnaryMaskOff<NAME, i16mf4.Value, i8mf4.Value, "_v",
                           "i8mf4"#"_"#!cast<VectorTypeInfo>("i16mf4").Name,
                           "", [-1, 0], []>;
  foreach I = [i16mf2, i32mf2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i8mf2.Value, "_v",
                             i8mf2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i16m1, i32m1, i64m1] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i8m1.Value, "_v",
                             i8m1.Name#"_"#I.Name, "", [-1, 0], []>;
  }
  foreach I = [i16m2, i32m2, i64m2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i8m2.Value, "_v",
                             i8m2.Name#"_"#I.Name, "", [-1, 0], []>;
  }
  foreach I = [i16m4, i32m4, i64m4] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i8m4.Value, "_v",
                             i8m4.Name#"_"#I.Name, "", [-1, 0], []>;
  }
  foreach I = [i16m8, i32m8, i64m8] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i8m8.Value, "_v",
                             i8m8.Name#"_"#I.Name, "", [-1, 0], []>;
  }
  defm NAME : UnaryMaskOff<NAME, i8mf4.Value, i16mf4.Value, "_v",
                           "i16mf4"#"_"#!cast<VectorTypeInfo>("i8mf4").Name,
                           "", [-1, 0], []>;
  foreach I = [i8mf2, i32mf2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i16mf2.Value, "_v",
                             i16mf2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m1, i32m1, i64m1] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i16m1.Value, "_v",
                             i16m1.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m2, i32m2, i64m2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i16m2.Value, "_v",
                             i16m2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m4, i32m4, i64m4] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i16m4.Value, "_v",
                             i16m4.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m8, i32m8, i64m8] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i16m8.Value, "_v",
                             i16m8.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8mf2, i16mf2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i32mf2.Value, "_v",
                             i32mf2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m1, i16m1, i64m1] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i32m1.Value, "_v",
                             i32m1.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m2, i16m2, i64m2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i32m2.Value, "_v",
                             i32m2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m4, i16m4, i64m4] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i32m4.Value, "_v",
                             i32m4.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m8, i16m8, i64m8] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i32m8.Value, "_v",
                             i32m8.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }

  foreach I = [i8m1, i16m1, i32m1] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i64m1.Value, "_v",
                             i64m1.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m2, i16m2, i32m2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i64m2.Value, "_v",
                             i64m2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m4, i16m4, i32m4] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i64m4.Value, "_v",
                             i64m4.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m8, i16m8, i32m8] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, i64m8.Value, "_v",
                             i64m8.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  
  defm NAME : UnaryMaskOff<NAME, u16mf4.Value, u8mf4.Value, "_v",
                           "u8mf4"#"_"#!cast<VectorTypeInfo>("u16mf4").Name,
                           "", [-1, 0], []>;
  foreach I = [u16mf2, u32mf2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u8mf2.Value, "_v",
                             i8mf2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u16m1, u32m1, u64m1] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u8m1.Value, "_v",
                             u8m1.Name#"_"#I.Name, "", [-1, 0], []>;
  }
  foreach I = [u16m2, u32m2, u64m2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u8m2.Value, "_v",
                             u8m2.Name#"_"#I.Name, "", [-1, 0], []>;
  }
  foreach I = [u16m4, u32m4, u64m4] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u8m4.Value, "_v",
                             u8m4.Name#"_"#I.Name, "", [-1, 0], []>;
  }
  foreach I = [u16m8, u32m8, u64m8] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u8m8.Value, "_v",
                             u8m8.Name#"_"#I.Name, "", [-1, 0], []>;
  }
  defm NAME : UnaryMaskOff<NAME, u8mf4.Value, u16mf4.Value, "_v",
                           "u16mf4"#"_"#!cast<VectorTypeInfo>("u8mf4").Name,
                           "", [-1, 0], []>;
  foreach I = [u8mf2, u32mf2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u16mf2.Value, "_v",
                             u16mf2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m1, u32m1, u64m1] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u16m1.Value, "_v",
                             u16m1.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m2, u32m2, u64m2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u16m2.Value, "_v",
                             u16m2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m4, u32m4, u64m4] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u16m4.Value, "_v",
                             u16m4.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m8, u32m8, u64m8] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u16m8.Value, "_v",
                             u16m8.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8mf2, u16mf2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u32mf2.Value, "_v",
                             u32mf2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m1, u16m1, u64m1] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u32m1.Value, "_v",
                             u32m1.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m2, u16m2, u64m2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u32m2.Value, "_v",
                             u32m2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m4, u16m4, u64m4] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u32m4.Value, "_v",
                             u32m4.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m8, u16m8, u64m8] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u32m8.Value, "_v",
                             u32m8.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }

  foreach I = [u8m1, u16m1, u32m1] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u64m1.Value, "_v",
                             u64m1.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m2, u16m2, u32m2] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u64m2.Value, "_v",
                             u64m2.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m4, u16m4, u32m4] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u64m4.Value, "_v",
                             u64m4.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m8, u16m8, u32m8] in {
    defm NAME : UnaryMaskOff<NAME, I.Value, u64m8.Value, "_v",
                             u64m8.Name#"_"#I.Name, "",
                             [-1, 0], []>;
  }
}
defm vreinterpret : reinterpret;

// Vector Initialization Functions
foreach I = AllVectorType in {
  def "vundefined_"#I.Name : Inst<"vundefined", [I.Value], "", I.Name, 0, [0]>;
}

let ShouldEmitBuiltin = 0 in {
  foreach I = AllIntVectorType in {
    def "vzero_"#I.Name : Inst<"vzero", [""], "", I.Name, 0, [-1],
                               "vmv_v_x_"#I.Name#"(0)">;
  }
  foreach I = AllFloatVectorType in {
    def "vzero_"#I.Name : Inst<"vzero", [""], "", I.Name, 0, [-1],
                               "vfmv_v_f_"#I.Name#"(0)">;
  }
}

class ScalarInfo<string TypeName, string TypeStr> {
  string Type = TypeName;
  string Str = TypeStr;
}

class VectorInfo<string TypeStr, string MStr, ScalarInfo Sca, string Suf,
                 int Sew, string BType, string M1Type> {
  string Str = TypeStr;
  string TypeSuffix = Suf;
  string MaskStr = MStr;
  int SEW = Sew;
  ScalarInfo ScalarType = Sca;
  string BoolType = BType;
  string Lmul1Type = M1Type;
}

class MaskInfo<string TypeStr, string Suf> {
  string Str = TypeStr;
  string TypeSuffix = Suf;
}

class WideVectorInfo<VectorInfo Origin, VectorInfo Wide> {
  VectorInfo WideVector = Wide;
  VectorInfo OriginVector = Origin;
}

class IntToFloat<VectorInfo integer, VectorInfo float> {
  VectorInfo Integer = integer;
  VectorInfo Float = float;
}

class IntToUnsigned<VectorInfo Integer> {
  string Result =
    !cast<VectorInfo>(!subst("i", "u", !cast<string>(Integer))).Str;
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

class ComputeWideLmul<string lmul> {
  string Result = !cond(!eq(lmul, "mf8") : "mf4",
                        !eq(lmul, "mf4") : "mf2",
                        !eq(lmul, "mf2") : "m1",
                        !eq(lmul, "m1") : "m2",
                        !eq(lmul, "m2") : "m4",
                        !eq(lmul, "m4") : "m8");
}

class ComputeBoolType<int VectorNum> {
  string Result = !cond(!eq(VectorNum, 1) : "b64",
                     !eq(VectorNum, 2) : "b32",
                     !eq(VectorNum, 4) : "b16",
                     !eq(VectorNum, 8) : "b8",
                     !eq(VectorNum, 16) : "b4",
                     !eq(VectorNum, 32) : "b2",
                     !eq(VectorNum, 64) : "b1");
}

class ComputeQuadWideLmul<string lmul> {
  string Result = !cond(!eq(lmul, "mf8") : "mf2",
                        !eq(lmul, "mf4") : "m1",
                        !eq(lmul, "mf2") : "m2",
                        !eq(lmul, "m1") : "m4",
                        !eq(lmul, "m2") : "m8");
}

defset list<ScalarInfo> AllScalarType = {
  def i8 : ScalarInfo<"i8", "Sc">;
  def u8 : ScalarInfo<"u8", "Uc">;
  def i16 : ScalarInfo<"i16", "s">;
  def u16 : ScalarInfo<"u16", "Us">;
  def i32 : ScalarInfo<"i32", "i">;
  def u32 : ScalarInfo<"u32", "Ui">;
  def i64 : ScalarInfo<"i64", "Wi">;
  def u64 : ScalarInfo<"u64", "UWi">;
  def f16 : ScalarInfo<"f16", "h">;
  def f32 : ScalarInfo<"f32", "f">;
  def f64 : ScalarInfo<"f64", "d">;
}

defset list<MaskInfo> AllMaskType = {
  def b1 : MaskInfo<"q64b", "b1">;
  def b2 : MaskInfo<"q32b", "b2">;
  def b4 : MaskInfo<"q16b", "b4">;
  def b8 : MaskInfo<"q8b", "b8">;
  def b16 : MaskInfo<"q4b", "b16">;
  def b32 : MaskInfo<"q2b", "b32">;
  def b64 : MaskInfo<"q1b", "b64">;
}

defset list<VectorInfo> AllVector = {
  defset list<VectorInfo> AllIntegerVectorType = {
    defset list<VectorInfo> AllSignedVectorType = {
      foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<3, lmul>.Result;
        defvar BoolType = ComputeBoolType<VectorNum>.Result;
        def i8#lmul : VectorInfo<"q"#VectorNum#"c", "q"#VectorNum#"b", i8,
                                 "i8"#lmul, 8, BoolType, "i8m1">;
      }
      foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<4, lmul>.Result;
        defvar BoolType = ComputeBoolType<VectorNum>.Result;
        def i16#lmul : VectorInfo<"q"#VectorNum#"s", "q"#VectorNum#"b", i16,
                                  "i16"#lmul, 16, BoolType, "i16m1">;
      }
      foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<5, lmul>.Result;
        defvar BoolType = ComputeBoolType<VectorNum>.Result;
        def i32#lmul : VectorInfo<"q"#VectorNum#"i", "q"#VectorNum#"b", i32,
                                  "i32"#lmul, 32, BoolType, "i32m1">;
      }
      foreach lmul = ["m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<6, lmul>.Result;
        defvar BoolType = ComputeBoolType<VectorNum>.Result;
        def i64#lmul : VectorInfo<"q"#VectorNum#"Wi", "q"#VectorNum#"b", i64,
                                  "i64"#lmul, 64, BoolType, "i64m1">;
      }
    } // defset list<VectorInfo> AllSignedVectorType
    defset list<VectorInfo> AllUnsignedVectorType = {
      foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<3, lmul>.Result;
        defvar BoolType = ComputeBoolType<VectorNum>.Result;
        def u8#lmul : VectorInfo<"q"#VectorNum#"Uc", "q"#VectorNum#"b", u8,
                                 "u8"#lmul, 8, BoolType, "u8m1">;
      }
      foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<4, lmul>.Result;
        defvar BoolType = ComputeBoolType<VectorNum>.Result;
        def u16#lmul : VectorInfo<"q"#VectorNum#"Us", "q"#VectorNum#"b", u16,
                                  "u16"#lmul, 16, BoolType, "u16m1">;
      }
      foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<5, lmul>.Result;
        defvar BoolType = ComputeBoolType<VectorNum>.Result;
        def u32#lmul : VectorInfo<"q"#VectorNum#"Ui", "q"#VectorNum#"b", u32,
                                  "u32"#lmul, 32, BoolType, "u32m1">;
      }
      foreach lmul = ["m1", "m2", "m4", "m8"] in {
        defvar VectorNum = ComputeVectorNum<6, lmul>.Result;
        defvar BoolType = ComputeBoolType<VectorNum>.Result;
        def u64#lmul : VectorInfo<"q"#VectorNum#"UWi", "q"#VectorNum#"b", u64,
                                  "u64"#lmul, 64, BoolType, "u64m1">;
      }
    } // defset list<VectorInfo> AllUnsignedVectorType
  } // defset list<VectorInfo> AllIntegerVectorType

  defset list<VectorInfo> AllFloatVectorType = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      defvar VectorNum = ComputeVectorNum<4, lmul>.Result;
      defvar BoolType = ComputeBoolType<VectorNum>.Result;
      def f16#lmul : VectorInfo<"q"#VectorNum#"h", "q"#VectorNum#"b", f16,
                                "f16"#lmul, 16, BoolType, "f16m1">;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      defvar VectorNum = ComputeVectorNum<5, lmul>.Result;
      defvar BoolType = ComputeBoolType<VectorNum>.Result;
      def f32#lmul : VectorInfo<"q"#VectorNum#"f", "q"#VectorNum#"b", f32,
                                "f32"#lmul, 32, BoolType, "f32m1">;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      defvar VectorNum = ComputeVectorNum<6, lmul>.Result;
      defvar BoolType = ComputeBoolType<VectorNum>.Result;
      def f64#lmul : VectorInfo<"q"#VectorNum#"d", "q"#VectorNum#"b", f64,
                                "f64"#lmul, 64, BoolType, "f64m1">;
    }
  } // defset list<VectorInfo> AllFloatVectorType
} // defset list<VectorInfo> AllVector

defset list<WideVectorInfo> AllWideVector = {
  defset list<WideVectorInfo> AllWideIntegerVector = {
    foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def wi8#lmul : WideVectorInfo<!cast<VectorInfo>(i8#lmul),
                                    !cast<VectorInfo>(i16#WideLmul)>; 
    }
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def wi16#lmul : WideVectorInfo<!cast<VectorInfo>(i16#lmul),
                                     !cast<VectorInfo>(i32#WideLmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def wi32#lmul : WideVectorInfo<!cast<VectorInfo>(i32#lmul),
                                     !cast<VectorInfo>(i64#WideLmul)>;
    }
  }

  defset list<WideVectorInfo> AllWideUnsignedVector = {
    foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def wu8#lmul : WideVectorInfo<!cast<VectorInfo>("u8"#lmul),
                                    !cast<VectorInfo>("u16"#WideLmul)>;
    }
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def wu16#lmul : WideVectorInfo<!cast<VectorInfo>("u16"#lmul),
                                     !cast<VectorInfo>("u32"#WideLmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in { 
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def wu32#lmul : WideVectorInfo<!cast<VectorInfo>("u32"#lmul),
                                     !cast<VectorInfo>("u64"#WideLmul)>;
    }
  }

  defset list<WideVectorInfo> AllWideFloatVector = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def wf16#lmul : WideVectorInfo<!cast<VectorInfo>("f16"#lmul),
                                     !cast<VectorInfo>("f32"#WideLmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def wf32#lmul : WideVectorInfo<!cast<VectorInfo>("f32"#lmul),
                                     !cast<VectorInfo>("f64"#WideLmul)>;
    }
  }
}

defset list<WideVectorInfo> AllQuadWideVector = {
  defset list<WideVectorInfo> AllQuadWideIntegerVector = {
    foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2"] in {
      defvar QuadWideLmul = ComputeQuadWideLmul<lmul>.Result;
      def qwi8#lmul : WideVectorInfo<!cast<VectorInfo>(i8#lmul),
                                     !cast<VectorInfo>(i32#QuadWideLmul)>;
    }
    foreach lmul = ["mf4", "mf2", "m1", "m2"] in {
      defvar QuadWideLmul = ComputeQuadWideLmul<lmul>.Result;
      def qwi16#lmul : WideVectorInfo<!cast<VectorInfo>(i16#lmul),
                                      !cast<VectorInfo>(i64#QuadWideLmul)>;
    }
  }
  
  defset list<WideVectorInfo> AllQuadWideUnsignedVector = {
    foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2"] in {
      defvar QuadWideLmul = ComputeQuadWideLmul<lmul>.Result;
      def qwu8#lmul : WideVectorInfo<!cast<VectorInfo>(u8#lmul),
                                     !cast<VectorInfo>(u32#QuadWideLmul)>;
    }
    foreach lmul = ["mf4", "mf2", "m1", "m2"] in {
      defvar QuadWideLmul = ComputeQuadWideLmul<lmul>.Result;
      def qwu16#lmul : WideVectorInfo<!cast<VectorInfo>(u16#lmul),
                                      !cast<VectorInfo>(u64#QuadWideLmul)>;
    }
  }
} // defset list<WideVectorInfo> AllQuadWideVector

defset list<IntToFloat> AllIntToFloat = {
  defset list<IntToFloat> SignedToFloat = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def 16b#lmul : IntToFloat<!cast<VectorInfo>("i16"#lmul),
                                !cast<VectorInfo>("f16"#lmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def 32b#lmul : IntToFloat<!cast<VectorInfo>("i32"#lmul),
                                !cast<VectorInfo>("f32"#lmul)>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def 64b#lmul : IntToFloat<!cast<VectorInfo>("i64"#lmul),
                                !cast<VectorInfo>("f64"#lmul)>;
    }
  }
  defset list<IntToFloat> UnsignedToFloat = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def u16b#lmul : IntToFloat<!cast<VectorInfo>("u16"#lmul),
                                 !cast<VectorInfo>("f16"#lmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def u32b#lmul : IntToFloat<!cast<VectorInfo>("u32"#lmul),
                                 !cast<VectorInfo>("f32"#lmul)>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def u64b#lmul : IntToFloat<!cast<VectorInfo>("u64"#lmul),
                                 !cast<VectorInfo>("f64"#lmul)>;
    }
  }
} // defset list<IntToFloat> AllIntToFloat

defset list<WideVectorInfo> AllWideIntToFloat = {
  defset list<WideVectorInfo> WideSignedToFloat = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def 32wsf#lmul : WideVectorInfo<!cast<VectorInfo>("f16"#lmul),
                                      !cast<VectorInfo>(i32#WideLmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def 64wsf#lmul : WideVectorInfo<!cast<VectorInfo>("f32"#lmul),
                                      !cast<VectorInfo>(i64#WideLmul)>;
    }
  }

  defset list<WideVectorInfo> WideUnsignedToFloat = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def 32wuf#lmul : WideVectorInfo<!cast<VectorInfo>("f16"#lmul),
                                      !cast<VectorInfo>(u32#WideLmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def 64wuf#lmul : WideVectorInfo<!cast<VectorInfo>("f32"#lmul),
                                      !cast<VectorInfo>(u64#WideLmul)>;
    }
  }
} // defset list<WideVectorInfo> AllWideIntToFloat

defset list<WideVectorInfo> AllWideFloatToInt = {
  defset list<WideVectorInfo> WideFloatToSigned = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def 32wfs#lmul : WideVectorInfo<!cast<VectorInfo>("i16"#lmul),
                                      !cast<VectorInfo>(f32#WideLmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def 64wfs#lmul : WideVectorInfo<!cast<VectorInfo>("i32"#lmul),
                                      !cast<VectorInfo>(f64#WideLmul)>;
    }
  }
  defset list<WideVectorInfo> WideFloatToUnsigned = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def 32wfu#lmul : WideVectorInfo<!cast<VectorInfo>("u16"#lmul),
                                      !cast<VectorInfo>(f32#WideLmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in {
      defvar WideLmul = ComputeWideLmul<lmul>.Result;
      def 64wfu#lmul : WideVectorInfo<!cast<VectorInfo>("u32"#lmul),
                                      !cast<VectorInfo>(f64#WideLmul)>;
    }
  }
} // defset list<WideVectorInfo> AllWideFloatToInt

defset list<WideVectorInfo> WideFloatToFloat = {
  foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
    defvar WideLmul = ComputeWideLmul<lmul>.Result;
    def 32wff#lmul : WideVectorInfo<!cast<VectorInfo>("f16"#lmul),
                                    !cast<VectorInfo>(f32#WideLmul)>;
  }
  foreach lmul = ["mf2", "m1", "m2", "m4"] in {
    defvar WideLmul = ComputeWideLmul<lmul>.Result;
    def 64wff#lmul : WideVectorInfo<!cast<VectorInfo>("f32"#lmul),
                                    !cast<VectorInfo>(f64#WideLmul)>;
  }
}

class Inst<string Name, list<string> Types, string Inf, string Suf,
           int isMask, list<int> TypeOperands, code Def = ""> {
  string IntrinsicName = Name;
  list<string> BuiltinStr = Types;
  string Infix = Inf;
  string Suffix = Suf;
  list<int> AnyTypeOperands = TypeOperands;
  int Mask = isMask;
  // If not empty, the emitter will use it to define the intrinsic function.
  // Otherwise, the emitter will generate intrinsic in the default way.
  code CustomDef = Def;
  // Should emit BUILTIN macro. Set to false if the intrinsic function can
  // be implemented by other existing builtin functions.
  bit ShouldEmitBuiltin = 1;
} 

multiclass binary<string name, string result_str, string arg1_str, 
                  string arg2_str, string infix, string suffix, string mask_str,
                  list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_str, mask_str, result_str,
                                       arg1_str, arg2_str], infix, suffix, 1,
                                       MaskAnyTypeOperands>;
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str], infix, 
                               suffix, 0, AnyTypeOperands>;
}

multiclass binary_nomask<string name, string result_str, string arg1_str, 
                         string arg2_str, string infix, string suffix,
                         string mask_str, list<int> AnyTypeOperands,
                         list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str], infix, 
                               suffix, 0, AnyTypeOperands>;
}

multiclass ternary<string name, string result_str, string arg1_str,
                   string arg2_str, string arg3_str, string infix,
                   string suffix, string mask_str, list<int> AnyTypeOperands,
                   list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_str, mask_str, arg1_str,
                                       arg2_str, arg3_str],
                                       infix, suffix, 1, MaskAnyTypeOperands>;
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str, arg3_str],
                               infix, suffix, 0, AnyTypeOperands>;
}

multiclass unary<string name, string result_str, string arg1_str,
                 string infix, string suffix, string mask_str,
                 list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_str, mask_str, result_str,
                                       arg1_str], infix, suffix, 1,
                                       MaskAnyTypeOperands>;
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str], infix, suffix, 0,
                               AnyTypeOperands>;
}

multiclass unary_m<string name, string result_str, string arg1_str,
                   string infix, string suffix, string mask_str,
                   list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_str, mask_str, arg1_str],
                                       infix, suffix, 1, MaskAnyTypeOperands>;
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str], infix, suffix, 0,
                               AnyTypeOperands>;
}

multiclass unary_nomask<string name, string result_str, string arg1_str,
                 string infix, string suffix, string mask_str,
                 list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str], infix, suffix, 0,
                               AnyTypeOperands>;
}

multiclass ternary_nomask<string name, string result_str, string arg1_str,
                          string arg2_str, string arg3_str, string infix,
                          string suffix, string mask_str,
                          list<int> AnyTypeOperands,
                          list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str, arg3_str],
                               infix, suffix, 0, AnyTypeOperands>;
}

multiclass unary_pop {
  foreach I = AllMaskType in {
    defm NAME : unary_m<NAME, "ULi", I.Str, "_m", I.TypeSuffix, I.Str,
                        [0], [0, 1]>;
  }
}

multiclass unary_vfirst {
  foreach I = AllMaskType in {
    defm NAME : unary_m<NAME, "Li", I.Str, "_m", I.TypeSuffix, I.Str,
                        [0], [0, 1]>;
  }
}

multiclass binary_vmsbf_vmsif_vmsof {
  foreach I = AllMaskType in {
    defm NAME : unary<NAME, I.Str, I.Str, "_m", I.TypeSuffix, I.Str,
                      [-1], [-1]>;
  }
}

multiclass binary_viota {
  foreach I = AllUnsignedVectorType in {
    defm NAME : unary<NAME, I.Str, I.MaskStr, "_m", I.TypeSuffix, I.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
}

multiclass vfcvt {
  foreach I = SignedToFloat in {
    defm NAME : unary<NAME, I.Integer.Str, I.Float.Str, "_x_f_v",
                      I.Integer.TypeSuffix, I.Integer.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<NAME, I.Integer.Str, I.Float.Str, "_rtz_x_f_v",
                      I.Integer.TypeSuffix, I.Integer.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<NAME, I.Float.Str, I.Integer.Str, "_f_x_v",
                      I.Float.TypeSuffix, I.Integer.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
  foreach I = UnsignedToFloat in {
    defm NAME : unary<NAME, I.Integer.Str, I.Float.Str, "_xu_f_v",
                      I.Integer.TypeSuffix, I.Integer.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<NAME, I.Integer.Str, I.Float.Str, "_rtz_xu_f_v",
                      I.Integer.TypeSuffix, I.Integer.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<NAME, I.Float.Str, I.Integer.Str, "_f_xu_v",
                      I.Float.TypeSuffix, I.Integer.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
}

multiclass vfwcvt {
  foreach I = WideSignedToFloat in {
    defm NAME : unary<NAME, I.WideVector.Str, I.OriginVector.Str, "_x_f_v",
                      I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<NAME, I.WideVector.Str, I.OriginVector.Str, "_rtz_x_f_v",
                      I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
  foreach I = WideUnsignedToFloat in {
    defm NAME : unary<NAME, I.WideVector.Str, I.OriginVector.Str, "_xu_f_v",
                      I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<NAME, I.WideVector.Str, I.OriginVector.Str, "_rtz_xu_f_v",
                      I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = WideFloatToSigned in {
    defm NAME : unary<NAME, I.WideVector.Str, I.OriginVector.Str, "_f_x_v",
                      I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = WideFloatToUnsigned in {
    defm NAME : unary<NAME, I.WideVector.Str, I.OriginVector.Str, "_f_xu_v",
                      I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
  
  foreach I = WideFloatToFloat in {
    defm NAME : unary<NAME, I.WideVector.Str, I.OriginVector.Str, "_f_f_v",
                      I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
}

multiclass vfncvt {
  foreach I = WideSignedToFloat in {
    defm NAME : unary<NAME, I.OriginVector.Str, I.WideVector.Str, "_x_f_w",
                      I.OriginVector.TypeSuffix, I.OriginVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<NAME, I.OriginVector.Str, I.WideVector.Str, "_rtz_x_f_w",
                      I.OriginVector.TypeSuffix, I.OriginVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
  foreach I = WideUnsignedToFloat in {
    defm NAME : unary<NAME, I.OriginVector.Str, I.WideVector.Str, "_xu_f_w",
                      I.OriginVector.TypeSuffix, I.OriginVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<NAME, I.OriginVector.Str, I.WideVector.Str, "_rtz_xu_f_w",
                      I.OriginVector.TypeSuffix, I.OriginVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = WideFloatToSigned in {
    defm NAME : unary<NAME, I.OriginVector.Str, I.WideVector.Str, "_f_x_w",
                      I.OriginVector.TypeSuffix, I.OriginVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = WideFloatToUnsigned in {
    defm NAME : unary<NAME, I.OriginVector.Str, I.WideVector.Str, "_f_xu_w",
                      I.OriginVector.TypeSuffix, I.OriginVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }

  foreach I = WideFloatToFloat in {
    defm NAME : unary<NAME, I.OriginVector.Str, I.WideVector.Str, "_f_f_w",
                      I.OriginVector.TypeSuffix, I.OriginVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<NAME, I.OriginVector.Str, I.WideVector.Str, "_rod_f_f_w",
                      I.OriginVector.TypeSuffix, I.OriginVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
}


multiclass vwcvt {
  foreach I = AllWideIntegerVector in {
    defm NAME : unary<NAME, I.WideVector.Str, I.OriginVector.Str, "_x_x_v", 
                      I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
}

multiclass vwcvtu {
  foreach I = AllWideUnsignedVector in {
    defm NAME : unary<NAME,  I.WideVector.Str, I.OriginVector.Str, "_x_x_v",
                      I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                      [-1, 0], [-1, 0, 2]>;
  }
}

multiclass vslide {
  foreach I = AllVector in {
    defm NAME : ternary<NAME, I.Str, I.Str, I.Str, "z", "_vx", I.TypeSuffix,
                        I.MaskStr, [-1, 2], [-1, 0, 3]>;
  }
}

multiclass int_unary_v_v_v_x {
  foreach I = AllIntegerVectorType in {
    defm NAME : unary_nomask<NAME, I.Str, I.Str, "_v_v", I.TypeSuffix, "",
                             [-1], []>;
    defm NAME : unary_nomask<NAME, I.Str, I.ScalarType.Str, "_v_x",
                             I.TypeSuffix, "", [-1, 0], []>;
  }
}

multiclass int_unary_v_v {
  foreach I = AllIntegerVectorType in {
    defm NAME : unary<NAME, I.Str, I.Str, "_v", I.TypeSuffix, I.MaskStr,
                      [-1], [-1, 0]>;
  }
}

multiclass vmv_x_s_s_x {
  foreach I = AllIntegerVectorType in {
    defm NAME : unary_nomask<NAME, I.ScalarType.Str, I.Str, "_x_s",
                             I.TypeSuffix#"_"#I.ScalarType.Type, "",
                             [-1, 0], []>;
    defm NAME : binary_nomask<NAME, I.Str, I.Str, I.ScalarType.Str, "_s_x",
                              I.TypeSuffix#"_"#I.ScalarType.Type, "",
                              [-1, 0, 1], []>;
  }
}

multiclass vfmv_f_s_s_f {
  foreach I = AllFloatVectorType in {
    defm NAME : unary_nomask<NAME, I.ScalarType.Str, I.Str, "_f_s",
                             I.TypeSuffix#"_"#I.ScalarType.Type, "",
                             [-1, 0], []>;
    defm NAME : binary_nomask<NAME, I.Str, I.Str, I.ScalarType.Str, "_s_f",
                              I.TypeSuffix#"_"#I.ScalarType.Type, "",
                              [-1, 0, 1], []>;
  }
}

multiclass float_unary_v_v {
  foreach I = AllFloatVectorType in {
    defm NAME : unary<NAME, I.Str, I.Str, "_v", I.TypeSuffix, I.MaskStr,
                      [-1], [-1, 0]>;
  }
}

multiclass float_unary_v_f {
  foreach I = AllFloatVectorType in {
    defm NAME : unary_nomask<NAME, I.Str, I.ScalarType.Str, "_v_f", I.TypeSuffix, "",
                             [-1, 0], []>;
  }
}

multiclass int_ternary_v_vvm_vxm {
  foreach I = AllIntegerVectorType in {
    defm NAME : ternary_nomask<NAME, I.Str, I.Str, I.Str, I.MaskStr, "_vvm",
                               I.TypeSuffix, "", [-1, 2], []>;
    defm NAME : ternary_nomask<NAME, I.Str, I.Str, I.ScalarType.Str, I.Str, "_vxm",
                               I.TypeSuffix, "", [-1, 1, 2], []>;
  }
}

multiclass int_vmerge_vvm_vxm {
  foreach I = AllIntegerVectorType in {
    defm NAME : ternary_nomask<NAME, I.Str, I.MaskStr, I.Str, I.Str, "_vvm",
                               I.TypeSuffix, "", [-1, 0], []>;
    defm NAME : ternary_nomask<NAME, I.Str, I.MaskStr, I.Str, I.ScalarType.Str,
                               "_vxm", I.TypeSuffix, "", [-1, 0, 2], []>; 
  }
}

multiclass float_vmerge_vvm {
  foreach I = AllFloatVectorType in {
    defm NAME : ternary_nomask<NAME, I.Str, I.MaskStr, I.Str, I.Str, "_vvm",
                               I.TypeSuffix, "", [-1, 0], []>;
  }
}

multiclass float_vmerge_vfm {
  foreach I = AllFloatVectorType in {
    defm NAME : ternary_nomask<NAME, I.Str, I.MaskStr, I.Str, I.ScalarType.Str,
                               "_vfm", I.TypeSuffix, "", [-1, 0, 2], []>; 
  }
}

multiclass signed_binary_v_vv_vx {
  foreach I = AllSignedVectorType in {
    defm NAME : binary<NAME, I.Str, I.Str, I.Str, "_vv", I.TypeSuffix,
                       I.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<NAME, I.Str, I.Str, I.ScalarType.Str, "_vx",
                       I.TypeSuffix, I.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass signed_binary_v_vv_vi8 {
  foreach I = AllSignedVectorType in {
    defm NAME : binary<NAME, I.Str, I.Str, IntToUnsigned<I>.Result, "_vv", 
                       I.TypeSuffix, I.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<NAME, I.Str, I.Str, "Uc", "_vx", I.TypeSuffix,
                       I.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass reinterpret {
  foreach I = AllSignedVectorType in {
    defm NAME : unary_nomask<NAME, I.Str, IntToUnsigned<I>.Result, "_v",
                             I.TypeSuffix#"_"#!subst("i", "u", I.TypeSuffix),
                             "", [-1, 0], []>;
    defm NAME : unary_nomask<NAME, IntToUnsigned<I>.Result, I.Str, "_v",
                             !subst("i", "u", I.TypeSuffix)#"_"#I.TypeSuffix,
                             "", [-1, 0], []>; 
  }
  foreach I = AllIntToFloat in {
    defm NAME : unary_nomask<NAME, I.Integer.Str, I.Float.Str, "_v",
                             I.Integer.TypeSuffix#"_"#I.Float.TypeSuffix, "",
                             [-1, 0], []>;
    defm NAME : unary_nomask<NAME, I.Float.Str, I.Integer.Str, "_v",
                             I.Float.TypeSuffix#"_"#I.Integer.TypeSuffix, "",
                             [-1, 0], []>;
  }

  defm NAME : unary_nomask<NAME, i16mf4.Str, i8mf4.Str, "_v",
                           "i8mf4"#"_"#!cast<VectorInfo>("i16mf4").TypeSuffix,
                           "", [-1, 0], []>;
  foreach I = [i16mf2, i32mf2] in {
    defm NAME : unary_nomask<NAME, I.Str, i8mf2.Str, "_v",
                             i8mf2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i16m1, i32m1, i64m1] in {
    defm NAME : unary_nomask<NAME, I.Str, i8m1.Str, "_v",
                             i8m1.TypeSuffix#"_"#I.TypeSuffix, "", [-1, 0], []>;
  }
  foreach I = [i16m2, i32m2, i64m2] in {
    defm NAME : unary_nomask<NAME, I.Str, i8m2.Str, "_v",
                             i8m2.TypeSuffix#"_"#I.TypeSuffix, "", [-1, 0], []>;
  }
  foreach I = [i16m4, i32m4, i64m4] in {
    defm NAME : unary_nomask<NAME, I.Str, i8m4.Str, "_v",
                             i8m4.TypeSuffix#"_"#I.TypeSuffix, "", [-1, 0], []>;
  }
  foreach I = [i16m8, i32m8, i64m8] in {
    defm NAME : unary_nomask<NAME, I.Str, i8m8.Str, "_v",
                             i8m8.TypeSuffix#"_"#I.TypeSuffix, "", [-1, 0], []>;
  }
  defm NAME : unary_nomask<NAME, i8mf4.Str, i16mf4.Str, "_v",
                           "i16mf4"#"_"#!cast<VectorInfo>("i8mf4").TypeSuffix,
                           "", [-1, 0], []>;
  foreach I = [i8mf2, i32mf2] in {
    defm NAME : unary_nomask<NAME, I.Str, i16mf2.Str, "_v",
                             i16mf2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m1, i32m1, i64m1] in {
    defm NAME : unary_nomask<NAME, I.Str, i16m1.Str, "_v",
                             i16m1.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m2, i32m2, i64m2] in {
    defm NAME : unary_nomask<NAME, I.Str, i16m2.Str, "_v",
                             i16m2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m4, i32m4, i64m4] in {
    defm NAME : unary_nomask<NAME, I.Str, i16m4.Str, "_v",
                             i16m4.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m8, i32m8, i64m8] in {
    defm NAME : unary_nomask<NAME, I.Str, i16m8.Str, "_v",
                             i16m8.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8mf2, i16mf2] in {
    defm NAME : unary_nomask<NAME, I.Str, i32mf2.Str, "_v",
                             i32mf2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m1, i16m1, i64m1] in {
    defm NAME : unary_nomask<NAME, I.Str, i32m1.Str, "_v",
                             i32m1.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m2, i16m2, i64m2] in {
    defm NAME : unary_nomask<NAME, I.Str, i32m2.Str, "_v",
                             i32m2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m4, i16m4, i64m4] in {
    defm NAME : unary_nomask<NAME, I.Str, i32m4.Str, "_v",
                             i32m4.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m8, i16m8, i64m8] in {
    defm NAME : unary_nomask<NAME, I.Str, i32m8.Str, "_v",
                             i32m8.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }

  foreach I = [i8m1, i16m1, i32m1] in {
    defm NAME : unary_nomask<NAME, I.Str, i64m1.Str, "_v",
                             i64m1.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m2, i16m2, i32m2] in {
    defm NAME : unary_nomask<NAME, I.Str, i64m2.Str, "_v",
                             i64m2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m4, i16m4, i32m4] in {
    defm NAME : unary_nomask<NAME, I.Str, i64m4.Str, "_v",
                             i64m4.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [i8m8, i16m8, i32m8] in {
    defm NAME : unary_nomask<NAME, I.Str, i64m8.Str, "_v",
                             i64m8.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  
  defm NAME : unary_nomask<NAME, u16mf4.Str, u8mf4.Str, "_v",
                           "u8mf4"#"_"#!cast<VectorInfo>("u16mf4").TypeSuffix,
                           "", [-1, 0], []>;
  foreach I = [u16mf2, u32mf2] in {
    defm NAME : unary_nomask<NAME, I.Str, u8mf2.Str, "_v",
                             i8mf2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u16m1, u32m1, u64m1] in {
    defm NAME : unary_nomask<NAME, I.Str, u8m1.Str, "_v",
                             u8m1.TypeSuffix#"_"#I.TypeSuffix, "", [-1, 0], []>;
  }
  foreach I = [u16m2, u32m2, u64m2] in {
    defm NAME : unary_nomask<NAME, I.Str, u8m2.Str, "_v",
                             u8m2.TypeSuffix#"_"#I.TypeSuffix, "", [-1, 0], []>;
  }
  foreach I = [u16m4, u32m4, u64m4] in {
    defm NAME : unary_nomask<NAME, I.Str, u8m4.Str, "_v",
                             u8m4.TypeSuffix#"_"#I.TypeSuffix, "", [-1, 0], []>;
  }
  foreach I = [u16m8, u32m8, u64m8] in {
    defm NAME : unary_nomask<NAME, I.Str, u8m8.Str, "_v",
                             u8m8.TypeSuffix#"_"#I.TypeSuffix, "", [-1, 0], []>;
  }
  defm NAME : unary_nomask<NAME, u8mf4.Str, u16mf4.Str, "_v",
                           "u16mf4"#"_"#!cast<VectorInfo>("u8mf4").TypeSuffix,
                           "", [-1, 0], []>;
  foreach I = [u8mf2, u32mf2] in {
    defm NAME : unary_nomask<NAME, I.Str, u16mf2.Str, "_v",
                             u16mf2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m1, u32m1, u64m1] in {
    defm NAME : unary_nomask<NAME, I.Str, u16m1.Str, "_v",
                             u16m1.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m2, u32m2, u64m2] in {
    defm NAME : unary_nomask<NAME, I.Str, u16m2.Str, "_v",
                             u16m2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m4, u32m4, u64m4] in {
    defm NAME : unary_nomask<NAME, I.Str, u16m4.Str, "_v",
                             u16m4.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m8, u32m8, u64m8] in {
    defm NAME : unary_nomask<NAME, I.Str, u16m8.Str, "_v",
                             u16m8.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8mf2, u16mf2] in {
    defm NAME : unary_nomask<NAME, I.Str, u32mf2.Str, "_v",
                             u32mf2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m1, u16m1, u64m1] in {
    defm NAME : unary_nomask<NAME, I.Str, u32m1.Str, "_v",
                             u32m1.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m2, u16m2, u64m2] in {
    defm NAME : unary_nomask<NAME, I.Str, u32m2.Str, "_v",
                             u32m2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m4, u16m4, u64m4] in {
    defm NAME : unary_nomask<NAME, I.Str, u32m4.Str, "_v",
                             u32m4.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m8, u16m8, u64m8] in {
    defm NAME : unary_nomask<NAME, I.Str, u32m8.Str, "_v",
                             u32m8.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }

  foreach I = [u8m1, u16m1, u32m1] in {
    defm NAME : unary_nomask<NAME, I.Str, u64m1.Str, "_v",
                             u64m1.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m2, u16m2, u32m2] in {
    defm NAME : unary_nomask<NAME, I.Str, u64m2.Str, "_v",
                             u64m2.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m4, u16m4, u32m4] in {
    defm NAME : unary_nomask<NAME, I.Str, u64m4.Str, "_v",
                             u64m4.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
  foreach I = [u8m8, u16m8, u32m8] in {
    defm NAME : unary_nomask<NAME, I.Str, u64m8.Str, "_v",
                             u64m8.TypeSuffix#"_"#I.TypeSuffix, "",
                             [-1, 0], []>;
  }
}

multiclass unsigned_binary_v_vv_vi8 {
  foreach I = AllUnsignedVectorType in {
    defm NAME : binary<NAME, I.Str, I.Str, I.Str, "_vv", I.TypeSuffix,
                       I.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<NAME, I.Str, I.Str, "Uc", "_vx", I.TypeSuffix,
                       I.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass int_binary_v_vv_vi8 :
  signed_binary_v_vv_vi8, unsigned_binary_v_vv_vi8;

multiclass binary_m_vv_vx {
  foreach I = AllIntegerVectorType in {
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vv",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0], [-1, 2, 3]>;
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vx",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass signed_binary_m_vx {
  foreach I = AllSignedVectorType in {
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vx",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass unsigned_binary_m_vx {
  foreach I = AllUnsignedVectorType in {
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vx",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass signed_binary_m_vv_vx {
  foreach I = AllSignedVectorType in {
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vv",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0], [-1, 2, 3]>;
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vx",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass unsigned_binary_m_vv_vx {
  foreach I = AllUnsignedVectorType in {
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vv",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0], [-1, 2, 3]>;
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vx",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass float_binary_m_vf {
  foreach I = AllFloatVectorType in {
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vf",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass float_binary_m_vv_vx {
  foreach I = AllFloatVectorType in {
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vv",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0], [-1, 2, 3]>;
    defm NAME : binary<NAME, I.MaskStr, I.Str, I.Str, "_vf",
                       I.TypeSuffix#"_"#I.BoolType, I.MaskStr,
                       [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass float_binary_v_vv_vf {
  foreach I = AllFloatVectorType in {
    defm NAME : binary<NAME, I.Str, I.Str, I.Str, "_vv",
                       I.TypeSuffix, I.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<NAME, I.Str, I.Str, I.ScalarType.Str, "_vf",
                       I.TypeSuffix, I.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass float_binary_v_vf {
  foreach I = AllFloatVectorType in {
    defm NAME : binary<NAME, I.Str, I.Str, I.ScalarType.Str, "_vf",
                       I.TypeSuffix, I.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass unsigned_binary_v_vv_vx {
  foreach I = AllUnsignedVectorType in {
    defm NAME : binary<NAME, I.Str, I.Str, I.Str, "_vv", I.TypeSuffix,
                       I.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<NAME, I.Str, I.Str, I.ScalarType.Str, "_vx",
                       I.TypeSuffix, I.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass int_binary_v_vv_vx :
  signed_binary_v_vv_vx, unsigned_binary_v_vv_vx;

multiclass binary_v_vx {
  foreach I = AllIntegerVectorType in {
      defm NAME : binary<NAME, I.Str, I.Str, I.ScalarType.Str, "_vx",
                         I.TypeSuffix, I.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass float_ternary_v_vvf_vvv {
  foreach I = AllFloatVectorType in {
    defm NAME : ternary<NAME, I.Str, I.Str, I.Str, I.Str, "_vv", I.TypeSuffix,
                        I.MaskStr, [-1], [-1, 0]>;
    defm NAME : ternary<NAME, I.Str, I.Str, I.ScalarType.Str, I.Str, "_vf",
                        I.TypeSuffix, I.MaskStr, [-1, 1], [-1, 0, 2]>;
  }
}

multiclass float_ternary_w_wvv_wvf {
  foreach I = AllWideFloatVector in {
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str,
                        I.OriginVector.Str, I.OriginVector.Str, "_vv",
                        I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1], [-1, 0, 2]>;
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str,
                        I.OriginVector.ScalarType.Str, I.OriginVector.Str,
                        "_vf", I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass ternary_v_vvx_vvv {
  foreach I = AllIntegerVectorType in {
    defm NAME : ternary<NAME, I.Str, I.Str, I.Str, I.Str, "_vv", I.TypeSuffix,
                        I.MaskStr, [-1], [-1, 0]>;
    defm NAME : ternary<NAME, I.Str, I.Str, I.ScalarType.Str, I.Str, "_vx",
                        I.TypeSuffix, I.MaskStr, [-1, 1], [-1, 0, 2]>;
  }
}

multiclass int_ternary_v_vs {
  foreach I = AllIntegerVectorType in {
    defvar Lmul1Type = !cast<VectorInfo>(I.Lmul1Type);
    defm NAME : ternary<NAME, Lmul1Type.Str, Lmul1Type.Str, I.Str,
                        Lmul1Type.Str, "_vs",
                        I.TypeSuffix#"_"#Lmul1Type.TypeSuffix,
                        I.MaskStr, [-1, 1], [-1, 0, 2]>;
  }
}

multiclass float_ternary_v_vs {
  foreach I = AllFloatVectorType in {
    defvar Lmul1Type = !cast<VectorInfo>(I.Lmul1Type);
    defm NAME : ternary<NAME, Lmul1Type.Str, Lmul1Type.Str, I.Str,
                        Lmul1Type.Str, "_vs",
                        I.TypeSuffix#"_"#Lmul1Type.TypeSuffix, I.MaskStr,
                        [-1, 1], [-1, 0, 2]>;
  }
}

multiclass int_ternary_qw_vvx_vvv {
  foreach I = AllQuadWideIntegerVector in {
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str,
                        I.OriginVector.Str, I.OriginVector.Str, "_vv",
                        I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1], [-1, 0, 2]>;
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str,
                        I.OriginVector.ScalarType.Str, I.OriginVector.Str,
                        "_vx", I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass unsigned_ternary_qw_vvx_vvv {
  foreach I = AllQuadWideUnsignedVector in {
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str,
                        I.OriginVector.Str, I.OriginVector.Str, "_vv",
                        I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1], [-1, 0, 2]>;
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str,
                        I.OriginVector.ScalarType.Str, I.OriginVector.Str,
                        "_vx", I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass int_ternary_qw_vvx {
  foreach I = AllQuadWideIntegerVector in {
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str,
                        I.OriginVector.ScalarType.Str, I.OriginVector.Str,
                        "_vx", I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass int_ternary_w_vvx_vvv {
  foreach I = AllWideIntegerVector in {
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str, 
                        I.OriginVector.Str, I.OriginVector.Str, "_vv",
                        I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1], [-1, 0, 2]>;
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str, 
                        I.OriginVector.ScalarType.Str, I.OriginVector.Str,
                        "_vx", I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass unsigned_ternary_w_vvx_vvv {
  foreach I = AllWideUnsignedVector in {
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str, 
                        I.OriginVector.Str, I.OriginVector.Str, "_vv",
                        I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1], [-1, 0, 2]>;
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str, 
                        I.OriginVector.ScalarType.Str, I.OriginVector.Str,
                        "_vx", I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass int_ternary_w_vvx {
  foreach I = AllWideIntegerVector in {
    defm NAME : ternary<NAME, I.WideVector.Str, I.WideVector.Str, 
                        I.OriginVector.ScalarType.Str, I.OriginVector.Str,
                        "_vx", I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                        [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass int_binary_w_vv_vx_wv_wx {
  foreach I = AllWideIntegerVector in {
    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str, 
                       I.OriginVector.Str, "_vv", I.WideVector.TypeSuffix, 
                       I.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str,
                       I.OriginVector.ScalarType.Str, "_vx",
                       I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                       [-1, 0, 1], [-1, 0, 2, 3]>;

    defm NAME : binary<NAME, I.WideVector.Str, I.WideVector.Str,
                       I.OriginVector.Str, "_wv", I.WideVector.TypeSuffix,
                       I.WideVector.MaskStr, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : binary<NAME, I.WideVector.Str, I.WideVector.Str,
                       I.OriginVector.ScalarType.Str, "_wx",
                       I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                       [-1, 1], [-1, 0, 3]>;
  }
}

multiclass float_binary_w_vv_vf_wv_wf {
  foreach I = AllWideFloatVector in {
    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str, 
                       I.OriginVector.Str, "_vv", I.WideVector.TypeSuffix, 
                       I.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str,
                       I.OriginVector.ScalarType.Str, "_vf",
                       I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                       [-1, 0, 1], [-1, 0, 2, 3]>;

    defm NAME : binary<NAME, I.WideVector.Str, I.WideVector.Str,
                       I.OriginVector.Str, "_wv", I.WideVector.TypeSuffix,
                       I.WideVector.MaskStr, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : binary<NAME, I.WideVector.Str, I.WideVector.Str,
                       I.OriginVector.ScalarType.Str, "_wf",
                       I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                       [-1, 1], [-1, 0, 3]>;
  }
}

multiclass int_binary_v_wv_wx {
  foreach I = AllWideIntegerVector in {
    defm NAME : binary<NAME, I.OriginVector.Str, I.WideVector.Str,
                       I.OriginVector.Str, "_wv", I.OriginVector.TypeSuffix,
                       I.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;
            
    defm NAME : binary<NAME, I.OriginVector.Str, I.WideVector.Str,
                       I.OriginVector.ScalarType.Str, "_wx",
                       I.OriginVector.TypeSuffix, I.WideVector.MaskStr,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

multiclass unsigned_binary_v_wv_wx {
  foreach I = AllWideUnsignedVector in {
    defm NAME : binary<NAME, I.OriginVector.Str, I.WideVector.Str,
                       I.OriginVector.Str, "_wv", I.OriginVector.TypeSuffix,
                       I.WideVector.MaskStr, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : binary<NAME, I.OriginVector.Str, I.WideVector.Str,
                       I.OriginVector.ScalarType.Str, "_wx",
                       I.OriginVector.TypeSuffix, I.WideVector.MaskStr,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

multiclass int_binary_w_vv_vx {
  foreach I = AllWideIntegerVector in {
    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str, 
                       I.OriginVector.Str, "_vv", I.WideVector.TypeSuffix, 
                       I.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str,
                       I.OriginVector.ScalarType.Str, "_vx",
                       I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

multiclass float_binary_w_vv_vf {
  foreach I = AllWideFloatVector in {
    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str, 
                       I.OriginVector.Str, "_vv", I.WideVector.TypeSuffix, 
                       I.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str,
                       I.OriginVector.ScalarType.Str, "_vf",
                       I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

multiclass unsigned_binary_w_vv_vx {
  foreach I = AllWideUnsignedVector in {
    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str, 
                       I.OriginVector.Str, "_vv", I.WideVector.TypeSuffix,
                       I.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;
    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str, 
                       I.OriginVector.ScalarType.Str, "_vx",
                       I.WideVector.TypeSuffix, I.WideVector.MaskStr,
                       [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

multiclass unsigned_binary_w_vv_vx_wv_wx {
  foreach I = AllWideUnsignedVector in {
    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str, 
                       I.OriginVector.Str, "_vv", I.WideVector.TypeSuffix,
                       I.WideVector.TypeSuffix, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<NAME, I.WideVector.Str, I.OriginVector.Str,
                       I.OriginVector.ScalarType.Str, "_vx",
                       I.WideVector.TypeSuffix, I.WideVector.TypeSuffix,
                       [-1, 0, 1], [-1, 0, 2, 3]>;

    defm NAME : binary<NAME, I.WideVector.Str, I.WideVector.Str,
                       I.OriginVector.Str, "_wv", I.WideVector.TypeSuffix,
                       I.WideVector.TypeSuffix, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : binary<NAME, I.WideVector.Str, I.WideVector.Str,
                       I.OriginVector.ScalarType.Str, "_wx",
                       I.WideVector.TypeSuffix, I.WideVector.TypeSuffix,
                       [-1, 1], [-1, 0, 3]>;
  }    
}

multiclass vsetvl {
  foreach suffix = ["e8mf8", "e8mf4", "e8mf2", "e8m1", "e8m2", "e8m4", "e8m8",
                    "e16mf4", "e16mf2", "e16m1", "e16m2", "e16m4", "e16m8",
                    "e32mf2", "e32m1", "e32m2", "e32m4", "e32m8",
                    "e64m1", "e64m2", "e64m4", "e64m8"] in {
    def NAME#suffix : Inst<"vsetvl", ["z", "z", "z"], "", suffix, 0, [-1]>;
  }
}

multiclass load_store {
  foreach I = AllVector in {
    def "vle"#I.SEW#"_v"#I.TypeSuffix : Inst<"vle"#I.SEW, 
      [I.Str, I.ScalarType.Str#"C*"], "_v", I.TypeSuffix, 0, [-1, 0]>;
    def "vle"#I.SEW#"_v"#I.TypeSuffix#"_mask" : Inst<"vle"#I.SEW, 
      [I.Str, I.MaskStr, I.Str, I.ScalarType.Str#"C*"], "_v", I.TypeSuffix, 1, [-1, 0, 2]>;
    def "vse"#I.SEW#"_v"#I.TypeSuffix : Inst<"vse"#I.SEW, 
      ["v", I.ScalarType.Str#"*", I.Str], "_v", I.TypeSuffix, 0, [0, 1]>;
    def "vse"#I.SEW#"_v"#I.TypeSuffix#"_mask" : Inst<"vse"#I.SEW,
      ["v", I.MaskStr, I.Str, I.ScalarType.Str#"C*"], "_v", I.TypeSuffix, 1, [0, 1, 2]>;
    def "vlse"#I.SEW#"_v"#I.TypeSuffix : Inst<"vlse"#I.SEW,
      [I.Str, I.ScalarType.Str#"C*", "Y"], "_v", I.TypeSuffix, 0, [-1, 0]>;
    def "vlse"#I.SEW#"_v"#I.TypeSuffix#"_mask" : Inst<"vlse"#I.SEW,
      [I.Str, I.MaskStr, I.Str, I.ScalarType.Str#"C*", "Y"], "_v", I.TypeSuffix, 1, [-1, 0, 2]>;
    def "vsse"#I.SEW#"_v"#I.TypeSuffix : Inst<"vsse"#I.SEW, 
      ["v", I.ScalarType.Str#"*", "Y", I.Str], "_v", I.TypeSuffix, 0, [0, 2]>;
    def "vsse"#I.SEW#"_v"#I.TypeSuffix#"_mask" : Inst<"vsse"#I.SEW,
      ["v", I.MaskStr, I.ScalarType.Str#"*", "Y", I.Str], "_v", I.TypeSuffix, 1, [0, 1, 2]>;
    // def "vlxei"#I.SEW#"_v"#I.TypeSuffix : Inst<"vlxei"#I.SEW,
    //   [I.Str, I.ScalarType.Str#"C*", !cast<VectorInfo>(!subst("i", "u", !cast<string>(I))).Str],
    //    "_v", I.TypeSuffix, 0, [-1, 0, 1]>;
    // def "vlxei"#I.SEW#"_v"#I.TypeSuffix#"_mask" : Inst<"vlxei"#I.SEW, 
    //   [I.Str, I.MaskStr, I.Str, I.ScalarType.Str#"C*", !cast<VectorInfo>(!subst("i", "u", !cast<string>(I))).Str],
    //    "_v", I.TypeSuffix, 1, [-1, 0, 2, 3]>;
    // def "vsxei"#I.SEW#"_v"#I.TypeSuffix : Inst<"vsxei"#I.SEW,
    //   ["v", I.ScalarType.Str#"C*", !cast<VectorInfo>(!subst("i", "u", !cast<string>(I))).Str, I.Str],
    //   "_v", I.TypeSuffix, 0, [0, 2, 3]>;
    // def "vsxei"#I.SEW#"_v"#I.TypeSuffix#"_mask" : Inst<"vsxei"#I.SEW,
    //   ["v", I.MaskStr, I.ScalarType.Str#"C*", !cast<VectorInfo>(!subst("i", "u", !cast<string>(I))).Str, 
    //   I.Str], "_v", I.TypeSuffix, 1, [0, 1, 2, 3]>;
  }
}

// 12.1. Vector Single-Width Integer Add and Subtract
defm vadd : int_binary_v_vv_vx;
defm vsub : int_binary_v_vv_vx;
defm vrsub : binary_v_vx;

// 12.2. Vector Widening Integer Add/Subtract
defm vwadd : int_binary_w_vv_vx_wv_wx;
defm vwsub : int_binary_w_vv_vx_wv_wx;
defm vwaddu : unsigned_binary_w_vv_vx_wv_wx;
defm vwsubu : unsigned_binary_w_vv_vx_wv_wx;

// 12.3. Vector Integer Extension

// 12.4. Vector Integer Add-with-Carry/Subtract-with-Borrow Instructions
defm vadc : int_ternary_v_vvm_vxm;
defm vsbc : int_ternary_v_vvm_vxm;

// 12.5. Vector Bitwise Logical Instructions
defm vand : int_binary_v_vv_vx;
defm vxor : int_binary_v_vv_vx;
defm vor : int_binary_v_vv_vx;
let ShouldEmitBuiltin = 0 in {
  foreach I = AllIntegerVectorType in {
    def "vnot_v"#I.TypeSuffix : Inst<"vnot", [I.Str, I.Str], "_v",
                                     I.TypeSuffix, 0, [-1],
                                     "vxor_vx_"#I.TypeSuffix#"(ARG0, -1)">;
  }
}

// 12.6. Vector Single-Width Bit Shift Instructions
defm vsll : int_binary_v_vv_vi8;
defm vsrl : int_binary_v_vv_vi8;
defm vsra : signed_binary_v_vv_vi8;

// 12.7. Vector Narrowing Integer Right Shift Instructions
defm vnsrl : unsigned_binary_v_wv_wx;
defm vnsra : int_binary_v_wv_wx;

// 12.8. Vector Integer Comparison Instructions
defm vmseq : binary_m_vv_vx;
defm vmsne : binary_m_vv_vx;
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
    def "vmsge_vv"#I.TypeSuffix#"_"#I.BoolType : Inst<"vmsge",
           [I.MaskStr, I.Str, I.Str], "_vv",
           I.TypeSuffix#"_"#I.BoolType, 0, [-1],
           "vmsle_vv_"#I.TypeSuffix#"_"#I.BoolType#"(ARG1, ARG0)">;

    def "vmsgt_vv"#I.TypeSuffix#"_"#I.BoolType : Inst<"vmsgt",
           [I.MaskStr, I.Str, I.Str], "_vv",
           I.TypeSuffix#"_"#I.BoolType, 0, [-1],
           "vmslt_vv_"#I.TypeSuffix#"_"#I.BoolType#"(ARG1, ARG0)">;
  }
  foreach I = AllUnsignedVectorType in {
    def "vmsgeu_vv"#I.TypeSuffix#"_"#I.BoolType : Inst<"vmsgeu",
           [I.MaskStr, I.Str, I.Str], "_vv",
           I.TypeSuffix#"_"#I.BoolType, 0, [-1],
           "vmsleu_vv_"#I.TypeSuffix#"_"#I.BoolType#"(ARG1, ARG0)">;

    def "vmsgtu_vv"#I.TypeSuffix#"_"#I.BoolType : Inst<"vmsgtu",
           [I.MaskStr, I.Str, I.Str], "_vv",
           I.TypeSuffix#"_"#I.BoolType, 0, [-1],
           "vmsltu_vv_"#I.TypeSuffix#"_"#I.BoolType#"(ARG1, ARG0)">;
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
defm vwmul : int_binary_w_vv_vx;
defm vwmulu : unsigned_binary_w_vv_vx;
defm vwmulsu : int_binary_w_vv_vx;

// 12.13. Vector Single-Width Integer Multiply-Add Instructions
defm vmacc : ternary_v_vvx_vvv;
defm vnmsac : ternary_v_vvx_vvv;
defm vmadd : ternary_v_vvx_vvv;
defm vnmsub : ternary_v_vvx_vvv;

// 12.14. Vector Widening Integer Multiply-Add Instructions
defm vwmacc : int_ternary_w_vvx_vvv;
defm vwmaccu : unsigned_ternary_w_vvx_vvv;
defm vwmaccsu : int_ternary_w_vvx_vvv;
defm vwmaccus : int_ternary_w_vvx;

// 12.15. Vector Quad-Widening Integer Multiply-Add Instructions (Extension Zvqmac)
defm vqmacc : int_ternary_qw_vvx_vvv;
defm vqmaccu : unsigned_ternary_qw_vvx_vvv;
defm vqmaccsu : int_ternary_qw_vvx_vvv;
defm vqmaccus : int_ternary_qw_vvx;

// 12.16. Vector Integer Merge Instructions
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
defm vssrl : unsigned_binary_v_vv_vx;
defm vssra : signed_binary_v_vv_vx;

// 13.5. Vector Narrowing Fixed-Point Clip Instructions
defm vnclip : int_binary_v_wv_wx;
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
defm vfmacc : float_ternary_v_vvf_vvv;
defm vfnmacc : float_ternary_v_vvf_vvv;
defm vfmsac : float_ternary_v_vvf_vvv;
defm vfmadd : float_ternary_v_vvf_vvv;
defm vfnmadd : float_ternary_v_vvf_vvv;
defm vfmsub : float_ternary_v_vvf_vvv;
defm vfnmsub : float_ternary_v_vvf_vvv;

// 14.7. Vector Widening Floating-Point Fused MultiplyAdd Instructions
defm vfwmacc : float_ternary_w_wvv_wvf;
defm vfwnmacc : float_ternary_w_wvv_wvf;
defm vfwmsac : float_ternary_w_wvv_wvf;
defm vfwnmsac : float_ternary_w_wvv_wvf;

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
defm vmfeq : float_binary_m_vv_vx;
defm vmfne : float_binary_m_vv_vx;
defm vmflt : float_binary_m_vv_vx;
defm vmfle : float_binary_m_vv_vx;
defm vmfgt : float_binary_m_vf;
defm vmfge : float_binary_m_vf;
let ShouldEmitBuiltin = 0 in {
  foreach I = AllFloatVectorType in {
    def "vmfge_vv"#I.TypeSuffix#"_"#I.BoolType : Inst<"vmfge",
           [I.MaskStr, I.Str, I.Str], "_vv",
           I.TypeSuffix#"_"#I.BoolType, 0, [-1],
           "vmfle_vv_"#I.TypeSuffix#"_"#I.BoolType#"(ARG1, ARG0)">;

    def "vmfgt_vv"#I.TypeSuffix#"_"#I.BoolType : Inst<"vmfgt",
           [I.MaskStr, I.Str, I.Str], "_vv",
           I.TypeSuffix#"_"#I.BoolType, 0, [-1],
           "vmflt_vv_"#I.TypeSuffix#"_"#I.BoolType#"(ARG1, ARG0)">;
  }
}

// 14.12. Vector Floating-Point Classify Instruction

// 14.13. Vector Floating-Point Merge Instruction
defm vmerge : float_vmerge_vvm;
defm vfmerge : float_vmerge_vfm;

// 14.14. Vector Floating-Point Move Instruction
defm vfmv : float_unary_v_f;

// 14.15. Single-Width Floating-Point/Integer TypeConvert Instructions
defm vfcvt : vfcvt;

// 14.16. Widening Floating-Point/Integer Type-Convert Instructions
defm vfwcvt : vfwcvt;
defm vwcvt : vwcvt;
defm vwcvtu : vwcvtu;

// 14.17. Narrowing Floating-Point/Integer Type-Convert Instructions
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

// 15.3. Vector Single-Width Floating-Point Reduction Instructions
defm vfredsum : float_ternary_v_vs;
defm vfredosum : float_ternary_v_vs;
defm vfredmax : float_ternary_v_vs;
defm vfredmin : float_ternary_v_vs;

// 15.4. Vector Widening Floating-Point Reduction Instructions
// 16.1. Vector Mask-Register Logical Instructions
// 16.2. Vector mask population count vpopc
defm vpopc : unary_pop;

// 16.3. vfirst find-first-set mask bit
defm vfirst : unary_vfirst;

// 16.4. vmsbf.m set-before-first mask bit
defm vmsbf : binary_vmsbf_vmsif_vmsof;

// 16.5. vmsif.m set-including-first mask bit
defm vmsif : binary_vmsbf_vmsif_vmsof;

// 16.6. vmsof.m set-only-first mask bit
defm vmsof : binary_vmsbf_vmsif_vmsof;

// 16.8. Vector Iota Instruction
defm viota : binary_viota;

// 16.9. Vector Element Index Instruction

// 17.1. Integer Scalar Move Instructions
defm vmv : vmv_x_s_s_x;

// 17.2. Floating-Point Scalar Move Instructions
defm vfmv : vfmv_f_s_s_f;

// 17.3.1. Vector Slideup Instructions
defm vslideup : vslide;

// 17.3.2. Vector Slidedown Instructions
defm vslidedown : vslide;

// 17.3.3. Vector Slide1up
defm vslide1up : binary_v_vx;
defm vfslide1up : float_binary_v_vf;

// 17.3.4. Vector Slide1down Instruction
defm vslide1down : binary_v_vx;
defm vfslide1down : float_binary_v_vf;

// 17.4. Vector Register Gather Instruction
// 17.5. Vector Compress Instruction
// 17.6. Whole Vector Register Move
// 19.3. Vector Integer Dot-Product Instruction
// 19.4. Vector Floating-Point Dot Product Instruction

defm vreinterpret : reinterpret;

defm : load_store;
defm : vsetvl;

let ShouldEmitBuiltin = 0 in {
  foreach I = AllIntegerVectorType in {
    def "vzero_"#I.TypeSuffix : Inst<"vzero", [""], "",
                                     I.TypeSuffix, 0, [-1],
                                     "vmv_v_x_"#I.TypeSuffix#"(0)">;
  }
  
  foreach I = AllFloatVectorType in {
    def "vzero_"#I.TypeSuffix : Inst<"vzero", [""], "",
                                     I.TypeSuffix, 0, [-1],
                                     "vmv_v_f_"#I.TypeSuffix#"(0)">;
  }
}

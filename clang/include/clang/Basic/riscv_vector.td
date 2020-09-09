class ScalarInfo<string TypeName, string TypeStr> {
  string Type = TypeName;
  string Str = TypeStr;
}

class VectorInfo<string TypeStr, string MStr, 
              ScalarInfo Sca, string Suf, int Sew,
              string BType, string M1Type> {
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
  string Result = !cast<VectorInfo>(!subst("i", "u", !cast<string>(Integer))).Str;
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

defset list<ScalarInfo> AllScalarType = {
  def i8 : ScalarInfo<"i8", "c">;
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
        def i8#lmul : VectorInfo<"q"#ComputeVectorNum<3, lmul>.Result#"c",
        "q"#ComputeVectorNum<3, lmul>.Result#"b", i8, "i8"#lmul, 8, ComputeBoolType<ComputeVectorNum<3, lmul>.Result>.Result, "i8m1">;
      }
      foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        def i16#lmul : VectorInfo<"q"#ComputeVectorNum<4, lmul>.Result#"s", 
        "q"#ComputeVectorNum<4, lmul>.Result#"b", i16, "i16"#lmul, 16, ComputeBoolType<ComputeVectorNum<4, lmul>.Result>.Result, "i16m1">;
      }

      foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
        def i32#lmul : VectorInfo<"q"#ComputeVectorNum<5, lmul>.Result#"i", 
        "q"#ComputeVectorNum<5, lmul>.Result#"b", i32, "i32"#lmul, 32, ComputeBoolType<ComputeVectorNum<5, lmul>.Result>.Result, "i32m1">;
      }
      
      foreach lmul = ["m1", "m2", "m4", "m8"] in {
        def i64#lmul : VectorInfo<"q"#ComputeVectorNum<6, lmul>.Result#"Wi", 
        "q"#ComputeVectorNum<6, lmul>.Result#"b", i64, "i64"#lmul, 64, ComputeBoolType<ComputeVectorNum<6, lmul>.Result>.Result, "i64m1">;
      }
    }
    defset list<VectorInfo> AllUnsignedVectorType = {
      foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        def u8#lmul : VectorInfo<"q"#ComputeVectorNum<3, lmul>.Result#"Uc",
        "q"#ComputeVectorNum<3, lmul>.Result#"b", u8, "u8"#lmul, 8, ComputeBoolType<ComputeVectorNum<3, lmul>.Result>.Result, "u8m1">;
      }
      foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        def u16#lmul : VectorInfo<"q"#ComputeVectorNum<4, lmul>.Result#"Us", 
        "q"#ComputeVectorNum<4, lmul>.Result#"b", u16, "u16"#lmul, 16, ComputeBoolType<ComputeVectorNum<4, lmul>.Result>.Result, "u16m1">;
      }
      foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
        def u32#lmul : VectorInfo<"q"#ComputeVectorNum<5, lmul>.Result#"Ui", 
        "q"#ComputeVectorNum<5, lmul>.Result#"b", u32, "u32"#lmul, 32, ComputeBoolType<ComputeVectorNum<5, lmul>.Result>.Result, "u32m1">;
      }
      foreach lmul = ["m1", "m2", "m4", "m8"] in {
        def u64#lmul : VectorInfo<"q"#ComputeVectorNum<6, lmul>.Result#"UWi", 
        "q"#ComputeVectorNum<6, lmul>.Result#"b", u64, "u64"#lmul, 64, ComputeBoolType<ComputeVectorNum<6, lmul>.Result>.Result, "u64m1">;
      }
    }
  }

  defset list<VectorInfo> AllFloatVectorType = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def f16#lmul : VectorInfo<"q"#ComputeVectorNum<4, lmul>.Result#"h",
      "q"#ComputeVectorNum<4, lmul>.Result#"b", f16, "f16"#lmul, 16, ComputeBoolType<ComputeVectorNum<4, lmul>.Result>.Result, "f16m1">;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def f32#lmul : VectorInfo<"q"#ComputeVectorNum<5, lmul>.Result#"f", 
      "q"#ComputeVectorNum<5, lmul>.Result#"b", f32, "f32"#lmul, 32, ComputeBoolType<ComputeVectorNum<5, lmul>.Result>.Result, "f32m1">;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def f64#lmul : VectorInfo<"q"#ComputeVectorNum<6, lmul>.Result#"d",
      "q"#ComputeVectorNum<6, lmul>.Result#"b", f64, "f64"#lmul, 64, ComputeBoolType<ComputeVectorNum<6, lmul>.Result>.Result, "f64m1">;
    }
  }
}

defset list<WideVectorInfo> AllWideVector = {
  defset list<WideVectorInfo> AllWideIntegerVector = {
    foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4"] in {
      def wi8#lmul : WideVectorInfo<!cast<VectorInfo>(i8#lmul), !cast<VectorInfo>(i16#ComputeWideLmul<lmul>.Result)>; 
    }
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      def wi16#lmul : WideVectorInfo<!cast<VectorInfo>(i16#lmul), !cast<VectorInfo>(i32#ComputeWideLmul<lmul>.Result)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in {
      def wi32#lmul : WideVectorInfo<!cast<VectorInfo>(i32#lmul), !cast<VectorInfo>(i64#ComputeWideLmul<lmul>.Result)>;
    }
  }

  defset list<WideVectorInfo> AllWideUnsignedVector = {
    foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4"] in {
      def wu8#lmul : WideVectorInfo<!cast<VectorInfo>("u8"#lmul), !cast<VectorInfo>("u16"#ComputeWideLmul<lmul>.Result)>;
    }
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      def wu16#lmul : WideVectorInfo<!cast<VectorInfo>("u16"#lmul), !cast<VectorInfo>("u32"#ComputeWideLmul<lmul>.Result)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in { 
      def wu32#lmul : WideVectorInfo<!cast<VectorInfo>("u32"#lmul), !cast<VectorInfo>("u64"#ComputeWideLmul<lmul>.Result)>;
    }
  }

  defset list<WideVectorInfo> AllWideFloatVector = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4"] in {
      def wf16#lmul : WideVectorInfo<!cast<VectorInfo>("f16"#lmul), !cast<VectorInfo>("f32"#ComputeWideLmul<lmul>.Result)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4"] in {
      def wf32#lmul : WideVectorInfo<!cast<VectorInfo>("f32"#lmul), !cast<VectorInfo>("f64"#ComputeWideLmul<lmul>.Result)>;
    }
  }
}

defset list<IntToFloat> AllIntToFloat = {
  defset list<IntToFloat> SignedToFloat = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def 16b#lmul : IntToFloat<!cast<VectorInfo>("i16"#lmul), !cast<VectorInfo>("f16"#lmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def 32b#lmul : IntToFloat<!cast<VectorInfo>("i32"#lmul), !cast<VectorInfo>("f32"#lmul)>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def 64b#lmul : IntToFloat<!cast<VectorInfo>("i64"#lmul), !cast<VectorInfo>("f64"#lmul)>;
    }
  }
  defset list<IntToFloat> UnsignedToFloat = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def u16b#lmul : IntToFloat<!cast<VectorInfo>("u16"#lmul), !cast<VectorInfo>("f16"#lmul)>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def u32b#lmul : IntToFloat<!cast<VectorInfo>("u32"#lmul), !cast<VectorInfo>("f32"#lmul)>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def u64b#lmul : IntToFloat<!cast<VectorInfo>("u64"#lmul), !cast<VectorInfo>("f64"#lmul)>;
    }
  }
}

class Inst<string Name, list<string> Types, string Inf, 
           string Suf, int isMask, list<int> TypeOperands> {
  string IntrinsicName = Name;
  list<string> BuiltinStr = Types;
  string Infix = Inf;
  string Suffix = Suf;
  list<int> AnyTypeOperands = TypeOperands;
  int Mask = isMask;
} 

// multiclass binary<string Name, string Types, string Inf, string Suf> {
//   def "" : Inst<Name, Types, Inf, Suf>;
// }
multiclass binary<string name, string result_str, string arg1_str, 
              string arg2_str, string infix, string suffix, string mask_str,
              list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_str, mask_str, result_str,
                        arg1_str, arg2_str], infix, suffix, 1, MaskAnyTypeOperands>;
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str], infix, 
                                suffix, 0, AnyTypeOperands>;
}

multiclass binary_nomask<string name, string result_str, string arg1_str, 
              string arg2_str, string infix, string suffix, string mask_str,
              list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str], infix, 
                                suffix, 0, AnyTypeOperands>;
}

multiclass ternary<string name, string result_str, string arg1_str,
                   string arg2_str, string arg3_str, string infix, string suffix, string mask_str,
                   list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_str, mask_str, arg1_str, arg2_str, arg3_str],
                                      infix, suffix, 1, MaskAnyTypeOperands>;
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str, arg3_str],
                              infix, suffix, 0, AnyTypeOperands>;
}

multiclass unary<string name, string result_str, string arg1_str,
                 string infix, string suffix, string mask_str,
                 list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_str, mask_str, result_str, arg1_str], infix, suffix, 1, MaskAnyTypeOperands>;
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str], infix, suffix, 0, AnyTypeOperands>;
}

multiclass unary_m<string name, string result_str, string arg1_str,
                   string infix, string suffix, string mask_str,
                   list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_str, mask_str, arg1_str], infix, suffix, 1, MaskAnyTypeOperands>;
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str], infix, suffix, 0, AnyTypeOperands>;
}

multiclass unary_nomask<string name, string result_str, string arg1_str,
                 string infix, string suffix, string mask_str,
                 list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str], infix, suffix, 0, AnyTypeOperands>;
}

multiclass ternary_nomask<string name, string result_str, string arg1_str,
                          string arg2_str, string arg3_str, string infix, string suffix, 
                          string mask_str, list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str, arg3_str],
                              infix, suffix, 0, AnyTypeOperands>;
}

multiclass unary_pop<string Name> {
  foreach evr = AllMaskType in {
    defm NAME : unary_m<Name, "ULi", evr.Str, "_m", evr.TypeSuffix, evr.Str, [0], [0, 1]>;
  }
}

multiclass unary_vfirst<string Name> {
  foreach evr = AllMaskType in {
    defm NAME : unary_m<Name, "Li", evr.Str, "_m", evr.TypeSuffix, evr.Str, [0], [0, 1]>;
  }
}

multiclass binary_vmsbf_vmsif_vmsof<string Name> {
  foreach evr = AllMaskType in {
    defm NAME : unary<Name, evr.Str, evr.Str, "_m", evr.TypeSuffix, evr.Str, [-1], [-1]>;
  }
}

multiclass binary_viota<string Name> {
  foreach evr = AllUnsignedVectorType in {
    defm NAME : unary<Name, evr.Str, evr.MaskStr, "_m", evr.TypeSuffix, evr.MaskStr, [-1, 0], [-1, 0, 2]>;
  }
}

multiclass vfcvt<string Name> {
  foreach evr = SignedToFloat in {
    defm NAME : unary<Name, evr.Integer.Str, evr.Float.Str, "_x_f_v", evr.Integer.TypeSuffix,
                      evr.Integer.MaskStr, [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<Name, evr.Integer.Str, evr.Float.Str, "_rtz_x_f_v", evr.Integer.TypeSuffix,
                      evr.Integer.MaskStr, [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<Name, evr.Float.Str, evr.Integer.Str, "_f_x_v", evr.Float.TypeSuffix,
                      evr.Integer.MaskStr, [-1, 0], [-1, 0, 2]>;
  }
  foreach evr = UnsignedToFloat in {
    defm NAME : unary<Name, evr.Integer.Str, evr.Float.Str, "_xu_f_v", evr.Integer.TypeSuffix,
                      evr.Integer.MaskStr, [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<Name, evr.Integer.Str, evr.Float.Str, "_rtz_xu_f_v", evr.Integer.TypeSuffix,
                      evr.Integer.MaskStr, [-1, 0], [-1, 0, 2]>;
    defm NAME : unary<Name, evr.Float.Str, evr.Integer.Str, "_f_xu_v", evr.Float.TypeSuffix,
                      evr.Integer.MaskStr, [-1, 0], [-1, 0, 2]>;
  }
}

multiclass vslide<string Name> {
  foreach evr = AllVector in {
    defm NAME : ternary<Name, evr.Str, evr.Str, evr.Str, "z",
                              "_vx", evr.TypeSuffix, evr.MaskStr, [-1, 2], [-1, 0, 3]>;
  }
}

multiclass int_unary_v_v_v_x<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : unary_nomask<Name, evr.Str, evr.Str, "_v_v", evr.TypeSuffix, "", [-1], []>;
    defm NAME : unary_nomask<Name, evr.Str, evr.ScalarType.Str, "_v_x", evr.TypeSuffix, "", [-1, 0], []>;
  }
}

multiclass int_unary_v_v<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : unary<Name, evr.Str, evr.Str, "_v", evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
  }
}

multiclass vmv_x_s_s_x<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : unary_nomask<Name, evr.ScalarType.Str, evr.Str, "_x_s", evr.TypeSuffix#"_"#evr.ScalarType.Type, 
                             "", [-1, 0], []>;
    defm NAME : binary_nomask<Name, evr.Str, evr.Str, evr.ScalarType.Str, "_s_x", evr.TypeSuffix#"_"#evr.ScalarType.Type,
                             "", [-1, 0, 1], []>;
  }
}

multiclass vfmv_f_s_s_f<string Name> {
  foreach evr = AllFloatVectorType in {
    defm NAME : unary_nomask<Name, evr.ScalarType.Str, evr.Str, "_f_s", evr.TypeSuffix#"_"#evr.ScalarType.Type, 
                             "", [-1, 0], []>;
    defm NAME : binary_nomask<Name, evr.Str, evr.Str, evr.ScalarType.Str, "_s_f", evr.TypeSuffix#"_"#evr.ScalarType.Type,
                             "", [-1, 0, 1], []>;
  }
}

multiclass float_unary_v_v<string Name> {
  foreach evr = AllFloatVectorType in {
    defm NAME : unary<Name, evr.Str, evr.Str, "_v", evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
  }
}

multiclass float_unary_v_f<string Name> {
  foreach evr = AllFloatVectorType in {
    defm NAME : unary_nomask<Name, evr.Str, evr.ScalarType.Str, "_v_f", evr.TypeSuffix, "", [-1, 0], []>;
  }
}

multiclass int_ternary_v_vvm_vxm<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : ternary_nomask<Name, evr.Str, evr.Str, evr.Str, evr.MaskStr, "_vvm",
                          evr.TypeSuffix, "", [-1, 2], []>;
    defm NAME : ternary_nomask<Name, evr.Str, evr.Str, evr.ScalarType.Str, evr.Str, "_vxm",
                          evr.TypeSuffix, "", [-1, 1, 2], []>;
  }
}

multiclass int_vmerge_vvm_vxm<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : ternary_nomask<Name, evr.Str, evr.MaskStr, evr.Str, evr.Str, "_vvm",
                          evr.TypeSuffix, "", [-1, 0], []>;
    defm NAME : ternary_nomask<Name, evr.Str, evr.MaskStr, evr.Str, evr.ScalarType.Str, "_vxm",
                          evr.TypeSuffix, "", [-1, 0, 2], []>; 
  }
}

multiclass float_vmerge_vvm<string Name> {
  foreach evr = AllFloatVectorType in {
    defm NAME : ternary_nomask<Name, evr.Str, evr.MaskStr, evr.Str, evr.Str, "_vvm",
                          evr.TypeSuffix, "", [-1, 0], []>;
  }
}

multiclass float_vmerge_vfm<string Name> {
  foreach evr = AllFloatVectorType in {
    defm NAME : ternary_nomask<Name, evr.Str, evr.MaskStr, evr.Str, evr.ScalarType.Str, "_vfm",
                            evr.TypeSuffix, "", [-1, 0, 2], []>; 
  }
}

multiclass int_binary_v_vv_vx<string Name> {
  foreach evr = AllSignedVectorType in {
    defm NAME : binary<Name, evr.Str, evr.Str, evr.Str, "_vv", 
                          evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<Name, evr.Str, evr.Str, evr.ScalarType.Str,
                          "_vx", evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass int_binary_v_vv_vi8<string Name> {
  foreach evr = AllSignedVectorType in {
    defm NAME : binary<Name, evr.Str, evr.Str, IntToUnsigned<evr>.Result, "_vv", 
                          evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<Name, evr.Str, evr.Str, "Uc",
                          "_vx", evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass reinterpret<string Name> {
  foreach evr = AllSignedVectorType in {
    defm NAME : unary_nomask<Name, evr.Str, IntToUnsigned<evr>.Result, "_v",
                         evr.TypeSuffix#"_"#!subst("i", "u", evr.TypeSuffix), "", [-1, 0], []>;
    defm NAME : unary_nomask<Name, IntToUnsigned<evr>.Result, evr.Str, "_v",
                         !subst("i", "u", evr.TypeSuffix)#"_"#evr.TypeSuffix, "", [-1, 0], []>; 
  }
  foreach evr = AllIntToFloat in {
    defm NAME : unary_nomask<Name, evr.Integer.Str, evr.Float.Str, "_v",
                         evr.Integer.TypeSuffix#"_"#evr.Float.TypeSuffix, "", [-1, 0], []>;
    defm NAME : unary_nomask<Name, evr.Float.Str, evr.Integer.Str, "_v",
                         evr.Float.TypeSuffix#"_"#evr.Integer.TypeSuffix, "", [-1, 0], []>;
  }

  defm NAME : unary_nomask<Name, i16mf4.Str, i8mf4.Str, "_v", "i8mf4"#"_"#!cast<VectorInfo>("i16mf4").TypeSuffix,
                          "", [-1, 0], []>;
  foreach evr = [i16mf2, i32mf2] in {
    defm NAME : unary_nomask<Name, evr.Str, i8mf2.Str, "_v", i8mf2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i16m1, i32m1, i64m1] in {
    defm NAME : unary_nomask<Name, evr.Str, i8m1.Str, "_v", i8m1.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i16m2, i32m2, i64m2] in {
    defm NAME : unary_nomask<Name, evr.Str, i8m2.Str, "_v", i8m2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i16m4, i32m4, i64m4] in {
    defm NAME : unary_nomask<Name, evr.Str, i8m4.Str, "_v", i8m4.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i16m8, i32m8, i64m8] in {
    defm NAME : unary_nomask<Name, evr.Str, i8m8.Str, "_v", i8m8.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  defm NAME : unary_nomask<Name, i8mf4.Str, i16mf4.Str, "_v", "i16mf4"#"_"#!cast<VectorInfo>("i8mf4").TypeSuffix,
                          "", [-1, 0], []>;
  foreach evr = [i8mf2, i32mf2] in {
    defm NAME : unary_nomask<Name, evr.Str, i16mf2.Str, "_v", i16mf2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i8m1, i32m1, i64m1] in {
    defm NAME : unary_nomask<Name, evr.Str, i16m1.Str, "_v", i16m1.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i8m2, i32m2, i64m2] in {
    defm NAME : unary_nomask<Name, evr.Str, i16m2.Str, "_v", i16m2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i8m4, i32m4, i64m4] in {
    defm NAME : unary_nomask<Name, evr.Str, i16m4.Str, "_v", i16m4.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i8m8, i32m8, i64m8] in {
    defm NAME : unary_nomask<Name, evr.Str, i16m8.Str, "_v", i16m8.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i8mf2, i16mf2] in {
    defm NAME : unary_nomask<Name, evr.Str, i32mf2.Str, "_v", i32mf2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i8m1, i16m1, i64m1] in {
    defm NAME : unary_nomask<Name, evr.Str, i32m1.Str, "_v", i32m1.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i8m2, i16m2, i64m2] in {
    defm NAME : unary_nomask<Name, evr.Str, i32m2.Str, "_v", i32m2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i8m4, i16m4, i64m4] in {
    defm NAME : unary_nomask<Name, evr.Str, i32m4.Str, "_v", i32m4.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [i8m8, i16m8, i64m8] in {
    defm NAME : unary_nomask<Name, evr.Str, i32m8.Str, "_v", i32m8.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }

  defm NAME : unary_nomask<Name, u16mf4.Str, u8mf4.Str, "_v", "u8mf4"#"_"#!cast<VectorInfo>("u16mf4").TypeSuffix,
                          "", [-1, 0], []>;
  foreach evr = [u16mf2, u32mf2] in {
    defm NAME : unary_nomask<Name, evr.Str, u8mf2.Str, "_v", i8mf2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u16m1, u32m1, u64m1] in {
    defm NAME : unary_nomask<Name, evr.Str, u8m1.Str, "_v", u8m1.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u16m2, u32m2, u64m2] in {
    defm NAME : unary_nomask<Name, evr.Str, u8m2.Str, "_v", u8m2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u16m4, u32m4, u64m4] in {
    defm NAME : unary_nomask<Name, evr.Str, u8m4.Str, "_v", u8m4.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u16m8, u32m8, u64m8] in {
    defm NAME : unary_nomask<Name, evr.Str, u8m8.Str, "_v", u8m8.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  defm NAME : unary_nomask<Name, u8mf4.Str, u16mf4.Str, "_v", "u16mf4"#"_"#!cast<VectorInfo>("u8mf4").TypeSuffix,
                          "", [-1, 0], []>;
  foreach evr = [u8mf2, u32mf2] in {
    defm NAME : unary_nomask<Name, evr.Str, u16mf2.Str, "_v", u16mf2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u8m1, u32m1, u64m1] in {
    defm NAME : unary_nomask<Name, evr.Str, u16m1.Str, "_v", u16m1.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u8m2, u32m2, u64m2] in {
    defm NAME : unary_nomask<Name, evr.Str, u16m2.Str, "_v", u16m2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u8m4, u32m4, u64m4] in {
    defm NAME : unary_nomask<Name, evr.Str, u16m4.Str, "_v", u16m4.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u8m8, u32m8, u64m8] in {
    defm NAME : unary_nomask<Name, evr.Str, u16m8.Str, "_v", u16m8.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u8mf2, u16mf2] in {
    defm NAME : unary_nomask<Name, evr.Str, u32mf2.Str, "_v", u32mf2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u8m1, u16m1, u64m1] in {
    defm NAME : unary_nomask<Name, evr.Str, u32m1.Str, "_v", u32m1.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u8m2, u16m2, u64m2] in {
    defm NAME : unary_nomask<Name, evr.Str, u32m2.Str, "_v", u32m2.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u8m4, u16m4, u64m4] in {
    defm NAME : unary_nomask<Name, evr.Str, u32m4.Str, "_v", u32m4.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
  foreach evr = [u8m8, u16m8, u64m8] in {
    defm NAME : unary_nomask<Name, evr.Str, u32m8.Str, "_v", u32m8.TypeSuffix#"_"#evr.TypeSuffix, "", [-1, 0], []>;
  }
}

multiclass unsigned_binary_v_vv_vi8<string Name> {
  foreach evr = AllUnsignedVectorType in {
    defm NAME : binary<Name, evr.Str, evr.Str, evr.Str, "_vv", 
                          evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<Name, evr.Str, evr.Str, "Uc",
                          "_vx", evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass binary_m_vv_vx<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : binary<Name, evr.MaskStr, evr.Str, evr.Str, "_vv",
                          evr.TypeSuffix#"_"#evr.BoolType, evr.MaskStr, [-1, 0], [-1, 2, 3]>;
    defm NAME : binary<Name, evr.MaskStr, evr.Str, evr.Str, "_vx",
                          evr.TypeSuffix#"_"#evr.BoolType, evr.MaskStr, [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass int_binary_m_vv_vx<string Name> {
  foreach evr = AllSignedVectorType in {
    defm NAME : binary<Name, evr.MaskStr, evr.Str, evr.Str, "_vv",
                          evr.TypeSuffix#"_"#evr.BoolType, evr.MaskStr, [-1, 0], [-1, 2, 3]>;
    defm NAME : binary<Name, evr.MaskStr, evr.Str, evr.Str, "_vx",
                          evr.TypeSuffix#"_"#evr.BoolType, evr.MaskStr, [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass unsigned_binary_m_vv_vx<string Name> {
  foreach evr = AllUnsignedVectorType in {
    defm NAME : binary<Name, evr.MaskStr, evr.Str, evr.Str, "_vv",
                          evr.TypeSuffix#"_"#evr.BoolType, evr.MaskStr, [-1, 0], [-1, 2, 3]>;
    defm NAME : binary<Name, evr.MaskStr, evr.Str, evr.Str, "_vx",
                          evr.TypeSuffix#"_"#evr.BoolType, evr.MaskStr, [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass float_binary_m_vv_vx<string Name> {
  foreach evr = AllFloatVectorType in {
    defm NAME : binary<Name, evr.MaskStr, evr.Str, evr.Str, "_vv",
                          evr.TypeSuffix#"_"#evr.BoolType, evr.MaskStr, [-1, 0], [-1, 2, 3]>;
    defm NAME : binary<Name, evr.MaskStr, evr.Str, evr.Str, "_vf",
                          evr.TypeSuffix#"_"#evr.BoolType, evr.MaskStr, [-1, 0, 1], [-1, 2, 3]>;
  }
}

multiclass float_binary_v_vv_vf<string Name> {
  foreach evr = AllFloatVectorType in {
    defm NAME : binary<Name, evr.Str, evr.Str, evr.Str, "_vv",
                       evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<Name, evr.Str, evr.Str, evr.ScalarType.Str, "_vf",
                       evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass float_binary_v_vf<string Name> {
  foreach evr = AllFloatVectorType in {
    defm NAME : binary<Name, evr.Str, evr.Str, evr.ScalarType.Str, "_vf",
                       evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass unsigned_binary_v_vv_vx<string Name> {
  foreach evr = AllUnsignedVectorType in {
    defm NAME : binary<Name, evr.Str, evr.Str, evr.Str, "_vv", 
                          evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
    defm NAME : binary<Name, evr.Str, evr.Str, evr.ScalarType.Str,
                          "_vx", evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass binary_v_vx<string Name> {
  foreach evr = AllIntegerVectorType in {
      defm NAME : binary<Name, evr.Str, evr.Str, evr.ScalarType.Str,
                            "_vx", evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass float_ternary_v_vvf_vvv<string Name> {
  foreach evr = AllFloatVectorType in {
    defm NAME : ternary<Name, evr.Str, evr.Str, evr.Str, evr.Str,
                            "_vv", evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
    defm NAME : ternary<Name, evr.Str, evr.Str, evr.ScalarType.Str, evr.Str,
                            "_vf", evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 2]>;
  }
}

multiclass float_ternary_w_wvv_wvf<string Name> {
  foreach evr = AllWideFloatVector in {
    defm NAME : ternary<Name, evr.WideVector.Str, evr.WideVector.Str, evr.OriginVector.Str,
                        evr.OriginVector.Str, "_vv", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr,
                        [-1, 1], [-1, 0, 2]>;
    defm NAME : ternary<Name, evr.WideVector.Str, evr.WideVector.Str, evr.OriginVector.ScalarType.Str, evr.OriginVector.Str,
                        "_vf", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass ternary_v_vvx_vvv<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : ternary<Name, evr.Str, evr.Str, evr.Str, evr.Str,
                            "_vv", evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
    defm NAME : ternary<Name, evr.Str, evr.Str, evr.ScalarType.Str, evr.Str,
                            "_vx", evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 2]>;
  }
}

multiclass int_ternary_v_vs<string Name> {
  foreach evr = AllIntegerVectorType in {
    defvar Lmul1Type = !cast<VectorInfo>(evr.Lmul1Type);
    defm NAME : ternary<Name, Lmul1Type.Str, Lmul1Type.Str, evr.Str, Lmul1Type.Str,
                        "_vs", evr.TypeSuffix#"_"#Lmul1Type.TypeSuffix, evr.MaskStr, [-1, 1],
                        [-1, 0, 2]>;
  }
}

multiclass float_ternary_v_vs<string Name> {
  foreach evr = AllFloatVectorType in {
    defvar Lmul1Type = !cast<VectorInfo>(evr.Lmul1Type);
    defm NAME : ternary<Name, Lmul1Type.Str, Lmul1Type.Str, evr.Str, Lmul1Type.Str,
                        "_vs", evr.TypeSuffix#"_"#Lmul1Type.TypeSuffix, evr.MaskStr, [-1, 1],
                        [-1, 0, 2]>;
  }
}

multiclass int_ternary_w_vvx_vvv<string Name> {
  foreach evr = AllWideIntegerVector in {
    defm NAME : ternary<Name, evr.WideVector.Str, evr.WideVector.Str, 
                        evr.OriginVector.Str, evr.OriginVector.Str, 
                        "_vv", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1], [-1, 0, 2]>;
    defm NAME : ternary<Name, evr.WideVector.Str, evr.WideVector.Str, 
                        evr.OriginVector.ScalarType.Str, evr.OriginVector.Str, "_vx",
                        evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass unsigned_ternary_w_vvx_vvv<string Name> {
  foreach evr = AllWideUnsignedVector in {
    defm NAME : ternary<Name, evr.WideVector.Str, evr.WideVector.Str, 
                        evr.OriginVector.Str, evr.OriginVector.Str, 
                        "_vv", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1], [-1, 0, 2]>;
    defm NAME : ternary<Name, evr.WideVector.Str, evr.WideVector.Str, 
                        evr.OriginVector.ScalarType.Str, evr.OriginVector.Str, "_vx",
                        evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass int_ternary_w_vvx<string Name> {
  foreach evr = AllWideIntegerVector in {
    defm NAME : ternary<Name, evr.WideVector.Str, evr.WideVector.Str, 
                        evr.OriginVector.ScalarType.Str, evr.OriginVector.Str, "_vx",
                        evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1, 2], [-1, 0, 2, 3]>;
  }
}

multiclass int_binary_w_vv_vx_wv_wx<string Name> {
  foreach evr = AllWideIntegerVector in {
    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, 
                evr.OriginVector.Str, "_vv", evr.WideVector.TypeSuffix, 
                evr.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, evr.OriginVector.ScalarType.Str,
                "_vx", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 0, 1], [-1, 0, 2, 3]>;

    defm NAME : binary<Name, evr.WideVector.Str, evr.WideVector.Str, evr.OriginVector.Str, 
                "_wv", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : binary<Name, evr.WideVector.Str, evr.WideVector.Str, evr.OriginVector.ScalarType.Str, 
                "_wx", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass float_binary_w_vv_vf_wv_wf<string Name> {
  foreach evr = AllWideFloatVector in {
    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, 
                evr.OriginVector.Str, "_vv", evr.WideVector.TypeSuffix, 
                evr.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, evr.OriginVector.ScalarType.Str,
                "_vf", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 0, 1], [-1, 0, 2, 3]>;

    defm NAME : binary<Name, evr.WideVector.Str, evr.WideVector.Str, evr.OriginVector.Str, 
                "_wv", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : binary<Name, evr.WideVector.Str, evr.WideVector.Str, evr.OriginVector.ScalarType.Str, 
                "_wf", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass int_binary_v_wv_wx<string Name> {
  foreach evr = AllWideIntegerVector in {
    defm NAME : binary<Name, evr.OriginVector.Str, evr.WideVector.Str, evr.OriginVector.Str, 
                "_wv", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;
            
    defm NAME : binary<Name, evr.OriginVector.Str, evr.WideVector.Str, evr.OriginVector.ScalarType.Str, 
                "_wx", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

multiclass unsigned_binary_v_wv_wx<string Name> {
  foreach evr = AllWideUnsignedVector in {
    defm NAME : binary<Name, evr.OriginVector.Str, evr.WideVector.Str, evr.OriginVector.Str, 
                "_wv", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : binary<Name, evr.OriginVector.Str, evr.WideVector.Str, evr.OriginVector.ScalarType.Str, 
                "_wx", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 1], [-1, 0, 3]>;
  }
}

multiclass int_binary_w_vv_vx<string Name> {
  foreach evr = AllWideIntegerVector in {
    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, 
                evr.OriginVector.Str, "_vv", evr.WideVector.TypeSuffix, 
                evr.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, evr.OriginVector.ScalarType.Str,
                "_vx", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

multiclass float_binary_w_vv_vf<string Name> {
  foreach evr = AllWideFloatVector in {
    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, 
                evr.OriginVector.Str, "_vv", evr.WideVector.TypeSuffix, 
                evr.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, evr.OriginVector.ScalarType.Str,
                "_vf", evr.WideVector.TypeSuffix, evr.WideVector.MaskStr, [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

multiclass unsigned_binary_w_vv_vx<string Name> {
  foreach evr = AllWideUnsignedVector in {
    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, 
                evr.OriginVector.Str, "_vv", evr.WideVector.TypeSuffix,
                evr.WideVector.MaskStr, [-1, 0], [-1, 0, 2]>;
    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, 
                evr.OriginVector.ScalarType.Str,"_vx", evr.WideVector.TypeSuffix,
                 evr.WideVector.MaskStr, [-1, 0, 1], [-1, 0, 2, 3]>;
  }
}

multiclass unsigned_binary_w_vv_vx_wv_wx<string Name> {
  foreach evr = AllWideUnsignedVector in {
    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, 
                evr.OriginVector.Str, "_vv", evr.WideVector.TypeSuffix, evr.WideVector.TypeSuffix, [-1, 0], [-1, 0, 2]>;

    defm NAME : binary<Name, evr.WideVector.Str, evr.OriginVector.Str, evr.OriginVector.ScalarType.Str,
                "_vx", evr.WideVector.TypeSuffix, evr.WideVector.TypeSuffix, [-1, 0, 1], [-1, 0, 2, 3]>;

    defm NAME : binary<Name, evr.WideVector.Str, evr.WideVector.Str, evr.OriginVector.Str, 
                "_wv", evr.WideVector.TypeSuffix, evr.WideVector.TypeSuffix, [-1, 1], [-1, 0, 3]>;
            
    defm NAME : binary<Name, evr.WideVector.Str, evr.WideVector.Str, evr.OriginVector.ScalarType.Str, 
                "_wx", evr.WideVector.TypeSuffix, evr.WideVector.TypeSuffix, [-1, 1], [-1, 0, 3]>;
  }    
}

multiclass vsetvl {
  foreach suffix = ["e32mf2", "e32m1", "e32m2", "e32m4", "e32m8"] in {
      def NAME#suffix : Inst<"vsetvl", ["z", "z", "z"], "", suffix, 0, [-1]>;
  }
}

multiclass load_store {
  foreach evr = AllVector in {
    def "vle"#evr.SEW#"_v"#evr.TypeSuffix : Inst<"vle"#evr.SEW, 
      [evr.Str, evr.ScalarType.Str#"C*"], "_v", evr.TypeSuffix, 0, [-1, 0]>;
    def "vle"#evr.SEW#"_v"#evr.TypeSuffix#"_mask" : Inst<"vle"#evr.SEW, 
      [evr.Str, evr.MaskStr, evr.Str, evr.ScalarType.Str#"C*"], "_v", evr.TypeSuffix, 1, [-1, 0, 2]>;
    def "vse"#evr.SEW#"_v"#evr.TypeSuffix : Inst<"vse"#evr.SEW, 
      ["v", evr.ScalarType.Str#"*", evr.Str], "_v", evr.TypeSuffix, 0, [0, 1]>;
    def "vse"#evr.SEW#"_v"#evr.TypeSuffix#"_mask" : Inst<"vse"#evr.SEW,
      ["v", evr.MaskStr, evr.Str, evr.ScalarType.Str#"C*"], "_v", evr.TypeSuffix, 1, [0, 1, 2]>;
    def "vlse"#evr.SEW#"_v"#evr.TypeSuffix : Inst<"vlse"#evr.SEW,
      [evr.Str, evr.ScalarType.Str#"C*", "Y"], "_v", evr.TypeSuffix, 0, [-1, 0]>;
    def "vlse"#evr.SEW#"_v"#evr.TypeSuffix#"_mask" : Inst<"vlse"#evr.SEW,
      [evr.Str, evr.MaskStr, evr.Str, evr.ScalarType.Str#"C*", "Y"], "_v", evr.TypeSuffix, 1, [-1, 0, 2]>;
    def "vsse"#evr.SEW#"_v"#evr.TypeSuffix : Inst<"vsse"#evr.SEW, 
      ["v", evr.ScalarType.Str#"*", "Y", evr.Str], "_v", evr.TypeSuffix, 0, [0, 2]>;
    def "vsse"#evr.SEW#"_v"#evr.TypeSuffix#"_mask" : Inst<"vsse"#evr.SEW,
      ["v", evr.MaskStr, evr.ScalarType.Str#"*", "Y", evr.Str], "_v", evr.TypeSuffix, 1, [0, 1, 2]>;
    // def "vlxei"#evr.SEW#"_v"#evr.TypeSuffix : Inst<"vlxei"#evr.SEW,
    //   [evr.Str, evr.ScalarType.Str#"C*", !cast<VectorInfo>(!subst("i", "u", !cast<string>(evr))).Str],
    //    "_v", evr.TypeSuffix, 0, [-1, 0, 1]>;
    // def "vlxei"#evr.SEW#"_v"#evr.TypeSuffix#"_mask" : Inst<"vlxei"#evr.SEW, 
    //   [evr.Str, evr.MaskStr, evr.Str, evr.ScalarType.Str#"C*", !cast<VectorInfo>(!subst("i", "u", !cast<string>(evr))).Str],
    //    "_v", evr.TypeSuffix, 1, [-1, 0, 2, 3]>;
    // def "vsxei"#evr.SEW#"_v"#evr.TypeSuffix : Inst<"vsxei"#evr.SEW,
    //   ["v", evr.ScalarType.Str#"C*", !cast<VectorInfo>(!subst("i", "u", !cast<string>(evr))).Str, evr.Str],
    //   "_v", evr.TypeSuffix, 0, [0, 2, 3]>;
    // def "vsxei"#evr.SEW#"_v"#evr.TypeSuffix#"_mask" : Inst<"vsxei"#evr.SEW,
    //   ["v", evr.MaskStr, evr.ScalarType.Str#"C*", !cast<VectorInfo>(!subst("i", "u", !cast<string>(evr))).Str, 
    //   evr.Str], "_v", evr.TypeSuffix, 1, [0, 1, 2, 3]>;
  }
}

defm vmul : int_binary_v_vv_vx<"vmul">;
defm vmul : unsigned_binary_v_vv_vx<"vmul">;
defm vadd : int_binary_v_vv_vx<"vadd">;
defm vadd : unsigned_binary_v_vv_vx<"vadd">;
defm vsub : int_binary_v_vv_vx<"vsub">;
defm vsub : unsigned_binary_v_vv_vx<"vsub">;
defm vrsub : binary_v_vx<"vrsub">;
defm vand : int_binary_v_vv_vx<"vand">;
defm vand : unsigned_binary_v_vv_vx<"vand">;
defm vxor : int_binary_v_vv_vx<"vxor">;
defm vxor : unsigned_binary_v_vv_vx<"vxor">;
defm vor : int_binary_v_vv_vx<"vor">; 
defm vor : unsigned_binary_v_vv_vx<"vor">;

defm vwadd : int_binary_w_vv_vx_wv_wx<"vwadd">;
defm vwsub : int_binary_w_vv_vx_wv_wx<"vwsub">;
defm vwaddu : unsigned_binary_w_vv_vx_wv_wx<"vwaddu">;
defm vwsubu : unsigned_binary_w_vv_vx_wv_wx<"vwsubu">;
defm vadc : int_ternary_v_vvm_vxm<"vadc">;
defm vsbc : int_ternary_v_vvm_vxm<"vsbc">;

defm vsll : int_binary_v_vv_vi8<"vsll">;
defm vsll : unsigned_binary_v_vv_vi8<"vsll">;
defm vsrl : int_binary_v_vv_vi8<"vsrl">;
defm vsrl : unsigned_binary_v_vv_vi8<"vsrl">;
defm vsra : int_binary_v_vv_vi8<"vsra">;
defm vmin : int_binary_v_vv_vx<"vmin">;
defm vminu : unsigned_binary_v_vv_vx<"vminu">;
defm vmax : int_binary_v_vv_vx<"vmax">;
defm vmaxu : unsigned_binary_v_vv_vx<"vmaxu">;
defm vmulh : int_binary_v_vv_vx<"vmulh">;
defm vmulhu : unsigned_binary_v_vv_vx<"vmulhu">;
defm vmulhsu : int_binary_v_vv_vx<"vmulhsu">;
defm vdiv : int_binary_v_vv_vx<"vdiv">;
defm vdivu : unsigned_binary_v_vv_vx<"vdivu">;
defm vrem : int_binary_v_vv_vx<"vrem">;
defm vremu : unsigned_binary_v_vv_vx<"vremu">;
defm vmacc : ternary_v_vvx_vvv<"vmacc">;
defm vnmsac : ternary_v_vvx_vvv<"vnmsac">;
defm vmadd : ternary_v_vvx_vvv<"vmadd">;
defm vnmsub : ternary_v_vvx_vvv<"vnmsub">;
defm vwmacc : int_ternary_w_vvx_vvv<"vwmacc">;
defm vwmaccu : unsigned_ternary_w_vvx_vvv<"vwmaccu">;
defm vwmaccsu : int_ternary_w_vvx_vvv<"vwmaccsu">;
defm vwmaccus : int_ternary_w_vvx<"vwmaccus">;
defm vmerge : int_vmerge_vvm_vxm<"vmerge">;
defm vsadd : int_binary_v_vv_vx<"vsadd">;
defm vsaddu : unsigned_binary_v_vv_vx<"vsaddu">;
defm vssub : int_binary_v_vv_vx<"vssub">;
defm vssubu : unsigned_binary_v_vv_vx<"vssubu">;
defm vaadd : int_binary_v_vv_vx<"vaadd">;
defm vaaddu : unsigned_binary_v_vv_vx<"vaaddu">;
defm vasub : int_binary_v_vv_vx<"vasub">;
defm vasubu : unsigned_binary_v_vv_vx<"vasubu">; 
defm vsmul : int_binary_v_vv_vx<"vsmul">;
defm vssrl : unsigned_binary_v_vv_vx<"vssrl">;
defm vssra : int_binary_v_vv_vx<"vssra">;
defm vnclip : int_binary_v_wv_wx<"vnclip">;
defm vnclipu : unsigned_binary_v_wv_wx<"vnclipu">;
defm vfadd : float_binary_v_vv_vf<"vfadd">;
defm vfsub : float_binary_v_vv_vf<"vfsub">;
defm vfrsub : float_binary_v_vf<"vfrsub">;
defm vfwadd : float_binary_w_vv_vf_wv_wf<"vfwadd">;
defm vfwsub : float_binary_w_vv_vf_wv_wf<"vfwsub">;
defm vfmul : float_binary_v_vv_vf<"vfmul">;
defm vfdiv : float_binary_v_vv_vf<"vfdiv">;
defm vfrdiv : float_binary_v_vf<"vfrdiv">;
defm vfwmul : float_binary_w_vv_vf<"vfwmul">;
defm vnsrl : unsigned_binary_v_wv_wx<"vnsrl">;
defm vnsra : int_binary_v_wv_wx<"vnsra">;
defm vmseq : binary_m_vv_vx<"vmseq">;
defm vmsne : binary_m_vv_vx<"vmsne">;
defm vmslt : int_binary_m_vv_vx<"vmslt">;
defm vmsltu : unsigned_binary_m_vv_vx<"vmsltu">;
defm vmsle : int_binary_m_vv_vx<"vmsle">;
defm vmsleu : unsigned_binary_m_vv_vx<"vmsleu">;
defm vmsgt : int_binary_m_vv_vx<"vmsgt">;
defm vmsgtu : unsigned_binary_m_vv_vx<"vmsgtu">;
defm vmsge : int_binary_m_vv_vx<"vmsge">;
defm vmsgeu : unsigned_binary_m_vv_vx<"vmsgeu">;

defm vfmacc : float_ternary_v_vvf_vvv<"vfmacc">;
defm vfnmacc : float_ternary_v_vvf_vvv<"vfnmacc">;
defm vfmsac : float_ternary_v_vvf_vvv<"vfmsac">;
defm vfmadd : float_ternary_v_vvf_vvv<"vfmadd">;
defm vfnmadd : float_ternary_v_vvf_vvv<"vfnmadd">;
defm vfmsub : float_ternary_v_vvf_vvv<"vfmsub">;
defm vfnmsub : float_ternary_v_vvf_vvv<"vfnmsub">;
defm vfwmacc : float_ternary_w_wvv_wvf<"vfwmacc">;
defm vfwnmacc : float_ternary_w_wvv_wvf<"vfwnmacc">;
defm vfwmsac : float_ternary_w_wvv_wvf<"vfwmsac">;
defm vfwnmsac : float_ternary_w_wvv_wvf<"vfwnmsac">;
defm vfsqrt : float_unary_v_v<"vfsqrt">;
defm vfmin : float_binary_v_vv_vf<"vfmin">;
defm vfmax : float_binary_v_vv_vf<"vfmax">;
defm vfsgnj : float_binary_v_vv_vf<"vfsgnj">;
defm vfsgnjn : float_binary_v_vv_vf<"vfsgnjn">;
defm vfsgnjx : float_binary_v_vv_vf<"vfsgnjx">;
defm vmfeq : float_binary_m_vv_vx<"vmfeq">;
defm vmfne : float_binary_m_vv_vx<"vmfne">;
defm vmflt : float_binary_m_vv_vx<"vmflt">;
defm vmfle : float_binary_m_vv_vx<"vmfle">;
defm vmfgt : float_binary_m_vv_vx<"vmfgt">;
defm vmfge : float_binary_m_vv_vx<"vmfge">;
defm vmv : int_unary_v_v_v_x<"vmv">;
defm vfmv : float_unary_v_f<"vfmv">;
defm vmerge : float_vmerge_vvm<"vmerge">;
defm vfmerge : float_vmerge_vfm<"vfmerge">;
defm vslideup : vslide<"vslideup">;
defm vslidedown : vslide<"vslidedown">;
defm vslide1up : binary_v_vx<"vslide1up">;
defm vslide1down : binary_v_vx<"vslide1down">;
defm vfslide1up : float_binary_v_vf<"vfslide1up">;
defm vfslide1down : float_binary_v_vf<"vfslide1down">;
defm vmv : vmv_x_s_s_x<"vmv">;
defm vfmv : vfmv_f_s_s_f<"vfmv">;
defm vredsum : int_ternary_v_vs<"vredsum">;
defm vredmax : int_ternary_v_vs<"vredmax">;
defm vredmaxu : int_ternary_v_vs<"vredmaxu">;
defm vredmin : int_ternary_v_vs<"vredmin">;
defm vredminu : int_ternary_v_vs<"vredminu">;
defm vredand : int_ternary_v_vs<"vredand">;
defm vredor : int_ternary_v_vs<"vredor">;
defm vredxor : int_ternary_v_vs<"vredxor">;
defm vfredsum : float_ternary_v_vs<"vfredsum">;
defm vfredosum : float_ternary_v_vs<"vfredosum">;
defm vfredmax : float_ternary_v_vs<"vfredmax">;
defm vfredmin : float_ternary_v_vs<"vfredmin">;
defm vfcvt : vfcvt<"vfcvt">;
defm vreinterpret : reinterpret<"vreinterpret">;
defm vpopc : unary_pop<"vpopc">;
defm vfirst : unary_vfirst<"vfirst">;
defm vmsbf : binary_vmsbf_vmsif_vmsof<"vmsbf">;
defm vmsif : binary_vmsbf_vmsif_vmsof<"vmsif">;
defm vmsof : binary_vmsbf_vmsif_vmsof<"vmsof">;
defm viota : binary_viota<"viota">;

defm "" : load_store;
defm "" : vsetvl;


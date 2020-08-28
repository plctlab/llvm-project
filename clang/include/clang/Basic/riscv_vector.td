class ScalarInfo<string TypeName, string TypeStr> {
  string Type = TypeName;
  string Str = TypeStr;
}

class VectorInfo<string TypeName, string TypeStr, string MType, string MStr, 
              ScalarInfo Sca, string Suf, int Sew> {
  string Type = TypeName;
  string Str = TypeStr;
  string TypeSuffix = Suf;
  string MaskType = MType;
  string MaskStr = MStr;
  int SEW = Sew;
  ScalarInfo ScalarType = Sca;
}

class WideVectorInfo<VectorInfo Origin, VectorInfo Wide> {
  VectorInfo WideVector = Wide;
  VectorInfo OriginVector = Origin;
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

defset list<ScalarInfo> AllScalarType = {
  def i8 : ScalarInfo<"int8_t", "c">;
  def i16 : ScalarInfo<"int16_t", "s">;
  def i32 : ScalarInfo<"int32_t", "i">;
  def i64 : ScalarInfo<"int64_t", "Wi">;
  def f16 : ScalarInfo<"float16_t", "h">;
  def f32 : ScalarInfo<"float32_t", "f">;
  def f64 : ScalarInfo<"float64_t", "d">;
}

defset list<VectorInfo> AllVector = {
  defset list<VectorInfo> AllIntegerVectorType = {
    defset list<VectorInfo> AllSignedVectorType = {
      foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        def i8#lmul : VectorInfo<"vint8"#lmul#"_t", "q"#ComputeVectorNum<3, lmul>.Result#"c",
        "vbool8"#lmul#"_t", "q"#ComputeVectorNum<3, lmul>.Result#"b", i8, "u8"#lmul, 8>;
        
      }
      foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        def i16#lmul : VectorInfo<"vint16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"s", 
        "vbool16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"b", i16, "i16"#lmul, 16>;
      }

      foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
        def i32#lmul : VectorInfo<"vint32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"i", 
        "vbool32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"b", i32, "32"#lmul, 32>;
      }
      
      foreach lmul = ["m1", "m2", "m4", "m8"] in {
        def i64#lmul : VectorInfo<"vint64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"Wi", 
        "vbool64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"b", i64, "i64"#lmul, 64>;
      }
    }
    defset list<VectorInfo> AllUnsignedVectorType = {
      foreach lmul = ["mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        def u8#lmul : VectorInfo<"vuint8"#lmul#"_t", "q"#ComputeVectorNum<3, lmul>.Result#"Uc",
        "vbool8"#lmul#"_t", "q"#ComputeVectorNum<3, lmul>.Result#"b", i8, "i8"#lmul, 8>;
      }
      foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
        def u16#lmul : VectorInfo<"vuint16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"Us", 
        "vbool16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"b", i16, "u16"#lmul, 16>;
      }
      foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
        def u32#lmul : VectorInfo<"vuint32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"Ui", 
        "vbool32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"b", i32, "u32"#lmul, 32>;
      }
      foreach lmul = ["m1", "m2", "m4", "m8"] in {
        def u64#lmul : VectorInfo<"vuint64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"UWi", 
        "vbool64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"b", i64, "u64"#lmul, 64>;
      }
    }
  }

  defset list<VectorInfo> AllFloatVectorType = {
    foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
      def f16#lmul : VectorInfo<"vfloat16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"h",
      "vbool16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"b", f16, "f16"#lmul, 16>;
    }
    foreach lmul = ["mf2", "m1", "m2", "m4", "m8"] in {
      def f32#lmul : VectorInfo<"vfloat32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"f", 
      "vbool32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"b", f32, "f32"#lmul, 32>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def f64#lmul : VectorInfo<"vfloat64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"d",
      "vbool64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"b", f64, "f64"#lmul, 64>;
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

multiclass ternary<string name, string result_str, string arg1_str,
                   string arg2_str, string arg3_str, string infix, string suffix, string mask_str,
                   list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix#"_mask" : Inst<name, [result_str, mask_str, arg1_str, arg2_str, arg3_str],
                                      infix, suffix, 1, MaskAnyTypeOperands>;
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str, arg3_str],
                              infix, suffix, 0, AnyTypeOperands>;
}

multiclass ternary_nomask<string name, string result_str, string arg1_str,
                          string arg2_str, string arg3_str, string infix, string suffix, 
                          string mask_str, list<int> AnyTypeOperands, list<int> MaskAnyTypeOperands> {
  def NAME#infix#suffix : Inst<name, [result_str, arg1_str, arg2_str, arg3_str],
                              infix, suffix, 0, AnyTypeOperands>;
}

multiclass int_ternary_v_vvm_vxm<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : ternary_nomask<Name, evr.Str, evr.Str, evr.Str, evr.MaskStr, "_vvm",
                          evr.TypeSuffix, "", [-1, 2], []>;
    defm NAME : ternary_nomask<Name, evr.Str, evr.Str, evr.ScalarType.Str, evr.Str, "_vxm",
                          evr.TypeSuffix, "", [-1, 1, 2], []>;
  }
}

multiclass int_vmerge<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : ternary_nomask<Name, evr.Str, evr.MaskStr, evr.Str, evr.Str, "_vvm",
                          evr.TypeSuffix, "", [-1, 0], []>;
    defm NAME : ternary_nomask<Name, evr.Str, evr.MaskStr, evr.Str, evr.ScalarType.Str, "_vxm",
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

multiclass int_binary_v_vx<string Name> {
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

multiclass ternary_v_vvx_vvv<string Name> {
  foreach evr = AllIntegerVectorType in {
    defm NAME : ternary<Name, evr.Str, evr.Str, evr.Str, evr.Str,
                            "_vv", evr.TypeSuffix, evr.MaskStr, [-1], [-1, 0]>;
    defm NAME : ternary<Name, evr.Str, evr.Str, evr.ScalarType.Str, evr.Str,
                            "_vx", evr.TypeSuffix, evr.MaskStr, [-1, 1], [-1, 0, 2]>;
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
    def "vse"#evr.SEW#"_v"#evr.TypeSuffix : Inst<"vse"#evr.SEW, 
      ["v", evr.ScalarType.Str#"*", evr.Str], "_v", evr.TypeSuffix, 0, [0, 1]>;
  }
}

defm vmul : int_binary_v_vv_vx<"vmul">;
defm vmul : unsigned_binary_v_vv_vx<"vmul">;
defm vadd : int_binary_v_vv_vx<"vadd">;
defm vadd : unsigned_binary_v_vv_vx<"vadd">;
defm vsub : int_binary_v_vv_vx<"vsub">;
defm vsub : unsigned_binary_v_vv_vx<"vsub">;
defm vrsub : int_binary_v_vx<"vrsub">;
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

defm vsll : int_binary_v_vv_vx<"vsll">;
defm vsrl : int_binary_v_vv_vx<"vsrl">;
defm vsra : int_binary_v_vv_vx<"vsra">;
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
defm vmerge : int_vmerge<"vmerge">;
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



defm vfmacc : float_ternary_v_vvf_vvv<"vfmacc">;
defm "" : load_store;
defm "" : vsetvl;


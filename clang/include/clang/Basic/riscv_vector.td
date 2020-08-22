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
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def i8#lmul : VectorInfo<"vint8"#lmul#"_t", "q"#ComputeVectorNum<3, lmul>.Result#"c",
      "vbool8"#lmul#"_t", "q"#ComputeVectorNum<3, lmul>.Result#"b", i8, "i8"#lmul, 8>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def i16#lmul : VectorInfo<"vint16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"s", 
      "vbool16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"b", i16, "i16"#lmul, 16>;
    }

    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def i32#lmul : VectorInfo<"vint32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"i", 
      "vbool32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"b", i32, "i32"#lmul, 32>;
    }
    
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def i64#lmul : VectorInfo<"vint64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"Wi", 
      "vbool64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"b", i64, "i64"#lmul, 64>;
    }
  }

  defset list<VectorInfo> AllFloatVectorType = {
    // foreach lmul = ["mf4", "mf2", "m1", "m2", "m4", "m8"] in {
    //   def f16#lmul : VectorInfo<"vfloat16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"h",
    //   "vbool16"#lmul#"_t", "q"#ComputeVectorNum<4, lmul>.Result#"b", f16, "f16"#lmul, 16>;
    // }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def f32#lmul : VectorInfo<"vfloat32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"f", 
      "vbool32"#lmul#"_t", "q"#ComputeVectorNum<5, lmul>.Result#"b", f32, "f32"#lmul, 32>;
    }
    foreach lmul = ["m1", "m2", "m4", "m8"] in {
      def f64#lmul : VectorInfo<"vfloat64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"d",
      "vbool64"#lmul#"_t", "q"#ComputeVectorNum<6, lmul>.Result#"b", f64, "f64"#lmul, 64>;
    }
  }
}

// defset list<TypeInfo> allScalarType = {
//   def i8 : 
// }
class Inst<string Name, list<string> Types, string Inf, string Suf> {
  string IntrinsicName = Name;
  // list<TypeInfo> Operands = Types;
  list<string> BuiltinStr = Types;
  // string BuiltinStr = Types;
  string Infix = Inf;
  string Suffix = Suf;
  list<int> AnyTypeOperands;
} 

// multiclass binary<string Name, string Types, string Inf, string Suf> {
//   def "" : Inst<Name, Types, Inf, Suf>;
// }

multiclass int_binary_v_vv_vx<string Name> {
  foreach evr = AllIntegerVectorType in {
    let AnyTypeOperands = [-1] in {
      def NAME#"_"#"vv"#evr.TypeSuffix : Inst<Name, [evr.Str, evr.Str, evr.Str], "_vv", evr.TypeSuffix>;
      def NAME#"_"#"vx"#evr.TypeSuffix : Inst<Name, [evr.Str, evr.Str, evr.ScalarType.Str], "_vx", evr.TypeSuffix>;
    }
  }
}

multiclass float_ternary_v_vvf_vvv<string Name> {
  foreach evr = AllFloatVectorType in {
    let AnyTypeOperands = [-1] in {
      def NAME#"_vv"#evr.TypeSuffix : Inst<Name, [evr.Str, evr.Str, evr.Str, evr.Str], "_vv", evr.TypeSuffix>;
    }
    let AnyTypeOperands = [-1, 1] in {
      def NAME#"_vf"#evr.TypeSuffix : Inst<Name, [evr.Str, evr.Str, evr.ScalarType.Str, evr.Str], "_vf", evr.TypeSuffix>;
    }
  }
}

multiclass vsetvl {
  foreach suffix = ["e32m8"] in {
    let AnyTypeOperands = [-1] in {
      def NAME#suffix : Inst<"vsetvl", ["z", "z", "z"], "", suffix>;
    }
  }
}

multiclass load_store {
  foreach evr = AllVector in {
    let AnyTypeOperands = [-1, 0] in {
      def "vle"#evr.SEW#"_v"#evr.TypeSuffix : Inst<"vle"#evr.SEW, [evr.Str, evr.ScalarType.Str#"C*"], "_v", evr.TypeSuffix>;
    }
    let AnyTypeOperands = [0, 1] in {
      def "vse"#evr.SEW#"_v"#evr.TypeSuffix : Inst<"vse"#evr.SEW, ["v", evr.ScalarType.Str#"*", evr.Str], "_v", evr.TypeSuffix>;
    }
  }
}

defm vmul : int_binary_v_vv_vx<"vmul">;
// defm vadd : int_binary_v_vv_vx<"vadd">;
// defm vsub : int_binary_v_vv_vx<"vsub">;
// defm vand : int_binary_v_vv_vx<"vand">;
// defm vxor : int_binary_v_vv_vx<"vxor">;
// defm vor : int_binary_v_vv_vx<"vor">; 

// multiclass binary_w_vv_vx_wv_wx<string Name> {
//   foreach evr = AllIntegerVectorType in {
//     let AnyTypeOperands = [-1, 0] in {
//       def NAME # "_" #evr.TypeSuffix : Inst<Name, evr.Str#evr.Str#evr.Str, "_vv", evr.TypeSuffix>;
//     }
//   }
// }

// defm vwadd : binary_w_vv_vx_wv_wx<"vwadd">;
defm vfmacc : float_ternary_v_vvf_vvv<"vfmacc">;
defm "" : load_store;
defm "" : vsetvl;


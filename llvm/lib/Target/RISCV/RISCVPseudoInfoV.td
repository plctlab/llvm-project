//===-- RISCVPseudoInfoV.td - RISC-V 'V' instructions -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// This file describes the RISC-V instructions from the standard 'V' Vector
/// extension, version 0.9.
/// This version is still experimental as the 'V' extension hasn't been
/// ratified yet.
///
//===----------------------------------------------------------------------===//

// Join strings in list using separator and ignoring empty elements
class Join<list<string> strings, string seperator> {
  string Result = !foldl(!head(strings), !tail(strings), a, b, 
                        !cond(
                          !and(!empty(a), !empty(b)) : "",
                          !empty(a):b,
                          !empty(b):a,
                          1 : a#seperator#b));
}

class ToScalarOp<ValueType type, DAGOperand operand, string name> {
  dag Result = !cond(!eq(!cast<string>(operand), !cast<string>(GPR)) : !dag(type, [GPR], [name]),
                     !eq(!cast<string>(operand), !cast<string>(FPR32)) : !dag(type, [FPR32], [name]),
                     1 : !dag(type, [operand], [name]));
}

class VectorTypeInfo<ValueType Vec, ValueType Mas, int Sew, RegisterClass Reg, int Lmul> {
  ValueType Vector = Vec;
  ValueType Mask = Mas;
  int SEW = Sew;
  RegisterClass RegClass = Reg;
  int LMUL = Lmul;
} 

class VlmulToRC<string Lmul, RegisterClass Reg, int LmulValue> {
  string lmulstr = Lmul;
  RegisterClass RegClass = Reg;
  int Vlmul = LmulValue;
} 

defset list<VlmulToRC> AllVlmuls = {
  // TODO: fractional lmul
  // def MF8 : VlmulToRC<"F8", VR>;
  // def MF4 : VlmulToRC<"F4", VR>;
  // def MF2 : VlmulToRC<"F2", VR>;
  def M1 : VlmulToRC<"1", VR, 1>;
  def M2 : VlmulToRC<"2", VRM2, 2>;
  def M4 : VlmulToRC<"4", VRM4, 4>;
  def M8 : VlmulToRC<"8", VRM8, 8>;
}

defset list<VectorTypeInfo> AllVectors = {
  defset list<VectorTypeInfo> AllIntegerVectors = {
    defset list<VectorTypeInfo> NoGroupIntegerVectors = {
      def Vtypev8xi8 : VectorTypeInfo<nxv8i8, nxv8i1, 8, VR, 1>;
      def Vtypev4xi16 : VectorTypeInfo<nxv4i16, nxv4i1, 16, VR, 1>;
      def Vtypev2xi32 : VectorTypeInfo<nxv2i32, nxv2i1, 32, VR, 1>;
      def Vtypev1xi64 : VectorTypeInfo<nxv1i64, nxv1i1, 64, VR, 1>;
    }

    defset list<VectorTypeInfo> GroupIntegerVectors = {
      def Vtypev16xi8 : VectorTypeInfo<nxv16i8, nxv16i1, 8, VRM2, 2>;
      def Vtypev8xi16 : VectorTypeInfo<nxv8i16, nxv8i1, 16, VRM2, 2>;
      def Vtypev4xi32 : VectorTypeInfo<nxv4i32, nxv4i1, 32, VRM2, 2>;
      def Vtypev2xi64 : VectorTypeInfo<nxv2i64, nxv2i1, 64, VRM2, 2>;

      def Vtypev32xi8 : VectorTypeInfo<nxv32i8, nxv32i1, 8, VRM4, 4>;
      def Vtypev16xi16 : VectorTypeInfo<nxv16i16, nxv16i1, 16, VRM4, 4>;
      def Vtypev8xi32 : VectorTypeInfo<nxv8i32, nxv8i1, 32, VRM4, 4>;
      def Vtypev4i64 : VectorTypeInfo<nxv4i64, nxv4i1, 64, VRM4, 4>;

      def Vtypev64xi8 : VectorTypeInfo<nxv64i8, nxv64i1, 8, VRM8, 8>;
      def Vtypev32xi16 : VectorTypeInfo<nxv32i16, nxv32i1, 16, VRM8, 8>;
      def Vtypev16xi32 : VectorTypeInfo<nxv16i32, nxv16i1, 32, VRM8, 8>;
      def Vtypev8xi64 : VectorTypeInfo<nxv8i64, nxv8i1, 64, VRM8, 8>;
    }
  }

  defset list<VectorTypeInfo> AllFloatVectors = {
    defset list<VectorTypeInfo> NoGroupFloatVectors = {
      def Vtypev4xf16 : VectorTypeInfo<nxv4f16, nxv4i1, 16, VR, 1>;
      def Vtypev2xf32 : VectorTypeInfo<nxv2f32, nxv2i1, 32, VR, 1>;
      def Vtypev1xf64 : VectorTypeInfo<nxv1f64, nxv1i1, 64, VR, 1>;
    }

    defset list<VectorTypeInfo> GroupFloatVectors = {
      def Vtypev8xf16 : VectorTypeInfo<nxv8f16, nxv8i1, 16, VRM2, 2>;
      def Vtypev4xf32 : VectorTypeInfo<nxv4f32, nxv4i1, 32, VRM2, 2>;
      def Vtypev2xf64 : VectorTypeInfo<nxv2f64, nxv2i1, 64, VRM2, 2>;

      def Vtypev16xf16 : VectorTypeInfo<nxv16f16, nxv16i1, 16, VRM4, 4>;
      def Vtypev8xf32 : VectorTypeInfo<nxv8f32, nxv8i1, 32, VRM4, 4>;
      def Vtypev4xf64 : VectorTypeInfo<nxv4f64, nxv4i1, 64, VRM4, 4>;

      def Vtypev32xf16 : VectorTypeInfo<nxv32f16, nxv32i1, 16, VRM8, 8>;
      def Vtypev16xf32 : VectorTypeInfo<nxv16f32, nxv16i1, 32, VRM8, 8>;
      def Vtypev8xf64 : VectorTypeInfo<nxv8f64, nxv8i1, 64, VRM8, 8>;
    }
  }
}

class RISCVVectorPseudo {
  Pseudo Pseudo = !cast<Pseudo>(NAME);
  Instruction BaseInstr;
  bits<8> SEWIndex;
  bits<8> MergeOpIndex;
  bits<8> VLMul;
}

def RISCVVectorPseudoTable : GenericTable {
  let FilterClass = "RISCVVectorPseudo";
  let CppTypeName = "RISCVVectorPseudoInfo";
  let Fields = ["Pseudo", "BaseInstr", "SEWIndex", "MergeOpIndex", "VLMul"];
  let PrimaryKey = ["Pseudo"];
  let PrimaryKeyName = "getRISCVVectorPseudoInfo";
}

// multiclass pseudo_unary<RegisterClass result_reg_class,
//                         RegisterClass arg1_reg_class,
//                         string vlmul, string constraints = ""> {
//   let Constraints = Join<[constraints, "$rd = $merge"], ",">.Result,
//       Uses = [VL, VTYPE], VLIndex = 4, SEWIndex = 5, MergeOpIndex = 1 in
//     def "_M" # vlmul : 
//                         }

multiclass pseudo_binary<RegisterClass result_reg_class,
                         RegisterClass arg1_reg_class,
                         RegisterClass arg2_reg_class,
                         string vlmul, string constraints = ""> {
  let Constraints = Join<[constraints, "$rd = $merge"], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 5, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in 
    def "_M" # vlmul : Pseudo<(outs result_reg_class:$rd),
                              (ins result_reg_class:$merge, 
                               arg1_reg_class:$rs1, arg2_reg_class:$rs2,
                               VMaskOp:$vm, ixlenimm:$sew),
                              []>,
                       RISCVVectorPseudo;
}

multiclass pseudo_binary_v_vv {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, evr.RegClass, evr.lmulstr>;
    }
  }
}

multiclass pseudo_binary_v_vx {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, GPR, evr.lmulstr>;
    }
  }
}

multiclass pseudo_binary_v_vf {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, FPR32, evr.lmulstr>;
    }
  }
}

multiclass pseudo_binary_v_vv_vx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, evr.RegClass, evr.lmulstr, constraints>;
      defm _VX : pseudo_binary<evr.RegClass, evr.RegClass, GPR, evr.lmulstr, constraints>;
    }
  }
}

defm PseudoVADD : pseudo_binary_v_vv_vx;


class swap_helper<dag Prefix,
                  dag A,
                  dag B,
                  dag Suffix,
                  bit swap> {
   dag Value = !con(
       Prefix,
       !if(swap, B, A),
       !if(swap, A, B),
       Suffix);
}


multiclass pat_intrinsic_binary<string intrinsic_name,
                                string instruction_name,
                                ValueType result_type,
                                ValueType arg1_type,
                                ValueType arg2_type,
                                ValueType mask_type,
                                int sew,
                                int lmul,
                                RegisterClass result_operand,
                                RegisterClass arg1_operand,
                                DAGOperand arg2_operand,
                                bit swap = 0>      
{
  defvar instruction = !cast<Instruction>(instruction_name#"_M"#lmul);
  // def : Pat<(result_type (int_riscv_vadd_vv (arg1_type arg1_operand:$rs1), (arg2_type arg2_operand:$rs2))), (result_type (PseudoVADD_VV_M1 (result_type zero_reg), (arg1_type VR:$rs1), (arg2_type VR:$rs2), (mask_type zero_reg), 8))>;

  // def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name#"_mask") 
  //                           (mask_type zero_reg),
  //                           (result_type result_operand:$merge),
  //                           (arg1_type arg1_operand:$rs1),
  //                           (arg2_type arg2_operand:$rs2))),
  //           (!cast<Instruction>(instruction_name#"_M"#lmul) 
  //                           (result_type zero_reg), 
  //                           (mask_type zero_reg),
  //                           (arg1_type arg1_operand:$rs1),
  //                           (ToScalarOp<arg2_type, arg2_operand, "rs2">.Result),
  //                           sew)>;
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type arg1_operand:$rs1),
                          (arg2_type arg2_operand:$rs2))),
            swap_helper<
              (instruction (result_type zero_reg)),
              (instruction
               (arg1_type arg1_operand:$rs1)),
              (instruction ToScalarOp<arg2_type, arg2_operand, "rs2">.Result),
              (instruction
               (mask_type zero_reg),
               sew),
              swap>.Value>;

  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name#"_mask")
                          (mask_type V0),
                          (result_type result_operand:$merge),
                          (arg1_type arg1_operand:$rs1),
                          (arg2_type arg2_operand:$rs2))),
            swap_helper<
              (instruction result_operand:$merge),
              (instruction
               arg1_operand:$rs1),
              (instruction ToScalarOp<arg2_type, arg2_operand, "rs2">.Result),
              (instruction
               (mask_type V0),
               sew),
              swap>.Value>;
}

multiclass pat_intrinsic_int_binary_vv_vx
        <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
                            evr.Vector, evr.Vector, evr.Vector, evr.Mask,
                            evr.SEW, evr.LMUL, evr.RegClass, evr.RegClass, 
                            evr.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vx", instruction_name#"_VX",
                            evr.Vector, evr.Vector, XLenVT, evr.Mask,
                            evr.SEW, evr.LMUL, evr.RegClass, evr.RegClass,
                            GPR>;
  }
      // defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
      //                       nxv16i8, nxv16i8, nxv16i8, nxv16i1,
      //                       8, 2, VRM2, VRM2, 
      //                       VRM2>;
  // foreach evr = AllFloatVectors in {
  //   defm : pat_intrinsic_binary<intrinsic_name#"_vf", instruction_name#"_VF",
  //                           evr.Vector, evr.Vector, f32, evr.Mask,
  //                           evr.SEW, evr.LMUL, evr.RegClass, evr.RegClass,
  //                           FPR32>;
  // }
}

defm "" : pat_intrinsic_int_binary_vv_vx<"int_riscv_vadd", "PseudoVADD">;
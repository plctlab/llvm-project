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
                     !eq(!cast<string>(operand), !cast<string>(FPR64)): (EXTRACT_SUBREG !dag(type, [FPR64], [name]), sub_32),
                     1 : !dag(type, [operand], [name]));
}

class VectorTypeInfo<ValueType Vec, ValueType Mas, int Sew, RegisterClass Reg, int Lmul, string Lmulstr> {
  ValueType Vector = Vec;
  ValueType Mask = Mas;
  int SEW = Sew;
  RegisterClass RegClass = Reg;
  int LMUL = Lmul;
  string LMULstr = Lmulstr;
} 

class VlmulToRC<string Lmul, RegisterClass Reg, int LmulValue> {
  string Lmulstr = Lmul;
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
  def MF2 : VlmulToRC<"F2", VR, 9>;
  def MF4 : VlmulToRC<"F4", VR, 10>;
  def MF8 : VlmulToRC<"F8", VR, 11>;
}

class WideVlmulToRCInfo<RegisterClass Ori, RegisterClass Wid, string Lmul, int Wlm, string OLmul> {
  RegisterClass OriginRegClass = Ori;
  RegisterClass WideRegClass = Wid;
  string Lmulstr = Lmul;
  string OriginLmulstr = OLmul;
  int Widelmul = Wlm;
}

defset list<WideVlmulToRCInfo> AllWideVlmuls = {
  // TODO : fractional lmul
  def WMF4 : WideVlmulToRCInfo<VR, VR, "F4", 10, "F8">;
  def WMF2 : WideVlmulToRCInfo<VR, VR, "F2", 9, "F4">;
  def WM1 : WideVlmulToRCInfo<VR, VR, "1", 1, "F2">;
  def WM2 : WideVlmulToRCInfo<VR, VRM2, "2", 2, "1">;
  def WM4 : WideVlmulToRCInfo<VRM2, VRM4, "4", 4, "2">;
  def WM8 : WideVlmulToRCInfo<VRM4, VRM8, "8", 8, "4">;
}

defset list<VectorTypeInfo> AllVectors = {
  defset list<VectorTypeInfo> AllIntegerVectors = {
    defset list<VectorTypeInfo> FractionalLmulIntegerVectors = {
      def Vtypev4xi8 : VectorTypeInfo<nxv4i8, nxv4i1, 8, VR, 9, "F2">;
      def Vtypev2xi16 : VectorTypeInfo<nxv2i16, nxv2i1, 16, VR, 9, "F2">;
      def Vtypev1xi32 : VectorTypeInfo<nxv1i32, nxv1i1, 32, VR, 9, "F2">;

      def Vtypev2xi8 : VectorTypeInfo<nxv2i8, nxv2i1, 8, VR, 10, "F4">;
      def Vtypev1xi16 : VectorTypeInfo<nxv1i16, nxv1i1, 16, VR, 10, "F4">;
      
      def Vtypev1xi8 : VectorTypeInfo<nxv1i8, nxv1i1, 8, VR, 11, "F8">;
    }

    defset list<VectorTypeInfo> NoGroupIntegerVectors = {
      def Vtypev8xi8 : VectorTypeInfo<nxv8i8, nxv8i1, 8, VR, 1, "1">;
      def Vtypev4xi16 : VectorTypeInfo<nxv4i16, nxv4i1, 16, VR, 1, "1">;
      def Vtypev2xi32 : VectorTypeInfo<nxv2i32, nxv2i1, 32, VR, 1, "1">;
      def Vtypev1xi64 : VectorTypeInfo<nxv1i64, nxv1i1, 64, VR, 1, "1">;
    }

    defset list<VectorTypeInfo> GroupIntegerVectors = {
      def Vtypev16xi8 : VectorTypeInfo<nxv16i8, nxv16i1, 8, VRM2, 2, "2">;
      def Vtypev8xi16 : VectorTypeInfo<nxv8i16, nxv8i1, 16, VRM2, 2, "2">;
      def Vtypev4xi32 : VectorTypeInfo<nxv4i32, nxv4i1, 32, VRM2, 2, "2">;
      def Vtypev2xi64 : VectorTypeInfo<nxv2i64, nxv2i1, 64, VRM2, 2, "2">;

      def Vtypev32xi8 : VectorTypeInfo<nxv32i8, nxv32i1, 8, VRM4, 4, "4">;
      def Vtypev16xi16 : VectorTypeInfo<nxv16i16, nxv16i1, 16, VRM4, 4, "4">;
      def Vtypev8xi32 : VectorTypeInfo<nxv8i32, nxv8i1, 32, VRM4, 4, "4">;
      def Vtypev4xi64 : VectorTypeInfo<nxv4i64, nxv4i1, 64, VRM4, 4, "4">;

      def Vtypev64xi8 : VectorTypeInfo<nxv64i8, nxv64i1, 8, VRM8, 8, "8">;
      def Vtypev32xi16 : VectorTypeInfo<nxv32i16, nxv32i1, 16, VRM8, 8, "8">;
      def Vtypev16xi32 : VectorTypeInfo<nxv16i32, nxv16i1, 32, VRM8, 8, "8">;
      def Vtypev8xi64 : VectorTypeInfo<nxv8i64, nxv8i1, 64, VRM8, 8, "8">;
    }
  }

  defset list<VectorTypeInfo> AllFloatVectors = {
    defset list<VectorTypeInfo> FractionalLmulFloatVectors = {
      def Vtypev1xf32 : VectorTypeInfo<nxv1f32, nxv1i1, 32, VR, 9, "F2">;
      def Vtypev2xf16 : VectorTypeInfo<nxv2f16, nxv2i1, 16, VR, 9, "F2">;
      
      def Vtypev1xf16 : VectorTypeInfo<nxv1f16, nxv1i1, 16, VR, 10, "F4">;
    }
    defset list<VectorTypeInfo> NoGroupFloatVectors = {
      def Vtypev4xf16 : VectorTypeInfo<nxv4f16, nxv4i1, 16, VR, 1, "1">;
      def Vtypev2xf32 : VectorTypeInfo<nxv2f32, nxv2i1, 32, VR, 1, "1">;
      def Vtypev1xf64 : VectorTypeInfo<nxv1f64, nxv1i1, 64, VR, 1, "1">;
    }

    defset list<VectorTypeInfo> GroupFloatVectors = {
      def Vtypev8xf16 : VectorTypeInfo<nxv8f16, nxv8i1, 16, VRM2, 2, "2">;
      def Vtypev4xf32 : VectorTypeInfo<nxv4f32, nxv4i1, 32, VRM2, 2, "2">;
      def Vtypev2xf64 : VectorTypeInfo<nxv2f64, nxv2i1, 64, VRM2, 2, "2">;

      def Vtypev16xf16 : VectorTypeInfo<nxv16f16, nxv16i1, 16, VRM4, 4, "4">;
      def Vtypev8xf32 : VectorTypeInfo<nxv8f32, nxv8i1, 32, VRM4, 4, "4">;
      def Vtypev4xf64 : VectorTypeInfo<nxv4f64, nxv4i1, 64, VRM4, 4, "4">;

      def Vtypev32xf16 : VectorTypeInfo<nxv32f16, nxv32i1, 16, VRM8, 8, "8">;
      def Vtypev16xf32 : VectorTypeInfo<nxv16f32, nxv16i1, 32, VRM8, 8, "8">;
      def Vtypev8xf64 : VectorTypeInfo<nxv8f64, nxv8i1, 64, VRM8, 8, "8">;
    }
  }
}

class WideVectorInfo<VectorTypeInfo Ori, ValueType Wid, RegisterClass Wrc, string Widelmulstr> {
  VectorTypeInfo OriginVector = Ori;
  ValueType WidenVector = Wid;
  RegisterClass WidenRegClass = Wrc;
  int WidenLMUL = !mul(Ori.LMUL, 2);
  int WidenSEW = !mul(Ori.SEW, 2);
  string WidenLMULstr = Widelmulstr;
}

defset list<WideVectorInfo> AllWideFloatVectors = {
  def Widev1xf16 : WideVectorInfo<Vtypev1xf16, nxv1f32, VR, "F2">;

  def Widev1xf32 : WideVectorInfo<Vtypev1xf32, nxv1f64, VR, "1">;
  def Widev2xf16 : WideVectorInfo<Vtypev2xf32, nxv2f32, VR, "1">;

  def Widev4xf16 : WideVectorInfo<Vtypev4xf16, nxv4f32, VRM2, "2">;
  def Widev2xf32 : WideVectorInfo<Vtypev2xf32, nxv2f64, VRM2, "2">;

  def Widev8xf16 : WideVectorInfo<Vtypev8xf16, nxv8f32, VRM4, "4">;
  def Widev4xf32 : WideVectorInfo<Vtypev4xf32, nxv4f64, VRM4, "4">;
  
  def Widev16xf16 : WideVectorInfo<Vtypev16xf16, nxv16f32, VRM8, "8">;
  def Widev8xf32 : WideVectorInfo<Vtypev8xf32, nxv8f64, VRM8, "8">;
}

defset list<WideVectorInfo> AllWideIntegerVectors = {
  def Widev1xi8 : WideVectorInfo<Vtypev1xi8, nxv1i16, VR, "F4">;

  def Widev1xi16 : WideVectorInfo<Vtypev1xi16, nxv1i32, VR, "F2">;
  def Widev2xi8 : WideVectorInfo<Vtypev2xi8, nxv2i16, VR, "F2">;

  def Widev1xi32 : WideVectorInfo<Vtypev1xi32, nxv1i64, VR, "1">;
  def Widev2xi16 : WideVectorInfo<Vtypev2xi16, nxv2i32, VR, "1">;
  def Widev4xi8 : WideVectorInfo<Vtypev4xi8, nxv4i16, VR, "1">;

  def Widev8xi8 : WideVectorInfo<Vtypev8xi8, nxv8i16, VRM2, "2">;
  def Widev4xi16 : WideVectorInfo<Vtypev4xi16, nxv4i32, VRM2, "2">;
  def Widev2xi32 : WideVectorInfo<Vtypev2xi32, nxv2i64, VRM2, "2">;
  
  def Widev16xi8 : WideVectorInfo<Vtypev16xi8, nxv16i16, VRM4, "4">;
  def Widev8xi16 : WideVectorInfo<Vtypev8xi16, nxv8i32, VRM4, "4">;
  def Widev4xi32 : WideVectorInfo<Vtypev4xi32, nxv4i64, VRM4, "4">;

  def Widev32xi8 : WideVectorInfo<Vtypev32xi8, nxv32i16, VRM8, "8">;
  def Widev16xi16 : WideVectorInfo<Vtypev16xi16, nxv16i32, VRM8, "8">;
  def Widev8xi32 : WideVectorInfo<Vtypev8xi32, nxv8i64, VRM8, "8">;
}

defset list<WideVectorInfo> AllQuadWideIntegerVectors = {
  def QWidev1xi8 : WideVectorInfo<Vtypev1xi8, nxv1i32, VR, "F2_8_MF8">; //vint32mf2_t, vint8mf8_t
  def QWidev2xi8 : WideVectorInfo<Vtypev2xi8, nxv2i32, VR, "1_8_MF4">; //vint32m1_t, vint8mf4_t
  def QWidev4xi8 : WideVectorInfo<Vtypev4xi8, nxv4i32, VRM2, "2_8_MF2">;  //vint32m2_t, vint8mf2_t
  def QWidev8xi8 : WideVectorInfo<Vtypev8xi8, nxv8i32, VRM4, "4_8_M1">; //vint32m4_t, vint8m1_t
  def QWidev16xi8 : WideVectorInfo<Vtypev16xi8, nxv16i32, VRM8, "8_8_M2">; //vint32m8_t, vint8m2_t

  def QWidev1xi16 : WideVectorInfo<Vtypev1xi16, nxv1i64, VR, "1_16_MF4">; //vint64m1_t, vint16mf4_t
  def QWidev2xi16 : WideVectorInfo<Vtypev2xi16, nxv2i64, VRM2, "2_16_MF2">;  //vint64m2_t, vint16mf2_t 
  def QWidev4xi16 : WideVectorInfo<Vtypev4xi16, nxv4i64, VRM4, "4_16_M1">; //vint64m4_t, vint16m1_t
  def QWidev8xi16 : WideVectorInfo<Vtypev8xi16, nxv8i64, VRM8, "8_16_M2">; //vint64m8_t, vint16m2_t op1
}

class VectorTypeInfoToNarrow<VectorTypeInfo vti, VectorTypeInfo wti>
{
   VectorTypeInfo Vti = vti;
   VectorTypeInfo Wti = wti;
}

defset list<VectorTypeInfoToNarrow> AllNarrowIntToFloatVectors = {
  def : VectorTypeInfoToNarrow<Vtypev4xi16, Vtypev4xf32>;
}

class VectorTypeInfoToNarrowOrWide<VectorTypeInfo vti, VectorTypeInfo wti, string Lmulstr>
{
   VectorTypeInfo Vti = vti;
   VectorTypeInfo Wti = wti;
   string LMULstr = Lmulstr;
}

defset list<VectorTypeInfoToNarrowOrWide> AllWideFloatToIntVectors = {
  def : VectorTypeInfoToNarrowOrWide<Vtypev1xi32, Vtypev1xf16, "F4_16_MF2">; //vfloat16mf4_t, vint32mf2_t
  def : VectorTypeInfoToNarrowOrWide<Vtypev2xi32, Vtypev2xf16, "F2_16_M1">; //vfloat16mf2_t, vint32m1_t
  def : VectorTypeInfoToNarrowOrWide<Vtypev4xi32, Vtypev4xf16, "1_16_M2">; //vfloat16m1_t, vint32m2_t
  def : VectorTypeInfoToNarrowOrWide<Vtypev8xi32, Vtypev8xf16, "2_16_M4">; //vfloat16m2_t, vint32m4_t
  def : VectorTypeInfoToNarrowOrWide<Vtypev16xi32, Vtypev16xf16, "4_16_M8">; //vfloat16m4_t, vint32m8_t
  def : VectorTypeInfoToNarrowOrWide<Vtypev1xi64, Vtypev1xf32, "F2_32_M1">; //vfloat32mf2_t, vint64m1_t
  def : VectorTypeInfoToNarrowOrWide<Vtypev2xi64, Vtypev2xf32, "1_32_M2">; //vfloat32m1_t, vint64m2_t
  def : VectorTypeInfoToNarrowOrWide<Vtypev4xi64, Vtypev4xf32, "2_32_M4">; //vfloat32m2_t, vint64m4_t
  def : VectorTypeInfoToNarrowOrWide<Vtypev8xi64, Vtypev8xf32, "4_32_M8">; //vfloat32m4_t, vint64m8_t
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
//       Uses = [VL, VTYPE], SEWIndex = 4, MergeOpIndex = 1 in
//     def "_M" # vlmul : Pseudo<(outs result_reg_class),
//                               (ins result_reg_class:$merge,
//                                arg1_reg_class:$rs1, VMaskOp:$vm, ixlenimm:$sew),
//                               []>;
//                        RISCVVectorPseudo;
// }

// load / store instruction
foreach evr = AllVlmuls in {
  defvar vlmul = evr.Lmulstr;
  foreach sew = [8, 16, 32, 64] in {
    let mayLoad = 1, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1, 
      VLMul = evr.Vlmul in {
      let Uses = [VL, VTYPE], SEWIndex = 4, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>("VLE"#sew#"_V") in {
      def PseudoVLE#sew#_V_M#vlmul
            : Pseudo<(outs evr.RegClass:$rd),
                    (ins evr.RegClass:$merge, GPR:$rs1, VMaskOp:$mask,
                      ixlenimm:$sew),
                    []>,
              RISCVVectorPseudo;
      }
    }

    let mayLoad = 0, mayStore = 1, hasSideEffects = 0, usesCustomInserter = 1,
      VLMul = evr.Vlmul in {
        let Uses = [VL, VTYPE], SEWIndex = 4, MergeOpIndex = 0,
        BaseInstr = !cast<Instruction>("VSE"#sew#"_V") in {
          def PseudoVSE#sew#_V_M#vlmul
            : Pseudo<(outs),
                    (ins evr.RegClass:$merge, evr.RegClass:$rs1, GPR:$rs2, VMaskOp:$mask,
                    ixlenimm:$sew),
                    []>,
              RISCVVectorPseudo;
        }
    }
  }
}

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

multiclass pseudo_binary_carryin<RegisterClass result_reg_class,
                                RegisterClass arg1_reg_class,
                                RegisterClass arg2_reg_class,
                                string vlmul, string constraints = ""> {
  let Constraints = Join<[constraints, ""], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 5, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in 
    def "_M" # vlmul : Pseudo<(outs result_reg_class:$rd),
                              (ins result_reg_class:$merge,
                                arg1_reg_class:$rs1, 
                                arg2_reg_class:$rs2,
                                VMV0:$maskop, ixlenimm:$sew),
                              []>,
                      RISCVVectorPseudo;
}

multiclass pseudo_binary_nomask<RegisterClass result_reg_class,
                                RegisterClass arg1_reg_class,
                                RegisterClass arg2_reg_class,
                                string vlmul, string constraints = ""> {
  let Constraints = Join<[constraints, ""], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 4, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in   
    def "_M" # vlmul : Pseudo<(outs result_reg_class:$rd),
                              (ins result_reg_class:$merge,
                                arg1_reg_class:$rs1,
                                arg2_reg_class:$rs2,
                                ixlenimm:$sew),
                              []>,
                       RISCVVectorPseudo;        
}

multiclass pseudo_unary<RegisterClass result_reg_class,
                        RegisterClass arg1_reg_class,
                        string vlmul, string constraints = ""> {
  let Constraints = Join<[constraints, "$rd = $merge"], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 4, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # vlmul : Pseudo<(outs result_reg_class:$rd),
                              (ins result_reg_class:$merge,
                              arg1_reg_class:$rs1,
                              VMaskOp:$vm, ixlenimm:$sew),
                              []>,
                              RISCVVectorPseudo;
}

multiclass pseudo_unary_nomask<RegisterClass result_reg_class,
                        RegisterClass arg1_reg_class,
                        string vlmul, string constraints = ""> {
  let Constraints = Join<[constraints, ""], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 3, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # vlmul : Pseudo<(outs result_reg_class:$rd),
                              (ins result_reg_class:$merge,
                              arg1_reg_class:$rs1,
                              ixlenimm:$sew),
                              []>,
                      RISCVVectorPseudo;
}

multiclass pseudo_ternary<RegisterClass result_reg_class,
                          RegisterClass arg1_reg_class,
                          RegisterClass arg2_reg_class,
                          string vlmul, string constraints = ""> {
  let Constraints = Join<[constraints, "$rd = $merge"], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 5, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # vlmul : Pseudo<(outs result_reg_class:$rd),
                              (ins result_reg_class:$merge,
                               arg1_reg_class:$rs1,
                               arg2_reg_class:$rs2,
                               VMaskOp:$vm, ixlenimm:$sew),
                              []>,
                              RISCVVectorPseudo;
}

multiclass pseudo_ternary_reduction {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
    foreach evr = AllVlmuls in {
      let VLMul = evr.Vlmul in {
        defm _VS : pseudo_ternary<VR, evr.RegClass, VR, evr.Lmulstr>; 
      }
    }
  }
}

multiclass pseudo_unary_v_n {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
    foreach evr = AllNarrowIntToFloatVectors in {
      defvar vti = evr.Vti;
      defvar wti = evr.Wti;
      let VLMul = vti.LMUL in {
        defm _W : pseudo_unary<vti.RegClass, wti.RegClass, vti.LMULstr, "@earlyclobber $rd">;
      }
    }
  }
}

// This functor is used to obtain the int vector type that has the same SEW and
// multiplier as the input parameter type
class GetIntVectorTypeInfo<VectorTypeInfo vti>
{
  // Equivalent integer vector type. Eg.
  //   Vtypev4xf64 → Vtypev4xi64
  VectorTypeInfo Vti =
    !cast<VectorTypeInfo>(
      !subst("xf", "xi", !cast<string>(vti))
    );
}

// This functor is used to obtain the float vector type that has the same SEW
// and multiplier as the input parameter type
class GetFloatVectorTypeInfo<VectorTypeInfo vti>
{
  // Equivalent float vector type. Eg.
  //   Vtypev2xf32 → Vtypev2xf32 
  VectorTypeInfo FVti =
    !cast<VectorTypeInfo>(
      !subst("xi", "xf", !cast<string>(vti))
    );
}


multiclass pseudo_unary_v_w<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
    foreach evr = AllWideFloatToIntVectors in {
      defvar vti = evr.Vti;
      defvar wti = evr.Wti;
      let VLMul = vti.LMUL in {
        defm _V : pseudo_unary<vti.RegClass, wti.RegClass, evr.LMULstr, constraints>;
      }
    }
  }
}

multiclass pseudo_unary_f_w<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
    foreach evr = AllWideFloatToIntVectors in {
      defvar fti = GetFloatVectorTypeInfo<evr.Vti>.FVti;
      defvar vti = GetIntVectorTypeInfo<evr.Wti>.Vti;
      let VLMul = vti.LMUL in {
        defm _V : pseudo_unary<fti.RegClass, vti.RegClass, evr.LMULstr, constraints>;
      }
    }
  }
}

multiclass pseudo_unary_f_f<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
    foreach evr = AllWideFloatToIntVectors in {
      defvar fti = GetFloatVectorTypeInfo<evr.Vti>.FVti;
      defvar wti = evr.Wti;
      let VLMul = fti.LMUL in {
        defm _V : pseudo_unary<fti.RegClass, wti.RegClass, evr.LMULstr, constraints>;
      }
    }
  }
}

multiclass pseudo_unary_v_v {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
    foreach evr = AllVlmuls in {
      let VLMul = evr.Vlmul in {
      defm _V : pseudo_unary<evr.RegClass, evr.RegClass, evr.Lmulstr>;
      }
    }
  }
}

multiclass pseudo_unary_nomask_v_x_v_v {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
    foreach evr = AllVlmuls in {
      let VLMul = evr.Vlmul in {
      defm _V : pseudo_unary_nomask<evr.RegClass, evr.RegClass, evr.Lmulstr>;
      defm _X : pseudo_unary_nomask<evr.RegClass, GPR, evr.Lmulstr>;
      }
    }
  }
}

multiclass pseudo_unary_nomask_x_s_s_x {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
    foreach evr = AllVlmuls in {
      let VLMul = evr.Vlmul in {
        defm _X_S : pseudo_unary_nomask<GPR, evr.RegClass, evr.Lmulstr>;
        defm _S_X : pseudo_unary_nomask<evr.RegClass, GPR, evr.Lmulstr>;
      }
    }
  }
}

multiclass pseudo_vfmv {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
    foreach evr = AllVlmuls in {
      let VLMul = evr.Vlmul in {
        defm _F_S : pseudo_unary_nomask<FPR32, evr.RegClass, evr.Lmulstr>;
        defm _S_F : pseudo_unary_nomask<evr.RegClass, FPR32, evr.Lmulstr>;
        defm _V_F : pseudo_unary_nomask<evr.RegClass, FPR32, evr.Lmulstr>;
      }
    }
  }
}


// TODO: vzext
// multiclass pseudo_unary_vf {
//   let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {
//     defm _VF
//   }
// }

// multiclass pseudo_binary_v_vv {
//   let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
//   foreach evr = AllVlmuls in {
//     let VLMul = evr.Vlmul in {
//       defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, evr.RegClass, evr.lmulstr>;
//     }
//   }
// }

multiclass pseudo_binary_v_vx {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, GPR, evr.Lmulstr>;
    }
  }
}

// multiclass pseudo_binary_v_vf {
//   let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
//   foreach evr = AllVlmuls in {
//     let VLMul = evr.Vlmul in {
//       defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, FPR32, evr.lmulstr>;
//     }
//   }
// }

multiclass pseudo_binary_v_vv_vx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VX : pseudo_binary<evr.RegClass, evr.RegClass, GPR, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_v_vv_vf<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
    defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
    defm _VF : pseudo_binary<evr.RegClass, evr.RegClass, FPR32, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_v_vf<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
    defm _VF : pseudo_binary<evr.RegClass, evr.RegClass, FPR32, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_w_vv_vx_wx_wv<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllWideVlmuls in {
    let VLMul = evr.Widelmul in {
      defm _VV : pseudo_binary<evr.WideRegClass, evr.OriginRegClass, 
                          evr.OriginRegClass, evr.Lmulstr, constraints>; 
      defm _VX : pseudo_binary<evr.WideRegClass, evr.OriginRegClass,
                              GPR, evr.Lmulstr, constraints>;
      defm _WV : pseudo_binary<evr.WideRegClass, evr.WideRegClass,
                              evr.OriginRegClass, evr.Lmulstr, constraints>;
      defm _WX : pseudo_binary<evr.WideRegClass, evr.WideRegClass,
                              GPR, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_w_vv_vf_wf_wv<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllWideVlmuls in {
    let VLMul = evr.Widelmul in {
      defm _VV : pseudo_binary<evr.WideRegClass, evr.OriginRegClass, 
                          evr.OriginRegClass, evr.Lmulstr, constraints>; 
      defm _VF : pseudo_binary<evr.WideRegClass, evr.OriginRegClass,
                              FPR32, evr.Lmulstr, constraints>;
      defm _WV : pseudo_binary<evr.WideRegClass, evr.WideRegClass,
                              evr.OriginRegClass, evr.Lmulstr, constraints>;
      defm _WF : pseudo_binary<evr.WideRegClass, evr.WideRegClass,
                              FPR32, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_w_vv_vx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllWideVlmuls in {
    let VLMul = evr.Widelmul in {
      defm _VV : pseudo_binary<evr.WideRegClass, evr.OriginRegClass,
                            evr.OriginRegClass, evr.Lmulstr, constraints>;
      defm _VX : pseudo_binary<evr.WideRegClass, evr.OriginRegClass,
                            GPR, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_w_vv_vf<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllWideVlmuls in {
    let VLMul = evr.Widelmul in {
      defm _VV : pseudo_binary<evr.WideRegClass, evr.OriginRegClass,
                            evr.OriginRegClass, evr.Lmulstr, constraints>;
      defm _VF : pseudo_binary<evr.WideRegClass, evr.OriginRegClass,
                            FPR32, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_n_wn_wx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllWideVlmuls in {
    let VLMul = evr.Widelmul in {
      defm _WV : pseudo_binary<evr.OriginRegClass, evr.WideRegClass, evr.OriginRegClass,
                                evr.OriginLmulstr, constraints>;
      defm _WX : pseudo_binary<evr.OriginRegClass, evr.WideRegClass, GPR,
                                evr.OriginLmulstr, constraints>;
    }
  }
}

// multiclass pseudo_binary_nomask_s_x<string constraints = ""> {
//   let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in
//   foreach evr = AllVlmuls in {
//     let VLMul = evr.Vlmul in {
//       defm _S_X : pseudo_binary_nomask<evr.RegClass, evr.RegClass, GPR, evr.Lmulstr, constraints>;
//     }
//   }
// }

multiclass pseudo_binary_v_vfm<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VFM : pseudo_binary_carryin<evr.RegClass, evr.RegClass, FPR32, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_v_vvm_vxm<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VVM : pseudo_binary_carryin<evr.RegClass, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VXM : pseudo_binary_carryin<evr.RegClass, evr.RegClass, GPR, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_m_vvm_vxm<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VVM : pseudo_binary_carryin<VM, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VXM : pseudo_binary_carryin<VM, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_m_vv_vx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_binary<VM, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VX : pseudo_binary<VM, evr.RegClass, GPR, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_m_vv_vf<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_binary<VM, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VF : pseudo_binary<VM, evr.RegClass, FPR32, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_m_vx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VX : pseudo_binary<VM, evr.RegClass, GPR, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_m_vf<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VF : pseudo_binary<VM, evr.RegClass, FPR32, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_ternary_v_vvv_vvf<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_ternary<evr.RegClass, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VF : pseudo_ternary<evr.RegClass, FPR32, evr.RegClass, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_ternary_v_vvv_vvx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_ternary<evr.RegClass, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VX : pseudo_ternary<evr.RegClass, GPR, evr.RegClass, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_ternary_v_vvx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VX : pseudo_ternary<evr.RegClass, evr.RegClass, GPR, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_ternary_w_wvv_wvx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllWideVlmuls in {
    let VLMul = evr.Widelmul in {
      defm _VV : pseudo_ternary<evr.WideRegClass, 
      evr.OriginRegClass, evr.OriginRegClass, evr.Lmulstr, constraints>;
      defm _VX : pseudo_ternary<evr.WideRegClass,
      GPR, evr.OriginRegClass, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_ternary_qw_wvv_wvx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in
  foreach evr = AllQuadWideIntegerVectors in {
    let VLMul = evr.OriginVector.LMUL in {
      defm _VV : pseudo_ternary<evr.WidenRegClass, evr.OriginVector.RegClass, evr.OriginVector.RegClass, evr.WidenLMULstr, constraints>;
      defm _VX : pseudo_ternary<evr.WidenRegClass,  GPR, evr.OriginVector.RegClass, evr.WidenLMULstr, constraints>;
    }
  }
}


multiclass pseudo_ternary_w_wvv_wvf<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllWideVlmuls in {
    let VLMul = evr.Widelmul in {
      defm _VV : pseudo_ternary<evr.WideRegClass, 
      evr.OriginRegClass, evr.OriginRegClass, evr.Lmulstr, constraints>;
      defm _VF : pseudo_ternary<evr.WideRegClass,
      FPR32, evr.OriginRegClass, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_ternary_w_wvx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in 
  foreach evr = AllWideVlmuls in {
    let VLMul = evr.Widelmul in {
      defm _VX : pseudo_ternary<evr.WideRegClass,
      GPR, evr.OriginRegClass, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_ternary_qw_wvx<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in
  foreach evr = AllQuadWideIntegerVectors in {
    let VLMul = evr.OriginVector.LMUL in {
      defm _VX : pseudo_ternary<evr.WidenRegClass, GPR, 
      evr.OriginVector.RegClass, evr.WidenLMULstr, constraints>;
    }
  }
}

// 12.1. Vector Single-Width Integer Add and Subtract
defm PseudoVADD : pseudo_binary_v_vv_vx;
defm PseudoVSUB : pseudo_binary_v_vv_vx;

// 12.2. Vector Widening Integer Add/Subtract
defm PseudoVWADD : pseudo_binary_w_vv_vx_wx_wv<"@earlyclobber $rd">;
defm PseudoVWADDU : pseudo_binary_w_vv_vx_wx_wv<"@earlyclobber $rd">;
defm PseudoVWSUB : pseudo_binary_w_vv_vx_wx_wv<"@earlyclobber $rd">;
defm PseudoVWSUBU : pseudo_binary_w_vv_vx_wx_wv<"@earlyclobber $rd">;

// 12.3. Vector Integer Extension

// 12.4. Vector Integer Add-with-Carry/Subtract-with-Borrow Instructions
defm PseudoVADC : pseudo_binary_v_vvm_vxm;
defm PseudoVMADC : pseudo_binary_m_vvm_vxm<"@earlyclobber $rd">;
defm PseudoVSBC : pseudo_binary_v_vvm_vxm;
defm PseudoVMSBC : pseudo_binary_v_vvm_vxm<"@earlyclobber $rd">;

// 12.5. Vector Bitwise Logical Instructions
defm PseudoVAND : pseudo_binary_v_vv_vx;
defm PseudoVOR : pseudo_binary_v_vv_vx;
defm PseudoVXOR : pseudo_binary_v_vv_vx;

// 12.6. Vector Single-Width Bit Shift Instructions
defm PseudoVSLL : pseudo_binary_v_vv_vx;
defm PseudoVSRL : pseudo_binary_v_vv_vx;
defm PseudoVSRA : pseudo_binary_v_vv_vx;

// 12.7. Vector Narrowing Integer Right Shift Instructions
defm PseudoVNSRL : pseudo_binary_n_wn_wx;
defm PseudoVNSRA : pseudo_binary_n_wn_wx;

// 12.8. Vector Integer Comparison Instructions
defm PseudoVMSEQ : pseudo_binary_m_vv_vx;
defm PseudoVMSNE : pseudo_binary_m_vv_vx;
defm PseudoVMSLT : pseudo_binary_m_vv_vx;
defm PseudoVMSLTU : pseudo_binary_m_vv_vx;
defm PseudoVMSLE : pseudo_binary_m_vv_vx;
defm PseudoVMSLEU : pseudo_binary_m_vv_vx;
defm PseudoVMSGT : pseudo_binary_m_vx;
defm PseudoVMSGTU : pseudo_binary_m_vx;

// 12.9. Vector Integer Min/Max Instructions
defm PseudoVMIN : pseudo_binary_v_vv_vx;
defm PseudoVMINU : pseudo_binary_v_vv_vx;
defm PseudoVMAX : pseudo_binary_v_vv_vx;
defm PseudoVMAXU : pseudo_binary_v_vv_vx;

// 12.10. Vector Single-Width Integer Multiply Instructions
defm PseudoVMUL : pseudo_binary_v_vv_vx;
defm PseudoVMULH : pseudo_binary_v_vv_vx;
defm PseudoVMULHU : pseudo_binary_v_vv_vx;
defm PseudoVMULHSU : pseudo_binary_v_vv_vx;

// 12.11. Vector Integer Divide Instructions
defm PseudoVDIV : pseudo_binary_v_vv_vx;
defm PseudoVDIVU : pseudo_binary_v_vv_vx;
defm PseudoVREM : pseudo_binary_v_vv_vx;
defm PseudoVREMU : pseudo_binary_v_vv_vx;

// 12.12. Vector Widening Integer Multiply Instructions
defm PseudoVWMUL : pseudo_binary_w_vv_vx<"@earlyclobber $rd">;
defm PseudoVWMULU : pseudo_binary_w_vv_vx<"@earlyclobber $rd">;
defm PseudoVWMULSU : pseudo_binary_w_vv_vx<"@earlyclobber $rd">;

// 12.13. Vector Single-Width Integer Multiply-Add Instructions
defm PseudoVMACC : pseudo_ternary_v_vvv_vvx;
defm PseudoVNMSAC : pseudo_ternary_v_vvv_vvx;
defm PseudoVMADD : pseudo_ternary_v_vvv_vvx;
defm PseudoVNMSUB : pseudo_ternary_v_vvv_vvx;

// 12.14. Vector Widening Integer Multiply-Add Instructions
defm PseudoVWMACC : pseudo_ternary_w_wvv_wvx;
defm PseudoVWMACCU : pseudo_ternary_w_wvv_wvx;
defm PseudoVWMACCSU : pseudo_ternary_w_wvv_wvx;
defm PseudoVWMACCUS : pseudo_ternary_w_wvx;

// 12.15. Vector Quad-Widening Integer Multiply-Add Instructions (Extension Zvqmac)
defm PseudoVQMACC : pseudo_ternary_qw_wvv_wvx;
defm PseudoVQMACCU : pseudo_ternary_qw_wvv_wvx;
defm PseudoVQMACCSU : pseudo_ternary_qw_wvv_wvx;
defm PseudoVQMACCUS : pseudo_ternary_qw_wvx;

// 12.16. Vector Integer Merge Instructions
defm PseudoVMERGE : pseudo_binary_v_vvm_vxm;

// 12.17. Vector Integer Move Instructions
defm PseudoVMV_V : pseudo_unary_nomask_v_x_v_v;

// 13.1. Vector Single-Width Saturating Add and Subtract
defm PseudoVSADD : pseudo_binary_v_vv_vx;
defm PseudoVSADDU : pseudo_binary_v_vv_vx;
defm PseudoVSSUB : pseudo_binary_v_vv_vx;
defm PseudoVSSUBU : pseudo_binary_v_vv_vx;

// 13.2. Vector Single-Width Averaging Add and Subtract
defm PseudoVAADD : pseudo_binary_v_vv_vx;
defm PseudoVAADDU : pseudo_binary_v_vv_vx;
defm PseudoVASUB : pseudo_binary_v_vv_vx;
defm PseudoVASUBU : pseudo_binary_v_vv_vx;

// 13.3. Vector Single-Width Fractional Multiply with Rounding and Saturation
defm PseudoVSMUL : pseudo_binary_v_vv_vx;

// 13.4. Vector Single-Width Scaling Shift Instructions
defm PseudoVSSRL : pseudo_binary_v_vv_vx;
defm PseudoVSSRA : pseudo_binary_v_vv_vx;

// 13.5. Vector Narrowing Fixed-Point Clip Instructions
defm PseudoVNCLIP : pseudo_binary_n_wn_wx;

// 14.2. Vector Single-Width Floating-Point Add/Subtract Instructions
defm PseudoVFADD : pseudo_binary_v_vv_vf;
defm PseudoVFSUB : pseudo_binary_v_vv_vf;
defm PseudoVFRSUB : pseudo_binary_v_vf;

// 14.3. Vector Widening Floating-Point Add/Subtract Instructions
defm PseudoVFWADD : pseudo_binary_w_vv_vf_wf_wv;
defm PseudoVFWSUB : pseudo_binary_w_vv_vf_wf_wv;

// 14.4. Vector Single-Width Floating-Point Multiply/Divide Instructions
defm PseudoVFMUL : pseudo_binary_v_vv_vf;
defm PseudoVFDIV : pseudo_binary_v_vv_vf;
defm PseudoVFRDIV : pseudo_binary_v_vf;

// 14.5. Vector Widening Floating-Point Multiply
defm PseudoVFWMUL : pseudo_binary_w_vv_vf;

// 14.6. Vector Single-Width Floating-Point Fused Multiply-Add Instructions
defm PseudoVFMACC : pseudo_ternary_v_vvv_vvf;
defm PseudoVFNMACC : pseudo_ternary_v_vvv_vvf;
defm PseudoVFNMSAC : pseudo_ternary_v_vvv_vvf;
defm PseudoVFMADD : pseudo_ternary_v_vvv_vvf;
defm PseudoVFNMADD : pseudo_ternary_v_vvv_vvf;
defm PseudoVFMSUB : pseudo_ternary_v_vvv_vvf;
defm PseudoVFNMSUB : pseudo_ternary_v_vvv_vvf;

// 14.7. Vector Widening Floating-Point Fused MultiplyAdd Instructions
defm PseudoVFWMACC : pseudo_ternary_w_wvv_wvf;
defm PseudoVFWNMACC : pseudo_ternary_w_wvv_wvf;
defm PseudoVFWMSAC : pseudo_ternary_w_wvv_wvf;
defm PseudoVFWNMSAC : pseudo_ternary_w_wvv_wvf;

// 14.8. Vector Floating-Point Square-Root Instruction
defm PseudoVFSQRT : pseudo_unary_v_v;

// 14.9. Vector Floating-Point MIN/MAX Instructions
defm PseudoVFMIN : pseudo_binary_v_vv_vf;
defm PseudoVFMAX : pseudo_binary_v_vv_vf;

// 14.10. Vector Floating-Point Sign-Injection Instructions
defm PseudoVFSGNJ : pseudo_binary_v_vv_vf;
defm PseudoVFSGNJN : pseudo_binary_v_vv_vf;
defm PseudoVFSGNJX : pseudo_binary_v_vv_vf;

// 14.11. Vector Floating-Point Compare Instructions
defm PseudoVMFEQ : pseudo_binary_m_vv_vf;
defm PseudoVMFNE : pseudo_binary_m_vv_vf;
defm PseudoVMFLT : pseudo_binary_m_vv_vf;
defm PseudoVMFLE : pseudo_binary_m_vv_vf;
defm PseudoVMFGT : pseudo_binary_m_vf;
defm PseudoVMFGE : pseudo_binary_m_vf;

// 14.12. Vector Floating-Point Classify Instruction
defm PseudoVFCLASS : pseudo_unary_v_v;

// 14.13. Vector Floating-Point Merge Instruction
defm PseudoVFMERGE : pseudo_binary_v_vfm;

// 14.14. Vector Floating-Point Move Instruction
// 17.2. Floating-Point Scalar Move Instructions
defm PseudoVFMV : pseudo_vfmv;

// 14.15. Single-Width Floating-Point/Integer TypeConvert Instructions
defm PseudoVFCVT_X_F : pseudo_unary_v_v;
defm PseudoVFCVT_XU_F : pseudo_unary_v_v;
defm PseudoVFCVT_RTZ_X_F : pseudo_unary_v_v;
defm PseudoVFCVT_RTZ_XU_F : pseudo_unary_v_v;
defm PseudoVFCVT_F_X : pseudo_unary_v_v;
defm PseudoVFCVT_F_XU : pseudo_unary_v_v;

// 14.16. Widening Floating-Point/Integer Type-Convert Instructions
defm PseudoVFWCVT_X_F : pseudo_unary_v_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_XU_F : pseudo_unary_v_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_RTZ_X_F : pseudo_unary_v_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_RTZ_XU_F : pseudo_unary_v_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_F_X : pseudo_unary_f_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_F_XU : pseudo_unary_f_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_F_F : pseudo_unary_f_f<"@earlyclobber $rd">;

// 14.17. Narrowing Floating-Point/Integer Type-Convert Instructions
defm PseudoVFNCVT_X_F : pseudo_unary_v_n;

// 15.1. Vector Single-Width Integer Reduction Instructions
defm PseudoVREDSUM : pseudo_ternary_reduction;
defm PseudoVREDMAX : pseudo_ternary_reduction;
defm PseudoVREDMAXU : pseudo_ternary_reduction;
defm PseudoVREDMIN : pseudo_ternary_reduction;
defm PseudoVREDMINU : pseudo_ternary_reduction;
defm PseudoVREDAND : pseudo_ternary_reduction;
defm PseudoVREDOR : pseudo_ternary_reduction;
defm PseudoVREDXOR : pseudo_ternary_reduction;

// 15.2. Vector Widening Integer Reduction Instructions

// 15.3. Vector Single-Width Floating-Point Reduction Instructions
defm PseudoVFREDOSUM : pseudo_ternary_reduction;
defm PseudoVFREDSUM : pseudo_ternary_reduction;
defm PseudoVFREDMAX : pseudo_ternary_reduction;
defm PseudoVFREDMIN : pseudo_ternary_reduction;

// 15.4. Vector Widening Floating-Point Reduction Instructions
// 16.1. Vector Mask-Register Logical Instructions
// 16.2. Vector mask population count vpopc
// 16.3. vfirst find-first-set mask bit
// 16.4. vmsbf.m set-before-first mask bit
// 16.5. vmsif.m set-including-first mask bit
// 16.6. vmsof.m set-only-first mask bit
// 16.8. Vector Iota Instruction
// 16.9. Vector Element Index Instruction

// 17.1. Integer Scalar Move Instructions
defm PseudoVMV : pseudo_unary_nomask_x_s_s_x;

// 17.3.1. Vector Slideup Instructions
defm PseudoVSLIDEUP : pseudo_ternary_v_vvx;

// 17.3.2. Vector Slidedown Instructions
defm PseudoVSLIDEDOWN : pseudo_ternary_v_vvx;

// 17.3.3. Vector Slide1up
// 17.3.4. Vector Slide1down Instruction
// 17.4. Vector Register Gather Instruction
// 17.5. Vector Compress Instruction
// 17.6. Whole Vector Register Move
// 19.3. Vector Integer Dot-Product Instruction
// 19.4. Vector Floating-Point Dot Product Instruction

//===----------------------------------------------------------------------===//
// Patterns for intrinsics
//===----------------------------------------------------------------------===//

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
                                string lmul,
                                RegisterClass result_operand,
                                RegisterClass arg1_operand,
                                DAGOperand arg2_operand,
                                bit swap = 0>      
{
  defvar instruction = !cast<Instruction>(instruction_name#"_M"#lmul);
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

multiclass pat_intrinsic_binary_carryin<string intrinsic_name,
                                        string instruction_name,
                                        ValueType result_type,
                                        ValueType arg1_type,
                                        ValueType arg2_type,
                                        ValueType carry_type,
                                        int sew,
                                        string lmul,
                                        RegisterClass result_operand,
                                        RegisterClass arg1_operand,
                                        DAGOperand arg2_operand,
                                        bit swap = 0> {
  defvar instruction = !cast<Instruction>(instruction_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type arg1_operand:$rs1),
                          (arg2_type arg2_operand:$rs2),
                          (carry_type V0))),
            (instruction  (result_type zero_reg),
            arg1_operand:$rs1, 
            ToScalarOp<arg2_type, arg2_operand, "rs2">.Result,
            (carry_type V0), sew)>;
}

multiclass pat_intrinsic_binary_nomask<string intrinsic_name,
                                       string instruction_name,
                                       ValueType result_type,
                                       ValueType arg1_type,
                                       ValueType arg2_type,
                                       int sew,
                                       string lmul,
                                       RegisterClass result_operand,
                                       RegisterClass arg1_operand,
                                       DAGOperand arg2_operand> {
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                           (arg1_type arg1_operand:$rs1),
                           (arg2_type arg2_operand:$rs2))),
            (!cast<Instruction>(instruction_name#"_M"#lmul)
              (result_type zero_reg),
              arg1_operand:$rs1,
              ToScalarOp<arg2_type, arg2_operand, "rs2">.Result,
              sew)>;
}

multiclass pat_intrinsic_ternary<string intrinsic_name,
                                 string instruction_name,
                                 ValueType result_type,
                                 ValueType arg1_type,
                                 ValueType arg2_type,
                                 ValueType mask_type,
                                 int sew,
                                 string lmul,
                                 RegisterClass result_operand,
                                 DAGOperand arg1_operand,
                                 RegisterClass arg2_operand> {
  defvar instruction = !cast<Instruction>(instruction_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (result_type result_operand:$merge),
                          (arg1_type arg1_operand:$rs1),
                          (arg2_type arg2_operand:$rs2))),
            (instruction result_operand:$merge, ToScalarOp<arg1_type, arg1_operand, "rs1">.Result, arg2_operand:$rs2, (mask_type zero_reg), sew)>;
}

multiclass pat_intrinsic_ternary_nomask<string intrinsic_name,
                                        string instruction_name,
                                        ValueType result_type,
                                        ValueType arg1_type,
                                        ValueType arg2_type,
                                        ValueType arg3_type,
                                        int sew,
                                        string lmul,
                                        RegisterClass result_operand,
                                        RegisterClass arg1_operand,
                                        RegisterClass arg2_operand,
                                        DAGOperand arg3_operand> {
  defvar instruction = !cast<Instruction>(instruction_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type V0),
                          (arg2_type arg2_operand:$rs2),
                          (arg3_type arg3_operand:$rs3))),
            (instruction (result_type zero_reg), arg2_operand:$rs2, 
                ToScalarOp<arg3_type, arg3_operand, "rs3">.Result, (arg1_type V0), sew)>;
}



multiclass pat_intrinsic_unary<string intrinsic_name,
                               string instruction_name,
                               ValueType result_type,
                               ValueType arg1_type,
                               ValueType mask_type,
                               int sew,
                               string lmul,
                               RegisterClass result_operand,
                               RegisterClass arg1_operand
                               > {
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type arg1_operand:$rs1))),
            (!cast<Instruction>(instruction_name#"_M"#lmul)
              (result_type zero_reg),
              arg1_operand:$rs1, (mask_type zero_reg), sew)>;
        
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name#"_mask") 
                         (mask_type V0),
                         (result_type result_operand:$merge),
                         (arg1_type arg1_operand:$rs1))),
            (!cast<Instruction>(instruction_name#"_M"#lmul)
             result_operand:$merge,
             arg1_operand:$rs1,
             (mask_type V0), sew)>;
}

multiclass pat_intrinsic_unary_nomask<string intrinsic_name,
                                      string instruction_name,
                                      ValueType result_type,
                                      ValueType arg1_type,
                                      int sew,
                                      string lmul,
                                      RegisterClass result_operand,
                                      DAGOperand arg1_operand> {
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type arg1_operand:$rs1))),
            (!cast<Instruction>(instruction_name#"_M"#lmul)
              (result_type zero_reg),
              ToScalarOp<arg1_type, arg1_operand, "rs1">.Result, sew)>;
}
                                        

multiclass pat_intrinsic_int_binary_vv_vx
        <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
                            evr.Vector, evr.Vector, evr.Vector, evr.Mask,
                            evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass, 
                            evr.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vx", instruction_name#"_VX",
                            evr.Vector, evr.Vector, XLenVT, evr.Mask,
                            evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass,
                            GPR>;
  }
  // foreach evr = AllFloatVectors in {
  //   defm : pat_intrinsic_binary<intrinsic_name#"_vf", instruction_name#"_VF",
  //                           evr.Vector, evr.Vector, f32, evr.Mask,
  //                           evr.SEW, evr.LMUL, evr.RegClass, evr.RegClass,
  //                           FPR32>;
  // }
}

multiclass pat_intrinsic_float_binary_v_vv_vf
        <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
                            evr.Vector, evr.Vector, evr.Vector, evr.Mask,
                            evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass, 
                            evr.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", instruction_name#"_VF",
                            evr.Vector, evr.Vector, f32, evr.Mask,
                            evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass,
                            FPR32>;
  }
}

multiclass pat_intrinsic_float_binary_v_vf
        <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", instruction_name#"_VF",
                            evr.Vector, evr.Vector, f32, evr.Mask,
                            evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass,
                            FPR32>;
  }
}

multiclass pat_intrinsic_int_binary_w_vv_vx_wv_wx
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
                              evr.WidenVector, evr.OriginVector.Vector, evr.OriginVector.Vector,
                              evr.OriginVector.Mask, evr.WidenSEW, evr.WidenLMULstr,
                              evr.WidenRegClass, evr.OriginVector.RegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vx", instruction_name#"_VX",
                              evr.WidenVector, evr.OriginVector.Vector, XLenVT, evr.OriginVector.Mask,
                              evr.WidenSEW, evr.WidenLMULstr, evr.WidenRegClass, 
                              evr.OriginVector.RegClass, GPR>;
    defm : pat_intrinsic_binary<intrinsic_name#"_wv", instruction_name#"_WV",
                              evr.WidenVector, evr.WidenVector, evr.OriginVector.Vector, evr.OriginVector.Mask,
                              evr.WidenSEW, evr.WidenLMULstr, evr.WidenRegClass,
                              evr.WidenRegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_wx", instruction_name#"_WX",
                              evr.WidenVector, evr.WidenVector, XLenVT, evr.OriginVector.Mask, evr.WidenSEW,
                              evr.WidenLMULstr, evr.WidenRegClass, evr.WidenRegClass,
                              GPR>;
    }
}

multiclass pat_intrinsic_float_binary_w_vv_vf_wv_wf
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideFloatVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
                              evr.WidenVector, evr.OriginVector.Vector, evr.OriginVector.Vector,
                              evr.OriginVector.Mask, evr.WidenSEW, evr.WidenLMULstr,
                              evr.WidenRegClass, evr.OriginVector.RegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", instruction_name#"_VF",
                              evr.WidenVector, evr.OriginVector.Vector, f32, evr.OriginVector.Mask,
                              evr.WidenSEW, evr.WidenLMULstr, evr.WidenRegClass, 
                              evr.OriginVector.RegClass, FPR32>;
    defm : pat_intrinsic_binary<intrinsic_name#"_wv", instruction_name#"_WV",
                              evr.WidenVector, evr.WidenVector, evr.OriginVector.Vector, evr.OriginVector.Mask,
                              evr.WidenSEW, evr.WidenLMULstr, evr.WidenRegClass,
                              evr.WidenRegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_wf", instruction_name#"_WF",
                              evr.WidenVector, evr.WidenVector, f32, evr.OriginVector.Mask, evr.WidenSEW,
                              evr.WidenLMULstr, evr.WidenRegClass, evr.WidenRegClass,
                              FPR32>;
    }
}

multiclass pat_intrinsic_int_binary_w_vv_vx
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
                              evr.WidenVector, evr.OriginVector.Vector, evr.OriginVector.Vector,
                              evr.OriginVector.Mask, evr.WidenSEW, evr.WidenLMULstr,
                              evr.WidenRegClass, evr.OriginVector.RegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vx", instruction_name#"_VX",
                              evr.WidenVector, evr.OriginVector.Vector, XLenVT, evr.OriginVector.Mask,
                              evr.WidenSEW, evr.WidenLMULstr, evr.WidenRegClass, 
                              evr.OriginVector.RegClass, GPR>;
    }
}

multiclass pat_intrinsic_float_binary_w_vv_vf
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideFloatVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
                              evr.WidenVector, evr.OriginVector.Vector, evr.OriginVector.Vector,
                              evr.OriginVector.Mask, evr.WidenSEW, evr.WidenLMULstr,
                              evr.WidenRegClass, evr.OriginVector.RegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", instruction_name#"_VF",
                              evr.WidenVector, evr.OriginVector.Vector, f32, evr.OriginVector.Mask,
                              evr.WidenSEW, evr.WidenLMULstr, evr.WidenRegClass, 
                              evr.OriginVector.RegClass, FPR32>;
    }
}

multiclass pat_intrinsic_int_binary_m_vv_vx
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
                              evr.Mask, evr.Vector, evr.Vector, evr.Mask, 
                              evr.SEW, evr.LMULstr, VM, evr.RegClass, evr.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vx", instruction_name#"_VX",
                              evr.Mask, evr.Vector, XLenVT, evr.Mask,
                              evr.SEW, evr.LMULstr, VM, evr.RegClass, GPR>;
  }
}

multiclass pat_intrinsic_float_binary_m_vv_vf
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", instruction_name#"_VV",
                              evr.Mask, evr.Vector, evr.Vector, evr.Mask, 
                              evr.SEW, evr.LMULstr, VM, evr.RegClass, evr.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", instruction_name#"_VF",
                              evr.Mask, evr.Vector, f32, evr.Mask,
                              evr.SEW, evr.LMULstr, VM, evr.RegClass, FPR32>;
  }
}

multiclass pat_intrinsic_float_binary_m_vf
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", instruction_name#"_VF",
                              evr.Mask, evr.Vector, f32, evr.Mask,
                              evr.SEW, evr.LMULstr, VM, evr.RegClass, FPR32>;
  }
}

multiclass pat_intrinsic_int_binary_m_vx
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vx", instruction_name#"_VX",
                              evr.Mask, evr.Vector, XLenVT, evr.Mask,
                              evr.SEW, evr.LMULstr, VM, evr.RegClass, GPR>;
  }
}

multiclass pat_intrinsic_int_binary_v_vvm_vxm 
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_binary_carryin<intrinsic_name#"_vvm", instruction_name#"_VVM",
                                        evr.Vector, evr.Vector, evr.Vector, evr.Mask,
                                        evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass, evr.RegClass>;
    defm : pat_intrinsic_binary_carryin<intrinsic_name#"_vxm", instruction_name#"_VXM",
                                        evr.Vector, evr.Vector, XLenVT, evr.Mask,
                                        evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass, GPR>;
  }
}

multiclass pat_intrinsic_vmerge
  <string intrinsic_name, string instruction_name> {
    foreach evr = AllVectors in {
      defm : pat_intrinsic_ternary_nomask<intrinsic_name#"_vvm", instruction_name#"_VVM",
      evr.Vector, evr.Mask, evr.Vector, evr.Vector, evr.SEW, evr.LMULstr, 
      evr.RegClass, VMV0, evr.RegClass, evr.RegClass>;
    }
    foreach evr = AllIntegerVectors in {
      defm : pat_intrinsic_ternary_nomask<intrinsic_name#"_vxm", instruction_name#"_VXM",
      evr.Vector, evr.Mask, evr.Vector, XLenVT, evr.SEW, evr.LMULstr, 
      evr.RegClass, VMV0, evr.RegClass, GPR>;
    }
}

multiclass pat_intrinsic_vfmerge
  <string intrinsic_name, string instruction_name> {
    foreach evr = AllFloatVectors in {
      defm : pat_intrinsic_ternary_nomask<intrinsic_name#"_vfm", instruction_name#"_VFM",
      evr.Vector, evr.Mask, evr.Vector, f32, evr.SEW, evr.LMULstr,
      evr.RegClass, VMV0, evr.RegClass, FPR32>;
    }
    foreach evr = AllFloatVectors in {
      defm : pat_intrinsic_ternary_nomask<intrinsic_name#"_vfm", instruction_name#"_VFM",
      evr.Vector, evr.Mask, evr.Vector, f64, evr.SEW, evr.LMULstr,
      evr.RegClass, VMV0, evr.RegClass, FPR64>;
    }
}


multiclass pat_intrinsic_int_binary_m_vvm_vxm
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_binary_carryin<intrinsic_name#"_vvm", instruction_name#"_VVM",
                                        evr.Mask, evr.Vector, evr.Vector, evr.Mask,
                                        evr.SEW, evr.LMULstr, VMV0, evr.RegClass, evr.RegClass>;
    defm : pat_intrinsic_binary_carryin<intrinsic_name#"_vxm", instruction_name#"_VXM",
                                        evr.Mask, evr.Vector, evr.Vector, evr.Mask,
                                        evr.SEW, evr.LMULstr, VMV0, evr.RegClass, evr.RegClass>;
  }
}

multiclass pat_intrinsic_int_binary_n_wn_wx 
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_wv", instruction_name#"_WV",
                                evr.OriginVector.Vector, evr.WidenVector, evr.OriginVector.Vector, 
                                evr.OriginVector.Mask, evr.OriginVector.SEW, evr.OriginVector.LMULstr, evr.OriginVector.RegClass,
                                evr.WidenRegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_wx", instruction_name#"_WX",
                                evr.OriginVector.Vector, evr.WidenVector, XLenVT,
                                evr.OriginVector.Mask, evr.OriginVector.SEW, evr.OriginVector.LMULstr, evr.OriginVector.RegClass,
                                evr.WidenRegClass, GPR>;             
  }
}

multiclass pat_intrinsic_int_binary_nomask_s_x
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defvar lmul = evr.LMULstr;
    def : Pat<(evr.Vector (!cast<Intrinsic>(intrinsic_name#"_s_x") 
                           (evr.Vector evr.RegClass:$merge),
                           (i64 GPR:$rs1))),
              (!cast<Instruction>(instruction_name#"_S_X_M"#lmul) 
               evr.RegClass:$merge,
               GPR:$rs1, evr.SEW)>;
  }
}

multiclass pat_intrinsic_int_unary_v
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_unary<intrinsic_name#"_v", instruction_name#"_V",
                               evr.Vector, evr.Vector, evr.Mask,
                               evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass>;
  }
}

multiclass pat_intrinsic_float_unary_v_v
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    defm : pat_intrinsic_unary<intrinsic_name#"_v", instruction_name#"_V",
                               evr.Vector, evr.Vector, evr.Mask,
                               evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass>;
  }
}

multiclass pat_intrinsic_int_unary_nomask_v_v_v_x 
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_v", instruction_name#"_V",
                               evr.Vector, evr.Vector, evr.SEW,
                               evr.LMULstr, evr.RegClass, evr.RegClass>;
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_x", instruction_name#"_X",
                               evr.Vector, XLenVT, evr.SEW,
                               evr.LMULstr, evr.RegClass, GPR>;
  }
}

multiclass pat_intrinsic_int_unary_nomask_x_s
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_x_s", instruction_name#"_X_S",
                               XLenVT, evr.Vector, evr.SEW,
                               evr.LMULstr, GPR, evr.RegClass>;
  }
}

multiclass pat_intrinsic_vfmv 
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_f_s", instruction_name#"_F_S",
                                f32, evr.Vector, evr.SEW, 
                                evr.LMULstr, FPR32, evr.RegClass>;
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_v_f", instruction_name#"_V_F",
                                evr.Vector, f32, evr.SEW,
                                evr.LMULstr, evr.RegClass, FPR32>;
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_v_f", instruction_name#"_V_F",
                                evr.Vector, f64, evr.SEW,
                                evr.LMULstr, evr.RegClass, FPR64>;
    def : Pat<(evr.Vector (!cast<Intrinsic>(intrinsic_name#"_s_f") 
                           (evr.Vector evr.RegClass:$merge),
                           (f32 FPR32:$rs1))),
              (!cast<Instruction>(instruction_name#"_S_F_M"#evr.LMULstr) 
               evr.RegClass:$merge,
               FPR32:$rs1, evr.SEW)>;
  }
}

multiclass pat_intrinsic_unary_n_f_v
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllNarrowIntToFloatVectors in {
    defvar vti = evr.Vti;
    defvar wti = evr.Wti;
    defm : pat_intrinsic_unary<intrinsic_name#"_w", instruction_name#"_W",
                               vti.Vector, wti.Vector, vti.Mask, vti.SEW,
                               vti.LMULstr, vti.RegClass, wti.RegClass>;

  }
}

multiclass pat_intrinsic_unary_w_f_v
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideFloatToIntVectors in {
    defvar vti = evr.Vti;
    defvar wti = evr.Wti;
    defm : pat_intrinsic_unary<intrinsic_name#"_v", instruction_name#"_V",
                               vti.Vector, wti.Vector, vti.Mask, vti.SEW,
                               evr.LMULstr, vti.RegClass, wti.RegClass>;

  }
}

multiclass pat_intrinsic_unary_w_v_f
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideFloatToIntVectors in {
    defvar fti = GetFloatVectorTypeInfo<evr.Vti>.FVti;
    defvar vti = GetIntVectorTypeInfo<evr.Wti>.Vti;
    defm : pat_intrinsic_unary<intrinsic_name#"_v", instruction_name#"_V",
                               fti.Vector, vti.Vector, fti.Mask, fti.SEW,
                               evr.LMULstr, fti.RegClass, vti.RegClass>;

  }
}


multiclass pat_intrinsic_unary_w_f_f
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideFloatToIntVectors in {
    defvar fti = GetFloatVectorTypeInfo<evr.Vti>.FVti;
    defvar wti = evr.Wti;
    defm : pat_intrinsic_unary<intrinsic_name#"_v", instruction_name#"_V",
                               fti.Vector, wti.Vector, fti.Mask, fti.SEW,
                               evr.LMULstr, fti.RegClass, wti.RegClass>;

  }
}

multiclass pat_intrinsic_unary_f_v
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    defvar vti = GetIntVectorTypeInfo<evr>.Vti;
    defm : pat_intrinsic_unary<intrinsic_name, instruction_name#"_V",
                               vti.Vector, evr.Vector, vti.Mask, vti.SEW,
                               evr.LMULstr, vti.RegClass, evr.RegClass>;

  }
}

multiclass pat_intrinsic_unary_v_f
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    defvar vti = GetIntVectorTypeInfo<evr>.Vti;
    defm : pat_intrinsic_unary<intrinsic_name, instruction_name#"_V",
                               evr.Vector, vti.Vector, vti.Mask, vti.SEW,
                               evr.LMULstr, evr.RegClass, vti.RegClass>;

  }
}


multiclass pat_intrinsic_float_ternary_v_vvv_vvf 
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", instruction_name#"_VV",
                                 evr.Vector, evr.Vector, evr.Vector, evr.Mask,
                                 evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass, evr.RegClass>;
    defm : pat_intrinsic_ternary<intrinsic_name#"_vf", instruction_name#"_VF",
                                 evr.Vector, f32, evr.Vector, evr.Mask,
                                 evr.SEW, evr.LMULstr, evr.RegClass, FPR32, evr.RegClass>;
  }
}

multiclass pat_intrinsic_int_ternary_v_vvv_vvx 
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", instruction_name#"_VV",
                                 evr.Vector, evr.Vector, evr.Vector, evr.Mask,
                                 evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass, evr.RegClass>;
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", instruction_name#"_VX",
                                 evr.Vector, XLenVT, evr.Vector, evr.Mask,
                                 evr.SEW, evr.LMULstr, evr.RegClass, GPR, evr.RegClass>;
  }
}

multiclass pat_intrinsic_int_ternary_v_vvx 
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", instruction_name#"_VX",
                                 evr.Vector, evr.Vector, XLenVT, evr.Mask,
                                 evr.SEW, evr.LMULstr, evr.RegClass, evr.RegClass, GPR>;
  }
}

multiclass pat_intrinsic_int_ternary_qw_wvv_wvx
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllQuadWideIntegerVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", instruction_name#"_VV",
                                 evr.WidenVector, evr.OriginVector.Vector, evr.OriginVector.Vector,
                                 evr.OriginVector.Mask, evr.OriginVector.SEW, evr.WidenLMULstr, evr.WidenRegClass,
                                 evr.OriginVector.RegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", instruction_name#"_VX",
                                 evr.WidenVector, XLenVT, evr.OriginVector.Vector, evr.OriginVector.Mask,
                                 evr.OriginVector.SEW, evr.WidenLMULstr, evr.WidenRegClass,
                                 GPR, evr.OriginVector.RegClass>;
  }
}

multiclass pat_intrinsic_int_ternary_w_wvv_wvx
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideIntegerVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", instruction_name#"_VV",
                                 evr.WidenVector, evr.OriginVector.Vector, evr.OriginVector.Vector,
                                 evr.OriginVector.Mask, evr.OriginVector.SEW, evr.WidenLMULstr, evr.WidenRegClass,
                                 evr.OriginVector.RegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", instruction_name#"_VX",
                                 evr.WidenVector, XLenVT, evr.OriginVector.Vector, evr.OriginVector.Mask,
                                 evr.OriginVector.SEW, evr.WidenLMULstr, evr.WidenRegClass,
                                 GPR, evr.OriginVector.RegClass>; 
  }
}

multiclass pat_intrinsic_float_ternary_w_wvv_wvf
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideFloatVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", instruction_name#"_VV",
                                 evr.WidenVector, evr.OriginVector.Vector, evr.OriginVector.Vector,
                                 evr.OriginVector.Mask, evr.OriginVector.SEW, evr.WidenLMULstr, evr.WidenRegClass,
                                 evr.OriginVector.RegClass, evr.OriginVector.RegClass>;
    defm : pat_intrinsic_ternary<intrinsic_name#"_vf", instruction_name#"_VF",
                                 evr.WidenVector, f32, evr.OriginVector.Vector, evr.OriginVector.Mask,
                                 evr.OriginVector.SEW, evr.WidenLMULstr, evr.WidenRegClass,
                                 FPR32, evr.OriginVector.RegClass>; 
  }
}

multiclass pat_intrinsic_int_ternary_w_wvx
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllWideIntegerVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", instruction_name#"_VX",
                                 evr.WidenVector, XLenVT, evr.OriginVector.Vector, evr.OriginVector.Mask,
                                 evr.OriginVector.SEW, evr.WidenLMULstr, evr.WidenRegClass,
                                 GPR, evr.OriginVector.RegClass>; 
  }
}

multiclass pat_intrinsic_int_ternary_qw_wvx
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllQuadWideIntegerVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", instruction_name#"_VX",
                                 evr.WidenVector, XLenVT, evr.OriginVector.Vector,  evr.OriginVector.Mask,
                                 evr.OriginVector.SEW, evr.WidenLMULstr, evr.WidenRegClass,
                                 GPR, evr.OriginVector.RegClass>;
  }
}

multiclass pat_intrinsic_int_reduction
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllIntegerVectors in {
    foreach evr1 = NoGroupIntegerVectors in {
      defm : pat_intrinsic_ternary<intrinsic_name#"_vs", instruction_name#"_VS", 
                                   evr1.Vector, evr.Vector, evr1.Vector, evr.Mask, evr.SEW, evr.LMULstr, 
                                   evr1.RegClass, evr.RegClass, evr1.RegClass>;
    }
  }
}

multiclass pat_intrinsic_float_reduction
    <string intrinsic_name, string instruction_name> {
  foreach evr = AllFloatVectors in {
    foreach evr1 = NoGroupFloatVectors in {
      defm : pat_intrinsic_ternary<intrinsic_name#"_vs", instruction_name#"_VS", 
                                   evr1.Vector, evr.Vector, evr1.Vector, evr.Mask, evr.SEW, evr.LMULstr, 
                                   evr1.RegClass, evr.RegClass, evr1.RegClass>;
    }
  }
}

multiclass pat_intrinsic_vload_store {
  foreach evr = AllVectors in {
    defvar str = evr.LMULstr;
    def : Pat<(evr.Vector (int_riscv_vload i64:$rs1)), 
          (evr.Vector (!cast<Instruction>("PseudoVLE"#evr.SEW#"_V_M"#str) (evr.Vector zero_reg), i64:$rs1,
          (evr.Mask zero_reg), evr.SEW))>;

    def : Pat<(evr.Vector (load i64:$rs1)), 
          (evr.Vector (!cast<Instruction>("PseudoVLE"#evr.SEW#"_V_M"#str) (evr.Vector zero_reg), i64:$rs1,
          (evr.Mask zero_reg), evr.SEW))>;

    def : Pat<(int_riscv_vstore i64:$rs2, (evr.Vector evr.RegClass:$rs1)), 
          (!cast<Instruction>("PseudoVSE"#evr.SEW#"_V_M"#str) (evr.Vector zero_reg), 
          (evr.Vector evr.RegClass:$rs1), i64:$rs2, (evr.Mask zero_reg), evr.SEW)>;

    def : Pat<(store (evr.Vector evr.RegClass:$rs1), i64:$rs2), 
          (!cast<Instruction>("PseudoVSE"#evr.SEW#"_V_M"#str) (evr.Vector zero_reg), 
          (evr.Vector evr.RegClass:$rs1), i64:$rs2, (evr.Mask zero_reg), evr.SEW)>;
  }
}

defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vadd", "PseudoVADD">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vsub", "PseudoVSUB">;
defm : pat_intrinsic_int_binary_w_vv_vx_wv_wx<"int_riscv_vwadd", "PseudoVWADD">;
defm : pat_intrinsic_int_binary_v_vvm_vxm<"int_riscv_vadc", "PseudoVADC">;
defm : pat_intrinsic_int_binary_m_vvm_vxm<"int_riscv_vmadc", "PseudoVMADC">;
defm : pat_intrinsic_vload_store;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfmacc", "PseudoVFMACC">;
defm : pat_intrinsic_int_unary_nomask_v_v_v_x<"int_riscv_vmv_v", "PseudoVMV_V">;
defm : pat_intrinsic_int_binary_nomask_s_x<"int_riscv_vmv", "PseudoVMV">;
defm : pat_intrinsic_int_unary_nomask_x_s<"int_riscv_vmv", "PseudoVMV">;
defm : pat_intrinsic_vfmv<"int_riscv_vfmv", "PseudoVFMV">;
defm : pat_intrinsic_unary_f_v<"int_riscv_vfcvt_x_f_v", "PseudoVFCVT_X_F">;
defm : pat_intrinsic_unary_f_v<"int_riscv_vfcvt_xu_f_v", "PseudoVFCVT_XU_F">;
defm : pat_intrinsic_unary_f_v<"int_riscv_vfcvt_rtz_x_f_v", "PseudoVFCVT_RTZ_X_F">;
defm : pat_intrinsic_unary_f_v<"int_riscv_vfcvt_rtz_xu_f_v", "PseudoVFCVT_RTZ_XU_F">;
defm : pat_intrinsic_unary_v_f<"int_riscv_vfcvt_f_x_v", "PseudoVFCVT_F_X">;
defm : pat_intrinsic_unary_v_f<"int_riscv_vfcvt_f_xu_v", "PseudoVFCVT_F_XU">;
defm : pat_intrinsic_int_binary_n_wn_wx<"int_riscv_vnsrl", "PseudoVNSRL">;
defm : pat_intrinsic_int_binary_n_wn_wx<"int_riscv_vnsra", "PseudoVNSRA">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmseq", "PseudoVMSEQ">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmsne", "PseudoVMSNE">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmsltu", "PseudoVMSLTU">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmslt", "PseudoVMSLT">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmsle", "PseudoVMSLE">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmsleu", "PseudoVMSLEU">;
defm : pat_intrinsic_int_binary_m_vx<"int_riscv_vmsgt", "PseudoVMSGT">;
defm : pat_intrinsic_int_binary_m_vx<"int_riscv_vmsgtu", "PseudoVMSGTU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vmin", "PseudoVMIN">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vmax", "PseudoVMAX">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vminu", "PseudoVMINU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vmaxu", "PseudoVMAXU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vmul", "PseudoVMUL">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vmulh", "PseudoVMULH">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vmulhu", "PseudoVMULHU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vmulhsu", "PseudoVMULHSU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vdiv", "PseudoVDIV">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vdivu", "PseudoVDIVU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vrem", "PseudoVREM">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vremu", "PseudoVREMU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vand", "PseudoVAND">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vor", "PseudoVOR">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vxor", "PseudoVXOR">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vsll", "PseudoVSLL">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vsrl", "PseudoVSRL">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vsra", "PseudoVSRA">;
defm : pat_intrinsic_int_binary_w_vv_vx<"int_riscv_vwmul", "PseudoVWMUL">;
defm : pat_intrinsic_int_binary_w_vv_vx<"int_riscv_vwmulu", "PseudoVWMULU">;
defm : pat_intrinsic_int_binary_w_vv_vx<"int_riscv_vwmulsu", "PseudoVWMULSU">;
defm : pat_intrinsic_int_ternary_v_vvv_vvx<"int_riscv_vmacc", "PseudoVMACC">;
defm : pat_intrinsic_int_ternary_v_vvv_vvx<"int_riscv_vnmsac", "PseudoVNMSAC">;
defm : pat_intrinsic_int_ternary_v_vvv_vvx<"int_riscv_vmadd", "PseudoVMADD">;
defm : pat_intrinsic_int_ternary_v_vvv_vvx<"int_riscv_vnmsub", "PseudoVNMSUB">;
defm : pat_intrinsic_int_ternary_w_wvv_wvx<"int_riscv_vwmacc", "PseudoVWMACC">;
defm : pat_intrinsic_int_ternary_w_wvv_wvx<"int_riscv_vwmaccu", "PseudoVWMACCU">;
defm : pat_intrinsic_int_ternary_w_wvv_wvx<"int_riscv_vwmaccsu", "PseudoVWMACCSU">;
defm : pat_intrinsic_int_ternary_w_wvx<"int_riscv_vwmaccus", "PseudoVWMACCUS">;
defm : pat_intrinsic_int_ternary_qw_wvv_wvx<"int_riscv_vqmacc", "PseudoVQMACC">;
defm : pat_intrinsic_int_ternary_qw_wvv_wvx<"int_riscv_vqmaccu", "PseudoVQMACCU">;
defm : pat_intrinsic_int_ternary_qw_wvv_wvx<"int_riscv_vqmaccsu", "PseudoVQMACCSU">;
defm : pat_intrinsic_int_ternary_qw_wvx<"int_riscv_vqmaccus", "PseudoVQMACCUS">;
defm : pat_intrinsic_vmerge<"int_riscv_vmerge", "PseudoVMERGE">;
defm : pat_intrinsic_vfmerge<"int_riscv_vfmerge", "PseudoVFMERGE">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vsadd", "PseudoVSADD">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vsaddu", "PseudoVSADDU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vaadd", "PseudoVAADD">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vaaddu", "PseudoVAADDU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vssub", "PseudoVSSUB">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vssubu", "PseudoVSSUBU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vasub", "PseudoVASUB">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vasubu", "PseudoVASUBU">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vsmul", "PseudoVSMUL">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vssrl", "PseudoVSSRL">;
defm : pat_intrinsic_int_binary_vv_vx<"int_riscv_vssra", "PseudoVSSRA">;
defm : pat_intrinsic_int_binary_n_wn_wx<"int_riscv_vnclip", "PseudoVNCLIP">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfadd", "PseudoVFADD">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfsub", "PseudoVFSUB">;
defm : pat_intrinsic_float_binary_v_vf<"int_riscv_vfrsub", "PseudoVFRSUB">;
defm : pat_intrinsic_float_binary_w_vv_vf_wv_wf<"int_riscv_vfwadd", "PseudoVFWADD">;
defm : pat_intrinsic_float_binary_w_vv_vf_wv_wf<"int_riscv_vfwsub", "PseudoVFWSUB">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfmul", "PseudoVFMUL">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfdiv", "PseudoVFDIV">;
defm : pat_intrinsic_float_binary_v_vf<"int_riscv_vfrdiv", "PseudoVFRDIV">;
defm : pat_intrinsic_float_binary_w_vv_vf<"int_riscv_vfwmul", "PseudoVFWMUL">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfnmacc", "PseudoVFNMACC">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfnmsac", "PseudoVFNMSAC">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfmadd", "PseudoVFMADD">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfnmadd", "PseudoVFNMADD">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfmsub", "PseudoVFMSUB">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfnmsub", "PseudoVFNMSUB">;
defm : pat_intrinsic_float_ternary_w_wvv_wvf<"int_riscv_vfwmacc", "PseudoVFWMACC">;
defm : pat_intrinsic_float_ternary_w_wvv_wvf<"int_riscv_vfwnmacc", "PseudoVFWNMACC">;
defm : pat_intrinsic_float_ternary_w_wvv_wvf<"int_riscv_vfwmsac", "PseudoVFWMSAC">;
defm : pat_intrinsic_float_ternary_w_wvv_wvf<"int_riscv_vfwnmsac", "PseudoVFWNMSAC">;
defm : pat_intrinsic_float_unary_v_v<"int_riscv_vfsqrt", "PseudoVFSQRT">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfmin", "PseudoVFMIN">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfmax", "PseudoVFMAX">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfsgnj", "PseudoVFSGNJ">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfsgnjn", "PseudoVFSGNJN">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfsgnjx", "PseudoVFSGNJX">;
defm : pat_intrinsic_float_binary_m_vv_vf<"int_riscv_vmfeq", "PseudoVMFEQ">;
defm : pat_intrinsic_float_binary_m_vv_vf<"int_riscv_vmfne", "PseudoVMFNE">;
defm : pat_intrinsic_float_binary_m_vv_vf<"int_riscv_vmflt", "PseudoVMFLT">;
defm : pat_intrinsic_float_binary_m_vv_vf<"int_riscv_vmfle", "PseudoVMFLE">;
defm : pat_intrinsic_float_binary_m_vf<"int_riscv_vmfgt", "PseudoVMFGT">;
defm : pat_intrinsic_float_binary_m_vf<"int_riscv_vmfge", "PseudoVMFGE">;
defm : pat_intrinsic_float_unary_v_v<"int_riscv_vfclass", "PseudoVFCLASS">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredsum", "PseudoVREDSUM">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredmax", "PseudoVREDMAX">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredmaxu", "PseudoVREDMAXU">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredmin", "PseudoVREDMIN">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredminu", "PseudoVREDMINU">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredand", "PseudoVREDAND">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredor", "PseudoVREDOR">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredxor", "PseudoVREDXOR">;
defm : pat_intrinsic_int_ternary_v_vvx<"int_riscv_vslideup", "PseudoVSLIDEUP">;
defm : pat_intrinsic_int_ternary_v_vvx<"int_riscv_vslidedown", "PseudoVSLIDEDOWN">;
defm : pat_intrinsic_float_reduction<"int_riscv_vfredosum", "PseudoVFREDOSUM">;
defm : pat_intrinsic_float_reduction<"int_riscv_vfredsum", "PseudoVFREDSUM">;
defm : pat_intrinsic_float_reduction<"int_riscv_vfredmax", "PseudoVFREDMAX">;
defm : pat_intrinsic_float_reduction<"int_riscv_vfredmin", "PseudoVFREDMIN">;
defm : pat_intrinsic_unary_n_f_v<"int_riscv_vfncvt_x_f", "PseudoVFNCVT_X_F">;
defm : pat_intrinsic_unary_w_f_v<"int_riscv_vfwcvt_x_f", "PseudoVFWCVT_X_F">;
defm : pat_intrinsic_unary_w_f_v<"int_riscv_vfwcvt_xu_f", "PseudoVFWCVT_XU_F">;
defm : pat_intrinsic_unary_w_f_v<"int_riscv_vfwcvt_rtz_x_f", "PseudoVFWCVT_RTZ_X_F">;
defm : pat_intrinsic_unary_w_f_v<"int_riscv_vfwcvt_rtz_xu_f", "PseudoVFWCVT_RTZ_XU_F">;
defm : pat_intrinsic_unary_w_v_f<"int_riscv_vfwcvt_f_x", "PseudoVFWCVT_F_X">;
defm : pat_intrinsic_unary_w_v_f<"int_riscv_vfwcvt_f_xu", "PseudoVFWCVT_F_XU">;
defm : pat_intrinsic_unary_w_f_f<"int_riscv_vfwcvt_f_f", "PseudoVFWCVT_F_F">;

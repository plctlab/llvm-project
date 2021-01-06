//===-- RISCVPseudoInfoV.td - RISC-V 'V' instructions -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the RISC-V instructions from the standard 'V' Vector
// extension, version 0.9. This version is still experimental as the 'V'
// extension hasn't been ratified yet.
//
//===----------------------------------------------------------------------===//

// Join strings in list using separator and ignoring empty elements
class Join<list<string> strings, string seperator> {
  string Result = !foldl(!head(strings), !tail(strings), a, b, 
                         !cond(!and(!empty(a), !empty(b)) : "",
                               !empty(a) : b,
                               !empty(b) : a,
                               1 : a#seperator#b));
}

class ToScalarOp<ValueType type, DAGOperand operand, string name> {
  dag Result = !cond(!eq(!cast<string>(operand), !cast<string>(GPR)) :
                         !dag(type, [GPR], [name]),
                     !eq(!cast<string>(operand), !cast<string>(FPR32)) :
                         !dag(type, [FPR32], [name]),
                     !eq(!cast<string>(operand), !cast<string>(FPR64)):
                         (EXTRACT_SUBREG !dag(type, [FPR64], [name]), sub_32),
                     1 : !dag(type, [operand], [name]));
}

class RoundFMToM1<string Lmul> {
  string Result = !cond(!eq(Lmul, "F8") : "1",
                        !eq(Lmul, "F4") : "1",
                        !eq(Lmul, "F2") : "1",
                        1 : Lmul);
}

class VectorTypeInfo<ValueType type, ValueType mask, int sew,
                     RegisterClass reg_class, int lmul, string lmul_str> {
  ValueType Type = type;
  ValueType Mask = mask;
  int SEW = sew;
  RegisterClass RegClass = reg_class;
  int LMUL = lmul;
  string LMULstr = lmul_str;
} 

class LMULToRC<string lmul, RegisterClass reg_class, int lmul_value> {
  string LMULstr = lmul;
  RegisterClass RegClass = reg_class;
  int LMUL = lmul_value;
} 

defset list<LMULToRC> AllLMULs = {
  def M1 : LMULToRC<"1", VR, 1>;
  def M2 : LMULToRC<"2", VRM2, 2>;
  def M4 : LMULToRC<"4", VRM4, 4>;
  def M8 : LMULToRC<"8", VRM8, 8>;
  def MF2 : LMULToRC<"F2", VR, 9>;
  def MF4 : LMULToRC<"F4", VR, 10>;
  def MF8 : LMULToRC<"F8", VR, 11>;
}

class WideLMULToRCInfo<RegisterClass ori, RegisterClass wid, string olmul,
                       string wlmul, int lmul> {
  RegisterClass OriginRegClass = ori;
  RegisterClass WideRegClass = wid;
  string OriginLMULstr = olmul;
  string WideLMULstr = wlmul;
  int LMUL = lmul;
}

defset list<WideLMULToRCInfo> AllWideLMULs = {
  // TODO : fractional lmul
  def WMF4 : WideLMULToRCInfo<VR, VR, "F8", "F4", 11>;
  def WMF2 : WideLMULToRCInfo<VR, VR, "F4", "F2", 10>;
  def WM1 : WideLMULToRCInfo<VR, VR, "F2", "1", 9>;
  def WM2 : WideLMULToRCInfo<VR, VRM2, "1", "2", 1>;
  def WM4 : WideLMULToRCInfo<VRM2, VRM4, "2", "4", 2>;
  def WM8 : WideLMULToRCInfo<VRM4, VRM8, "4", "8", 4>;
}

defset list<VectorTypeInfo> AllVectors = {
  defset list<VectorTypeInfo> AllIntegerVectors = {
    defset list<VectorTypeInfo> FractionalLmulIntegerVectors = {
      // vint8mf2_t, vbool16_t
      def Vtypev4xi8 : VectorTypeInfo<nxv4i8, nxv4i1, 8, VR, 9, "F2">;
      // vint16mf2_t, vbool32_t
      def Vtypev2xi16 : VectorTypeInfo<nxv2i16, nxv2i1, 16, VR, 9, "F2">;
      // vint32mf2_t, vbool64_t
      def Vtypev1xi32 : VectorTypeInfo<nxv1i32, nxv1i1, 32, VR, 9, "F2">;

      // vint8mf4_t, vbool32_t
      def Vtypev2xi8 : VectorTypeInfo<nxv2i8, nxv2i1, 8, VR, 10, "F4">;
      // vint16mf4_t, vbool64_t
      def Vtypev1xi16 : VectorTypeInfo<nxv1i16, nxv1i1, 16, VR, 10, "F4">;

      // vint8mf8_t, vbool64_t
      def Vtypev1xi8 : VectorTypeInfo<nxv1i8, nxv1i1, 8, VR, 11, "F8">;
    }

    defset list<VectorTypeInfo> NoGroupIntegerVectors = {
      // vint8m1_t, vbool8_t
      def Vtypev8xi8 : VectorTypeInfo<nxv8i8, nxv8i1, 8, VR, 1, "1">;
      // vint16m1_t, vbool16_t
      def Vtypev4xi16 : VectorTypeInfo<nxv4i16, nxv4i1, 16, VR, 1, "1">;
      // vint32m1_t, vbool32_t
      def Vtypev2xi32 : VectorTypeInfo<nxv2i32, nxv2i1, 32, VR, 1, "1">;
      // vint64m1_t, vbool64_t
      def Vtypev1xi64 : VectorTypeInfo<nxv1i64, nxv1i1, 64, VR, 1, "1">;
    }

    defset list<VectorTypeInfo> GroupIntegerVectors = {
      // vint8m2_t, vbool4_t
      def Vtypev16xi8 : VectorTypeInfo<nxv16i8, nxv16i1, 8, VRM2, 2, "2">;
      // vint16m2_t, vbool8_t
      def Vtypev8xi16 : VectorTypeInfo<nxv8i16, nxv8i1, 16, VRM2, 2, "2">;
      // vint32m2_t, vbool16_t
      def Vtypev4xi32 : VectorTypeInfo<nxv4i32, nxv4i1, 32, VRM2, 2, "2">;
      // vint64m2_t, vbool32_t
      def Vtypev2xi64 : VectorTypeInfo<nxv2i64, nxv2i1, 64, VRM2, 2, "2">;

      // vint8m4_t, vbool2_t
      def Vtypev32xi8 : VectorTypeInfo<nxv32i8, nxv32i1, 8, VRM4, 4, "4">;
      // vint16m4_t, vbool4_t
      def Vtypev16xi16 : VectorTypeInfo<nxv16i16, nxv16i1, 16, VRM4, 4, "4">;
      // vint32m4_t, vbool8_t
      def Vtypev8xi32 : VectorTypeInfo<nxv8i32, nxv8i1, 32, VRM4, 4, "4">;
      // vint64m4_t, vbool16_t
      def Vtypev4xi64 : VectorTypeInfo<nxv4i64, nxv4i1, 64, VRM4, 4, "4">;

      // vint8m8_t, vbool1_t
      def Vtypev64xi8 : VectorTypeInfo<nxv64i8, nxv64i1, 8, VRM8, 8, "8">;
      // vint16m8_t, vbool2_t
      def Vtypev32xi16 : VectorTypeInfo<nxv32i16, nxv32i1, 16, VRM8, 8, "8">;
      // vint32m8_t, vbool4_t
      def Vtypev16xi32 : VectorTypeInfo<nxv16i32, nxv16i1, 32, VRM8, 8, "8">;
      // vint64m8_t, vbool8_t
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

class WideVectorInfo<VectorTypeInfo ori, ValueType wid, RegisterClass wrc,
                     string widelmulstr> {
  VectorTypeInfo OriginVector = ori;
  ValueType WidenVector = wid;
  RegisterClass WidenRegClass = wrc;
  int WidenSEW = ori.SEW;
  string WidenLMULstr = widelmulstr;
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
  // vint32mf2_t, vint8mf8_t
  def QWidev1xi8 : WideVectorInfo<Vtypev1xi8, nxv1i32, VR, "F2_8_MF8">;
  // vint32m1_t, vint8mf4_t
  def QWidev2xi8 : WideVectorInfo<Vtypev2xi8, nxv2i32, VR, "1_8_MF4">;
  // vint32m2_t, vint8mf2_t
  def QWidev4xi8 : WideVectorInfo<Vtypev4xi8, nxv4i32, VRM2, "2_8_MF2">;
  // vint32m4_t, vint8m1_t
  def QWidev8xi8 : WideVectorInfo<Vtypev8xi8, nxv8i32, VRM4, "4_8_M1">;
  // vint32m8_t, vint8m2_t
  def QWidev16xi8 : WideVectorInfo<Vtypev16xi8, nxv16i32, VRM8, "8_8_M2">;
  // vint64m1_t, vint16mf4_t
  def QWidev1xi16 : WideVectorInfo<Vtypev1xi16, nxv1i64, VR, "1_16_MF4">;
  // vint64m2_t, vint16mf2_t
  def QWidev2xi16 : WideVectorInfo<Vtypev2xi16, nxv2i64, VRM2, "2_16_MF2">;
  // vint64m4_t, vint16m1_t
  def QWidev4xi16 : WideVectorInfo<Vtypev4xi16, nxv4i64, VRM4, "4_16_M1">;
  // vint64m8_t, vint16m2_t op1
  def QWidev8xi16 : WideVectorInfo<Vtypev8xi16, nxv8i64, VRM8, "8_16_M2">;
}

class VectorTypeInfoPair<VectorTypeInfo first, VectorTypeInfo second,
                         string lmulstr> {
  VectorTypeInfo First = first;
  VectorTypeInfo Second = second;
  string LMULstr = lmulstr;
}

defset list<VectorTypeInfoPair> AllWideIntAndFloatVectors = {
  // vint32mf2_t, vfloat16mf4_t
  def : VectorTypeInfoPair<Vtypev1xi32, Vtypev1xf16, "F4_16_MF2">;
  // vint32m1_t, vfloat16mf2_t
  def : VectorTypeInfoPair<Vtypev2xi32, Vtypev2xf16, "F2_16_M1">;
  // vint32m2_t ,vfloat16m1_t
  def : VectorTypeInfoPair<Vtypev4xi32, Vtypev4xf16, "1_16_M2">;
  // vint32m4_t ,vfloat16m2_t
  def : VectorTypeInfoPair<Vtypev8xi32, Vtypev8xf16, "2_16_M4">;
  // vint32m8_t ,vfloat16m4_t
  def : VectorTypeInfoPair<Vtypev16xi32, Vtypev16xf16, "4_16_M8">;
  // vint64m1_t ,vfloat32mf2_t
  def : VectorTypeInfoPair<Vtypev1xi64, Vtypev1xf32, "F2_32_M1">;
  // vint64m2_t ,vfloat32m1_t
  def : VectorTypeInfoPair<Vtypev2xi64, Vtypev2xf32, "1_32_M2">;
  // vint64m4_t ,vfloat32m2_t
  def : VectorTypeInfoPair<Vtypev4xi64, Vtypev4xf32, "2_32_M4">;
  // vint64m8_t ,vfloat32m4_t
  def : VectorTypeInfoPair<Vtypev8xi64, Vtypev8xf32, "4_32_M8">;
}

def RVVIntrinsicsTable : GenericTable {
  let FilterClass = "RVVIntrinsic";
  let CppTypeName = "RVVIntrinsicInfo";
  let Fields = ["IntrinsicID", "ExtendOperand"];
  let PrimaryKey = ["IntrinsicID"];
  let PrimaryKeyName = "getRVVIntrinsicInfo";
}

class RISCVVectorPseudo {
  Pseudo Pseudo = !cast<Pseudo>(NAME);
  Instruction BaseInstr;
  bits<8> SEWIndex;
  bits<8> MergeOpIndex;
  bits<8> LMUL;
}

def RISCVVectorPseudoTable : GenericTable {
  let FilterClass = "RISCVVectorPseudo";
  let CppTypeName = "RISCVVectorPseudoInfo";
  let Fields = ["Pseudo", "BaseInstr", "SEWIndex", "MergeOpIndex", "LMUL"];
  let PrimaryKey = ["Pseudo"];
  let PrimaryKeyName = "getRISCVVectorPseudoInfo";
}

// This functor is used to obtain the int vector type that has the same SEW and
// multiplier as the input parameter type
class GetIntVectorTypeInfo<VectorTypeInfo vti>
{
  // Equivalent integer vector type. Eg.
  //   Vtypev4xf64 → Vtypev4xi64
  VectorTypeInfo Vti = !cast<VectorTypeInfo>(
                       !subst("xf", "xi", !cast<string>(vti)));
}

// This functor is used to obtain the float vector type that has the same SEW
// and multiplier as the input parameter type
class GetFloatVectorTypeInfo<VectorTypeInfo vti>
{
  // Equivalent float vector type. Eg.
  //   Vtypev2xi32 → Vtypev2xf32
  VectorTypeInfo FVti = !cast<VectorTypeInfo>(
                        !subst("xi", "xf", !cast<string>(vti)));
}

foreach I = [M1, M2, M4, M8] in {
  defvar lmul = I.LMULstr;
  foreach sew = [8, 16, 32, 64] in {
    let mayLoad = 1, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0,
        LMUL = I.LMUL, SEWIndex = 3, MergeOpIndex = 1,
        BaseInstr = !cast<Instruction>("VL"#lmul#"RE"#sew#"_V") in {
      def PseudoVL#lmul#RE#sew#_V
        : Pseudo<(outs I.RegClass:$rd), (ins I.RegClass:$merge,
                 GPR:$rs1, ixlenimm:$sew), []>,
          RISCVVectorPseudo;
    }
  }
  let mayLoad = 0, mayStore = 1, hasSideEffects = 0, usesCustomInserter = 0,
    LMUL = I.LMUL, SEWIndex = 3, MergeOpIndex = 0,
    BaseInstr = !cast<Instruction>("VS"#lmul#"R_V") in {
  def PseudoVS#lmul#R_V
    : Pseudo<(outs), (ins I.RegClass:$merge, I.RegClass:$rs1,
              GPR:$rs2, ixlenimm:$sew), []>,
      RISCVVectorPseudo;
  }
}

// load / store instruction
foreach I = AllLMULs in {
  defvar lmul = I.LMULstr;
  foreach sew = [8, 16, 32, 64] in {
    let mayLoad = 1, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1,
      LMUL = I.LMUL in 
    {
      let Uses = [VL, VTYPE], SEWIndex = 4, MergeOpIndex = 1,
        BaseInstr = !cast<Instruction>("VLE"#sew#"_V") in 
        def PseudoVLE#sew#_V_M#lmul
          : Pseudo<(outs I.RegClass:$rd), (ins I.RegClass:$merge,
                 GPR:$rs1, VMaskOp:$mask, ixlenimm:$sew), []>,
          RISCVVectorPseudo;
     
      let Uses = [VL, VTYPE], SEWIndex = 5, MergeOpIndex = 1,
        BaseInstr = !cast<Instruction>("VLXEI"#sew#"_V") in
        def PseudoVLXEI#sew#_V_M#lmul
          : Pseudo<(outs I.RegClass:$rd), (ins I.RegClass:$merge,
                 GPR:$rs1, I.RegClass:$rs2, VMaskOp:$mask, ixlenimm:$sew), []>,
          RISCVVectorPseudo; 
 
    }

    let mayLoad = 0, mayStore = 1, hasSideEffects = 0, usesCustomInserter = 1,
        LMUL = I.LMUL, Uses = [VL, VTYPE], SEWIndex = 4, MergeOpIndex = 0,
        BaseInstr = !cast<Instruction>("VSE"#sew#"_V") in {
      def PseudoVSE#sew#_V_M#lmul
        : Pseudo<(outs), (ins I.RegClass:$merge, I.RegClass:$rs1,
                 GPR:$rs2, VMaskOp:$mask, ixlenimm:$sew), []>,
          RISCVVectorPseudo;
    }
  
  }  
}

let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1 in {

multiclass pseudo_unary<RegisterClass result, RegisterClass arg1,
                        string lmul, string constraints = ""> {
  let Constraints = Join<[constraints, "$rd = $merge"], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 4, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # lmul
      : Pseudo<(outs result:$rd), (ins result:$merge, arg1:$rs1, VMaskOp:$vm,
               ixlenimm:$sew), []>,
        RISCVVectorPseudo;
}

multiclass pseudo_unary_nomask<RegisterClass result, RegisterClass arg1,
                               string lmul, string constraints = ""> {
  let Constraints = Join<[constraints, ""], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 3, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # lmul
      : Pseudo<(outs result:$rd), (ins result:$merge, arg1:$rs1,
               ixlenimm:$sew), []>,
        RISCVVectorPseudo;
}

// vop.v vd, vs2, vm
multiclass pseudo_unary_v_v {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _V : pseudo_unary<I.RegClass, I.RegClass, I.LMULstr>;
}

multiclass pseudo_unary_v_w<string constraints = ""> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = I.First;
    defvar src = I.Second;
    let LMUL = src.LMUL in {
      defm _V : pseudo_unary<dst.RegClass, src.RegClass, I.LMULstr,
                             constraints>;
    }
  }
}

// vop.m vd, vs2, vm
multiclass pseudo_unary_v_m {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _M : pseudo_unary<I.RegClass, VM, I.LMULstr>;
}

// vop.v vd, vm
multiclass pseudo_vid_v<RegisterClass result, string lmul,
                        string constraints = ""> {
  let Constraints = Join<[constraints, "$rd = $merge"], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 3, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # lmul
      : Pseudo<(outs result:$rd), (ins result:$merge, VMaskOp:$vm,
               ixlenimm:$sew), []>,
        RISCVVectorPseudo;
}

multiclass pseudo_vid {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _V : pseudo_vid_v<I.RegClass, I.LMULstr>;
}

multiclass pseudo_unary_f_w<string constraints = ""> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = GetFloatVectorTypeInfo<I.First>.FVti;
    defvar src = GetIntVectorTypeInfo<I.Second>.Vti;
    let LMUL = src.LMUL in {
      defm _V : pseudo_unary<dst.RegClass, src.RegClass, I.LMULstr,
                             constraints>;
    }
  }
}

multiclass pseudo_unary_f_f<string constraints = ""> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = GetFloatVectorTypeInfo<I.First>.FVti;
    defvar src = I.Second;
    let LMUL = src.LMUL in {
      defm _V : pseudo_unary<dst.RegClass, src.RegClass, I.LMULstr,
                             constraints>;
    }
  }
}

multiclass pseudo_unary_f_n<string constraints = ""> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = GetIntVectorTypeInfo<I.Second>.Vti;
    defvar src = GetFloatVectorTypeInfo<I.First>.FVti;
    let LMUL = dst.LMUL in {
      defm _W : pseudo_unary<dst.RegClass, src.RegClass, I.LMULstr,
                             constraints>;
    }
  }
}

multiclass pseudo_unary_v_n<string constraints = ""> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = I.Second;
    defvar src = I.First;
    let LMUL = dst.LMUL in {
      defm _W : pseudo_unary<dst.RegClass, src.RegClass, I.LMULstr,
                             constraints>;
    }
  }
}

multiclass pseudo_unary_f_f_n<string constraints = ""> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = I.Second;
    defvar src = GetFloatVectorTypeInfo<I.First>.FVti;
    let LMUL = dst.LMUL in {
      defm _W : pseudo_unary<dst.RegClass, src.RegClass, I.LMULstr,
                             constraints>;
    }
  }
}

// vmv.v.v vd, vs1
// vmv.v.x vd, rs1
// vmv.x.s rd, vs2
// vmv.s.x vd, rs1
multiclass pseudo_vmv {
  foreach I = AllLMULs in {
    let LMUL = I.LMUL in {
      defm _V_V : pseudo_unary_nomask<I.RegClass, I.RegClass, I.LMULstr>;
      defm _V_X : pseudo_unary_nomask<I.RegClass, GPR, I.LMULstr>;
      defm _X_S : pseudo_unary_nomask<GPR, I.RegClass, I.LMULstr>;
      defm _S_X : pseudo_unary_nomask<I.RegClass, GPR, I.LMULstr>;
    }
  }
}

// vfmv.f.s rd, vs2
// vfmv.s.f vd, rs1
// vfmv.v.f vd, rs1
multiclass pseudo_vfmv {
  foreach I = AllLMULs in {
    let LMUL = I.LMUL in {
      defm _F_S : pseudo_unary_nomask<FPR32, I.RegClass, I.LMULstr>;
      defm _S_F : pseudo_unary_nomask<I.RegClass, FPR32, I.LMULstr>;
      defm _V_F : pseudo_unary_nomask<I.RegClass, FPR32, I.LMULstr>;
    }
  }
}

multiclass pseudo_binary<RegisterClass result, RegisterClass arg1,
                         RegisterClass arg2, string lmul,
                         string constraints = ""> {
  let Constraints = Join<[constraints, "$rd = $merge"], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 5, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # lmul
      : Pseudo<(outs result:$rd), (ins result:$merge, arg1:$rs1, arg2:$rs2,
               VMaskOp:$vm, ixlenimm:$sew), []>,
        RISCVVectorPseudo;
}

multiclass pseudo_binary_nomask<RegisterClass result, RegisterClass arg1,
                                RegisterClass arg2, string lmul,
                                string constraints = ""> {
  let Constraints = Join<[constraints, ""], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 4, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # lmul
      : Pseudo<(outs result:$rd), (ins result:$merge, arg1:$rs1, arg2:$rs2,
               ixlenimm:$sew), []>,
        RISCVVectorPseudo;
}

multiclass pseudo_binary_carryin<RegisterClass result, RegisterClass arg1,
                                 RegisterClass arg2, string lmul,
                                 string constraints = ""> {
  let Constraints = Join<[constraints, ""], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 5, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # lmul
      : Pseudo<(outs result:$rd), (ins result:$merge, arg1:$rs1, arg2:$rs2,
               VMV0:$maskop, ixlenimm:$sew), []>,
        RISCVVectorPseudo;
}

multiclass pseudo_binary_v_vv<string constraints = ""> {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VV : pseudo_binary<I.RegClass, I.RegClass, I.RegClass, I.LMULstr,
                               constraints>;
}

multiclass pseudo_binary_v_vx<string constraints = ""> {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VX : pseudo_binary<I.RegClass, I.RegClass, GPR, I.LMULstr,
                               constraints>;
}

multiclass pseudo_binary_v_vf<string constraints = ""> {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VF : pseudo_binary<I.RegClass, I.RegClass, FPR32, I.LMULstr,
                               constraints>;
}

multiclass pseudo_binary_v_vv_vx<string constraints = "">
  : pseudo_binary_v_vv<constraints>, pseudo_binary_v_vx<constraints>;

multiclass pseudo_binary_v_vv_vf<string constraints = "">
  : pseudo_binary_v_vv<constraints>, pseudo_binary_v_vf<constraints>;

multiclass pseudo_binary_w_vv_vx<string constraints = ""> {
  foreach I = AllWideLMULs in {
    let LMUL = I.LMUL in {
      defm _VV : pseudo_binary<I.WideRegClass, I.OriginRegClass,
                               I.OriginRegClass, I.WideLMULstr, constraints>;
      defm _VX : pseudo_binary<I.WideRegClass, I.OriginRegClass,
                               GPR, I.WideLMULstr, constraints>;
    }
  }
}

multiclass pseudo_binary_w_wv_wx<string constraints = ""> {
  foreach I = AllWideLMULs in {
    let LMUL = I.LMUL in {
      defm _WV : pseudo_binary<I.WideRegClass, I.WideRegClass,
                               I.OriginRegClass, I.WideLMULstr, constraints>;
      defm _WX : pseudo_binary<I.WideRegClass, I.WideRegClass,
                               GPR, I.WideLMULstr, constraints>;
    }
  }
}

multiclass pseudo_binary_w_vv_vx_wv_wx<string constraints = "">
  : pseudo_binary_w_vv_vx<constraints>, pseudo_binary_w_wv_wx<constraints>;

multiclass pseudo_binary_w_vv_vf<string constraints = ""> {
  foreach I = AllWideLMULs in {
    let LMUL = I.LMUL in {
      defm _VV : pseudo_binary<I.WideRegClass, I.OriginRegClass,
                               I.OriginRegClass, I.WideLMULstr, constraints>;
      defm _VF : pseudo_binary<I.WideRegClass, I.OriginRegClass,
                               FPR32, I.WideLMULstr, constraints>;
    }
  }
}

multiclass pseudo_binary_w_wv_wf<string constraints = ""> {
  foreach I = AllWideLMULs in {
    let LMUL = I.LMUL in {
      defm _WV : pseudo_binary<I.WideRegClass, I.WideRegClass,
                               I.OriginRegClass, I.WideLMULstr, constraints>;
      defm _WF : pseudo_binary<I.WideRegClass, I.WideRegClass,
                               FPR32, I.WideLMULstr, constraints>;
    }
  }
}

multiclass pseudo_binary_w_vv_vf_wv_wf<string constraints = "">
  : pseudo_binary_w_vv_vf<constraints>, pseudo_binary_w_wv_wf<constraints>;

multiclass pseudo_binary_n_wn_wx<string constraints = ""> {
  foreach I = AllWideLMULs in {
    let LMUL = I.LMUL in {
      defm _WV : pseudo_binary<I.OriginRegClass, I.WideRegClass,
                               I.OriginRegClass, I.OriginLMULstr, constraints>;
      defm _WX : pseudo_binary<I.OriginRegClass, I.WideRegClass, GPR,
                               I.OriginLMULstr, constraints>;
    }
  }
}

multiclass pseudo_binary_v_vfm<string constraints = ""> {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VFM : pseudo_binary_carryin<I.RegClass, I.RegClass, FPR32,
                                        I.LMULstr, constraints>;
}

multiclass pseudo_binary_v_vvm_vxm<string constraints = ""> {
  foreach I = AllLMULs in {
    let LMUL = I.LMUL in {
      defm _VVM : pseudo_binary_carryin<I.RegClass, I.RegClass, I.RegClass,
                                        I.LMULstr, constraints>;
      defm _VXM : pseudo_binary_carryin<I.RegClass, I.RegClass, GPR,
                                        I.LMULstr, constraints>;
    }
  }
}

multiclass pseudo_binary_m_vvm_vxm<string constraints = ""> {
  foreach I = AllLMULs in {
    let LMUL = I.LMUL in {
      defm _VVM : pseudo_binary_carryin<VM, I.RegClass, I.RegClass,
                                        I.LMULstr, constraints>;
      defm _VXM : pseudo_binary_carryin<VM, I.RegClass, I.RegClass,
                                        I.LMULstr, constraints>;
    }
  }
}

multiclass pseudo_binary_m_vv<string constraints = ""> {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VV : pseudo_binary<VM, I.RegClass, I.RegClass, I.LMULstr,
                               constraints>;
}

multiclass pseudo_binary_m_vx<string constraints = ""> {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VX : pseudo_binary<VM, I.RegClass, GPR, I.LMULstr, constraints>;
}

multiclass pseudo_binary_m_vf<string constraints = ""> {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VF : pseudo_binary<VM, I.RegClass, FPR32, I.LMULstr, constraints>;
}

multiclass pseudo_binary_m_vv_vx<string constraints = "">
  : pseudo_binary_m_vv<constraints>, pseudo_binary_m_vx<constraints>;

multiclass pseudo_binary_m_vv_vf<string constraints = "">
  : pseudo_binary_m_vv<constraints>, pseudo_binary_m_vf<constraints>;

multiclass pseudo_ternary<RegisterClass result, RegisterClass arg1,
                          RegisterClass arg2, string lmul,
                          string constraints = ""> {
  let Constraints = Join<[constraints, "$rd = $merge"], ",">.Result,
      Uses = [VL, VTYPE], SEWIndex = 5, MergeOpIndex = 1,
      BaseInstr = !cast<Instruction>(!subst("Pseudo", "", NAME)) in
    def "_M" # lmul
      : Pseudo<(outs result:$rd), (ins result:$merge, arg1:$rs1, arg2:$rs2,
               VMaskOp:$vm, ixlenimm:$sew), []>,
        RISCVVectorPseudo;
}

multiclass pseudo_ternary_reduction {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VS : pseudo_ternary<VR, I.RegClass, VR, I.LMULstr>;
}

multiclass pseudo_ternary_v_vvv_vvf<string constraints = ""> {
  foreach I = AllLMULs in {
    let LMUL = I.LMUL in {
      defm _VV : pseudo_ternary<I.RegClass, I.RegClass, I.RegClass, I.LMULstr,
                                constraints>;
      defm _VF : pseudo_ternary<I.RegClass, FPR32, I.RegClass, I.LMULstr,
                                constraints>;
    }
  }
}

multiclass pseudo_ternary_v_vvx<string constraints = ""> {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VX : pseudo_ternary<I.RegClass, I.RegClass, GPR, I.LMULstr,
                                constraints>;
}

multiclass pseudo_ternary_v_vvv_vvx<string constraints = ""> {
  foreach I = AllLMULs in {
    let LMUL = I.LMUL in {
      defm _VV : pseudo_ternary<I.RegClass, I.RegClass, I.RegClass, I.LMULstr,
                                constraints>;
      defm _VX : pseudo_ternary<I.RegClass, GPR, I.RegClass, I.LMULstr,
                                constraints>;
    }
  }
}

multiclass pseudo_binary_v_vm<string constraints = ""> {
  foreach I = AllLMULs in
    let LMUL = I.LMUL in
      defm _VM : pseudo_binary_nomask<I.RegClass, I.RegClass, VM, I.LMULstr,
                                      constraints>;
}

multiclass pseudo_ternary_w_wvv<string constraints = ""> {
  foreach I = AllWideLMULs in
    let LMUL = I.LMUL in
      defm _VV : pseudo_ternary<I.WideRegClass, I.OriginRegClass,
                                I.OriginRegClass, I.WideLMULstr, constraints>;
}

multiclass pseudo_ternary_w_wvx<string constraints = ""> {
  foreach I = AllWideLMULs in
    let LMUL = I.LMUL in
      defm _VX : pseudo_ternary<I.WideRegClass, GPR, I.OriginRegClass,
                                I.WideLMULstr, constraints>;
}

multiclass pseudo_ternary_w_wvf<string constraints = ""> {
  foreach I = AllWideLMULs in
    let LMUL = I.LMUL in
      defm _VF : pseudo_ternary<I.WideRegClass, FPR32, I.OriginRegClass,
                                I.WideLMULstr, constraints>;
}

multiclass pseudo_ternary_w_wvv_wvx<string constraints = "">
  : pseudo_ternary_w_wvv<constraints>, pseudo_ternary_w_wvx<constraints>;

multiclass pseudo_ternary_w_wvv_wvf<string constraints = "">
  : pseudo_ternary_w_wvv<constraints>, pseudo_ternary_w_wvf<constraints>;

multiclass pseudo_ternary_qw_wvv<string constraints = ""> {
  foreach I = AllQuadWideIntegerVectors in
    let LMUL = I.OriginVector.LMUL in
      defm _VV : pseudo_ternary<I.WidenRegClass, I.OriginVector.RegClass,
                                I.OriginVector.RegClass, I.WidenLMULstr,
                                constraints>;
}

multiclass pseudo_ternary_qw_wvx<string constraints = ""> {
  foreach I = AllQuadWideIntegerVectors in
    let LMUL = I.OriginVector.LMUL in
      defm _VX : pseudo_ternary<I.WidenRegClass, GPR, I.OriginVector.RegClass,
                                I.WidenLMULstr, constraints>;
}

multiclass pseudo_ternary_qw_wvv_wvx<string constraints = "">
  : pseudo_ternary_qw_wvv<constraints>, pseudo_ternary_qw_wvx<constraints>;

} // let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 1

// pseudo instructions for read CSR register
let mayLoad = 0, mayStore = 0, hasSideEffects = 0 in {
  def PseudoReadVTYPE : Pseudo<(outs GPR:$v0), (ins ), []> {
    let Uses = [VTYPE];
  }

  def PseudoReadVL : Pseudo<(outs GPR:$v0), (ins ), []> {
    let Uses = [VL];
  }
}

//===----------------------------------------------------------------------===//
// Patterns for intrinsics
//===----------------------------------------------------------------------===//

class swap_helper<dag Prefix, dag A, dag B, dag Suffix, bit swap> {
  dag Value = !con(Prefix, !if(swap, B, A), !if(swap, A, B), Suffix);
}

multiclass pat_intrinsic_unary<string intrinsic_name, string insn_name,
                               ValueType result_type, ValueType arg1_type,
                               ValueType mask_type, int sew, string lmul,
                               RegisterClass result, RegisterClass arg1> {
  defvar insn = !cast<Instruction>(insn_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type arg1:$rs1))),
            (insn (result_type zero_reg), arg1:$rs1,
                  (mask_type zero_reg), sew)>;

  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name#"_mask")
                         (mask_type V0),
                         (result_type result:$merge),
                         (arg1_type arg1:$rs1))),
            (insn result:$merge, arg1:$rs1, (mask_type V0), sew)>;
}

multiclass pat_intrinsic_unary_nomask<string intrinsic_name,
                                      string insn_name,
                                      ValueType result_type,
                                      ValueType arg1_type,
                                      int sew, string lmul,
                                      RegisterClass result,
                                      DAGOperand arg1> {
  defvar insn = !cast<Instruction>(insn_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type arg1:$rs1))),
            (insn (result_type zero_reg),
                  ToScalarOp<arg1_type, arg1, "rs1">.Result, sew)>;
}

multiclass pat_intrinsic_int_unary_v<string intrinsic_name,
                                     string insn_name> {
  foreach I = AllIntegerVectors in
    defm : pat_intrinsic_unary<intrinsic_name#"_v", insn_name#"_V",
                               I.Type, I.Type, I.Mask, I.SEW, I.LMULstr,
                               I.RegClass, I.RegClass>;
}

multiclass pat_intrinsic_float_unary_v_v<string intrinsic_name,
                                         string insn_name> {
  foreach I = AllFloatVectors in
    defm : pat_intrinsic_unary<intrinsic_name#"_v", insn_name#"_V",
                               I.Type, I.Type, I.Mask, I.SEW, I.LMULstr,
                               I.RegClass, I.RegClass>;
}

multiclass pat_intrinsic_int_unary_v_m<string intrinsic_name,
                                       string insn_name> {
  foreach I = AllIntegerVectors in
    defm : pat_intrinsic_unary<intrinsic_name#"_m", insn_name#"_M",
                               I.Type, I.Mask, I.Mask, I.SEW, I.LMULstr,
                               I.RegClass, VM>;
}

multiclass pat_intrinsic_vmv<string intrinsic_name, string insn_name> {
  foreach I = AllIntegerVectors in {
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_v_v",
                                      insn_name#"_V_V", I.Type, I.Type,
                                      I.SEW, I.LMULstr, I.RegClass, I.RegClass>;
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_v_x",
                                      insn_name#"_V_X", I.Type, XLenVT,
                                      I.SEW, I.LMULstr, I.RegClass, GPR>;
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_x_s",
                                      insn_name#"_X_S", XLenVT, I.Type,
                                      I.SEW, I.LMULstr, GPR, I.RegClass>;
    def : Pat<(I.Type (!cast<Intrinsic>(intrinsic_name#"_s_x")
                        (I.Type I.RegClass:$merge), (i64 GPR:$rs1))),
              (!cast<Instruction>(insn_name#"_S_X_M"#I.LMULstr)
               I.RegClass:$merge, GPR:$rs1, I.SEW)>;
  }
}

multiclass pat_intrinsic_vfmv<string intrinsic_name, string insn_name> {
  foreach I = AllFloatVectors in {
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_f_s",
                                      insn_name#"_F_S", f32, I.Type,
                                      I.SEW, I.LMULstr, FPR32, I.RegClass>;
    def : Pat<(f64 (!cast<Intrinsic>(intrinsic_name#"_f_s")
                   (I.Type I.RegClass:$rs1))),
              (SUBREG_TO_REG (i32 -1),
                  (!cast<Instruction>(insn_name#"_F_S_M"#I.LMULstr)
                  (f32 zero_reg), I.RegClass:$rs1, I.SEW), sub_32)>;

    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_v_f",
                                      insn_name#"_V_F", I.Type, f32,
                                      I.SEW, I.LMULstr, I.RegClass, FPR32>;
    defm : pat_intrinsic_unary_nomask<intrinsic_name#"_v_f",
                                      insn_name#"_V_F", I.Type, f64,
                                      I.SEW, I.LMULstr, I.RegClass, FPR64>;
    def : Pat<(I.Type (!cast<Intrinsic>(intrinsic_name#"_s_f")
                        (I.Type I.RegClass:$merge), (f32 FPR32:$rs1))),
              (!cast<Instruction>(insn_name#"_S_F_M"#I.LMULstr)
               I.RegClass:$merge, FPR32:$rs1, I.SEW)>;
  }
}

multiclass pat_intrinsic_unary_w_f_v<string intrinsic_name,
                                     string insn_name> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = I.First;
    defvar src = I.Second;
    defm : pat_intrinsic_unary<intrinsic_name#"_v", insn_name#"_V",
                               dst.Type, src.Type, dst.Mask, src.SEW,
                               I.LMULstr, dst.RegClass, src.RegClass>;

  }
}

multiclass pat_intrinsic_unary_w_v_f<string intrinsic_name,
                                     string insn_name> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = GetFloatVectorTypeInfo<I.First>.FVti;
    defvar src = GetIntVectorTypeInfo<I.Second>.Vti;
    defm : pat_intrinsic_unary<intrinsic_name#"_v", insn_name#"_V",
                               dst.Type, src.Type, dst.Mask, src.SEW,
                               I.LMULstr, dst.RegClass, src.RegClass>;

  }
}

multiclass pat_intrinsic_unary_w_f_f<string intrinsic_name,
                                     string insn_name> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = GetFloatVectorTypeInfo<I.First>.FVti;
    defvar src = I.Second;
    defm : pat_intrinsic_unary<intrinsic_name#"_v", insn_name#"_V",
                               dst.Type, src.Type, dst.Mask, src.SEW,
                               I.LMULstr, dst.RegClass, src.RegClass>;

  }
}

multiclass pat_intrinsic_unary_n_v_f<string intrinsic_name,
                                     string insn_name> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = I.Second;
    defvar src = I.First;
    defm : pat_intrinsic_unary<intrinsic_name#"_w", insn_name#"_W",
                               dst.Type, src.Type, dst.Mask, dst.SEW,
                               I.LMULstr, dst.RegClass, src.RegClass>;
  }
}

multiclass pat_intrinsic_unary_n_f_v<string intrinsic_name,
                                     string insn_name> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = GetIntVectorTypeInfo<I.Second>.Vti;
    defvar src = GetFloatVectorTypeInfo<I.First>.FVti;
    defm : pat_intrinsic_unary<intrinsic_name#"_w", insn_name#"_W",
                               dst.Type, src.Type, dst.Mask, dst.SEW,
                               I.LMULstr, dst.RegClass, src.RegClass>;

  }
}

multiclass pat_intrinsic_unary_n_f_f<string intrinsic_name,
                                     string insn_name> {
  foreach I = AllWideIntAndFloatVectors in {
    defvar dst = I.Second;
    defvar src = GetFloatVectorTypeInfo<I.First>.FVti;
    defm : pat_intrinsic_unary<intrinsic_name#"_w", insn_name#"_W",
                               dst.Type, src.Type, dst.Mask, dst.SEW,
                               I.LMULstr, dst.RegClass, src.RegClass>;

  }
}

multiclass pat_intrinsic_unary_f_v<string intrinsic_name,
                                   string insn_name> {
  foreach I = AllFloatVectors in {
    defvar vti = GetIntVectorTypeInfo<I>.Vti;
    defm : pat_intrinsic_unary<intrinsic_name, insn_name#"_V",
                               vti.Type, I.Type, vti.Mask, vti.SEW,
                               I.LMULstr, vti.RegClass, I.RegClass>;

  }
}

multiclass pat_intrinsic_unary_v_f<string intrinsic_name, string insn_name> {
  foreach I = AllFloatVectors in {
    defvar vti = GetIntVectorTypeInfo<I>.Vti;
    defm : pat_intrinsic_unary<intrinsic_name, insn_name#"_V",
                               I.Type, vti.Type, vti.Mask, vti.SEW,
                               I.LMULstr, I.RegClass, vti.RegClass>;
  }
}

multiclass pat_intrinsic_binary<string intrinsic_name, string insn_name,
                                ValueType result_type, ValueType arg1_type,
                                ValueType arg2_type, ValueType mask_type,
                                int sew, string lmul, RegisterClass result,
                                RegisterClass arg1, DAGOperand arg2,
                                bit swap = 0> {
  defvar insn = !cast<Instruction>(insn_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type arg1:$rs1),
                          (arg2_type arg2:$rs2))),
            swap_helper<
              (insn (result_type (IMPLICIT_DEF))),
              (insn (arg1_type arg1:$rs1)),
              (insn ToScalarOp<arg2_type, arg2, "rs2">.Result),
              (insn (mask_type zero_reg), sew), swap>.Value>;

  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name#"_mask")
                          (mask_type V0), (result_type result:$merge),
                          (arg1_type arg1:$rs1), (arg2_type arg2:$rs2))),
            swap_helper<
              (insn result:$merge), (insn arg1:$rs1),
              (insn ToScalarOp<arg2_type, arg2, "rs2">.Result),
              (insn (mask_type V0), sew), swap>.Value>;
}

multiclass pat_intrinsic_binary_carryin<string intrinsic_name,
                                        string insn_name,
                                        ValueType result_type,
                                        ValueType arg1_type,
                                        ValueType arg2_type,
                                        ValueType carry_type,
                                        int sew, string lmul,
                                        RegisterClass result,
                                        RegisterClass arg1,
                                        DAGOperand arg2,
                                        bit swap = 0> {
  defvar insn = !cast<Instruction>(insn_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type arg1:$rs1), (arg2_type arg2:$rs2),
                          (carry_type V0))),
            (insn (result_type zero_reg), arg1:$rs1,
                  ToScalarOp<arg2_type, arg2, "rs2">.Result,
                  (carry_type V0), sew)>;
}

multiclass pat_intrinsic_int_binary_v_vv<string intrinsic_name,
                                         string insn_name> {
  foreach I = AllIntegerVectors in
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", insn_name#"_VV",
                                I.Type, I.Type, I.Type, I.Mask, I.SEW,
                                I.LMULstr, I.RegClass, I.RegClass, I.RegClass>;
}

multiclass pat_intrinsic_int_binary_v_vx<string intrinsic_name,
                                         string insn_name> {
  foreach I = AllIntegerVectors in
    defm : pat_intrinsic_binary<intrinsic_name#"_vx", insn_name#"_VX",
                                I.Type, I.Type, XLenVT, I.Mask, I.SEW,
                                I.LMULstr, I.RegClass, I.RegClass, GPR>;
}

multiclass pat_intrinsic_int_binary_v_vv_vx<string intrinsic_name,
                                            string insn_name>
  : pat_intrinsic_int_binary_v_vv<intrinsic_name, insn_name>,
    pat_intrinsic_int_binary_v_vx<intrinsic_name, insn_name>;

multiclass pat_intrinsic_float_binary_v_vv<string intrinsic_name,
                                           string insn_name> {
  foreach I = AllFloatVectors in
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", insn_name#"_VV",
                                I.Type, I.Type, I.Type, I.Mask, I.SEW,
                                I.LMULstr, I.RegClass, I.RegClass, I.RegClass>;
}

multiclass pat_intrinsic_float_binary_v_vf<string intrinsic_name,
                                           string insn_name> {
  foreach I = AllFloatVectors in
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", insn_name#"_VF",
                                I.Type, I.Type, f32, I.Mask, I.SEW,
                                I.LMULstr, I.RegClass, I.RegClass, FPR32>;
}

multiclass pat_intrinsic_float_binary_v_vv_vf<string intrinsic_name,
                                              string insn_name>
  : pat_intrinsic_float_binary_v_vv<intrinsic_name, insn_name>,
    pat_intrinsic_float_binary_v_vf<intrinsic_name, insn_name>;

multiclass pat_intrinsic_int_binary_w_vv_vx<string intrinsic_name,
                                            string insn_name> {
  foreach I = AllWideIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", insn_name#"_VV",
                                I.WidenVector, I.OriginVector.Type,
                                I.OriginVector.Type, I.OriginVector.Mask,
                                I.WidenSEW, I.WidenLMULstr, I.WidenRegClass,
                                I.OriginVector.RegClass,
                                I.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vx", insn_name#"_VX",
                                I.WidenVector, I.OriginVector.Type, XLenVT,
                                I.OriginVector.Mask, I.WidenSEW, I.WidenLMULstr,
                                I.WidenRegClass, I.OriginVector.RegClass, GPR>;
    }
}

multiclass pat_intrinsic_int_binary_w_wv_wx<string intrinsic_name,
                                            string insn_name> {
  foreach I = AllWideIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_wv", insn_name#"_WV",
                                I.WidenVector, I.WidenVector,
                                I.OriginVector.Type, I.OriginVector.Mask,
                                I.WidenSEW, I.WidenLMULstr, I.WidenRegClass,
                                I.WidenRegClass, I.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_wx", insn_name#"_WX",
                                I.WidenVector, I.WidenVector, XLenVT,
                                I.OriginVector.Mask, I.WidenSEW, I.WidenLMULstr,
                                I.WidenRegClass, I.WidenRegClass, GPR>;
    }
}

multiclass pat_intrinsic_int_binary_w_vv_vx_wv_wx<string intrinsic_name,
                                                  string insn_name>
  : pat_intrinsic_int_binary_w_vv_vx<intrinsic_name, insn_name>,
    pat_intrinsic_int_binary_w_wv_wx<intrinsic_name, insn_name>;

multiclass pat_intrinsic_int_binary_w_vX0<string intrinsic_name,
                                          string insn_name> {
   foreach I = AllWideIntegerVectors in {
     defvar insn = !cast<Instruction>(insn_name#"_M"#I.WidenLMULstr);
     def : Pat<(I.WidenVector (!cast<Intrinsic>(intrinsic_name)
                (I.OriginVector.Type I.OriginVector.RegClass:$rs1))),
               (insn (I.WidenVector zero_reg), I.OriginVector.RegClass:$rs1, X0,
                     (I.OriginVector.Mask zero_reg), I.WidenSEW)>;

     def : Pat<(I.WidenVector (!cast<Intrinsic>(intrinsic_name#"_mask")
                              (I.OriginVector.Mask V0),
                              (I.WidenVector I.WidenRegClass:$merge),
                    (I.OriginVector.Type I.OriginVector.RegClass:$rs1))),
               (insn (I.WidenVector I.WidenRegClass:$merge),
                     I.OriginVector.RegClass:$rs1, X0,
                     (I.OriginVector.Mask V0), I.WidenSEW)>;
   }
}

multiclass pat_intrinsic_float_binary_w_vv_vf<string intrinsic_name,
                                              string insn_name> {
  foreach I = AllWideFloatVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", insn_name#"_VV",
                                I.WidenVector, I.OriginVector.Type,
                                I.OriginVector.Type, I.OriginVector.Mask,
                                I.WidenSEW, I.WidenLMULstr, I.WidenRegClass,
                                I.OriginVector.RegClass,
                                I.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", insn_name#"_VF",
                                I.WidenVector, I.OriginVector.Type, f32,
                                I.OriginVector.Mask, I.WidenSEW, I.WidenLMULstr,
                                I.WidenRegClass, I.OriginVector.RegClass,
                                FPR32>;
    }
}

multiclass pat_intrinsic_float_binary_w_wv_wf<string intrinsic_name,
                                              string insn_name> {
  foreach I = AllWideFloatVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_wv", insn_name#"_WV",
                                I.WidenVector, I.WidenVector,
                                I.OriginVector.Type, I.OriginVector.Mask,
                                I.WidenSEW, I.WidenLMULstr, I.WidenRegClass,
                                I.WidenRegClass, I.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_wf", insn_name#"_WF",
                                I.WidenVector, I.WidenVector, f32,
                                I.OriginVector.Mask, I.WidenSEW,
                                I.WidenLMULstr, I.WidenRegClass,
                                I.WidenRegClass, FPR32>;
    }
}

multiclass pat_intrinsic_float_binary_w_vv_vf_wv_wf<string intrinsic_name,
                                                    string insn_name>
  : pat_intrinsic_float_binary_w_vv_vf<intrinsic_name, insn_name>,
    pat_intrinsic_float_binary_w_wv_wf<intrinsic_name, insn_name>;

multiclass pat_intrinsic_int_binary_m_vv<string intrinsic_name,
                                         string insn_name> {
  foreach I = AllIntegerVectors in
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", insn_name#"_VV",
                                I.Mask, I.Type, I.Type, I.Mask,
                                I.SEW, I.LMULstr, VM, I.RegClass, I.RegClass>;
}

multiclass pat_intrinsic_int_binary_m_vx<string intrinsic_name,
                                         string insn_name> {
  foreach I = AllIntegerVectors in
    defm : pat_intrinsic_binary<intrinsic_name#"_vx", insn_name#"_VX",
                                I.Mask, I.Type, XLenVT, I.Mask,
                                I.SEW, I.LMULstr, VM, I.RegClass, GPR>;
}

multiclass pat_intrinsic_int_binary_m_vv_vx<string intrinsic_name,
                                            string insn_name>
  : pat_intrinsic_int_binary_m_vv<intrinsic_name, insn_name>,
    pat_intrinsic_int_binary_m_vx<intrinsic_name, insn_name>;

multiclass pat_intrinsic_float_binary_m_vv<string intrinsic_name,
                                           string insn_name> {
  foreach I = AllFloatVectors in
    defm : pat_intrinsic_binary<intrinsic_name#"_vv", insn_name#"_VV",
                                I.Mask, I.Type, I.Type, I.Mask,
                                I.SEW, I.LMULstr, VM, I.RegClass, I.RegClass>;
}

multiclass pat_intrinsic_float_binary_m_vf<string intrinsic_name,
                                           string insn_name> {
  foreach I = AllFloatVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", insn_name#"_VF",
                                I.Mask, I.Type, f32, I.Mask,
                                I.SEW, I.LMULstr, VM, I.RegClass, FPR32>;
    defm : pat_intrinsic_binary<intrinsic_name#"_vf", insn_name#"_VF",
                                I.Mask, I.Type, f64, I.Mask,
                                I.SEW, I.LMULstr, VM, I.RegClass, FPR64>;
  }
}

multiclass pat_intrinsic_float_binary_m_vv_vf<string intrinsic_name,
                                              string insn_name>
  : pat_intrinsic_float_binary_m_vv<intrinsic_name, insn_name>,
    pat_intrinsic_float_binary_m_vf<intrinsic_name, insn_name>;

multiclass pat_intrinsic_int_binary_v_vvm_vxm<string intrinsic_name,
                                              string insn_name> {
  foreach I = AllIntegerVectors in {
    defm : pat_intrinsic_binary_carryin<intrinsic_name#"_vvm",
                                        insn_name#"_VVM",
                                        I.Type, I.Type, I.Type, I.Mask,
                                        I.SEW, I.LMULstr, I.RegClass,
                                        I.RegClass, I.RegClass>;
    defm : pat_intrinsic_binary_carryin<intrinsic_name#"_vxm",
                                        insn_name#"_VXM",
                                        I.Type, I.Type, XLenVT, I.Mask,
                                        I.SEW, I.LMULstr, I.RegClass,
                                        I.RegClass, GPR>;
  }
}

multiclass pat_intrinsic_int_binary_m_vvm_vxm<string intrinsic_name,
                                              string insn_name> {
  foreach I = AllIntegerVectors in {
    defm : pat_intrinsic_binary_carryin<intrinsic_name#"_vvm",
                                        insn_name#"_VVM", I.Mask,
                                        I.Type, I.Type, I.Mask, I.SEW,
                                        I.LMULstr, VMV0, I.RegClass,
                                        I.RegClass>;
    defm : pat_intrinsic_binary_carryin<intrinsic_name#"_vxm",
                                        insn_name#"_VXM", I.Mask,
                                        I.Type, I.Type, I.Mask, I.SEW,
                                        I.LMULstr, VMV0, I.RegClass,
                                        I.RegClass>;
  }
}

multiclass pat_intrinsic_int_binary_n_wn_wx<string intrinsic_name,
                                            string insn_name> {
  foreach I = AllWideIntegerVectors in {
    defm : pat_intrinsic_binary<intrinsic_name#"_wv", insn_name#"_WV",
                                I.OriginVector.Type, I.WidenVector,
                                I.OriginVector.Type, I.OriginVector.Mask,
                                I.OriginVector.SEW, I.OriginVector.LMULstr,
                                I.OriginVector.RegClass,
                                I.WidenRegClass, I.OriginVector.RegClass>;
    defm : pat_intrinsic_binary<intrinsic_name#"_wx", insn_name#"_WX",
                                I.OriginVector.Type, I.WidenVector, XLenVT,
                                I.OriginVector.Mask, I.OriginVector.SEW,
                                I.OriginVector.LMULstr, I.OriginVector.RegClass,
                                I.WidenRegClass, GPR>;
  }
}

multiclass pat_intrinsic_int_binary_v_vm<string intrinsic_name,
                                         string insn_name> {
  foreach I = AllIntegerVectors in {
    defvar insn = !cast<Instruction>(insn_name#"_VM_M"#I.LMULstr);
    def : Pat<(I.Type (!cast<Intrinsic>(intrinsic_name#"_vm") (I.Mask VM:$vs1),
                       (I.Type I.RegClass:$merge), (I.Type I.RegClass:$vs2))),
              (insn I.RegClass:$merge, I.RegClass:$vs2, VM:$vs1, I.SEW)>;
  }
}

multiclass pat_intrinsic_ternary<string intrinsic_name, string insn_name,
                                 ValueType result_type, ValueType arg1_type,
                                 ValueType arg2_type, ValueType mask_type,
                                 int sew, string lmul, RegisterClass result,
                                 DAGOperand arg1, RegisterClass arg2> {
  defvar insn = !cast<Instruction>(insn_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (result_type result:$merge),
                          (arg1_type arg1:$rs1), (arg2_type arg2:$rs2))),
            (insn result:$merge, ToScalarOp<arg1_type, arg1, "rs1">.Result,
                  arg2:$rs2, (mask_type zero_reg), sew)>;
}

multiclass pat_intrinsic_ternary_nomask<string intrinsic_name,
                                        string insn_name,
                                        ValueType result_type,
                                        ValueType arg1_type,
                                        ValueType arg2_type,
                                        ValueType arg3_type,
                                        int sew, string lmul,
                                        RegisterClass result,
                                        RegisterClass arg1,
                                        RegisterClass arg2,
                                        DAGOperand arg3> {
  defvar insn = !cast<Instruction>(insn_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name)
                          (arg1_type V0), (arg2_type arg2:$rs2),
                          (arg3_type arg3:$rs3))),
            (insn (result_type zero_reg), arg2:$rs2,
                  ToScalarOp<arg3_type, arg3, "rs3">.Result,
                  (arg1_type V0), sew)>;
}

multiclass pat_intrinsic_vmerge<string intrinsic_name, string insn_name> {
    foreach I = AllVectors in {
      defm : pat_intrinsic_ternary_nomask<intrinsic_name#"_vvm",
                                          insn_name#"_VVM",
                                          I.Type, I.Mask, I.Type, I.Type,
                                          I.SEW, I.LMULstr, I.RegClass, VMV0,
                                          I.RegClass, I.RegClass>;
    }
    foreach I = AllIntegerVectors in {
      defm : pat_intrinsic_ternary_nomask<intrinsic_name#"_vxm",
                                          insn_name#"_VXM",
                                          I.Type, I.Mask, I.Type, XLenVT,
                                          I.SEW, I.LMULstr, I.RegClass, VMV0,
                                          I.RegClass, GPR>;
    }
}

multiclass pat_intrinsic_vfmerge<string intrinsic_name, string insn_name> {
    foreach I = AllFloatVectors in {
      defm : pat_intrinsic_ternary_nomask<intrinsic_name#"_vfm",
                                          insn_name#"_VFM",
                                          I.Type, I.Mask, I.Type, f32,
                                          I.SEW, I.LMULstr, I.RegClass, VMV0,
                                          I.RegClass, FPR32>;
    }
    foreach I = AllFloatVectors in {
      defm : pat_intrinsic_ternary_nomask<intrinsic_name#"_vfm",
                                          insn_name#"_VFM", I.Type,
                                          I.Mask, I.Type, f64, I.SEW,
                                          I.LMULstr, I.RegClass, VMV0,
                                          I.RegClass, FPR64>;
    }
}

multiclass pat_intrinsic_int_ternary_v_vvv_vvx<string intrinsic_name,
                                               string insn_name> {
  foreach I = AllIntegerVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", insn_name#"_VV",
                                 I.Type, I.Type, I.Type, I.Mask, I.SEW,
                                 I.LMULstr, I.RegClass, I.RegClass, I.RegClass>;
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", insn_name#"_VX",
                                 I.Type, XLenVT, I.Type, I.Mask,
                                 I.SEW, I.LMULstr, I.RegClass, GPR, I.RegClass>;
  }
}

multiclass pat_intrinsic_int_ternary_v_vvx<string intrinsic_name,
                                           string insn_name> {
  foreach I = AllVectors in
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", insn_name#"_VX",
                                 I.Type, I.Type, XLenVT, I.Mask, I.SEW,
                                 I.LMULstr, I.RegClass, I.RegClass, GPR>;
}

multiclass pat_intrinsic_float_ternary_v_vvv_vvf<string intrinsic_name,
                                                 string insn_name> {
  foreach I = AllFloatVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", insn_name#"_VV",
                                 I.Type, I.Type, I.Type, I.Mask, I.SEW,
                                 I.LMULstr, I.RegClass, I.RegClass, I.RegClass>;
    defm : pat_intrinsic_ternary<intrinsic_name#"_vf", insn_name#"_VF",
                                 I.Type, f32, I.Type, I.Mask, I.SEW,
                                 I.LMULstr, I.RegClass, FPR32, I.RegClass>;
  }
}

multiclass pat_intrinsic_int_ternary_w_wvv<string intrinsic_name,
                                           string insn_name> {
  foreach I = AllWideIntegerVectors in
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", insn_name#"_VV",
                                 I.WidenVector, I.OriginVector.Type,
                                 I.OriginVector.Type, I.OriginVector.Mask,
                                 I.OriginVector.SEW, I.WidenLMULstr,
                                 I.WidenRegClass, I.OriginVector.RegClass,
                                 I.OriginVector.RegClass>;
}

multiclass pat_intrinsic_int_ternary_w_wvx<string intrinsic_name,
                                           string insn_name> {
  foreach I = AllWideIntegerVectors in
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", insn_name#"_VX",
                                 I.WidenVector, XLenVT, I.OriginVector.Type,
                                 I.OriginVector.Mask, I.OriginVector.SEW,
                                 I.WidenLMULstr, I.WidenRegClass,
                                 GPR, I.OriginVector.RegClass>;
}

multiclass pat_intrinsic_int_ternary_w_wvv_wvx<string intrinsic_name,
                                               string insn_name>
  : pat_intrinsic_int_ternary_w_wvv<intrinsic_name, insn_name>,
    pat_intrinsic_int_ternary_w_wvx<intrinsic_name, insn_name>;

multiclass pat_intrinsic_float_ternary_w_wvv_wvf<string intrinsic_name,
                                                 string insn_name> {
  foreach I = AllWideFloatVectors in {
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", insn_name#"_VV",
                                 I.WidenVector, I.OriginVector.Type,
                                 I.OriginVector.Type, I.OriginVector.Mask,
                                 I.OriginVector.SEW, I.WidenLMULstr,
                                 I.WidenRegClass, I.OriginVector.RegClass,
                                 I.OriginVector.RegClass>;
    defm : pat_intrinsic_ternary<intrinsic_name#"_vf", insn_name#"_VF",
                                 I.WidenVector, f32, I.OriginVector.Type,
                                 I.OriginVector.Mask, I.OriginVector.SEW,
                                 I.WidenLMULstr, I.WidenRegClass,
                                 FPR32, I.OriginVector.RegClass>;
  }
}

multiclass pat_intrinsic_int_ternary_qw_wvv<string intrinsic_name,
                                            string insn_name> {
  foreach I = AllQuadWideIntegerVectors in
    defm : pat_intrinsic_ternary<intrinsic_name#"_vv", insn_name#"_VV",
                                 I.WidenVector, I.OriginVector.Type,
                                 I.OriginVector.Type, I.OriginVector.Mask,
                                 I.OriginVector.SEW, I.WidenLMULstr,
                                 I.WidenRegClass, I.OriginVector.RegClass,
                                 I.OriginVector.RegClass>;
}

multiclass pat_intrinsic_int_ternary_qw_wvx<string intrinsic_name,
                                            string insn_name> {
  foreach I = AllQuadWideIntegerVectors in
    defm : pat_intrinsic_ternary<intrinsic_name#"_vx", insn_name#"_VX",
                                 I.WidenVector, XLenVT, I.OriginVector.Type,
                                 I.OriginVector.Mask, I.OriginVector.SEW,
                                 I.WidenLMULstr, I.WidenRegClass,
                                 GPR, I.OriginVector.RegClass>;
}

multiclass pat_intrinsic_int_ternary_qw_wvv_wvx<string intrinsic_name,
                                                string insn_name>
  : pat_intrinsic_int_ternary_qw_wvv<intrinsic_name, insn_name>,
    pat_intrinsic_int_ternary_qw_wvx<intrinsic_name, insn_name>;

multiclass pat_intrinsic_int_reduction<string intrinsic_name,
                                       string insn_name> {
  foreach I = AllIntegerVectors in {
    foreach J = NoGroupIntegerVectors in {
      defm : pat_intrinsic_ternary<intrinsic_name#"_vs", insn_name#"_VS",
                                   J.Type, I.Type, J.Type, I.Mask, I.SEW,
                                   I.LMULstr, J.RegClass, I.RegClass,
                                   J.RegClass>;
    }
  }
}

multiclass pat_intrinsic_float_reduction<string intrinsic_name,
                                         string insn_name> {
  foreach I = AllFloatVectors in {
    foreach J = NoGroupFloatVectors in {
      defm : pat_intrinsic_ternary<intrinsic_name#"_vs", insn_name#"_VS",
                                   J.Type, I.Type, J.Type, I.Mask, I.SEW,
                                   I.LMULstr, J.RegClass, I.RegClass,
                                   J.RegClass>;
    }
  }
}

multiclass pat_intrinsic_vid_v<string intrinsic_name, string insn_name,
                               ValueType result_type, ValueType mask_type,
                               int sew, string lmul, RegisterClass result> {
  defvar insn = !cast<Instruction>(insn_name#"_M"#lmul);
  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name))),
            (insn (result_type zero_reg), (mask_type zero_reg), sew)>;

  def : Pat<(result_type (!cast<Intrinsic>(intrinsic_name#"_mask")
                          (mask_type V0), (result_type result:$merge))),
            (insn result:$merge, (mask_type V0), sew)>;
}

multiclass pat_intrinsic_vid<string intrinsic_name, string insn_name> {
  foreach I = AllVectors in
    defm : pat_intrinsic_vid_v<intrinsic_name#"_v", insn_name#"_V",
                               I.Type, I.Mask, I.SEW, I.LMULstr, I.RegClass>;
}

multiclass pat_intrinsic_vload_store {
  foreach I = AllVectors in {
    defvar str = I.LMULstr;
    def : Pat<(I.Type (int_riscv_vload i64:$rs1)),
              (I.Type (!cast<Instruction>("PseudoVLE"#I.SEW#"_V_M"#str)
                        (I.Type zero_reg), i64:$rs1, (I.Mask zero_reg),
                        I.SEW))>;
    
    def : Pat<(I.Type (load i64:$rs1)),
              (I.Type (!cast<Instruction>("PseudoVL"#RoundFMToM1<str>.Result#"RE"#I.SEW#"_V")
                        (I.Type zero_reg), i64:$rs1, I.SEW))>;

    def : Pat<(int_riscv_vstore i64:$rs2, (I.Type I.RegClass:$rs1)),
                   (!cast<Instruction>("PseudoVSE"#I.SEW#"_V_M"#str)
                   (I.Type zero_reg), (I.Type I.RegClass:$rs1), i64:$rs2,
                   (I.Mask zero_reg), I.SEW)>;
    
    def : Pat<(store (I.Type I.RegClass:$rs1), i64:$rs2),
              (!cast<Instruction>("PseudoVS"#RoundFMToM1<str>.Result#"R_V")
              (I.Type zero_reg), (I.Type I.RegClass:$rs1), i64:$rs2, I.SEW)>;

    def : Pat<(I.Type (int_riscv_vload_indexed i64:$rs1, (I.Type I.RegClass:$rs2))),
              (I.Type (!cast<Instruction>("PseudoVLXEI"#I.SEW#"_V_M"#str)
                       (I.Type zero_reg), i64:$rs1, (I.Type I.RegClass:$rs2), (I.Mask zero_reg),
                        I.SEW))>;
  }

  foreach Mask = [nxv1i1, nxv2i1, nxv4i1, nxv8i1, nxv16i1, nxv32i1, nxv64i1] in {
    def : Pat<(Mask (load i64:$rs1)), (Mask (VL1RE8_V i64:$rs1))>;
    def : Pat<(store (Mask VR:$vs3), GPR:$rs1), (VS1R_V (Mask VR:$vs3), GPR:$rs1)>;
  }
}

defm : pat_intrinsic_vload_store;

// 12.1. Vector Single-Width Integer Add and Subtract
defm PseudoVADD : pseudo_binary_v_vv_vx;
defm PseudoVSUB : pseudo_binary_v_vv_vx;
defm PseudoVRSUB : pseudo_binary_v_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vadd", "PseudoVADD">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vsub", "PseudoVSUB">;
defm : pat_intrinsic_int_binary_v_vx<"int_riscv_vrsub", "PseudoVRSUB">;

// 12.2. Vector Widening Integer Add/Subtract
defm PseudoVWADD : pseudo_binary_w_vv_vx_wv_wx<"@earlyclobber $rd">;
defm PseudoVWADDU : pseudo_binary_w_vv_vx_wv_wx<"@earlyclobber $rd">;
defm PseudoVWSUB : pseudo_binary_w_vv_vx_wv_wx<"@earlyclobber $rd">;
defm PseudoVWSUBU : pseudo_binary_w_vv_vx_wv_wx<"@earlyclobber $rd">;
defm : pat_intrinsic_int_binary_w_vv_vx_wv_wx<"int_riscv_vwadd", "PseudoVWADD">;
defm : pat_intrinsic_int_binary_w_vv_vx_wv_wx<"int_riscv_vwaddu", "PseudoVWADDU">;
defm : pat_intrinsic_int_binary_w_vv_vx_wv_wx<"int_riscv_vwsub", "PseudoVWSUB">;
defm : pat_intrinsic_int_binary_w_vv_vx_wv_wx<"int_riscv_vwsubu", "PseudoVWSUBU">;
defm : pat_intrinsic_int_binary_w_vX0<"int_riscv_vwcvt_x_x_v", "PseudoVWADD_VX">;
defm : pat_intrinsic_int_binary_w_vX0<"int_riscv_vwcvtu_x_x_v", "PseudoVWADDU_VX">;

// 12.3. Vector Integer Extension

// 12.4. Vector Integer Add-with-Carry/Subtract-with-Borrow Instructions
defm PseudoVADC : pseudo_binary_v_vvm_vxm;
defm PseudoVMADC : pseudo_binary_m_vvm_vxm<"@earlyclobber $rd">;
defm PseudoVSBC : pseudo_binary_v_vvm_vxm;
defm PseudoVMSBC : pseudo_binary_v_vvm_vxm<"@earlyclobber $rd">;
defm : pat_intrinsic_int_binary_v_vvm_vxm<"int_riscv_vadc", "PseudoVADC">;
defm : pat_intrinsic_int_binary_m_vvm_vxm<"int_riscv_vmadc", "PseudoVMADC">;

// 12.5. Vector Bitwise Logical Instructions
defm PseudoVAND : pseudo_binary_v_vv_vx;
defm PseudoVOR : pseudo_binary_v_vv_vx;
defm PseudoVXOR : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vand", "PseudoVAND">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vor", "PseudoVOR">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vxor", "PseudoVXOR">;

// 12.6. Vector Single-Width Bit Shift Instructions
defm PseudoVSLL : pseudo_binary_v_vv_vx;
defm PseudoVSRL : pseudo_binary_v_vv_vx;
defm PseudoVSRA : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vsll", "PseudoVSLL">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vsrl", "PseudoVSRL">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vsra", "PseudoVSRA">;

// 12.7. Vector Narrowing Integer Right Shift Instructions
defm PseudoVNSRL : pseudo_binary_n_wn_wx;
defm PseudoVNSRA : pseudo_binary_n_wn_wx;
defm : pat_intrinsic_int_binary_n_wn_wx<"int_riscv_vnsrl", "PseudoVNSRL">;
defm : pat_intrinsic_int_binary_n_wn_wx<"int_riscv_vnsra", "PseudoVNSRA">;

// 12.8. Vector Integer Comparison Instructions
defm PseudoVMSEQ : pseudo_binary_m_vv_vx;
defm PseudoVMSNE : pseudo_binary_m_vv_vx;
defm PseudoVMSLT : pseudo_binary_m_vv_vx;
defm PseudoVMSLTU : pseudo_binary_m_vv_vx;
defm PseudoVMSLE : pseudo_binary_m_vv_vx;
defm PseudoVMSLEU : pseudo_binary_m_vv_vx;
defm PseudoVMSGT : pseudo_binary_m_vx;
defm PseudoVMSGTU : pseudo_binary_m_vx;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmseq", "PseudoVMSEQ">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmsne", "PseudoVMSNE">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmsltu", "PseudoVMSLTU">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmslt", "PseudoVMSLT">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmsle", "PseudoVMSLE">;
defm : pat_intrinsic_int_binary_m_vv_vx<"int_riscv_vmsleu", "PseudoVMSLEU">;
defm : pat_intrinsic_int_binary_m_vx<"int_riscv_vmsgt", "PseudoVMSGT">;
defm : pat_intrinsic_int_binary_m_vx<"int_riscv_vmsgtu", "PseudoVMSGTU">;

// 12.9. Vector Integer Min/Max Instructions
defm PseudoVMIN : pseudo_binary_v_vv_vx;
defm PseudoVMINU : pseudo_binary_v_vv_vx;
defm PseudoVMAX : pseudo_binary_v_vv_vx;
defm PseudoVMAXU : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vmin", "PseudoVMIN">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vmax", "PseudoVMAX">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vminu", "PseudoVMINU">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vmaxu", "PseudoVMAXU">;

// 12.10. Vector Single-Width Integer Multiply Instructions
defm PseudoVMUL : pseudo_binary_v_vv_vx;
defm PseudoVMULH : pseudo_binary_v_vv_vx;
defm PseudoVMULHU : pseudo_binary_v_vv_vx;
defm PseudoVMULHSU : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vmul", "PseudoVMUL">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vmulh", "PseudoVMULH">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vmulhu", "PseudoVMULHU">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vmulhsu", "PseudoVMULHSU">;

// 12.11. Vector Integer Divide Instructions
defm PseudoVDIV : pseudo_binary_v_vv_vx;
defm PseudoVDIVU : pseudo_binary_v_vv_vx;
defm PseudoVREM : pseudo_binary_v_vv_vx;
defm PseudoVREMU : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vdiv", "PseudoVDIV">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vdivu", "PseudoVDIVU">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vrem", "PseudoVREM">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vremu", "PseudoVREMU">;

// 12.12. Vector Widening Integer Multiply Instructions
defm PseudoVWMUL : pseudo_binary_w_vv_vx<"@earlyclobber $rd">;
defm PseudoVWMULU : pseudo_binary_w_vv_vx<"@earlyclobber $rd">;
defm PseudoVWMULSU : pseudo_binary_w_vv_vx<"@earlyclobber $rd">;
defm : pat_intrinsic_int_binary_w_vv_vx<"int_riscv_vwmul", "PseudoVWMUL">;
defm : pat_intrinsic_int_binary_w_vv_vx<"int_riscv_vwmulu", "PseudoVWMULU">;
defm : pat_intrinsic_int_binary_w_vv_vx<"int_riscv_vwmulsu", "PseudoVWMULSU">;

// 12.13. Vector Single-Width Integer Multiply-Add Instructions
defm PseudoVMACC : pseudo_ternary_v_vvv_vvx;
defm PseudoVNMSAC : pseudo_ternary_v_vvv_vvx;
defm PseudoVMADD : pseudo_ternary_v_vvv_vvx;
defm PseudoVNMSUB : pseudo_ternary_v_vvv_vvx;
defm : pat_intrinsic_int_ternary_v_vvv_vvx<"int_riscv_vmacc", "PseudoVMACC">;
defm : pat_intrinsic_int_ternary_v_vvv_vvx<"int_riscv_vnmsac", "PseudoVNMSAC">;
defm : pat_intrinsic_int_ternary_v_vvv_vvx<"int_riscv_vmadd", "PseudoVMADD">;
defm : pat_intrinsic_int_ternary_v_vvv_vvx<"int_riscv_vnmsub", "PseudoVNMSUB">;

// 12.14. Vector Widening Integer Multiply-Add Instructions
defm PseudoVWMACC : pseudo_ternary_w_wvv_wvx;
defm PseudoVWMACCU : pseudo_ternary_w_wvv_wvx;
defm PseudoVWMACCSU : pseudo_ternary_w_wvv_wvx;
defm PseudoVWMACCUS : pseudo_ternary_w_wvx;
defm : pat_intrinsic_int_ternary_w_wvv_wvx<"int_riscv_vwmacc", "PseudoVWMACC">;
defm : pat_intrinsic_int_ternary_w_wvv_wvx<"int_riscv_vwmaccu", "PseudoVWMACCU">;
defm : pat_intrinsic_int_ternary_w_wvv_wvx<"int_riscv_vwmaccsu", "PseudoVWMACCSU">;
defm : pat_intrinsic_int_ternary_w_wvx<"int_riscv_vwmaccus", "PseudoVWMACCUS">;

// 12.15. Vector Quad-Widening Integer Multiply-Add Instructions (Extension Zvqmac)
defm PseudoVQMACC : pseudo_ternary_qw_wvv_wvx;
defm PseudoVQMACCU : pseudo_ternary_qw_wvv_wvx;
defm PseudoVQMACCSU : pseudo_ternary_qw_wvv_wvx;
defm PseudoVQMACCUS : pseudo_ternary_qw_wvx;
defm : pat_intrinsic_int_ternary_qw_wvv_wvx<"int_riscv_vqmacc", "PseudoVQMACC">;
defm : pat_intrinsic_int_ternary_qw_wvv_wvx<"int_riscv_vqmaccu", "PseudoVQMACCU">;
defm : pat_intrinsic_int_ternary_qw_wvv_wvx<"int_riscv_vqmaccsu", "PseudoVQMACCSU">;
defm : pat_intrinsic_int_ternary_qw_wvx<"int_riscv_vqmaccus", "PseudoVQMACCUS">;

// 12.16. Vector Integer Merge Instructions
defm PseudoVMERGE : pseudo_binary_v_vvm_vxm;
defm : pat_intrinsic_vmerge<"int_riscv_vmerge", "PseudoVMERGE">;

// 12.17. Vector Integer Move Instructions
// 17.1. Integer Scalar Move Instructions
defm PseudoVMV : pseudo_vmv;
defm : pat_intrinsic_vmv<"int_riscv_vmv", "PseudoVMV">;

// 13.1. Vector Single-Width Saturating Add and Subtract
defm PseudoVSADD : pseudo_binary_v_vv_vx;
defm PseudoVSADDU : pseudo_binary_v_vv_vx;
defm PseudoVSSUB : pseudo_binary_v_vv_vx;
defm PseudoVSSUBU : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vsadd", "PseudoVSADD">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vsaddu", "PseudoVSADDU">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vssub", "PseudoVSSUB">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vssubu", "PseudoVSSUBU">;

// 13.2. Vector Single-Width Averaging Add and Subtract
defm PseudoVAADD : pseudo_binary_v_vv_vx;
defm PseudoVAADDU : pseudo_binary_v_vv_vx;
defm PseudoVASUB : pseudo_binary_v_vv_vx;
defm PseudoVASUBU : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vaadd", "PseudoVAADD">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vaaddu", "PseudoVAADDU">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vasub", "PseudoVASUB">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vasubu", "PseudoVASUBU">;

// 13.3. Vector Single-Width Fractional Multiply with Rounding and Saturation
defm PseudoVSMUL : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vsmul", "PseudoVSMUL">;

// 13.4. Vector Single-Width Scaling Shift Instructions
defm PseudoVSSRL : pseudo_binary_v_vv_vx;
defm PseudoVSSRA : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vssrl", "PseudoVSSRL">;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vssra", "PseudoVSSRA">;

// 13.5. Vector Narrowing Fixed-Point Clip Instructions
defm PseudoVNCLIP : pseudo_binary_n_wn_wx;
defm PseudoVNCLIPU : pseudo_binary_n_wn_wx;
defm : pat_intrinsic_int_binary_n_wn_wx<"int_riscv_vnclip", "PseudoVNCLIP">;
defm : pat_intrinsic_int_binary_n_wn_wx<"int_riscv_vnclipu", "PseudoVNCLIPU">;

// 14.2. Vector Single-Width Floating-Point Add/Subtract Instructions
defm PseudoVFADD : pseudo_binary_v_vv_vf;
defm PseudoVFSUB : pseudo_binary_v_vv_vf;
defm PseudoVFRSUB : pseudo_binary_v_vf;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfadd", "PseudoVFADD">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfsub", "PseudoVFSUB">;
defm : pat_intrinsic_float_binary_v_vf<"int_riscv_vfrsub", "PseudoVFRSUB">;

// 14.3. Vector Widening Floating-Point Add/Subtract Instructions
defm PseudoVFWADD : pseudo_binary_w_vv_vf_wv_wf;
defm PseudoVFWSUB : pseudo_binary_w_vv_vf_wv_wf;
defm : pat_intrinsic_float_binary_w_vv_vf_wv_wf<"int_riscv_vfwadd", "PseudoVFWADD">;
defm : pat_intrinsic_float_binary_w_vv_vf_wv_wf<"int_riscv_vfwsub", "PseudoVFWSUB">;

// 14.4. Vector Single-Width Floating-Point Multiply/Divide Instructions
defm PseudoVFMUL : pseudo_binary_v_vv_vf;
defm PseudoVFDIV : pseudo_binary_v_vv_vf;
defm PseudoVFRDIV : pseudo_binary_v_vf;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfmul", "PseudoVFMUL">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfdiv", "PseudoVFDIV">;
defm : pat_intrinsic_float_binary_v_vf<"int_riscv_vfrdiv", "PseudoVFRDIV">;

// 14.5. Vector Widening Floating-Point Multiply
defm PseudoVFWMUL : pseudo_binary_w_vv_vf;
defm : pat_intrinsic_float_binary_w_vv_vf<"int_riscv_vfwmul", "PseudoVFWMUL">;

// 14.6. Vector Single-Width Floating-Point Fused Multiply-Add Instructions
defm PseudoVFMACC : pseudo_ternary_v_vvv_vvf;
defm PseudoVFNMACC : pseudo_ternary_v_vvv_vvf;
defm PseudoVFNMSAC : pseudo_ternary_v_vvv_vvf;
defm PseudoVFMADD : pseudo_ternary_v_vvv_vvf;
defm PseudoVFNMADD : pseudo_ternary_v_vvv_vvf;
defm PseudoVFMSUB : pseudo_ternary_v_vvv_vvf;
defm PseudoVFNMSUB : pseudo_ternary_v_vvv_vvf;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfmacc", "PseudoVFMACC">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfnmacc", "PseudoVFNMACC">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfnmsac", "PseudoVFNMSAC">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfmadd", "PseudoVFMADD">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfnmadd", "PseudoVFNMADD">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfmsub", "PseudoVFMSUB">;
defm : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfnmsub", "PseudoVFNMSUB">;

// 14.7. Vector Widening Floating-Point Fused MultiplyAdd Instructions
defm PseudoVFWMACC : pseudo_ternary_w_wvv_wvf;
defm PseudoVFWNMACC : pseudo_ternary_w_wvv_wvf;
defm PseudoVFWMSAC : pseudo_ternary_w_wvv_wvf;
defm PseudoVFWNMSAC : pseudo_ternary_w_wvv_wvf;
defm : pat_intrinsic_float_ternary_w_wvv_wvf<"int_riscv_vfwmacc", "PseudoVFWMACC">;
defm : pat_intrinsic_float_ternary_w_wvv_wvf<"int_riscv_vfwnmacc", "PseudoVFWNMACC">;
defm : pat_intrinsic_float_ternary_w_wvv_wvf<"int_riscv_vfwmsac", "PseudoVFWMSAC">;
defm : pat_intrinsic_float_ternary_w_wvv_wvf<"int_riscv_vfwnmsac", "PseudoVFWNMSAC">;

// 14.8. Vector Floating-Point Square-Root Instruction
defm PseudoVFSQRT : pseudo_unary_v_v;
defm : pat_intrinsic_float_unary_v_v<"int_riscv_vfsqrt", "PseudoVFSQRT">;

// 14.9. Vector Floating-Point MIN/MAX Instructions
defm PseudoVFMIN : pseudo_binary_v_vv_vf;
defm PseudoVFMAX : pseudo_binary_v_vv_vf;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfmin", "PseudoVFMIN">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfmax", "PseudoVFMAX">;

// 14.10. Vector Floating-Point Sign-Injection Instructions
defm PseudoVFSGNJ : pseudo_binary_v_vv_vf;
defm PseudoVFSGNJN : pseudo_binary_v_vv_vf;
defm PseudoVFSGNJX : pseudo_binary_v_vv_vf;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfsgnj", "PseudoVFSGNJ">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfsgnjn", "PseudoVFSGNJN">;
defm : pat_intrinsic_float_binary_v_vv_vf<"int_riscv_vfsgnjx", "PseudoVFSGNJX">;

// 14.11. Vector Floating-Point Compare Instructions
defm PseudoVMFEQ : pseudo_binary_m_vv_vf;
defm PseudoVMFNE : pseudo_binary_m_vv_vf;
defm PseudoVMFLT : pseudo_binary_m_vv_vf;
defm PseudoVMFLE : pseudo_binary_m_vv_vf;
defm PseudoVMFGT : pseudo_binary_m_vf;
defm PseudoVMFGE : pseudo_binary_m_vf;
defm : pat_intrinsic_float_binary_m_vv_vf<"int_riscv_vmfeq", "PseudoVMFEQ">;
defm : pat_intrinsic_float_binary_m_vv_vf<"int_riscv_vmfne", "PseudoVMFNE">;
defm : pat_intrinsic_float_binary_m_vv_vf<"int_riscv_vmflt", "PseudoVMFLT">;
defm : pat_intrinsic_float_binary_m_vv_vf<"int_riscv_vmfle", "PseudoVMFLE">;
defm : pat_intrinsic_float_binary_m_vf<"int_riscv_vmfgt", "PseudoVMFGT">;
defm : pat_intrinsic_float_binary_m_vf<"int_riscv_vmfge", "PseudoVMFGE">;

// 14.12. Vector Floating-Point Classify Instruction
defm PseudoVFCLASS : pseudo_unary_v_v;
defm : pat_intrinsic_float_unary_v_v<"int_riscv_vfclass", "PseudoVFCLASS">;

// 14.13. Vector Floating-Point Merge Instruction
defm PseudoVFMERGE : pseudo_binary_v_vfm;
defm : pat_intrinsic_vfmerge<"int_riscv_vfmerge", "PseudoVFMERGE">;

// 14.14. Vector Floating-Point Move Instruction
// 17.2. Floating-Point Scalar Move Instructions
defm PseudoVFMV : pseudo_vfmv;
defm : pat_intrinsic_vfmv<"int_riscv_vfmv", "PseudoVFMV">;

// 14.15. Single-Width Floating-Point/Integer TypeConvert Instructions
defm PseudoVFCVT_X_F : pseudo_unary_v_v;
defm PseudoVFCVT_XU_F : pseudo_unary_v_v;
defm PseudoVFCVT_RTZ_X_F : pseudo_unary_v_v;
defm PseudoVFCVT_RTZ_XU_F : pseudo_unary_v_v;
defm PseudoVFCVT_F_X : pseudo_unary_v_v;
defm PseudoVFCVT_F_XU : pseudo_unary_v_v;
defm : pat_intrinsic_unary_f_v<"int_riscv_vfcvt_x_f_v", "PseudoVFCVT_X_F">;
defm : pat_intrinsic_unary_f_v<"int_riscv_vfcvt_xu_f_v", "PseudoVFCVT_XU_F">;
defm : pat_intrinsic_unary_f_v<"int_riscv_vfcvt_rtz_x_f_v", "PseudoVFCVT_RTZ_X_F">;
defm : pat_intrinsic_unary_f_v<"int_riscv_vfcvt_rtz_xu_f_v", "PseudoVFCVT_RTZ_XU_F">;
defm : pat_intrinsic_unary_v_f<"int_riscv_vfcvt_f_x_v", "PseudoVFCVT_F_X">;
defm : pat_intrinsic_unary_v_f<"int_riscv_vfcvt_f_xu_v", "PseudoVFCVT_F_XU">;

// 14.16. Widening Floating-Point/Integer Type-Convert Instructions
defm PseudoVFWCVT_X_F : pseudo_unary_v_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_XU_F : pseudo_unary_v_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_RTZ_X_F : pseudo_unary_v_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_RTZ_XU_F : pseudo_unary_v_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_F_X : pseudo_unary_f_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_F_XU : pseudo_unary_f_w<"@earlyclobber $rd">;
defm PseudoVFWCVT_F_F : pseudo_unary_f_f<"@earlyclobber $rd">;
defm : pat_intrinsic_unary_w_f_v<"int_riscv_vfwcvt_x_f", "PseudoVFWCVT_X_F">;
defm : pat_intrinsic_unary_w_f_v<"int_riscv_vfwcvt_xu_f", "PseudoVFWCVT_XU_F">;
defm : pat_intrinsic_unary_w_f_v<"int_riscv_vfwcvt_rtz_x_f", "PseudoVFWCVT_RTZ_X_F">;
defm : pat_intrinsic_unary_w_f_v<"int_riscv_vfwcvt_rtz_xu_f", "PseudoVFWCVT_RTZ_XU_F">;
defm : pat_intrinsic_unary_w_v_f<"int_riscv_vfwcvt_f_x", "PseudoVFWCVT_F_X">;
defm : pat_intrinsic_unary_w_v_f<"int_riscv_vfwcvt_f_xu", "PseudoVFWCVT_F_XU">;
defm : pat_intrinsic_unary_w_f_f<"int_riscv_vfwcvt_f_f", "PseudoVFWCVT_F_F">;

// 14.17. Narrowing Floating-Point/Integer Type-Convert Instructions
defm PseudoVFNCVT_X_F : pseudo_unary_f_n<"@earlyclobber $rd">;
defm PseudoVFNCVT_XU_F : pseudo_unary_f_n<"@earlyclobber $rd">;
defm PseudoVFNCVT_RTZ_X_F : pseudo_unary_f_n<"@earlyclobber $rd">;
defm PseudoVFNCVT_RTZ_XU_F : pseudo_unary_f_n<"@earlyclobber $rd">;
defm PseudoVFNCVT_F_X : pseudo_unary_v_n<"@earlyclobber $rd">;
defm PseudoVFNCVT_F_XU : pseudo_unary_v_n<"@earlyclobber $rd">;
defm PseudoVFNCVT_F_F : pseudo_unary_f_f_n<"@earlyclobber $rd">;
defm PseudoVFNCVT_ROD_F_F : pseudo_unary_f_f_n<"@earlyclobber $rd">;
defm : pat_intrinsic_unary_n_f_v<"int_riscv_vfncvt_x_f", "PseudoVFNCVT_X_F">;
defm : pat_intrinsic_unary_n_f_v<"int_riscv_vfncvt_xu_f", "PseudoVFNCVT_XU_F">;
defm : pat_intrinsic_unary_n_f_v<"int_riscv_vfncvt_rtz_x_f", "PseudoVFNCVT_RTZ_X_F">;
defm : pat_intrinsic_unary_n_f_v<"int_riscv_vfncvt_rtz_xu_f", "PseudoVFNCVT_RTZ_XU_F">;
defm : pat_intrinsic_unary_n_v_f<"int_riscv_vfncvt_f_x", "PseudoVFNCVT_F_X">;
defm : pat_intrinsic_unary_n_v_f<"int_riscv_vfncvt_f_xu", "PseudoVFNCVT_F_XU">;
defm : pat_intrinsic_unary_n_f_f<"int_riscv_vfncvt_f_f", "PseudoVFNCVT_F_F">;
defm : pat_intrinsic_unary_n_f_f<"int_riscv_vfncvt_rod_f_f", "PseudoVFNCVT_ROD_F_F">;

// 15.1. Vector Single-Width Integer Reduction Instructions
defm PseudoVREDSUM : pseudo_ternary_reduction;
defm PseudoVREDMAX : pseudo_ternary_reduction;
defm PseudoVREDMAXU : pseudo_ternary_reduction;
defm PseudoVREDMIN : pseudo_ternary_reduction;
defm PseudoVREDMINU : pseudo_ternary_reduction;
defm PseudoVREDAND : pseudo_ternary_reduction;
defm PseudoVREDOR : pseudo_ternary_reduction;
defm PseudoVREDXOR : pseudo_ternary_reduction;
defm : pat_intrinsic_int_reduction<"int_riscv_vredsum", "PseudoVREDSUM">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredmax", "PseudoVREDMAX">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredmaxu", "PseudoVREDMAXU">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredmin", "PseudoVREDMIN">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredminu", "PseudoVREDMINU">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredand", "PseudoVREDAND">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredor", "PseudoVREDOR">;
defm : pat_intrinsic_int_reduction<"int_riscv_vredxor", "PseudoVREDXOR">;

// 15.2. Vector Widening Integer Reduction Instructions
defm PseudoVWREDSUM : pseudo_ternary_reduction;
defm PseudoVWREDSUMU : pseudo_ternary_reduction;
defm : pat_intrinsic_int_reduction<"int_riscv_vwredsum", "PseudoVWREDSUM">;
defm : pat_intrinsic_int_reduction<"int_riscv_vwredsumu", "PseudoVWREDSUMU">;

// 15.3. Vector Single-Width Floating-Point Reduction Instructions
defm PseudoVFREDOSUM : pseudo_ternary_reduction;
defm PseudoVFREDSUM : pseudo_ternary_reduction;
defm PseudoVFREDMAX : pseudo_ternary_reduction;
defm PseudoVFREDMIN : pseudo_ternary_reduction;
defm : pat_intrinsic_float_reduction<"int_riscv_vfredosum", "PseudoVFREDOSUM">;
defm : pat_intrinsic_float_reduction<"int_riscv_vfredsum", "PseudoVFREDSUM">;
defm : pat_intrinsic_float_reduction<"int_riscv_vfredmax", "PseudoVFREDMAX">;
defm : pat_intrinsic_float_reduction<"int_riscv_vfredmin", "PseudoVFREDMIN">;

// 15.4. Vector Widening Floating-Point Reduction Instructions
defm PseudoVFWREDOSUM : pseudo_ternary_reduction;
defm PseudoVFWREDSUM : pseudo_ternary_reduction;
defm : pat_intrinsic_float_reduction<"int_riscv_vfwredosum", "PseudoVFWREDOSUM">;
defm : pat_intrinsic_float_reduction<"int_riscv_vfwredsum", "PseudoVFWREDSUM">;

// 16.1. Vector Mask-Register Logical Instructions
// These instructions all operate on single vector registers regardless of
// the setting of the vlmul field in vtype. So no need to define pseudo
// instructions.
multiclass pat_intrinsic_binary_m_mm<string intrinsic_name, string insn_name> {
  foreach BT = VMaskVT.types in
    def : Pat<(BT (!cast<Intrinsic>(intrinsic_name#"_mm") (BT VM:$vs1),
                                                      (BT VM:$vs2))),
              (!cast<Instruction>(insn_name#"_MM") (BT VM:$vs1), (BT VM:$vs2))>;
}
defm : pat_intrinsic_binary_m_mm<"int_riscv_vmand", "VMAND">;
defm : pat_intrinsic_binary_m_mm<"int_riscv_vmnand", "VMNAND">;
defm : pat_intrinsic_binary_m_mm<"int_riscv_vmandnot", "VMANDNOT">;
defm : pat_intrinsic_binary_m_mm<"int_riscv_vmxor", "VMXOR">;
defm : pat_intrinsic_binary_m_mm<"int_riscv_vmor", "VMOR">;
defm : pat_intrinsic_binary_m_mm<"int_riscv_vmnor", "VMNOR">;
defm : pat_intrinsic_binary_m_mm<"int_riscv_vmornot", "VMORNOT">;
defm : pat_intrinsic_binary_m_mm<"int_riscv_vmxnor", "VMXNOR">;

// 16.2. Vector mask population count vpopc
multiclass pat_intrinsic_unary_x_m<string intrinsic_name, string insn_name> {
  foreach BT = VMaskVT.types in {
    def : Pat<(XLenVT (!cast<Intrinsic>(intrinsic_name#"_m") (BT VM:$vs1))),
              (!cast<Instruction>(insn_name#"_M") (BT VM:$vs1), (BT zero_reg))>;
    def : Pat<(XLenVT (!cast<Intrinsic>(intrinsic_name#"_m") (BT VM:$vs1))),
              (!cast<Instruction>(insn_name#"_M") (BT VM:$vs1), (BT V0))>;
  }
}
defm : pat_intrinsic_unary_x_m<"int_riscv_vpopc", "VPOPC">;

// 16.3. vfirst find-first-set mask bit
defm : pat_intrinsic_unary_x_m<"int_riscv_vfirst", "VFIRST">;

// 16.4. vmsbf.m set-before-first mask bit
multiclass pat_intrinsic_unary_m_m<string intrinsic_name, string insn_name> {
  foreach BT = VMaskVT.types in {
    def : Pat<(BT (!cast<Intrinsic>(intrinsic_name#"_m") (BT VM:$vs1))),
              (!cast<Instruction>(insn_name#"_M") (BT VM:$vs1), (BT zero_reg))>;
    def : Pat<(BT (!cast<Intrinsic>(intrinsic_name#"_m") (BT VM:$vs1))),
              (!cast<Instruction>(insn_name#"_M") (BT VM:$vs1), (BT V0))>;
  }
}
defm : pat_intrinsic_unary_m_m<"int_riscv_vmsbf", "VMSBF">;

// 16.5. vmsif.m set-including-first mask bit
defm : pat_intrinsic_unary_m_m<"int_riscv_vmsif", "VMSIF">;

// 16.6. vmsof.m set-only-first mask bit
defm : pat_intrinsic_unary_m_m<"int_riscv_vmsof", "VMSOF">;

// 16.8. Vector Iota Instruction
defm PseudoVIOTA : pseudo_unary_v_m;
defm : pat_intrinsic_int_unary_v_m<"int_riscv_viota", "PseudoVIOTA">;

// 16.9. Vector Element Index Instruction
defm PseudoVID : pseudo_vid;
defm : pat_intrinsic_vid<"int_riscv_vid", "PseudoVID">;

// 17.3. Vector Slide Instructions
defm PseudoVSLIDEUP : pseudo_ternary_v_vvx;
defm PseudoVSLIDEDOWN : pseudo_ternary_v_vvx;
defm : pat_intrinsic_int_ternary_v_vvx<"int_riscv_vslideup", "PseudoVSLIDEUP">;
defm : pat_intrinsic_int_ternary_v_vvx<"int_riscv_vslidedown", "PseudoVSLIDEDOWN">;

defm PseudoVSLIDE1UP : pseudo_binary_v_vx;
defm PseudoVSLIDE1DOWN : pseudo_binary_v_vx;
defm PseudoVFSLIDE1UP : pseudo_binary_v_vf;
defm PseudoVFSLIDE1DOWN : pseudo_binary_v_vf;
defm : pat_intrinsic_int_binary_v_vx<"int_riscv_vslide1up", "PseudoVSLIDE1UP">;
defm : pat_intrinsic_int_binary_v_vx<"int_riscv_vslide1down", "PseudoVSLIDE1DOWN">;
defm : pat_intrinsic_float_binary_v_vf<"int_riscv_vfslide1up", "PseudoVFSLIDE1UP">;
defm : pat_intrinsic_float_binary_v_vf<"int_riscv_vfslide1down", "PseudoVFSLIDE1DOWN">;

// 17.4. Vector Register Gather Instruction
defm PseudoVRGATHER : pseudo_binary_v_vv_vx;
defm : pat_intrinsic_int_binary_v_vv_vx<"int_riscv_vrgather", "PseudoVRGATHER">;

// 17.5. Vector Compress Instruction
defm PseudoVCOMPRESS : pseudo_binary_v_vm;
defm : pat_intrinsic_int_binary_v_vm<"int_riscv_vcompress", "PseudoVCOMPRESS">;

// 17.6. Whole Vector Register Move
// 19.3. Vector Integer Dot-Product Instruction
// 19.4. Vector Floating-Point Dot Product Instruction


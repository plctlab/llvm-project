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
}

class WideVlmulToRCInfo<RegisterClass Ori, RegisterClass Wid, string Lmul, int Wlm> {
  RegisterClass OriginRegClass = Ori;
  RegisterClass WideRegClass = Wid;
  string Lmulstr = Lmul;
  int Widelmul = Wlm;
}

defset list<WideVlmulToRCInfo> AllWideVlmuls = {
  // TODO : fractional lmul
  def WM2 : WideVlmulToRCInfo<VR, VRM2, "2", 2>;
  def WM4 : WideVlmulToRCInfo<VRM2, VRM4, "4", 4>;
  def WM8 : WideVlmulToRCInfo<VRM4, VRM8, "8", 8>;
}

defset list<VectorTypeInfo> AllVectors = {
  defset list<VectorTypeInfo> AllIntegerVectors = {
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
      def Vtypev4i64 : VectorTypeInfo<nxv4i64, nxv4i1, 64, VRM4, 4, "4">;

      def Vtypev64xi8 : VectorTypeInfo<nxv64i8, nxv64i1, 8, VRM8, 8, "8">;
      def Vtypev32xi16 : VectorTypeInfo<nxv32i16, nxv32i1, 16, VRM8, 8, "8">;
      def Vtypev16xi32 : VectorTypeInfo<nxv16i32, nxv16i1, 32, VRM8, 8, "8">;
      def Vtypev8xi64 : VectorTypeInfo<nxv8i64, nxv8i1, 64, VRM8, 8, "8">;
    }
  }

  defset list<VectorTypeInfo> AllFloatVectors = {
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

defset list<WideVectorInfo> AllWideIntegerVectors = {
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
  defvar vlmul = evr.Vlmul;
  foreach sew = [8, 16, 32, 64, 128, 256, 512, 1024] in {
    let mayLoad = 1, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0, 
      VLMul = vlmul in {
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

    let mayLoad = 0, mayStore = 1, hasSideEffects = 0, usesCustomInserter = 0,
      VLMul = vlmul in {
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


multiclass pseudo_unary_v_v {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in {
    foreach evr = AllVlmuls in {
      defm _V : pseudo_unary<evr.RegClass, evr.RegClass, evr.Lmulstr>;
    }
  }
}

multiclass pseudo_unary_nomask_v_x_v_v {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in {
    foreach evr = AllVlmuls in {
      let VLMul = evr.Vlmul in {
      defm _V : pseudo_unary_nomask<evr.RegClass, evr.RegClass, evr.Lmulstr>;
      defm _X : pseudo_unary_nomask<evr.RegClass, GPR, evr.Lmulstr>;
      }
    }
  }
}

multiclass pseudo_unary_nomask_x_s_s_x {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in {
    foreach evr = AllVlmuls in {
      let VLMul = evr.Vlmul in {
        defm _X_S : pseudo_unary_nomask<GPR, evr.RegClass, evr.Lmulstr>;
        defm _S_X : pseudo_unary_nomask<evr.RegClass, GPR, evr.Lmulstr>;
      }
    }
  }
}

multiclass pseudo_vfmv {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in {
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
//   let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in {
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
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_binary<evr.RegClass, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VX : pseudo_binary<evr.RegClass, evr.RegClass, GPR, evr.Lmulstr, constraints>;
      // defm _VI : pseudo_binary<evr.RegClass, evr.RegClass, simm5, evr.Lmulstr, con
    }
  }
}

multiclass pseudo_binary_w_vv_vx_wx_wv<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in 
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

// multiclass pseudo_binary_nomask_s_x<string constraints = ""> {
//   let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in
//   foreach evr = AllVlmuls in {
//     let VLMul = evr.Vlmul in {
//       defm _S_X : pseudo_binary_nomask<evr.RegClass, evr.RegClass, GPR, evr.Lmulstr, constraints>;
//     }
//   }
// }

multiclass pseudo_binary_v_vvm_vxm<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VVM : pseudo_binary_carryin<evr.RegClass, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VXM : pseudo_binary_carryin<evr.RegClass, evr.RegClass, GPR, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_binary_m_vvm_vxm<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VVM : pseudo_binary_carryin<VM, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VXM : pseudo_binary_carryin<VM, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
    }
  }
}

multiclass pseudo_ternary_v_vvv_vvf<string constraints = ""> {
  let mayLoad = 0, mayStore = 0, hasSideEffects = 0, usesCustomInserter = 0 in 
  foreach evr = AllVlmuls in {
    let VLMul = evr.Vlmul in {
      defm _VV : pseudo_ternary<evr.RegClass, evr.RegClass, evr.RegClass, evr.Lmulstr, constraints>;
      defm _VF : pseudo_ternary<evr.RegClass, FPR32, evr.RegClass, evr.Lmulstr, constraints>;
    }
  }
}



defm PseudoVADD : pseudo_binary_v_vv_vx;
defm PseudoVSUB : pseudo_binary_v_vv_vx;
defm PseudoVMUL : pseudo_binary_v_vv_vx;
defm PseudoVDIV : pseudo_binary_v_vv_vx;
defm PseudoVAND : pseudo_binary_v_vv_vx;
defm PseudoVOR : pseudo_binary_v_vv_vx;
defm PseudoVXOR : pseudo_binary_v_vv_vx;
defm PseudoVWADD : pseudo_binary_w_vv_vx_wx_wv<"@earlyclobber $rd">;
defm PseudoVWADDU : pseudo_binary_w_vv_vx_wx_wv<"@earlyclobber $rd">;
defm PseudoVWSUB : pseudo_binary_w_vv_vx_wx_wv<"@earlyclobber $rd">;
defm PseudoVWSUBU : pseudo_binary_w_vv_vx_wx_wv<"@earlyclobber $rd">;
defm PseudoVADC : pseudo_binary_v_vvm_vxm;
defm PseudoVMADC : pseudo_binary_m_vvm_vxm<"@earlyclobber $rd">;
defm PseudoVSBC : pseudo_binary_v_vvm_vxm;
defm PseudoVMSBC : pseudo_binary_v_vvm_vxm<"@earlyclobber $rd">;
// defm PseudoVNOT : pseudo_unary_v_v;
defm PseudoVSLL : pseudo_binary_v_vv_vx;
defm PseudoVSRL : pseudo_binary_v_vv_vx;
defm PseudoVSRA : pseudo_binary_v_vv_vx;
defm PseudoVFMACC : pseudo_ternary_v_vvv_vvf;
defm PseudoVMV_V : pseudo_unary_nomask_v_x_v_v;
defm PseudoVMV : pseudo_unary_nomask_x_s_s_x;
defm PseudoVFMV : pseudo_vfmv;



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
              arg1_operand:$rs1)>;
        
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
    def : Pat<(evr.Vector (!cast<Intrinsic>(intrinsic_name#"_s_f") 
                           (evr.Vector evr.RegClass:$merge),
                           (f32 FPR32:$rs1))),
              (!cast<Instruction>(instruction_name#"_S_F_M"#evr.LMULstr) 
               evr.RegClass:$merge,
               FPR32:$rs1, evr.SEW)>;
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

defm "" : pat_intrinsic_int_binary_vv_vx<"int_riscv_vadd", "PseudoVADD">;
defm "" : pat_intrinsic_int_binary_w_vv_vx_wv_wx<"int_riscv_vwadd", "PseudoVWADD">;
defm "" : pat_intrinsic_int_binary_v_vvm_vxm<"int_riscv_vadc", "PseudoVADC">;
defm "" : pat_intrinsic_int_binary_m_vvm_vxm<"int_riscv_vmadc", "PseudoVMADC">;
defm "" : pat_intrinsic_vload_store;
defm "" : pat_intrinsic_float_ternary_v_vvv_vvf<"int_riscv_vfmacc", "PseudoVFMACC">;
defm "" : pat_intrinsic_int_unary_nomask_v_v_v_x<"int_riscv_vmv_v", "PseudoVMV_V">;
defm "" : pat_intrinsic_int_binary_nomask_s_x<"int_riscv_vmv", "PseudoVMV">;
defm "" : pat_intrinsic_int_unary_nomask_x_s<"int_riscv_vmv", "PseudoVMV">;
defm "" : pat_intrinsic_vfmv<"int_riscv_vfmv", "PseudoVFMV">;
// defm "" : pat_intrinsic_int_unary_v<"int_riscv_vnot", "PseudoVNOT">;
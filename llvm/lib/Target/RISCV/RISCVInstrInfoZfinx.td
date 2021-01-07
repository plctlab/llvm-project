//=== RISCVInstrInfoZfinx.td - RISC-V 'Zfinx' instructions -*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the RISC-V instructions from the standard 'Zfinx'
// float in integer.
// This version is still experimental as the 'Zfinx' extension hasn't been
// ratified yet.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

def GPRAsFPR : AsmOperandClass {
  let Name = "GPRAsFPR";
  let ParserMethod = "parseGPRAsFPR";
}

def GPRF32Op : RegisterOperand<GPRF32> {
  let ParserMatchClass = GPRAsFPR;
}

def GPROp : RegisterOperand<GPR> {
  let ParserMatchClass = GPRAsFPR;
}

let DecoderNamespace = "RVZfinx" in {
// For all floating extension

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPUnaryOpINX_r<bits<7> funct7, bits<3> funct3, RegisterOperand rdty,
                RegisterOperand rs1ty, string opcodestr>
    : RVInstR<funct7, funct3, OPC_OP_FP, (outs rdty:$rd), (ins rs1ty:$rs1),
              opcodestr, "$rd, $rs1">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPUnaryOpINX_r_frm<bits<7> funct7, RegisterOperand rdty, RegisterOperand rs1ty,
                      string opcodestr>
    : RVInstRFrm<funct7, OPC_OP_FP, (outs rdty:$rd),
                 (ins rs1ty:$rs1, frmarg:$funct3), opcodestr,
                  "$rd, $rs1, $funct3">;

// Zfinx extension on RV32/64
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPFMASINX_rrr_frm<RISCVOpcode opcode, string opcodestr>
    : RVInstR4<0b00, opcode, (outs GPRF32Op:$rd),
               (ins GPRF32Op:$rs1, GPRF32Op:$rs2, GPRF32Op:$rs3, frmarg:$funct3),
                opcodestr, "$rd, $rs1, $rs2, $rs3, $funct3">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPALUSINX_rr<bits<7> funct7, bits<3> funct3, string opcodestr>
    : RVInstR<funct7, funct3, OPC_OP_FP, (outs GPRF32Op:$rd),
              (ins GPRF32Op:$rs1, GPRF32Op:$rs2), opcodestr, "$rd, $rs1, $rs2">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPALUSINX_rr_frm<bits<7> funct7, string opcodestr>
    : RVInstRFrm<funct7, OPC_OP_FP, (outs GPRF32Op:$rd),
                 (ins GPRF32Op:$rs1, GPRF32Op:$rs2, frmarg:$funct3), opcodestr,
                  "$rd, $rs1, $rs2, $funct3">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPCmpSINX_rr<bits<3> funct3, string opcodestr>
    : RVInstR<0b1010000, funct3, OPC_OP_FP, (outs GPROp:$rd),
              (ins GPRF32Op:$rs1, GPRF32Op:$rs2), opcodestr, "$rd, $rs1, $rs2">,
      Sched<[WriteFCmp32, ReadFCmp32, ReadFCmp32]>;

} // DecoderNamespace = "RVZfinx"

class FPUnaryOpINXDynFrmAlias<FPUnaryOpINX_r_frm Inst, string OpcodeStr,
                           RegisterOperand rdty, RegisterOperand rs1ty>
    : InstAlias<OpcodeStr#" $rd, $rs1",
                (Inst rdty:$rd, rs1ty:$rs1, 0b111)>;

class FPFMASINXDynFrmAlias<FPFMASINX_rrr_frm Inst, string OpcodeStr>
    : InstAlias<OpcodeStr#" $rd, $rs1, $rs2, $rs3",
                (Inst GPRF32Op:$rd, GPRF32Op:$rs1, GPRF32Op:$rs2, GPRF32Op:$rs3, 0b111)>;

class FPALUSINXDynFrmAlias<FPALUSINX_rr_frm Inst, string OpcodeStr>
    : InstAlias<OpcodeStr#" $rd, $rs1, $rs2",
                (Inst GPRF32Op:$rd, GPRF32Op:$rs1, GPRF32Op:$rs2, 0b111)>;

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

// Instructions in Zfinx extension on RV32/64
let Predicates = [HasStdExtZfinx] in {
def FMADD_S_INX  : FPFMASINX_rrr_frm<OPC_MADD, "fmadd.s">,
        Sched<[WriteFMulAdd32, ReadFMulAdd32, ReadFMulAdd32, ReadFMulAdd32]>;
def           : FPFMASINXDynFrmAlias<FMADD_S_INX, "fmadd.s">;
def FMSUB_S_INX  : FPFMASINX_rrr_frm<OPC_MSUB, "fmsub.s">,
        Sched<[WriteFMulSub32, ReadFMulSub32, ReadFMulSub32, ReadFMulSub32]>;
def           : FPFMASINXDynFrmAlias<FMSUB_S_INX, "fmsub.s">;
def FNMSUB_S_INX : FPFMASINX_rrr_frm<OPC_NMSUB, "fnmsub.s">,
        Sched<[WriteFMulSub32, ReadFMulSub32, ReadFMulSub32, ReadFMulSub32]>;
def           : FPFMASINXDynFrmAlias<FNMSUB_S_INX, "fnmsub.s">;
def FNMADD_S_INX : FPFMASINX_rrr_frm<OPC_NMADD, "fnmadd.s">,
        Sched<[WriteFMulAdd32, ReadFMulAdd32, ReadFMulAdd32, ReadFMulAdd32]>;
def           : FPFMASINXDynFrmAlias<FNMADD_S_INX, "fnmadd.s">;

def FADD_S_INX   : FPALUSINX_rr_frm<0b0000000, "fadd.s">,
                Sched<[WriteFALU32, ReadFALU32, ReadFALU32]>;
def           : FPALUSINXDynFrmAlias<FADD_S_INX, "fadd.s">;
def FSUB_S_INX   : FPALUSINX_rr_frm<0b0000100, "fsub.s">,
                Sched<[WriteFALU32, ReadFALU32, ReadFALU32]>;
def           : FPALUSINXDynFrmAlias<FSUB_S_INX, "fsub.s">;
def FMUL_S_INX   : FPALUSINX_rr_frm<0b0001000, "fmul.s">,
                Sched<[WriteFMul32, ReadFMul32, ReadFMul32]>;
def           : FPALUSINXDynFrmAlias<FMUL_S_INX, "fmul.s">;
def FDIV_S_INX   : FPALUSINX_rr_frm<0b0001100, "fdiv.s">,
                Sched<[WriteFDiv32, ReadFDiv32, ReadFDiv32]>;
def           : FPALUSINXDynFrmAlias<FDIV_S_INX, "fdiv.s">;

def FSQRT_S_INX  : FPUnaryOpINX_r_frm<0b0101100, GPRF32Op, GPRF32Op, "fsqrt.s">,
                Sched<[]> {
  let rs2 = 0b00000;
}
def           : FPUnaryOpINXDynFrmAlias<FSQRT_S_INX, "fsqrt.s", GPRF32Op, GPRF32Op>;

def FSGNJ_S_INX  : FPALUSINX_rr<0b0010000, 0b000, "fsgnj.s">,
                Sched<[WriteFSGNJ32, ReadFSGNJ32, ReadFSGNJ32]>;
def FSGNJN_S_INX : FPALUSINX_rr<0b0010000, 0b001, "fsgnjn.s">,
                Sched<[WriteFSGNJ32, ReadFSGNJ32, ReadFSGNJ32]>;
def FSGNJX_S_INX : FPALUSINX_rr<0b0010000, 0b010, "fsgnjx.s">,
                Sched<[WriteFSGNJ32, ReadFSGNJ32, ReadFSGNJ32]>;
def FMIN_S_INX   : FPALUSINX_rr<0b0010100, 0b000, "fmin.s">,
                Sched<[WriteFMinMax32, ReadFMinMax32, ReadFMinMax32]>;
def FMAX_S_INX   : FPALUSINX_rr<0b0010100, 0b001, "fmax.s">,
                Sched<[WriteFMinMax32, ReadFMinMax32, ReadFMinMax32]>;

def FCVT_W_S_INX : FPUnaryOpINX_r_frm<0b1100000, GPROp, GPRF32Op, "fcvt.w.s">,
               Sched<[WriteFCvtF32ToI32, ReadFCvtF32ToI32]> {
  let rs2 = 0b00000;
}
def        : FPUnaryOpINXDynFrmAlias<FCVT_W_S_INX, "fcvt.w.s", GPROp, GPRF32Op>;

def FCVT_WU_S_INX : FPUnaryOpINX_r_frm<0b1100000, GPROp, GPRF32Op, "fcvt.wu.s">,
                Sched<[WriteFCvtF32ToI32, ReadFCvtF32ToI32]> {
  let rs2 = 0b00001;
}
def        : FPUnaryOpINXDynFrmAlias<FCVT_WU_S_INX, "fcvt.wu.s", GPROp, GPRF32Op>;

def FEQ_S_INX    : FPCmpSINX_rr<0b010, "feq.s">;
def FLT_S_INX    : FPCmpSINX_rr<0b001, "flt.s">;
def FLE_S_INX    : FPCmpSINX_rr<0b000, "fle.s">;

def FCLASS_S_INX : FPUnaryOpINX_r<0b1110000, 0b001, GPRF32Op, GPRF32Op, "fclass.s">,
                Sched<[WriteFClass32, ReadFClass32]> {
  let rs2 = 0b00000;
}

def FCVT_S_W_INX : FPUnaryOpINX_r_frm<0b1101000, GPRF32Op, GPROp, "fcvt.s.w">,
               Sched<[WriteFCvtI32ToF32, ReadFCvtI32ToF32]> {
  let rs2 = 0b00000;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_S_W_INX, "fcvt.s.w", GPRF32Op, GPROp>;

def ZFCVT_S_WU_INX : FPUnaryOpINX_r_frm<0b1101000, GPRF32Op, GPROp, "fcvt.s.wu">,
                Sched<[WriteFCvtI32ToF32, ReadFCvtI32ToF32]> {
  let rs2 = 0b00001;
}
def           : FPUnaryOpINXDynFrmAlias<ZFCVT_S_WU_INX, "fcvt.s.wu", GPRF32Op, GPROp>;

def : InstAlias<"fabs.s $rd, $rs", (FSGNJX_S_INX GPRF32Op:$rd, GPRF32Op:$rs, GPRF32Op:$rs)>;
def : InstAlias<"fneg.s $rd, $rs", (FSGNJN_S_INX GPRF32Op:$rd, GPRF32Op:$rs, GPRF32Op:$rs)>;

def : InstAlias<"fgt.s $rd, $rs, $rt",
                (FLT_S_INX GPROp:$rd, GPRF32Op:$rt, GPRF32Op:$rs), 0>;
def : InstAlias<"fge.s $rd, $rs, $rt",
                (FLE_S_INX GPROp:$rd, GPRF32Op:$rt, GPRF32Op:$rs), 0>;
} // Predicates = [HasStdExtZfinx]

// Instructions in Zfinx extension on RV64
let Predicates = [HasStdExtZfinx, IsRV64] in {
def FCVT_L_S_INX  : FPUnaryOpINX_r_frm<0b1100000, GPROp, GPRF32Op, "fcvt.l.s">,
                Sched<[WriteFCvtF32ToI64, ReadFCvtF32ToI64]> {
  let rs2 = 0b00010;
}
def           : FPUnaryOpINXDynFrmAlias<FCVT_L_S_INX, "fcvt.l.s", GPROp, GPRF32Op>;

def FCVT_LU_S_INX  : FPUnaryOpINX_r_frm<0b1100000, GPROp, GPRF32Op, "fcvt.lu.s">,
                 Sched<[WriteFCvtF32ToI64, ReadFCvtF32ToI64]> {
  let rs2 = 0b00011;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_LU_S_INX, "fcvt.lu.s", GPROp, GPRF32Op>;

def FCVT_S_L_INX : FPUnaryOpINX_r_frm<0b1101000, GPRF32Op, GPROp, "fcvt.s.l">,
               Sched<[WriteFCvtI64ToF32, ReadFCvtI64ToF32]> {
  let rs2 = 0b00010;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_S_L_INX, "fcvt.s.l", GPRF32Op, GPROp>;

def ZFCVT_S_LU_INX : FPUnaryOpINX_r_frm<0b1101000, GPRF32Op, GPROp, "fcvt.s.lu">,
                Sched<[WriteFCvtI64ToF32, ReadFCvtI64ToF32]> {
  let rs2 = 0b00011;
}
def           : FPUnaryOpINXDynFrmAlias<ZFCVT_S_LU_INX, "fcvt.s.lu", GPRF32Op, GPROp>;
} // Predicates = [HasStdExtZfinx, IsRV64]

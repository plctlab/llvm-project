//===- RISCVInstrInfoZfinx.td - RISC-V 'Zfdinx' instructions -*- tblgen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the RISC-V instructions from the standard 'Zfdinx'
// double in integer.
// This version is still experimental as the 'Zfdinx' extension hasn't been
// ratified yet.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

def GPRPF64AsFPR : AsmOperandClass {
  let Name = "GPRPF64AsFPR";
  let ParserMethod = "parseGPRAsFPR";
}

def GPRF64AsFPR : AsmOperandClass {
  let Name = "GPRF64AsFPR";
  let ParserMethod = "parseGPRAsFPR";
}

def GPRF64Op : RegisterOperand<GPRF64> {
  let ParserMatchClass = GPRF64AsFPR;
}

def GPRPF64Op : RegisterOperand<GPRPF64> {
  let ParserMatchClass = GPRPF64AsFPR;
}

let DecoderNamespace = "RVZfinx" in {

// RV64 and Zfdinx extension
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPFMADINX_rrr_frm<RISCVOpcode opcode, string opcodestr, RegisterOperand freg>
    : RVInstR4<0b01, opcode, (outs freg:$rd),
               (ins freg:$rs1, freg:$rs2, freg:$rs3, frmarg:$funct3),
                opcodestr, "$rd, $rs1, $rs2, $rs3, $funct3">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPALUDINX_rr<bits<7> funct7, bits<3> funct3, string opcodestr, RegisterOperand freg>
    : RVInstR<funct7, funct3, OPC_OP_FP, (outs freg:$rd),
              (ins freg:$rs1, freg:$rs2), opcodestr, "$rd, $rs1, $rs2">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPALUDINX_rr_frm<bits<7> funct7, string opcodestr, RegisterOperand freg>
    : RVInstRFrm<funct7, OPC_OP_FP, (outs freg:$rd),
                (ins freg:$rs1, freg:$rs2, frmarg:$funct3), opcodestr,
                 "$rd, $rs1, $rs2, $funct3">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPCmpDINX_rr<bits<3> funct3, string opcodestr, RegisterOperand freg>
    : RVInstR<0b1010001, funct3, OPC_OP_FP, (outs GPROp:$rd),
              (ins freg:$rs1, freg:$rs2), opcodestr, "$rd, $rs1, $rs2">,
      Sched<[WriteFCmp64, ReadFCmp64, ReadFCmp64]>;
}

class FPFMADINXDynFrmAlias<FPFMADINX_rrr_frm Inst, string OpcodeStr, RegisterOperand freg>
    : InstAlias<OpcodeStr#" $rd, $rs1, $rs2, $rs3",
                (Inst freg:$rd, freg:$rs1, freg:$rs2, freg:$rs3, 0b111)>;

class FPALUDINXDynFrmAlias<FPALUDINX_rr_frm Inst, string OpcodeStr, RegisterOperand freg>
    : InstAlias<OpcodeStr#" $rd, $rs1, $rs2",
                (Inst freg:$rd, freg:$rs1, freg:$rs2, 0b111)>;

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//


// Instructions in Zfdinx extension on RV64
let Predicates = [HasStdExtZfdinx, IsRV64] in {
def FMADD_D_INX  : FPFMADINX_rrr_frm<OPC_MADD, "fmadd.d", GPRF64Op>,
                Sched<[WriteFMulAdd64, ReadFMulAdd64, ReadFMulAdd64, ReadFMulAdd64]>;
def           : FPFMADINXDynFrmAlias<FMADD_D_INX, "fmadd.d", GPRF64Op>;
def FMSUB_D_INX  : FPFMADINX_rrr_frm<OPC_MSUB, "fmsub.d", GPRF64Op>,
                Sched<[WriteFMulSub64, ReadFMulSub64, ReadFMulSub64, ReadFMulSub64]>;
def           : FPFMADINXDynFrmAlias<FMSUB_D_INX, "fmsub.d", GPRF64Op>;
def FNMSUB_D_INX : FPFMADINX_rrr_frm<OPC_NMSUB, "fnmsub.d", GPRF64Op>,
                Sched<[WriteFMulSub64, ReadFMulSub64, ReadFMulSub64, ReadFMulSub64]>;
def           : FPFMADINXDynFrmAlias<FNMSUB_D_INX, "fnmsub.d", GPRF64Op>;
def FNMADD_D_INX : FPFMADINX_rrr_frm<OPC_NMADD, "fnmadd.d", GPRF64Op>,
                Sched<[WriteFMulAdd64, ReadFMulAdd64, ReadFMulAdd64, ReadFMulAdd64]>;
def           : FPFMADINXDynFrmAlias<FNMADD_D_INX, "fnmadd.d", GPRF64Op>;

def FADD_D_INX : FPALUDINX_rr_frm<0b0000001, "fadd.d", GPRF64Op>,
             Sched<[WriteFALU64, ReadFALU64, ReadFALU64]>;
def        : FPALUDINXDynFrmAlias<FADD_D_INX, "fadd.d", GPRF64Op>;
def FSUB_D_INX : FPALUDINX_rr_frm<0b0000101, "fsub.d", GPRF64Op>,
             Sched<[WriteFALU64, ReadFALU64, ReadFALU64]>;
def        : FPALUDINXDynFrmAlias<FSUB_D_INX, "fsub.d", GPRF64Op>;
def FMUL_D_INX : FPALUDINX_rr_frm<0b0001001, "fmul.d", GPRF64Op>,
             Sched<[WriteFMul64, ReadFMul64, ReadFMul64]>;
def        : FPALUDINXDynFrmAlias<FMUL_D_INX, "fmul.d", GPRF64Op>;
def FDIV_D_INX : FPALUDINX_rr_frm<0b0001101, "fdiv.d", GPRF64Op>,
             Sched<[WriteFDiv64, ReadFDiv64, ReadFDiv64]>;
def        : FPALUDINXDynFrmAlias<FDIV_D_INX, "fdiv.d", GPRF64Op>;

def FSQRT_D_INX : FPUnaryOpINX_r_frm<0b0101101, GPRF64Op, GPRF64Op, "fsqrt.d">,
              Sched<[WriteFSqrt64, ReadFSqrt64]> {
  let rs2 = 0b00000;
}
def         : FPUnaryOpINXDynFrmAlias<FSQRT_D_INX, "fsqrt.d", GPRF64Op, GPRF64Op>;

def FSGNJ_D_INX  : FPALUDINX_rr<0b0010001, 0b000, "fsgnj.d", GPRF64Op>,
               Sched<[WriteFSGNJ64, ReadFSGNJ64, ReadFSGNJ64]>;
def FSGNJN_D_INX : FPALUDINX_rr<0b0010001, 0b001, "fsgnjn.d", GPRF64Op>,
               Sched<[WriteFSGNJ64, ReadFSGNJ64, ReadFSGNJ64]>;
def FSGNJX_D_INX : FPALUDINX_rr<0b0010001, 0b010, "fsgnjx.d", GPRF64Op>,
               Sched<[WriteFSGNJ64, ReadFSGNJ64, ReadFSGNJ64]>;
def FMIN_D_INX   : FPALUDINX_rr<0b0010101, 0b000, "fmin.d", GPRF64Op>,
               Sched<[WriteFMinMax64, ReadFMinMax64, ReadFMinMax64]>;
def FMAX_D_INX   : FPALUDINX_rr<0b0010101, 0b001, "fmax.d", GPRF64Op>,
               Sched<[WriteFMinMax64, ReadFMinMax64, ReadFMinMax64]>;

def FCVT_S_D_INX : FPUnaryOpINX_r_frm<0b0100000, GPRF32Op, GPRF64Op, "fcvt.s.d">,
               Sched<[WriteFCvtF64ToF32, ReadFCvtF64ToF32]> {
  let rs2 = 0b00001;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_S_D_INX, "fcvt.s.d", GPRF32Op, GPRF64Op>;

def FCVT_D_S_INX : FPUnaryOpINX_r<0b0100001, 0b000, GPRF64Op, GPRF32Op, "fcvt.d.s">,
               Sched<[WriteFCvtF32ToF64, ReadFCvtF32ToF64]> {
  let rs2 = 0b00000;
}

def FEQ_D_INX : FPCmpDINX_rr<0b010, "feq.d", GPRF64Op>;
def FLT_D_INX : FPCmpDINX_rr<0b001, "flt.d", GPRF64Op>;
def FLE_D_INX : FPCmpDINX_rr<0b000, "fle.d", GPRF64Op>;

def FCLASS_D_INX : FPUnaryOpINX_r<0b1110001, 0b001, GPROp, GPRF64Op, "fclass.d">,
               Sched<[WriteFClass64, ReadFClass64]> {
  let rs2 = 0b00000;
}

def FCVT_W_D_INX : FPUnaryOpINX_r_frm<0b1100001, GPROp, GPRF64Op, "fcvt.w.d">,
               Sched<[WriteFCvtF64ToI32, ReadFCvtF64ToI32]> {
  let rs2 = 0b00000;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_W_D_INX, "fcvt.w.d", GPROp, GPRF64Op>;

def FCVT_WU_D_INX : FPUnaryOpINX_r_frm<0b1100001, GPROp, GPRF64Op, "fcvt.wu.d">,
                Sched<[WriteFCvtF64ToI32, ReadFCvtF64ToI32]> {
  let rs2 = 0b00001;
}
def           : FPUnaryOpINXDynFrmAlias<FCVT_WU_D_INX, "fcvt.wu.d", GPROp, GPRF64Op>;

def FCVT_D_W_INX : FPUnaryOpINX_r<0b1101001, 0b000, GPRF64Op, GPROp, "fcvt.d.w">,
               Sched<[WriteFCvtI32ToF64, ReadFCvtI32ToF64]> {
  let rs2 = 0b00000;
}

def ZFCVT_D_WU_INX : FPUnaryOpINX_r<0b1101001, 0b000, GPRF64Op, GPROp, "fcvt.d.wu">,
                Sched<[WriteFCvtI32ToF64, ReadFCvtI32ToF64]> {
  let rs2 = 0b00001;
}

def FCVT_L_D_INX  : FPUnaryOpINX_r_frm<0b1100001, GPROp, GPRF64Op, "fcvt.l.d">,
               Sched<[WriteFCvtF64ToI64, ReadFCvtF64ToI64]> {
  let rs2 = 0b00010;
}
def            : FPUnaryOpINXDynFrmAlias<FCVT_L_D_INX, "fcvt.l.d", GPROp, GPRF64Op>;

def FCVT_LU_D_INX : FPUnaryOpINX_r_frm<0b1100001, GPROp, GPRF64Op, "fcvt.lu.d">,
                Sched<[WriteFCvtF64ToI64, ReadFCvtF64ToI64]> {
  let rs2 = 0b00011;
}
def            : FPUnaryOpINXDynFrmAlias<FCVT_LU_D_INX, "fcvt.lu.d", GPROp, GPRF64Op>;

def FCVT_D_L_INX  : FPUnaryOpINX_r_frm<0b1101001, GPRF64Op, GPROp, "fcvt.d.l">,
               Sched<[WriteFCvtI64ToF64, ReadFCvtI64ToF64]> {
  let rs2 = 0b00010;
}
def            : FPUnaryOpINXDynFrmAlias<FCVT_D_L_INX, "fcvt.d.l", GPRF64Op, GPROp>;

def FCVT_D_L_INXU : FPUnaryOpINX_r_frm<0b1101001, GPRF64Op, GPROp, "fcvt.d.lu">,
                Sched<[WriteFCvtI64ToF64, ReadFCvtI64ToF64]> {
  let rs2 = 0b00011;
}
def            : FPUnaryOpINXDynFrmAlias<FCVT_D_L_INXU, "fcvt.d.lu", GPRF64Op, GPROp>;

} // Predicates = [HasStdExtZfdinx, IsRV64]

// Instruction in Zfdinx extension on RV32
let Predicates = [HasStdExtZfdinx, IsRV32] in {
let DecoderNamespace = "RV32DZfinx" in {
def ZFMADD_IN32X : FPFMADINX_rrr_frm<OPC_MADD, "fmadd.d", GPRPF64Op>,
               Sched<[WriteFMulAdd64, ReadFMulAdd64, ReadFMulAdd64, ReadFMulAdd64]>;
def ZFMSUB_IN32X : FPFMADINX_rrr_frm<OPC_MSUB, "fmsub.d", GPRPF64Op>,
               Sched<[WriteFMulSub64, ReadFMulSub64, ReadFMulSub64, ReadFMulSub64]>;
def ZFNMSUB_IN32X : FPFMADINX_rrr_frm<OPC_NMSUB, "fnmsub.d", GPRPF64Op>,
               Sched<[WriteFMulSub64, ReadFMulSub64, ReadFMulSub64, ReadFMulSub64]>;
def ZFNMADD_IN32X : FPFMADINX_rrr_frm<OPC_NMADD, "fnmadd.d", GPRPF64Op>,
               Sched<[WriteFMulAdd64, ReadFMulAdd64, ReadFMulAdd64, ReadFMulAdd64]>;

def ZFADD_IN32X : FPALUDINX_rr_frm<0b0000001, "fadd.d", GPRPF64Op>,
             Sched<[WriteFALU64, ReadFALU64, ReadFALU64]>;
def ZFSUB_IN32X : FPALUDINX_rr_frm<0b0000101, "fsub.d", GPRPF64Op>,
             Sched<[WriteFALU64, ReadFALU64, ReadFALU64]>;
def ZFMUL_IN32X : FPALUDINX_rr_frm<0b0001001, "fmul.d", GPRPF64Op>,
             Sched<[WriteFMul64, ReadFMul64, ReadFMul64]>;
def ZFDIV_IN32X : FPALUDINX_rr_frm<0b0001101, "fdiv.d", GPRPF64Op>,
             Sched<[WriteFDiv64, ReadFDiv64, ReadFDiv64]>;

def ZFSQRT_IN32X : FPUnaryOpINX_r_frm<0b0101101, GPRPF64Op, GPRPF64Op, "fsqrt.d">,
              Sched<[WriteFSqrt64, ReadFSqrt64]> {
  let rs2 = 0b00000;
}

def ZFSGNJ_IN32X  : FPALUDINX_rr<0b0010001, 0b000, "fsgnj.d", GPRPF64Op>,
               Sched<[WriteFSGNJ64, ReadFSGNJ64, ReadFSGNJ64]>;
def ZFSGNJN_IN32X : FPALUDINX_rr<0b0010001, 0b001, "fsgnjn.d", GPRPF64Op>,
               Sched<[WriteFSGNJ64, ReadFSGNJ64, ReadFSGNJ64]>;
def ZFSGNJX_IN32X : FPALUDINX_rr<0b0010001, 0b010, "fsgnjx.d", GPRPF64Op>,
               Sched<[WriteFSGNJ64, ReadFSGNJ64, ReadFSGNJ64]>;
def ZFMIN_IN32X   : FPALUDINX_rr<0b0010101, 0b000, "fmin.d", GPRPF64Op>,
               Sched<[WriteFMinMax64, ReadFMinMax64, ReadFMinMax64]>;
def ZFMAX_IN32X   : FPALUDINX_rr<0b0010101, 0b001, "fmax.d", GPRPF64Op>,
               Sched<[WriteFMinMax64, ReadFMinMax64, ReadFMinMax64]>;

def ZFCVT_S_IN32X : FPUnaryOpINX_r_frm<0b0100000, GPRF32Op, GPRPF64Op, "fcvt.s.d">,
               Sched<[WriteFCvtF64ToF32, ReadFCvtF64ToF32]> {
  let rs2 = 0b00001;
}

def ZFCVT_D_S32 : FPUnaryOpINX_r<0b0100001, 0b000, GPRPF64Op, GPRF32Op, "fcvt.d.s">,
               Sched<[WriteFCvtF32ToF64, ReadFCvtF32ToF64]> {
  let rs2 = 0b00000;
}

def ZFEQ_IN32X : FPCmpDINX_rr<0b010, "feq.d", GPRPF64Op>;
def ZFLT_IN32X : FPCmpDINX_rr<0b001, "flt.d", GPRPF64Op>;
def ZFLE_IN32X : FPCmpDINX_rr<0b000, "fle.d", GPRPF64Op>;

def ZFCLASS_IN32X : FPUnaryOpINX_r<0b1110001, 0b001, GPROp, GPRPF64Op, "fclass.d">,
               Sched<[WriteFClass64, ReadFClass64]> {
  let rs2 = 0b00000;
}

def ZFCVT_W_IN32X : FPUnaryOpINX_r_frm<0b1100001, GPROp, GPRPF64Op, "fcvt.w.d">,
               Sched<[WriteFCvtF64ToI32, ReadFCvtF64ToI32]> {
  let rs2 = 0b00000;
}

def ZFCVT_WU_IN32X : FPUnaryOpINX_r_frm<0b1100001, GPROp, GPRPF64Op, "fcvt.wu.d">,
                Sched<[WriteFCvtF64ToI32, ReadFCvtF64ToI32]> {
  let rs2 = 0b00001;
}

def ZFCVT_D_W32 : FPUnaryOpINX_r<0b1101001, 0b000, GPRPF64Op, GPROp, "fcvt.d.w">,
               Sched<[WriteFCvtI32ToF64, ReadFCvtI32ToF64]> {
  let rs2 = 0b00000;
}

def ZFCVT_D_WU32 : FPUnaryOpINX_r<0b1101001, 0b000, GPRPF64Op, GPROp, "fcvt.d.wu">,
                Sched<[WriteFCvtI32ToF64, ReadFCvtI32ToF64]> {
  let rs2 = 0b00001;
}
} // DecoderNamespace = "RV32DZfinx"
def        : FPFMADINXDynFrmAlias<ZFMADD_IN32X, "fmadd.d", GPRPF64Op>;
def        : FPFMADINXDynFrmAlias<ZFMSUB_IN32X, "fmsub.d", GPRPF64Op>;
def        : FPFMADINXDynFrmAlias<ZFNMSUB_IN32X, "fnmsub.d", GPRPF64Op>;
def        : FPALUDINXDynFrmAlias<ZFADD_IN32X, "fadd.d", GPRPF64Op>;
def        : FPFMADINXDynFrmAlias<ZFNMADD_IN32X, "fnmadd.d", GPRPF64Op>;
def        : FPALUDINXDynFrmAlias<ZFSUB_IN32X, "fsub.d", GPRPF64Op>;
def        : FPALUDINXDynFrmAlias<ZFMUL_IN32X, "fmul.d", GPRPF64Op>;
def        : FPALUDINXDynFrmAlias<ZFDIV_IN32X, "fdiv.d", GPRPF64Op>;
def        : FPUnaryOpINXDynFrmAlias<ZFCVT_W_IN32X, "fcvt.w.d", GPROp, GPRPF64Op>;
def        : FPUnaryOpINXDynFrmAlias<ZFSQRT_IN32X, "fsqrt.d", GPRPF64Op, GPRPF64Op>;
def        : FPUnaryOpINXDynFrmAlias<ZFCVT_S_IN32X, "fcvt.s.d", GPRF32Op, GPRPF64Op>;
def        : FPUnaryOpINXDynFrmAlias<ZFCVT_WU_IN32X, "fcvt.wu.d", GPROp, GPRPF64Op>;

} // Predicates = [HasStdExtD, HasStdExtZfinx, IsRV32]

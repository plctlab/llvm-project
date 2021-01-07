//===- RISCVInstrInfoZfinx.td - RISC-V 'Zfhinx' instructions -*- tblgen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the RISC-V instructions from the standard 'Zfhinx'
// half float in integer.
// This version is still experimental as the 'Zfhinx' extension hasn't been
// ratified yet.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

def GPRF16Op : RegisterOperand<GPRF16> {
  let ParserMatchClass = GPRAsFPR;
}

let DecoderNamespace = "RVZfinx" in {

// Zfhinx extension on RV32/64
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPFMAHINX_rrr_frm<RISCVOpcode opcode, string opcodestr>
    : RVInstR4<0b10, opcode, (outs GPRF16Op:$rd),
               (ins GPRF16Op:$rs1, GPRF16Op:$rs2, GPRF16Op:$rs3, frmarg:$funct3),
                opcodestr, "$rd, $rs1, $rs2, $rs3, $funct3">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPALUHINX_rr<bits<7> funct7, bits<3> funct3, string opcodestr>
    : RVInstR<funct7, funct3, OPC_OP_FP, (outs GPRF16Op:$rd),
              (ins GPRF16Op:$rs1, GPRF16Op:$rs2), opcodestr, "$rd, $rs1, $rs2">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPALUHINX_rr_frm<bits<7> funct7, string opcodestr>
    : RVInstRFrm<funct7, OPC_OP_FP, (outs GPRF16Op:$rd),
                 (ins GPRF16Op:$rs1, GPRF16Op:$rs2, frmarg:$funct3), opcodestr,
                  "$rd, $rs1, $rs2, $funct3">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class FPCmpHINX_rr<bits<3> funct3, string opcodestr>
    : RVInstR<0b1010010, funct3, OPC_OP_FP, (outs GPROp:$rd),
              (ins GPRF16Op:$rs1, GPRF16Op:$rs2), opcodestr, "$rd, $rs1, $rs2">,
      Sched<[]>;
}

class FPFMAHINXDynFrmAlias<FPFMAHINX_rrr_frm Inst, string OpcodeStr>
    : InstAlias<OpcodeStr#" $rd, $rs1, $rs2, $rs3",
                (Inst GPRF16Op:$rd, GPRF16Op:$rs1, GPRF16Op:$rs2, GPRF16Op:$rs3, 0b111)>;

class FPALUHINXDynFrmAlias<FPALUHINX_rr_frm Inst, string OpcodeStr>
    : InstAlias<OpcodeStr#" $rd, $rs1, $rs2",
                (Inst GPRF16Op:$rd, GPRF16Op:$rs1, GPRF16Op:$rs2, 0b111)>;

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

// instructions in Zfhinx extension on RV32/64
let Predicates = [HasStdExtZfhinx] in {
def FMADD_H_INX  : FPFMAHINX_rrr_frm<OPC_MADD, "fmadd.h">, Sched<[]>;
def           : FPFMAHINXDynFrmAlias<FMADD_H_INX, "fmadd.h">;
def FMSUB_H_INX  : FPFMAHINX_rrr_frm<OPC_MSUB, "fmsub.h">, Sched<[]>;
def           : FPFMAHINXDynFrmAlias<FMSUB_H_INX, "fmsub.h">;
def FNMSUB_H_INX : FPFMAHINX_rrr_frm<OPC_NMSUB, "fnmsub.h">, Sched<[]>;
def           : FPFMAHINXDynFrmAlias<FNMSUB_H_INX, "fnmsub.h">;
def FNMADD_H_INX : FPFMAHINX_rrr_frm<OPC_NMADD, "fnmadd.h">, Sched<[]>;
def           : FPFMAHINXDynFrmAlias<FNMADD_H_INX, "fnmadd.h">;

def FADD_H_INX   : FPALUHINX_rr_frm<0b0000010, "fadd.h">, Sched<[]>;
def           : FPALUHINXDynFrmAlias<FADD_H_INX, "fadd.h">;
def FSUB_H_INX   : FPALUHINX_rr_frm<0b0000110, "fsub.h">, Sched<[]>;
def           : FPALUHINXDynFrmAlias<FSUB_H_INX, "fsub.h">;
def FMUL_H_INX   : FPALUHINX_rr_frm<0b0001010, "fmul.h">, Sched<[]>;
def           : FPALUHINXDynFrmAlias<FMUL_H_INX, "fmul.h">;
def FDIV_H_INX   : FPALUHINX_rr_frm<0b0001110, "fdiv.h">, Sched<[]>;
def           : FPALUHINXDynFrmAlias<FDIV_H_INX, "fdiv.h">;

def FSQRT_H_INX  : FPUnaryOpINX_r_frm<0b0101110, GPRF16Op, GPRF16Op, "fsqrt.h">,
                Sched<[]> {
  let rs2 = 0b00000;
}
def           : FPUnaryOpINXDynFrmAlias<FSQRT_H_INX, "fsqrt.h", GPRF16Op, GPRF16Op>;

def FSGNJ_H_INX  : FPALUHINX_rr<0b0010010, 0b000, "fsgnj.h">, Sched<[]>;
def FSGNJN_H_INX : FPALUHINX_rr<0b0010010, 0b001, "fsgnjn.h">, Sched<[]>;
def FSGNJX_H_INX : FPALUHINX_rr<0b0010010, 0b010, "fsgnjx.h">, Sched<[]>;
def FMIN_H_INX   : FPALUHINX_rr<0b0010110, 0b000, "fmin.h">, Sched<[]>;
def FMAX_H_INX   : FPALUHINX_rr<0b0010110, 0b001, "fmax.h">, Sched<[]>;

def FCVT_W_H_INX : FPUnaryOpINX_r_frm<0b1100010, GPROp, GPRF16Op, "fcvt.w.h">,
                Sched<[]> {
  let rs2 = 0b00000;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_W_H_INX, "fcvt.w.h", GPROp, GPRF16Op>;

def FCVT_WU_H_INX : FPUnaryOpINX_r_frm<0b1100010, GPROp, GPRF16Op, "fcvt.wu.h">,
                Sched<[]> {
  let rs2 = 0b00001;
}
def           : FPUnaryOpINXDynFrmAlias<FCVT_WU_H_INX, "fcvt.wu.h", GPROp, GPRF16Op>;

def FCVT_H_W_INX : FPUnaryOpINX_r_frm<0b1101010, GPRF16Op, GPROp, "fcvt.h.w">,
               Sched<[]> {
  let rs2 = 0b00000;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_H_W_INX, "fcvt.h.w", GPRF16Op, GPROp>;

def FCVT_H_W_INXU : FPUnaryOpINX_r_frm<0b1101010, GPRF16Op, GPROp, "fcvt.h.wu">,
                Sched<[]> {
  let rs2 = 0b00001;
}
def           : FPUnaryOpINXDynFrmAlias<FCVT_H_W_INXU, "fcvt.h.wu", GPRF16Op, GPROp>;

def FCVT_H_S_INX : FPUnaryOpINX_r_frm<0b0100010, GPRF16Op, GPRF32Op, "fcvt.h.s">,
               Sched<[]> {
  let rs2 = 0b00000;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_H_S_INX, "fcvt.h.s", GPRF16Op, GPRF32Op>;

def FCVT_S_H_INX : FPUnaryOpINX_r<0b0100000, 0b000, GPRF32Op, GPRF16Op, "fcvt.s.h">,
               Sched<[]> {
  let rs2 = 0b00010;
}

def FEQ_H_INX    : FPCmpHINX_rr<0b010, "feq.h">;
def FLT_H_INX    : FPCmpHINX_rr<0b001, "flt.h">;
def FLE_H_INX    : FPCmpHINX_rr<0b000, "fle.h">;

def FCLASS_H_INX : FPUnaryOpINX_r<0b1110010, 0b001, GPRF16Op, GPRF16Op, "fclass.h">,
                Sched<[]> {
  let rs2 = 0b00000;
}

def : InstAlias<"fabs.h $rd, $rs", (FSGNJX_H_INX GPRF16Op:$rd, GPRF16Op:$rs, GPRF16Op:$rs)>;
def : InstAlias<"fneg.h $rd, $rs", (FSGNJN_H_INX GPRF16Op:$rd, GPRF16Op:$rs, GPRF16Op:$rs)>;

def : InstAlias<"fgt.h $rd, $rs, $rt",
                (FLT_H_INX GPROp:$rd, GPRF16Op:$rt, GPRF16Op:$rs), 0>;
def : InstAlias<"fge.h $rd, $rs, $rt",
                (FLE_H_INX GPROp:$rd, GPRF16Op:$rt, GPRF16Op:$rs), 0>;
} // Predicates = [HasStdExtZfhinx]

// Instructions in Zfinx extension on RV64
let Predicates = [HasStdExtZfhinx, IsRV64] in {
def FCVT_L_H_INX  : FPUnaryOpINX_r_frm<0b1100010, GPROp, GPRF16Op, "fcvt.l.h">,
                Sched<[]> {
  let rs2 = 0b00010;
}
def           : FPUnaryOpINXDynFrmAlias<FCVT_L_H_INX, "fcvt.l.h", GPROp, GPRF16Op>;

def FCVT_LU_H_INX  : FPUnaryOpINX_r_frm<0b1100010, GPROp, GPRF16Op, "fcvt.lu.h">,
                 Sched<[]> {
  let rs2 = 0b00011;
}
def            : FPUnaryOpINXDynFrmAlias<FCVT_LU_H_INX, "fcvt.lu.h", GPROp, GPRF16Op>;

def FCVT_H_L_INX : FPUnaryOpINX_r_frm<0b1101010, GPRF16Op, GPROp, "fcvt.h.l">,
               Sched<[]> {
  let rs2 = 0b00010;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_H_L_INX, "fcvt.h.l", GPRF16Op, GPROp>;

def ZFCVT_H_LU_INX : FPUnaryOpINX_r_frm<0b1101010, GPRF16Op, GPROp, "fcvt.h.lu">,
                Sched<[]> {
  let rs2 = 0b00011;
}
def           : FPUnaryOpINXDynFrmAlias<ZFCVT_H_LU_INX, "fcvt.h.lu", GPRF16Op, GPROp>;
} // Predicates = [HasStdExtZfhinx, IsRV64]

// instructions in Zfinx and Zfdinx extensions
let Predicates = [HasStdExtZfhinx, HasStdExtZfdinx] in {
def FCVT_H_D_INX : FPUnaryOpINX_r_frm<0b0100010, GPRF16Op, GPRF64Op, "fcvt.h.d">,
               Sched<[]> {
  let rs2 = 0b00001;
}
def          : FPUnaryOpINXDynFrmAlias<FCVT_H_D_INX, "fcvt.h.d", GPRF16Op, GPRF64Op>;

def FCVT_D_H_INX : FPUnaryOpINX_r<0b0100001, 0b000, GPRF64Op, GPRF16Op, "fcvt.d.h">,
               Sched<[]> {
  let rs2 = 0b00010;
}
} // Predicates = [HasStdExtZfhinx, HasStdExtZfdinx]

//===-- RISCVInstPrinter.cpp - Convert RISCV MCInst to asm syntax ---------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This class prints an RISCV MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#include "RISCVInstPrinter.h"
#include "RISCVBaseInfo.h"
#include "RISCVMCExpr.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"
using namespace llvm;

#define DEBUG_TYPE "asm-printer"

// Include the auto-generated portion of the assembly writer.
#define PRINT_ALIAS_INSTR
#include "RISCVGenAsmWriter.inc"

// Include the auto-generated portion of the compress emitter.
#define GEN_UNCOMPRESS_INSTR
#include "RISCVGenCompressInstEmitter.inc"

static cl::opt<bool>
    NoAliases("riscv-no-aliases",
              cl::desc("Disable the emission of assembler pseudo instructions"),
              cl::init(false), cl::Hidden);

// Print architectural register names rather than the ABI names (such as x2
// instead of sp).
// TODO: Make RISCVInstPrinter::getRegisterName non-static so that this can a
// member.
static bool ArchRegNames;

// The command-line flags above are used by llvm-mc and llc. They can be used by
// `llvm-objdump`, but we override their values here to handle options passed to
// `llvm-objdump` with `-M` (which matches GNU objdump). There did not seem to
// be an easier way to allow these options in all these tools, without doing it
// this way.
bool RISCVInstPrinter::applyTargetSpecificCLOption(StringRef Opt) {
  if (Opt == "no-aliases") {
    PrintAliases = false;
    return true;
  }
  if (Opt == "numeric") {
    ArchRegNames = true;
    return true;
  }

  return false;
}

void RISCVInstPrinter::printInst(const MCInst *MI, uint64_t Address,
                                 StringRef Annot, const MCSubtargetInfo &STI,
                                 raw_ostream &O) {
  bool Res = false;
  const MCInst *NewMI = MI;
  MCInst UncompressedMI;
  if (PrintAliases && !NoAliases)
    Res = uncompressInst(UncompressedMI, *MI, MRI, STI);
  if (Res)
    NewMI = const_cast<MCInst *>(&UncompressedMI);
  if (!PrintAliases || NoAliases || !printAliasInstr(NewMI, Address, STI, O))
    printInstruction(NewMI, Address, STI, O);
  printAnnotation(O, Annot);
}

void RISCVInstPrinter::printRegName(raw_ostream &O, unsigned RegNo) const {
  O << getRegisterName(RegNo);
}

void RISCVInstPrinter::printOperand(const MCInst *MI, unsigned OpNo,
                                    const MCSubtargetInfo &STI, raw_ostream &O,
                                    const char *Modifier) {
  assert((Modifier == 0 || Modifier[0] == 0) && "No modifiers supported");
  const MCOperand &MO = MI->getOperand(OpNo);

  if (MO.isReg()) {
    printRegName(O, MO.getReg());
    return;
  }

  if (MO.isImm()) {
    O << MO.getImm();
    return;
  }

  assert(MO.isExpr() && "Unknown operand kind in printOperand");
  MO.getExpr()->print(O, &MAI);
}

void RISCVInstPrinter::printBranchOperand(const MCInst *MI, uint64_t Address,
                                          unsigned OpNo,
                                          const MCSubtargetInfo &STI,
                                          raw_ostream &O) {
  const MCOperand &MO = MI->getOperand(OpNo);
  if (!MO.isImm())
    return printOperand(MI, OpNo, STI, O);

  if (PrintBranchImmAsAddress) {
    uint64_t Target = Address + MO.getImm();
    if (!STI.hasFeature(RISCV::Feature64Bit))
      Target &= 0xffffffff;
    O << formatHex(Target);
  } else {
    O << MO.getImm();
  }
}

void RISCVInstPrinter::printCSRSystemRegister(const MCInst *MI, unsigned OpNo,
                                              const MCSubtargetInfo &STI,
                                              raw_ostream &O) {
  unsigned Imm = MI->getOperand(OpNo).getImm();
  auto SysReg = RISCVSysReg::lookupSysRegByEncoding(Imm);
  if (SysReg && SysReg->haveRequiredFeatures(STI.getFeatureBits()))
    O << SysReg->Name;
  else
    O << Imm;
}

void RISCVInstPrinter::printFenceArg(const MCInst *MI, unsigned OpNo,
                                     const MCSubtargetInfo &STI,
                                     raw_ostream &O) {
  unsigned FenceArg = MI->getOperand(OpNo).getImm();
  assert (((FenceArg >> 4) == 0) && "Invalid immediate in printFenceArg");

  if ((FenceArg & RISCVFenceField::I) != 0)
    O << 'i';
  if ((FenceArg & RISCVFenceField::O) != 0)
    O << 'o';
  if ((FenceArg & RISCVFenceField::R) != 0)
    O << 'r';
  if ((FenceArg & RISCVFenceField::W) != 0)
    O << 'w';
  if (FenceArg == 0)
    O << "unknown";
}

void RISCVInstPrinter::printFRMArg(const MCInst *MI, unsigned OpNo,
                                   const MCSubtargetInfo &STI, raw_ostream &O) {
  auto FRMArg =
      static_cast<RISCVFPRndMode::RoundingMode>(MI->getOperand(OpNo).getImm());
  O << RISCVFPRndMode::roundingModeToString(FRMArg);
}

void RISCVInstPrinter::printAtomicMemOp(const MCInst *MI, unsigned OpNo,
                                        const MCSubtargetInfo &STI,
                                        raw_ostream &O) {
  const MCOperand &MO = MI->getOperand(OpNo);

  assert(MO.isReg() && "printAtomicMemOp can only print register operands");
  O << "(";
  printRegName(O, MO.getReg());
  O << ")";
}

void RISCVInstPrinter::printVTypeI(const MCInst *MI, unsigned OpNo,
                                   const MCSubtargetInfo &STI, raw_ostream &O) {
  unsigned Imm = MI->getOperand(OpNo).getImm();
  // Print the raw immediate for reserved values: vlmul[2:0]=4, vsew[2:0]=0b1xx,
  // or non-zero in bits 8 and above.
  if (RISCVVType::getVLMUL(Imm) == RISCVII::VLMUL::LMUL_RESERVED ||
      RISCVVType::getSEW(Imm) > 64 || (Imm >> 8) != 0) {
    O << Imm;
    return;
  }
  // Print the text form.
  RISCVVType::printVType(Imm, O);
}

void RISCVInstPrinter::printAlist(const MCInst *MI, unsigned OpNo,
                                  const MCSubtargetInfo &STI, raw_ostream &O) {
  unsigned SlistImm = MI->getOperand(OpNo - 1).getImm();
  unsigned areg = MI->getOperand(OpNo).getImm();
  unsigned opcode = MI->getOpcode();
  RISCVZCE::printAlist(opcode, SlistImm, areg, O);
}

void RISCVInstPrinter::printSlist(const MCInst *MI, unsigned OpNo,
                                  const MCSubtargetInfo &STI, raw_ostream &O) {
  unsigned Imm = MI->getOperand(OpNo).getImm();
  RISCVZCE::printSlist(Imm, O);
}

void RISCVInstPrinter::printRetval(const MCInst *MI, unsigned OpNo,
                                  const MCSubtargetInfo &STI, raw_ostream &O) {
  unsigned Imm = MI->getOperand(OpNo).getImm();
  RISCVZCE::printRetval(Imm, O);
}

void RISCVInstPrinter::printRlist2(const MCInst *MI, unsigned OpNo,
                                  const MCSubtargetInfo &STI, raw_ostream &O) {
  unsigned Imm = MI->getOperand(OpNo).getImm();
  RISCVZCE::printRlist2(Imm, O);
}

void RISCVInstPrinter::printRlist3(const MCInst *MI, unsigned OpNo,
                                  const MCSubtargetInfo &STI, raw_ostream &O) {
  unsigned Imm = MI->getOperand(OpNo).getImm();
  RISCVZCE::printRlist3(Imm, O);
}

#define DECODE_SPIMM(MAX_BINARYVALUE, VAL, VAL64) \
if (Imm <= MAX_BINARYVALUE){ \
  int64_t res = isRV64 ? VAL64 : VAL; \
  spimm = res + 16 * Imm; \
}

void RISCVInstPrinter::printSpimm(const MCInst *MI, unsigned OpNo,
                const MCSubtargetInfo &STI, raw_ostream &O){
  int64_t Imm = MI->getOperand(OpNo).getImm();
  Imm = Imm >> 4;
  unsigned opcode = MI->getOpcode();
  bool isRV64 = STI.getFeatureBits()[RISCV::Feature64Bit];
  int64_t spimm = 0;

  if (opcode == RISCV::PUSH || opcode == RISCV::PUSH_E ||
      opcode == RISCV::POP || opcode == RISCV::POP_E ||
      opcode == RISCV::POPRET || opcode == RISCV::POPRET_E){
    switch ((RISCVZCE::SLISTENCODE)MI->getOperand(0).getImm())
    {
    default:
      break;
    case RISCVZCE::SLISTENCODE::RA:
    case RISCVZCE::SLISTENCODE::RA_S0:
      DECODE_SPIMM(31,16,16)
      break;
    case RISCVZCE::SLISTENCODE::RA_S0_S1:
    case RISCVZCE::SLISTENCODE::RA_S0_S2:
    case RISCVZCE::SLISTENCODE::RA_S0_S2_E:
      DECODE_SPIMM(31,16,32)
      break;
    case RISCVZCE::SLISTENCODE::RA_S0_S3:
    case RISCVZCE::SLISTENCODE::RA_S0_S4:
    case RISCVZCE::SLISTENCODE::RA_S0_S3_E:
    case RISCVZCE::SLISTENCODE::RA_S0_S4_E:
      DECODE_SPIMM(31,32,48)
      break;
    case RISCVZCE::SLISTENCODE::RA_S0_S5:
    case RISCVZCE::SLISTENCODE::RA_S0_S6:
      DECODE_SPIMM(31,32,64)
      break;
    case RISCVZCE::SLISTENCODE::RA_S0_S7:
    case RISCVZCE::SLISTENCODE::RA_S0_S8:
      DECODE_SPIMM(31,48,80)
      break;
    case RISCVZCE::SLISTENCODE::RA_S0_S9:
    case RISCVZCE::SLISTENCODE::RA_S0_S10:
      DECODE_SPIMM(31,48,96)
      break;
    case RISCVZCE::SLISTENCODE::RA_S0_S11:
      DECODE_SPIMM(31,64,112)
      break;
    }
  }
  if (opcode == RISCV::C_POPRET || opcode == RISCV::C_PUSH){
    switch ((RISCVZCE::RLIST3ENCODE)MI->getOperand(0).getImm())
    {
    default:
      break;
    case RISCVZCE::RLIST3ENCODE::RA:
    case RISCVZCE::RLIST3ENCODE::RA_S0:
      DECODE_SPIMM(5,16,16)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S1:
    case RISCVZCE::RLIST3ENCODE::RA_S0_S2:
      DECODE_SPIMM(5,16,32)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S3:
      DECODE_SPIMM(5,32,48)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S5:
      DECODE_SPIMM(5,32,64)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S7:
      DECODE_SPIMM(5,48,80)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S11:
      DECODE_SPIMM(5,64,112)
      break;
    }
  }
  if (opcode == RISCV::C_POP){
    switch ((RISCVZCE::RLIST3ENCODE)MI->getOperand(0).getImm())
    {
    default:
      break;
    case RISCVZCE::RLIST3ENCODE::RA:
    case RISCVZCE::RLIST3ENCODE::RA_S0:
      DECODE_SPIMM(1,16,16)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S1:
    case RISCVZCE::RLIST3ENCODE::RA_S0_S2:
      DECODE_SPIMM(1,16,32)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S3:
      DECODE_SPIMM(1,32,48)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S5:
      DECODE_SPIMM(1,32,64)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S7:
      DECODE_SPIMM(1,48,80)
      break;
    case RISCVZCE::RLIST3ENCODE::RA_S0_S11:
      DECODE_SPIMM(1,64,112)
      break;
    }
  }
  if (opcode == RISCV::C_POP_E){
    switch ((RISCVZCE::RLIST2ENCODE)MI->getOperand(0).getImm())
    {
    default:
      break;
    case RISCVZCE::RLIST2ENCODE::RA_S0_S2:
      DECODE_SPIMM(1,16,0)
      break;
    case RISCVZCE::RLIST2ENCODE::RA_S0_S3:
      DECODE_SPIMM(1,32,0)
      break;
    // case RISCVZCE::RLIST2ENCODE::RA_S0_S4:
    //   DECODE_SPIMM(1,16,0)
    //   break;
    }
  }
  if (opcode == RISCV::C_POPRET_E || opcode == RISCV::C_PUSH_E){
    int64_t rlist2 = MI->getOperand(0).getImm();
    switch (rlist2)
    {
    default:
      break;
    case (int64_t)RISCVZCE::RLIST2ENCODE::RA_S0_S2:
      DECODE_SPIMM(5,16,0)
      break;
    case (int64_t)RISCVZCE::RLIST2ENCODE::RA_S0_S3:
    case (int64_t)RISCVZCE::RLIST2ENCODE::RA_S0_S4:
      DECODE_SPIMM(5,32,0)
      break;
    }
  }

  if(opcode == RISCV::PUSH || opcode == RISCV::PUSH_E || opcode == RISCV::C_PUSH || opcode == RISCV::C_PUSH_E){
    spimm *= -1;
  }

  RISCVZCE::printSpimm(spimm, O);
}

void RISCVInstPrinter::printVMaskReg(const MCInst *MI, unsigned OpNo,
                                     const MCSubtargetInfo &STI,
                                     raw_ostream &O) {
  const MCOperand &MO = MI->getOperand(OpNo);

  assert(MO.isReg() && "printVMaskReg can only print register operands");
  if (MO.getReg() == RISCV::NoRegister)
    return;
  O << ", ";
  printRegName(O, MO.getReg());
  O << ".t";
}

const char *RISCVInstPrinter::getRegisterName(unsigned RegNo) {
  return getRegisterName(RegNo, ArchRegNames ? RISCV::NoRegAltName
                                             : RISCV::ABIRegAltName);
}

//===-- RISCVBaseInfo.h - Top level definitions for RISCV MC ----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains small standalone enum definitions for the RISCV target
// useful for the compiler back-end and the MC libraries.
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_LIB_TARGET_RISCV_MCTARGETDESC_RISCVBASEINFO_H
#define LLVM_LIB_TARGET_RISCV_MCTARGETDESC_RISCVBASEINFO_H

#include "MCTargetDesc/RISCVMCTargetDesc.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/MC/MCInstrDesc.h"
#include "llvm/MC/SubtargetFeature.h"
#include "llvm/MC/MCRegister.h"

namespace llvm {

// RISCVII - This namespace holds all of the target specific flags that
// instruction info tracks. All definitions must match RISCVInstrFormats.td.
namespace RISCVII {
enum {
  InstFormatPseudo = 0,
  InstFormatR = 1,
  InstFormatR4 = 2,
  InstFormatI = 3,
  InstFormatS = 4,
  InstFormatB = 5,
  InstFormatU = 6,
  InstFormatJ = 7,
  InstFormatCR = 8,
  InstFormatCI = 9,
  InstFormatCSS = 10,
  InstFormatCIW = 11,
  InstFormatCL = 12,
  InstFormatCS = 13,
  InstFormatCA = 14,
  InstFormatCB = 15,
  InstFormatCJ = 16,
  InstFormatOther = 17,

  InstFormatMask = 31,
  InstFormatShift = 0,

  ConstraintShift = InstFormatShift + 5,
  ConstraintMask = 0b111 << ConstraintShift,

  VLMulShift = ConstraintShift + 3,
  VLMulMask = 0b111 << VLMulShift,

  // Do we need to add a dummy mask op when converting RVV Pseudo to MCInst.
  HasDummyMaskOpShift = VLMulShift + 3,
  HasDummyMaskOpMask = 1 << HasDummyMaskOpShift,

  // Force a tail agnostic policy even this instruction has a tied destination.
  ForceTailAgnosticShift = HasDummyMaskOpShift + 1,
  ForceTailAgnosticMask = 1 << ForceTailAgnosticShift,

  // Does this instruction have a merge operand that must be removed when
  // converting to MCInst. It will be the first explicit use operand. Used by
  // RVV Pseudos.
  HasMergeOpShift = ForceTailAgnosticShift + 1,
  HasMergeOpMask = 1 << HasMergeOpShift,

  // Does this instruction have a SEW operand. It will be the last explicit
  // operand unless there is a vector policy operand. Used by RVV Pseudos.
  HasSEWOpShift = HasMergeOpShift + 1,
  HasSEWOpMask = 1 << HasSEWOpShift,

  // Does this instruction have a VL operand. It will be the second to last
  // explicit operand unless there is a vector policy operand. Used by RVV
  // Pseudos.
  HasVLOpShift = HasSEWOpShift + 1,
  HasVLOpMask = 1 << HasVLOpShift,

  // Does this instruction have a vector policy operand. It will be the last
  // explicit operand. Used by RVV Pseudos.
  HasVecPolicyOpShift = HasVLOpShift + 1,
  HasVecPolicyOpMask = 1 << HasVecPolicyOpShift,

  // Is this instruction a vector widening reduction instruction. Used by RVV
  // Pseudos.
  IsRVVWideningReductionShift = HasVecPolicyOpShift + 1,
  IsRVVWideningReductionMask = 1 << IsRVVWideningReductionShift,
};

// Match with the definitions in RISCVInstrFormatsV.td
enum VConstraintType {
  NoConstraint = 0,
  VS2Constraint = 0b001,
  VS1Constraint = 0b010,
  VMConstraint = 0b100,
};

enum VLMUL : uint8_t {
  LMUL_1 = 0,
  LMUL_2,
  LMUL_4,
  LMUL_8,
  LMUL_RESERVED,
  LMUL_F8,
  LMUL_F4,
  LMUL_F2
};

enum {
  TAIL_UNDISTURBED = 0,
  TAIL_AGNOSTIC = 1,
};

// Helper functions to read TSFlags.
/// \returns the format of the instruction.
static inline unsigned getFormat(uint64_t TSFlags) {
  return (TSFlags & InstFormatMask) >> InstFormatShift;
}
/// \returns the constraint for the instruction.
static inline VConstraintType getConstraint(uint64_t TSFlags) {
  return static_cast<VConstraintType>
             ((TSFlags & ConstraintMask) >> ConstraintShift);
}
/// \returns the LMUL for the instruction.
static inline VLMUL getLMul(uint64_t TSFlags) {
  return static_cast<VLMUL>((TSFlags & VLMulMask) >> VLMulShift);
}
/// \returns true if there is a dummy mask operand for the instruction.
static inline bool hasDummyMaskOp(uint64_t TSFlags) {
  return TSFlags & HasDummyMaskOpMask;
}
/// \returns true if tail agnostic is enforced for the instruction.
static inline bool doesForceTailAgnostic(uint64_t TSFlags) {
  return TSFlags & ForceTailAgnosticMask;
}
/// \returns true if there is a merge operand for the instruction.
static inline bool hasMergeOp(uint64_t TSFlags) {
  return TSFlags & HasMergeOpMask;
}
/// \returns true if there is a SEW operand for the instruction.
static inline bool hasSEWOp(uint64_t TSFlags) {
  return TSFlags & HasSEWOpMask;
}
/// \returns true if there is a VL operand for the instruction.
static inline bool hasVLOp(uint64_t TSFlags) {
  return TSFlags & HasVLOpMask;
}
/// \returns true if there is a vector policy operand for this instruction.
static inline bool hasVecPolicyOp(uint64_t TSFlags) {
  return TSFlags & HasVecPolicyOpMask;
}
/// \returns true if it is a vector widening reduction instruction.
static inline bool isRVVWideningReduction(uint64_t TSFlags) {
  return TSFlags & IsRVVWideningReductionMask;
}

// RISC-V Specific Machine Operand Flags
enum {
  MO_None = 0,
  MO_CALL = 1,
  MO_PLT = 2,
  MO_LO = 3,
  MO_HI = 4,
  MO_PCREL_LO = 5,
  MO_PCREL_HI = 6,
  MO_GOT_HI = 7,
  MO_TPREL_LO = 8,
  MO_TPREL_HI = 9,
  MO_TPREL_ADD = 10,
  MO_TLS_GOT_HI = 11,
  MO_TLS_GD_HI = 12,

  // Used to differentiate between target-specific "direct" flags and "bitmask"
  // flags. A machine operand can only have one "direct" flag, but can have
  // multiple "bitmask" flags.
  MO_DIRECT_FLAG_MASK = 15
};
} // namespace RISCVII

namespace RISCVOp {
enum OperandType : unsigned {
  OPERAND_FIRST_RISCV_IMM = MCOI::OPERAND_FIRST_TARGET,
  OPERAND_UIMM2 = OPERAND_FIRST_RISCV_IMM,
  OPERAND_UIMM3,
  OPERAND_UIMM4,
  OPERAND_UIMM5,
  OPERAND_UIMM7,
  OPERAND_UIMM12,
  OPERAND_SIMM12,
  OPERAND_UIMM20,
  OPERAND_UIMMLOG2XLEN,
  OPERAND_LAST_RISCV_IMM = OPERAND_UIMMLOG2XLEN,
  // Operand is either a register or uimm5, this is used by V extension pseudo
  // instructions to represent a value that be passed as AVL to either vsetvli
  // or vsetivli.
  OPERAND_AVL,
};
} // namespace RISCVOp

// Describes the predecessor/successor bits used in the FENCE instruction.
namespace RISCVFenceField {
enum FenceField {
  I = 8,
  O = 4,
  R = 2,
  W = 1
};
}

// Describes the supported floating point rounding mode encodings.
namespace RISCVFPRndMode {
enum RoundingMode {
  RNE = 0,
  RTZ = 1,
  RDN = 2,
  RUP = 3,
  RMM = 4,
  DYN = 7,
  Invalid
};

inline static StringRef roundingModeToString(RoundingMode RndMode) {
  switch (RndMode) {
  default:
    llvm_unreachable("Unknown floating point rounding mode");
  case RISCVFPRndMode::RNE:
    return "rne";
  case RISCVFPRndMode::RTZ:
    return "rtz";
  case RISCVFPRndMode::RDN:
    return "rdn";
  case RISCVFPRndMode::RUP:
    return "rup";
  case RISCVFPRndMode::RMM:
    return "rmm";
  case RISCVFPRndMode::DYN:
    return "dyn";
  }
}

inline static RoundingMode stringToRoundingMode(StringRef Str) {
  return StringSwitch<RoundingMode>(Str)
      .Case("rne", RISCVFPRndMode::RNE)
      .Case("rtz", RISCVFPRndMode::RTZ)
      .Case("rdn", RISCVFPRndMode::RDN)
      .Case("rup", RISCVFPRndMode::RUP)
      .Case("rmm", RISCVFPRndMode::RMM)
      .Case("dyn", RISCVFPRndMode::DYN)
      .Default(RISCVFPRndMode::Invalid);
}

inline static bool isValidRoundingMode(unsigned Mode) {
  switch (Mode) {
  default:
    return false;
  case RISCVFPRndMode::RNE:
  case RISCVFPRndMode::RTZ:
  case RISCVFPRndMode::RDN:
  case RISCVFPRndMode::RUP:
  case RISCVFPRndMode::RMM:
  case RISCVFPRndMode::DYN:
    return true;
  }
}
} // namespace RISCVFPRndMode

namespace RISCVSysReg {
struct SysReg {
  const char *Name;
  const char *AltName;
  const char *DeprecatedName;
  unsigned Encoding;
  // FIXME: add these additional fields when needed.
  // Privilege Access: Read, Write, Read-Only.
  // unsigned ReadWrite;
  // Privilege Mode: User, System or Machine.
  // unsigned Mode;
  // Check field name.
  // unsigned Extra;
  // Register number without the privilege bits.
  // unsigned Number;
  FeatureBitset FeaturesRequired;
  bool isRV32Only;

  bool haveRequiredFeatures(const FeatureBitset &ActiveFeatures) const {
    // Not in 32-bit mode.
    if (isRV32Only && ActiveFeatures[RISCV::Feature64Bit])
      return false;
    // No required feature associated with the system register.
    if (FeaturesRequired.none())
      return true;
    return (FeaturesRequired & ActiveFeatures) == FeaturesRequired;
  }
};

#define GET_SysRegsList_DECL
#include "RISCVGenSearchableTables.inc"
} // end namespace RISCVSysReg

namespace RISCVABI {

enum ABI {
  ABI_ILP32,
  ABI_ILP32F,
  ABI_ILP32D,
  ABI_ILP32E,
  ABI_LP64,
  ABI_LP64F,
  ABI_LP64D,
  ABI_Unknown
};

// Returns the target ABI, or else a StringError if the requested ABIName is
// not supported for the given TT and FeatureBits combination.
ABI computeTargetABI(const Triple &TT, FeatureBitset FeatureBits,
                     StringRef ABIName);

ABI getTargetABI(StringRef ABIName);

// Returns the register used to hold the stack pointer after realignment.
MCRegister getBPReg();

// Returns the register holding shadow call stack pointer.
MCRegister getSCSPReg();

} // namespace RISCVABI

namespace RISCVFeatures {

// Validates if the given combination of features are valid for the target
// triple. Exits with report_fatal_error if not.
void validate(const Triple &TT, const FeatureBitset &FeatureBits);

// Convert FeatureBitset to FeatureVector.
void toFeatureVector(std::vector<std::string> &FeatureVector,
                     const FeatureBitset &FeatureBits);

} // namespace RISCVFeatures

namespace RISCVVType {
// Is this a SEW value that can be encoded into the VTYPE format.
inline static bool isValidSEW(unsigned SEW) {
  return isPowerOf2_32(SEW) && SEW >= 8 && SEW <= 1024;
}

// Is this a LMUL value that can be encoded into the VTYPE format.
inline static bool isValidLMUL(unsigned LMUL, bool Fractional) {
  return isPowerOf2_32(LMUL) && LMUL <= 8 && (!Fractional || LMUL != 1);
}

unsigned encodeVTYPE(RISCVII::VLMUL VLMUL, unsigned SEW, bool TailAgnostic,
                     bool MaskAgnostic);

inline static RISCVII::VLMUL getVLMUL(unsigned VType) {
  unsigned VLMUL = VType & 0x7;
  return static_cast<RISCVII::VLMUL>(VLMUL);
}

// Decode VLMUL into 1,2,4,8 and fractional indicator.
std::pair<unsigned, bool> decodeVLMUL(RISCVII::VLMUL VLMUL);

inline static unsigned decodeVSEW(unsigned VSEW) {
  assert(VSEW < 8 && "Unexpected VSEW value");
  return 1 << (VSEW + 3);
}

inline static unsigned getSEW(unsigned VType) {
  unsigned VSEW = (VType >> 3) & 0x7;
  return decodeVSEW(VSEW);
}

inline static bool isTailAgnostic(unsigned VType) { return VType & 0x40; }

inline static bool isMaskAgnostic(unsigned VType) { return VType & 0x80; }

void printVType(unsigned VType, raw_ostream &OS);

} // namespace RISCVVType

namespace RISCVZCE {
enum class SLISTENCODE {
  RA = 0,
  RA_S0,
  RA_S0_S1,
  RA_S0_S2,
  RA_S0_S3,
  RA_S0_S4,
  RA_S0_S5,
  RA_S0_S6,
  RA_S0_S7,
  RA_S0_S8,
  RA_S0_S9,
  RA_S0_S10,
  RA_S0_S11,
  RA_S0_S2_E,
  RA_S0_S3_E,
  RA_S0_S4_E,
};

enum class SLIST16ENCODE {
  RA = 0,
  RA_S0,
  RA_S0_S1,
  RA_S0_S2,
  RA_S0_S3,
  RA_S0_S5,
  RA_S0_S7,
  RA_S0_S11
};

enum class RLIST3ENCODE {
  NO_MATCH = -1,
  RA = 0,
  RA_S0,
  RA_S0_S1,
  RA_S0_S2,
  RA_S0_S3,
  RA_S0_S5,
  RA_S0_S7,
  RA_S0_S11
};

enum class RLIST2ENCODE {
  NO_MATCH = -1,
  RA_S0_S2 = 0,
  RA_S0_S3,
  RA_S0_S4,
  RA,
  RA_S0,
  RA_S0_S1,
};

enum class SPIMMINST {
  PUSH,
  PUSH_E,
  POP,
  POP_E,
  POPRET,
  POPRET_E,
  C_POPRET,
  C_POP,
  C_PUSH,
  C_POPRET_E,
  C_POP_E,
  C_PUSH_E
};

enum class BINARYVALUE_OF_SPIMM {
  B000 = 0,
  B001,
  B010,
  B011,
  B100,
  B101
};

// Encode slist, the EndReg is the end of the register of the slist,
//
#define ENDREG_TO_ENCODE(ENDREG, ENCODE) \
case RISCV::X##ENDREG:                 \
  return SLISTENCODE::ENCODE;
inline static SLISTENCODE encodeSlist(MCRegister EndReg,bool isRV32E) {
  if (isRV32E)
  {
    switch (EndReg) {
    default:
      break;
    ENDREG_TO_ENCODE(18, RA_S0_S2_E)
    ENDREG_TO_ENCODE(19, RA_S0_S3_E)
    ENDREG_TO_ENCODE(20, RA_S0_S4_E)
    }
  }
  
  switch (EndReg) {
  default:
    llvm_unreachable("Unexpected register");
  ENDREG_TO_ENCODE(8, RA_S0)
  ENDREG_TO_ENCODE(9, RA_S0_S1)
  ENDREG_TO_ENCODE(18, RA_S0_S2)
  ENDREG_TO_ENCODE(19, RA_S0_S3)
  ENDREG_TO_ENCODE(20, RA_S0_S4)
  ENDREG_TO_ENCODE(21, RA_S0_S5)
  ENDREG_TO_ENCODE(22, RA_S0_S6)
  ENDREG_TO_ENCODE(23, RA_S0_S7)
  ENDREG_TO_ENCODE(24, RA_S0_S8)
  ENDREG_TO_ENCODE(25, RA_S0_S9)
  ENDREG_TO_ENCODE(26, RA_S0_S10)
  ENDREG_TO_ENCODE(27, RA_S0_S11)
  case RISCV::NoRegister:
    return SLISTENCODE::RA;
  }
}

inline static RLIST2ENCODE encodeRlist2(MCRegister EndReg) {                      
  switch (EndReg) {
  default: 
    return RLIST2ENCODE::NO_MATCH;
  case RISCV::X18:
    return RLIST2ENCODE::RA_S0_S2;
  case RISCV::X19:
    return RLIST2ENCODE::RA_S0_S3;
  case RISCV::X20:
    return RLIST2ENCODE::RA_S0_S4;
  case RISCV::X1:
    return RLIST2ENCODE::RA;
  case RISCV::X8:
    return RLIST2ENCODE::RA_S0;
  case RISCV::X9:
    return RLIST2ENCODE::RA_S0_S1;
  }
}

inline static RLIST3ENCODE encodeRlist3(MCRegister EndReg) {                      
  switch (EndReg) {
  default: 
    return RLIST3ENCODE::NO_MATCH;
  case RISCV::X1:
    return RLIST3ENCODE::RA;
  case RISCV::X8:
    return RLIST3ENCODE::RA_S0;
  case RISCV::X9:
    return RLIST3ENCODE::RA_S0_S1;
  case RISCV::X18:
    return RLIST3ENCODE::RA_S0_S2;
  case RISCV::X19:
    return RLIST3ENCODE::RA_S0_S3;
  case RISCV::X21:
    return RLIST3ENCODE::RA_S0_S5;
  case RISCV::X23:
    return RLIST3ENCODE::RA_S0_S7;
  case RISCV::X27:
    return RLIST3ENCODE::RA_S0_S11;
  case RISCV::NoRegister:
    return RLIST3ENCODE::RA;
  }
}

inline static signed encodeRlist(MCRegister EndReg, bool isRV32E) {                      
  if(isRV32E)
    return (signed)encodeRlist2(EndReg);
  else
    return (signed)encodeRlist3(EndReg);
}
#undef ENDREG_TO_ENCODE

inline static bool isValidAlist(MCRegister EndReg, unsigned SlistEncode) {
  switch (static_cast<SLISTENCODE>(SlistEncode)) {
    case SLISTENCODE::RA:
      return EndReg == RISCV::NoRegister;
    case SLISTENCODE::RA_S0:
      return EndReg == RISCV::X10;
    case SLISTENCODE::RA_S0_S1:
      return EndReg == RISCV::X11;
    case SLISTENCODE::RA_S0_S2:
    case SLISTENCODE::RA_S0_S2_E:
      return EndReg == RISCV::X12;
    case SLISTENCODE::RA_S0_S3:
    case SLISTENCODE::RA_S0_S4:
    case SLISTENCODE::RA_S0_S5:
    case SLISTENCODE::RA_S0_S6:
    case SLISTENCODE::RA_S0_S7:
    case SLISTENCODE::RA_S0_S8:
    case SLISTENCODE::RA_S0_S9:
    case SLISTENCODE::RA_S0_S10:
    case SLISTENCODE::RA_S0_S11:
    case SLISTENCODE::RA_S0_S3_E:
    case SLISTENCODE::RA_S0_S4_E:
      return EndReg == RISCV::X13;
    default:
      llvm_unreachable("Unexpected slist encode!");
  }
}

inline static bool isValidAlist16(MCRegister EndReg, unsigned Slist16Encode, bool isRlist2) {
  if (isRlist2){
    switch (static_cast<RLIST2ENCODE>(Slist16Encode)) {
    case RLIST2ENCODE::RA_S0_S2:
      return EndReg == RISCV::X12;
    case RLIST2ENCODE::RA_S0_S3:
    case RLIST2ENCODE::RA_S0_S4:
      return EndReg == RISCV::X13;
    case RLIST2ENCODE::RA:
      return EndReg == RISCV::NoRegister;
    case RLIST2ENCODE::RA_S0:
      return EndReg == RISCV::X10;
    case RLIST2ENCODE::RA_S0_S1:
      return EndReg == RISCV::X11;
    default:
      return false;
    }
  }
  switch (static_cast<RLIST3ENCODE>(Slist16Encode)) {
    case RLIST3ENCODE::RA:
      return EndReg == RISCV::NoRegister;
    case RLIST3ENCODE::RA_S0:
      return EndReg == RISCV::X10;
    case RLIST3ENCODE::RA_S0_S1:
      return EndReg == RISCV::X11;
    case RLIST3ENCODE::RA_S0_S2:
      return EndReg == RISCV::X12;
    case RLIST3ENCODE::RA_S0_S3:
    case RLIST3ENCODE::RA_S0_S5:
    case RLIST3ENCODE::RA_S0_S7:
    case RLIST3ENCODE::RA_S0_S11:
      return EndReg == RISCV::X13;
    default:
      llvm_unreachable("Unexpected slist encode!");
  }
}

#define ENCODE_SPIMM(MAX_SPIMM,VAL,VAL64) \
spimmVal = (stackAdjustment - (isRV64 ? VAL64 : VAL)) / 16; \
if ((isRV64 && VAL64 == 0)||(!isRV64 && VAL == 0)||spimmVal > MAX_SPIMM) \
  return false;

inline static bool getSpimm(SPIMMINST Inst, unsigned rlistVal, unsigned &spimmVal, int64_t stackAdjustment, bool isRV64) {
  if(Inst >= SPIMMINST::C_POPRET_E){  // use rlist
    RLIST2ENCODE rlist = (RLIST2ENCODE)rlistVal;
    if(Inst == SPIMMINST::C_PUSH_E || Inst == SPIMMINST::C_POPRET_E){
      switch (rlist)
      {
      case RLIST2ENCODE::RA_S0_S2:
        ENCODE_SPIMM(5,16,0)
        return true;
      case RLIST2ENCODE::RA_S0_S3:
      case RLIST2ENCODE::RA_S0_S4:
        ENCODE_SPIMM(5,32,0)
        return true;
      case RLIST2ENCODE::RA:
      case RLIST2ENCODE::RA_S0:
      case RLIST2ENCODE::RA_S0_S1:
        ENCODE_SPIMM(5,16,0)
        return true;
      default:
        return false;
      }
    }
    else if (Inst == SPIMMINST::C_POP_E){
      switch (rlist)
      {
      case RLIST2ENCODE::RA_S0_S2:
        ENCODE_SPIMM(5,16,0)
        return true;
      case RLIST2ENCODE::RA_S0_S3:
        ENCODE_SPIMM(5,32,0)
        return true;
      case RLIST2ENCODE::RA:
      case RLIST2ENCODE::RA_S0:
      case RLIST2ENCODE::RA_S0_S1:
        ENCODE_SPIMM(1,16,0)
        return true;
      default:
        return false;
      }
    }
  }
  RLIST3ENCODE rlist = (RLIST3ENCODE)rlistVal;
  SLISTENCODE slist = (SLISTENCODE)rlistVal;
  if (Inst == SPIMMINST::PUSH || Inst == SPIMMINST::PUSH_E ||
      Inst == SPIMMINST::POP || Inst == SPIMMINST::POP_E ||
      Inst == SPIMMINST::POPRET || Inst == SPIMMINST::POPRET_E){
    switch (slist)
    {
    case SLISTENCODE::RA:
    case SLISTENCODE::RA_S0:
      ENCODE_SPIMM(31,16,16)
      return true;
    case SLISTENCODE::RA_S0_S1:
    case SLISTENCODE::RA_S0_S2:
    case SLISTENCODE::RA_S0_S2_E:
      ENCODE_SPIMM(31,16,32)
      return true;
    case SLISTENCODE::RA_S0_S3:
    case SLISTENCODE::RA_S0_S4:
    case SLISTENCODE::RA_S0_S3_E:
    case SLISTENCODE::RA_S0_S4_E:
      ENCODE_SPIMM(31,32,48)
      return true;
    case SLISTENCODE::RA_S0_S5:
    case SLISTENCODE::RA_S0_S6:
      ENCODE_SPIMM(31,32,64)
      return true;
    case SLISTENCODE::RA_S0_S7:
    case SLISTENCODE::RA_S0_S8:
      ENCODE_SPIMM(31,48,80)
      return true;
    case SLISTENCODE::RA_S0_S9:
    case SLISTENCODE::RA_S0_S10:
      ENCODE_SPIMM(31,48,96)
      return true;
    case SLISTENCODE::RA_S0_S11:
      ENCODE_SPIMM(31,64,112)
      return true;
    default:
      return false;
    }
  }
  else if(Inst == SPIMMINST::C_POPRET)
  {
    switch (rlist)
    {
    case RLIST3ENCODE::RA:
    case RLIST3ENCODE::RA_S0:
      ENCODE_SPIMM(5,16,16)
      return true;
    case RLIST3ENCODE::RA_S0_S1:
    case RLIST3ENCODE::RA_S0_S2:
      ENCODE_SPIMM(5,16,32)
      return true;
    case RLIST3ENCODE::RA_S0_S3:
      ENCODE_SPIMM(5,32,48)
      return true;
    case RLIST3ENCODE::RA_S0_S5:
      ENCODE_SPIMM(5,32,64)
      return true;
    case RLIST3ENCODE::RA_S0_S7:
      ENCODE_SPIMM(5,48,80)
      return true;
    case RLIST3ENCODE::RA_S0_S11:
      ENCODE_SPIMM(5,64,112)
      return true;
    default:
      return false;
    }
  }
  else if(Inst == SPIMMINST::C_PUSH)
  {
    switch (rlist)
    {
    case RLIST3ENCODE::RA:
    case RLIST3ENCODE::RA_S0:
      ENCODE_SPIMM(5,16,16)
      return true;
    case RLIST3ENCODE::RA_S0_S1:
    case RLIST3ENCODE::RA_S0_S2:
      ENCODE_SPIMM(5,16,32)
      return true;
    case RLIST3ENCODE::RA_S0_S3:
      ENCODE_SPIMM(5,32,48)
      return true;
    case RLIST3ENCODE::RA_S0_S5:
      ENCODE_SPIMM(5,32,64)
      return true;
    case RLIST3ENCODE::RA_S0_S7:
      ENCODE_SPIMM(5,48,80)
      return true;
    case RLIST3ENCODE::RA_S0_S11:
      ENCODE_SPIMM(5,64,112)
      return true;
    default:
      return false;
    }
  }
  else if(Inst == SPIMMINST::C_POP)
  {
    switch (rlist)
    {
    case RLIST3ENCODE::RA:
    case RLIST3ENCODE::RA_S0:
      ENCODE_SPIMM(1,16,16)
      return true;
    case RLIST3ENCODE::RA_S0_S1:
    case RLIST3ENCODE::RA_S0_S2:
      ENCODE_SPIMM(1,16,32)
      return true;
    case RLIST3ENCODE::RA_S0_S3:
      ENCODE_SPIMM(1,32,48)
      return true;
    case RLIST3ENCODE::RA_S0_S5:
      ENCODE_SPIMM(1,32,64)
      return true;
    case RLIST3ENCODE::RA_S0_S7:
      ENCODE_SPIMM(1,48,80)
      return true;
    case RLIST3ENCODE::RA_S0_S11:
      ENCODE_SPIMM(1,64,112)
      return true;
    default:
      return false;
    }
  }
  else {
    return false;
  }
}

inline static unsigned encodeAlist(MCRegister EndReg, unsigned SlistEncode) {
  return (SlistEncode != 0 && EndReg == RISCV::NoRegister) ? 0 : 1;
}

inline static unsigned encodeRetval(int Retval) {
  return Retval == -1 ? 3 : (Retval + 1);
}

inline static RISCVZCE::RLIST3ENCODE convertRlist2ToRlist3(RISCVZCE::RLIST2ENCODE rlist2) {
  switch ((RISCVZCE::RLIST2ENCODE)rlist2)
  {
  case RISCVZCE::RLIST2ENCODE::RA:
    return RISCVZCE::RLIST3ENCODE::RA;
    break;
  case RISCVZCE::RLIST2ENCODE::RA_S0:
    return RISCVZCE::RLIST3ENCODE::RA_S0;
    break;
  case RISCVZCE::RLIST2ENCODE::RA_S0_S1:
    return RISCVZCE::RLIST3ENCODE::RA_S0_S1;
    break;
  default:
    return RISCVZCE::RLIST3ENCODE::NO_MATCH;
    break;
  }
}

void printAlist(unsigned opcode, unsigned SlistEncode, raw_ostream &OS);
void printSlist(unsigned SlistEncode, raw_ostream &OS);
void printRetval(unsigned RetvalEncode, raw_ostream &OS);
void printSlist16(unsigned RlistEncode, raw_ostream &OS);
void printRlist3(unsigned RlistEncode, raw_ostream &OS);
void printRlist2(unsigned RlistEncode, raw_ostream &OS);
void printSpimm(int64_t Spimm, raw_ostream &OS);

}

} // namespace llvm

#endif

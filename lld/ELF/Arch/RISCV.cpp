//===- RISCV.cpp ----------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "InputFiles.h"
#include "OutputSections.h"
#include "Symbols.h"
#include "SyntheticSections.h"
#include "Target.h"
#include "llvm/Support/MathExtras.h"

using namespace llvm;
using namespace llvm::object;
using namespace llvm::support::endian;
using namespace llvm::ELF;
using namespace lld;
using namespace lld::elf;

namespace {

class RISCV final : public TargetInfo {
public:
  RISCV();
  uint32_t calcEFlags() const override;
  int64_t getImplicitAddend(const uint8_t *buf, RelType type) const override;
  void writeGotHeader(uint8_t *buf) const override;
  void writeGotPlt(uint8_t *buf, const Symbol &s) const override;
  void writeIgotPlt(uint8_t *buf, const Symbol &s) const override;
  void writePltHeader(uint8_t *buf) const override;
  void writePlt(uint8_t *buf, const Symbol &sym,
                uint64_t pltEntryAddr) const override;
  RelType getDynRel(RelType type) const override;
  RelExpr getRelExpr(RelType type, const Symbol &s,
                     const uint8_t *loc) const override;
  void relocate(uint8_t *loc, const Relocation &rel,
                uint64_t val) const override;
  void finalizeSections() const override;
};

} // end anonymous namespace

const uint64_t dtpOffset = 0x800;

enum Op {
  ADDI = 0x13,
  AUIPC = 0x17,
  JALR = 0x67,
  LD = 0x3003,
  LW = 0x2003,
  SRLI = 0x5013,
  SUB = 0x40000033,
};

enum Reg {
  X_RA = 1,
  X_GP = 3,
  X_T0 = 5,
  X_T1 = 6,
  X_T2 = 7,
  X_T3 = 28,
};

static uint32_t hi20(uint32_t val) { return (val + 0x800) >> 12; }
static uint32_t lo12(uint32_t val) { return val & 4095; }

static uint32_t itype(uint32_t op, uint32_t rd, uint32_t rs1, uint32_t imm) {
  return op | (rd << 7) | (rs1 << 15) | (imm << 20);
}
static uint32_t rtype(uint32_t op, uint32_t rd, uint32_t rs1, uint32_t rs2) {
  return op | (rd << 7) | (rs1 << 15) | (rs2 << 20);
}
static uint32_t utype(uint32_t op, uint32_t rd, uint32_t imm) {
  return op | (rd << 7) | (imm << 12);
}

RISCV::RISCV() {
  copyRel = R_RISCV_COPY;
  pltRel = R_RISCV_JUMP_SLOT;
  relativeRel = R_RISCV_RELATIVE;
  iRelativeRel = R_RISCV_IRELATIVE;
  if (config->is64) {
    symbolicRel = R_RISCV_64;
    tlsModuleIndexRel = R_RISCV_TLS_DTPMOD64;
    tlsOffsetRel = R_RISCV_TLS_DTPREL64;
    tlsGotRel = R_RISCV_TLS_TPREL64;
  } else {
    symbolicRel = R_RISCV_32;
    tlsModuleIndexRel = R_RISCV_TLS_DTPMOD32;
    tlsOffsetRel = R_RISCV_TLS_DTPREL32;
    tlsGotRel = R_RISCV_TLS_TPREL32;
  }
  gotRel = symbolicRel;

  // .got[0] = _DYNAMIC
  gotHeaderEntriesNum = 1;

  // .got.plt[0] = _dl_runtime_resolve, .got.plt[1] = link_map
  gotPltHeaderEntriesNum = 2;

  pltHeaderSize = 32;
  pltEntrySize = 16;
  ipltEntrySize = 16;
}

static uint32_t getEFlags(InputFile *f) {
  if (config->is64)
    return cast<ObjFile<ELF64LE>>(f)->getObj().getHeader().e_flags;
  return cast<ObjFile<ELF32LE>>(f)->getObj().getHeader().e_flags;
}

uint32_t RISCV::calcEFlags() const {
  // If there are only binary input files (from -b binary), use a
  // value of 0 for the ELF header flags.
  if (objectFiles.empty())
    return 0;

  uint32_t target = getEFlags(objectFiles.front());

  for (InputFile *f : objectFiles) {
    uint32_t eflags = getEFlags(f);
    if (eflags & EF_RISCV_RVC)
      target |= EF_RISCV_RVC;

    if ((eflags & EF_RISCV_FLOAT_ABI) != (target & EF_RISCV_FLOAT_ABI))
      error(toString(f) +
            ": cannot link object files with different floating-point ABI");

    if ((eflags & EF_RISCV_RVE) != (target & EF_RISCV_RVE))
      error(toString(f) +
            ": cannot link object files with different EF_RISCV_RVE");
  }

  return target;
}

int64_t RISCV::getImplicitAddend(const uint8_t *buf, RelType type) const {
  switch (type) {
  default:
    internalLinkerError(getErrorLocation(buf),
                        "cannot read addend for relocation " + toString(type));
    return 0;
  case R_RISCV_32:
  case R_RISCV_TLS_DTPMOD32:
  case R_RISCV_TLS_DTPREL32:
    return SignExtend64<32>(read32le(buf));
  case R_RISCV_64:
    return read64le(buf);
  case R_RISCV_RELATIVE:
  case R_RISCV_IRELATIVE:
    return config->is64 ? read64le(buf) : read32le(buf);
  case R_RISCV_NONE:
  case R_RISCV_JUMP_SLOT:
    // These relocations are defined as not having an implicit addend.
    return 0;
  }
}

void RISCV::writeGotHeader(uint8_t *buf) const {
  if (config->is64)
    write64le(buf, mainPart->dynamic->getVA());
  else
    write32le(buf, mainPart->dynamic->getVA());
}

void RISCV::writeGotPlt(uint8_t *buf, const Symbol &s) const {
  if (config->is64)
    write64le(buf, in.plt->getVA());
  else
    write32le(buf, in.plt->getVA());
}

void RISCV::writeIgotPlt(uint8_t *buf, const Symbol &s) const {
  if (config->writeAddends) {
    if (config->is64)
      write64le(buf, s.getVA());
    else
      write32le(buf, s.getVA());
  }
}

void RISCV::writePltHeader(uint8_t *buf) const {
  // 1: auipc t2, %pcrel_hi(.got.plt)
  // sub t1, t1, t3
  // l[wd] t3, %pcrel_lo(1b)(t2); t3 = _dl_runtime_resolve
  // addi t1, t1, -pltHeaderSize-12; t1 = &.plt[i] - &.plt[0]
  // addi t0, t2, %pcrel_lo(1b)
  // srli t1, t1, (rv64?1:2); t1 = &.got.plt[i] - &.got.plt[0]
  // l[wd] t0, Wordsize(t0); t0 = link_map
  // jr t3
  uint32_t offset = in.gotPlt->getVA() - in.plt->getVA();
  uint32_t load = config->is64 ? LD : LW;
  write32le(buf + 0, utype(AUIPC, X_T2, hi20(offset)));
  write32le(buf + 4, rtype(SUB, X_T1, X_T1, X_T3));
  write32le(buf + 8, itype(load, X_T3, X_T2, lo12(offset)));
  write32le(buf + 12, itype(ADDI, X_T1, X_T1, -target->pltHeaderSize - 12));
  write32le(buf + 16, itype(ADDI, X_T0, X_T2, lo12(offset)));
  write32le(buf + 20, itype(SRLI, X_T1, X_T1, config->is64 ? 1 : 2));
  write32le(buf + 24, itype(load, X_T0, X_T0, config->wordsize));
  write32le(buf + 28, itype(JALR, 0, X_T3, 0));
}

void RISCV::writePlt(uint8_t *buf, const Symbol &sym,
                     uint64_t pltEntryAddr) const {
  // 1: auipc t3, %pcrel_hi(f@.got.plt)
  // l[wd] t3, %pcrel_lo(1b)(t3)
  // jalr t1, t3
  // nop
  uint32_t offset = sym.getGotPltVA() - pltEntryAddr;
  write32le(buf + 0, utype(AUIPC, X_T3, hi20(offset)));
  write32le(buf + 4, itype(config->is64 ? LD : LW, X_T3, X_T3, lo12(offset)));
  write32le(buf + 8, itype(JALR, X_T1, X_T3, 0));
  write32le(buf + 12, itype(ADDI, 0, 0, 0));
}

RelType RISCV::getDynRel(RelType type) const {
  return type == target->symbolicRel ? type
                                     : static_cast<RelType>(R_RISCV_NONE);
}

RelExpr RISCV::getRelExpr(const RelType type, const Symbol &s,
                          const uint8_t *loc) const {
  switch (type) {
  case R_RISCV_NONE:
    return R_NONE;
  case R_RISCV_32:
  case R_RISCV_64:
  case R_RISCV_HI20:
  case R_RISCV_LO12_I:
  case R_RISCV_LO12_S:
  case R_RISCV_RVC_LUI:
    return R_ABS;
  case R_RISCV_ADD8:
  case R_RISCV_ADD16:
  case R_RISCV_ADD32:
  case R_RISCV_ADD64:
  case R_RISCV_SET6:
  case R_RISCV_SET8:
  case R_RISCV_SET16:
  case R_RISCV_SET32:
  case R_RISCV_SUB6:
  case R_RISCV_SUB8:
  case R_RISCV_SUB16:
  case R_RISCV_SUB32:
  case R_RISCV_SUB64:
    return R_RISCV_ADD;
  case R_RISCV_JAL:
  case R_RISCV_BRANCH:
  case R_RISCV_PCREL_HI20:
  case R_RISCV_RVC_BRANCH:
  case R_RISCV_RVC_JUMP:
  case R_RISCV_32_PCREL:
    return R_PC;
  case R_RISCV_CALL:
  case R_RISCV_CALL_PLT:
    return R_PLT_PC;
  case R_RISCV_GOT_HI20:
    return R_GOT_PC;
  case R_RISCV_PCREL_LO12_I:
  case R_RISCV_PCREL_LO12_S:
    return R_RISCV_PC_INDIRECT;
  case R_RISCV_TLS_GD_HI20:
    return R_TLSGD_PC;
  case R_RISCV_TLS_GOT_HI20:
    config->hasTlsIe = true;
    return R_GOT_PC;
  case R_RISCV_TPREL_HI20:
  case R_RISCV_TPREL_LO12_I:
  case R_RISCV_TPREL_LO12_S:
    return R_TPREL;
  case R_RISCV_GPREL_I:
  case R_RISCV_GPREL_S:
  case R_RISCV_GPREL_ZCE_LWGP:
  case R_RISCV_GPREL_ZCE_SWGP:
  case R_RISCV_GPREL_ZCE_LDGP:
  case R_RISCV_GPREL_ZCE_SDGP:
    return R_RISCV_GPREL;
  case R_RISCV_TPREL_ADD:
    return R_NONE;
  case R_RISCV_RELAX:
  case R_RISCV_ALIGN:
    return R_RELAX_HINT;
  default:
    error(getErrorLocation(loc) + "unknown relocation (" + Twine(type) +
          ") against symbol " + toString(s));
    return R_NONE;
  }
}

// Extract bits V[Begin:End], where range is inclusive, and Begin must be < 63.
static uint32_t extractBits(uint64_t v, uint32_t begin, uint32_t end) {
  return (v & ((1ULL << (begin + 1)) - 1)) >> end;
}

void RISCV::relocate(uint8_t *loc, const Relocation &rel, uint64_t val) const {
  const unsigned bits = config->wordsize * 8;

  switch (rel.type) {
  case R_RISCV_32:
    write32le(loc, val);
    return;
  case R_RISCV_64:
    write64le(loc, val);
    return;

  case R_RISCV_RVC_BRANCH: {
    checkInt(loc, static_cast<int64_t>(val) >> 1, 8, rel);
    checkAlignment(loc, val, 2, rel);
    uint16_t insn = read16le(loc) & 0xE383;
    uint16_t imm8 = extractBits(val, 8, 8) << 12;
    uint16_t imm4_3 = extractBits(val, 4, 3) << 10;
    uint16_t imm7_6 = extractBits(val, 7, 6) << 5;
    uint16_t imm2_1 = extractBits(val, 2, 1) << 3;
    uint16_t imm5 = extractBits(val, 5, 5) << 2;
    insn |= imm8 | imm4_3 | imm7_6 | imm2_1 | imm5;

    write16le(loc, insn);
    return;
  }

  case R_RISCV_RVC_JUMP: {
    checkInt(loc, static_cast<int64_t>(val) >> 1, 11, rel);
    checkAlignment(loc, val, 2, rel);
    uint16_t insn = read16le(loc) & 0xE003;
    uint16_t imm11 = extractBits(val, 11, 11) << 12;
    uint16_t imm4 = extractBits(val, 4, 4) << 11;
    uint16_t imm9_8 = extractBits(val, 9, 8) << 9;
    uint16_t imm10 = extractBits(val, 10, 10) << 8;
    uint16_t imm6 = extractBits(val, 6, 6) << 7;
    uint16_t imm7 = extractBits(val, 7, 7) << 6;
    uint16_t imm3_1 = extractBits(val, 3, 1) << 3;
    uint16_t imm5 = extractBits(val, 5, 5) << 2;
    insn |= imm11 | imm4 | imm9_8 | imm10 | imm6 | imm7 | imm3_1 | imm5;

    write16le(loc, insn);
    return;
  }

  case R_RISCV_RVC_LUI: {
    int64_t imm = SignExtend64(val + 0x800, bits) >> 12;
    checkInt(loc, imm, 6, rel);
    if (imm == 0) { // `c.lui rd, 0` is illegal, convert to `c.li rd, 0`
      write16le(loc, (read16le(loc) & 0x0F83) | 0x4000);
    } else {
      uint16_t imm17 = extractBits(val + 0x800, 17, 17) << 12;
      uint16_t imm16_12 = extractBits(val + 0x800, 16, 12) << 2;
      write16le(loc, (read16le(loc) & 0xEF83) | imm17 | imm16_12);
    }
    return;
  }

  case R_RISCV_JAL: {
    checkInt(loc, static_cast<int64_t>(val) >> 1, 20, rel);
    checkAlignment(loc, val, 2, rel);

    uint32_t insn = read32le(loc) & 0xFFF;
    uint32_t imm20 = extractBits(val, 20, 20) << 31;
    uint32_t imm10_1 = extractBits(val, 10, 1) << 21;
    uint32_t imm11 = extractBits(val, 11, 11) << 20;
    uint32_t imm19_12 = extractBits(val, 19, 12) << 12;
    insn |= imm20 | imm10_1 | imm11 | imm19_12;

    write32le(loc, insn);
    return;
  }

  case R_RISCV_BRANCH: {
    checkInt(loc, static_cast<int64_t>(val) >> 1, 12, rel);
    checkAlignment(loc, val, 2, rel);

    uint32_t insn = read32le(loc) & 0x1FFF07F;
    uint32_t imm12 = extractBits(val, 12, 12) << 31;
    uint32_t imm10_5 = extractBits(val, 10, 5) << 25;
    uint32_t imm4_1 = extractBits(val, 4, 1) << 8;
    uint32_t imm11 = extractBits(val, 11, 11) << 7;
    insn |= imm12 | imm10_5 | imm4_1 | imm11;

    write32le(loc, insn);
    return;
  }

  // auipc + jalr pair
  case R_RISCV_CALL:
  case R_RISCV_CALL_PLT: {
    int64_t hi = SignExtend64(val + 0x800, bits) >> 12;
    checkInt(loc, hi, 20, rel);
    if (isInt<20>(hi)) {
      relocateNoSym(loc, R_RISCV_PCREL_HI20, val);
      relocateNoSym(loc + 4, R_RISCV_PCREL_LO12_I, val);
    }
    return;
  }

  case R_RISCV_GOT_HI20:
  case R_RISCV_PCREL_HI20:
  case R_RISCV_TLS_GD_HI20:
  case R_RISCV_TLS_GOT_HI20:
  case R_RISCV_TPREL_HI20:
  case R_RISCV_HI20: {
    uint64_t hi = val + 0x800;
    checkInt(loc, SignExtend64(hi, bits) >> 12, 20, rel);
    write32le(loc, (read32le(loc) & 0xFFF) | (hi & 0xFFFFF000));
    return;
  }

  case R_RISCV_PCREL_LO12_I:
  case R_RISCV_TPREL_LO12_I:
  case R_RISCV_GPREL_I:
  case R_RISCV_LO12_I: {
    uint64_t hi = (val + 0x800) >> 12;
    uint64_t lo = val - (hi << 12);
    write32le(loc, (read32le(loc) & 0xFFFFF) | ((lo & 0xFFF) << 20));
    return;
  }

  case R_RISCV_PCREL_LO12_S:
  case R_RISCV_TPREL_LO12_S:
  case R_RISCV_GPREL_S:
  case R_RISCV_LO12_S: {
    uint64_t hi = (val + 0x800) >> 12;
    uint64_t lo = val - (hi << 12);
    uint32_t imm11_5 = extractBits(lo, 11, 5) << 25;
    uint32_t imm4_0 = extractBits(lo, 4, 0) << 7;
    write32le(loc, (read32le(loc) & 0x1FFF07F) | imm11_5 | imm4_0);
    return;
  }

  case R_RISCV_ADD8:
    *loc += val;
    return;
  case R_RISCV_ADD16:
    write16le(loc, read16le(loc) + val);
    return;
  case R_RISCV_ADD32:
    write32le(loc, read32le(loc) + val);
    return;
  case R_RISCV_ADD64:
    write64le(loc, read64le(loc) + val);
    return;
  case R_RISCV_SUB6:
    *loc = (*loc & 0xc0) | (((*loc & 0x3f) - val) & 0x3f);
    return;
  case R_RISCV_SUB8:
    *loc -= val;
    return;
  case R_RISCV_SUB16:
    write16le(loc, read16le(loc) - val);
    return;
  case R_RISCV_SUB32:
    write32le(loc, read32le(loc) - val);
    return;
  case R_RISCV_SUB64:
    write64le(loc, read64le(loc) - val);
    return;
  case R_RISCV_SET6:
    *loc = (*loc & 0xc0) | (val & 0x3f);
    return;
  case R_RISCV_SET8:
    *loc = val;
    return;
  case R_RISCV_SET16:
    write16le(loc, val);
    return;
  case R_RISCV_SET32:
  case R_RISCV_32_PCREL:
    write32le(loc, val);
    return;

  case R_RISCV_TLS_DTPREL32:
    write32le(loc, val - dtpOffset);
    break;
  case R_RISCV_TLS_DTPREL64:
    write64le(loc, val - dtpOffset);
    break;

  case R_RISCV_RELAX:
  case R_RISCV_TPREL_ADD:
    return; // Ignored (for now)
  
  case R_RISCV_GPREL_ZCE_LWGP: {
    bool enableZceLsgp = config->optmizeZceLsgp;

    if(!enableZceLsgp){
      error(getErrorLocation(loc) + "can't relocate  (" + Twine(rel.type) +
          ") check whether you have enable '-mzce-lsgp'");
    }
    else if(isShiftedInt<14,2>(val)){
      unsigned rd = (read32le(loc) & 0x00000fe0) >> 7;

      uint64_t imm8_2 = (val >> 2) & 0x7f;
      uint64_t imm10_9 = (val >> 9) & 0x3;
      uint64_t imm15_11 = (val >> 11) & 0x1f;

      write32le(loc,
              (0x3007 | imm8_2 << 22 | imm10_9 << 20 | imm15_11 << 15 | rd << 7 )); // lwgp rs, val(gp)
      return;
    }
    return;
  }
  case R_RISCV_GPREL_ZCE_SWGP: {
    bool enableZceLsgp = config->optmizeZceLsgp;
    if(!enableZceLsgp){
      error(getErrorLocation(loc) + "can't relocate  (" + Twine(rel.type) +
          ") check whether you have enable '-mzce-lsgp'");
    }
    else if(isShiftedInt<14,2>(val)){
      unsigned rs2 = (read32le(loc) & 0x1F00000) >> 20;

      uint64_t imm4_2 = (val >> 2) & 0x7;
      uint64_t imm8_5 = (val >> 5) & 0xf;
      uint64_t imm10_9 = (val >> 9) & 0x3;
      uint64_t imm15_11 = (val >> 11) & 0x1f;

      write32le(loc,
              (0x3027 | imm8_5 << 25 | rs2 << 20 | imm15_11 << 15 | imm4_2 << 9 | imm10_9 << 7 )); // swgp rs2, val(gp)
      return;
    }
    return;
  }
  case R_RISCV_GPREL_ZCE_LDGP: {
    bool enableZceLsgp = config->optmizeZceLsgp;

    if(!enableZceLsgp){
      error(getErrorLocation(loc) + "can't relocate  (" + Twine(rel.type) +
          ") check whether you have enable '-mzce-lsgp'");
    }
    else if(isShiftedInt<14,3>(val)){
      unsigned rd = (read32le(loc) & 0x00000fe0) >> 7;

      uint64_t imm8_3 = (val >> 3) & 0x3f;
      uint64_t imm10_9 = (val >> 9) & 0x3;
      uint64_t imm15_11 = (val >> 11) & 0x1f;
      uint64_t imm16 = (val >> 16) & 0x1;

      write32le(loc,
              (0x40003007 | imm8_3 << 23 | imm16 << 22 | imm10_9 << 20 | imm15_11 << 15 | rd << 7 )); // ldgp rd, val(gp)
      return;
    }
    return;
  }
  case R_RISCV_GPREL_ZCE_SDGP: {
    bool enableZceLsgp = config->optmizeZceLsgp;
    if(!enableZceLsgp){
      error(getErrorLocation(loc) + "can't relocate  (" + Twine(rel.type) +
          ") check whether you have enable '-mzce-lsgp'");
    }
    else if(isShiftedInt<14,3>(val)){
      unsigned rs2 = (read32le(loc) & 0x1F00000) >> 20;

      uint64_t imm4_3 = (val >> 3) & 0x3;
      uint64_t imm8_5 = (val >> 5) & 0xf;
      uint64_t imm10_9 = (val >> 9) & 0x3;
      uint64_t imm15_11 = (val >> 11) & 0x1f;
      uint64_t imm16 = (val >> 16) & 0x1;

      write32le(loc,
              (0x40003027 | imm8_5 << 25 | rs2 << 20 | imm15_11 << 15 | imm4_3 << 10 | imm16 << 9 | imm10_9 << 7 )); // swgp rs2, val(gp)
      return;
    }
    return;
  }
  default:
    llvm_unreachable("unknown relocation");
    return;
  }
}

static uint64_t maxOutputSectionAlignment() {
  uint64_t maxAlign = 1;
  for (auto *os : outputSections) {
    maxAlign = std::max<uint64_t>(maxAlign, os->alignment);
  }

  return maxAlign;
}

static void setRs1(uint8_t *buf, int rs1) {
  write32le(buf, (read32le(buf) & 0xfff07fff) | rs1 << 15);
}

static int64_t addWorstCaseAlignment(int64_t offset, uint64_t alignment) {
  return offset >= 0 ? offset + alignment : offset - alignment;
}

using DeleteRanges = std::vector<InputSectionBase::DeleteRange>;

static void addDeleteRange(DeleteRanges &ranges, uint64_t offset,
                           uint64_t size) {
  ranges.push_back({offset, size});
}

// Relax R_RISCV_CALL to jal or c.jal.
//
// We always assume during relaxation the symbols can only come closer modulo
// the effects of alignment.
static bool relaxCall(InputSection *is, Relocation &rel,
                      DeleteRanges &deleteRanges) {
  auto *sym = dyn_cast_or_null<Defined>(rel.sym);
  if (!sym || !sym->section)
    return false;

  uint64_t pc = is->getVA(rel.offset);
  uint64_t target = sym->getVA(rel.addend);
  int64_t offset = target - pc;

  // As the call site and callee may reside in different sections, we need to
  // consider the worst case possible offset caused by alignment.
  if (is->getOutputSection() != sym->getOutputSection()) {
    offset = addWorstCaseAlignment(offset, maxOutputSectionAlignment());
  } else if (is != sym->section) {
    offset = addWorstCaseAlignment(offset, is->getOutputSection()->alignment);
  }

  bool rvc = config->eflags & EF_RISCV_RVC;
  unsigned rd =
      (read32le(is->data().data() + rel.offset + 4) & 0x00000fe0) >> 7;

  // Convert to c.j or c.jal (RV32-only) if offset fits in 12 bits.
  if (rvc && isInt<12>(offset) && rd == 0) {
    write16le(is->mutableData().data() + rel.offset, 0xa001); // c.j 0
    addDeleteRange(deleteRanges, rel.offset + 2, 6);
    rel.type = R_RISCV_RVC_JUMP;
    return true;
  }

  if (!config->is64 && rvc && isInt<12>(offset) && rd == 1) {
    write16le(is->mutableData().data() + rel.offset, 0x2001); // c.jal 0
    addDeleteRange(deleteRanges, rel.offset + 2, 6);
    rel.type = R_RISCV_RVC_JUMP;
    return true;
  }

  // Convert to jal if offset fits in 21 bits.
  if (isInt<21>(offset)) {
    write32le(is->mutableData().data() + rel.offset,
              0x0000006f | rd << 7); // jal rd, 0
    addDeleteRange(deleteRanges, rel.offset + 4, 4);
    rel.type = R_RISCV_JAL;
    return true;
  }

  return false;
}

// For R_RISCV_HI20 and R_RISCV_LO12_[IS], only relax to GP-relative form if
// __global_pointer$ symbol is defined and the target symbol is within the
// same section as gp. This assumes the offset between gp and the target
// symbol is static during relaxation.
static bool relaxHi20Lo12(InputSection *is, Relocation &rel,
                          DeleteRanges &deleteRanges) {
  bool rvc = config->eflags & EF_RISCV_RVC;
  uint64_t target = rel.sym->getVA(rel.addend);

  Defined *gp = ElfSym::riscvGlobalPointer;

  auto relaxToCLui = [&]() -> bool {
    unsigned rd = (read32le(is->data().data() + rel.offset) & 0x00000fe0) >> 7;
    if (rvc &&
        isInt<6>(SignExtend64(target + 0x800, config->wordsize * 8) >> 12) &&
        rd != 0 && rd != 2 && target != 0) {
      write16le(is->mutableData().data() + rel.offset,
                0x6001 | rd << 7); // c.lui rd, 0
      addDeleteRange(deleteRanges, rel.offset + 2, 2);
      rel.type = R_RISCV_RVC_LUI;
      return true;
    }
    return false;
  };

  if (!gp || rel.sym->getOutputSection() != gp->section->getOutputSection())
    return rel.type == R_RISCV_HI20 ? relaxToCLui() : false;

  uint64_t offset = target - gp->getVA();

  bool enableZceLsgp = config->optmizeZceLsgp;

  // relax to lwgp/swgp and ld/sdgp
  if(enableZceLsgp){
    bool isRV64 = config->is64;
    uint32_t inst = read32le(is->data().data() + rel.offset);
    uint32_t newInst = 0x0;
    bool isLw = (inst & 0x707f) == 0x2003;
    bool isSw = (inst & 0x707f) == 0x2023;
    bool isLd = (inst & 0x707f) == 0x3003;
    bool isSd = (inst & 0x707f) == 0x3023;
    if (rel.type == R_RISCV_HI20 && isShiftedInt<14,2>(offset)) {
      uint32_t nextInst = read32le(is->data().data() + rel.offset + 4) & 0x707f;
      if((nextInst == 0x2003) || (nextInst == 0x2023) ||
         (nextInst == 0x3003) || (nextInst == 0x3023)){
        addDeleteRange(deleteRanges, rel.offset, 4);
        rel.type = R_RISCV_NONE;
        rel.expr = R_NONE;
        return true;
      }
    } else if(rel.type == R_RISCV_LO12_I){
      unsigned rd = (inst & 0x00000fe0) >> 7;
      if(isLw && isShiftedInt<14,2>(offset)){
        newInst = (0x3007 | rd << 7); // lwgp rs, 0(gp)
        rel.type = R_RISCV_GPREL_ZCE_LWGP;
      } // isLw && isShiftedInt<14,2>(offset)
      else if(isRV64 && isLd && isShiftedInt<14,3>(offset)){
        newInst = (0x40003007 | rd << 7); // ldgp rs, 0(gp)
        rel.type = R_RISCV_GPREL_ZCE_LDGP;
      } // isRV64 && isLd && isShiftedInt<14,3>(offset)
    } // rel.type == R_RISCV_LO12_I
    else if(rel.type == R_RISCV_LO12_S){
      unsigned rs2 = (inst & 0x1F00000) >> 20;
      if(isSw && isShiftedInt<14,2>(offset)){
        newInst = (0x3027 | rs2 << 20); // swgp rs2, 0(gp)
        rel.type = R_RISCV_GPREL_ZCE_SWGP;
      } // isSw && isShiftedInt<14,2>(offset)
      else if(isRV64 && isSd && isShiftedInt<14,3>(offset)){
        newInst = (0x40003027 | rs2 << 20); // sdgp rs2, 0(gp)
        rel.type = R_RISCV_GPREL_ZCE_SDGP;
      } // isRV64 && isSd && isShiftedInt<14,3>(offset)
    } // rel.type == R_RISCV_LO12_S
    if (newInst > 0){
      write32le(is->mutableData().data() + rel.offset, newInst);
      rel.expr = R_RISCV_GPREL;
      return true;
    }
  }

  if (isInt<12>(offset)) {
    if (rel.type == R_RISCV_HI20) {
      addDeleteRange(deleteRanges, rel.offset, 4);
      rel.type = R_RISCV_NONE;
      rel.expr = R_NONE;
    } else { // R_RISCV_LO12_[IS]
      setRs1(is->mutableData().data() + rel.offset, X_GP);
      rel.type = rel.type == R_RISCV_LO12_I ? R_RISCV_GPREL_I : R_RISCV_GPREL_S;
      rel.expr = R_RISCV_GPREL;
    }
    return true;
  }

  return false;
}

// Relaxing PCREL relocations requires two passes due to the linkage from
// LO12 to HI20. The first pass only relaxes PCREL_LO12 and the second one
// relaxes PCREL_HI20.
static bool relaxPcrel(InputSection *is, Relocation &rel,
                       DeleteRanges &deleteRanges) {
  Defined *gp = ElfSym::riscvGlobalPointer;
  if (!gp)
    return false;

  const Relocation *hi20 = &rel;
  if (rel.type == R_RISCV_PCREL_LO12_I || rel.type == R_RISCV_PCREL_LO12_S) {
    hi20 = getRISCVPCRelHi20(rel.sym, rel.addend);
    if (!hi20)
      return false;
  }

  if (hi20->sym->getOutputSection() != gp->section->getOutputSection())
    return false;

  uint64_t target = hi20->sym->getVA(hi20->addend);
  uint64_t offset = target - gp->getVA();

  if (isInt<12>(offset)) {
    if (rel.type == R_RISCV_PCREL_HI20) {
      addDeleteRange(deleteRanges, rel.offset, 4);
      rel.type = R_RISCV_NONE;
      rel.expr = R_NONE;
    } else {
      setRs1(is->mutableData().data() + rel.offset, X_GP);
      rel.sym = hi20->sym;
      rel.addend = hi20->addend + rel.addend;
      rel.type =
          rel.type == R_RISCV_PCREL_LO12_I ? R_RISCV_GPREL_I : R_RISCV_GPREL_S;
      rel.expr = R_RISCV_GPREL;
    }
    return true;
  }

  return false;
}

template <typename F>
void processRelaxations(MutableArrayRef<Relocation> rels, F f) {
  if (rels.empty())
    return;

  for (auto *r = rels.begin() + 1, *e = rels.end(); r != e; ++r) {
    if (r->type != R_RISCV_RELAX)
      continue;

    Relocation *rel = std::prev(r);
    if (r->offset != rel->offset)
      continue;

    if (f(*rel)) {
      r->type = R_RISCV_NONE;
      r->expr = R_NONE;
    }
  }
}

static bool relax() {
  bool changed = false;

  for (OutputSection *os : outputSections) {
    for (InputSection *is : getInputSections(os)) {
      if (!(is->flags & SHF_EXECINSTR))
        continue;

      DeleteRanges deleteRanges;
      processRelaxations(is->relocations, [&](Relocation &rel) {
        switch (rel.type) {
        case R_RISCV_CALL:
        case R_RISCV_CALL_PLT:
          return relaxCall(is, rel, deleteRanges);
        case R_RISCV_HI20:
        case R_RISCV_LO12_I:
        case R_RISCV_LO12_S:
          return relaxHi20Lo12(is, rel, deleteRanges);
        case R_RISCV_PCREL_LO12_I:
        case R_RISCV_PCREL_LO12_S:
          return relaxPcrel(is, rel, deleteRanges);
        }

        return false;
      });

      // The second-pass for PCREL_HI20 relaxation.
      processRelaxations(is->relocations, [&](Relocation &rel) {
        if (rel.type != R_RISCV_PCREL_HI20)
          return false;

        return relaxPcrel(is, rel, deleteRanges);
      });

      using DeleteRange = InputSectionBase::DeleteRange;
      llvm::sort(deleteRanges,
                 [](const DeleteRange &lhs, const DeleteRange &rhs) {
                   return lhs.offset < rhs.offset;
                 });

      is->deleteRanges(deleteRanges);
      script->assignAddresses();
      changed |= !deleteRanges.empty();
    }
  }

  return changed;
}

static void relaxAlign() {
  bool rvc = config->eflags & EF_RISCV_RVC;

  for (OutputSection *os : outputSections) {
    for (InputSection *is : getInputSections(os)) {
      if (!(is->flags & SHF_EXECINSTR))
        continue;

      uint64_t bytesDeleted = 0;
      DeleteRanges deleteRanges;
      for (auto &rel : is->relocations) {
        if (rel.type == R_RISCV_ALIGN && rel.addend > 0) {
          uint64_t pc = is->getVA(rel.offset) - bytesDeleted;
          uint64_t alignment = PowerOf2Ceil(rel.addend + 2);
          uint64_t nopBytes = alignTo(pc, alignment) - pc;

          if (nopBytes % 2 != 0 || (!rvc && nopBytes % 4 != 0)) {
            errorOrWarn(is->getObjMsg(rel.offset) + ": alignment requires " +
                        Twine(nopBytes) + " of nop");
            break;
          }

          if (nopBytes > (uint64_t)rel.addend) {
            errorOrWarn(is->getObjMsg(rel.offset) + ": alignment requires " +
                        Twine(nopBytes) + " of nop, but only " +
                        Twine(rel.addend) + " bytes are available");
            break;
          }
          uint64_t bytesToDelete = rel.addend - nopBytes;

          if (bytesToDelete > 0) {
            addDeleteRange(deleteRanges, rel.offset + nopBytes, bytesToDelete);
            bytesDeleted += bytesToDelete;
          }

          uint8_t *buf = is->mutableData().data() + rel.offset;
          while (nopBytes != 0) {
            if (nopBytes >= 4) {
              write32le(buf, 0x00000013); // nop
              nopBytes -= 4;
              buf += 4;
            } else if (rvc && nopBytes == 2) {
              write16le(buf, 0x0001); // c.nop
              nopBytes -= 2;
              buf += 2;
            }
          }
        }
      }

      is->deleteRanges(deleteRanges);
      script->assignAddresses();
    }
  }
}

void RISCV::finalizeSections() const {
  // Can't perform relaxation if it is not a final link.
  if (config->relocatable)
    return;

  if (config->relax)
    while (relax())
      ;

  relaxAlign();
}

TargetInfo *elf::getRISCVTargetInfo() {
  static RISCV target;
  return &target;
}

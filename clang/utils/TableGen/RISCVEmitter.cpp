#include "llvm/Support/MathExtras.h"
#include "llvm/TableGen/Record.h"
#include <cctype>

namespace {

using namespace llvm;

struct SkipWhiteSpace {
  raw_ostream &OS;

  raw_ostream &operator<<(const char *Str) {
    while (isspace(*Str))
      Str++;
    return OS << Str;
  }
};

template <typename T>
auto operator<<(raw_ostream &OS, const T &Object)
    -> decltype(Object.Write(OS), OS) {
  Object.Write(OS);
  return OS;
}

const char *LicenseDeclaration = R"(
/*===---- riscv_vector.h - RISC-V Vector Extensions ------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */
)";

const char *HeaderGuard = R"(
#ifndef __RISCV_VECTOR_H__
#define __RISCV_VECTOR_H__
)";

const char *EndIf = R"(
#endif
)";

struct BaseType {
  enum { INTEGER, UNSIGNED_INTEGER, FLOATING_POINT };

  int ID;

  void Write(raw_ostream &OS) const {
    switch (ID) {
    case INTEGER:
      OS << "int";
      break;
    case UNSIGNED_INTEGER:
      OS << "uint";
      break;
    case FLOATING_POINT:
      OS << "float";
      break;
    default:
      llvm_unreachable("Unhandled BaseTy!");
    }
  }

  auto ToCType() const {
    struct {
      BaseType BT;

      void Write(raw_ostream &OS) const {
        switch (BT.ID) {
        case INTEGER:
          OS << "int";
          break;
        case UNSIGNED_INTEGER:
          OS << "unsigned";
          break;
        case FLOATING_POINT:
          OS << "float";
          break;
        default:
          llvm_unreachable("Unhandled BaseTy!");
        }
      }
    } Wrapper{*this};

    return Wrapper;
  }

  static void Enum(function_ref<void(BaseType BT)> F) {
    for (int I : {INTEGER, UNSIGNED_INTEGER, FLOATING_POINT}) {
      F(BaseType{I});
    }
  }
};

struct StdElemWidth {
  unsigned Width;

  unsigned Encoding() const { return (Log2_64(Width) - 3) << 2; }

  void Write(raw_ostream &OS) const { OS << Width; }

  static void Enum(function_ref<void(StdElemWidth SEW)> F) {
    for (unsigned W : {8, 16, 32, 64}) {
      F(StdElemWidth{W});
    }
  }

  static void Enum(BaseType BT, function_ref<void(StdElemWidth SEW)> F) {
    Enum([&](StdElemWidth SEW) {
      if (SEW.Width == 8 && BT.ID == BaseType::FLOATING_POINT)
        return;
      F(SEW);
    });
  }
};

// FIXME: Is ELEN a compile-time constant?
constexpr unsigned ELEN = 64;

struct LengthMultiplier {
  unsigned Mul;
  bool IsFract;

  unsigned Encoding() const { return (unsigned(IsFract) << 5) | Log2_64(Mul); }

  void Write(raw_ostream &OS) const { OS << (IsFract ? "mf" : "m") << Mul; }

  auto ToUpper() const {
    struct {
      LengthMultiplier LMUL;

      void Write(raw_ostream &OS) const {
        OS << (LMUL.IsFract ? "MF" : "M") << LMUL.Mul;
      }
    } Wrapper{*this};

    return Wrapper;
  }

  static void Enum(function_ref<void(LengthMultiplier LMUL)> F) {
    for (unsigned Mul : {1, 2, 4, 8}) {
      F({Mul, false});
    }

    for (unsigned Mul : {2, 4, 8}) {
      F({Mul, true});
    }
  }

  static void Enum(StdElemWidth SEW,
                   function_ref<void(LengthMultiplier LMUL)> F) {
    Enum([&](LengthMultiplier LMUL) {
      // LMUL = 1/Mul
      // LMUL >= SEW / ELEN
      // <=> 1/Mul >= SEW / ELEN
      // <=> ELEN >= SEW * Mul
      if (LMUL.IsFract && ELEN < SEW.Width * LMUL.Mul)
        return;
      F(LMUL);
    });
  }
};

struct VectorType {
  BaseType BT;
  StdElemWidth SEW;
  LengthMultiplier LMUL;

  void Write(raw_ostream &OS) const { OS << "v" << BT << SEW << LMUL << "_t"; }

  static void Enum(function_ref<void(VectorType VT)> F) {
    BaseType::Enum([&](BaseType BT) {
      StdElemWidth::Enum(BT, [&](StdElemWidth SEW) {
        LengthMultiplier::Enum(SEW, [&](LengthMultiplier LMUL) {
          F({BT, SEW, LMUL});
        });
      });
    });
  }
};

struct VectorTypeDef {
  VectorType VT;

  void Write(raw_ostream &OS) const {
    OS << "typedef __attribute(riscv_vector_type(" << VT.SEW;
    OS << ", " << VT.LMUL.Mul << ", ";
    OS << ", " << (VT.LMUL.IsFract ? "true" : "false") << "))";
    OS << " " << VT.BT.ToCType() << " " << VT << ";";
  }
};

struct MaskType {
  unsigned N;

  void Write(raw_ostream &OS) const { OS << "vbool" << N << "_t"; }

  static void Enum(function_ref<void(MaskType MT)> F) {
    for (unsigned N : {1, 2, 4, 8, 16, 32, 64}) {
      F(MaskType{N});
    }
  }
};

struct MaskTypeDef {
  MaskType MT;

  void Write(raw_ostream &OS) const {
    OS << "typedef __attribute(riscv_mask_type(" << MT.N;
    OS << ")) bool " << MT << ";";
  }
};

struct VectorTupleDef {
  VectorType VT;
  unsigned N;

  void Write(raw_ostream &OS) const {
    OS << "typedef struct {\n";

    for (unsigned I = 0; I < N; ++I) {
      OS << "  " << VT << " v" << I << ";\n";
    }

    OS << "} v" << VT.BT << VT.SEW << VT.LMUL;
    OS << "x" << N << "_t;";
  }

  static void Enum(VectorType VT, function_ref<void(VectorTupleDef Def)> F) {
    for (unsigned N : {2, 3, 4, 5, 6, 7, 8}) {
      F({VT, N});
    }
  }
};

struct ConstantEDef {
  StdElemWidth SEW;

  void Write(raw_ostream &OS) const {
    OS << "#define _E" << SEW << " " << SEW.Encoding() << ";";
  }
};

struct ConstantMDef {
  LengthMultiplier LMUL;

  void Write(raw_ostream &OS) const {
    OS << "#define _M" << (LMUL.IsFract ? "F" : "");
    OS << LMUL.Mul << " " << LMUL.Encoding() << ";";
  }
};

struct VSetVLDef {
  StdElemWidth SEW;
  LengthMultiplier LMUL;

  void Write(raw_ostream &OS) const {
    OS << "static __attribute__((always_inline, nothrow))\n";
    OS << "size_t vsetvl_e" << SEW << "" << LMUL << "(";
    OS << "size_t avl) {\n";
    OS << "  return __builtin_riscv_vsetvl(avl, ";
    OS << "_E" << SEW << " | "
       << "_" << LMUL.ToUpper() << ");\n";
    OS << "}";
  }
};

} // namespace

namespace clang {

void EmitRISCVVectorHeader(RecordKeeper &Records, raw_ostream &OS) {
  SkipWhiteSpace{OS} << LicenseDeclaration << HeaderGuard << "\n";

  // Emit definitions of all vector types.
  VectorType::Enum([&](VectorType VT) { OS << VectorTypeDef{VT} << "\n\n"; });

  // Emit definitions of all mask types.
  MaskType::Enum([&](MaskType MT) { OS << MaskTypeDef{MT} << "\n\n"; });

  // Emit definitions of all vector-tuple types.
  VectorType::Enum([&](VectorType VT) {
    VectorTupleDef::Enum(VT, [&](VectorTupleDef Def) { OS << Def << "\n\n"; });
  });

  // Emit definitions of all _Exxx constant.
  StdElemWidth::Enum(
      [&](StdElemWidth SEW) { OS << ConstantEDef{SEW} << "\n\n"; });

  // Emit definitions of all _Mxxx constant.
  LengthMultiplier::Enum(
      [&](LengthMultiplier LMUL) { OS << ConstantMDef{LMUL} << "\n\n"; });

  // Emit definitions of all vsetvl_xxx.
  VectorType::Enum([&](VectorType VT) {
    OS << VSetVLDef{VT.SEW, VT.LMUL} << "\n\n";
  });

  SkipWhiteSpace{OS} << EndIf;
}

} // namespace clang

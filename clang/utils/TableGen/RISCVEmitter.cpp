#include "llvm/Support/MathExtras.h"
#include "llvm/TableGen/Record.h"
#include <cctype>

namespace {

using namespace llvm;

// Simple decorator for raw_ostream, which skips
// leading spaces in outputed strings.
struct SkipWhiteSpace {
  raw_ostream &OS;

  raw_ostream &operator<<(const char *Str) {
    while (isspace(*Str))
      Str++;
    return OS << Str;
  }
};

// Interface of writable objects.
template <typename T>
auto operator<<(raw_ostream &OS, const T &Object)
    -> decltype(Object.Write(OS), OS) {
  Object.Write(OS);
  return OS;
}

// Utilities for building parsers.
inline namespace simple_parser_combinators {

// All parsers should have a signature like this one.
using ParserSignature = const char *(const char *);

// Tools for concept checking.
template <typename F, typename S>
using requires_signature =
    std::enable_if_t<std::is_constructible<std::function<S>, F>::value, int>;

template <typename Par>
using requires_parser = requires_signature<Par, ParserSignature>;

// If parser PX succeeds, then run parser PY.
template <typename ParserX, typename ParserY, //
          requires_parser<ParserX> = 1,       //
          requires_parser<ParserY> = 1>
constexpr auto operator,(ParserX PX, ParserY PY) {
  return [=](const char *Text) {
    const char *Rest = PX(Text);
    return Rest ? PY(Rest) : nullptr;
  };
}

// If parser PX fails, then run parser PY.
template <typename ParserX, typename ParserY, //
          requires_parser<ParserX> = 1,       //
          requires_parser<ParserY> = 1>
constexpr auto operator|(ParserX PX, ParserY PY) {
  return [=](const char *Text) {
    const char *Rest = PX(Text);
    return Rest ? Rest : PY(Text);
  };
}

// Run some code during parsing.
template <typename Par, requires_signature<Par, void(const char *)> = 1> //
constexpr auto Act(Par P) {
  return [=](const char *Text) {
    P(Text);
    return Text;
  };
}

template <typename Par, requires_signature<Par, void()> = 1> //
constexpr auto Act(Par P) {
  return [=](const char *Text) {
    P();
    return Text;
  };
}

// Check if the current character matches with the desired one.
constexpr auto Match(char C) {
  return [=](const char *Text) { return *Text == C ? ++Text : nullptr; };
}

template <typename Par> //
constexpr auto MatchNot(char C, Par P) {
  return
      [=](const char *Text) { return *Text && *Text != C ? P(Text) : nullptr; };
}

// Run parser P as many times as possible.
template <typename Par, requires_parser<Par> = 1> //
constexpr auto Many(Par P) {
  return [=](const char *Text) {
    const char *Latest = Text;

    do {
      Text = Latest;
      Latest = P(Text);
    } while (Latest);

    return Text;
  };
}

// Run an optional parser.
template <typename Par, requires_parser<Par> = 1> //
constexpr auto Maybe(Par P) {
  return [=](const char *Text) {
    const char *Rest = P(Text);
    return Rest ? Rest : Text;
  };
}

// Read a digit.
template <typename Func> //
constexpr auto ReadDigit(Func F) {
  return [=](const char *Text) {
    return isdigit(*Text) ? (F(*Text - '0'), ++Text) : nullptr;
  };
}
} // namespace simple_parser_combinators

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

const char *Dependencies = R"(
#include <stdbool.h>
#include <stddef.h>
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

  auto ToSuffix() const {
    struct {
      BaseType BT;

      void Write(raw_ostream &OS) const {
        switch (BT.ID) {
        case INTEGER:
          OS << "i";
          break;
        case UNSIGNED_INTEGER:
          OS << "u";
          break;
        case FLOATING_POINT:
          OS << "f";
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
    OS << "typedef __attribute__((riscv_vector_type(" << VT.SEW;
    OS << ", " << VT.LMUL.Mul;
    OS << ", " << (VT.LMUL.IsFract ? "1" : "0") << ")))";
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
    OS << "typedef __attribute__((riscv_mask_type(" << MT.N;
    OS << "))) bool " << MT << ";";
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
    OS << "#define _E" << SEW << " " << SEW.Encoding();
  }
};

struct ConstantMDef {
  LengthMultiplier LMUL;

  void Write(raw_ostream &OS) const {
    OS << "#define _M" << (LMUL.IsFract ? "F" : "");
    OS << LMUL.Mul << " " << LMUL.Encoding();
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

struct GeneratorParams {
  Optional<BaseType> Base;
  Optional<StdElemWidth> SEW;
  Optional<LengthMultiplier> LMUL;
  Optional<unsigned> TupleN;

  auto Format(StringRef Str) const {
    struct {
      StringRef Str;
      GeneratorParams GP;

      void Write(raw_ostream &OS) const {
        Many((MatchNot('%', [&](auto Text) { return OS << *Text, ++Text; })) //
             | (Match('%'),                                                  //
                ((Match('b'), Act([&] { OS << GP.Base->ToSuffix(); }))       //
                 | (Match('s'), Act([&] { OS << *GP.SEW; }))                 //
                 | (Match('l'), Act([&] { OS << *GP.LMUL; }))                //
                 | (Match('L'), Act([&] { OS << GP.LMUL->ToUpper(); })))))   //
            (Str.data());
      }

    } Wrapper{Str, *this};
    return Wrapper;
  }

  auto ToVector() const { return VectorType{*Base, *SEW, *LMUL}; }

  unsigned MaskLength() const {
    return LMUL->IsFract ? (SEW->Width / LMUL->Mul) : (SEW->Width * LMUL->Mul);
  }
};

using Generator = function_ref<void(GeneratorParams)>;

// grammar for type specification
//
// type_spec
//   : prefix* base_type postfix*
//   ;
// prefix
//   : 'U' # unsigned
//   ;
// base_type
//   : 'v' # void
//   | 'b' # bool
//   | 'c' # char
//   | 's' # int16_t
//   | 'i' # int32_t
//   | 'l' # int64_t
//   | 'h' # float16_t
//   | 'f' # float32_t
//   | 'd' # float64_t
//   | 'z' # size_t
//   | 'e' # type that depends on the context
//   | 'q' # vector
//   ;
// postfix
//   : '*' # pointer
//   | '&' # reference
//   | 'C' # const
//   | 'D' # volatile
//   ;
struct TypeSpecifier {
private:
  auto InsertPrefix(const char *P) {
    return Act([&, P] { Prefixes.insert(P); });
  };

  auto SetBase(const char *B) {
    return Act([&, B] { Base = B; });
  };

  auto InsertPostfix(const char *P) {
    return Act([&, P] { Postfixes.insert(P); });
  };

public:
  enum SpecClass { ATOM, VECTOR, DEPENDENT };

  DenseSet<StringRef> Prefixes;
  DenseSet<StringRef> Postfixes;
  std::string Base;
  SpecClass SC;

  TypeSpecifier(StringRef Text) : TypeSpecifier(Text.data()) {}

  TypeSpecifier(const char *Text) : SC(ATOM) {
    auto Parser = (Many((Match('U'), InsertPrefix("unsigned"))),
                   ((Match('v'), SetBase("void"))                //
                    | (Match('b'), SetBase("bool"))              //
                    | (Match('c'), SetBase("int8_t"))            //
                    | (Match('s'), SetBase("int16_t"))           //
                    | (Match('i'), SetBase("int32_t"))           //
                    | (Match('l'), SetBase("int64_t"))           //
                    | (Match('h'), SetBase("float16_t"))         //
                    | (Match('f'), SetBase("float32_t"))         //
                    | (Match('d'), SetBase("float64_t"))         //
                    | (Match('z'), SetBase("size_t"))            //
                    | (Match('e'), Act([&] { SC = DEPENDENT; })) //
                    | (Match('q'), Act([&] { SC = VECTOR; }))),  //
                   Many((Match('*'), InsertPostfix("*"))         //
                        | (Match('&'), InsertPostfix("&"))       //
                        | (Match('C'), InsertPostfix("const"))   //
                        | (Match('D'), InsertPostfix("volatile"))));

    const char *Rest = Parser(Text);
    assert(Rest && !*Rest && "Failed to parse the type");
  }

  auto ToWritable(GeneratorParams GP) const {
    struct {
      GeneratorParams GP;
      TypeSpecifier Spec;

      void Write(raw_ostream &OS) const {
        switch (Spec.SC) {
        case ATOM: {
          if (Spec.Postfixes.count("const"))
            OS << "const ";

          if (Spec.Prefixes.count("unsigned"))
            OS << "unsigned ";

          OS << Spec.Base;

          if (Spec.Postfixes.count("*"))
            OS << "*";
          else if (Spec.Postfixes.count("&"))
            OS << "&";

          if (Spec.Postfixes.count("volatile"))
            OS << " volatile";
        } break;
        case VECTOR: {
          OS << "v" << *GP.Base << *GP.SEW << *GP.LMUL;

          if (GP.TupleN.hasValue())
            OS << "v" << *GP.TupleN;

          OS << "_t";
        } break;
        case DEPENDENT: {
          if (Spec.Postfixes.count("const"))
            OS << "const ";

          OS << *GP.Base << *GP.SEW << "_t";

          if (Spec.Postfixes.count("*"))
            OS << "*";
          else if (Spec.Postfixes.count("&"))
            OS << "&";

          if (Spec.Postfixes.count("volatile"))
            OS << " volatile";
        } break;
        default:
          llvm_unreachable("Unhandled type class");
        }
      }
    } Wrapper{GP, *this};

    return Wrapper;
  }
};

// Adhoc tests for type specification parsing.
struct UnitTest {
  UnitTest(function_ref<void()> F) { F(); }
};

struct ParserUnitTest : UnitTest {
  ParserUnitTest(const char *Input, DenseSet<StringRef> Prefixes,
                 const char *Base, DenseSet<StringRef> Postfixes)
      : UnitTest([=] {
          TypeSpecifier Spec(Input);
          assert(Spec.Prefixes == Prefixes);
          assert(Spec.Base == Base);
          assert(Spec.Postfixes == Postfixes);
        }) {}
};

ParserUnitTest TestPrefix[]{
    {"Uv", {"unsigned"}, "void", {}} //
};

ParserUnitTest TestBaseType[]{
    {"v", {}, "void", {}},      //
    {"b", {}, "bool", {}},      //
    {"c", {}, "int8_t", {}},    //
    {"s", {}, "int16_t", {}},   //
    {"i", {}, "int32_t", {}},   //
    {"h", {}, "float16_t", {}}, //
    {"f", {}, "float32_t", {}}, //
    {"d", {}, "float64_t", {}}, //
    {"z", {}, "size_t", {}}     //
};

ParserUnitTest TestPostfix[]{
    {"v*", {}, "void", {"*"}},       //
    {"v&", {}, "void", {"&"}},       //
    {"vD", {}, "void", {"volatile"}} //
};

struct RISCVBuiltin {
  StringRef Instruction;
  std::vector<TypeSpecifier> Prototype;
  StringRef TypeRange;
  bool MayMask;
  bool MaskedOff;
  bool HasVL;
  bool HasSideEffects;
  StringRef IntrinsicName;
  bool BasePolymorphic;
  bool SEWPolymorphic;
  bool LMULPolymorphic;
  bool TuplePolymorphic;
  std::string Body;

  RISCVBuiltin(const Record *Rec)
      : Instruction(Rec->getValueAsString("Instruction")),
        TypeRange(Rec->getValueAsString("TypeRange")),
        MayMask(Rec->getValueAsBit("MayMask")),
        MaskedOff(Rec->getValueAsBit("MaskedOff")),
        HasVL(Rec->getValueAsBit("HasVL")),
        HasSideEffects(Rec->getValueAsBit("HasSideEffects")),
        IntrinsicName(Rec->getValueAsString("IntrinsicName")),
        BasePolymorphic(Rec->getValueAsBit("BasePolymorphic")),
        SEWPolymorphic(Rec->getValueAsBit("SEWPolymorphic")),
        LMULPolymorphic(Rec->getValueAsBit("LMULPolymorphic")),
        TuplePolymorphic(Rec->getValueAsBit("TuplePolymorphic")),
        Body(Rec->getValue("Body")->getValue()->getAsUnquotedString()) {
    for (StringRef Type : Rec->getValueAsListOfStrings("Prototype")) {
      Prototype.emplace_back(Type);
    }
  }

  void Yield(Generator G) const {
    auto YieldTuple = [=](auto... args) {
      if (TuplePolymorphic) {
        for (unsigned N : {2, 3, 4, 5, 6, 7, 8})
          G({args..., N});
      } else
        G({args..., None});
    };

    auto YieldLMUL = [=](Optional<BaseType> BT, Optional<StdElemWidth> SEW) {
      if (LMULPolymorphic) {
        if (SEW.hasValue())
          LengthMultiplier::Enum(
              *SEW, [=](LengthMultiplier LMUL) { YieldTuple(BT, SEW, LMUL); });
        else
          LengthMultiplier::Enum(
              [=](LengthMultiplier LMUL) { YieldTuple(BT, SEW, LMUL); });
      } else
        YieldTuple(BT, SEW, None);
    };

    auto YieldSEW = [=](Optional<BaseType> BT) {
      if (SEWPolymorphic) {
        if (BT.hasValue())
          StdElemWidth::Enum(*BT,
                             [=](StdElemWidth SEW) { YieldLMUL(BT, SEW); });
        else
          StdElemWidth::Enum([=](StdElemWidth SEW) { YieldLMUL(BT, SEW); });
      } else
        YieldLMUL(BT, None);
    };

    if (BasePolymorphic)
      BaseType::Enum([=](BaseType BT) { YieldSEW(BT); });
    else
      YieldSEW(None);
  }

  void Write(raw_ostream &OS) const {
    OS << "// Intrinsics for " << Instruction << "\n\n";

    Yield([&](GeneratorParams GP) {
      Write(OS, GP, false, false, false);
      OS << "\n\n";

      if (HasVL) {
        Write(OS, GP, false, false, true);
        OS << "\n\n";
      }

      if (MayMask) {
        Write(OS, GP, true, MaskedOff, false);
        OS << "\n\n";

        if (HasVL) {
          Write(OS, GP, false, MaskedOff, true);
          OS << "\n\n";
        }
      }
    });
  }

  void Write(raw_ostream &OS, GeneratorParams GP, bool HasMask, bool MaskedOff,
             bool HasVL) const {

    OS << "static __attribute__((always_inline, nothrow))\n";

    assert(Prototype.size());
    const TypeSpecifier &RetTy = Prototype[0];

    OS << RetTy.ToWritable(GP) << " ";

    if (IntrinsicName.empty()) {
      OS << GP.Format(Instruction);
    } else
      OS << IntrinsicName;

    if (HasMask)
      OS << "_m";

    if (HasVL)
      OS << "_vl";

    OS << "(";

    if (HasMask) {
      OS << "vbool" << GP.MaskLength() << "_t mask, ";

      if (MaskedOff) {
        OS << GP.ToVector() << " maskedoff, ";
      }
    }

    for (unsigned I = 1, E = Prototype.size(); I != E; ++I) {
      const TypeSpecifier &Spec = Prototype[I];
      OS << Spec.ToWritable(GP);

      OS << " arg" << I;

      if (I + 1 != E)
        OS << ", ";
    }

    if (HasVL)
      OS << ", size_t vl";

    OS << ") {\n  ";

    if (Body.empty()) {
      if (HasVL)
        OS << GP.Format("vsetvl_e%s%l") << "(vl);\n  ";

      if (RetTy.Base != "void")
        OS << "return ";

      OS << "__builtin_riscv_";

      if (IntrinsicName.empty()) {
        OS << GP.Format(Instruction);
      } else
        OS << IntrinsicName;

      OS << "(";

      if (HasMask) {
        OS << "mask, ";

        if (MaskedOff)
          OS << "maskedoff ";
      }

      for (unsigned I = 1, E = Prototype.size(); I != E; ++I) {
        OS << "arg" << I;
        if (I + 1 != E)
          OS << ", ";
      }

      OS << ");";
    } else {
      OS << GP.Format(Body);
    }

    OS << "\n}";
  }
};

} // namespace

namespace clang {

void EmitRISCVVectorHeader(RecordKeeper &Keeper, raw_ostream &OS) {
  SkipWhiteSpace{OS} << LicenseDeclaration;
  SkipWhiteSpace{OS} << HeaderGuard << "\n";
  SkipWhiteSpace{OS} << Dependencies << "\n";

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

  // // Emit definitions of all vsetvl_xxx.
  // StdElemWidth::Enum([&](StdElemWidth SEW) {
  //   LengthMultiplier::Enum(SEW, [&](LengthMultiplier LMUL) {
  //     OS << VSetVLDef{SEW, LMUL} << "\n\n";
  //   });
  // });

  // Emit definitions of all intrinsics.
  for (const Record *Rec : Keeper.getAllDerivedDefinitions("RISCVBuiltin")) {
    OS << RISCVBuiltin(Rec) << "\n\n";
  }

  SkipWhiteSpace{OS} << EndIf;
}

} // namespace clang

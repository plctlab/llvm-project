#include "llvm/Support/MathExtras.h"
#include "llvm/TableGen/Record.h"
#include <cctype>

// Fractional LMUL is not supported at the moment.
// #define SUPPORT_FRACTIONAL_LMUL

namespace {

using namespace llvm;

// Interface for writable objects.
template <typename T>
auto operator<<(raw_ostream &OS, const T &Object)
    -> decltype(Object.Write(OS), OS) {
  Object.Write(OS);
  return OS;
}

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

struct SeparatedBy {
  raw_ostream &OS;
  StringRef Delimiter;
  bool NeedDelimiter = false;

  template <typename T>
  constexpr auto operator<<(const T &Value) -> decltype(OS << Value, *this) {
    if (NeedDelimiter)
      OS << Delimiter;

    OS << Value;

    NeedDelimiter = true;

    return *this;
  }
};

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

template <typename ParserX, typename ParserY, //
          requires_parser<ParserX> = 1,       //
          requires_parser<ParserY> = 1>
constexpr auto operator&&(ParserX PX, ParserY PY) {
  return [=](const char *Text) { return PY(PX(Text)); };
}

// Run some code during parsing.
template <typename Par, requires_signature<Par, void(const char *)> = 1> //
constexpr auto Act(Par P) {
  return [=](const char *Text) { return P(Text), Text; };
}

template <typename Par, requires_signature<Par, void()> = 1> //
constexpr auto Act(Par P) {
  return [=](const char *Text) { return P(), Text; };
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

    while ((Latest = P(Text)))
      Text = Latest;

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

constexpr auto WriteChar(raw_ostream &OS) {
  return [&](const char *Text) { //
    return *Text ? (OS << *Text, ++Text) : nullptr;
  };
}

raw_ostream &WriteSeq(raw_ostream &OS) { return OS; }

template <typename T, typename... Ts>
raw_ostream &WriteSeq(raw_ostream &OS, T M, Ts... Ms) {
  return OS << M, WriteSeq(OS, Ms...);
}

template <typename... Ts> //
constexpr auto EofOrFail(Ts... Messages) {
  return [=](const char *Text) {
    if (!Text || *Text) {
      WriteSeq(errs(), Messages..., "\n");
      llvm_unreachable("Failed to run the parser");
    }
    return nullptr;
  };
}

} // namespace simple_parser_combinators

class BaseType {
public:
  static BaseType Integer() { return BaseType(INTEGER); }

  static BaseType UnsignedInteger() { return BaseType(UNSIGNED_INTEGER); }

  static BaseType FloatingPoint() { return BaseType(FLOATING_POINT); }

  bool IsInteger() const { return ID == INTEGER; }

  bool IsUnsignedInteger() const { return ID == UNSIGNED_INTEGER; }

  bool IsFloatingPoint() const { return ID == FLOATING_POINT; }

  // Used in various typedefs.
  void Write(raw_ostream &OS) const {
    switch (ID) {
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

  // Used in names like vint32m1_t, vuint32m1_t and vfloat32m1_t.
  auto Abbr() const {
    struct {
      const BaseType &BT;

      void Write(raw_ostream &OS) const {
        switch (BT.ID) {
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
    } Wrapper{*this};

    return Wrapper;
  }

  // Used in suffixes of intrinsics' names, e.g. vle32_v_i32m1.
  auto SingleLetter() const {
    struct {
      const BaseType &BT;

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
      F(BaseType(I));
    }
  }

private:
  BaseType(int ID) : ID(ID) {}

private:
  enum { INTEGER, UNSIGNED_INTEGER, FLOATING_POINT };

  int ID;
};

class StdElemWidth {
public:
  unsigned GetWidth() const { return Width; }

  unsigned GetEncoding() const { return (Log2_64(Width) - 3) << 2; }

  void Write(raw_ostream &OS) const { OS << Width; }

  static void Enum(function_ref<void(StdElemWidth SEW)> F) {
    for (unsigned W : {8, 16, 32, 64})
      F(StdElemWidth{W});
  }

  static void Enum(BaseType BT, function_ref<void(StdElemWidth SEW)> F) {
    Enum([&](StdElemWidth SEW) {
      if ((SEW.Width == 8 || SEW.Width == 16) && BT.IsFloatingPoint())
        return;
      F(SEW);
    });
  }

private:
  StdElemWidth(unsigned Width) : Width(Width) {}

private:
  unsigned Width;
};

// FIXME: Is ELEN a compile-time constant?
constexpr unsigned ELEN = 64;

class LengthMultiplier {
public:
  unsigned GetMul() const { return Mul; }

  bool IsFract() const { return Fract; }

  unsigned GetEncoding() const { return (unsigned(Fract) << 5) | Log2_64(Mul); }

  // Used in suffixes of intrinsics' names, e.g. vle32_v_i32mf2.
  auto LowerCase() const {
    struct {
      const LengthMultiplier &LMUL;

      void Write(raw_ostream &OS) const {
        OS << (LMUL.Fract ? "f" : "") << LMUL.Mul;
      }
    } Wrapper{*this};

    return Wrapper;
  }

  // Used in constants' definitions, e.g. _MF2
  auto UpperCase() const {
    struct {
      const LengthMultiplier &LMUL;

      void Write(raw_ostream &OS) const {
        OS << (LMUL.Fract ? "F" : "") << LMUL.Mul;
      }
    } Wrapper{*this};

    return Wrapper;
  }

  static void Enum(function_ref<void(LengthMultiplier LMUL)> F) {
    for (unsigned Mul : {1, 2, 4, 8}) {
      F(LengthMultiplier(Mul, false));

#ifdef SUPPORT_FRACTIONAL_LMUL
      for (unsigned Mul : {2, 4, 8})
        F(LengthMultiplier(Mul, true));
#endif
    }
  }

  static void Enum(StdElemWidth SEW,
                   function_ref<void(LengthMultiplier LMUL)> F) {
    Enum([&](LengthMultiplier LMUL) {
      // LMUL = 1/Mul
      // LMUL >= SEW / ELEN
      // <=> 1/Mul >= SEW / ELEN
      // <=> ELEN >= SEW * Mul
      if (LMUL.Fract && ELEN < SEW.GetWidth() * LMUL.Mul)
        return;
      F(LMUL);
    });
  }

private:
  LengthMultiplier(unsigned Mul, bool Fract) : Mul(Mul), Fract(Fract) {}

private:
  unsigned Mul;
  bool Fract;
};

struct ElementType {
  const BaseType BT;
  const StdElemWidth SEW;

  // Used in dependent parameters' types in intrinsics' signatures.
  void Write(raw_ostream &OS) const {
    if (BT.IsFloatingPoint()) {
      switch (SEW.GetWidth()) {
      case 16:
        OS << "_Float16";
        break;
      case 32:
        OS << "float";
        break;
      case 64:
        OS << "double";
        break;
      default:
        llvm_unreachable("Unhandled SEW");
      }
    } else if (BT.IsUnsignedInteger()) {
      switch (SEW.GetWidth()) {
      case 8:
        OS << "unsigned char";
        break;
      case 16:
        OS << "unsigned short";
        break;
      case 32:
        OS << "uint32_t";
        break;
      case 64:
        OS << "uint64_t";
        break;
      default:
        llvm_unreachable("Unhandled SEW");
      }
    } else {
      switch (SEW.GetWidth()) {
      case 8:
        OS << "char";
        break;
      case 16:
        OS << "short";
        break;
      case 32:
        OS << "int32_t";
        break;
      case 64:
        OS << "int64_t";
        break;
      default:
        llvm_unreachable("Unhandled SEW");
      }
    }
  }

  // Mapped to characters defined in Builtins.def
  auto Abbr() const {
    struct {
      const ElementType &ET;

      void Write(raw_ostream &OS) const {
        if (ET.BT.IsFloatingPoint()) {
          switch (ET.SEW.GetWidth()) {
          case 16:
            OS << "h";
            break;
          case 32:
            OS << "f";
            break;
          case 64:
            OS << "d";
            break;
          default:
            llvm_unreachable("Unhandled SEW");
          }
        } else {
          if (ET.BT.IsUnsignedInteger())
            OS << "U";

          switch (ET.SEW.GetWidth()) {
          case 8:
            OS << "c";
            break;
          case 16:
            OS << "s";
            break;
          case 32:
            OS << "Zi";
            break;
          case 64:
            OS << "Wi";
            break;
          default:
            llvm_unreachable("Unhandled SEW");
          }
        }
      }
    } Wrapper{*this};
    return Wrapper;
  }
};

struct VectorType {
  const BaseType BT;
  const StdElemWidth SEW;
  const LengthMultiplier LMUL;

  ElementType Element() const { return {BT, SEW}; }

  void Write(raw_ostream &OS) const {
    OS << "v" << BT.Abbr() << SEW << "m" << LMUL.LowerCase() << "_t";
  }

  // Mapped to characters defined in Builtins.def
  auto Abbr() const {
    struct {
      const VectorType &VT;

      void Write(raw_ostream &OS) const {
        OS << "q" << VT.LMUL.LowerCase() << VT.Element().Abbr();
      }

    } Wrapper{*this};

    return Wrapper;
  }

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
  const VectorType VT;

  void Write(raw_ostream &OS) const {
    OS << "typedef __attribute__((riscv_vector_type(" << VT.SEW;
    OS << ", " << VT.LMUL.GetMul();
    OS << ", " << (VT.LMUL.IsFract() ? "1" : "0") << ")))";
    OS << " " << VT.BT << " " << VT << ";";
  }
};

struct MaskType {
  const unsigned N;

  void Write(raw_ostream &OS) const { OS << "vbool" << N << "_t"; }

  // Mapped to characters defined in Builtins.def
  auto Abbr() const {
    struct {
      const MaskType &MT;

      void Write(raw_ostream &OS) const { OS << "q" << MT.N << "i1"; }

    } Wrapper{*this};

    return Wrapper;
  }

  static void Enum(function_ref<void(MaskType MT)> F) {
    for (unsigned N : {1, 2, 4, 8, 16, 32, 64}) {
      F(MaskType{N});
    }
  }
};

struct MaskTypeDef {
  const MaskType MT;

  void Write(raw_ostream &OS) const {
    OS << "typedef __attribute__((riscv_mask_type(" << MT.N;
    OS << "))) bool " << MT << ";";
  }
};

struct VectorTupleDef {
  const VectorType VT;
  const unsigned N;

  void Write(raw_ostream &OS) const {
    OS << "typedef struct {\n";

    for (unsigned I = 0; I < N; ++I) {
      OS << "  " << VT << " v" << I << ";\n";
    }

    OS << "} v" << VT.BT.Abbr() << VT.SEW << "m" << VT.LMUL.LowerCase();
    OS << "x" << N << "_t;";
  }

  static void Enum(VectorType VT, function_ref<void(VectorTupleDef Def)> F) {
    for (unsigned N : {2, 3, 4, 5, 6, 7, 8}) {
      F({VT, N});
    }
  }
};

struct ConstantEDef {
  const StdElemWidth SEW;

  void Write(raw_ostream &OS) const {
    OS << "#define _E" << SEW << " " << SEW.GetEncoding();
  }
};

struct ConstantMDef {
  const LengthMultiplier LMUL;

  void Write(raw_ostream &OS) const {
    OS << "#define _M" << LMUL.UpperCase() << " " << LMUL.GetEncoding();
  }
};

struct GeneratorParams {
  const Optional<BaseType> &Base;
  const Optional<StdElemWidth> &SEW;
  const Optional<LengthMultiplier> &LMUL;
  const Optional<unsigned> &TupleN;
  const bool HasMask;
  const bool MaskedOff;
  const bool HasVL;

  auto Format(StringRef Str) const {
    struct {
      StringRef Str;
      const GeneratorParams &GP;

      void Write(raw_ostream &OS) const {
        (Many(MatchNot('%', WriteChar(OS))                                    //
              | (Match('%'),                                                  //
                 ((Match('b'), Act([&] { OS << GP.Base->SingleLetter(); }))   //
                  | (Match('s'), Act([&] { OS << *GP.SEW; }))                 //
                  | (Match('l'), Act([&] { OS << GP.LMUL->LowerCase(); }))    //
                  | (Match('L'), Act([&] { OS << GP.LMUL->UpperCase(); }))))) //
         && EofOrFail("Failed to format `", Str, "'"))(Str.data());
      }
    } Wrapper{Str, *this};

    return Wrapper;
  }

  auto Vector() const {
    assert(Base.hasValue());
    assert(SEW.hasValue());
    assert(LMUL.hasValue());
    return VectorType{*Base, *SEW, *LMUL};
  }

  auto Element() const {
    assert(Base.hasValue());
    assert(SEW.hasValue());
    return ElementType{*Base, *SEW};
  }

  auto Mask() const {
    assert(LMUL.hasValue());
    assert(SEW.hasValue());
    unsigned Length = LMUL->IsFract() ? (SEW->GetWidth() / LMUL->GetMul())
                                      : (SEW->GetWidth() * LMUL->GetMul());
    return MaskType{Length};
  }
};

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

  StringRef RawSpec;
  DenseSet<StringRef> Prefixes;
  DenseSet<StringRef> Postfixes;
  std::string Base;
  SpecClass SC;

  TypeSpecifier(StringRef Text) : RawSpec(Text), SC(ATOM) {
    (Many((Match('U'), InsertPrefix("unsigned"))),
     ((Match('v'), SetBase("void"))                                           //
      | (Match('b'), SetBase("bool"))                                         //
      | (Match('c'), SetBase("int8_t"))                                       //
      | (Match('s'), SetBase("int16_t"))                                      //
      | (Match('i'), SetBase("int32_t"))                                      //
      | (Match('l'), SetBase("int64_t"))                                      //
      | (Match('h'), SetBase("float16_t"))                                    //
      | (Match('f'), SetBase("float"))                                        //
      | (Match('d'), SetBase("double"))                                       //
      | (Match('z'), SetBase("size_t"))                                       //
      | (Match('e'), Act([&] { SC = DEPENDENT; }))                            //
      | (Match('q'), Act([&] { SC = VECTOR; }))),                             //
     Many((Match('*'), InsertPostfix("*"))                                    //
          | (Match('&'), InsertPostfix("&"))                                  //
          | (Match('C'), InsertPostfix("const"))                              //
          | (Match('D'), InsertPostfix("volatile")))                          //
         && EofOrFail("Failed to parse the type specification `", Text, "'")) //
        (Text.data());
  }

  bool IsOverloaded() const {
    if (Postfixes.count("*"))
      return true;

    if (SC == ATOM && Base == "size_t")
      return true;

    return false;
  }

  auto Abbr(const GeneratorParams &GP) const {
    struct {
      const GeneratorParams &GP;
      const TypeSpecifier &Spec;

      void Write(raw_ostream &OS) const {
        Many((Match('q'), Act([&] { OS << GP.Vector().Abbr(); }))    //
             | (Match('e'), Act([&] { OS << GP.Element().Abbr(); })) //
             | WriteChar(OS))                                        //
            (Spec.RawSpec.data());
      }
    } Wrapper{GP, *this};

    return Wrapper;
  }

  // Used in parameters' types in intrinsics' signatures.
  auto ConcreteType(const GeneratorParams &GP) const {
    struct {
      const GeneratorParams &GP;
      const TypeSpecifier &Spec;

      void Write(raw_ostream &OS) const {
        if (Spec.SC == VECTOR) {
          OS << "v" << GP.Base->Abbr() << *GP.SEW;
          OS << "m" << GP.LMUL->LowerCase();

          if (GP.TupleN.hasValue())
            OS << "v" << *GP.TupleN;

          OS << "_t";
        } else {
          if (Spec.Postfixes.count("const"))
            OS << "const ";

          if (Spec.Prefixes.count("unsigned"))
            OS << "unsigned ";

          if (Spec.SC == ATOM)
            OS << Spec.Base;
          else
            OS << GP.Element();

          if (Spec.Postfixes.count("*"))
            OS << "*";
          else if (Spec.Postfixes.count("&"))
            OS << "&";

          if (Spec.Postfixes.count("volatile"))
            OS << " volatile";
        }
      }
    } Wrapper{GP, *this};

    return Wrapper;
  }
};

class RISCVBuiltin {
private:
  auto InsertAttr(const char *Attr) {
    return Act([&, Attr] { Attributes.push_back(Attr); });
  };

public:
  RISCVBuiltin(const Record *Rec)
      : Name(Rec->getValueAsString("Name")),
        AttrStr(Rec->getValueAsString("Attributes")),
        MayMask(Rec->getValueAsBit("MayMask")),
        MaskedOff(Rec->getValueAsBit("MaskedOff")),
        HasVL(Rec->getValueAsBit("HasVL")),
        Body(Rec->getValue("Body")->getValue()->getAsUnquotedString()),
        GenIntrinsic(Rec->getValueAsBit("GenIntrinsic")),
        GenBuiltin(Rec->getValueAsBit("GenBuiltin")), BasePolymorphic(false),
        SEWPolymorphic(false), LMULPolymorphic(false), TuplePolymorphic(false) {

    for (StringRef Type : Rec->getValueAsListOfStrings("Prototype"))
      Prototype.emplace_back(Type);

    Attributes.push_back("always_inline");

    (Many((Match('n'), InsertAttr("nothrow"))                            //
          | (Match('r'), InsertAttr("noreturn"))                         //
          | (Match('U'), InsertAttr("pure"))                             //
          | (Match('c'), InsertAttr("const")))                           //
     && EofOrFail("Failed to parse the attribute list `", AttrStr, "'")) //
        (AttrStr.data());

    CheckPolymorphism(Name);
    CheckPolymorphism(Body);
  }

  void Write(raw_ostream &OS) const {
    if (GenIntrinsic) {
      OS << "// Intrinsics for " << Name << "\n\n";
      WriteAll([&](const GeneratorParams &GP) {
        if (Attributes.size()) {
          OS << "static __attribute__((";

          for (unsigned I = 0, E = Attributes.size(); I != E; ++I) {
            if (I != 0)
              OS << ", ";

            OS << Attributes[I];
          }

          OS << "))\n";
        }

        assert(Prototype.size());
        const TypeSpecifier &RetTy = Prototype[0];

        OS << RetTy.ConcreteType(GP) << " ";
        OS << GP.Format(Name);

        if (GP.HasMask)
          OS << "_m";

        if (GP.HasVL)
          OS << "_vl";

        OS << "(";

        if (GP.HasMask) {
          OS << GP.Mask() << " mask";

          if (GP.MaskedOff) {
            OS << GP.Vector() << " maskedoff, ";
          }
        }

        for (unsigned I = 1, E = Prototype.size(); I != E; ++I) {
          const TypeSpecifier &Spec = Prototype[I];
          OS << Spec.ConcreteType(GP);

          OS << " arg" << I;

          if (I + 1 != E)
            OS << ", ";
        }

        if (GP.HasVL)
          OS << ", size_t vl";

        OS << ") {\n  ";

        if (Body.empty()) {
          if (HasVL)
            OS << GP.Format("vsetvl_e%s%l") << "(vl);\n  ";

          if (RetTy.Base != "void")
            OS << "return ";

          OS << "__builtin_riscv_";

          OS << GP.Format(Name);

          OS << "(";

          if (GP.HasMask) {
            OS << "mask, ";

            if (GP.MaskedOff)
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

        OS << "\n\n";
      });
    }
  }

  auto Builtin() const {
    struct {
      const RISCVBuiltin &RB;

      void Write(raw_ostream &OS) const {
        if (RB.GenBuiltin) {
          OS << "// Builtins for " << RB.Name << "\n\n";

          RB.WriteAll([&](const GeneratorParams &GP) {
            OS << "RISCVBuiltin(";

            OS << GP.Format(RB.Name);

            if (GP.HasMask)
              OS << "_m";

            if (GP.HasVL)
              OS << "_vl";

            OS << ", \"";

            OS << RB.Prototype[0].Abbr(GP);

            if (GP.HasMask) {
              OS << GP.Mask().Abbr();

              if (GP.MaskedOff)
                OS << GP.Vector().Abbr();
            }

            for (unsigned I = 1, E = RB.Prototype.size(); I < E; ++I)
              OS << RB.Prototype[I].Abbr(GP);

            OS << "\", \"" << RB.AttrStr << "\", ";

            SeparatedBy SOS{OS, ", "};
            for (unsigned I = 0, E = RB.Prototype.size(); I < E; ++I) {
              if (RB.Prototype[I].IsOverloaded())
                SOS << I;
            }

            OS << ")";

            OS << "\n\n";
          });
        }
      }
    } Wrapper{*this};

    return Wrapper;
  }

private:
  void CheckPolymorphism(StringRef Str) {
    (Many((MatchNot('%', [&](auto Text) { return ++Text; }))          //
          | (Match('%'),                                              //
             ((Match('b'), Act([&] { BasePolymorphic = true; }))      //
              | (Match('s'), Act([&] { SEWPolymorphic = true; }))     //
              | (Match('l'), Act([&] { LMULPolymorphic = true; }))    //
              | (Match('L'), Act([&] { LMULPolymorphic = true; }))))) //
     && EofOrFail("Failed to check polymorphism in `", Str, "'"))     //
        (Str.data());
  }

  void WriteAll(function_ref<void(const GeneratorParams &)> G) const {
    using namespace std::placeholders;

    auto Yield = [=](auto... Args) {
      G({Args..., false, false, false});

      if (HasVL)
        G({Args..., false, false, true});

      if (MayMask) {
        G({Args..., true, MaskedOff, false});

        if (HasVL)
          G({Args..., false, MaskedOff, true});
      }
    };

    auto YieldTuple = [=](auto... Args) {
      if (TuplePolymorphic) {
        for (unsigned N : {2, 3, 4, 5, 6, 7, 8})
          Yield(Args..., N);
      } else
        Yield(Args..., None);
    };

    auto YieldLMUL = [=](Optional<BaseType> BT, Optional<StdElemWidth> SEW) {
      auto YT = std::bind(YieldTuple, BT, SEW, _1);

      if (LMULPolymorphic) {
        if (SEW.hasValue())
          LengthMultiplier::Enum(*SEW, YT);
        else
          LengthMultiplier::Enum(YT);
      } else
        YT(None);
    };

    auto YieldSEW = [=](Optional<BaseType> BT) {
      auto YL = std::bind(YieldLMUL, BT, _1);

      if (SEWPolymorphic) {
        if (BT.hasValue())
          StdElemWidth::Enum(*BT, YL);
        else
          StdElemWidth::Enum(YL);
      } else
        YL(None);
    };

    if (BasePolymorphic)
      BaseType::Enum(YieldSEW);
    else
      YieldSEW(None);
  }

private:
  StringRef Name;
  std::vector<TypeSpecifier> Prototype;
  std::vector<StringRef> Attributes;
  StringRef AttrStr;
  bool MayMask;
  bool MaskedOff;
  bool HasVL;
  std::string Body;
  bool GenIntrinsic;
  bool GenBuiltin;
  bool BasePolymorphic;
  bool SEWPolymorphic;
  bool LMULPolymorphic;
  bool TuplePolymorphic;
};

} // namespace

namespace clang {

void EmitRISCVVectorHeader(RecordKeeper &Keeper, raw_ostream &OS) {
  SkipWhiteSpace{OS} << R"(
/*===---- riscv_vector.h - RISC-V Vector Extensions ------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __RISCV_VECTOR_H__
#define __RISCV_VECTOR_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

)";

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

  // Emit definitions of all intrinsics.
  for (const Record *Rec : Keeper.getAllDerivedDefinitions("RISCVBuiltin"))
    OS << RISCVBuiltin(Rec);

  OS << "#endif\n";
}

// Emit content needed by BuiltinsRISCV.td and CGBuiltin.cpp
void EmitRISCVBuiltins(RecordKeeper &Keeper, raw_ostream &OS) {
  for (const Record *Rec : Keeper.getAllDerivedDefinitions("RISCVBuiltin"))
    OS << RISCVBuiltin(Rec).Builtin();

  OS << "#undef RISCVBuiltin\n";
}

} // namespace clang

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
  return [=](const char *Text) { //
    return *Text && *Text != C ? P(Text) : nullptr;
  };
}

constexpr auto Match(const char *Str) {
  return [=](const char *Text) {
    const char *Cursor = Str;

    while (*Cursor && *Cursor == *Text) {
      ++Cursor;
      ++Text;
    };

    return *Cursor ? nullptr : Text;
  };
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

template <typename U, typename V> //
constexpr auto BindValue(U &X, V Y) {
  return Act([&, Y] { X = Y; });
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

  void Write(raw_ostream &OS) const {
    if (BT.IsFloatingPoint()) {
      switch (SEW.GetWidth()) {
      case 16:
        OS << "llvm_half_ty";
        break;
      case 32:
        OS << "llvm_float_ty";
        break;
      case 64:
        OS << "llvm_double_ty";
        break;
      default:
        llvm_unreachable("Unhandled SEW");
      }
    } else {
      OS << "llvm_i" << SEW << "_ty";
    }
  }
};

struct VectorType {
  const BaseType BT;
  const StdElemWidth SEW;
  const LengthMultiplier LMUL;

  void Write(raw_ostream &OS) const {
    OS << "llvm_nxv" << LMUL.LowerCase() << BT.SingleLetter() << SEW << "_t";
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

  auto LLVMType() const {
    struct {
      const MaskType &MT;

      void Write(raw_ostream &OS) const { OS << "llvm_v" << MT.N << "i1"; }
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

class TypeSpecifier {
public:
  enum SpecClass { ATOM, VECTOR, DEPENDENT };
  StringRef Base;
  SpecClass SC;

  TypeSpecifier(StringRef Text) : SC(ATOM) {
    (((Match('v'), BindValue(Base, "llvm_void_ty"))               //
      | (Match('q'), BindValue(SC, VECTOR))                       //
      | (Match('e'), BindValue(SC, DEPENDENT))                    //
      | (Match('*'), BindValue(Base, "llvm_anyptr_ty"))           //
      | (Match('i'),                                              //
         (Match('a'), BindValue(Base, "llvm_anyint_ty"))          //
             | (Match('8'), BindValue(Base, "llvm_i8_ty"))        //
             | (Match("16"), BindValue(Base, "llvm_i16_ty"))      //
             | (Match("32"), BindValue(Base, "llvm_i32_ty"))      //
             | (Match("64"), BindValue(Base, "llvm_i64_ty")))     //
      | (Match('f'),                                              //
         (Match('a'), BindValue(Base, "llvm_anyfloat_ty"))        //
             | (Match("16"), BindValue(Base, "llvm_half_ty"))     //
             | (Match("32"), BindValue(Base, "llvm_float_ty"))    //
             | (Match("64"), BindValue(Base, "llvm_double_ty")))) //
     && EofOrFail("Failed to parse the type spec: '", Text, "'")) //
        (Text.data());
  }

  bool IsVoid() const { return Base == "llvm_void_ty"; }

  auto LLVMType(const GeneratorParams &GP) const {
    struct {
      const GeneratorParams &GP;
      const TypeSpecifier &Spec;

      void Write(raw_ostream &OS) const {
        if (Spec.SC == VECTOR) {
          OS << GP.Vector();
        } else if (Spec.SC == DEPENDENT) {
          OS << GP.Element();
        } else {
          OS << Spec.Base;
        }
      }
    } Wrapper{GP, *this};

    return Wrapper;
  }
};

class RISCVIntrinsic {
private:
  auto InsertProperty(const char *P) {
    return Act([&, P] { Properties.push_back(P); });
  };

public:
  RISCVIntrinsic(const Record *Rec)
      : Name(Rec->getValueAsString("Name")),
        MayMask(Rec->getValueAsBit("MayMask")),
        MaskedOff(Rec->getValueAsBit("MaskedOff")),
        HasVL(Rec->getValueAsBit("HasVL")), BasePolymorphic(false),
        SEWPolymorphic(false), LMULPolymorphic(false), TuplePolymorphic(false) {

    for (StringRef Type : Rec->getValueAsListOfStrings("Prototype"))
      Prototype.emplace_back(Type);

    StringRef PropStr = Rec->getValueAsString("Properties");

    (Many((Match('n'), InsertProperty("IntrNoMem"))                //
          | (Match('r'), InsertProperty("IntrReadMem"))            //
          | (Match('w'), InsertProperty("IntrWriteMem"))           //
          | (Match('s'), InsertProperty("IntrHasSideEffects")))    //
     && EofOrFail("Failed to parse the property list: ", PropStr)) //
        (PropStr.data());

    CheckPolymorphism(Name);
  }

  void Write(raw_ostream &OS) const {
    WriteAll([&](const GeneratorParams &GP) {
      OS << "def int_riscv_" << GP.Format(Name);

      if (GP.HasMask)
        OS << "_m";

      if (GP.HasVL)
        OS << "_vl";

      OS << "\n";
      OS << "  : Intrinsic<[";

      const TypeSpecifier &RetSpec = Prototype[0];
      if (!RetSpec.IsVoid())
        OS << RetSpec.LLVMType(GP);

      OS << "],\n";
      OS << "              [";

      {
        SeparatedBy SOS{OS, ", "};

        if (GP.HasMask) {
          SOS << GP.Mask().LLVMType();

          if (GP.MaskedOff)
            SOS << GP.Vector();
        }

        for (unsigned I = 1, E = Prototype.size(); I < E; ++I)
          SOS << Prototype[I].LLVMType(GP);
      }

      OS << "],\n";

      OS << "              [";

      {
        SeparatedBy SOS{OS, ", "};

        for (unsigned I = 0, E = Properties.size(); I < E; ++I)
          SOS << Properties[I];
      }

      OS << "]>;";
      OS << "\n\n";
    });
  }

private:
  void CheckPolymorphism(StringRef Str) {
    (Many((MatchNot('%', [&](auto Text) { return ++Text; }))           //
          | (Match('%'),                                               //
             ((Match('b'), Act([&] { BasePolymorphic = true; }))       //
              | (Match('s'), Act([&] { SEWPolymorphic = true; }))      //
              | (Match('l'), Act([&] { LMULPolymorphic = true; }))     //
              | (Match('L'), Act([&] { LMULPolymorphic = true; }))     //
              | (Match('L'), Act([&] { TuplePolymorphic = true; }))))) //
     && EofOrFail("Failed to check polymorphism in `", Str, "'"))(Str.data());
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
  std::vector<StringRef> Properties;
  bool MayMask;
  bool MaskedOff;
  bool HasVL;
  bool BasePolymorphic;
  bool SEWPolymorphic;
  bool LMULPolymorphic;
  bool TuplePolymorphic;
};

} // namespace

namespace llvm {

// Emit content needed by BuiltinsRISCV.td and CGBuiltin.cpp
void EmitRISCVIntrinsics(RecordKeeper &Keeper, raw_ostream &OS) {
  for (const Record *Rec : Keeper.getAllDerivedDefinitions("RISCVIntrinsic"))
    OS << RISCVIntrinsic(Rec);
}

} // namespace llvm

#include "llvm/Support/MathExtras.h"
#include "llvm/TableGen/Record.h"
#include <cctype>

namespace {

using namespace llvm;

// Interface for writable objects.
template <typename T>
auto operator<<(raw_ostream &OS, const T &Object)
    -> decltype(Object.Write(OS), OS) {
  Object.Write(OS);
  return OS;
}

// Tool for writing ad hoc tests.
struct UnitTest {
  UnitTest(function_ref<void()> F) { F(); }
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

struct BaseType {
  enum { INTEGER, UNSIGNED_INTEGER, FLOATING_POINT };

  int ID;

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

  auto CType() const {
    struct {
      const BaseType &BT;

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

  auto LLVMSingleLetter() const {
    struct {
      const BaseType &BT;

      void Write(raw_ostream &OS) const {
        switch (BT.ID) {
        case INTEGER:
          OS << "i";
          break;
        case UNSIGNED_INTEGER:
          OS << "i";
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

  auto LowerCase() const {
    struct {
      const LengthMultiplier &LMUL;

      void Write(raw_ostream &OS) const {
        OS << (LMUL.IsFract ? "f" : "") << LMUL.Mul;
      }
    } Wrapper{*this};

    return Wrapper;
  }

  auto UpperCase() const {
    struct {
      const LengthMultiplier &LMUL;

      void Write(raw_ostream &OS) const {
        OS << (LMUL.IsFract ? "F" : "") << LMUL.Mul;
      }
    } Wrapper{*this};

    return Wrapper;
  }

  static void Enum(function_ref<void(LengthMultiplier LMUL)> F) {
    for (unsigned Mul : {1, 2, 4, 8}) {
      F({Mul, false});

      // for (unsigned Mul : {2, 4, 8}) {
      //   F({Mul, true});
      // }
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

struct ElementType {
  BaseType BT;
  StdElemWidth SEW;

  void Write(raw_ostream &OS) const {
    if (BT.ID == BaseType::FLOATING_POINT) {
      switch (SEW.Width) {
      case 16:
        OS << "float16_t";
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
    } else {
      switch (SEW.Width) {
      case 8:
        OS << "char";
        break;
      case 16:
        OS << "short";
        break;
      case 32:
        OS << "int";
        break;
      case 64:
        OS << "long int";
        break;
      default:
        llvm_unreachable("Unhandled SEW");
      }
    }
  }

  auto Abbr() const {
    struct {
      const ElementType &AT;

      void Write(raw_ostream &OS) const {
        if (AT.BT.ID == BaseType::FLOATING_POINT) {
          switch (AT.SEW.Width) {
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
          switch (AT.SEW.Width) {
          case 8:
            OS << "c";
            break;
          case 16:
            OS << "s";
            break;
          case 32:
            OS << "i";
            break;
          case 64:
            OS << "i";
            break;
          default:
            llvm_unreachable("Unhandled SEW");
          }
        }
      }
    } Wrapper{*this};
    return Wrapper;
  }

  auto LLVMType() const {
    struct {
      const ElementType &ET;

      void Write(raw_ostream &OS) const {
        if (ET.BT.ID == BaseType::FLOATING_POINT) {
          switch (ET.SEW.Width) {
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
          OS << "llvm_i" << ET.SEW << "_ty";
        }
      }
    } Wrapper{*this};
    return Wrapper;
  }
};

struct VectorType {
  BaseType BT;
  StdElemWidth SEW;
  LengthMultiplier LMUL;

  void Write(raw_ostream &OS) const {
    OS << "v" << BT.Abbr() << SEW << "m" << LMUL.LowerCase() << "_t";
  }

  auto LLVMType() const {
    struct {
      const VectorType &VT;

      void Write(raw_ostream &OS) const {
        if (VT.LMUL.IsFract)
          llvm_unreachable("Fractional LMUL not supported at the moment");

        OS << "llvm_nxv" << VT.LMUL.LowerCase();

        OS << VT.BT.LLVMSingleLetter() << VT.SEW << "_ty";
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
  VectorType VT;

  void Write(raw_ostream &OS) const {
    OS << "typedef __attribute__((riscv_vector_type(" << VT.SEW;
    OS << ", " << VT.LMUL.Mul;
    OS << ", " << (VT.LMUL.IsFract ? "1" : "0") << ")))";
    OS << " " << VT.BT.CType() << " " << VT << ";";
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
  StdElemWidth SEW;

  void Write(raw_ostream &OS) const {
    OS << "#define _E" << SEW << " " << SEW.Encoding();
  }
};

struct ConstantMDef {
  LengthMultiplier LMUL;

  void Write(raw_ostream &OS) const {
    OS << "#define _M" << LMUL.UpperCase() << " " << LMUL.Encoding();
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
      const GeneratorParams &GP;

      void Write(raw_ostream &OS) const {
        (Many((MatchNot('%', WriteChar(OS))) //
              |
              (Match('%'),                                                   //
               ((Match('b'), Act([&] { OS << GP.Base->SingleLetter(); }))    //
                | (Match('s'), Act([&] { OS << *GP.SEW; }))                  //
                | (Match('l'), Act([&] { OS << GP.LMUL->LowerCase(); }))     //
                | (Match('L'), Act([&] { OS << GP.LMUL->UpperCase(); }))))), //
         EofOrFail("Failed to format `", Str, "'"))(Str.data());
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

  auto Element() const { return ElementType{*Base, *SEW}; }

  unsigned MaskLength() const {
    assert(LMUL.hasValue());
    assert(SEW.hasValue());
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

  StringRef RawSpec;
  DenseSet<StringRef> Prefixes;
  DenseSet<StringRef> Postfixes;
  std::string Base;
  SpecClass SC;

  TypeSpecifier(StringRef Text) : RawSpec(Text), SC(ATOM) {
    (Many((Match('U'), InsertPrefix("unsigned"))),
     ((Match('v'), SetBase("void"))                                    //
      | (Match('b'), SetBase("bool"))                                  //
      | (Match('c'), SetBase("int8_t"))                                //
      | (Match('s'), SetBase("int16_t"))                               //
      | (Match('i'), SetBase("int32_t"))                               //
      | (Match('l'), SetBase("int64_t"))                               //
      | (Match('h'), SetBase("float16_t"))                             //
      | (Match('f'), SetBase("float32_t"))                             //
      | (Match('d'), SetBase("float64_t"))                             //
      | (Match('z'), SetBase("size_t"))                                //
      | (Match('e'), Act([&] { SC = DEPENDENT; }))                     //
      | (Match('q'), Act([&] { SC = VECTOR; }))),                      //
     Many((Match('*'), InsertPostfix("*"))                             //
          | (Match('&'), InsertPostfix("&"))                           //
          | (Match('C'), InsertPostfix("const"))                       //
          | (Match('D'), InsertPostfix("volatile"))),                  //
     EofOrFail("Failed to parse the type specification `", Text, "'")) //
        (Text.data());
  }

  auto Abbr(const GeneratorParams &GP) const {
    struct {
      const GeneratorParams &GP;
      const TypeSpecifier &Spec;

      void Write(raw_ostream &OS) const {
        Many((Match('q'), Act([&] {
                OS << "q";
                if (GP.LMUL->IsFract)
                  llvm_unreachable(
                      "Fractional LMUL not supported at the moment");
                OS << GP.LMUL->Mul;
                OS << ElementType{*GP.Base, *GP.SEW}.Abbr();
              })) |
             (Match('e'), Act([&] {
                OS << ElementType{*GP.Base, *GP.SEW}.Abbr();
              }))             //
             | WriteChar(OS)) //
            (Spec.RawSpec.data());
      }
    } Wrapper{GP, *this};

    return Wrapper;
  }

  auto LLVMType(const GeneratorParams &GP) const {
    struct {
      const GeneratorParams &GP;
      const TypeSpecifier &Spec;

      void Write(raw_ostream &OS) const {
        ((Match('q'), Act([&] { OS << GP.Vector().LLVMType(); }))    //
         | (Match('e'), Act([&] { OS << GP.Element().LLVMType(); })) //
         | [&](const char *Text) {
             if (Spec.Postfixes.count("*")) {
               OS << "llvm_ptr_ty";
               return nullptr;
             }

             auto WriteStr = [&](const char *Str) {
               return Act([&, Str] { OS << Str; });
             };

             return (Maybe(Match('U')),                          //
                     ((Match('v'), WriteStr("llvm_void_ty"))     //
                      | (Match('b'), WriteStr("llvm_i1_ty"))     //
                      | (Match('c'), WriteStr("llvm_i8_ty"))     //
                      | (Match('s'), WriteStr("llvm_i16_ty"))    //
                      | (Match('i'), WriteStr("llvm_i32_ty"))    //
                      | (Match('l'), WriteStr("llvm_i64_ty"))    //
                      | (Match('h'), WriteStr("llvm_half_ty"))   //
                      | (Match('f'), WriteStr("llvm_float_ty"))  //
                      | (Match('d'), WriteStr("llvm_double_ty")) //
                      | (Match('z'), WriteStr("llvm_anyint_ty"))),
                     (Many(Match('*')   //
                           | Match('&') //
                           | Match('C') //
                           | (Match('D')))),
                     EofOrFail("Failed parse the prototype")) //
                 (Text);
           })(Spec.RawSpec.data());
      }
    } Wrapper{GP, *this};

    return Wrapper;
  }

  auto ConcreteType(const GeneratorParams &GP) const {
    struct {
      const GeneratorParams &GP;
      const TypeSpecifier &Spec;

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
          OS << "v" << GP.Base->Abbr() << *GP.SEW;
          OS << "m" << GP.LMUL->LowerCase();

          if (GP.TupleN.hasValue())
            OS << "v" << *GP.TupleN;

          OS << "_t";
        } break;
        case DEPENDENT: {
          if (Spec.Postfixes.count("const"))
            OS << "const ";

          OS << GP.Base->Abbr() << *GP.SEW << "_t";

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

// Ad hoc tests for parsing type specification.
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

class RISCVBuiltin {
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

    for (StringRef Type : Rec->getValueAsListOfStrings("Prototype")) {
      Prototype.emplace_back(Type);
    }

    auto InsertAttr = [&](const char *Attr) {
      return Act([&, Attr] { Attributes.push_back(Attr); });
    };

    Attributes.push_back("always_inline");

    (Many((Match('n'), InsertAttr("nothrow"))                         //
          | (Match('r'), InsertAttr("noreturn"))                      //
          | (Match('U'), InsertAttr("pure"))                          //
          | (Match('c'), InsertAttr("const"))),                       //
     EofOrFail("Failed to parse the attribute list `", AttrStr, "'")) //
        (AttrStr.data());

    auto InsertProp = [&](const char *Prop) {
      return Act([&, Prop] { Properties.push_back(Prop); });
    };

    (Many((Match('n'), InsertProp("IntrNoMem"))              //
          | (Match('r'), InsertProp("IntrReadMem"))          //
          | (Match('w'), InsertProp("IntrWriteMem"))         //
          | (Match('s'), InsertProp("IntrHasSideEffects"))), //
     EofOrFail("Failed to parse the property list"))         //
        (Rec->getValueAsString("Properties").data());

    CheckPolymorphism(Name);
    CheckPolymorphism(Body);
  }

  void Write(raw_ostream &OS) const {
    if (GenIntrinsic) {
      OS << "// Intrinsics for " << Name << "\n\n";

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
  }

  auto Builtin() const {
    struct {
      const RISCVBuiltin &RB;

      void Write(raw_ostream &OS) const {
        if (RB.GenBuiltin) {
          OS << "// Builtins for " << RB.Name << "\n\n";

          RB.Yield([&](GeneratorParams GP) {
            Write(OS, GP, false, false, false);
            OS << "\n\n";

            if (RB.HasVL) {
              Write(OS, GP, false, false, true);
              OS << "\n\n";
            }

            if (RB.MayMask) {
              Write(OS, GP, true, RB.MaskedOff, false);
              OS << "\n\n";

              if (RB.HasVL) {
                Write(OS, GP, false, RB.MaskedOff, true);
                OS << "\n\n";
              }
            }
          });
        }
      }

      void Write(raw_ostream &OS, GeneratorParams GP, bool HasMask,
                 bool MaskedOff, bool HasVL) const {
        OS << "RISCVBuiltin(";

        OS << GP.Format(RB.Name) << ", \"";

        for (const TypeSpecifier &Spec : RB.Prototype) {
          OS << Spec.Abbr(GP);
          // OS << Spec.ConcreteType(GP);
        }

        OS << "\", \"" << RB.AttrStr << "\")";
      }

    } Wrapper{*this};

    return Wrapper;
  }

  auto Intrinsic() const {
    struct {
      const RISCVBuiltin &RB;

      void Write(raw_ostream &OS) const {
        if (RB.GenBuiltin) {
          OS << "// Intrinsics for " << RB.Name << "\n\n";

          RB.Yield([&](GeneratorParams GP) {
            Write(OS, GP, false, false, false);
            OS << "\n\n";

            if (RB.HasVL) {
              Write(OS, GP, false, false, true);
              OS << "\n\n";
            }

            if (RB.MayMask) {
              Write(OS, GP, true, RB.MaskedOff, false);
              OS << "\n\n";

              if (RB.HasVL) {
                Write(OS, GP, false, RB.MaskedOff, true);
                OS << "\n\n";
              }
            }
          });
        }
      }

      void Write(raw_ostream &OS, GeneratorParams GP, bool HasMask,
                 bool MaskedOff, bool HasVL) const {

        OS << "def int_riscv_" << GP.Format(RB.Name) << "\n";
        OS << "    : Intrinsic<[" << RB.Prototype[0].LLVMType(GP) << "],\n";
        OS << "                [";

        for (unsigned I = 1, E = RB.Prototype.size(); I < E; ++I) {
          if (I != 1)
            OS << ", ";

          OS << RB.Prototype[I].LLVMType(GP);
        }

        OS << "],\n";
        OS << "                [";

        for (unsigned I = 0, E = RB.Properties.size(); I < E; ++I) {
          if (I != 0)
            OS << ", ";

          OS << RB.Properties[I];
        }

        OS << "]>;";
      }
    } Wrapper{*this};

    return Wrapper;
  }

private:
  void CheckPolymorphism(StringRef Str) {
    (Many((MatchNot('%', [&](auto Text) { return ++Text; }))            //
          | (Match('%'),                                                //
             ((Match('b'), Act([&] { BasePolymorphic = true; }))        //
              | (Match('s'), Act([&] { SEWPolymorphic = true; }))       //
              | (Match('l'), Act([&] { LMULPolymorphic = true; }))      //
              | (Match('L'), Act([&] { LMULPolymorphic = true; }))      //
              | (Match('L'), Act([&] { TuplePolymorphic = true; }))))), //
     EofOrFail("Failed to check polymorphism in `", Str, "'"))(Str.data());
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

  void Write(raw_ostream &OS, GeneratorParams GP, bool HasMask, bool MaskedOff,
             bool HasVL) const {

    if (Attributes.size()) {
      // OS << "static __attribute__((always_inline, nothrow))\n";
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

    if (HasMask)
      OS << "_m";

    if (HasVL)
      OS << "_vl";

    OS << "(";

    if (HasMask) {
      OS << "vbool" << GP.MaskLength() << "_t mask, ";

      if (MaskedOff) {
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

    if (HasVL)
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

private:
  StringRef Name;
  std::vector<TypeSpecifier> Prototype;
  std::vector<StringRef> Attributes;
  StringRef AttrStr;
  bool MayMask;
  bool MaskedOff;
  bool HasVL;
  std::string Body;
  std::vector<StringRef> Properties;
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
  for (const Record *Rec : Keeper.getAllDerivedDefinitions("RISCVBuiltin")) {
    OS << RISCVBuiltin(Rec) << "\n\n";
  }

  SkipWhiteSpace{OS} << R"(
#endif
)";
}

void EmitRISCVBuiltins(RecordKeeper &Keeper, raw_ostream &OS) {
  for (const Record *Rec : Keeper.getAllDerivedDefinitions("RISCVBuiltin")) {
    OS << RISCVBuiltin(Rec).Builtin() << "\n\n";
  }

  SkipWhiteSpace{OS} << R"(
#undef RISCVBuiltin
)";
}

void EmitRISCVIntrinsics(RecordKeeper &Keeper, raw_ostream &OS) {
  for (const Record *Rec : Keeper.getAllDerivedDefinitions("RISCVBuiltin")) {
    OS << RISCVBuiltin(Rec).Intrinsic() << "\n\n";
  }
}

} // namespace clang

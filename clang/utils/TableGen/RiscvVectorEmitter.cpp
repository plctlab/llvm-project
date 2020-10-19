#include "llvm/TableGen/Record.h"
#include "llvm/ADT/SmallVector.h"
#include <sstream>
#include <string>
#include <ctype.h>

using namespace llvm;

class Intrinsic;
class RISCVVectorType;

class RISCVVectorEmitter {
private:
  RecordKeeper &Records;

public:
  RISCVVectorEmitter(RecordKeeper &R) : Records(R) {}

  void createHeader(raw_ostream &OS);

  void createBuiltinCG(raw_ostream &OS);

  void createBuiltins(raw_ostream &OS);

  void createIntrinsic(Record *R, std::vector<std::shared_ptr<Intrinsic>>& Out);

};

class Intrinsic {
private:
  // The name fo the intrinsic
  std::string Name;
  
  // The type string of the intrinsic
  std::vector<std::shared_ptr<RISCVVectorType>> Types;

  // The "_vx", "_vv" like infix
  std::string Infix;

  // The "i8mf8" like suffix
  std::string Suffix;

  // The any type operands
  std::vector<int64_t> AnyTypeOperands;

  bool MaskBit;

  // If not empty, the emitter will use it to define the intrinsic function.
  // Otherwise, the emitter will generate intrinsic in the default way.
  std::string CustomDef;

public:

  std::string getName() { return Name; }

  std::vector<std::shared_ptr<RISCVVectorType>>& getTypes() { return Types; }
  std::string getInfix() { return Infix; }
  std::string getSuffix() { return Suffix; }

  std::vector<int64_t> getAnyTypeOperand() { return AnyTypeOperands; }

  // FixMe: for stride index load or store
  bool isLoadOrStore() { return (Name.find("vle") != std::string::npos 
                      || Name.find("vse") != std::string::npos
                      || Name.find("vlse") != std::string::npos 
                      || Name.find("vsse") != std::string::npos
                      || Name.find("vlxei") != std::string::npos
                      || Name.find("vsuxei") != std::string::npos
                      || Name.find("vsxei") != std::string::npos) && (Infix != ""); }
  
  bool isVsetvl() { return Name.find("vsetvl") != std::string::npos; }
  bool isMask() { return MaskBit; }

  std::string getCustomDef() { return CustomDef; }

  Intrinsic(StringRef Name, std::vector<std::shared_ptr<RISCVVectorType>> &Types,
            StringRef Infix, StringRef Suffix, std::vector<int64_t> &Operands,
            bool Mask, StringRef Def)
      : Name(Name.str()), Types(Types), Infix(Infix.str()), Suffix(Suffix),
        AnyTypeOperands(Operands), MaskBit(Mask), CustomDef(Def) {}

  std::string createStatementInCase();
};

class RISCVVectorType {
private:
  std::string BuiltinStr;

public:
  RISCVVectorType(std::string Str) : BuiltinStr(Str) {}

  std::string getBuiltinStr() { return BuiltinStr; }

  std::string parseTypeName();
};

std::string RISCVVectorType::parseTypeName() {
  std::string Builtin = BuiltinStr;
  if (Builtin[0] != 'q') {
    std::string TypeName;
    switch (Builtin[0]) {
      case 'z':
        TypeName = "size_t";
        break;
      case 'v':
        TypeName = "void";
        break;
      case 'c':
        TypeName = "int8_t";
        break;
      case 's':
        TypeName = "int16_t";
        break;
      case 'i':
        TypeName = "int32_t";
        break;
      case 'Z':
        assert(Builtin[1] == 'i');
        Builtin = Builtin.substr(1, Builtin.size());
        TypeName = "int32_t";
        break;
      case 'W':
        assert(Builtin[1] == 'i');
        Builtin = Builtin.substr(1, Builtin.size());
        TypeName = "int64_t";
        break;
      case 'f':
        TypeName = "float32_t";
        break;
      case 'd':
        TypeName = "float64_t";
        break;
      case 'h':
        TypeName = "float16_t";
        break;
      default:
        llvm_unreachable("unknown simple type");
    }
    Builtin = Builtin.substr(1, Builtin.size());
    while (Builtin.size() > 0) {
      switch (Builtin[0]) {
        case 'C':
          TypeName = "const " + TypeName;
          break;
        case '*':
          TypeName += "*";
          break;
        default:
          llvm_unreachable("unknown modifier");
      }
      Builtin = Builtin.substr(1, Builtin.size());
    }
    return TypeName;
  }
  std::vector<std::string> SplitedTypes;
  std::string::iterator ScanStart = BuiltinStr.begin();
  for (std::string::iterator iter = BuiltinStr.begin(), end = BuiltinStr.end();
        iter != end; iter++ ) {
    if (*iter == 'q') {
      SplitedTypes.push_back("q");
      continue;
    }
    if (isdigit(*iter)) {
      if (!isdigit(*ScanStart))
        ScanStart = iter;
      else 
        continue;
    }

    if (isalpha(*iter)) {
      if (isdigit(*ScanStart)) {
        SplitedTypes.push_back(std::string(ScanStart, iter));
        SplitedTypes.push_back(std::string(iter, end));
        break;
      } else {
        llvm_unreachable("Unsupported imm check");
      }
    }
  }

  int ElementWidth = 0;
  switch(SplitedTypes.back()[0]) {
    case 'c': {
      ElementWidth = 8;
      break;
    }
    case 's':
    case 'h':
      ElementWidth = 16;
      break;
    case 'i':
    case 'f':
    case 'Z':
      ElementWidth = 32;
      break;
    case 'W':
    case 'd':
      ElementWidth = 64;
      break;
    default:
      llvm_unreachable("unknown element type");
  }
  std::string SimpleType;
  switch(SplitedTypes.back().back()) {
    case 's':
    case 'c':
    case 'i':
    case 'W':
    case 'Z':
      SimpleType = "int";
      break;
    case 'f':
    case 'h':
    case 'd':
      SimpleType = "float";
      break;
  }

  int ElementNum = std::stoi(SplitedTypes[1]);
  std::string lmul = "";
  if (ElementNum * ElementWidth >= 64) {
    lmul = std::to_string((ElementWidth * ElementNum) / 64);
  } else {
    lmul = "f" + std::to_string(64 / (ElementWidth * ElementNum));
  }
  return "v" + SimpleType + std::to_string(ElementWidth) + "m" + lmul + "_t";
}

void RISCVVectorEmitter::createHeader(raw_ostream &OS) {
  OS << "#ifndef __RISCV_VECTOR_H__\n";
  OS << "#define __RISCV_VECTOR_H__\n";
  OS << "#include <stdbool.h>\n";
  OS << "#include <stddef.h>\n";
  OS << "#include <stdint.h>\n";
  OS << "// TODO: float16_t should be implemented based on RISC-V Zfh extension.\n";
  OS << "// See https://github.com/riscv/riscv-v-spec/issues/349.\n";
  OS << "typedef float float32_t;\n";
  OS << "typedef double float64_t;\n";
  OS << "#define _e8 0\n";
  OS << "#define _e16 4\n";
  OS << "#define _e32 8\n";
  OS << "#define _e64 12\n";
  OS << "#define _m1 0\n";
  OS << "#define _m2 1\n";
  OS << "#define _m4 2\n";
  OS << "#define _m8 3\n";
  OS << "#define _mf2 35\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 8, 1))) int vint8mf8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 4, 1))) int vint8mf4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 2, 1))) int vint8mf2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 1, 0))) int vint8m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 2, 0))) int vint8m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 4, 0))) int vint8m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 8, 0))) int vint8m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 4, 1))) int vint16mf4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 2, 1))) int vint16mf2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 1, 0))) int vint16m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 2, 0))) int vint16m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 4, 0))) int vint16m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 8, 0))) int vint16m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 2, 1))) int vint32mf2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 1, 0))) int vint32m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 2, 0))) int vint32m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 4, 0))) int vint32m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 8, 0))) int vint32m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 1, 0))) int vint64m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 2, 0))) int vint64m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 4, 0))) int vint64m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 8, 0))) int vint64m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 8, 1))) int vint64m8x1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 1, 4))) int vint64m1x8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 2, 4))) int vint64m2x4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 4, 4))) int vint64m4x4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 8, 4))) int vint64m8x4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 1, 8))) int vint64m1x8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 2, 8))) int vint64m2x8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 4, 8))) int vint64m4x8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 8, 8))) int vint64m8x8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 8, 1))) unsigned vuint8mf8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 4, 1))) unsigned vuint8mf4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 2, 1))) unsigned vuint8mf2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 1, 0))) unsigned vuint8m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 2, 0))) unsigned vuint8m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 4, 0))) unsigned vuint8m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 8, 0))) unsigned vuint8m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 4, 1))) unsigned vuint16mf4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 2, 1))) unsigned vuint16mf2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 1, 0))) unsigned vuint16m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 2, 0))) unsigned vuint16m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 4, 0))) unsigned vuint16m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 8, 0))) unsigned vuint16m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 2, 1))) unsigned vuint32mf2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 1, 0))) unsigned vuint32m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 2, 0))) unsigned vuint32m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 4, 0))) unsigned vuint32m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 8, 0))) unsigned vuint32m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 1, 0))) unsigned vuint64m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 2, 0))) unsigned vuint64m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 4, 0))) unsigned vuint64m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 8, 0))) unsigned vuint64m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 4, 1))) float vfloat16mf4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 2, 1))) float vfloat16mf2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 1, 0))) float vfloat16m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 2, 0))) float vfloat16m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 4, 0))) float vfloat16m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 8, 0))) float vfloat16m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 2, 1))) float vfloat32mf2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 1, 0))) float vfloat32m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 2, 0))) float vfloat32m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 4, 0))) float vfloat32m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 8, 0))) float vfloat32m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 1, 0))) float vfloat64m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 2, 0))) float vfloat64m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 4, 0))) float vfloat64m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 8, 0))) float vfloat64m8_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(1))) bool vbool1_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(2))) bool vbool2_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(4))) bool vbool4_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(8))) bool vbool8_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(16))) bool vbool16_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(32))) bool vbool32_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(64))) bool vbool64_t;\n";
  std::vector<Record *> RV = Records.getAllDerivedDefinitions("Inst");
  std::vector<std::shared_ptr<Intrinsic>> Defs;
  std::vector<std::shared_ptr<Intrinsic>> CustomDefs;
  for (auto R : RV) {
    createIntrinsic(R, Defs);
  }

  for (auto def : Defs) {
    if (def->isVsetvl()) {
      OS << "static __attribute__((always_inline))\n";
      OS << def->getTypes()[0]->parseTypeName() << " ";
      OS << def->getName() << "_" << def->getSuffix();
      OS << "(size_t avl) {\n";
      OS << "return __builtin_riscv_vsetvl(avl, ";
      size_t MPosition = def->getSuffix().find('m');
      std::string Sew = def->getSuffix().substr(0, MPosition);
      std::string Lmul = def->getSuffix().substr(MPosition, def->getSuffix().size());
      OS << "_" << Sew << " | " << "_" << Lmul << ");\n}\n";
    } else if (!def->getCustomDef().empty()) {
      CustomDefs.push_back(def);
    } else {
      OS << "#define ";
      OS << def->getName() << def->getInfix() << "_" << def->getSuffix();
      if (def->isMask())
        OS << "_m";
      OS << "(...)";
      OS << " __builtin_riscv_" << def->getName() 
         << def->getInfix() << "_" << def->getSuffix();
      if (def->isMask())
        OS << "_m";
      OS << "(__VA_ARGS__)\n";
    }
  }

  for (auto def : CustomDefs) {
    OS << "#define ";
    OS << def->getName() << def->getInfix() << "_" << def->getSuffix();
    if (def->isMask())
      OS << "_m";
    OS << "(";
    assert(def->getTypes().size() > 1);
    for (unsigned i = 0; i < def->getTypes().size() - 1; ++i) {
      if (i)
        OS << ", ";
      OS << "ARG" << i;
    }
    OS << ") ";
    OS << def->getCustomDef();
    OS << "\n";
  }

  OS << "#define vzero_i8mf8() vmv_v_x_i8mf8(0)\n";
  OS << "#define vzero_i8mf4() vmv_v_x_i8mf4(0)\n";
  OS << "#define vzero_i8mf2() vmv_v_x_i8mf2(0)\n";
  OS << "#define vzero_i8m1() vmv_v_x_i8m1(0)\n";
  OS << "#define vzero_i8m2() vmv_v_x_i8m2(0)\n";
  OS << "#define vzero_i8m4() vmv_v_x_i8m4(0)\n";
  OS << "#define vzero_i8m8() vmv_v_x_i8m8(0)\n";
  OS << "#define vzero_i16mf4() vmv_v_x_i16mf4(0)\n";
  OS << "#define vzero_i16mf2() vmv_v_x_i16mf2(0)\n";
  OS << "#define vzero_i16m1() vmv_v_x_i16m1(0)\n";
  OS << "#define vzero_i16m2() vmv_v_x_i16m2(0)\n";
  OS << "#define vzero_i16m4() vmv_v_x_i16m4(0)\n";
  OS << "#define vzero_i16m8() vmv_v_x_i16m8(0)\n";
  OS << "#define vzero_i32mf2() vmv_v_x_i32mf2(0)\n";
  OS << "#define vzero_i32m1() vmv_v_x_i32m1(0)\n";
  OS << "#define vzero_i32m2() vmv_v_x_i32m2(0)\n";
  OS << "#define vzero_i32m4() vmv_v_x_i32m4(0)\n";
  OS << "#define vzero_i32m8() vmv_v_x_i32m8(0)\n";
  OS << "#define vzero_i64m1() vmv_v_x_i64m1(0)\n";
  OS << "#define vzero_i64m2() vmv_v_x_i64m2(0)\n";
  OS << "#define vzero_i64m4() vmv_v_x_i64m4(0)\n";
  OS << "#define vzero_i64m8() vmv_v_x_i64m8(0)\n";
  OS << "#define vzero_u8mf8() vmv_v_x_u8mf8(0)\n";
  OS << "#define vzero_u8mf4() vmv_v_x_u8mf4(0)\n";
  OS << "#define vzero_u8mf2() vmv_v_x_u8mf2(0)\n";
  OS << "#define vzero_u8m1() vmv_v_x_u8m1(0)\n";
  OS << "#define vzero_u8m2() vmv_v_x_u8m2(0)\n";
  OS << "#define vzero_u8m4() vmv_v_x_u8m4(0)\n";
  OS << "#define vzero_u8m8() vmv_v_x_u8m8(0)\n";
  OS << "#define vzero_u16mf4() vmv_v_x_u16mf4(0)\n";
  OS << "#define vzero_u16mf2() vmv_v_x_u16mf2(0)\n";
  OS << "#define vzero_u16m1() vmv_v_x_u16m1(0)\n";
  OS << "#define vzero_u16m2() vmv_v_x_u16m2(0)\n";
  OS << "#define vzero_u16m4() vmv_v_x_u16m4(0)\n";
  OS << "#define vzero_u16m8() vmv_v_x_u16m8(0)\n";
  OS << "#define vzero_u32mf2() vmv_v_x_u32mf2(0)\n";
  OS << "#define vzero_u32m1() vmv_v_x_u32m1(0)\n";
  OS << "#define vzero_u32m2() vmv_v_x_u32m2(0)\n";
  OS << "#define vzero_u32m4() vmv_v_x_u32m4(0)\n";
  OS << "#define vzero_u32m8() vmv_v_x_u32m8(0)\n";
  OS << "#define vzero_u64m1() vmv_v_x_u64m1(0)\n";
  OS << "#define vzero_u64m2() vmv_v_x_u64m2(0)\n";
  OS << "#define vzero_u64m4() vmv_v_x_u64m4(0)\n";
  OS << "#define vzero_u64m8() vmv_v_x_u64m8(0)\n";
  OS << "#define vzero_f16mf4() vfmv_v_f_f16mf4(0)\n";
  OS << "#define vzero_f16mf2() vfmv_v_f_f16mf2(0)\n";
  OS << "#define vzero_f16m1() vfmv_v_f_f16m1(0)\n";
  OS << "#define vzero_f16m2() vfmv_v_f_f16m2(0)\n";
  OS << "#define vzero_f16m4() vfmv_v_f_f16m4(0)\n";
  OS << "#define vzero_f16m8() vfmv_v_f_f16m8(0)\n";
  OS << "#define vzero_f32mf2() vfmv_v_f_f32mf2(0)\n";
  OS << "#define vzero_f32m1() vfmv_v_f_f32m1(0)\n";
  OS << "#define vzero_f32m2() vfmv_v_f_f32m2(0)\n";
  OS << "#define vzero_f32m4() vfmv_v_f_f32m4(0)\n";
  OS << "#define vzero_f32m8() vfmv_v_f_f32m8(0)\n";
  OS << "#define vzero_f64m1() vfmv_v_f_f64m1(0)\n";
  OS << "#define vzero_f64m2() vfmv_v_f_f64m2(0)\n";
  OS << "#define vzero_f64m4() vfmv_v_f_f64m4(0)\n";
  OS << "#define vzero_f64m8() vfmv_v_f_f64m8(0)\n";
  OS << "#undef _e8\n";
  OS << "#undef _e16\n";
  OS << "#undef _e32\n";
  OS << "#undef _e64\n";
  OS << "#undef _m1\n";
  OS << "#undef _m2\n";
  OS << "#undef _m4\n";
  OS << "#undef _m8\n";
  OS << "#undef _mf2\n";
  OS << "#endif";
}

void RISCVVectorEmitter::createIntrinsic(Record *R, std::vector<std::shared_ptr<Intrinsic>>& Out) {
  StringRef Name = R->getValueAsString("IntrinsicName");
  std::vector<StringRef> BuiltinStr = R->getValueAsListOfStrings("BuiltinStr");
  std::vector<std::shared_ptr<RISCVVectorType>> BuiltinTypes;
  for (auto str : BuiltinStr) {
    BuiltinTypes.push_back(std::make_shared<RISCVVectorType>(str.str()));
  }
  // StringRef Types = R->getValueAsString("BuiltinStr");
  StringRef Infix = R->getValueAsString("Infix");
  StringRef Suffix = R->getValueAsString("Suffix");
  std::vector<int64_t> Operands = R->getValueAsListOfInts("AnyTypeOperands");
  bool Mask = R->getValueAsInt("Mask") == 1;
  StringRef Def = R->getValueAsString("CustomDef");

  Out.push_back(std::make_shared<Intrinsic>(Name, BuiltinTypes, Infix, Suffix,
                                            Operands, Mask, Def));
}

void RISCVVectorEmitter::createBuiltinCG(raw_ostream &OS) {
  std::vector<Record *> RV = Records.getAllDerivedDefinitions("Inst");
  std::vector<std::shared_ptr<Intrinsic>> Defs;
  for (auto R : RV) {
    if (R->getValueAsBit("ShouldEmitBuiltin"))
      createIntrinsic(R, Defs);
  }

  std::map<std::string, std::vector<std::shared_ptr<Intrinsic>>> SplitedIntrinsics;

  for (auto def : Defs) {
    std::string IntrinsicName = def->getName() + def->getInfix();
    if (def->isMask())
      IntrinsicName += "_m";
    if (SplitedIntrinsics.count(IntrinsicName))
      SplitedIntrinsics[IntrinsicName].push_back(def);
    else 
      SplitedIntrinsics.insert({IntrinsicName, {def}});
  }

  for (auto intrinsics : SplitedIntrinsics) {
    for (auto &intrinsic : intrinsics.second) {
      if (intrinsic->isVsetvl()) {
        OS << "case RISCV::BI__builtin_riscv_vsetvl:\n";
        break;
      }
      OS << "case RISCV::BI__builtin_riscv_" << intrinsic->getName() 
         << intrinsic->getInfix() << "_" << intrinsic->getSuffix();
      if (intrinsic->isMask())
        OS << "_m";
      OS <<  ":\n";
    }
    OS << "{\n";
    OS << intrinsics.second[0]->createStatementInCase();
    OS << "}\n";
  }
}

void RISCVVectorEmitter::createBuiltins(raw_ostream &OS) {
  std::vector<Record *> RV = Records.getAllDerivedDefinitions("Inst");
  std::vector<std::shared_ptr<Intrinsic>> Defs;
  for (auto R : RV) {
    if (R->getValueAsBit("ShouldEmitBuiltin"))
      createIntrinsic(R, Defs);
  }

  OS << "BUILTIN(__builtin_riscv_vsetvl, \"zzz\", \"n\")\n";

  for (auto def : Defs) {
    if (def->isVsetvl()) {
      continue;
    }

    OS << "BUILTIN(__builtin_riscv_" << def->getName() 
       << def->getInfix() << "_" << def->getSuffix();
    
    if (def->isMask())
      OS << "_m";

    OS << ", " << "\"";
    
    for (auto type : def->getTypes()) {
      OS << type->getBuiltinStr();
    }

    OS << "\", \"\")\n";
  }
}

std::string Intrinsic::createStatementInCase() {
  std::string result = "";
  std::map<std::string, std::string> intrinsicMap= 
    {{"vle", "vload"}, {"vse", "vstore"}, {"vlse", "vload_strided"}, {"vsse", "vstore_strided"},
     {"vlxei", "vload_indexed"}, {"vsxei", "vstore_indexed"}};
  if (isLoadOrStore()) {
    std::string Name = getName();
    std::string::iterator NameIter = Name.begin();
    while (!isdigit(*(NameIter++))) {}
    result += "Function *F = CGM.getIntrinsic(Intrinsic::riscv_";
    result += intrinsicMap[std::string(Name.begin(), NameIter-1)];
    result += ", {";
  } else {
    result += "Function *F = CGM.getIntrinsic(Intrinsic::riscv_" + getName() + getInfix();
    if (isMask())
      result += "_mask";
    result += ", {";
  }
  if (!isVsetvl()) {
    for (auto operandIndex : AnyTypeOperands) {
      if (operandIndex == -1)
        result += "ResultType, ";
      else 
        result += "Ops[" + std::to_string(operandIndex) + "]" + "->getType(), ";
    }
    // delete unnecessay ", "
    result = result.substr(0, result.size() - 2);
  }
  result += "});\n";
  result += "return Builder.CreateCall(F, Ops);\n";
  return result;
}

namespace clang {
  void EmitRiscvVectorHeader(RecordKeeper &Records, raw_ostream &OS) {
    RISCVVectorEmitter(Records).createHeader(OS);
  }

  void EmitRiscvVectorBuiltinCG(RecordKeeper &Records, raw_ostream &OS) {
    RISCVVectorEmitter(Records).createBuiltinCG(OS);
  }

  void EmitRiscvVectorBuiltin(RecordKeeper &Records, raw_ostream &OS) {
    RISCVVectorEmitter(Records).createBuiltins(OS);
  }
}

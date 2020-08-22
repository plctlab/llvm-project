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

public:

  std::string getName() { return Name; }

  std::vector<std::shared_ptr<RISCVVectorType>>& getTypes() { return Types; }
  std::string getInfix() { return Infix; }
  std::string getSuffix() { return Suffix; }

  std::vector<int64_t> getAnyTypeOperand() { return AnyTypeOperands; }

  // FixMe: for stride index load or store
  bool isLoad() { return Name.find("vle") != std::string::npos; }
  bool isStore() { return (Name.find("vse") != std::string::npos) && (Infix != ""); }
  bool isVsetvl() { return Name.find("vsetvl") != std::string::npos; }

  Intrinsic(StringRef Name, std::vector<std::shared_ptr<RISCVVectorType>> & Types, StringRef Infix, 
                    StringRef Suffix, std::vector<int64_t> &Operands)
      : Name(Name.str()), Types(Types), Infix(Infix.str()),
        Suffix(Suffix), AnyTypeOperands(Operands) {}

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
  OS << "#define float32_t float\n";
  OS << "#define float64_t double\n";
  OS << "#define _E8 0\n";
  OS << "#define _E16 4\n";
  OS << "#define _E32 8\n";
  OS << "#define _E64 12\n";
  OS << "#define _M1 0\n";
  OS << "#define _M2 1\n";
  OS << "#define _M4 2\n";
  OS << "#define _M8 3\n";
  OS << "#define _MF2 35\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 1, 0))) int vint8m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 2, 0))) int vint8m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 4, 0))) int vint8m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 8, 0))) int vint8m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 1, 0))) int vint16m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 2, 0))) int vint16m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 4, 0))) int vint16m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 8, 0))) int vint16m8_t;\n";
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
  OS << "typedef __attribute__((riscv_vector_type(8, 1, 0))) unsigned vuint8m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 2, 0))) unsigned vuint8m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 4, 0))) unsigned vuint8m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(8, 8, 0))) unsigned vuint8m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 1, 0))) unsigned vuint16m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 2, 0))) unsigned vuint16m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 4, 0))) unsigned vuint16m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 8, 0))) unsigned vuint16m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 1, 0))) unsigned vuint32m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 2, 0))) unsigned vuint32m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 4, 0))) unsigned vuint32m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 8, 0))) unsigned vuint32m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 1, 0))) unsigned vuint64m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 2, 0))) unsigned vuint64m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 4, 0))) unsigned vuint64m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(64, 8, 0))) unsigned vuint64m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 1, 0))) float vfloat16m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 2, 0))) float vfloat16m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 4, 0))) float vfloat16m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(16, 8, 0))) float vfloat16m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 1, 0))) float vfloat32m1_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 2, 0))) float vfloat32m2_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 4, 0))) float vfloat32m4_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 8, 0))) float vfloat32m8_t;\n";
  OS << "typedef __attribute__((riscv_vector_type(32, 2, 1))) float vfloat32mf2_t;\n";
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
      OS << "_E32 | _M8);\n}\n";
    } else {
      OS << "static __attribute__((always_inline))\n";
      OS << def->getTypes()[0]->parseTypeName() << " ";
      OS << def->getName() << def->getInfix() << "_" << def->getSuffix();
      OS << "(";
      std::vector<std::shared_ptr<RISCVVectorType>> arguments = 
          {def->getTypes().begin() + 1, def->getTypes().end()};
      std::string argument = "";
      std::vector<std::string> ArgumentName;
      if (arguments.size() > 0) {
        int ArgIndex = 0;
        for (auto type : arguments) {
          ArgumentName.push_back("value" + std::to_string(ArgIndex));
          argument += type->parseTypeName() + " value" + std::to_string(ArgIndex) + ", ";
          ArgIndex++;
        }
        argument = argument.substr(0, argument.size() - 2);
        OS << argument;
      }
      OS << ") {\n";
      OS << "return __builtin_riscv_" << def->getName() << def->getInfix() << "_" << def->getSuffix() << "(";

      std::string CallArguments = "";
      for (auto Arg : ArgumentName) {
        CallArguments += Arg + ", ";
      }
      CallArguments = CallArguments.substr(0, CallArguments.size() - 2);

      OS << CallArguments << ");\n";
      OS << "}\n\n";
    }
  }
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

  Out.push_back(std::make_shared<Intrinsic>(Name, BuiltinTypes, Infix, Suffix, Operands));
}

void RISCVVectorEmitter::createBuiltinCG(raw_ostream &OS) {
  std::vector<Record *> RV = Records.getAllDerivedDefinitions("Inst");
  std::vector<std::shared_ptr<Intrinsic>> Defs;
  for (auto R : RV) {
    createIntrinsic(R, Defs);
  }

  std::map<std::string, std::vector<std::shared_ptr<Intrinsic>>> SplitedIntrinsics;

  for (auto def : Defs) {
    std::string IntrinsicName = def->getName() + def->getInfix();
    if (SplitedIntrinsics.count(IntrinsicName))
      SplitedIntrinsics[IntrinsicName].push_back(def);
    else 
      SplitedIntrinsics.insert({IntrinsicName, {def}});
  }

  for (auto intrinsics : SplitedIntrinsics) {
    for (auto &intrinsic : intrinsics.second) {
      OS << "case RISCV::BI__builtin_riscv_" << intrinsic->getName() << intrinsic->getInfix();
      if (!intrinsic->isVsetvl())
        OS << "_" << intrinsic->getSuffix();
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
    createIntrinsic(R, Defs);
  }

  for (auto def : Defs) {
    OS << "BUILTIN(__builtin_riscv_" << def->getName() << def->getInfix();
    if (!def->isVsetvl()) {
      OS << "_" << def->getSuffix();
    }
    
    OS << ", " << "\"";
    
    for (auto type : def->getTypes()) {
      OS << type->getBuiltinStr();
    }

    OS << "\", \"\")\n";
  }
}

std::string Intrinsic::createStatementInCase() {
  std::string result = "";
  if (isLoad()) {
    result += "Function *F = CGM.getIntrinsic(Intrinsic::riscv_vload, {";
  } else if (isStore()) {
    result += "Function *F = CGM.getIntrinsic(Intrinsic::riscv_vstore, {";
  } else {
    result += "Function *F = CGM.getIntrinsic(Intrinsic::riscv_" + getName() + getInfix() + ", {";
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
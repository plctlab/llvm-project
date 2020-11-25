#include "llvm/TableGen/Record.h"
#include "llvm/ADT/SmallVector.h"
#include <sstream>
#include <string>
#include <ctype.h>

using namespace llvm;

class Intrinsic;
class RISCVVectorType;
class BaseVectorType;

class RISCVVectorEmitter {
private:
  RecordKeeper &Records;

public:
  RISCVVectorEmitter(RecordKeeper &R) : Records(R) {}

  void createHeader(raw_ostream &OS);

  void createBuiltinCG(raw_ostream &OS);

  void createBuiltins(raw_ostream &OS);

  void createVectorType(Record *R, std::vector<std::shared_ptr<BaseVectorType>>& Out);

  void createIntrinsic(Record *R, std::vector<std::shared_ptr<Intrinsic>>& Out);

};

class BaseVectorType {
private:  
  std::string Name;
  int64_t ELEN;
  std::string LMUL;
  bool IsLMULFractional;
  int64_t NF;

public:
  BaseVectorType(StringRef Name, int64_t ELEN, StringRef LMUL, bool IsLMULFractional, int64_t NF)
      : Name(Name.str()), ELEN(ELEN), LMUL(LMUL.str()), IsLMULFractional(IsLMULFractional), NF(NF) {}

  std::string getName() { return Name; }
  int64_t getELEN() { return ELEN; }
  std::string getLMUL() { return LMUL; }
  bool isLMULFractional() { return IsLMULFractional; }
  int64_t getNF()  { return NF; }
};

class Intrinsic {
private:
  // The name of the intrinsic
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

  // FIXME: for stride index load or store
  bool isLoadOrStore() {
    return (Name.find("vle8") != std::string::npos
            || Name.find("vle16") != std::string::npos
            || Name.find("vle64") != std::string::npos
            || Name.find("vle32") != std::string::npos
            || Name.find("vse8") != std::string::npos
            || Name.find("vse16") != std::string::npos
            || Name.find("vse32") != std::string::npos
            || Name.find("vse64") != std::string::npos
            || Name.find("vlse") != std::string::npos
            || Name.find("vsse") != std::string::npos
            || Name.find("vlxei") != std::string::npos
            || Name.find("vsuxei") != std::string::npos
            || Name.find("vsxei") != std::string::npos) && (Infix != "");
  }
  
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
  
  std::string getTypeName();

  std::string parseTypeName();
};


std::string RISCVVectorType::getTypeName() {
  std::string Builtin = BuiltinStr;
  std::map<std::string, std::string> TYPE = {
    {"q1c", "vint8mf8_t"}, {"q2c", "vint8mf4_t"}, {"q4c", "vint8mf2_t"},
    {"q8c", "vint8m1_t"}, {"q16c", "vint8m2_t"}, {"q32c", "vint8m4_t"},
    {"q64c", "vint8m8_t"}, {"q1s", "vint16mf4_t"}, {"q2s", "vint16mf2_t"},
    {"q4s", "vint16m1_t"}, {"q8s", "vint16m2_t"}, {"q16s", "vint16m4_t"},
    {"q32s", "vint16m8_t"}, {"q1i", "vint32mf2_t"}, {"q2i", "vint32m1_t"},
    {"q4i", "vint32m2_t"}, {"q8i", "vint32m4_t"}, {"q16i", "vint32m8_t"},
    {"q1Wi", "vint64m1_t"}, {"q2Wi", "vint64m2_t"}, {"q4Wi", "vint64m4_t"},
    {"q8Wi", "vint64m8_t"}, {"q1Uc", "vuint8mf8_t"}, {"q2Uc", "vuint8mf4_t"},
    {"q4Uc", "vuint8mf2_t"}, {"q8Uc", "vuint8m1_t"}, {"q16Uc", "vuint8m2_t"},
    {"q32Uc", "vuint8m4_t"}, {"q64Uc", "vuint8m8_t"}, {"q1Us", "vuint16mf4_t"},
    {"q2Us", "vuint16mf2_t"}, {"q4Us", "vuint16m1_t"}, {"q8Us", "vuint16m2_t"},
    {"q16Us", "vuint16m4_t"}, {"q32Us", "vuint16m8_t"}, {"q1Ui", "vuint32mf2_t"},
    {"q2Ui", "vuint32m1_t"}, {"q4Ui", "vuint32m2_t"}, {"q8Ui", "vuint32m4_t"},
    {"q16Ui", "vuint32m8_t"}, {"q1UWi", "vuint64m1_t"}, {"q2UWi", "vuint64m2_t"},
    {"q4UWi", "vuint64m4_t"}, {"q8UWi", "vuint64m8_t"}, {"q1h", "vfloat16mf4_t"},
    {"q2h", "vfloat16mf2_t"}, {"q4h",  "vfloat16m1_t"}, {"q8h", "vfloat16m2_t"},
    {"q16h", "vfloat16m4_t"}, {"q32h", "vfloat16m8_t"}, {"q1f", "vfloat32mf2_t"}, 
    {"q2f", "vfloat32m1_t"}, {"q4f", "vfloat32m2_t"}, {"q8f", "vfloat32m4_t"},
    {"q16f", "vfloat32m8_t"}, {"q1d", "vfloat64m1_t"}, {"q2d", "vfloat64m2_t"}, 
    {"q4d", "vfloat64m4_t"}, {"q8d", "vfloat64m8_t"}, {"q1b", "vbool64_t"},
    {"q2b", "vbool32_t"}, {"q4b", "vbool16_t"}, {"q8b", "vbool8_t"},
    {"q16b", "vbool4_t"}, {"q32b", "vbool2_t"}, {"q64b", "vbool1_t"},
    {"Sc", "int8_t"}, {"Uc", "uint8_t"}, {"s", "int16_t"},
    {"Us", "uint16_t"}, {"i", "int32_t"}, {"Ui", "uint32_t"},
    {"Wi", "int64_t"}, {"UWi", "uint64_t"}, {"h", "float16_t"},
    {"f", "float32_t"}, {"d", "float64_t"}, {"z", "size_t"}
  };
  std::map<std::string, std::string>::iterator titer;
  std::string TypeName ="null"; //TODO, special null, used only at development time
  titer = TYPE.find(Builtin);
  if (titer != TYPE.end()) 
    TypeName = titer->second;
  return TypeName;
}
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
  OS << "typedef __fp16 float16_t;\n";
  OS << "typedef float float32_t;\n";
  OS << "typedef double float64_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(1))) bool vbool1_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(2))) bool vbool2_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(4))) bool vbool4_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(8))) bool vbool8_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(16))) bool vbool16_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(32))) bool vbool32_t;\n";
  OS << "typedef __attribute__((riscv_mask_type(64))) bool vbool64_t;\n";
  std::vector<Record *> RVT = Records.getAllDerivedDefinitions("VType");
  std::vector<std::shared_ptr<BaseVectorType>> VTypes;
  for (auto R : RVT) {
    createVectorType(R, VTypes);
  }
  for (auto type : VTypes) {
    OS << "typedef __attribute__((riscv_vector_type(";
    std::string::const_iterator it = type->getLMUL().end();
    OS << type->getELEN() << ", " << *(--it) << ", ";
    OS << type->isLMULFractional() << ", " << type->getNF() <<"))) ";
    if (type->getName().find("float") != std::string::npos)
      OS << " float" << type->getELEN() << "_t ";
    else if (type->getName().find("uint") != std::string::npos)
      OS << " uint" << type->getELEN() << "_t ";
    else 
      OS << " int" <<type->getELEN() << "_t "; 
    OS << type->getName() <<";\n";
  }

  std::vector<Record *> RV = Records.getAllDerivedDefinitions("Inst");
  std::vector<std::shared_ptr<Intrinsic>> Defs;
  std::vector<std::shared_ptr<Intrinsic>> CustomDefs;
  for (auto R : RV) {
    createIntrinsic(R, Defs);
  }

  std::map<std::string, int> LMUL = {
    {"m1", 0}, /* 0b000000 */
    {"m2", 1}, /* 0b000001 */
    {"m4", 2}, /* 0b000010 */ 
    {"m8", 3}, /* 0b000011 */
    {"mf2", 35}, /* 0b100011 */
    {"mf4", 34}, /* 0b100010 */
    {"mf8", 33} /* 0b100001 */
  };
  std::map<std::string, int>::iterator miter;
  std::map<std::string, int> SEW = {
    {"e8", 0}, /* 0b000000 */
    {"e16", 4},  /* 0b000100 */
    {"e32", 8}, /* 0b001000 */
    {"e64", 12} /* 0b001100 */
  };
  std::map<std::string, int>::iterator eiter;
  
  for (auto def : Defs) {
    if (!def->getCustomDef().empty()) {
      CustomDefs.push_back(def);
    } else if (def->isVsetvl()) {
      OS << "#define ";
      OS << def->getName() << "_" << def->getSuffix() << "(avl) ";
      OS << "__builtin_riscv_vsetvl(avl, ";
      size_t MPosition = def->getSuffix().find('m');
      std::string Sew = def->getSuffix().substr(0, MPosition);
      std::string Lmul = def->getSuffix().substr(MPosition, def->getSuffix().size()); 
      eiter = SEW.find(Sew);
      miter = LMUL.find(Lmul);
      if (eiter != SEW.end() && miter != LMUL.end())
        OS << eiter->second << "/*" << eiter->first << "*/ | " << miter->second << "/*" <<miter->first<< "*/)\n";

      // vsetvlmax
      OS << "#define ";
      OS << def->getName() << "max_" << def->getSuffix() << "() ";
      OS << def->getName() << "_" << def->getSuffix() << "(-1)\n";
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
      
     //vl intrinsic
    if (def->getInfix() == "_vv" && def->getSuffix().find("_") == std::string::npos) {
      OS <<"static inline ";
      int count = 0;
      int opnum = 1;
      for (auto type : def->getTypes()) {
        if (count == 0) {
          OS <<type->getTypeName()<<" "<< def->getName() << def->getInfix() <<"_"<< def->getSuffix();
          if (def->isMask())
             OS << "_m";
          OS << "_vl(";
        }
        else
          OS << type->getTypeName() << " op" << count << ",";
          count++;
      }
      OS <<"size_t vl) { vsetvl_e" << def->getSuffix().substr(1) <<"(vl); return ";
      OS << def->getName() << def->getInfix() <<"_"<< def->getSuffix();
      if (def->isMask())
        OS << "_m";
      OS << "(";
      while (opnum < count - 1)
        OS << "op" << opnum++ <<",";
      OS << "op" << opnum++ <<");}\n";
    }
    }
  }

  for (auto def : CustomDefs) {
    OS << "#define ";
    OS << def->getName() << def->getInfix() << "_" << def->getSuffix();
    if (def->isMask())
      OS << "_m";
    OS << "(";
    assert(def->getTypes().size() > 0);
    for (unsigned i = 0; i < def->getTypes().size() - 1; ++i) {
      if (i)
        OS << ", ";
      OS << "ARG" << i;
    }
    OS << ") ";
    OS << def->getCustomDef();
    OS << "\n";
  }

  OS << "#endif";
}

void RISCVVectorEmitter::createVectorType(Record *R, std::vector<std::shared_ptr<BaseVectorType>>& Out) {
  StringRef Name = R->getValueAsString("VTypeName");
  int64_t ELEN = R->getValueAsInt("ELEN");
  StringRef LMUL = R->getValueAsString("LMUL"); 
  bool IsLMULFractional = Name.find("mf") != std::string::npos;
  int64_t NF = R->getValueAsInt("NF");
  Out.push_back(std::make_shared<BaseVectorType>(Name, ELEN, LMUL, IsLMULFractional, NF));
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
    if (isMask())
      result += "_mask";
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

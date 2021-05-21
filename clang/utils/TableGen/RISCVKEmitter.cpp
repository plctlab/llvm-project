#include "llvm/TableGen/Record.h"
#include "llvm/ADT/SmallVector.h"
// #include "llvm/ADT/StringExtras.h"
#include <sstream>
#include <string>
#include <ctype.h>

using namespace llvm;

class Intrinsic;
class RISCVCryptoType;

class RISCVCryptoEmitter {
private:
  RecordKeeper &Records;

public:
  RISCVCryptoEmitter(RecordKeeper &R) : Records(R) {}

  void createHeader(raw_ostream &OS);

  void createBuiltinCG(raw_ostream &OS);

  void createBuiltins(raw_ostream &OS);

  void createIntrinsic(Record *R, std::vector<std::shared_ptr<Intrinsic>>& Out);

  void createEmulateIntrinsic(Record *R, std::vector<std::shared_ptr<Intrinsic>>& Out);
};

class Intrinsic {
private:
  std::string Prefix;

  // The name fo the intrinsic
  std::string Name;
  
  std::vector<StringRef> paramTypes;
  StringRef returnType;

  // The type string of the intrinsic
  StringRef Types;

  // If not empty, the emitter will use it to define the intrinsic emulate function 
  // so that it can be called without suport of k-Ext.
  std::string EmulateDef;

  bool enableForRV32;
  bool enableForRV64;

  // The types we use to obtain the specific LLVM intrinsic. They are index of
  // InputTypes. -1 means the return type.
  std::vector<int64_t> IntrinsicTypes;

public:
  std::string getPrefix() { return Prefix; }

  std::string getName() { return Name; }

  std::string getEmulateDef() { return EmulateDef; }

  StringRef getTypes() { return Types; }

  std::vector<StringRef> getParamTypes() { return paramTypes; }

  StringRef getReturnType() { return returnType; }

  Intrinsic(StringRef Name, std::vector<StringRef> paramTypes, StringRef returnType, StringRef Def)
      : Prefix(""), Name(Name.str()), paramTypes(paramTypes), returnType(returnType), EmulateDef(Def) {}

  Intrinsic(StringRef Prefix, StringRef Name, std::vector<StringRef> paramTypes, StringRef returnType, StringRef Types, std::vector<int64_t> &IntrinsicTypes, StringRef Def, bool enableForRV32, bool enableForRV64)
      : Prefix(Prefix.str()), Name(Name.str()), paramTypes(paramTypes), returnType(returnType), Types(Types), EmulateDef(Def), enableForRV32(enableForRV32), enableForRV64(enableForRV64), IntrinsicTypes(IntrinsicTypes) {}

  void createSwitchBody(raw_ostream &OS);
};

class RISCVCryptoType{
private:
  std::string BuiltinStr;

public:
  RISCVCryptoType(std::string Str) : BuiltinStr(Str) {}

  std::string getBuiltinStr() { return BuiltinStr; }

  std::string parseTypeName();
};

std::string RISCVCryptoType::parseTypeName(){
    return BuiltinStr;
}

void RISCVCryptoEmitter::createHeader(raw_ostream &OS) {
    OS << "//	rvkintrin.h\n";
    OS << "//	2021-02-13	Markku-Juhani O. Saarinen <mjos@pqshield.com>\n";
    OS << "//	Copyright (c) 2021, PQShield Ltd. All rights reserved.\n\n";
    OS << "//	RISC-V \"K\" extension proposal intrinsics and emulation\n";
    OS << "/*\n";
    OS << " *	Krypto intrinsics follow the conventions of rvintrin.h from bitmanip:\n";
    OS << " *\n";
    OS << " *	_rv_*(...)\n";
    OS << " *	  RV32/64 intrinsics that operate on the \"long\" data type\n";
    OS << " *\n";
    OS << " * _rv32_*(...)\n";
    OS << " *	  RV32/64 intrinsics that operate on the \"int32_t\" data type\n";
    OS << " *\n";
    OS << " *	_rv64_*(...)\n";
    OS << " *	  RV64-only intrinsics that operate on the \"int64_t\" data type\n";
    OS << " */\n";
    OS << "\n";
    OS << "#ifndef _RVKINTRIN_H_\n";
    OS << "#define _RVKINTRIN_H_\n";
    OS << "\n";
    OS << "#include <limits.h>\n";
    OS << "#include <stdint.h>\n";
    OS << "\n";
    OS << "//	always include bitmanip intrinsics; architecture macros defined there\n";
    OS << "\n//Fixme: uncomment include line in clang/utils/TableGen/RISCVKEmitter.cpp when rvintrin.h is available. \n";
    OS << "//#include \"rvintrin.h\"\n"; 
    OS << "\n";
    OS << "//	IMPORTANT:\n";
    OS << "//	Compilers should never emit emulation code (especially conditionals or\n";
    OS << "//	table lookups) for these machine intrinsics, just the instructions.\n";
    OS << "//	If architecture is not enabled, fail.\n";
    OS << "\n";
    OS << "#if !defined(__riscv_xlen) && !defined(RVINTRIN_EMULATE)\n";
    OS << "#  warning \"Target is not RISC-V. Enabling <rvkintrin.h> emulation mode.\"\n";
    OS << "#  define RVINTRIN_EMULATE 1\n";
    OS << "#endif\n";
    OS << "\n";
    OS << "#ifndef RVINTRIN_EMULATE\n";

    std::vector<Record *> RV = Records.getAllDerivedDefinitions("Inst");
    std::vector<Record *> Emulat = Records.getAllDerivedDefinitions("EmulateIntr");
    std::vector<std::shared_ptr<Intrinsic>> RV32Defs;
    std::vector<std::shared_ptr<Intrinsic>> RV64Defs;
    std::vector<std::shared_ptr<Intrinsic>> RVUniDefs;
    std::vector<std::shared_ptr<Intrinsic>> EmulateDefs;

    for (auto Intr : Emulat) {
      createEmulateIntrinsic(Intr, EmulateDefs);
    }

    for (auto R : RV) {
      if(R->getValueAsBit("enableForRV32")&&R->getValueAsBit("enableForRV64")){
        createIntrinsic(R, RVUniDefs);
      }else if(R->getValueAsBit("enableForRV32")){
        createIntrinsic(R, RV32Defs);
      }else if(R->getValueAsBit("enableForRV64")){
        createIntrinsic(R, RV64Defs);
      }
    }

    OS << "#ifdef RVINTRIN_RV32\n";
    for (auto def : RV32Defs) {
      if (!def->getEmulateDef().empty()) {
        EmulateDefs.push_back(def);
      }
      std::vector<StringRef> PT = def->getParamTypes();
      OS << "static inline " << def->getReturnType() << " " << def->getPrefix() << def->getName() << "(";
      int flag = 0;
      for(auto param : PT){
        if(flag++>0){
          OS << ",";
        }
        OS << param << " rs" <<flag;
      }
      OS <<")" << " { return __builtin_riscv_" << def->getName() << "(";
      for (int i = 0; i < flag; i++)
      {
        if(i>0){
          OS << ",";
        }
        OS <<"rs" <<i+1;
      }
      OS <<"); }\n";
    }
    OS << "#endif // RVINTRIN_RV32\n";

    OS << "#ifdef RVINTRIN_RV64\n";
    for (auto def : RV64Defs) {
      if (!def->getEmulateDef().empty()) {
        EmulateDefs.push_back(def);
      }
      std::vector<StringRef> PT = def->getParamTypes();
      OS << "static inline " << def->getReturnType() << " " << def->getPrefix() << def->getName() << "(";
      int flag = 0;
      for(auto param : PT){
        if(flag++>0){
          OS << ",";
        }
        OS << param << " rs" <<flag;
      }
      OS <<")" << " { return __builtin_riscv_" << def->getName() << "(";
      for (int i = 0; i < flag; i++)
      {
        if(i>0){
          OS << ",";
        }
        OS <<"rs" <<i+1;
      }
      OS <<"); }\n";
    }
    OS << "#endif // RVINTRIN_RV64\n";

    for (auto def : RVUniDefs) {
      if (!def->getEmulateDef().empty()) {
        EmulateDefs.push_back(def);
      }
      std::vector<StringRef> PT = def->getParamTypes();
      OS << "static inline " << def->getReturnType() << " " << def->getPrefix() << def->getName() << "(";
      int flag = 0;
      for(auto param : PT){
        if(flag++>0){
          OS << ",";
        }
        OS << param << " rs" <<flag;
      }
      OS <<")" << " { return __builtin_riscv_" << def->getName() << "(";
      for (int i = 0; i < flag; i++)
      {
        if(i>0){
          OS << ",";
        }
        OS <<"rs" <<i+1;
      }
      OS <<"); }\n";
    }

    OS << "#else\n";
    OS << "//	===	RVINTRIN_EMULATE ==============================================\n";
    OS << "/*\n";
    OS << " *	_rvk_emu_*(...)\n";
    OS << " *	  Some INTERNAL tables (rvk_emu.c) and functions.\n";
    OS << " */\n";
    OS << "extern const uint8_t _rvk_emu_aes_fwd_sbox[256];	//	AES Forward S-Box\n";
    OS << "extern const uint8_t _rvk_emu_aes_inv_sbox[256];	//	AES Inverse S-Box\n";
    OS << "extern const uint8_t _rvk_emu_sm4_sbox[256];		//	SM4 S-Box\n";
    OS << "//	rvk_emu internal: multiply by 0x02 in AES's GF(256) - LFSR style.\n\n";

    for (auto def : EmulateDefs) {
      OS << "static inline " << def->getReturnType() << " " << def->getPrefix() << def->getName();
      OS << "(";
      std::vector<StringRef> types = def->getParamTypes();
      for(size_t i = 0; i<types.size(); i++){
        OS << ((i>0)?", ":"") << types[i] << " rs" <<i+1;
      }
      OS << ");\n";
    }
    OS << "\n\n";
    for (auto def : EmulateDefs) {
      OS << "static inline " << def->getReturnType() << " " << def->getPrefix() << def->getName();
      OS << "(";
      std::vector<StringRef> types = def->getParamTypes();
      for(size_t i = 0; i<types.size(); i++){
        OS << ((i>0)?", ":"") << types[i] << " rs" <<i+1;
      }
      OS << ")\n";
      OS << "{";
      OS << def->getEmulateDef();
      OS << "\n}\n";
    }

    OS << "//	=== Entropy source:	Zkr (RV32 & RV64) -- function prototypes only for emu.\n";
    OS << "long _rv_pollentropy();\n";
    OS << "long _rv_getnoise();\n";
    OS << "\n";
    
    OS << "#endif	// RVINTRIN_EMULATE\n";
    OS << "#endif	// _RVKINTRIN_H_\n";


}

void RISCVCryptoEmitter::createBuiltinCG(raw_ostream &OS){
  std::vector<Record *> RV = Records.getAllDerivedDefinitions("Inst");
  std::vector<std::shared_ptr<Intrinsic>> Defs;
  for (auto R : RV) {
    if (R->getValueAsBit("ShouldEmitBuiltin"))
      createIntrinsic(R, Defs);
  }

  for (auto def : Defs) {
    OS << "case RISCV::BI__builtin_riscv_"<< def->getName() <<":\n";
    def->createSwitchBody(OS);
    OS << " break;\n";
  }
}

void RISCVCryptoEmitter::createBuiltins(raw_ostream &OS){
  std::vector<Record *> RV = Records.getAllDerivedDefinitions("Inst");
  std::vector<std::shared_ptr<Intrinsic>> Defs;
  for (auto R : RV) {
    if (R->getValueAsBit("ShouldEmitBuiltin"))
      createIntrinsic(R, Defs);
  }

  OS << "#if defined(TARGET_BUILTIN) && !defined(RISCVK_BUILTIN)\n";
  OS << "#define RISCVK_BUILTIN(ID, TYPE, ATTRS) TARGET_BUILTIN(ID, TYPE, "
        "ATTRS, \"experimental-k\")\n";
  OS << "#endif\n";
  for (auto &Def : Defs) {
    OS << "RISCVK_BUILTIN(__builtin_riscv_" << Def->getName() << ",\""<< Def->getTypes() << "\", " << "\"n\")\n";
  }
  OS << "#undef RISCVK_BUILTIN\n";
}

void Intrinsic::createSwitchBody(raw_ostream &OS) {
  if (!getName().empty()){
    OS << "  ID = Intrinsic::riscv_" + getName() + ";\n";
  }
  if (IntrinsicTypes.size() > 0){
    OS << "  IntrinsicTypes = {";
    ListSeparator LS;
    for (const auto &Idx : IntrinsicTypes) {
      if (Idx == -1)
        OS << LS << "ResultType";
      else
        OS << LS << "Ops[" << Idx << "]->getType()";
    }
    OS << "};\n";
  }
    
}

void RISCVCryptoEmitter::createIntrinsic(Record *R, std::vector<std::shared_ptr<Intrinsic>>& Out){
  StringRef Name = R->getValueAsString("IntrinsicName");
  StringRef BuiltinStr = R->getValueAsString("BuiltinStr");
  StringRef Prefix = R->getValueAsString("Prefix");
  bool enableForRV32 = R->getValueAsBit("enableForRV32");
  bool enableForRV64 = R->getValueAsBit("enableForRV64");
  StringRef Def = R->getValueAsString("EmulateDef");
  std::vector<StringRef> paramTypes = R->getValueAsListOfStrings("paramTypes");
  StringRef returnType = R->getValueAsString("returnType");
  std::vector<int64_t> IntrinsicTypes =
        R->getValueAsListOfInts("IntrinsicTypes");

  Out.push_back(std::make_shared<Intrinsic>(Prefix, Name, paramTypes, returnType, BuiltinStr, IntrinsicTypes, Def, enableForRV32, enableForRV64));
}

void RISCVCryptoEmitter::createEmulateIntrinsic(Record *R, std::vector<std::shared_ptr<Intrinsic>>& Out){
  StringRef Name = R->getValueAsString("IntrinsicName");
  StringRef Def = R->getValueAsString("EmulateDef");
  std::vector<StringRef> paramTypes = R->getValueAsListOfStrings("paramTypes");
  StringRef returnType = R->getValueAsString("returnType");

  Out.push_back(std::make_shared<Intrinsic>(Name, paramTypes, returnType, Def));
}

namespace clang {
  void EmitRiscvCryptoHeader(RecordKeeper &Records, raw_ostream &OS) {
    RISCVCryptoEmitter(Records).createHeader(OS);
  }

  void EmitRiscvCryptoBuiltinCG(RecordKeeper &Records, raw_ostream &OS) {
    RISCVCryptoEmitter(Records).createBuiltinCG(OS);
  }

  void EmitRiscvCryptoBuiltins(RecordKeeper &Records, raw_ostream &OS) {
    RISCVCryptoEmitter(Records).createBuiltins(OS);
  }
}

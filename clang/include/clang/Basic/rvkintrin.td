//==--- rvkintrin.td - RISC-V Crypto Definitions -----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the TableGen definitions from which the RISC-V Crypto
// header file will be generated. It is also used to generate clang CodeGen
// snippet.
//
//===----------------------------------------------------------------------===//

class Inst<string name, bit rv32, bit rv64,list<string> param_types, string return_types, string types, code definition = "">{
    string IntrinsicName = name;

    string BuiltinStr = types;
    list<int> IntrinsicTypes = [];
    list<string> paramTypes = param_types;
    string returnType = return_types;

    bit enableForRV32 = rv32;
    bit enableForRV64 = rv64;

    // If not empty, the emitter will use it to define the intrinsic function.
    // Otherwise, the emitter will generate intrinsic in the default way.
    code CustomDef = definition;
    // Should emit BUILTIN macro. Set to false if the intrinsic function can
    // be implemented by other existing builtin functions.
    bit ShouldEmitBuiltin = 1;
}

class RVK32Inst<list<string> param_types = [], string return_types, string types, list<int> intrinsic_types = []> 
            : Inst<NAME, 1, 0, param_types, return_types, types>{
    let IntrinsicTypes = intrinsic_types;
}

class RVK64Inst<list<string> param_types = [], string return_types, string types, list<int> intrinsic_types = []> 
            : Inst<NAME, 0, 1, param_types, return_types, types>{
    let IntrinsicTypes = intrinsic_types;
}

class RVKInst<list<string> param_types = [], string return_types, string types, list<int> intrinsic_types = []> 
            : Inst<NAME, 1, 1, param_types, return_types, types>{
    let IntrinsicTypes = intrinsic_types;
}

// RV32
// === AES32: Zkn (RV32), Zknd, Zkne 
// def aesdsi : RVK32Inst<["int32_t", "int32_t", "uint8_t"], "int32_t" , "ZiZiZiUi", [0,1,2]>;
// def aes32dsmi : RVK32Inst<["int32_t", "int32_t", "uint8_t"], "int32_t" , "ZiZiZiUi", [0,1,2]>;
// def aes32esi : RVK32Inst<["int32_t", "int32_t", "uint8_t"], "int32_t" , "ZiZiZiUi", [0,1,2]>;
// def aes32esmi : RVK32Inst<["int32_t", "int32_t", "uint8_t"], "int32_t" , "ZiZiZiUi", [0,1,2]>;


// RV64
// AES64: Zkn (RV64), Zknd, Zkne
def aes64dsm : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">;
def aes64ds  : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">;
def aes64ks2 : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">;
def aes64esm : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">;
def aes64es  : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">;
// def aes64ks1i : RVK64Inst<["int64_t", "int"], "int64_t", "WiWii">;
def aes64im : RVK64Inst<["int64_t"], "int64_t", "WiWi">;

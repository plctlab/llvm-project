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

class RVK32Inst<string name, list<string> param_types = [], string return_types, string types> 
            : Inst<name, 1, 0, param_types, return_types, types>;

class RVK64Inst<string name, list<string> param_types = [], string return_types, string types> 
            : Inst<name, 0, 1, param_types, return_types, types>;

class RVKInst<string name, list<string> param_types = [], string return_types, string types> 
            : Inst<name, 1, 1, param_types, return_types, types>;

class RVK32InstBinary<string name, list<string> param_types, string return_types, string types, list<int> intrinsic_types = []>
            : RVK32Inst<name, param_types, return_types, types>{
    let IntrinsicTypes = intrinsic_types;
}

class RVK64InstBinary<string name, list<string> param_types, string return_types, string types, list<int> intrinsic_types = []>
            : RVK64Inst<name, param_types, return_types, types>{
    let IntrinsicTypes = intrinsic_types;
}


// def aesdsi : RVK32InstBinary<"aes32dsi", "ZZu8", [0,1,-1]>;

    def aes64dsm : RVK64InstBinary<"aes64dsm", ["int64_t", "int64_t"], "int64_t", "WiWiWi">;
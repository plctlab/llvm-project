//==--- rvkintrin.td - RISC-V Crypto Definitions -----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the TableGen definitions from which the RISC-V Crypto
// header file will be generated. It is also used to generate Clang CodeGen
// snippet.
//
//===----------------------------------------------------------------------===//

class Inst<string name, bit rv32, bit rv64,list<string> param_types, string return_types, string types>{
    string IntrinsicName = name;

    string BuiltinStr = types;
    list<int> IntrinsicTypes = [];
    list<string> paramTypes = param_types;
    string returnType = return_types;
    
    string Prefix = "";

    bit enableForRV32 = rv32;
    bit enableForRV64 = rv64;

    // If not empty, the emitter will use it to define the intrinsic emulate function 
    // so that it can be called without suport of k-Ext.
    code EmulateDef = [{}];
    // Should emit BUILTIN macro. Set to false if the intrinsic function can
    // be implemented by other existing builtin functions.
    bit ShouldEmitBuiltin = 1;
}

class EmulateIntr<string return_type, list<string> param_types>{
    string IntrinsicName = NAME;
    code EmulateDef = [{}];
    string returnType = return_type;
    list<string> paramTypes = param_types;
}

class RVK32Inst<list<string> param_types, string return_types, string types, list<int> intrinsic_types = []> 
            : Inst<NAME, 1, 0, param_types, return_types, types>{
    let IntrinsicTypes = intrinsic_types;
    let Prefix = "_rv32_";
}

class RVK64Inst<list<string> param_types, string return_types, string types, list<int> intrinsic_types = []> 
            : Inst<NAME, 0, 1, param_types, return_types, types>{
    let IntrinsicTypes = intrinsic_types;
    let Prefix = "_rv64_";
}

class RVKInst<list<string> param_types, string return_types, string types, list<int> intrinsic_types = []> 
            : Inst<NAME, 1, 1, param_types, return_types, types>{
    let IntrinsicTypes = intrinsic_types;
    let Prefix = "_rv_";
}

def _rvk_emu_aes_xtime : EmulateIntr<"uint8_t ",["uint8_t "]>{
    let EmulateDef = [{return (rs1 << 1) ^ ((rs1 & 0x80) ? 0x11B : 0x00);}];
}

def _rvk_emu_aes_fwd_mc_8 : EmulateIntr<"uint32_t",["uint32_t"]>{
    let EmulateDef = [{
        uint32_t x2;
        x2 = _rvk_emu_aes_xtime(rs1);				//	double rs1
        rs1 = ((rs1 ^ x2) << 24) |					//	0x03	MixCol MDS Matrix
            (rs1 << 16) |							//	0x01
            (rs1 << 8) |							//	0x01
            x2;									//	0x02
        return rs1;}];
}

def _rvk_emu_aes_fwd_mc_32 : EmulateIntr<"uint32_t",["uint32_t"]>{
    let EmulateDef = [{
        return	_rvk_emu_aes_fwd_mc_8(rs1 & 0xFF) ^
                _rv32_rol(_rvk_emu_aes_fwd_mc_8((rs1 >>  8) & 0xFF),	8) ^
                _rv32_rol(_rvk_emu_aes_fwd_mc_8((rs1 >> 16) & 0xFF), 16) ^
                _rv32_rol(_rvk_emu_aes_fwd_mc_8((rs1 >> 24) & 0xFF), 24);}];
}

def _rvk_emu_aes_inv_mc_8 : EmulateIntr<"uint32_t",["uint32_t"]>{
    let EmulateDef = [{
        uint32_t x2, x4, x8;
        x2 = _rvk_emu_aes_xtime(rs1);				//	double rs1
        x4 = _rvk_emu_aes_xtime(x2);			//	double to 4*rs1
        x8 = _rvk_emu_aes_xtime(x4);			//	double to 8*rs1
        rs1 = ((rs1 ^ x2 ^ x8) << 24) |				//	0x0B	Inv MixCol MDS Matrix
            ((rs1 ^ x4 ^ x8) << 16) |				//	0x0D
            ((rs1 ^ x8) << 8) |					//	0x09
            (x2 ^ x4 ^ x8);						//	0x0E
        return rs1;}];
}

def _rvk_emu_aes_inv_mc_32 : EmulateIntr<"uint32_t",["uint32_t"]>{
    let EmulateDef = [{
        return	_rvk_emu_aes_inv_mc_8(rs1 & 0xFF) ^
                _rv32_rol(_rvk_emu_aes_inv_mc_8((rs1 >>  8) & 0xFF),	8) ^
                _rv32_rol(_rvk_emu_aes_inv_mc_8((rs1 >> 16) & 0xFF), 16) ^
                _rv32_rol(_rvk_emu_aes_inv_mc_8((rs1 >> 24) & 0xFF), 24);}];
}

// RV32
// === AES32: Zkn (RV32), Zknd, Zkne 
def aes32dsi : RVK32Inst<["int32_t", "int32_t", "uint8_t"], "int32_t" , "ZiZiZiUc">{
    let EmulateDef = [{
        int32_t x;

	    rs3 = (rs3 & 3) << 3;						//	byte select
	    x = (rs2 >> rs3) & 0xFF;
	    x = _rvk_emu_aes_inv_sbox[x];			//	AES inverse s-box

	    return rs1 ^ _rv32_rol(x, rs3);}];
}

def aes32dsmi : RVK32Inst<["int32_t", "int32_t", "uint8_t"], "int32_t" , "ZiZiZiUc">{
    let EmulateDef = [{
        int32_t x;

	    rs3 = (rs3 & 3) << 3;						//	byte select
	    x = (rs2 >> rs3) & 0xFF;
	    x = _rvk_emu_aes_inv_sbox[x];			//	AES inverse s-box
	    x = _rvk_emu_aes_inv_mc_8(x);			//	inverse MixColumns

	    return rs1 ^ _rv32_rol(x, rs3);}];
}

def aes32esi : RVK32Inst<["int32_t", "int32_t", "uint8_t"], "int32_t" , "ZiZiZiUc">{
    let EmulateDef = [{
        int32_t x;

	    rs3 = (rs3 & 3) << 3;						//	byte select
	    x = (rs2 >> rs3) & 0xFF;
	    x = _rvk_emu_aes_fwd_sbox[x];			//	AES forward s-box

	    return rs1 ^ _rv32_rol(x, rs3);}];
}

def aes32esmi : RVK32Inst<["int32_t", "int32_t", "uint8_t"], "int32_t" , "ZiZiZiUc">{
    let EmulateDef = [{
        uint32_t x;

	    rs3 = (rs3 & 3) << 3;						//	byte select
	    x = (rs2 >> rs3) & 0xFF;
	    x = _rvk_emu_aes_fwd_sbox[x];			//	AES forward s-box
	    x = _rvk_emu_aes_fwd_mc_8(x);			//	forward MixColumns

	    return rs1 ^ _rv32_rol(x, rs3);}];
}

//	=== SHA512: Zkn (RV32), Zknh
def sha512sig0l : RVK32Inst<["int32_t", "int32_t"], "int32_t" , "ZiZiZi">{
    let EmulateDef = [{
        return	_rv32_srl(rs1, 1) ^ _rv32_srl(rs1, 7) ^ _rv32_srl(rs1, 8) ^
                _rv32_sll(rs2, 31) ^ _rv32_sll(rs2, 25) ^ _rv32_sll(rs2, 24);}];
}

def sha512sig0h : RVK32Inst<["int32_t", "int32_t"], "int32_t" , "ZiZiZi">{
    let EmulateDef = [{
        return	_rv32_srl(rs1, 1) ^ _rv32_srl(rs1, 7) ^ _rv32_srl(rs1, 8) ^
			    _rv32_sll(rs2, 31) ^ _rv32_sll(rs2, 24);}];
}

def sha512sig1l : RVK32Inst<["int32_t", "int32_t"], "int32_t" , "ZiZiZi">{
    let EmulateDef = [{
        return	_rv32_sll(rs1, 3) ^ _rv32_srl(rs1, 6) ^ _rv32_srl(rs1, 19) ^
			    _rv32_srl(rs2, 29) ^ _rv32_sll(rs2, 26) ^ _rv32_sll(rs2, 13);}];
}

def sha512sig1h : RVK32Inst<["int32_t", "int32_t"], "int32_t" , "ZiZiZi">{
    let EmulateDef = [{
        return	_rv32_sll(rs1, 3) ^ _rv32_srl(rs1, 6) ^ _rv32_srl(rs1, 19) ^
			    _rv32_srl(rs2, 29) ^ _rv32_sll(rs2, 13);}];
}

def sha512sum0r : RVK32Inst<["int32_t", "int32_t"], "int32_t" , "ZiZiZi">{
    let EmulateDef = [{
        return	_rv32_sll(rs1, 25) ^ _rv32_sll(rs1, 30) ^ _rv32_srl(rs1, 28) ^
			    _rv32_srl(rs2, 7) ^ _rv32_srl(rs2, 2) ^ _rv32_sll(rs2, 4);}];
}

def sha512sum1r : RVK32Inst<["int32_t", "int32_t"], "int32_t" , "ZiZiZi">{
    let EmulateDef = [{
        return	_rv32_sll(rs1, 23) ^ _rv32_srl(rs1, 14) ^ _rv32_srl(rs1, 18) ^
			    _rv32_srl(rs2, 9) ^ _rv32_sll(rs2, 18) ^ _rv32_sll(rs2, 14);}];
}


// RV64
// AES64: Zkn (RV64), Zknd, Zkne
def aes64ds  : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">{
    let EmulateDef = [{
        //	Half of inverse ShiftRows and SubBytes (last round)
        return ((int64_t) _rvk_emu_aes_inv_sbox[rs1 & 0xFF]) |
            (((int64_t) _rvk_emu_aes_inv_sbox[(rs2 >> 40) & 0xFF]) <<  8) |
            (((int64_t) _rvk_emu_aes_inv_sbox[(rs2 >> 16) & 0xFF]) << 16) |
            (((int64_t) _rvk_emu_aes_inv_sbox[(rs1 >> 56) & 0xFF]) << 24) |
            (((int64_t) _rvk_emu_aes_inv_sbox[(rs1 >> 32) & 0xFF]) << 32) |
            (((int64_t) _rvk_emu_aes_inv_sbox[(rs1 >>  8) & 0xFF]) << 40) |
            (((int64_t) _rvk_emu_aes_inv_sbox[(rs2 >> 48) & 0xFF]) << 48) |
            (((int64_t) _rvk_emu_aes_inv_sbox[(rs2 >> 24) & 0xFF]) << 56);}];
}

def aes64im : RVK64Inst<["int64_t"], "int64_t", "WiWi">{
    let EmulateDef = [{
        return ((int64_t) _rvk_emu_aes_inv_mc_32(rs1)) |
		(((int64_t) _rvk_emu_aes_inv_mc_32(rs1 >> 32)) << 32);}];
}

def aes64dsm : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">{
    let EmulateDef = [{
        int64_t x;
        x = _rv64_aes64ds(rs1, rs2);			//	Inverse ShiftRows, SubBytes
        x = _rv64_aes64im(x);					//	Inverse MixColumns
        return x;}];
}

def aes64ks2 : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">{
    let EmulateDef = [{
        uint32_t t;
        t = (rs1 >> 32) ^ (rs2 & 0xFFFFFFFF);	//	wrap 32 bits
        return ((int64_t) t) ^					//	low 32 bits
            (((int64_t) t) << 32) ^ (rs2 & 0xFFFFFFFF00000000ULL);}];
}

def aes64es  : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">{
    let EmulateDef = [{
        //	Half of forward ShiftRows and SubBytes (last round)
        return ((int64_t) _rvk_emu_aes_fwd_sbox[rs1 & 0xFF]) |
            (((int64_t) _rvk_emu_aes_fwd_sbox[(rs1 >> 40) & 0xFF]) <<  8) |
            (((int64_t) _rvk_emu_aes_fwd_sbox[(rs2 >> 16) & 0xFF]) << 16) |
            (((int64_t) _rvk_emu_aes_fwd_sbox[(rs2 >> 56) & 0xFF]) << 24) |
            (((int64_t) _rvk_emu_aes_fwd_sbox[(rs1 >> 32) & 0xFF]) << 32) |
            (((int64_t) _rvk_emu_aes_fwd_sbox[(rs2 >>  8) & 0xFF]) << 40) |
            (((int64_t) _rvk_emu_aes_fwd_sbox[(rs2 >> 48) & 0xFF]) << 48) |
            (((int64_t) _rvk_emu_aes_fwd_sbox[(rs1 >> 24) & 0xFF]) << 56);}];
}

def aes64esm : RVK64Inst<["int64_t", "int64_t"], "int64_t", "WiWiWi">{
    let EmulateDef = [{
        int64_t x;
        x = _rv64_aes64es(rs1, rs2);			//	ShiftRows and SubBytes
        x = ((int64_t) _rvk_emu_aes_fwd_mc_32(x)) |		//	MixColumns
            (((int64_t) _rvk_emu_aes_fwd_mc_32(x >> 32)) << 32);
        return x;}];
}


def aes64ks1i : RVK64Inst<["int64_t", "int"], "int64_t", "WiWiUi">{
    let EmulateDef = [{
        //	AES Round Constants
        const uint8_t aes_rcon[] = {
            0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36
        };

        uint32_t t, rc;

        t = rs1 >> 32;							//	high word
        rc = 0;

        if (rcon < 10) {						//	10: don't do it
            t = _rv32_ror(t, 8);
            rc = aes_rcon[rcon];				//	round constant
        }
        //	SubWord
        t = ((uint32_t) _rvk_emu_aes_fwd_sbox[t & 0xFF]) |
            (((uint32_t) _rvk_emu_aes_fwd_sbox[(t >> 8) & 0xFF]) << 8) |
            (((uint32_t) _rvk_emu_aes_fwd_sbox[(t >> 16) & 0xFF]) << 16) |
            (((uint32_t) _rvk_emu_aes_fwd_sbox[(t >> 24) & 0xFF]) << 24);

        t ^= rc;

        return ((int64_t) t) | (((int64_t) t) << 32);}];
}



//	=== SHA512: Zkn (RV64), Zknh
def sha512sig0 : RVK64Inst<["int64_t"], "int64_t", "WiWi">{
    let EmulateDef = [{
        return _rv64_ror(rs1, 1) ^ _rv64_ror(rs1, 8) ^ _rv64_srl(rs1, 7);}];
}
def sha512sig1 : RVK64Inst<["int64_t"], "int64_t", "WiWi">{
    let EmulateDef = [{
        return _rv64_ror(rs1, 19) ^ _rv64_ror(rs1, 61) ^ _rv64_srl(rs1, 6);}];
}
def sha512sum0 : RVK64Inst<["int64_t"], "int64_t", "WiWi">{
    let EmulateDef = [{
        return _rv64_ror(rs1, 28) ^ _rv64_ror(rs1, 34) ^ _rv64_ror(rs1, 39);}];
}
def sha512sum1 : RVK64Inst<["int64_t"], "int64_t", "WiWi">{
    let EmulateDef = [{
        return _rv64_ror(rs1, 14) ^ _rv64_ror(rs1, 18) ^ _rv64_ror(rs1, 41);}];
}

// RV32&64

//	=== SHA256: Zkn (RV32, RV64), Zknh
def sha256sig0 : RVKInst<["long"],"long","LiLi",[0,-1]>{
    let EmulateDef = [{
        return _rv32_ror(rs1, 7) ^ _rv32_ror(rs1, 18) ^ _rv32_srl(rs1, 3);}];
}
def sha256sig1 : RVKInst<["long"],"long","LiLi",[0,-1]>{
    let EmulateDef = [{
        return _rv32_ror(rs1, 17) ^ _rv32_ror(rs1, 19) ^ _rv32_srl(rs1, 10);}];
}
def sha256sum0 : RVKInst<["long"],"long","LiLi",[0,-1]>{
    let EmulateDef = [{
        return _rv32_ror(rs1, 2) ^ _rv32_ror(rs1, 13) ^ _rv32_ror(rs1, 22);}];
}
def sha256sum1 : RVKInst<["long"],"long","LiLi",[0,-1]>{
    let EmulateDef = [{
        return _rv32_ror(rs1, 6) ^ _rv32_ror(rs1, 11) ^ _rv32_ror(rs1, 25);}];
}

//	=== SM3:	Zks (RV32, RV64), Zksh 
def sm3p0 : RVKInst<["long"],"long","LiLi",[0,-1]>{
    let EmulateDef = [{
        return rs1 ^ _rv32_ror(rs1, 15) ^ _rv32_ror(rs1, 23);}];
}
def sm3p1 : RVKInst<["long"],"long","LiLi",[0,-1]>{
    let EmulateDef = [{
        return rs1 ^ _rv32_ror(rs1, 9) ^ _rv32_ror(rs1, 17);}];
}
//	=== SM4:	Zks (RV32, RV64), Zksed
def sm4ks : RVKInst<["long","long","uint8_t"],"long","LiLiLiUc",[0,1,2,-1]>{
    let EmulateDef = [{
        uint32_t x;

        rs3 = (rs3 & 3) << 3;						//	byte select
        x = (rs2 >> rs3) & 0xFF;
        x = _rvk_emu_sm4_sbox[x];				//	SM4 s-box

        //	SM4 transform L' (key)
        x = x ^ ((x & 0x07) << 29) ^ ((x & 0xFE) << 7) ^
            ((x & 1) << 23) ^ ((x & 0xF8) << 13);

        return rs1 ^ _rv32_rol(x, rs3);
    }];
}

def sm4ed : RVKInst<["long","long","uint8_t"],"long","LiLiLiUc",[0,1,2,-1]>{
    let EmulateDef = [{
        uint32_t x;

        rs3 = (rs3 & 3) << 3;						//	byte select
        x = (rs2 >> rs3) & 0xFF;
        x = _rvk_emu_sm4_sbox[x];				//	SM4 s-box

        //	SM4 linear transform L
        x = x ^ (x << 8) ^ (x << 2) ^ (x << 18) ^
                ((x & 0x3F) << 26) ^ ((x & 0xC0) << 10);

        return rs1 ^ _rv32_rol(x, rs3);
    }];
}

//	===	Entropy source: Zkr (RV32, RV64)
def getnoise    : RVKInst<[],"long","Li",[-1]>;
def pollentropy : RVKInst<[],"long","Li",[-1]>; 

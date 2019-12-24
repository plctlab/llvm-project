# RUN: llvm-mc %s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s


# CHECK-ASM-AND-OBJ: vlb.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x10]
vlb.v v0, (a1), v0.t
 
# CHECK-ASM-AND-OBJ: vlh.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x10]
vlh.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlw.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x10]
vlw.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlbu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x00]
vlbu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlhu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x00]
vlhu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlwu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x00]
vlwu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vle.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x00]
vle.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsb.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x00]
vsb.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsh.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x00]
vsh.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsw.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x00]
vsw.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vse.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x00]
vse.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlsb.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x18]
vlsb.v v0, (a1), a2, v0.t
 
# CHECK-ASM-AND-OBJ: vlsh.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x18]
vlsh.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsw.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x18]
vlsw.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsbu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x08]
vlsbu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlshu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x08]
vlshu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlswu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x08]
vlswu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlse.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x08]
vlse.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssb.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x08]
vssb.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssh.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x08]
vssh.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssw.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x08]
vssw.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vsse.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x08]
vsse.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlxb.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x1c]
vlxb.v v0, (a1), v2, v0.t
 
# CHECK-ASM-AND-OBJ: vlxh.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x1c]
vlxh.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxw.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x1c]
vlxw.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxbu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x0c]
vlxbu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxhu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x0c]
vlxhu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxwu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x0c]
vlxwu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxe.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x0c]
vlxe.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxb.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x0c]
vsxb.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxh.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x0c]
vsxh.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxw.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x0c]
vsxw.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxe.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x0c]
vsxe.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsuxb.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x1c]
vsuxb.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsuxh.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x1c]
vsuxh.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsuxw.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x1c]
vsuxw.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsuxe.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x1c]
vsuxe.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlbff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x11]
vlbff.v v0, (a1), v0.t
 
# CHECK-ASM-AND-OBJ: vlhff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x11]
vlhff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlwff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x11]
vlwff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlbuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x01]
vlbuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlhuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x01]
vlhuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlwuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x01]
vlwuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vleff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x01]
vleff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vwadd.vx v0, v1, zero, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x10,0xc4]
vwcvt.x.x.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vwaddu.vx v0, v1, zero, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x10,0xc0]
vwcvtu.x.x.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vxor.vi v0, v1, -1, v0.t
# CHECK-ASM: encoding: [0x57,0xb0,0x1f,0x2c]
vnot.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vmslt.vv v0, v2, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x80,0x20,0x6c]
vmsgt.vv v0, v1, v2, v0.t

# CHECK-ASM-AND-OBJ: vmsltu.vv v0, v2, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x80,0x20,0x68]
vmsgtu.vv v0, v1, v2, v0.t

# CHECK-ASM-AND-OBJ: vmsle.vv v0, v2, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x80,0x20,0x74]
vmsge.vv v0, v1, v2, v0.t

# CHECK-ASM-AND-OBJ: vmsleu.vv v0, v2, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x80,0x20,0x70]
vmsgeu.vv v0, v1, v2, v0.t

# CHECK-ASM-AND-OBJ: vmflt.vv v0, v2, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x90,0x20,0x6c]
vmfgt.vv v0, v1, v2, v0.t

# CHECK-ASM-AND-OBJ: vmfle.vv v0, v2, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x90,0x20,0x64]
vmfge.vv v0, v1, v2, v0.t

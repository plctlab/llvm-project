# RUN: llvm-mc %s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s


# CHECK-ASM-AND-OBJ: vlb.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x12]
vlb.v v0, (a1)
 
# CHECK-ASM-AND-OBJ: vlh.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x12]
vlh.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlw.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x12]
vlw.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlbu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x02]
vlbu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlhu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x02]
vlhu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlwu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x02]
vlwu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vle.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x02]
vle.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsb.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x02]
vsb.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsh.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x02]
vsh.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsw.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x02]
vsw.v v0, (a1)

# CHECK-ASM-AND-OBJ: vse.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x02]
vse.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlsb.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x1a]
vlsb.v v0, (a1), a2
 
# CHECK-ASM-AND-OBJ: vlsh.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x1a]
vlsh.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsw.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x1a]
vlsw.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsbu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x0a]
vlsbu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlshu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x0a]
vlshu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlswu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x0a]
vlswu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlse.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x0a]
vlse.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssb.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x0a]
vssb.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssh.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x0a]
vssh.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssw.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x0a]
vssw.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vsse.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x0a]
vsse.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlxb.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x1e]
vlxb.v v0, (a1), v2
 
# CHECK-ASM-AND-OBJ: vlxh.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x1e]
vlxh.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxw.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x1e]
vlxw.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxbu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x0e]
vlxbu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxhu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x0e]
vlxhu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxwu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x0e]
vlxwu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxe.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x0e]
vlxe.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxb.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x0e]
vsxb.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxh.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x0e]
vsxh.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxw.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x0e]
vsxw.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxe.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x0e]
vsxe.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsuxb.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x1e]
vsuxb.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsuxh.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x1e]
vsuxh.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsuxw.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x1e]
vsuxw.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsuxe.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x1e]
vsuxe.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlbff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x13]
vlbff.v v0, (a1)
 
# CHECK-ASM-AND-OBJ: vlhff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x13]
vlhff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlwff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x13]
vlwff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlbuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x03]
vlbuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlhuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x03]
vlhuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlwuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x03]
vlwuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vleff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x03]
vleff.v v0, (a1)

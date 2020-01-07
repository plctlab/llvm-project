# RUN: llvm-mc %s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s


# CHECK-ASM-AND-OBJ: vsetvl a3, a3, a2
# CHECK-ASM: encoding: [0xd7,0xf6,0xc6,0x80]
vsetvl a3, a3, a2

# CHECK-ASM-AND-OBJ: vsetvli a0, a1, e16,m2,d4
# CHECK-ASM: encoding: [0x57,0xf5,0x55,0x04]
vsetvli a0, a1, e16,m2,d4

# CHECK-ASM-AND-OBJ: vsetvli a0, a1, e1024,m8,d8
# CHECK-ASM: encoding: [0x57,0xf5,0xf5,0x07]
vsetvli a0, a1, e1024, m8, d8

# CHECK-ASM-AND-OBJ: vsetvli a0, a1, e8,m1,d1
# CHECK-ASM: encoding: [0x57,0xf5,0x05,0x00]
vsetvli a0, a1, e8

# CHECK-ASM-AND-OBJ: vsetvli a0, a1, e8,m2,d1
# CHECK-ASM: encoding: [0x57,0xf5,0x15,0x00]
vsetvli a0, a1, e8, m2

# CHECK-ASM-AND-OBJ: vsetvli a0, a1, e16,m1,d4
# CHECK-ASM: encoding: [0x57,0xf5,0x45,0x04]
vsetvli a0, a1, e16, d4

# CHECK-ASM-AND-OBJ: vlb.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x12]
vlb.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlh.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x12]
vlh.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlw.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x12]
vlw.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlbu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x02]
vlbu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlhu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x02]
vlhu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlwu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x02]
vlwu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vle.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x02]
vle.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsb.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x02]
vsb.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsh.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x02]
vsh.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsw.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x02]
vsw.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vse.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x02]
vse.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlsb.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x1a]
vlsb.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsh.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x1a]
vlsh.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsw.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x1a]
vlsw.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsbu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x0a]
vlsbu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlshu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x0a]
vlshu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlswu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x0a]
vlswu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlse.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x0a]
vlse.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssb.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x0a]
vssb.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssh.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x0a]
vssh.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssw.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x0a]
vssw.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vsse.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x0a]
vsse.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlxb.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x1e]
vlxb.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxh.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x1e]
vlxh.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxw.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x1e]
vlxw.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxbu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x0e]
vlxbu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxhu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x0e]
vlxhu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxwu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x0e]
vlxwu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxe.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x0e]
vlxe.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxb.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x0e]
vsxb.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxh.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x0e]
vsxh.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxw.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x0e]
vsxw.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxe.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x0e]
vsxe.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsuxb.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x1e]
vsuxb.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsuxh.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x1e]
vsuxh.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsuxw.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x1e]
vsuxw.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsuxe.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x1e]
vsuxe.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlbff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x13]
vlbff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlhff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x13]
vlhff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlwff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x13]
vlwff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlbuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x03]
vlbuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlhuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x03]
vlhuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlwuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x03]
vlwuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vleff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x03]
vleff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x32]
vlseg2b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x32]
vlseg2h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x32]
vlseg2w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x22]
vlseg2bu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x22]
vlseg2hu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x22]
vlseg2wu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x22]
vlseg2e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg2b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x22]
vsseg2b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg2h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x22]
vsseg2h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg2w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x22]
vsseg2w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg2e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x22]
vsseg2e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x52]
vlseg3b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x52]
vlseg3h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x52]
vlseg3w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x42]
vlseg3bu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x42]
vlseg3hu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x42]
vlseg3wu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x42]
vlseg3e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg3b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x42]
vsseg3b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg3h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x42]
vsseg3h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg3w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x42]
vsseg3w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg3e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x42]
vsseg3e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x72]
vlseg4b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x72]
vlseg4h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x72]
vlseg4w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x62]
vlseg4bu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x62]
vlseg4hu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x62]
vlseg4wu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x62]
vlseg4e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg4b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x62]
vsseg4b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg4h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x62]
vsseg4h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg4w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x62]
vsseg4w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg4e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x62]
vsseg4e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x92]
vlseg5b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x92]
vlseg5h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x92]
vlseg5w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x82]
vlseg5bu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x82]
vlseg5hu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x82]
vlseg5wu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x82]
vlseg5e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg5b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x82]
vsseg5b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg5h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x82]
vsseg5h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg5w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x82]
vsseg5w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg5e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x82]
vsseg5e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xb2]
vlseg6b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xb2]
vlseg6h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xb2]
vlseg6w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xa2]
vlseg6bu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xa2]
vlseg6hu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xa2]
vlseg6wu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xa2]
vlseg6e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg6b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0xa2]
vsseg6b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg6h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0xa2]
vsseg6h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg6w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0xa2]
vsseg6w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg6e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0xa2]
vsseg6e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xd2]
vlseg7b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xd2]
vlseg7h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xd2]
vlseg7w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xc2]
vlseg7bu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xc2]
vlseg7hu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xc2]
vlseg7wu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xc2]
vlseg7e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg7b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0xc2]
vsseg7b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg7h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0xc2]
vsseg7h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg7w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0xc2]
vsseg7w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg7e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0xc2]
vsseg7e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xf2]
vlseg8b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xf2]
vlseg8h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xf2]
vlseg8w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xe2]
vlseg8bu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xe2]
vlseg8hu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xe2]
vlseg8wu.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xe2]
vlseg8e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg8b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0xe2]
vsseg8b.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg8h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0xe2]
vsseg8h.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg8w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0xe2]
vsseg8w.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsseg8e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0xe2]
vsseg8e.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlsseg2b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x3a]
vlsseg2b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x3a]
vlsseg2h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x3a]
vlsseg2w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x2a]
vlsseg2bu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x2a]
vlsseg2hu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x2a]
vlsseg2wu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x2a]
vlsseg2e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg2b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x2a]
vssseg2b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg2h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x2a]
vssseg2h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg2w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x2a]
vssseg2w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg2e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x2a]
vssseg2e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x5a]
vlsseg3b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x5a]
vlsseg3h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x5a]
vlsseg3w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x4a]
vlsseg3bu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x4a]
vlsseg3hu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x4a]
vlsseg3wu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x4a]
vlsseg3e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg3b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x4a]
vssseg3b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg3h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x4a]
vssseg3h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg3w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x4a]
vssseg3w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg3e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x4a]
vssseg3e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x7a]
vlsseg4b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x7a]
vlsseg4h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x7a]
vlsseg4w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x6a]
vlsseg4bu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x6a]
vlsseg4hu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x6a]
vlsseg4wu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x6a]
vlsseg4e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg4b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x6a]
vssseg4b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg4h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x6a]
vssseg4h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg4w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x6a]
vssseg4w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg4e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x6a]
vssseg4e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x9a]
vlsseg5b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x9a]
vlsseg5h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x9a]
vlsseg5w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x8a]
vlsseg5bu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x8a]
vlsseg5hu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x8a]
vlsseg5wu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x8a]
vlsseg5e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg5b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x8a]
vssseg5b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg5h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x8a]
vssseg5h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg5w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x8a]
vssseg5w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg5e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x8a]
vssseg5e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xba]
vlsseg6b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xba]
vlsseg6h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xba]
vlsseg6w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xaa]
vlsseg6bu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xaa]
vlsseg6hu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xaa]
vlsseg6wu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0xaa]
vlsseg6e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg6b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0xaa]
vssseg6b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg6h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0xaa]
vssseg6h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg6w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0xaa]
vssseg6w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg6e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0xaa]
vssseg6e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xda]
vlsseg7b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xda]
vlsseg7h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xda]
vlsseg7w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xca]
vlsseg7bu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xca]
vlsseg7hu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xca]
vlsseg7wu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0xca]
vlsseg7e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg7b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0xca]
vssseg7b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg7h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0xca]
vssseg7h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg7w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0xca]
vssseg7w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg7e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0xca]
vssseg7e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xfa]
vlsseg8b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xfa]
vlsseg8h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xfa]
vlsseg8w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xea]
vlsseg8bu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xea]
vlsseg8hu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xea]
vlsseg8wu.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0xea]
vlsseg8e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg8b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0xea]
vssseg8b.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg8h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0xea]
vssseg8h.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg8w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0xea]
vssseg8w.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vssseg8e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0xea]
vssseg8e.v v0, 0(a1), a2

# CHECK-ASM-AND-OBJ: vlxseg2b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x3e]
vlxseg2b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x3e]
vlxseg2h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x3e]
vlxseg2w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x2e]
vlxseg2bu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x2e]
vlxseg2hu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x2e]
vlxseg2wu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x2e]
vlxseg2e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg2b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x2e]
vsxseg2b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg2h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x2e]
vsxseg2h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg2w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x2e]
vsxseg2w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg2e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x2e]
vsxseg2e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x5e]
vlxseg3b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x5e]
vlxseg3h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x5e]
vlxseg3w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x4e]
vlxseg3bu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x4e]
vlxseg3hu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x4e]
vlxseg3wu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x4e]
vlxseg3e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg3b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x4e]
vsxseg3b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg3h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x4e]
vsxseg3h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg3w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x4e]
vsxseg3w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg3e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x4e]
vsxseg3e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x7e]
vlxseg4b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x7e]
vlxseg4h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x7e]
vlxseg4w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x6e]
vlxseg4bu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x6e]
vlxseg4hu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x6e]
vlxseg4wu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x6e]
vlxseg4e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg4b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x6e]
vsxseg4b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg4h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x6e]
vsxseg4h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg4w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x6e]
vsxseg4w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg4e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x6e]
vsxseg4e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x9e]
vlxseg5b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x9e]
vlxseg5h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x9e]
vlxseg5w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x8e]
vlxseg5bu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x8e]
vlxseg5hu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x8e]
vlxseg5wu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x8e]
vlxseg5e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg5b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x8e]
vsxseg5b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg5h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x8e]
vsxseg5h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg5w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x8e]
vsxseg5w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg5e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x8e]
vsxseg5e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xbe]
vlxseg6b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xbe]
vlxseg6h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xbe]
vlxseg6w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xae]
vlxseg6bu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xae]
vlxseg6hu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xae]
vlxseg6wu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0xae]
vlxseg6e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg6b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0xae]
vsxseg6b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg6h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0xae]
vsxseg6h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg6w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0xae]
vsxseg6w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg6e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0xae]
vsxseg6e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xde]
vlxseg7b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xde]
vlxseg7h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xde]
vlxseg7w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xce]
vlxseg7bu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xce]
vlxseg7hu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xce]
vlxseg7wu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0xce]
vlxseg7e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg7b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0xce]
vsxseg7b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg7h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0xce]
vsxseg7h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg7w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0xce]
vsxseg7w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg7e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0xce]
vsxseg7e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xfe]
vlxseg8b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xfe]
vlxseg8h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xfe]
vlxseg8w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xee]
vlxseg8bu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xee]
vlxseg8hu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xee]
vlxseg8wu.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0xee]
vlxseg8e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg8b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0xee]
vsxseg8b.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg8h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0xee]
vsxseg8h.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg8w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0xee]
vsxseg8w.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vsxseg8e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0xee]
vsxseg8e.v v0, 0(a1), v2

# CHECK-ASM-AND-OBJ: vlseg2bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x33]
vlseg2bff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x33]
vlseg2hff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x33]
vlseg2wff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x23]
vlseg2buff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x23]
vlseg2huff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x23]
vlseg2wuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg2eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x23]
vlseg2eff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x53]
vlseg3bff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x53]
vlseg3hff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x53]
vlseg3wff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x43]
vlseg3buff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x43]
vlseg3huff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x43]
vlseg3wuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg3eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x43]
vlseg3eff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x73]
vlseg4bff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x73]
vlseg4hff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x73]
vlseg4wff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x63]
vlseg4buff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x63]
vlseg4huff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x63]
vlseg4wuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg4eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x63]
vlseg4eff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x93]
vlseg5bff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x93]
vlseg5hff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x93]
vlseg5wff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x83]
vlseg5buff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x83]
vlseg5huff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x83]
vlseg5wuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg5eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x83]
vlseg5eff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xb3]
vlseg6bff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xb3]
vlseg6hff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xb3]
vlseg6wff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xa3]
vlseg6buff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xa3]
vlseg6huff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xa3]
vlseg6wuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg6eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xa3]
vlseg6eff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xd3]
vlseg7bff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xd3]
vlseg7hff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xd3]
vlseg7wff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xc3]
vlseg7buff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xc3]
vlseg7huff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xc3]
vlseg7wuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg7eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xc3]
vlseg7eff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xf3]
vlseg8bff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xf3]
vlseg8hff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xf3]
vlseg8wff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xe3]
vlseg8buff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xe3]
vlseg8huff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xe3]
vlseg8wuff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vlseg8eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xe3]
vlseg8eff.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vl1r.v v3, 0(a1)
# CHECK-ASM: encoding: [0x87,0xf1,0x85,0x02]
vl1r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vs1r.v v3, 0(a1)
# CHECK-ASM: encoding: [0xa7,0xf1,0x85,0x02]
vs1r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vl2r.v v3, 0(a1)
# CHECK-ASM: encoding: [0x87,0xf1,0x85,0x22]
vl2r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vs2r.v v3, 0(a1)
# CHECK-ASM: encoding: [0xa7,0xf1,0x85,0x22]
vs2r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vl3r.v v3, 0(a1)
# CHECK-ASM: encoding: [0x87,0xf1,0x85,0x42]
vl3r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vs3r.v v3, 0(a1)
# CHECK-ASM: encoding: [0xa7,0xf1,0x85,0x42]
vs3r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vl4r.v v3, 0(a1)
# CHECK-ASM: encoding: [0x87,0xf1,0x85,0x62]
vl4r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vs4r.v v3, 0(a1)
# CHECK-ASM: encoding: [0xa7,0xf1,0x85,0x62]
vs4r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vl5r.v v3, 0(a1)
# CHECK-ASM: encoding: [0x87,0xf1,0x85,0x82]
vl5r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vs5r.v v3, 0(a1)
# CHECK-ASM: encoding: [0xa7,0xf1,0x85,0x82]
vs5r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vl6r.v v3, 0(a1)
# CHECK-ASM: encoding: [0x87,0xf1,0x85,0xa2]
vl6r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vs6r.v v3, 0(a1)
# CHECK-ASM: encoding: [0xa7,0xf1,0x85,0xa2]
vs6r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vl7r.v v3, 0(a1)
# CHECK-ASM: encoding: [0x87,0xf1,0x85,0xc2]
vl7r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vs7r.v v3, 0(a1)
# CHECK-ASM: encoding: [0xa7,0xf1,0x85,0xc2]
vs7r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vl8r.v v3, 0(a1)
# CHECK-ASM: encoding: [0x87,0xf1,0x85,0xe2]
vl8r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vs8r.v v3, 0(a1)
# CHECK-ASM: encoding: [0xa7,0xf1,0x85,0xe2]
vs8r.v v3, 0(a1)

# CHECK-ASM-AND-OBJ: vamoswapw.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x0e]
vamoswapw.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoswapw.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x0a]
vamoswapw.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoaddw.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x06]
vamoaddw.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoaddw.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x02]
vamoaddw.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoxorw.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x26]
vamoxorw.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoxorw.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x22]
vamoxorw.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoandw.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x66]
vamoandw.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoandw.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x62]
vamoandw.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoorw.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x46]
vamoorw.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoorw.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x42]
vamoorw.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamominw.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x86]
vamominw.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamominw.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0x82]
vamominw.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomaxw.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0xa6]
vamomaxw.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomaxw.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0xa2]
vamomaxw.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamominuw.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0xc6]
vamominuw.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamominuw.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0xc2]
vamominuw.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomaxuw.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0xe6]
vamomaxuw.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomaxuw.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xe0,0x25,0xe2]
vamomaxuw.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoswape.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x0e]
vamoswape.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoswape.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x0a]
vamoswape.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoadde.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x06]
vamoadde.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoadde.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x02]
vamoadde.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoxore.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x26]
vamoxore.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoxore.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x22]
vamoxore.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoande.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x66]
vamoande.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoande.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x62]
vamoande.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoore.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x46]
vamoore.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamoore.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x42]
vamoore.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomine.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x86]
vamomine.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomine.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0x82]
vamomine.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomaxe.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0xa6]
vamomaxe.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomaxe.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0xa2]
vamomaxe.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamominue.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0xc6]
vamominue.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamominue.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0xc2]
vamominue.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomaxue.v v0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0xe6]
vamomaxue.v v0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vamomaxue.v x0, 0(a1), v2, v0
# CHECK-ASM: encoding: [0x2f,0xf0,0x25,0xe2]
vamomaxue.v x0, 0(a1), v2, v0

# CHECK-ASM-AND-OBJ: vadd.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x02]
vadd.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vadd.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x02]
vadd.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vadd.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x02]
vadd.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vsub.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x0a]
vsub.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vsub.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x0a]
vsub.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vrsub.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x0e]
vrsub.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vrsub.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x0e]
vrsub.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vwaddu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xc2]
vwaddu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwaddu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xc2]
vwaddu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwsubu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xca]
vwsubu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwsubu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xca]
vwsubu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwadd.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xc6]
vwadd.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwadd.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xc6]
vwadd.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwsub.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xce]
vwsub.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwsub.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xce]
vwsub.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwaddu.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xd2]
vwaddu.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwaddu.wx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xd2]
vwaddu.wx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwsubu.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xda]
vwsubu.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwsubu.wx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xda]
vwsubu.wx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwadd.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xd6]
vwadd.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwadd.wx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xd6]
vwadd.wx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwsub.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xde]
vwsub.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwsub.wx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xde]
vwsub.wx v0, v1, a0

# CHECK-ASM-AND-OBJ: vadc.vvm v0, v1, v0, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x40]
vadc.vvm v0, v1, v0, v0

# CHECK-ASM-AND-OBJ: vadc.vxm v0, v1, a0, v0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x40]
vadc.vxm v0, v1, a0, v0

# CHECK-ASM-AND-OBJ: vadc.vim v0, v1, 0, v0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x40]
vadc.vim v0, v1, 0, v0

# CHECK-ASM-AND-OBJ: vmadc.vvm v0, v1, v0, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x44]
vmadc.vvm v0, v1, v0, v0

# CHECK-ASM-AND-OBJ: vmadc.vxm v0, v1, a0, v0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x44]
vmadc.vxm v0, v1, a0, v0

# CHECK-ASM-AND-OBJ: vmadc.vim v0, v1, 0, v0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x44]
vmadc.vim v0, v1, 0, v0

# CHECK-ASM-AND-OBJ: vmadc.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x46]
vmadc.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmadc.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x46]
vmadc.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmadc.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x46]
vmadc.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vsbc.vvm v0, v1, v0, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x48]
vsbc.vvm v0, v1, v0, v0

# CHECK-ASM-AND-OBJ: vsbc.vxm v0, v1, a0, v0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x48]
vsbc.vxm v0, v1, a0, v0

# CHECK-ASM-AND-OBJ: vmsbc.vvm v0, v1, v0, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x4c]
vmsbc.vvm v0, v1, v0, v0

# CHECK-ASM-AND-OBJ: vmsbc.vxm v0, v1, a0, v0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x4c]
vmsbc.vxm v0, v1, a0, v0

# CHECK-ASM-AND-OBJ: vmsbc.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x4e]
vmsbc.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmsbc.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x4e]
vmsbc.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vand.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x26]
vand.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vand.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x26]
vand.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vand.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x26]
vand.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vor.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x2a]
vor.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vor.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x2a]
vor.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vor.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x2a]
vor.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vxor.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x2e]
vxor.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vxor.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x2e]
vxor.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vxor.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x2e]
vxor.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vsll.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x96]
vsll.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vsll.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x96]
vsll.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vsll.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x96]
vsll.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vsrl.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xa2]
vsrl.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vsrl.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xa2]
vsrl.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vsrl.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xa2]
vsrl.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vsra.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xa6]
vsra.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vsra.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xa6]
vsra.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vsra.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xa6]
vsra.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vnsrl.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xb2]
vnsrl.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vnsrl.wx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xb2]
vnsrl.wx v0, v1, a0

# CHECK-ASM-AND-OBJ: vnsrl.wi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xb2]
vnsrl.wi v0, v1, 0

# CHECK-ASM-AND-OBJ: vnsra.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xb6]
vnsra.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vnsra.wx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xb6]
vnsra.wx v0, v1, a0

# CHECK-ASM-AND-OBJ: vnsra.wi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xb6]
vnsra.wi v0, v1, 0

# CHECK-ASM-AND-OBJ: vmseq.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x62]
vmseq.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmseq.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x62]
vmseq.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmseq.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x62]
vmseq.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vmsne.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x66]
vmsne.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmsne.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x66]
vmsne.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmsne.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x66]
vmsne.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vmsltu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x6a]
vmsltu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmsltu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x6a]
vmsltu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmslt.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x6e]
vmslt.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmslt.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x6e]
vmslt.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmsleu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x72]
vmsleu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmsleu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x72]
vmsleu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmsleu.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x72]
vmsleu.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vmsle.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x76]
vmsle.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmsle.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x76]
vmsle.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmsle.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x76]
vmsle.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vmsgtu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x7a]
vmsgtu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmsgtu.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x7a]
vmsgtu.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vmsgt.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x7e]
vmsgt.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmsgt.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x7e]
vmsgt.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vminu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x12]
vminu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vminu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x12]
vminu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmin.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x16]
vmin.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmin.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x16]
vmin.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmaxu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x1a]
vmaxu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmaxu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x1a]
vmaxu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmax.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x1e]
vmax.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmax.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x1e]
vmax.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmul.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x96]
vmul.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmul.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x96]
vmul.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmulh.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x9e]
vmulh.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmulh.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x9e]
vmulh.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmulhu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x92]
vmulhu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmulhu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x92]
vmulhu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmulhsu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x9a]
vmulhsu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmulhsu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x9a]
vmulhsu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vdivu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x82]
vdivu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vdivu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x82]
vdivu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vdiv.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x86]
vdiv.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vdiv.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x86]
vdiv.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vremu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x8a]
vremu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vremu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x8a]
vremu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vrem.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x8e]
vrem.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vrem.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x8e]
vrem.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwmul.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xee]
vwmul.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwmul.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xee]
vwmul.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwmulu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xe2]
vwmulu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwmulu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xe2]
vwmulu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vwmulsu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xea]
vwmulsu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vwmulsu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xea]
vwmulsu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vmacc.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xb6]
vmacc.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vmacc.vx v0, a0, v1
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xb6]
vmacc.vx v0, a0, v1

# CHECK-ASM-AND-OBJ: vnmsac.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xbe]
vnmsac.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vnmsac.vx v0, a0, v1
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xbe]
vnmsac.vx v0, a0, v1

# CHECK-ASM-AND-OBJ: vmadd.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xa6]
vmadd.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vmadd.vx v0, a0, v1
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xa6]
vmadd.vx v0, a0, v1

# CHECK-ASM-AND-OBJ: vnmsub.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xae]
vnmsub.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vnmsub.vx v0, a0, v1
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xae]
vnmsub.vx v0, a0, v1

# CHECK-ASM-AND-OBJ: vwmaccu.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xf2]
vwmaccu.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vwmaccu.vx v0, a0, v1
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xf2]
vwmaccu.vx v0, a0, v1

# CHECK-ASM-AND-OBJ: vwmacc.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xf6]
vwmacc.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vwmacc.vx v0, a0, v1
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xf6]
vwmacc.vx v0, a0, v1

# CHECK-ASM-AND-OBJ: vwmaccsu.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xfa]
vwmaccsu.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vwmaccsu.vx v0, a0, v1
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xfa]
vwmaccsu.vx v0, a0, v1

# CHECK-ASM-AND-OBJ: vwmaccus.vx v0, a0, v1
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xfe]
vwmaccus.vx v0, a0, v1

# CHECK-ASM-AND-OBJ: vmerge.vvm v0, v1, v0, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x5c]
vmerge.vvm v0, v1, v0, v0

# CHECK-ASM-AND-OBJ: vmerge.vxm v0, v1, a0, v0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x5c]
vmerge.vxm v0, v1, a0, v0

# CHECK-ASM-AND-OBJ: vmerge.vim v0, v1, 0, v0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x5c]
vmerge.vim v0, v1, 0, v0

# CHECK-ASM-AND-OBJ: vmv.v.v v0, v0
# CHECK-ASM: encoding: [0x57,0x00,0x00,0x5e]
vmv.v.v v0, v0

# CHECK-ASM-AND-OBJ: vmv.v.x v0, a0
# CHECK-ASM: encoding: [0x57,0x40,0x05,0x5e]
vmv.v.x v0, a0

# CHECK-ASM-AND-OBJ: vmv.v.i v0, 0
# CHECK-ASM: encoding: [0x57,0x30,0x00,0x5e]
vmv.v.i v0, 0

# CHECK-ASM-AND-OBJ: vsaddu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x82]
vsaddu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vsaddu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x82]
vsaddu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vsaddu.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x82]
vsaddu.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vsadd.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x86]
vsadd.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vsadd.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x86]
vsadd.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vsadd.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x86]
vsadd.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vssubu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x8a]
vssubu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vssubu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x8a]
vssubu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vssub.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x8e]
vssub.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vssub.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x8e]
vssub.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vaaddu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x22]
vaaddu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vaaddu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x22]
vaaddu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vaadd.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x26]
vaadd.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vaadd.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x26]
vaadd.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vasubu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x2a]
vasubu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vasubu.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x2a]
vasubu.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vasub.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x2e]
vasub.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vasub.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x2e]
vasub.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vsmul.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x9e]
vsmul.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vsmul.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x9e]
vsmul.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vssrl.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xaa]
vssrl.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vssrl.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xaa]
vssrl.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vssrl.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xaa]
vssrl.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vssra.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xae]
vssra.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vssra.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xae]
vssra.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vssra.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xae]
vssra.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vnclipu.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xba]
vnclipu.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vnclipu.wx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xba]
vnclipu.wx v0, v1, a0

# CHECK-ASM-AND-OBJ: vnclipu.wi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xba]
vnclipu.wi v0, v1, 0

# CHECK-ASM-AND-OBJ: vnclip.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xbe]
vnclip.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vnclip.wx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xbe]
vnclip.wx v0, v1, a0

# CHECK-ASM-AND-OBJ: vnclip.wi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xbe]
vnclip.wi v0, v1, 0

# CHECK-ASM-AND-OBJ: vfadd.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x02]
vfadd.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfadd.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x02]
vfadd.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfsub.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x0a]
vfsub.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfsub.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x0a]
vfsub.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfrsub.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x9e]
vfrsub.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfwadd.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xc2]
vfwadd.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfwadd.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xc2]
vfwadd.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfwsub.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xca]
vfwsub.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfwsub.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xca]
vfwsub.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfwadd.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xd2]
vfwadd.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfwadd.wf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xd2]
vfwadd.wf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfwsub.wv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xda]
vfwsub.wv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfwsub.wf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xda]
vfwsub.wf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfmul.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x92]
vfmul.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfmul.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x92]
vfmul.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfdiv.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x82]
vfdiv.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfdiv.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x82]
vfdiv.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfrdiv.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x86]
vfrdiv.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfwmul.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xe2]
vfwmul.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfwmul.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xe2]
vfwmul.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfmacc.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xb2]
vfmacc.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfmacc.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xb2]
vfmacc.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfnmacc.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xb6]
vfnmacc.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfnmacc.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xb6]
vfnmacc.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfmsac.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xba]
vfmsac.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfmsac.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xba]
vfmsac.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfnmsac.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xbe]
vfnmsac.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfnmsac.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xbe]
vfnmsac.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfmadd.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xa2]
vfmadd.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfmadd.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xa2]
vfmadd.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfnmadd.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xa6]
vfnmadd.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfnmadd.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xa6]
vfnmadd.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfmsub.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xaa]
vfmsub.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfmsub.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xaa]
vfmsub.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfnmsub.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xae]
vfnmsub.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfnmsub.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xae]
vfnmsub.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfwmacc.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xf2]
vfwmacc.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfwmacc.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xf2]
vfwmacc.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfwnmacc.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xf6]
vfwnmacc.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfwnmacc.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xf6]
vfwnmacc.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfwmsac.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xfa]
vfwmsac.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfwmsac.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xfa]
vfwmsac.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfwnmsac.vv v0, v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xfe]
vfwnmsac.vv v0, v0, v1

# CHECK-ASM-AND-OBJ: vfwnmsac.vf v0, ft0, v1
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xfe]
vfwnmsac.vf v0, ft0, v1

# CHECK-ASM-AND-OBJ: vfsqrt.v v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x8e]
vfsqrt.v v0, v1

# CHECK-ASM-AND-OBJ: vfmin.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x12]
vfmin.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfmin.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x12]
vfmin.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfmax.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x1a]
vfmax.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfmax.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x1a]
vfmax.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfsgnj.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x22]
vfsgnj.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfsgnj.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x22]
vfsgnj.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfsgnjn.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x26]
vfsgnjn.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfsgnjn.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x26]
vfsgnjn.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfsgnjx.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x2a]
vfsgnjx.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfsgnjx.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x2a]
vfsgnjx.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vmfeq.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x62]
vmfeq.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmfeq.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x62]
vmfeq.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vmfne.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x72]
vmfne.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmfne.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x72]
vmfne.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vmflt.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x6e]
vmflt.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmflt.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x6e]
vmflt.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vmfle.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x66]
vmfle.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vmfle.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x66]
vmfle.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vmfgt.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x76]
vmfgt.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vmfge.vf v0, v1, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x7e]
vmfge.vf v0, v1, ft0

# CHECK-ASM-AND-OBJ: vfclass.v v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x18,0x8e]
vfclass.v v0, v1

# CHECK-ASM-AND-OBJ: vfmerge.vfm v0, v1, ft0, v0
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x5c]
vfmerge.vfm v0, v1, ft0, v0

# CHECK-ASM-AND-OBJ: vfmv.v.f v0, ft0
# CHECK-ASM: encoding: [0x57,0x50,0x00,0x5e]
vfmv.v.f v0, ft0

# CHECK-ASM-AND-OBJ: vfcvt.xu.f.v v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x8a]
vfcvt.xu.f.v v0, v1

# CHECK-ASM-AND-OBJ: vfcvt.x.f.v v0, v1
# CHECK-ASM: encoding: [0x57,0x90,0x10,0x8a]
vfcvt.x.f.v v0, v1

# CHECK-ASM-AND-OBJ: vfcvt.f.xu.v v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x11,0x8a]
vfcvt.f.xu.v v0, v1

# CHECK-ASM-AND-OBJ: vfcvt.f.x.v v0, v1
# CHECK-ASM: encoding: [0x57,0x90,0x11,0x8a]
vfcvt.f.x.v v0, v1

# CHECK-ASM-AND-OBJ: vfwcvt.xu.f.v v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x14,0x8a]
vfwcvt.xu.f.v v0, v1

# CHECK-ASM-AND-OBJ: vfwcvt.x.f.v v0, v1
# CHECK-ASM: encoding: [0x57,0x90,0x14,0x8a]
vfwcvt.x.f.v v0, v1

# CHECK-ASM-AND-OBJ: vfwcvt.f.xu.v v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x15,0x8a]
vfwcvt.f.xu.v v0, v1

# CHECK-ASM-AND-OBJ: vfwcvt.f.x.v v0, v1
# CHECK-ASM: encoding: [0x57,0x90,0x15,0x8a]
vfwcvt.f.x.v v0, v1

# CHECK-ASM-AND-OBJ: vfwcvt.f.f.v v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x16,0x8a]
vfwcvt.f.f.v v0, v1

# CHECK-ASM-AND-OBJ: vfncvt.xu.f.w v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x18,0x8a]
vfncvt.xu.f.w v0, v1

# CHECK-ASM-AND-OBJ: vfncvt.x.f.w v0, v1
# CHECK-ASM: encoding: [0x57,0x90,0x18,0x8a]
vfncvt.x.f.w v0, v1

# CHECK-ASM-AND-OBJ: vfncvt.f.xu.w v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x19,0x8a]
vfncvt.f.xu.w v0, v1

# CHECK-ASM-AND-OBJ: vfncvt.f.x.w v0, v1
# CHECK-ASM: encoding: [0x57,0x90,0x19,0x8a]
vfncvt.f.x.w v0, v1

# CHECK-ASM-AND-OBJ: vfncvt.f.f.w v0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x1a,0x8a]
vfncvt.f.f.w v0, v1

# CHECK-ASM-AND-OBJ: vfncvt.rod.f.f.w v0, v1
# CHECK-ASM: encoding: [0x57,0x90,0x1a,0x8a]
vfncvt.rod.f.f.w v0, v1

# CHECK-ASM-AND-OBJ: vredsum.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x02]
vredsum.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vredmaxu.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x1a]
vredmaxu.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vredmax.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x1e]
vredmax.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vredminu.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x12]
vredminu.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vredmin.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x16]
vredmin.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vredand.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x06]
vredand.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vredor.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x0a]
vredor.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vredxor.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x0e]
vredxor.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vwredsumu.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xc2]
vwredsumu.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vwredsum.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xc6]
vwredsum.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vfredosum.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x0e]
vfredosum.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vfredsum.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x06]
vfredsum.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vfredmax.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x1e]
vfredmax.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vfredmin.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x16]
vfredmin.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vfwredosum.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xce]
vfwredosum.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vfwredsum.vs v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xc6]
vfwredsum.vs v0, v1, v0

# CHECK-ASM-AND-OBJ: vmand.mm v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x66]
vmand.mm v0, v1, v0

# CHECK-ASM-AND-OBJ: vmnand.mm v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x76]
vmnand.mm v0, v1, v0

# CHECK-ASM-AND-OBJ: vmandnot.mm v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x62]
vmandnot.mm v0, v1, v0

# CHECK-ASM-AND-OBJ: vmxor.mm v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x6e]
vmxor.mm v0, v1, v0

# CHECK-ASM-AND-OBJ: vmor.mm v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x6a]
vmor.mm v0, v1, v0

# CHECK-ASM-AND-OBJ: vmnor.mm v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x7a]
vmnor.mm v0, v1, v0

# CHECK-ASM-AND-OBJ: vmornot.mm v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x72]
vmornot.mm v0, v1, v0

# CHECK-ASM-AND-OBJ: vmxnor.mm v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x7e]
vmxnor.mm v0, v1, v0

# CHECK-ASM-AND-OBJ: vpopc.m a0, v1
# CHECK-ASM: encoding: [0x57,0x25,0x18,0x42]
vpopc.m a0, v1

# CHECK-ASM-AND-OBJ: vfirst.m a0, v1
# CHECK-ASM: encoding: [0x57,0xa5,0x18,0x42]
vfirst.m a0, v1

# CHECK-ASM-AND-OBJ: vmsbf.m v0, v1
# CHECK-ASM: encoding: [0x57,0xa0,0x10,0x52]
vmsbf.m v0, v1

# CHECK-ASM-AND-OBJ: vmsif.m v0, v1
# CHECK-ASM: encoding: [0x57,0xa0,0x11,0x52]
vmsif.m v0, v1

# CHECK-ASM-AND-OBJ: vmsof.m v0, v1
# CHECK-ASM: encoding: [0x57,0x20,0x11,0x52]
vmsof.m v0, v1

# CHECK-ASM-AND-OBJ: viota.m v0, v1
# CHECK-ASM: encoding: [0x57,0x20,0x18,0x52]
viota.m v0, v1

# CHECK-ASM-AND-OBJ: vid.v v0
# CHECK-ASM: encoding: [0x57,0xa0,0x08,0x52]
vid.v v0

# CHECK-ASM-AND-OBJ: vmv.x.s a0, v1
# CHECK-ASM: encoding: [0x57,0x25,0x10,0x42]
vmv.x.s a0, v1

# CHECK-ASM-AND-OBJ: vmv.s.x v0, a1
# CHECK-ASM: encoding: [0x57,0xe0,0x05,0x42]
vmv.s.x v0, a1

# CHECK-ASM-AND-OBJ: vfmv.f.s ft0, v1
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x42]
vfmv.f.s ft0, v1

# CHECK-ASM-AND-OBJ: vfmv.s.f v0, ft1
# CHECK-ASM: encoding: [0x57,0xd0,0x00,0x42]
vfmv.s.f v0, ft1

# CHECK-ASM-AND-OBJ: vslideup.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x3a]
vslideup.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vslideup.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x3a]
vslideup.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vslidedown.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x3e]
vslidedown.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vslidedown.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x3e]
vslidedown.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vslide1up.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x3a]
vslide1up.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vslide1down.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x3e]
vslide1down.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vrgather.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x32]
vrgather.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vrgather.vx v0, v1, a0
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x32]
vrgather.vx v0, v1, a0

# CHECK-ASM-AND-OBJ: vrgather.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x32]
vrgather.vi v0, v1, 0

# CHECK-ASM-AND-OBJ: vcompress.vm v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x5e]
vcompress.vm v0, v1, v0

# CHECK-ASM-AND-OBJ: vmv1r.v v0, v8
# CHECK-ASM: encoding: [0x57,0x30,0x80,0x9e]
vmv1r.v v0, v8

# CHECK-ASM-AND-OBJ: vmv2r.v v0, v8
# CHECK-ASM: encoding: [0x57,0xb0,0x80,0x9e]
vmv2r.v v0, v8

# CHECK-ASM-AND-OBJ: vmv3r.v v0, v8
# CHECK-ASM: encoding: [0x57,0x30,0x81,0x9e]
vmv3r.v v0, v8

# CHECK-ASM-AND-OBJ: vmv4r.v v0, v8
# CHECK-ASM: encoding: [0x57,0xb0,0x81,0x9e]
vmv4r.v v0, v8

# CHECK-ASM-AND-OBJ: vmv5r.v v0, v8
# CHECK-ASM: encoding: [0x57,0x30,0x82,0x9e]
vmv5r.v v0, v8

# CHECK-ASM-AND-OBJ: vmv6r.v v0, v8
# CHECK-ASM: encoding: [0x57,0xb0,0x82,0x9e]
vmv6r.v v0, v8

# CHECK-ASM-AND-OBJ: vmv7r.v v0, v8
# CHECK-ASM: encoding: [0x57,0x30,0x83,0x9e]
vmv7r.v v0, v8

# CHECK-ASM-AND-OBJ: vmv8r.v v0, v8
# CHECK-ASM: encoding: [0x57,0xb0,0x83,0x9e]
vmv8r.v v0, v8

# CHECK-ASM-AND-OBJ: vdotu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xe2]
vdotu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vdot.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xe6]
vdot.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfdot.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xe6]
vfdot.vv v0, v1, v0

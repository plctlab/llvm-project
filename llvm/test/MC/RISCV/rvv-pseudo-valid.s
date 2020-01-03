# RUN: llvm-mc %s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s


# CHECK-ASM-AND-OBJ: vsetvli a0, a1, e8,m1,d1
# CHECK-ASM: encoding: [0x57,0xf5,0x05,0x00]
vsetvli a0, a1, 0

# CHECK-ASM-AND-OBJ: vsetvli a0, a1, e1024,m8,d8
# CHECK-ASM: encoding: [0x57,0xf5,0xf5,0x7f]
vsetvli a0, a1, 0x7ff

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

# CHECK-ASM-AND-OBJ: vlseg2b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x32]
vlseg2b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x32]
vlseg2h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x32]
vlseg2w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x22]
vlseg2bu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x22]
vlseg2hu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x22]
vlseg2wu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x22]
vlseg2e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg2b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x22]
vsseg2b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg2h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x22]
vsseg2h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg2w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x22]
vsseg2w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg2e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x22]
vsseg2e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x52]
vlseg3b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x52]
vlseg3h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x52]
vlseg3w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x42]
vlseg3bu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x42]
vlseg3hu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x42]
vlseg3wu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x42]
vlseg3e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg3b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x42]
vsseg3b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg3h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x42]
vsseg3h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg3w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x42]
vsseg3w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg3e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x42]
vsseg3e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x72]
vlseg4b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x72]
vlseg4h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x72]
vlseg4w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x62]
vlseg4bu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x62]
vlseg4hu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x62]
vlseg4wu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x62]
vlseg4e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg4b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x62]
vsseg4b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg4h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x62]
vsseg4h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg4w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x62]
vsseg4w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg4e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x62]
vsseg4e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x92]
vlseg5b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x92]
vlseg5h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x92]
vlseg5w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x82]
vlseg5bu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x82]
vlseg5hu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x82]
vlseg5wu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x82]
vlseg5e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg5b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x82]
vsseg5b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg5h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x82]
vsseg5h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg5w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x82]
vsseg5w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg5e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x82]
vsseg5e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xb2]
vlseg6b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xb2]
vlseg6h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xb2]
vlseg6w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xa2]
vlseg6bu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xa2]
vlseg6hu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xa2]
vlseg6wu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xa2]
vlseg6e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg6b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0xa2]
vsseg6b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg6h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0xa2]
vsseg6h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg6w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0xa2]
vsseg6w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg6e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0xa2]
vsseg6e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xd2]
vlseg7b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xd2]
vlseg7h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xd2]
vlseg7w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xc2]
vlseg7bu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xc2]
vlseg7hu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xc2]
vlseg7wu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xc2]
vlseg7e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg7b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0xc2]
vsseg7b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg7h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0xc2]
vsseg7h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg7w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0xc2]
vsseg7w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg7e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0xc2]
vsseg7e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xf2]
vlseg8b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xf2]
vlseg8h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xf2]
vlseg8w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8bu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xe2]
vlseg8bu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8hu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xe2]
vlseg8hu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8wu.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xe2]
vlseg8wu.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xe2]
vlseg8e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg8b.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0x80,0x05,0xe2]
vsseg8b.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg8h.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0xe2]
vsseg8h.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg8w.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0xe2]
vsseg8w.v v0, (a1)

# CHECK-ASM-AND-OBJ: vsseg8e.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0xe2]
vsseg8e.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlsseg2b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x3a]
vlsseg2b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x3a]
vlsseg2h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x3a]
vlsseg2w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x2a]
vlsseg2bu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x2a]
vlsseg2hu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x2a]
vlsseg2wu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg2e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x2a]
vlsseg2e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg2b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x2a]
vssseg2b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg2h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x2a]
vssseg2h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg2w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x2a]
vssseg2w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg2e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x2a]
vssseg2e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x5a]
vlsseg3b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x5a]
vlsseg3h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x5a]
vlsseg3w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x4a]
vlsseg3bu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x4a]
vlsseg3hu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x4a]
vlsseg3wu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg3e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x4a]
vlsseg3e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg3b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x4a]
vssseg3b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg3h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x4a]
vssseg3h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg3w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x4a]
vssseg3w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg3e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x4a]
vssseg3e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x7a]
vlsseg4b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x7a]
vlsseg4h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x7a]
vlsseg4w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x6a]
vlsseg4bu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x6a]
vlsseg4hu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x6a]
vlsseg4wu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg4e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x6a]
vlsseg4e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg4b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x6a]
vssseg4b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg4h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x6a]
vssseg4h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg4w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x6a]
vssseg4w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg4e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x6a]
vssseg4e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x9a]
vlsseg5b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x9a]
vlsseg5h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x9a]
vlsseg5w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x8a]
vlsseg5bu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x8a]
vlsseg5hu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x8a]
vlsseg5wu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg5e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x8a]
vlsseg5e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg5b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x8a]
vssseg5b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg5h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x8a]
vssseg5h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg5w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x8a]
vssseg5w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg5e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x8a]
vssseg5e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xba]
vlsseg6b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xba]
vlsseg6h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xba]
vlsseg6w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xaa]
vlsseg6bu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xaa]
vlsseg6hu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xaa]
vlsseg6wu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg6e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0xaa]
vlsseg6e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg6b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0xaa]
vssseg6b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg6h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0xaa]
vssseg6h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg6w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0xaa]
vssseg6w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg6e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0xaa]
vssseg6e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xda]
vlsseg7b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xda]
vlsseg7h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xda]
vlsseg7w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xca]
vlsseg7bu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xca]
vlsseg7hu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xca]
vlsseg7wu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg7e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0xca]
vlsseg7e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg7b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0xca]
vssseg7b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg7h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0xca]
vssseg7h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg7w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0xca]
vssseg7w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg7e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0xca]
vssseg7e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xfa]
vlsseg8b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xfa]
vlsseg8h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xfa]
vlsseg8w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8bu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xea]
vlsseg8bu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8hu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xea]
vlsseg8hu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8wu.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xea]
vlsseg8wu.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlsseg8e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0xea]
vlsseg8e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg8b.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0xea]
vssseg8b.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg8h.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0xea]
vssseg8h.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg8w.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0xea]
vssseg8w.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vssseg8e.v v0, 0(a1), a2
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0xea]
vssseg8e.v v0, (a1), a2

# CHECK-ASM-AND-OBJ: vlxseg2b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x3e]
vlxseg2b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x3e]
vlxseg2h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x3e]
vlxseg2w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x2e]
vlxseg2bu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x2e]
vlxseg2hu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x2e]
vlxseg2wu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg2e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x2e]
vlxseg2e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg2b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x2e]
vsxseg2b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg2h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x2e]
vsxseg2h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg2w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x2e]
vsxseg2w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg2e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x2e]
vsxseg2e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x5e]
vlxseg3b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x5e]
vlxseg3h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x5e]
vlxseg3w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x4e]
vlxseg3bu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x4e]
vlxseg3hu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x4e]
vlxseg3wu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg3e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x4e]
vlxseg3e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg3b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x4e]
vsxseg3b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg3h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x4e]
vsxseg3h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg3w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x4e]
vsxseg3w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg3e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x4e]
vsxseg3e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x7e]
vlxseg4b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x7e]
vlxseg4h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x7e]
vlxseg4w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x6e]
vlxseg4bu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x6e]
vlxseg4hu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x6e]
vlxseg4wu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg4e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x6e]
vlxseg4e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg4b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x6e]
vsxseg4b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg4h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x6e]
vsxseg4h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg4w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x6e]
vsxseg4w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg4e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x6e]
vsxseg4e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x9e]
vlxseg5b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x9e]
vlxseg5h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x9e]
vlxseg5w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x8e]
vlxseg5bu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x8e]
vlxseg5hu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x8e]
vlxseg5wu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg5e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x8e]
vlxseg5e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg5b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x8e]
vsxseg5b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg5h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x8e]
vsxseg5h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg5w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x8e]
vsxseg5w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg5e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x8e]
vsxseg5e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xbe]
vlxseg6b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xbe]
vlxseg6h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xbe]
vlxseg6w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xae]
vlxseg6bu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xae]
vlxseg6hu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xae]
vlxseg6wu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg6e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0xae]
vlxseg6e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg6b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0xae]
vsxseg6b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg6h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0xae]
vsxseg6h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg6w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0xae]
vsxseg6w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg6e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0xae]
vsxseg6e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xde]
vlxseg7b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xde]
vlxseg7h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xde]
vlxseg7w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xce]
vlxseg7bu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xce]
vlxseg7hu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xce]
vlxseg7wu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg7e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0xce]
vlxseg7e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg7b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0xce]
vsxseg7b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg7h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0xce]
vsxseg7h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg7w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0xce]
vsxseg7w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg7e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0xce]
vsxseg7e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xfe]
vlxseg8b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xfe]
vlxseg8h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xfe]
vlxseg8w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8bu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xee]
vlxseg8bu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8hu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xee]
vlxseg8hu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8wu.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xee]
vlxseg8wu.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlxseg8e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0xee]
vlxseg8e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg8b.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0x80,0x25,0xee]
vsxseg8b.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg8h.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0xee]
vsxseg8h.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg8w.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0xee]
vsxseg8w.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vsxseg8e.v v0, 0(a1), v2
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0xee]
vsxseg8e.v v0, (a1), v2

# CHECK-ASM-AND-OBJ: vlseg2bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x33]
vlseg2bff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x33]
vlseg2hff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x33]
vlseg2wff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x23]
vlseg2buff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x23]
vlseg2huff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x23]
vlseg2wuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg2eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x23]
vlseg2eff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x53]
vlseg3bff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x53]
vlseg3hff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x53]
vlseg3wff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x43]
vlseg3buff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x43]
vlseg3huff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x43]
vlseg3wuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg3eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x43]
vlseg3eff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x73]
vlseg4bff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x73]
vlseg4hff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x73]
vlseg4wff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x63]
vlseg4buff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x63]
vlseg4huff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x63]
vlseg4wuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg4eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x63]
vlseg4eff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x93]
vlseg5bff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x93]
vlseg5hff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x93]
vlseg5wff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x83]
vlseg5buff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x83]
vlseg5huff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x83]
vlseg5wuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg5eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x83]
vlseg5eff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xb3]
vlseg6bff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xb3]
vlseg6hff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xb3]
vlseg6wff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xa3]
vlseg6buff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xa3]
vlseg6huff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xa3]
vlseg6wuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg6eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xa3]
vlseg6eff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xd3]
vlseg7bff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xd3]
vlseg7hff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xd3]
vlseg7wff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xc3]
vlseg7buff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xc3]
vlseg7huff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xc3]
vlseg7wuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg7eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xc3]
vlseg7eff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8bff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xf3]
vlseg8bff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8hff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xf3]
vlseg8hff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8wff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xf3]
vlseg8wff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8buff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xe3]
vlseg8buff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8huff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xe3]
vlseg8huff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8wuff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xe3]
vlseg8wuff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vlseg8eff.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xe3]
vlseg8eff.v v0, (a1)

# CHECK-ASM-AND-OBJ: vwadd.vx v0, v1, zero
# CHECK-ASM: encoding: [0x57,0x60,0x10,0xc6]
vwcvt.x.x.v v0, v1

# CHECK-ASM-AND-OBJ: vwaddu.vx v0, v1, zero
# CHECK-ASM: encoding: [0x57,0x60,0x10,0xc2]
vwcvtu.x.x.v v0, v1

# CHECK-ASM-AND-OBJ: vxor.vi v0, v1, -1
# CHECK-ASM: encoding: [0x57,0xb0,0x1f,0x2e]
vnot.v v0, v1

# CHECK-ASM-AND-OBJ: vmslt.vv v0, v2, v1
# CHECK-ASM: encoding: [0x57,0x80,0x20,0x6e]
vmsgt.vv v0, v1, v2

# CHECK-ASM-AND-OBJ: vmsltu.vv v0, v2, v1
# CHECK-ASM: encoding: [0x57,0x80,0x20,0x6a]
vmsgtu.vv v0, v1, v2

# CHECK-ASM-AND-OBJ: vmsle.vv v0, v2, v1
# CHECK-ASM: encoding: [0x57,0x80,0x20,0x76]
vmsge.vv v0, v1, v2

# CHECK-ASM-AND-OBJ: vmsleu.vv v0, v2, v1
# CHECK-ASM: encoding: [0x57,0x80,0x20,0x72]
vmsgeu.vv v0, v1, v2

# CHECK-ASM-AND-OBJ: vmflt.vv v0, v2, v1
# CHECK-ASM: encoding: [0x57,0x90,0x20,0x6e]
vmfgt.vv v0, v1, v2

# CHECK-ASM-AND-OBJ: vmfle.vv v0, v2, v1
# CHECK-ASM: encoding: [0x57,0x90,0x20,0x66]
vmfge.vv v0, v1, v2

# CHECK-ASM-AND-OBJ: vmand.mm v0, v1, v1
# CHECK-ASM: encoding: [0x57,0xa0,0x10,0x66]
vmcpy.m v0, v1

# CHECK-ASM-AND-OBJ: vmxor.mm v0, v0, v0
# CHECK-ASM: encoding: [0x57,0x20,0x00,0x6e]
vmclr.m v0

# CHECK-ASM-AND-OBJ: vmxnor.mm v0, v0, v0
# CHECK-ASM: encoding: [0x57,0x20,0x00,0x7e]
vmset.m v0

# CHECK-ASM-AND-OBJ: vmnand.mm v0, v1, v1
# CHECK-ASM: encoding: [0x57,0xa0,0x10,0x76]
vmnot.m v0, v1

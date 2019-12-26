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

# CHECK-ASM-AND-OBJ: vlseg2b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x30]
vlseg2b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x30]
vlseg2h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x30]
vlseg2w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2bu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x20]
vlseg2bu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2hu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x20]
vlseg2hu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2wu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x20]
vlseg2wu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x20]
vlseg2e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg2b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x20]
vsseg2b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg2h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x20]
vsseg2h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg2w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x20]
vsseg2w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg2e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x20]
vsseg2e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x50]
vlseg3b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x50]
vlseg3h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x50]
vlseg3w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3bu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x40]
vlseg3bu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3hu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x40]
vlseg3hu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3wu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x40]
vlseg3wu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x40]
vlseg3e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg3b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x40]
vsseg3b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg3h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x40]
vsseg3h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg3w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x40]
vsseg3w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg3e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x40]
vsseg3e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x70]
vlseg4b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x70]
vlseg4h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x70]
vlseg4w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4bu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x60]
vlseg4bu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4hu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x60]
vlseg4hu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4wu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x60]
vlseg4wu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x60]
vlseg4e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg4b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x60]
vsseg4b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg4h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x60]
vsseg4h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg4w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x60]
vsseg4w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg4e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x60]
vsseg4e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x90]
vlseg5b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x90]
vlseg5h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x90]
vlseg5w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5bu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x80]
vlseg5bu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5hu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x80]
vlseg5hu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5wu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x80]
vlseg5wu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x80]
vlseg5e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg5b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x80]
vsseg5b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg5h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x80]
vsseg5h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg5w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x80]
vsseg5w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg5e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x80]
vsseg5e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xb0]
vlseg6b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xb0]
vlseg6h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xb0]
vlseg6w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6bu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xa0]
vlseg6bu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6hu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xa0]
vlseg6hu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6wu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xa0]
vlseg6wu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xa0]
vlseg6e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg6b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x05,0xa0]
vsseg6b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg6h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0xa0]
vsseg6h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg6w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0xa0]
vsseg6w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg6e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0xa0]
vsseg6e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xd0]
vlseg7b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xd0]
vlseg7h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xd0]
vlseg7w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7bu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xc0]
vlseg7bu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7hu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xc0]
vlseg7hu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7wu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xc0]
vlseg7wu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xc0]
vlseg7e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg7b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x05,0xc0]
vsseg7b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg7h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0xc0]
vsseg7h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg7w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0xc0]
vsseg7w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg7e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0xc0]
vsseg7e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xf0]
vlseg8b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xf0]
vlseg8h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xf0]
vlseg8w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8bu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xe0]
vlseg8bu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8hu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xe0]
vlseg8hu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8wu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xe0]
vlseg8wu.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xe0]
vlseg8e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg8b.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x05,0xe0]
vsseg8b.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg8h.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0xe0]
vsseg8h.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg8w.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0xe0]
vsseg8w.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vsseg8e.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0xe0]
vsseg8e.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlsseg2b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x38]
vlsseg2b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg2h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x38]
vlsseg2h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg2w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x38]
vlsseg2w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg2bu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x28]
vlsseg2bu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg2hu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x28]
vlsseg2hu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg2wu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x28]
vlsseg2wu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg2e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x28]
vlsseg2e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg2b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x28]
vssseg2b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg2h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x28]
vssseg2h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg2w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x28]
vssseg2w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg2e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x28]
vssseg2e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg3b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x58]
vlsseg3b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg3h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x58]
vlsseg3h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg3w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x58]
vlsseg3w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg3bu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x48]
vlsseg3bu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg3hu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x48]
vlsseg3hu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg3wu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x48]
vlsseg3wu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg3e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x48]
vlsseg3e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg3b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x48]
vssseg3b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg3h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x48]
vssseg3h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg3w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x48]
vssseg3w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg3e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x48]
vssseg3e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg4b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x78]
vlsseg4b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg4h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x78]
vlsseg4h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg4w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x78]
vlsseg4w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg4bu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x68]
vlsseg4bu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg4hu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x68]
vlsseg4hu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg4wu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x68]
vlsseg4wu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg4e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x68]
vlsseg4e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg4b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x68]
vssseg4b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg4h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x68]
vssseg4h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg4w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x68]
vssseg4w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg4e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x68]
vssseg4e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg5b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x98]
vlsseg5b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg5h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x98]
vlsseg5h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg5w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x98]
vlsseg5w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg5bu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x88]
vlsseg5bu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg5hu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x88]
vlsseg5hu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg5wu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x88]
vlsseg5wu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg5e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x88]
vlsseg5e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg5b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x88]
vssseg5b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg5h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x88]
vssseg5h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg5w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x88]
vssseg5w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg5e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x88]
vssseg5e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg6b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xb8]
vlsseg6b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg6h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xb8]
vlsseg6h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg6w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xb8]
vlsseg6w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg6bu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xa8]
vlsseg6bu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg6hu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xa8]
vlsseg6hu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg6wu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xa8]
vlsseg6wu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg6e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0xa8]
vlsseg6e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg6b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0xa8]
vssseg6b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg6h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0xa8]
vssseg6h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg6w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0xa8]
vssseg6w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg6e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0xa8]
vssseg6e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg7b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xd8]
vlsseg7b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg7h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xd8]
vlsseg7h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg7w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xd8]
vlsseg7w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg7bu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xc8]
vlsseg7bu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg7hu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xc8]
vlsseg7hu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg7wu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xc8]
vlsseg7wu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg7e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0xc8]
vlsseg7e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg7b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0xc8]
vssseg7b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg7h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0xc8]
vssseg7h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg7w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0xc8]
vssseg7w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg7e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0xc8]
vssseg7e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg8b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xf8]
vlsseg8b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg8h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xf8]
vlsseg8h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg8w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xf8]
vlsseg8w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg8bu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0xe8]
vlsseg8bu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg8hu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0xe8]
vlsseg8hu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg8wu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0xe8]
vlsseg8wu.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsseg8e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0xe8]
vlsseg8e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg8b.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0xe8]
vssseg8b.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg8h.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0xe8]
vssseg8h.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg8w.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0xe8]
vssseg8w.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssseg8e.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0xe8]
vssseg8e.v v0, (a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg2b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x3c]
vlxseg2b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg2h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x3c]
vlxseg2h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg2w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x3c]
vlxseg2w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg2bu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x2c]
vlxseg2bu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg2hu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x2c]
vlxseg2hu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg2wu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x2c]
vlxseg2wu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg2e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x2c]
vlxseg2e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg2b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x2c]
vsxseg2b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg2h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x2c]
vsxseg2h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg2w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x2c]
vsxseg2w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg2e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x2c]
vsxseg2e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg3b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x5c]
vlxseg3b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg3h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x5c]
vlxseg3h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg3w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x5c]
vlxseg3w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg3bu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x4c]
vlxseg3bu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg3hu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x4c]
vlxseg3hu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg3wu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x4c]
vlxseg3wu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg3e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x4c]
vlxseg3e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg3b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x4c]
vsxseg3b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg3h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x4c]
vsxseg3h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg3w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x4c]
vsxseg3w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg3e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x4c]
vsxseg3e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg4b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x7c]
vlxseg4b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg4h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x7c]
vlxseg4h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg4w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x7c]
vlxseg4w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg4bu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x6c]
vlxseg4bu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg4hu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x6c]
vlxseg4hu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg4wu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x6c]
vlxseg4wu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg4e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x6c]
vlxseg4e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg4b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x6c]
vsxseg4b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg4h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x6c]
vsxseg4h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg4w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x6c]
vsxseg4w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg4e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x6c]
vsxseg4e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg5b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x9c]
vlxseg5b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg5h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x9c]
vlxseg5h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg5w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x9c]
vlxseg5w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg5bu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x8c]
vlxseg5bu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg5hu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x8c]
vlxseg5hu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg5wu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x8c]
vlxseg5wu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg5e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x8c]
vlxseg5e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg5b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x8c]
vsxseg5b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg5h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x8c]
vsxseg5h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg5w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x8c]
vsxseg5w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg5e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x8c]
vsxseg5e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg6b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xbc]
vlxseg6b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg6h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xbc]
vlxseg6h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg6w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xbc]
vlxseg6w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg6bu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xac]
vlxseg6bu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg6hu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xac]
vlxseg6hu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg6wu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xac]
vlxseg6wu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg6e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0xac]
vlxseg6e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg6b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0xac]
vsxseg6b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg6h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0xac]
vsxseg6h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg6w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0xac]
vsxseg6w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg6e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0xac]
vsxseg6e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg7b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xdc]
vlxseg7b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg7h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xdc]
vlxseg7h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg7w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xdc]
vlxseg7w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg7bu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xcc]
vlxseg7bu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg7hu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xcc]
vlxseg7hu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg7wu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xcc]
vlxseg7wu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg7e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0xcc]
vlxseg7e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg7b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0xcc]
vsxseg7b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg7h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0xcc]
vsxseg7h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg7w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0xcc]
vsxseg7w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg7e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0xcc]
vsxseg7e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg8b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xfc]
vlxseg8b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg8h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xfc]
vlxseg8h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg8w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xfc]
vlxseg8w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg8bu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0xec]
vlxseg8bu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg8hu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0xec]
vlxseg8hu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg8wu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0xec]
vlxseg8wu.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxseg8e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0xec]
vlxseg8e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg8b.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0xec]
vsxseg8b.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg8h.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0xec]
vsxseg8h.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg8w.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0xec]
vsxseg8w.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxseg8e.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0xec]
vsxseg8e.v v0, (a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlseg2bff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x31]
vlseg2bff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2hff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x31]
vlseg2hff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2wff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x31]
vlseg2wff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2buff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x21]
vlseg2buff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2huff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x21]
vlseg2huff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2wuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x21]
vlseg2wuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg2eff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x21]
vlseg2eff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3bff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x51]
vlseg3bff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3hff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x51]
vlseg3hff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3wff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x51]
vlseg3wff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3buff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x41]
vlseg3buff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3huff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x41]
vlseg3huff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3wuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x41]
vlseg3wuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg3eff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x41]
vlseg3eff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4bff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x71]
vlseg4bff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4hff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x71]
vlseg4hff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4wff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x71]
vlseg4wff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4buff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x61]
vlseg4buff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4huff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x61]
vlseg4huff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4wuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x61]
vlseg4wuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg4eff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x61]
vlseg4eff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5bff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x91]
vlseg5bff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5hff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x91]
vlseg5hff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5wff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x91]
vlseg5wff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5buff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x81]
vlseg5buff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5huff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x81]
vlseg5huff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5wuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x81]
vlseg5wuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg5eff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x81]
vlseg5eff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6bff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xb1]
vlseg6bff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6hff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xb1]
vlseg6hff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6wff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xb1]
vlseg6wff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6buff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xa1]
vlseg6buff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6huff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xa1]
vlseg6huff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6wuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xa1]
vlseg6wuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg6eff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xa1]
vlseg6eff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7bff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xd1]
vlseg7bff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7hff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xd1]
vlseg7hff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7wff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xd1]
vlseg7wff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7buff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xc1]
vlseg7buff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7huff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xc1]
vlseg7huff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7wuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xc1]
vlseg7wuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg7eff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xc1]
vlseg7eff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8bff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xf1]
vlseg8bff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8hff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xf1]
vlseg8hff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8wff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xf1]
vlseg8wff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8buff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0xe1]
vlseg8buff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8huff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0xe1]
vlseg8huff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8wuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0xe1]
vlseg8wuff.v v0, (a1), v0.t

# CHECK-ASM-AND-OBJ: vlseg8eff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0xe1]
vlseg8eff.v v0, (a1), v0.t

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

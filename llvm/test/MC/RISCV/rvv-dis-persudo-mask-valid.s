# RUN: llvm-mc -disassemble --triple riscv64 -mattr m,+a,+f,+d,+c,+v < %s | \
# RUN:         FileCheck %s


# CHECK: vlb.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x10]
vlb.v v0, (a1), v0.t
 
# CHECK: vlh.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x10]
vlh.v v0, (a1), v0.t

# CHECK: vlw.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x10]
vlw.v v0, (a1), v0.t

# CHECK: vlbu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x00]
vlbu.v v0, (a1), v0.t

# CHECK: vlhu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x00]
vlhu.v v0, (a1), v0.t

# CHECK: vlwu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x00]
vlwu.v v0, (a1), v0.t

# CHECK: vle.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x00]
vle.v v0, (a1), v0.t

# CHECK: vsb.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x00]
vsb.v v0, (a1), v0.t

# CHECK: vsh.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x00]
vsh.v v0, (a1), v0.t

# CHECK: vsw.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x00]
vsw.v v0, (a1), v0.t

# CHECK: vse.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x00]
vse.v v0, (a1), v0.t

# CHECK: vlsb.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x18]
vlsb.v v0, (a1), a2, v0.t
 
# CHECK: vlsh.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x18]
vlsh.v v0, (a1), a2, v0.t

# CHECK: vlsw.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x18]
vlsw.v v0, (a1), a2, v0.t

# CHECK: vlsbu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x08]
vlsbu.v v0, (a1), a2, v0.t

# CHECK: vlshu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x08]
vlshu.v v0, (a1), a2, v0.t

# CHECK: vlswu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x08]
vlswu.v v0, (a1), a2, v0.t

# CHECK: vlse.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x08]
vlse.v v0, (a1), a2, v0.t

# CHECK: vssb.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x08]
vssb.v v0, (a1), a2, v0.t

# CHECK: vssh.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x08]
vssh.v v0, (a1), a2, v0.t

# CHECK: vssw.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x08]
vssw.v v0, (a1), a2, v0.t

# CHECK: vsse.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x08]
vsse.v v0, (a1), a2, v0.t

# CHECK: vlxb.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x1c]
vlxb.v v0, (a1), v2, v0.t
 
# CHECK: vlxh.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x1c]
vlxh.v v0, (a1), v2, v0.t

# CHECK: vlxw.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x1c]
vlxw.v v0, (a1), v2, v0.t

# CHECK: vlxbu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x0c]
vlxbu.v v0, (a1), v2, v0.t

# CHECK: vlxhu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x0c]
vlxhu.v v0, (a1), v2, v0.t

# CHECK: vlxwu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x0c]
vlxwu.v v0, (a1), v2, v0.t

# CHECK: vlxe.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x0c]
vlxe.v v0, (a1), v2, v0.t

# CHECK: vsxb.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x0c]
vsxb.v v0, (a1), v2, v0.t

# CHECK: vsxh.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x0c]
vsxh.v v0, (a1), v2, v0.t

# CHECK: vsxw.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x0c]
vsxw.v v0, (a1), v2, v0.t

# CHECK: vsxe.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x0c]
vsxe.v v0, (a1), v2, v0.t

# CHECK: vsuxb.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x1c]
vsuxb.v v0, (a1), v2, v0.t

# CHECK: vsuxh.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x1c]
vsuxh.v v0, (a1), v2, v0.t

# CHECK: vsuxw.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x1c]
vsuxw.v v0, (a1), v2, v0.t

# CHECK: vsuxe.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x1c]
vsuxe.v v0, (a1), v2, v0.t

# CHECK: vlbff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x11]
vlbff.v v0, (a1), v0.t
 
# CHECK: vlhff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x11]
vlhff.v v0, (a1), v0.t

# CHECK: vlwff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x11]
vlwff.v v0, (a1), v0.t

# CHECK: vlbuff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x01]
vlbuff.v v0, (a1), v0.t

# CHECK: vlhuff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x01]
vlhuff.v v0, (a1), v0.t

# CHECK: vlwuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x01]
vlwuff.v v0, (a1), v0.t

# CHECK: vleff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x01]
vleff.v v0, (a1), v0.t

# CHECK: vlseg2b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x30]
vlseg2b.v v0, (a1), v0.t

# CHECK: vlseg2h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x30]
vlseg2h.v v0, (a1), v0.t

# CHECK: vlseg2w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x30]
vlseg2w.v v0, (a1), v0.t

# CHECK: vlseg2bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x20]
vlseg2bu.v v0, (a1), v0.t

# CHECK: vlseg2hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x20]
vlseg2hu.v v0, (a1), v0.t

# CHECK: vlseg2wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x20]
vlseg2wu.v v0, (a1), v0.t

# CHECK: vlseg2e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x20]
vlseg2e.v v0, (a1), v0.t

# CHECK: vsseg2b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x20]
vsseg2b.v v0, (a1), v0.t

# CHECK: vsseg2h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x20]
vsseg2h.v v0, (a1), v0.t

# CHECK: vsseg2w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x20]
vsseg2w.v v0, (a1), v0.t

# CHECK: vsseg2e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x20]
vsseg2e.v v0, (a1), v0.t

# CHECK: vlseg3b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x50]
vlseg3b.v v0, (a1), v0.t

# CHECK: vlseg3h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x50]
vlseg3h.v v0, (a1), v0.t

# CHECK: vlseg3w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x50]
vlseg3w.v v0, (a1), v0.t

# CHECK: vlseg3bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x40]
vlseg3bu.v v0, (a1), v0.t

# CHECK: vlseg3hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x40]
vlseg3hu.v v0, (a1), v0.t

# CHECK: vlseg3wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x40]
vlseg3wu.v v0, (a1), v0.t

# CHECK: vlseg3e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x40]
vlseg3e.v v0, (a1), v0.t

# CHECK: vsseg3b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x40]
vsseg3b.v v0, (a1), v0.t

# CHECK: vsseg3h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x40]
vsseg3h.v v0, (a1), v0.t

# CHECK: vsseg3w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x40]
vsseg3w.v v0, (a1), v0.t

# CHECK: vsseg3e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x40]
vsseg3e.v v0, (a1), v0.t

# CHECK: vlseg4b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x70]
vlseg4b.v v0, (a1), v0.t

# CHECK: vlseg4h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x70]
vlseg4h.v v0, (a1), v0.t

# CHECK: vlseg4w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x70]
vlseg4w.v v0, (a1), v0.t

# CHECK: vlseg4bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x60]
vlseg4bu.v v0, (a1), v0.t

# CHECK: vlseg4hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x60]
vlseg4hu.v v0, (a1), v0.t

# CHECK: vlseg4wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x60]
vlseg4wu.v v0, (a1), v0.t

# CHECK: vlseg4e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x60]
vlseg4e.v v0, (a1), v0.t

# CHECK: vsseg4b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x60]
vsseg4b.v v0, (a1), v0.t

# CHECK: vsseg4h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x60]
vsseg4h.v v0, (a1), v0.t

# CHECK: vsseg4w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x60]
vsseg4w.v v0, (a1), v0.t

# CHECK: vsseg4e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x60]
vsseg4e.v v0, (a1), v0.t

# CHECK: vlseg5b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x90]
vlseg5b.v v0, (a1), v0.t

# CHECK: vlseg5h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x90]
vlseg5h.v v0, (a1), v0.t

# CHECK: vlseg5w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x90]
vlseg5w.v v0, (a1), v0.t

# CHECK: vlseg5bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x80]
vlseg5bu.v v0, (a1), v0.t

# CHECK: vlseg5hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x80]
vlseg5hu.v v0, (a1), v0.t

# CHECK: vlseg5wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x80]
vlseg5wu.v v0, (a1), v0.t

# CHECK: vlseg5e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x80]
vlseg5e.v v0, (a1), v0.t

# CHECK: vsseg5b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x80]
vsseg5b.v v0, (a1), v0.t

# CHECK: vsseg5h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x80]
vsseg5h.v v0, (a1), v0.t

# CHECK: vsseg5w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x80]
vsseg5w.v v0, (a1), v0.t

# CHECK: vsseg5e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x80]
vsseg5e.v v0, (a1), v0.t

# CHECK: vlseg6b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xb0]
vlseg6b.v v0, (a1), v0.t

# CHECK: vlseg6h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xb0]
vlseg6h.v v0, (a1), v0.t

# CHECK: vlseg6w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xb0]
vlseg6w.v v0, (a1), v0.t

# CHECK: vlseg6bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xa0]
vlseg6bu.v v0, (a1), v0.t

# CHECK: vlseg6hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xa0]
vlseg6hu.v v0, (a1), v0.t

# CHECK: vlseg6wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xa0]
vlseg6wu.v v0, (a1), v0.t

# CHECK: vlseg6e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xa0]
vlseg6e.v v0, (a1), v0.t

# CHECK: vsseg6b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0xa0]
vsseg6b.v v0, (a1), v0.t

# CHECK: vsseg6h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0xa0]
vsseg6h.v v0, (a1), v0.t

# CHECK: vsseg6w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0xa0]
vsseg6w.v v0, (a1), v0.t

# CHECK: vsseg6e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0xa0]
vsseg6e.v v0, (a1), v0.t

# CHECK: vlseg7b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xd0]
vlseg7b.v v0, (a1), v0.t

# CHECK: vlseg7h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xd0]
vlseg7h.v v0, (a1), v0.t

# CHECK: vlseg7w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xd0]
vlseg7w.v v0, (a1), v0.t

# CHECK: vlseg7bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xc0]
vlseg7bu.v v0, (a1), v0.t

# CHECK: vlseg7hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xc0]
vlseg7hu.v v0, (a1), v0.t

# CHECK: vlseg7wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xc0]
vlseg7wu.v v0, (a1), v0.t

# CHECK: vlseg7e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xc0]
vlseg7e.v v0, (a1), v0.t

# CHECK: vsseg7b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0xc0]
vsseg7b.v v0, (a1), v0.t

# CHECK: vsseg7h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0xc0]
vsseg7h.v v0, (a1), v0.t

# CHECK: vsseg7w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0xc0]
vsseg7w.v v0, (a1), v0.t

# CHECK: vsseg7e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0xc0]
vsseg7e.v v0, (a1), v0.t

# CHECK: vlseg8b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xf0]
vlseg8b.v v0, (a1), v0.t

# CHECK: vlseg8h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xf0]
vlseg8h.v v0, (a1), v0.t

# CHECK: vlseg8w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xf0]
vlseg8w.v v0, (a1), v0.t

# CHECK: vlseg8bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xe0]
vlseg8bu.v v0, (a1), v0.t

# CHECK: vlseg8hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xe0]
vlseg8hu.v v0, (a1), v0.t

# CHECK: vlseg8wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xe0]
vlseg8wu.v v0, (a1), v0.t

# CHECK: vlseg8e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xe0]
vlseg8e.v v0, (a1), v0.t

# CHECK: vsseg8b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0xe0]
vsseg8b.v v0, (a1), v0.t

# CHECK: vsseg8h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0xe0]
vsseg8h.v v0, (a1), v0.t

# CHECK: vsseg8w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0xe0]
vsseg8w.v v0, (a1), v0.t

# CHECK: vsseg8e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0xe0]
vsseg8e.v v0, (a1), v0.t

# CHECK: vlsseg2b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x38]
vlsseg2b.v v0, (a1), a2, v0.t

# CHECK: vlsseg2h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x38]
vlsseg2h.v v0, (a1), a2, v0.t

# CHECK: vlsseg2w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x38]
vlsseg2w.v v0, (a1), a2, v0.t

# CHECK: vlsseg2bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x28]
vlsseg2bu.v v0, (a1), a2, v0.t

# CHECK: vlsseg2hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x28]
vlsseg2hu.v v0, (a1), a2, v0.t

# CHECK: vlsseg2wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x28]
vlsseg2wu.v v0, (a1), a2, v0.t

# CHECK: vlsseg2e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x28]
vlsseg2e.v v0, (a1), a2, v0.t

# CHECK: vssseg2b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x28]
vssseg2b.v v0, (a1), a2, v0.t

# CHECK: vssseg2h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x28]
vssseg2h.v v0, (a1), a2, v0.t

# CHECK: vssseg2w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x28]
vssseg2w.v v0, (a1), a2, v0.t

# CHECK: vssseg2e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x28]
vssseg2e.v v0, (a1), a2, v0.t

# CHECK: vlsseg3b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x58]
vlsseg3b.v v0, (a1), a2, v0.t

# CHECK: vlsseg3h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x58]
vlsseg3h.v v0, (a1), a2, v0.t

# CHECK: vlsseg3w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x58]
vlsseg3w.v v0, (a1), a2, v0.t

# CHECK: vlsseg3bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x48]
vlsseg3bu.v v0, (a1), a2, v0.t

# CHECK: vlsseg3hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x48]
vlsseg3hu.v v0, (a1), a2, v0.t

# CHECK: vlsseg3wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x48]
vlsseg3wu.v v0, (a1), a2, v0.t

# CHECK: vlsseg3e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x48]
vlsseg3e.v v0, (a1), a2, v0.t

# CHECK: vssseg3b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x48]
vssseg3b.v v0, (a1), a2, v0.t

# CHECK: vssseg3h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x48]
vssseg3h.v v0, (a1), a2, v0.t

# CHECK: vssseg3w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x48]
vssseg3w.v v0, (a1), a2, v0.t

# CHECK: vssseg3e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x48]
vssseg3e.v v0, (a1), a2, v0.t

# CHECK: vlsseg4b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x78]
vlsseg4b.v v0, (a1), a2, v0.t

# CHECK: vlsseg4h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x78]
vlsseg4h.v v0, (a1), a2, v0.t

# CHECK: vlsseg4w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x78]
vlsseg4w.v v0, (a1), a2, v0.t

# CHECK: vlsseg4bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x68]
vlsseg4bu.v v0, (a1), a2, v0.t

# CHECK: vlsseg4hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x68]
vlsseg4hu.v v0, (a1), a2, v0.t

# CHECK: vlsseg4wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x68]
vlsseg4wu.v v0, (a1), a2, v0.t

# CHECK: vlsseg4e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x68]
vlsseg4e.v v0, (a1), a2, v0.t

# CHECK: vssseg4b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x68]
vssseg4b.v v0, (a1), a2, v0.t

# CHECK: vssseg4h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x68]
vssseg4h.v v0, (a1), a2, v0.t

# CHECK: vssseg4w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x68]
vssseg4w.v v0, (a1), a2, v0.t

# CHECK: vssseg4e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x68]
vssseg4e.v v0, (a1), a2, v0.t

# CHECK: vlsseg5b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x98]
vlsseg5b.v v0, (a1), a2, v0.t

# CHECK: vlsseg5h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x98]
vlsseg5h.v v0, (a1), a2, v0.t

# CHECK: vlsseg5w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x98]
vlsseg5w.v v0, (a1), a2, v0.t

# CHECK: vlsseg5bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x88]
vlsseg5bu.v v0, (a1), a2, v0.t

# CHECK: vlsseg5hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x88]
vlsseg5hu.v v0, (a1), a2, v0.t

# CHECK: vlsseg5wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x88]
vlsseg5wu.v v0, (a1), a2, v0.t

# CHECK: vlsseg5e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x88]
vlsseg5e.v v0, (a1), a2, v0.t

# CHECK: vssseg5b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x88]
vssseg5b.v v0, (a1), a2, v0.t

# CHECK: vssseg5h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x88]
vssseg5h.v v0, (a1), a2, v0.t

# CHECK: vssseg5w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x88]
vssseg5w.v v0, (a1), a2, v0.t

# CHECK: vssseg5e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x88]
vssseg5e.v v0, (a1), a2, v0.t

# CHECK: vlsseg6b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xb8]
vlsseg6b.v v0, (a1), a2, v0.t

# CHECK: vlsseg6h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xb8]
vlsseg6h.v v0, (a1), a2, v0.t

# CHECK: vlsseg6w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xb8]
vlsseg6w.v v0, (a1), a2, v0.t

# CHECK: vlsseg6bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xa8]
vlsseg6bu.v v0, (a1), a2, v0.t

# CHECK: vlsseg6hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xa8]
vlsseg6hu.v v0, (a1), a2, v0.t

# CHECK: vlsseg6wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xa8]
vlsseg6wu.v v0, (a1), a2, v0.t

# CHECK: vlsseg6e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0xa8]
vlsseg6e.v v0, (a1), a2, v0.t

# CHECK: vssseg6b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0xa8]
vssseg6b.v v0, (a1), a2, v0.t

# CHECK: vssseg6h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0xa8]
vssseg6h.v v0, (a1), a2, v0.t

# CHECK: vssseg6w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0xa8]
vssseg6w.v v0, (a1), a2, v0.t

# CHECK: vssseg6e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0xa8]
vssseg6e.v v0, (a1), a2, v0.t

# CHECK: vlsseg7b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xd8]
vlsseg7b.v v0, (a1), a2, v0.t

# CHECK: vlsseg7h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xd8]
vlsseg7h.v v0, (a1), a2, v0.t

# CHECK: vlsseg7w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xd8]
vlsseg7w.v v0, (a1), a2, v0.t

# CHECK: vlsseg7bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xc8]
vlsseg7bu.v v0, (a1), a2, v0.t

# CHECK: vlsseg7hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xc8]
vlsseg7hu.v v0, (a1), a2, v0.t

# CHECK: vlsseg7wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xc8]
vlsseg7wu.v v0, (a1), a2, v0.t

# CHECK: vlsseg7e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0xc8]
vlsseg7e.v v0, (a1), a2, v0.t

# CHECK: vssseg7b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0xc8]
vssseg7b.v v0, (a1), a2, v0.t

# CHECK: vssseg7h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0xc8]
vssseg7h.v v0, (a1), a2, v0.t

# CHECK: vssseg7w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0xc8]
vssseg7w.v v0, (a1), a2, v0.t

# CHECK: vssseg7e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0xc8]
vssseg7e.v v0, (a1), a2, v0.t

# CHECK: vlsseg8b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xf8]
vlsseg8b.v v0, (a1), a2, v0.t

# CHECK: vlsseg8h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xf8]
vlsseg8h.v v0, (a1), a2, v0.t

# CHECK: vlsseg8w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xf8]
vlsseg8w.v v0, (a1), a2, v0.t

# CHECK: vlsseg8bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xe8]
vlsseg8bu.v v0, (a1), a2, v0.t

# CHECK: vlsseg8hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xe8]
vlsseg8hu.v v0, (a1), a2, v0.t

# CHECK: vlsseg8wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xe8]
vlsseg8wu.v v0, (a1), a2, v0.t

# CHECK: vlsseg8e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0xe8]
vlsseg8e.v v0, (a1), a2, v0.t

# CHECK: vssseg8b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0xe8]
vssseg8b.v v0, (a1), a2, v0.t

# CHECK: vssseg8h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0xe8]
vssseg8h.v v0, (a1), a2, v0.t

# CHECK: vssseg8w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0xe8]
vssseg8w.v v0, (a1), a2, v0.t

# CHECK: vssseg8e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0xe8]
vssseg8e.v v0, (a1), a2, v0.t

# CHECK: vlxseg2b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x3c]
vlxseg2b.v v0, (a1), v2, v0.t

# CHECK: vlxseg2h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x3c]
vlxseg2h.v v0, (a1), v2, v0.t

# CHECK: vlxseg2w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x3c]
vlxseg2w.v v0, (a1), v2, v0.t

# CHECK: vlxseg2bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x2c]
vlxseg2bu.v v0, (a1), v2, v0.t

# CHECK: vlxseg2hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x2c]
vlxseg2hu.v v0, (a1), v2, v0.t

# CHECK: vlxseg2wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x2c]
vlxseg2wu.v v0, (a1), v2, v0.t

# CHECK: vlxseg2e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x2c]
vlxseg2e.v v0, (a1), v2, v0.t

# CHECK: vsxseg2b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x2c]
vsxseg2b.v v0, (a1), v2, v0.t

# CHECK: vsxseg2h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x2c]
vsxseg2h.v v0, (a1), v2, v0.t

# CHECK: vsxseg2w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x2c]
vsxseg2w.v v0, (a1), v2, v0.t

# CHECK: vsxseg2e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x2c]
vsxseg2e.v v0, (a1), v2, v0.t

# CHECK: vlxseg3b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x5c]
vlxseg3b.v v0, (a1), v2, v0.t

# CHECK: vlxseg3h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x5c]
vlxseg3h.v v0, (a1), v2, v0.t

# CHECK: vlxseg3w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x5c]
vlxseg3w.v v0, (a1), v2, v0.t

# CHECK: vlxseg3bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x4c]
vlxseg3bu.v v0, (a1), v2, v0.t

# CHECK: vlxseg3hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x4c]
vlxseg3hu.v v0, (a1), v2, v0.t

# CHECK: vlxseg3wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x4c]
vlxseg3wu.v v0, (a1), v2, v0.t

# CHECK: vlxseg3e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x4c]
vlxseg3e.v v0, (a1), v2, v0.t

# CHECK: vsxseg3b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x4c]
vsxseg3b.v v0, (a1), v2, v0.t

# CHECK: vsxseg3h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x4c]
vsxseg3h.v v0, (a1), v2, v0.t

# CHECK: vsxseg3w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x4c]
vsxseg3w.v v0, (a1), v2, v0.t

# CHECK: vsxseg3e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x4c]
vsxseg3e.v v0, (a1), v2, v0.t

# CHECK: vlxseg4b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x7c]
vlxseg4b.v v0, (a1), v2, v0.t

# CHECK: vlxseg4h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x7c]
vlxseg4h.v v0, (a1), v2, v0.t

# CHECK: vlxseg4w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x7c]
vlxseg4w.v v0, (a1), v2, v0.t

# CHECK: vlxseg4bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x6c]
vlxseg4bu.v v0, (a1), v2, v0.t

# CHECK: vlxseg4hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x6c]
vlxseg4hu.v v0, (a1), v2, v0.t

# CHECK: vlxseg4wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x6c]
vlxseg4wu.v v0, (a1), v2, v0.t

# CHECK: vlxseg4e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x6c]
vlxseg4e.v v0, (a1), v2, v0.t

# CHECK: vsxseg4b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x6c]
vsxseg4b.v v0, (a1), v2, v0.t

# CHECK: vsxseg4h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x6c]
vsxseg4h.v v0, (a1), v2, v0.t

# CHECK: vsxseg4w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x6c]
vsxseg4w.v v0, (a1), v2, v0.t

# CHECK: vsxseg4e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x6c]
vsxseg4e.v v0, (a1), v2, v0.t

# CHECK: vlxseg5b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x9c]
vlxseg5b.v v0, (a1), v2, v0.t

# CHECK: vlxseg5h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x9c]
vlxseg5h.v v0, (a1), v2, v0.t

# CHECK: vlxseg5w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x9c]
vlxseg5w.v v0, (a1), v2, v0.t

# CHECK: vlxseg5bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x8c]
vlxseg5bu.v v0, (a1), v2, v0.t

# CHECK: vlxseg5hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x8c]
vlxseg5hu.v v0, (a1), v2, v0.t

# CHECK: vlxseg5wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x8c]
vlxseg5wu.v v0, (a1), v2, v0.t

# CHECK: vlxseg5e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x8c]
vlxseg5e.v v0, (a1), v2, v0.t

# CHECK: vsxseg5b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x8c]
vsxseg5b.v v0, (a1), v2, v0.t

# CHECK: vsxseg5h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x8c]
vsxseg5h.v v0, (a1), v2, v0.t

# CHECK: vsxseg5w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x8c]
vsxseg5w.v v0, (a1), v2, v0.t

# CHECK: vsxseg5e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x8c]
vsxseg5e.v v0, (a1), v2, v0.t

# CHECK: vlxseg6b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xbc]
vlxseg6b.v v0, (a1), v2, v0.t

# CHECK: vlxseg6h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xbc]
vlxseg6h.v v0, (a1), v2, v0.t

# CHECK: vlxseg6w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xbc]
vlxseg6w.v v0, (a1), v2, v0.t

# CHECK: vlxseg6bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xac]
vlxseg6bu.v v0, (a1), v2, v0.t

# CHECK: vlxseg6hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xac]
vlxseg6hu.v v0, (a1), v2, v0.t

# CHECK: vlxseg6wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xac]
vlxseg6wu.v v0, (a1), v2, v0.t

# CHECK: vlxseg6e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0xac]
vlxseg6e.v v0, (a1), v2, v0.t

# CHECK: vsxseg6b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0xac]
vsxseg6b.v v0, (a1), v2, v0.t

# CHECK: vsxseg6h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0xac]
vsxseg6h.v v0, (a1), v2, v0.t

# CHECK: vsxseg6w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0xac]
vsxseg6w.v v0, (a1), v2, v0.t

# CHECK: vsxseg6e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0xac]
vsxseg6e.v v0, (a1), v2, v0.t

# CHECK: vlxseg7b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xdc]
vlxseg7b.v v0, (a1), v2, v0.t

# CHECK: vlxseg7h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xdc]
vlxseg7h.v v0, (a1), v2, v0.t

# CHECK: vlxseg7w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xdc]
vlxseg7w.v v0, (a1), v2, v0.t

# CHECK: vlxseg7bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xcc]
vlxseg7bu.v v0, (a1), v2, v0.t

# CHECK: vlxseg7hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xcc]
vlxseg7hu.v v0, (a1), v2, v0.t

# CHECK: vlxseg7wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xcc]
vlxseg7wu.v v0, (a1), v2, v0.t

# CHECK: vlxseg7e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0xcc]
vlxseg7e.v v0, (a1), v2, v0.t

# CHECK: vsxseg7b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0xcc]
vsxseg7b.v v0, (a1), v2, v0.t

# CHECK: vsxseg7h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0xcc]
vsxseg7h.v v0, (a1), v2, v0.t

# CHECK: vsxseg7w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0xcc]
vsxseg7w.v v0, (a1), v2, v0.t

# CHECK: vsxseg7e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0xcc]
vsxseg7e.v v0, (a1), v2, v0.t

# CHECK: vlxseg8b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xfc]
vlxseg8b.v v0, (a1), v2, v0.t

# CHECK: vlxseg8h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xfc]
vlxseg8h.v v0, (a1), v2, v0.t

# CHECK: vlxseg8w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xfc]
vlxseg8w.v v0, (a1), v2, v0.t

# CHECK: vlxseg8bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xec]
vlxseg8bu.v v0, (a1), v2, v0.t

# CHECK: vlxseg8hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xec]
vlxseg8hu.v v0, (a1), v2, v0.t

# CHECK: vlxseg8wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xec]
vlxseg8wu.v v0, (a1), v2, v0.t

# CHECK: vlxseg8e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0xec]
vlxseg8e.v v0, (a1), v2, v0.t

# CHECK: vsxseg8b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0xec]
vsxseg8b.v v0, (a1), v2, v0.t

# CHECK: vsxseg8h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0xec]
vsxseg8h.v v0, (a1), v2, v0.t

# CHECK: vsxseg8w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0xec]
vsxseg8w.v v0, (a1), v2, v0.t

# CHECK: vsxseg8e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0xec]
vsxseg8e.v v0, (a1), v2, v0.t

# CHECK: vlseg2bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x31]
vlseg2bff.v v0, (a1), v0.t

# CHECK: vlseg2hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x31]
vlseg2hff.v v0, (a1), v0.t

# CHECK: vlseg2wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x31]
vlseg2wff.v v0, (a1), v0.t

# CHECK: vlseg2buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x21]
vlseg2buff.v v0, (a1), v0.t

# CHECK: vlseg2huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x21]
vlseg2huff.v v0, (a1), v0.t

# CHECK: vlseg2wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x21]
vlseg2wuff.v v0, (a1), v0.t

# CHECK: vlseg2eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x21]
vlseg2eff.v v0, (a1), v0.t

# CHECK: vlseg3bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x51]
vlseg3bff.v v0, (a1), v0.t

# CHECK: vlseg3hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x51]
vlseg3hff.v v0, (a1), v0.t

# CHECK: vlseg3wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x51]
vlseg3wff.v v0, (a1), v0.t

# CHECK: vlseg3buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x41]
vlseg3buff.v v0, (a1), v0.t

# CHECK: vlseg3huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x41]
vlseg3huff.v v0, (a1), v0.t

# CHECK: vlseg3wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x41]
vlseg3wuff.v v0, (a1), v0.t

# CHECK: vlseg3eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x41]
vlseg3eff.v v0, (a1), v0.t

# CHECK: vlseg4bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x71]
vlseg4bff.v v0, (a1), v0.t

# CHECK: vlseg4hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x71]
vlseg4hff.v v0, (a1), v0.t

# CHECK: vlseg4wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x71]
vlseg4wff.v v0, (a1), v0.t

# CHECK: vlseg4buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x61]
vlseg4buff.v v0, (a1), v0.t

# CHECK: vlseg4huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x61]
vlseg4huff.v v0, (a1), v0.t

# CHECK: vlseg4wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x61]
vlseg4wuff.v v0, (a1), v0.t

# CHECK: vlseg4eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x61]
vlseg4eff.v v0, (a1), v0.t

# CHECK: vlseg5bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x91]
vlseg5bff.v v0, (a1), v0.t

# CHECK: vlseg5hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x91]
vlseg5hff.v v0, (a1), v0.t

# CHECK: vlseg5wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x91]
vlseg5wff.v v0, (a1), v0.t

# CHECK: vlseg5buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x81]
vlseg5buff.v v0, (a1), v0.t

# CHECK: vlseg5huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x81]
vlseg5huff.v v0, (a1), v0.t

# CHECK: vlseg5wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x81]
vlseg5wuff.v v0, (a1), v0.t

# CHECK: vlseg5eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x81]
vlseg5eff.v v0, (a1), v0.t

# CHECK: vlseg6bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xb1]
vlseg6bff.v v0, (a1), v0.t

# CHECK: vlseg6hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xb1]
vlseg6hff.v v0, (a1), v0.t

# CHECK: vlseg6wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xb1]
vlseg6wff.v v0, (a1), v0.t

# CHECK: vlseg6buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xa1]
vlseg6buff.v v0, (a1), v0.t

# CHECK: vlseg6huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xa1]
vlseg6huff.v v0, (a1), v0.t

# CHECK: vlseg6wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xa1]
vlseg6wuff.v v0, (a1), v0.t

# CHECK: vlseg6eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xa1]
vlseg6eff.v v0, (a1), v0.t

# CHECK: vlseg7bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xd1]
vlseg7bff.v v0, (a1), v0.t

# CHECK: vlseg7hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xd1]
vlseg7hff.v v0, (a1), v0.t

# CHECK: vlseg7wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xd1]
vlseg7wff.v v0, (a1), v0.t

# CHECK: vlseg7buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xc1]
vlseg7buff.v v0, (a1), v0.t

# CHECK: vlseg7huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xc1]
vlseg7huff.v v0, (a1), v0.t

# CHECK: vlseg7wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xc1]
vlseg7wuff.v v0, (a1), v0.t

# CHECK: vlseg7eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xc1]
vlseg7eff.v v0, (a1), v0.t

# CHECK: vlseg8bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xf1]
vlseg8bff.v v0, (a1), v0.t

# CHECK: vlseg8hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xf1]
vlseg8hff.v v0, (a1), v0.t

# CHECK: vlseg8wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xf1]
vlseg8wff.v v0, (a1), v0.t

# CHECK: vlseg8buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xe1]
vlseg8buff.v v0, (a1), v0.t

# CHECK: vlseg8huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xe1]
vlseg8huff.v v0, (a1), v0.t

# CHECK: vlseg8wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xe1]
vlseg8wuff.v v0, (a1), v0.t

# CHECK: vlseg8eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xe1]
vlseg8eff.v v0, (a1), v0.t

# CHECK: vamoswapw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x0c]
vamoswapw.v v0, (a1), v2, v0, v0.t

# CHECK: vamoswapw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x08]
vamoswapw.v x0, (a1), v2, v0, v0.t

# CHECK: vamoaddw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x04]
vamoaddw.v v0, (a1), v2, v0, v0.t

# CHECK: vamoaddw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x00]
vamoaddw.v x0, (a1), v2, v0, v0.t

# CHECK: vamoxorw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x24]
vamoxorw.v v0, (a1), v2, v0, v0.t

# CHECK: vamoxorw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x20]
vamoxorw.v x0, (a1), v2, v0, v0.t

# CHECK: vamoandw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x64]
vamoandw.v v0, (a1), v2, v0, v0.t

# CHECK: vamoandw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x60]
vamoandw.v x0, (a1), v2, v0, v0.t

# CHECK: vamoorw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x44]
vamoorw.v v0, (a1), v2, v0, v0.t

# CHECK: vamoorw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x40]
vamoorw.v x0, (a1), v2, v0, v0.t

# CHECK: vamominw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x84]
vamominw.v v0, (a1), v2, v0, v0.t

# CHECK: vamominw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x80]
vamominw.v x0, (a1), v2, v0, v0.t

# CHECK: vamomaxw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xa4]
vamomaxw.v v0, (a1), v2, v0, v0.t

# CHECK: vamomaxw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xa0]
vamomaxw.v x0, (a1), v2, v0, v0.t

# CHECK: vamominuw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xc4]
vamominuw.v v0, (a1), v2, v0, v0.t

# CHECK: vamominuw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xc0]
vamominuw.v x0, (a1), v2, v0, v0.t

# CHECK: vamomaxuw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xe4]
vamomaxuw.v v0, (a1), v2, v0, v0.t

# CHECK: vamomaxuw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xe0]
vamomaxuw.v x0, (a1), v2, v0, v0.t

# CHECK: vamoswape.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x0c]
vamoswape.v v0, (a1), v2, v0, v0.t

# CHECK: vamoswape.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x08]
vamoswape.v x0, (a1), v2, v0, v0.t

# CHECK: vamoadde.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x04]
vamoadde.v v0, (a1), v2, v0, v0.t

# CHECK: vamoadde.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x00]
vamoadde.v x0, (a1), v2, v0, v0.t

# CHECK: vamoxore.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x24]
vamoxore.v v0, (a1), v2, v0, v0.t

# CHECK: vamoxore.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x20]
vamoxore.v x0, (a1), v2, v0, v0.t

# CHECK: vamoande.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x64]
vamoande.v v0, (a1), v2, v0, v0.t

# CHECK: vamoande.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x60]
vamoande.v x0, (a1), v2, v0, v0.t

# CHECK: vamoore.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x44]
vamoore.v v0, (a1), v2, v0, v0.t

# CHECK: vamoore.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x40]
vamoore.v x0, (a1), v2, v0, v0.t

# CHECK: vamomine.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x84]
vamomine.v v0, (a1), v2, v0, v0.t

# CHECK: vamomine.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x80]
vamomine.v x0, (a1), v2, v0, v0.t

# CHECK: vamomaxe.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xa4]
vamomaxe.v v0, (a1), v2, v0, v0.t

# CHECK: vamomaxe.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xa0]
vamomaxe.v x0, (a1), v2, v0, v0.t

# CHECK: vamominue.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xc4]
vamominue.v v0, (a1), v2, v0, v0.t

# CHECK: vamominue.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xc0]
vamominue.v x0, (a1), v2, v0, v0.t

# CHECK: vamomaxue.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xe4]
vamomaxue.v v0, (a1), v2, v0, v0.t

# CHECK: vamomaxue.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xe0]
vamomaxue.v x0, (a1), v2, v0, v0.t

# CHECK: vwadd.vx v0, v1, zero, v0.t
[0x57,0x60,0x10,0xc4]
vwcvt.x.x.v v0, v1, v0.t

# CHECK: vwaddu.vx v0, v1, zero, v0.t
[0x57,0x60,0x10,0xc0]
vwcvtu.x.x.v v0, v1, v0.t

# CHECK: vxor.vi v0, v1, -1, v0.t
[0x57,0xb0,0x1f,0x2c]
vnot.v v0, v1, v0.t

# CHECK: vmslt.vv v0, v2, v1, v0.t
[0x57,0x80,0x20,0x6c]
vmsgt.vv v0, v1, v2, v0.t

# CHECK: vmsltu.vv v0, v2, v1, v0.t
[0x57,0x80,0x20,0x68]
vmsgtu.vv v0, v1, v2, v0.t

# CHECK: vmsle.vv v0, v2, v1, v0.t
[0x57,0x80,0x20,0x74]
vmsge.vv v0, v1, v2, v0.t

# CHECK: vmsleu.vv v0, v2, v1, v0.t
[0x57,0x80,0x20,0x70]
vmsgeu.vv v0, v1, v2, v0.t

# CHECK: vmflt.vv v0, v2, v1, v0.t
[0x57,0x90,0x20,0x6c]
vmfgt.vv v0, v1, v2, v0.t

# CHECK: vmfle.vv v0, v2, v1, v0.t
[0x57,0x90,0x20,0x64]
vmfge.vv v0, v1, v2, v0.t

# CHECK: vmsle.vi v0, v1, 3, v0.t
[0x57,0xb0,0x11,0x74]
vmslt.vi v0, v1, 4, v0.t

# CHECK: vmsleu.vi v0, v1, 3, v0.t
[0x57,0xb0,0x11,0x70]
vmsltu.vi v0, v1, 4, v0.t

# CHECK: vmsgt.vi v0, v1, 3, v0.t
[0x57,0xb0,0x11,0x7c]
vmsge.vi v0, v1, 4, v0.t

# CHECK: vmsgtu.vi v0, v1, 3, v0.t
[0x57,0xb0,0x11,0x78]
vmsgeu.vi v0, v1, 4, v0.t

# CHECK: addi   t0, a2, -1
#                    vmsgt.vx v0, v1, t0, v0.t
[0x93,0x02,0xf6,0xff]
#            encoding: [0x57,0xb0,0x11,0x7c]
vmsge.vx v0, v1, a2, v0.t

# CHECK: addi   t0, a2, -1
#                    vmsgtu.vx v0, v1, t0, v0.t
[0x93,0x02,0xf6,0xff]
#            encoding: [0x57,0xb0,0x11,0x78]
vmsgeu.vx v0, v1, a2, v0.t

# CHECK: vmslt.vx  v3, v1, a2
#                    vmandnot.mm  v0, v0, v3
[0xd7,0x41,0x16,0x6e]
#            encoding: [0x57,0xa0,0x01,0x62]
vmsge.vx v0, v1, a2, v0.t, v3

# CHECK: vmsltu.vx  v3, v1, a2
#                    vmandnot.mm  v0, v0, v3
[0xd7,0x41,0x16,0x6a]
#            encoding: [0x57,0xa0,0x01,0x62]
vmsgeu.vx v0, v1, a2, v0.t, v3


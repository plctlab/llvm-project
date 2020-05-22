# RUN: llvm-mc -disassemble --triple riscv64 -mattr m,+a,+f,+d,+c,+v < %s | \
# RUN:         FileCheck %s



# CHECK: vlb.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x10]
vlb.v v0, 0(a1), v0.t

# CHECK: vlh.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x10]
vlh.v v0, 0(a1), v0.t

# CHECK: vlw.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x10]
vlw.v v0, 0(a1), v0.t

# CHECK: vlbu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x00]
vlbu.v v0, 0(a1), v0.t

# CHECK: vlhu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x00]
vlhu.v v0, 0(a1), v0.t

# CHECK: vlwu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x00]
vlwu.v v0, 0(a1), v0.t

# CHECK: vle.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x00]
vle.v v0, 0(a1), v0.t

# CHECK: vsb.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x00]
vsb.v v0, 0(a1), v0.t

# CHECK: vsh.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x00]
vsh.v v0, 0(a1), v0.t

# CHECK: vsw.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x00]
vsw.v v0, 0(a1), v0.t

# CHECK: vse.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x00]
vse.v v0, 0(a1), v0.t

# CHECK: vlsb.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x18]
vlsb.v v0, 0(a1), a2, v0.t

# CHECK: vlsh.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x18]
vlsh.v v0, 0(a1), a2, v0.t

# CHECK: vlsw.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x18]
vlsw.v v0, 0(a1), a2, v0.t

# CHECK: vlsbu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x08]
vlsbu.v v0, 0(a1), a2, v0.t

# CHECK: vlshu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x08]
vlshu.v v0, 0(a1), a2, v0.t

# CHECK: vlswu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x08]
vlswu.v v0, 0(a1), a2, v0.t

# CHECK: vlse.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x08]
vlse.v v0, 0(a1), a2, v0.t

# CHECK: vssb.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x08]
vssb.v v0, 0(a1), a2, v0.t

# CHECK: vssh.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x08]
vssh.v v0, 0(a1), a2, v0.t

# CHECK: vssw.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x08]
vssw.v v0, 0(a1), a2, v0.t

# CHECK: vsse.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x08]
vsse.v v0, 0(a1), a2, v0.t

# CHECK: vlxb.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x1c]
vlxb.v v0, 0(a1), v2, v0.t

# CHECK: vlxh.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x1c]
vlxh.v v0, 0(a1), v2, v0.t

# CHECK: vlxw.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x1c]
vlxw.v v0, 0(a1), v2, v0.t

# CHECK: vlxbu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x0c]
vlxbu.v v0, 0(a1), v2, v0.t

# CHECK: vlxhu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x0c]
vlxhu.v v0, 0(a1), v2, v0.t

# CHECK: vlxwu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x0c]
vlxwu.v v0, 0(a1), v2, v0.t

# CHECK: vlxe.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x0c]
vlxe.v v0, 0(a1), v2, v0.t

# CHECK: vsxb.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x0c]
vsxb.v v0, 0(a1), v2, v0.t

# CHECK: vsxh.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x0c]
vsxh.v v0, 0(a1), v2, v0.t

# CHECK: vsxw.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x0c]
vsxw.v v0, 0(a1), v2, v0.t

# CHECK: vsxe.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x0c]
vsxe.v v0, 0(a1), v2, v0.t

# CHECK: vsuxb.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x1c]
vsuxb.v v0, 0(a1), v2, v0.t

# CHECK: vsuxh.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x1c]
vsuxh.v v0, 0(a1), v2, v0.t

# CHECK: vsuxw.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x1c]
vsuxw.v v0, 0(a1), v2, v0.t

# CHECK: vsuxe.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x1c]
vsuxe.v v0, 0(a1), v2, v0.t

# CHECK: vlbff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x11]
vlbff.v v0, 0(a1), v0.t

# CHECK: vlhff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x11]
vlhff.v v0, 0(a1), v0.t

# CHECK: vlwff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x11]
vlwff.v v0, 0(a1), v0.t

# CHECK: vlbuff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x01]
vlbuff.v v0, 0(a1), v0.t

# CHECK: vlhuff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x01]
vlhuff.v v0, 0(a1), v0.t

# CHECK: vlwuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x01]
vlwuff.v v0, 0(a1), v0.t

# CHECK: vleff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x01]
vleff.v v0, 0(a1), v0.t

# CHECK: vlseg2b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x30]
vlseg2b.v v0, 0(a1), v0.t

# CHECK: vlseg2h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x30]
vlseg2h.v v0, 0(a1), v0.t

# CHECK: vlseg2w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x30]
vlseg2w.v v0, 0(a1), v0.t

# CHECK: vlseg2bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x20]
vlseg2bu.v v0, 0(a1), v0.t

# CHECK: vlseg2hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x20]
vlseg2hu.v v0, 0(a1), v0.t

# CHECK: vlseg2wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x20]
vlseg2wu.v v0, 0(a1), v0.t

# CHECK: vlseg2e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x20]
vlseg2e.v v0, 0(a1), v0.t

# CHECK: vsseg2b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x20]
vsseg2b.v v0, 0(a1), v0.t

# CHECK: vsseg2h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x20]
vsseg2h.v v0, 0(a1), v0.t

# CHECK: vsseg2w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x20]
vsseg2w.v v0, 0(a1), v0.t

# CHECK: vsseg2e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x20]
vsseg2e.v v0, 0(a1), v0.t

# CHECK: vlseg3b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x50]
vlseg3b.v v0, 0(a1), v0.t

# CHECK: vlseg3h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x50]
vlseg3h.v v0, 0(a1), v0.t

# CHECK: vlseg3w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x50]
vlseg3w.v v0, 0(a1), v0.t

# CHECK: vlseg3bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x40]
vlseg3bu.v v0, 0(a1), v0.t

# CHECK: vlseg3hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x40]
vlseg3hu.v v0, 0(a1), v0.t

# CHECK: vlseg3wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x40]
vlseg3wu.v v0, 0(a1), v0.t

# CHECK: vlseg3e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x40]
vlseg3e.v v0, 0(a1), v0.t

# CHECK: vsseg3b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x40]
vsseg3b.v v0, 0(a1), v0.t

# CHECK: vsseg3h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x40]
vsseg3h.v v0, 0(a1), v0.t

# CHECK: vsseg3w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x40]
vsseg3w.v v0, 0(a1), v0.t

# CHECK: vsseg3e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x40]
vsseg3e.v v0, 0(a1), v0.t

# CHECK: vlseg4b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x70]
vlseg4b.v v0, 0(a1), v0.t

# CHECK: vlseg4h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x70]
vlseg4h.v v0, 0(a1), v0.t

# CHECK: vlseg4w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x70]
vlseg4w.v v0, 0(a1), v0.t

# CHECK: vlseg4bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x60]
vlseg4bu.v v0, 0(a1), v0.t

# CHECK: vlseg4hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x60]
vlseg4hu.v v0, 0(a1), v0.t

# CHECK: vlseg4wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x60]
vlseg4wu.v v0, 0(a1), v0.t

# CHECK: vlseg4e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x60]
vlseg4e.v v0, 0(a1), v0.t

# CHECK: vsseg4b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x60]
vsseg4b.v v0, 0(a1), v0.t

# CHECK: vsseg4h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x60]
vsseg4h.v v0, 0(a1), v0.t

# CHECK: vsseg4w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x60]
vsseg4w.v v0, 0(a1), v0.t

# CHECK: vsseg4e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x60]
vsseg4e.v v0, 0(a1), v0.t

# CHECK: vlseg5b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x90]
vlseg5b.v v0, 0(a1), v0.t

# CHECK: vlseg5h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x90]
vlseg5h.v v0, 0(a1), v0.t

# CHECK: vlseg5w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x90]
vlseg5w.v v0, 0(a1), v0.t

# CHECK: vlseg5bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x80]
vlseg5bu.v v0, 0(a1), v0.t

# CHECK: vlseg5hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x80]
vlseg5hu.v v0, 0(a1), v0.t

# CHECK: vlseg5wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x80]
vlseg5wu.v v0, 0(a1), v0.t

# CHECK: vlseg5e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x80]
vlseg5e.v v0, 0(a1), v0.t

# CHECK: vsseg5b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0x80]
vsseg5b.v v0, 0(a1), v0.t

# CHECK: vsseg5h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0x80]
vsseg5h.v v0, 0(a1), v0.t

# CHECK: vsseg5w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0x80]
vsseg5w.v v0, 0(a1), v0.t

# CHECK: vsseg5e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0x80]
vsseg5e.v v0, 0(a1), v0.t

# CHECK: vlseg6b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xb0]
vlseg6b.v v0, 0(a1), v0.t

# CHECK: vlseg6h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xb0]
vlseg6h.v v0, 0(a1), v0.t

# CHECK: vlseg6w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xb0]
vlseg6w.v v0, 0(a1), v0.t

# CHECK: vlseg6bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xa0]
vlseg6bu.v v0, 0(a1), v0.t

# CHECK: vlseg6hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xa0]
vlseg6hu.v v0, 0(a1), v0.t

# CHECK: vlseg6wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xa0]
vlseg6wu.v v0, 0(a1), v0.t

# CHECK: vlseg6e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xa0]
vlseg6e.v v0, 0(a1), v0.t

# CHECK: vsseg6b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0xa0]
vsseg6b.v v0, 0(a1), v0.t

# CHECK: vsseg6h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0xa0]
vsseg6h.v v0, 0(a1), v0.t

# CHECK: vsseg6w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0xa0]
vsseg6w.v v0, 0(a1), v0.t

# CHECK: vsseg6e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0xa0]
vsseg6e.v v0, 0(a1), v0.t

# CHECK: vlseg7b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xd0]
vlseg7b.v v0, 0(a1), v0.t

# CHECK: vlseg7h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xd0]
vlseg7h.v v0, 0(a1), v0.t

# CHECK: vlseg7w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xd0]
vlseg7w.v v0, 0(a1), v0.t

# CHECK: vlseg7bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xc0]
vlseg7bu.v v0, 0(a1), v0.t

# CHECK: vlseg7hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xc0]
vlseg7hu.v v0, 0(a1), v0.t

# CHECK: vlseg7wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xc0]
vlseg7wu.v v0, 0(a1), v0.t

# CHECK: vlseg7e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xc0]
vlseg7e.v v0, 0(a1), v0.t

# CHECK: vsseg7b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0xc0]
vsseg7b.v v0, 0(a1), v0.t

# CHECK: vsseg7h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0xc0]
vsseg7h.v v0, 0(a1), v0.t

# CHECK: vsseg7w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0xc0]
vsseg7w.v v0, 0(a1), v0.t

# CHECK: vsseg7e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0xc0]
vsseg7e.v v0, 0(a1), v0.t

# CHECK: vlseg8b.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xf0]
vlseg8b.v v0, 0(a1), v0.t

# CHECK: vlseg8h.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xf0]
vlseg8h.v v0, 0(a1), v0.t

# CHECK: vlseg8w.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xf0]
vlseg8w.v v0, 0(a1), v0.t

# CHECK: vlseg8bu.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xe0]
vlseg8bu.v v0, 0(a1), v0.t

# CHECK: vlseg8hu.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xe0]
vlseg8hu.v v0, 0(a1), v0.t

# CHECK: vlseg8wu.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xe0]
vlseg8wu.v v0, 0(a1), v0.t

# CHECK: vlseg8e.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xe0]
vlseg8e.v v0, 0(a1), v0.t

# CHECK: vsseg8b.v v0, 0(a1), v0.t
[0x27,0x80,0x05,0xe0]
vsseg8b.v v0, 0(a1), v0.t

# CHECK: vsseg8h.v v0, 0(a1), v0.t
[0x27,0xd0,0x05,0xe0]
vsseg8h.v v0, 0(a1), v0.t

# CHECK: vsseg8w.v v0, 0(a1), v0.t
[0x27,0xe0,0x05,0xe0]
vsseg8w.v v0, 0(a1), v0.t

# CHECK: vsseg8e.v v0, 0(a1), v0.t
[0x27,0xf0,0x05,0xe0]
vsseg8e.v v0, 0(a1), v0.t

# CHECK: vlsseg2b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x38]
vlsseg2b.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg2h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x38]
vlsseg2h.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg2w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x38]
vlsseg2w.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg2bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x28]
vlsseg2bu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg2hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x28]
vlsseg2hu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg2wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x28]
vlsseg2wu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg2e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x28]
vlsseg2e.v v0, 0(a1), a2, v0.t

# CHECK: vssseg2b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x28]
vssseg2b.v v0, 0(a1), a2, v0.t

# CHECK: vssseg2h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x28]
vssseg2h.v v0, 0(a1), a2, v0.t

# CHECK: vssseg2w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x28]
vssseg2w.v v0, 0(a1), a2, v0.t

# CHECK: vssseg2e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x28]
vssseg2e.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg3b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x58]
vlsseg3b.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg3h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x58]
vlsseg3h.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg3w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x58]
vlsseg3w.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg3bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x48]
vlsseg3bu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg3hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x48]
vlsseg3hu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg3wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x48]
vlsseg3wu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg3e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x48]
vlsseg3e.v v0, 0(a1), a2, v0.t

# CHECK: vssseg3b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x48]
vssseg3b.v v0, 0(a1), a2, v0.t

# CHECK: vssseg3h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x48]
vssseg3h.v v0, 0(a1), a2, v0.t

# CHECK: vssseg3w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x48]
vssseg3w.v v0, 0(a1), a2, v0.t

# CHECK: vssseg3e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x48]
vssseg3e.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg4b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x78]
vlsseg4b.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg4h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x78]
vlsseg4h.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg4w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x78]
vlsseg4w.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg4bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x68]
vlsseg4bu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg4hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x68]
vlsseg4hu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg4wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x68]
vlsseg4wu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg4e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x68]
vlsseg4e.v v0, 0(a1), a2, v0.t

# CHECK: vssseg4b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x68]
vssseg4b.v v0, 0(a1), a2, v0.t

# CHECK: vssseg4h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x68]
vssseg4h.v v0, 0(a1), a2, v0.t

# CHECK: vssseg4w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x68]
vssseg4w.v v0, 0(a1), a2, v0.t

# CHECK: vssseg4e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x68]
vssseg4e.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg5b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x98]
vlsseg5b.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg5h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x98]
vlsseg5h.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg5w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x98]
vlsseg5w.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg5bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0x88]
vlsseg5bu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg5hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0x88]
vlsseg5hu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg5wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0x88]
vlsseg5wu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg5e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0x88]
vlsseg5e.v v0, 0(a1), a2, v0.t

# CHECK: vssseg5b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0x88]
vssseg5b.v v0, 0(a1), a2, v0.t

# CHECK: vssseg5h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0x88]
vssseg5h.v v0, 0(a1), a2, v0.t

# CHECK: vssseg5w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0x88]
vssseg5w.v v0, 0(a1), a2, v0.t

# CHECK: vssseg5e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0x88]
vssseg5e.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg6b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xb8]
vlsseg6b.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg6h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xb8]
vlsseg6h.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg6w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xb8]
vlsseg6w.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg6bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xa8]
vlsseg6bu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg6hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xa8]
vlsseg6hu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg6wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xa8]
vlsseg6wu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg6e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0xa8]
vlsseg6e.v v0, 0(a1), a2, v0.t

# CHECK: vssseg6b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0xa8]
vssseg6b.v v0, 0(a1), a2, v0.t

# CHECK: vssseg6h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0xa8]
vssseg6h.v v0, 0(a1), a2, v0.t

# CHECK: vssseg6w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0xa8]
vssseg6w.v v0, 0(a1), a2, v0.t

# CHECK: vssseg6e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0xa8]
vssseg6e.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg7b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xd8]
vlsseg7b.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg7h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xd8]
vlsseg7h.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg7w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xd8]
vlsseg7w.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg7bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xc8]
vlsseg7bu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg7hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xc8]
vlsseg7hu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg7wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xc8]
vlsseg7wu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg7e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0xc8]
vlsseg7e.v v0, 0(a1), a2, v0.t

# CHECK: vssseg7b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0xc8]
vssseg7b.v v0, 0(a1), a2, v0.t

# CHECK: vssseg7h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0xc8]
vssseg7h.v v0, 0(a1), a2, v0.t

# CHECK: vssseg7w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0xc8]
vssseg7w.v v0, 0(a1), a2, v0.t

# CHECK: vssseg7e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0xc8]
vssseg7e.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg8b.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xf8]
vlsseg8b.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg8h.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xf8]
vlsseg8h.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg8w.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xf8]
vlsseg8w.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg8bu.v v0, 0(a1), a2, v0.t
[0x07,0x80,0xc5,0xe8]
vlsseg8bu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg8hu.v v0, 0(a1), a2, v0.t
[0x07,0xd0,0xc5,0xe8]
vlsseg8hu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg8wu.v v0, 0(a1), a2, v0.t
[0x07,0xe0,0xc5,0xe8]
vlsseg8wu.v v0, 0(a1), a2, v0.t

# CHECK: vlsseg8e.v v0, 0(a1), a2, v0.t
[0x07,0xf0,0xc5,0xe8]
vlsseg8e.v v0, 0(a1), a2, v0.t

# CHECK: vssseg8b.v v0, 0(a1), a2, v0.t
[0x27,0x80,0xc5,0xe8]
vssseg8b.v v0, 0(a1), a2, v0.t

# CHECK: vssseg8h.v v0, 0(a1), a2, v0.t
[0x27,0xd0,0xc5,0xe8]
vssseg8h.v v0, 0(a1), a2, v0.t

# CHECK: vssseg8w.v v0, 0(a1), a2, v0.t
[0x27,0xe0,0xc5,0xe8]
vssseg8w.v v0, 0(a1), a2, v0.t

# CHECK: vssseg8e.v v0, 0(a1), a2, v0.t
[0x27,0xf0,0xc5,0xe8]
vssseg8e.v v0, 0(a1), a2, v0.t

# CHECK: vlxseg2b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x3c]
vlxseg2b.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg2h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x3c]
vlxseg2h.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg2w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x3c]
vlxseg2w.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg2bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x2c]
vlxseg2bu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg2hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x2c]
vlxseg2hu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg2wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x2c]
vlxseg2wu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg2e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x2c]
vlxseg2e.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg2b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x2c]
vsxseg2b.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg2h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x2c]
vsxseg2h.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg2w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x2c]
vsxseg2w.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg2e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x2c]
vsxseg2e.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg3b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x5c]
vlxseg3b.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg3h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x5c]
vlxseg3h.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg3w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x5c]
vlxseg3w.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg3bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x4c]
vlxseg3bu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg3hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x4c]
vlxseg3hu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg3wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x4c]
vlxseg3wu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg3e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x4c]
vlxseg3e.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg3b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x4c]
vsxseg3b.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg3h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x4c]
vsxseg3h.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg3w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x4c]
vsxseg3w.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg3e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x4c]
vsxseg3e.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg4b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x7c]
vlxseg4b.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg4h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x7c]
vlxseg4h.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg4w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x7c]
vlxseg4w.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg4bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x6c]
vlxseg4bu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg4hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x6c]
vlxseg4hu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg4wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x6c]
vlxseg4wu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg4e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x6c]
vlxseg4e.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg4b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x6c]
vsxseg4b.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg4h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x6c]
vsxseg4h.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg4w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x6c]
vsxseg4w.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg4e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x6c]
vsxseg4e.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg5b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x9c]
vlxseg5b.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg5h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x9c]
vlxseg5h.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg5w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x9c]
vlxseg5w.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg5bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0x8c]
vlxseg5bu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg5hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0x8c]
vlxseg5hu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg5wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0x8c]
vlxseg5wu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg5e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0x8c]
vlxseg5e.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg5b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0x8c]
vsxseg5b.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg5h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0x8c]
vsxseg5h.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg5w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0x8c]
vsxseg5w.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg5e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0x8c]
vsxseg5e.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg6b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xbc]
vlxseg6b.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg6h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xbc]
vlxseg6h.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg6w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xbc]
vlxseg6w.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg6bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xac]
vlxseg6bu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg6hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xac]
vlxseg6hu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg6wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xac]
vlxseg6wu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg6e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0xac]
vlxseg6e.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg6b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0xac]
vsxseg6b.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg6h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0xac]
vsxseg6h.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg6w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0xac]
vsxseg6w.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg6e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0xac]
vsxseg6e.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg7b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xdc]
vlxseg7b.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg7h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xdc]
vlxseg7h.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg7w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xdc]
vlxseg7w.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg7bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xcc]
vlxseg7bu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg7hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xcc]
vlxseg7hu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg7wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xcc]
vlxseg7wu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg7e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0xcc]
vlxseg7e.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg7b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0xcc]
vsxseg7b.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg7h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0xcc]
vsxseg7h.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg7w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0xcc]
vsxseg7w.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg7e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0xcc]
vsxseg7e.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg8b.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xfc]
vlxseg8b.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg8h.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xfc]
vlxseg8h.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg8w.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xfc]
vlxseg8w.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg8bu.v v0, 0(a1), v2, v0.t
[0x07,0x80,0x25,0xec]
vlxseg8bu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg8hu.v v0, 0(a1), v2, v0.t
[0x07,0xd0,0x25,0xec]
vlxseg8hu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg8wu.v v0, 0(a1), v2, v0.t
[0x07,0xe0,0x25,0xec]
vlxseg8wu.v v0, 0(a1), v2, v0.t

# CHECK: vlxseg8e.v v0, 0(a1), v2, v0.t
[0x07,0xf0,0x25,0xec]
vlxseg8e.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg8b.v v0, 0(a1), v2, v0.t
[0x27,0x80,0x25,0xec]
vsxseg8b.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg8h.v v0, 0(a1), v2, v0.t
[0x27,0xd0,0x25,0xec]
vsxseg8h.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg8w.v v0, 0(a1), v2, v0.t
[0x27,0xe0,0x25,0xec]
vsxseg8w.v v0, 0(a1), v2, v0.t

# CHECK: vsxseg8e.v v0, 0(a1), v2, v0.t
[0x27,0xf0,0x25,0xec]
vsxseg8e.v v0, 0(a1), v2, v0.t

# CHECK: vlseg2bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x31]
vlseg2bff.v v0, 0(a1), v0.t

# CHECK: vlseg2hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x31]
vlseg2hff.v v0, 0(a1), v0.t

# CHECK: vlseg2wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x31]
vlseg2wff.v v0, 0(a1), v0.t

# CHECK: vlseg2buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x21]
vlseg2buff.v v0, 0(a1), v0.t

# CHECK: vlseg2huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x21]
vlseg2huff.v v0, 0(a1), v0.t

# CHECK: vlseg2wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x21]
vlseg2wuff.v v0, 0(a1), v0.t

# CHECK: vlseg2eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x21]
vlseg2eff.v v0, 0(a1), v0.t

# CHECK: vlseg3bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x51]
vlseg3bff.v v0, 0(a1), v0.t

# CHECK: vlseg3hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x51]
vlseg3hff.v v0, 0(a1), v0.t

# CHECK: vlseg3wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x51]
vlseg3wff.v v0, 0(a1), v0.t

# CHECK: vlseg3buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x41]
vlseg3buff.v v0, 0(a1), v0.t

# CHECK: vlseg3huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x41]
vlseg3huff.v v0, 0(a1), v0.t

# CHECK: vlseg3wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x41]
vlseg3wuff.v v0, 0(a1), v0.t

# CHECK: vlseg3eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x41]
vlseg3eff.v v0, 0(a1), v0.t

# CHECK: vlseg4bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x71]
vlseg4bff.v v0, 0(a1), v0.t

# CHECK: vlseg4hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x71]
vlseg4hff.v v0, 0(a1), v0.t

# CHECK: vlseg4wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x71]
vlseg4wff.v v0, 0(a1), v0.t

# CHECK: vlseg4buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x61]
vlseg4buff.v v0, 0(a1), v0.t

# CHECK: vlseg4huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x61]
vlseg4huff.v v0, 0(a1), v0.t

# CHECK: vlseg4wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x61]
vlseg4wuff.v v0, 0(a1), v0.t

# CHECK: vlseg4eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x61]
vlseg4eff.v v0, 0(a1), v0.t

# CHECK: vlseg5bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x91]
vlseg5bff.v v0, 0(a1), v0.t

# CHECK: vlseg5hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x91]
vlseg5hff.v v0, 0(a1), v0.t

# CHECK: vlseg5wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x91]
vlseg5wff.v v0, 0(a1), v0.t

# CHECK: vlseg5buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0x81]
vlseg5buff.v v0, 0(a1), v0.t

# CHECK: vlseg5huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0x81]
vlseg5huff.v v0, 0(a1), v0.t

# CHECK: vlseg5wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0x81]
vlseg5wuff.v v0, 0(a1), v0.t

# CHECK: vlseg5eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0x81]
vlseg5eff.v v0, 0(a1), v0.t

# CHECK: vlseg6bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xb1]
vlseg6bff.v v0, 0(a1), v0.t

# CHECK: vlseg6hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xb1]
vlseg6hff.v v0, 0(a1), v0.t

# CHECK: vlseg6wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xb1]
vlseg6wff.v v0, 0(a1), v0.t

# CHECK: vlseg6buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xa1]
vlseg6buff.v v0, 0(a1), v0.t

# CHECK: vlseg6huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xa1]
vlseg6huff.v v0, 0(a1), v0.t

# CHECK: vlseg6wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xa1]
vlseg6wuff.v v0, 0(a1), v0.t

# CHECK: vlseg6eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xa1]
vlseg6eff.v v0, 0(a1), v0.t

# CHECK: vlseg7bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xd1]
vlseg7bff.v v0, 0(a1), v0.t

# CHECK: vlseg7hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xd1]
vlseg7hff.v v0, 0(a1), v0.t

# CHECK: vlseg7wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xd1]
vlseg7wff.v v0, 0(a1), v0.t

# CHECK: vlseg7buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xc1]
vlseg7buff.v v0, 0(a1), v0.t

# CHECK: vlseg7huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xc1]
vlseg7huff.v v0, 0(a1), v0.t

# CHECK: vlseg7wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xc1]
vlseg7wuff.v v0, 0(a1), v0.t

# CHECK: vlseg7eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xc1]
vlseg7eff.v v0, 0(a1), v0.t

# CHECK: vlseg8bff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xf1]
vlseg8bff.v v0, 0(a1), v0.t

# CHECK: vlseg8hff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xf1]
vlseg8hff.v v0, 0(a1), v0.t

# CHECK: vlseg8wff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xf1]
vlseg8wff.v v0, 0(a1), v0.t

# CHECK: vlseg8buff.v v0, 0(a1), v0.t
[0x07,0x80,0x05,0xe1]
vlseg8buff.v v0, 0(a1), v0.t

# CHECK: vlseg8huff.v v0, 0(a1), v0.t
[0x07,0xd0,0x05,0xe1]
vlseg8huff.v v0, 0(a1), v0.t

# CHECK: vlseg8wuff.v v0, 0(a1), v0.t
[0x07,0xe0,0x05,0xe1]
vlseg8wuff.v v0, 0(a1), v0.t

# CHECK: vlseg8eff.v v0, 0(a1), v0.t
[0x07,0xf0,0x05,0xe1]
vlseg8eff.v v0, 0(a1), v0.t

# CHECK: vamoswapw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x0c]
vamoswapw.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoswapw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x08]
vamoswapw.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamoaddw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x04]
vamoaddw.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoaddw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x00]
vamoaddw.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamoxorw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x24]
vamoxorw.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoxorw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x20]
vamoxorw.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamoandw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x64]
vamoandw.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoandw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x60]
vamoandw.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamoorw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x44]
vamoorw.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoorw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x40]
vamoorw.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamominw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x84]
vamominw.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamominw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0x80]
vamominw.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamomaxw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xa4]
vamomaxw.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamomaxw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xa0]
vamomaxw.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamominuw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xc4]
vamominuw.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamominuw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xc0]
vamominuw.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamomaxuw.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xe4]
vamomaxuw.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamomaxuw.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xe0,0x25,0xe0]
vamomaxuw.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamoswape.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x0c]
vamoswape.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoswape.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x08]
vamoswape.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamoadde.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x04]
vamoadde.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoadde.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x00]
vamoadde.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamoxore.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x24]
vamoxore.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoxore.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x20]
vamoxore.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamoande.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x64]
vamoande.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoande.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x60]
vamoande.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamoore.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x44]
vamoore.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamoore.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x40]
vamoore.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamomine.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x84]
vamomine.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamomine.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0x80]
vamomine.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamomaxe.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xa4]
vamomaxe.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamomaxe.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xa0]
vamomaxe.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamominue.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xc4]
vamominue.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamominue.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xc0]
vamominue.v x0, 0(a1), v2, v0, v0.t

# CHECK: vamomaxue.v v0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xe4]
vamomaxue.v v0, 0(a1), v2, v0, v0.t

# CHECK: vamomaxue.v x0, 0(a1), v2, v0, v0.t
[0x2f,0xf0,0x25,0xe0]
vamomaxue.v x0, 0(a1), v2, v0, v0.t

# CHECK: vadd.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x00]
vadd.vv v0, v1, v0, v0.t

# CHECK: vadd.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x00]
vadd.vx v0, v1, a0, v0.t

# CHECK: vadd.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x00]
vadd.vi v0, v1, 0, v0.t

# CHECK: vsub.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x08]
vsub.vv v0, v1, v0, v0.t

# CHECK: vsub.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x08]
vsub.vx v0, v1, a0, v0.t

# CHECK: vrsub.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x0c]
vrsub.vx v0, v1, a0, v0.t

# CHECK: vrsub.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x0c]
vrsub.vi v0, v1, 0, v0.t

# CHECK: vwaddu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xc0]
vwaddu.vv v0, v1, v0, v0.t

# CHECK: vwaddu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xc0]
vwaddu.vx v0, v1, a0, v0.t

# CHECK: vwsubu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xc8]
vwsubu.vv v0, v1, v0, v0.t

# CHECK: vwsubu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xc8]
vwsubu.vx v0, v1, a0, v0.t

# CHECK: vwadd.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xc4]
vwadd.vv v0, v1, v0, v0.t

# CHECK: vwadd.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xc4]
vwadd.vx v0, v1, a0, v0.t

# CHECK: vwsub.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xcc]
vwsub.vv v0, v1, v0, v0.t

# CHECK: vwsub.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xcc]
vwsub.vx v0, v1, a0, v0.t

# CHECK: vwaddu.wv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xd0]
vwaddu.wv v0, v1, v0, v0.t

# CHECK: vwaddu.wx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xd0]
vwaddu.wx v0, v1, a0, v0.t

# CHECK: vwsubu.wv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xd8]
vwsubu.wv v0, v1, v0, v0.t

# CHECK: vwsubu.wx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xd8]
vwsubu.wx v0, v1, a0, v0.t

# CHECK: vwadd.wv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xd4]
vwadd.wv v0, v1, v0, v0.t

# CHECK: vwadd.wx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xd4]
vwadd.wx v0, v1, a0, v0.t

# CHECK: vwsub.wv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xdc]
vwsub.wv v0, v1, v0, v0.t

# CHECK: vwsub.wx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xdc]
vwsub.wx v0, v1, a0, v0.t

# CHECK: vand.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x24]
vand.vv v0, v1, v0, v0.t

# CHECK: vand.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x24]
vand.vx v0, v1, a0, v0.t

# CHECK: vand.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x24]
vand.vi v0, v1, 0, v0.t

# CHECK: vor.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x28]
vor.vv v0, v1, v0, v0.t

# CHECK: vor.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x28]
vor.vx v0, v1, a0, v0.t

# CHECK: vor.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x28]
vor.vi v0, v1, 0, v0.t

# CHECK: vxor.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x2c]
vxor.vv v0, v1, v0, v0.t

# CHECK: vxor.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x2c]
vxor.vx v0, v1, a0, v0.t

# CHECK: vxor.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x2c]
vxor.vi v0, v1, 0, v0.t

# CHECK: vsll.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x94]
vsll.vv v0, v1, v0, v0.t

# CHECK: vsll.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x94]
vsll.vx v0, v1, a0, v0.t

# CHECK: vsll.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x94]
vsll.vi v0, v1, 0, v0.t

# CHECK: vsrl.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xa0]
vsrl.vv v0, v1, v0, v0.t

# CHECK: vsrl.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0xa0]
vsrl.vx v0, v1, a0, v0.t

# CHECK: vsrl.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0xa0]
vsrl.vi v0, v1, 0, v0.t

# CHECK: vsra.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xa4]
vsra.vv v0, v1, v0, v0.t

# CHECK: vsra.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0xa4]
vsra.vx v0, v1, a0, v0.t

# CHECK: vsra.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0xa4]
vsra.vi v0, v1, 0, v0.t

# CHECK: vnsrl.wv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xb0]
vnsrl.wv v0, v1, v0, v0.t

# CHECK: vnsrl.wx v0, v1, a0, v0.t
[0x57,0x40,0x15,0xb0]
vnsrl.wx v0, v1, a0, v0.t

# CHECK: vnsrl.wi v0, v1, 0, v0.t
[0x57,0x30,0x10,0xb0]
vnsrl.wi v0, v1, 0, v0.t

# CHECK: vnsra.wv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xb4]
vnsra.wv v0, v1, v0, v0.t

# CHECK: vnsra.wx v0, v1, a0, v0.t
[0x57,0x40,0x15,0xb4]
vnsra.wx v0, v1, a0, v0.t

# CHECK: vnsra.wi v0, v1, 0, v0.t
[0x57,0x30,0x10,0xb4]
vnsra.wi v0, v1, 0, v0.t

# CHECK: vmseq.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x60]
vmseq.vv v0, v1, v0, v0.t

# CHECK: vmseq.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x60]
vmseq.vx v0, v1, a0, v0.t

# CHECK: vmseq.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x60]
vmseq.vi v0, v1, 0, v0.t

# CHECK: vmsne.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x64]
vmsne.vv v0, v1, v0, v0.t

# CHECK: vmsne.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x64]
vmsne.vx v0, v1, a0, v0.t

# CHECK: vmsne.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x64]
vmsne.vi v0, v1, 0, v0.t

# CHECK: vmsltu.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x68]
vmsltu.vv v0, v1, v0, v0.t

# CHECK: vmsltu.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x68]
vmsltu.vx v0, v1, a0, v0.t

# CHECK: vmslt.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x6c]
vmslt.vv v0, v1, v0, v0.t

# CHECK: vmslt.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x6c]
vmslt.vx v0, v1, a0, v0.t

# CHECK: vmsleu.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x70]
vmsleu.vv v0, v1, v0, v0.t

# CHECK: vmsleu.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x70]
vmsleu.vx v0, v1, a0, v0.t

# CHECK: vmsleu.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x70]
vmsleu.vi v0, v1, 0, v0.t

# CHECK: vmsle.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x74]
vmsle.vv v0, v1, v0, v0.t

# CHECK: vmsle.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x74]
vmsle.vx v0, v1, a0, v0.t

# CHECK: vmsle.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x74]
vmsle.vi v0, v1, 0, v0.t

# CHECK: vmsgtu.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x78]
vmsgtu.vx v0, v1, a0, v0.t

# CHECK: vmsgtu.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x78]
vmsgtu.vi v0, v1, 0, v0.t

# CHECK: vmsgt.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x7c]
vmsgt.vx v0, v1, a0, v0.t

# CHECK: vmsgt.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x7c]
vmsgt.vi v0, v1, 0, v0.t

# CHECK: vminu.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x10]
vminu.vv v0, v1, v0, v0.t

# CHECK: vminu.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x10]
vminu.vx v0, v1, a0, v0.t

# CHECK: vmin.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x14]
vmin.vv v0, v1, v0, v0.t

# CHECK: vmin.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x14]
vmin.vx v0, v1, a0, v0.t

# CHECK: vmaxu.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x18]
vmaxu.vv v0, v1, v0, v0.t

# CHECK: vmaxu.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x18]
vmaxu.vx v0, v1, a0, v0.t

# CHECK: vmax.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x1c]
vmax.vv v0, v1, v0, v0.t

# CHECK: vmax.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x1c]
vmax.vx v0, v1, a0, v0.t

# CHECK: vmul.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x94]
vmul.vv v0, v1, v0, v0.t

# CHECK: vmul.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x94]
vmul.vx v0, v1, a0, v0.t

# CHECK: vmulh.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x9c]
vmulh.vv v0, v1, v0, v0.t

# CHECK: vmulh.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x9c]
vmulh.vx v0, v1, a0, v0.t

# CHECK: vmulhu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x90]
vmulhu.vv v0, v1, v0, v0.t

# CHECK: vmulhu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x90]
vmulhu.vx v0, v1, a0, v0.t

# CHECK: vmulhsu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x98]
vmulhsu.vv v0, v1, v0, v0.t

# CHECK: vmulhsu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x98]
vmulhsu.vx v0, v1, a0, v0.t

# CHECK: vdivu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x80]
vdivu.vv v0, v1, v0, v0.t

# CHECK: vdivu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x80]
vdivu.vx v0, v1, a0, v0.t

# CHECK: vdiv.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x84]
vdiv.vv v0, v1, v0, v0.t

# CHECK: vdiv.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x84]
vdiv.vx v0, v1, a0, v0.t

# CHECK: vremu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x88]
vremu.vv v0, v1, v0, v0.t

# CHECK: vremu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x88]
vremu.vx v0, v1, a0, v0.t

# CHECK: vrem.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x8c]
vrem.vv v0, v1, v0, v0.t

# CHECK: vrem.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x8c]
vrem.vx v0, v1, a0, v0.t

# CHECK: vwmul.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xec]
vwmul.vv v0, v1, v0, v0.t

# CHECK: vwmul.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xec]
vwmul.vx v0, v1, a0, v0.t

# CHECK: vwmulu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xe0]
vwmulu.vv v0, v1, v0, v0.t

# CHECK: vwmulu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xe0]
vwmulu.vx v0, v1, a0, v0.t

# CHECK: vwmulsu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0xe8]
vwmulsu.vv v0, v1, v0, v0.t

# CHECK: vwmulsu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0xe8]
vwmulsu.vx v0, v1, a0, v0.t

# CHECK: vmacc.vv v0, v0, v1, v0.t
[0x57,0x20,0x10,0xb4]
vmacc.vv v0, v0, v1, v0.t

# CHECK: vmacc.vx v0, a0, v1, v0.t
[0x57,0x60,0x15,0xb4]
vmacc.vx v0, a0, v1, v0.t

# CHECK: vnmsac.vv v0, v0, v1, v0.t
[0x57,0x20,0x10,0xbc]
vnmsac.vv v0, v0, v1, v0.t

# CHECK: vnmsac.vx v0, a0, v1, v0.t
[0x57,0x60,0x15,0xbc]
vnmsac.vx v0, a0, v1, v0.t

# CHECK: vmadd.vv v0, v0, v1, v0.t
[0x57,0x20,0x10,0xa4]
vmadd.vv v0, v0, v1, v0.t

# CHECK: vmadd.vx v0, a0, v1, v0.t
[0x57,0x60,0x15,0xa4]
vmadd.vx v0, a0, v1, v0.t

# CHECK: vnmsub.vv v0, v0, v1, v0.t
[0x57,0x20,0x10,0xac]
vnmsub.vv v0, v0, v1, v0.t

# CHECK: vnmsub.vx v0, a0, v1, v0.t
[0x57,0x60,0x15,0xac]
vnmsub.vx v0, a0, v1, v0.t

# CHECK: vwmaccu.vv v0, v0, v1, v0.t
[0x57,0x20,0x10,0xf0]
vwmaccu.vv v0, v0, v1, v0.t

# CHECK: vwmaccu.vx v0, a0, v1, v0.t
[0x57,0x60,0x15,0xf0]
vwmaccu.vx v0, a0, v1, v0.t

# CHECK: vwmacc.vv v0, v0, v1, v0.t
[0x57,0x20,0x10,0xf4]
vwmacc.vv v0, v0, v1, v0.t

# CHECK: vwmacc.vx v0, a0, v1, v0.t
[0x57,0x60,0x15,0xf4]
vwmacc.vx v0, a0, v1, v0.t

# CHECK: vwmaccsu.vv v0, v0, v1, v0.t
[0x57,0x20,0x10,0xfc]
vwmaccsu.vv v0, v0, v1, v0.t

# CHECK: vwmaccsu.vx v0, a0, v1, v0.t
[0x57,0x60,0x15,0xfc]
vwmaccsu.vx v0, a0, v1, v0.t

# CHECK: vwmaccus.vx v0, a0, v1, v0.t
[0x57,0x60,0x15,0xf8]
vwmaccus.vx v0, a0, v1, v0.t

# CHECK: vqmaccu.vv v0, v0, v1, v0.t
[0x57,0x00,0x10,0xf0]
vqmaccu.vv v0, v0, v1, v0.t

# CHECK: vqmaccu.vx v0, a0, v1, v0.t
[0x57,0x40,0x15,0xf0]
vqmaccu.vx v0, a0, v1, v0.t

# CHECK: vqmacc.vv v0, v0, v1, v0.t
[0x57,0x00,0x10,0xf4]
vqmacc.vv v0, v0, v1, v0.t

# CHECK: vqmacc.vx v0, a0, v1, v0.t
[0x57,0x40,0x15,0xf4]
vqmacc.vx v0, a0, v1, v0.t

# CHECK: vqmaccsu.vv v0, v0, v1, v0.t
[0x57,0x00,0x10,0xfc]
vqmaccsu.vv v0, v0, v1, v0.t

# CHECK: vqmaccsu.vx v0, a0, v1, v0.t
[0x57,0x40,0x15,0xfc]
vqmaccsu.vx v0, a0, v1, v0.t

# CHECK: vqmaccus.vx v0, a0, v1, v0.t
[0x57,0x40,0x15,0xf8]
vqmaccus.vx v0, a0, v1, v0.t

# CHECK: vsaddu.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x80]
vsaddu.vv v0, v1, v0, v0.t

# CHECK: vsaddu.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x80]
vsaddu.vx v0, v1, a0, v0.t

# CHECK: vsaddu.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x80]
vsaddu.vi v0, v1, 0, v0.t

# CHECK: vsadd.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x84]
vsadd.vv v0, v1, v0, v0.t

# CHECK: vsadd.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x84]
vsadd.vx v0, v1, a0, v0.t

# CHECK: vsadd.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x84]
vsadd.vi v0, v1, 0, v0.t

# CHECK: vssubu.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x88]
vssubu.vv v0, v1, v0, v0.t

# CHECK: vssubu.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x88]
vssubu.vx v0, v1, a0, v0.t

# CHECK: vssub.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x8c]
vssub.vv v0, v1, v0, v0.t

# CHECK: vssub.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x8c]
vssub.vx v0, v1, a0, v0.t

# CHECK: vaaddu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x20]
vaaddu.vv v0, v1, v0, v0.t

# CHECK: vaaddu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x20]
vaaddu.vx v0, v1, a0, v0.t

# CHECK: vaadd.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x24]
vaadd.vv v0, v1, v0, v0.t

# CHECK: vaadd.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x24]
vaadd.vx v0, v1, a0, v0.t

# CHECK: vasubu.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x28]
vasubu.vv v0, v1, v0, v0.t

# CHECK: vasubu.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x28]
vasubu.vx v0, v1, a0, v0.t

# CHECK: vasub.vv v0, v1, v0, v0.t
[0x57,0x20,0x10,0x2c]
vasub.vv v0, v1, v0, v0.t

# CHECK: vasub.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x2c]
vasub.vx v0, v1, a0, v0.t

# CHECK: vsmul.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x9c]
vsmul.vv v0, v1, v0, v0.t

# CHECK: vsmul.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x9c]
vsmul.vx v0, v1, a0, v0.t

# CHECK: vssrl.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xa8]
vssrl.vv v0, v1, v0, v0.t

# CHECK: vssrl.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0xa8]
vssrl.vx v0, v1, a0, v0.t

# CHECK: vssrl.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0xa8]
vssrl.vi v0, v1, 0, v0.t

# CHECK: vssra.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xac]
vssra.vv v0, v1, v0, v0.t

# CHECK: vssra.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0xac]
vssra.vx v0, v1, a0, v0.t

# CHECK: vssra.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0xac]
vssra.vi v0, v1, 0, v0.t

# CHECK: vnclipu.wv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xb8]
vnclipu.wv v0, v1, v0, v0.t

# CHECK: vnclipu.wx v0, v1, a0, v0.t
[0x57,0x40,0x15,0xb8]
vnclipu.wx v0, v1, a0, v0.t

# CHECK: vnclipu.wi v0, v1, 0, v0.t
[0x57,0x30,0x10,0xb8]
vnclipu.wi v0, v1, 0, v0.t

# CHECK: vnclip.wv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xbc]
vnclip.wv v0, v1, v0, v0.t

# CHECK: vnclip.wx v0, v1, a0, v0.t
[0x57,0x40,0x15,0xbc]
vnclip.wx v0, v1, a0, v0.t

# CHECK: vnclip.wi v0, v1, 0, v0.t
[0x57,0x30,0x10,0xbc]
vnclip.wi v0, v1, 0, v0.t

# CHECK: vfadd.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x00]
vfadd.vv v0, v1, v0, v0.t

# CHECK: vfadd.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x00]
vfadd.vf v0, v1, ft0, v0.t

# CHECK: vfsub.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x08]
vfsub.vv v0, v1, v0, v0.t

# CHECK: vfsub.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x08]
vfsub.vf v0, v1, ft0, v0.t

# CHECK: vfrsub.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x9c]
vfrsub.vf v0, v1, ft0, v0.t

# CHECK: vfwadd.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0xc0]
vfwadd.vv v0, v1, v0, v0.t

# CHECK: vfwadd.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0xc0]
vfwadd.vf v0, v1, ft0, v0.t

# CHECK: vfwsub.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0xc8]
vfwsub.vv v0, v1, v0, v0.t

# CHECK: vfwsub.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0xc8]
vfwsub.vf v0, v1, ft0, v0.t

# CHECK: vfwadd.wv v0, v1, v0, v0.t
[0x57,0x10,0x10,0xd0]
vfwadd.wv v0, v1, v0, v0.t

# CHECK: vfwadd.wf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0xd0]
vfwadd.wf v0, v1, ft0, v0.t

# CHECK: vfwsub.wv v0, v1, v0, v0.t
[0x57,0x10,0x10,0xd8]
vfwsub.wv v0, v1, v0, v0.t

# CHECK: vfwsub.wf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0xd8]
vfwsub.wf v0, v1, ft0, v0.t

# CHECK: vfmul.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x90]
vfmul.vv v0, v1, v0, v0.t

# CHECK: vfmul.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x90]
vfmul.vf v0, v1, ft0, v0.t

# CHECK: vfdiv.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x80]
vfdiv.vv v0, v1, v0, v0.t

# CHECK: vfdiv.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x80]
vfdiv.vf v0, v1, ft0, v0.t

# CHECK: vfrdiv.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x84]
vfrdiv.vf v0, v1, ft0, v0.t

# CHECK: vfwmul.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0xe0]
vfwmul.vv v0, v1, v0, v0.t

# CHECK: vfwmul.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0xe0]
vfwmul.vf v0, v1, ft0, v0.t

# CHECK: vfmacc.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xb0]
vfmacc.vv v0, v0, v1, v0.t

# CHECK: vfmacc.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xb0]
vfmacc.vf v0, ft0, v1, v0.t

# CHECK: vfnmacc.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xb4]
vfnmacc.vv v0, v0, v1, v0.t

# CHECK: vfnmacc.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xb4]
vfnmacc.vf v0, ft0, v1, v0.t

# CHECK: vfmsac.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xb8]
vfmsac.vv v0, v0, v1, v0.t

# CHECK: vfmsac.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xb8]
vfmsac.vf v0, ft0, v1, v0.t

# CHECK: vfnmsac.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xbc]
vfnmsac.vv v0, v0, v1, v0.t

# CHECK: vfnmsac.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xbc]
vfnmsac.vf v0, ft0, v1, v0.t

# CHECK: vfmadd.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xa0]
vfmadd.vv v0, v0, v1, v0.t

# CHECK: vfmadd.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xa0]
vfmadd.vf v0, ft0, v1, v0.t

# CHECK: vfnmadd.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xa4]
vfnmadd.vv v0, v0, v1, v0.t

# CHECK: vfnmadd.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xa4]
vfnmadd.vf v0, ft0, v1, v0.t

# CHECK: vfmsub.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xa8]
vfmsub.vv v0, v0, v1, v0.t

# CHECK: vfmsub.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xa8]
vfmsub.vf v0, ft0, v1, v0.t

# CHECK: vfnmsub.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xac]
vfnmsub.vv v0, v0, v1, v0.t

# CHECK: vfnmsub.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xac]
vfnmsub.vf v0, ft0, v1, v0.t

# CHECK: vfwmacc.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xf0]
vfwmacc.vv v0, v0, v1, v0.t

# CHECK: vfwmacc.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xf0]
vfwmacc.vf v0, ft0, v1, v0.t

# CHECK: vfwnmacc.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xf4]
vfwnmacc.vv v0, v0, v1, v0.t

# CHECK: vfwnmacc.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xf4]
vfwnmacc.vf v0, ft0, v1, v0.t

# CHECK: vfwmsac.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xf8]
vfwmsac.vv v0, v0, v1, v0.t

# CHECK: vfwmsac.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xf8]
vfwmsac.vf v0, ft0, v1, v0.t

# CHECK: vfwnmsac.vv v0, v0, v1, v0.t
[0x57,0x10,0x10,0xfc]
vfwnmsac.vv v0, v0, v1, v0.t

# CHECK: vfwnmsac.vf v0, ft0, v1, v0.t
[0x57,0x50,0x10,0xfc]
vfwnmsac.vf v0, ft0, v1, v0.t

# CHECK: vfsqrt.v v0, v1, v0.t
[0x57,0x10,0x10,0x8c]
vfsqrt.v v0, v1, v0.t

# CHECK: vfmin.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x10]
vfmin.vv v0, v1, v0, v0.t

# CHECK: vfmin.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x10]
vfmin.vf v0, v1, ft0, v0.t

# CHECK: vfmax.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x18]
vfmax.vv v0, v1, v0, v0.t

# CHECK: vfmax.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x18]
vfmax.vf v0, v1, ft0, v0.t

# CHECK: vfsgnj.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x20]
vfsgnj.vv v0, v1, v0, v0.t

# CHECK: vfsgnj.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x20]
vfsgnj.vf v0, v1, ft0, v0.t

# CHECK: vfsgnjn.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x24]
vfsgnjn.vv v0, v1, v0, v0.t

# CHECK: vfsgnjn.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x24]
vfsgnjn.vf v0, v1, ft0, v0.t

# CHECK: vfsgnjx.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x28]
vfsgnjx.vv v0, v1, v0, v0.t

# CHECK: vfsgnjx.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x28]
vfsgnjx.vf v0, v1, ft0, v0.t

# CHECK: vmfeq.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x60]
vmfeq.vv v0, v1, v0, v0.t

# CHECK: vmfeq.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x60]
vmfeq.vf v0, v1, ft0, v0.t

# CHECK: vmfne.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x70]
vmfne.vv v0, v1, v0, v0.t

# CHECK: vmfne.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x70]
vmfne.vf v0, v1, ft0, v0.t

# CHECK: vmflt.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x6c]
vmflt.vv v0, v1, v0, v0.t

# CHECK: vmflt.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x6c]
vmflt.vf v0, v1, ft0, v0.t

# CHECK: vmfle.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0x64]
vmfle.vv v0, v1, v0, v0.t

# CHECK: vmfle.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x64]
vmfle.vf v0, v1, ft0, v0.t

# CHECK: vmfgt.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x74]
vmfgt.vf v0, v1, ft0, v0.t

# CHECK: vmfge.vf v0, v1, ft0, v0.t
[0x57,0x50,0x10,0x7c]
vmfge.vf v0, v1, ft0, v0.t

# CHECK: vfclass.v v0, v1, v0.t
[0x57,0x10,0x18,0x8c]
vfclass.v v0, v1, v0.t

# CHECK: vfcvt.xu.f.v v0, v1, v0.t
[0x57,0x10,0x10,0x88]
vfcvt.xu.f.v v0, v1, v0.t

# CHECK: vfcvt.x.f.v v0, v1, v0.t
[0x57,0x90,0x10,0x88]
vfcvt.x.f.v v0, v1, v0.t

# CHECK: vfcvt.f.xu.v v0, v1, v0.t
[0x57,0x10,0x11,0x88]
vfcvt.f.xu.v v0, v1, v0.t

# CHECK: vfcvt.f.x.v v0, v1, v0.t
[0x57,0x90,0x11,0x88]
vfcvt.f.x.v v0, v1, v0.t

# CHECK: vfwcvt.xu.f.v v0, v1, v0.t
[0x57,0x10,0x14,0x88]
vfwcvt.xu.f.v v0, v1, v0.t

# CHECK: vfwcvt.x.f.v v0, v1, v0.t
[0x57,0x90,0x14,0x88]
vfwcvt.x.f.v v0, v1, v0.t

# CHECK: vfwcvt.f.xu.v v0, v1, v0.t
[0x57,0x10,0x15,0x88]
vfwcvt.f.xu.v v0, v1, v0.t

# CHECK: vfwcvt.f.x.v v0, v1, v0.t
[0x57,0x90,0x15,0x88]
vfwcvt.f.x.v v0, v1, v0.t

# CHECK: vfwcvt.f.f.v v0, v1, v0.t
[0x57,0x10,0x16,0x88]
vfwcvt.f.f.v v0, v1, v0.t

# CHECK: vfncvt.xu.f.w v0, v1, v0.t
[0x57,0x10,0x18,0x88]
vfncvt.xu.f.w v0, v1, v0.t

# CHECK: vfncvt.x.f.w v0, v1, v0.t
[0x57,0x90,0x18,0x88]
vfncvt.x.f.w v0, v1, v0.t

# CHECK: vfncvt.f.xu.w v0, v1, v0.t
[0x57,0x10,0x19,0x88]
vfncvt.f.xu.w v0, v1, v0.t

# CHECK: vfncvt.f.x.w v0, v1, v0.t
[0x57,0x90,0x19,0x88]
vfncvt.f.x.w v0, v1, v0.t

# CHECK: vfncvt.f.f.w v0, v1, v0.t
[0x57,0x10,0x1a,0x88]
vfncvt.f.f.w v0, v1, v0.t

# CHECK: vfncvt.rod.f.f.w v0, v1, v0.t
[0x57,0x90,0x1a,0x88]
vfncvt.rod.f.f.w v0, v1, v0.t

# CHECK: vredsum.vs v0, v1, v0, v0.t
[0x57,0x20,0x10,0x00]
vredsum.vs v0, v1, v0, v0.t

# CHECK: vredmaxu.vs v0, v1, v0, v0.t
[0x57,0x20,0x10,0x18]
vredmaxu.vs v0, v1, v0, v0.t

# CHECK: vredmax.vs v0, v1, v0, v0.t
[0x57,0x20,0x10,0x1c]
vredmax.vs v0, v1, v0, v0.t

# CHECK: vredminu.vs v0, v1, v0, v0.t
[0x57,0x20,0x10,0x10]
vredminu.vs v0, v1, v0, v0.t

# CHECK: vredmin.vs v0, v1, v0, v0.t
[0x57,0x20,0x10,0x14]
vredmin.vs v0, v1, v0, v0.t

# CHECK: vredand.vs v0, v1, v0, v0.t
[0x57,0x20,0x10,0x04]
vredand.vs v0, v1, v0, v0.t

# CHECK: vredor.vs v0, v1, v0, v0.t
[0x57,0x20,0x10,0x08]
vredor.vs v0, v1, v0, v0.t

# CHECK: vredxor.vs v0, v1, v0, v0.t
[0x57,0x20,0x10,0x0c]
vredxor.vs v0, v1, v0, v0.t

# CHECK: vwredsumu.vs v0, v1, v0, v0.t
[0x57,0x00,0x10,0xc0]
vwredsumu.vs v0, v1, v0, v0.t

# CHECK: vwredsum.vs v0, v1, v0, v0.t
[0x57,0x00,0x10,0xc4]
vwredsum.vs v0, v1, v0, v0.t

# CHECK: vfredosum.vs v0, v1, v0, v0.t
[0x57,0x10,0x10,0x0c]
vfredosum.vs v0, v1, v0, v0.t

# CHECK: vfredsum.vs v0, v1, v0, v0.t
[0x57,0x10,0x10,0x04]
vfredsum.vs v0, v1, v0, v0.t

# CHECK: vfredmax.vs v0, v1, v0, v0.t
[0x57,0x10,0x10,0x1c]
vfredmax.vs v0, v1, v0, v0.t

# CHECK: vfredmin.vs v0, v1, v0, v0.t
[0x57,0x10,0x10,0x14]
vfredmin.vs v0, v1, v0, v0.t

# CHECK: vfwredosum.vs v0, v1, v0, v0.t
[0x57,0x10,0x10,0xcc]
vfwredosum.vs v0, v1, v0, v0.t

# CHECK: vfwredsum.vs v0, v1, v0, v0.t
[0x57,0x10,0x10,0xc4]
vfwredsum.vs v0, v1, v0, v0.t

# CHECK: vpopc.m a0, v1, v0.t
[0x57,0x25,0x18,0x40]
vpopc.m a0, v1, v0.t

# CHECK: vfirst.m a0, v1, v0.t
[0x57,0xa5,0x18,0x40]
vfirst.m a0, v1, v0.t

# CHECK: vmsbf.m v0, v1, v0.t
[0x57,0xa0,0x10,0x50]
vmsbf.m v0, v1, v0.t

# CHECK: vmsif.m v0, v1, v0.t
[0x57,0xa0,0x11,0x50]
vmsif.m v0, v1, v0.t

# CHECK: vmsof.m v0, v1, v0.t
[0x57,0x20,0x11,0x50]
vmsof.m v0, v1, v0.t

# CHECK: viota.m v0, v1, v0.t
[0x57,0x20,0x18,0x50]
viota.m v0, v1, v0.t

# CHECK: vid.v v0, v0.t
[0x57,0xa0,0x08,0x50]
vid.v v0, v0.t

# CHECK: vslideup.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x38]
vslideup.vx v0, v1, a0, v0.t

# CHECK: vslideup.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x38]
vslideup.vi v0, v1, 0, v0.t

# CHECK: vslidedown.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x3c]
vslidedown.vx v0, v1, a0, v0.t

# CHECK: vslidedown.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x3c]
vslidedown.vi v0, v1, 0, v0.t

# CHECK: vslide1up.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x38]
vslide1up.vx v0, v1, a0, v0.t

# CHECK: vslide1down.vx v0, v1, a0, v0.t
[0x57,0x60,0x15,0x3c]
vslide1down.vx v0, v1, a0, v0.t

# CHECK: vrgather.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0x30]
vrgather.vv v0, v1, v0, v0.t

# CHECK: vrgather.vx v0, v1, a0, v0.t
[0x57,0x40,0x15,0x30]
vrgather.vx v0, v1, a0, v0.t

# CHECK: vrgather.vi v0, v1, 0, v0.t
[0x57,0x30,0x10,0x30]
vrgather.vi v0, v1, 0, v0.t

# CHECK: vdotu.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xe0]
vdotu.vv v0, v1, v0, v0.t

# CHECK: vdot.vv v0, v1, v0, v0.t
[0x57,0x00,0x10,0xe4]
vdot.vv v0, v1, v0, v0.t

# CHECK: vfdot.vv v0, v1, v0, v0.t
[0x57,0x10,0x10,0xe4]
vfdot.vv v0, v1, v0, v0.t




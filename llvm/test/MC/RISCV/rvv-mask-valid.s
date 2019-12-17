# RUN: llvm-mc %s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s


# CHECK-ASM-AND-OBJ: vlb.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x10]
vlb.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlh.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x10]
vlh.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlw.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x10]
vlw.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlbu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x00]
vlbu.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlhu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x00]
vlhu.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlwu.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x00]
vlwu.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vle.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x00]
vle.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vsb.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x05,0x00]
vsb.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vsh.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x05,0x00]
vsh.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vsw.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x00]
vsw.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vse.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x05,0x00]
vse.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlsb.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x18]
vlsb.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsh.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x18]
vlsh.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsw.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x18]
vlsw.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlsbu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0xc5,0x08]
vlsbu.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlshu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0xc5,0x08]
vlshu.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlswu.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0xc5,0x08]
vlswu.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlse.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0xc5,0x08]
vlse.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssb.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0xc5,0x08]
vssb.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssh.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0xc5,0x08]
vssh.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vssw.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0xc5,0x08]
vssw.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vsse.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0xc5,0x08]
vsse.v v0, 0(a1), a2, v0.t

# CHECK-ASM-AND-OBJ: vlxb.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x1c]
vlxb.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxh.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x1c]
vlxh.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxw.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x1c]
vlxw.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxbu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x25,0x0c]
vlxbu.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxhu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x25,0x0c]
vlxhu.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxwu.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x25,0x0c]
vlxwu.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlxe.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x25,0x0c]
vlxe.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxb.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x0c]
vsxb.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxh.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x0c]
vsxh.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxw.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x0c]
vsxw.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsxe.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x0c]
vsxe.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsuxb.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0x80,0x25,0x1c]
vsuxb.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsuxh.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xd0,0x25,0x1c]
vsuxh.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsuxw.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xe0,0x25,0x1c]
vsuxw.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vsuxe.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding: [0x27,0xf0,0x25,0x1c]
vsuxe.v v0, 0(a1), v2, v0.t

# CHECK-ASM-AND-OBJ: vlbff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x11]
vlbff.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlhff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x11]
vlhff.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlwff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x11]
vlwff.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlbuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0x80,0x05,0x01]
vlbuff.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlhuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xd0,0x05,0x01]
vlhuff.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vlwuff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x01]
vlwuff.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vleff.v v0, 0(a1), v0.t
# CHECK-ASM: encoding: [0x07,0xf0,0x05,0x01]
vleff.v v0, 0(a1), v0.t

# CHECK-ASM-AND-OBJ: vadd.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x00]
vadd.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vadd.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x00]
vadd.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vadd.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x00]
vadd.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vsub.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x08]
vsub.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vsub.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x08]
vsub.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vrsub.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x0c]
vrsub.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vrsub.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x0c]
vrsub.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vwaddu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xc0]
vwaddu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwaddu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xc0]
vwaddu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwsubu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xc8]
vwsubu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwsubu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xc8]
vwsubu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwadd.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xc4]
vwadd.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwadd.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xc4]
vwadd.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwsub.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xcc]
vwsub.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwsub.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xcc]
vwsub.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwaddu.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xd0]
vwaddu.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwaddu.wx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xd0]
vwaddu.wx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwsubu.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xd8]
vwsubu.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwsubu.wx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xd8]
vwsubu.wx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwadd.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xd4]
vwadd.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwadd.wx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xd4]
vwadd.wx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwsub.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xdc]
vwsub.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwsub.wx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xdc]
vwsub.wx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vand.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x24]
vand.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vand.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x24]
vand.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vand.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x24]
vand.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vor.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x28]
vor.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vor.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x28]
vor.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vor.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x28]
vor.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vxor.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x2c]
vxor.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vxor.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x2c]
vxor.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vxor.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x2c]
vxor.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vsll.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x94]
vsll.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vsll.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x94]
vsll.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vsll.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x94]
vsll.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vsrl.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xa0]
vsrl.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vsrl.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xa0]
vsrl.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vsrl.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xa0]
vsrl.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vsra.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xa4]
vsra.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vsra.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xa4]
vsra.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vsra.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xa4]
vsra.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vnsrl.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xb0]
vnsrl.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vnsrl.wx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xb0]
vnsrl.wx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vnsrl.wi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xb0]
vnsrl.wi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vnsra.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xb4]
vnsra.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vnsra.wx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xb4]
vnsra.wx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vnsra.wi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xb4]
vnsra.wi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vmseq.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x60]
vmseq.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmseq.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x60]
vmseq.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmseq.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x60]
vmseq.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vmsne.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x64]
vmsne.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmsne.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x64]
vmsne.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmsne.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x64]
vmsne.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vmsltu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x68]
vmsltu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmsltu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x68]
vmsltu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmslt.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x6c]
vmslt.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmslt.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x6c]
vmslt.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmsleu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x70]
vmsleu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmsleu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x70]
vmsleu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmsleu.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x70]
vmsleu.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vmsle.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x74]
vmsle.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmsle.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x74]
vmsle.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmsle.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x74]
vmsle.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vmsgtu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x78]
vmsgtu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmsgtu.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x78]
vmsgtu.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vmsgt.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x7c]
vmsgt.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmsgt.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x7c]
vmsgt.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vminu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x10]
vminu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vminu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x10]
vminu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmin.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x14]
vmin.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmin.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x14]
vmin.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmaxu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x18]
vmaxu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmaxu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x18]
vmaxu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmax.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x1c]
vmax.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmax.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x1c]
vmax.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmul.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x94]
vmul.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmul.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x94]
vmul.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmulh.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x9c]
vmulh.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmulh.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x9c]
vmulh.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmulhu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x90]
vmulhu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmulhu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x90]
vmulhu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmulhsu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x98]
vmulhsu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmulhsu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x98]
vmulhsu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vdivu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x80]
vdivu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vdivu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x80]
vdivu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vdiv.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x84]
vdiv.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vdiv.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x84]
vdiv.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vremu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x88]
vremu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vremu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x88]
vremu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vrem.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x8c]
vrem.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vrem.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x8c]
vrem.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwmul.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xec]
vwmul.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwmul.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xec]
vwmul.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwmulu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xe0]
vwmulu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwmulu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xe0]
vwmulu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vwmulsu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xe8]
vwmulsu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwmulsu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xe8]
vwmulsu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vmacc.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xb4]
vmacc.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vmacc.vx v0, a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xb4]
vmacc.vx v0, a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vnmsac.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xbc]
vnmsac.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vnmsac.vx v0, a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xbc]
vnmsac.vx v0, a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vmadd.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xa4]
vmadd.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vmadd.vx v0, a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xa4]
vmadd.vx v0, a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vnmsub.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xac]
vnmsub.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vnmsub.vx v0, a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xac]
vnmsub.vx v0, a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vwmaccu.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xf0]
vwmaccu.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vwmaccu.vx v0, a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xf0]
vwmaccu.vx v0, a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vwmacc.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xf4]
vwmacc.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vwmacc.vx v0, a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xf4]
vwmacc.vx v0, a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vwmaccsu.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0xf8]
vwmaccsu.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vwmaccsu.vx v0, a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xf8]
vwmaccsu.vx v0, a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vwmaccus.vx v0, a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0xfc]
vwmaccus.vx v0, a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vsaddu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x80]
vsaddu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vsaddu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x80]
vsaddu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vsaddu.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x80]
vsaddu.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vsadd.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x84]
vsadd.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vsadd.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x84]
vsadd.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vsadd.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x84]
vsadd.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vssubu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x88]
vssubu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vssubu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x88]
vssubu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vssub.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x8c]
vssub.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vssub.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x8c]
vssub.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vaaddu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x20]
vaaddu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vaaddu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x20]
vaaddu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vaadd.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x24]
vaadd.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vaadd.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x24]
vaadd.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vasubu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x28]
vasubu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vasubu.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x28]
vasubu.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vasub.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x2c]
vasub.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vasub.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x2c]
vasub.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vsmul.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x9c]
vsmul.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vsmul.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x9c]
vsmul.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vssrl.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xa8]
vssrl.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vssrl.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xa8]
vssrl.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vssrl.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xa8]
vssrl.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vssra.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xac]
vssra.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vssra.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xac]
vssra.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vssra.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xac]
vssra.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vnclipu.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xb8]
vnclipu.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vnclipu.wx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xb8]
vnclipu.wx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vnclipu.wi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xb8]
vnclipu.wi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vnclip.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xbc]
vnclip.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vnclip.wx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0xbc]
vnclip.wx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vnclip.wi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0xbc]
vnclip.wi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vfadd.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x00]
vfadd.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfadd.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x00]
vfadd.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfsub.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x08]
vfsub.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfsub.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x08]
vfsub.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfrsub.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x9c]
vfrsub.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfwadd.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xc0]
vfwadd.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfwadd.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xc0]
vfwadd.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfwsub.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xc8]
vfwsub.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfwsub.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xc8]
vfwsub.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfwadd.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xd0]
vfwadd.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfwadd.wf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xd0]
vfwadd.wf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfwsub.wv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xd8]
vfwsub.wv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfwsub.wf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xd8]
vfwsub.wf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfmul.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x90]
vfmul.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfmul.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x90]
vfmul.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfdiv.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x80]
vfdiv.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfdiv.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x80]
vfdiv.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfrdiv.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x84]
vfrdiv.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfwmul.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xe0]
vfwmul.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfwmul.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xe0]
vfwmul.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfmacc.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xb0]
vfmacc.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfmacc.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xb0]
vfmacc.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfnmacc.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xb4]
vfnmacc.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfnmacc.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xb4]
vfnmacc.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfmsac.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xb8]
vfmsac.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfmsac.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xb8]
vfmsac.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfnmsac.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xbc]
vfnmsac.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfnmsac.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xbc]
vfnmsac.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfmadd.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xa0]
vfmadd.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfmadd.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xa0]
vfmadd.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfnmadd.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xa4]
vfnmadd.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfnmadd.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xa4]
vfnmadd.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfmsub.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xa8]
vfmsub.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfmsub.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xa8]
vfmsub.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfnmsub.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xac]
vfnmsub.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfnmsub.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xac]
vfnmsub.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwmacc.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xf0]
vfwmacc.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwmacc.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xf0]
vfwmacc.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwnmacc.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xf4]
vfwnmacc.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwnmacc.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xf4]
vfwnmacc.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwmsac.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xf8]
vfwmsac.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwmsac.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xf8]
vfwmsac.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwnmsac.vv v0, v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xfc]
vfwnmsac.vv v0, v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwnmsac.vf v0, ft0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0xfc]
vfwnmsac.vf v0, ft0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfsqrt.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x8c]
vfsqrt.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfmin.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x10]
vfmin.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfmin.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x10]
vfmin.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfmax.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x18]
vfmax.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfmax.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x18]
vfmax.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfsgnj.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x20]
vfsgnj.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfsgnj.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x20]
vfsgnj.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfsgnjn.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x24]
vfsgnjn.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfsgnjn.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x24]
vfsgnjn.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfsgnjx.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x28]
vfsgnjx.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfsgnjx.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x28]
vfsgnjx.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vmfeq.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x60]
vmfeq.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmfeq.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x60]
vmfeq.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vmfne.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x70]
vmfne.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmfne.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x70]
vmfne.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vmflt.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x6c]
vmflt.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmflt.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x6c]
vmflt.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vmfle.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x64]
vmfle.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmfle.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x64]
vmfle.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vmfgt.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x74]
vmfgt.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vmfge.vf v0, v1, ft0, v0.t
# CHECK-ASM: encoding: [0x57,0x50,0x10,0x7c]
vmfge.vf v0, v1, ft0, v0.t

# CHECK-ASM-AND-OBJ: vfclass.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x18,0x8c]
vfclass.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfcvt.xu.f.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x88]
vfcvt.xu.f.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfcvt.x.f.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x90,0x10,0x88]
vfcvt.x.f.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfcvt.f.xu.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x11,0x88]
vfcvt.f.xu.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfcvt.f.x.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x90,0x11,0x88]
vfcvt.f.x.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwcvt.xu.f.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x14,0x88]
vfwcvt.xu.f.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwcvt.x.f.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x90,0x14,0x88]
vfwcvt.x.f.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwcvt.f.xu.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x15,0x88]
vfwcvt.f.xu.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwcvt.f.x.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x90,0x15,0x88]
vfwcvt.f.x.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfwcvt.f.f.v v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x16,0x88]
vfwcvt.f.f.v v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfncvt.xu.f.w v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x18,0x88]
vfncvt.xu.f.w v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfncvt.x.f.w v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x90,0x18,0x88]
vfncvt.x.f.w v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfncvt.f.xu.w v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x19,0x88]
vfncvt.f.xu.w v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfncvt.f.x.w v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x90,0x19,0x88]
vfncvt.f.x.w v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfncvt.f.f.w v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x1a,0x88]
vfncvt.f.f.w v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfncvt.rod.f.f.w v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x90,0x1a,0x88]
vfncvt.rod.f.f.w v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vredsum.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x00]
vredsum.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vredmaxu.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x18]
vredmaxu.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vredmax.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x1c]
vredmax.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vredminu.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x10]
vredminu.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vredmin.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x14]
vredmin.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vredand.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x04]
vredand.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vredor.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x08]
vredor.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vredxor.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x0c]
vredxor.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwredsumu.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xc0]
vwredsumu.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vwredsum.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xc4]
vwredsum.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfredosum.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x0c]
vfredosum.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfredsum.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x04]
vfredsum.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfredmax.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x1c]
vfredmax.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfredmin.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0x14]
vfredmin.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfwredosum.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xcc]
vfwredosum.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfwredsum.vs v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xc4]
vfwredsum.vs v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmand.mm v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x64]
vmand.mm v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmnand.mm v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x74]
vmnand.mm v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmandnot.mm v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x60]
vmandnot.mm v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmxor.mm v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x6c]
vmxor.mm v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmor.mm v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x68]
vmor.mm v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmnor.mm v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x78]
vmnor.mm v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmornot.mm v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x70]
vmornot.mm v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vmxnor.mm v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x10,0x7c]
vmxnor.mm v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vpopc.m a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x25,0x18,0x40]
vpopc.m a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vfirst.m a0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0xa5,0x18,0x40]
vfirst.m a0, v1, v0.t

# CHECK-ASM-AND-OBJ: vmsbf.m v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0xa0,0x10,0x50]
vmsbf.m v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vmsif.m v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0xa0,0x11,0x50]
vmsif.m v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vmsof.m v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x11,0x50]
vmsof.m v0, v1, v0.t

# CHECK-ASM-AND-OBJ: viota.m v0, v1, v0.t
# CHECK-ASM: encoding: [0x57,0x20,0x18,0x50]
viota.m v0, v1, v0.t

# CHECK-ASM-AND-OBJ: vid.v v0, v0.t
# CHECK-ASM: encoding: [0x57,0xa0,0x08,0x50]
vid.v v0, v0.t

# CHECK-ASM-AND-OBJ: vslideup.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x38]
vslideup.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vslideup.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x38]
vslideup.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vslidedown.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x3c]
vslidedown.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vslidedown.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x3c]
vslidedown.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vslide1up.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x38]
vslide1up.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vslide1down.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x60,0x15,0x3c]
vslide1down.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vrgather.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x30]
vrgather.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vrgather.vx v0, v1, a0, v0.t
# CHECK-ASM: encoding: [0x57,0x40,0x15,0x30]
vrgather.vx v0, v1, a0, v0.t

# CHECK-ASM-AND-OBJ: vrgather.vi v0, v1, 0, v0.t
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x30]
vrgather.vi v0, v1, 0, v0.t

# CHECK-ASM-AND-OBJ: vdotu.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xe0]
vdotu.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vdot.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xe4]
vdot.vv v0, v1, v0, v0.t

# CHECK-ASM-AND-OBJ: vfdot.vv v0, v1, v0, v0.t
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xe4]
vfdot.vv v0, v1, v0, v0.t


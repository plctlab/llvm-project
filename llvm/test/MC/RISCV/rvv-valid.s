# RUN: llvm-mc %s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s


# CHECK-ASM-AND-OBJ: vsetvl a3, a3, a2
# CHECK-ASM: encoding: [0xd7,0xf6,0xc6,0x80]
vsetvl a3, a3, a2

# CHECK-ASM-AND-OBJ: vsetvli a0, a1, 0
# CHECK-ASM: encoding: [0x57,0xf5,0x05,0x00]
vsetvli a0, a1, 0

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

# CHECK-ASM-AND-OBJ: vdotu.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xe2]
vdotu.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vdot.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0xe6]
vdot.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vfdot.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x10,0x10,0xe6]
vfdot.vv v0, v1, v0

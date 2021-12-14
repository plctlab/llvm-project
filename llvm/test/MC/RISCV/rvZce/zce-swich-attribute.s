## Arch string without version.

# RUN: llvm-mc %s -triple=riscv32 -filetype=asm | FileCheck %s
# RUN: llvm-mc %s -triple=riscv64 -filetype=asm | FileCheck %s

.attribute arch, "rv32i_zce-cmul"
# CHECK: attribute      5, "rv32i2p0_zce-cmul0p50"

.attribute arch, "rv32i_zce-sext"
# CHECK: attribute      5, "rv32i2p0_zce-sext0p50"

.attribute arch, "rv32i_zce-zext"
# CHECK: attribute      5, "rv32i2p0_zce-zext0p50"

.attribute arch, "rv32i_zce-cnot"
# CHECK: attribute      5, "rv32i2p0_zce-cnot0p50"

.attribute arch, "rv32i_zce-cneg"
# CHECK: attribute      5, "rv32i2p0_zce-cneg0p50"

.attribute arch, "rv32i_zce-cmva01s07"
# CHECK: attribute      5, "rv32i2p0_zce-cmva01s070p50"

.attribute arch, "rv32i_zce-muli"
# CHECK: attribute      5, "rv32i2p0_zce-muli0p50"

.attribute arch, "rv32i_zce-beqi"
# CHECK: attribute      5, "rv32i2p0_zce-beqi0p50"

.attribute arch, "rv32i_zce-bnei"
# CHECK: attribute      5, "rv32i2p0_zce-bnei0p50"

.attribute arch, "rv32i_zce-tbljal"
# CHECK: attribute      5, "rv32i2p0_zce-tbljal0p50"

.attribute arch, "rv32i_zce-push-pop"
# CHECK: attribute      5, "rv32i2p0_zce-push-pop0p50"

.attribute arch, "rv32i_zce-pushe-pope"
# CHECK: attribute      5, "rv32i2p0_zce-pushe-pope0p50"

.attribute arch, "rv32i_zce-cpush-cpop"
# CHECK: attribute      5, "rv32i2p0_zce-cpush-cpop0p50"

.attribute arch, "rv32i_zce-cpushe-cpope"
# CHECK: attribute      5, "rv32i2p0_zce-cpushe-cpope0p50"

.attribute arch, "rv32i_zce-push-pop"
# CHECK: attribute      5, "rv32i2p0_zce-push-pop0p50"

.attribute arch, "rv32i_zce-cdecbnez"
# CHECK: attribute      5, "rv32i2p0_zce-cdecbnez0p50"

.attribute arch, "rv32i_zce-decbnez"
# CHECK: attribute      5, "rv32i2p0_zce-decbnez0p50"

.attribute arch, "rv32i_zce-lsgp"
# CHECK: attribute      5, "rv32i2p0_zce-lsgp0p50"

.attribute arch, "rv32i_zce-clbh"
# CHECK: attribute      5, "rv32i2p0_zce-clbh0p50"

.attribute arch, "rv32i_zce-clbhu"
# CHECK: attribute      5, "rv32i2p0_zce-clbhu0p50"

.attribute arch, "rv32i_zce-csbh"
# CHECK: attribute      5, "rv32i2p0_zce-csbh0p50"

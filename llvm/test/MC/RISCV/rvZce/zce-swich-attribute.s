## Arch string without version.

# RUN: llvm-mc %s -triple=riscv32 -filetype=asm | FileCheck %s
# RUN: llvm-mc %s -triple=riscv64 -filetype=asm | FileCheck %s

.attribute arch, "rv32i_zce-muli0p50"
# CHECK: attribute      5, "rv32i2p0_zce-muli0p50"

.attribute arch, "rv32i_zce-beqi0p50"
# CHECK: attribute      5, "rv32i2p0_zce-beqi0p50"

.attribute arch, "rv32i_zce-bnei0p50"
# CHECK: attribute      5, "rv32i2p0_zce-bnei0p50"

.attribute arch, "rv32i_zce-cdecbnez0p50"
# CHECK: attribute      5, "rv32i2p0_zce-cdecbnez0p50"

.attribute arch, "rv32i_zce-decbnez0p50"
# CHECK: attribute      5, "rv32i2p0_zce-decbnez0p50"

.attribute arch, "rv32i_zce-lsgp0p50"
# CHECK: attribute      5, "rv32i2p0_zce-lsgp0p50"

## Arch string without version.

# RUN: llvm-mc %s -triple=riscv32 -filetype=asm | FileCheck %s
# RUN: llvm-mc %s -triple=riscv64 -filetype=asm | FileCheck %s

.attribute arch, "rv32i_zceCmul"
# CHECK: attribute      5, "rv32i2p0_zceCmul"

.attribute arch, "rv32i_zceSext"
# CHECK: attribute      5, "rv32i2p0_zceSext"

.attribute arch, "rv32i_zceZext"
# CHECK: attribute      5, "rv32i2p0_zceZext"

.attribute arch, "rv32i_zceCNot"
# CHECK: attribute      5, "rv32i2p0_zceCNot"

.attribute arch, "rv32i_zceCNeg"
# CHECK: attribute      5, "rv32i2p0_zceCNeg"

.attribute arch, "rv32i_zceCMva01s07"
# CHECK: attribute      5, "rv32i2p0_zceCMva01s07"

.attribute arch, "rv32i_zceMuli"
# CHECK: attribute      5, "rv32i2p0_zceMuli"

.attribute arch, "rv32i_zceBeqi"
# CHECK: attribute      5, "rv32i2p0_zceBeqi"

.attribute arch, "rv32i_zceBnei"
# CHECK: attribute      5, "rv32i2p0_zceBnei"

.attribute arch, "rv32i_zceTbljal"
# CHECK: attribute      5, "rv32i2p0_zceTbljal"

.attribute arch, "rv32i_zcePushPop"
# CHECK: attribute      5, "rv32i2p0_zcePushPop"

.attribute arch, "rv32i_zcePushEPopE"
# CHECK: attribute      5, "rv32i2p0_zcePushEPopE"

.attribute arch, "rv32i_zceCPushCPop"
# CHECK: attribute      5, "rv32i2p0_zceCPushCPop"

.attribute arch, "rv32i_zceCPushECPopE"
# CHECK: attribute      5, "rv32i2p0_zceCPushECPopE"

.attribute arch, "rv32i_zcePushPop"
# CHECK: attribute      5, "rv32i2p0_zcePushPop"

.attribute arch, "rv32i_zceCDecbnez"
# CHECK: attribute      5, "rv32i2p0_zceCDecbnez"

.attribute arch, "rv32i_zceDecbnez"
# CHECK: attribute      5, "rv32i2p0_zceDecbnez"

.attribute arch, "rv32i_zceLsgp"
# CHECK: attribute      5, "rv32i2p0_zceLsgp"

.attribute arch, "rv32i_zceClbh"
# CHECK: attribute      5, "rv32i2p0_zceClbh"

.attribute arch, "rv32i_zceClbhu"
# CHECK: attribute      5, "rv32i2p0_zceClbhu"

.attribute arch, "rv32i_zceCsbh"
# CHECK: attribute      5, "rv32i2p0_zceCsbh"

;; Generate ELF attributes from llc.

; RUN: llc -mtriple=riscv32 -mattr=+m %s -o - | FileCheck --check-prefix=RV32M %s
; RUN: llc -mtriple=riscv32 -mattr=+a %s -o - | FileCheck --check-prefix=RV32A %s
; RUN: llc -mtriple=riscv32 -mattr=+f %s -o - | FileCheck --check-prefix=RV32F %s
; RUN: llc -mtriple=riscv32 -mattr=+d %s -o - | FileCheck --check-prefix=RV32D %s
; RUN: llc -mtriple=riscv32 -mattr=+c %s -o - | FileCheck --check-prefix=RV32C %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-b %s -o - | FileCheck --check-prefix=RV32B %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-v,+experimental-zvamo,+experimental-zvlsseg %s -o - | FileCheck --check-prefix=RV32V %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zfh %s -o - | FileCheck --check-prefix=RV32ZFH %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zba %s -o - | FileCheck --check-prefix=RV32ZBA %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbb %s -o - | FileCheck --check-prefix=RV32ZBB %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbc %s -o - | FileCheck --check-prefix=RV32ZBC %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbe %s -o - | FileCheck --check-prefix=RV32ZBE %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbf %s -o - | FileCheck --check-prefix=RV32ZBF %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbm %s -o - | FileCheck --check-prefix=RV32ZBM %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbp %s -o - | FileCheck --check-prefix=RV32ZBP %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbproposedc %s -o - | FileCheck --check-prefix=RV32ZBPROPOSEDC %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbr %s -o - | FileCheck --check-prefix=RV32ZBR %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbs %s -o - | FileCheck --check-prefix=RV32ZBS %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbt %s -o - | FileCheck --check-prefix=RV32ZBT %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-k %s -o - | FileCheck --check-prefix=RV32K %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zkb %s -o - | FileCheck --check-prefix=RV32ZKB %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zkg %s -o - | FileCheck --check-prefix=RV32ZKG %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zkN %s -o - | FileCheck --check-prefix=RV32ZKN %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zknd %s -o - | FileCheck --check-prefix=RV32ZKND %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zkne %s -o - | FileCheck --check-prefix=RV32ZKNE %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zknh %s -o - | FileCheck --check-prefix=RV32ZKNH %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zkr %s -o - | FileCheck --check-prefix=RV32ZKR %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zks %s -o - | FileCheck --check-prefix=RV32ZKS %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zksh %s -o - | FileCheck --check-prefix=RV32ZKSH %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zksed %s -o - | FileCheck --check-prefix=RV32ZKSED %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbb,+experimental-zfh,+experimental-zvamo,+experimental-v,+f,+experimental-zvlsseg %s -o - | FileCheck --check-prefix=RV32COMBINED %s
; RUN: llc -mtriple=riscv64 -mattr=+m %s -o - | FileCheck --check-prefix=RV64M %s
; RUN: llc -mtriple=riscv64 -mattr=+a %s -o - | FileCheck --check-prefix=RV64A %s
; RUN: llc -mtriple=riscv64 -mattr=+f %s -o - | FileCheck --check-prefix=RV64F %s
; RUN: llc -mtriple=riscv64 -mattr=+d %s -o - | FileCheck --check-prefix=RV64D %s
; RUN: llc -mtriple=riscv64 -mattr=+c %s -o - | FileCheck --check-prefix=RV64C %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-b %s -o - | FileCheck --check-prefix=RV64B %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-v,+experimental-zvamo,+experimental-zvlsseg %s -o - | FileCheck --check-prefix=RV64V %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zfh %s -o - | FileCheck --check-prefix=RV64ZFH %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zba %s -o - | FileCheck --check-prefix=RV64ZBA %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbb %s -o - | FileCheck --check-prefix=RV64ZBB %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbc %s -o - | FileCheck --check-prefix=RV64ZBC %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbe %s -o - | FileCheck --check-prefix=RV64ZBE %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbf %s -o - | FileCheck --check-prefix=RV64ZBF %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbm %s -o - | FileCheck --check-prefix=RV64ZBM %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbp %s -o - | FileCheck --check-prefix=RV64ZBP %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbproposedc %s -o - | FileCheck --check-prefix=RV64ZBPROPOSEDC %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbr %s -o - | FileCheck --check-prefix=RV64ZBR %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbs %s -o - | FileCheck --check-prefix=RV64ZBS %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbt %s -o - | FileCheck --check-prefix=RV64ZBT %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-k %s -o - | FileCheck --check-prefix=RV64K %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zkb %s -o - | FileCheck --check-prefix=RV64ZKB %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zkg %s -o - | FileCheck --check-prefix=RV64ZKG %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zkN %s -o - | FileCheck --check-prefix=RV64ZKN %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zknd %s -o - | FileCheck --check-prefix=RV64ZKND %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zkne %s -o - | FileCheck --check-prefix=RV64ZKNE %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zknh %s -o - | FileCheck --check-prefix=RV64ZKNH %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zkr %s -o - | FileCheck --check-prefix=RV64ZKR %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zks %s -o - | FileCheck --check-prefix=RV64ZKS %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zksh %s -o - | FileCheck --check-prefix=RV64ZKSH %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zksed %s -o - | FileCheck --check-prefix=RV64ZKSED %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbb,+experimental-zfh,+experimental-zvamo,+experimental-v,+f,+experimental-zvlsseg %s -o - | FileCheck --check-prefix=RV64COMBINED %s

; RV32M: .attribute 5, "rv32i2p0_m2p0"
; RV32A: .attribute 5, "rv32i2p0_a2p0"
; RV32F: .attribute 5, "rv32i2p0_f2p0"
; RV32D: .attribute 5, "rv32i2p0_f2p0_d2p0"
; RV32C: .attribute 5, "rv32i2p0_c2p0"
; RV32B: .attribute 5, "rv32i2p0_b0p93_zba0p93_zbb0p93_zbc0p93_zbe0p93_zbf0p93_zbm0p93_zbp0p93_zbr0p93_zbs0p93_zbt0p93"
; RV32V: .attribute 5, "rv32i2p0_v0p10_zvamo0p10_zvlsseg0p10"
; RV32ZFH: .attribute 5, "rv32i2p0_f2p0_zfh0p1"
; RV32ZBA: .attribute 5, "rv32i2p0_zba0p93"
; RV32ZBB: .attribute 5, "rv32i2p0_zbb0p93"
; RV32ZBC: .attribute 5, "rv32i2p0_zbc0p93"
; RV32ZBE: .attribute 5, "rv32i2p0_zbe0p93"
; RV32ZBF: .attribute 5, "rv32i2p0_zbf0p93"
; RV32ZBM: .attribute 5, "rv32i2p0_zbm0p93"
; RV32ZBP: .attribute 5, "rv32i2p0_zbp0p93"
; RV32ZBPROPOSEDC: .attribute 5, "rv32i2p0_zbproposedc0p93"
; RV32ZBR: .attribute 5, "rv32i2p0_zbr0p93"
; RV32ZBS: .attribute 5, "rv32i2p0_zbs0p93"
; RV32ZBT: .attribute 5, "rv32i2p0_zbt0p93"
; RV32K: .attribute 5, "rv32i2p0_zbc0p93_zbp0p93_k0p9_zkb0p9_zkg0p9_zkn0p9_zknd0p9_zkne0p9_zknh0p9_zkr0p9"
; RV32ZKB: .attribute 5, "rv32i2p0_zbp0p93_zkb0p9"
; RV32ZKG: .attribute 5, "rv32i2p0_zbc0p93_zkg0p9"
; RV32ZKN: .attribute 5, "rv32i2p0_zbc0p93_zbp0p93_zkb0p9_zkg0p9_zkn0p9_zknd0p9_zkne0p9_zknh0p9"
; RV32ZKND: .attribute 5, "rv32i2p0_zknd0p9"
; RV32ZKNE: .attribute 5, "rv32i2p0_zkne0p9"
; RV32ZKNH: .attribute 5, "rv32i2p0_zknh0p9"
; RV32ZKR: .attribute 5, "rv32i2p0_zkr0p9"
; RV32ZKS: .attribute 5, "rv32i2p0_zbc0p93_zbp0p93_zkb0p9_zkg0p9_zks0p9_zksh0p9_zksed0p9"
; RV32ZKSH: .attribute 5, "rv32i2p0_zksh0p9"
; RV32ZKSED: .attribute 5, "rv32i2p0_zksed0p9"
; RV32COMBINED: .attribute 5, "rv32i2p0_f2p0_v0p10_zfh0p1_zbb0p93_zvamo0p10_zvlsseg0p10"

; RV64M: .attribute 5, "rv64i2p0_m2p0"
; RV64A: .attribute 5, "rv64i2p0_a2p0"
; RV64F: .attribute 5, "rv64i2p0_f2p0"
; RV64D: .attribute 5, "rv64i2p0_f2p0_d2p0"
; RV64C: .attribute 5, "rv64i2p0_c2p0"
; RV64B: .attribute 5, "rv64i2p0_b0p93_zba0p93_zbb0p93_zbc0p93_zbe0p93_zbf0p93_zbm0p93_zbp0p93_zbr0p93_zbs0p93_zbt0p93"
; RV64ZFH: .attribute 5, "rv64i2p0_f2p0_zfh0p1"
; RV64ZBA: .attribute 5, "rv64i2p0_zba0p93"
; RV64ZBB: .attribute 5, "rv64i2p0_zbb0p93"
; RV64ZBC: .attribute 5, "rv64i2p0_zbc0p93"
; RV64ZBE: .attribute 5, "rv64i2p0_zbe0p93"
; RV64ZBF: .attribute 5, "rv64i2p0_zbf0p93"
; RV64ZBM: .attribute 5, "rv64i2p0_zbm0p93"
; RV64ZBP: .attribute 5, "rv64i2p0_zbp0p93"
; RV64ZBPROPOSEDC: .attribute 5, "rv64i2p0_zbproposedc0p93"
; RV64ZBR: .attribute 5, "rv64i2p0_zbr0p93"
; RV64ZBS: .attribute 5, "rv64i2p0_zbs0p93"
; RV64ZBT: .attribute 5, "rv64i2p0_zbt0p93"
; RV64V: .attribute 5, "rv64i2p0_v0p10_zvamo0p10_zvlsseg0p10"
; RV64K: .attribute 5, "rv64i2p0_zbc0p93_zbp0p93_k0p9_zkb0p9_zkg0p9_zkn0p9_zknd0p9_zkne0p9_zknh0p9_zkr0p9"
; RV64ZKB: .attribute 5, "rv64i2p0_zbp0p93_zkb0p9"
; RV64ZKG: .attribute 5, "rv64i2p0_zbc0p93_zkg0p9"
; RV64ZKN: .attribute 5, "rv64i2p0_zbc0p93_zbp0p93_zkb0p9_zkg0p9_zkn0p9_zknd0p9_zkne0p9_zknh0p9"
; RV64ZKND: .attribute 5, "rv64i2p0_zknd0p9"
; RV64ZKNE: .attribute 5, "rv64i2p0_zkne0p9"
; RV64ZKNH: .attribute 5, "rv64i2p0_zknh0p9"
; RV64ZKR: .attribute 5, "rv64i2p0_zkr0p9"
; RV64ZKS: .attribute 5, "rv64i2p0_zbc0p93_zbp0p93_zkb0p9_zkg0p9_zks0p9_zksh0p9_zksed0p9"
; RV64ZKSH: .attribute 5, "rv64i2p0_zksh0p9"
; RV64ZKSED: .attribute 5, "rv64i2p0_zksed0p9"
; RV64COMBINED: .attribute 5, "rv64i2p0_f2p0_v0p10_zfh0p1_zbb0p93_zvamo0p10_zvlsseg0p10"


define i32 @addi(i32 %a) {
  %1 = add i32 %a, 1
  ret i32 %1
}

; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32I %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zceb -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32IZce %s
; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64I %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zceb -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64IZce %s

define dso_local i32 @lh(i16 *%a) nounwind {
; RV32I-LABEL: lh:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lh a1, 4(a0)
; RV32I-NEXT:    lh a0, 0(a0)
; RV32I-NEXT:    mv a0, a1
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: lh:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.lh a1, 4(a0)
; RV32IZce-NEXT:    c.lh a0, 0(a0)
; RV32IZce-NEXT:    mv a0, a1
; RV32IZce-NEXT:    ret
  %1 = getelementptr i16, i16* %a, i32 2
  %2 = load i16, i16* %1
  %3 = sext i16 %2 to i32
  ; the unused load will produce an anyext for selection
  %4 = load volatile i16, i16* %a
  ret i32 %3
}

define void @test_load_store(half* %p, half* %q) nounwind {
; RV32I-LABEL: test_load_store:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lh a0, 0(a0)
; RV32I-NEXT:    sh a0, 0(a1)
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: test_load_store:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.lh a0, 0(a0)
; RV32IZce-NEXT:    c.sh a0, 0(a1)
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: test_load_store:
; RV64I:       # %bb.0:
; RV64I-NEXT:    lh a0, 0(a0)
; RV64I-NEXT:    sh a0, 0(a1)
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: test_load_store:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.lh a0, 0(a0)
; RV64IZce-NEXT:    c.sh a0, 0(a1)
; RV64IZce-NEXT:    ret
  %a = load half, half* %p
  store half %a, half* %q
  ret void
}

define <4 x i16> @fold_srem_vec_1(<4 x i16> %x) nounwind {
; RV32I-LABEL: fold_srem_vec_1:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -32
; RV32I-NEXT:    sw ra, 28(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s0, 24(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s1, 20(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s2, 16(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s3, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s4, 8(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s5, 4(sp) # 4-byte Folded Spill
; RV32I-NEXT:    lh s2, 12(a1)
; RV32I-NEXT:    lh s3, 8(a1)
; RV32I-NEXT:    lh s0, 4(a1)
; RV32I-NEXT:    lh a2, 0(a1)
; RV32I-NEXT:    mv s1, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, a2
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s4, a0
; RV32I-NEXT:    addi a1, zero, -124
; RV32I-NEXT:    mv a0, s0
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s5, a0
; RV32I-NEXT:    addi a1, zero, 98
; RV32I-NEXT:    mv a0, s3
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s0, a0
; RV32I-NEXT:    addi a1, zero, -1003
; RV32I-NEXT:    mv a0, s2
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    sh a0, 6(s1)
; RV32I-NEXT:    sh s0, 4(s1)
; RV32I-NEXT:    sh s5, 2(s1)
; RV32I-NEXT:    sh s4, 0(s1)
; RV32I-NEXT:    lw s5, 4(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s4, 8(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s3, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s2, 16(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s1, 20(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s0, 24(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw ra, 28(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 32
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: fold_srem_vec_1:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -32
; RV32IZce-NEXT:    sw ra, 28(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s0, 24(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s1, 20(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s2, 16(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s3, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s4, 8(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s5, 4(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    lh s2, 12(a1)
; RV32IZce-NEXT:    lh s3, 8(a1)
; RV32IZce-NEXT:    c.lh s0, 4(a1)
; RV32IZce-NEXT:    c.lh a2, 0(a1)
; RV32IZce-NEXT:    mv s1, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, a2
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s4, a0
; RV32IZce-NEXT:    addi a1, zero, -124
; RV32IZce-NEXT:    mv a0, s0
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s5, a0
; RV32IZce-NEXT:    addi a1, zero, 98
; RV32IZce-NEXT:    mv a0, s3
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s0, a0
; RV32IZce-NEXT:    addi a1, zero, -1003
; RV32IZce-NEXT:    mv a0, s2
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    c.sh a0, 6(s1)
; RV32IZce-NEXT:    c.sh s0, 4(s1)
; RV32IZce-NEXT:    sh s5, 2(s1)
; RV32IZce-NEXT:    sh s4, 0(s1)
; RV32IZce-NEXT:    lw s5, 4(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s4, 8(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s3, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s2, 16(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s1, 20(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s0, 24(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw ra, 28(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 32
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: fold_srem_vec_1:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -64
; RV64I-NEXT:    sd ra, 56(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s0, 48(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s1, 40(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s2, 32(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s3, 24(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s4, 16(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s5, 8(sp) # 8-byte Folded Spill
; RV64I-NEXT:    lh s2, 24(a1)
; RV64I-NEXT:    lh s3, 16(a1)
; RV64I-NEXT:    lh s0, 8(a1)
; RV64I-NEXT:    lh a2, 0(a1)
; RV64I-NEXT:    mv s1, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, a2
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s4, a0
; RV64I-NEXT:    addi a1, zero, -124
; RV64I-NEXT:    mv a0, s0
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s5, a0
; RV64I-NEXT:    addi a1, zero, 98
; RV64I-NEXT:    mv a0, s3
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s0, a0
; RV64I-NEXT:    addi a1, zero, -1003
; RV64I-NEXT:    mv a0, s2
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    sh a0, 6(s1)
; RV64I-NEXT:    sh s0, 4(s1)
; RV64I-NEXT:    sh s5, 2(s1)
; RV64I-NEXT:    sh s4, 0(s1)
; RV64I-NEXT:    ld s5, 8(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s4, 16(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s3, 24(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s2, 32(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s1, 40(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s0, 48(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld ra, 56(sp) # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 64
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: fold_srem_vec_1:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -64
; RV64IZce-NEXT:    sd ra, 56(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s0, 48(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s1, 40(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s2, 32(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s3, 24(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s4, 16(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s5, 8(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    lh s2, 24(a1)
; RV64IZce-NEXT:    lh s3, 16(a1)
; RV64IZce-NEXT:    c.lh s0, 8(a1)
; RV64IZce-NEXT:    c.lh a2, 0(a1)
; RV64IZce-NEXT:    mv s1, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, a2
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s4, a0
; RV64IZce-NEXT:    addi a1, zero, -124
; RV64IZce-NEXT:    mv a0, s0
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s5, a0
; RV64IZce-NEXT:    addi a1, zero, 98
; RV64IZce-NEXT:    mv a0, s3
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s0, a0
; RV64IZce-NEXT:    addi a1, zero, -1003
; RV64IZce-NEXT:    mv a0, s2
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    c.sh a0, 6(s1)
; RV64IZce-NEXT:    c.sh s0, 4(s1)
; RV64IZce-NEXT:    sh s5, 2(s1)
; RV64IZce-NEXT:    sh s4, 0(s1)
; RV64IZce-NEXT:    ld s5, 8(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s4, 16(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s3, 24(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s2, 32(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s1, 40(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s0, 48(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld ra, 56(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 64
; RV64IZce-NEXT:    ret
  %1 = srem <4 x i16> %x, <i16 95, i16 -124, i16 98, i16 -1003>
  ret <4 x i16> %1
}

define <4 x i16> @fold_srem_vec_2(<4 x i16> %x) nounwind {
; RV32I-LABEL: fold_srem_vec_2:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -32
; RV32I-NEXT:    sw ra, 28(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s0, 24(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s1, 20(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s2, 16(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s3, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s4, 8(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s5, 4(sp) # 4-byte Folded Spill
; RV32I-NEXT:    lh s2, 12(a1)
; RV32I-NEXT:    lh s3, 8(a1)
; RV32I-NEXT:    lh s0, 4(a1)
; RV32I-NEXT:    lh a2, 0(a1)
; RV32I-NEXT:    mv s1, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, a2
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s4, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s0
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s5, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s3
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s0, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s2
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    sh a0, 6(s1)
; RV32I-NEXT:    sh s0, 4(s1)
; RV32I-NEXT:    sh s5, 2(s1)
; RV32I-NEXT:    sh s4, 0(s1)
; RV32I-NEXT:    lw s5, 4(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s4, 8(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s3, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s2, 16(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s1, 20(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s0, 24(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw ra, 28(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 32
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: fold_srem_vec_2:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -32
; RV32IZce-NEXT:    sw ra, 28(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s0, 24(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s1, 20(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s2, 16(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s3, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s4, 8(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s5, 4(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    lh s2, 12(a1)
; RV32IZce-NEXT:    lh s3, 8(a1)
; RV32IZce-NEXT:    c.lh s0, 4(a1)
; RV32IZce-NEXT:    c.lh a2, 0(a1)
; RV32IZce-NEXT:    mv s1, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, a2
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s4, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s0
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s5, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s3
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s0, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s2
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    c.sh a0, 6(s1)
; RV32IZce-NEXT:    c.sh s0, 4(s1)
; RV32IZce-NEXT:    sh s5, 2(s1)
; RV32IZce-NEXT:    sh s4, 0(s1)
; RV32IZce-NEXT:    lw s5, 4(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s4, 8(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s3, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s2, 16(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s1, 20(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s0, 24(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw ra, 28(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 32
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: fold_srem_vec_2:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -64
; RV64I-NEXT:    sd ra, 56(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s0, 48(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s1, 40(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s2, 32(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s3, 24(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s4, 16(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s5, 8(sp) # 8-byte Folded Spill
; RV64I-NEXT:    lh s2, 24(a1)
; RV64I-NEXT:    lh s3, 16(a1)
; RV64I-NEXT:    lh s0, 8(a1)
; RV64I-NEXT:    lh a2, 0(a1)
; RV64I-NEXT:    mv s1, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, a2
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s4, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s0
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s5, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s3
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s0, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s2
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    sh a0, 6(s1)
; RV64I-NEXT:    sh s0, 4(s1)
; RV64I-NEXT:    sh s5, 2(s1)
; RV64I-NEXT:    sh s4, 0(s1)
; RV64I-NEXT:    ld s5, 8(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s4, 16(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s3, 24(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s2, 32(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s1, 40(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s0, 48(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld ra, 56(sp) # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 64
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: fold_srem_vec_2:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -64
; RV64IZce-NEXT:    sd ra, 56(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s0, 48(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s1, 40(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s2, 32(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s3, 24(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s4, 16(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s5, 8(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    lh s2, 24(a1)
; RV64IZce-NEXT:    lh s3, 16(a1)
; RV64IZce-NEXT:    c.lh s0, 8(a1)
; RV64IZce-NEXT:    c.lh a2, 0(a1)
; RV64IZce-NEXT:    mv s1, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, a2
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s4, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s0
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s5, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s3
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s0, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s2
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    c.sh a0, 6(s1)
; RV64IZce-NEXT:    c.sh s0, 4(s1)
; RV64IZce-NEXT:    sh s5, 2(s1)
; RV64IZce-NEXT:    sh s4, 0(s1)
; RV64IZce-NEXT:    ld s5, 8(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s4, 16(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s3, 24(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s2, 32(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s1, 40(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s0, 48(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld ra, 56(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 64
; RV64IZce-NEXT:    ret
  %1 = srem <4 x i16> %x, <i16 95, i16 95, i16 95, i16 95>
  ret <4 x i16> %1
}


; Don't fold if we can combine srem with sdiv.
define <4 x i16> @combine_srem_sdiv(<4 x i16> %x) nounwind {
; RV32I-LABEL: combine_srem_sdiv:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -48
; RV32I-NEXT:    sw ra, 44(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s0, 40(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s1, 36(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s2, 32(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s3, 28(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s4, 24(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s5, 20(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s6, 16(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s7, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s8, 8(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s9, 4(sp) # 4-byte Folded Spill
; RV32I-NEXT:    lh s2, 0(a1)
; RV32I-NEXT:    lh s3, 4(a1)
; RV32I-NEXT:    lh s4, 8(a1)
; RV32I-NEXT:    lh s1, 12(a1)
; RV32I-NEXT:    mv s0, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s1
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s5, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s4
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s6, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s3
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s7, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s2
; RV32I-NEXT:    call __modsi3@plt
; RV32I-NEXT:    mv s8, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s1
; RV32I-NEXT:    call __divsi3@plt
; RV32I-NEXT:    mv s9, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s4
; RV32I-NEXT:    call __divsi3@plt
; RV32I-NEXT:    mv s4, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s3
; RV32I-NEXT:    call __divsi3@plt
; RV32I-NEXT:    mv s1, a0
; RV32I-NEXT:    addi a1, zero, 95
; RV32I-NEXT:    mv a0, s2
; RV32I-NEXT:    call __divsi3@plt
; RV32I-NEXT:    add a0, s8, a0
; RV32I-NEXT:    add a1, s7, s1
; RV32I-NEXT:    add a2, s6, s4
; RV32I-NEXT:    add a3, s5, s9
; RV32I-NEXT:    sh a3, 6(s0)
; RV32I-NEXT:    sh a2, 4(s0)
; RV32I-NEXT:    sh a1, 2(s0)
; RV32I-NEXT:    sh a0, 0(s0)
; RV32I-NEXT:    lw s9, 4(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s8, 8(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s7, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s6, 16(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s5, 20(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s4, 24(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s3, 28(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s2, 32(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s1, 36(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s0, 40(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw ra, 44(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 48
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: combine_srem_sdiv:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -48
; RV32IZce-NEXT:    sw ra, 44(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s0, 40(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s1, 36(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s2, 32(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s3, 28(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s4, 24(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s5, 20(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s6, 16(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s7, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s8, 8(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s9, 4(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    lh s2, 0(a1)
; RV32IZce-NEXT:    lh s3, 4(a1)
; RV32IZce-NEXT:    lh s4, 8(a1)
; RV32IZce-NEXT:    c.lh s1, 12(a1)
; RV32IZce-NEXT:    mv s0, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s1
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s5, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s4
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s6, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s3
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s7, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s2
; RV32IZce-NEXT:    call __modsi3@plt
; RV32IZce-NEXT:    mv s8, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s1
; RV32IZce-NEXT:    call __divsi3@plt
; RV32IZce-NEXT:    mv s9, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s4
; RV32IZce-NEXT:    call __divsi3@plt
; RV32IZce-NEXT:    mv s4, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s3
; RV32IZce-NEXT:    call __divsi3@plt
; RV32IZce-NEXT:    mv s1, a0
; RV32IZce-NEXT:    addi a1, zero, 95
; RV32IZce-NEXT:    mv a0, s2
; RV32IZce-NEXT:    call __divsi3@plt
; RV32IZce-NEXT:    add a0, s8, a0
; RV32IZce-NEXT:    add a1, s7, s1
; RV32IZce-NEXT:    add a2, s6, s4
; RV32IZce-NEXT:    add a3, s5, s9
; RV32IZce-NEXT:    c.sh a3, 6(s0)
; RV32IZce-NEXT:    c.sh a2, 4(s0)
; RV32IZce-NEXT:    c.sh a1, 2(s0)
; RV32IZce-NEXT:    c.sh a0, 0(s0)
; RV32IZce-NEXT:    lw s9, 4(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s8, 8(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s7, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s6, 16(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s5, 20(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s4, 24(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s3, 28(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s2, 32(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s1, 36(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s0, 40(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw ra, 44(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 48
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: combine_srem_sdiv:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -96
; RV64I-NEXT:    sd ra, 88(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s0, 80(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s1, 72(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s2, 64(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s3, 56(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s4, 48(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s5, 40(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s6, 32(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s7, 24(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s8, 16(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s9, 8(sp) # 8-byte Folded Spill
; RV64I-NEXT:    lh s2, 0(a1)
; RV64I-NEXT:    lh s3, 8(a1)
; RV64I-NEXT:    lh s4, 16(a1)
; RV64I-NEXT:    lh s1, 24(a1)
; RV64I-NEXT:    mv s0, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s1
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s5, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s4
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s6, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s3
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s7, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s2
; RV64I-NEXT:    call __moddi3@plt
; RV64I-NEXT:    mv s8, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s1
; RV64I-NEXT:    call __divdi3@plt
; RV64I-NEXT:    mv s9, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s4
; RV64I-NEXT:    call __divdi3@plt
; RV64I-NEXT:    mv s4, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s3
; RV64I-NEXT:    call __divdi3@plt
; RV64I-NEXT:    mv s1, a0
; RV64I-NEXT:    addi a1, zero, 95
; RV64I-NEXT:    mv a0, s2
; RV64I-NEXT:    call __divdi3@plt
; RV64I-NEXT:    add a0, s8, a0
; RV64I-NEXT:    add a1, s7, s1
; RV64I-NEXT:    add a2, s6, s4
; RV64I-NEXT:    add a3, s5, s9
; RV64I-NEXT:    sh a3, 6(s0)
; RV64I-NEXT:    sh a2, 4(s0)
; RV64I-NEXT:    sh a1, 2(s0)
; RV64I-NEXT:    sh a0, 0(s0)
; RV64I-NEXT:    ld s9, 8(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s8, 16(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s7, 24(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s6, 32(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s5, 40(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s4, 48(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s3, 56(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s2, 64(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s1, 72(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s0, 80(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld ra, 88(sp) # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 96
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: combine_srem_sdiv:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -96
; RV64IZce-NEXT:    sd ra, 88(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s0, 80(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s1, 72(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s2, 64(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s3, 56(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s4, 48(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s5, 40(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s6, 32(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s7, 24(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s8, 16(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s9, 8(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    lh s2, 0(a1)
; RV64IZce-NEXT:    lh s3, 8(a1)
; RV64IZce-NEXT:    lh s4, 16(a1)
; RV64IZce-NEXT:    c.lh s1, 24(a1)
; RV64IZce-NEXT:    mv s0, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s1
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s5, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s4
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s6, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s3
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s7, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s2
; RV64IZce-NEXT:    call __moddi3@plt
; RV64IZce-NEXT:    mv s8, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s1
; RV64IZce-NEXT:    call __divdi3@plt
; RV64IZce-NEXT:    mv s9, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s4
; RV64IZce-NEXT:    call __divdi3@plt
; RV64IZce-NEXT:    mv s4, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s3
; RV64IZce-NEXT:    call __divdi3@plt
; RV64IZce-NEXT:    mv s1, a0
; RV64IZce-NEXT:    addi a1, zero, 95
; RV64IZce-NEXT:    mv a0, s2
; RV64IZce-NEXT:    call __divdi3@plt
; RV64IZce-NEXT:    add a0, s8, a0
; RV64IZce-NEXT:    add a1, s7, s1
; RV64IZce-NEXT:    add a2, s6, s4
; RV64IZce-NEXT:    add a3, s5, s9
; RV64IZce-NEXT:    c.sh a3, 6(s0)
; RV64IZce-NEXT:    c.sh a2, 4(s0)
; RV64IZce-NEXT:    c.sh a1, 2(s0)
; RV64IZce-NEXT:    c.sh a0, 0(s0)
; RV64IZce-NEXT:    ld s9, 8(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s8, 16(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s7, 24(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s6, 32(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s5, 40(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s4, 48(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s3, 56(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s2, 64(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s1, 72(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s0, 80(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld ra, 88(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 96
; RV64IZce-NEXT:    ret
  %1 = srem <4 x i16> %x, <i16 95, i16 95, i16 95, i16 95>
  %2 = sdiv <4 x i16> %x, <i16 95, i16 95, i16 95, i16 95>
  %3 = add <4 x i16> %1, %2
  ret <4 x i16> %3
}
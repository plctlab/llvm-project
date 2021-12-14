; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32I %s
; RUN: llc -mtriple=riscv32 -mattr=+zce-clbhu -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32IZce %s
; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64I %s
; RUN: llc -mtriple=riscv64 -mattr=+zce-clbhu -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64IZce %s

define dso_local i32 @lhu(i16 *%a) nounwind {
; RV32I-LABEL: lhu:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lhu a1, 10(a0)
; RV32I-NEXT:    lhu a0, 0(a0)
; RV32I-NEXT:    add a0, a1, a0
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: lhu:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.lhu a1, 10(a0)
; RV32IZce-NEXT:    c.lhu a0, 0(a0)
; RV32IZce-NEXT:    add a0, a1, a0
; RV32IZce-NEXT:    ret
  %1 = getelementptr i16, i16* %a, i32 5
  %2 = load i16, i16* %1
  %3 = zext i16 %2 to i32
  %4 = load volatile i16, i16* %a
  %5 = zext i16 %4 to i32
  %6 = add i32 %3, %5
  ret i32 %6
}

define dso_local i64 @lhu64(i16 *%a) nounwind {
; RV64I-LABEL: lhu:
; RV64I:       # %bb.0:
; RV64I-NEXT:    lhu a1, 10(a0)
; RV64I-NEXT:    lhu a0, 0(a0)
; RV64I-NEXT:    add a0, a1, a0
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: lhu:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.lhu a1, 10(a0)
; RV64IZce-NEXT:    c.lhu a0, 0(a0)
; RV64IZce-NEXT:    add a0, a1, a0
; RV64IZce-NEXT:    ret
  %1 = getelementptr i16, i16* %a, i32 5
  %2 = load i16, i16* %1
  %3 = zext i16 %2 to i64
  %4 = load volatile i16, i16* %a
  %5 = zext i16 %4 to i64
  %6 = add i64 %3, %5
  ret i64 %6
}

define i32 @callee_half_on_stack(i32 %a, i32 %b, i32 %c, i32 %d, i32 %e, i32 %f, i32 %g, i32 %h, half %i) nounwind {
; RV32I-LABEL: callee_half_on_stack:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -16
; RV32I-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    sw s0, 8(sp) # 4-byte Folded Spill
; RV32I-NEXT:    lhu a0, 16(sp)
; RV32I-NEXT:    mv s0, a7
; RV32I-NEXT:    call __gnu_h2f_ieee@plt
; RV32I-NEXT:    call __fixsfsi@plt
; RV32I-NEXT:    add a0, s0, a0
; RV32I-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    lw s0, 8(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 16
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: callee_half_on_stack:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -16
; RV32IZce-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    sw s0, 8(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    lhu a0, 16(sp)
; RV32IZce-NEXT:    mv s0, a7
; RV32IZce-NEXT:    call __gnu_h2f_ieee@plt
; RV32IZce-NEXT:    call __fixsfsi@plt
; RV32IZce-NEXT:    add a0, s0, a0
; RV32IZce-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    lw s0, 8(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 16
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: callee_half_on_stack:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -16
; RV64I-NEXT:    sd ra, 8(sp) # 8-byte Folded Spill
; RV64I-NEXT:    sd s0, 0(sp) # 8-byte Folded Spill
; RV64I-NEXT:    lhu a0, 16(sp)
; RV64I-NEXT:    mv s0, a7
; RV64I-NEXT:    call __gnu_h2f_ieee@plt
; RV64I-NEXT:    call __fixsfdi@plt
; RV64I-NEXT:    addw a0, s0, a0
; RV64I-NEXT:    ld ra, 8(sp) # 8-byte Folded Reload
; RV64I-NEXT:    ld s0, 0(sp) # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 16
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: callee_half_on_stack:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -16
; RV64IZce-NEXT:    sd ra, 8(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    sd s0, 0(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    lhu a0, 16(sp)
; RV64IZce-NEXT:    mv s0, a7
; RV64IZce-NEXT:    call __gnu_h2f_ieee@plt
; RV64IZce-NEXT:    call __fixsfdi@plt
; RV64IZce-NEXT:    addw a0, s0, a0
; RV64IZce-NEXT:    ld ra, 8(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    ld s0, 0(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 16
; RV64IZce-NEXT:    ret
  %1 = fptosi half %i to i32
  %2 = add i32 %h, %1
  ret i32 %2
}

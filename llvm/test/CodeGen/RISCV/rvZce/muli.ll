; RUN: llc -mtriple=riscv32 -mattr=+m -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32IM %s
; RUN: llc -mtriple=riscv32 -mattr=+m,+zce-muli -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32IMMULI %s
; RUN: llc -mtriple=riscv64 -mattr=+m -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64IM %s
; RUN: llc -mtriple=riscv64 -mattr=+m,+zce-muli -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64IMMULI %s

define signext i32 @mulOfTwoParam(i32 %a, i32 %b) #0 {
; RV32IM-LABEL: mulOfTwoParam:
; RV32IM:       # %bb.0:
; RV32IM-NEXT:  addi	sp, sp, -16
; RV32IM-NEXT:	sw	a0, 12(sp)
; RV32IM-NEXT:	sw	a1, 8(sp)
; RV32IM-NEXT:	lw	a0, 12(sp)
; RV32IM-NEXT:	lw	a1, 8(sp)
; RV32IM-NEXT:	mul	a0, a0, a1
; RV32IM-NEXT:	sw	a0, 4(sp)
; RV32IM-NEXT:	lw	a0, 4(sp)
; RV32IM-NEXT:	addi	sp, sp, 16
; RV32IM-NEXT:	ret
;
; RV32IMMULI-LABEL: mulOfTwoParam:
; RV32IMMULI:       # %bb.0:
; RV32IMMULI-NEXT:      addi	sp, sp, -16
; RV32IMMULI-NEXT:    	sw	a0, 12(sp)
; RV32IMMULI-NEXT:    	sw	a1, 8(sp)
; RV32IMMULI-NEXT:    	lw	a0, 12(sp)
; RV32IMMULI-NEXT:    	lw	a1, 8(sp)
; RV32IMMULI-NEXT:    	mul	a0, a0, a1
; RV32IMMULI-NEXT:    	sw	a0, 4(sp)
; RV32IMMULI-NEXT:    	lw	a0, 4(sp)
; RV32IMMULI-NEXT:    	addi	sp, sp, 16
; RV32IMMULI-NEXT:    	ret
;
; RV64IM-LABEL: mulOfTwoParam:
; RV64IM:       # %bb.0:
; RV64IM-NEXT:  addi	sp, sp, -16
; RV64IM-NEXT:	sw	a0, 12(sp)
; RV64IM-NEXT:	sw	a1, 8(sp)
; RV64IM-NEXT:	lw	a0, 12(sp)
; RV64IM-NEXT:	lw	a1, 8(sp)
; RV64IM-NEXT:	mulw	a0, a0, a1
; RV64IM-NEXT:	sw	a0, 4(sp)
; RV64IM-NEXT:	lw	a0, 4(sp)
; RV64IM-NEXT:	addi	sp, sp, 16
; RV64IM-NEXT:	ret
;
; RV64IMMULI-LABEL: mulOfTwoParam:
; RV64IMMULI:       # %bb.0:
; RV64IMMULI-NEXT:      addi	sp, sp, -16
; RV64IMMULI-NEXT:    	sw	a0, 12(sp)
; RV64IMMULI-NEXT:    	sw	a1, 8(sp)
; RV64IMMULI-NEXT:    	lw	a0, 12(sp)
; RV64IMMULI-NEXT:    	lw	a1, 8(sp)
; RV64IMMULI-NEXT:    	mulw	a0, a0, a1
; RV64IMMULI-NEXT:    	sw	a0, 4(sp)
; RV64IMMULI-NEXT:    	lw	a0, 4(sp)
; RV64IMMULI-NEXT:    	addi	sp, sp, 16
; RV64IMMULI-NEXT:    	ret
entry:
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %c = alloca i32, align 4
  store i32 %a, i32* %a.addr, align 4
  store i32 %b, i32* %b.addr, align 4
  %0 = load i32, i32* %a.addr, align 4
  %1 = load i32, i32* %b.addr, align 4
  %mul = mul nsw i32 %0, %1
  store i32 %mul, i32* %c, align 4
  %2 = load i32, i32* %c, align 4
  ret i32 %2
}

define signext i32 @mulRegAndImm() #0 {
; RV32IM-LABEL: mulRegAndImm:
; RV32IM:       # %bb.0:
; RV32IM-NEXT:  addi	sp, sp, -16
; RV32IM-NEXT:	li a0, 15
; RV32IM-NEXT:	sw	a0, 12(sp)
; RV32IM-NEXT:	li a0, 10
; RV32IM-NEXT:	sw	a0, 8(sp)
; RV32IM-NEXT:	lw	a0, 8(sp)
; RV32IM-NEXT:	lw	a1, 12(sp)
; RV32IM-NEXT:	mul	a0, a0, a1
; RV32IM-NEXT:	li a1, 185
; RV32IM-NEXT:	mul	a0, a0, a1
; RV32IM-NEXT:	sw	a0, 4(sp)
; RV32IM-NEXT:	lw	a0, 4(sp)
; RV32IM-NEXT:	addi	sp, sp, 16
; RV32IM-NEXT:	ret
;
; RV32IMMULI-LABEL: mulRegAndImm:
; RV32IMMULI:       # %bb.0:
; RV32IMMULI-NEXT:  addi	sp, sp, -16
; RV32IMMULI-NEXT:	li a0, 15
; RV32IMMULI-NEXT:	sw	a0, 12(sp)
; RV32IMMULI-NEXT:	li a0, 10
; RV32IMMULI-NEXT:	sw	a0, 8(sp)
; RV32IMMULI-NEXT:	lw	a0, 8(sp)
; RV32IMMULI-NEXT:	lw	a1, 12(sp)
; RV32IMMULI-NEXT:	mul	a0, a0, a1
; RV32IMMULI-NEXT:	muli	a0, a0, 185
; RV32IMMULI-NEXT:	sw	a0, 4(sp)
; RV32IMMULI-NEXT:	lw	a0, 4(sp)
; RV32IMMULI-NEXT:	addi	sp, sp, 16
; RV32IMMULI-NEXT:	ret
;
; RV64IM-LABEL: mulRegAndImm:
; RV64IM:       # %bb.0:
; RV64IM-NEXT:  addi	sp, sp, -16
; RV64IM-NEXT:	li a0, 15
; RV64IM-NEXT:	sw	a0, 12(sp)
; RV64IM-NEXT:	li a0, 10
; RV64IM-NEXT:	sw	a0, 8(sp)
; RV64IM-NEXT:	lw	a0, 8(sp)
; RV64IM-NEXT:	lw	a1, 12(sp)
; RV64IM-NEXT:	mulw a0, a0, a1
; RV64IM-NEXT:	li a1, 185
; RV64IM-NEXT:	mulw a0, a0, a1
; RV64IM-NEXT:	sw	a0, 4(sp)
; RV64IM-NEXT:	lw	a0, 4(sp)
; RV64IM-NEXT:	addi	sp, sp, 16
; RV64IM-NEXT:	ret
;
; RV64IMMULI-LABEL: mulRegAndImm:
; RV64IMMULI:       # %bb.0:
; RV64IMMULI-NEXT:  addi	sp, sp, -16
; RV64IMMULI-NEXT:	li a0, 15
; RV64IMMULI-NEXT:	sw	a0, 12(sp)
; RV64IMMULI-NEXT:	li a0, 10
; RV64IMMULI-NEXT:	sw	a0, 8(sp)
; RV64IMMULI-NEXT:	lw	a0, 8(sp)
; RV64IMMULI-NEXT:	lw	a1, 12(sp)
; RV64IMMULI-NEXT:	mul	a0, a0, a1
; RV64IMMULI-NEXT:	muli	a0, a0, 185
; RV64IMMULI-NEXT:	sw	a0, 4(sp)
; RV64IMMULI-NEXT:	lw	a0, 4(sp)
; RV64IMMULI-NEXT:	addi	sp, sp, 16
; RV64IMMULI-NEXT:	ret
entry:
  %a = alloca i32, align 4
  %c = alloca i32, align 4
  %res = alloca i32, align 4
  store i32 15, i32* %a, align 4
  store i32 10, i32* %c, align 4
  %0 = load i32, i32* %c, align 4
  %1 = load i32, i32* %a, align 4
  %mul = mul nsw i32 %0, %1
  %mul1 = mul nsw i32 %mul, 185
  store i32 %mul1, i32* %res, align 4
  %2 = load i32, i32* %res, align 4
  ret i32 %2
}

define signext i32 @mulTwoFuncRes() #0 {
; RV32IM-LABEL: mulTwoFuncRes:
; RV32IM:       # %bb.0:
; RV32IM-NEXT:  addi	sp, sp, -16
; RV32IM-NEXT:	sw	ra, 12(sp)                      # 4-byte Folded Spill
; RV32IM-NEXT:	li a0, 5
; RV32IM-NEXT:	li a1, 6
; RV32IM-NEXT:	call	mulOfTwoParam@plt
; RV32IM-NEXT:	sw	a0, 8(sp)
; RV32IM-NEXT:	call	mulRegAndImm@plt
; RV32IM-NEXT:	sw	a0, 4(sp)
; RV32IM-NEXT:	lw	a0, 8(sp)
; RV32IM-NEXT:	lw	a1, 4(sp)
; RV32IM-NEXT:	mul	a0, a0, a1
; RV32IM-NEXT:	sw	a0, 0(sp)
; RV32IM-NEXT:	li a0, 0
; RV32IM-NEXT:	lw	ra, 12(sp)                      # 4-byte Folded Reload
; RV32IM-NEXT:	addi	sp, sp, 16
; RV32IM-NEXT:	ret
;
; RV32IMMULI-LABEL: mulTwoFuncRes:
; RV32IMMULI:       # %bb.0:
; RV32IMMULI-NEXT:  addi	sp, sp, -16
; RV32IMMULI-NEXT:	sw	ra, 12(sp)                      # 4-byte Folded Spill
; RV32IMMULI-NEXT:	li a0, 5
; RV32IMMULI-NEXT:	li a1, 6
; RV32IMMULI-NEXT:	call	mulOfTwoParam@plt
; RV32IMMULI-NEXT:	sw	a0, 8(sp)
; RV32IMMULI-NEXT:	call	mulRegAndImm@plt
; RV32IMMULI-NEXT:	sw	a0, 4(sp)
; RV32IMMULI-NEXT:	lw	a0, 8(sp)
; RV32IMMULI-NEXT:	lw	a1, 4(sp)
; RV32IMMULI-NEXT:	mul	a0, a0, a1
; RV32IMMULI-NEXT:	sw	a0, 0(sp)
; RV32IMMULI-NEXT:	li a0, 0
; RV32IMMULI-NEXT:	lw	ra, 12(sp)                      # 4-byte Folded Reload
; RV32IMMULI-NEXT:	addi	sp, sp, 16
; RV32IMMULI-NEXT:	ret
;
; RV64IM-LABEL: mulTwoFuncRes:
; RV64IM:       # %bb.0:
; RV64IM-NEXT:  addi	sp, sp, -32
; RV64IM-NEXT:	sd	ra, 24(sp)                      # 8-byte Folded Spill
; RV64IM-NEXT:	li a0, 5
; RV64IM-NEXT:	li a1, 6
; RV64IM-NEXT:	call	mulOfTwoParam@plt
; RV64IM-NEXT:	sw	a0, 20(sp)
; RV64IM-NEXT:	call	mulRegAndImm@plt
; RV64IM-NEXT:	sw	a0, 16(sp)
; RV64IM-NEXT:	lw	a0, 20(sp)
; RV64IM-NEXT:	lw	a1, 16(sp)
; RV64IM-NEXT:	mulw	a0, a0, a1
; RV64IM-NEXT:	sw	a0, 12(sp)
; RV64IM-NEXT:	li a0, 0
; RV64IM-NEXT:	ld	ra, 24(sp)                      # 8-byte Folded Reload
; RV64IM-NEXT:	addi	sp, sp, 32
; RV64IM-NEXT:	ret
;
; RV64IMMULI-LABEL: mulTwoFuncRes:
; RV64IMMULI:       # %bb.0:
; RV64IMMULI-NEXT:  addi	sp, sp, -32
; RV64IMMULI-NEXT:	sd	ra, 24(sp)                      # 8-byte Folded Spill
; RV64IMMULI-NEXT:	li a0, 5
; RV64IMMULI-NEXT:	li a1, 6
; RV64IMMULI-NEXT:	call	mulOfTwoParam@plt
; RV64IMMULI-NEXT:	sw	a0, 20(sp)
; RV64IMMULI-NEXT:	call	mulRegAndImm@plt
; RV64IMMULI-NEXT:	sw	a0, 16(sp)
; RV64IMMULI-NEXT:	lw	a0, 20(sp)
; RV64IMMULI-NEXT:	lw	a1, 16(sp)
; RV64IMMULI-NEXT:	mulw	a0, a0, a1
; RV64IMMULI-NEXT:	sw	a0, 12(sp)
; RV64IMMULI-NEXT:	li a0, 0
; RV64IMMULI-NEXT:	ld	ra, 24(sp)                      # 8-byte Folded Reload
; RV64IMMULI-NEXT:	addi	sp, sp, 32
; RV64IMMULI-NEXT:	ret
entry:
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %res = alloca i32, align 4
  %call = call i32 @mulOfTwoParam(i32 5, i32 6)
  store i32 %call, i32* %a, align 4
  %call1 = call i32 @mulRegAndImm()
  store i32 %call1, i32* %b, align 4
  %0 = load i32, i32* %a, align 4
  %1 = load i32, i32* %b, align 4
  %mul = mul nsw i32 %0, %1
  store i32 %mul, i32* %res, align 4
  ret i32 0
}

attributes #0 = { noinline nounwind optnone}

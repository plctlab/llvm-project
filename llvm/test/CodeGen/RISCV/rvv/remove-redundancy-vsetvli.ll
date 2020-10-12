; RUN: llc -mtriple=riscv64 -mattr=+experimental-v -verify-machineinstrs < %s \
; RUN:   | FileCheck --check-prefix=OPT %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-v -verify-machineinstrs -O0 < %s \
; RUN:   | FileCheck --check-prefix=NO-OPT %s



declare <vscale x 8 x i8> @llvm.riscv.vload(i8*);
declare void @llvm.riscv.vstore(i8*, <vscale x 8 x i8>);
define void @load_value(i8* %ptr, i8* %addr) {
;OPT-LABEL: load_value
;OPT:       # %bb.0:
;OPT-NEXT: vsetvli zero, zero, e8,m1,tu,mu
;OPT-NEXT: vle8.v	v25, (a0)
;OPT-NEXT: vse8.v	v25, (a1)
;OPT-NEXT: ret
;
;NO-OPT-LABEL: load_value
;NO-OPT:       # %bb.0:
;NO-OPT-NEXT: vsetvli zero, zero, e8,m1,tu,mu
;NO-OPT-NEXT: vle8.v	v25, (a0)
;NO-OPT-NEXT: vsetvli zero, zero, e8,m1,tu,mu
;NO-OPT-NEXT: vse8.v	v25, (a1)
;NO-OPT-NEXT: ret
  %value = tail call <vscale x 8 x i8> @llvm.riscv.vload(i8* %ptr)
  tail call void @llvm.riscv.vstore(i8* %addr, <vscale x 8 x i8> %value)
  ret void
}
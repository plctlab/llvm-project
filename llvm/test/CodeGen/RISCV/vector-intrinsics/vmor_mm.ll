; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 64 x i1> @llvm.riscv.vmor.mm.b1(<vscale x 64 x i1>, <vscale x 64 x i1>);
define <vscale x 64 x i1> @vmor_mm_b1(<vscale x 64 x i1> %0, <vscale x 64 x i1> %1) {
entry:
  ; CHECK-LABEL: vmor_mm_b1
  ; CHECK: vmor.mm v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i1> @llvm.riscv.vmor.mm.b1(<vscale x 64 x i1> %0, <vscale x 64 x i1> %1)
  ret <vscale x 64 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmor.mm.b2(<vscale x 32 x i1>, <vscale x 32 x i1>);
define <vscale x 32 x i1> @vmor_mm_b2(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1) {
entry:
  ; CHECK-LABEL: vmor_mm_b2
  ; CHECK: vmor.mm v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmor.mm.b2(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmor.mm.b4(<vscale x 16 x i1>, <vscale x 16 x i1>);
define <vscale x 16 x i1> @vmor_mm_b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1) {
entry:
  ; CHECK-LABEL: vmor_mm_b4
  ; CHECK: vmor.mm v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmor.mm.b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmor.mm.b8(<vscale x 8 x i1>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmor_mm_b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1) {
entry:
  ; CHECK-LABEL: vmor_mm_b8
  ; CHECK: vmor.mm v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmor.mm.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmor.mm.b16(<vscale x 4 x i1>, <vscale x 4 x i1>);
define <vscale x 4 x i1> @vmor_mm_b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1) {
entry:
  ; CHECK-LABEL: vmor_mm_b16
  ; CHECK: vmor.mm v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmor.mm.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmor.mm.b32(<vscale x 2 x i1>, <vscale x 2 x i1>);
define <vscale x 2 x i1> @vmor_mm_b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1) {
entry:
  ; CHECK-LABEL: vmor_mm_b32
  ; CHECK: vmor.mm v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmor.mm.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmor.mm.b64(<vscale x 1 x i1>, <vscale x 1 x i1>);
define <vscale x 1 x i1> @vmor_mm_b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1) {
entry:
  ; CHECK-LABEL: vmor_mm_b64
  ; CHECK: vmor.mm v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmor.mm.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1)
  ret <vscale x 1 x i1> %a
}


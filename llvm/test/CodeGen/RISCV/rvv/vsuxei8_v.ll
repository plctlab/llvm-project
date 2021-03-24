; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

declare void @llvm.riscv.vstore.unordered.indexed.nxv1i8.p0i8(i8* %base, <vscale x 1 x i8> %bindex, <vscale x 1 x i8> %value)

; Function Attrs: noinline nounwind optnone
define void @test_vsuxei8_v_i8mf8(i8* %base, <vscale x 1 x i8> %bindex, <vscale x 1 x i8> %value) {
entry:
; CHECK-LABEL: test_vsuxei8_v_i8mf8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vsuxei8.v {{v[0-9]+}}, ({{a[0-9]+}}), {{v[0-9]+}}
; CHECK: ret
  tail call void @llvm.riscv.vstore.unordered.indexed.nxv1i8.p0i8(i8* %base, <vscale x 1 x i8> %bindex, <vscale x 1 x i8> %value)
  ret void
}

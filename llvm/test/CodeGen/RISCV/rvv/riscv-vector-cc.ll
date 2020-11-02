; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck %s

declare <vscale x 1 x double> @llvm.riscv.vfadd.vv.nxv1f64.nxv1f64(
                                 <vscale x 1 x double> %v1,
                                 <vscale x 1 x double> %v2)
define <vscale x 1 x double> @too_many_registers_1(
; CHECK-LABEL: too_many_registers_1:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetvli	zero, zero, e64,m1,tu,mu
; CHECK-NEXT:    vle64.v	v25, (a2)
; CHECK-NEXT:    vle64.v	v26, (a1)
; CHECK-NEXT:    vfadd.vv	v16, v26, v25
; CHECK-NEXT:    ret
                                 i64 %gvl,
                                 <vscale x 1 x double> %v0,
                                 <vscale x 1 x double> %v1,
                                 <vscale x 1 x double> %v2,
                                 <vscale x 1 x double> %v3,
                                 <vscale x 1 x double> %v4,
                                 <vscale x 1 x double> %v5,
                                 <vscale x 1 x double> %v6,
                                 <vscale x 1 x double> %v7,
                                 <vscale x 1 x double> %v8,
                                 <vscale x 1 x double> %v9) nounwind
{
  %vt = call <vscale x 1 x double> @llvm.riscv.vfadd.vv.nxv1f64.nxv1f64(
      <vscale x 1 x double> %v8,
      <vscale x 1 x double> %v9)
  ret <vscale x 1 x double> %vt
}
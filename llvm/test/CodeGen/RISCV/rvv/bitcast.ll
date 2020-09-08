; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

define <vscale x 16 x i8> @bitcast_i16_to_i8(<vscale x 8 x i16> %v) {
; CHECK-LABEL: bitcast_i16_to_i8:
; CHECK:       ret
  %bc = bitcast <vscale x 8 x i16> %v to <vscale x 16 x i8>
  ret <vscale x 16 x i8> %bc
}
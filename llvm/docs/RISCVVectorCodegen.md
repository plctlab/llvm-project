Code Generation for the RISC-V Vector Extension
===============================================

The vector processing capabilities added by the vector extension are very flexible, but this flexibility introduces some unique challenges in generating correct code for it, let alone optimized code. This document gives a bird's eye view of how vector values and operations are handled throughout the RISCV backend to solve these challenges.

## Context

The LLVM IR we receive as input explicitly operates on vectors of unknown length (e.g., `<scalable 1 x i32>`). The number of elements in an IR vector can be a compile-time integer multiple of the unknown `vscale` (e.g. `<scalable 4 x i32>`), but only a multiple of 1 is legal in the RISCV backend. The unknown factor of the vector element count (`vscale`) corresponds directly to the RVV *Maximum Vector Length* (MVL).

The IR occasionally uses RISCV-specific intrinsics that take and return the *active vector length* as an integer value, as in this fragment:

```
%vl = call i32 @llvm.riscv.setvl(i32 %n)
%a = call <scalable 1 x i32> @llvm.riscv.vlw(i32* %p, i32 %vl)
```

However, there are also target-independent operations such as `add <scalable 1 x i32>` that have no such concept.

## Instruction Selection

Instruction selection ignores the vector unit configuration entirely: it operates as if we had a full hard-wired set of regular vector registers with some unknown-but-fixed number of elements. This is done by using pseudo-instructions with suffix `_ImpConf` (*imp*licit *conf*iguration).

In general these instructions would omit an important dependency and therefore open us up to miscompilations, but during instruction selection it's fine because we select no instructions that *change* the configuration (that comes later).

Another concern is the active vector length, which is an operand to most vector instructions we want to select. For IR instructions such as `add <scalable 1 x i32>` that have no VL operand in IR, we use MVL for that operation (and hope to optimize it later). For RISCV-specific intrinsics that handle the active vector length, we just use the integer passed to that intrinsic.

## Vector length register

We represent the VL CSR as an ordinary physical register that can hold an XLEN-sized integer (`XLenVT`). There is a register class, `VLR`, that contains only VL. Most vector instructions have `VLR` inputs, `setvl` has a `VLR` output (along with the GPR result).

This register class is naturally not the preferred one for selecting integer code, but copies between it and GPRs are possible via CSR reads and writes.

> Note: Still need to decide on a solution for VLR virtregs with overlapping live ranges. As-is they cause crashes during register allocation.

## Vector unit configuration CSR

Ẃe represent the vector unit configuration CSR as an unallocatable, permanently reserved physical register.
It is implicitly used by most vector instructions, and instructions that change the configuration define this register implicitly.
There are no corresponding virtual registers, it's a physical register operand from the very start.

## Selecting the active vector length

> Note: This part is not implemented yet.

RISC-V vector instructions are generally controlled by the VL register and only process the lanes up to VL and zero the remaining elements of the destination. This does not match LLVM IR semantics, where many vector operations operate on the full vector and prediction is often applied as a separate operation afterwards.

For correctness, the RISCV backend must therefore be prepared to generate code that sets VL to MAXVL, i.e., operates on full vectors. This is particularly relevant for register copies and spill/fill code, but may also sometimes be required for arithmetic operations (though it shouldn't be required for IR produced by a V-aware vectorizer).

Nevertheless, we really want to use VL in the natural way. Thus we perform a "demanded elements" analysis which symbolically computes .

This is only correct for side-effect-free operations, but operations with side effects need to be "inherently predicated" in the IR already (e.g., consider `@llvm.masked.load` versus a regular vector load).

## Deciding the configuration

The configuration is decided before register allocation, because register allocation needs complete knowledge of the physical register field.
Integrating these decisions into register allocation would be even better, but it's not clear how to do that (and it would be likely a huge project in any case).
By looking at the live intervals, proportions of data type widths among them, etc. we can at least try to heuristically find a good fit.

In the future we should try to separate the function body into several regions between which we can safely change the configuration (at minimum this means no vector values live between them, not even in memory).

## Scalar operations in vector registers

Details TBD, see https://lists.llvm.org/pipermail/llvm-dev/2018-October/126733.html for some thoughts on this

## Emitting configuration instructions

Currently the vector unit is configured in the prologue and disabled in the epilogue.

In the future, especially once we start to support more than one configurations per function, we may insert configuration changes earlier, and also place them closer to the code that actually uses the vector unit.

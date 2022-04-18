//==- RISCVSchedXiangShan.td - XiangShan Scheduling Definitions --*- tablegen -*-=//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//

// XiangShan machine model for scheduling and other instruction cost heuristics.
def XiangShanNanHuModel : SchedMachineModel {
  let MicroOpBufferSize = 256; // Based on the reorder buffer.
  let IssueWidth = 6;
  let LoadLatency = 3;
  // let MispredictPenalty = 15; // Needs a typical value here.
  let CompleteModel = 0;
  let UnsupportedFeatures = [HasStdExtZkr,
                             HasVInstructions];
}

// Integer, Float and Memory Blocks in Xiangshan NanHu microarchitecture.
let SchedModel = XiangShanNanHuModel in {
  let BufferSize = 16 in {
    def NanHuIntPipe : ProcResource<4>;
    def NanHuFloatPipe : ProcResource<4>;
    def NanHuMemPipe : ProcResource<4>;
  }

  let BufferSize = 16 in {

    let Super = NanHuFloatPipe in {
      def NanHuFloatArith : ProcResource<4>;
      def NanHuFloatMisc : ProcResource<2>;
    }

    let Super = NanHuMemPipe in {
      // Address pipelines are not considered at this moment.
      def NanHuMemSave : ProcResource<2>;
      def NanHuMemLoad : ProcResource<2>;
    }
  
    let Super = NanHuIntPipe in {
      def NanHuIntArith : ProcResource<4>;
      def NanHuIntMulDiv : ProcResource<2>;
      def NanHuIntMisc : ProcResource<1>;
    }
  }

// Following parts referenced SiFive7's implementation 
// In NanHu microarchitecture, branching is calculated in Int-Misc
def : WriteRes<WriteJmp, [NanHuIntMisc]>;
def : WriteRes<WriteJal, [NanHuIntMisc]>;
def : WriteRes<WriteJalr, [NanHuIntMisc]>;
def : WriteRes<WriteJmpReg, [NanHuIntMisc]>;

// Integer arithmetic and logic
let Latency = 1 in {
def : WriteRes<WriteIALU, [NanHuIntArith]>;
def : WriteRes<WriteIALU32, [NanHuIntArith]>;
def : WriteRes<WriteShiftImm, [NanHuIntArith]>;
def : WriteRes<WriteShiftImm32, [NanHuIntArith]>;
def : WriteRes<WriteShiftReg, [NanHuIntArith]>;
def : WriteRes<WriteShiftReg32, [NanHuIntArith]>;
}

// Integer multiplication
let Latency = 3 in {
def : WriteRes<WriteIMul, [NanHuIntMulDiv]>{
}
def : WriteRes<WriteIMul32, [NanHuIntMulDiv]>{
}
}

// Integer division
def : WriteRes<WriteIDiv, [NanHuIntMulDiv]> {
  let Latency = 21;
}
def : WriteRes<WriteIDiv32,  [NanHuIntMulDiv]> {
  let Latency = 21;
}

// Memory
def : WriteRes<WriteSTB, [NanHuMemSave]>;
def : WriteRes<WriteSTH, [NanHuMemSave]>;
def : WriteRes<WriteSTW, [NanHuMemSave]>;
def : WriteRes<WriteSTD, [NanHuMemSave]>;
def : WriteRes<WriteFST32, [NanHuMemSave]>;
def : WriteRes<WriteFST64, [NanHuMemSave]>;

let Latency = 3 in {
def : WriteRes<WriteLDB, [NanHuMemLoad]>;
def : WriteRes<WriteLDH, [NanHuMemLoad]>;
def : WriteRes<WriteLDW, [NanHuMemLoad]>;
def : WriteRes<WriteLDWU, [NanHuMemLoad]>;
def : WriteRes<WriteLDD, [NanHuMemLoad]>;
def : WriteRes<WriteFLD32, [NanHuMemLoad]>;
def : WriteRes<WriteFLD64, [NanHuMemLoad]>;
}

// TODO : Find out the real value of XiangShan's Atomic memory latency.
// Atomic memory
def : WriteRes<WriteAtomicSTW, [NanHuMemPipe]>;
def : WriteRes<WriteAtomicSTD, [NanHuMemPipe]>;

let Latency = 3 in {
def : WriteRes<WriteAtomicW, [NanHuMemPipe]>;
def : WriteRes<WriteAtomicD, [NanHuMemPipe]>;
def : WriteRes<WriteAtomicLDW, [NanHuMemPipe]>;
def : WriteRes<WriteAtomicLDD, [NanHuMemPipe]>;
}

// Floating operations
let Latency = 5 in {
def : WriteRes<WriteFMA32, [NanHuFloatArith]>;
def : WriteRes<WriteFMA64, [NanHuFloatArith]>;
}

let Latency = 3 in {
def : WriteRes<WriteFALU32, [NanHuFloatArith]>;
def : WriteRes<WriteFMul32, [NanHuFloatArith]>;
def : WriteRes<WriteFALU64, [NanHuFloatArith]>;
def : WriteRes<WriteFMul64, [NanHuFloatArith]>;
}

let Latency = 3 in {
  def : WriteRes<WriteFSGNJ32, [NanHuFloatMisc]>;
  def : WriteRes<WriteFMinMax32, [NanHuFloatMisc]>;
  def : WriteRes<WriteFSGNJ64, [NanHuFloatMisc]>;
  def : WriteRes<WriteFMinMax64, [NanHuFloatMisc]>;
}

def : WriteRes<WriteFDiv32, [NanHuFloatMisc]> { let Latency = 11;
}
def : WriteRes<WriteFSqrt32, [NanHuFloatMisc]> { let Latency = 17;
}
def : WriteRes<WriteFDiv64, [NanHuFloatMisc]> { let Latency = 21;
}
def : WriteRes<WriteFSqrt64, [NanHuFloatMisc]> { let Latency = 37;
}

// Conversions
let Latency = 3 in {
def : WriteRes<WriteFCvtI32ToF32, [NanHuFloatMisc]>;
def : WriteRes<WriteFCvtI32ToF64, [NanHuFloatMisc]>;
def : WriteRes<WriteFCvtI64ToF32, [NanHuFloatMisc]>;
def : WriteRes<WriteFCvtI64ToF64, [NanHuFloatMisc]>;
def : WriteRes<WriteFCvtF32ToI32, [NanHuFloatMisc]>;
def : WriteRes<WriteFCvtF32ToI64, [NanHuFloatMisc]>;
def : WriteRes<WriteFCvtF32ToF64, [NanHuFloatMisc]>;
def : WriteRes<WriteFCvtF64ToI32, [NanHuFloatMisc]>;
def : WriteRes<WriteFCvtF64ToI64, [NanHuFloatMisc]>;
def : WriteRes<WriteFCvtF64ToF32, [NanHuFloatMisc]>;

def : WriteRes<WriteFClass32, [NanHuFloatMisc]>;
def : WriteRes<WriteFClass64, [NanHuFloatMisc]>;
def : WriteRes<WriteFCmp32, [NanHuFloatMisc]>;
def : WriteRes<WriteFCmp64, [NanHuFloatMisc]>;
def : WriteRes<WriteFMovI32ToF32, [NanHuFloatMisc]>;
def : WriteRes<WriteFMovF32ToI32, [NanHuFloatMisc]>;
def : WriteRes<WriteFMovI64ToF64, [NanHuFloatMisc]>;
def : WriteRes<WriteFMovF64ToI64, [NanHuFloatMisc]>;
}

// Others
def : WriteRes<WriteCSR, [NanHuIntPipe]>;
def : WriteRes<WriteNop, []>;

def : InstRW<[WriteIALU], (instrs COPY)>;

def : ReadAdvance<ReadJmp, 0>;
def : ReadAdvance<ReadJalr, 0>;
def : ReadAdvance<ReadCSR, 0>;
def : ReadAdvance<ReadStoreData, 0>;
def : ReadAdvance<ReadMemBase, 0>;
def : ReadAdvance<ReadIALU, 0>;
def : ReadAdvance<ReadIALU32, 0>;
def : ReadAdvance<ReadShiftImm, 0>;
def : ReadAdvance<ReadShiftImm32, 0>;
def : ReadAdvance<ReadShiftReg, 0>;
def : ReadAdvance<ReadShiftReg32, 0>;
def : ReadAdvance<ReadIDiv, 0>;
def : ReadAdvance<ReadIDiv32, 0>;
def : ReadAdvance<ReadIMul, 0>;
def : ReadAdvance<ReadIMul32, 0>;
def : ReadAdvance<ReadAtomicWA, 0>;
def : ReadAdvance<ReadAtomicWD, 0>;
def : ReadAdvance<ReadAtomicDA, 0>;
def : ReadAdvance<ReadAtomicDD, 0>;
def : ReadAdvance<ReadAtomicLDW, 0>;
def : ReadAdvance<ReadAtomicLDD, 0>;
def : ReadAdvance<ReadAtomicSTW, 0>;
def : ReadAdvance<ReadAtomicSTD, 0>;
def : ReadAdvance<ReadFMemBase, 0>;
def : ReadAdvance<ReadFALU32, 0>;
def : ReadAdvance<ReadFALU64, 0>;
def : ReadAdvance<ReadFMul32, 0>;
def : ReadAdvance<ReadFMA32, 0>;
def : ReadAdvance<ReadFMul64, 0>;
def : ReadAdvance<ReadFMA64, 0>;
def : ReadAdvance<ReadFDiv32, 0>;
def : ReadAdvance<ReadFDiv64, 0>;
def : ReadAdvance<ReadFSqrt32, 0>;
def : ReadAdvance<ReadFSqrt64, 0>;
def : ReadAdvance<ReadFCmp32, 0>;
def : ReadAdvance<ReadFCmp64, 0>;
def : ReadAdvance<ReadFSGNJ32, 0>;
def : ReadAdvance<ReadFSGNJ64, 0>;
def : ReadAdvance<ReadFMinMax32, 0>;
def : ReadAdvance<ReadFMinMax64, 0>;
def : ReadAdvance<ReadFCvtF32ToI32, 0>;
def : ReadAdvance<ReadFCvtF32ToI64, 0>;
def : ReadAdvance<ReadFCvtF64ToI32, 0>;
def : ReadAdvance<ReadFCvtF64ToI64, 0>;
def : ReadAdvance<ReadFCvtI32ToF32, 0>;
def : ReadAdvance<ReadFCvtI32ToF64, 0>;
def : ReadAdvance<ReadFCvtI64ToF32, 0>;
def : ReadAdvance<ReadFCvtI64ToF64, 0>;
def : ReadAdvance<ReadFCvtF32ToF64, 0>;
def : ReadAdvance<ReadFCvtF64ToF32, 0>;
def : ReadAdvance<ReadFMovF32ToI32, 0>;
def : ReadAdvance<ReadFMovI32ToF32, 0>;
def : ReadAdvance<ReadFMovF64ToI64, 0>;
def : ReadAdvance<ReadFMovI64ToF64, 0>;
def : ReadAdvance<ReadFClass32, 0>;
def : ReadAdvance<ReadFClass64, 0>;

defm : UnsupportedSchedV;
defm : UnsupportedSchedZba;
defm : UnsupportedSchedZbb;
defm : UnsupportedSchedZbc;
defm : UnsupportedSchedZbs;
defm : UnsupportedSchedZbe;
defm : UnsupportedSchedZbf;
defm : UnsupportedSchedZbm;
defm : UnsupportedSchedZbp;
defm : UnsupportedSchedZbr;
defm : UnsupportedSchedZbt;
defm : UnsupportedSchedZfh;
}
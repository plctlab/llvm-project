// multiclass Binary_vv {
//   def "int_riscv_" # NAME : Intrinsic<[llvm_anyvector_ty],
//                                       [LLVMMatchType<0>, LLVMMatchType<0>],
//                                       [IntrNoMem]>;
//   // TODO: mask type
// }
// 
// multiclass Binary_vx {
//   def "int_riscv_" # NAME : Intrinsic<[llvm_anyvector_ty],
//                                       [LLVMMatchType<0>, llvm_anyint_ty],
//                                       [IntrNoMem]>;
//   // TODO: mask type
// }
// 
// defm vadd_vv : Binary_vv;
// defm vsub_vv : Binary_vv;
// defm vmul_vv : Binary_vv;
// defm vdiv_vv : Binary_vv;
// 
// defm vadd_vx : Binary_vx;
// defm vsub_vx : Binary_vx;
// defm vmul_vx : Binary_vx;
// defm vdiv_vx : Binary_vx;

def int_riscv_vsetvl
  : Intrinsic<[llvm_anyint_ty],
              [llvm_anyint_ty, llvm_anyint_ty],
              [IntrHasSideEffects,IntrNoMem]>;

def int_riscv_vsetvlmax
  : Intrinsic<[llvm_anyint_ty],
              [llvm_anyint_ty],
              [IntrHasSideEffects,IntrNoMem]>;

def int_riscv_vle8_v_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_i8m1
  : Intrinsic<[],
              [llvm_nxv8i8_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle8_v_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_i8m2
  : Intrinsic<[],
              [llvm_nxv2i8_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle8_v_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_i8m4
  : Intrinsic<[],
              [llvm_nxv4i8_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle8_v_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_i8m8
  : Intrinsic<[],
              [llvm_nxv8i8_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle16_v_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_i16m1
  : Intrinsic<[],
              [llvm_nxv4i16_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle16_v_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_i16m2
  : Intrinsic<[],
              [llvm_nxv2i16_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle16_v_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_i16m4
  : Intrinsic<[],
              [llvm_nxv4i16_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle16_v_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_i16m8
  : Intrinsic<[],
              [llvm_nxv8i16_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_i32m1
  : Intrinsic<[],
              [llvm_nxv2i32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_i32m2
  : Intrinsic<[],
              [llvm_nxv2i32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_i32m4
  : Intrinsic<[],
              [llvm_nxv4i32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_i32m8
  : Intrinsic<[],
              [llvm_nxv8i32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_i64m1
  : Intrinsic<[],
              [llvm_nxv1i64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_i64m2
  : Intrinsic<[],
              [llvm_nxv2i64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_i64m4
  : Intrinsic<[],
              [llvm_nxv4i64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_i64m8
  : Intrinsic<[],
              [llvm_nxv8i64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle8_v_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_u8m1
  : Intrinsic<[],
              [llvm_nxv8i8_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle8_v_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_u8m2
  : Intrinsic<[],
              [llvm_nxv2i8_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle8_v_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_u8m4
  : Intrinsic<[],
              [llvm_nxv4i8_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle8_v_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_u8m8
  : Intrinsic<[],
              [llvm_nxv8i8_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle16_v_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_u16m1
  : Intrinsic<[],
              [llvm_nxv4i16_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle16_v_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_u16m2
  : Intrinsic<[],
              [llvm_nxv2i16_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle16_v_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_u16m4
  : Intrinsic<[],
              [llvm_nxv4i16_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle16_v_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_u16m8
  : Intrinsic<[],
              [llvm_nxv8i16_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_u32m1
  : Intrinsic<[],
              [llvm_nxv2i32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_u32m2
  : Intrinsic<[],
              [llvm_nxv2i32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_u32m4
  : Intrinsic<[],
              [llvm_nxv4i32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_u32m8
  : Intrinsic<[],
              [llvm_nxv8i32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_u64m1
  : Intrinsic<[],
              [llvm_nxv1i64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_u64m2
  : Intrinsic<[],
              [llvm_nxv2i64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_u64m4
  : Intrinsic<[],
              [llvm_nxv4i64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_u64m8
  : Intrinsic<[],
              [llvm_nxv8i64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_f32m1
  : Intrinsic<[],
              [llvm_nxv2f32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_f32m2
  : Intrinsic<[],
              [llvm_nxv2f32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_f32m4
  : Intrinsic<[],
              [llvm_nxv4f32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle32_v_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_f32m8
  : Intrinsic<[],
              [llvm_nxv8f32_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_f64m1
  : Intrinsic<[],
              [llvm_nxv1f64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_f64m2
  : Intrinsic<[],
              [llvm_nxv2f64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_f64m4
  : Intrinsic<[],
              [llvm_nxv4f64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vle64_v_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse64_v_f64m8
  : Intrinsic<[],
              [llvm_nxv8f64_ty, llvm_anyptr_ty],
              [IntrWriteMem]>;

def int_riscv_vmv_x_s_i8m1_i8
  : Intrinsic<[llvm_anyint_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i8m2_i8
  : Intrinsic<[llvm_i8_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i8m4_i8
  : Intrinsic<[llvm_i8_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i8m8_i8
  : Intrinsic<[llvm_i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i16m1_i16
  : Intrinsic<[llvm_anyint_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i16m2_i16
  : Intrinsic<[llvm_i16_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i16m4_i16
  : Intrinsic<[llvm_i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i16m8_i16
  : Intrinsic<[llvm_i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i32m1_i32
  : Intrinsic<[llvm_i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i32m2_i32
  : Intrinsic<[llvm_i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i32m4_i32
  : Intrinsic<[llvm_i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i32m8_i32
  : Intrinsic<[llvm_i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i64m1_i64
  : Intrinsic<[llvm_i64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i64m2_i64
  : Intrinsic<[llvm_i64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i64m4_i64
  : Intrinsic<[llvm_i64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_i64m8_i64
  : Intrinsic<[llvm_i64_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u8m1_u8
  : Intrinsic<[llvm_anyint_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u8m2_u8
  : Intrinsic<[llvm_i8_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u8m4_u8
  : Intrinsic<[llvm_i8_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u8m8_u8
  : Intrinsic<[llvm_i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u16m1_u16
  : Intrinsic<[llvm_anyint_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u16m2_u16
  : Intrinsic<[llvm_i16_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u16m4_u16
  : Intrinsic<[llvm_i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u16m8_u16
  : Intrinsic<[llvm_i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u32m1_u32
  : Intrinsic<[llvm_i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u32m2_u32
  : Intrinsic<[llvm_i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u32m4_u32
  : Intrinsic<[llvm_i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u32m8_u32
  : Intrinsic<[llvm_i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u64m1_u64
  : Intrinsic<[llvm_i64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u64m2_u64
  : Intrinsic<[llvm_i64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u64m4_u64
  : Intrinsic<[llvm_i64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_x_s_u64m8_u64
  : Intrinsic<[llvm_i64_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_f_s_f32m1_f32
  : Intrinsic<[llvm_float_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_s_f_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_f_s_f32m2_f32
  : Intrinsic<[llvm_float_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_s_f_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_f_s_f32m4_f32
  : Intrinsic<[llvm_float_ty],
              [llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_s_f_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_f_s_f32m8_f32
  : Intrinsic<[llvm_float_ty],
              [llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_s_f_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_f_s_f64m1_f64
  : Intrinsic<[llvm_double_ty],
              [llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_s_f_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_f_s_f64m2_f64
  : Intrinsic<[llvm_double_ty],
              [llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_s_f_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_f_s_f64m4_f64
  : Intrinsic<[llvm_double_ty],
              [llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_s_f_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_f_s_f64m8_f64
  : Intrinsic<[llvm_double_ty],
              [llvm_nxv8f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_s_f_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_nxv8f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vzero_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vzero_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_v_f_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_v_f_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_v_f_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_v_f_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_v_f_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_v_f_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_v_f_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_nxv8f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_v_f_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_u8_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_i8_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_u8_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_i8_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_u8_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_i8_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_u8_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_i8_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_u16_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_i16_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_u16_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_i16_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_u16_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_i16_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_u16_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_i16_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_f32_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_u32_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_f32_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_i32_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_u32_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_i32_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_f32_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_u32_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_f32_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_i32_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_u32_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_i32_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_f32_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_u32_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_f32_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_i32_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_u32_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_i32_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_f32_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_u32_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_f32_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_i32_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_u32_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_i32_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_f64_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f64_u64_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_f64_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f64_i64_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_u64_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_i64_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_f64_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f64_u64_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_f64_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f64_i64_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_u64_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_i64_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_f64_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f64_u64_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_f64_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f64_i64_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_u64_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_i64_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_f64_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8f64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f64_u64_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_f64_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8f64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f64_i64_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_u64_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_i64_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i64_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i32_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i64_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i16_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i64_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i8_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i32_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i16_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i32_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i8_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i16_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i8_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i64_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i32_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i64_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i16_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i64_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i8_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i32_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i16_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i32_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i8_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i16_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i8_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i64_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i32_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i64_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i16_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i64_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i8_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i32_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i16_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i32_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i8_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i16_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i8_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i64_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i32_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i64_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i16_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i64_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i8_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i32_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i16_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i32_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i8_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i16_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i8_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u64_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u32_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u64_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u16_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u64_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u8_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u32_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u16_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u32_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u8_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u16_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u8_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u64_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u32_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u64_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u16_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u64_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u8_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u32_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u16_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u32_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u8_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u16_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u8_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u64_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u32_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u64_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u16_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u64_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u8_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u32_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u16_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u32_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u8_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u16_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u8_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u64_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u32_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u64_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u16_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u64_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u8_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u32_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u16_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u32_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u8_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u16_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u8_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vslideup_vx_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_nxv8f64_ty, llvm_anyint_ty],
              [IntrNoMem]>;

def int_riscv_vmset_m_b1
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmset_m_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmset_m_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmset_m_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmset_m_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmset_m_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmset_m_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmclr_m_b1
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmclr_m_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmclr_m_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmclr_m_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmclr_m_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmclr_m_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vmclr_m_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [],
              [IntrNoMem]>;

// Vector Integer Arithmetic Operations

// Vector Single-Width Integer Add and Subtract Functions
def int_riscv_vadd_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vadd_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsub_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vrsub_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;


// Vector Bitwise Logical Operations
def int_riscv_vand_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vand_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vor_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vxor_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vnot_v_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;


// Vector Single-Width Bit Shift Operations
def int_riscv_vsll_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsll_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsrl_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsra_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;


// Vector Integer Comparison Operations
def int_riscv_vmseq_vv_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i8m1
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i8m2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i8m4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i16m1
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i16m2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i16m4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i32m1
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i32m2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i32m4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i64m1
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i64m2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vv_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmslt_vx_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vv_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsle_vx_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vv_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgt_vx_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vv_i64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx__i64m4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u8m1_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u8m1
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u8m2_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u8m2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u8m4_b2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u8m4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u16m1_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u16m1
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u16m2_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u16m2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u16m4_b4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u16m4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u32m1
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u32m2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u32m4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u64m1
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u64m2
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vv_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmseq_vx_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vv_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsne_vx_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vv_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsltu_vx_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vv_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsleu_vx_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vv_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgtu_vx_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsgeu_vv_u64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmsge_vx_u_u64m4
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;


// Vector Integer Min/Max Operations
def int_riscv_vmin_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmin_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmax_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vminu_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmaxu_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;


// Vector Single-Width Integer Multiply Operations
def int_riscv_vmul_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmul_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;


// Vector Integer Divide Operations
def int_riscv_vdiv_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vdiv_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vdivu_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;


// Vector Single-Width Integer Multiply-Add Operations
def int_riscv_vmacc_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmacc_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsac_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmadd_vf_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vnmsub_vf_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;


// Vector Integer Merge Operations
def int_riscv_vmerge_vvm_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv1i1_ty, llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv1i1_ty, llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv1i1_ty, llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vxm_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv1i1_ty, llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;


// Vector Fixed-Point Arithmetic Operations

// Vector Single-Width Saturating Add and Subtract Functions
def int_riscv_vsadd_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsadd_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vsaddu_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vssub_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vv_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vssubu_vx_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_i64_ty],
              [IntrNoMem]>;


// Vector Floating-Point Operations

// Vector Single-Width Floating-Point Add/Subtract Operations
def int_riscv_vfadd_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfadd_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfsub_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;


// Vector Single-Width Floating-Point Multiply/Divide Operations
def int_riscv_vfmul_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmul_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfdiv_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;


// Vector Single-Width Floating-Point Fused Multiply-Add Operations
def int_riscv_vfmacc_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vf_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vf_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vf_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vf_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vf_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmacc_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmacc_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsac_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsac_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmadd_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmadd_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmsub_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfnmsub_vf_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;


// Vector Floating-Point Square-Root Operations
def int_riscv_vfsqrt_v_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfsqrt_v_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfsqrt_v_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfsqrt_v_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfsqrt_v_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfsqrt_v_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty],
              [IntrNoMem]>;


// Vector Floating-Point MIN/MAX Operations
def int_riscv_vfmin_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vx_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vv_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vx_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vx_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vv_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vx_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vx_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vv_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vx_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vx_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vv_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vx_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vx_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vv_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vx_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmin_vx_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vv_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmax_vx_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;


// Vector Floating-Point Compare Operations
def int_riscv_vmfeq_vv_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vx_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vv_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vx_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vv_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vx_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vv_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vx_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vv_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vx_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vv_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vx_f32m1_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vv_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vx_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vv_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vx_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vv_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vx_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vv_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vx_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vv_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vx_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vv_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vx_f32m2_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vv_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vx_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vv_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vx_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vv_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vx_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vv_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vx_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vv_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vx_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vv_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vx_f32m4_b8
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vv_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vx_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vv_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vx_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vv_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vx_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vv_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vx_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vv_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vx_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vv_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vx_f64m1_b64
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vv_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vx_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vv_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vx_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vv_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vx_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vv_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vx_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vv_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vx_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vv_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vx_f64m2_b32
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vv_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfeq_vx_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vv_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfne_vx_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vv_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vmflt_vx_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vv_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfle_vx_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vv_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfgt_vx_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vv_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vmfge_vx_f64m4_b16
  : Intrinsic<[llvm_nxv1i1_ty],
              [llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;


// Vector Floating-Point Merge Operations
def int_riscv_vmerge_vvm_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv1i1_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmerge_vfm_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv1i1_ty, llvm_nxv2f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv1i1_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmerge_vfm_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv1i1_ty, llvm_nxv4f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv1i1_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmerge_vfm_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv1i1_ty, llvm_nxv8f32_ty, llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1i1_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmerge_vfm_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1i1_ty, llvm_nxv1f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv1i1_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmerge_vfm_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv1i1_ty, llvm_nxv2f64_ty, llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmerge_vvm_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv1i1_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfmerge_vfm_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv1i1_ty, llvm_nxv4f64_ty, llvm_double_ty],
              [IntrNoMem]>;


// Vector Single-Width Integer Reduction Operations
def int_riscv_vredsum_vs_i8m1_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i8m1_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i8m1_i8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i8m2_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i8m2_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i8m2_i8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i8m4_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i8m4_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i8m4_i8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i16m1_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i16m1_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i16m1_i16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i16m2_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i16m2_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i16m2_i16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i16m4_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i16m4_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i16m4_i16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i32m1_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i32m1_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i32m1_i32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i32m2_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i32m2_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i32m2_i32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i32m4_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i32m4_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i32m4_i32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i64m1_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i64m1_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i64m1_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i64m2_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i64m2_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i64m2_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_i64m4_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vredmax_vs_i64m4_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vredmin_vs_i64m4_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u8m1_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u8m1_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u8m1_u8m1
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty, llvm_nxv8i8_ty, llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u8m2_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u8m2_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u8m2_u8m2
  : Intrinsic<[llvm_nxv16i8_ty],
              [llvm_nxv16i8_ty, llvm_nxv16i8_ty, llvm_nxv16i8_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u8m4_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u8m4_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u8m4_u8m4
  : Intrinsic<[llvm_nxv32i8_ty],
              [llvm_nxv32i8_ty, llvm_nxv32i8_ty, llvm_nxv32i8_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u16m1_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u16m1_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u16m1_u16m1
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty, llvm_nxv4i16_ty, llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u16m2_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u16m2_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u16m2_u16m2
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty, llvm_nxv8i16_ty, llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u16m4_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u16m4_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u16m4_u16m4
  : Intrinsic<[llvm_nxv16i16_ty],
              [llvm_nxv16i16_ty, llvm_nxv16i16_ty, llvm_nxv16i16_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u32m1_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u32m1_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u32m1_u32m1
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty, llvm_nxv2i32_ty, llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u32m2_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u32m2_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u32m2_u32m2
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty, llvm_nxv4i32_ty, llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u32m4_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u32m4_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u32m4_u32m4
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty, llvm_nxv8i32_ty, llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u64m1_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u64m1_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u64m1_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty, llvm_nxv1i64_ty, llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u64m2_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u64m2_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u64m2_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty, llvm_nxv2i64_ty, llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vredsum_vs_u64m4_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vredmaxu_vs_u64m4_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vredminu_vs_u64m4_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty, llvm_nxv4i64_ty, llvm_nxv4i64_ty],
              [IntrNoMem]>;


// Vector Single-Width Floating-Point Reduction Operations
def int_riscv_vfredsum_vs_f32m1_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfredmax_vs_f32m1_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfredmin_vs_f32m1_f32m1
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty, llvm_nxv2f32_ty, llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vfredsum_vs_f32m2_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfredmax_vs_f32m2_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfredmin_vs_f32m2_f32m2
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty, llvm_nxv4f32_ty, llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vfredsum_vs_f32m4_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfredmax_vs_f32m4_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfredmin_vs_f32m4_f32m4
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty, llvm_nxv8f32_ty, llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vfredsum_vs_f64m1_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfredmax_vs_f64m1_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfredmin_vs_f64m1_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty, llvm_nxv1f64_ty, llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vfredsum_vs_f64m2_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfredmax_vs_f64m2_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfredmin_vs_f64m2_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty, llvm_nxv2f64_ty, llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vfredsum_vs_f64m4_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfredmax_vs_f64m4_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vfredmin_vs_f64m4_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty, llvm_nxv4f64_ty, llvm_nxv4f64_ty],
              [IntrNoMem]>;



def int_riscv_vsetvl
  : Intrinsic<[llvm_anyint_ty],
              [llvm_anyint_ty, llvm_anyint_ty],
              [IntrHasSideEffects,IntrNoMem]>;

def int_riscv_vsetvlmax
  : Intrinsic<[llvm_anyint_ty],
              [llvm_anyint_ty],
              [IntrHasSideEffects,IntrNoMem]>;

def int_riscv_vle8_v_i8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_i8m1
  : Intrinsic<[],
              [llvm_nxv1i8_ty, llvm_anyptr_ty],
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
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_i16m1
  : Intrinsic<[],
              [llvm_nxv1i16_ty, llvm_anyptr_ty],
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
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_i32m1
  : Intrinsic<[],
              [llvm_nxv1i32_ty, llvm_anyptr_ty],
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
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse8_v_u8m1
  : Intrinsic<[],
              [llvm_nxv1i8_ty, llvm_anyptr_ty],
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
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse16_v_u16m1
  : Intrinsic<[],
              [llvm_nxv1i16_ty, llvm_anyptr_ty],
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
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_u32m1
  : Intrinsic<[],
              [llvm_nxv1i32_ty, llvm_anyptr_ty],
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
  : Intrinsic<[llvm_nxv1f32_ty],
              [llvm_anyptr_ty],
              [IntrReadMem]>;

def int_riscv_vse32_v_f32m1
  : Intrinsic<[],
              [llvm_nxv1f32_ty, llvm_anyptr_ty],
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
  : Intrinsic<[llvm_i8_ty],
              [llvm_nxv1i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i8_ty, llvm_i8_ty],
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
  : Intrinsic<[llvm_i16_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i16_ty, llvm_i16_ty],
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
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_i32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i32_ty, llvm_i32_ty],
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
  : Intrinsic<[llvm_i8_ty],
              [llvm_nxv1i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i8_ty, llvm_i8_ty],
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
  : Intrinsic<[llvm_i16_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i16_ty, llvm_i16_ty],
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
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_s_x_u32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i32_ty, llvm_i32_ty],
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
              [llvm_nxv1f32_ty],
              [IntrNoMem]>;

def int_riscv_vfmv_s_f_f32m1
  : Intrinsic<[llvm_nxv1f32_ty],
              [llvm_nxv1f32_ty, llvm_float_ty],
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
  : Intrinsic<[llvm_nxv1i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i8m1
  : Intrinsic<[llvm_nxv1i8_ty],
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
  : Intrinsic<[llvm_nxv1i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i16m1
  : Intrinsic<[llvm_nxv1i16_ty],
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
  : Intrinsic<[llvm_nxv1i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_i32m1
  : Intrinsic<[llvm_nxv1i32_ty],
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
  : Intrinsic<[llvm_nxv1i8_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u8m1
  : Intrinsic<[llvm_nxv1i8_ty],
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
  : Intrinsic<[llvm_nxv1i16_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u16m1
  : Intrinsic<[llvm_nxv1i16_ty],
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
  : Intrinsic<[llvm_nxv1i32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_u32m1
  : Intrinsic<[llvm_nxv1i32_ty],
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
  : Intrinsic<[llvm_nxv1f32_ty],
              [],
              [IntrNoMem]>;

def int_riscv_vundefined_f32m1
  : Intrinsic<[llvm_nxv1f32_ty],
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
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_nxv2i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_nxv4i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_nxv8i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_nxv2i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_nxv4i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_nxv8i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_nxv2i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_nxv4i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_nxv8i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_nxv2i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_nxv4i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_nxv8i32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_i32_ty],
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
  : Intrinsic<[llvm_nxv1f32_ty],
              [llvm_nxv1f32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_f32m1
  : Intrinsic<[llvm_nxv1f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_nxv2f32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_nxv4f32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_nxv8f32_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_nxv1f64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_nxv2f64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_nxv4f64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_v_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_nxv8f64_ty],
              [IntrNoMem]>;

def int_riscv_vmv_v_x_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_u8_i8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_i8_u8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i8_ty],
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
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_i16_u16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i16_ty],
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
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_u32_f32m1
  : Intrinsic<[llvm_nxv1f32_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_f32_i32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1f32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_f32_i32_f32m1
  : Intrinsic<[llvm_nxv1f32_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_u32_i32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_i32_u32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i32_ty],
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
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i32_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i64_i16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i16_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i64_i8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i64_i8_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i32_i16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i16_i32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i32_i8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i32_i8_i32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i8_i16_i8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_i16_i8_i16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i8_ty],
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
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u32_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u64_u16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u16_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u64_u8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i64_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u64_u8_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_nxv1i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u32_u16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u16_u32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u32_u8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i32_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u32_u8_u32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i8_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u8_u16_u8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i16_ty],
              [IntrNoMem]>;

def int_riscv_vreinterpret_u16_u8_u16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i8_ty],
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
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i8_ty, llvm_anyint_ty],
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
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i16_ty, llvm_anyint_ty],
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
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i32_ty, llvm_anyint_ty],
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
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_nxv1i8_ty, llvm_anyint_ty],
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
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_nxv1i16_ty, llvm_anyint_ty],
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
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_nxv1i32_ty, llvm_anyint_ty],
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
  : Intrinsic<[llvm_nxv1f32_ty],
              [llvm_nxv1f32_ty, llvm_anyint_ty],
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


// intrinsic vsetvl

def int_riscv_vsetvl
  : Intrinsic<[llvm_anyint_ty],
              [llvm_anyint_ty, llvm_anyint_ty],
              [IntrHasSideEffects]>;

// intrinsic vle%s_v_%b%sm%l

def int_riscv_vle8_v_i8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vle8_v_i8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vle8_v_i8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vle8_v_i8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_i16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_i16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_i16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_i16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_i32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_i32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_i32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_i32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_i64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_i64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_i64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_i64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vle8_v_u8m1
  : Intrinsic<[llvm_nxv1i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vle8_v_u8m2
  : Intrinsic<[llvm_nxv2i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vle8_v_u8m4
  : Intrinsic<[llvm_nxv4i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vle8_v_u8m8
  : Intrinsic<[llvm_nxv8i8_ty],
              [llvm_i8_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_u16m1
  : Intrinsic<[llvm_nxv1i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_u16m2
  : Intrinsic<[llvm_nxv2i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_u16m4
  : Intrinsic<[llvm_nxv4i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_u16m8
  : Intrinsic<[llvm_nxv8i16_ty],
              [llvm_i16_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_u32m1
  : Intrinsic<[llvm_nxv1i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_u32m2
  : Intrinsic<[llvm_nxv2i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_u32m4
  : Intrinsic<[llvm_nxv4i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_u32m8
  : Intrinsic<[llvm_nxv8i32_ty],
              [llvm_i32_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_u64m1
  : Intrinsic<[llvm_nxv1i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_u64m2
  : Intrinsic<[llvm_nxv2i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_u64m4
  : Intrinsic<[llvm_nxv4i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_u64m8
  : Intrinsic<[llvm_nxv8i64_ty],
              [llvm_i64_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_f16m1
  : Intrinsic<[llvm_nxv1f16_ty],
              [llvm_half_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_f16m2
  : Intrinsic<[llvm_nxv2f16_ty],
              [llvm_half_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_f16m4
  : Intrinsic<[llvm_nxv4f16_ty],
              [llvm_half_ty],
              [IntrNoMem]>;

def int_riscv_vle16_v_f16m8
  : Intrinsic<[llvm_nxv8f16_ty],
              [llvm_half_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_f32m1
  : Intrinsic<[llvm_nxv1f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_f32m2
  : Intrinsic<[llvm_nxv2f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_f32m4
  : Intrinsic<[llvm_nxv4f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vle32_v_f32m8
  : Intrinsic<[llvm_nxv8f32_ty],
              [llvm_float_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_f64m1
  : Intrinsic<[llvm_nxv1f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_f64m2
  : Intrinsic<[llvm_nxv2f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_f64m4
  : Intrinsic<[llvm_nxv4f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;

def int_riscv_vle64_v_f64m8
  : Intrinsic<[llvm_nxv8f64_ty],
              [llvm_double_ty],
              [IntrNoMem]>;
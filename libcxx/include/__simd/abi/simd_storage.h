#ifndef _LIBCPP___SIMD_ABI_SIMD_STORAGE_H
#define _LIBCPP___SIMD_ABI_SIMD_STORAGE_H

#include <experimental/__config>
#include <__simd/arch/config.h>
#if _LIBCPP_SIMD_HAVE_NEON
#include <arm_neon.h>
#endif
#if _LIBCPP_SIMD_HAVE_PPC
#include <altivec.h>
#endif

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD_ABI

struct __scalar {
  static constexpr bool __is_abi_tag = true;
  static constexpr size_t __simd_size = 1;
};

template <int _Np>
struct __vec_ext {
  static constexpr bool __is_abi_tag = _Np > 0;
  static constexpr size_t __simd_size = _Np;
};

template <int _Np>
struct __neon {
  static constexpr bool __is_abi_tag = true;
  static constexpr size_t __simd_size = _Np;
};

struct __ppc {
  static constexpr bool __is_abi_tag = true;
  static constexpr size_t __simd_size = 16;
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD_ABI

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

// constexpr feature detection
constexpr inline bool __have_mmx = _LIBCPP_SIMD_HAVE_MMX;
constexpr inline bool __have_sse = _LIBCPP_SIMD_HAVE_SSE;
constexpr inline bool __have_sse2 = _LIBCPP_SIMD_HAVE_SSE2;
constexpr inline bool __have_sse3 = _LIBCPP_SIMD_HAVE_SSE3;
constexpr inline bool __have_ssse3 = _LIBCPP_SIMD_HAVE_SSSE3;
constexpr inline bool __have_sse4_1 = _LIBCPP_SIMD_HAVE_SSE4_1;
constexpr inline bool __have_sse4_2 = _LIBCPP_SIMD_HAVE_SSE4_2;
constexpr inline bool __have_xop = _LIBCPP_SIMD_HAVE_XOP;
constexpr inline bool __have_avx = _LIBCPP_SIMD_HAVE_AVX;
constexpr inline bool __have_avx2 = _LIBCPP_SIMD_HAVE_AVX2;
constexpr inline bool __have_bmi = _LIBCPP_SIMD_HAVE_BMI1;
constexpr inline bool __have_bmi2 = _LIBCPP_SIMD_HAVE_BMI2;
constexpr inline bool __have_lzcnt = _LIBCPP_SIMD_HAVE_LZCNT;
constexpr inline bool __have_sse4a = _LIBCPP_SIMD_HAVE_SSE4A;
constexpr inline bool __have_fma = _LIBCPP_SIMD_HAVE_FMA;
constexpr inline bool __have_fma4 = _LIBCPP_SIMD_HAVE_FMA4;
constexpr inline bool __have_f16c = _LIBCPP_SIMD_HAVE_F16C;
constexpr inline bool __have_popcnt = _LIBCPP_SIMD_HAVE_POPCNT;
constexpr inline bool __have_avx512f = _LIBCPP_SIMD_HAVE_AVX512F;
constexpr inline bool __have_avx512dq = _LIBCPP_SIMD_HAVE_AVX512DQ;
constexpr inline bool __have_avx512vl = _LIBCPP_SIMD_HAVE_AVX512VL;
constexpr inline bool __have_avx512bw = _LIBCPP_SIMD_HAVE_AVX512BW;
constexpr inline bool __have_avx512dq_vl = __have_avx512dq && __have_avx512vl;
constexpr inline bool __have_avx512bw_vl = __have_avx512bw && __have_avx512vl;
constexpr inline bool __have_x86 = _LIBCPP_SIMD_X86INTRIN;

constexpr inline bool __have_neon = _LIBCPP_SIMD_HAVE_NEON;
constexpr inline bool __have_neon_a32 = _LIBCPP_SIMD_HAVE_NEON_A32;
constexpr inline bool __have_neon_a64 = _LIBCPP_SIMD_HAVE_NEON_A64;

constexpr inline bool __have_power10vec = _LIBCPP_SIMD_HAVE_POWER10VEC;
constexpr inline bool __have_power9vec = _LIBCPP_SIMD_HAVE_POWER9VEC;
constexpr inline bool __have_power8vec = _LIBCPP_SIMD_HAVE_POWER8VEC;
constexpr inline bool __have_power_vsx = _LIBCPP_SIMD_HAVE_VSX;
constexpr inline bool __have_power_vmx = _LIBCPP_SIMD_HAVE_PPC;

// TODO: replace it by std::bit_ceil when bump to C++20
constexpr size_t __next_pow_of_2(size_t __val) {
  size_t __pow = 1;
  while (__pow < __val)
    __pow <<= 1;
  return __pow;
}

template <class _Tp>
auto __choose_mask_type() {
  if constexpr (sizeof(_Tp) == 1) {
    return uint8_t{};
  } else if constexpr (sizeof(_Tp) == 2) {
    return uint16_t{};
  } else if constexpr (sizeof(_Tp) == 4) {
    return uint32_t{};
  } else if constexpr (sizeof(_Tp) == 8) {
    return uint64_t{};
  }
}

template <class _Tp, class _Abi>
struct __simd_storage;

template <class _Tp, class _Abi>
struct __mask_storage;

template <class _Tp>
struct __simd_storage <_Tp, simd_abi::__scalar> {
  _Tp __data;

  _Tp __get(size_t __idx) const noexcept { return (&__data)[__idx]; }

  void __set(size_t __idx, _Tp __v) noexcept { (&__data)[__idx] = __v; }
};

template <class _Tp>
struct __mask_storage <_Tp, simd_abi::__scalar> : __simd_storage<bool, simd_abi::__scalar> {};

template <class _Tp, int _Np>
struct __simd_storage <_Tp, simd_abi::__vec_ext<_Np>> {
#if defined(_LIBCPP_COMPILER_CLANG_BASED)
  _Tp __data __attribute__((vector_size(sizeof(_Tp) * _Np)));
#else
  _Tp __data __attribute__((vector_size(__next_pow_of_2(sizeof(_Tp) * _Np))));
#endif

  _Tp __get(size_t __idx) const noexcept { return __data[__idx]; }

  void __set(size_t __idx, _Tp __v) noexcept { __data[__idx] = __v; }
};

template <class _Tp, int _Np>
struct __mask_storage <_Tp, simd_abi::__vec_ext<_Np>> : __simd_storage<decltype(__choose_mask_type<_Tp>()), simd_abi::__vec_ext<_Np>> {};

#if _LIBCPP_SIMD_HAVE_NEON
template <class _Tp, int _Np>
struct __neon_type;

template <class _Tp, int _Np>
using __neon_type_t = typename __neon_type<_Tp, _Np>::type;

#define _LIBCPP_SIMD_ARM_NEON_TYPES(_Tp, _NTp, _Np)         \
template <>                                                 \
struct __neon_type<_Tp, _Np>                                \
{ using type = _NTp##x##_Np##_t; };
// 64-bits NEON types
_LIBCPP_SIMD_ARM_NEON_TYPES(unsigned char,      uint8,    8)
_LIBCPP_SIMD_ARM_NEON_TYPES(signed char,        int8,     8)
_LIBCPP_SIMD_ARM_NEON_TYPES(unsigned short,     uint16,   4)
_LIBCPP_SIMD_ARM_NEON_TYPES(short,              int16,    4)
_LIBCPP_SIMD_ARM_NEON_TYPES(unsigned,           uint32,   2)
_LIBCPP_SIMD_ARM_NEON_TYPES(int,                int32,    2)
_LIBCPP_SIMD_ARM_NEON_TYPES(unsigned long long, uint64,   1)
_LIBCPP_SIMD_ARM_NEON_TYPES(long long,          int64,    1)
_LIBCPP_SIMD_ARM_NEON_TYPES(float,              float32,  2)
_LIBCPP_SIMD_ARM_NEON_TYPES(double,             float64,  1)
// 128-bits NEON types
_LIBCPP_SIMD_ARM_NEON_TYPES(unsigned char,      uint8,    16)
_LIBCPP_SIMD_ARM_NEON_TYPES(signed char,        int8,     16)
_LIBCPP_SIMD_ARM_NEON_TYPES(unsigned short,     uint16,   8)
_LIBCPP_SIMD_ARM_NEON_TYPES(short,              int16,    8)
_LIBCPP_SIMD_ARM_NEON_TYPES(unsigned,           uint32,   4)
_LIBCPP_SIMD_ARM_NEON_TYPES(int,                int32,    4)
_LIBCPP_SIMD_ARM_NEON_TYPES(unsigned long long, uint64,   2)
_LIBCPP_SIMD_ARM_NEON_TYPES(long long,          int64,    2)
_LIBCPP_SIMD_ARM_NEON_TYPES(float,              float32,  4)
_LIBCPP_SIMD_ARM_NEON_TYPES(double,             float64,  2)

#define _LIBCPP_SIMD_ARM_NEON_STORAGE64(_Tp, _Np, _Suffix)  \
template <>                                                 \
struct __simd_storage <_Tp, simd_abi::__neon<_Np>> {        \
  __neon_type_t<_Tp, _Np> __data;                           \
};
//   _Tp __get(size_t __idx) const noexcept                    \
//   { return vget_lane_##_Suffix(__data, __idx); }            \
//   void __set(size_t __idx, _Tp __v) noexcept                \
//   { vset_lane_##_Suffix(__v, __data, __idx); }              \
// };
// 64-bits NEON Storage
_LIBCPP_SIMD_ARM_NEON_STORAGE64(unsigned char,      8,  u8)
_LIBCPP_SIMD_ARM_NEON_STORAGE64(signed char,        8,  s8)
_LIBCPP_SIMD_ARM_NEON_STORAGE64(unsigned short,     4,  u16)
_LIBCPP_SIMD_ARM_NEON_STORAGE64(short,              4,  s16)
_LIBCPP_SIMD_ARM_NEON_STORAGE64(unsigned,           2,  u32)
_LIBCPP_SIMD_ARM_NEON_STORAGE64(int,                2,  s32)
_LIBCPP_SIMD_ARM_NEON_STORAGE64(unsigned long long, 1,  u64)
_LIBCPP_SIMD_ARM_NEON_STORAGE64(long long,          1,  s64)
_LIBCPP_SIMD_ARM_NEON_STORAGE64(float,              2,  f32)
_LIBCPP_SIMD_ARM_NEON_STORAGE64(double,             1,  f64)

#define _LIBCPP_SIMD_ARM_NEON_STORAGE128(_Tp, _Np, _Suffix) \
template <>                                                 \
struct __simd_storage <_Tp, simd_abi::__neon<_Np>> {        \
  __neon_type_t<_Tp, _Np> __data;                           \
};
//   _Tp __get(size_t __idx) const noexcept                    \
//   { return vgetq_lane_##_Suffix(__data, __idx); }           \
//   void __set(size_t __idx, _Tp __v) noexcept                \
//   { vsetq_lane_##_Suffix(__v, __data, __idx); }             \
// };
// 128-bits NEON Storage
_LIBCPP_SIMD_ARM_NEON_STORAGE128(unsigned char,      16,  u8)
_LIBCPP_SIMD_ARM_NEON_STORAGE128(signed char,        16,  s8)
_LIBCPP_SIMD_ARM_NEON_STORAGE128(unsigned short,     8,   u16)
_LIBCPP_SIMD_ARM_NEON_STORAGE128(short,              8,   s16)
_LIBCPP_SIMD_ARM_NEON_STORAGE128(unsigned,           4,   u32)
_LIBCPP_SIMD_ARM_NEON_STORAGE128(int,                4,   s32)
_LIBCPP_SIMD_ARM_NEON_STORAGE128(unsigned long long, 2,   u64)
_LIBCPP_SIMD_ARM_NEON_STORAGE128(long long,          2,   s64)
_LIBCPP_SIMD_ARM_NEON_STORAGE128(float,              4,   f32)
_LIBCPP_SIMD_ARM_NEON_STORAGE128(double,             2,   f64)

template <class _Tp, int _Np>
struct __mask_storage <_Tp, simd_abi::__neon<_Np>> : __simd_storage<decltype(__choose_mask_type<_Tp>()), simd_abi::__neon<_Np>> {};
#endif

#if _LIBCPP_SIMD_HAVE_PPC
template <class _Tp>
struct __ppc_type;

template <class _Tp>
using __ppc_type_t = typename __ppc_type<_Tp>::type;

#define _LIBCPP_SIMD_PPC_TYPES(_Tp)         \
template <>                                 \
struct __ppc_type<_Tp>                      \
{ using type = vector _Tp; };
// PPC types
_LIBCPP_SIMD_PPC_TYPES(unsigned char)
_LIBCPP_SIMD_PPC_TYPES(signed char)
_LIBCPP_SIMD_PPC_TYPES(unsigned short)
_LIBCPP_SIMD_PPC_TYPES(short)
_LIBCPP_SIMD_PPC_TYPES(unsigned)
_LIBCPP_SIMD_PPC_TYPES(int)
_LIBCPP_SIMD_PPC_TYPES(unsigned long long)
_LIBCPP_SIMD_PPC_TYPES(long long)
_LIBCPP_SIMD_PPC_TYPES(float)
_LIBCPP_SIMD_PPC_TYPES(double)

template <_Tp>
struct __simd_storage <_Tp, simd_abi::__ppc> {
  __ppc_type_t<_Tp> __data;
  _Tp __get(size_t __idx) const noexcept
  { return vec_extract(__data, __idx); }
  void __set(size_t __idx, _Tp __v) noexcept
  { vec_insert(__v, __data, __idx); }
}

template <class _Tp, int _Np>
struct __mask_storage <_Tp, simd_abi::__ppc> : __simd_storage<decltype(__choose_mask_type<_Tp>()), simd_abi::__ppc> {};
#endif


_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_SIMD_STORAGE_H

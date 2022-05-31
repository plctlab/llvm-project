#ifndef _LIBCPP___SIMD_ABI_UTILITY_H
#define _LIBCPP___SIMD_ABI_UTILITY_H

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, class _Abi>
struct __simd_impl;

template <class _Tp, class _Abi>
struct __mask_impl;

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

template <typename Tuple, typename Func, size_t ... N>
void call_tuple( Tuple& t, Func&& func, std::index_sequence<N...>) {
  static_cast<void>(std::initializer_list<int>{(func(std::get<N>(t)), 0)...});
}

template <typename ... Args, typename Func>
void for_tuple( std::tuple<Args...>& t, Func&& func) {
  call_tuple(t, std::forward<Func>(func), std::make_index_sequence<sizeof...(Args)>{});
}

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_UTILITY_H

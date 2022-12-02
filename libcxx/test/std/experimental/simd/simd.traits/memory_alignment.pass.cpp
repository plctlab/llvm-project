//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14

// <experimental/simd>
//
// [simd.traits]
// template <class T, class U = typename T::value_type> struct memory_alignment;
// template <class T, class U = typename T::value_type>
//   inline constexpr size_t memory_alignment_v = memory_alignment<T, U>::value;

#include "../test_utils.h"
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckMemoryAlignmentNative {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 16);
    static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 16);
  }
};
struct CheckMemoryAlignmentCompatible {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 16);
    static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 16);
  }
};
struct CheckMemoryAlignmentScalar {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same_v<_Tp, signed char> || std::is_same_v<_Tp, unsigned char>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 1);
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 1);
    } else if constexpr (std::is_same_v<_Tp, short> || std::is_same_v<_Tp, unsigned short> ||
                         std::is_same_v<_Tp, char16_t>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 2);
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 2);
    } else if constexpr (std::is_same_v<_Tp, float> || std::is_same_v<_Tp, int> || std::is_same_v<_Tp, unsigned int> ||
                         std::is_same_v<_Tp, wchar_t> || std::is_same_v<_Tp, char32_t>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 4);
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 4);
    } else if constexpr (std::is_same_v<_Tp, double> || std::is_same_v<_Tp, long long> ||
                         std::is_same_v<_Tp, unsigned long long> || std::is_same_v<_Tp, long> ||
                         std::is_same_v<_Tp, unsigned long>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 8);
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 8);
    } else {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 16);
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 16);
    }
  }
};

struct CheckMemoryAlignmentFixedSize {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same_v<_Tp, signed char> || std::is_same_v<_Tp, unsigned char>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == next_pow2(_Np));
    } else if constexpr (std::is_same_v<_Tp, short> || std::is_same_v<_Tp, unsigned short> ||
                         std::is_same_v<_Tp, char16_t>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 2 * next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 2 * next_pow2(_Np));
    } else if constexpr (std::is_same_v<_Tp, float> || std::is_same_v<_Tp, int> || std::is_same_v<_Tp, unsigned int> ||
                         std::is_same_v<_Tp, wchar_t> || std::is_same_v<_Tp, char32_t>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 4 * next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 4 * next_pow2(_Np));
    } else if constexpr (std::is_same_v<_Tp, double> || std::is_same_v<_Tp, long long> ||
                         std::is_same_v<_Tp, unsigned long long> || std::is_same_v<_Tp, long> ||
                         std::is_same_v<_Tp, unsigned long>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 8 * next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 8 * next_pow2(_Np));
    } else {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 16 * next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 16 * next_pow2(_Np));
    }
  }
};

struct CheckMemoryAlignmentDeduce {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same_v<_Tp, signed char> || std::is_same_v<_Tp, unsigned char>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == next_pow2(_Np));
    } else if constexpr (std::is_same_v<_Tp, short> || std::is_same_v<_Tp, unsigned short> ||
                         std::is_same_v<_Tp, char16_t>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 2 * next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 2 * next_pow2(_Np));
    } else if constexpr (std::is_same_v<_Tp, float> || std::is_same_v<_Tp, int> || std::is_same_v<_Tp, unsigned int> ||
                         std::is_same_v<_Tp, wchar_t> || std::is_same_v<_Tp, char32_t>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 4 * next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 4 * next_pow2(_Np));
    } else if constexpr (std::is_same_v<_Tp, double> || std::is_same_v<_Tp, long long> ||
                         std::is_same_v<_Tp, unsigned long long> || std::is_same_v<_Tp, long> ||
                         std::is_same_v<_Tp, unsigned long>) {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 8 * next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 8 * next_pow2(_Np));
    } else {
      static_assert(ex::memory_alignment<ex::simd<_Tp, SimdAbi>>{}.value == 16 * next_pow2(_Np));
      static_assert(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>> == 16 * next_pow2(_Np));
    }
  }
};
template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  if constexpr (std::is_same_v<F, CheckMemoryAlignmentNative>) {
    F{}.template operator()<_Tp, ex::simd_abi::native<_Tp>, _Np>();
  } else if constexpr (std::is_same_v<F, CheckMemoryAlignmentCompatible>) {
    F{}.template operator()<_Tp, ex::simd_abi::compatible<_Tp>, _Np>();
  } else if constexpr (std::is_same_v<F, CheckMemoryAlignmentScalar>) {
    F{}.template operator()<_Tp, ex::simd_abi::scalar, _Np>();
  } else if constexpr (std::is_same_v<F, CheckMemoryAlignmentFixedSize>) {
    F{}.template operator()<_Tp, ex::simd_abi::fixed_size<_Np>, _Np>();
  } else {
    F{}.template operator()<_Tp, ex::simd_abi::deduce_t<_Tp, _Np>, _Np>();
  }
  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main() {
  test_all_simd_abi<CheckMemoryAlignmentNative>();
  test_all_simd_abi<CheckMemoryAlignmentCompatible>();
  test_all_simd_abi<CheckMemoryAlignmentScalar>();
  test_all_simd_abi<CheckMemoryAlignmentFixedSize>();
  test_all_simd_abi<CheckMemoryAlignmentFixedSize>();
}
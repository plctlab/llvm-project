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
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckMemoryAlignmentTrueSimdPart1 {
  template <class _Np>
  void operator()() {
    static_assert(_Np::value == 16);
  }
};

struct CheckMemoryAlignmentTrueSimdPart2 {
  template <class _Tp, std::size_t _Lp, class _Np>
  void operator()() {
    if constexpr (std::is_same<_Tp, double>::value || std::is_same<_Tp, long long>::value ||
                  std::is_same<_Tp, unsigned long long>::value || std::is_same<_Tp, long>::value ||
                  std::is_same<_Tp, unsigned long>::value) {
      static_assert(_Np::value == 8 * _Lp);
    } else if constexpr (std::is_same<_Tp, float>::value || std::is_same<_Tp, int>::value ||
                         std::is_same<_Tp, unsigned int>::value || std::is_same<_Tp, wchar_t>::value ||
                         std::is_same<_Tp, char32_t>::value) {
      static_assert(_Np::value == 4 * _Lp);
    } else if constexpr (std::is_same<_Tp, short>::value || std::is_same<_Tp, unsigned short>::value ||
                         std::is_same<_Tp, char16_t>::value) {
      static_assert(_Np::value == 2 * _Lp);
    } else if constexpr (std::is_same<_Tp, signed char>::value || std::is_same<_Tp, unsigned char>::value) {
      static_assert(_Np::value == 1 * _Lp);
    } else {
      static_assert(_Np::value == 16 * _Lp);
    }
  }
};

struct CheckMemoryAlignmentTrueSimdMaskPart1 {
  template <class _Tp, class _Np>
  void operator()() {
    if constexpr (std::is_same<_Tp, double>::value || std::is_same<_Tp, long long>::value ||
                  std::is_same<_Tp, unsigned long long>::value || std::is_same<_Tp, long>::value ||
                  std::is_same<_Tp, unsigned long>::value) {
      static_assert(_Np::value == 2);
    } else if constexpr (std::is_same<_Tp, float>::value || std::is_same<_Tp, int>::value ||
                         std::is_same<_Tp, unsigned int>::value || std::is_same<_Tp, wchar_t>::value ||
                         std::is_same<_Tp, char32_t>::value) {
      static_assert(_Np::value == 4);
    } else if constexpr (std::is_same<_Tp, short>::value || std::is_same<_Tp, unsigned short>::value ||
                         std::is_same<_Tp, char16_t>::value) {
      static_assert(_Np::value == 8);
    } else if constexpr (std::is_same<_Tp, signed char>::value || std::is_same<_Tp, unsigned char>::value) {
      static_assert(_Np::value == 16);
    } else {
      static_assert(_Np::value == 1);
    }
  }
};

struct CheckMemoryAlignmentTrueSimdMaskPart2 {
  template <class _Tp, std::size_t _Lp, class Abi, class _Np>
  void operator()() {
    if constexpr (std::is_same<Abi, ex::simd_abi::scalar>::value) {
      static_assert(_Np::value == 1);
    } else {
      static_assert(_Np::value == (_Lp + 1));
    }
  }
};

struct CheckMemoryAlignmentVTrueSimdPart1 {
  template <std::size_t _Np>
  void operator()() {
    static_assert(_Np == 16);
  }
};

struct CheckMemoryAlignmentVTrueSimdPart2 {
  template <class _Tp, std::size_t _Lp, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same<_Tp, double>::value || std::is_same<_Tp, long long>::value ||
                  std::is_same<_Tp, unsigned long long>::value || std::is_same<_Tp, long>::value ||
                  std::is_same<_Tp, unsigned long>::value) {
      static_assert(_Np == 8 * _Lp);
    } else if constexpr (std::is_same<_Tp, float>::value || std::is_same<_Tp, int>::value ||
                         std::is_same<_Tp, unsigned int>::value || std::is_same<_Tp, wchar_t>::value ||
                         std::is_same<_Tp, char32_t>::value) {
      static_assert(_Np == 4 * _Lp);
    } else if constexpr (std::is_same<_Tp, short>::value || std::is_same<_Tp, unsigned short>::value ||
                         std::is_same<_Tp, char16_t>::value) {
      static_assert(_Np == 2 * _Lp);
    } else if constexpr (std::is_same<_Tp, signed char>::value || std::is_same<_Tp, unsigned char>::value) {
      static_assert(_Np == 1 * _Lp);
    } else {
      static_assert(_Np == 16 * _Lp);
    }
  }
};

struct CheckMemoryAlignmentVTrueSimdMaskPart1 {
  template <class _Tp, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same<_Tp, double>::value || std::is_same<_Tp, long long>::value ||
                  std::is_same<_Tp, unsigned long long>::value || std::is_same<_Tp, long>::value ||
                  std::is_same<_Tp, unsigned long>::value) {
      static_assert(_Np == 2);
    } else if constexpr (std::is_same<_Tp, float>::value || std::is_same<_Tp, int>::value ||
                         std::is_same<_Tp, unsigned int>::value || std::is_same<_Tp, wchar_t>::value ||
                         std::is_same<_Tp, char32_t>::value) {
      static_assert(_Np == 4);
    } else if constexpr (std::is_same<_Tp, short>::value || std::is_same<_Tp, unsigned short>::value ||
                         std::is_same<_Tp, char16_t>::value) {
      static_assert(_Np == 8);
    } else if constexpr (std::is_same<_Tp, signed char>::value || std::is_same<_Tp, unsigned char>::value) {
      static_assert(_Np == 16);
    } else {
      static_assert(_Np == 1);
    }
  }
};

struct CheckMemoryAlignmentVTrueSimdMaskPart2 {
  template <class _Tp, std::size_t _Lp, class Abi, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same<Abi, ex::simd_abi::scalar>::value) {
      static_assert(_Np == 1);
    } else {
      static_assert(_Np == (_Lp + 1));
    }
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  if constexpr (_Np % 2 == 1) {
    if constexpr (std::is_same<F, CheckMemoryAlignmentTrueSimdPart1>::value) {
      F{}.template operator()<ex::memory_alignment<ex::simd<_Tp, ex::simd_abi::native<_Tp>>, _Tp>>();
      F{}.template operator()<ex::memory_alignment<ex::simd<_Tp, ex::simd_abi::compatible<_Tp>>, _Tp>>();
    } else if constexpr (std::is_same<F, CheckMemoryAlignmentTrueSimdPart2>::value) {
      F{}.template operator()<_Tp, 1, ex::memory_alignment<ex::simd<_Tp, ex::simd_abi::scalar>, _Tp>>();
      F{}.template
      operator()<_Tp, _Np + 1, ex::memory_alignment<ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, _Np + 1>>, _Tp>>();
      F{}.template
      operator()<_Tp, _Np + 1, ex::memory_alignment<ex::simd<_Tp, ex::simd_abi::fixed_size<_Np + 1>>, _Tp>>();
    } else if constexpr (std::is_same<F, CheckMemoryAlignmentTrueSimdMaskPart1>::value) {
      F{}.template operator()<_Tp, ex::memory_alignment<ex::simd_mask<_Tp, ex::simd_abi::native<_Tp>>, bool>>();
      F{}.template operator()<_Tp, ex::memory_alignment<ex::simd_mask<_Tp, ex::simd_abi::compatible<_Tp>>, bool>>();
    } else if constexpr (std::is_same<F, CheckMemoryAlignmentTrueSimdMaskPart2>::value) {
      F{}.template
      operator()<_Tp, 1, ex::simd_abi::scalar, ex::memory_alignment<ex::simd_mask<_Tp, ex::simd_abi::scalar>, bool>>();
      F{}.template operator()<_Tp,
                              _Np,
                              ex::simd_abi::deduce_t<_Tp, _Np + 1>,
                              ex::memory_alignment<ex::simd_mask<_Tp, ex::simd_abi::deduce_t<_Tp, _Np + 1>>, bool>>();
      F{}.template operator()<_Tp,
                              _Np,
                              ex::simd_abi::fixed_size<_Np + 1>,
                              ex::memory_alignment<ex::simd_mask<_Tp, ex::simd_abi::fixed_size<_Np + 1>>, bool>>();
    } else if constexpr (std::is_same<F, CheckMemoryAlignmentVTrueSimdPart1>::value) {
      F{}.template operator()<ex::memory_alignment_v<ex::simd<_Tp, ex::simd_abi::native<_Tp>>, _Tp>>();
      F{}.template operator()<ex::memory_alignment_v<ex::simd<_Tp, ex::simd_abi::compatible<_Tp>>, _Tp>>();
    } else if constexpr (std::is_same<F, CheckMemoryAlignmentVTrueSimdPart2>::value) {
      F{}.template operator()<_Tp, 1, ex::memory_alignment_v<ex::simd<_Tp, ex::simd_abi::scalar>, _Tp>>();
      F{}.template
      operator()<_Tp, _Np + 1, ex::memory_alignment_v<ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, _Np + 1>>, _Tp>>();
      F{}.template
      operator()<_Tp, _Np + 1, ex::memory_alignment_v<ex::simd<_Tp, ex::simd_abi::fixed_size<_Np + 1>>, _Tp>>();
    } else if constexpr (std::is_same<F, CheckMemoryAlignmentVTrueSimdMaskPart1>::value) {
      F{}.template operator()<_Tp, ex::memory_alignment_v<ex::simd_mask<_Tp, ex::simd_abi::native<_Tp>>, bool>>();
      F{}.template operator()<_Tp, ex::memory_alignment_v<ex::simd_mask<_Tp, ex::simd_abi::compatible<_Tp>>, bool>>();
    } else {
      F{}.template operator()<_Tp,
                              1,
                              ex::simd_abi::scalar,
                              ex::memory_alignment_v<ex::simd_mask<_Tp, ex::simd_abi::scalar>, bool>>();
      F{}.template operator()<_Tp,
                              _Np,
                              ex::simd_abi::deduce_t<_Tp, _Np + 1>,
                              ex::memory_alignment_v<ex::simd_mask<_Tp, ex::simd_abi::deduce_t<_Tp, _Np + 1>>, bool>>();
      F{}.template operator()<_Tp,
                              _Np,
                              ex::simd_abi::fixed_size<_Np + 1>,
                              ex::memory_alignment_v<ex::simd_mask<_Tp, ex::simd_abi::fixed_size<_Np + 1>>, bool>>();
    }

    test_simd_abi<F, _Np, _Tp, SimdAbis...>();
  }
}

int main() {
  test_all_simd_abi<CheckMemoryAlignmentTrueSimdPart1>();
  test_all_simd_abi<CheckMemoryAlignmentTrueSimdPart2>();
  test_all_simd_abi<CheckMemoryAlignmentTrueSimdMaskPart1>();
  test_all_simd_abi<CheckMemoryAlignmentTrueSimdMaskPart2>();

  test_all_simd_abi<CheckMemoryAlignmentVTrueSimdPart1>();
  test_all_simd_abi<CheckMemoryAlignmentVTrueSimdPart2>();
  test_all_simd_abi<CheckMemoryAlignmentVTrueSimdMaskPart1>();
  test_all_simd_abi<CheckMemoryAlignmentVTrueSimdMaskPart2>();
}
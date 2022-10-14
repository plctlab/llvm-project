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
//template <class T, class Abi = simd_abi::compatible<T>> struct simd_size;
//template <class T, class Abi = simd_abi::compatible<T>>
//inline constexpr size_t ex::simd_size_v = ex::simd_size<T, Abi>::value;

#include "../test_utils.h"
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdSizeTrue {
  template <class _Tp, std::size_t _Np>
  void operator()() {
    static_assert(_Tp::value == _Np);
  }
};

struct CheckSimdSizeVTrue {
  template <std::size_t _Tp, std::size_t _Np>
  void operator()() {
    static_assert(_Tp == _Np);
  }
};

struct CheckSimdSizeExtraTrue {
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

struct CheckSimdSizeVExtraTrue {
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

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  if constexpr (std::is_same<F, CheckSimdSizeTrue>::value) {
    F{}.template operator()<ex::simd_size<_Tp, ex::simd_abi::scalar>, 1>();
    F{}.template operator()<ex::simd_size<_Tp, ex::simd_abi::deduce_t<_Tp, _Np>>, _Np>();
    F{}.template operator()<ex::simd_size<_Tp, ex::simd_abi::fixed_size<_Np>>, _Np>();
  } else if constexpr (std::is_same<F, CheckSimdSizeVTrue>::value) {
    F{}.template operator()<ex::simd_size_v<_Tp, ex::simd_abi::scalar>, 1>();
    F{}.template operator()<ex::simd_size_v<_Tp, ex::simd_abi::deduce_t<_Tp, _Np>>, _Np>();
    F{}.template operator()<ex::simd_size_v<_Tp, ex::simd_abi::fixed_size<_Np>>, _Np>();
  } else if constexpr (std::is_same<F, CheckSimdSizeExtraTrue>::value) {
    F{}.template operator()<_Tp, ex::simd_size<_Tp, ex::simd_abi::native<_Tp>>>();
    F{}.template operator()<_Tp, ex::simd_size<_Tp, ex::simd_abi::compatible<_Tp>>>();
  } else {
    F{}.template operator()<_Tp, ex::simd_size_v<_Tp, ex::simd_abi::native<_Tp>>>();
    F{}.template operator()<_Tp, ex::simd_size_v<_Tp, ex::simd_abi::compatible<_Tp>>>();
  }

  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main() {
  test_all_simd_abi<CheckSimdSizeTrue>();
  test_all_simd_abi<CheckSimdSizeVTrue>();
  test_all_simd_abi<CheckSimdSizeExtraTrue>();
  test_all_simd_abi<CheckSimdSizeVExtraTrue>();
}
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
// [simd.nonmembers]
// template<class T, class Abi> simd<T, Abi> min(const simd<T, Abi>& a, const simd<T, Abi>& b) noexcept;
// template<class T, class Abi> simd<T, Abi> max(const simd<T, Abi>& a, const simd<T, Abi>& b) noexcept;
// template<class T, class Abi> pair<simd<T, Abi>, simd<T, Abi>> minmax(const simd<T, Abi>& a, const simd<T, Abi>& b) noexcept;
// template<class T, class Abi> simd<T, Abi> clamp(const simd<T, Abi>& v, const simd<T, Abi>& lo, const simd<T, Abi>& hi);

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdMin {
  template <class _Tp, class SimdAbi>
  void operator()() {
    const ex::simd<_Tp, SimdAbi> lhs([](_Tp i){return i;});
    const ex::simd<_Tp, SimdAbi> rhs(static_cast<_Tp>(5));

    ex::simd<_Tp, SimdAbi> result_min_simd = ex::min(lhs, rhs);
    for (size_t i = 0; i < result_min_simd.size(); ++i) {
        assert(result_min_simd[i] == std::min(lhs[i], rhs[i]));
    }
  }
};

struct CheckSimdMax {
  template <class _Tp, class SimdAbi>
  void operator()() {
    const ex::simd<_Tp, SimdAbi> lhs([](_Tp i){return i;});
    const ex::simd<_Tp, SimdAbi> rhs(static_cast<_Tp>(5));

    ex::simd<_Tp, SimdAbi> result_max_simd = ex::max(lhs, rhs);
    for (size_t i = 0; i < result_max_simd.size(); ++i) {
        assert(result_max_simd[i] == std::max(lhs[i], rhs[i]));
    }
  }
};

struct CheckSimdMinMax {
  template <class _Tp, class SimdAbi>
  void operator()() {
    const ex::simd<_Tp, SimdAbi> lhs([](_Tp i){return i;});
    const ex::simd<_Tp, SimdAbi> rhs(static_cast<_Tp>(5));

    std::pair<ex::simd<_Tp, SimdAbi>,ex::simd<_Tp, SimdAbi>> result_min_max_simd = ex::minmax(lhs, rhs);
    for (size_t i = 0; i < result_min_max_simd.first.size(); ++i) {
        assert(result_min_max_simd.first[i] == std::min(lhs[i], rhs[i]));
    }
    for (size_t i = 0; i < result_min_max_simd.second.size(); ++i) {
        assert(result_min_max_simd.second[i] == std::max(lhs[i], rhs[i]));
    }
  }
};

struct CheckSimdClamp {
  template <class _Tp, class SimdAbi>
  void operator()() {
    const ex::simd<_Tp, SimdAbi> lo([](_Tp i){return i;});
    const ex::simd<_Tp, SimdAbi> hi([](_Tp i){return static_cast<_Tp>(i+1);});
    const ex::simd<_Tp, SimdAbi> v(static_cast<_Tp>(5));

    ex::simd<_Tp, SimdAbi> result_simd = ex::clamp(v, lo, hi);
    for (size_t i = 0; i < result_simd.size(); ++i) {
        assert(result_simd[i] == std::clamp(v[i], lo[i], hi[i]));
    }
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  F{}.template operator()<_Tp, SimdAbi>();
  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main() {
    test_all_simd_abi<CheckSimdMin>();
    test_all_simd_abi<CheckSimdMax>();
    test_all_simd_abi<CheckSimdMinMax>();
    test_all_simd_abi<CheckSimdClamp>();
}

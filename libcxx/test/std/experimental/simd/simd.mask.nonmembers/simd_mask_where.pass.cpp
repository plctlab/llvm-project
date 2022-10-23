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
// [simd.mask.nonmembers]
// template <class T, class Abi>
// where_expression<simd_mask<T, Abi>, simd<T, Abi>> where(const typename simd<T, Abi>::mask_type& k,
//                                                         simd<T, Abi>& v) noexcept;
// template <class T, class Abi>
// const_where_expression<simd_mask<T, Abi>, simd<T, Abi>> where(const typename simd<T, Abi>::mask_type& k,
//                                                               const simd<T, Abi>& v) noexcept;
// template <class T, class Abi>
// where_expression<simd_mask<T, Abi>, simd_mask<T, Abi>> where(const type_identity_t<simd_mask<T, Abi>>& k,
//                                                              simd_mask<T, Abi>& v) noexcept;
// template <class T, class Abi>
// const_where_expression<simd_mask<T, Abi>, simd_mask<T, Abi>> where(const type_identity_t<simd_mask<T, Abi>>& k,
//                                                                    const simd_mask<T, Abi>& v) noexcept;
// template <class T>
// where_expression<bool T> where(see below k, T& v) noexcept;
// template <class T>
// const_where_expression<bool, T> where(see below k, const T& v) noexcept;

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdMaskComparision {
  template <class _Tp, class SimdAbi>
  void operator()() {
    const typename ex::simd<_Tp, SimdAbi>::mask_type mask_{};
    ex::simd<_Tp, SimdAbi> simd_([](_Tp i){return i;});
    const ex::simd<_Tp, SimdAbi> const_simd_([](_Tp i){return i;});

    ex::where_expression<ex::simd_mask<_Tp, SimdAbi>, ex::simd<_Tp, SimdAbi>> ex::where pure_where(mask_, simd_);
    //assert(pure_where.)
    ex::where_expression<ex::simd_mask<_Tp, SimdAbi>, ex::simd<_Tp, SimdAbi>> ex::where const_where(mask_, const_simd_);
    
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
  test_all_simd_abi<CheckSimdMaskComparision>();
}

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
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdMaskWhere {
  template <class _Tp, class SimdAbi>
  void operator()() {
    [[maybe_unused]]const typename ex::simd<_Tp, SimdAbi>::mask_type mask_{};
    [[maybe_unused]]ex::simd<_Tp, SimdAbi> simd_([](_Tp i) { return i; });
    [[maybe_unused]]const ex::simd<_Tp, SimdAbi> const_simd_([](_Tp i) { return i; });
    [[maybe_unused]]const ex::simd_mask<_Tp, SimdAbi> const_mask_(simd_ == const_simd_);
    [[maybe_unused]]constexpr size_t array_size = simd_.size();
    {
      auto pure_simd = +ex::where(mask_, simd_);
      static_assert(std::is_same_v<decltype(pure_simd), ex::simd<_Tp, SimdAbi> >);

      std::array<_Tp, array_size> expected_values;
      for (size_t i = 0; i < array_size; ++i) 
        expected_values[i] = static_cast<_Tp>(i);

      assert_simd_value_correct(pure_simd, expected_values);
    }
    {
      auto const_simd = +ex::where(mask_, const_simd_);
      static_assert(std::is_same_v<decltype(const_simd), ex::simd<_Tp, SimdAbi>>);

      std::array<_Tp, array_size> expected_values;
      for (size_t i = 0; i < array_size; ++i) 
        expected_values[i] = static_cast<_Tp>(i);

      assert_simd_value_correct(const_simd, expected_values);
    }
    {
      auto pure_mask = +ex::where(std::type_identity_t<ex::simd_mask<_Tp, SimdAbi>>(mask_), mask_);
      static_assert(std::is_same_v<decltype
    }
    /*
    {
      auto const_mask = +ex::where(std::type_identity_t<ex::simd_mask<_Tp, SimdAbi>>(mask_), const_mask_);
      assert(ex::all_of(const_mask == const_mask_) == true);
    }
    {
      _Tp val{1};
      auto data = +ex::where<_Tp>(true, val);
      assert(ex::all_of(data == ex::simd<_Tp, SimdAbi>(val)) == true);
    }
    {
      const _Tp val{1};
      auto data = +ex::where<_Tp>(true, val);
      assert(ex::all_of(data == ex::simd<_Tp, SimdAbi>(val)) == true);
    }
    */
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
  test_all_simd_abi<CheckSimdMaskWhere>();
}

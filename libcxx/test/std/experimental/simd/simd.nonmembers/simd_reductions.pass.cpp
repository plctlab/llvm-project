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
// template <class T, class Abi, class BinaryOperation = plus<>>
//   T reduce(const simd<T, Abi>&,
//            BinaryOperation = {});

// template <class M, class V, class BinaryOperation>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 typename V::value_type neutral_element,
//                                 BinaryOperation binary_op);

// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 plus<> binary_op = {}) noexcept;
// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 multiplies<> binary_op) noexcept;
// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 bit_and<> binary_op) noexcept;
// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 bit_or<> binary_op) noexcept;
// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 bit_xor<> binary_op) noexcept;

// template <class T, class Abi>
//   T hmin(const simd<T, Abi>&) noexcept;
// template <class M, class V>
//   typename V::value_type hmin(const const_where_expression<M, V>&) noexcept;
// template <class T, class Abi>
//   T hmax(const simd<T, Abi>&) noexcept;
// template <class M, class V>
//   typename V::value_type hmax(const const_where_expression<M, V>&) noexcept;

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;
#include <iostream>
struct CheckSimdReduction {
  template <class _Tp, class SimdAbi>
  void operator()() {
    const ex::simd<_Tp, SimdAbi> lhs(static_cast<_Tp>(5));
    const ex::simd<_Tp, SimdAbi> rhs([](_Tp i) { return i; });

    if constexpr (!std::is_floating_point_v<_Tp>) // ex::reduce has not finish?
    {
      _Tp result = ex::reduce(simd_, std::plus<>());
      _Tp expected{};
      for (size_t i = 0; i < simd_.size(); ++i)
        expected += simd_[i];
      assert(result == expected);
    }
    if constexpr (!std::is_floating_point_v<_Tp>) // ex::reduce has not finish?
    {
      const ex::simd<_Tp, SimdAbi> simd_([](_Tp i) { return i; });
      _Tp identity_element{};
      auto reduce_result = ex::reduce(ex::where(simd_ > 0, simd_), identity_element, std::plus<>());

      if (ex::none_of(simd_ > 0)) {
        assert(identity_element == reduce_result);
      } else {
        _Tp result = ex::reduce(simd_, std::plus<>());
        _Tp expected{};
        for (size_t i = 0; i < simd_.size(); ++i)
          expected += simd_[i];
        assert(result == expected);
      }
    }
    if constexpr (!std::is_floating_point_v<_Tp>) // ex::reduce has not finish?
    {
      const ex::simd<_Tp, SimdAbi> simd_([](_Tp i) { return i; });
      auto reduce_result = ex::reduce(ex::where(simd_ > 0, simd_), std::plus<>());

      if (ex::none_of(simd_ > 0)) {
        assert(0 == reduce_result);
      } else {
        _Tp result = ex::reduce(simd_, std::plus<>());
        _Tp expected{};
        for (size_t i = 0; i < simd_.size(); ++i)
          expected += simd_[i];
        assert(result == expected);
      }
    }
    if constexpr (!std::is_floating_point_v<_Tp>) // ex::reduce has not finish?
    {
      const ex::simd<_Tp, SimdAbi> simd_([](_Tp i) { return i; });
      auto reduce_result = ex::reduce(ex::where(simd_ > 0, simd_), std::multiplies<>());

      if (ex::none_of(simd_ > 0)) {
        assert(1 == reduce_result);
      } else {
        _Tp result = ex::reduce(simd_, std::multiplies<>());
        _Tp expected{1};
        for (size_t i = 0; i < simd_.size(); ++i)
          expected *= simd_[i];
        assert(result == expected);
      }
    }
    if constexpr (std::is_integral_v<_Tp> && std::is_signed_v<_Tp>) // ex::reduce has not finish?
    {
      const ex::simd<_Tp, SimdAbi> simd_([](_Tp i) { return i; });
      auto reduce_result = ex::reduce(ex::where(simd_ > 0, simd_), std::bit_and<>());

      if (ex::none_of(simd_ > 0)) {
        assert(~(_Tp()) == reduce_result);
      } else {
        _Tp result = ex::reduce(simd_, std::bit_and<>());
        _Tp expected{1};
        for (size_t i = 0; i < simd_.size(); ++i)
          expected &= simd_[i];
        assert(result == expected);
      }
    }
    if constexpr (std::is_integral_v<_Tp> && std::is_signed_v<_Tp>) // ex::reduce has not finish?
    {
      const ex::simd<_Tp, SimdAbi> simd_([](_Tp i) { return i; });
      auto reduce_result = ex::reduce(ex::where(simd_ > 0, simd_), std::bit_or<>());

      if (ex::none_of(simd_ > 0)) {
        assert(0 == reduce_result);
      } else {
        _Tp result = ex::reduce(simd_, std::bit_or<>());
        _Tp expected{0};
        for (size_t i = 0; i < simd_.size(); ++i)
          expected |= simd_[i];
        assert(result == expected);
      }
    }
    if constexpr (std::is_integral_v<_Tp> && std::is_signed_v<_Tp>) // ex::reduce has not finish?
    {
      const ex::simd<_Tp, SimdAbi> simd_([](_Tp i) { return i; });
      auto reduce_result = ex::reduce(ex::where(simd_ > 0, simd_), std::bit_xor<>());

      if (ex::none_of(simd_ > 0)) {
        assert(0 == reduce_result);
      } else {
        _Tp result = ex::reduce(simd_, std::bit_xor<>());
        _Tp expected{0};
        for (size_t i = 0; i < simd_.size(); ++i)
          expected ^= simd_[i];
        assert(result == expected);
      }
    }

    {
      const ex::simd<_Tp, SimdAbi> origin([](_Tp i) { return i; });
      assert(ex::hmin(origin) == 0);

      const ex::simd_mask<_Tp, SimdAbi> mask_(origin > 0);
      auto where_expr = ex::where(mask_, origin);
      _Tp result = ex::hmin(where_expr);

      if (ex::none_of(mask_)) {
        assert(std::numeric_limits<_Tp>::max() == result);
      } else {
        _Tp expected(std::numeric_limits<_Tp>::max());
        for (size_t i = 0; i < origin.size(); ++i) {
          if (mask_[i] == true) {
            if (expected == std::numeric_limits<_Tp>::max())
              expected = origin[i];
            else
              expected = std::min(expected, origin[i]);
          }
        }
        assert(result == expected);
      }
    }
    {
      const ex::simd<_Tp, SimdAbi> origin([](_Tp i) { return i; });
      assert(ex::hmax(origin) == static_cast<_Tp>(origin.size() - 1));

      const ex::simd_mask<_Tp, SimdAbi> mask_(origin > 0);
      auto where_expr = ex::where(mask_, origin);
      _Tp result = ex::hmax(where_expr);

      if (ex::none_of(mask_)) {
        assert(std::numeric_limits<_Tp>::lowest() == result);
      } else {
        _Tp expected{0};
        for (size_t i = 0; i < origin.size(); ++i) {
          if (mask_[i] == true) {
            if (expected == 0)
              expected = origin[i];
            else
              expected = std::max(expected, origin[i]);
          }
        }
        assert(result == expected);
      }
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
  test_all_simd_abi<CheckSimdReduction>();
}
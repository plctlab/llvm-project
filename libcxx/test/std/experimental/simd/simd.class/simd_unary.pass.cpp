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
// [simd.class]
// simd& operator++() noexcept;
// simd operator++(int) noexcept;
// simd& operator--() noexcept;
// simd operator--(int) noexcept;
// mask_type operator!() const noexcept;
// simd operator~() const noexcept;
// simd operator+() const noexcept;
// simd operator-() const noexcept;

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;
struct CheckSimdUnaryOperator {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    {
      ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });
      auto after_increment_simd = origin_simd.operator++();
      assert(ex::all_of(after_increment_simd == origin_simd) == true);

      ex::simd<_Tp, SimdAbi> expected_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });
      assert(ex::all_of(expected_simd == origin_simd) == true);
    }
    {
      ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });
      auto before_increment = origin_simd;

      int increment_value = static_cast<int>(_Np);

      auto after_increment_simd = origin_simd.operator++(increment_value);
      assert(ex::all_of(after_increment_simd == before_increment) == true);

      ex::simd<_Tp, SimdAbi> expected_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });
      assert(ex::all_of(expected_simd == origin_simd) == true);
    }
    {
      ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });
      auto after_decrement_simd = origin_simd.operator--();
      assert(ex::all_of(after_decrement_simd == origin_simd) == true);

      ex::simd<_Tp, SimdAbi> expected_simd([](_Tp i) { return i; });
      assert(ex::all_of(expected_simd == origin_simd) == true);
    }
    {
      ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });
      auto before_decrement = origin_simd;

      int decrement_value = static_cast<int>(_Np);

      auto after_decrement_simd = origin_simd.operator--(decrement_value);
      assert(ex::all_of(after_decrement_simd == before_decrement) == true);

      ex::simd<_Tp, SimdAbi> expected_simd([](_Tp i) { return i; });
      assert(ex::all_of(expected_simd == origin_simd) == true);
    }
    {
      const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });
      const auto origin_mask = origin_simd.operator!();
      for (size_t i = 0; i < origin_mask.size(); ++i) {
        assert(origin_mask[i] == !origin_simd.operator[](i));
      }
    }
    {
      if constexpr (std::is_integral_v<_Tp> && !std::is_unsigned_v<_Tp>) {
        const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });
        const auto after_inverse_simd = origin_simd.operator~();

        for (size_t i = 0; i < after_inverse_simd.size(); ++i) {
          assert(after_inverse_simd[i] == ~origin_simd.operator[](i));
        }
      }
    }
    {
      const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });
      const auto expected_simd = origin_simd.operator+();
      assert(ex::all_of(expected_simd == origin_simd) == true);
    }
    {
      if constexpr (!std::is_unsigned_v<_Tp>) {
        const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });
        const auto expected_simd = origin_simd.operator-();

        for (size_t i = 0; i < expected_simd.size(); ++i) {
          assert(expected_simd[i] == -origin_simd.operator[](i));
        }
      }
    }
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  F{}.template operator()<_Tp, SimdAbi, _Np>();
  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main(int, char**) {
  test_all_simd_abi<CheckSimdUnaryOperator>();
}
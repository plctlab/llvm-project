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
// [simd.mask.class]
// explicit simd_mask(value_type) noexcept;
// template<class U> simd_mask(const simd_mask<U, simd_abi::fixed_size<size()>>&) noexcept;
// template<class Flags> simd_mask(const value_type* mem, Flags);

#include "../test_utils.h"
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdMaskCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;
    {
      const ex::simd_mask<_Tp, SimdAbi> mask_ctor_from_broadcast(false);
      const std::array<bool, array_size> expected_value{};
      assert_simd_mask_value_correct(mask_ctor_from_broadcast, expected_value);
    }
    {
      if constexpr (std::is_same_v<SimdAbi, ex::simd_abi::fixed_size<_Np>>) {
        ex::simd_mask<_Tp, SimdAbi> origin_fixed_size_abi_mask;
        for (size_t i = 0; i < array_size; i++)
          origin_fixed_size_abi_mask[i] = static_cast<bool>(i % 2);
        ex::simd_mask<_Tp, SimdAbi> mask_ctor_from_fixed_abi(origin_fixed_size_abi_mask);

        std::array<bool, array_size> expected_value;
        for (size_t i = 0; i < array_size; i++)
          expected_value[i] = static_cast<bool>(i % 2);

        assert_simd_mask_value_correct<array_size, bool>(mask_ctor_from_fixed_abi, expected_value);
      }
    }
    {
      alignas(alignof(bool)) bool expected_value[array_size];
      for (size_t i = 0; i < array_size; i++)
        expected_value[i] = static_cast<bool>(i % 2);

      ex::simd_mask<_Tp, SimdAbi> simd_mask_(expected_value, ex::element_aligned_tag());
      assert_simd_mask_value_correct(simd_mask_, expected_value);
    }
    {
      alignas(ex::memory_alignment_v<ex::simd_mask<_Tp, SimdAbi>>) bool expected_value[array_size];
      for (size_t i = 0; i < array_size; i++)
        expected_value[i] = static_cast<bool>(i % 2);

      ex::simd_mask<_Tp, SimdAbi> simd_mask_(expected_value, ex::vector_aligned_tag());
      assert_simd_mask_value_correct(simd_mask_, expected_value);
    }
    {
      alignas(ex::memory_alignment_v<ex::simd_mask<_Tp, SimdAbi>>) bool expected_value[array_size];
      for (size_t i = 0; i < array_size; i++)
        expected_value[i] = static_cast<bool>(i % 2);

      ex::simd_mask<_Tp, SimdAbi> simd_mask_(expected_value, ex::overaligned_tag<sizeof(bool)>());
      assert_simd_mask_value_correct(simd_mask_, expected_value);
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

int main() {
  test_all_simd_abi<CheckSimdMaskCtor>();
}
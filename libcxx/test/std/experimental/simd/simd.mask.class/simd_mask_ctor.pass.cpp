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

struct CheckBroadCastSimdMaskCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;

    const ex::simd_mask<_Tp, SimdAbi> mask_ctor_from_broadcast(false);
    const std::array<bool, array_size> expected_value{};
    assert_simd_mask_value_correct(mask_ctor_from_broadcast, expected_value);
  }
};

#define GENERATE_FOR_FIXED_SIMD_MASK_CTOR(_Up, suffix)                                                                 \
  ex::simd_mask<_Up, SimdAbi> suffix##_mask;                                                                           \
  std::array<bool, _Np> expected_value_in_##suffix;                                                                    \
  for (size_t i = 0; i < _Np; i++) {                                                                                   \
    suffix##_mask[i]              = static_cast<bool>(i % 2);                                                          \
    expected_value_in_##suffix[i] = suffix##_mask[i];                                                                  \
  }                                                                                                                    \
  ex::simd_mask<_Tp, SimdAbi> fixed_mask_from_type_##suffix(suffix##_mask);                                            \
  assert_simd_mask_value_correct(fixed_mask_from_type_##suffix, expected_value_in_##suffix);

struct CheckFixedSimdMaskCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same_v<SimdAbi, ex::simd_abi::fixed_size<_Np>>) {
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(char16_t, char16)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(char32_t, char32)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(unsigned char, uchar)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(signed char, schar)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(wchar_t, wchar)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(unsigned short, ushort)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(short, short)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(unsigned int, uint)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(int, int)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(unsigned long, ulong)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(long, long)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(unsigned long long, ulonglong)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(long long, longlong)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(float, float)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(double, double)
      GENERATE_FOR_FIXED_SIMD_MASK_CTOR(long double, longdouble)
    }
  }
};

struct CheckLoadSimdMaskCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;
    {
      alignas(ex::memory_alignment_v<ex::simd_mask<_Tp, SimdAbi>>) bool buffer[array_size];
      std::array<bool, array_size> expected_value;
      for (size_t i = 0; i < array_size; i++) {
        buffer[i]         = static_cast<bool>(i % 2);
        expected_value[i] = buffer[i];
      }
      ex::simd_mask<_Tp, SimdAbi> simd_mask(buffer, ex::vector_aligned_tag());
      assert_simd_mask_value_correct(simd_mask, expected_value);
    }
    {
      alignas(8) bool buffer[array_size];
      std::array<bool, array_size> expected_value;
      for (size_t i = 0; i < array_size; i++) {
        buffer[i]         = static_cast<bool>(i % 2);
        expected_value[i] = buffer[i];
      }
      ex::simd_mask<_Tp, SimdAbi> simd_mask(buffer, ex::overaligned_tag<8>());
      assert_simd_mask_value_correct(simd_mask, expected_value);
    }
    {
      alignas(alignof(bool)) bool buffer[array_size];
      std::array<bool, array_size> expected_value;
      for (size_t i = 0; i < array_size; i++) {
        buffer[i]         = static_cast<bool>(i % 2);
        expected_value[i] = buffer[i];
      }
      ex::simd_mask<_Tp, SimdAbi> simd_mask(buffer, ex::element_aligned_tag());
      assert_simd_mask_value_correct(simd_mask, expected_value);
    }
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  F{}.template operator()<_Tp, SimdAbi, _Np>();
  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main(int, char**) {
  test_all_simd_abi<CheckBroadCastSimdMaskCtor>();
  test_all_simd_abi<CheckFixedSimdMaskCtor>();
  test_all_simd_abi<CheckLoadSimdMaskCtor>();
  return 0;
}

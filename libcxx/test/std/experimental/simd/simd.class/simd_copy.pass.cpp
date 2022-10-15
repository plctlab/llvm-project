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
// template <class U, class Flags> void copy_from(const U* mem, Flags f);
// template <class U, class Flags> void copy_to(U* mem, Flags f);

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

// credit to: https://stackoverflow.com/a/466242
constexpr size_t next_pow2(size_t v) noexcept {
  v--;
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v++;
  return v;
}
template <class T>
constexpr bool is_pow2(T x) noexcept {
  return x != 0 && (x & (x - 1)) == 0;
}
struct CheckSimdCopyFrom {
  template <class _Tp, class SimdAbi, size_t _Np>
  void operator()() {
    if constexpr (is_pow2(_Np) == true) { // waiting to more check
      constexpr auto alignas_size = next_pow2(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>, _Tp>);
      ex::simd<_Tp, SimdAbi> origin_simd;

      constexpr auto array_length = origin_simd.size();

      alignas(alignas_size) _Tp buffer[array_length];
      for (size_t i = 0; i < array_length; i++)
        buffer[i] = static_cast<_Tp>(i + 1);

      origin_simd.copy_from(buffer, ex::vector_aligned_tag());

      ex::simd<_Tp, SimdAbi> expected_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });

      assert(ex::all_of(expected_simd == origin_simd) == true);
    }

    {
      constexpr auto alignas_size = std::max(next_pow2(sizeof(_Tp)), next_pow2(_Np));
      ex::simd<_Tp, SimdAbi> origin_simd;
      constexpr auto array_length = origin_simd.size();

      alignas(alignas_size) _Tp buffer[array_length];
      for (size_t i = 0; i < array_length; i++)
        buffer[i] = static_cast<_Tp>(i);

      origin_simd.copy_from(buffer, ex::overaligned_tag<alignas_size>());

      ex::simd<_Tp, SimdAbi> expected_simd([](_Tp i) { return static_cast<_Tp>(i); });

      assert(ex::all_of(expected_simd == origin_simd) == true);
    }

    {
      constexpr auto alignas_size = std::max(next_pow2(sizeof(_Tp)), next_pow2(alignof(_Tp)));
      ex::simd<_Tp, SimdAbi> origin_simd;
      constexpr auto array_length = origin_simd.size();

      alignas(alignas_size) _Tp buffer[array_length];
      for (size_t i = 0; i < array_length; i++)
        buffer[i] = static_cast<_Tp>(i);

      origin_simd.copy_from(buffer, ex::overaligned_tag<alignas_size>());

      ex::simd<_Tp, SimdAbi> expected_simd([](_Tp i) { return static_cast<_Tp>(i); });

      assert(ex::all_of(expected_simd == origin_simd) == true);
    }
  }
};

struct CheckSimdCopyTo {
  template <class _Tp, class SimdAbi, size_t _Np>
  void operator()() {
    if constexpr (is_pow2(_Np) == true) { // waiting to more check
      constexpr auto alignas_size = next_pow2(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>, _Tp>);

      const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });
      constexpr auto array_length = origin_simd.size();
      alignas(alignas_size) _Tp expected_buffer[array_length]{};

      origin_simd.copy_to(expected_buffer, ex::vector_aligned_tag());

      for (size_t i = 0; i < origin_simd.size(); i++)
        assert(expected_buffer[i] == static_cast<_Tp>(i + 1));
    }

    {
      constexpr auto alignas_size = std::max(next_pow2(sizeof(_Tp)), next_pow2(_Np));
      const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });

      constexpr auto array_length = origin_simd.size();

      alignas(alignas_size) _Tp expected_buffer[array_length]{};

      origin_simd.copy_to(expected_buffer, ex::overaligned_tag<alignas_size>());

      for (size_t i = 0; i < array_length; i++)
        assert(expected_buffer[i] == static_cast<_Tp>(i + 1));
    }

    {
      constexpr auto alignas_size = std::max(next_pow2(sizeof(_Tp)), next_pow2(alignof(_Tp)));
      const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });

      constexpr auto array_length = origin_simd.size();

      alignas(alignas_size) _Tp expected_buffer[array_length]{};

      origin_simd.copy_to(expected_buffer, ex::element_aligned_tag());

      for (size_t i = 0; i < array_length; i++)
        assert(expected_buffer[i] == static_cast<_Tp>(i + 1));
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
  test_all_simd_abi<CheckSimdCopyFrom>();
  test_all_simd_abi<CheckSimdCopyTo>();
}
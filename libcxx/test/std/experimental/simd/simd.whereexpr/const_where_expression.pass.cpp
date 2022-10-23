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
// // [simd.whereexpr]
// template <class M, class T>
// class const_where_expression {
//   const M& mask; // exposition only
//   T& data; // exposition only
// public:
//   const_where_expression(const const_where_expression&) = delete;
//   const_where_expression& operator=(const const_where_expression&) = delete;
//   T operator-() const && noexcept;
//   T operator+() const && noexcept;
//   T operator~() const && noexcept;
//   template<class U, class Flags> void copy_to(U* mem, Flags f) const &&;
// };

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckConstWhereExprOperatorMinus {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (ex::simd_size_v<_Tp, SimdAbi> >= 2 && !std::is_unsigned_v<_Tp>) {
      const ex::simd<_Tp, SimdAbi> a([](_Tp i) { return i; });
      auto b = -ex::where(a < static_cast<_Tp>(2), a);
      assert(b[0] == static_cast<_Tp>(0));
      assert(b[1] == -static_cast<_Tp>(1));
      for (size_t i = 2; i < b.size(); ++i) {
        assert(b[i] == static_cast<_Tp>(i));
      }
    }
  }
};

struct CheckConstWhereExprOperatorPositive {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    const ex::simd<_Tp, SimdAbi> a([](_Tp i) { return i; });
    auto b = +ex::where(a < static_cast<_Tp>(2), a);
    for (size_t i = 0; i < b.size(); ++i) {
      assert(b[i] == static_cast<_Tp>(i));
    }
  }
};

struct CheckConstWhereExprOperatorNegation {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    const ex::simd_mask<_Tp, SimdAbi> a([](_Tp i) { return i; });
    auto b = ~ex::where(true, a);
    for (size_t i = 0; i < b.size(); ++i) {
      assert(!b[i]);
    }
  }
};

struct CheckConstWhereExprCopyTo {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    {
      const ex::simd<_Tp, SimdAbi> simd_(static_cast<_Tp>(5));
      constexpr size_t array_length = simd_.size();
      alignas(alignof(_Tp)) _Tp arr[array_length]{};

      ex::where(simd_ > 0, simd_).copy_to(arr, ex::element_aligned_tag());
      for (size_t i = 0; i < array_length; i++) {
        assert(arr[i] == static_cast<_Tp>(5));
      }
    }
    {
      const ex::simd<_Tp, SimdAbi> simd_(static_cast<_Tp>(5));
      constexpr size_t array_length = simd_.size();
      alignas(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>, _Tp>) _Tp arr[array_length]{};

      ex::where(simd_ > 0, simd_).copy_to(arr, ex::vector_aligned_tag());
      for (size_t i = 0; i < array_length; i++) {
        assert(arr[i] == static_cast<_Tp>(5));
      }
    }

    {
      const ex::simd<_Tp, SimdAbi> simd_(static_cast<_Tp>(5));
      constexpr size_t array_length = simd_.size();
      alignas(alignof(_Tp)) _Tp arr[array_length]{};

      ex::where(simd_ > 0, simd_).copy_to(arr, ex::overaligned_tag<alignof(_Tp)>());
      for (size_t i = 0; i < array_length; i++) {
        assert(arr[i] == static_cast<_Tp>(5));
      }
    }
    {
      const ex::simd<_Tp, SimdAbi> simd_(static_cast<_Tp>(5));
      constexpr size_t array_length = simd_.size();
      alignas(alignof(_Tp)) _Tp arr[array_length]{};

      ex::where(simd_ > 0, simd_).copy_to(arr, ex::element_aligned_tag());
      for (size_t i = 0; i < array_length; i++) {
        assert(arr[i] == static_cast<_Tp>(5));
      }
    }
    {
      constexpr ex::simd_mask<_Tp, SimdAbi> a{};

      if constexpr (a.size() == 4) {
        bool buffer[] = {true, true, false, false};
        ex::where(a, a).copy_to(buffer, ex::element_aligned_tag());
        assert(buffer[0]);
        assert(buffer[1]);
        assert(!buffer[2]);
        assert(!buffer[3]);
      }
    }
    {
      _Tp val = static_cast<_Tp>(1);
      ex::where(true, static_cast<_Tp>(3)).copy_to(&val, ex::element_aligned_tag());
      assert(val == static_cast<_Tp>(3));
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
  test_all_simd_abi<CheckConstWhereExprOperatorMinus>();
  test_all_simd_abi<CheckConstWhereExprOperatorPositive>();
  test_all_simd_abi<CheckConstWhereExprOperatorNegation>();
  test_all_simd_abi<CheckConstWhereExprCopyTo>();
}

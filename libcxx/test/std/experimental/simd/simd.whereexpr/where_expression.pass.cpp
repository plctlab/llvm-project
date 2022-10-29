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
// class where_expression : public const_where_expression<M, T> {
// public:
//   where_expression(const where_expression&) = delete;
//   where_expression& operator=(const where_expression&) = delete;
//   template <class U> void operator=(U&& x);
//   template <class U> void operator+=(U&& x);
//   template <class U> void operator-=(U&& x);
//   template <class U> void operator*=(U&& x);
//   template <class U> void operator/=(U&& x);
//   template <class U> void operator%=(U&& x);
//   template <class U> void operator&=(U&& x);
//   template <class U> void operator|=(U&& x);
//   template <class U> void operator^=(U&& x);
//   template <class U> void operator<<=(U&& x);
//   template <class U> void operator>>=(U&& x);
//   void operator++();
//   void operator++(int);
//   void operator--();
//   void operator--(int);
//   template <class U, class Flags> void copy_from(const U* mem, Flags);
// };

#include "../test_utils.h"
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckWhereExprOperators {
  template <class _Tp, class SimdAbi>
  void operator()() {
    if constexpr (ex::simd_size_v<_Tp, SimdAbi> == 4) {
      {
        ex::simd_mask<_Tp, SimdAbi> lhs(true);
        ex::simd_mask<_Tp, SimdAbi> rhs(false);
        ex::where(lhs, rhs) = lhs;
        assert(rhs[0] == true);
        assert(rhs[1] == true);
        assert(rhs[2] == true);
        assert(rhs[3] == true);
      }
      {
        _Tp buf[]{1, 2, 3, 4};
        ex::simd<_Tp, SimdAbi> lhs;
        lhs.copy_from(buf, ex::element_aligned_tag());
        ex::simd_mask<_Tp, SimdAbi> rhs(true);

        ex::where(rhs, lhs) += 2;
        assert(lhs[0] == static_cast<_Tp>(3));
        assert(lhs[1] == static_cast<_Tp>(4));
        assert(lhs[2] == static_cast<_Tp>(5));
        assert(lhs[3] == static_cast<_Tp>(6));
      }
      {
        _Tp buf[]{1, 2, 3, 4};
        ex::simd<_Tp, SimdAbi> lhs;
        lhs.copy_from(buf, ex::element_aligned_tag());
        ex::simd_mask<_Tp, SimdAbi> rhs(true);

        ex::where(rhs, lhs) -= 2;
        assert(lhs[0] == static_cast<_Tp>(-1));
        assert(lhs[1] == static_cast<_Tp>(0));
        assert(lhs[2] == static_cast<_Tp>(1));
        assert(lhs[3] == static_cast<_Tp>(2));
      }
      {
        _Tp buf[]{2, 2, 4, 4};
        ex::simd<_Tp, SimdAbi> lhs;
        lhs.copy_from(buf, ex::element_aligned_tag());
        ex::simd_mask<_Tp, SimdAbi> rhs(true);

        ex::where(rhs, lhs) /= 2;
        assert(lhs[0] == static_cast<_Tp>(1));
        assert(lhs[1] == static_cast<_Tp>(1));
        assert(lhs[2] == static_cast<_Tp>(2));
        assert(lhs[3] == static_cast<_Tp>(2));
      }
      {
        if constexpr (!std::is_floating_point_v<_Tp>()) {
          _Tp buf[]{3, 3, 4, 4};
          ex::simd<_Tp, SimdAbi> lhs;
          lhs.copy_from(buf, ex::element_aligned_tag());
          ex::simd_mask<_Tp, SimdAbi> rhs(true);

          ex::where(rhs, lhs) %= 2;
          assert(lhs[0] == static_cast<_Tp>(1));
          assert(lhs[1] == static_cast<_Tp>(1));
          assert(lhs[2] == static_cast<_Tp>(0));
          assert(lhs[3] == static_cast<_Tp>(0));
        }
      }
      {
        if constexpr (!std::is_floating_point_v<_Tp>()) {
          _Tp buf[]{3, 3, 4, 4};
          ex::simd<_Tp, SimdAbi> lhs;
          lhs.copy_from(buf, ex::element_aligned_tag());
          ex::simd_mask<_Tp, SimdAbi> rhs(true);

          ex::where(rhs, lhs) &= 2;
          assert(lhs[0] == static_cast<_Tp>(2));
          assert(lhs[1] == static_cast<_Tp>(2));
          assert(lhs[2] == static_cast<_Tp>(0));
          assert(lhs[3] == static_cast<_Tp>(0));
        }
      }
      {
        if constexpr (!std::is_floating_point_v<_Tp>()) {
          _Tp buf[]{3, 3, 4, 4};
          ex::simd<_Tp, SimdAbi> lhs;
          lhs.copy_from(buf, ex::element_aligned_tag());
          ex::simd_mask<_Tp, SimdAbi> rhs(true);

          ex::where(rhs, lhs) |= 2;
          assert(lhs[0] == static_cast<_Tp>(3));
          assert(lhs[1] == static_cast<_Tp>(3));
          assert(lhs[2] == static_cast<_Tp>(6));
          assert(lhs[3] == static_cast<_Tp>(6));
        }
      }
      {
        if constexpr (!std::is_floating_point_v<_Tp>()) {
          _Tp buf[]{3, 3, 4, 4};
          ex::simd<_Tp, SimdAbi> lhs;
          lhs.copy_from(buf, ex::element_aligned_tag());
          ex::simd_mask<_Tp, SimdAbi> rhs(true);

          ex::where(rhs, lhs) ^= 2;
          assert(lhs[0] == static_cast<_Tp>(1));
          assert(lhs[1] == static_cast<_Tp>(1));
          assert(lhs[2] == static_cast<_Tp>(6));
          assert(lhs[3] == static_cast<_Tp>(6));
        }
      }
      {
        if constexpr (!std::is_floating_point_v<_Tp>()) {
          _Tp buf[]{3, 3, 4, 4};
          ex::simd<_Tp, SimdAbi> lhs;
          lhs.copy_from(buf, ex::element_aligned_tag());
          ex::simd_mask<_Tp, SimdAbi> rhs(true);

          ex::where(rhs, lhs).operator<<=(2);
          assert(lhs[0] == static_cast<_Tp>(12));
          assert(lhs[1] == static_cast<_Tp>(12));
          assert(lhs[2] == static_cast<_Tp>(16));
          assert(lhs[3] == static_cast<_Tp>(16));
        }
      }
      {
        if constexpr (!std::is_floating_point_v<_Tp>()) {
          _Tp buf[]{3, 3, 4, 4};
          ex::simd<_Tp, SimdAbi> lhs;
          lhs.copy_from(buf, ex::element_aligned_tag());
          ex::simd_mask<_Tp, SimdAbi> rhs(true);

          ex::where(rhs, lhs).operator>>=(2);
          assert(lhs[0] == static_cast<_Tp>(0));
          assert(lhs[1] == static_cast<_Tp>(0));
          assert(lhs[2] == static_cast<_Tp>(1));
          assert(lhs[3] == static_cast<_Tp>(1));
        }
      }
      {
        _Tp buf[]{1, 2, 3, 4};
        ex::simd<_Tp, SimdAbi> lhs;
        lhs.copy_from(buf, ex::element_aligned_tag());
        ex::simd_mask<_Tp, SimdAbi> rhs(true);

        ex::where(rhs, lhs) *= 2;
        assert(lhs[0] == static_cast<_Tp>(2));
        assert(lhs[1] == static_cast<_Tp>(4));
        assert(lhs[2] == static_cast<_Tp>(6));
        assert(lhs[3] == static_cast<_Tp>(8));
      }
      {
        _Tp buf[]{1, 2, 3, 4};
        ex::simd<_Tp, SimdAbi> lhs;
        lhs.copy_from(buf, ex::element_aligned_tag());
        ex::simd_mask<_Tp, SimdAbi> rhs(true);

        ex::where(rhs, lhs)++;
        assert(lhs[0] == static_cast<_Tp>(2));
        assert(lhs[1] == static_cast<_Tp>(3));
        assert(lhs[2] == static_cast<_Tp>(4));
        assert(lhs[3] == static_cast<_Tp>(5));
      }
      {
        _Tp buf[]{1, 2, 3, 4};
        ex::simd<_Tp, SimdAbi> lhs;
        lhs.copy_from(buf, ex::element_aligned_tag());
        ex::simd_mask<_Tp, SimdAbi> rhs(true);

        ex::where(rhs, lhs).operator++(2);
        assert(lhs[0] == static_cast<_Tp>(2));
        assert(lhs[1] == static_cast<_Tp>(3));
        assert(lhs[2] == static_cast<_Tp>(4));
        assert(lhs[3] == static_cast<_Tp>(5));
      }
      {
        _Tp buf[]{1, 2, 3, 4};
        ex::simd<_Tp, SimdAbi> lhs;
        lhs.copy_from(buf, ex::element_aligned_tag());
        ex::simd_mask<_Tp, SimdAbi> rhs(true);

        ex::where(rhs, lhs)--;
        assert(lhs[0] == static_cast<_Tp>(0));
        assert(lhs[1] == static_cast<_Tp>(1));
        assert(lhs[2] == static_cast<_Tp>(2));
        assert(lhs[3] == static_cast<_Tp>(3));
      }
      {
        _Tp buf[]{1, 2, 3, 4};
        ex::simd<_Tp, SimdAbi> lhs;
        lhs.copy_from(buf, ex::element_aligned_tag());
        ex::simd_mask<_Tp, SimdAbi> rhs(true);

        ex::where(rhs, lhs).operator--(2);
        assert(lhs[0] == static_cast<_Tp>(0));
        assert(lhs[1] == static_cast<_Tp>(1));
        assert(lhs[2] == static_cast<_Tp>(2));
        assert(lhs[3] == static_cast<_Tp>(3));
      }
    }
  }
};

struct CheckWhereExprCopyFrom {
  template <class _Tp, class SimdAbi>
  void operator()() {
    if constexpr (ex::simd_size_v<_Tp, SimdAbi> == 4) {
      {
        alignas(alignof(_Tp))
            const _Tp buffer[]{static_cast<_Tp>(-1), static_cast<_Tp>(-2), static_cast<_Tp>(-3), static_cast<_Tp>(-4)};
        ex::simd<_Tp, SimdAbi> lhs([](_Tp i) { return i; });
        ex::where(lhs < 2, lhs).copy_from(buffer, ex::element_aligned_tag());
        assert(lhs[0] == static_cast<_Tp>(-1));
        assert(lhs[1] == static_cast<_Tp>(-2));
        assert(lhs[2] == static_cast<_Tp>(2));
        assert(lhs[3] == static_cast<_Tp>(3));
      }
      {
        alignas(alignof(_Tp))
            const _Tp buffer[]{static_cast<_Tp>(-1), static_cast<_Tp>(-2), static_cast<_Tp>(-3), static_cast<_Tp>(-4)};
        ex::simd<_Tp, SimdAbi> lhs([](_Tp i) { return i; });
        ex::where(lhs < 2, lhs).copy_from(buffer, ex::overaligned_tag<alignof(_Tp)>());
        assert(lhs[0] == static_cast<_Tp>(-1));
        assert(lhs[1] == static_cast<_Tp>(-2));
        assert(lhs[2] == static_cast<_Tp>(2));
        assert(lhs[3] == static_cast<_Tp>(3));
      }
      {
        alignas(ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>, _Tp>)
            const _Tp buffer[]{static_cast<_Tp>(-1), static_cast<_Tp>(-2), static_cast<_Tp>(-3), static_cast<_Tp>(-4)};
        ex::simd<_Tp, SimdAbi> lhs([](_Tp i) { return i; });
        ex::where(lhs < 2, lhs).copy_from(buffer, ex::vector_aligned_tag());
        assert(lhs[0] == static_cast<_Tp>(-1));
        assert(lhs[1] == static_cast<_Tp>(-2));
        assert(lhs[2] == static_cast<_Tp>(2));
        assert(lhs[3] == static_cast<_Tp>(3));
      }
    }

    {
      constexpr _Tp rhs = static_cast<_Tp>(1);
      _Tp lhs = 3;
      ex::where(true, lhs).copy_from(&rhs, ex::element_aligned_tag());
      assert(lhs == 1);
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
  test_all_simd_abi<CheckWhereExprOperators>();
  test_all_simd_abi<CheckWhereExprCopyFrom>();
}

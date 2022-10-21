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
// friend simd& operator+=(simd& lhs, const simd& rhs) noexcept;
// friend simd& operator-=(simd& lhs, const simd& rhs) noexcept;
// friend simd& operator*=(simd& lhs, const simd& rhs) noexcept;
// friend simd& operator/=(simd& lhs, const simd& rhs) noexcept;
// friend simd& operator%=(simd& lhs, const simd& rhs) noexcept;
// friend simd& operator&=(simd& lhs, const simd& rhs) noexcept;
// friend simd& operator|=(simd& lhs, const simd& rhs) noexcept;
// friend simd& operator^=(simd& lhs, const simd& rhs) noexcept;
// friend simd& operator<<=(simd& lhs, const simd& rhs) noexcept;
// friend simd& operator>>=(simd& lhs, const simd& rhs) noexcept;
#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdCassign {
  template <class _Tp, class SimdAbi>
  void operator()() {
    ex::simd<_Tp, SimdAbi> lhs([](_Tp i) { return static_cast<_Tp>(i + 1); });
    const ex::simd<_Tp, SimdAbi> rhs([](_Tp i) { return i; });

    {
      auto check_operator_work_from_rhs = rhs[0];
      check_operator_work_from_rhs += rhs[0];
      assert(check_operator_work_from_rhs == rhs[0] + rhs[0]);

      const auto origin_lhs_backup = lhs;
      ex::simd<_Tp, SimdAbi> result_plus_simd = lhs += rhs;
      assert(ex::all_of(result_plus_simd == lhs) == true);
      for (size_t i = 0; i < result_plus_simd.size(); ++i)
        assert(result_plus_simd[i] == origin_lhs_backup[i] + rhs[i]);
      lhs = origin_lhs_backup;
    }
    {
      auto check_operator_work_from_rhs = rhs[0];
      check_operator_work_from_rhs -= rhs[0];
      assert(check_operator_work_from_rhs == rhs[0] - rhs[0]);

      const auto origin_lhs_backup = lhs;
      ex::simd<_Tp, SimdAbi> result_minus_simd = lhs -= rhs;
      assert(ex::all_of(result_minus_simd == lhs) == true);
      for (size_t i = 0; i < result_minus_simd.size(); ++i)
        assert(result_minus_simd[i] == origin_lhs_backup[i] - rhs[i]);
      lhs = origin_lhs_backup;
    }
    {
      auto check_operator_work_from_rhs = rhs[0];
      check_operator_work_from_rhs *= rhs[0];
      assert(check_operator_work_from_rhs == rhs[0] * rhs[0]);

      const auto origin_lhs_backup = lhs;
      ex::simd<_Tp, SimdAbi> result_multiply_simd = lhs *= rhs;
      assert(ex::all_of(result_multiply_simd == lhs) == true);
      for (size_t i = 0; i < result_multiply_simd.size(); ++i)
        assert(result_multiply_simd[i] == origin_lhs_backup[i] * rhs[i]);
      lhs = origin_lhs_backup;
    }
    {
      auto check_operator_work_from_lhs = lhs[0];
      auto check_operator_work_from_rhs = rhs[0];
      check_operator_work_from_lhs /= check_operator_work_from_rhs;
      assert(check_operator_work_from_lhs == lhs[0] / check_operator_work_from_rhs);

      const auto origin_lhs_backup = lhs;
      ex::simd<_Tp, SimdAbi> result_division_simd = lhs /= rhs;
      assert(ex::all_of(result_division_simd == lhs) == true);
      for (size_t i = 0; i < result_division_simd.size(); ++i)
        assert(result_division_simd[i] == (origin_lhs_backup[i] / rhs[i]));
      lhs = origin_lhs_backup;
    }
    {
      if constexpr (std::is_integral_v<_Tp>) {
        auto check_operator_work_from_lhs = lhs[0];
        auto check_operator_work_from_rhs = rhs[0];
        check_operator_work_from_lhs %= check_operator_work_from_rhs;
        assert(check_operator_work_from_lhs == lhs[0] % check_operator_work_from_rhs);

        const auto origin_lhs_backup = lhs;
        ex::simd<_Tp, SimdAbi> result_mod_simd = lhs %= rhs;
        assert(ex::all_of(result_mod_simd == lhs) == true);
        for (size_t i = 0; i < result_mod_simd.size(); ++i)
          assert(result_mod_simd[i] == (origin_lhs_backup[i] % rhs[i]));
        lhs = origin_lhs_backup;
      }
    }
    {
      if constexpr (std::is_integral_v<_Tp>) {
        auto check_operator_work_from_rhs = rhs[0];
        check_operator_work_from_rhs &= rhs[0];
        assert(check_operator_work_from_rhs == (rhs[0] & rhs[0]));

        const auto origin_lhs_backup = lhs;
        ex::simd<_Tp, SimdAbi> result_and_simd = lhs &= rhs;
        assert(ex::all_of(result_and_simd == lhs) == true);
        for (size_t i = 0; i < result_and_simd.size(); ++i)
          assert(result_and_simd[i] == (origin_lhs_backup[i] & rhs[i]));
        lhs = origin_lhs_backup;
      }
    }
    {
      if constexpr (std::is_integral_v<_Tp>) {
        auto check_operator_work_from_rhs = rhs[0];
        check_operator_work_from_rhs |= rhs[0];
        assert(check_operator_work_from_rhs == (rhs[0] | rhs[0]));

        const auto origin_lhs_backup = lhs;
        ex::simd<_Tp, SimdAbi> result_or_simd = lhs |= rhs;
        assert(ex::all_of(result_or_simd == lhs) == true);
        for (size_t i = 0; i < result_or_simd.size(); ++i)
          assert(result_or_simd[i] == (origin_lhs_backup[i] | rhs[i]));
        lhs = origin_lhs_backup;
      }
    }
    {
      if constexpr (std::is_integral_v<_Tp>) {
        auto check_operator_work_from_rhs = rhs[0];
        check_operator_work_from_rhs ^= rhs[0];
        assert(check_operator_work_from_rhs == (rhs[0] ^ rhs[0]));

        const auto origin_lhs_backup = lhs;
        ex::simd<_Tp, SimdAbi> result_exor_simd = lhs ^= rhs;
        assert(ex::all_of(result_exor_simd == lhs) == true);
        for (size_t i = 0; i < result_exor_simd.size(); ++i)
          assert(result_exor_simd[i] == (origin_lhs_backup[i] ^ rhs[i]));
        lhs = origin_lhs_backup;
      }
    }
    {
      if constexpr (std::is_integral_v<_Tp>) {
        auto check_operator_work_from_rhs = rhs[0];
        check_operator_work_from_rhs <<= rhs[0];
        assert(check_operator_work_from_rhs == (rhs[0] << rhs[0]));

        const auto origin_lhs_backup = lhs;
        ex::simd<_Tp, SimdAbi> result_shift_left_simd = lhs <<= rhs;
        assert(ex::all_of(result_shift_left_simd == lhs) == true);
        for (size_t i = 0; i < result_shift_left_simd.size(); ++i)
          assert(result_shift_left_simd[i] == (origin_lhs_backup[i] << rhs[i]));
        lhs = origin_lhs_backup;
      }
    }
    {
      if constexpr (std::is_integral_v<_Tp>) {
        auto check_operator_work_from_rhs = rhs[0];
        check_operator_work_from_rhs >>= rhs[0];
        assert(check_operator_work_from_rhs == (rhs[0] >> rhs[0]));

        const auto origin_lhs_backup = lhs;
        ex::simd<_Tp, SimdAbi> result_shift_right_simd = lhs >>= rhs;
        assert(ex::all_of(result_shift_right_simd == lhs) == true);
        for (size_t i = 0; i < result_shift_right_simd.size(); ++i)
          assert(result_shift_right_simd[i] == (origin_lhs_backup[i] >> rhs[i]));
        lhs = origin_lhs_backup;
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
  test_all_simd_abi<CheckSimdCassign>();
}

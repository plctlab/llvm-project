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
// [simd.reference]
// template<class U> reference operator=(U&& x) && noexcept;
// template<class U> reference operator+=(U&& x) && noexcept;
// template<class U> reference operator-=(U&& x) && noexcept;
// template<class U> reference operator*=(U&& x) && noexcept;
// template<class U> reference operator/=(U&& x) && noexcept;
// template<class U> reference operator%=(U&& x) && noexcept;
// template<class U> reference operator|=(U&& x) && noexcept;
// template<class U> reference operator&=(U&& x) && noexcept;
// template<class U> reference operator^=(U&& x) && noexcept;
// template<class U> reference operator<<=(U&& x) && noexcept;
// template<class U> reference operator>>=(U&& x) && noexcept;
// reference operator++() && noexcept;
// value_type operator++(int) && noexcept;
// reference operator--() && noexcept;
// value_type operator--(int) && noexcept;

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

template <class T>
struct is_simd_reference : std::false_type {};

template <class _Storage, class _ValueType>
struct is_simd_reference<ex::__simd_reference<_Storage, _ValueType>> : std::true_type {};

struct CheckReferenceOperators {
  template <class _Tp, class SimdAbi>
  void operator()() {
    ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return static_cast<_Tp>(i + 2); });

    {
      assert(origin_simd[0] == static_cast<_Tp>(2));

      using U = _Tp;
      _Tp origin_val = static_cast<_Tp>(3);
      U x = static_cast<U>(3);

      {
        decltype(std::declval<_Tp&>()) check_assgin(origin_val);
        check_assgin = std::forward<U>(x);
      }

      auto res = origin_simd[0].operator=(x);
      assert(origin_simd[0] == static_cast<_Tp>(3));
      static_assert(is_simd_reference<decltype(res)>::value);
      assert(res == static_cast<_Tp>(3));
    }
    {
      assert(origin_simd[0] == static_cast<_Tp>(3));

      using U = _Tp;
      _Tp origin_val = static_cast<_Tp>(4);
      U x = static_cast<U>(4);

      {
        decltype(std::declval<_Tp&>()) check_add_assgin(origin_val);
        check_add_assgin += std::forward<U>(x);
      }

      auto res = origin_simd[0].operator+=(x);
      assert(origin_simd[0] == static_cast<_Tp>(7));
      static_assert(is_simd_reference<decltype(res)>::value);
      assert(res == static_cast<_Tp>(7));
    }
    {
      assert(origin_simd[0] == static_cast<_Tp>(7));

      using U = _Tp;
      _Tp origin_val = static_cast<_Tp>(6);
      U x = static_cast<U>(6);

      {
        decltype(std::declval<_Tp&>()) check_minus_assgin(origin_val);
        check_minus_assgin -= std::forward<U>(x);
      }

      auto res = origin_simd[0].operator-=(x);
      assert(origin_simd[0] == static_cast<_Tp>(1));
      static_assert(is_simd_reference<decltype(res)>::value);
      assert(res == static_cast<_Tp>(1));
    }
    {
      assert(origin_simd[0] == static_cast<_Tp>(1));

      using U = _Tp;
      _Tp origin_val = static_cast<_Tp>(12);
      U x = static_cast<U>(12);

      {
        decltype(std::declval<_Tp&>()) check_mul_assgin(origin_val);
        check_mul_assgin *= std::forward<U>(x);
      }

      auto res = origin_simd[0].operator*=(x);
      assert(origin_simd[0] == static_cast<_Tp>(12));
      static_assert(is_simd_reference<decltype(res)>::value);
      assert(res == static_cast<_Tp>(12));
    }
    {
      assert(origin_simd[0] == static_cast<_Tp>(12));

      using U = _Tp;
      _Tp origin_val = static_cast<_Tp>(2);
      U x = static_cast<U>(2);

      {
        decltype(std::declval<_Tp&>()) check_div_assgin(origin_val);
        check_div_assgin /= std::forward<U>(x);
      }

      auto res = origin_simd[0].operator/=(x);
      assert(origin_simd[0] == static_cast<_Tp>(6));
      static_assert(is_simd_reference<decltype(res)>::value);
      assert(res == static_cast<_Tp>(6));
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(6));

        using U = _Tp;
        _Tp origin_val = static_cast<_Tp>(4);
        U x = static_cast<U>(4);

        {
          decltype(std::declval<_Tp&>()) check_mod_assgin(origin_val);
          check_mod_assgin %= std::forward<U>(x);
        }

        auto res = origin_simd[0].operator%=(x);
        assert(origin_simd[0] == static_cast<_Tp>(2));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(2));
      }
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(2));

        using U = _Tp;
        _Tp origin_val = static_cast<_Tp>(5);
        U x = static_cast<U>(5);

        {
          decltype(std::declval<_Tp&>()) check_or_assgin(origin_val);
          check_or_assgin |= std::forward<U>(x);
        }

        auto res = origin_simd[0].operator|=(x);
        assert(origin_simd[0] == static_cast<_Tp>(7));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(7));
      }
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(7));

        using U = _Tp;
        _Tp origin_val = static_cast<_Tp>(3);
        U x = static_cast<U>(3);

        {
          decltype(std::declval<_Tp&>()) check_and_assgin(origin_val);
          check_and_assgin &= std::forward<U>(x);
        }

        auto res = origin_simd[0].operator&=(x);
        assert(origin_simd[0] == static_cast<_Tp>(3));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(3));
      }
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(3));

        using U = _Tp;
        _Tp origin_val = static_cast<_Tp>(8);
        U x = static_cast<U>(8);

        {
          decltype(std::declval<_Tp&>()) check_exor_assgin(origin_val);
          check_exor_assgin ^= std::forward<U>(x);
        }

        auto res = origin_simd[0].operator^=(x);
        assert(origin_simd[0] == static_cast<_Tp>(11));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(11));
      }
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(11));

        using U = _Tp;
        _Tp origin_val = static_cast<_Tp>(2);
        U x = static_cast<U>(2);

        {
          decltype(std::declval<_Tp&>()) check_left_shift_assgin(origin_val);
          check_left_shift_assgin <<= std::forward<U>(x);
        }

        auto res = origin_simd[0].operator<<=(x);
        assert(origin_simd[0] == static_cast<_Tp>(44));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(44));
      }
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(44));

        using U = _Tp;
        _Tp origin_val = static_cast<_Tp>(2);
        U x = static_cast<U>(2);

        {
          decltype(std::declval<_Tp&>()) check_right_shift_assgin(origin_val);
          check_right_shift_assgin >>= std::forward<U>(x);
        }

        auto res = origin_simd[0].operator>>=(x);
        assert(origin_simd[0] == static_cast<_Tp>(11));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(11));
      }
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(11));

        _Tp origin_val = static_cast<_Tp>(2);

        { origin_val++; }

        auto res = origin_simd[0].operator++();
        assert(origin_simd[0] == static_cast<_Tp>(12));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(12));

      } else {
        assert(origin_simd[0] == static_cast<_Tp>(6));

        _Tp origin_val = static_cast<_Tp>(2);

        { origin_val++; }

        auto res = origin_simd[0].operator++();
        assert(origin_simd[0] == static_cast<_Tp>(7));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(7));
      }
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(12));

        _Tp origin_val = static_cast<_Tp>(2);

        { origin_val--; }

        auto res = origin_simd[0].operator--();
        assert(origin_simd[0] == static_cast<_Tp>(11));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(11));

      } else {
        assert(origin_simd[0] == static_cast<_Tp>(7));

        _Tp origin_val = static_cast<_Tp>(2);

        { origin_val--; }

        auto res = origin_simd[0].operator--();
        assert(origin_simd[0] == static_cast<_Tp>(6));
        static_assert(is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(6));
      }
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(11));

        _Tp origin_val = static_cast<_Tp>(2);

        { origin_val++; }

        auto res = origin_simd[0].operator++(origin_val);

        assert(origin_simd[0] == static_cast<_Tp>(12));
        static_assert(!is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(11));

      } else {
        assert(origin_simd[0] == static_cast<_Tp>(6));

        _Tp origin_val = static_cast<_Tp>(2);

        { origin_val++; }

        auto res = origin_simd[0].operator++(origin_val);

        assert(origin_simd[0] == static_cast<_Tp>(7));
        static_assert(!is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(6));
      }
    }
    {
      if constexpr (!std::is_floating_point_v<_Tp>) {
        assert(origin_simd[0] == static_cast<_Tp>(12));

        _Tp origin_val = static_cast<_Tp>(2);

        { origin_val--; }

        auto res = origin_simd[0].operator--(origin_val);

        assert(origin_simd[0] == static_cast<_Tp>(11));
        static_assert(!is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(12));

      } else {
        assert(origin_simd[0] == static_cast<_Tp>(7));

        _Tp origin_val = static_cast<_Tp>(2);

        { origin_val--; }

        auto res = origin_simd[0].operator--(origin_val);

        assert(origin_simd[0] == static_cast<_Tp>(6));
        static_assert(!is_simd_reference<decltype(res)>::value);
        assert(res == static_cast<_Tp>(7));
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

int main(int, char**) {
  test_all_simd_abi<CheckReferenceOperators>();
}
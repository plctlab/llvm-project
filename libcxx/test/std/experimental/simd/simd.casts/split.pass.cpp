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
// [simd.casts]
// template <size_t... Sizes, class T, class Abi>
// tuple<simd<T, simd_abi::deduce_t<T, Sizes>>...> split(const simd<T, Abi>&) noexcept;

// template <size_t... Sizes, class T, class Abi>
// tuple<simd_mask<T, simd_mask_abi::deduce_t<T, Sizes>>...> split(const simd_mask<T, Abi>&) noexcept;

// template <class V, class Abi>
// array<V, simd_size_v<typename V::value_type, Abi> / V::size()> split(const simd<typename V::value_type, Abi>&) noexcept;

// template <class V, class Abi>
// array<V, simd_size_v<typename V::simd_type::value_type, Abi> / V::size()>
// split(const simd_mask<typename V::simd_type::value_type, Abi>&) noexcept;

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

// TODO: implement call in utility.h? or replace with std::apply later
template <typename Tuple, typename Func, size_t... N>
[[maybe_unused]] void __call_tuple(Tuple& t, Func&& func, std::index_sequence<N...>) {
  static_cast<void>(std::initializer_list<int>{(func(std::get<N>(t)), 0)...});
}

template <typename... Args, typename Func>
[[maybe_unused]] void __for_tuple(std::tuple<Args...>& t, Func&& func) {
  __call_tuple(t, std::forward<Func>(func), std::make_index_sequence<sizeof...(Args)>{});
}

struct CheckSplitToArray {
  template <class _Tp, class SimdAbi>
  void operator()() {
    using simd_type = ex::simd<_Tp, SimdAbi>;
    using simd_mask_type = ex::simd_mask<_Tp, SimdAbi>;

    {
      simd_type origin_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });
      const auto expected_array_simd = split<simd_type, SimdAbi>(origin_simd);
      for (size_t i = 0; i < expected_array_simd.size(); ++i) {
        assert(ex::all_of(expected_array_simd[i] == origin_simd) == true);
      }
    }

    {
      constexpr size_t simd_mask_size = simd_mask_type().size();

      simd_mask_type origin_simd_mask;

      for (size_t i = 0; i < simd_mask_size;) {
        origin_simd_mask[i++] = 0;
        if (i + 1 < simd_mask_size) {
          origin_simd_mask[i + 1] = 1;
          i++;
        }
      }

      const auto expected_array_simd_mask = split<simd_mask_type, SimdAbi>(origin_simd_mask);

      for (size_t i = 0; i < expected_array_simd_mask.size(); ++i) {
        assert(ex::all_of(expected_array_simd_mask[i] == origin_simd_mask) == true);
      }
    }
  }
};

struct CheckSplitToTuple {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    static auto initialize_mask = [](auto& origin_mask) {
      origin_mask[0] = 0;
      for (std::size_t i = 1; i < origin_mask.size(); ++i) {
        origin_mask[i] = 1;
      }
    };
    if constexpr (_Np == 1) {
      {
        ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });

        auto temp = ex::split<1>(origin_simd);
        size_t k = 0;

        std::apply(
            [origin_simd, &k](auto&& item) {
              for (size_t i = 0; i < item.size(); ++i) {
                assert(item[i] == origin_simd[k]);
                ++k;
              }
            },
            temp);
      }
      {
        ex::simd_mask<_Tp, SimdAbi> origin_mask;
        initialize_mask(origin_mask);

        auto temp = ex::split<1>(origin_mask);
        size_t k = 0;

        std::apply(
            [origin_mask, &k](auto&& item) {
              for (size_t i = 0; i < item.size(); ++i) {
                assert(item[i] == origin_mask[k]);
                ++k;
              }
            },
            temp);
      }

    } else if constexpr (_Np == 4) {
      ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return static_cast<_Tp>(i + 1); });
      ex::simd_mask<_Tp, SimdAbi> origin_mask;
      initialize_mask(origin_mask);

      static const auto split22 = [](const auto& origin_simd_or_mask) {
        auto temp = ex::split<2, 2>(origin_simd_or_mask);
        size_t k = 0;
        __for_tuple(temp, [origin_simd_or_mask, &k](auto&& item) {
          for (size_t i = 0; i < item.size(); ++i) {
            assert(item[i] == origin_simd_or_mask[k]);
            ++k;
          }
        });
      };
      static const auto split13 = [](const auto& origin_simd_or_mask) {
        auto temp = ex::split<1, 3>(origin_simd_or_mask);
        size_t k = 0;
        __for_tuple(temp, [origin_simd_or_mask, &k](auto&& item) {
          for (size_t i = 0; i < item.size(); ++i) {
            assert(item[i] == origin_simd_or_mask[k]);
            ++k;
          }
        });
      };
      static const auto split31 = [](const auto& origin_simd_or_mask) {
        auto temp = ex::split<3, 1>(origin_simd_or_mask);
        size_t k = 0;
        __for_tuple(temp, [origin_simd_or_mask, &k](auto&& item) {
          for (size_t i = 0; i < item.size(); ++i) {
            assert(item[i] == origin_simd_or_mask[k]);
            ++k;
          }
        });
      };
      static const auto split112 = [](const auto& origin_simd_or_mask) {
        auto temp = ex::split<1, 1, 2>(origin_simd_or_mask);
        size_t k = 0;
        __for_tuple(temp, [origin_simd_or_mask, &k](auto&& item) {
          for (size_t i = 0; i < item.size(); ++i) {
            assert(item[i] == origin_simd_or_mask[k]);
            ++k;
          }
        });
      };
      static const auto split1111 = [](const auto& origin_simd_or_mask) {
        auto temp = ex::split<1, 1, 1, 1>(origin_simd_or_mask);
        size_t k = 0;
        __for_tuple(temp, [origin_simd_or_mask, &k](auto&& item) {
          for (size_t i = 0; i < item.size(); ++i) {
            assert(item[i] == origin_simd_or_mask[k]);
            ++k;
          }
        });
      };
      split22(origin_mask);
      split22(origin_simd);
      split13(origin_mask);
      split13(origin_simd);
      split31(origin_simd);
      split31(origin_mask);
      split112(origin_simd);
      split112(origin_mask);
      split1111(origin_simd);
      split1111(origin_mask);
    } else { // pass if simd_size not equal 1 and 4
    }
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  if constexpr (std::is_same_v<F, CheckSplitToTuple>) {
    if constexpr (ex::simd_size_v<_Tp, SimdAbi> <= 4) {
      F{}.template operator()<_Tp, SimdAbi, ex::simd_size_v<_Tp, SimdAbi>>();
      test_simd_abi<F, _Np, _Tp, SimdAbis...>();
    }
  } else {
    F{}.template operator()<_Tp, SimdAbi>();
    test_simd_abi<F, _Np, _Tp, SimdAbis...>();
  }
}

int main(int, char**) {
  test_all_simd_abi<CheckSplitToArray>();
  test_all_simd_abi<CheckSplitToTuple>();
}
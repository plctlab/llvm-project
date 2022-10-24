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
// template <class T, class... Abis>
// simd<T, simd_abi::deduce_t<T, (simd_size_v<T, Abis> + ...)>> concat(const simd<T, Abis>&...) noexcept;
// template <class T, class... Abis>
// simd_mask<T, simd_abi::deduce_t<T, (simd_size_v<T, Abis> + ...)>> concat(const simd_mask<T, Abis>&...) noexcept;
// template <class T, class Abi, size_t N>
// resize_simd<simd_size_v<T, Abi> * N, simd<T, Abi>> concat(const array<simd<T, Abi>, N>& arr) noexcept;
// template <class T, class Abi, size_t N>
// resize_simd<simd_size_v<T, Abi> * N, simd_mask<T, Abi>> concat(const array<simd_mask<T, Abi>, N>& arr) noexcept;

#include "../test_utils.h"
#include <cassert>
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckConcatSimd {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    ex::native_simd<_Tp> native_simd_([](_Tp i) { return i; });
    ex::fixed_size_simd<_Tp, _Np> fixed_size_simd_([](_Tp i) { return static_cast<_Tp>(_Np - i); });

    ex::simd<_Tp, SimdAbi> full_type_simd_([](_Tp i) { return i; });
    {
      auto temp = ex::concat<_Tp, ex::simd_abi::native<_Tp>, ex::simd_abi::fixed_size<_Np>, SimdAbi>(
          native_simd_, fixed_size_simd_, full_type_simd_);

      size_t k = 0;
      for (size_t i = 0; i < native_simd_.size(); ++i) {
        assert(temp[k] == native_simd_[i]);
        ++k;
      }

      for (size_t i = 0; i < fixed_size_simd_.size(); ++i) {
        assert(temp[k] == fixed_size_simd_[i]);
        ++k;
      }

      for (size_t i = 0; i < full_type_simd_.size(); ++i) {
        assert(temp[k] == full_type_simd_[i]);
        ++k;
      }
    }

    {
      auto temp_simd = ex::concat<_Tp, SimdAbi>(full_type_simd_);

      assert(ex::all_of(temp_simd == full_type_simd_) == true);
    }
  }
};

struct CheckConcatSimdMask {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (!std::is_same<SimdAbi, ex::simd_abi::scalar>::value) {
      ex::native_simd_mask<_Tp> native_simd_mask_([](_Tp i) { return i; });
      ex::fixed_size_simd_mask<_Tp, _Np> fixed_size_simd_mask_([](_Tp i) { return static_cast<_Tp>(_Np - i); });

      ex::simd_mask<_Tp, SimdAbi> full_type_simd_mask_([](_Tp i) { return i; });

      {
        auto temp = ex::concat<_Tp, ex::simd_abi::native<_Tp>, ex::simd_abi::fixed_size<_Np>, SimdAbi>(
            native_simd_mask_, fixed_size_simd_mask_, full_type_simd_mask_);

        size_t k = 0;
        for (size_t i = 0; i < native_simd_mask_.size(); ++i) {
          assert(temp[k] == native_simd_mask_[i]);
          ++k;
        }

        for (size_t i = 0; i < fixed_size_simd_mask_.size(); ++i) {
          assert(temp[k] == fixed_size_simd_mask_[i]);
          ++k;
        }

        for (size_t i = 0; i < full_type_simd_mask_.size(); ++i) {
          assert(temp[k] == full_type_simd_mask_[i]);
          ++k;
        }
      }

      {
        auto temp_simd_mask = ex::concat<_Tp, SimdAbi>(full_type_simd_mask_);

        assert(ex::all_of(temp_simd_mask == full_type_simd_mask_) == true);
      }
    }
  }
};

struct CheckConcatResizeSimd {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    std::array<ex::simd<_Tp, SimdAbi>, _Np> arr;
    for (auto& sub_simd : arr) {
      for (size_t i = 0; i < sub_simd.size(); ++i) {
        sub_simd[i] = static_cast<_Tp>(i);
      }
    }
    auto res = ex::concat<_Tp, SimdAbi, _Np>(arr);

    constexpr size_t prev_length = ex::simd_size_v<_Tp, SimdAbi>;

    for (size_t i = 0; i < res.size(); ++i) {
      assert(res[i] == arr[i / prev_length][i % prev_length]);
    }
  }
};

struct CheckConcatResizeSimdMask {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    std::array<ex::simd_mask<_Tp, SimdAbi>, _Np> arr;
    for (auto& sub_simd_mask : arr) {
      for (size_t i = 0; i < sub_simd_mask.size(); ++i) {
        sub_simd_mask[i] = static_cast<bool>(i);
      }
    }
    auto res = ex::concat<_Tp, SimdAbi, _Np>(arr);

    constexpr size_t prev_length = ex::simd_size_v<_Tp, SimdAbi>;

    for (size_t i = 0; i < res.size(); ++i) {
      assert(res[i] == arr[i / prev_length][i % prev_length]);
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
  test_all_simd_abi<CheckConcatSimd>();
  test_all_simd_abi<CheckConcatSimdMask>();
  test_all_simd_abi<CheckConcatResizeSimd>();
  test_all_simd_abi<CheckConcatResizeSimdMask>();
}
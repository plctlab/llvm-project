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
// // masked assignment [simd.mask.where]
// template <class T, class Abi>
// where_expression<simd_mask<T, Abi>, simd<T, Abi>>
// where(const typename simd<T, Abi>::mask_type&, simd<T, Abi>&) noexcept;
//
// template <class T, class Abi>
// const_where_expression<simd_mask<T, Abi>, const simd<T, Abi>>
// where(const typename simd<T, Abi>::mask_type&, const simd<T, Abi>&) noexcept;
//
// template <class T, class Abi>
// where_expression<simd_mask<T, Abi>, simd_mask<T, Abi>>
// where(const type_identity_t<simd_mask<T, Abi>>&, simd_mask<T, Abi>&) noexcept;
//
// template <class T, class Abi>
// const_where_expression<simd_mask<T, Abi>, const simd_mask<T, Abi>>
// where(const type_identity_t<simd_mask<T, Abi>>&, const simd_mask<T, Abi>&) noexcept;
//
// template <class T> where_expression<bool, T> where(see below k, T& d) noexcept;
//
// template <class T>
// const_where_expression<bool, const T> where(see below k, const T& d) noexcept;

#include <experimental/simd>
#include <cassert>
#include <cstdint>
#include <algorithm>

namespace ex = std::experimental::parallelism_v2;

void compile_const_where() {
  {
    const ex::native_simd<int> a{};
    static_assert(
        std::is_same<decltype(ex::where(a < 2, a)),
                     ex::const_where_expression<ex::native_simd_mask<int>,
                                            const ex::native_simd<int>>>::value,
        "");
  }
  {
    const ex::native_simd_mask<int> a{};
    static_assert(
        std::is_same<decltype(ex::where(a, a)),
            ex::const_where_expression<ex::native_simd_mask<int>,
                                   const ex::native_simd_mask<int>>>::value,
        "");
  }
  {
    const bool b = true;
    static_assert(std::is_same<decltype(ex::where(b, 3)),
                               ex::const_where_expression<bool, const int>>::value,
                  "");
  }
}

void compile_where() {
  {
    ex::native_simd<int> a;
    static_assert(
        std::is_same<
            decltype(ex::where(a < 2, a)),
            ex::where_expression<ex::native_simd_mask<int>, ex::native_simd<int>>>::value,
        "");
  }
  {
    ex::native_simd_mask<int> a;
    static_assert(std::is_same<decltype(ex::where(a, a)),
                               ex::where_expression<ex::native_simd_mask<int>,
                                                ex::native_simd_mask<int>>>::value,
                  "");
  }
  {
    int v = 3;
    static_assert(
        std::is_same<decltype(ex::where(true, v)), ex::where_expression<bool, int>>::value,
        "");
  }
}

int main() {}

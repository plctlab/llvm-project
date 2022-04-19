
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
// template <class V, class Abi>
// array<V, simd_size_v<typename V::value_type, Abi> / V::size()> split(
// const simd_mask<typename V::value_type, Abi>&);

#include <experimental/simd>
#include <cstdint>
#include <cassert>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

template<typename _SimdMaskType,typename _Abi>
void test_split()
{
    bool buff[] = {1,0,1,0,0,1,1,0};
    ex::simd_mask<int32_t,_Abi> data(buff,ex::element_aligned_tag());
    { 
        auto temp = split<_SimdMaskType,_Abi>(data);
        size_t k = 0;
        for(size_t i = 0; i < temp.size(); ++i){
            for(size_t j = 0; j < temp[i].size(); ++j){
                assert(temp[i][j] == data[k]);
                ++k;
            }
        }
    }
}

int main(int, char**) {
  test_split<ex::simd_mask<int32_t,ex::simd_abi::fixed_size<2>>,ex::simd_abi::compatible<int32_t>>();
  test_split<ex::simd_mask<int32_t,ex::simd_abi::fixed_size<2>>,ex::simd_abi::fixed_size<8>>();
  test_split<ex::simd_mask<int32_t,ex::simd_abi::fixed_size<4>>,ex::simd_abi::fixed_size<8>>();
  test_split<ex::simd_mask<int32_t,ex::simd_abi::fixed_size<8>>,ex::simd_abi::fixed_size<8>>();
  return 0;
}

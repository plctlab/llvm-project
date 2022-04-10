

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
// tuple<simd<T, abi_for_size_t<Sizes>>...> split(const simd<T, Abi>&);

#include <experimental/simd>
#include <cstdint>
#include <cassert>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

template<typename _SimdType,typename _Abi>
void test_split()
{
  _SimdType data([](int i) { return 4 - i; });
 { 
  auto temp =  split<int,_Abi,2,2>(data);
  int k = 0;
  for_tuple(temp,[data,&k](auto&& item)
  {
    for(size_t i = 0; i < item.size(); ++i){
      assert(item[i] == data[k]);
      ++k;
    }
  });
 }

 { 
  auto temp =  split<int,_Abi,1,3>(data);
  int k = 0;
  for_tuple(temp,[data,&k](auto&& item)
  {
    for(size_t i = 0; i < item.size(); ++i){
      assert(item[i] == data[k]);
      ++k;
    }
  });
 }

 { 
  auto temp =  split<int,_Abi,3,1>(data);
  int k = 0;
  for_tuple(temp,[data,&k](auto&& item)
  {
    for(size_t i = 0; i < item.size(); ++i){
      assert(item[i] == data[k]);
      ++k;
    }
  });
 }

 { 
  auto temp =  split<int,_Abi,1,1,2>(data);
  int k = 0;
  for_tuple(temp,[data,&k](auto&& item)
  {
    for(size_t i = 0; i < item.size(); ++i){
      assert(item[i] == data[k]);
      ++k;
    }
  });
 }

  { 
  auto temp =  split<int,_Abi,1,1,1,1>(data);
  int k = 0;
  for_tuple(temp,[data,&k](auto&& item)
  {
    for(size_t i = 0; i < item.size(); ++i){
      assert(item[i] == data[k]);
      ++k;
    }
  });
 }
}

int main(int, char**) {
  test_split<ex::native_simd<int>,ex::simd_abi::native<int>>();
  test_split<ex::fixed_size_simd<int,4>,ex::simd_abi::fixed_size<4>>();
  //test_split<ex::fixed_size_simd<int,15>,ex::simd_abi::fixed_size<15>>();
  return 0;
}

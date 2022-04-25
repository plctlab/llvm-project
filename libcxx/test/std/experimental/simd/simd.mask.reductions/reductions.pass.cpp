//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
/*
template<class T, class Abi> bool all_of(const simd_mask<T, Abi>& k) noexcept;
1   Returns: true if all boolean elements in k are true, false otherwise.
template<class T, class Abi> bool any_of(const simd_mask<T, Abi>& k) noexcept;
2   Returns: true if at least one boolean element in k is true, false otherwise.
template<class T, class Abi> bool none_of(const simd_mask<T, Abi>& k) noexcept;
3   Returns: true if none of the one boolean elements in k is true, false otherwise.
template<class T, class Abi> bool some_of(const simd_mask<T, Abi>& k) noexcept;
4   Returns: true if at least one of the one boolean elements in k is true and at least one of the boolean
elements in k is false, false otherwise.
template<class T, class Abi> int popcount(const simd_mask<T, Abi>& k) noexcept;
5   Returns: The number of boolean elements in k that are true.
template<class T, class Abi> int find_first_set(const simd_mask<T, Abi>& k);
6 Requires: any_of(k) returns true. 
7   Returns: The lowest element index i where k[i] is true.
8 Throws: Nothing.
template<class T, class Abi> int find_last_set(const simd_mask<T, Abi>& k);

9 Requires: any_of(k) returns true.
10  Returns: The greatest element index i where k[i] is true.
11 Throws: Nothing.
*/

#include <cassert>
#include <cstdint>
#include <experimental/simd>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

void test_reductions(){
    bool buf1[] = {
      false, true, true,false,
    };
    bool buf2[] = {
      true, true,true, true,
    };
    bool buf3[] = {
      false, false,false, false,
    };
    ex::fixed_size_simd_mask<int, 4> a(buf1, ex::element_aligned_tag());
    ex::fixed_size_simd_mask<int, 4> b(buf2, ex::element_aligned_tag());
    ex::fixed_size_simd_mask<int, 4> c(buf3, ex::element_aligned_tag());


    assert(ex::all_of(a) == false);
    assert(ex::all_of(b) == true);
    assert(ex::all_of(c) == false);

    assert(ex::any_of(a) == true);
    assert(ex::any_of(b) == true);
    assert(ex::any_of(c) == false);

    assert(ex::none_of(a) == false);
    assert(ex::none_of(b) == false);
    assert(ex::none_of(c) == true);

    assert(ex::some_of(a) == true);
    assert(ex::some_of(b) == false);
    assert(ex::some_of(c) == false);

    assert(ex::popcount(a) == 2);
    assert(ex::popcount(b) == 4);
    assert(ex::popcount(c) == 0);

    assert(ex::find_first_set(a) == 1);
    assert(ex::find_first_set(b) == 0);
   // assert(ex::find_first_set(c) == 0);

    assert(ex::find_last_set(a) == 2);
    assert(ex::find_last_set(b) == 3);
  //assert(ex::find_last_set(c) == 0);

    bool x1 = true,x2=false;
    assert(ex::all_of(x1) == true);
    assert(ex::all_of(x2) == false);

    assert(ex::any_of(x1) == true);
    assert(ex::any_of(x2) == false);

    assert(ex::none_of(x1) == false);
    assert(ex::none_of(x2) == true);

    assert(ex::some_of(x1)  == false);
    assert(ex::some_of(x2) == false);

    assert(ex::popcount(x1) == 1);
    assert(ex::popcount(x2) == 0);

    assert(ex::find_first_set(x1) == 0);
  //  assert(ex::find_first_set(x2) == 0);

    assert(ex::find_last_set(x1) == 0);
  // assert(ex::find_last_set(x2) == 0);
}
int main(){
    test_reductions();
    return 0;
}
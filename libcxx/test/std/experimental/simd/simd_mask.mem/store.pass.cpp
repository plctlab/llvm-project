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
// // stores [simd_mask.store]
// template <class Flags> void copy_to(value_type* mem, Flags) const;

#include <experimental/simd>
#include <cstdint>
#include <cassert>

#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

template <typename Simd_MaskType>
void test_store() {

    {
        alignas(8) bool mem[] = {true,false,true,false};
        Simd_MaskType a(mem,ex::element_aligned_tag());
        alignas(8) bool buffer[4] = {0};
        a.copy_to(buffer, ex::element_aligned_tag());
        assert(buffer[0] == 1);
        assert(buffer[1] == 0);
        assert(buffer[2] == 1);
        assert(buffer[3] == 0);
    }
    {
        alignas(8) bool mem[] = {true,false,true,false};
        Simd_MaskType a(mem,ex::vector_aligned_tag());
        alignas(8) bool buffer[4] = {0};
        a.copy_to(buffer, ex::vector_aligned_tag());
        assert(buffer[0] == 1);
        assert(buffer[1] == 0);
        assert(buffer[2] == 1);
        assert(buffer[3] == 0);
    }
    {
        alignas(8) bool mem[] = {true,false,true,false};
        Simd_MaskType a(mem,ex::overaligned_tag<8>());
        alignas(8) bool buffer[4] = {0};
        a.copy_to(buffer, ex::overaligned_tag<8>());
        assert(buffer[0] == 1);
        assert(buffer[1] == 0);
        assert(buffer[2] == 1);
        assert(buffer[3] == 0);
    }

    {
        alignas(8) bool mem[] = {true,false,true,false};
        Simd_MaskType a(mem,ex::element_aligned);
        alignas(8) bool buffer[4] = {0};
        a.copy_to(buffer, ex::element_aligned);
        assert(buffer[0] == 1);
        assert(buffer[1] == 0);
        assert(buffer[2] == 1);
        assert(buffer[3] == 0);
    }
    {
        alignas(8) bool mem[] = {true,false,true,false};
        Simd_MaskType a(mem,ex::vector_aligned);
        alignas(8) bool buffer[4] = {0};
        a.copy_to(buffer, ex::vector_aligned);
        assert(buffer[0] == 1);
        assert(buffer[1] == 0);
        assert(buffer[2] == 1);
        assert(buffer[3] == 0);
    }
    {
        alignas(8) bool mem[] = {true,false,true,false};
        Simd_MaskType a(mem,ex::overaligned<8>);
        alignas(8) bool buffer[4] = {0};
        a.copy_to(buffer, ex::overaligned<8>);
        assert(buffer[0] == 1);
        assert(buffer[1] == 0);
        assert(buffer[2] == 1);
        assert(buffer[3] == 0);
    }
}



int main(int, char**) {

  test_store<ex::native_simd_mask<int32_t>>();
  test_store<ex::fixed_size_simd_mask<int32_t, 4>>();
  return 0;
}

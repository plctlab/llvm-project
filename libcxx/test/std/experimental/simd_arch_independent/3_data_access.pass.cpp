// This series of test cases is intended for internal usage only and does not include draft N4808.
//
// Data Access:
// Test for proper handling of loading and storing data, alignment requirements, conversion between data types.

#include <cassert>
#include <experimental/simd>
#include "type_algorithms.h"

namespace ex = std::experimental::parallelism_v2;

// Test for alignment
struct TestAlignment {
  template <class _Tp>
  void operator()() {
    constexpr size_t vector_size = 4;

    alignas(16) _Tp data[vector_size] = {1, 2, 3, 4};
    ex::fixed_size_simd<_Tp, vector_size> fixed_simd;

    fixed_simd.copy_from(data, ex::element_aligned_tag());

    for (size_t i = 0; i < vector_size; ++i)
      assert(fixed_simd[i] == static_cast<_Tp>(i + 1));

    for (size_t i = 0; i < vector_size; ++i)
      fixed_simd[i]++;

    fixed_simd.copy_to(data, ex::vector_aligned_tag());

    for (size_t i = 0; i < vector_size; ++i)
      assert(data[i] == static_cast<_Tp>(i + 2));
  }
};

int main() {
  types::for_each(types::integer_types(), TestAlignment());
  types::for_each(types::floating_point_types(), TestAlignment());

  return 0;
}

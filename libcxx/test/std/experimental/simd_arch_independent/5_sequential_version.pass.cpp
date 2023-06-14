// This series of test cases is intended for internal usage only and does not include draft N4808.
//
// Sequential Version:
// Test for a version of the SIMD library that operates sequentially for comparison purposes and for running on systems without SIMD support.

#include <cassert>
#include <experimental/simd>
#include "type_algorithms.h"

namespace ex = std::experimental::parallelism_v2;

struct TestSequential {
  template <class _Tp>
  void operator()() {
    std::array<_Tp, 4> a = {1, 2, 3, 4};
    std::array<_Tp, 4> b = {5, 6, 7, 8};
    std::array<_Tp, 4> c;
    for (size_t i = 0; i < 4; ++i)
      c[i] = a[i] + b[i];
    assert((c == std::array<_Tp, 4>{6, 8, 10, 12}));
  }
};

int main() {
  types::for_each(types::integer_types(), TestSequential());
  types::for_each(types::floating_point_types(), TestSequential());

  return 0;
}
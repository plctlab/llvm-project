// This series of test cases is intended for internal usage only and does not include draft N4808.
//
// Environment Configuration:
// Test different configurations of SIMD. For instance, different vector lengths.

#include <cassert>
#include <experimental/simd>
#include "type_algorithms.h"

namespace ex = std::experimental::parallelism_v2;

template <std::size_t... I, typename Functor>
void for_each_index(std::index_sequence<I...>, Functor f) {
  (f(std::integral_constant<std::size_t, I + 1>{}), ...);
}

template <typename _Tp>
struct TestLengthFixedAndDeduce {
  template <std::size_t _Np>
  void operator()(std::integral_constant<std::size_t, _Np>) {
    ex::fixed_size_simd<_Tp, _Np> fixed_size_simd_{};
    assert(fixed_size_simd_.size() == _Np);

    ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, _Np>> deduce_simd_{};
    assert(deduce_simd_.size() == _Np);
  }
};

class TestVectorLength {
public:
  template <class _Tp>
  void operator()() {
    for_each_index(std::make_index_sequence<31>(), TestLengthFixedAndDeduce<_Tp>{});

    {
      ex::native_simd<_Tp> native_simd_{};
#if defined(__AVX__)
      assert(native_simd_.size() == _LIBCPP_NATIVE_SIMD_WIDTH_IN_BYTES / sizeof(_Tp));
#else
      assert(native_simd_.size() == 16 / sizeof(_Tp));
#endif
    }

    {
      ex::simd<_Tp, ex::simd_abi::compatible<_Tp>> compatible_simd_{};
#if defined(__AVX__)
      assert(compatible_simd_.size() == _LIBCPP_NATIVE_SIMD_WIDTH_IN_BYTES / sizeof(_Tp));
#else
      assert(compatible_simd_.size() == 16 / sizeof(_Tp));
#endif
    }

    {
      ex::simd<_Tp, ex::simd_abi::scalar> scalar_simd_{};
      assert(scalar_simd_.size() == 1);
    }
  }
};

int main() {
  types::for_each(types::integer_types(), TestVectorLength());
  types::for_each(types::floating_point_types(), TestVectorLength());

  return 0;
}

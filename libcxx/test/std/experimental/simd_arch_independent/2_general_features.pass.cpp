// This series of test cases is intended for internal usage only and does not include draft N4808.
//
// General Features:
// Test advanced features of SIMD like broadcasting.

#include <cassert>
#include <experimental/simd>
#include "type_algorithms.h"

namespace ex = std::experimental::parallelism_v2;

template <std::size_t... I, typename Functor>
void for_each_index(std::index_sequence<I...>, Functor f) {
  (f(std::integral_constant<std::size_t, I + 1>{}), ...);
}

template <typename _Tp>
struct TestBroadcastFixedAndDeduce {
  template <std::size_t _Np>
  void operator()(std::integral_constant<std::size_t, _Np>) {
    ex::fixed_size_simd<_Tp, _Np> fixed_size_simd_{1};
    for (size_t i = 0; i < _Np; ++i)
      assert(fixed_size_simd_[i] == 1);

    ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, _Np>> deduce_simd_{1};
    for (size_t i = 0; i < _Np; ++i)
      assert(deduce_simd_[i] == 1);
  }
};

class TestBroadcast {
public:
  template <class _Tp>
  void operator()() {
    for_each_index(std::make_index_sequence<31>(), TestBroadcastFixedAndDeduce<_Tp>{});

    {
      ex::native_simd<_Tp> native_simd_{1};
      for (size_t i = 0; i < native_simd_.size(); ++i)
        assert(native_simd_[i] == 1);
    }

    {
      ex::simd<_Tp, ex::simd_abi::compatible<_Tp>> compatible_simd_{1};
      for (size_t i = 0; i < compatible_simd_.size(); ++i)
        assert(compatible_simd_[i] == 1);
    }

    {
      ex::simd<_Tp, ex::simd_abi::scalar> scalar_simd_{1};
      for (size_t i = 0; i < scalar_simd_.size(); ++i)
        assert(scalar_simd_[i] == 1);
    }
  }
};

int main() {
  types::for_each(types::integer_types(), TestBroadcast());
  types::for_each(types::floating_point_types(), TestBroadcast());

  return 0;
}
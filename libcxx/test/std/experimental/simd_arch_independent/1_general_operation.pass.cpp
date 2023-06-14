// This series of test cases is intended for internal usage only and does not include draft N4808.
//
// General Operation:
// Test the basic SIMD operations, including arithmetic operations (addition, subtraction, multiplication, division), logical operations (and, or, not), and comparison operations (less than, greater than, equal, not equal).

#include <cassert>
#include <experimental/simd>
#include "type_algorithms.h"

namespace ex = std::experimental::parallelism_v2;

template <class _Tp, class SimdAbi>
void generate_simd() {
  ex::simd<_Tp, SimdAbi> lhs{2};
  ex::simd<_Tp, SimdAbi> rhs{4};
  ex::simd<_Tp, SimdAbi> res;
  constexpr size_t vec_size = res.size();

  /*test arithmetic op: */
  res = lhs + rhs;
  for (size_t i = 0; i < vec_size; ++i)
    assert(res[i] == static_cast<_Tp>(2 + 4));
  res = rhs - lhs;
  for (size_t i = 0; i < vec_size; ++i)
    assert(res[i] == static_cast<_Tp>(4 - 2));
  res = lhs * rhs;
  for (size_t i = 0; i < vec_size; ++i)
    assert(res[i] == static_cast<_Tp>(4 * 2));
  res = rhs / lhs;
  for (size_t i = 0; i < vec_size; ++i)
    assert(res[i] == static_cast<_Tp>(4 / 2));

  /* test comparison op: */
  ex::simd_mask<_Tp, SimdAbi> comparision_res;
  lhs             = ex::simd<_Tp, SimdAbi>([](_Tp i) { return i; });
  rhs             = ex::simd<_Tp, SimdAbi>{5};
  comparision_res = lhs <= rhs;
  for (size_t i = 0; i < vec_size; ++i)
    assert(comparision_res[i] == (lhs[i] <= rhs[i]));
  comparision_res = lhs >= rhs;
  for (size_t i = 0; i < vec_size; ++i)
    assert(comparision_res[i] == (lhs[i] >= rhs[i]));
  comparision_res = lhs == rhs;
  for (size_t i = 0; i < vec_size; ++i)
    assert(comparision_res[i] == (lhs[i] == rhs[i]));
  comparision_res = lhs != rhs;
  for (size_t i = 0; i < vec_size; ++i)
    assert(comparision_res[i] == (lhs[i] != rhs[i]));
}

struct TestArithmeticAndComparison {
  template <class _Tp>
  void operator()() {
    generate_simd<_Tp, ex::simd_abi::scalar>();
    generate_simd<_Tp, ex::simd_abi::native<_Tp>>();
    generate_simd<_Tp, ex::simd_abi::compatible<_Tp>>();

    // TODO: consider to replace with `std::make_index` to get fully coverage
    generate_simd<_Tp, ex::simd_abi::fixed_size<3>>();
    generate_simd<_Tp, ex::simd_abi::fixed_size<4>>();
    generate_simd<_Tp, ex::simd_abi::fixed_size<7>>();
    generate_simd<_Tp, ex::simd_abi::fixed_size<8>>();

    generate_simd<_Tp, ex::simd_abi::deduce_t<_Tp, 3>>();
    generate_simd<_Tp, ex::simd_abi::deduce_t<_Tp, 4>>();
    generate_simd<_Tp, ex::simd_abi::deduce_t<_Tp, 7>>();
    generate_simd<_Tp, ex::simd_abi::deduce_t<_Tp, 8>>();
  }
};

struct TestLogicalOp {
  template <class _Tp>
  void operator()() {
    /* test logical op: */

    alignas(16) std::array<_Tp, 4> lhs{0b1100, 0b1010, 0b1111, 0b1001};
    alignas(16) std::array<_Tp, 4> rhs{0b1010, 0b1100, 0b1001, 0b1111};

    ex::fixed_size_simd<_Tp, 4> lhs_fixed;
    lhs_fixed.copy_from(lhs.data(), ex::vector_aligned_tag());
    ex::fixed_size_simd<_Tp, 4> rhs_fixed;
    rhs_fixed.copy_from(rhs.data(), ex::element_aligned_tag());
    ex::fixed_size_simd<_Tp, 4> res_fixed;

    res_fixed = lhs_fixed & rhs_fixed;
    assert(res_fixed[0] = 0b1000);
    assert(res_fixed[1] = 0b1000);
    assert(res_fixed[2] = 0b1001);
    assert(res_fixed[3] = 0b1001);

    res_fixed = lhs_fixed | rhs_fixed;
    assert(res_fixed[0] = 0b1110);
    assert(res_fixed[1] = 0b1110);
    assert(res_fixed[2] = 0b1111);
    assert(res_fixed[3] = 0b1111);

    res_fixed = ~lhs_fixed;
    assert(res_fixed[0] = 0b0011);
    assert(res_fixed[1] = 0b0101);

    // note: when apply bitwise NOT op on `0b1111`, all bits are inverted.
    // unsigned val wil be maximum
    if constexpr (std::is_signed_v<_Tp>) {
      assert(res_fixed[2] = -16);
    }

    assert(res_fixed[3] = 0b0110);
  }
};

int main() {
  types::for_each(types::integer_types(), TestArithmeticAndComparison());
  types::for_each(types::floating_point_types(), TestArithmeticAndComparison());
  types::for_each(types::integer_types(), TestLogicalOp());

  return 0;
}
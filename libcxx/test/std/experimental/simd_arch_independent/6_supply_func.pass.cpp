// This series of test cases is intended for internal usage only and does not include draft N4808.
//
// Supply Function:
// Test user-defined functions that operate on SIMD data types.

#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

// 1. __next_pow_of_2
void test_next_pow_of_2() {
  static_assert(ex::__next_pow_of_2(0) == 1);
  static_assert(ex::__next_pow_of_2(1) == 1);
  static_assert(ex::__next_pow_of_2(2) == 2);
  static_assert(ex::__next_pow_of_2(3) == 4);
  static_assert(ex::__next_pow_of_2(15) == 16);
  static_assert(ex::__next_pow_of_2(16) == 16);
  static_assert(ex::__next_pow_of_2(1000) == 1024);
}

// 2. __choose_mask_type
void test_choose_mask_type() {
  assert(typeid(ex::__choose_mask_type<char>()) == typeid(uint8_t));
  assert(typeid(ex::__choose_mask_type<short>()) == typeid(uint16_t));
  assert(typeid(ex::__choose_mask_type<int>()) == typeid(uint32_t));
  assert(typeid(ex::__choose_mask_type<long long>()) == typeid(uint64_t));
#ifndef _LIBCPP_HAS_NO_INT128
  assert(typeid(ex::__choose_mask_type<__uint128_t>()) == typeid(__uint128_t));
#endif
}

// 3. __set_all_bits
void test_set_all_bits() {
  assert(ex::__set_all_bits<char>(1) == 0xFF);
  assert(ex::__set_all_bits<short>(1) == 0xFFFF);
  assert(ex::__set_all_bits<int>(1) == 0xFFFFFFFF);
  assert(ex::__set_all_bits<long long>(1) == 0xFFFFFFFFFFFFFFFF);
}

// 4. __is_non_narrowing_arithmetic_convertible
void test_is_non_narrowing_arithmetic_convertible() {
  static_assert(ex::__is_non_narrowing_arithmetic_convertible<int, long long>() == true);
  static_assert(ex::__is_non_narrowing_arithmetic_convertible<long long, int>() == false);
  static_assert(ex::__is_non_narrowing_arithmetic_convertible<float, double>() == true);
  static_assert(ex::__is_non_narrowing_arithmetic_convertible<double, float>() == false);
}

// 5. __variadic_sum
void test_variadic_sum() {
  static_assert(ex::__variadic_sum<int>(1, 2, 3, 4, 5) == 15);
  static_assert(ex::__variadic_sum<double>(1.5, 2.5, 3.5) == 7.5);
}

// 6. __is_vectorizable
void test_is_vectorizable() {
  static_assert(ex::__is_vectorizable<int>() == true);
  static_assert(ex::__is_vectorizable<const int>() == false);
  static_assert(ex::__is_vectorizable<volatile int>() == false);
  static_assert(ex::__is_vectorizable<bool>() == false);
}

// 7. __can_broadcast
void test_can_broadcast() {
  static_assert(ex::__can_broadcast<int, double>() == false);
  static_assert(ex::__can_broadcast<double, int>() == true);
  static_assert(ex::__can_broadcast<int, char>() == true);
  static_assert(ex::__can_broadcast<char, int>() == true);
}

// 8. __can_generate
template <typename _Tp>
struct SimpleGenerator {
  _Tp base;
  SimpleGenerator(_Tp base): base(base) {}
  constexpr _Tp operator()(std::integral_constant<size_t, 0>) const {
    return base;
  }
  template <size_t I>
  constexpr _Tp operator()(std::integral_constant<size_t, I>) const {
    return base + I;
  }
};

void test_can_generate() {
  // Test with integers
  static_assert(ex::__can_generate<int, SimpleGenerator<int>>(std::index_sequence<0, 1, 2, 3>{}) == true);
  
  // Test with floating-point numbers
  static_assert(ex::__can_generate<double, SimpleGenerator<double>>(std::index_sequence<0, 1, 2, 3>{}) == true);

  // Test with other type conversions
  static_assert(ex::__can_generate<double, SimpleGenerator<int>>(std::index_sequence<0, 1, 2, 3>{}) == true);
  static_assert(ex::__can_generate<int, SimpleGenerator<double>>(std::index_sequence<0, 1, 2, 3>{}) == false);

  // Test with no indices, should return true
  static_assert(ex::__can_generate<int, SimpleGenerator<int>>(std::index_sequence<>{}) == true);
}

int main() {
  test_next_pow_of_2();
  test_choose_mask_type();
  test_set_all_bits();
  test_is_non_narrowing_arithmetic_convertible();
  test_variadic_sum();
  test_is_vectorizable();
  test_can_broadcast();
  test_can_generate();

  return 0;
}
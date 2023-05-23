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
// [simd.class]
// template<class U> simd(U&& value) noexcept;
// template<class U> simd(const simd<U, simd_abi::fixed_size<size()>>&) noexcept;
// template<class G> explicit simd(G&& gen) noexcept;
// template<class U, class Flags> simd(const U* mem, Flags f);

#include "../test_utils.h"
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;
template <typename T>
class zero_init {
  T val;

public:
  zero_init() : val(static_cast<T>(0)) {}
  zero_init(T val) : val(val) {}
  operator T&() { return val; }
  operator T() const { return val; }
};

template <typename _Tp, typename SimdAbi, std::size_t array_size>
struct BroadCastHelper {
  const std::array<_Tp, array_size>& origin_value;

  BroadCastHelper(const std::array<_Tp, array_size>& origin_value) : origin_value(origin_value) {}

  template <typename _Up>
  void operator()() const {
    if constexpr (sizeof(_Up) <= sizeof(_Tp)) {
      ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type(static_cast<_Up>(3));
      assert_simd_value_correct<array_size>(expected_simd_from_vectorizable_type, origin_value);
    }
  }
};

struct CheckBroadCastSimdCtorFromVectorizedType {
  template <class TypeList, class _Tp, class SimdAbi, size_t array_size>
  void check(const std::array<_Tp, array_size>& origin_value) {
    types::for_each(TypeList{}, BroadCastHelper<_Tp, SimdAbi, array_size>(origin_value));
  }

  template <class _Tp, class SimdAbi, std::size_t>
  void operator()() {
    constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;
    std::array<_Tp, array_size> origin_value;
    for (size_t i = 0; i < array_size; ++i)
      origin_value[i] = static_cast<_Tp>(3);

    if constexpr (std::is_floating_point_v<_Tp>)
      check<types::floating_point_types, _Tp, SimdAbi, array_size>(origin_value);
    else if constexpr (std::is_signed_v<_Tp>)
      check<types::signed_integer_types, _Tp, SimdAbi, array_size>(origin_value);
    else
      check<types::unsigned_integer_types, _Tp, SimdAbi, array_size>(origin_value);
  }
};

struct CheckBroadCastSimdCtor {
  template <class _Tp, class SimdAbi, std::size_t>
  void operator()() {
    constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;
    std::array<_Tp, array_size> origin_value;
    for (size_t i = 0; i < array_size; ++i)
      origin_value[i] = static_cast<_Tp>(3);

    zero_init<_Tp> implicit_convert_to_3(3);
    ex::simd<_Tp, SimdAbi> expected_simd_from_implicit_convert(std::move(implicit_convert_to_3));
    assert_simd_value_correct<array_size>(expected_simd_from_implicit_convert, origin_value);

    int int_value_3 = 3;
    ex::simd<_Tp, SimdAbi> expected_simd_from_int(std::move(int_value_3));
    assert_simd_value_correct<array_size>(expected_simd_from_int, origin_value);

    if constexpr (std::is_unsigned_v<_Tp>) {
      unsigned int uint_value_3 = static_cast<unsigned int>(3);
      ex::simd<_Tp, SimdAbi> expected_simd_from_uint(std::move(uint_value_3));
      assert_simd_value_correct<array_size>(expected_simd_from_uint, origin_value);
    }
  }
};

template <typename _Tp, typename SimdAbi, std::size_t _Np>
struct FixedSimdForEachHelper {
  static constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;

  template <typename _Up>
  void operator()() const {
    if constexpr (sizeof(_Tp) >= sizeof(_Up)) {
      ex::simd<_Up, SimdAbi> origin_simd([](_Up i) { return i; });
      ex::simd<_Tp, SimdAbi> convert_from_other_simd(origin_simd);
      std::array<_Up, array_size> expected_value;
      for (size_t i = 0; i < array_size; i++)
        expected_value[i] = static_cast<_Up>(i);

      assert_simd_value_correct<array_size, _Up>(convert_from_other_simd, expected_value);
    }
  }
};

struct CheckFixedSimdCtor {
  template <class TypeList, class _Tp, class SimdAbi, std::size_t _Np>
  void check() {
    types::for_each(TypeList{}, FixedSimdForEachHelper<_Tp, SimdAbi, _Np>());
  }

  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same_v<SimdAbi, ex::simd_abi::fixed_size<_Np>>) {
      if constexpr (std::is_floating_point_v<_Tp>)
        check<types::floating_point_types, _Tp, SimdAbi, _Np>();
      else if constexpr (std::is_signed_v<_Tp>)
        check<types::signed_integer_types, _Tp, SimdAbi, _Np>();
      else
        check<types::unsigned_integer_types, _Tp, SimdAbi, _Np>();
    }
  }
};

struct CheckGenerateSimdCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });
    constexpr size_t array_size = origin_simd.size();
    std::array<_Tp, array_size> expected_value;
    for (size_t i = 0; i < array_size; ++i)
      expected_value[i] = static_cast<_Tp>(i);
    assert_simd_value_correct(origin_simd, expected_value);
  }
};

struct CheckLoadSimdCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    {
      constexpr auto alignas_size = ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>, _Tp>;

      constexpr auto array_length = ex::simd_size_v<_Tp, SimdAbi>;

      alignas(alignas_size) _Tp buffer[array_length];
      for (size_t i = 0; i < array_length; i++)
        buffer[i] = static_cast<_Tp>(i + 1);

      ex::simd<_Tp, SimdAbi> origin_simd(buffer, ex::vector_aligned_tag());
      assert_simd_value_correct(origin_simd, buffer);
    }

    {
      constexpr auto alignas_size = std::max(next_pow2(sizeof(_Tp)), next_pow2(_Np));

      constexpr auto array_length = ex::simd_size_v<_Tp, SimdAbi>;

      alignas(alignas_size) _Tp buffer[array_length];
      for (size_t i = 0; i < array_length; i++)
        buffer[i] = static_cast<_Tp>(i);

      ex::simd<_Tp, SimdAbi> origin_simd(buffer, ex::overaligned_tag<alignas_size>());
      assert_simd_value_correct(origin_simd, buffer);
    }

    {
      constexpr auto alignas_size = std::max(next_pow2(sizeof(_Tp)), next_pow2(alignof(_Tp)));

      constexpr auto array_length = ex::simd_size_v<_Tp, SimdAbi>;

      alignas(alignas_size) _Tp buffer[array_length];
      for (size_t i = 0; i < array_length; i++)
        buffer[i] = static_cast<_Tp>(i);

      ex::simd<_Tp, SimdAbi> origin_simd(buffer, ex::element_aligned_tag());
      assert_simd_value_correct(origin_simd, buffer);
    }
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  F{}.template operator()<_Tp, SimdAbi, _Np>();
  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main(int, char**) {
  test_all_simd_abi<CheckBroadCastSimdCtorFromVectorizedType>();
  test_all_simd_abi<CheckBroadCastSimdCtor>();
  test_all_simd_abi<CheckFixedSimdCtor>();
  test_all_simd_abi<CheckGenerateSimdCtor>();
  test_all_simd_abi<CheckLoadSimdCtor>();
  return 0;
}

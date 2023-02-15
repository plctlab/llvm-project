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

#define GENARETE_SIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(x)                                                                \
  if constexpr (sizeof(signed x) <= sizeof(_Tp)) {                                                                     \
    ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type_signed_##x(static_cast<signed x>(3));                  \
    assert_simd_value_correct<array_size>(expected_simd_from_vectorizable_type_signed_##x, origin_value);              \
  }

#define GENARETE_UNSIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(y)                                                              \
  if constexpr (sizeof(unsigned y) <= sizeof(_Tp)) {                                                                   \
    ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type_unsigned_##y(static_cast<unsigned y>(3));              \
    assert_simd_value_correct<array_size>(expected_simd_from_vectorizable_type_unsigned_##y, origin_value);            \
  }

#define GENARETE_FLOATING_TYPE_FOR_BROADCAST_SIMD_CTOR(x)                                                              \
  if constexpr (sizeof(x) <= sizeof(_Tp)) {                                                                            \
    ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type_##x(static_cast<x>(3));                                \
    assert_simd_value_correct<array_size>(expected_simd_from_vectorizable_type_##x, origin_value);                     \
  }
struct CheckBroadCastSimdCtorFromVectorizedType {
  template <class _Tp, class SimdAbi, std::size_t>
  void operator()() {
    constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;
    std::array<_Tp, array_size> origin_value;
    for (size_t i = 0; i < array_size; ++i)
      origin_value[i] = static_cast<_Tp>(3);

    if constexpr (std::is_integral_v<_Tp>) {
      if constexpr (std::is_signed_v<_Tp>) {
        if constexpr (std::is_signed_v<wchar_t> && sizeof(wchar_t) <= sizeof(_Tp)) {
          ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type_wchar_t(static_cast<wchar_t>(3));
          assert_simd_value_correct<array_size>(expected_simd_from_vectorizable_type_wchar_t, origin_value);
        }
        GENARETE_SIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(char)
        GENARETE_SIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(short)
        GENARETE_SIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(int)
        GENARETE_SIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(long)

        if constexpr (sizeof(long long) <= sizeof(_Tp)) {
          ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type_long_long(static_cast<long long>(3));
          assert_simd_value_correct<array_size>(expected_simd_from_vectorizable_type_long_long, origin_value);
        }
      } else {
        GENARETE_UNSIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(char)
        GENARETE_UNSIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(short)
        GENARETE_UNSIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(int)
        GENARETE_UNSIGNED_TYPE_FOR_BROADCAST_SIMD_CTOR(long)

        if constexpr (sizeof(unsigned long long) <= sizeof(_Tp)) {
          ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type_unsigned_long_long(
              static_cast<unsigned long long>(3));
          assert_simd_value_correct<array_size>(expected_simd_from_vectorizable_type_unsigned_long_long, origin_value);
        }
      }
    } else {
      GENARETE_FLOATING_TYPE_FOR_BROADCAST_SIMD_CTOR(float)
      GENARETE_FLOATING_TYPE_FOR_BROADCAST_SIMD_CTOR(double)
      if constexpr (sizeof(long double) <= sizeof(_Tp)) {
        ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type_long_double(static_cast<long double>(3));
        assert_simd_value_correct<array_size>(expected_simd_from_vectorizable_type_long_double, origin_value);
      }
    }
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

#define GENERATE_SIGNED_TYPE_FOR_FIXED_SIMD_CTOR(x)                                                                    \
  if constexpr (sizeof(_Tp) >= sizeof(signed x)) {                                                                     \
    ex::simd<signed x, SimdAbi> x##_simd([](signed x i) { return i; });                                                \
    ex::simd<_Tp, SimdAbi> convert_from_##x(x##_simd);                                                                 \
    std::array<signed x, array_size> expected_value;                                                                   \
    for (size_t i = 0; i < array_size; i++)                                                                            \
      expected_value[i] = static_cast<signed x>(i);                                                                    \
    assert_simd_value_correct<array_size, signed x>(convert_from_##x, expected_value);                                 \
  }

#define GENERATE_UNSIGNED_TYPE_FOR_FIXED_SIMD_CTOR(x)                                                                  \
  if constexpr (sizeof(_Tp) >= sizeof(unsigned x)) {                                                                   \
    ex::simd<unsigned x, SimdAbi> x##_simd([](unsigned x i) { return i; });                                            \
    ex::simd<_Tp, SimdAbi> convert_from_##x(x##_simd);                                                                 \
    std::array<unsigned x, array_size> expected_value;                                                                 \
    for (size_t i = 0; i < array_size; i++)                                                                            \
      expected_value[i] = static_cast<unsigned x>(i);                                                                  \
    assert_simd_value_correct<array_size, unsigned x>(convert_from_##x, expected_value);                               \
  }

#define GENERATE_FLOATING_TYPE_FOR_FIXED_SIMD_CTOR(x)                                                                  \
  if constexpr (sizeof(_Tp) >= sizeof(x)) {                                                                            \
    ex::simd<x, SimdAbi> x##_simd([](x i) { return i; });                                                              \
    ex::simd<_Tp, SimdAbi> convert_from_##x(x##_simd);                                                                 \
    std::array<x, array_size> expected_value;                                                                          \
    for (size_t i = 0; i < array_size; i++)                                                                            \
      expected_value[i] = static_cast<x>(i);                                                                           \
    assert_simd_value_correct<array_size, x>(convert_from_##x, expected_value);                                        \
  }

struct CheckFixedSimdCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same_v<SimdAbi, ex::simd_abi::fixed_size<_Np>>) {
      constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;
      if constexpr (std::is_integral_v<_Tp>) {
        if constexpr (std::is_signed_v<_Tp>) {
          GENERATE_SIGNED_TYPE_FOR_FIXED_SIMD_CTOR(char)
          GENERATE_SIGNED_TYPE_FOR_FIXED_SIMD_CTOR(short)
          GENERATE_SIGNED_TYPE_FOR_FIXED_SIMD_CTOR(int)
          GENERATE_SIGNED_TYPE_FOR_FIXED_SIMD_CTOR(long)

          if constexpr (std::is_signed_v<wchar_t> && sizeof(_Tp) >= sizeof(wchar_t)) {
            ex::simd<wchar_t, SimdAbi> wchar_simd([](wchar_t i) { return i; });
            ex::simd<_Tp, SimdAbi> convert_from_wchar(wchar_simd);

            std::array<wchar_t, array_size> expected_value_in_wchar;
            for (size_t i = 0; i < array_size; i++)
              expected_value_in_wchar[i] = static_cast<wchar_t>(i);
            assert_simd_value_correct<array_size, wchar_t>(convert_from_wchar, expected_value_in_wchar);
          }

          if constexpr (sizeof(_Tp) >= sizeof(long long)) {
            ex::simd<long long, SimdAbi> long_long_simd([](long long i) { return i; });
            ex::simd<_Tp, SimdAbi> convert_from_long_long(long_long_simd);

            std::array<long long, array_size> expected_value_in_long_long;
            for (size_t i = 0; i < array_size; i++)
              expected_value_in_long_long[i] = static_cast<long long>(i);
            assert_simd_value_correct<array_size, long long>(convert_from_long_long, expected_value_in_long_long);
          }
        } else {
          GENERATE_UNSIGNED_TYPE_FOR_FIXED_SIMD_CTOR(char)
          GENERATE_UNSIGNED_TYPE_FOR_FIXED_SIMD_CTOR(short)
          GENERATE_UNSIGNED_TYPE_FOR_FIXED_SIMD_CTOR(int)
          GENERATE_UNSIGNED_TYPE_FOR_FIXED_SIMD_CTOR(long)

          if constexpr (sizeof(_Tp) >= sizeof(unsigned long long)) {
            ex::simd<unsigned long long, SimdAbi> unsigned_long_long_simd([](unsigned long long i) { return i; });
            ex::simd<_Tp, SimdAbi> convert_from_unsigned_long_long(unsigned_long_long_simd);

            std::array<unsigned long long, array_size> expected_value_in_unsigned_long_long;
            for (size_t i = 0; i < array_size; i++)
              expected_value_in_unsigned_long_long[i] = static_cast<unsigned long long>(i);
            assert_simd_value_correct<array_size, unsigned long long>(
                convert_from_unsigned_long_long, expected_value_in_unsigned_long_long);
          }
        }
      } else {
        GENERATE_FLOATING_TYPE_FOR_FIXED_SIMD_CTOR(float)
        GENERATE_FLOATING_TYPE_FOR_FIXED_SIMD_CTOR(double)
        if constexpr (sizeof(_Tp) >= sizeof(long double)) {
          const ex::simd<long double, SimdAbi> long_double_simd([](long double i) { return i; });
          ex::simd<_Tp, SimdAbi> convert_from_long_double(long_double_simd);

          std::array<long double, array_size> expected_value_in_long_double;
          for (size_t i = 0; i < array_size; i++)
            expected_value_in_long_double[i] = static_cast<long double>(i);
          assert_simd_value_correct<array_size, long double>(convert_from_long_double, expected_value_in_long_double);
        }
      }
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

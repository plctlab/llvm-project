// -*- C++ -*-
//===-------------------------- __simd/abi/builtin.h -------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP___SIMD_ABI_BUILTIN_H
#define _LIBCPP___SIMD_ABI_BUILTIN_H

#include <experimental/__config>
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <type_traits>
#include <utility>
#include <__simd/abi/simd_storage.h>
#include <__simd/abi/vec_ext.h>
#include <__simd/abi/neon.h>
#include <__simd/abi/ppc.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, class _Abi>
struct __simd_traits {
  using _Simd = __simd_storage<_Tp, _Abi>;
  using _Mask = __mask_storage<_Tp, _Abi>;

  static _Simd __broadcast(_Tp __v) noexcept {
    return __generate([=](size_t) { return __v; });
  }

  template <class _Generator, size_t... _Is>
  static _Simd __generate_init(_Generator&& __g, std::index_sequence<_Is...>) {
    // _Simd specified here is to work around GCC
    return _Simd{{__g(std::integral_constant<size_t, _Is>())...}};
  }

  template <class _Generator>
  static _Simd __generate(_Generator&& __g) noexcept {
    return __generate_init(std::forward<_Generator>(__g), std::make_index_sequence<_Abi::__simd_size>());
  }

  template <class _Up, class _Flags>
  static _Simd __load(const _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    return __generate([=](size_t __i) { return static_cast<_Tp>(__mem[__i]); });
  }

  template <class _Up, class _Flags>
  static void __store(_Simd __s, _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    for (size_t __i = 0; __i < _Abi::__simd_size; __i++)
      __mem[__i] = static_cast<_Up>(__s.__data[__i]);
  }

  static void __increment(_Simd& __s) noexcept { __s.__data = __s.__data + 1; }

  static void __decrement(_Simd& __s) noexcept { __s.__data = __s.__data - 1; }

  static _Simd __negate(_Simd __s) noexcept { return {!__s.__data}; }

  static _Simd __bitwise_not(_Simd __s) noexcept { return {~__s.__data}; }

  static _Simd __unary_minus(_Simd __s) noexcept { return {-__s.__data}; }

  static _Simd __plus(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data + __rhs.__data}; }

  static _Simd __minus(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data - __rhs.__data}; }

  static _Simd __multiplies(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data * __rhs.__data}; }

  static _Simd __divides(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data / __rhs.__data}; }

  static _Simd __modulus(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data % __rhs.__data}; }

  static _Simd __bitwise_and(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data & __rhs.__data}; }

  static _Simd __bitwise_or(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data | __rhs.__data}; }

  static _Simd __bitwise_xor(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data ^ __rhs.__data}; }

  static _Simd __shift_left(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data << __rhs.__data}; }

  static _Simd __shift_right(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data >> __rhs.__data}; }

  static _Simd __shift_left(_Simd __lhs, int __rhs) noexcept { return {__lhs.__data << __rhs}; }

  static _Simd __shift_right(_Simd __lhs, int __rhs) noexcept { return {__lhs.__data >> __rhs}; }

  static _Simd __equal_to(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data == __rhs.__data}; }

  static _Simd __not_equal_to(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data != __rhs.__data}; }

  static _Simd __less_equal(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data <= __rhs.__data}; }

  static _Simd __less(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data < __rhs.__data}; }

  static _Tp __hmin(_Simd __s) {
    _Tp __min = __s.__data[0];
    for (auto __v : __s.__data)
      __min = std::min(__min, __v);
    return __min;
  }

  static _Tp __hmax(_Simd __s) {
    _Tp __max = __s.__data[0];
    for (auto __v : __s.__data)
      __max = std::max(__max, __v);
    return __max;
  }

  static _Simd __min(_Simd __a, _Simd __b) noexcept {
    _Simd __r;
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __r.__data[__i] = std::min(__a.__data[__i], __b.__data[__i]);
    return __r;
  }

  static _Simd __max(_Simd __a, _Simd __b) noexcept {
    _Simd __r;
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __r.__data[__i] = std::max(__a.__data[__i], __b.__data[__i]);
    return __r;
  }

  static std::pair<_Simd, _Simd> __minmax(_Simd __a, _Simd __b) noexcept {
    _Simd __min, __max;
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i) {
      __min.__data[__i] = std::min(__a.__data[__i], __b.__data[__i]);
      __max.__data[__i] = std::max(__a.__data[__i], __b.__data[__i]);
    }
    return {__min, __max};
  }

  static _Simd __clamp(_Simd __v, _Simd __lo, _Simd __hi) noexcept {
    _Simd __r;
    for (size_t __i = 0; __i <  _Abi::__simd_size; ++__i)
      __r.__data[__i] = std::min(std::max(__v.__data[__i], __lo.__data[__i]), __hi.__data[__i]);
    return __r;
  }

  static _Simd __masked_unary_minus(_Simd __s, _Mask __m) noexcept {
    _Simd __r;
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __r.__data[__i] = __m.__data[__i] ? -__s.__data[__i] : __s.__data[__i];
    return __r;
  }

  static _Simd __masked_assign(_Simd& __s, _Mask __m, _Tp __v) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __v : __s.__data[__i];
    return __s;
  }
#define _LIBCXX_MASKED_OP_(__op, __name)				\
  static _Simd __masked##__name(_Simd&__s, _Mask __m, _Tp __v) noexcept \
  {									\
     for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)		\
       __s.__data[__i] = __m.__data[__i] ? __s.__data[__i] __op __v :   \
	  __s.__data[__i];						\
     return __s;							\
  }
  _LIBCXX_MASKED_OP_(+, _plus)
  _LIBCXX_MASKED_OP_(-, _minus)
  _LIBCXX_MASKED_OP_(*, _multiplues)
  _LIBCXX_MASKED_OP_(/, _divides)
  _LIBCXX_MASKED_OP_(%, _modulus)
  _LIBCXX_MASKED_OP_(&, _bit_and)
  _LIBCXX_MASKED_OP_(|, _bit_or)
  _LIBCXX_MASKED_OP_(^, _bit_xor)
  _LIBCXX_MASKED_OP_(<<, _shift_left)
  _LIBCXX_MASKED_OP_(>>, _shift_right)
#undef _LIBCXX_MASKED_OP_
  static _Simd __masked_incre(_Simd& __s, _Mask __m) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __s.__data[__i]++ : __s.__data[__i];
    return __s;
  }
  static _Simd __masked_decre(_Simd& __s, _Mask __m) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __s.__data[__i]-- : __s.__data[__i];
    return __s;
  }
  template<class _Up>
  static _Simd __masked_load(_Simd& __s, _Mask __m, _Up* __mem) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __mem[__i] : __s.__data[__i];
    return __s;
  }
 template<class _Up>
 static _Simd __masked_store(_Simd& __s, _Mask __m, _Up* __mem) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __mem[__i] = __m.__data[__i] ? __s.__data[__i] : __mem[__i];
    return __s;
  }
};


template <class _Tp, class _Abi>
struct __mask_traits {
  using _Mask = __mask_storage<_Tp, _Abi>;

  static _Mask __broadcast(_Tp __v) noexcept {
    return __generate([=](size_t) { return  static_cast<decltype(__choose_mask_type<_Tp>())>(__v); });
  }
 template <class _Generator, size_t... _Is>
  static _Mask __generate_init(_Generator&& __g, std::index_sequence<_Is...>) {
    // _Simd specified here is to work around GCC
    return _Mask{{__g(std::integral_constant<size_t, _Is>())...}};
  }

  template <class _Generator>
  static _Mask __generate(_Generator&& __g) noexcept {
    return __generate_init(std::forward<_Generator>(__g), std::make_index_sequence<_Abi::__simd_size>());
  }


  template <class _Up, class _Flags>
  static _Mask __load(const _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    return __generate([=](size_t __i) { return static_cast<decltype(__choose_mask_type<_Tp>())>(__mem[__i]); });
  }

  template <class _Up, class _Flags>
  static void __store(_Mask __s, _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    for (size_t __i = 0; __i < _Abi::__simd_size; __i++)
      __mem[__i] = static_cast<_Up>(__s.__data[__i]);
  }

  static _Mask __logical_and(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data & __rhs.__data}; }

  static _Mask __logical_or(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data | __rhs.__data}; }

  static _Mask __bitwise_and(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data & __rhs.__data}; }

  static _Mask __bitwise_or(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data | __rhs.__data}; }

  static _Mask __bitwise_xor(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data ^ __rhs.__data}; }

  static _Mask __equal_to(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data == __rhs.__data}; }

  static _Mask __not_equal_to(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data != __rhs.__data}; }

  static bool __all_of(_Mask __s) noexcept {
    for (auto __v : __s.__data)
      if (!__v)
        return false;
    return true;
  }

  static bool __any_of(_Mask __s) noexcept {
    for (auto __v : __s.__data)
      if (__v)
        return true;
    return false;
  }

  static bool __none_of(_Mask __s) noexcept {
    for (auto __v : __s.__data)
      if (__v)
        return false;
    return true;
  }

  static bool __some_of(_Mask __s) noexcept {
    for (size_t __i = 1; __i < _Abi::__simd_size; ++__i)
      if (__s[__i] != __s[__i - 1])
        return true;
    return false;
  }

  static int __popcount(_Mask __s) noexcept {
    int __count = 0;
    for (auto __v : __s.__data)
      __count += __v != 0;
    return __count;
  }

  static int __find_first_set(_Mask __s) {
    int __i = 0;
    for (; __i < _Abi::__simd_size; ++__i)
      if (__s.__data[__i])
        break;
    return __i;
  }

  static int __find_last_set(_Mask __s) {
    int __i = _Abi::__simd_size - 1;
    for (; __i != -1; --__i)
      if (__s.__data[__i])
        break;
    return __i;
  }
  static _Mask __masked_unary_minus(_Mask __s, _Mask __m) noexcept {
    _Mask __r;
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __r.__data[__i] = __m.__data[__i] ? -__s.__data[__i] : __s.__data[__i];
    return __r;
  }

  static _Mask __masked_assign(_Mask& __s, _Mask __m, _Tp __v) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __v : __s.__data[__i];
    return __s;
  }
#define _LIBCXX_MASKED_OP_M(__op, __name)				\
  static _Mask __masked##__name(_Mask&__s, _Mask __m, _Tp __v) noexcept \
  {									\
     for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)		\
       __s.__data[__i] = __m.__data[__i] ? __s.__data[__i] __op __v :   \
	  __s.__data[__i];						\
     return __s;							\
  }
  _LIBCXX_MASKED_OP_M(+, _plus)
  _LIBCXX_MASKED_OP_M(-, _minus)
  _LIBCXX_MASKED_OP_M(*, _multiplues)
  _LIBCXX_MASKED_OP_M(/, _divides)
  _LIBCXX_MASKED_OP_M(%, _modulus)
  _LIBCXX_MASKED_OP_M(&, _bit_and)
  _LIBCXX_MASKED_OP_M(|, _bit_or)
  _LIBCXX_MASKED_OP_M(^, _bit_xor)
  _LIBCXX_MASKED_OP_M(<<, _shift_left)
  _LIBCXX_MASKED_OP_M(>>, _shift_right)
#undef _LIBCXX_MASKED_OP_M
  static _Mask __masked_incre(_Mask& __s, _Mask __m) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __s.__data[__i]++ : __s.__data[__i];
    return __s;
  }
  static _Mask __masked_decre(_Mask& __s, _Mask __m) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __s.__data[__i]-- : __s.__data[__i];
    return __s;
  }
  template<class _Up>
  static _Mask __masked_load(_Mask& __s, _Mask __m, _Up* __mem) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __mem[__i] : __s.__data[__i];
    return __s;
  }
 template<class _Up>
 static _Mask __masked_store(_Mask& __s, _Mask __m, _Up* __mem) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __mem[__i] = __m.__data[__i] ? __s.__data[__i] : __mem[__i];
    return __s;
  } 
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_BUILTIN_H

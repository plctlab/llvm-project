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
#include <tuple>
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
  using _Impl = __simd_impl<_Tp, _Abi>;

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

  static _Mask __negate(_Simd __s) noexcept { return {!__s.__data}; }

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

  static _Mask __equal_to(_Simd __lhs, _Simd __rhs) noexcept {
    return {{__lhs.__data == __rhs.__data}};
  }

  static _Mask __not_equal_to(_Simd __lhs, _Simd __rhs) noexcept {
    return {{__lhs.__data != __rhs.__data}};
  }

  static _Mask __less_equal(_Simd __lhs, _Simd __rhs) noexcept {
    return {{__lhs.__data <= __rhs.__data}};
  }

  static _Mask __less(_Simd __lhs, _Simd __rhs) noexcept{
    return {{__lhs.__data < __rhs.__data}};
  }

  static _Tp __hmin(_Simd __s) noexcept{
    return _Impl::__hmin(__s);
  }

  static _Tp __hmax(_Simd __s) noexcept{
    return _Impl::__hmax(__s);
  }

  static _Simd __min(_Simd __a, _Simd __b) noexcept {
    return {__a.__data < __b.__data ? __a.__data : __b.__data};
  }

  static _Simd __max(_Simd __a, _Simd __b) noexcept {
    return {__a.__data > __b.__data ? __a.__data : __b.__data};
  }

  static std::pair<_Simd, _Simd> __minmax(_Simd __a, _Simd __b) noexcept {
    return {__min(__a,__b), __max(__a,__b)};
  }

  static _Simd __clamp(_Simd __v, _Simd __lo, _Simd __hi) noexcept {
    return __min(__max(__v, __lo), __hi);
  }

  static _Simd __masked_unary_minus(_Simd __s, _Mask __m) noexcept {
    return _Impl::__masked_unary_minus(__s, __m);
  }

  static _Simd __masked_assign(_Simd& __s, _Mask __m, _Tp __v) noexcept {
    return _Impl::__masked_assign(__s, __m, __v);
  }

  static _Simd __masked_assign(_Simd& __s, _Mask __m, _Simd __v) noexcept {
    return _Impl::__masked_assign(__s, __m, __v);
  }

#define _LIBCXX_MASKED_OP_(__op, __name)                                  \
  static void __masked##__name(_Simd&__s, _Mask __m, _Tp __v) noexcept {  \
    return _Impl::__masked##__name(__s, __m, __v);                        \
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

#define _LIBCXX_MASKED_OP_(__op, __name)                                    \
  static void __masked##__name(_Simd&__s, _Mask __m, _Simd __v) noexcept {  \
    return _Impl::__masked##__name(__s, __m, __v);                          \
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

  static void __masked_incre(_Simd& __s, _Mask __m) noexcept {
    return _Impl::__masked_incre(__s, __m);
  }

  static void __masked_decre(_Simd& __s, _Mask __m) noexcept {
    return _Impl::__masked_decre(__s, __m);
  }
  template<class _Up>
  static void __masked_load(_Simd& __s, _Mask __m, _Up* __mem) noexcept {
    return _Impl::__masked_load(__s, __m, __mem);
  }
 template<class _Up>
 static void __masked_store(const _Simd& __s,  _Mask __m, _Up* __mem) noexcept {
    return _Impl::__masked_store(__s, __m, __mem);
  }

  template<class _BinaryOp>
  static _Tp __reduce(const _Simd& __s, _BinaryOp __op) {
    return _Impl::__reduce(__s, __op);
  }
};

template <class _Tp, class _Abi>
struct __mask_traits {
  using _Mask = __mask_storage<_Tp, _Abi>;
  using _Impl = __mask_impl<_Tp, _Abi>;

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
  static _Mask __negate(_Mask __s) noexcept { return {{~__s.__data}}; }

  static _Mask __unary_minus(_Mask __s) noexcept { return {{-__s.__data}}; }

  static _Mask __logical_and(_Mask __lhs, _Mask __rhs) noexcept { return {{__lhs.__data & __rhs.__data}}; }

  static _Mask __logical_or(_Mask __lhs, _Mask __rhs) noexcept { return {{__lhs.__data | __rhs.__data}}; }

  static _Mask __bitwise_and(_Mask __lhs, _Mask __rhs) noexcept { return {{__lhs.__data & __rhs.__data}}; }

  static _Mask __bitwise_or(_Mask __lhs, _Mask __rhs) noexcept { return {{__lhs.__data | __rhs.__data}}; }

  static _Mask __bitwise_xor(_Mask __lhs, _Mask __rhs) noexcept { return {{__lhs.__data ^ __rhs.__data}}; }

  static bool __all_of(_Mask __s) noexcept {
    return _Impl::__all_of(__s);
  }

  static bool __any_of(_Mask __s) noexcept {
    return _Impl::__any_of(__s);
  }

  static bool __none_of(_Mask __s) noexcept {
    return _Impl::__none_of(__s);
  }

  static bool __some_of(_Mask __s) noexcept {
    return _Impl::__some_of(__s);
  }

  static int __popcount(_Mask __s) noexcept {
    return _Impl::__popcount(__s);
  }

  static int __find_first_set(_Mask __s) {
    return _Impl::__find_first_set(__s);
  }

  static int __find_last_set(_Mask __s) {
    return _Impl::__find_last_set(__s);
  }

  static _Mask __masked_unary_minus(_Mask __s, _Mask __m) noexcept {
    return _Impl::__masked_unary_minus(__s, __m);
  }

  static _Mask __masked_assign(_Mask& __s, _Mask __m, _Tp __v) noexcept {
    return _Impl::__masked_assign(__s, __m, __v);
  }

  static _Mask __masked_assign(_Mask& __s, _Mask __m, _Mask __v) noexcept {
    return _Impl::__masked_assign(__s, __m, __v);
  }

#define _LIBCXX_MASKED_OP_M(__op, __name)                                 \
  static void __masked##__name(_Mask&__s, _Mask __m, _Tp __v) noexcept {  \
    return _Impl::__masked##__name(__s, __m, __v);                        \
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

#define _LIBCXX_MASKED_OP_M(__op, __name)                                   \
  static void __masked##__name(_Mask&__s, _Mask __m, _Mask __v) noexcept {  \
    return _Impl::__masked##__name(__s, __m, __v);                          \
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

  static void __masked_incre(_Mask& __s, _Mask __m) noexcept {
    return _Impl::__masked_incre(__s, __m);
  }
  static void __masked_decre(_Mask& __s, _Mask __m) noexcept {
    return _Impl::__masked_decre(__s, __m);
  }
  template<class _Up>
  static void __masked_load(_Mask& __s, _Mask __m, _Up* __mem) noexcept {
    return _Impl::__masked_load(__s, __m, __mem);
  }
 template<class _Up>
 static void __masked_store(const _Mask& __s, _Mask __m, _Up* __mem) noexcept {
    return _Impl::__masked_store(__s, __m, __mem);
  }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_BUILTIN_H

// -*- C++ -*-
//===------------------------ __simd/abi/vec_ext.h ------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP___SIMD_ABI_VEC_EXT_H
#define _LIBCPP___SIMD_ABI_VEC_EXT_H

#include <experimental/__config>
#include <__simd/abi/decl.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD_ABI

template <int _Np>
struct __vec_ext {
  static constexpr bool __is_abi_tag = _Np > 0;
  static constexpr size_t __simd_size = _Np;
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD_ABI

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

constexpr size_t __next_pow_of_2(size_t __val) {
  size_t __pow = 1;
  while (__pow < __val)
    __pow <<= 1;
  return __pow;
}

template <class _Tp, int _Np>
class __simd_storage<_Tp, simd_abi::__vec_ext<_Np>> {
#if defined(_LIBCPP_COMPILER_CLANG_BASED)
  using _StorageType = _Tp __attribute__((vector_size(sizeof(_Tp) * _Np)));
#else
  using _StorageType = _Tp __attribute__((vector_size(__next_pow_of_2(sizeof(_Tp) * _Np))));
#endif

  _StorageType __storage_;

  template <class, class>
  friend struct simd;

  template <class, class>
  friend struct simd_mask;

public:
  _Tp __get(size_t __index) const noexcept { return __storage_[__index]; }
  void __set(size_t __index, _Tp __val) noexcept { __storage_[__index] = __val; }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_VEC_EXT_H

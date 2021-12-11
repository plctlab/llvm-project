// -*- C++ -*-
//===-------------------------- __simd/abi/decl.h -------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP___SIMD_ABI_DECL_H
#define _LIBCPP___SIMD_ABI_DECL_H

#include <experimental/__config>
#include <cstddef>
#include <type_traits>
#include <utility>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, class _Abi>
struct __simd_traits;

template <class _Tp, class _Abi>
struct __mask_traits;

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_DECL_H

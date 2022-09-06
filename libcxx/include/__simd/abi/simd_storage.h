#ifndef _LIBCPP___SIMD_ABI_SIMD_STORAGE_H
#define _LIBCPP___SIMD_ABI_SIMD_STORAGE_H

#include <experimental/__config>
#include <__simd/arch/config.h>
#include <__simd/abi/utility.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD_ABI

struct __scalar {
  static constexpr bool __is_abi_tag = true;
  static constexpr size_t __simd_size = 1;
};

template <int _Np>
struct __builtin {
  static constexpr bool __is_abi_tag = _Np > 0;
  static constexpr size_t __simd_size = _Np;
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD_ABI

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, class _Abi>
struct __simd_storage;

template <class _Tp, class _Abi>
struct __mask_storage;

template <class _Tp>
struct __simd_storage <_Tp, simd_abi::__scalar> {
  _Tp __data;

  _Tp __get(size_t __idx) const noexcept { return (&__data)[__idx]; }

  void __set(size_t __idx, _Tp __v) noexcept { (&__data)[__idx] = __v; }
};

template <class _Tp>
struct __mask_storage <_Tp, simd_abi::__scalar> : __simd_storage<bool, simd_abi::__scalar> {};

template <class _Tp, int _Np>
struct __simd_storage <_Tp, simd_abi::__builtin<_Np>> {
#if defined(_LIBCPP_COMPILER_CLANG_BASED)
  _Tp __data __attribute__((vector_size(sizeof(_Tp) * _Np)));
#else
  _Tp __data __attribute__((vector_size(__next_pow_of_2(sizeof(_Tp) * _Np))));
#endif

  _Tp __get(size_t __idx) const noexcept { return __data[__idx]; }

  void __set(size_t __idx, _Tp __v) noexcept { __data[__idx] = __v; }
};

template <class _Tp, int _Np>
struct __mask_storage <_Tp, simd_abi::__builtin<_Np>> : __simd_storage<decltype(__choose_mask_type<_Tp>()), simd_abi::__builtin<_Np>> {};


_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_SIMD_STORAGE_H

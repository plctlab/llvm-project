#ifndef _LIBCPP___SIMD_ABI_SERIAL_H
#define _LIBCPP___SIMD_ABI_SERIAL_H

#include <__simd/abi/simd_storage.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, class _Abi>
struct __simd_serial {
  using _Simd = __simd_storage<_Tp, _Abi>;
  using _Mask = __mask_storage<_Tp, _Abi>;

  static _Tp __masked_hmax(_Mask __m, _Simd __s) noexcept{
    if (__mask_serial<_Tp, _Abi>::__none_of(__m)) {
      return numeric_limits<_Tp>::lowest();
    } else {
      _Tp __max = numeric_limits<_Tp>::lowest();
      for (size_t i = 0; i < _Abi::__simd_size; i++) {
        if ( __m.__data[i] > 0 && __s.__data[i] >= __max) {
          __max = __s.__data[i];
        }
      }
      return __max;
    }
  }

  static _Tp __masked_hmin(_Mask __m, _Simd __s) noexcept{
    if (__mask_serial<_Tp, _Abi>::__none_of(__m)) {
      return numeric_limits<_Tp>::max();
    } else {
      _Tp __min = numeric_limits<_Tp>::max();
      for (size_t i = 0; i < _Abi::__simd_size; i++) {
        if ( __m.__data[i] > 0 && __s.__data[i] <= __min) {
          __min = __s.__data[i];
        }
      }
      return __min;
    }
  }

  static _Simd __masked_assign(_Simd& __s, _Mask __m, _Simd __v) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __v.__data[__i] : __s.__data[__i];
    return __s;
  }

  template<class _BinaryOp>
  static _Tp __reduce(const _Simd& __s, _BinaryOp __op) {
    _Tp __sum = __s.__data[0];
    for (size_t __i = 1; __i < _Abi::__simd_size; __i++)
      __sum = __op(__sum, __s.__data[__i]);
    return __sum;
  }
};

template <class _Tp, class _Abi>
struct __mask_serial {
  using _Mask = __mask_storage<_Tp, _Abi>;

  static bool __all_of(_Mask __s) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      if (!__s.__data[__i])
        return false;
    return true;
  }

  static bool __any_of(_Mask __s) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      if (__s.__data[__i])
        return true;
    return false;
  }

  static bool __none_of(_Mask __s) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      if (__s.__data[__i])
        return false;
    return true;
  }

  static bool __some_of(_Mask __s) noexcept {
    for (size_t __i = 1; __i < _Abi::__simd_size; ++__i)
      if (__s.__data[__i] != __s.__data[__i - 1])
        return true;
    return false;
  }

  static int __popcount(_Mask __s) noexcept {
    int __count = 0;
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __count += __s.__data[__i] != 0;
    return __count;
  }

  static int __find_first_set(_Mask __s) {
    size_t __i = 0;
    for (; __i < _Abi::__simd_size; ++__i)
      if (__s.__data[__i])
        break;
    return __i;
  }

  static int __find_last_set(_Mask __s) {
    size_t __i = 1;
    for (; __i < _Abi::__simd_size; ++__i)
      if (__s.__data[_Abi::__simd_size - __i])
        break;
    return _Abi::__simd_size - __i;
  }

  static _Mask __masked_assign(_Mask& __s, _Mask __m, _Mask __v) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __v.__data[__i] : __s.__data[__i];
    return __s;
  }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_SERIAL_H

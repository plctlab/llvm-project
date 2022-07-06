#ifndef _LIBCPP___SIMD_ABI_SERIAL_H
#define _LIBCPP___SIMD_ABI_SERIAL_H

#include <__simd/abi/simd_storage.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, class _Abi>
struct __simd_serial {
  using _Simd = __simd_storage<_Tp, _Abi>;
  using _Mask = __mask_storage<_Tp, _Abi>;

  static _Tp __hmin(_Simd __s) noexcept{
    _Tp __min = __s.__data[0];
    for (size_t __i = 1; __i < _Abi::__simd_size; ++__i)
      __min = std::min(__min, __s.__data[__i]);
    return __min;
  }

  static _Tp __hmax(_Simd __s) noexcept{
    _Tp __max = __s.__data[0];
    for (size_t __i = 1; __i < _Abi::__simd_size; ++__i)
      __max = std::max(__max, __s.__data[__i]);
    return __max;
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
#define _LIBCXX_MASKED_OP_(__op, __name)                                  \
  static void __masked##__name(_Simd&__s, _Mask __m, _Tp __v) noexcept {  \
     for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)                 \
       __s.__data[__i] = __m.__data[__i] ? __s.__data[__i] __op __v :     \
    __s.__data[__i];                                                      \
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
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __s.__data[__i]++ : __s.__data[__i];
  }

  static void __masked_decre(_Simd& __s, _Mask __m) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __s.__data[__i]-- : __s.__data[__i];
  }
  template<class _Up>
  static void __masked_load(_Simd& __s, _Mask __m, _Up* __mem) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? static_cast<_Tp>(__mem[__i]) : __s.__data[__i];
  }
 template<class _Up>
 static void __masked_store(const _Simd& __s,  _Mask __m, _Up* __mem) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __mem[__i] = __m.__data[__i] ? static_cast<_Up>(__s.__data[__i]) : __mem[__i];
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
#define _LIBCXX_MASKED_OP_M(__op, __name)                                 \
  static void __masked##__name(_Mask&__s, _Mask __m, _Tp __v) noexcept {  \
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)                  \
      __s.__data[__i] = __m.__data[__i] ? __s.__data[__i] __op __v :      \
    __s.__data[__i];                                                      \
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
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __s.__data[__i]++ : __s.__data[__i];
  }
  static void __masked_decre(_Mask& __s, _Mask __m) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __s.__data[__i]-- : __s.__data[__i];
  }
  template<class _Up>
  static void __masked_load(_Mask& __s, _Mask __m, _Up* __mem) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __s.__data[__i] = __m.__data[__i] ?static_cast<_Tp>(__mem[__i]) : __s.__data[__i];
  }
 template<class _Up>
 static void __masked_store(const _Mask& __s, _Mask __m, _Up* __mem) noexcept {
    for (size_t __i = 0; __i < _Abi::__simd_size; ++__i)
      __mem[__i] = __m.__data[__i] ? static_cast<_Up>(__s.__data[__i]) : __mem[__i];
  }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_SERIAL_H

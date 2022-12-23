# libcxx experimental/simd

## Introduction

`std::experimental::simd` is a portable, zero-overhead C++ types for explicitly data-parallel programming. It has been included in [GCC/libstdc++](https://gcc.gnu.org/git/?p=gcc.git;a=blob;f=libstdc%2B%2B-v3/include/experimental/simd;hb=HEAD) since GCC 11.

The [patch set](https://reviews.llvm.org/differential/diff/139057/changesets/) of the first version of experimental/simd implementation has been shelved for several years. We (PLCT Lab) have updated and revised a version of the implementation based on the previous works, according to the latest document. We reconstructed the original code structure. Moved most independent internal interfaces to directory `libcxx/include/__simd/`. We also reconstructed the test code structure. Added a test framework to improve test coverage.

## Documentations

- [https://en.cppreference.com/w/cpp/experimental/simd](https://en.cppreference.com/w/cpp/experimental/simd)

- [J. Hoberock, "Working Draft, C++ Extensions for Parallelism Version 2",
  2019](https://wg21.link/N4808) ISO/IEC TS 19570:2018 Section 9 "Data-Parallel Types"

## libcxx status before the patch

Tim Shen <timshen91@gmail.com> submitted a version of experimental/simd implementation at LLVM upstream about four years ago. However, only two patches have been merged into upstream, and the rest of the implementation have been shelved (see [https://reviews.llvm.org/differential/diff/139057/changesets/](https://reviews.llvm.org/differential/diff/139057/changesets/)). We got his permission to take over the issue after communicating with him via email.

The previously merged patchs only addded synopsis, declarations and a few external interfaces implementations. And the documents referenced by the implementations are out of date.

## About the patch

### Implementation framework

We reconstructed the original code structure. Moved most independent internal interfaces to directory `libcxx/include/experimental/__simd/`. The current directory structure of simd implementations is as follows:

	- libcxx
		- include
			- experimental
				- __simd
					- config.h //................. Macros of target simd ISA
					- declaration.h //............ Declarations of internal classes
					- scalar.h //................. Implementation of internal ABI `__scalar`
					- vec_ext.h //................ Implementation of internal ABI `__vec_ext`
					- utility.h //................ Some utility internal interfaces and functions
				- simd //..................... The user visible header file. Definition of the external user interfaces given in the documentation

The current implementation follows previous to use GCC vector extension as the storage type of main internal ABI `__vec_ext`. And use Clang vector operations and vector builtins to implement the operations of `__vec_ext`. Reference: [Clang Language Extensions: Vectors and Extended Vectors](https://clang.llvm.org/docs/LanguageExtensions.html#vectors-and-extended-vectors).

### Test framework

We also reconstructed the test code structure. Added a test framework to improve test coverage. Because most external user interfaces are related to class `simd/simd_mask`, we have traversed all possible data types and ABI tags combinations for class `simd/simd_mask` in related interface tests. The current directory structure of simd tests is as follows:

	- simd/
		- simd.traits/
			- is_abi_tag.pass.cpp
			- is_simd.pass.cpp
			- is_simd_mask.pass.cpp
			- is_simd_flag_type.pass.cpp
			- simd_size.pass.cpp
			- memory_alignment.pass.cpp
			- rebind_simd.pass.cpp
			- resize_simd.pass.cpp
		- simd.casts/
			- static_simd_cast.pass.cpp
			- simd_cast.pass.cpp
			- to_fixed_size.pass.cpp
			- to_native.pass.cpp
			- to_compatible.pass.cpp
			- split.pass.cpp
			- split_by.pass.cpp
			- concat.pass.cpp
		- simd.whereexpr/
			- const_where_expression.pass.cpp
			- where_expression.pass.cpp
		- simd.reference/
			- reference_value_type.pass.cpp
			- reference_operators.pass.cpp
			- reference_swap.pass.cpp
		- simd.class/
			- simd_width.pass.cpp
			- simd_ctor.pass.cpp
			- simd_copy.pass.cpp
			- simd_subscr.pass.cpp
			- simd_unary.pass.cpp
		- simd.nonmembers/
			- simd_binary.pass.cpp
			- simd_cassign.pass.cpp
			- simd_comparison.pass.cpp
			- simd_reductions.pass.cpp
			- simd_alg.pass.cpp
			- simd.math/
				- ......
		- simd.mask.class/
			- simd_mask_width.pass.cpp
			- simd_mask_ctor.pass.cpp
			- simd_mask_copy.pass.cpp
			- simd_mask_subscr.pass.cpp
			- simd_mask_unary.pass.cpp
		- simd.mask.nonmembers/
			- simd_mask_binary.pass.cpp
			- simd_mask_cassign.pass.cpp
			- simd_mask_comparison.pass.cpp
			- simd_mask_reductions.pass.cpp
			- simd_mask_where.pass.cpp
		- test_utils.h

### Current status

At present, we have implemented all external user interfaces **except** the Section 9.7.7 Math Library. And added corresponding external interfaces tests.

We use [bootstrapping build](https://libcxx.llvm.org/BuildingLibcxx.html#bootstrapping-build) to build and test. All the tests passed with x86_64 from SSE-only up to AVX512. And there are still 4 failed tests on ARM64. Testing on other target platforms has not been completed.

#### Interfaces support

| Documentation Sections | Classes and Functions | Implementation| Related Tests |
| ------ | ------ | ------ | ------ |
| 9.3 simd ABI tags | scalar<br>fixed\_size<br>max\_fixed\_size<br>compatible<br>native | Done | All interface tests involving ABIs will traverse all these ABI tags |
| 9.4 simd type traits |is\_abi\_tag<br>is\_simd<br>is\_simd\_mask<br>is\_simd\_flag\_type<br>simd\_size<br>memory\_alignment<br>rebind\_simd<br>resize\_simd | Done | simd.traits/<br> is\_abi\_tag.pass.cpp <br> is\_simd.pass.cpp <br> is\_simd\_mask.pass.cpp <br> is\_simd\_flag\_type.pass.cpp <br> simd\_size.pass.cpp <br> memory\_alignment.pass.cpp <br> rebind\_simd.pass.cpp <br> resize\_simd.pass.cpp |
| 9.5 Where expression class templates | const\_where\_expression<br>where\_expression| Done| simd.whereexpr/ <br> const\_where\_expression.pass.cpp <br> where\_expression.pass.cpp |
| 9.6 Class template simd |  |  | simd.class/ |
| 9.6.2 simd width |  size() | Done | simd\_width.pass.cpp |
| 9.6.3 Element references | \_\_simd\_reference | Done | simd.reference/ <br> reference\_value\_type.pass.cpp <br> reference\_operators.pass.cpp <br> reference\_swap.pass.cpp |
| 9.6.4 simd constructors |  simd(U&&)<br> simd(const simd\<U, simd\_abi::fixed\_size\<size()>>& x) <br> simd(G&& gen)<br> simd(const U* mem, Flags)| Done | simd\_ctor.pass.cpp |
| 9.6.5 simd copy functions |  copy\_from(const U* mem, Flags) <br> copy\_to(U* mem, Flags) | Done | simd\_copy.pass.cpp |
| 9.6.6 simd subscript operators |  reference operator\[\](size\_t i)<br>value\_type operator\[](size\_t i) const| Done | simd\_subscr.pass.cpp |
| 9.6.7 simd unary operators |  operator++()<br> operator++(int)<br>operator--()<br>operator--(int)<br>operator!()<br>operator~()<br>operator+()<br>operator-()| Done | simd\_unary.pass.cpp |
| 9.7 simd non-member operations |  |  | simd.nonmembers/ |
| 9.7.1 simd binary operators | operator+(const simd& lhs, const simd& rhs)<br>operator-(const simd& lhs, const simd& rhs)<br>operator*(const simd& lhs, const simd& rhs)<br>operator/(const simd& lhs, const simd& rhs)<br>operator%(const simd& lhs, const simd& rhs)<br>operator&(const simd& lhs, const simd& rhs)<br>operator\|(const simd& lhs, const simd& rhs)<br>operator^(const simd& lhs, const simd& rhs)<br>operator<<(const simd& lhs, const simd& rhs)<br>operator>>(const simd& lhs, const simd& rhs)  | Done | simd\_binary.pass.cpp |
| 9.7.2 simd compound assignment |operator+=(simd& lhs, const simd& rhs)<br>operator-=(simd& lhs, const simd& rhs)<br> operator*=(simd& lhs, const simd& rhs)<br>operator/=(simd& lhs, const simd& rhs)<br>operator%=(simd& lhs, const simd& rhs)<br>operator&=(simd& lhs, const simd& rhs)<br>operator\|=(simd& lhs, const simd& rhs)<br>operator^=(simd& lhs, const simd& rhs)<br>operator<<=(simd& lhs, const simd& rhs)<br>operator>>=(simd& lhs, const simd& rhs) | Done | simd\_cassign.pass.cpp |
| 9.7.3 simd compare operators | operator==(const simd& lhs, const simd& rhs)<br>operator!=(const simd& lhs, const simd& rhs)<br> operator>=(const simd& lhs, const simd& rhs)<br>operator<=(const simd& lhs, const simd& rhs)<br>operator>(const simd& lhs, const simd& rhs)<br>operator<(const simd& lhs, const simd& rhs)| Done | simd\_comparison.pass.cpp |
| 9.7.4 simd reductions | reduce(const simd<T, Abi>& x, BinaryOperation binary\_op = {})<br>reduce(const const\_where\_expression<M, V>& x, typename V::value\_type identity\_element, BinaryOperation binary\_op = {})<br>reduce(const const\_where\_expression<M, V>& x, plus<> binary\_op)<br>reduce(const const\_where\_expression<M, V>& x, multiplies<> binary\_op)<br>reduce(const const\_where\_expression<M, V>& x, bit\_and<> binary\_op)<br>reduce(const const\_where\_expression<M, V>& x, bit\_or<> binary\_op)<br>reduce(const const\_where\_expression<M, V>& x, bit\_xor<> binary\_op)<br>hmin(const simd<T, Abi>& x)<br>hmin(const const\_where\_expression<M, V>& x)<br>hmax(const simd<T, Abi>& x)<br>hmax(const const\_where\_expression<M, V>& x)| Done | simd\_reductions.pass.cpp |
| 9.7.5 Casts | simd\_cast(const simd<U, Abi>& x)<br>static\_simd\_cast(const simd<U, Abi>& x)<br>to\_fixed\_size(const simd<T, Abi>& x)<br>to\_fixed\_size(const simd\_mask<T, Abi>& x)<br>to\_native(const fixed\_size\_simd<T, N>& x)<br>to\_native(const fixed\_size\_simd\_mask<T, N>&x)<br>to\_compatible(const fixed\_size\_simd<T, N>& x)<br>to\_compatible(const fixed\_size\_simd\_mask<T, N>& x)<br>split(const simd<T, Abi>& x)<br>split(const simd\_mask<T, Abi>& x)<br>split(const simd<typename V::value\_type, Abi>& x)<br>split(const simd\_mask<typename V::simd\_type::value\_type, Abi>& x)<br>split\_by(const simd<T, A>& x) split\_by(const simd\_mask<T, A>& x)<br>concat(const simd<T, Abis>&... xs)<br>concat(const simd\_mask<T, Abis>&... xs)<br>concat(const array<simd<T, Abi>, N>& arr)<br>concat(const array<simd\_mask<T, Abi>, N>& arr)| Done | simd.casts/ <br> static\_simd\_cast.pass.cpp <br> simd\_cast.pass.cpp <br> to\_fixed\_size.pass.cpp <br> to\_native.pass.cpp <br> to\_compatible.pass.cpp <br> split.pass.cpp <br> split\_by.pass.cpp <br> concat.pass.cpp |
| 9.7.6 Algorithms |min(const simd<T, Abi>& a, const simd<T, Abi>& b)<br>max(const simd<T, Abi>& a, const simd<T, Abi>& b)<br>minmax(const simd<T, Abi>& a, const simd<T, Abi>& b) <br> clamp(const simd<T, Abi>& v, const simd<T, Abi>& lo, const simd<T, Abi>& hi) | Done | simd\_alg.pass.cpp |
| 9.7.7 Math library |  | Pending | Pending |
| 9.8 Class template simd\_mask |  |  | simd.mask.class/ |
| 9.8.2 simd\_mask width |size() | Done | simd\_mask\_width.pass.cpp |
| 9.8.3 simd\_mask constructors | simd\_mask(value\_type x)<br>simd\_mask(const simd\_mask\<U, simd\_abi::fixed\_size\<size()>>& x)<br>simd\_mask(const value\_type* mem, Flags) | Done | simd\_mask\_ctor.pass.cpp |
| 9.8.4 simd\_mask copy functions |copy\_from(const value\_type* mem, Flags) <br>copy\_to(value\_type* mem, Flags)| Done | simd\_mask\_copy.pass.cpp |
| 9.8.5 simd\_mask subscript operators |reference operator\[](size\_t i)<br>value\_type operator\[](size\_t i) const | Done | simd\_mask\_subscr.pass.cpp |
| 9.8.6 simd\_mask unary operators |  operator!() | Done | simd\_mask\_unary.pass.cpp |
| 9.9 simd\_mask non-member operations |  |  | simd.mask.nonmembers/ |
| 9.9.1 simd\_mask binary operators | operator&&(const simd\_mask& lhs, const simd\_mask& rhs)<br>operator\|\|(const simd\_mask& lhs, const simd\_mask& rhs)<br> operator& (const simd\_mask& lhs, const simd\_mask& rhs)<br>operator\| (const simd\_mask& lhs, const simd\_mask& rhs)<br>operator^ (const simd\_mask& lhs, const simd\_mask& rhs) | Done | simd\_mask\_binary.pass.cpp |
| 9.9.2 simd\_mask compound assignment |  operator&=(simd\_mask& lhs, const simd\_mask& rhs)<br>operator\|=(simd\_mask& lhs, const simd\_mask& rhs)<br> operator^=(simd\_mask& lhs, const simd\_mask& rhs)| Done | simd\_mask\_cassign.pass.cpp |
| 9.9.3 simd\_mask comparisons |  operator==(const simd\_mask&, const simd\_mask&)<br> operator!=(const simd\_mask&, const simd\_mask&) | Done | simd\_mask\_comparison.pass.cpp |
| 9.9.4 simd\_mask reductions |  all\_of(const simd\_mask<T, Abi>& k)<br>any\_of(const simd\_mask<T, Abi>& k)<br>none\_of(const simd\_mask<T, Abi>& k)<br>some\_of(const simd\_mask<T, Abi>& k)<br>popcount(const simd\_mask<T, Abi>& k)<br>find\_first\_set(const simd\_mask<T, Abi>& k)<br>find\_last\_set(const simd\_mask<T, Abi>& k)<br>all\_of(T)<br>any\_of(T)<br>none\_of(T)<br>some\_of(T)<br>popcount(T)  | Done | simd\_mask\_reductions.pass.cpp |
| 9.9.5 where functions |where(const typename simd<T, Abi>::mask\_type& k, simd<T, Abi>& v)<br>where(const typename simd<T, Abi>::mask\_type& k, const simd<T, Abi>& v)<br>where(const type\_identity\_t<simd\_mask<T, Abi>>& k, simd\_mask<T, Abi>& v)<br>where(const type\_identity\_t<simd\_mask<T, Abi>>& k, const simd\_mask<T, Abi>& v)<br> where(see below k, const T& v) | Done | simd\_mask\_where.pass.cpp |



## Existing issues and Future work

### Implementations

- About compatibility:
	- Some features of LLVM 14 or later are used in the current implementation. Therefore, it may not be compatible with lower version compilers. Need to use [bootstrapping build](https://libcxx.llvm.org/BuildingLibcxx.html#bootstrapping-build). Modifications may be required for compatibility
	- Some features of C++20 or later are used in the current implementation. It does not compatible with lower C++ versions. Modifications may be required for compatibility.
- Refine the implementation of ABI tags to support more target platforms.
- Optimize the implementation of simd operations on specific target platforms (May need to use intrinsics).
- Optimize target platform specialization may need to extend implementation of ABI `fixed_size`.
- Implement an internal mask with bitwise for AVX512.
- Math library support.

### Tests

- Negative tests for SFINAE check.
- Run tests in more target platform environments such as PowerPC.
- Optimize test structure, increase code reuse and reduce redundancy.
- Because the test uses a framework with high coverage, the test will take a long time. It can be simplified and optimized if necessary.

## Contributors

- Yin Zhang - <zhangyin2018@iscas.ac.cn> (Contact me if you have any questions and suggestions)
- Yiliang He - <QuarticCat@protonmail.com>
- Yi Zhang - <zhangyi216@mails.ucas.ac.cn>
- Haolin Pan - <panhaolin21@mails.ucas.ac.cn>
- Jiatai He - <jiatai2021@iscas.ac.cn>
- Heda Chen - <marcythm@gmail.com>
- Haichuan Hu - <huhaichuan0704@126.com>
- Haohang Shi - <shyhot@outlook.com>

PLCT Lab, Intelligent Software Research Center

Institute of Software Chinese Academy of Sciences

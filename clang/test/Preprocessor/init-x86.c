//
// RUN: %clang_cc1 -E -dM -ffreestanding -triple=i386-none-none < /dev/null | FileCheck -match-full-lines -check-prefix I386 %s
//
// I386-NOT:#define _LP64
// I386:#define __BIGGEST_ALIGNMENT__ 16
// I386:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
// I386:#define __CHAR16_TYPE__ unsigned short
// I386:#define __CHAR32_TYPE__ unsigned int
// I386:#define __CHAR_BIT__ 8
// I386:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
// I386:#define __DBL_DIG__ 15
// I386:#define __DBL_EPSILON__ 2.2204460492503131e-16
// I386:#define __DBL_HAS_DENORM__ 1
// I386:#define __DBL_HAS_INFINITY__ 1
// I386:#define __DBL_HAS_QUIET_NAN__ 1
// I386:#define __DBL_MANT_DIG__ 53
// I386:#define __DBL_MAX_10_EXP__ 308
// I386:#define __DBL_MAX_EXP__ 1024
// I386:#define __DBL_MAX__ 1.7976931348623157e+308
// I386:#define __DBL_MIN_10_EXP__ (-307)
// I386:#define __DBL_MIN_EXP__ (-1021)
// I386:#define __DBL_MIN__ 2.2250738585072014e-308
// I386:#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
// I386:#define __FLT_DENORM_MIN__ 1.40129846e-45F
// I386:#define __FLT_DIG__ 6
// I386:#define __FLT_EPSILON__ 1.19209290e-7F
// I386:#define __FLT_HAS_DENORM__ 1
// I386:#define __FLT_HAS_INFINITY__ 1
// I386:#define __FLT_HAS_QUIET_NAN__ 1
// I386:#define __FLT_MANT_DIG__ 24
// I386:#define __FLT_MAX_10_EXP__ 38
// I386:#define __FLT_MAX_EXP__ 128
// I386:#define __FLT_MAX__ 3.40282347e+38F
// I386:#define __FLT_MIN_10_EXP__ (-37)
// I386:#define __FLT_MIN_EXP__ (-125)
// I386:#define __FLT_MIN__ 1.17549435e-38F
// I386:#define __FLT_RADIX__ 2
// I386:#define __INT16_C(c) c
// I386:#define __INT16_C_SUFFIX__
// I386:#define __INT16_FMTd__ "hd"
// I386:#define __INT16_FMTi__ "hi"
// I386:#define __INT16_MAX__ 32767
// I386:#define __INT16_TYPE__ short
// I386:#define __INT32_C(c) c
// I386:#define __INT32_C_SUFFIX__
// I386:#define __INT32_FMTd__ "d"
// I386:#define __INT32_FMTi__ "i"
// I386:#define __INT32_MAX__ 2147483647
// I386:#define __INT32_TYPE__ int
// I386:#define __INT64_C(c) c##LL
// I386:#define __INT64_C_SUFFIX__ LL
// I386:#define __INT64_FMTd__ "lld"
// I386:#define __INT64_FMTi__ "lli"
// I386:#define __INT64_MAX__ 9223372036854775807LL
// I386:#define __INT64_TYPE__ long long int
// I386:#define __INT8_C(c) c
// I386:#define __INT8_C_SUFFIX__
// I386:#define __INT8_FMTd__ "hhd"
// I386:#define __INT8_FMTi__ "hhi"
// I386:#define __INT8_MAX__ 127
// I386:#define __INT8_TYPE__ signed char
// I386:#define __INTMAX_C(c) c##LL
// I386:#define __INTMAX_C_SUFFIX__ LL
// I386:#define __INTMAX_FMTd__ "lld"
// I386:#define __INTMAX_FMTi__ "lli"
// I386:#define __INTMAX_MAX__ 9223372036854775807LL
// I386:#define __INTMAX_TYPE__ long long int
// I386:#define __INTMAX_WIDTH__ 64
// I386:#define __INTPTR_FMTd__ "d"
// I386:#define __INTPTR_FMTi__ "i"
// I386:#define __INTPTR_MAX__ 2147483647
// I386:#define __INTPTR_TYPE__ int
// I386:#define __INTPTR_WIDTH__ 32
// I386:#define __INT_FAST16_FMTd__ "hd"
// I386:#define __INT_FAST16_FMTi__ "hi"
// I386:#define __INT_FAST16_MAX__ 32767
// I386:#define __INT_FAST16_TYPE__ short
// I386:#define __INT_FAST32_FMTd__ "d"
// I386:#define __INT_FAST32_FMTi__ "i"
// I386:#define __INT_FAST32_MAX__ 2147483647
// I386:#define __INT_FAST32_TYPE__ int
// I386:#define __INT_FAST64_FMTd__ "lld"
// I386:#define __INT_FAST64_FMTi__ "lli"
// I386:#define __INT_FAST64_MAX__ 9223372036854775807LL
// I386:#define __INT_FAST64_TYPE__ long long int
// I386:#define __INT_FAST8_FMTd__ "hhd"
// I386:#define __INT_FAST8_FMTi__ "hhi"
// I386:#define __INT_FAST8_MAX__ 127
// I386:#define __INT_FAST8_TYPE__ signed char
// I386:#define __INT_LEAST16_FMTd__ "hd"
// I386:#define __INT_LEAST16_FMTi__ "hi"
// I386:#define __INT_LEAST16_MAX__ 32767
// I386:#define __INT_LEAST16_TYPE__ short
// I386:#define __INT_LEAST32_FMTd__ "d"
// I386:#define __INT_LEAST32_FMTi__ "i"
// I386:#define __INT_LEAST32_MAX__ 2147483647
// I386:#define __INT_LEAST32_TYPE__ int
// I386:#define __INT_LEAST64_FMTd__ "lld"
// I386:#define __INT_LEAST64_FMTi__ "lli"
// I386:#define __INT_LEAST64_MAX__ 9223372036854775807LL
// I386:#define __INT_LEAST64_TYPE__ long long int
// I386:#define __INT_LEAST8_FMTd__ "hhd"
// I386:#define __INT_LEAST8_FMTi__ "hhi"
// I386:#define __INT_LEAST8_MAX__ 127
// I386:#define __INT_LEAST8_TYPE__ signed char
// I386:#define __INT_MAX__ 2147483647
// I386:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
// I386:#define __LDBL_DIG__ 18
// I386:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
// I386:#define __LDBL_HAS_DENORM__ 1
// I386:#define __LDBL_HAS_INFINITY__ 1
// I386:#define __LDBL_HAS_QUIET_NAN__ 1
// I386:#define __LDBL_MANT_DIG__ 64
// I386:#define __LDBL_MAX_10_EXP__ 4932
// I386:#define __LDBL_MAX_EXP__ 16384
// I386:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
// I386:#define __LDBL_MIN_10_EXP__ (-4931)
// I386:#define __LDBL_MIN_EXP__ (-16381)
// I386:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
// I386:#define __LITTLE_ENDIAN__ 1
// I386:#define __LONG_LONG_MAX__ 9223372036854775807LL
// I386:#define __LONG_MAX__ 2147483647L
// I386-NOT:#define __LP64__
// I386:#define __NO_MATH_INLINES 1
// I386:#define __POINTER_WIDTH__ 32
// I386:#define __PTRDIFF_TYPE__ int
// I386:#define __PTRDIFF_WIDTH__ 32
// I386:#define __REGISTER_PREFIX__
// I386:#define __SCHAR_MAX__ 127
// I386:#define __SHRT_MAX__ 32767
// I386:#define __SIG_ATOMIC_MAX__ 2147483647
// I386:#define __SIG_ATOMIC_WIDTH__ 32
// I386:#define __SIZEOF_DOUBLE__ 8
// I386:#define __SIZEOF_FLOAT__ 4
// I386:#define __SIZEOF_INT__ 4
// I386:#define __SIZEOF_LONG_DOUBLE__ 12
// I386:#define __SIZEOF_LONG_LONG__ 8
// I386:#define __SIZEOF_LONG__ 4
// I386:#define __SIZEOF_POINTER__ 4
// I386:#define __SIZEOF_PTRDIFF_T__ 4
// I386:#define __SIZEOF_SHORT__ 2
// I386:#define __SIZEOF_SIZE_T__ 4
// I386:#define __SIZEOF_WCHAR_T__ 4
// I386:#define __SIZEOF_WINT_T__ 4
// I386:#define __SIZE_MAX__ 4294967295U
// I386:#define __SIZE_TYPE__ unsigned int
// I386:#define __SIZE_WIDTH__ 32
// I386:#define __UINT16_C(c) c
// I386:#define __UINT16_C_SUFFIX__
// I386:#define __UINT16_MAX__ 65535
// I386:#define __UINT16_TYPE__ unsigned short
// I386:#define __UINT32_C(c) c##U
// I386:#define __UINT32_C_SUFFIX__ U
// I386:#define __UINT32_MAX__ 4294967295U
// I386:#define __UINT32_TYPE__ unsigned int
// I386:#define __UINT64_C(c) c##ULL
// I386:#define __UINT64_C_SUFFIX__ ULL
// I386:#define __UINT64_MAX__ 18446744073709551615ULL
// I386:#define __UINT64_TYPE__ long long unsigned int
// I386:#define __UINT8_C(c) c
// I386:#define __UINT8_C_SUFFIX__
// I386:#define __UINT8_MAX__ 255
// I386:#define __UINT8_TYPE__ unsigned char
// I386:#define __UINTMAX_C(c) c##ULL
// I386:#define __UINTMAX_C_SUFFIX__ ULL
// I386:#define __UINTMAX_MAX__ 18446744073709551615ULL
// I386:#define __UINTMAX_TYPE__ long long unsigned int
// I386:#define __UINTMAX_WIDTH__ 64
// I386:#define __UINTPTR_MAX__ 4294967295U
// I386:#define __UINTPTR_TYPE__ unsigned int
// I386:#define __UINTPTR_WIDTH__ 32
// I386:#define __UINT_FAST16_MAX__ 65535
// I386:#define __UINT_FAST16_TYPE__ unsigned short
// I386:#define __UINT_FAST32_MAX__ 4294967295U
// I386:#define __UINT_FAST32_TYPE__ unsigned int
// I386:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
// I386:#define __UINT_FAST64_TYPE__ long long unsigned int
// I386:#define __UINT_FAST8_MAX__ 255
// I386:#define __UINT_FAST8_TYPE__ unsigned char
// I386:#define __UINT_LEAST16_MAX__ 65535
// I386:#define __UINT_LEAST16_TYPE__ unsigned short
// I386:#define __UINT_LEAST32_MAX__ 4294967295U
// I386:#define __UINT_LEAST32_TYPE__ unsigned int
// I386:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
// I386:#define __UINT_LEAST64_TYPE__ long long unsigned int
// I386:#define __UINT_LEAST8_MAX__ 255
// I386:#define __UINT_LEAST8_TYPE__ unsigned char
// I386:#define __USER_LABEL_PREFIX__
// I386:#define __WCHAR_MAX__ 2147483647
// I386:#define __WCHAR_TYPE__ int
// I386:#define __WCHAR_WIDTH__ 32
// I386:#define __WINT_TYPE__ int
// I386:#define __WINT_WIDTH__ 32
// I386:#define __i386 1
// I386:#define __i386__ 1
// I386:#define i386 1

// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=i386-pc-linux-gnu -target-cpu i486 < /dev/null | FileCheck -match-full-lines -check-prefix I386-LINUX -check-prefix I386-LINUX-ALIGN32 %s
// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=i386-pc-linux-gnu -target-cpu pentium4 < /dev/null | FileCheck -match-full-lines -check-prefix I386-LINUX -check-prefix I386-LINUX-ALIGN64 %s
// RUN: %clang_cc1 -x c++ -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=i386-pc-linux-gnu -target-cpu pentium4 < /dev/null | FileCheck -match-full-lines -check-prefix I386-LINUX -check-prefix I386-LINUX-ALIGN64 -check-prefix I386-LINUX-CXX %s
//
// I386-LINUX-NOT:#define _LP64
// I386-LINUX:#define __BIGGEST_ALIGNMENT__ 16
// I386-LINUX:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
// I386-LINUX:#define __CHAR16_TYPE__ unsigned short
// I386-LINUX:#define __CHAR32_TYPE__ unsigned int
// I386-LINUX:#define __CHAR_BIT__ 8
// I386-LINUX:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
// I386-LINUX:#define __DBL_DIG__ 15
// I386-LINUX:#define __DBL_EPSILON__ 2.2204460492503131e-16
// I386-LINUX:#define __DBL_HAS_DENORM__ 1
// I386-LINUX:#define __DBL_HAS_INFINITY__ 1
// I386-LINUX:#define __DBL_HAS_QUIET_NAN__ 1
// I386-LINUX:#define __DBL_MANT_DIG__ 53
// I386-LINUX:#define __DBL_MAX_10_EXP__ 308
// I386-LINUX:#define __DBL_MAX_EXP__ 1024
// I386-LINUX:#define __DBL_MAX__ 1.7976931348623157e+308
// I386-LINUX:#define __DBL_MIN_10_EXP__ (-307)
// I386-LINUX:#define __DBL_MIN_EXP__ (-1021)
// I386-LINUX:#define __DBL_MIN__ 2.2250738585072014e-308
// I386-LINUX:#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
// I386-LINUX:#define __FLT_DENORM_MIN__ 1.40129846e-45F
// I386-LINUX:#define __FLT_DIG__ 6
// I386-LINUX:#define __FLT_EPSILON__ 1.19209290e-7F
// I386-LINUX:#define __FLT_HAS_DENORM__ 1
// I386-LINUX:#define __FLT_HAS_INFINITY__ 1
// I386-LINUX:#define __FLT_HAS_QUIET_NAN__ 1
// I386-LINUX:#define __FLT_MANT_DIG__ 24
// I386-LINUX:#define __FLT_MAX_10_EXP__ 38
// I386-LINUX:#define __FLT_MAX_EXP__ 128
// I386-LINUX:#define __FLT_MAX__ 3.40282347e+38F
// I386-LINUX:#define __FLT_MIN_10_EXP__ (-37)
// I386-LINUX:#define __FLT_MIN_EXP__ (-125)
// I386-LINUX:#define __FLT_MIN__ 1.17549435e-38F
// I386-LINUX:#define __FLT_RADIX__ 2
// I386-LINUX:#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
// I386-LINUX:#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
// I386-LINUX:#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
// I386-LINUX:#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
// I386-LINUX:#define __GCC_ATOMIC_INT_LOCK_FREE 2
// I386-LINUX-ALIGN32:#define __GCC_ATOMIC_LLONG_LOCK_FREE 1
// I386-LINUX-ALIGN64:#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
// I386-LINUX:#define __GCC_ATOMIC_LONG_LOCK_FREE 2
// I386-LINUX:#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
// I386-LINUX:#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
// I386-LINUX:#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
// I386-LINUX:#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
// I386-LINUX:#define __INT16_C(c) c
// I386-LINUX:#define __INT16_C_SUFFIX__
// I386-LINUX:#define __INT16_FMTd__ "hd"
// I386-LINUX:#define __INT16_FMTi__ "hi"
// I386-LINUX:#define __INT16_MAX__ 32767
// I386-LINUX:#define __INT16_TYPE__ short
// I386-LINUX:#define __INT32_C(c) c
// I386-LINUX:#define __INT32_C_SUFFIX__
// I386-LINUX:#define __INT32_FMTd__ "d"
// I386-LINUX:#define __INT32_FMTi__ "i"
// I386-LINUX:#define __INT32_MAX__ 2147483647
// I386-LINUX:#define __INT32_TYPE__ int
// I386-LINUX:#define __INT64_C(c) c##LL
// I386-LINUX:#define __INT64_C_SUFFIX__ LL
// I386-LINUX:#define __INT64_FMTd__ "lld"
// I386-LINUX:#define __INT64_FMTi__ "lli"
// I386-LINUX:#define __INT64_MAX__ 9223372036854775807LL
// I386-LINUX:#define __INT64_TYPE__ long long int
// I386-LINUX:#define __INT8_C(c) c
// I386-LINUX:#define __INT8_C_SUFFIX__
// I386-LINUX:#define __INT8_FMTd__ "hhd"
// I386-LINUX:#define __INT8_FMTi__ "hhi"
// I386-LINUX:#define __INT8_MAX__ 127
// I386-LINUX:#define __INT8_TYPE__ signed char
// I386-LINUX:#define __INTMAX_C(c) c##LL
// I386-LINUX:#define __INTMAX_C_SUFFIX__ LL
// I386-LINUX:#define __INTMAX_FMTd__ "lld"
// I386-LINUX:#define __INTMAX_FMTi__ "lli"
// I386-LINUX:#define __INTMAX_MAX__ 9223372036854775807LL
// I386-LINUX:#define __INTMAX_TYPE__ long long int
// I386-LINUX:#define __INTMAX_WIDTH__ 64
// I386-LINUX:#define __INTPTR_FMTd__ "d"
// I386-LINUX:#define __INTPTR_FMTi__ "i"
// I386-LINUX:#define __INTPTR_MAX__ 2147483647
// I386-LINUX:#define __INTPTR_TYPE__ int
// I386-LINUX:#define __INTPTR_WIDTH__ 32
// I386-LINUX:#define __INT_FAST16_FMTd__ "hd"
// I386-LINUX:#define __INT_FAST16_FMTi__ "hi"
// I386-LINUX:#define __INT_FAST16_MAX__ 32767
// I386-LINUX:#define __INT_FAST16_TYPE__ short
// I386-LINUX:#define __INT_FAST32_FMTd__ "d"
// I386-LINUX:#define __INT_FAST32_FMTi__ "i"
// I386-LINUX:#define __INT_FAST32_MAX__ 2147483647
// I386-LINUX:#define __INT_FAST32_TYPE__ int
// I386-LINUX:#define __INT_FAST64_FMTd__ "lld"
// I386-LINUX:#define __INT_FAST64_FMTi__ "lli"
// I386-LINUX:#define __INT_FAST64_MAX__ 9223372036854775807LL
// I386-LINUX:#define __INT_FAST64_TYPE__ long long int
// I386-LINUX:#define __INT_FAST8_FMTd__ "hhd"
// I386-LINUX:#define __INT_FAST8_FMTi__ "hhi"
// I386-LINUX:#define __INT_FAST8_MAX__ 127
// I386-LINUX:#define __INT_FAST8_TYPE__ signed char
// I386-LINUX:#define __INT_LEAST16_FMTd__ "hd"
// I386-LINUX:#define __INT_LEAST16_FMTi__ "hi"
// I386-LINUX:#define __INT_LEAST16_MAX__ 32767
// I386-LINUX:#define __INT_LEAST16_TYPE__ short
// I386-LINUX:#define __INT_LEAST32_FMTd__ "d"
// I386-LINUX:#define __INT_LEAST32_FMTi__ "i"
// I386-LINUX:#define __INT_LEAST32_MAX__ 2147483647
// I386-LINUX:#define __INT_LEAST32_TYPE__ int
// I386-LINUX:#define __INT_LEAST64_FMTd__ "lld"
// I386-LINUX:#define __INT_LEAST64_FMTi__ "lli"
// I386-LINUX:#define __INT_LEAST64_MAX__ 9223372036854775807LL
// I386-LINUX:#define __INT_LEAST64_TYPE__ long long int
// I386-LINUX:#define __INT_LEAST8_FMTd__ "hhd"
// I386-LINUX:#define __INT_LEAST8_FMTi__ "hhi"
// I386-LINUX:#define __INT_LEAST8_MAX__ 127
// I386-LINUX:#define __INT_LEAST8_TYPE__ signed char
// I386-LINUX:#define __INT_MAX__ 2147483647
// I386-LINUX:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
// I386-LINUX:#define __LDBL_DIG__ 18
// I386-LINUX:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
// I386-LINUX:#define __LDBL_HAS_DENORM__ 1
// I386-LINUX:#define __LDBL_HAS_INFINITY__ 1
// I386-LINUX:#define __LDBL_HAS_QUIET_NAN__ 1
// I386-LINUX:#define __LDBL_MANT_DIG__ 64
// I386-LINUX:#define __LDBL_MAX_10_EXP__ 4932
// I386-LINUX:#define __LDBL_MAX_EXP__ 16384
// I386-LINUX:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
// I386-LINUX:#define __LDBL_MIN_10_EXP__ (-4931)
// I386-LINUX:#define __LDBL_MIN_EXP__ (-16381)
// I386-LINUX:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
// I386-LINUX:#define __LITTLE_ENDIAN__ 1
// I386-LINUX:#define __LONG_LONG_MAX__ 9223372036854775807LL
// I386-LINUX:#define __LONG_MAX__ 2147483647L
// I386-LINUX-NOT:#define __LP64__
// I386-LINUX:#define __NO_MATH_INLINES 1
// I386-LINUX:#define __POINTER_WIDTH__ 32
// I386-LINUX:#define __PTRDIFF_TYPE__ int
// I386-LINUX:#define __PTRDIFF_WIDTH__ 32
// I386-LINUX:#define __REGISTER_PREFIX__
// I386-LINUX:#define __SCHAR_MAX__ 127
// I386-LINUX:#define __SHRT_MAX__ 32767
// I386-LINUX:#define __SIG_ATOMIC_MAX__ 2147483647
// I386-LINUX:#define __SIG_ATOMIC_WIDTH__ 32
// I386-LINUX:#define __SIZEOF_DOUBLE__ 8
// I386-LINUX:#define __SIZEOF_FLOAT__ 4
// I386-LINUX:#define __SIZEOF_INT__ 4
// I386-LINUX:#define __SIZEOF_LONG_DOUBLE__ 12
// I386-LINUX:#define __SIZEOF_LONG_LONG__ 8
// I386-LINUX:#define __SIZEOF_LONG__ 4
// I386-LINUX:#define __SIZEOF_POINTER__ 4
// I386-LINUX:#define __SIZEOF_PTRDIFF_T__ 4
// I386-LINUX:#define __SIZEOF_SHORT__ 2
// I386-LINUX:#define __SIZEOF_SIZE_T__ 4
// I386-LINUX:#define __SIZEOF_WCHAR_T__ 4
// I386-LINUX:#define __SIZEOF_WINT_T__ 4
// I386-LINUX:#define __SIZE_MAX__ 4294967295U
// I386-LINUX:#define __SIZE_TYPE__ unsigned int
// I386-LINUX:#define __SIZE_WIDTH__ 32
// I386-LINUX-CXX:#define __STDCPP_DEFAULT_NEW_ALIGNMENT__ 8U
// I386-LINUX:#define __UINT16_C(c) c
// I386-LINUX:#define __UINT16_C_SUFFIX__
// I386-LINUX:#define __UINT16_MAX__ 65535
// I386-LINUX:#define __UINT16_TYPE__ unsigned short
// I386-LINUX:#define __UINT32_C(c) c##U
// I386-LINUX:#define __UINT32_C_SUFFIX__ U
// I386-LINUX:#define __UINT32_MAX__ 4294967295U
// I386-LINUX:#define __UINT32_TYPE__ unsigned int
// I386-LINUX:#define __UINT64_C(c) c##ULL
// I386-LINUX:#define __UINT64_C_SUFFIX__ ULL
// I386-LINUX:#define __UINT64_MAX__ 18446744073709551615ULL
// I386-LINUX:#define __UINT64_TYPE__ long long unsigned int
// I386-LINUX:#define __UINT8_C(c) c
// I386-LINUX:#define __UINT8_C_SUFFIX__
// I386-LINUX:#define __UINT8_MAX__ 255
// I386-LINUX:#define __UINT8_TYPE__ unsigned char
// I386-LINUX:#define __UINTMAX_C(c) c##ULL
// I386-LINUX:#define __UINTMAX_C_SUFFIX__ ULL
// I386-LINUX:#define __UINTMAX_MAX__ 18446744073709551615ULL
// I386-LINUX:#define __UINTMAX_TYPE__ long long unsigned int
// I386-LINUX:#define __UINTMAX_WIDTH__ 64
// I386-LINUX:#define __UINTPTR_MAX__ 4294967295U
// I386-LINUX:#define __UINTPTR_TYPE__ unsigned int
// I386-LINUX:#define __UINTPTR_WIDTH__ 32
// I386-LINUX:#define __UINT_FAST16_MAX__ 65535
// I386-LINUX:#define __UINT_FAST16_TYPE__ unsigned short
// I386-LINUX:#define __UINT_FAST32_MAX__ 4294967295U
// I386-LINUX:#define __UINT_FAST32_TYPE__ unsigned int
// I386-LINUX:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
// I386-LINUX:#define __UINT_FAST64_TYPE__ long long unsigned int
// I386-LINUX:#define __UINT_FAST8_MAX__ 255
// I386-LINUX:#define __UINT_FAST8_TYPE__ unsigned char
// I386-LINUX:#define __UINT_LEAST16_MAX__ 65535
// I386-LINUX:#define __UINT_LEAST16_TYPE__ unsigned short
// I386-LINUX:#define __UINT_LEAST32_MAX__ 4294967295U
// I386-LINUX:#define __UINT_LEAST32_TYPE__ unsigned int
// I386-LINUX:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
// I386-LINUX:#define __UINT_LEAST64_TYPE__ long long unsigned int
// I386-LINUX:#define __UINT_LEAST8_MAX__ 255
// I386-LINUX:#define __UINT_LEAST8_TYPE__ unsigned char
// I386-LINUX:#define __USER_LABEL_PREFIX__
// I386-LINUX:#define __WCHAR_MAX__ 2147483647
// I386-LINUX:#define __WCHAR_TYPE__ int
// I386-LINUX:#define __WCHAR_WIDTH__ 32
// I386-LINUX:#define __WINT_TYPE__ unsigned int
// I386-LINUX:#define __WINT_WIDTH__ 32
// I386-LINUX:#define __i386 1
// I386-LINUX:#define __i386__ 1
// I386-LINUX:#define i386 1

// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=i386-netbsd -target-cpu i486 < /dev/null | FileCheck -match-full-lines -check-prefix I386-NETBSD %s
// RUN: %clang_cc1 -x c++ -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=i386-netbsd -target-cpu i486 < /dev/null | FileCheck -match-full-lines -check-prefix I386-NETBSD -check-prefix I386-NETBSD-CXX %s
// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=i386-netbsd -target-cpu i486 -malign-double < /dev/null | FileCheck -match-full-lines -check-prefix I386-NETBSD %s
//
//
// I386-NETBSD-NOT:#define _LP64
// I386-NETBSD:#define __BIGGEST_ALIGNMENT__ 16
// I386-NETBSD:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
// I386-NETBSD:#define __CHAR16_TYPE__ unsigned short
// I386-NETBSD:#define __CHAR32_TYPE__ unsigned int
// I386-NETBSD:#define __CHAR_BIT__ 8
// I386-NETBSD:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
// I386-NETBSD:#define __DBL_DIG__ 15
// I386-NETBSD:#define __DBL_EPSILON__ 2.2204460492503131e-16
// I386-NETBSD:#define __DBL_HAS_DENORM__ 1
// I386-NETBSD:#define __DBL_HAS_INFINITY__ 1
// I386-NETBSD:#define __DBL_HAS_QUIET_NAN__ 1
// I386-NETBSD:#define __DBL_MANT_DIG__ 53
// I386-NETBSD:#define __DBL_MAX_10_EXP__ 308
// I386-NETBSD:#define __DBL_MAX_EXP__ 1024
// I386-NETBSD:#define __DBL_MAX__ 1.7976931348623157e+308
// I386-NETBSD:#define __DBL_MIN_10_EXP__ (-307)
// I386-NETBSD:#define __DBL_MIN_EXP__ (-1021)
// I386-NETBSD:#define __DBL_MIN__ 2.2250738585072014e-308
// I386-NETBSD:#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
// I386-NETBSD:#define __FLT_DENORM_MIN__ 1.40129846e-45F
// I386-NETBSD:#define __FLT_DIG__ 6
// I386-NETBSD:#define __FLT_EPSILON__ 1.19209290e-7F
// I386-NETBSD:#define __FLT_HAS_DENORM__ 1
// I386-NETBSD:#define __FLT_HAS_INFINITY__ 1
// I386-NETBSD:#define __FLT_HAS_QUIET_NAN__ 1
// I386-NETBSD:#define __FLT_MANT_DIG__ 24
// I386-NETBSD:#define __FLT_MAX_10_EXP__ 38
// I386-NETBSD:#define __FLT_MAX_EXP__ 128
// I386-NETBSD:#define __FLT_MAX__ 3.40282347e+38F
// I386-NETBSD:#define __FLT_MIN_10_EXP__ (-37)
// I386-NETBSD:#define __FLT_MIN_EXP__ (-125)
// I386-NETBSD:#define __FLT_MIN__ 1.17549435e-38F
// I386-NETBSD:#define __FLT_RADIX__ 2
// I386-NETBSD:#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
// I386-NETBSD:#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
// I386-NETBSD:#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
// I386-NETBSD:#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
// I386-NETBSD:#define __GCC_ATOMIC_INT_LOCK_FREE 2
// I386-NETBSD:#define __GCC_ATOMIC_LLONG_LOCK_FREE 1
// I386-NETBSD:#define __GCC_ATOMIC_LONG_LOCK_FREE 2
// I386-NETBSD:#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
// I386-NETBSD:#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
// I386-NETBSD:#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
// I386-NETBSD:#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
// I386-NETBSD:#define __INT16_C(c) c
// I386-NETBSD:#define __INT16_C_SUFFIX__
// I386-NETBSD:#define __INT16_FMTd__ "hd"
// I386-NETBSD:#define __INT16_FMTi__ "hi"
// I386-NETBSD:#define __INT16_MAX__ 32767
// I386-NETBSD:#define __INT16_TYPE__ short
// I386-NETBSD:#define __INT32_C(c) c
// I386-NETBSD:#define __INT32_C_SUFFIX__
// I386-NETBSD:#define __INT32_FMTd__ "d"
// I386-NETBSD:#define __INT32_FMTi__ "i"
// I386-NETBSD:#define __INT32_MAX__ 2147483647
// I386-NETBSD:#define __INT32_TYPE__ int
// I386-NETBSD:#define __INT64_C(c) c##LL
// I386-NETBSD:#define __INT64_C_SUFFIX__ LL
// I386-NETBSD:#define __INT64_FMTd__ "lld"
// I386-NETBSD:#define __INT64_FMTi__ "lli"
// I386-NETBSD:#define __INT64_MAX__ 9223372036854775807LL
// I386-NETBSD:#define __INT64_TYPE__ long long int
// I386-NETBSD:#define __INT8_C(c) c
// I386-NETBSD:#define __INT8_C_SUFFIX__
// I386-NETBSD:#define __INT8_FMTd__ "hhd"
// I386-NETBSD:#define __INT8_FMTi__ "hhi"
// I386-NETBSD:#define __INT8_MAX__ 127
// I386-NETBSD:#define __INT8_TYPE__ signed char
// I386-NETBSD:#define __INTMAX_C(c) c##LL
// I386-NETBSD:#define __INTMAX_C_SUFFIX__ LL
// I386-NETBSD:#define __INTMAX_FMTd__ "lld"
// I386-NETBSD:#define __INTMAX_FMTi__ "lli"
// I386-NETBSD:#define __INTMAX_MAX__ 9223372036854775807LL
// I386-NETBSD:#define __INTMAX_TYPE__ long long int
// I386-NETBSD:#define __INTMAX_WIDTH__ 64
// I386-NETBSD:#define __INTPTR_FMTd__ "d"
// I386-NETBSD:#define __INTPTR_FMTi__ "i"
// I386-NETBSD:#define __INTPTR_MAX__ 2147483647
// I386-NETBSD:#define __INTPTR_TYPE__ int
// I386-NETBSD:#define __INTPTR_WIDTH__ 32
// I386-NETBSD:#define __INT_FAST16_FMTd__ "hd"
// I386-NETBSD:#define __INT_FAST16_FMTi__ "hi"
// I386-NETBSD:#define __INT_FAST16_MAX__ 32767
// I386-NETBSD:#define __INT_FAST16_TYPE__ short
// I386-NETBSD:#define __INT_FAST32_FMTd__ "d"
// I386-NETBSD:#define __INT_FAST32_FMTi__ "i"
// I386-NETBSD:#define __INT_FAST32_MAX__ 2147483647
// I386-NETBSD:#define __INT_FAST32_TYPE__ int
// I386-NETBSD:#define __INT_FAST64_FMTd__ "lld"
// I386-NETBSD:#define __INT_FAST64_FMTi__ "lli"
// I386-NETBSD:#define __INT_FAST64_MAX__ 9223372036854775807LL
// I386-NETBSD:#define __INT_FAST64_TYPE__ long long int
// I386-NETBSD:#define __INT_FAST8_FMTd__ "hhd"
// I386-NETBSD:#define __INT_FAST8_FMTi__ "hhi"
// I386-NETBSD:#define __INT_FAST8_MAX__ 127
// I386-NETBSD:#define __INT_FAST8_TYPE__ signed char
// I386-NETBSD:#define __INT_LEAST16_FMTd__ "hd"
// I386-NETBSD:#define __INT_LEAST16_FMTi__ "hi"
// I386-NETBSD:#define __INT_LEAST16_MAX__ 32767
// I386-NETBSD:#define __INT_LEAST16_TYPE__ short
// I386-NETBSD:#define __INT_LEAST32_FMTd__ "d"
// I386-NETBSD:#define __INT_LEAST32_FMTi__ "i"
// I386-NETBSD:#define __INT_LEAST32_MAX__ 2147483647
// I386-NETBSD:#define __INT_LEAST32_TYPE__ int
// I386-NETBSD:#define __INT_LEAST64_FMTd__ "lld"
// I386-NETBSD:#define __INT_LEAST64_FMTi__ "lli"
// I386-NETBSD:#define __INT_LEAST64_MAX__ 9223372036854775807LL
// I386-NETBSD:#define __INT_LEAST64_TYPE__ long long int
// I386-NETBSD:#define __INT_LEAST8_FMTd__ "hhd"
// I386-NETBSD:#define __INT_LEAST8_FMTi__ "hhi"
// I386-NETBSD:#define __INT_LEAST8_MAX__ 127
// I386-NETBSD:#define __INT_LEAST8_TYPE__ signed char
// I386-NETBSD:#define __INT_MAX__ 2147483647
// I386-NETBSD:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
// I386-NETBSD:#define __LDBL_DIG__ 18
// I386-NETBSD:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
// I386-NETBSD:#define __LDBL_HAS_DENORM__ 1
// I386-NETBSD:#define __LDBL_HAS_INFINITY__ 1
// I386-NETBSD:#define __LDBL_HAS_QUIET_NAN__ 1
// I386-NETBSD:#define __LDBL_MANT_DIG__ 64
// I386-NETBSD:#define __LDBL_MAX_10_EXP__ 4932
// I386-NETBSD:#define __LDBL_MAX_EXP__ 16384
// I386-NETBSD:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
// I386-NETBSD:#define __LDBL_MIN_10_EXP__ (-4931)
// I386-NETBSD:#define __LDBL_MIN_EXP__ (-16381)
// I386-NETBSD:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
// I386-NETBSD:#define __LITTLE_ENDIAN__ 1
// I386-NETBSD:#define __LONG_LONG_MAX__ 9223372036854775807LL
// I386-NETBSD:#define __LONG_MAX__ 2147483647L
// I386-NETBSD-NOT:#define __LP64__
// I386-NETBSD:#define __NO_MATH_INLINES 1
// I386-NETBSD:#define __POINTER_WIDTH__ 32
// I386-NETBSD:#define __PTRDIFF_TYPE__ int
// I386-NETBSD:#define __PTRDIFF_WIDTH__ 32
// I386-NETBSD:#define __REGISTER_PREFIX__
// I386-NETBSD:#define __SCHAR_MAX__ 127
// I386-NETBSD:#define __SHRT_MAX__ 32767
// I386-NETBSD:#define __SIG_ATOMIC_MAX__ 2147483647
// I386-NETBSD:#define __SIG_ATOMIC_WIDTH__ 32
// I386-NETBSD:#define __SIZEOF_DOUBLE__ 8
// I386-NETBSD:#define __SIZEOF_FLOAT__ 4
// I386-NETBSD:#define __SIZEOF_INT__ 4
// I386-NETBSD:#define __SIZEOF_LONG_DOUBLE__ 12
// I386-NETBSD:#define __SIZEOF_LONG_LONG__ 8
// I386-NETBSD:#define __SIZEOF_LONG__ 4
// I386-NETBSD:#define __SIZEOF_POINTER__ 4
// I386-NETBSD:#define __SIZEOF_PTRDIFF_T__ 4
// I386-NETBSD:#define __SIZEOF_SHORT__ 2
// I386-NETBSD:#define __SIZEOF_SIZE_T__ 4
// I386-NETBSD:#define __SIZEOF_WCHAR_T__ 4
// I386-NETBSD:#define __SIZEOF_WINT_T__ 4
// I386-NETBSD:#define __SIZE_MAX__ 4294967295U
// I386-NETBSD:#define __SIZE_TYPE__ unsigned int
// I386-NETBSD:#define __SIZE_WIDTH__ 32
// I386-NETBSD-CXX:#define __STDCPP_DEFAULT_NEW_ALIGNMENT__ 4U
// I386-NETBSD:#define __UINT16_C(c) c
// I386-NETBSD:#define __UINT16_C_SUFFIX__
// I386-NETBSD:#define __UINT16_MAX__ 65535
// I386-NETBSD:#define __UINT16_TYPE__ unsigned short
// I386-NETBSD:#define __UINT32_C(c) c##U
// I386-NETBSD:#define __UINT32_C_SUFFIX__ U
// I386-NETBSD:#define __UINT32_MAX__ 4294967295U
// I386-NETBSD:#define __UINT32_TYPE__ unsigned int
// I386-NETBSD:#define __UINT64_C(c) c##ULL
// I386-NETBSD:#define __UINT64_C_SUFFIX__ ULL
// I386-NETBSD:#define __UINT64_MAX__ 18446744073709551615ULL
// I386-NETBSD:#define __UINT64_TYPE__ long long unsigned int
// I386-NETBSD:#define __UINT8_C(c) c
// I386-NETBSD:#define __UINT8_C_SUFFIX__
// I386-NETBSD:#define __UINT8_MAX__ 255
// I386-NETBSD:#define __UINT8_TYPE__ unsigned char
// I386-NETBSD:#define __UINTMAX_C(c) c##ULL
// I386-NETBSD:#define __UINTMAX_C_SUFFIX__ ULL
// I386-NETBSD:#define __UINTMAX_MAX__ 18446744073709551615ULL
// I386-NETBSD:#define __UINTMAX_TYPE__ long long unsigned int
// I386-NETBSD:#define __UINTMAX_WIDTH__ 64
// I386-NETBSD:#define __UINTPTR_MAX__ 4294967295U
// I386-NETBSD:#define __UINTPTR_TYPE__ unsigned int
// I386-NETBSD:#define __UINTPTR_WIDTH__ 32
// I386-NETBSD:#define __UINT_FAST16_MAX__ 65535
// I386-NETBSD:#define __UINT_FAST16_TYPE__ unsigned short
// I386-NETBSD:#define __UINT_FAST32_MAX__ 4294967295U
// I386-NETBSD:#define __UINT_FAST32_TYPE__ unsigned int
// I386-NETBSD:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
// I386-NETBSD:#define __UINT_FAST64_TYPE__ long long unsigned int
// I386-NETBSD:#define __UINT_FAST8_MAX__ 255
// I386-NETBSD:#define __UINT_FAST8_TYPE__ unsigned char
// I386-NETBSD:#define __UINT_LEAST16_MAX__ 65535
// I386-NETBSD:#define __UINT_LEAST16_TYPE__ unsigned short
// I386-NETBSD:#define __UINT_LEAST32_MAX__ 4294967295U
// I386-NETBSD:#define __UINT_LEAST32_TYPE__ unsigned int
// I386-NETBSD:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
// I386-NETBSD:#define __UINT_LEAST64_TYPE__ long long unsigned int
// I386-NETBSD:#define __UINT_LEAST8_MAX__ 255
// I386-NETBSD:#define __UINT_LEAST8_TYPE__ unsigned char
// I386-NETBSD:#define __USER_LABEL_PREFIX__
// I386-NETBSD:#define __WCHAR_MAX__ 2147483647
// I386-NETBSD:#define __WCHAR_TYPE__ int
// I386-NETBSD:#define __WCHAR_WIDTH__ 32
// I386-NETBSD:#define __WINT_TYPE__ int
// I386-NETBSD:#define __WINT_WIDTH__ 32
// I386-NETBSD:#define __i386 1
// I386-NETBSD:#define __i386__ 1
// I386-NETBSD:#define i386 1

// RUN: %clang_cc1 -E -dM -triple=i686-pc-mingw32 < /dev/null | FileCheck -match-full-lines -check-prefix I386-DECLSPEC-GNU %s
// RUN: %clang_cc1 -E -dM -triple=i686-unknown-cygwin < /dev/null | FileCheck -match-full-lines -check-prefix I386-DECLSPEC-GNU %s
// I386-DECLSPEC-GNU: #define __declspec{{.*}} __attribute__{{.*}}

// RUN: %clang_cc1 -E -dM -fms-extensions -triple=i686-pc-mingw32 < /dev/null | FileCheck -match-full-lines -check-prefix I386-DECLSPEC-MS %s
// RUN: %clang_cc1 -E -dM -fdeclspec -triple=i686-pc-mingw32 < /dev/null | FileCheck -match-full-lines -check-prefix I386-DECLSPEC-MS %s
// RUN: %clang_cc1 -E -dM -fms-extensions -triple=i686-unknown-cygwin < /dev/null | FileCheck -match-full-lines -check-prefix I386-DECLSPEC-MS %s
// RUN: %clang_cc1 -E -dM -fdeclspec -triple=i686-unknown-cygwin < /dev/null | FileCheck -match-full-lines -check-prefix I386-DECLSPEC-MS %s
// I386-DECLSPEC-MS: #define __declspec{{.*}} __declspec{{.*}}

//
// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=x86_64-none-none < /dev/null | FileCheck -match-full-lines -check-prefix X86_64 %s
// RUN: %clang_cc1 -x c++ -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=x86_64-none-none < /dev/null | FileCheck -match-full-lines -check-prefix X86_64 -check-prefix X86_64-CXX %s
//
// X86_64:#define _LP64 1
// X86_64-NOT:#define _LP32 1
// X86_64:#define __BIGGEST_ALIGNMENT__ 16
// X86_64:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
// X86_64:#define __CHAR16_TYPE__ unsigned short
// X86_64:#define __CHAR32_TYPE__ unsigned int
// X86_64:#define __CHAR_BIT__ 8
// X86_64:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
// X86_64:#define __DBL_DIG__ 15
// X86_64:#define __DBL_EPSILON__ 2.2204460492503131e-16
// X86_64:#define __DBL_HAS_DENORM__ 1
// X86_64:#define __DBL_HAS_INFINITY__ 1
// X86_64:#define __DBL_HAS_QUIET_NAN__ 1
// X86_64:#define __DBL_MANT_DIG__ 53
// X86_64:#define __DBL_MAX_10_EXP__ 308
// X86_64:#define __DBL_MAX_EXP__ 1024
// X86_64:#define __DBL_MAX__ 1.7976931348623157e+308
// X86_64:#define __DBL_MIN_10_EXP__ (-307)
// X86_64:#define __DBL_MIN_EXP__ (-1021)
// X86_64:#define __DBL_MIN__ 2.2250738585072014e-308
// X86_64:#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
// X86_64:#define __FLT_DENORM_MIN__ 1.40129846e-45F
// X86_64:#define __FLT_DIG__ 6
// X86_64:#define __FLT_EPSILON__ 1.19209290e-7F
// X86_64:#define __FLT_HAS_DENORM__ 1
// X86_64:#define __FLT_HAS_INFINITY__ 1
// X86_64:#define __FLT_HAS_QUIET_NAN__ 1
// X86_64:#define __FLT_MANT_DIG__ 24
// X86_64:#define __FLT_MAX_10_EXP__ 38
// X86_64:#define __FLT_MAX_EXP__ 128
// X86_64:#define __FLT_MAX__ 3.40282347e+38F
// X86_64:#define __FLT_MIN_10_EXP__ (-37)
// X86_64:#define __FLT_MIN_EXP__ (-125)
// X86_64:#define __FLT_MIN__ 1.17549435e-38F
// X86_64:#define __FLT_RADIX__ 2
// X86_64:#define __INT16_C(c) c
// X86_64:#define __INT16_C_SUFFIX__
// X86_64:#define __INT16_FMTd__ "hd"
// X86_64:#define __INT16_FMTi__ "hi"
// X86_64:#define __INT16_MAX__ 32767
// X86_64:#define __INT16_TYPE__ short
// X86_64:#define __INT32_C(c) c
// X86_64:#define __INT32_C_SUFFIX__
// X86_64:#define __INT32_FMTd__ "d"
// X86_64:#define __INT32_FMTi__ "i"
// X86_64:#define __INT32_MAX__ 2147483647
// X86_64:#define __INT32_TYPE__ int
// X86_64:#define __INT64_C(c) c##L
// X86_64:#define __INT64_C_SUFFIX__ L
// X86_64:#define __INT64_FMTd__ "ld"
// X86_64:#define __INT64_FMTi__ "li"
// X86_64:#define __INT64_MAX__ 9223372036854775807L
// X86_64:#define __INT64_TYPE__ long int
// X86_64:#define __INT8_C(c) c
// X86_64:#define __INT8_C_SUFFIX__
// X86_64:#define __INT8_FMTd__ "hhd"
// X86_64:#define __INT8_FMTi__ "hhi"
// X86_64:#define __INT8_MAX__ 127
// X86_64:#define __INT8_TYPE__ signed char
// X86_64:#define __INTMAX_C(c) c##L
// X86_64:#define __INTMAX_C_SUFFIX__ L
// X86_64:#define __INTMAX_FMTd__ "ld"
// X86_64:#define __INTMAX_FMTi__ "li"
// X86_64:#define __INTMAX_MAX__ 9223372036854775807L
// X86_64:#define __INTMAX_TYPE__ long int
// X86_64:#define __INTMAX_WIDTH__ 64
// X86_64:#define __INTPTR_FMTd__ "ld"
// X86_64:#define __INTPTR_FMTi__ "li"
// X86_64:#define __INTPTR_MAX__ 9223372036854775807L
// X86_64:#define __INTPTR_TYPE__ long int
// X86_64:#define __INTPTR_WIDTH__ 64
// X86_64:#define __INT_FAST16_FMTd__ "hd"
// X86_64:#define __INT_FAST16_FMTi__ "hi"
// X86_64:#define __INT_FAST16_MAX__ 32767
// X86_64:#define __INT_FAST16_TYPE__ short
// X86_64:#define __INT_FAST32_FMTd__ "d"
// X86_64:#define __INT_FAST32_FMTi__ "i"
// X86_64:#define __INT_FAST32_MAX__ 2147483647
// X86_64:#define __INT_FAST32_TYPE__ int
// X86_64:#define __INT_FAST64_FMTd__ "ld"
// X86_64:#define __INT_FAST64_FMTi__ "li"
// X86_64:#define __INT_FAST64_MAX__ 9223372036854775807L
// X86_64:#define __INT_FAST64_TYPE__ long int
// X86_64:#define __INT_FAST8_FMTd__ "hhd"
// X86_64:#define __INT_FAST8_FMTi__ "hhi"
// X86_64:#define __INT_FAST8_MAX__ 127
// X86_64:#define __INT_FAST8_TYPE__ signed char
// X86_64:#define __INT_LEAST16_FMTd__ "hd"
// X86_64:#define __INT_LEAST16_FMTi__ "hi"
// X86_64:#define __INT_LEAST16_MAX__ 32767
// X86_64:#define __INT_LEAST16_TYPE__ short
// X86_64:#define __INT_LEAST32_FMTd__ "d"
// X86_64:#define __INT_LEAST32_FMTi__ "i"
// X86_64:#define __INT_LEAST32_MAX__ 2147483647
// X86_64:#define __INT_LEAST32_TYPE__ int
// X86_64:#define __INT_LEAST64_FMTd__ "ld"
// X86_64:#define __INT_LEAST64_FMTi__ "li"
// X86_64:#define __INT_LEAST64_MAX__ 9223372036854775807L
// X86_64:#define __INT_LEAST64_TYPE__ long int
// X86_64:#define __INT_LEAST8_FMTd__ "hhd"
// X86_64:#define __INT_LEAST8_FMTi__ "hhi"
// X86_64:#define __INT_LEAST8_MAX__ 127
// X86_64:#define __INT_LEAST8_TYPE__ signed char
// X86_64:#define __INT_MAX__ 2147483647
// X86_64:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
// X86_64:#define __LDBL_DIG__ 18
// X86_64:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
// X86_64:#define __LDBL_HAS_DENORM__ 1
// X86_64:#define __LDBL_HAS_INFINITY__ 1
// X86_64:#define __LDBL_HAS_QUIET_NAN__ 1
// X86_64:#define __LDBL_MANT_DIG__ 64
// X86_64:#define __LDBL_MAX_10_EXP__ 4932
// X86_64:#define __LDBL_MAX_EXP__ 16384
// X86_64:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
// X86_64:#define __LDBL_MIN_10_EXP__ (-4931)
// X86_64:#define __LDBL_MIN_EXP__ (-16381)
// X86_64:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
// X86_64:#define __LITTLE_ENDIAN__ 1
// X86_64:#define __LONG_LONG_MAX__ 9223372036854775807LL
// X86_64:#define __LONG_MAX__ 9223372036854775807L
// X86_64:#define __LP64__ 1
// X86_64-NOT:#define __ILP32__ 1
// X86_64:#define __MMX__ 1
// X86_64:#define __NO_MATH_INLINES 1
// X86_64:#define __POINTER_WIDTH__ 64
// X86_64:#define __PTRDIFF_TYPE__ long int
// X86_64:#define __PTRDIFF_WIDTH__ 64
// X86_64:#define __REGISTER_PREFIX__
// X86_64:#define __SCHAR_MAX__ 127
// X86_64:#define __SHRT_MAX__ 32767
// X86_64:#define __SIG_ATOMIC_MAX__ 2147483647
// X86_64:#define __SIG_ATOMIC_WIDTH__ 32
// X86_64:#define __SIZEOF_DOUBLE__ 8
// X86_64:#define __SIZEOF_FLOAT__ 4
// X86_64:#define __SIZEOF_INT__ 4
// X86_64:#define __SIZEOF_LONG_DOUBLE__ 16
// X86_64:#define __SIZEOF_LONG_LONG__ 8
// X86_64:#define __SIZEOF_LONG__ 8
// X86_64:#define __SIZEOF_POINTER__ 8
// X86_64:#define __SIZEOF_PTRDIFF_T__ 8
// X86_64:#define __SIZEOF_SHORT__ 2
// X86_64:#define __SIZEOF_SIZE_T__ 8
// X86_64:#define __SIZEOF_WCHAR_T__ 4
// X86_64:#define __SIZEOF_WINT_T__ 4
// X86_64:#define __SIZE_MAX__ 18446744073709551615UL
// X86_64:#define __SIZE_TYPE__ long unsigned int
// X86_64:#define __SIZE_WIDTH__ 64
// X86_64:#define __SSE2_MATH__ 1
// X86_64:#define __SSE2__ 1
// X86_64:#define __SSE_MATH__ 1
// X86_64:#define __SSE__ 1
// X86_64-CXX:#define __STDCPP_DEFAULT_NEW_ALIGNMENT__ 16UL
// X86_64:#define __UINT16_C(c) c
// X86_64:#define __UINT16_C_SUFFIX__
// X86_64:#define __UINT16_MAX__ 65535
// X86_64:#define __UINT16_TYPE__ unsigned short
// X86_64:#define __UINT32_C(c) c##U
// X86_64:#define __UINT32_C_SUFFIX__ U
// X86_64:#define __UINT32_MAX__ 4294967295U
// X86_64:#define __UINT32_TYPE__ unsigned int
// X86_64:#define __UINT64_C(c) c##UL
// X86_64:#define __UINT64_C_SUFFIX__ UL
// X86_64:#define __UINT64_MAX__ 18446744073709551615UL
// X86_64:#define __UINT64_TYPE__ long unsigned int
// X86_64:#define __UINT8_C(c) c
// X86_64:#define __UINT8_C_SUFFIX__
// X86_64:#define __UINT8_MAX__ 255
// X86_64:#define __UINT8_TYPE__ unsigned char
// X86_64:#define __UINTMAX_C(c) c##UL
// X86_64:#define __UINTMAX_C_SUFFIX__ UL
// X86_64:#define __UINTMAX_MAX__ 18446744073709551615UL
// X86_64:#define __UINTMAX_TYPE__ long unsigned int
// X86_64:#define __UINTMAX_WIDTH__ 64
// X86_64:#define __UINTPTR_MAX__ 18446744073709551615UL
// X86_64:#define __UINTPTR_TYPE__ long unsigned int
// X86_64:#define __UINTPTR_WIDTH__ 64
// X86_64:#define __UINT_FAST16_MAX__ 65535
// X86_64:#define __UINT_FAST16_TYPE__ unsigned short
// X86_64:#define __UINT_FAST32_MAX__ 4294967295U
// X86_64:#define __UINT_FAST32_TYPE__ unsigned int
// X86_64:#define __UINT_FAST64_MAX__ 18446744073709551615UL
// X86_64:#define __UINT_FAST64_TYPE__ long unsigned int
// X86_64:#define __UINT_FAST8_MAX__ 255
// X86_64:#define __UINT_FAST8_TYPE__ unsigned char
// X86_64:#define __UINT_LEAST16_MAX__ 65535
// X86_64:#define __UINT_LEAST16_TYPE__ unsigned short
// X86_64:#define __UINT_LEAST32_MAX__ 4294967295U
// X86_64:#define __UINT_LEAST32_TYPE__ unsigned int
// X86_64:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
// X86_64:#define __UINT_LEAST64_TYPE__ long unsigned int
// X86_64:#define __UINT_LEAST8_MAX__ 255
// X86_64:#define __UINT_LEAST8_TYPE__ unsigned char
// X86_64:#define __USER_LABEL_PREFIX__
// X86_64:#define __WCHAR_MAX__ 2147483647
// X86_64:#define __WCHAR_TYPE__ int
// X86_64:#define __WCHAR_WIDTH__ 32
// X86_64:#define __WINT_TYPE__ int
// X86_64:#define __WINT_WIDTH__ 32
// X86_64:#define __amd64 1
// X86_64:#define __amd64__ 1
// X86_64:#define __code_model_small__ 1
// X86_64:#define __x86_64 1
// X86_64:#define __x86_64__ 1

// RUN: %clang_cc1 -E -dM -ffreestanding -triple=x86_64h-none-none < /dev/null | FileCheck -match-full-lines -check-prefix X86_64H %s
//
// X86_64H:#define __x86_64 1
// X86_64H:#define __x86_64__ 1
// X86_64H:#define __x86_64h 1
// X86_64H:#define __x86_64h__ 1

// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=x86_64-none-none-gnux32 < /dev/null | FileCheck -match-full-lines -check-prefix X32 %s
// RUN: %clang_cc1 -x c++ -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=x86_64-none-none-gnux32 < /dev/null | FileCheck -match-full-lines -check-prefix X32 -check-prefix X32-CXX %s
//
// X32:#define _ILP32 1
// X32-NOT:#define _LP64 1
// X32:#define __BIGGEST_ALIGNMENT__ 16
// X32:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
// X32:#define __CHAR16_TYPE__ unsigned short
// X32:#define __CHAR32_TYPE__ unsigned int
// X32:#define __CHAR_BIT__ 8
// X32:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
// X32:#define __DBL_DIG__ 15
// X32:#define __DBL_EPSILON__ 2.2204460492503131e-16
// X32:#define __DBL_HAS_DENORM__ 1
// X32:#define __DBL_HAS_INFINITY__ 1
// X32:#define __DBL_HAS_QUIET_NAN__ 1
// X32:#define __DBL_MANT_DIG__ 53
// X32:#define __DBL_MAX_10_EXP__ 308
// X32:#define __DBL_MAX_EXP__ 1024
// X32:#define __DBL_MAX__ 1.7976931348623157e+308
// X32:#define __DBL_MIN_10_EXP__ (-307)
// X32:#define __DBL_MIN_EXP__ (-1021)
// X32:#define __DBL_MIN__ 2.2250738585072014e-308
// X32:#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
// X32:#define __FLT_DENORM_MIN__ 1.40129846e-45F
// X32:#define __FLT_DIG__ 6
// X32:#define __FLT_EPSILON__ 1.19209290e-7F
// X32:#define __FLT_HAS_DENORM__ 1
// X32:#define __FLT_HAS_INFINITY__ 1
// X32:#define __FLT_HAS_QUIET_NAN__ 1
// X32:#define __FLT_MANT_DIG__ 24
// X32:#define __FLT_MAX_10_EXP__ 38
// X32:#define __FLT_MAX_EXP__ 128
// X32:#define __FLT_MAX__ 3.40282347e+38F
// X32:#define __FLT_MIN_10_EXP__ (-37)
// X32:#define __FLT_MIN_EXP__ (-125)
// X32:#define __FLT_MIN__ 1.17549435e-38F
// X32:#define __FLT_RADIX__ 2
// X32:#define __ILP32__ 1
// X32-NOT:#define __LP64__ 1
// X32:#define __INT16_C(c) c
// X32:#define __INT16_C_SUFFIX__
// X32:#define __INT16_FMTd__ "hd"
// X32:#define __INT16_FMTi__ "hi"
// X32:#define __INT16_MAX__ 32767
// X32:#define __INT16_TYPE__ short
// X32:#define __INT32_C(c) c
// X32:#define __INT32_C_SUFFIX__
// X32:#define __INT32_FMTd__ "d"
// X32:#define __INT32_FMTi__ "i"
// X32:#define __INT32_MAX__ 2147483647
// X32:#define __INT32_TYPE__ int
// X32:#define __INT64_C(c) c##LL
// X32:#define __INT64_C_SUFFIX__ LL
// X32:#define __INT64_FMTd__ "lld"
// X32:#define __INT64_FMTi__ "lli"
// X32:#define __INT64_MAX__ 9223372036854775807LL
// X32:#define __INT64_TYPE__ long long int
// X32:#define __INT8_C(c) c
// X32:#define __INT8_C_SUFFIX__
// X32:#define __INT8_FMTd__ "hhd"
// X32:#define __INT8_FMTi__ "hhi"
// X32:#define __INT8_MAX__ 127
// X32:#define __INT8_TYPE__ signed char
// X32:#define __INTMAX_C(c) c##LL
// X32:#define __INTMAX_C_SUFFIX__ LL
// X32:#define __INTMAX_FMTd__ "lld"
// X32:#define __INTMAX_FMTi__ "lli"
// X32:#define __INTMAX_MAX__ 9223372036854775807LL
// X32:#define __INTMAX_TYPE__ long long int
// X32:#define __INTMAX_WIDTH__ 64
// X32:#define __INTPTR_FMTd__ "d"
// X32:#define __INTPTR_FMTi__ "i"
// X32:#define __INTPTR_MAX__ 2147483647
// X32:#define __INTPTR_TYPE__ int
// X32:#define __INTPTR_WIDTH__ 32
// X32:#define __INT_FAST16_FMTd__ "hd"
// X32:#define __INT_FAST16_FMTi__ "hi"
// X32:#define __INT_FAST16_MAX__ 32767
// X32:#define __INT_FAST16_TYPE__ short
// X32:#define __INT_FAST32_FMTd__ "d"
// X32:#define __INT_FAST32_FMTi__ "i"
// X32:#define __INT_FAST32_MAX__ 2147483647
// X32:#define __INT_FAST32_TYPE__ int
// X32:#define __INT_FAST64_FMTd__ "lld"
// X32:#define __INT_FAST64_FMTi__ "lli"
// X32:#define __INT_FAST64_MAX__ 9223372036854775807LL
// X32:#define __INT_FAST64_TYPE__ long long int
// X32:#define __INT_FAST8_FMTd__ "hhd"
// X32:#define __INT_FAST8_FMTi__ "hhi"
// X32:#define __INT_FAST8_MAX__ 127
// X32:#define __INT_FAST8_TYPE__ signed char
// X32:#define __INT_LEAST16_FMTd__ "hd"
// X32:#define __INT_LEAST16_FMTi__ "hi"
// X32:#define __INT_LEAST16_MAX__ 32767
// X32:#define __INT_LEAST16_TYPE__ short
// X32:#define __INT_LEAST32_FMTd__ "d"
// X32:#define __INT_LEAST32_FMTi__ "i"
// X32:#define __INT_LEAST32_MAX__ 2147483647
// X32:#define __INT_LEAST32_TYPE__ int
// X32:#define __INT_LEAST64_FMTd__ "lld"
// X32:#define __INT_LEAST64_FMTi__ "lli"
// X32:#define __INT_LEAST64_MAX__ 9223372036854775807LL
// X32:#define __INT_LEAST64_TYPE__ long long int
// X32:#define __INT_LEAST8_FMTd__ "hhd"
// X32:#define __INT_LEAST8_FMTi__ "hhi"
// X32:#define __INT_LEAST8_MAX__ 127
// X32:#define __INT_LEAST8_TYPE__ signed char
// X32:#define __INT_MAX__ 2147483647
// X32:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
// X32:#define __LDBL_DIG__ 18
// X32:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
// X32:#define __LDBL_HAS_DENORM__ 1
// X32:#define __LDBL_HAS_INFINITY__ 1
// X32:#define __LDBL_HAS_QUIET_NAN__ 1
// X32:#define __LDBL_MANT_DIG__ 64
// X32:#define __LDBL_MAX_10_EXP__ 4932
// X32:#define __LDBL_MAX_EXP__ 16384
// X32:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
// X32:#define __LDBL_MIN_10_EXP__ (-4931)
// X32:#define __LDBL_MIN_EXP__ (-16381)
// X32:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
// X32:#define __LITTLE_ENDIAN__ 1
// X32:#define __LONG_LONG_MAX__ 9223372036854775807LL
// X32:#define __LONG_MAX__ 2147483647L
// X32:#define __MMX__ 1
// X32:#define __NO_MATH_INLINES 1
// X32:#define __POINTER_WIDTH__ 32
// X32:#define __PTRDIFF_TYPE__ int
// X32:#define __PTRDIFF_WIDTH__ 32
// X32:#define __REGISTER_PREFIX__
// X32:#define __SCHAR_MAX__ 127
// X32:#define __SHRT_MAX__ 32767
// X32:#define __SIG_ATOMIC_MAX__ 2147483647
// X32:#define __SIG_ATOMIC_WIDTH__ 32
// X32:#define __SIZEOF_DOUBLE__ 8
// X32:#define __SIZEOF_FLOAT__ 4
// X32:#define __SIZEOF_INT__ 4
// X32:#define __SIZEOF_LONG_DOUBLE__ 16
// X32:#define __SIZEOF_LONG_LONG__ 8
// X32:#define __SIZEOF_LONG__ 4
// X32:#define __SIZEOF_POINTER__ 4
// X32:#define __SIZEOF_PTRDIFF_T__ 4
// X32:#define __SIZEOF_SHORT__ 2
// X32:#define __SIZEOF_SIZE_T__ 4
// X32:#define __SIZEOF_WCHAR_T__ 4
// X32:#define __SIZEOF_WINT_T__ 4
// X32:#define __SIZE_MAX__ 4294967295U
// X32:#define __SIZE_TYPE__ unsigned int
// X32:#define __SIZE_WIDTH__ 32
// X32:#define __SSE2_MATH__ 1
// X32:#define __SSE2__ 1
// X32:#define __SSE_MATH__ 1
// X32:#define __SSE__ 1
// X32-CXX:#define __STDCPP_DEFAULT_NEW_ALIGNMENT__ 16U
// X32:#define __UINT16_C(c) c
// X32:#define __UINT16_C_SUFFIX__
// X32:#define __UINT16_MAX__ 65535
// X32:#define __UINT16_TYPE__ unsigned short
// X32:#define __UINT32_C(c) c##U
// X32:#define __UINT32_C_SUFFIX__ U
// X32:#define __UINT32_MAX__ 4294967295U
// X32:#define __UINT32_TYPE__ unsigned int
// X32:#define __UINT64_C(c) c##ULL
// X32:#define __UINT64_C_SUFFIX__ ULL
// X32:#define __UINT64_MAX__ 18446744073709551615ULL
// X32:#define __UINT64_TYPE__ long long unsigned int
// X32:#define __UINT8_C(c) c
// X32:#define __UINT8_C_SUFFIX__
// X32:#define __UINT8_MAX__ 255
// X32:#define __UINT8_TYPE__ unsigned char
// X32:#define __UINTMAX_C(c) c##ULL
// X32:#define __UINTMAX_C_SUFFIX__ ULL
// X32:#define __UINTMAX_MAX__ 18446744073709551615ULL
// X32:#define __UINTMAX_TYPE__ long long unsigned int
// X32:#define __UINTMAX_WIDTH__ 64
// X32:#define __UINTPTR_MAX__ 4294967295U
// X32:#define __UINTPTR_TYPE__ unsigned int
// X32:#define __UINTPTR_WIDTH__ 32
// X32:#define __UINT_FAST16_MAX__ 65535
// X32:#define __UINT_FAST16_TYPE__ unsigned short
// X32:#define __UINT_FAST32_MAX__ 4294967295U
// X32:#define __UINT_FAST32_TYPE__ unsigned int
// X32:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
// X32:#define __UINT_FAST64_TYPE__ long long unsigned int
// X32:#define __UINT_FAST8_MAX__ 255
// X32:#define __UINT_FAST8_TYPE__ unsigned char
// X32:#define __UINT_LEAST16_MAX__ 65535
// X32:#define __UINT_LEAST16_TYPE__ unsigned short
// X32:#define __UINT_LEAST32_MAX__ 4294967295U
// X32:#define __UINT_LEAST32_TYPE__ unsigned int
// X32:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
// X32:#define __UINT_LEAST64_TYPE__ long long unsigned int
// X32:#define __UINT_LEAST8_MAX__ 255
// X32:#define __UINT_LEAST8_TYPE__ unsigned char
// X32:#define __USER_LABEL_PREFIX__
// X32:#define __WCHAR_MAX__ 2147483647
// X32:#define __WCHAR_TYPE__ int
// X32:#define __WCHAR_WIDTH__ 32
// X32:#define __WINT_TYPE__ int
// X32:#define __WINT_WIDTH__ 32
// X32:#define __amd64 1
// X32:#define __amd64__ 1
// X32:#define __x86_64 1
// X32:#define __x86_64__ 1

// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=x86_64-pc-linux-gnu < /dev/null | FileCheck -match-full-lines -check-prefix X86_64-LINUX %s
// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=x86_64-unknown-fuchsia < /dev/null | FileCheck -match-full-lines -check-prefix X86_64-LINUX %s
//
// X86_64-LINUX:#define _LP64 1
// X86_64-LINUX:#define __BIGGEST_ALIGNMENT__ 16
// X86_64-LINUX:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
// X86_64-LINUX:#define __CHAR16_TYPE__ unsigned short
// X86_64-LINUX:#define __CHAR32_TYPE__ unsigned int
// X86_64-LINUX:#define __CHAR_BIT__ 8
// X86_64-LINUX:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
// X86_64-LINUX:#define __DBL_DIG__ 15
// X86_64-LINUX:#define __DBL_EPSILON__ 2.2204460492503131e-16
// X86_64-LINUX:#define __DBL_HAS_DENORM__ 1
// X86_64-LINUX:#define __DBL_HAS_INFINITY__ 1
// X86_64-LINUX:#define __DBL_HAS_QUIET_NAN__ 1
// X86_64-LINUX:#define __DBL_MANT_DIG__ 53
// X86_64-LINUX:#define __DBL_MAX_10_EXP__ 308
// X86_64-LINUX:#define __DBL_MAX_EXP__ 1024
// X86_64-LINUX:#define __DBL_MAX__ 1.7976931348623157e+308
// X86_64-LINUX:#define __DBL_MIN_10_EXP__ (-307)
// X86_64-LINUX:#define __DBL_MIN_EXP__ (-1021)
// X86_64-LINUX:#define __DBL_MIN__ 2.2250738585072014e-308
// X86_64-LINUX:#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
// X86_64-LINUX:#define __FLT_DENORM_MIN__ 1.40129846e-45F
// X86_64-LINUX:#define __FLT_DIG__ 6
// X86_64-LINUX:#define __FLT_EPSILON__ 1.19209290e-7F
// X86_64-LINUX:#define __FLT_HAS_DENORM__ 1
// X86_64-LINUX:#define __FLT_HAS_INFINITY__ 1
// X86_64-LINUX:#define __FLT_HAS_QUIET_NAN__ 1
// X86_64-LINUX:#define __FLT_MANT_DIG__ 24
// X86_64-LINUX:#define __FLT_MAX_10_EXP__ 38
// X86_64-LINUX:#define __FLT_MAX_EXP__ 128
// X86_64-LINUX:#define __FLT_MAX__ 3.40282347e+38F
// X86_64-LINUX:#define __FLT_MIN_10_EXP__ (-37)
// X86_64-LINUX:#define __FLT_MIN_EXP__ (-125)
// X86_64-LINUX:#define __FLT_MIN__ 1.17549435e-38F
// X86_64-LINUX:#define __FLT_RADIX__ 2
// X86_64-LINUX:#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
// X86_64-LINUX:#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
// X86_64-LINUX:#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
// X86_64-LINUX:#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
// X86_64-LINUX:#define __GCC_ATOMIC_INT_LOCK_FREE 2
// X86_64-LINUX:#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
// X86_64-LINUX:#define __GCC_ATOMIC_LONG_LOCK_FREE 2
// X86_64-LINUX:#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
// X86_64-LINUX:#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
// X86_64-LINUX:#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
// X86_64-LINUX:#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
// X86_64-LINUX:#define __INT16_C(c) c
// X86_64-LINUX:#define __INT16_C_SUFFIX__
// X86_64-LINUX:#define __INT16_FMTd__ "hd"
// X86_64-LINUX:#define __INT16_FMTi__ "hi"
// X86_64-LINUX:#define __INT16_MAX__ 32767
// X86_64-LINUX:#define __INT16_TYPE__ short
// X86_64-LINUX:#define __INT32_C(c) c
// X86_64-LINUX:#define __INT32_C_SUFFIX__
// X86_64-LINUX:#define __INT32_FMTd__ "d"
// X86_64-LINUX:#define __INT32_FMTi__ "i"
// X86_64-LINUX:#define __INT32_MAX__ 2147483647
// X86_64-LINUX:#define __INT32_TYPE__ int
// X86_64-LINUX:#define __INT64_C(c) c##L
// X86_64-LINUX:#define __INT64_C_SUFFIX__ L
// X86_64-LINUX:#define __INT64_FMTd__ "ld"
// X86_64-LINUX:#define __INT64_FMTi__ "li"
// X86_64-LINUX:#define __INT64_MAX__ 9223372036854775807L
// X86_64-LINUX:#define __INT64_TYPE__ long int
// X86_64-LINUX:#define __INT8_C(c) c
// X86_64-LINUX:#define __INT8_C_SUFFIX__
// X86_64-LINUX:#define __INT8_FMTd__ "hhd"
// X86_64-LINUX:#define __INT8_FMTi__ "hhi"
// X86_64-LINUX:#define __INT8_MAX__ 127
// X86_64-LINUX:#define __INT8_TYPE__ signed char
// X86_64-LINUX:#define __INTMAX_C(c) c##L
// X86_64-LINUX:#define __INTMAX_C_SUFFIX__ L
// X86_64-LINUX:#define __INTMAX_FMTd__ "ld"
// X86_64-LINUX:#define __INTMAX_FMTi__ "li"
// X86_64-LINUX:#define __INTMAX_MAX__ 9223372036854775807L
// X86_64-LINUX:#define __INTMAX_TYPE__ long int
// X86_64-LINUX:#define __INTMAX_WIDTH__ 64
// X86_64-LINUX:#define __INTPTR_FMTd__ "ld"
// X86_64-LINUX:#define __INTPTR_FMTi__ "li"
// X86_64-LINUX:#define __INTPTR_MAX__ 9223372036854775807L
// X86_64-LINUX:#define __INTPTR_TYPE__ long int
// X86_64-LINUX:#define __INTPTR_WIDTH__ 64
// X86_64-LINUX:#define __INT_FAST16_FMTd__ "hd"
// X86_64-LINUX:#define __INT_FAST16_FMTi__ "hi"
// X86_64-LINUX:#define __INT_FAST16_MAX__ 32767
// X86_64-LINUX:#define __INT_FAST16_TYPE__ short
// X86_64-LINUX:#define __INT_FAST32_FMTd__ "d"
// X86_64-LINUX:#define __INT_FAST32_FMTi__ "i"
// X86_64-LINUX:#define __INT_FAST32_MAX__ 2147483647
// X86_64-LINUX:#define __INT_FAST32_TYPE__ int
// X86_64-LINUX:#define __INT_FAST64_FMTd__ "ld"
// X86_64-LINUX:#define __INT_FAST64_FMTi__ "li"
// X86_64-LINUX:#define __INT_FAST64_MAX__ 9223372036854775807L
// X86_64-LINUX:#define __INT_FAST64_TYPE__ long int
// X86_64-LINUX:#define __INT_FAST8_FMTd__ "hhd"
// X86_64-LINUX:#define __INT_FAST8_FMTi__ "hhi"
// X86_64-LINUX:#define __INT_FAST8_MAX__ 127
// X86_64-LINUX:#define __INT_FAST8_TYPE__ signed char
// X86_64-LINUX:#define __INT_LEAST16_FMTd__ "hd"
// X86_64-LINUX:#define __INT_LEAST16_FMTi__ "hi"
// X86_64-LINUX:#define __INT_LEAST16_MAX__ 32767
// X86_64-LINUX:#define __INT_LEAST16_TYPE__ short
// X86_64-LINUX:#define __INT_LEAST32_FMTd__ "d"
// X86_64-LINUX:#define __INT_LEAST32_FMTi__ "i"
// X86_64-LINUX:#define __INT_LEAST32_MAX__ 2147483647
// X86_64-LINUX:#define __INT_LEAST32_TYPE__ int
// X86_64-LINUX:#define __INT_LEAST64_FMTd__ "ld"
// X86_64-LINUX:#define __INT_LEAST64_FMTi__ "li"
// X86_64-LINUX:#define __INT_LEAST64_MAX__ 9223372036854775807L
// X86_64-LINUX:#define __INT_LEAST64_TYPE__ long int
// X86_64-LINUX:#define __INT_LEAST8_FMTd__ "hhd"
// X86_64-LINUX:#define __INT_LEAST8_FMTi__ "hhi"
// X86_64-LINUX:#define __INT_LEAST8_MAX__ 127
// X86_64-LINUX:#define __INT_LEAST8_TYPE__ signed char
// X86_64-LINUX:#define __INT_MAX__ 2147483647
// X86_64-LINUX:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
// X86_64-LINUX:#define __LDBL_DIG__ 18
// X86_64-LINUX:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
// X86_64-LINUX:#define __LDBL_HAS_DENORM__ 1
// X86_64-LINUX:#define __LDBL_HAS_INFINITY__ 1
// X86_64-LINUX:#define __LDBL_HAS_QUIET_NAN__ 1
// X86_64-LINUX:#define __LDBL_MANT_DIG__ 64
// X86_64-LINUX:#define __LDBL_MAX_10_EXP__ 4932
// X86_64-LINUX:#define __LDBL_MAX_EXP__ 16384
// X86_64-LINUX:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
// X86_64-LINUX:#define __LDBL_MIN_10_EXP__ (-4931)
// X86_64-LINUX:#define __LDBL_MIN_EXP__ (-16381)
// X86_64-LINUX:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
// X86_64-LINUX:#define __LITTLE_ENDIAN__ 1
// X86_64-LINUX:#define __LONG_LONG_MAX__ 9223372036854775807LL
// X86_64-LINUX:#define __LONG_MAX__ 9223372036854775807L
// X86_64-LINUX:#define __LP64__ 1
// X86_64-LINUX:#define __MMX__ 1
// X86_64-LINUX:#define __NO_MATH_INLINES 1
// X86_64-LINUX:#define __POINTER_WIDTH__ 64
// X86_64-LINUX:#define __PTRDIFF_TYPE__ long int
// X86_64-LINUX:#define __PTRDIFF_WIDTH__ 64
// X86_64-LINUX:#define __REGISTER_PREFIX__
// X86_64-LINUX:#define __SCHAR_MAX__ 127
// X86_64-LINUX:#define __SHRT_MAX__ 32767
// X86_64-LINUX:#define __SIG_ATOMIC_MAX__ 2147483647
// X86_64-LINUX:#define __SIG_ATOMIC_WIDTH__ 32
// X86_64-LINUX:#define __SIZEOF_DOUBLE__ 8
// X86_64-LINUX:#define __SIZEOF_FLOAT__ 4
// X86_64-LINUX:#define __SIZEOF_INT__ 4
// X86_64-LINUX:#define __SIZEOF_LONG_DOUBLE__ 16
// X86_64-LINUX:#define __SIZEOF_LONG_LONG__ 8
// X86_64-LINUX:#define __SIZEOF_LONG__ 8
// X86_64-LINUX:#define __SIZEOF_POINTER__ 8
// X86_64-LINUX:#define __SIZEOF_PTRDIFF_T__ 8
// X86_64-LINUX:#define __SIZEOF_SHORT__ 2
// X86_64-LINUX:#define __SIZEOF_SIZE_T__ 8
// X86_64-LINUX:#define __SIZEOF_WCHAR_T__ 4
// X86_64-LINUX:#define __SIZEOF_WINT_T__ 4
// X86_64-LINUX:#define __SIZE_MAX__ 18446744073709551615UL
// X86_64-LINUX:#define __SIZE_TYPE__ long unsigned int
// X86_64-LINUX:#define __SIZE_WIDTH__ 64
// X86_64-LINUX:#define __SSE2_MATH__ 1
// X86_64-LINUX:#define __SSE2__ 1
// X86_64-LINUX:#define __SSE_MATH__ 1
// X86_64-LINUX:#define __SSE__ 1
// X86_64-LINUX:#define __UINT16_C(c) c
// X86_64-LINUX:#define __UINT16_C_SUFFIX__
// X86_64-LINUX:#define __UINT16_MAX__ 65535
// X86_64-LINUX:#define __UINT16_TYPE__ unsigned short
// X86_64-LINUX:#define __UINT32_C(c) c##U
// X86_64-LINUX:#define __UINT32_C_SUFFIX__ U
// X86_64-LINUX:#define __UINT32_MAX__ 4294967295U
// X86_64-LINUX:#define __UINT32_TYPE__ unsigned int
// X86_64-LINUX:#define __UINT64_C(c) c##UL
// X86_64-LINUX:#define __UINT64_C_SUFFIX__ UL
// X86_64-LINUX:#define __UINT64_MAX__ 18446744073709551615UL
// X86_64-LINUX:#define __UINT64_TYPE__ long unsigned int
// X86_64-LINUX:#define __UINT8_C(c) c
// X86_64-LINUX:#define __UINT8_C_SUFFIX__
// X86_64-LINUX:#define __UINT8_MAX__ 255
// X86_64-LINUX:#define __UINT8_TYPE__ unsigned char
// X86_64-LINUX:#define __UINTMAX_C(c) c##UL
// X86_64-LINUX:#define __UINTMAX_C_SUFFIX__ UL
// X86_64-LINUX:#define __UINTMAX_MAX__ 18446744073709551615UL
// X86_64-LINUX:#define __UINTMAX_TYPE__ long unsigned int
// X86_64-LINUX:#define __UINTMAX_WIDTH__ 64
// X86_64-LINUX:#define __UINTPTR_MAX__ 18446744073709551615UL
// X86_64-LINUX:#define __UINTPTR_TYPE__ long unsigned int
// X86_64-LINUX:#define __UINTPTR_WIDTH__ 64
// X86_64-LINUX:#define __UINT_FAST16_MAX__ 65535
// X86_64-LINUX:#define __UINT_FAST16_TYPE__ unsigned short
// X86_64-LINUX:#define __UINT_FAST32_MAX__ 4294967295U
// X86_64-LINUX:#define __UINT_FAST32_TYPE__ unsigned int
// X86_64-LINUX:#define __UINT_FAST64_MAX__ 18446744073709551615UL
// X86_64-LINUX:#define __UINT_FAST64_TYPE__ long unsigned int
// X86_64-LINUX:#define __UINT_FAST8_MAX__ 255
// X86_64-LINUX:#define __UINT_FAST8_TYPE__ unsigned char
// X86_64-LINUX:#define __UINT_LEAST16_MAX__ 65535
// X86_64-LINUX:#define __UINT_LEAST16_TYPE__ unsigned short
// X86_64-LINUX:#define __UINT_LEAST32_MAX__ 4294967295U
// X86_64-LINUX:#define __UINT_LEAST32_TYPE__ unsigned int
// X86_64-LINUX:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
// X86_64-LINUX:#define __UINT_LEAST64_TYPE__ long unsigned int
// X86_64-LINUX:#define __UINT_LEAST8_MAX__ 255
// X86_64-LINUX:#define __UINT_LEAST8_TYPE__ unsigned char
// X86_64-LINUX:#define __USER_LABEL_PREFIX__
// X86_64-LINUX:#define __WCHAR_MAX__ 2147483647
// X86_64-LINUX:#define __WCHAR_TYPE__ int
// X86_64-LINUX:#define __WCHAR_WIDTH__ 32
// X86_64-LINUX:#define __WINT_TYPE__ unsigned int
// X86_64-LINUX:#define __WINT_WIDTH__ 32
// X86_64-LINUX:#define __amd64 1
// X86_64-LINUX:#define __amd64__ 1
// X86_64-LINUX:#define __x86_64 1
// X86_64-LINUX:#define __x86_64__ 1

// RUN: %clang_cc1 -E -dM -ffreestanding -triple=x86_64-unknown-freebsd9.1 < /dev/null | FileCheck -match-full-lines -check-prefix X86_64-FREEBSD %s
//
// X86_64-FREEBSD:#define __DBL_DECIMAL_DIG__ 17
// X86_64-FREEBSD:#define __FLT_DECIMAL_DIG__ 9
// X86_64-FREEBSD:#define __FreeBSD__ 9
// X86_64-FREEBSD:#define __FreeBSD_cc_version 900001
// X86_64-FREEBSD:#define __LDBL_DECIMAL_DIG__ 21
// X86_64-FREEBSD:#define __STDC_MB_MIGHT_NEQ_WC__ 1

// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=x86_64-netbsd < /dev/null | FileCheck -match-full-lines -check-prefix X86_64-NETBSD %s
//
// X86_64-NETBSD:#define _LP64 1
// X86_64-NETBSD:#define __BIGGEST_ALIGNMENT__ 16
// X86_64-NETBSD:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
// X86_64-NETBSD:#define __CHAR16_TYPE__ unsigned short
// X86_64-NETBSD:#define __CHAR32_TYPE__ unsigned int
// X86_64-NETBSD:#define __CHAR_BIT__ 8
// X86_64-NETBSD:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
// X86_64-NETBSD:#define __DBL_DIG__ 15
// X86_64-NETBSD:#define __DBL_EPSILON__ 2.2204460492503131e-16
// X86_64-NETBSD:#define __DBL_HAS_DENORM__ 1
// X86_64-NETBSD:#define __DBL_HAS_INFINITY__ 1
// X86_64-NETBSD:#define __DBL_HAS_QUIET_NAN__ 1
// X86_64-NETBSD:#define __DBL_MANT_DIG__ 53
// X86_64-NETBSD:#define __DBL_MAX_10_EXP__ 308
// X86_64-NETBSD:#define __DBL_MAX_EXP__ 1024
// X86_64-NETBSD:#define __DBL_MAX__ 1.7976931348623157e+308
// X86_64-NETBSD:#define __DBL_MIN_10_EXP__ (-307)
// X86_64-NETBSD:#define __DBL_MIN_EXP__ (-1021)
// X86_64-NETBSD:#define __DBL_MIN__ 2.2250738585072014e-308
// X86_64-NETBSD:#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
// X86_64-NETBSD:#define __FLT_DENORM_MIN__ 1.40129846e-45F
// X86_64-NETBSD:#define __FLT_DIG__ 6
// X86_64-NETBSD:#define __FLT_EPSILON__ 1.19209290e-7F
// X86_64-NETBSD:#define __FLT_HAS_DENORM__ 1
// X86_64-NETBSD:#define __FLT_HAS_INFINITY__ 1
// X86_64-NETBSD:#define __FLT_HAS_QUIET_NAN__ 1
// X86_64-NETBSD:#define __FLT_MANT_DIG__ 24
// X86_64-NETBSD:#define __FLT_MAX_10_EXP__ 38
// X86_64-NETBSD:#define __FLT_MAX_EXP__ 128
// X86_64-NETBSD:#define __FLT_MAX__ 3.40282347e+38F
// X86_64-NETBSD:#define __FLT_MIN_10_EXP__ (-37)
// X86_64-NETBSD:#define __FLT_MIN_EXP__ (-125)
// X86_64-NETBSD:#define __FLT_MIN__ 1.17549435e-38F
// X86_64-NETBSD:#define __FLT_RADIX__ 2
// X86_64-NETBSD:#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
// X86_64-NETBSD:#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
// X86_64-NETBSD:#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
// X86_64-NETBSD:#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
// X86_64-NETBSD:#define __GCC_ATOMIC_INT_LOCK_FREE 2
// X86_64-NETBSD:#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
// X86_64-NETBSD:#define __GCC_ATOMIC_LONG_LOCK_FREE 2
// X86_64-NETBSD:#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
// X86_64-NETBSD:#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
// X86_64-NETBSD:#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
// X86_64-NETBSD:#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
// X86_64-NETBSD:#define __INT16_C(c) c
// X86_64-NETBSD:#define __INT16_C_SUFFIX__
// X86_64-NETBSD:#define __INT16_FMTd__ "hd"
// X86_64-NETBSD:#define __INT16_FMTi__ "hi"
// X86_64-NETBSD:#define __INT16_MAX__ 32767
// X86_64-NETBSD:#define __INT16_TYPE__ short
// X86_64-NETBSD:#define __INT32_C(c) c
// X86_64-NETBSD:#define __INT32_C_SUFFIX__
// X86_64-NETBSD:#define __INT32_FMTd__ "d"
// X86_64-NETBSD:#define __INT32_FMTi__ "i"
// X86_64-NETBSD:#define __INT32_MAX__ 2147483647
// X86_64-NETBSD:#define __INT32_TYPE__ int
// X86_64-NETBSD:#define __INT64_C(c) c##L
// X86_64-NETBSD:#define __INT64_C_SUFFIX__ L
// X86_64-NETBSD:#define __INT64_FMTd__ "ld"
// X86_64-NETBSD:#define __INT64_FMTi__ "li"
// X86_64-NETBSD:#define __INT64_MAX__ 9223372036854775807L
// X86_64-NETBSD:#define __INT64_TYPE__ long int
// X86_64-NETBSD:#define __INT8_C(c) c
// X86_64-NETBSD:#define __INT8_C_SUFFIX__
// X86_64-NETBSD:#define __INT8_FMTd__ "hhd"
// X86_64-NETBSD:#define __INT8_FMTi__ "hhi"
// X86_64-NETBSD:#define __INT8_MAX__ 127
// X86_64-NETBSD:#define __INT8_TYPE__ signed char
// X86_64-NETBSD:#define __INTMAX_C(c) c##L
// X86_64-NETBSD:#define __INTMAX_C_SUFFIX__ L
// X86_64-NETBSD:#define __INTMAX_FMTd__ "ld"
// X86_64-NETBSD:#define __INTMAX_FMTi__ "li"
// X86_64-NETBSD:#define __INTMAX_MAX__ 9223372036854775807L
// X86_64-NETBSD:#define __INTMAX_TYPE__ long int
// X86_64-NETBSD:#define __INTMAX_WIDTH__ 64
// X86_64-NETBSD:#define __INTPTR_FMTd__ "ld"
// X86_64-NETBSD:#define __INTPTR_FMTi__ "li"
// X86_64-NETBSD:#define __INTPTR_MAX__ 9223372036854775807L
// X86_64-NETBSD:#define __INTPTR_TYPE__ long int
// X86_64-NETBSD:#define __INTPTR_WIDTH__ 64
// X86_64-NETBSD:#define __INT_FAST16_FMTd__ "hd"
// X86_64-NETBSD:#define __INT_FAST16_FMTi__ "hi"
// X86_64-NETBSD:#define __INT_FAST16_MAX__ 32767
// X86_64-NETBSD:#define __INT_FAST16_TYPE__ short
// X86_64-NETBSD:#define __INT_FAST32_FMTd__ "d"
// X86_64-NETBSD:#define __INT_FAST32_FMTi__ "i"
// X86_64-NETBSD:#define __INT_FAST32_MAX__ 2147483647
// X86_64-NETBSD:#define __INT_FAST32_TYPE__ int
// X86_64-NETBSD:#define __INT_FAST64_FMTd__ "ld"
// X86_64-NETBSD:#define __INT_FAST64_FMTi__ "li"
// X86_64-NETBSD:#define __INT_FAST64_MAX__ 9223372036854775807L
// X86_64-NETBSD:#define __INT_FAST64_TYPE__ long int
// X86_64-NETBSD:#define __INT_FAST8_FMTd__ "hhd"
// X86_64-NETBSD:#define __INT_FAST8_FMTi__ "hhi"
// X86_64-NETBSD:#define __INT_FAST8_MAX__ 127
// X86_64-NETBSD:#define __INT_FAST8_TYPE__ signed char
// X86_64-NETBSD:#define __INT_LEAST16_FMTd__ "hd"
// X86_64-NETBSD:#define __INT_LEAST16_FMTi__ "hi"
// X86_64-NETBSD:#define __INT_LEAST16_MAX__ 32767
// X86_64-NETBSD:#define __INT_LEAST16_TYPE__ short
// X86_64-NETBSD:#define __INT_LEAST32_FMTd__ "d"
// X86_64-NETBSD:#define __INT_LEAST32_FMTi__ "i"
// X86_64-NETBSD:#define __INT_LEAST32_MAX__ 2147483647
// X86_64-NETBSD:#define __INT_LEAST32_TYPE__ int
// X86_64-NETBSD:#define __INT_LEAST64_FMTd__ "ld"
// X86_64-NETBSD:#define __INT_LEAST64_FMTi__ "li"
// X86_64-NETBSD:#define __INT_LEAST64_MAX__ 9223372036854775807L
// X86_64-NETBSD:#define __INT_LEAST64_TYPE__ long int
// X86_64-NETBSD:#define __INT_LEAST8_FMTd__ "hhd"
// X86_64-NETBSD:#define __INT_LEAST8_FMTi__ "hhi"
// X86_64-NETBSD:#define __INT_LEAST8_MAX__ 127
// X86_64-NETBSD:#define __INT_LEAST8_TYPE__ signed char
// X86_64-NETBSD:#define __INT_MAX__ 2147483647
// X86_64-NETBSD:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
// X86_64-NETBSD:#define __LDBL_DIG__ 18
// X86_64-NETBSD:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
// X86_64-NETBSD:#define __LDBL_HAS_DENORM__ 1
// X86_64-NETBSD:#define __LDBL_HAS_INFINITY__ 1
// X86_64-NETBSD:#define __LDBL_HAS_QUIET_NAN__ 1
// X86_64-NETBSD:#define __LDBL_MANT_DIG__ 64
// X86_64-NETBSD:#define __LDBL_MAX_10_EXP__ 4932
// X86_64-NETBSD:#define __LDBL_MAX_EXP__ 16384
// X86_64-NETBSD:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
// X86_64-NETBSD:#define __LDBL_MIN_10_EXP__ (-4931)
// X86_64-NETBSD:#define __LDBL_MIN_EXP__ (-16381)
// X86_64-NETBSD:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
// X86_64-NETBSD:#define __LITTLE_ENDIAN__ 1
// X86_64-NETBSD:#define __LONG_LONG_MAX__ 9223372036854775807LL
// X86_64-NETBSD:#define __LONG_MAX__ 9223372036854775807L
// X86_64-NETBSD:#define __LP64__ 1
// X86_64-NETBSD:#define __MMX__ 1
// X86_64-NETBSD:#define __NO_MATH_INLINES 1
// X86_64-NETBSD:#define __POINTER_WIDTH__ 64
// X86_64-NETBSD:#define __PTRDIFF_TYPE__ long int
// X86_64-NETBSD:#define __PTRDIFF_WIDTH__ 64
// X86_64-NETBSD:#define __REGISTER_PREFIX__
// X86_64-NETBSD:#define __SCHAR_MAX__ 127
// X86_64-NETBSD:#define __SHRT_MAX__ 32767
// X86_64-NETBSD:#define __SIG_ATOMIC_MAX__ 2147483647
// X86_64-NETBSD:#define __SIG_ATOMIC_WIDTH__ 32
// X86_64-NETBSD:#define __SIZEOF_DOUBLE__ 8
// X86_64-NETBSD:#define __SIZEOF_FLOAT__ 4
// X86_64-NETBSD:#define __SIZEOF_INT__ 4
// X86_64-NETBSD:#define __SIZEOF_LONG_DOUBLE__ 16
// X86_64-NETBSD:#define __SIZEOF_LONG_LONG__ 8
// X86_64-NETBSD:#define __SIZEOF_LONG__ 8
// X86_64-NETBSD:#define __SIZEOF_POINTER__ 8
// X86_64-NETBSD:#define __SIZEOF_PTRDIFF_T__ 8
// X86_64-NETBSD:#define __SIZEOF_SHORT__ 2
// X86_64-NETBSD:#define __SIZEOF_SIZE_T__ 8
// X86_64-NETBSD:#define __SIZEOF_WCHAR_T__ 4
// X86_64-NETBSD:#define __SIZEOF_WINT_T__ 4
// X86_64-NETBSD:#define __SIZE_MAX__ 18446744073709551615UL
// X86_64-NETBSD:#define __SIZE_TYPE__ long unsigned int
// X86_64-NETBSD:#define __SIZE_WIDTH__ 64
// X86_64-NETBSD:#define __SSE2_MATH__ 1
// X86_64-NETBSD:#define __SSE2__ 1
// X86_64-NETBSD:#define __SSE_MATH__ 1
// X86_64-NETBSD:#define __SSE__ 1
// X86_64-NETBSD:#define __UINT16_C(c) c
// X86_64-NETBSD:#define __UINT16_C_SUFFIX__
// X86_64-NETBSD:#define __UINT16_MAX__ 65535
// X86_64-NETBSD:#define __UINT16_TYPE__ unsigned short
// X86_64-NETBSD:#define __UINT32_C(c) c##U
// X86_64-NETBSD:#define __UINT32_C_SUFFIX__ U
// X86_64-NETBSD:#define __UINT32_MAX__ 4294967295U
// X86_64-NETBSD:#define __UINT32_TYPE__ unsigned int
// X86_64-NETBSD:#define __UINT64_C(c) c##UL
// X86_64-NETBSD:#define __UINT64_C_SUFFIX__ UL
// X86_64-NETBSD:#define __UINT64_MAX__ 18446744073709551615UL
// X86_64-NETBSD:#define __UINT64_TYPE__ long unsigned int
// X86_64-NETBSD:#define __UINT8_C(c) c
// X86_64-NETBSD:#define __UINT8_C_SUFFIX__
// X86_64-NETBSD:#define __UINT8_MAX__ 255
// X86_64-NETBSD:#define __UINT8_TYPE__ unsigned char
// X86_64-NETBSD:#define __UINTMAX_C(c) c##UL
// X86_64-NETBSD:#define __UINTMAX_C_SUFFIX__ UL
// X86_64-NETBSD:#define __UINTMAX_MAX__ 18446744073709551615UL
// X86_64-NETBSD:#define __UINTMAX_TYPE__ long unsigned int
// X86_64-NETBSD:#define __UINTMAX_WIDTH__ 64
// X86_64-NETBSD:#define __UINTPTR_MAX__ 18446744073709551615UL
// X86_64-NETBSD:#define __UINTPTR_TYPE__ long unsigned int
// X86_64-NETBSD:#define __UINTPTR_WIDTH__ 64
// X86_64-NETBSD:#define __UINT_FAST16_MAX__ 65535
// X86_64-NETBSD:#define __UINT_FAST16_TYPE__ unsigned short
// X86_64-NETBSD:#define __UINT_FAST32_MAX__ 4294967295U
// X86_64-NETBSD:#define __UINT_FAST32_TYPE__ unsigned int
// X86_64-NETBSD:#define __UINT_FAST64_MAX__ 18446744073709551615UL
// X86_64-NETBSD:#define __UINT_FAST64_TYPE__ long unsigned int
// X86_64-NETBSD:#define __UINT_FAST8_MAX__ 255
// X86_64-NETBSD:#define __UINT_FAST8_TYPE__ unsigned char
// X86_64-NETBSD:#define __UINT_LEAST16_MAX__ 65535
// X86_64-NETBSD:#define __UINT_LEAST16_TYPE__ unsigned short
// X86_64-NETBSD:#define __UINT_LEAST32_MAX__ 4294967295U
// X86_64-NETBSD:#define __UINT_LEAST32_TYPE__ unsigned int
// X86_64-NETBSD:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
// X86_64-NETBSD:#define __UINT_LEAST64_TYPE__ long unsigned int
// X86_64-NETBSD:#define __UINT_LEAST8_MAX__ 255
// X86_64-NETBSD:#define __UINT_LEAST8_TYPE__ unsigned char
// X86_64-NETBSD:#define __USER_LABEL_PREFIX__
// X86_64-NETBSD:#define __WCHAR_MAX__ 2147483647
// X86_64-NETBSD:#define __WCHAR_TYPE__ int
// X86_64-NETBSD:#define __WCHAR_WIDTH__ 32
// X86_64-NETBSD:#define __WINT_TYPE__ int
// X86_64-NETBSD:#define __WINT_WIDTH__ 32
// X86_64-NETBSD:#define __amd64 1
// X86_64-NETBSD:#define __amd64__ 1
// X86_64-NETBSD:#define __x86_64 1
// X86_64-NETBSD:#define __x86_64__ 1

// RUN: %clang_cc1 -E -dM -triple=i386-unknown-openbsd -x c++ < /dev/null | FileCheck -match-full-lines -check-prefix I386-OPENBSD-CXX %s
// I386-OPENBSD-CXX: #define __STDCPP_DEFAULT_NEW_ALIGNMENT__ 16UL

// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=i386-pc-windows-cygnus -target-cpu pentium4 < /dev/null | FileCheck -match-full-lines -check-prefix I386-CYGWIN %s
// I386-CYGWIN-NOT:#define _LP64
// I386-CYGWIN:#define __BIGGEST_ALIGNMENT__ 16
// I386-CYGWIN:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
// I386-CYGWIN:#define __CHAR16_TYPE__ unsigned short
// I386-CYGWIN:#define __CHAR32_TYPE__ unsigned int
// I386-CYGWIN:#define __CHAR_BIT__ 8
// I386-CYGWIN:#define __CYGWIN32__ 1
// I386-CYGWIN:#define __CYGWIN__ 1
// I386-CYGWIN:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
// I386-CYGWIN:#define __DBL_DIG__ 15
// I386-CYGWIN:#define __DBL_EPSILON__ 2.2204460492503131e-16
// I386-CYGWIN:#define __DBL_HAS_DENORM__ 1
// I386-CYGWIN:#define __DBL_HAS_INFINITY__ 1
// I386-CYGWIN:#define __DBL_HAS_QUIET_NAN__ 1
// I386-CYGWIN:#define __DBL_MANT_DIG__ 53
// I386-CYGWIN:#define __DBL_MAX_10_EXP__ 308
// I386-CYGWIN:#define __DBL_MAX_EXP__ 1024
// I386-CYGWIN:#define __DBL_MAX__ 1.7976931348623157e+308
// I386-CYGWIN:#define __DBL_MIN_10_EXP__ (-307)
// I386-CYGWIN:#define __DBL_MIN_EXP__ (-1021)
// I386-CYGWIN:#define __DBL_MIN__ 2.2250738585072014e-308
// I386-CYGWIN:#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
// I386-CYGWIN:#define __FLT_DENORM_MIN__ 1.40129846e-45F
// I386-CYGWIN:#define __FLT_DIG__ 6
// I386-CYGWIN:#define __FLT_EPSILON__ 1.19209290e-7F
// I386-CYGWIN:#define __FLT_HAS_DENORM__ 1
// I386-CYGWIN:#define __FLT_HAS_INFINITY__ 1
// I386-CYGWIN:#define __FLT_HAS_QUIET_NAN__ 1
// I386-CYGWIN:#define __FLT_MANT_DIG__ 24
// I386-CYGWIN:#define __FLT_MAX_10_EXP__ 38
// I386-CYGWIN:#define __FLT_MAX_EXP__ 128
// I386-CYGWIN:#define __FLT_MAX__ 3.40282347e+38F
// I386-CYGWIN:#define __FLT_MIN_10_EXP__ (-37)
// I386-CYGWIN:#define __FLT_MIN_EXP__ (-125)
// I386-CYGWIN:#define __FLT_MIN__ 1.17549435e-38F
// I386-CYGWIN:#define __FLT_RADIX__ 2
// I386-CYGWIN:#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
// I386-CYGWIN:#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
// I386-CYGWIN:#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
// I386-CYGWIN:#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
// I386-CYGWIN:#define __GCC_ATOMIC_INT_LOCK_FREE 2
// I386-CYGWIN:#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
// I386-CYGWIN:#define __GCC_ATOMIC_LONG_LOCK_FREE 2
// I386-CYGWIN:#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
// I386-CYGWIN:#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
// I386-CYGWIN:#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
// I386-CYGWIN:#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
// I386-CYGWIN:#define __GXX_TYPEINFO_EQUALITY_INLINE 0
// I386-CYGWIN:#define __ILP32__ 1
// I386-CYGWIN:#define __INT16_C(c) c
// I386-CYGWIN:#define __INT16_C_SUFFIX__
// I386-CYGWIN:#define __INT16_FMTd__ "hd"
// I386-CYGWIN:#define __INT16_FMTi__ "hi"
// I386-CYGWIN:#define __INT16_MAX__ 32767
// I386-CYGWIN:#define __INT16_TYPE__ short
// I386-CYGWIN:#define __INT32_C(c) c
// I386-CYGWIN:#define __INT32_C_SUFFIX__
// I386-CYGWIN:#define __INT32_FMTd__ "d"
// I386-CYGWIN:#define __INT32_FMTi__ "i"
// I386-CYGWIN:#define __INT32_MAX__ 2147483647
// I386-CYGWIN:#define __INT32_TYPE__ int
// I386-CYGWIN:#define __INT64_C(c) c##LL
// I386-CYGWIN:#define __INT64_C_SUFFIX__ LL
// I386-CYGWIN:#define __INT64_FMTd__ "lld"
// I386-CYGWIN:#define __INT64_FMTi__ "lli"
// I386-CYGWIN:#define __INT64_MAX__ 9223372036854775807LL
// I386-CYGWIN:#define __INT64_TYPE__ long long int
// I386-CYGWIN:#define __INT8_C(c) c
// I386-CYGWIN:#define __INT8_C_SUFFIX__
// I386-CYGWIN:#define __INT8_FMTd__ "hhd"
// I386-CYGWIN:#define __INT8_FMTi__ "hhi"
// I386-CYGWIN:#define __INT8_MAX__ 127
// I386-CYGWIN:#define __INT8_TYPE__ signed char
// I386-CYGWIN:#define __INTMAX_C(c) c##LL
// I386-CYGWIN:#define __INTMAX_C_SUFFIX__ LL
// I386-CYGWIN:#define __INTMAX_FMTd__ "lld"
// I386-CYGWIN:#define __INTMAX_FMTi__ "lli"
// I386-CYGWIN:#define __INTMAX_MAX__ 9223372036854775807LL
// I386-CYGWIN:#define __INTMAX_TYPE__ long long int
// I386-CYGWIN:#define __INTMAX_WIDTH__ 64
// I386-CYGWIN:#define __INTPTR_FMTd__ "d"
// I386-CYGWIN:#define __INTPTR_FMTi__ "i"
// I386-CYGWIN:#define __INTPTR_MAX__ 2147483647
// I386-CYGWIN:#define __INTPTR_TYPE__ int
// I386-CYGWIN:#define __INTPTR_WIDTH__ 32
// I386-CYGWIN:#define __INT_FAST16_FMTd__ "hd"
// I386-CYGWIN:#define __INT_FAST16_FMTi__ "hi"
// I386-CYGWIN:#define __INT_FAST16_MAX__ 32767
// I386-CYGWIN:#define __INT_FAST16_TYPE__ short
// I386-CYGWIN:#define __INT_FAST32_FMTd__ "d"
// I386-CYGWIN:#define __INT_FAST32_FMTi__ "i"
// I386-CYGWIN:#define __INT_FAST32_MAX__ 2147483647
// I386-CYGWIN:#define __INT_FAST32_TYPE__ int
// I386-CYGWIN:#define __INT_FAST64_FMTd__ "lld"
// I386-CYGWIN:#define __INT_FAST64_FMTi__ "lli"
// I386-CYGWIN:#define __INT_FAST64_MAX__ 9223372036854775807LL
// I386-CYGWIN:#define __INT_FAST64_TYPE__ long long int
// I386-CYGWIN:#define __INT_FAST8_FMTd__ "hhd"
// I386-CYGWIN:#define __INT_FAST8_FMTi__ "hhi"
// I386-CYGWIN:#define __INT_FAST8_MAX__ 127
// I386-CYGWIN:#define __INT_FAST8_TYPE__ signed char
// I386-CYGWIN:#define __INT_LEAST16_FMTd__ "hd"
// I386-CYGWIN:#define __INT_LEAST16_FMTi__ "hi"
// I386-CYGWIN:#define __INT_LEAST16_MAX__ 32767
// I386-CYGWIN:#define __INT_LEAST16_TYPE__ short
// I386-CYGWIN:#define __INT_LEAST32_FMTd__ "d"
// I386-CYGWIN:#define __INT_LEAST32_FMTi__ "i"
// I386-CYGWIN:#define __INT_LEAST32_MAX__ 2147483647
// I386-CYGWIN:#define __INT_LEAST32_TYPE__ int
// I386-CYGWIN:#define __INT_LEAST64_FMTd__ "lld"
// I386-CYGWIN:#define __INT_LEAST64_FMTi__ "lli"
// I386-CYGWIN:#define __INT_LEAST64_MAX__ 9223372036854775807LL
// I386-CYGWIN:#define __INT_LEAST64_TYPE__ long long int
// I386-CYGWIN:#define __INT_LEAST8_FMTd__ "hhd"
// I386-CYGWIN:#define __INT_LEAST8_FMTi__ "hhi"
// I386-CYGWIN:#define __INT_LEAST8_MAX__ 127
// I386-CYGWIN:#define __INT_LEAST8_TYPE__ signed char
// I386-CYGWIN:#define __INT_MAX__ 2147483647
// I386-CYGWIN:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
// I386-CYGWIN:#define __LDBL_DIG__ 18
// I386-CYGWIN:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
// I386-CYGWIN:#define __LDBL_HAS_DENORM__ 1
// I386-CYGWIN:#define __LDBL_HAS_INFINITY__ 1
// I386-CYGWIN:#define __LDBL_HAS_QUIET_NAN__ 1
// I386-CYGWIN:#define __LDBL_MANT_DIG__ 64
// I386-CYGWIN:#define __LDBL_MAX_10_EXP__ 4932
// I386-CYGWIN:#define __LDBL_MAX_EXP__ 16384
// I386-CYGWIN:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
// I386-CYGWIN:#define __LDBL_MIN_10_EXP__ (-4931)
// I386-CYGWIN:#define __LDBL_MIN_EXP__ (-16381)
// I386-CYGWIN:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
// I386-CYGWIN:#define __LITTLE_ENDIAN__ 1
// I386-CYGWIN:#define __LONG_LONG_MAX__ 9223372036854775807LL
// I386-CYGWIN:#define __LONG_MAX__ 2147483647L
// I386-CYGWIN-NOT:#define __LP64__
// I386-CYGWIN:#define __NO_MATH_INLINES 1
// I386-CYGWIN:#define __POINTER_WIDTH__ 32
// I386-CYGWIN:#define __PTRDIFF_TYPE__ int
// I386-CYGWIN:#define __PTRDIFF_WIDTH__ 32
// I386-CYGWIN:#define __REGISTER_PREFIX__
// I386-CYGWIN:#define __SCHAR_MAX__ 127
// I386-CYGWIN:#define __SHRT_MAX__ 32767
// I386-CYGWIN:#define __SIG_ATOMIC_MAX__ 2147483647
// I386-CYGWIN:#define __SIG_ATOMIC_WIDTH__ 32
// I386-CYGWIN:#define __SIZEOF_DOUBLE__ 8
// I386-CYGWIN:#define __SIZEOF_FLOAT__ 4
// I386-CYGWIN:#define __SIZEOF_INT__ 4
// I386-CYGWIN:#define __SIZEOF_LONG_DOUBLE__ 12
// I386-CYGWIN:#define __SIZEOF_LONG_LONG__ 8
// I386-CYGWIN:#define __SIZEOF_LONG__ 4
// I386-CYGWIN:#define __SIZEOF_POINTER__ 4
// I386-CYGWIN:#define __SIZEOF_PTRDIFF_T__ 4
// I386-CYGWIN:#define __SIZEOF_SHORT__ 2
// I386-CYGWIN:#define __SIZEOF_SIZE_T__ 4
// I386-CYGWIN:#define __SIZEOF_WCHAR_T__ 2
// I386-CYGWIN:#define __SIZEOF_WINT_T__ 4
// I386-CYGWIN:#define __SIZE_MAX__ 4294967295U
// I386-CYGWIN:#define __SIZE_TYPE__ unsigned int
// I386-CYGWIN:#define __SIZE_WIDTH__ 32
// I386-CYGWIN:#define __UINT16_C(c) c
// I386-CYGWIN:#define __UINT16_C_SUFFIX__
// I386-CYGWIN:#define __UINT16_MAX__ 65535
// I386-CYGWIN:#define __UINT16_TYPE__ unsigned short
// I386-CYGWIN:#define __UINT32_C(c) c##U
// I386-CYGWIN:#define __UINT32_C_SUFFIX__ U
// I386-CYGWIN:#define __UINT32_MAX__ 4294967295U
// I386-CYGWIN:#define __UINT32_TYPE__ unsigned int
// I386-CYGWIN:#define __UINT64_C(c) c##ULL
// I386-CYGWIN:#define __UINT64_C_SUFFIX__ ULL
// I386-CYGWIN:#define __UINT64_MAX__ 18446744073709551615ULL
// I386-CYGWIN:#define __UINT64_TYPE__ long long unsigned int
// I386-CYGWIN:#define __UINT8_C(c) c
// I386-CYGWIN:#define __UINT8_C_SUFFIX__
// I386-CYGWIN:#define __UINT8_MAX__ 255
// I386-CYGWIN:#define __UINT8_TYPE__ unsigned char
// I386-CYGWIN:#define __UINTMAX_C(c) c##ULL
// I386-CYGWIN:#define __UINTMAX_C_SUFFIX__ ULL
// I386-CYGWIN:#define __UINTMAX_MAX__ 18446744073709551615ULL
// I386-CYGWIN:#define __UINTMAX_TYPE__ long long unsigned int
// I386-CYGWIN:#define __UINTMAX_WIDTH__ 64
// I386-CYGWIN:#define __UINTPTR_MAX__ 4294967295U
// I386-CYGWIN:#define __UINTPTR_TYPE__ unsigned int
// I386-CYGWIN:#define __UINTPTR_WIDTH__ 32
// I386-CYGWIN:#define __UINT_FAST16_MAX__ 65535
// I386-CYGWIN:#define __UINT_FAST16_TYPE__ unsigned short
// I386-CYGWIN:#define __UINT_FAST32_MAX__ 4294967295U
// I386-CYGWIN:#define __UINT_FAST32_TYPE__ unsigned int
// I386-CYGWIN:#define __UINT_FAST64_MAX__ 18446744073709551615ULL
// I386-CYGWIN:#define __UINT_FAST64_TYPE__ long long unsigned int
// I386-CYGWIN:#define __UINT_FAST8_MAX__ 255
// I386-CYGWIN:#define __UINT_FAST8_TYPE__ unsigned char
// I386-CYGWIN:#define __UINT_LEAST16_MAX__ 65535
// I386-CYGWIN:#define __UINT_LEAST16_TYPE__ unsigned short
// I386-CYGWIN:#define __UINT_LEAST32_MAX__ 4294967295U
// I386-CYGWIN:#define __UINT_LEAST32_TYPE__ unsigned int
// I386-CYGWIN:#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
// I386-CYGWIN:#define __UINT_LEAST64_TYPE__ long long unsigned int
// I386-CYGWIN:#define __UINT_LEAST8_MAX__ 255
// I386-CYGWIN:#define __UINT_LEAST8_TYPE__ unsigned char
// I386-CYGWIN:#define __USER_LABEL_PREFIX__ _
// I386-CYGWIN:#define __WCHAR_MAX__ 65535
// I386-CYGWIN:#define __WCHAR_TYPE__ unsigned short
// I386-CYGWIN:#define __WCHAR_WIDTH__ 16
// I386-CYGWIN:#define __WINT_TYPE__ unsigned int
// I386-CYGWIN:#define __WINT_WIDTH__ 32
// I386-CYGWIN:#define __i386 1
// I386-CYGWIN:#define __i386__ 1
// I386-CYGWIN:#define __unix 1
// I386-CYGWIN:#define __unix__ 1
// I386-CYGWIN:#define i386 1
// I386-CYGWIN:#define unix 1

// RUN: %clang_cc1 -E -dM -ffreestanding -fgnuc-version=4.2.1 -triple=x86_64-pc-windows-cygnus < /dev/null | FileCheck -match-full-lines -check-prefix X86_64-CYGWIN %s
// X86_64-CYGWIN:#define _LP64 1
// X86_64-CYGWIN:#define __BIGGEST_ALIGNMENT__ 16
// X86_64-CYGWIN:#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
// X86_64-CYGWIN:#define __CHAR16_TYPE__ unsigned short
// X86_64-CYGWIN:#define __CHAR32_TYPE__ unsigned int
// X86_64-CYGWIN:#define __CHAR_BIT__ 8
// X86_64-CYGWIN:#define __CYGWIN__ 1
// X86_64-CYGWIN:#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
// X86_64-CYGWIN:#define __DBL_DIG__ 15
// X86_64-CYGWIN:#define __DBL_EPSILON__ 2.2204460492503131e-16
// X86_64-CYGWIN:#define __DBL_HAS_DENORM__ 1
// X86_64-CYGWIN:#define __DBL_HAS_INFINITY__ 1
// X86_64-CYGWIN:#define __DBL_HAS_QUIET_NAN__ 1
// X86_64-CYGWIN:#define __DBL_MANT_DIG__ 53
// X86_64-CYGWIN:#define __DBL_MAX_10_EXP__ 308
// X86_64-CYGWIN:#define __DBL_MAX_EXP__ 1024
// X86_64-CYGWIN:#define __DBL_MAX__ 1.7976931348623157e+308
// X86_64-CYGWIN:#define __DBL_MIN_10_EXP__ (-307)
// X86_64-CYGWIN:#define __DBL_MIN_EXP__ (-1021)
// X86_64-CYGWIN:#define __DBL_MIN__ 2.2250738585072014e-308
// X86_64-CYGWIN:#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
// X86_64-CYGWIN:#define __FLT_DENORM_MIN__ 1.40129846e-45F
// X86_64-CYGWIN:#define __FLT_DIG__ 6
// X86_64-CYGWIN:#define __FLT_EPSILON__ 1.19209290e-7F
// X86_64-CYGWIN:#define __FLT_HAS_DENORM__ 1
// X86_64-CYGWIN:#define __FLT_HAS_INFINITY__ 1
// X86_64-CYGWIN:#define __FLT_HAS_QUIET_NAN__ 1
// X86_64-CYGWIN:#define __FLT_MANT_DIG__ 24
// X86_64-CYGWIN:#define __FLT_MAX_10_EXP__ 38
// X86_64-CYGWIN:#define __FLT_MAX_EXP__ 128
// X86_64-CYGWIN:#define __FLT_MAX__ 3.40282347e+38F
// X86_64-CYGWIN:#define __FLT_MIN_10_EXP__ (-37)
// X86_64-CYGWIN:#define __FLT_MIN_EXP__ (-125)
// X86_64-CYGWIN:#define __FLT_MIN__ 1.17549435e-38F
// X86_64-CYGWIN:#define __FLT_RADIX__ 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_INT_LOCK_FREE 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_LONG_LOCK_FREE 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
// X86_64-CYGWIN:#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
// X86_64-CYGWIN:#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
// X86_64-CYGWIN:#define __GXX_TYPEINFO_EQUALITY_INLINE 0
// X86_64-CYGWIN:#define __INT16_C(c) c
// X86_64-CYGWIN:#define __INT16_C_SUFFIX__
// X86_64-CYGWIN:#define __INT16_FMTd__ "hd"
// X86_64-CYGWIN:#define __INT16_FMTi__ "hi"
// X86_64-CYGWIN:#define __INT16_MAX__ 32767
// X86_64-CYGWIN:#define __INT16_TYPE__ short
// X86_64-CYGWIN:#define __INT32_C(c) c
// X86_64-CYGWIN:#define __INT32_C_SUFFIX__
// X86_64-CYGWIN:#define __INT32_FMTd__ "d"
// X86_64-CYGWIN:#define __INT32_FMTi__ "i"
// X86_64-CYGWIN:#define __INT32_MAX__ 2147483647
// X86_64-CYGWIN:#define __INT32_TYPE__ int
// X86_64-CYGWIN:#define __INT64_C(c) c##L
// X86_64-CYGWIN:#define __INT64_C_SUFFIX__ L
// X86_64-CYGWIN:#define __INT64_FMTd__ "ld"
// X86_64-CYGWIN:#define __INT64_FMTi__ "li"
// X86_64-CYGWIN:#define __INT64_MAX__ 9223372036854775807L
// X86_64-CYGWIN:#define __INT64_TYPE__ long int
// X86_64-CYGWIN:#define __INT8_C(c) c
// X86_64-CYGWIN:#define __INT8_C_SUFFIX__
// X86_64-CYGWIN:#define __INT8_FMTd__ "hhd"
// X86_64-CYGWIN:#define __INT8_FMTi__ "hhi"
// X86_64-CYGWIN:#define __INT8_MAX__ 127
// X86_64-CYGWIN:#define __INT8_TYPE__ signed char
// X86_64-CYGWIN:#define __INTMAX_C(c) c##L
// X86_64-CYGWIN:#define __INTMAX_C_SUFFIX__ L
// X86_64-CYGWIN:#define __INTMAX_FMTd__ "ld"
// X86_64-CYGWIN:#define __INTMAX_FMTi__ "li"
// X86_64-CYGWIN:#define __INTMAX_MAX__ 9223372036854775807L
// X86_64-CYGWIN:#define __INTMAX_TYPE__ long int
// X86_64-CYGWIN:#define __INTMAX_WIDTH__ 64
// X86_64-CYGWIN:#define __INTPTR_FMTd__ "ld"
// X86_64-CYGWIN:#define __INTPTR_FMTi__ "li"
// X86_64-CYGWIN:#define __INTPTR_MAX__ 9223372036854775807L
// X86_64-CYGWIN:#define __INTPTR_TYPE__ long int
// X86_64-CYGWIN:#define __INTPTR_WIDTH__ 64
// X86_64-CYGWIN:#define __INT_FAST16_FMTd__ "hd"
// X86_64-CYGWIN:#define __INT_FAST16_FMTi__ "hi"
// X86_64-CYGWIN:#define __INT_FAST16_MAX__ 32767
// X86_64-CYGWIN:#define __INT_FAST16_TYPE__ short
// X86_64-CYGWIN:#define __INT_FAST32_FMTd__ "d"
// X86_64-CYGWIN:#define __INT_FAST32_FMTi__ "i"
// X86_64-CYGWIN:#define __INT_FAST32_MAX__ 2147483647
// X86_64-CYGWIN:#define __INT_FAST32_TYPE__ int
// X86_64-CYGWIN:#define __INT_FAST64_FMTd__ "ld"
// X86_64-CYGWIN:#define __INT_FAST64_FMTi__ "li"
// X86_64-CYGWIN:#define __INT_FAST64_MAX__ 9223372036854775807L
// X86_64-CYGWIN:#define __INT_FAST64_TYPE__ long int
// X86_64-CYGWIN:#define __INT_FAST8_FMTd__ "hhd"
// X86_64-CYGWIN:#define __INT_FAST8_FMTi__ "hhi"
// X86_64-CYGWIN:#define __INT_FAST8_MAX__ 127
// X86_64-CYGWIN:#define __INT_FAST8_TYPE__ signed char
// X86_64-CYGWIN:#define __INT_LEAST16_FMTd__ "hd"
// X86_64-CYGWIN:#define __INT_LEAST16_FMTi__ "hi"
// X86_64-CYGWIN:#define __INT_LEAST16_MAX__ 32767
// X86_64-CYGWIN:#define __INT_LEAST16_TYPE__ short
// X86_64-CYGWIN:#define __INT_LEAST32_FMTd__ "d"
// X86_64-CYGWIN:#define __INT_LEAST32_FMTi__ "i"
// X86_64-CYGWIN:#define __INT_LEAST32_MAX__ 2147483647
// X86_64-CYGWIN:#define __INT_LEAST32_TYPE__ int
// X86_64-CYGWIN:#define __INT_LEAST64_FMTd__ "ld"
// X86_64-CYGWIN:#define __INT_LEAST64_FMTi__ "li"
// X86_64-CYGWIN:#define __INT_LEAST64_MAX__ 9223372036854775807L
// X86_64-CYGWIN:#define __INT_LEAST64_TYPE__ long int
// X86_64-CYGWIN:#define __INT_LEAST8_FMTd__ "hhd"
// X86_64-CYGWIN:#define __INT_LEAST8_FMTi__ "hhi"
// X86_64-CYGWIN:#define __INT_LEAST8_MAX__ 127
// X86_64-CYGWIN:#define __INT_LEAST8_TYPE__ signed char
// X86_64-CYGWIN:#define __INT_MAX__ 2147483647
// X86_64-CYGWIN:#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
// X86_64-CYGWIN:#define __LDBL_DIG__ 18
// X86_64-CYGWIN:#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
// X86_64-CYGWIN:#define __LDBL_HAS_DENORM__ 1
// X86_64-CYGWIN:#define __LDBL_HAS_INFINITY__ 1
// X86_64-CYGWIN:#define __LDBL_HAS_QUIET_NAN__ 1
// X86_64-CYGWIN:#define __LDBL_MANT_DIG__ 64
// X86_64-CYGWIN:#define __LDBL_MAX_10_EXP__ 4932
// X86_64-CYGWIN:#define __LDBL_MAX_EXP__ 16384
// X86_64-CYGWIN:#define __LDBL_MAX__ 1.18973149535723176502e+4932L
// X86_64-CYGWIN:#define __LDBL_MIN_10_EXP__ (-4931)
// X86_64-CYGWIN:#define __LDBL_MIN_EXP__ (-16381)
// X86_64-CYGWIN:#define __LDBL_MIN__ 3.36210314311209350626e-4932L
// X86_64-CYGWIN:#define __LITTLE_ENDIAN__ 1
// X86_64-CYGWIN:#define __LONG_LONG_MAX__ 9223372036854775807LL
// X86_64-CYGWIN:#define __LONG_MAX__ 9223372036854775807L
// X86_64-CYGWIN:#define __LP64__ 1
// X86_64-CYGWIN:#define __MMX__ 1
// X86_64-CYGWIN:#define __NO_MATH_INLINES 1
// X86_64-CYGWIN:#define __POINTER_WIDTH__ 64
// X86_64-CYGWIN:#define __PTRDIFF_TYPE__ long int
// X86_64-CYGWIN:#define __PTRDIFF_WIDTH__ 64
// X86_64-CYGWIN:#define __REGISTER_PREFIX__
// X86_64-CYGWIN:#define __SCHAR_MAX__ 127
// X86_64-CYGWIN:#define __SHRT_MAX__ 32767
// X86_64-CYGWIN:#define __SIG_ATOMIC_MAX__ 2147483647
// X86_64-CYGWIN:#define __SIG_ATOMIC_WIDTH__ 32
// X86_64-CYGWIN:#define __SIZEOF_DOUBLE__ 8
// X86_64-CYGWIN:#define __SIZEOF_FLOAT__ 4
// X86_64-CYGWIN:#define __SIZEOF_INT__ 4
// X86_64-CYGWIN:#define __SIZEOF_LONG_DOUBLE__ 16
// X86_64-CYGWIN:#define __SIZEOF_LONG_LONG__ 8
// X86_64-CYGWIN:#define __SIZEOF_LONG__ 8
// X86_64-CYGWIN:#define __SIZEOF_POINTER__ 8
// X86_64-CYGWIN:#define __SIZEOF_PTRDIFF_T__ 8
// X86_64-CYGWIN:#define __SIZEOF_SHORT__ 2
// X86_64-CYGWIN:#define __SIZEOF_SIZE_T__ 8
// X86_64-CYGWIN:#define __SIZEOF_WCHAR_T__ 2
// X86_64-CYGWIN:#define __SIZEOF_WINT_T__ 4
// X86_64-CYGWIN:#define __SIZE_MAX__ 18446744073709551615UL
// X86_64-CYGWIN:#define __SIZE_TYPE__ long unsigned int
// X86_64-CYGWIN:#define __SIZE_WIDTH__ 64
// X86_64-CYGWIN:#define __SSE2_MATH__ 1
// X86_64-CYGWIN:#define __SSE2__ 1
// X86_64-CYGWIN:#define __SSE_MATH__ 1
// X86_64-CYGWIN:#define __SSE__ 1
// X86_64-CYGWIN:#define __UINT16_C(c) c
// X86_64-CYGWIN:#define __UINT16_C_SUFFIX__
// X86_64-CYGWIN:#define __UINT16_MAX__ 65535
// X86_64-CYGWIN:#define __UINT16_TYPE__ unsigned short
// X86_64-CYGWIN:#define __UINT32_C(c) c##U
// X86_64-CYGWIN:#define __UINT32_C_SUFFIX__ U
// X86_64-CYGWIN:#define __UINT32_MAX__ 4294967295U
// X86_64-CYGWIN:#define __UINT32_TYPE__ unsigned int
// X86_64-CYGWIN:#define __UINT64_C(c) c##UL
// X86_64-CYGWIN:#define __UINT64_C_SUFFIX__ UL
// X86_64-CYGWIN:#define __UINT64_MAX__ 18446744073709551615UL
// X86_64-CYGWIN:#define __UINT64_TYPE__ long unsigned int
// X86_64-CYGWIN:#define __UINT8_C(c) c
// X86_64-CYGWIN:#define __UINT8_C_SUFFIX__
// X86_64-CYGWIN:#define __UINT8_MAX__ 255
// X86_64-CYGWIN:#define __UINT8_TYPE__ unsigned char
// X86_64-CYGWIN:#define __UINTMAX_C(c) c##UL
// X86_64-CYGWIN:#define __UINTMAX_C_SUFFIX__ UL
// X86_64-CYGWIN:#define __UINTMAX_MAX__ 18446744073709551615UL
// X86_64-CYGWIN:#define __UINTMAX_TYPE__ long unsigned int
// X86_64-CYGWIN:#define __UINTMAX_WIDTH__ 64
// X86_64-CYGWIN:#define __UINTPTR_MAX__ 18446744073709551615UL
// X86_64-CYGWIN:#define __UINTPTR_TYPE__ long unsigned int
// X86_64-CYGWIN:#define __UINTPTR_WIDTH__ 64
// X86_64-CYGWIN:#define __UINT_FAST16_MAX__ 65535
// X86_64-CYGWIN:#define __UINT_FAST16_TYPE__ unsigned short
// X86_64-CYGWIN:#define __UINT_FAST32_MAX__ 4294967295U
// X86_64-CYGWIN:#define __UINT_FAST32_TYPE__ unsigned int
// X86_64-CYGWIN:#define __UINT_FAST64_MAX__ 18446744073709551615UL
// X86_64-CYGWIN:#define __UINT_FAST64_TYPE__ long unsigned int
// X86_64-CYGWIN:#define __UINT_FAST8_MAX__ 255
// X86_64-CYGWIN:#define __UINT_FAST8_TYPE__ unsigned char
// X86_64-CYGWIN:#define __UINT_LEAST16_MAX__ 65535
// X86_64-CYGWIN:#define __UINT_LEAST16_TYPE__ unsigned short
// X86_64-CYGWIN:#define __UINT_LEAST32_MAX__ 4294967295U
// X86_64-CYGWIN:#define __UINT_LEAST32_TYPE__ unsigned int
// X86_64-CYGWIN:#define __UINT_LEAST64_MAX__ 18446744073709551615UL
// X86_64-CYGWIN:#define __UINT_LEAST64_TYPE__ long unsigned int
// X86_64-CYGWIN:#define __UINT_LEAST8_MAX__ 255
// X86_64-CYGWIN:#define __UINT_LEAST8_TYPE__ unsigned char
// X86_64-CYGWIN:#define __USER_LABEL_PREFIX__
// X86_64-CYGWIN:#define __WCHAR_MAX__ 65535
// X86_64-CYGWIN:#define __WCHAR_TYPE__ unsigned short
// X86_64-CYGWIN:#define __WCHAR_WIDTH__ 16
// X86_64-CYGWIN:#define __WINT_TYPE__ unsigned int
// X86_64-CYGWIN:#define __WINT_WIDTH__ 32
// X86_64-CYGWIN:#define __amd64 1
// X86_64-CYGWIN:#define __amd64__ 1
// X86_64-CYGWIN:#define __unix 1
// X86_64-CYGWIN:#define __unix__ 1
// X86_64-CYGWIN:#define __x86_64 1
// X86_64-CYGWIN:#define __x86_64__ 1
// X86_64-CYGWIN:#define unix 1

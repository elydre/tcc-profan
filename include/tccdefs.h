/*  tccdefs.h

    === Definitions for the Tiny C Compiler on profanOS - i386 ===

    This file is included during the preprocessing of the C source
    files by TCC. Nothing is defined before this file except target
    machine, target os and the few things related to option settings
    in tccpp.c:tcc_predefs().
*/

#define __ILP32__ 1

#define __SIZEOF_INT__ 4
#define __INT_MAX__ 0x7fffffff
#define __LONG_MAX__ 0x7fffffffL

#define __SIZEOF_LONG_LONG__ 8
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __CHAR_BIT__ 8
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_BIG_ENDIAN__ 4321
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__

#if __STDC_VERSION__ >= 201112L
 #define __STDC_NO_ATOMICS__ 1
 #define __STDC_NO_COMPLEX__ 1
 #define __STDC_NO_THREADS__ 1
 #define __STDC_UTF_16__ 1
 #define __STDC_UTF_32__ 1
#endif // C11

#define __SIZEOF_SIZE_T__ 4
#define __SIZEOF_PTRDIFF_T__ 4

//* Some derived integer types needed to get stdint.h to compile correctly on some platforms */
#define __INT8_TYPE__   signed char
#define __INT16_TYPE__  short
#define __INT32_TYPE__  int
#define __INT64_TYPE__  long long
#define __UINT8_TYPE__  unsigned char
#define __UINT16_TYPE__ unsigned short
#define __UINT32_TYPE__ unsigned int
#define __UINT64_TYPE__ unsigned long long

#define __INT_LEAST8_TYPE__   __INT8_TYPE__
#define __INT_LEAST16_TYPE__  __INT16_TYPE__
#define __INT_LEAST32_TYPE__  __INT32_TYPE__
#define __INT_LEAST64_TYPE__ __INT64_TYPE__
#define __UINT_LEAST8_TYPE__  __UINT8_TYPE__
#define __UINT_LEAST16_TYPE__ __UINT16_TYPE__
#define __UINT_LEAST32_TYPE__ __UINT32_TYPE__
#define __UINT_LEAST64_TYPE__ __UINT64_TYPE__

#define __INT_FAST8_TYPE__   __INT8_TYPE__
#define __INT_FAST16_TYPE__  __INT16_TYPE__
#define __INT_FAST32_TYPE__  __INT32_TYPE__
#define __INT_FAST64_TYPE__  __INT64_TYPE__
#define __UINT_FAST8_TYPE__  __UINT8_TYPE__
#define __UINT_FAST16_TYPE__ __UINT16_TYPE__
#define __UINT_FAST32_TYPE__ __UINT32_TYPE__
#define __UINT_FAST64_TYPE__ __UINT64_TYPE__

#define __INTPTR_TYPE__  __INT32_TYPE__
#define __UINTPTR_TYPE__ __UINT32_TYPE__

#define __INTMAX_TYPE__  __INT64_TYPE__
#define __UINTMAX_TYPE__ __UINT64_TYPE__

#define __SIZE_TYPE__    __UINT32_TYPE__
#define __PTRDIFF_TYPE__ __INT32_TYPE__
#define __WCHAR_TYPE__   __INT32_TYPE__
#define __WINT_TYPE__    __INT32_TYPE__

#define __INT8_MAX__        (0x7F)
#define __INT16_MAX__       (0x7FFF)
#define __INT32_MAX__       (0x7FFFFFFFL)
#define __INT64_MAX__       (0x7FFFFFFFFFFFFFFFLL)
#define __UINT8_MAX__       (0xFF)
#define __UINT16_MAX__      (0xFFFF)
#define __UINT32_MAX__      (0xFFFFFFFFL)
#define __UINT64_MAX__      (0xFFFFFFFFFFFFFFFFLL)

#define __INT_LEAST8_MAX__   __INT8_MAX__
#define __INT_LEAST16_MAX__  __INT16_MAX__
#define __INT_LEAST32_MAX__  __INT32_MAX__
#define __INT_LEAST64_MAX__  __INT64_MAX__
#define __UINT_LEAST8_MAX__  __UINT8_MAX__
#define __UINT_LEAST16_MAX__ __UINT16_MAX__
#define __UINT_LEAST32_MAX__ __UINT32_MAX__
#define __UINT_LEAST64_MAX__ __UINT64_MAX__

#define __INT_FAST8_MAX__   __INT8_MAX__
#define __INT_FAST16_MAX__  __INT16_MAX__
#define __INT_FAST32_MAX__  __INT32_MAX__
#define __INT_FAST64_MAX__  __INT64_MAX__
#define __UINT_FAST8_MAX__  __UINT8_MAX__
#define __UINT_FAST16_MAX__ __UINT16_MAX__
#define __UINT_FAST32_MAX__ __UINT32_MAX__
#define __UINT_FAST64_MAX__ __UINT64_MAX__

#define __INTPTR_MAX__  __INT32_MAX__
#define __UINTPTR_MAX__ __UINT32_MAX__

#define __INTMAX_MAX__  __INT64_MAX__
#define __UINTMAX_MAX__ __UINT64_MAX__

#define __SIZE_MAX__    __UINT32_MAX__
#define __PTRDIFF_MAX__ __INT32_MAX__
#define __WCHAR_MAX__   __INT32_MAX__
#define __WINT_MAX__    __INT32_MAX__

/* glibc defines. We do not support __USER_NAME_PREFIX__ */
#define __REDIRECT(name, proto, alias) name proto __asm__ (#alias)
#define __REDIRECT_NTH(name, proto, alias) name proto __asm__ (#alias) __THROW
#define __REDIRECT_NTHNL(name, proto, alias) name proto __asm__ (#alias) __THROWNL

/* not implemented */
#define  __PRETTY_FUNCTION__ __FUNCTION__
#define __has_builtin(x) 0
#define __has_feature(x) 0
#define __has_attribute(x) 0

/* C23 Keywords */
#define _Nonnull
#define _Nullable
#define _Nullable_result
#define _Null_unspecified

/* skip __builtin... with -E */
#ifndef __TCC_PP__

#define __builtin_offsetof(type, field) ((__SIZE_TYPE__)&((type*)0)->field)
#define __builtin_extract_return_addr(x) x

/* used by math.h */
#define __builtin_huge_val() 1e500
#define __builtin_huge_valf() 1e50f
#define __builtin_huge_vall() 1e5000L

#define __builtin_nanf(ignored_string) (0.0F/0.0F)

/* __builtin_va_list */
typedef char *__builtin_va_list;
#define __builtin_va_start(ap,last) (ap = ((char *)&(last)) + ((sizeof(last)+3)&~3))
#define __builtin_va_arg(ap,t) (*(t*)((ap+=(sizeof(t)+3)&~3)-((sizeof(t)+3)&~3)))

#define __builtin_va_end(ap) (void)(ap)

#ifndef __builtin_va_copy
# define __builtin_va_copy(dest, src) (dest) = (src)
#endif

/* TCC BBUILTIN AND BOUNDS ALIASES */
#ifdef __leading_underscore
# define __RENAME(X) __asm__("_"X)
#else
# define __RENAME(X) __asm__(X)
#endif

#ifdef __TCC_BCHECK__
# define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME("__bound_"#name);
# define __BOUND(ret,name,params) ret name params __RENAME("__bound_"#name);
#else
# define __BUILTINBC(ret,name,params) ret __builtin_##name params __RENAME(#name);
# define __BOUND(ret,name,params)
#endif

#define __BOTH(ret,name,params) __BUILTINBC(ret,name,params)__BOUND(ret,name,params)
#define __BUILTIN(ret,name,params) ret __builtin_##name params __RENAME(#name);

__BOTH(void*, memcpy, (void *, const void*, __SIZE_TYPE__))
__BOTH(void*, memmove, (void *, const void*, __SIZE_TYPE__))
__BOTH(void*, memset, (void *, int, __SIZE_TYPE__))
__BOTH(int, memcmp, (const void *, const void*, __SIZE_TYPE__))
__BOTH(__SIZE_TYPE__, strlen, (const char *))
__BOTH(char*, strcpy, (char *, const char *))
__BOTH(char*, strncpy, (char *, const char*, __SIZE_TYPE__))
__BOTH(int, strcmp, (const char*, const char*))
__BOTH(int, strncmp, (const char*, const char*, __SIZE_TYPE__))
__BOTH(char*, strcat, (char*, const char*))
__BOTH(char*, strncat, (char*, const char*, __SIZE_TYPE__))
__BOTH(char*, strchr, (const char*, int))
__BOTH(char*, strrchr, (const char*, int))
__BOTH(char*, strdup, (const char*))

__BUILTIN(void*, malloc, (__SIZE_TYPE__))
__BUILTIN(void*, realloc, (void *, __SIZE_TYPE__))
__BUILTIN(void*, calloc, (__SIZE_TYPE__, __SIZE_TYPE__))
__BUILTIN(void*, memalign, (__SIZE_TYPE__, __SIZE_TYPE__))
__BUILTIN(void, free, (void*))

__BOTH(void*, alloca, (__SIZE_TYPE__))
__BUILTIN(void, abort, (void))
__BOUND(void, longjmp, ())
__BOUND(void*, mmap, ())
__BOUND(int, munmap, ())

#undef __BUILTINBC
#undef __BUILTIN
#undef __BOUND
#undef __BOTH
#undef __RENAME

#define __BUILTIN_EXTERN(name,u) 		\
    int __builtin_##name(u int);		\
    int __builtin_##name##l(u long);	\
    int __builtin_##name##ll(u long long);

__BUILTIN_EXTERN(ffs,)
__BUILTIN_EXTERN(clz, unsigned)
__BUILTIN_EXTERN(ctz, unsigned)
__BUILTIN_EXTERN(clrsb,)
__BUILTIN_EXTERN(popcount, unsigned)
__BUILTIN_EXTERN(parity, unsigned)
#undef __BUILTIN_EXTERN

#endif /* ndef __TCC_PP__ */

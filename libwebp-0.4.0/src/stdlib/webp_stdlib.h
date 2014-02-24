#ifndef _WEBP_STDLIB_H_
#define _WEBP_STDLIB_H_

#ifndef WEBP_ENABLE_ASSERTS
#ifdef assert
#undef assert
#endif
#define assert(cond)
#endif

#if 0
// remap qsort
#ifdef qsort
#undef qsort
#endif
#define qsort s4_qsort
#endif

#if 0
// remap memcpy/memset/memcmp
#ifdef memcpy
#undef memcpy
#endif
#define memcpy s4_memcpy

#ifdef memset
#undef memset
#endif
#define memset s4_memset

#ifdef memcmp
#undef memcmp
#endif
#define memcmp s4_memcmp
#endif

#endif

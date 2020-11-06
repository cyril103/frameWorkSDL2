#ifndef COLLECTIONS_C_COMMON_H
#define COLLECTIONS_C_COMMON_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#ifdef ARCH_64
#define MAX_POW_TWO (((size_t) 1) << 63)
#else
#define MAX_POW_TWO (((size_t) 1) << 31)
#endif /* ARCH_64 */


enum cc_stat {
    CC_OK                   = 0,

    CC_ERR_ALLOC            = 1,
    CC_ERR_INVALID_CAPACITY = 2,
    CC_ERR_INVALID_RANGE    = 3,
    CC_ERR_MAX_CAPACITY     = 4,
    CC_ERR_KEY_NOT_FOUND    = 6,
    CC_ERR_VALUE_NOT_FOUND  = 7,
    CC_ERR_OUT_OF_RANGE     = 8,

    CC_ITER_END             = 9,
};

#define CC_MAX_ELEMENTS ((size_t) - 2)

#if defined(_MSC_VER)

#define       INLINE __inline
#define FORCE_INLINE __forceinline

#else

#define       INLINE inline
#define FORCE_INLINE inline __attribute__((always_inline))

#endif /* _MSC_VER */


int cc_common_cmp_str(const void *key1, const void *key2);

#define CC_CMP_STRING  cc_common_cmp_str

#endif
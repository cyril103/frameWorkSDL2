#include "common.h"


/**
 * String comparator function.
 *
 * @param[in] str1 first string
 * @param[in] str2 second string
 *
 * @return
 */
int cc_common_cmp_str(const void *str1, const void *str2)
{
    return strcmp((const char*) str1, (const char*) str2);
}
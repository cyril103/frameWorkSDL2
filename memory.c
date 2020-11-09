#include "memory.h"

static int TotalAllocation = 0;

void *memory_Alloc(int byte)
{
    TotalAllocation += byte;
    return malloc((size_t)byte);
}

void memory_Free(void *ptr, int byte)
{
    TotalAllocation -= byte;
    free(ptr);
}

void memory_leak_check(void)
{
    if (TotalAllocation > 0)
        printf("fuite de mémoire de %d octets.\n", TotalAllocation);
    else if (TotalAllocation < 0)
        printf("le programme a un bug, %d octets ont ete libéres sans etre alloués\n", TotalAllocation);
    else
        printf("pas de fuites de mémoire\n");
}
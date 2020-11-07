#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stdlib.h>
#include <stdio.h>

void *memory_Alloc(int byte);
void memory_Free(void *ptr, int byte);
void memory_leak_check(void);

#endif
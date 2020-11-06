#ifndef __BUFFER__
#define __BUFFER__

#include"memory.h"
#include <string.h>
#include <stdlib.h>

typedef struct Buffer Buffer;

Buffer *Buffer_empty(int elem_size);
void Buffer_add(Buffer *buffer, void *elem);
void Buffer_Destroy(Buffer **buffer, void (* freefn)(void * elem));
int Buffer_Nb_elem(Buffer *buffer);
void *Buffer_get(Buffer *buffer,int index);
void Buffer_update(Buffer *buffer, int index , void *elem);

#endif

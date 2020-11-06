#include "buffer.h"

struct Buffer
{    
    int len;
    int alloc;
    int elem_size;
    void *elems;    
};

Buffer *Buffer_empty(int elem_size)
{
    Buffer *buffer = memory_Alloc(sizeof(Buffer));
    buffer->alloc = 64;
    buffer->len = 0;
    buffer->elem_size = elem_size;
    buffer->elems = memory_Alloc(buffer->alloc * elem_size);
    return buffer;
}
int Buffer_Nb_elem(Buffer *buffer)
{
    return buffer->len;
}

void Buffer_add(Buffer *buffer, void *elem)
{

    if (buffer->len == buffer->alloc)
    {

        int newAlloc = buffer->alloc * 2;

        void *tmp = memcpy(memory_Alloc(newAlloc * buffer->elem_size), buffer->elems, buffer->alloc * buffer->elem_size);

        memory_Free(buffer->elems, buffer->alloc * buffer->elem_size);
        buffer->elems = tmp;
        buffer->alloc = newAlloc;
    }

    memcpy((char *)buffer->elems + buffer->len * buffer->elem_size, elem, buffer->elem_size);

    buffer->len++;
}

void Buffer_Destroy(Buffer **buffer, void (*freefn)(void *elem))
{
    if (*buffer == NULL)
        return;
    if (freefn != NULL)
    {

        for (int i = 0; i < (*buffer)->len; i++)
        {
            freefn((char *)(*buffer)->elems + i * (*buffer)->elem_size);
        }
    }

    memory_Free((*buffer)->elems, (*buffer)->alloc * (*buffer)->elem_size);
    (*buffer)->elems = NULL;

    memory_Free(*buffer, sizeof **buffer);
    *buffer = NULL;
}

void *Buffer_get(Buffer *buffer, int index)
{
    if (buffer == 0 || buffer->len == 0)
        return NULL;
    if (index < 0 || index >= Buffer_Nb_elem(buffer))
        return NULL;
    return (char *)buffer->elems + index * buffer->elem_size;
}

void Buffer_update(Buffer *buffer, int index, void *elem)
{
    if (buffer == 0 || buffer->len == 0)
        return;
    if (index < 0 || index >= Buffer_Nb_elem(buffer))
        return;

    memcpy((char *)buffer->elems + index * buffer->elem_size, elem, buffer->elem_size);
}
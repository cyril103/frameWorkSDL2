#include "hashtable.h"

#include <stdio.h>

int main( int argc , char **argv){

   HashTable *texs;
    enum cc_stat status = hashtable_new(&texs);
    if(status == CC_ERR_ALLOC){
        printf("hastable error alloc\n");
    }

    hashtable_add(texs,"un",(void *)1);
    hashtable_add(texs,"deux",(void *) 2);
    void* out;
    hashtable_get(texs,"un",&out);
    printf("value %lld\n", (long long) out);
    HashTableIter hti;
    hashtable_iter_init(&hti,texs);
    TableEntry *entry;
    while (hashtable_iter_next(&hti,&entry) != CC_ITER_END)
    {
        void * out;
        printf("key %s\n", (char *) entry->key);
        hashtable_iter_remove(&hti,&out);
        printf("remove %lld\n", (long long) out );
    }
    





}
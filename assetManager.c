#include "assetManager.h"
#include <string.h>
#include "memory.h"

static Bool initialized = False;
static HashTable *textures;

void AssetManager_Init(void){
    if(initialized)
        return;
    hashtable_new(&textures);



    initialized = True;    

}
void AssetManager_Released(void){
    HashTableIter iterTex;
    hashtable_iter_init(&iterTex,textures);
    TableEntry *texEntry;
    while (hashtable_iter_next(&iterTex,&texEntry) != CC_ITER_END)
    {
       memory_Free(texEntry->key,512);
       texEntry->key = NULL;
       SDL_DestroyTexture(texEntry->value);
       texEntry->value = NULL;    
    }
    hashtable_destroy(textures);
    textures = NULL;

}
SDL_Texture *AssetManager_GetTexture(char const *filename){
    char * path = memory_Alloc(512);
    char *home =  SDL_GetBasePath();
    strcpy(path,home);
    strcat(path,"asset/");
    strcat(path,filename);
    SDL_free(home);
    home = NULL;
    Bool toFree = True;

    void *tex = NULL;
    hashtable_get(textures,path,&tex);
    if(tex == NULL){
        hashtable_add(textures,path,Graphics_loadTexture(path));
        toFree = False;
    }
    
    hashtable_get(textures,path,&tex);
    if(toFree){
        memory_Free(path,512);
        path = NULL;
    }

    return tex;



}


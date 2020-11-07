#include "assetManager.h"
#include <string.h>
#include "memory.h"

/* static Bool initialized = False;
static HashTable *textures; */
static AssetManager *s_instance = NULL;
static AssetManager *AssetManager_new(void);

static AssetManager *AssetManager_new(void){
    AssetManager model = {
        .GetTexture = AssetManager_GetTexture,
    };
    s_instance = memory_Alloc(sizeof(AssetManager));
    memcpy(s_instance,&model,sizeof(AssetManager));
    hashtable_new(&s_instance->mTextures);
    return s_instance;

}

AssetManager *AssetManager_Instance(void){
    if(s_instance == NULL)
        s_instance = AssetManager_new();
    
    return s_instance; 

}
void AssetManager_Released(void){
    //freeing loadTextures
    HashTableIter iterTex;
    hashtable_iter_init(&iterTex,s_instance->mTextures);
    TableEntry *texEntry;
    while (hashtable_iter_next(&iterTex,&texEntry) != CC_ITER_END)
    {
       memory_Free(texEntry->key,512);
       texEntry->key = NULL;
       SDL_DestroyTexture(texEntry->value);
       texEntry->value = NULL;    
    }
    hashtable_destroy(s_instance->mTextures);
    s_instance->mTextures = NULL;
    /**************************************/

    memory_Free(s_instance,sizeof(AssetManager));

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
    hashtable_get(s_instance->mTextures,path,&tex);
    if(tex == NULL){
        hashtable_add(s_instance->mTextures,path,Graphics_loadTexture(path));
        toFree = False;
    }
    
    hashtable_get(s_instance->mTextures,path,&tex);
    if(toFree){
        memory_Free(path,512);
        path = NULL;
    }

    return tex;



}


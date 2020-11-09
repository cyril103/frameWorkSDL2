#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "Graphics.h"
#include "hashtable.h"


typedef struct AssetManager {
    /*public methods*/
    SDL_Texture *(*GetTexture)(char const *filename);

    /*private attributs*/
    HashTable *mTextures;

}AssetManager;

AssetManager *AssetManager_Instance(void);
void AssetManager_Released(void);
SDL_Texture *AssetManager_GetTexture(char const *filename);




#endif
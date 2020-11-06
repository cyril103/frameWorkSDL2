#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "Graphics.h"
#include "hashtable.h"
#include "util.h"

void AssetManager_Init(void);
void AssetManager_Released(void);
SDL_Texture *AssetManager_GetTexture(char const *filename);




#endif
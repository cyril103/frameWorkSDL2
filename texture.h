#ifndef _TEXTURE_H
#define _TEXTURE_H
#include "Graphics.h"
#include "entity.h"
#include "assetManager.h"

typedef struct Texture Texture;

Texture *Texture_(char const *filename);
void Texture_Destroy(Texture **self);
void Texture_Render(Texture *self);

void Texture_setPos(Texture *self, Vector2 pos);
Vector2 Texture_getPos(Texture *self, ENTITY_SPACE space);
void Texture_setRotation(Texture *self, float rotation);
float Texture_getRotation(Texture *self, ENTITY_SPACE space);
void Texture_setScale(Texture *self, Vector2 scale);
Vector2 Texture_getScale(Texture *self, ENTITY_SPACE space);
void Texture_active(Texture *self, bool active);
bool Texture_isActive(Texture *self);
void Texture_setParent(Texture *self, Entity *parent);
Entity *Texture_getParent(Texture *self);
void Texture_translate(Texture *self, Vector2 vec, ENTITY_SPACE space);
void Texture_rotate(Texture *self, float amount);



#endif
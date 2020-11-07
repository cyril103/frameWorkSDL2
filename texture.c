#include "texture.h"

struct Texture
{
    Entity *super;
    SDL_Texture *mtex;
    int mWidth;
    int mHeight;
};
void Texture_Destroy(Texture **self)
{
    Texture *This = *self;
    Entity_Destroy(&(This->super));
    This->super = NULL;

    memory_Free(This, sizeof(Texture));
    This = NULL;
}

Texture *Texture_(char const *filename)
{
    Graphics_instance();
    AssetManager_Instance();
    Texture *This = memory_Alloc(sizeof(Texture));
    This->super = Entity_0();
    This->mtex = AssetManager_GetTexture(filename);
    SDL_QueryTexture(This->mtex, NULL, NULL, &(This->mWidth), &(This->mHeight));

    return This;
}

void Texture_Render(Texture *self)
{
    Graphics_drawTexture(self->mtex);
}

void Texture_setPos(Texture *self, Vector2 pos)
{
    Entity_setPos(self->super, pos);
}

Vector2 Texture_getPos(Texture *self, ENTITY_SPACE space)
{
    return Entity_getPos(self->super, space);
}
void Texture_setRotation(Texture *self, float rotation)
{
    Entity_setRotation(self->super, rotation);
}
float Texture_getRotation(Texture *self, ENTITY_SPACE space)
{
    return Entity_getRotation(self->super, space);
}
void Texture_setScale(Texture *self, Vector2 scale)
{
    Entity_setScale(self->super, scale);
}
Vector2 Texture_getScale(Texture *self, ENTITY_SPACE space)
{
    return Entity_getScale(self->super, space);
}
void Texture_active(Texture *self, bool active)
{
    Entity_active(self->super, active);
}
bool Texture_isActive(Texture *self)
{
    return Entity_isActive(self->super);
}
void Texture_setParent(Texture *self, Entity *parent)
{
    Entity_setParent(self->super, parent);
}
Entity *Texture_getParent(Texture *self)
{
    return Entity_getParent(self->super);
}
void Texture_translate(Texture *self, Vector2 vec, ENTITY_SPACE space)
{
    Entity_translate(self->super, vec, space);
}
void Texture_rotate(Texture *self, float amount)
{
    Entity_rotate(self->super, amount);
}
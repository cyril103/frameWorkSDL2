#ifndef ENTITY_H
#define ENTITY_H
#include <stdbool.h>
#include "mathHelper.h"
#include "memory.h"


typedef struct Entity Entity;

typedef enum ENTITY_SPACE {LOCAL ,WORLD} ENTITY_SPACE;

Entity *Entity_0(void);
Entity *Entity_(Vector2 pos);
void Entity_Destroy(Entity **self);

void Entity_setPos(Entity *self, Vector2 pos);
Vector2 Entity_getPos(Entity *self, ENTITY_SPACE space);
void Entity_setRotation(Entity *self, float rotation);
float Entity_getRotation(Entity *self, ENTITY_SPACE space);
void Entity_setScale(Entity *self, Vector2 scale);
Vector2 Entity_getScale(Entity *self, ENTITY_SPACE space);
void Entity_active(Entity *self, bool active);
bool Entity_isActive(Entity *self);
void Entity_setParent(Entity *self, Entity *parent);
Entity *Entity_getParent(Entity *self);
void Entity_translate(Entity *self, Vector2 vec, ENTITY_SPACE space);
void Entity_rotate(Entity *self, float amount);






#endif
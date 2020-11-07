#include "entity.h"


struct Entity{

    Vector2 mPos;
    float mRotation;
    Vector2 mScale;
    bool mActive;
    Entity *mParent;


};



Entity *Entity_0(void){
   return Entity_(Vector2_0());
}

Entity *Entity_(Vector2 pos){
    Entity *This = memory_Alloc(sizeof (Entity));
    This->mPos = pos;
    This->mRotation = 0.0f;
    This->mActive = true;
    This->mParent = NULL;
    This->mScale = Vector2_(1.f,1.f);
    return This;

}
void Entity_Destroy(Entity **self){
    Entity *This = *self;
    This->mParent = NULL;
    memory_Free(This,sizeof (Entity));
    This = NULL;
}

void Entity_setPos(Entity *self, Vector2 pos){
    self->mPos = pos;
}
Vector2 Entity_getPos(Entity *self, ENTITY_SPACE space){

    if(space == LOCAL || self->mParent == NULL)
        return self->mPos;
    
    Vector2 parentScale = Entity_getScale(self->mParent,WORLD);
    Vector2 roto2 = Vector2_(self->mPos.x * parentScale.x, self->mPos.y * parentScale.y);
    float roto2_2 = Entity_getRotation(self->mParent,LOCAL);
    Vector2 rotPos = Vector2_Rotate(roto2,roto2_2);
    return Vector2_Plus(Entity_getPos(self->mParent, WORLD), rotPos);
}
void Entity_setRotation(Entity *self, float rotation){
    self->mRotation = rotation;

    if(self->mRotation > 360.0f){
        int mul = self->mRotation / 360;
        self->mRotation -= 360.0f * mul;
        
    } else if(self->mRotation < 0.0f){
        int mul = (self->mRotation / 360) -1;
        self->mRotation -= 360.0f * mul;
    }
}

float Entity_getRotation(Entity *self, ENTITY_SPACE space){
    if(space == LOCAL || self->mParent == NULL)
        return self->mRotation;
    
    return Entity_getRotation(self->mParent,WORLD) + self->mRotation;
}
void Entity_setScale(Entity *self, Vector2 scale){
    self->mScale = scale;
}
Vector2 Entity_getScale(Entity *self, ENTITY_SPACE space){

    if(space == LOCAL || self->mParent == NULL)
        return self->mScale;
    
    Vector2 scale = Entity_getScale(self->mParent,WORLD);
    scale.x *= self->mScale.x;
    scale.y *= self->mScale.y;
    return scale;
}

void Entity_active(Entity *self, bool active){
    self->mActive = active;
}
bool Entity_isActive(Entity *self){
    return self->mActive;
}
void Entity_setParent(Entity *self, Entity *parent){
    if(parent == NULL){
        self->mPos = Entity_getPos(self,WORLD);
        self->mScale = Entity_getScale(self,WORLD);
        self->mRotation = Entity_getRotation(self,WORLD);
    } else {
        if(self->mParent != NULL)
            Entity_setParent(self, NULL);
        
        Vector2 parentScale = Entity_getScale(self->mParent,WORLD);
        Vector2 rot1 = Vector2_Minus(Entity_getPos(self,WORLD),Entity_getPos(self->mParent,WORLD));
        float rot2 = -Entity_getRotation(self->mParent,WORLD);

        self->mPos = Vector2_Rotate(rot1,rot2);
        self->mPos.x /= parentScale.x;
        self->mPos.y /= parentScale.y;

        self->mRotation = self->mRotation - Entity_getRotation(self->mParent,WORLD);

        self->mScale = Vector2_(self->mScale.x / parentScale.x, self->mScale.y / parentScale.y);

    }
    self->mParent = parent;
}
Entity *Entity_getParent(Entity *self){
    return self->mParent;
}

void Entity_translate(Entity *self, Vector2 vec, ENTITY_SPACE space){
    if(space == WORLD){

        self->mPos = Vector2_Plus_Equal(self->mPos,vec);
    } else{

        self->mPos = Vector2_Plus_Equal(self->mPos, Vector2_Rotate(vec, Entity_getRotation(self,WORLD)));

    }
}

void Entity_rotate(Entity *self, float amount){
    self->mRotation += amount;
}

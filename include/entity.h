#ifndef ENTITY_H_
#define ENTITY_H_

#include "raylib.h"

typedef struct {
    float health;
    Vector2 pos;

    char* name;
    // Inventory inventory;
} Entity;

float Entity_Distance(Entity e1, Entity e2);
void Entity_Damage(Entity *self, float damage);
void Entity_Kill(Entity *self);

#endif
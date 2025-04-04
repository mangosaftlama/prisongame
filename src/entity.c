#include "entity.h"

float Entity_Distance(Entity e1, Entity e2) {
    return abs(e1.pos.x, e2.pos.x) + abs(e1.pos.y, e2.pos.y);
}

void Entity_Damage(Entity *self, float damage) {
    self->health -= damage;
}

void Entity_Kill(Entity *self) {
    self->health = 0;
}
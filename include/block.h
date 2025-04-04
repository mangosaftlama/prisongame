#ifndef BLOCK_H_
#define BLOCK_H_

#include "raylib.h"
#include "item.h"

// just tiles btw. (3d but in 2d)

typedef struct {
    Vector3 pos;
} Tile;

typedef struct {
    Tile tile;
} Toilet;

void Toilet_Flush(Toilet *self, Item i);

#endif
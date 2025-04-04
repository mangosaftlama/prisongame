#ifndef ITEM_H_
#define ITEM_H_

enum class ItemType : char {
    NONE = 0,
    FOOD = 1,
    WEAPON = 2,
    TOOL = 3,
};

typedef struct {
    bool isIllegal: 1;
    char type: 4;

    unsigned long id;
    char *name;
    int amount;
    int durability;
} Item;

float Item_GetDamage(Item self);

#endif
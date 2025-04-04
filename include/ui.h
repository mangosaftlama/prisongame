#ifndef UI_H_
#define UI_H_

#include <raylib.h>
#include <stdbool.h>

typedef struct {
  Vector2 pos;
  Vector2 size;
  Color fillColor;
  char* text;
} Button;

typedef struct {
  float min;
  float max;
  float step;
} Slider;

bool Button_Hovered(Button self);
int Button_Clicked(Button self);
void Button_Draw(Button self);
#endif

#include "ui.h"
#include "raylib.h"
#include <stdbool.h>

bool Button_Hovered(Button self) {
  Vector2 mouse_pos = GetMousePosition();

  if (mouse_pos.x >= self.pos.x && mouse_pos.x <= self.pos.x + self.size.x) {
    if (mouse_pos.y >= self.pos.y && mouse_pos.y <= self.pos.y + self.size.y) {
      return true;
    }
  }
  return false;
}

void Button_Draw(Button self) {
  DrawRectangle(self.pos.x, self.pos.y, self.size.x, self.size.y, self.fillColor);
}

// Returns the mouse button or -1 if it didn't got clicked.
int Button_Clicked(Button self) {
  for (int i = 0; i < 7; i++) {
    if (IsMouseButtonPressed(i) && Button_Hovered(self)) {
      return i;
    }
  }
  return -1;
}
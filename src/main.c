#include <stdlib.h>
#include "raylib.h"
#include "resource_dir.h"
#include "ui.h"
#include "stdio.h"
#include "dog.h"

enum GameState { SPLASHSCREEN, MENU };

struct Game {
  enum GameState state;
};

void Init_Game(struct Game *game) { game->state = SPLASHSCREEN; }

Color selection_color(int i, int wantIdx, Color notSelected, Color selected) {
  if (i == wantIdx) {
    return selected;
  }
  return notSelected;
}

void Launch_Menu() {
  PollInputEvents();

  int selectedItem = 0;

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(BLACK);
  
    int menuItemSpacing = 45;
    int lastItemY = 20;

    if (IsKeyPressed(KEY_DOWN)) {
      if (selectedItem < 3) {
        selectedItem++;
      } else {
        selectedItem = 0;
      }
    } else if (IsKeyPressed(KEY_UP)) {
      if (selectedItem > 0) {
        selectedItem--;
      } else {
        selectedItem = 3;
      }
    } else if (IsKeyPressed(KEY_ENTER)) {
      switch (selectedItem) {
        case 3:
          exit(0);
      }
    }

    DrawText("Singleplayer", 20, lastItemY, 30, selection_color(selectedItem, 0, WHITE, BLUE));
    lastItemY = lastItemY + menuItemSpacing;
    DrawText("Multiplayer", 20, lastItemY, 30, selection_color(selectedItem, 1, WHITE, BLUE));
    lastItemY = lastItemY + menuItemSpacing;
    DrawText("Credits", 20, lastItemY, 30, selection_color(selectedItem, 2, WHITE, BLUE));
    lastItemY = lastItemY + menuItemSpacing;
    DrawText("Quit", 20, lastItemY, 30, selection_color(selectedItem, 3, WHITE, BLUE));
  
  
    Button b;
    b.pos.x = 600;
    b.pos.y = 40;
    b.size.x = 200;
    b.size.y = 110;
    b.fillColor = RED;
  
    // Button_Draw(b);
    
    int button = Button_Clicked(b);
  
    if (button != -1) {
      printf("Button clicked: %d!\n", button);
    }
  
    EndDrawing();
  }
};

void Draw_Splashscreen() {
  BeginDrawing();
  ClearBackground(BLACK);
  DrawText("Hello Raylib", 20, 20, 20, WHITE);
  EndDrawing();
};

int main() {
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  InitWindow(1280, 800, "PrisonGame");

  SearchAndSetResourceDir("resources");

  struct Game game;
  Init_Game(&game);


  switch (game.state) {
    case SPLASHSCREEN:
      while (!WindowShouldClose()) {
        Draw_Splashscreen();
        game.state = MENU;
        break;
      }
    case MENU:
      Launch_Menu();
      break;
  }

  CloseWindow();
  return 0;
}

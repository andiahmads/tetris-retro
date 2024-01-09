#include "game.h"
#include <iostream>
#include <raylib.h>
using namespace std;

// 1.setup game loop -> done
// 2.creating the grid -> done
// 3.create th blocks -> done
// 4.move the blocks -> done
// 5.rotate the blocks -> on progress
// 6.checking for collisions
// 7.check for completed rows
// 8.game over
// 9.create user interface
// 10.add score
// 11.add next block
// 12.add sound.
// Color green = {172, 204, 96, 255};
// Color darkGreen = {43, 51, 24, 255};
// Color Dark_Blue = Color{44, 44, 127, 255};

Game game = Game();

int main() {
  InitWindow(300, 600, "Tetris retro");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    // ClearBackground(Dark_Blue);

    game.HandleInput();
    game.Draw();

    EndDrawing();
  }
  CloseWindow();
  return 0;
}

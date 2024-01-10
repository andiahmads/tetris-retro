#include "game.h"
#include <iostream>
#include <raylib.h>
using namespace std;

// 1.setup game loop -> done
// 2.creating the grid -> done
// 3.create th blocks -> done
// 4.move the blocks -> done
// 5.rotate the blocks -> done
// 6.checking for collisions -> done
// 7.check for completed rows -> done
// 8.game over
// 9.create user interface
// 10.add score
// 11.add next block
// 12.add sound.
// Color green = {172, 204, 96, 255};
// Color darkGreen = {43, 51, 24, 255};
// Color Dark_Blue = Color{44, 44, 127, 255};

// melacak waktu terjadinya pembaruan terkahir
double lastUpdateTime = 0;

bool EventTriggered(double interval) {

  double currentTime = GetTime();
  // jika selisih lebih besar atau sama dengan interval maka interval tersebut
  // telah berlalu
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main() {
  InitWindow(300, 600, "Tetris retro");
  SetTargetFPS(60);
  Game game = Game();
  while (!WindowShouldClose()) {
    BeginDrawing();
    // ClearBackground(Dark_Blue);

    game.HandleInput();
    if (EventTriggered(0.3)) {
      game.MoveBlockDown();
    }

    game.Draw();

    EndDrawing();
  }
  CloseWindow();
  return 0;
}

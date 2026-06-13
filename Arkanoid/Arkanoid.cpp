#include <raylib.h>
#include "Game.hpp"

//Incomplete
int main() {
    InitWindow(600, 900, "Arkanoid");
    SetTargetFPS(144);
    Game game;
    while (!WindowShouldClose()) {
        game.Update();
        BeginDrawing();
        ClearBackground(BLACK);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}
#include <iostream>
#include <raylib.h>
#include "Racket.hpp"
#include "Ball.hpp"

const Color BACKGROUND = { 0, 0, 0, 255 };

int main() {
    InitWindow(600, 900, "Arkanoid By Diogo");
    SetTargetFPS(144);
    Racket racket;
    Ball ball;
    while (!WindowShouldClose()) {
        racket.move();
        ball.Update(racket);
        BeginDrawing();
        ClearBackground(BLACK);
        racket.Draw();
        ball.Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}








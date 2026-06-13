#include <raylib.h>
#include "Grid.cpp"

const Color BACKGROUND = { 0, 0, 0, 255 };

int main() {
    InitWindow(300, 600, "Tetris By Diogo");
    SetTargetFPS(144);
    Grid grid = Grid();
    grid.Print();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BACKGROUND);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
#include "Racket.hpp"
#include "raymath.h"

Racket::Racket() {
    dimensions = {WIDTH, HEIGHT};
    position = {INIT_X, INIT_Y};
}
void Racket::Move() {
    float mouseX = GetMouseX();
    position.x = Clamp(mouseX - dimensions.x / 2.0f, 0.0f, GetScreenWidth() - dimensions.x);
}
void Racket::Draw() {
    DrawRectangle(position.x, position.y, dimensions.x, dimensions.y, WHITE);
}
#include "Brick.hpp"

Brick::Brick(Vector2 pos) {
    position = pos;
}
void Brick::Draw() {
    if (!alive) return;
    DrawRectangle(position.x - 50, position.y, size.x, size.y, ORANGE);
}
Rectangle Brick::GetRect() const {
    return {
        position.x,
        position.y,
        size.x,
        size.y
    };
}
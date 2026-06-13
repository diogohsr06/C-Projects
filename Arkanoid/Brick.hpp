#pragma once
#include <raylib.h>

class Brick {
public:
    Brick() = default;
    Brick(Vector2 pos);
    void Draw();
    bool alive = true;
    Rectangle GetRect() const;
private:
    Vector2 position;
    Vector2 size = {50, 20};
};
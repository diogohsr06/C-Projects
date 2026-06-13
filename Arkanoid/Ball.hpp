#pragma once
#include <raylib.h>

class Ball {
public:
    Ball();
    void Update();
    void Draw();
    Vector2 position;
    Vector2 direction;
    static constexpr float RADIUS = 10.5f;
private:
    void CheckWallCollision();
};
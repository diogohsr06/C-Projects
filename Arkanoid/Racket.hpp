#pragma once
#include <raylib.h>

class Racket {
public:
    Racket();
    void Move();
    void Draw();
    Vector2 position;
    Vector2 dimensions;
    static constexpr float WIDTH = 90;
    static constexpr float HEIGHT = 15;
private:
    static constexpr float INIT_X = 263;
    static constexpr float INIT_Y = 840;
};
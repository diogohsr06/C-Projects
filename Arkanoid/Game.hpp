#pragma once

#include <vector>
#include "Ball.hpp"
#include "Racket.hpp"
#include "Brick.hpp"

class Game {
public:
    Game();
    void Update();
    void Draw();
private:
    void CheckRacketCollision();
    void CheckBrickCollision();
    void CheckLoseLife();
    void ResetBall();
    Ball ball;
    Racket racket;
    std::vector<Brick> bricks;
    int lives = 5;
};
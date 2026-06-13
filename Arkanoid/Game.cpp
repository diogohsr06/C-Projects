#include "Game.hpp"
#include <raylib.h>

Game::Game() {
    int rows = 5;
    int cols = 10;

    float startX = 50;
    float startY = 50;
    float spacing = 5;

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {

            Vector2 pos = {
                startX + x * (50 + spacing),
                startY + y * (20 + spacing)
            };

            bricks.push_back(Brick(pos));
        }
    }
}

void Game::Update() {
    racket.Move();
    ball.Update();

    CheckRacketCollision();
    CheckBrickCollision();
    CheckLoseLife();
}

void Game::CheckRacketCollision() {
    if (ball.position.y + Ball::RADIUS >= racket.position.y &&
        ball.position.x >= racket.position.x &&
        ball.position.x <= racket.position.x + racket.dimensions.x)
    {
        ball.direction.y *= -1;

        // controlo simples de ângulo (efeito Arkanoid)
        float hitPos =
            (ball.position.x - racket.position.x) / racket.dimensions.x;

        ball.direction.x = (hitPos - 0.5f) * 8.0f;
    }
}

void Game::CheckBrickCollision() {
    for (Brick& brick : bricks) {
        if (!brick.alive) continue;

        if (CheckCollisionCircleRec(
                ball.position,
                Ball::RADIUS,
                brick.GetRect()))
        {
            brick.alive = false;
            ball.direction.y *= -1;
            break;
        }
    }
}

void Game::CheckLoseLife() {
    if (ball.position.y - Ball::RADIUS > GetScreenHeight()) {
        lives--;
        ResetBall();
    }
}

void Game::ResetBall() {
    ball.position = {300, 700};
    ball.direction = {4, -4};
}

void Game::Draw() {
    racket.Draw();
    ball.Draw();

    for (Brick& brick : bricks) {
        brick.Draw();
    }

    DrawText(TextFormat("Lives: %d", lives), 10, 10, 20, WHITE);
}
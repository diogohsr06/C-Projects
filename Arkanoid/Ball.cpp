#include "Ball.hpp"

Ball::Ball() {
    position = {300, 700};
    direction = {4, -4};
}
void Ball::Update() {
    CheckWallCollision();

    position.x += direction.x;
    position.y += direction.y;
}
void Ball::CheckWallCollision() {
    if (position.x - RADIUS <= 0 || position.x + RADIUS >= GetScreenWidth())
        direction.x *= -1;
    if (position.y - RADIUS <= 0)
        direction.y *= -1;
}
void Ball::Draw() {
    DrawCircle(position.x, position.y, RADIUS, RED);
}
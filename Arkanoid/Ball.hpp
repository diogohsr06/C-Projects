#include <raylib.h>

const double BALL_RADIUS = 10.5;
const Color BALLCOLOR = {255, 0, 0, 255};
const int INIT_Y_DIR = -4;

class Ball {
public:
    Vector2 position = {300, 300};
    Vector2 direction = {4, -4};
    float radius = 10.5f;
    void Update(Racket& racket) {
        if (position.x - radius <= 0 || position.x + radius >= GetScreenWidth())
            direction.x *= -1;
        if (position.y - radius <= 0)
            direction.y *= -1;
        if (CheckCollisionCircleRec(position, radius, Rectangle{racket.position.x, racket.position.y, racket.dimensions.x, racket.dimensions.y})){
            direction.y *= -1;
        }
        position.x += direction.x;
        position.y += direction.y;
    }
    void Draw() {
        DrawCircle(position.x, position.y, radius, RED);
    }
};
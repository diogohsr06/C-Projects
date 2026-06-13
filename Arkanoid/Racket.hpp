#include <raylib.h>
#include "raymath.h"

const Color RACKET_CENTER_COLOR = {255, 255, 255, 255};
const Color RACKET_MID_COLOR = {255, 255, 0, 255};
const Color RACKET_EXT_COLOR = {255, 0, 0, 255};
const int RACKET_WIDTH = 90;
const int RACKET_HEIGHT = 15;
const int RACKET_INIT_X = 263;
const int RACKET_INIT_Y = 840;
const int RACKET_EXT_WIDTH = 15;
const double RACKET_MID_WIDTH = 22.5;

class Racket {
    public:
        Vector2 position = {RACKET_INIT_X, RACKET_INIT_Y};
        Vector2 dimensions = {RACKET_WIDTH, RACKET_HEIGHT};

        void Draw() {
            DrawRectangle(position.x, position.y, dimensions.x, dimensions.y, RACKET_CENTER_COLOR);
            DrawRectangle(position.x, position.y, RACKET_EXT_WIDTH, dimensions.y - 7.5, RACKET_EXT_COLOR);
            DrawRectangle(position.x + 15, position.y, RACKET_MID_WIDTH, dimensions.y - 7.5, RACKET_MID_COLOR);
            DrawRectangle(position.x + 52.5, position.y, RACKET_MID_WIDTH, dimensions.y - 7.5, RACKET_MID_COLOR);
            DrawRectangle(position.x + 75, position.y, RACKET_EXT_WIDTH, dimensions.y - 7.5, RACKET_EXT_COLOR);
        }

        void move() {
            float cursorX = GetMouseX();
            position.x = Clamp(cursorX - RACKET_WIDTH / 2.0f, 0.0f, (float)GetScreenWidth() - RACKET_WIDTH);
        }
};
#include <raylib.h>
#include <iostream>
#include <deque>
#include "raymath.h"

using namespace std;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 30;
double lastUpdateTime = 0;

bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
};

bool posExists(Vector2 element, deque<Vector2> deque) {
    for (unsigned int i = 0; i < deque.size(); i++) {
        if (Vector2Equals(element, deque[i])) {
            return true;
        }
    }
    return false;
};

class Snake {
    public:
        deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
        Vector2 direction = Vector2{1, 0};
        void Draw() {
            for (unsigned int i = 0; i < body.size(); i++) {
                DrawRectangle(body[i].x * cellSize, body[i].y * cellSize, cellSize, cellSize, darkGreen);
            }
        }
        void UpdateDir(){
            body.pop_back();
            body.push_front(Vector2Add(body[0], direction));
        }
};

class Apple {
    public:
        deque<Vector2> snakeBody;
        Vector2 position = generateRandomPos(snakeBody);
        void Draw() {
            DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);
        }
        Vector2 generateRandomPos(deque<Vector2> snakeBody) {
            float x = GetRandomValue(0, cellCount - 1);
            float y = GetRandomValue(0, cellCount - 1);
            Vector2 pos = Vector2{x, y};
            if (posExists(pos, snakeBody)) {
                return generateRandomPos(snakeBody);
            }
            return Vector2{x, y};
        }
};

class Game {
    public:
        Snake snake = Snake();
        Apple apple = Apple();

        void Draw() {
            apple.Draw();
            snake.Draw();   
        }
        void Update() {
            snake.UpdateDir();
            foodEaten();
            checkWallCollision();
            checkSelfCollision();
        }
        void foodEaten() {
            if (Vector2Equals(snake.body[0], apple.position)) {
                apple.position = apple.generateRandomPos(snake.body);
                snake.body.push_back(snake.body[snake.body.size() - 1]);
            }
        }
        void checkWallCollision() {
            if (snake.body[0].x < 0 || snake.body[0].x >= cellCount || snake.body[0].y < 0 || snake.body[0].y >= cellCount) {
                GameOver();
            }
        }
        void checkSelfCollision() {
            for (unsigned int i = 1; i < snake.body.size(); i++) {
                if (Vector2Equals(snake.body[0], snake.body[i])) {
                    GameOver();
                }
            }
        }
        void GameOver() {
            snake.body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
            snake.direction = Vector2{1, 0};
        }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Snake By Diogo");
    SetTargetFPS(120);

    Game game = Game();

    while(WindowShouldClose() == false) {
        BeginDrawing();
        if (eventTriggered(0.1)) {
            game.Update();
        }
        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
            game.snake.direction = Vector2{0, -1};
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
            game.snake.direction = Vector2{0, 1};
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
            game.snake.direction = Vector2{-1, 0};
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
            game.snake.direction = Vector2{1, 0};
        }
        ClearBackground(green);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#include "Game.h"



void Game::playGame() {
    const int FPS_VALUE = 60;
    InitWindow(2 * offset + (grid.Width), 2 * offset + (grid.Height), "Snake Game");
    SetTargetFPS(FPS_VALUE);

    while (!WindowShouldClose()) {
        BeginDrawing();

        if (eventTriggered(0.15)) {
            update();
        }

        if (IsKeyPressed(KEY_UP) && snake.GetYcoor() != 1) {
            snake.setDirection(0, -1);
            gameIsRunning = true;
        }
        if (IsKeyPressed(KEY_DOWN) && snake.GetYcoor() != -1) {
            snake.setDirection(0, 1);
            gameIsRunning = true;
        }
        if (IsKeyPressed(KEY_LEFT) && snake.GetXcoor() != 1) {
            snake.setDirection(-1, 0);
            gameIsRunning = true;
        }
        if (IsKeyPressed(KEY_RIGHT) && snake.GetXcoor() != -1) {
            snake.setDirection(1, 0);
            gameIsRunning = true;
        }

        ClearBackground(color.Getgreen());
        DrawRectangleLinesEx(Rectangle{ (float)offset - 5, (float)offset - 5, (float)grid.Width + 10, (float)grid.Width + 10 }, 5, color.GetdarkGreen());
        DrawText(TextFormat("%i", score), offset - 5, offset + grid.Width + 10, 40, color.GetdarkGreen());
        Draw();

        EndDrawing();
    }

    CloseWindow();
}


void Game::Draw() {
    food.Draw();
    snake.Draw();
}

void Game::update() {
    if (gameIsRunning) {
        snake.update();
        checkCollisionWithFood();
        checkCollisionWithEdges();
        checkCollisionWithTail();
    }
}

bool Game::eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdatetime >= interval) {
        lastUpdatetime = currentTime;
        return true;
    }
    return false;
}

void Game::gameOver() {
    snake.reset();
    food.setPosition(food.randomPosition(snake.getBody()));
    score = 0;
    gameIsRunning = false;
}

void Game::checkCollisionWithFood() {
    if (Vector2Equals(snake.getBody()[0], food.getPosition())) {
        food.setPosition(food.randomPosition(snake.getBody()));
        snake.setaddSegment(true);
        score++;
    }
}

void Game::checkCollisionWithEdges() {
    auto x_axis_collision = snake.getBody()[0].x == Grid().cellCount || snake.getBody()[0].x == -1;
    auto y_axis_collision = snake.getBody()[0].y == Grid().cellCount || snake.getBody()[0].y == -1;
    if (x_axis_collision || y_axis_collision) {
        gameOver();
    }
}

bool Game::check(Vector2 element, std::deque<Vector2> deq) {
    for (auto coordinate : deq) {
        if (Vector2Equals(coordinate, element)) {
            return true;
        }
    }
    return false;
}

void Game::checkCollisionWithTail() {
    std::deque<Vector2> tail = snake.getBody();
    tail.pop_front();
    if (check(snake.getBody()[0], tail)) {
        gameOver();
    }
}

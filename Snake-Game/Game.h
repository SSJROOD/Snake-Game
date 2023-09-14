#pragma once

#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <iostream>
#include <deque>
#include "Colors.h"
#include "Grid.h"
#include "Snake.h"
#include "Food.h"
#include "raylib.h"
#include <deque>

class Game {
public:
    void playGame();
private:
    Grid grid;
    Colors color;
    int score = 0;
    Snake snake;
    Food food = Food(snake.getBody());
    bool gameIsRunning = true;
    const int offset = 75;
    void Draw();
    void update();
    double lastUpdatetime;
    bool eventTriggered(double interval);
    void gameOver();
    void checkCollisionWithFood();
    void checkCollisionWithEdges();
    bool check(Vector2 element, std::deque<Vector2> deq);
    void checkCollisionWithTail();
};
#endif
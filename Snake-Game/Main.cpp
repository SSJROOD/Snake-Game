
#include <raylib.h>
#include <iostream>
#include <deque>
#include "Colors.h"
#include "Grid.h"
#include "Snake.h"
#include "Food.h"



int main()
{
    Colors color;
    const int FPS_VALUE = 60;
    InitWindow(Grid().Width, Grid().Height, "Snake Game");

    SetTargetFPS(FPS_VALUE);
    Food food = Food();
    Snake snake = Snake();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(color.Getgreen());
        food.Draw();
        snake.Draw();

        EndDrawing();
    }

    CloseWindow();


    return 0;
}


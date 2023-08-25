
#include "raylib.h"
#include <iostream>

int main()
{
    const int FPS_VALUE = 60;
    InitWindow(750,750,"Snake Game");

    SetTargetFPS(FPS_VALUE);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();


    return 0;
}


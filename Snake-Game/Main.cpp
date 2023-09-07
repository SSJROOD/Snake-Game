
#include "raylib.h"
#include <iostream>
#include <deque>
#include "Colors.h"
#include "Grid.h"


class Snake {
public:
    Grid grid;
    Colors color;
    std::deque<Vector2> snake = { Vector2{6,9},Vector2{5,9} };

    void Draw()
    {
        for (auto& body : snake)
        {
            int xcoor = body.x;
            int ycoor = body.y;
            DrawRectangle(xcoor * grid.cellSize,ycoor*grid.cellSize,grid.cellSize, grid.cellSize,color.darkGreen);

        }
    }
};



class Food{
public: 
    Grid grid;
    Vector2 position;
    Texture2D texture;

    Food() {
        Image image = LoadImage("apple2.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = randomPosition();
    }
    ~Food() {
        UnloadTexture(texture);
    }
    void Draw()
    {
        DrawTexture(texture,position.x * grid.cellSize, position.y * grid.cellSize, WHITE);
    }
    Vector2 randomPosition()
    {
        float xCoord = GetRandomValue(0, grid.cellCount - 1);
        float yCoord = GetRandomValue(0, grid.cellCount - 1);
        return { xCoord,yCoord };
    }
};


int main()
{
    const int FPS_VALUE = 60;
    InitWindow(Grid().Width, Grid().Height, "Snake Game");

    SetTargetFPS(FPS_VALUE);
    Food food = Food();
    Snake snake = Snake();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(Colors().green);
        food.Draw();
        snake.Draw();

        EndDrawing();
    }

    CloseWindow();


    return 0;
}


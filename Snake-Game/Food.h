#include "Grid.h"
#include <raylib.h>

class Food {
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
        DrawTexture(texture, position.x * grid.cellSize, position.y * grid.cellSize, WHITE);
    }
    Vector2 randomPosition()
    {
        float xCoord = GetRandomValue(0, grid.cellCount - 1);
        float yCoord = GetRandomValue(0, grid.cellCount - 1);
        return { xCoord,yCoord };
    }
};
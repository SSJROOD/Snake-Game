#include "Colors.h"
#include "Grid.h"
#include <deque>

class Snake {
public:
    void Draw()
    {
        for (auto& body : snake)
        {
            int xcoor = body.x;
            int ycoor = body.y;
            DrawRectangle(xcoor * grid.cellSize, ycoor * grid.cellSize, grid.cellSize, grid.cellSize, color.darkGreen);
        }
    }
private:
    Grid grid;
    Colors color;
    std::deque<Vector2> snake = { Vector2{6,9},Vector2{5,9} };
};
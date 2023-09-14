#include "Snake.h"

void Snake::reset()
{
    Body = { Vector2{6,9},Vector2{5,9} };
    direction = { 1,0 };
}

Snake::Snake()
{
    Body = { Vector2{6,9},Vector2{5,9} };
    addSegment = false;
}

void Snake::Draw() {
    for (auto& body : Body) {
        int xcoor = static_cast<int>(body.x);
        int ycoor = static_cast<int>(body.y);
        DrawRectangle(75+ xcoor * grid.cellSize,75 + ycoor * grid.cellSize, grid.cellSize, grid.cellSize, color.GetdarkGreen());
    }
}

void Snake::update() {
    Body.push_front(Vector2Add(Body[0], direction));

    if (addSegment) addSegment = false;
    else  Body.pop_back();
}

void Snake::setDirection(float x, float y) {
    direction.x = x;
    direction.y = y;
}

void Snake::setaddSegment(bool val)
{
    addSegment = val;
}

float Snake::GetXcoor() const {
    return direction.x;
}

float Snake::GetYcoor() const {
    return direction.y;
}

const std::deque<Vector2>& Snake::getBody() const {
    return Body;
}

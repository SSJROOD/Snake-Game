#ifndef SNAKE_H
#define SNAKE_H

#include "Colors.h"
#include "Grid.h"
#include <deque>
#include "raymath.h"

class Snake {
public:
    void reset();
    Snake();
    void Draw();
    void update();
    void setDirection(float x, float y);
    void setaddSegment(bool);
    float GetXcoor() const;
    float GetYcoor() const;
    const std::deque<Vector2>& getBody() const;

private:
    Grid grid;
    Colors color;
    std::deque<Vector2> Body;
    Vector2 direction;
    bool addSegment;
};

#endif

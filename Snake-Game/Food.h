#ifndef FOOD_H
#define FOOD_H
#include "Grid.h"
#include <deque>
#include <raylib.h>
#include <raymath.h>

class Food {
    private:
    Grid grid;
    Vector2 position;
    Texture2D texture;
public:
    
    Food(std::deque<Vector2> snake);

    Vector2 randomPosition(std::deque<Vector2> snake);

    bool elementinDeque(Vector2 element, std::deque<Vector2> deq);
 
    void Draw();

    Vector2 positionHelper();

    Vector2 getPosition()const;

    void setPosition(Vector2 position);
};

#endif
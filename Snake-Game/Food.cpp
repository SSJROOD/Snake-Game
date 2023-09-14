#include "Food.h"



Food::Food(std::deque<Vector2> snake)
{
    position = randomPosition(snake);
}




Vector2 Food::positionHelper()
{
    float xCoord = static_cast<float>(GetRandomValue(0, grid.cellCount - 1));
    float yCoord = static_cast<float>(GetRandomValue(0, grid.cellCount - 1));

    return Vector2{ xCoord,yCoord };
}

bool Food::elementinDeque(Vector2 element, std::deque<Vector2> deq)
{
    for (auto coordinate : deq)
    {
        if (Vector2Equals(coordinate, element))  return true;
    }
    return false;
}

Vector2 Food::randomPosition(std::deque<Vector2> snake)
{
    Vector2 position = positionHelper();
    while (elementinDeque(position, snake))
    {
        position = positionHelper();
    }
    return position;

}

Vector2 Food::getPosition()const
{
    return position;
}

void Food::Draw()
{
    int posX = static_cast<int>(75 + position.x * grid.cellSize);
    int posY = static_cast<int>(75 + position.y * grid.cellSize);
    DrawCircle(posX + grid.cellSize / 2, posY + grid.cellSize / 2, static_cast<float>(grid.cellSize / 2), RED);
}

void Food::setPosition(Vector2 position) {
    this->position = position;
}
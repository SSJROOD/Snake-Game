#ifndef GRID_H
#define GRID_H

class Grid
{
public:
    int cellSize = 30;
    int cellCount = 25;
    const int Width = (cellCount * cellSize);
    const int Height = (cellCount * cellSize);
};

#endif

#ifndef COLORS_H
#define COLORS_H
#include "raylib.h"

class Colors {
public:
    Colors() {};
    Color Getgreen() { return green; }
    Color GetdarkGreen() { return darkGreen; }

private:
    Color green = { 173, 204, 96, 255 };
    Color darkGreen = { 43,51,24,255 };
};

#endif 

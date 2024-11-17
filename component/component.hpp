#pragma once
#include "display.hpp"

typedef struct {
    int r;
    int g;
    int b;
} Color;

typedef struct {
    char value;
    Color color;
} Cell;

class Component {
    public:
        int x;
        int y;
        int width;
        int height;
        Cell** image;
        
        Component(int _x, int _y, int _width, int _height, Cell** _image);
        void changeImage(Cell** new_image);
        void draw(Display* Display);
};
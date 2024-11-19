#pragma once
#include "display.hpp"

class Component {
    public:
        int x;
        int y;
        int width;
        int height;
        Cell** image;
        
        Component(int _x, int _y, int _width, int _height, Cell** _image);
        void changeImage(Cell** new_image);
        void draw(Display* display);
};
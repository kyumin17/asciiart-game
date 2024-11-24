#include "component.hpp"

Component::Component(int _x, int _y, int _width, int _height, Cell** _image) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;

    image = new Cell*[height];
    for (int row = 0; row < height; row++) {
        image[row] = new Cell[width];
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            image[row][col] = _image[row][col];
        }
    }
}

void Component::changeImage(Cell** new_image) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            image[row][col] = new_image[row][col];
        }
    }
}

void Component::draw(Display* display) {
    int r = display -> height - y - height;
    int c = x;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (image[row][col].value == ' ') continue;
            display -> screen[row + r][col + c].value = image[row][col].value;
            display -> screen[row + r][col + c].color = image[row][col].color;
        }
    }
}
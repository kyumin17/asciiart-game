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

void Component::draw(Display* Display) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Display -> display[row + x][col + y] = image[row][col];
        }
    }
}
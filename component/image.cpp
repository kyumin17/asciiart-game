#include "image.hpp"

Image::Image(int _width, int _height) {
    width = _width;
    height = _height;
};

void Image::allocateCell(Cell** cell) {
    cell = new Cell*[height];
    for (int row = 0; row < height; row++) {
        cell[row] = new Cell[width];
    }
}

void PlayerImage::putValue(Cell** cell, char image[3][4], int color[3]) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            cell[row][col].value = image[row][col];
            cell[row][col].color = {color[0], color[1], color[2]};
        }
    }
}

PlayerImage::PlayerImage(): Image(4, 3) {
    int white[] = {255, 255, 255};

    char standImage[3][4] = {
        " o ",
        "/|\\",
        "/ \\"
    };

    char downImage[3][4] = {
        "   ",
        " o ",
        "_|_"
    };

    char jumpImage[3][4] = {
        " o ",
        "-|-",
        "/ \\"
    };

    char attackImage[3][4] = {
        " o ",
        "/|=",
        "/ \\"
    };

    allocateCell(stand);
    allocateCell(down);
    allocateCell(jump);
    allocateCell(attack);

    putValue(stand, standImage, white);
    putValue(down, downImage, white);
    putValue(jump, jumpImage, white);
    putValue(attack, attackImage, white);
}
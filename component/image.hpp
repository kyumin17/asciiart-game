#pragma once
#include "display.hpp"

class Image {
    public:
        int height;
        int width;
        Image(int _width, int _height);
        void allocateCell(Cell** cell);
};

class PlayerImage: Image {
    public:
        Cell** stand;
        Cell** down;
        Cell** jump;
        Cell** attack;
        Cell** jump_attack;
        PlayerImage();
        void putValue(Cell** cell, char image[3][4], int color[3]);
};

class EnemyImage: Image {
    public:

};

class ProjectileImage: Image {
    public:

};
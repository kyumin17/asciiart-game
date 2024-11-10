#pragma once
#include <png.h>

struct Pixel {
	png_byte r, g, b, a;
};

struct ImageInfo {
	int width, height;
	Pixel** image;
};

typedef enum {
    PLAYER,
    ENEMY,
    ATTACK,
    BLOCK,
    EMPTY,
    BACKGROUND,
} Attr;

typedef enum {
    WHITE,
    RED,
    GREEN,
    BLUE,
} Color;

struct Cell {
    Attr attr;
    char value;
    Color color;
};

struct Element {
	int width, height;
	Cell** image;
};

class Player {
    public:
        int HP;
        int STR;
};

class Enemy {
    public:
        int HP;
        int STR;
};
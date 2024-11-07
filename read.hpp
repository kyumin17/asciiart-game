#pragma once
#include <png.h>
#include <ncurses.h>
#include <stdlib.h>

struct Pixel {
	png_byte r, g, b, a;
};

struct ImageInfo {
	int width, height;
	Pixel** image;
};

typedef enum {
    RED,
    GREEN,
    BLUE,
} Color;

typedef enum {
    PLAYER,
    ENEMY,
    BLOCK,
    EMPTY,
} Attr;

struct Cell {
    Attr attr;
    char value;
};

struct Element {
	int width, height;
	Cell** image;
};

bool readImage(char* file_name, ImageInfo* image_info);

void compressImage(int com_width, ImageInfo* compress_image_info, ImageInfo* image_info);

void imageToElement(Element* element, Attr attr, char c, ImageInfo* image_info);
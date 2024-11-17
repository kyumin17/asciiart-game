#pragma once
#include <png.h>
#include <ncurses.h>
#include <stdlib.h>
#define HEIGHT 30
#define WIDTH 130

struct Pixel {
	png_byte r, g, b, a;
};

struct ImageInfo {
	int width, height;
	Pixel** image;
};

bool readImage(const char* fn, ImageInfo* image_info);

void makeElement();
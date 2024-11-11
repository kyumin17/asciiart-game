#pragma once
#include <png.h>
#include <ncurses.h>
#include <stdlib.h>
#include "element.hpp"

struct Pixel {
	png_byte r, g, b, a;
};

struct ImageInfo {
	int width, height;
	Pixel** image;
};

class Image {
    public:
        const char* fn;
        Image(const char* file_name);
        ImageInfo* readImage();
        ImageInfo* compressImage(int width);
        Element* imageToElement(int width, char c);
};
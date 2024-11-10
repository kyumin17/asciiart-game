#pragma once
#include <png.h>
#include <ncurses.h>
#include <stdlib.h>
#include "attribute.hpp"

class Image {
    public:
        const char* fn;
        Image(const char* file_name);
        ImageInfo* readImage();
        ImageInfo* compressImage(int width);
        Element* imageToElement(int width, Attr attr, char c);
};
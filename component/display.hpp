#pragma once
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "component.hpp"
#define ms 1000

enum Key { W, A, S, D, J, I, Q };

class Display {
    public:
        int width;
        int height;
        Cell** display;
        Display(int _width, int _height);
        void printDisplay();
        std::string getInput();
};
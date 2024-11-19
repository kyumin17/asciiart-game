#pragma once
#include <string>
#include <ncurses.h>
#include <unistd.h>
#define ms 1000

typedef struct {
    char value;
    int color;
} Cell;

enum Key { W, A, S, D, J, I, Q };

typedef struct {
    std::string attackDirection;
    std::string moveDirection;
    bool isAttack;
    bool isQuit;
} Input;

class Display {
    public:
        int width;
        int height;
        Cell** screen;
        Display(int _width, int _height);
        void printDisplay();
        void initDisplay();
        Input getInput();
};
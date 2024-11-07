#pragma once
#include <ncurses.h>

#define WIDTH 60
#define HEIGHT 30

typedef enum {
    PLAYER, // move by key input
    ENEMY, // attack player
    BLOCK, // player cannot go but not attack
    EMPTY, // player can go
} Attr;

struct Cell {
    Attr attr;
    char value;
};

void printBoard(Cell** board);
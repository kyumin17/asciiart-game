#pragma once
#include <ncurses.h>
#include "attribute.hpp"

#define WIDTH 130
#define HEIGHT 30

void printBoard(Cell** board);

void updateBoard(int x, int y, Cell** board);

void manipulatePlayer(int& x, int& y, char command);

void insertElement(int x, int y, Element* element, Cell** board);
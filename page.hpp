#pragma once
#include "player.hpp"
#include <ncurses.h>
#define WIDTH 130
#define HEIGHT 30

typedef enum { L, R, J, D, A, Q } KeyInput;

int printStartPage();

int printStagePage();

Direction getInput();

void printStage1Page();

void printStage2Page();

void printStage3Page();

void printClearPage();

void printDeathPage();
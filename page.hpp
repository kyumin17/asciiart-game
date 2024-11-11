#pragma once
#include <ncurses.h>
#define WIDTH 130
#define HEIGHT 30

typedef enum { WHITE, RED, GREEN, BLUE } Color;

int printStartPage();

int printStagePage();

void printStage1Page();

void printStage2Page();

void printStage3Page();

void printClearPage();

void printDeathPage();
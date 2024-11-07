#include "game.hpp"

void printBoard(Cell** board) {
    clear();

    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printw("%c ", board[row][col].value);
        }
        printw("\n");
    }

    refresh();
}
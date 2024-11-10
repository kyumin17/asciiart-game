#include "game.hpp"

void insertElement(int r, int c, Element* element, Cell** board) {
    for (int row = 0; row < element -> height; row++) {
        for (int col = 0; col < element -> width; col++) {
            board[row + r][col + c] = element -> image[row][col];
        }
    }
}

void updateBoard(int x, int y, Cell** board) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            board[row][col].value = ' ';
            board[row][col].attr = EMPTY;
            board[row][col].color = WHITE;
        }
    }

    for (int col = 0; col < WIDTH; col++) {
        board[HEIGHT - 1][col].value = '_';
        board[HEIGHT - 1][col].attr = BLOCK;
    }

    board[y][x].value = 'P';
    board[y][x].attr = PLAYER;
}

void manipulatePlayer(int& x, int& y, char command) {
    if (command == 'w' && y >= 1) {
        y--; //jump
    } else if (command == 'a' && x >= 1) {
        x--; //left
    } else if (command == 's' && y < HEIGHT - 1) {
        y++; //down
    } else if (command == 'd' && x < WIDTH - 1) {
        x++; //right
    }
}

void printBoard(Cell** board) {
    clear();

    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            Cell cell = board[row][col];
            attron(COLOR_PAIR(cell.color));
            printw("%c", cell.value);
        }
        printw("\n");
    }

    refresh();
}
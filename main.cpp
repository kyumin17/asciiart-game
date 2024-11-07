#include "read.hpp"
#include "game.hpp"
#include <unistd.h>

int main(int argc, char *argv[]) {
	initscr();
	noecho();
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	/*
	int max_y, max_x;
	getmaxyx(stdscr, max_y, max_x);
	if (max_y < HEIGHT || max_x < WIDTH) {
		printw("Please size up your window for better play!");
	}
	*/

	Cell** board = new Cell*[HEIGHT];
	for (int i = 0; i < HEIGHT; i++) {
		board[i] = new Cell[WIDTH];
	}

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			board[i][j].value = ' ';
			board[i][j].attr = EMPTY;
		}
	}

	for (int col = 0; col < WIDTH; col++) {
        board[HEIGHT - 1][col].value = '_';
		board[HEIGHT - 1][col].attr = BLOCK;
    }

	int x = 0;
	int y = HEIGHT - 1;
	board[y][x].value = 'P';

	printBoard(board);
	char command;
	while ((command = getch()) != 'q') {
		if (command == 'a' && x >= 1) {
			board[y][x].value = '_';
			board[y][--x].value = 'P';
		} else if (command == 'd' && x < WIDTH - 1) {
			board[y][x].value = '_';
			board[y][++x].value = 'P';
		} else if (command == ' ' && y >= 1) {
			board[y][x].value = '_';
			board[--y][x].value = 'P';
		}
		printBoard(board);
	}

	for (int i = 0; i < HEIGHT; i++) {
		delete[] board[i];
	}
	delete[] board;

	endwin();
	return 0;
}
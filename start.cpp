#include "start.hpp"

void checkWindowSize() {
    /*
    if window size is small to play, request to resize window
    */

	int max_y, max_x; //함수 다시짜야함
	getmaxyx(stdscr, max_y, max_x);
	while (max_y > HEIGHT * 16 && max_x > WIDTH * 16) {
        clear();
		printw("Please size up your window for better play");
        refresh();
	}
}

bool printStartPage() {
    /*
    float start page
    when enter 'Enter' key, return true(start)
    when enter 'q' key, return false(quit)
    */

    char** board = new char*[HEIGHT];

	for (int row = 0; row < HEIGHT; row++) {
		board[row] = new char[WIDTH];
	}

	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {
			board[row][col] = ' ';
		}
	}

	for (int col = 0; col < WIDTH; col++) {
		board[0][col] = '#';
		board[HEIGHT - 1][col] = '#';
	}

    char command = ' ';

    while (command != 'q' && command != '\n') {
        clear();

        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                printw("%c", board[row][col]);
            }
            printw("\n");
        }

        move(10, 56);
        printw("--------");
        move(11, 56);
        printw("WELCOME!");
        move(12, 56);
        printw("--------");

        move(18, 49);
        printw("> Press Enter to start");
        move(20, 49);
        printw("> Press q to quit");

        command = getch();

        refresh();
    }

    for (int row = 0; row < HEIGHT; row++) {
		delete[] board[row];
	}
	delete[] board;

    if (command == '\n') {
        return true; //play game
    } else {
        return false; //quit game
    }
}
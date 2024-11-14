#include "page.hpp"

int main(int argc, char *argv[]) {
	typedef enum { WHITE, RED, GREEN, BLUE } Color;

	/* initial setting */
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();
	cbreak();
	init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(RED, COLOR_RED, COLOR_BLACK);
	init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);

	/* game */
	int stage = 0;
	if (printStartPage()) {
		clear();
		stage = printStagePage();
	}

	clear();
	switch(stage) {
		case 1:
			printStage1Page();
			break;
		case 2:
			printStage2Page();
			break;
		case 3:
			printStage3Page();
			break;
	}

	endwin();
	
	return 0;
}
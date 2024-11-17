#include <ncurses.h>
#include "./page/page.hpp"

int main(int argc, char *argv[]) {

	/* initial setting */
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	cbreak();
	start_color();

	/* game */
	int stage = 0;
	if (printStartPage()) {
		clear();
		stage = printStageSelectPage();
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
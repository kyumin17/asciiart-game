#include "game.hpp"
#include "start.hpp"
#include "attribute.hpp"
#include "image.hpp"
#include <unistd.h>

int main(int argc, char *argv[]) {

	/* initial setting */
	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(RED, COLOR_RED, COLOR_BLACK);
	init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
	checkWindowSize();

	/* game */
	Cell** board = new Cell*[HEIGHT];
	for (int row = 0; row < HEIGHT; row++) {
		board[row] = new Cell[WIDTH];
	}

    Image image("./image/boss/ghost/B1D.png");
    Element* ghost_default = new Element;
	//세그폴트 디버깅해야 함ㅜㅜ
    //ghost_default = image.imageToElement(29, ENEMY, '*');
	//insertElement(0, 0, ghost_default, board);
	
	char command = ' ';
	int px = 0;
	int py = HEIGHT - 1;

	if (printStartPage()) {
		while (command != 'Q') {
			clear();
			//이거 나중에 키입력에 따라 while문 돌리는게 아니라 sleep써서 시간에 따라 프레임으로 돌려야함
			//보스 움직임이 프레임으로 움직여야해서
			updateBoard(px, py, board);
			printBoard(board);
			command = getch();
			manipulatePlayer(px, py, command);
			refresh();
		}
	}

    for (int row = 0; row < HEIGHT; row++) {
		delete[] board[row];
	}
	delete[] board;

	endwin();
	return 0;
}
#include <ncurses.h>
#include <unistd.h>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30
#define ms 1000

int printStartPage() {
    /*
    시작 페이지
    Q(종료)를 누르면 0을 반환하고, 엔터(시작)를 누르면 1을 반환
    */

    char input = ' ';

    while (input != 'Q' && input != '\n') {
        usleep(10 * ms);

        //시작 페이지
        mvprintw(8, 56, "--------");
        mvprintw(9, 56, "GAMEGAME");
        mvprintw(10, 56, "--------");

        mvprintw(15, 49, "> Press Enter to start");
        mvprintw(17, 49, "> Press Shift + q to quit");

        mvprintw(22, 50, "W: jump        S: down");
        mvprintw(23, 50, "A: left        D: right");

        input = getch();

        refresh();
    }

    if (input == '\n') {
        return 1; //play game
    } else {
        return 0; //quit game
    }
}
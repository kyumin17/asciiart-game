#include <ncurses.h>
#include <unistd.h>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30
#define ms 1000

int printStageSelectPage() {
    /*
    스테이지 페이지
    Q를 누르면 0을 반환하고, 엔터를 누르면 해당 스테이지로 이동
    W와 D키로 스테이지 변경 가능
    */

    int selectStage = 1;
    char input = ' ';
    while (input != 'Q' && input != '\n') {
        usleep(10 * ms);
        input = getch();

        switch(input) {
            case 'w':
                if (selectStage != 1) {
                    selectStage--;
                }
                break;
            case 's':
                if (selectStage != 3) {
                    selectStage++;
                }
                break;
        }

        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        
        switch (selectStage) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(13, 61, "> Stage 1");
                attroff(COLOR_PAIR(1));
                mvprintw(15, 61, "  Stage 2");
                mvprintw(17, 61, "  Stage 3");
                break;
            case 2:
                mvprintw(13, 61, "  Stage 1");
                attron(COLOR_PAIR(1));
                mvprintw(15, 61, "> Stage 2");
                attroff(COLOR_PAIR(1));
                mvprintw(17, 61, "  Stage 3");
                break;
            case 3:
                mvprintw(13, 61, "  Stage 1");
                mvprintw(15, 61, "  Stage 2");
                attron(COLOR_PAIR(1));
                mvprintw(17, 61, "> Stage 3");
                attroff(COLOR_PAIR(1));
                break;
        }
        
        refresh();
    }

    if (input == '\n') {
        return selectStage; //go to stage
    } else {
        return 0; //quit
    }
}
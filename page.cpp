#include "page.hpp"
#include <unistd.h>
#define ms 1000

int printStartPage() {
    /*
    float start page
    when enter 'Enter' key, return true(start)
    when enter 'q' key, return false(quit)
    */

    char border[WIDTH + 1];
    for (int i = 0; i < WIDTH; i++) border[i] = '#';
    border[WIDTH] = '\0';

    char command = ' ';

    while (command != 'Q' && command != '\n') {
        usleep(10 * ms);
        mvprintw(0, 0, border);

        mvprintw(8, 56, "--------");
        mvprintw(9, 56, "GAMEGAME");
        mvprintw(10, 56, "--------");

        mvprintw(15, 49, "> Press Enter to start");
        mvprintw(17, 49, "> Press Shift + q to quit");

        mvprintw(22, 50, "W: jump        S: down");
        mvprintw(23, 50, "A: left        D: right");

        mvprintw(HEIGHT - 1, 0, border);

        command = getch();

        refresh();
    }

    if (command == '\n') {
        return 1; //play game
    } else {
        return 0; //quit game
    }
}

int printStagePage() {
    /*
    float stage selecting page
    when enter 'Enter' key, return selected stage(start)
    when enter 'q' key, return 0(quit)
    select stage with 'w'(up) and 's'(down) key
    */

    char border[WIDTH + 1];
    for (int i = 0; i < WIDTH; i++) border[i] = '#';
    border[WIDTH] = '\0';

    int selectStage = 1;
    char command = ' ';
    while (command != 'Q' && command != '\n') {
        usleep(10 * ms);
        command = getch();

        switch(command) {
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
        
        mvprintw(0, 0, border);
        switch (selectStage) {
            case 1:
                attron(COLOR_PAIR(RED));
                mvprintw(13, 61,"> Stage 1");
                attroff(COLOR_PAIR(RED));
                mvprintw(15, 61,"  Stage 2");
                mvprintw(17, 61,"  Stage 3");
                break;
            case 2:
                mvprintw(13, 61,"  Stage 1");
                attron(COLOR_PAIR(RED));
                mvprintw(15, 61,"> Stage 2");
                attroff(COLOR_PAIR(RED));
                mvprintw(17, 61,"  Stage 3");
                break;
            case 3:
                mvprintw(13, 61,"  Stage 1");
                mvprintw(15, 61,"  Stage 2");
                attron(COLOR_PAIR(RED));
                mvprintw(17, 61,"> Stage 3");
                attroff(COLOR_PAIR(RED));
                break;
        }
        mvprintw(HEIGHT - 1, 0, border);
        
        refresh();
    }

    if (command == '\n') {
        return selectStage; //go to stage
    } else {
        return 0; //quit
    }
}

void printStage1Page() {
    char command = ' ';
    while (command != 'Q') {
        usleep(10 * ms);
        command = getch();
        //implement stage 2
        refresh();
    }
}

void printStage2Page() {
    char command = ' ';
    while (command != 'Q') {
        usleep(10 * ms);
        command = getch();
        //implement stage 2
        refresh();
    }
}

void printStage3Page() {
    char command = ' ';

    while (command != 'Q') {
        usleep(10 * ms);
        command = getch();
        //implement stage 3
        refresh();
    }
}

void printClearPage() {

}

void printDeathPage() {
    
}
#include "page.hpp"
#include <unistd.h>
#define ms 1000
typedef enum { WHITE, RED, GREEN, BLUE } Color;

int printStartPage() {
    /*
    시작 페이지
    Q(종료)를 누르면 0을 반환하고, 엔터(시작)를 누르면 1을 반환
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
    스테이지 페이지
    Q를 누르면 0을 반환하고, 엔터를 누르면 해당 스테이지로 이동
    W와 D키로 스테이지 변경 가능
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
                mvprintw(13, 61, "> Stage 1");
                attroff(COLOR_PAIR(RED));
                mvprintw(15, 61, "  Stage 2");
                mvprintw(17, 61, "  Stage 3");
                break;
            case 2:
                mvprintw(13, 61, "  Stage 1");
                attron(COLOR_PAIR(RED));
                mvprintw(15, 61, "> Stage 2");
                attroff(COLOR_PAIR(RED));
                mvprintw(17, 61, "  Stage 3");
                break;
            case 3:
                mvprintw(13, 61, "  Stage 1");
                mvprintw(15, 61, "  Stage 2");
                attron(COLOR_PAIR(RED));
                mvprintw(17, 61, "> Stage 3");
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

Direction getInput() {
    /*
    10ms동안 키 입력을 받고 입력 키에 따라 해당하는 방향을 반환함
    */

    //키 동시 입력 지원
    char command;
    int isPressed[6] = {0, 0, 0, 0, 0, 0}; //10ms동안 입력된 키를 저장
    for (int i = 0; i < 20; i++) {
        command = getch();
        switch(command) {
            case 'a':
                isPressed[L] = 1;
                break;
            case 'd':
                isPressed[R] = 1;
                break;
            case ' ':
                isPressed[J] = 1;
                break;
            case 's':
                isPressed[D] = 1;
                break;
            case 'i':
                isPressed[A] = 1;
                break;
            case 'q':
                isPressed[Q] = 1;
                break;
        }
        usleep(500);
    }
    
    //입력 키에 따라 방향을 결정
    Direction dir = NONE;
    if (isPressed[Q]) {
        dir = QUIT;
    } else if ((isPressed[J] && isPressed[D]) || (isPressed[L] && isPressed[R])) {
        dir = NONE;
    } else if (isPressed[L] && isPressed[J]) {
        dir = LEFTJUMP;
    } else if (isPressed[R] && isPressed[J]) {
        dir = RIGHTJUMP;
    } else if (isPressed[L] && isPressed[D]) {
        dir = LEFTDOWN;
    } else if (isPressed[R] && isPressed[D]) {
        dir = RIGHTDOWN;
    } else if (isPressed[L]) {
        dir = LEFT;
    } else if (isPressed[R]) {
        dir = RIGHT;
    } else if (isPressed[J]) {
        dir = JUMP;
    } else if (isPressed[D]) {
        dir = DOWN;
    }

    return dir;
}

void printStage1Page() {

    Player player(5, 10, 3, 3, HEIGHT - 4, 0);
    char board[HEIGHT][WIDTH];

    while (1) {
        Direction dir = getInput();
        if (dir == QUIT) break;

        player.move(dir);
        
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                board[row][col] = ' ';
            }
        }

        for (int col = 0; col < WIDTH; col++) {
            board[HEIGHT - 1][col] = '=';
        }

        for (int i = 0; i < player.height; i++) {
            for (int j = 0; j < player.width; j++) {
                board[player.x + i][player.y + j] = player.character[i][j];
            }
        }

        move(0, 0);
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                printw("%c", board[row][col]);
            }
            printw("\n");
        }

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
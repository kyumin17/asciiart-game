#include "display.hpp"

Display::Display(int _width, int _height) {
    width = _width;
    height = _height;

    display = new Cell*[height];
    for (int row = 0; row < height; row++) {
        display[row] = new Cell[width];
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            display[row][col].value = ' ';
            display[row][col].color = {0, 0, 0};
        }
    }
}

void Display::printDisplay() {
    float scale = 3.9; //ncurses color num / rgb color num
    move(0, 0);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Cell cell = display[row][col];
            init_color(1, cell.color.r * scale, cell.color.g * scale, cell.color.b * scale);
            init_pair(1, 1, COLOR_BLACK);
            attron(COLOR_PAIR(1));
            printw("%c", cell.value);
            attroff(COLOR_PAIR(1));
        }
        printw("\n");
    }
}

std::string Display::getInput() {
    /*
    10ms동안 키 입력을 받고 입력 키에 따른 명령어를 반환
    */

    //키 동시 입력
    char input;
    bool isPressed[7] = {false, }; //키 입력 여부 확인
    for (int i = 0; i < 10; i++) {
        input = getch();
        switch(input) {
            case 'w':
                isPressed[W] = true; //up
                break;
            case 'a':
                isPressed[A] = true; //left
                break;
            case 's':
                isPressed[S] = true; //down
                break;
            case 'd':
                isPressed[D] = true; //right
                break;
            case ' ':
                isPressed[J] = true; //jump
                break;
            case 'i':
                isPressed[I] = true; //attack
                break;
            case 'q':
                isPressed[Q] = true; //quit
                break;
        }
        usleep(ms);
    }

    std::string command = "none";
    
    if (isPressed[Q]) {
        command = "quit";
    } else if ((isPressed[S] && isPressed[W]) || (isPressed[A] && isPressed[D])) {
        command = "none";
    }
    //not complete

    return command;
}

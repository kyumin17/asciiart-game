#include "display.hpp"

Display::Display(int _width, int _height) {
    width = _width;
    height = _height;

    screen = new Cell*[height];
    for (int row = 0; row < height; row++) {
        screen[row] = new Cell[width];
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            screen[row][col].value = ' ';
            screen[row][col].color = COLOR_WHITE;
        }
    }
}

void Display::printDisplay() {
    move(0, 0);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Cell cell = screen[row][col];
            init_pair(cell.color, cell.color, COLOR_BLACK);
            attron(COLOR_PAIR(cell.color));
            printw("%c", cell.value);
            attroff(COLOR_PAIR(cell.color));
        }
        printw("\n");
    }

    move(29, 0);
    for (int col = 0; col < width; col++) {
        printw("%c", '=');
    }
}

void Display::initDisplay() {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            screen[row][col].value = ' ';
            screen[row][col].color = COLOR_WHITE;
        }
    }
}

Input Display::getInput() {
    /*
    10ms동안 키 입력을 받고 입력 키에 따른 명령어를 반환
    */

    //키 동시 입력
    char key;
    bool isPressed[7] = {false, }; //키 입력 여부 확인
    for (int i = 0; i < 10; i++) {
        key = getch();
        switch(key) {
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

    Input input;

    input.isQuit = false;
    input.isAttack = false;
    input.attackDirection = "  ";
    input.moveDirection = "  ";

    if (isPressed[I]) input.isAttack = true;
    if (isPressed[Q]) input.isQuit = true;
    
    if (!(isPressed[S] && isPressed[W]) && !(isPressed[A] && isPressed[D])) {
        if (isPressed[W]) {
            input.attackDirection[0] = 'w'; //up
        }
        if (isPressed[S]) {
            input.moveDirection[0] = 's'; //down
        }
        if (isPressed[J]) {
            input.moveDirection[0] = 'j'; //jump
        }
        if (isPressed[A]) {
            input.attackDirection[1] = 'a'; //left
            input.moveDirection[1] = 'a';
        }
        if (isPressed[D]) {
            input.attackDirection[1] = 'd'; //right
            input.moveDirection[1] = 'd';
        }
    }

    return input;
}
#include "page.hpp"

void printStage1Page() {
    Display display(130, 30);
    PlayerImage playerImage;
    EnemyImage enemyImage;
    Player player(3, 25, 8, 5, 4, playerImage.stand);
    Enemy enemy(100, 10, 0, 50, enemyImage.width, enemyImage.height, enemyImage.stand);
    Input input;
    input.isQuit = false;
    Bullet* bulletArr[300];
    int bulletNum = 0;
    
    while (!input.isQuit && player.hp != 0 && enemy.hp != 0) {
        display.initDisplay();
        input = display.getInput();

        player.move(input.moveDirection, playerImage);
        player.attack(input.isAttack, input.attackDirection, playerImage);
        player.draw(&display);
        enemy.attack(&player);
        enemy.draw(&display);

        for (int i = 0; i < bulletNum; i++) {
            bulletArr[i] -> move();
            bulletArr[i] -> draw(&display);
        }

        display.printDisplay();

        //print player hp
        printw("\n\n  HP: ");
        for (int i = 0; i < player.hp; i++) {
            addch(ACS_CKBOARD);
            printw(" ");
        }

        //print enemy hp
        move(1, 61);
        printw("BOSSNAME");
        move(3, 15);
        for (int i = 0; i < enemy.hp; i++) {
            addch(ACS_CKBOARD);
        }

        refresh();
    }

    if (player.hp == 0) {
        char key;
        while (key != '\n') {
            key = getch();
            mvprintw(15, 44, "An enemy has had a feast after a long time.");
            mvprintw(17, 63, "Retry?");
            usleep(10 * ms);
        }
    }

    if (enemy.hp == 0) {
        char key;
        while (key != '\n') {
            key = getch();
            mvprintw(17, 55, "You are alive");
            usleep(10 * ms);
        }
    }
}
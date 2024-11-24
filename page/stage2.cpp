#include "page.hpp"
#define MAXBULLET 300

void printStage2Page() {
    Display display(130, 30);
    PlayerImage playerImage;
    EnemyStage2Image enemyImage;
    BulletImage bulletImage;
    Player player(3, 3, 1, 5, 4, playerImage.stand);
    Enemy enemy(100, 1, 35, 0, enemyImage.width, enemyImage.height, enemyImage.stand);
    Input input;
    input.isQuit = false;
    Bullet* bulletArr[MAXBULLET];
    int bulletNum = 0;
    
    while (!input.isQuit && player.hp != 0 && enemy.hp != 0) {
        display.initDisplay();
        input = display.getInput();

        player.move(input.moveDirection, playerImage);
        enemy.attack(&player);
        enemy.draw(&display);
        player.attack(input.isAttack, bulletArr, bulletNum, input.attackDirection, playerImage, bulletImage.bullet);
        player.draw(&display);

        display.printDisplay();
        display.printBackground(player.hp, enemy.hp);

        refresh();
    }

    if (player.hp == 0) {
        char key;
        while (key != '\n') {
            key = getch();
            mvprintw(15, 44, "You have become a good fertilizer");
            mvprintw(17, 63, "Retry?");
            usleep(10 * ms);
        }
    }

    if (enemy.hp == 0) {
        char key;
        while (key != '\n') {
            key = getch();
            mvprintw(17, 55, "Delicious carrot soup!");
            mvprintw(19, 63, "Press enter");
            usleep(10 * ms);
        }
    }
}
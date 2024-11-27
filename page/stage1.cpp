#include "page.hpp"
#define MAXBULLET 300

void printStage1Page() {
    Display display(130, 30);
    PlayerImage playerImage;
    EnemyStage1Image enemyImage;
    BulletImage bulletImage;
    Player player(3, 3, 1, 5, 4, playerImage.stand);
    Enemy enemy(100, 1, 75, -3, enemyImage.width, enemyImage.height, 15, enemyImage.ghostList[0]);
    Input input;
    input.isQuit = false;
    Bullet* bulletArr[MAXBULLET];
    int bulletNum = 0;
    bulletArr[bulletNum++] = new Bullet(player.x + 5, player.y + 1, "ww", 1, 1, bulletImage.bullet);
    
    while (!input.isQuit && player.hp != 0 && enemy.hp != 0) {
        display.initDisplay();
        input = display.getInput();

        player.move(input.moveDirection, playerImage);
        enemy.moveStage1(enemyImage);
        enemy.attack(&player);
        enemy.draw(&display);
        player.attack(input.isAttack, bulletArr, bulletNum, input.attackDirection, playerImage, bulletImage.bullet);
        player.draw(&display);

        for (int i = 0; i < bulletNum; i++) {
            bulletArr[i] -> draw(&display);
        }

        display.printDisplay();
        display.printBackground(player.hp, enemy.hp, "GHOST");

        refresh();
    }

    if (player.hp == 0) {
        char key;
        while (key != '\n') {
            key = getch();
            mvprintw(15, 44, "You are dead");
            mvprintw(17, 63, "Retry?");
            usleep(10 * ms);
        }
    }

    if (enemy.hp == 0) {
        char key;
        while (key != '\n') {
            key = getch();
            mvprintw(17, 55, "clear");
            usleep(10 * ms);
        }
    }
}
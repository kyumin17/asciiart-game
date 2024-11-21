#include "image.hpp"

PlayerImage::PlayerImage() {
    char standImage[3][4] = {
        " o ",
        "/|\\",
        "/ \\"
    };

    char downImage[3][4] = {
        "   ",
        " o ",
        "_|_"
    };

    char jumpImage[3][4] = {
        " o ",
        "-|-",
        "/ \\"
    };

    char attackImage[3][4] = {
        " o ",
        "/|=",
        "/ \\"
    };

    stand = new Cell*[3];
    down = new Cell*[3];
    jump = new Cell*[3];
    attack = new Cell*[3];

    for (int i = 0; i < 3; i++) {
        stand[i] = new Cell[3];
        down[i] = new Cell[3];
        jump[i] = new Cell[3];
        attack[i] = new Cell[3];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            stand[i][j].value = standImage[i][j];
            down[i][j].value = downImage[i][j];
            jump[i][j].value = jumpImage[i][j];
            attack[i][j].value = attackImage[i][j];
        }
    }
}

EnemyImage::EnemyImage() {
    char standImage[4][9] = {
        " ______ ",
        "/ o  o \\",
        "\\______/",
        "/ |  | \\"
    };

    stand = new Cell*[4];
    for (int i = 0; i < 4; i++) {
        stand[i] = new Cell[8];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            stand[i][j].value = standImage[i][j];
            stand[i][j].color = COLOR_RED;
        }
    }
}

BulletImage::BulletImage() {
    char bulletShape[1][2] = {
        "*"
    };

    bulletShape = new Cell*[1];
    for (int i = 0; i < 1; i++) {
        bulletShape[i] = new Cell[2];
    }

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 2; j++) {
            bulletShape[i][j].value = bulletShape[0][0];
            bulletShape[i][j].color = COLOR_YELLOW;
        }
    }
}
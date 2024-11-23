#include "image.hpp"

PlayerImage::PlayerImage() {
    int row = 4;
    int col = 6;
    char standImage[row][col] = {
        "     ",
        "  o  ",
        " /|\\ ",
        " / \\ "
    };

    char downImage[row][col] = {
        "     ",
        "     ",
        "  o  ",
        " / \\ "
    };

    char jumpImage[row][col] = {
        "     ",
        "  o  ",
        " -|- ",
        " / \\ "
    };

    char attackImage[row][col] = {
        "     ",
        "  o  ",
        " /|+-",
        " / \\ "
    };
    
    stand = new Cell*[row];
    down = new Cell*[row];
    jump = new Cell*[row];
    attack = new Cell*[row];

    for (int i = 0; i < row; i++) {
        stand[i] = new Cell[col];
        down[i] = new Cell[col];
        jump[i] = new Cell[col];
        attack[i] = new Cell[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            stand[i][j].value = standImage[i][j];
            down[i][j].value = downImage[i][j];
            jump[i][j].value = jumpImage[i][j];
            attack[i][j].value = attackImage[i][j];
        }
    }
}

EnemyImage::EnemyImage() {
    Image image("./image/stage2/carrot_01.png");
    height = 25;
    width = 0;
    image.getComponentImage(stand, height, width, '.');
}

ProjectileImage::ProjectileImage() {
    blueCircle = new Cell*[1];
    blueCircle[0] = new Cell[1];

    blueCircle[0][0].value = 'o';
    blueCircle[0][0].color = COLOR_BLUE;
}
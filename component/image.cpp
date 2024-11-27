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

EnemyStage1Image::EnemyStage1Image() {
    height = 27;
    width = 0;
    Image image1("./image/stage1/ghost_01.png");
    Image image2("./image/stage1/ghost_02.png");
    Image image3("./image/stage1/ghost_03.png");
    Image image4("./image/stage1/ghost_04.png");
    Image image5("./image/stage1/ghost_05.png");
    Image image6("./image/stage1/ghost_06.png");
    Image image7("./image/stage1/ghost_07.png");
    Image image8("./image/stage1/ghost_08.png");
    Image image9("./image/stage1/ghost_09.png");
    Image image10("./image/stage1/ghost_10.png");
    Image image11("./image/stage1/ghost_11.png");
    Image image12("./image/stage1/ghost_12.png");
    image1.getComponentImage(ghostList[0], height, width, '@');
    image2.getComponentImage(ghostList[1], height, width, '@');
    image3.getComponentImage(ghostList[2], height, width, '@');
    image4.getComponentImage(ghostList[3], height, width, '@');
    image5.getComponentImage(ghostList[4], height, width, '@');
    image6.getComponentImage(ghostList[5], height, width, '@');
    image7.getComponentImage(ghostList[6], height, width, '@');
    image8.getComponentImage(ghostList[7], height, width, '@');
    image9.getComponentImage(ghostList[8], height, width, '@');
    image10.getComponentImage(ghostList[9], height, width, '@');
    image11.getComponentImage(ghostList[10], height, width, '@');
    image12.getComponentImage(ghostList[11], height, width, '@');
}

EnemyStage2Image::EnemyStage2Image() {
    Image image("./image/stage2/carrot_01.png");
    height = 30;
    width = 0;
    image.getComponentImage(stand, height, width, '@');
}

EnemyStage3Image::EnemyStage3Image() {
    height = 30;
    width = 0;
    Image image1("./image/stage3/sun_01.png");
    Image image2("./image/stage3/sun_02.png");
    Image image3("./image/stage3/sun_03.png");
    Image image4("./image/stage3/sun_04.png");
    Image image5("./image/stage3/sun_05.png");
    Image image6("./image/stage3/sun_06.png");
    image1.getComponentImage(sunList[0], height, width, '@');
    image2.getComponentImage(sunList[1], height, width, '@');
    image3.getComponentImage(sunList[2], height, width, '@');
    image4.getComponentImage(sunList[3], height, width, '@');
    image5.getComponentImage(sunList[4], height, width, '@');
    image6.getComponentImage(sunList[5], height, width, '@');
}

ProjectileImage::ProjectileImage() {
    blueCircle = new Cell*[1];
    blueCircle[0] = new Cell[1];

    blueCircle[0][0].value = 'o';
    blueCircle[0][0].color = COLOR_BLUE;
}


BulletImage::BulletImage() {
    bullet = new Cell*[1];
    bullet[0] = new Cell[1];

    bullet[0][0].value = '*';
    bullet[0][0].color = COLOR_YELLOW;
}
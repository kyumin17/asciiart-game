#pragma once
#include "display.hpp"
#include "../convert-img.hpp"
#include <string>

class PlayerImage {
    public:
        Cell** stand;
        Cell** down;
        Cell** jump;
        Cell** attack;
        PlayerImage();
};

class EnemyStage1Image {
    public:
        Cell** ghostList[12];
        int width;
        int height;
        EnemyStage1Image();
};

class EnemyStage2Image {
    public:
        Cell** stand;
        int width;
        int height;
        EnemyStage2Image();
};

class EnemyStage3Image {
    public:
        Cell** sunList[6];
        int width;
        int height;
        EnemyStage3Image();
};

class BulletImage {
    public:
        Cell** bullet;
        BulletImage();
};

class ProjectileImage {
    public:
        Cell** blueCircle;
        ProjectileImage();
};
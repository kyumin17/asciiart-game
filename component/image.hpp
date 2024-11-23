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

class EnemyImage {
    public:
        Cell** stand;
        EnemyImage();
};

class ProjectileImage {
    public:
        Cell** blueCircle;
        ProjectileImage();
};

class BackgroundImage {
    public:
        BackgroundImage();
};
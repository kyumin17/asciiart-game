#pragma once
#include "player.hpp"
#include "component.hpp"

class Enemy: public Component {
    public:
        int hp;
        int str;
        int moveDuration;
        int frame;

        Enemy(int _hp, int _str, int _x, int _y, int _width, int _height, int _frame, Cell** _image);
        bool isTouch(Player* player);
        void attack(Player* player);
        void moveStage1(EnemyStage1Image enemyImage);
        void moveStage3(EnemyStage3Image enemyImage);
};
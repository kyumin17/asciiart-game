#pragma once
#include <string>
#include "enemy.hpp"
#include "display.hpp"

class Bullet: public Component {
    public:
        int str;
        std::string direction; //8방향

        Bullet(int _x, int _y, std::string _direction, int _width, int _height, Cell** _image);
        void move();
        bool isEnemyTouch(Enemy* enemy);
        void enemyAttack(Enemy* enemy);
        bool isProjectileTouch();
        void projectileAttack();
        bool isOutOfDisplay(Enemy* enemy);
};
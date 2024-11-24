#pragma once
#include <string>
#include "component.hpp"

class Bullet: public Component {
    public:
        int str;
        std::string direction; //8방향
    
        Bullet(int _x, int _y, std::string _direction, int _width, int _height, Cell** _image);
        void move();
        bool isEnemyTouch();
        void enemyAttack();
        bool isProjectileTouch();
        void projectileAttack();
        bool isOutOfDisplay();
};
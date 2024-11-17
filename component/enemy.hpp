#pragma once
#include "player.hpp"
#include "component.hpp"

class Enemy: public Component {
    public:
        int hp;
        int str;

        Enemy(int _hp, int _str, int _x, int _y, int _width, int _height, Cell** _image);
        bool isTouch(int playerX, int playerY);
        void attack(Player* player);
};
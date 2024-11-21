#pragma once
#include "component.hpp"
#include "image.hpp"
#include "player-bullet.hpp"

class Player: public Component {
    public:
        int hp;
        Cell** image;
        Player(int _hp, int _x, int _y, int _width, int _height, Cell** _image);
        void move(Input input, PlayerImage playerImage);
        void attack(bool isAttack, BulletImage bulletImage, Bullet* bulletArr[], int &bulletNum);
};
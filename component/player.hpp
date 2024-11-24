#pragma once
#include "component.hpp"
#include "player-bullet.hpp"
#include "image.hpp"

enum State { LEFT, RIGHT, JUMP, DOWN, ATTACK };

class Player: public Component {
    public:
        int hp;
        Cell** image;
        bool state[5];
        int stateDuration[5];
        Player(int _hp, int _x, int _y, int _width, int _height, Cell** _image);
        void move(std::string moveDirection, PlayerImage playerImage);
        void attack(bool isAttack, Bullet*(&bulletArr)[300], int& bulletNum, std::string attackDirection, PlayerImage playerImage, Cell** image);
};
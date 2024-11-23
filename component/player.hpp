#pragma once
#include "component.hpp"
#include "image.hpp"

typedef enum {
    LEFT,
    RIGHT,
    JUMP,
    DOWN,
    ATTACK
} State;

class Player: public Component {
    public:
        int hp;
        Cell** image;
        bool state[5];
        int stateDuration[5];
        Player(int _hp, int _x, int _y, int _width, int _height, Cell** _image);
        void move(std::string moveDirection, PlayerImage playerImage);
        void attack(bool isAttack, std::string attackDirection, PlayerImage playerImage);
};
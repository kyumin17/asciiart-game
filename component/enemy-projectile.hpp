#pragma once
#include <string>
#include "player.hpp"
#include "component.hpp"

class Projectile: public Component {
    public:
        int str;
        int dx;
        int dy;
        std::string type;

        Projectile(int _str, int _x, int _y, int _dx, int _dy, int _width, int _height, Cell** _image, std::string _type);
        void straightMove();
        void curveMove();
        void straightChaseMove(int playerX, int playerY);
        void curveChaseMove(int playerX, int playerY);
        bool isTouch(Player* player);
        void attack(Player* player);
        bool isOutOfDisplay();
};
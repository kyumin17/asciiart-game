#include "enemy-projectile.hpp"

Projectile::Projectile(int _str, int _x, int _y, int _dx, int _dy, int _width, int _height, Cell** _image, std::string _type)
: Component(_x, _y, _width, _height, _image) {
    str = _str;
    dx = _dx;
    dy = _dy;
    type = _type;
}

void Projectile::straightMove() {
    /*
    x, y값 변경
    */
}

void Projectile::curveMove() {
    /*
    x, y값 변경
    */
}

void Projectile::straightChaseMove(int playerX, int playerY) {
    /*
    한 번 따라옴 (방향 변경 X)
    */
}

void Projectile::curveChaseMove(int playerX, int playerY) {
    /*
    계속 쫓아옴
    */
}

bool Projectile::isTouch(Player* player) {
    /*
    닿았는지 판단
    */
}

void Projectile::attack(Player* player) {
    /*
    isTouch라면 공격
    */
}

bool Projectile::isOutOfDisplay() {
    /*
    화면 벗어나면 true반환, 아니면 false
    */
}
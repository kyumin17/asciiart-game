#include "enemy.hpp"

Enemy::Enemy(int _hp, int _str, int _x, int _y, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    hp = _hp;
    str = _str;
}

bool Enemy::isTouch(Player* player) {
    /*
    유저랑 만나면 true반환
    */

    return false;
}

void Enemy::attack(Player* player) {
    /*
    player의 hp를 감소시킴
    */

    if (isTouch(player)) {
        player -> hp -= str;
    }
}
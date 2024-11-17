#include "player.hpp"

Player::Player(int _hp, int _x, int _y, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    hp = _hp;
}

void Player::move() {
    //플레이어 이동
}
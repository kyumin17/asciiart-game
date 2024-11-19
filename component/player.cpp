#include "player.hpp"

Player::Player(int _hp, int _x, int _y, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    hp = _hp;
}

void Player::move(Input input, PlayerImage playerImage) {
    /*
    입력값에 따라 플레이어 이동
    */
    
    if (input.moveDirection[1] == 'a' && y >= 1) {
        y--;
    } else if (input.moveDirection[1] == 'd' && y < 126) {
        y++;
    }

}

void Player::attack(bool isAttack, PlayerImage playerImage) {
    changeImage(playerImage.attack);
}
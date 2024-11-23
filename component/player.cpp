#include "player.hpp"

Player::Player(int _hp, int _x, int _y, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    hp = _hp;
    for (int i = 0; i < 5; i++) {
        state[i] = false;
    }
}

void Player::move(std::string moveDirection, PlayerImage playerImage) {
    /*
    입력값에 따라 플레이어 이동
    */

    if (state[DOWN]) {
        stateDuration[DOWN]--;
        if (stateDuration[DOWN] == 0) {
            state[DOWN] = false;
            changeImage(playerImage.stand);
        }
    }

    if (state[JUMP]) {
        stateDuration[JUMP]--;
        if (stateDuration[JUMP] == 0) {
            state[JUMP] = false;
            changeImage(playerImage.stand);
        }
    }

    if (state[LEFT]) {
        stateDuration[LEFT]--;
        if (stateDuration[LEFT] == 0) {
            state[LEFT] = false;
        }
    }

    if (state[RIGHT]) {
        stateDuration[RIGHT]--;
        if (stateDuration[RIGHT] == 0) {
            state[RIGHT] = false;
        }
    }
    
    if (moveDirection[1] == 'a') {
        if (state[LEFT]) {
            return;
        }
        y -= 2;
        state[LEFT] = true;
        stateDuration[LEFT] = 20;
    } else if (moveDirection[1] == 'd') {
        if (state[RIGHT]) {
            return;
        }
        y += 2;
        state[RIGHT] = true;
        stateDuration[RIGHT] = 20;
    }

    if (moveDirection[0] == 's') {
        if (state[DOWN]) {
            stateDuration[DOWN] = 5;
            return;
        }
        state[DOWN] = true;
        stateDuration[DOWN] = 70;
        changeImage(playerImage.down);
    } else if (moveDirection[0] == 'j') {
        if (state[JUMP]) {
            stateDuration[JUMP] = 5;
            return;
        }
        state[JUMP] = true;
        stateDuration[JUMP] = 70;
        changeImage(playerImage.jump);
    }
}

void Player::attack(bool isAttack, std::string attackDirection, PlayerImage playerImage) {
    if (state[ATTACK]) {
        stateDuration[ATTACK]--;
        if (stateDuration[ATTACK] == 0) {
            state[ATTACK] = false;
            changeImage(playerImage.stand);
        }
    }

    if (isAttack) {
        if (state[ATTACK]) {
            stateDuration[ATTACK] = 5;
            return;
        }
        state[ATTACK] = true;
        stateDuration[ATTACK] = 70;
        changeImage(playerImage.attack);
    }
}
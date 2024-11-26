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
    int jumpVelocity[9] = {-2, -2, -2, -1, 1, 1, 1, 2, 2};

    if (state[DOWN]) {
        stateDuration[DOWN]--;
        if (stateDuration[DOWN] == 0) {
            state[DOWN] = false;
            changeImage(playerImage.stand);
        }
    }

    if (state[JUMP]) {
        stateDuration[JUMP]--;
        if (stateDuration[JUMP] % 3 == 0) {
            y += jumpVelocity[stateDuration[JUMP]/3];

            if (state[RIGHT]) {
                x++;
                stateDuration[RIGHT] = 10;
            } else if (state[LEFT]) {
                x--;
                stateDuration[LEFT] = 10;
            }
        }

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
        x--;
        if (state[LEFT]) return;
        state[LEFT] = true;
        stateDuration[LEFT] = 20;
    } else if (moveDirection[1] == 'd') {
        x++;
        if (state[RIGHT]) return;
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
        if (state[JUMP]) return;
        state[JUMP] = true;
        stateDuration[JUMP] = 27;
        changeImage(playerImage.jump);
    }

}

void Player::attack(bool isAttack, Bullet*(&bulletArr)[300], int& bulletNum, std::string attackDirection, PlayerImage playerImage, Cell** image) {
    if (state[ATTACK]) {
        stateDuration[ATTACK]--;
        if (stateDuration[ATTACK] == 0) {
            state[ATTACK] = false;
            changeImage(playerImage.stand);
        }
    }

    if (isAttack) {
        if (state[ATTACK]) {
            stateDuration[ATTACK] = 4;
            return;
        }
        state[ATTACK] = true;
        stateDuration[ATTACK] = 60;
        changeImage(playerImage.attack);
    }

    if (state[ATTACK]) {
        if (stateDuration[ATTACK] % 4 == 0) 
        {
            //bulletArr[bulletNum++] = new Bullet(x + 5, y + 1, attackDirection, width, height, image);
        }
    }
}
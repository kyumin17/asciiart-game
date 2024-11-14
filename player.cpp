#include "player.hpp"
#define HEIGHT 30
#define WIDTH 130

Player::Player(int _hp, int _str, int _width, int _height, int _x, int _y) {
    hp = _hp;
    str = _str;
    width = _width;
    height = _height;
    x = _x;
    y = _y;
    isDown = 0;
    isJump = 0;
    downTime = 0;
    jumpTime = 0;
    isRightJump = 0;
    isLeftJump = 0;

    PlayerIcon player_icon;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            character[row][col] = player_icon.PlayerDefault[row][col];
        }
    }
}

void Player::changeCharacter(char _character[3][4]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            character[row][col] = _character[row][col];
        }
    }
}

void Player::move(Direction dir) {
    PlayerIcon player_icon;

    if (isDown) {
        downTime++;
        if (downTime >= 50) {
            isDown = 0;
            downTime = 0;
            changeCharacter(player_icon.PlayerDefault);
        }
    }

    int dy = 0;
    int jumpVelocity[] = {2, 2, 1, 1, 1, -1, -2, -2, -2};
    if (isJump) {
        if (jumpTime % 2 == 0) {

            if (isRightJump) {
                if (y < WIDTH - 1) y++;
            } else if (isLeftJump) {
                if (y > 1) y--;
            }

            x -= jumpVelocity[jumpTime/2];
            y += dy;
        }
        jumpTime++;
        if (jumpTime == 9 * 2) {
            isJump = 0;
            isRightJump = 0;
            isLeftJump = 0;
            jumpTime = 0;
        }
    }

    if (dir == JUMP) {
        isJump = 1;
    } else if (dir == DOWN) {
        isDown = 1;
        changeCharacter(player_icon.playerDown);
        if (isDown) {
            downTime = 40;
        }
    } else if (dir == LEFT) {
        if (isJump) {
            isLeftJump = 1;
        }
        if (y > 1) y--;
    } else if (dir == RIGHT) {
        if (isJump) {
            isRightJump = 1;
        }
        if (y < WIDTH - 1) y++;
    } 
    if (dir == RIGHTJUMP) {
        isJump = 1;
        isRightJump = 1;
    }
    if (dir == LEFTJUMP) {
        isLeftJump = 1;
        isJump = 1;
    }

}
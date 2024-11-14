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
    isLeft = 0;
    isRight = 0;
    leftTime = 0;
    rightTime = 0;

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
    /*
    플레이어를 입력 키에 따라 움직임
    */

    //spaghetti...
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

        if (jumpTime % 4 == 0) {

            if (isRightJump) {
                if (y < WIDTH - 1) y++;
            } else if (isLeftJump) {
                if (y > 1) y--;
            }

            x -= jumpVelocity[jumpTime/4];
            y += dy;
        }

        jumpTime++;
        if (jumpTime == 9 * 4) {
            isJump = 0;
            isRightJump = 0;
            isLeftJump = 0;
            jumpTime = 0;
            changeCharacter(player_icon.PlayerDefault);
        }
    }

    if (isLeft) {
        leftTime++;
        if (leftTime == 10) {
            isLeft = 0;
            leftTime = 0;
        }
    }

    if (isRight) {
        rightTime++;
        if (rightTime == 10) {
            isRight = 0;
            rightTime = 0;
        }
    }

    if (dir == JUMP) {
        isJump = 1;
        if (isRight) {
            isRightJump = 1;
        } else if (isLeft) {
            isLeftJump = 1;
        }
    } else if (dir == DOWN) {
        changeCharacter(player_icon.playerDown);
        if (isDown) {
            downTime = 45;
        }
        isDown = 1;
    } else if (dir == LEFT) {
        if (y > 1 && !isLeftJump) y--;
        isLeft = 1;
        isRight = 0;
        if (isJump) {
            isLeftJump = 1;
        }
        if (isLeft) {
            leftTime = 5;
        }
    } else if (dir == RIGHT) {
        if (y < WIDTH - 1 && !isRightJump) y++;
        isRight = 1;
        isLeft = 0;
        if (isJump) {
            isRightJump = 1;
        }
        if (isRight) {
            rightTime = 5;
        }
    } 
    if (dir == RIGHTJUMP) {
        isJump = 1;
        isRightJump = 1;
    }
    if (dir == LEFTJUMP) {
        isLeftJump = 1;
        isJump = 1;
    }

    if (isJump) {
        changeCharacter(player_icon.playerJump);
    }

}
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

void Player::attack(bool isAttack, BulletImage bulletImage, Bullet* bulletArr[], int &bulletNum) {
    if (isAttack && bulletNum < 300) {
        // 새로운 총알 생성
        int bulletX = x + 2; // 플레이어 중앙에서 총알 발싸
        int bulletY = y + 2;
    
        bulletArr[bulletNum] = new Bullet( bulletX, bulletY, bulletImage);
        bulletNum++;
    }

    for(int i = 0; i < bulletNum; i++) {
        if ( bulletArr[i] ) {
            bulletArr[i]->move(x, y);
            //총알이 밖으로 나가면 제거 
            if ( bulletArr[i]->x < 0 || bulletArr[i]->x >= width || bulletArr[i]->y < 0 || bulletArr[i]->y >= height) {
                delete bulletArr[i];
                bulletArr[i] = nullptr;
                //배열 재정렬
                for (int j = i; j < bulletNum - 1; j++) {
                    bulletArr[j] = bulletArr[j + 1];
                }
                bulletArr[bulletNum - 1] = nullptr;
                bulletNum--;
                i--;   //인덱스 조정과정
            }
        }
    }
}
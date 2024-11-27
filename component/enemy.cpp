#include "enemy.hpp"

Enemy::Enemy(int _hp, int _str, int _x, int _y, int _width, int _height, int _frame, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    hp = _hp;
    str = _str;
    moveDuration = 0;
    frame = _frame;
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

void Enemy::moveStage1(EnemyStage1Image enemyImage) {
    if (moveDuration < frame * 11) moveDuration++;
    image = enemyImage.ghostList[moveDuration / frame];
}

void Enemy::moveStage3(EnemyStage3Image enemyImage) {
    moveDuration++;
    if (moveDuration >= frame * 6) moveDuration = 0;
    image = enemyImage.sunList[moveDuration / frame];
}
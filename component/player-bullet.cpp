#include "player-bullet.hpp"

Bullet::Bullet(int _x, int _y, std::string _direction, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    direction = _direction;
}

void Bullet::move() {
    /*
    direction에 따라 x, y값 변경
    */
}

bool Bullet::isEnemyTouch(Enemy* enemy) {
    /*
    적이랑 만났어? true 반환
    적이랑 안만났어? false 반환
    */
}

void Bullet::enemyAttack(Enemy* enemy) {
    /*
    적과 만날 시 피해를 준다
    */
}

bool Bullet::isProjectileTouch() {
    /*
    투사체랑 만났어? true 반환
    투사체랑 안만났어? false 반환
    */
}

void Bullet::projectileAttack() {
    /*
    투사체와 만날 시 피해를 준다
    */
}

bool Bullet::isOutOfDisplay(Enemy* enemy) {
    /*
    x, y값을 받아서 화면에서 나가면 true 반환
    아니면 false 반환
    */
}
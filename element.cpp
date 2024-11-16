#include "element.hpp"
//HIIIIIIIIII
Element::Element(char _id[], int _width, int _height, int _x, int _y, Cell** _image) {
    width = _width;
    height = _height;
    x = _x;
    y = _y;
    image = new Cell*[height];
    for (int row = 0; row < height; row++) {
        image[row] = new Cell[width];
    }
    
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            image[row][col] = _image[row][col];
        }
    }

    for (int i = 0; i < MAXLEN; i++) {
        id[i] = _id[i];
    }
}

Enemy::Enemy(char _id[], int _hp, int _str, char _pattern[], int _width, int _height, int _x, int _y, Cell** _image)
: Element(_id, _width, _height, _x, _y, _image) {
    hp = _hp;
    str = _str;
    for (int i = 0; i < MAXLEN; i++) pattern[i] = _pattern[i];
}

Attack::Attack(char _id[], int _str, bool _isAttackable, bool _isTracking, int _width, int _height, int _x, int _y, Cell** _image)
: Element(_id, _width, _height, _x, _y, _image) {
    str = _str;
    isAttackable = _isAttackable;
    isTracking = _isTracking;
}

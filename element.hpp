#pragma once
#define MAXLEN 20
#define HEIGHT 30
#define WIDTH 130
typedef enum { WHITE, RED, GREEN, BLUE } Color;

struct Cell {
    char value;
    Color color;
};

class Element {
    public:
        char id[MAXLEN];
        int width;
        int height;
        int x;
        int y;
        Cell** image;
        Element(char _id[], int _width, int _height, int _x, int _y, Cell** _image);
};

class Enemy: Element {
    public:
        int hp;
        int str;
        char pattern[MAXLEN];
        Enemy(char _id[], int _hp, int _str, char _pattern[], int _width, int _height, int _x, int _y, Cell** _image);
};

class Attack: Element {
    public:
        int str;
        bool isAttackable;
        bool isTracking;
        Attack(char _id[], int _str, bool _isAttackable, bool _isTracking, int _width, int _height, int _x, int _y, Cell** _image);
};

class Block: Element {
    public:
        Block(char _id[], int _width, int _height, int _x, int _y, Cell** _image);
};

class Background: Element {
    public:
        Background(char _id[], int _width, int _height, int _x, int _y, Cell** _image);
        
};
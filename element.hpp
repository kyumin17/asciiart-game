#pragma once
typedef enum { WHITE, RED, GREEN, BLUE } Color;

struct Cell {
    char value;
    Color color;
};

class Element {
    public:
        char* id;
        int width;
        int height;
        Cell** image;
};

class Player: Element {
    public:
        int hp;
        int str;
};

class Enemy: Element {
    public:
        int hp;
        int str;
};

class Attack: Element {
    public:
        int str;
        bool attackable;
};

class Block: Element {
    public:

};

class Background: Element {
    public:
        
};
#pragma once
typedef enum { LEFT, RIGHT, JUMP, DOWN, LEFTJUMP, RIGHTJUMP, LEFTDOWN, RIGHTDOWN, NONE, QUIT } Direction;

class PlayerIcon {
    public:
        char PlayerDefault[3][4] = {
            " o ",
            "/|\\",
            "/ \\"
        };

        char playerDealing[3][4] = {
            " o ",
            "/|=",
            "/ \\"
        };

        char playerJump[3][4] = {
            " o ",
            "-|-",
            "- -"
        };

        char playerJumpDealing[3][4] = {
            " o ",
            "-|=",
            "/ \\"
        };

        char playerDown[3][4] = {
            "   ",
            " o ",
            "_|_"
        };
};

class Player {
    public:
        int hp;
        int str;
        int width;
        int height;
        int x;
        int y;
        char character[3][4];
        int isDown;
        int isJump;
        int downTime;
        int jumpTime;
        int isRightJump;
        int isLeftJump;
        
        Player(int _hp, int _str, int _width, int _height, int _x, int _y);
        void changeCharacter(char _character[3][4]);
        void move(Direction dir);
};
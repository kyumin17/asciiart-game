#pragma once

class GameState {
    public:
        bool stage1Clear;
        bool stage2Clear;
        bool stage3Clear;
        GameState() {
            stage1Clear = false;
            stage2Clear = false;
            stage3Clear = false;
        }
};
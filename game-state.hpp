#pragma once

class GameState {
    public:
        bool stage1Access;
        bool stage2Access;
        bool stage3Access;
        GameState() {
            stage1Access = true;
            stage2Access = false;
            stage3Access = false;
        }
};
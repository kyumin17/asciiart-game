#include "page.hpp"

void printStage3Page() {
    Display display(130, 30);
    PlayerImage playerImage;
    Player player(10, 26, 3, 3, 3, playerImage.stand);
    Input input;
    input.isQuit = false;
    
    while (!input.isQuit) {
        display.initDisplay();
        input = display.getInput();
        player.move(input.moveDirection, playerImage);
        player.draw(&display);
        display.printDisplay();
        refresh();
    }
}
#include "page.hpp"
#include "../component/player.hpp"
#include "../component/image.hpp"
#include "../component/display.hpp"

void printStage1Page() {
    Display Display(130, 30);

    while (1) {
        usleep(10 * ms);
        Display.printDisplay();
        refresh();
    }
}
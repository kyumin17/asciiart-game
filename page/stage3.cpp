#include "page.hpp"
#include "../component/display.hpp"

void printStage3Page() {
    Display Display(130, 30);
    while (1) {
        usleep(10 * ms);
        Display.printDisplay();
        refresh();
    }
}
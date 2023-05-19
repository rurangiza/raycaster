#include "raycaster.h"

int isGameRunning = FALSE;

int main() {
    isGameRunning = initWindow();
    setup();
    while (isGameRunning) {
        processInput();
        update();
        render();
    }
    destroyWindow();
    return 0;
}
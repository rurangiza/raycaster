#include "raycaster.h"

int main() {
    initWindow();
    setup();
    while (1) {
        processInput();
        update();
        render();
    }

    return 0;
}
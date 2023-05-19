
#include "raycaster.h"

int playerX, playerY;
int stickX, stickY;

int Xpolarity = 1;
int Ypolarity = 1;


void    update() {
    // playerX += 1;
    // playerY += 1;

    if (Xpolarity == 1) {
        playerX += 1;
        if (playerX >= WINDOW_WIDTH - 20)
            Xpolarity = -1;
    }
    else
    {
        playerX -= 1;
        if (playerX <= 0)
            Xpolarity = 1;
    }

    if (Ypolarity == 1) {
        playerY += 1;
        if (playerY >= WINDOW_HEIGHT - 20)
            Ypolarity = -1;
    }
    else
    {
        playerY -= 1;
        if (playerY <= 0)
            Ypolarity = 1;
    }
    //playerY = (playerY + (1 * polarity));
    usleep(100);
}

void    processInput() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isGameRunning = FALSE;
            break ;
        case SDL_KEYDOWN: {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isGameRunning = FALSE;
            else if (event.key.keysym.sym == SDLK_DOWN)
                stickY += 20;
            else if (event.key.keysym.sym == SDLK_UP)
                stickY -= 20;
            break;
        }
    }
}
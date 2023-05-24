
#include "raycaster.h"

typedef struct Object {
    int x;
    int y;
    int polarityX;
    int polarityY;
}   Object;

int     playerX, playerY;
int     ticksLastFrame = 0;
float   deltaTime = 0;

void    update() {
    // wait some time until reach target frame rate
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TIME_LENGTH))
        ;
    // difference in ticks from last frame converted to seconds
    deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    ticksLastFrame = SDL_GetTicks();

    playerX += PLAYER_SPEED * deltaTime;
    playerY += PLAYER_SPEED * deltaTime;
}

void    processInput() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isGameRunning = FALSE;
            break ;
        case SDL_KEYDOWN: 
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    isGameRunning = FALSE;
                    break ;
                case SDLK_DOWN:
                    playerY += PLAYER_SPEED * deltaTime;
                    break ;
                case SDLK_UP:
                    playerY -= PLAYER_SPEED * deltaTime;
                    break ;
                case SDLK_LEFT:
                    playerX -= PLAYER_SPEED * deltaTime;
                    printf("playerX = %d\n", playerX);
                    break ;
                case SDLK_RIGHT:
                    playerX += PLAYER_SPEED * deltaTime;
                    printf("playerX = %d\n", playerX);
                    break ;
            break;
        }
    }
}

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

    movePlayer(deltaTime);

    // playerX += PLAYER_SPEED * deltaTime;
    // playerY += PLAYER_SPEED * deltaTime;
}

void    movePlayer(float deltaTime)
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_KEYDOWN: 
            switch (event.key.keysym.sym) {
                case SDLK_DOWN:
                    player.y += PLAYER_SPEED * deltaTime;
                    break ;
                case SDLK_UP:
                    player.y -= PLAYER_SPEED * deltaTime;
                    break ;
                case SDLK_LEFT:
                    player.x -= PLAYER_SPEED * deltaTime;
                    break ;
                case SDLK_RIGHT:
                    player.x += PLAYER_SPEED * deltaTime;
                    break ;
            break;
        }
    }
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
                    player.walkDirection = -1;
                    break ;
                case SDLK_UP:
                    player.walkDirection = +1;
                    break ;
                case SDLK_LEFT:
                    player.turnDirection = -1;
                    break ;
                case SDLK_RIGHT:
                    player.turnDirection = +1;
                    break ;
            }
        case SDL_KEYUP: {
            // switch () {

            // }
        }
    }
}
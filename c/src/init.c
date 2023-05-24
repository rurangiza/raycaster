#include "raycaster.h"

SDL_Window *window = NULL;

int initWindow() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }
    window = SDL_CreateWindow(
        NULL,                       // title
        SDL_WINDOWPOS_CENTERED,     // x position
        SDL_WINDOWPOS_CENTERED,     // y position
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        fprintf(stderr, "Error creating SDL window.\n");
        return FALSE;
    }
    renderer = SDL_CreateRenderer(
        window,                     // window
        -1,                         // driver (-1 means default driver)
        0
    );
    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return FALSE;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    return TRUE;
}

void    setup() {
    Player.x = WINDOW_WIDTH / 2;
    Player.y = WINDOW_HEIGHT / 2;
    Player.width = 5;
    Player.height = 5;
    Player.turnDirection = 0;
    Player.walkDirection = 0;
    Player.rotationAngle = PI / 2;
    Player.walkSpeed = 100; // pixels per second
    Player.turnSpeed = 45 * (PI / 180);
}
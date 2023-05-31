#include "raycaster.h"

SDL_Window *window = NULL;

int initWindow() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }
    window = SDL_CreateWindow(
        "Adventura 3D",								// title
        SDL_WINDOWPOS_CENTERED,				// x position
        SDL_WINDOWPOS_CENTERED,				// y position
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        fprintf(stderr, "Error creating SDL window.\n");
        return FALSE;
    }
    renderer = SDL_CreateRenderer(
        window,								// window
        -1,									// driver (-1 means default driver)
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
    player.x = WINDOW_WIDTH / 2;
    player.y = WINDOW_HEIGHT / 2;
    player.width = 1;
    player.height = 1;
    player.turnDirection = 0;
    player.walkDirection = 0;
    player.rotationAngle = PI / 2;
    player.walkSpeed = 100;					// pixels per second
    player.turnSpeed = 45 * (PI / 180);
}
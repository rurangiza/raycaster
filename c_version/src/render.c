
#include "raycaster.h"

SDL_Renderer *renderer = NULL;

void render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect rect = {playerX, playerY, 20, 20};
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 129, 255);
    SDL_Rect stick = {stickX, stickY, 30, 60};
    SDL_RenderFillRect(renderer, &stick);

    // TODO:
    // render all game objects for the current frame

    SDL_RenderPresent(renderer);
}

#include "raycaster.h"

SDL_Renderer *renderer = NULL;

void    renderMap();

void render() {
    // Set background color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    renderMap();
    // renderRays();
    // renderPlayer();

    // Show the rendered frame
    SDL_RenderPresent(renderer);
}

void    renderMap() {
    int row = 0, col;
    int tileX, tileY, tileColor;

    while (row < MAP_NUM_ROWS)
    {
        col = 0;
        while (col < MAP_NUM_COLS)
        {
            tileX = col * TILE_SIZE;
            tileY = row * TILE_SIZE;
            tileColor = map[row][col] != 0 ? 255 : 0;

            SDL_SetRenderDrawColor(renderer, tileColor, tileColor, tileColor, 255);
            SDL_Rect mapTileRect = {
                tileX,
                tileY,
                TILE_SIZE,
                TILE_SIZE
            };
            SDL_RenderFillRect(renderer, &mapTileRect);

            col++;
        }
        row++;
    }
}
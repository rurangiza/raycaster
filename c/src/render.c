
#include "raycaster.h"

SDL_Renderer *renderer = NULL;

void    renderMap();

void render() {
    // Set background color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    renderMap();
    renderPlayer();
    // renderRays();

    // Show the rendered frame
    SDL_RenderPresent(renderer);
}

/*===---===---===---===---===---===---===---===---===---===---===---===---*/


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

            // Like preparing your colors before painting
            SDL_SetRenderDrawColor(renderer, tileColor, tileColor, tileColor, 255);
            SDL_Rect mapTileRect = {
                tileX * MINIMAP_SCALE_FACTOR,
                tileY * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR
            };
            SDL_RenderFillRect(renderer, &mapTileRect);

            col++;
        }
        row++;
    }
}

void    renderPlayer() {
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_Rect playerRect = {
        player.x * MINIMAP_SCALE_FACTOR,		// x position
        player.y * MINIMAP_SCALE_FACTOR,		// y position
        player.width * MINIMAP_SCALE_FACTOR,				//
        player.height * MINIMAP_SCALE_FACTOR
    };
    SDL_RenderFillRect(renderer, &playerRect);

    SDL_RenderDrawLine(
        renderer,
        player.x * MINIMAP_SCALE_FACTOR,
        player.y * MINIMAP_SCALE_FACTOR,
        (player.x + cos(player.rotationAngle) * 40) * MINIMAP_SCALE_FACTOR,
        (player.y + sin(player.rotationAngle) * 40) * MINIMAP_SCALE_FACTOR
    );
}
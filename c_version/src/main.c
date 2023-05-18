#include "raycaster.h"

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

void    destroyWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void    setup() {
    // TODO:
    // Initialize and setup game objects
    playerX = 0;
    playerY = WINDOW_HEIGHT / 2;
    stickX = 0;
    stickY = 0;
}

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
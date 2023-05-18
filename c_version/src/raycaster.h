
#ifndef RAYCASTER_H
# define RAYCASTER_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>

#include <unistd.h>

#define FALSE   0
#define TRUE    1

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int isGameRunning = FALSE;
int playerX, playerY;
int stickX, stickY;


#endif
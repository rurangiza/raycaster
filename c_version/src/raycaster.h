
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

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern int isGameRunning;
extern int playerX, playerY;
extern int stickX, stickY;

int		initWindow(void);
void	setup(void);
void	destroyWindow(void);
void	render(void);
void	update(void);
void	processInput(void);

#endif
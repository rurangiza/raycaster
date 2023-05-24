
#ifndef RAYCASTER_H
# define RAYCASTER_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>

#include <unistd.h>

#define FALSE   0
#define TRUE    1

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64
#define MAP_NUM_ROWS 13 
#define MAP_NUM_COLS 20
#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

#define FOV_ANGLE (60 * (PI/180))

#define NUM_RAYS WINDOW_WIDTH

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define PLAYER_SPEED 100

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern int isGameRunning;
extern int stickX, stickY;

extern int ticksLastFrame;

extern int map[MAP_NUM_ROWS][MAP_NUM_COLS];


struct Player {
    float   x;
    float   y;
    float   width;
    float   height;
    int     turnDirection; // -1 for left, +1 right
    int     walkDirection; // -1 for back, +1 for front
    float   rotationAngle;
    float   walkSpeed;
    float   turnSpeed;
}   Player;


int		initWindow(void);
void	setup(void);
void	destroyWindow(void);
void	render(void);
void	update(void);
void	processInput(void);

#endif
#ifndef CONSTANTS_H
# define CONSTANTS_H

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

#define PLAYER_SPEED 300

#define MINIMAP_SCALE_FACTOR 0.3

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern int isGameRunning;
extern int playerX, playerY;

extern int ticksLastFrame;

extern int map[MAP_NUM_ROWS][MAP_NUM_COLS];

#endif
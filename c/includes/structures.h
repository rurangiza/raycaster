#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "constants.h"

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
}   player;

#endif
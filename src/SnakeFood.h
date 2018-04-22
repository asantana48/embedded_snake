#ifndef _SNAKEFOOD_H
#define _SNAKEFOOD_H

// *****************
// Standard Headers
// *****************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// *****************
// Local Headers
// *****************
#include "snake.h"
#include "globals.h"
#include "drawing.h"
#include "wavfactory.h"

// ********************
// Snake Food Structure
// ********************
typedef struct SnakeFood {
	int x, y;
} SnakeFood;

// **************************
// Global Snake Food Structure
// **************************
SnakeFood snakeFood;

// *******************
// Function Prototypes
// *******************
void initSnakeFood(SnakeFood* snakeFood);
void removeSnakeFood(SnakeFood* snakeFood);
int isScore(Snake *snake, SnakeFood *snakeFood);

#endif

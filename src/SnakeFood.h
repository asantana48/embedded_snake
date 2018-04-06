#ifndef _SNAKEFOOD_H
#define _SNAKEFOOD_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "Snake.h"

typedef struct SnakeFood {
	int x, y;
} SnakeFood;

SnakeFood snakeFood;

void initSnakeFood(SnakeFood* snakeFood);

int isScore(Snake *snake, SnakeFood *snakeFood);

#endif

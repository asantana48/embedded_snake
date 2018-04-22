#ifndef _SNAKEFOOD_H
#define _SNAKEFOOD_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>


#include <unistd.h>
#include <string.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "Globals.h"
#include "Snake.h"
#include "Drawing.h"
#include "DoublyLinkedList.h"

typedef struct SnakeFood {
	int x, y;
} SnakeFood;

SnakeFood snakeFood;

void initSnakeFood(SnakeFood* snakeFood);

int isScore(Snake *snake, SnakeFood *snakeFood);

#endif

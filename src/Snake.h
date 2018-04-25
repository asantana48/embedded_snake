#ifndef _SNAKE_H
#define _SNAKE_H

// *****************
// Standard Headers
// *****************
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>

// *****************
// Local Headers
// *****************
#include "Globals.h"
#include "Drawing.h"
#include "wavfactory.h"
#include "DoublyLinkedList.h"

// ***************
// Snake Structure
// ***************
typedef struct Snake {
	int size;
	int tailx;
	int taily;
	int score;
	int headx;
	int heady;
	int direction; 
	int newDirection;
} Snake;

// *********************
// Global Snake Structure
// *********************
Snake snake;

// *******************
// Function Prototypes
// *******************
void initSnake(Snake* snake);
int moveSnake(Snake* snake);
void slaySnake(Snake* snake);
void wipeSnake(Snake* snake);
void drawSnake(Snake* snake);
void placeSnake(Snake* snake);
int coordinateInBounds(int x, int y);
void incrementScore(Snake* snake);
void moveValidRandom(Snake* snake);
void getScore(Snake* snake, char* score);

#endif

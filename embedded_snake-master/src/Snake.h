#ifndef _SNAKE_H
#define _SNAKE_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Globals.h"
#include "Drawing.h"
#include "DoublyLinkedList.h"

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

Snake snake;

void initSnake(Snake* snake);
void wipeSnake(Snake* snake);
void drawSnake(Snake* snake);
void placeSnake(Snake* snake);
int moveSnake(Snake* snake);
void slaySnake(Snake* snake);

char* getScore(Snake* snake);
void incrementScore(Snake* snake);

int coordinateInBounds(int x, int y);

void getRandomAdjacent(int* x, int* y);
#endif

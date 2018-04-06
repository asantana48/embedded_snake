#ifndef _SNAKE_H
#define _SNAKE_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#include "DoublyLinkedList.h"

typedef struct Snake {
	int size;
	int tailx;
	int taily;
	int score;
	int headx;
	int heady;
	int direction; 
	int prevDirection;
} Snake;

Snake snake;

void initSnake(Snake* snake);
void placeSnake(Snake* snake);
void moveSnake(Snake* snake);
void moveSnakeTail(Snake* snake);
void incrementScore(Snake* snake);
void moveSnakeHead(Snake* snake, int direction);

char* getScore(Snake* snake);
int inBounds(Snake* snake, int direction);
int coordInBounds(int x, int y);

void wipeSnake(Snake* snake);
void drawSnake(Snake* snake);

void getRandomAdjacent(int* x, int* y);

#endif

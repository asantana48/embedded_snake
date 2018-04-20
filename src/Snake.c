#include "Snake.h"

void initSnake(Snake* snake) {
	snake->score = 0;
	snake->size = 1;
	snake->direction = RIGHT;
	snake->nextDirection = RIGHT;
	snake->tailx = -1;
	snake->taily = -1;
	snake->headx = -1;
	snake->heady = -1;
	
	// Place snake head randomly
	snake->headx = (rand() % (HORIZONTAL - 5) +1);
	snake->heady = (rand() % (VERTICAL - 5) + 1);
	insertAtHead(snake->headx , 	snake->heady);
	
	int tempx = snake->headx ;
	int tempy = snake->heady;
	int i = 0;
	for(i = 0; i < 2; ++i){
		// Place snake tail in valid random adjacent positions
		while(inList(tempx, tempy) || !coordInBounds(tempx, tempy)) {
			tempx = list.TAIL->x;
			tempy = list.TAIL->y;
			getRandomAdjacent(&tempx, &tempy);
		}
		insertAtTail(tempx, tempy);
	}
	drawSnake(snake);
	
	//start moving snake automatically
	//make a thread of this function: moveSnake()?
	
} // end initSnake()

int moveSnake(Snake* snake) {
	//snake->direction = snake->nextDirection;
	snake->tailx = list.TAIL->x;
	snake->taily = list.TAIL->y;
	
	// If the next direction is the opposite current direction, move is invalid
	if (snake->direction == -(snake->nextDirection))
		return 0;
	
	snake->direction = snake->nextDirection;
	switch(snake->direction) {
		case RIGHT:
			snake->headx++;
			break;
		case LEFT:
 			snake->headx--;
			break;
		case UP:
			snake->heady--;
			break;
		case DOWN:
			snake->heady++;
			break;
		default:
			break;
	} 
	moveHead(snake->headx, snake->heady);
	return 1;
} // end moveSnakeHead()

int coordInBounds(int x, int y) {

	if((x*HORIZONTAL) < 0 || (x*HORIZONTAL) >= WIDTH) {
		return 0;
	} else if((y*VERTICAL) < 0 && (y*HORIZONTAL) >=LENGTH) {
		return 0;
	} else {
		return 1;
	} // end if-else

} // end inBounds()

int inBounds(Snake* snake, int direction) {

	if(((snake->headx-1)*HORIZONTAL) < 0 && direction == LEFT) {
		return 0;
	} else if(((snake->headx+1)*HORIZONTAL) >= WIDTH && direction == RIGHT) {
		return 0;
	} else if(((snake->heady-1)*VERTICAL) < 0 && direction == UP) {
		return 0;
	} else if(((snake->heady+1)*VERTICAL) >= LENGTH && direction == DOWN) {
		return 0;
	} else {
		return 1;
	} // end if-else

} // end inBounds()

void incrementScore(Snake* snake) {

	snake->score = snake->score + 1;
	
} // end incrementScore()

char* getScore(Snake* snake) {

	int temp = snake->score;
	char str[15];
	
	snprintf(str, 15, "%d", temp);

	return str;

} // end getScore()


void drawSnake(Snake* snake) {
	Node* iter = list.HEAD;
	while (iter != NULL) {
		if (iter == list.HEAD)
			DrawSnakeHead((iter->x*HORIZONTAL)+STX, (iter->y*VERTICAL)+STY,
							((iter->x+1)*HORIZONTAL)+STX, ((iter->y+1)*VERTICAL)+STY);
		else 
			DrawSnakeSquare((iter->x*HORIZONTAL)+STX, (iter->y*VERTICAL)+STY,
							((iter->x+1)*HORIZONTAL)+STX, ((iter->y+1)*VERTICAL)+STY);
		iter = iter-> next;
	}
}

void wipeSnake(Snake* snake) {
	Node* iter = list.HEAD;
	while (iter != NULL) {
		ClearSquare((iter->x*HORIZONTAL)+STX, (iter->y*VERTICAL)+STY,
							((iter->x+1)*HORIZONTAL)+STX, ((iter->y+1)*VERTICAL)+STY);
		iter = iter-> next;
	}
}

void getRandomAdjacent(int* x, int* y) {
	int direction = (rand() % 4) + 1;
	switch(direction) {
		case UP:
				(*y)--;
			break;
		case DOWN:
				(*y)++;
			break;
		case LEFT:
				(*x)--;
			break;
		case RIGHT:
				(*x)++;
			break;
	}
}

void killSnake(Snake* snake) 
{
	freeList();
	ClearSquare(STX, STY, WIDTH+STX, LENGTH+STY);
	snake->headx = 0;
	snake->heady = 0;
	snake->tailx = 0;
	snake->taily = 0;
}
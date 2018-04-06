#include "Snake.h"
#include "Globals.h"
#include "Snake.h"
#include "Drawing.h"
#include "DoublyLinkedList.h"

void initSnake(Snake* snake) {
	snake->score = 0;
	snake->size = 1;
	snake->direction = RIGHT;
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

void placeSnake(Snake* snake) {

} // end placeSnake()

void moveSnake(Snake* snake) {
	//while(1){
		//sleep(1 second)
		//find head
		//find front facing by looking for adjacent red tile, and finding the opposite tile
			//if tile is not outofbounds
				//moveSnakeHead(opposite direction of red tile)
			//else 
				//do
					//pick random direction
				//while (random direction is not out of bounds or red tile)
				//moveSnakehead(random)
	//}//end while
} // end moveSnake()

void moveSnakeTail(Snake* snake) {

} // end moveSnakeTail()

void moveSnakeHead(Snake* snake, int direction) {
	snake->direction = direction;
	snake->tailx = list.TAIL->x;
	snake->taily = list.TAIL->y;
	switch(snake->direction) {
		case RIGHT:
			if(snake->direction == LEFT) {
				snake->headx--;
				break;
			} else {
				snake->headx++;
				break;
			} // end if-else
		case LEFT:
			if(snake->direction == RIGHT) {
				snake->headx++;
				break;
			} else {
				snake->headx--;
				break;
			} // end if-else
		case UP:
			if(snake->direction == DOWN) {
				snake->heady++;
				break;
			} else {
				snake->heady--;
				break;
			} // end if-else
		case DOWN:
			if(snake->direction == UP) {
				snake->heady--;
				break;
			} else {
				snake->heady++;
				break;
			} // end if-else
		default:
			break;
	} 
	moveHead(snake->headx, snake->heady);
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












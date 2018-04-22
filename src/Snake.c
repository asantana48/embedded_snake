#include "snake.h"

// Function : initSnake()
// Purpose : Initialize snake structure and display in random position in game environment.
void initSnake(Snake* snake) {
	snake->score = 0;
	snake->size = 1;
	snake->direction = NULL;
	snake->newDirection = NULL;
	snake->tailx = -1;
	snake->taily = -1;
	snake->headx = -1;
	snake->heady = -1;
	
	snake->headx = (rand() % (HORIZONTAL - 10) +5);
	snake->heady = (rand() % (VERTICAL - 10) + 5);
	
	insertAtHead(snake->headx , 	snake->heady);
	snake->tailx = snake->headx ;
	snake->taily = snake->heady;
	
	int i = 0;
	for(i = 0; i < 2; ++i){
		// Move snake randomly
		moveValidRandom(snake);
		insertAtTail(snake->tailx, snake->taily);
		snake->tailx = list.TAIL->x;
		snake->taily = list.TAIL->y;
	} // end for
	
	drawSnake(snake);
	
	media_index = 2;
	pthread_create(NULL, NULL, (void*)playingWave, NULL);
} // end initSnake()

// Function : coordinateInBounds()
// Purpose : Determine whether given coordinate is within game environment bounds.
int coordinateInBounds(int x, int y) {
	if (x*HORIZONTAL < 0 || x * HORIZONTAL >=WIDTH) {
		media_index = 1;
		pthread_create(NULL, NULL, (void*)playingWave, NULL);
		return 0;
	} else if (y*VERTICAL < 0 || y * VERTICAL >= LENGTH) {
		media_index = 1;
		pthread_create(NULL, NULL, (void*)playingWave, NULL);
		return 0;
	} else {
		return 1;
	} // end if-else
} // end coordinateInBounds()

// Function : moveSnake()
// Purpose : Move the current snake structure through doubly linked list.
int moveSnake(Snake* snake) {
	int eatingSelf = 0;
	if (snake->direction == -snake->newDirection)
		return 0;
	
	snake->direction = snake->newDirection;	
	switch(snake->direction) {
		case RIGHT: 	snake->headx++; break;
		case LEFT: snake->headx--; break;
		case UP: snake->heady--; break;
		case DOWN: snake->heady++; break;
		default: break;
	} // end switch 
	
	if (inList(snake->headx, snake->heady)){
		eatingSelf = 1;
		fprintf(stderr, "Eating itself.\n");
	} // end if
			
	moveHead(snake->headx, snake->heady);
	
	fprintf(stderr, "SnakeHead:(%d,%d) | SnakeTail:(%d, %d)\n", snake->headx, snake->heady, snake->tailx, snake->taily);
	if (eatingSelf && !( snake->headx == snake->tailx && snake->heady == snake->taily))
			return 0;	
	if (!coordinateInBounds(snake->headx, snake->heady))
		return 0;
		
	return 1;
} // end moveSnake()

// Function : incrementScore()
// Purpose : Increment the score held within the global snake structure.
void incrementScore(Snake* snake) {
	snake->score = snake->score + 1;
} // end incrementScore()

// Function : getScore() 
// Purpose : Return character representation of score to be displayed to graphics.
void getScore(Snake* snake, char* score) {
	int temp = snake->score;	
	snprintf(score, 15, "%d", temp);
} // end getScore()

// Function : drawSnake()
// Purpose : Iterate through snake structure and draw each snake node to environment.
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
	} // end while
} // end drawSnake()

// Function : wipeSnake()
// Purpose : Clear snake from game environment.
void wipeSnake(Snake* snake) {
	Node* iter = list.HEAD;
	while (iter != NULL) {
		ClearSquare((iter->x*HORIZONTAL)+STX, (iter->y*VERTICAL)+STY,
							((iter->x+1)*HORIZONTAL)+STX, ((iter->y+1)*VERTICAL)+STY);
		iter = iter-> next;
	} // end while
} // end wipeSnake()

// Function : moveValidRandom()
// Purpose : Randomly move snake in new direction.
void moveValidRandom(Snake* snake) {
	int direction[] = {UP, DOWN, LEFT, RIGHT};	
	do{
		int rIndex = rand() % 4;
		snake->newDirection = direction[rIndex];
	} while (!moveSnake(snake));
} // end moveValidRandom()

// Function : slaySnake()
// Purpose : Free allocated memory and reset snake structure.
void slaySnake(Snake* snake) {
	freeList();
	ClearSquare(STX, STY, WIDTH+STX, LENGTH+STY);
	snake->headx = 0;
	snake->heady = 0;
	snake->tailx = 0;
	snake->taily = 0;
} // end slaySnake()

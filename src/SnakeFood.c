#include "SnakeFood.h"

// Function : initSnakeFood()
// Purpose : Initialize snake food structure to random location within game environment.
void initSnakeFood(SnakeFood* snakeFood) {
	do  {
		snakeFood->x = rand() % MAX_H;
		snakeFood->y =  rand() % MAX_V;
	} while (inList(snakeFood->x, snakeFood->y));
	DrawFoodSquare((snakeFood->x*HORIZONTAL)+STX, (snakeFood->y*VERTICAL)+STY,
							((snakeFood->x + 1)*HORIZONTAL)+STX, ((snakeFood->y + 1)*VERTICAL)+STY);
} // end initSnakeFood()

void removeSnakeFood(SnakeFood* snakeFood) {
	ClearSquare((snakeFood->x*HORIZONTAL)+STX, (snakeFood->y*VERTICAL)+STY,
							((snakeFood->x + 1)*HORIZONTAL)+STX, ((snakeFood->y + 1)*VERTICAL)+STY);
	snakeFood->x = -1;
	snakeFood->y = -1;
}

// Function : isScore()
// Purpose : Determine whether current state results in a score state.
int isScore(Snake *snake, SnakeFood *snakeFood) {
	if(snake->headx == snakeFood->x && snake->heady == snakeFood->y) {
		media_index = 0;
		pthread_create(NULL, NULL, (void*)playingWave, NULL);
		return 1;
	} else {
		return 0;
	} // end if-else
} // end isScore()

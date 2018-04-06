#include "Snake.h"
#include "Globals.h"
#include "Drawing.h"
#include "SnakeFood.h"

void initSnakeFood(SnakeFood* snakeFood) {
	time_t t;
	// Make sure we are not placing snake food on top of a snake square
	do  {
		snakeFood->x = (rand() % (HORIZONTAL - 5) +1);
		snakeFood->y = (rand() % (VERTICAL - 5) + 1);
	} while (inList(snakeFood->x, snakeFood->y));
	DrawFoodSquare((snakeFood->x*HORIZONTAL)+STX, (snakeFood->y*VERTICAL)+STY,
							((snakeFood->x + 1)*HORIZONTAL)+STX, ((snakeFood->y + 1)*VERTICAL)+STY);
							
	//init Timer for snake food
} // end initSnakeFood()

int isScore(Snake *snake, SnakeFood *snakeFood) {

	if(snake->headx == snakeFood->x && snake->heady == snakeFood->y) {
		return 1;
	} else {
		return 0;
	} // end if-else

} // end isScore()

//Timer(){
	//this is called when timer ends?
//}
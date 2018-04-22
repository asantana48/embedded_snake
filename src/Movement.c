#include "movement.h"

// Function : move()
// Purpose : Move the snake location within the game environment.
void move() {
	wipeSnake(&snake);	
	if(RUNNING == 1 && moveSnake(&snake)) {
	
	
		if(isScore(&snake, &snakeFood)) {
			incrementScore(&snake);
			char scr[20];
			getScore(&snake, scr);
			PtSetResource(ABW_scoreTextField, Pt_ARG_TEXT_STRING, scr , 0);
			insertAtTail(snake.tailx, snake.taily);
			initSnakeFood(&snakeFood);
			
			PtSetResource(ABW_FoodTimer, Pt_ARG_TIMER_INITIAL, 10000, 0);
		} // end if
		snake.tailx = list.TAIL->x;
		snake.taily = list.TAIL->y;
	} else if (RUNNING != 2){
		RUNNING = 0;
		slaySnake(&snake);
	} // end if-else
	drawSnake(&snake);
} // end move()

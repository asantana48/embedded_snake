#include "Movement.h"

void move()
{
	wipeSnake(&snake);	
	
	if(moveSnake(&snake)) {
		if(isScore(&snake, &snakeFood)) {
			incrementScore(&snake);
			char* scr = getScore(&snake);
			PtSetResource(ABW_scoreTextField, Pt_ARG_TEXT_STRING, scr, 0);
		
			insertAtTail(snake.tailx, snake.taily);
			initSnakeFood(&snakeFood);
		} 
	}
	else {
		RUNNING = 0;
		slaySnake(&snake);
	}
	
	drawSnake(&snake);
}
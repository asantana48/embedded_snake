/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 2.03  */

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "Snake.h"
#include "Globals.h"
#include "Drawing.h"
#include "SnakeFood.h"

int
downButton_ActionPerformed( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	if (!RUNNING)
		return 0;
	
	snake.nextDirection = DOWN;
	
	wipeSnake(&snake);
	/*
	if(inBounds(&snake, DOWN) == 1) {
		moveSnakeHead(&snake, DOWN);
		if(isScore(&snake, &snakeFood)) {
			incrementScore(&snake);
			char* scr = getScore(&snake);
			PtSetResource(ABW_scoreTextField, Pt_ARG_TEXT_STRING, scr, 0);
		
			insertAtTail(snake.tailx, snake.taily);
			initSnakeFood(&snakeFood);
		} //end if
	} // end if
	*/
	
	drawSnake(&snake);
	return( Pt_CONTINUE );

}
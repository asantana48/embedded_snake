// *****************
// Standard Headers
// *****************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// *****************
// Local Headers
// *****************
#include "proto.h"
#include "ablibs.h"
#include "snake.h"
#include "globals.h"
#include "drawing.h"
#include "abimport.h"
#include "snakefood.h"
#include "doublylinkedlist.h"

// Function : press()
// Purpose : Action handler for button press events.
int press( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo ) {
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	int id = ApName(widget);
	
	if(id == ABN_upButton) {
		if(!RUNNING) {
			return 0;
		} // end if
		snake.newDirection = UP;
	} else if(id == ABN_leftButton) {
		if(!RUNNING) {
			return 0;
		} // end if
		snake.newDirection = LEFT;
	} else if(id == ABN_rightButton) {
		if(!RUNNING) {
			return 0;
		} // end if
		snake.newDirection = RIGHT;
	} else if(id == ABN_downButton) {
		if(!RUNNING) {
			return 0;
		} // end if
		snake.newDirection = DOWN;
	} else if(id == ABN_pauseButton) {
		if(RUNNING != 2) {
			RUNNING = 2;
			PtSetResource(ABW_pauseButton, Pt_ARG_TEXT_STRING, "Resume", 0);
		} else if(RUNNING != 0) {
			RUNNING = 1;
			PtSetResource(ABW_pauseButton, Pt_ARG_TEXT_STRING, "Pause", 0);
		} // end if-else
	} else if(id == ABN_newGameButton) {
		if(!SEEDED) {
			srand((unsigned int) time(NULL));
			SEEDED = 1;
		} // end if
		PtSetResource(ABW_scoreTextField, Pt_ARG_TEXT_STRING, "0", 0);
		slaySnake(&snake);
		ClearSquare(STX, STY, WIDTH+STX, LENGTH+STY);
		RUNNING = 1;
		FED = 1;
		
		initSnake(&snake);
		initSnakeFood(&snakeFood);

		PtSetResource(ABW_SnakeTimer, Pt_ARG_TIMER_INITIAL, 1000, 0);
		PtSetResource(ABW_FoodTimer, Pt_ARG_TIMER_INITIAL, 10000, 0);
	} else {
		return 0;
	} // end if-else

	return( Pt_CONTINUE );
} // end press()


/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 2.03  */

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "Globals.h"
#include "Snake.h"
#include "Drawing.h"
#include "SnakeFood.h"
#include "DoublyLinkedList.h"

PtWidget_t* widget0;
ApInfo_t* apinfo0;
PtCallbackInfo_t* cbinfo0;

int restartFood( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo );

int newGameButton_ActionPerformed( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	if (!SEEDED)
	{
		srand((unsigned int) time(NULL));
		SEEDED = 1;
	}
		
	PtSetResource(ABW_scoreTextField, Pt_ARG_TEXT_STRING, "0", 0);
	
	slaySnake(&snake);
	ClearSquare(STX, STY, WIDTH+STX, LENGTH+STY);
	
	RUNNING = 1;
	initSnake(&snake);
	initSnakeFood(&snakeFood);
	
	//get ref to window
	PtWidget_t *this_window = ApGetInstance(widget);
	
	//get ref to timer
	PtWidget_t *timer = ApGetWidgetPtr(this_window, ABN_SnakeTimer);
	
	//init Timer
	PtSetResource(timer, Pt_ARG_TIMER_INITIAL, 1000, 0);

	
	widget0 = widget;
	apinfo0 = apinfo;
	cbinfo0 = cbinfo;
	
	//get ref to window
	PtWidget_t *this_window2 = ApGetInstance(widget);
	
	//get ref to timer
	PtWidget_t *timer2 = ApGetWidgetPtr(this_window2, ABN_FoodTimer);
	
	//init Timer
	PtSetResource(timer2, Pt_ARG_TIMER_INITIAL, 10000, 0);

	return( Pt_CONTINUE );

} // end newGameButton_ActionPerformed()

int restartFood( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	//get ref to window
	PtWidget_t *this_window = ApGetInstance(widget);
	
	//get ref to timer
	PtWidget_t *timer = ApGetWidgetPtr(this_window, ABN_FoodTimer);
	
	//init Timer
	PtSetResource(timer, Pt_ARG_TIMER_INITIAL, 10000, 0);
	
	return 0;
}
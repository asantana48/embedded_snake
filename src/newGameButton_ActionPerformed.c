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
#include "Snake.h"
#include "Globals.h"
#include "Drawing.h"
#include "SnakeFood.h"
#include "DoublyLinkedList.h"

int newGameButton_ActionPerformed( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{

	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	srand((unsigned int) time(NULL));
	freeList();
	
	PtSetResource(ABW_scoreTextField, Pt_ARG_TEXT_STRING, "0", 0);
	
	ClearSquare(STX, STY, WIDTH+STX, LENGTH+STY);
	
	RUNNING = 1;
	initSnake(&snake);
	initSnakeFood(&snakeFood);

	return( Pt_CONTINUE );

} // end newGameButton_ActionPerformed()


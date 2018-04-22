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
#include "Movement.h"

int
rightButton_ActionPerformed( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{

	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	if (!RUNNING)
		return 0;
	
	snake.newDirection = RIGHT;
	move();
	
	return( Pt_CONTINUE );

}


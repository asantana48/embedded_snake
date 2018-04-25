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
#include "SnakeFood.h"

int
foodtimeractivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	if (RUNNING == 1)
	{
		FOODGEN -= 500;	
	}
	if (FOODGEN == 0) {
		removeSnakeFood(&snakeFood);
		initSnakeFood(&snakeFood);
		FOODGEN = 10000;
	}
	return( Pt_CONTINUE );

	}


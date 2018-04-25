// *****************
// Standard Headers
// *****************
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// *****************
// Local Headers
// *****************
#include "proto.h"
#include "ablibs.h"
#include "abimport.h"
#include "Movement.h"

// Function : snaketimeractivate()
// Purpose : If the snake is running then move the snake every timer activation period.
int snaketimeractivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo ) {
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	if(RUNNING) {
		move();
	} // end if

	return( Pt_CONTINUE );
} // end snaketimeractivate()


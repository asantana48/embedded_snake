// *****************
// Standard Headers
// *****************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// *****************
// Local headers
// *****************
#include "proto.h"
#include "ablibs.h"
#include "abimport.h"
#include "wavfactory.h"

// *********************
// Media Global Variables
// *********************
int media_index = 0;
char *musicDir = "/gamesounds/";
char *notes[] = {"pickup.wav", "death.wav", "achievement.wav"};

int initsounds( PtWidget_t *link_instance, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo ) {
	link_instance = link_instance, apinfo = apinfo, cbinfo = cbinfo;

	media_index = 0;
	paused = 0;

	return( Pt_CONTINUE );
}


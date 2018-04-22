#ifndef _WAVFACTORY_H
#define _WAVFACTORY_H

// *****************
// Standard Headers
// *****************
#include <Pt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <gulliver.h>
#include <sys/asoundlib.h>

// **************
// Local Headers
// **************
#include "ablibs.h"
#include "abimport.h"

// ************************
// Constant Global Variables
// ************************
#define SIZE 3

// ***************************
// External Application Variables
// ***************************
extern char *notes[];
extern char *musicDir;
extern int media_index;

// *******************
// Application Variables
// *******************
int paused;
int stopped;
int inFunction;

// ******************
// Function Prototypes
// ******************
void *playingWave();

#endif

#ifndef _HEADER_INCLUDED
#define _HEADER_INCLUDED

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
#include "abimport.h"

// *******************
// Function Prototypes
// *******************
void ClearSquare(int x1, int y1, int x2, int y2);
void DrawSnakeHead(int x1, int y1, int x2, int y2);
void DrawFoodSquare(int x1, int y1, int x2, int y2);
void DrawSnakeSquare(int x1, int y1, int x2, int y2);

#endif

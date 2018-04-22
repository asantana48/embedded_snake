#ifndef _DRAWING_H
#define _DRAWING_H

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"

void ClearSquare(int x1, int y1, int x2, int y2);
void DrawFoodSquare(int x1, int y1, int x2, int y2);
void DrawSnakeHead(int x1, int y1, int x2, int y2);
void DrawSnakeSquare(int x1, int y1, int x2, int y2);

#endif

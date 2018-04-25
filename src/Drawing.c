#include "Drawing.h"

// Function : ClearSquare()
// Purpose : Clear given square dimension within game environment.
void ClearSquare(int x1, int y1, int x2, int y2) {
	PgSetFillColor(Pg_BLACK);
	PgSetStrokeColor(Pg_BLACK);
	PgDrawIRect(x1, y1, x2, y2, Pg_DRAW_FILL_STROKE);
} // end ClearSquare()

// Function : DrawSnakeHead()
// Purpose : Draw snake graphic into game environment.
void DrawSnakeHead(int x1, int y1, int x2, int y2) {
	PgSetFillColor(Pg_YELLOW);
	PgSetStrokeColor(Pg_BLACK);
	PgDrawIRect(x1, y1, x2, y2, Pg_DRAW_FILL_STROKE);
} // end DrawSnakeSquare()

// Function : DrawSnakeSquare()
// Purpose : Draw snake node graphic into game environment.
void DrawSnakeSquare(int x1, int y1, int x2, int y2) {
	PgSetFillColor(Pg_RED);
	PgSetStrokeColor(Pg_BLACK);
	PgDrawIRect(x1, y1, x2, y2, Pg_DRAW_FILL_STROKE);
} // end DrawSnakeSquare()

// Function : DrawFoodSquare() 
// Purpose : Draw food node graphic into game environment.
void DrawFoodSquare(int x1, int y1, int x2, int y2) {
	PgSetFillColor(Pg_GREEN);	
	PgSetStrokeColor(Pg_BLACK);
	PgDrawIRect(x1, y1, x2, y2, Pg_DRAW_FILL_STROKE);
} // end DrawFoodSquare()

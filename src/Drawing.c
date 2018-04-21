#include "Drawing.h"

void ClearSquare(int x1, int y1, int x2, int y2) {
	
	// Creates rectangle object to draw based off dimensions.
	PgSetFillColor(Pg_BLACK);
	
	// Set the color of the rectangle then draw the rectangle to the screen.
	PgSetStrokeColor(Pg_BLACK);
	PgDrawIRect(x1, y1, x2, y2, Pg_DRAW_FILL_STROKE);
	
} // end ClearSquare()

void DrawSnakeHead(int x1, int y1, int x2, int y2) {
	
	// Creates rectangle object to draw based off dimensions.
	PgSetFillColor(Pg_YELLOW);
	
	// Set the color of the rectangle then draw the rectangle to the screen.
	PgSetStrokeColor(Pg_BLACK);
	PgDrawIRect(x1, y1, x2, y2, Pg_DRAW_FILL_STROKE);
	
} // end DrawSnakeSquare()

void DrawSnakeSquare(int x1, int y1, int x2, int y2) {
	
	// Creates rectangle object to draw based off dimensions.
	PgSetFillColor(Pg_RED);
	
	// Set the color of the rectangle then draw the rectangle to the screen.
	PgSetStrokeColor(Pg_BLACK);
	PgDrawIRect(x1, y1, x2, y2, Pg_DRAW_FILL_STROKE);
	
} // end DrawSnakeSquare()

void DrawFoodSquare(int x1, int y1, int x2, int y2) {

	// Creates rectangle object to draw based off dimensions.
	PgSetFillColor(Pg_GREEN);

	// Set the color of the rectangle then draw the rectangle to the screen.	
	PgSetStrokeColor(Pg_BLACK);
	PgDrawIRect(x1, y1, x2, y2, Pg_DRAW_FILL_STROKE);

} // end DrawFoodSquare()

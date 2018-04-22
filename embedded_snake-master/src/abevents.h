/* Event header for application - AppBuilder 2.03  */

static const ApEventLink_t AbApplLinks[] = {
	{ 3, 0, 0L, 0L, 0L, &frame, NULL, NULL, 0, NULL, 0, 0, 0, 0, },
	{ 0 }
	};

static const ApEventLink_t AbLinks_frame[] = {
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "newGameButton", 2009, newGameButton_ActionPerformed, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "leftButton", 2009, leftButton_ActionPerformed, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "upButton", 2009, upButton_ActionPerformed, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "rightButton", 2009, rightButton_ActionPerformed, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "downButton", 2009, downButton_ActionPerformed, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "SnakeTimer", 41002, SnakeTimerActivate, 0, 0, 0, 0, },
	{ 0 }
	};

const char ApOptions[] = AB_OPTIONS;

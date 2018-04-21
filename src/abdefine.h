/* Define header for application - AppBuilder 2.03  */

/* 'frame' Window link */
extern const int ABN_frame;
#define ABW_frame                            AbGetABW( ABN_frame )
extern const int ABN_gameBackground;
#define ABW_gameBackground                   AbGetABW( ABN_gameBackground )
extern const int ABN_newGameButton;
#define ABW_newGameButton                    AbGetABW( ABN_newGameButton )
extern const int ABN_scoreLabel;
#define ABW_scoreLabel                       AbGetABW( ABN_scoreLabel )
extern const int ABN_scoreTextField;
#define ABW_scoreTextField                   AbGetABW( ABN_scoreTextField )
extern const int ABN_leftButton;
#define ABW_leftButton                       AbGetABW( ABN_leftButton )
extern const int ABN_upButton;
#define ABW_upButton                         AbGetABW( ABN_upButton )
extern const int ABN_rightButton;
#define ABW_rightButton                      AbGetABW( ABN_rightButton )
extern const int ABN_downButton;
#define ABW_downButton                       AbGetABW( ABN_downButton )
extern const int ABN_pauseButton;
#define ABW_pauseButton                      AbGetABW( ABN_pauseButton )

/* 'GameOver' Dialog link */
extern const int ABN_GameOver;
#define ABW_GameOver                         AbGetABW( ABN_GameOver )

#define AbGetABW( n ) ( AbWidgets[ n ].wgt )

#define AB_OPTIONS "s:x:y:h:w:S:"

/* Define header for application - AppBuilder 2.03  */

/* 'base' Window link */
extern const int ABN_base;
#define ABW_base                             AbGetABW( ABN_base )
extern const int ABN_gameBackground;
#define ABW_gameBackground                   AbGetABW( ABN_gameBackground )
extern const int ABN_scoreLabel;
#define ABW_scoreLabel                       AbGetABW( ABN_scoreLabel )
extern const int ABN_scoreTextField;
#define ABW_scoreTextField                   AbGetABW( ABN_scoreTextField )
extern const int ABN_upButton;
#define ABW_upButton                         AbGetABW( ABN_upButton )
extern const int ABN_leftButton;
#define ABW_leftButton                       AbGetABW( ABN_leftButton )
extern const int ABN_rightButton;
#define ABW_rightButton                      AbGetABW( ABN_rightButton )
extern const int ABN_downButton;
#define ABW_downButton                       AbGetABW( ABN_downButton )
extern const int ABN_pauseButton;
#define ABW_pauseButton                      AbGetABW( ABN_pauseButton )
extern const int ABN_newGameButton;
#define ABW_newGameButton                    AbGetABW( ABN_newGameButton )
extern const int ABN_SnakeTimer;
#define ABW_SnakeTimer                       AbGetABW( ABN_SnakeTimer )
extern const int ABN_FoodTimer;
#define ABW_FoodTimer                        AbGetABW( ABN_FoodTimer )

#define AbGetABW( n ) ( AbWidgets[ n ].wgt )

#define AB_OPTIONS "s:x:y:h:w:S:"

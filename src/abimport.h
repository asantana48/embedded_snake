/* Import (extern) header for application - AppBuilder 2.03  */

#include "abdefine.h"

extern ApWindowLink_t frame;
extern ApDialogLink_t GameOver;
extern ApWidget_t AbWidgets[ 11 ];


#ifdef __cplusplus
extern "C" {
#endif
int newGameButton_ActionPerformed( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int rightButton_ActionPerformed( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int downButton_ActionPerformed( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int leftButton_ActionPerformed( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int upButton_ActionPerformed( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
#ifdef __cplusplus
}
#endif

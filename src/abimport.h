/* Import (extern) header for application - AppBuilder 2.03  */

#include "abdefine.h"

extern ApWindowLink_t base;
extern ApWidget_t AbWidgets[ 12 ];


#ifdef __cplusplus
extern "C" {
#endif
int initsounds( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int snaketimeractivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int press( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int foodtimeractivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
#ifdef __cplusplus
}
#endif

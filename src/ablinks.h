/* Link header for application - AppBuilder 2.03  */

extern ApContext_t AbContext;

ApWindowLink_t frame = {
	"frame.wgtw",
	&AbContext,
	AbLinks_frame, 0, 6
	};

ApDialogLink_t GameOver = {
	"GameOver.wgtd",
	&AbContext,
	NULL, 10, 0
	};


/****************************************/
/*Author     : Ahmad Akram              */
/*Description: Program file For GIE     */
/*Date       : 4 june 2021              */
/*Version    : 1.0V                     */
/****************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "GIE_int.h"
#include "GIE_cfg.h"
#include "GIE_priv.h"

void GIE_VoidEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_VoidDisable(void)
{
	CLEAR_BIT(SREG,7);
}

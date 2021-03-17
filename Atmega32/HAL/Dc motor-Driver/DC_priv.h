/***************************************/
/*Author     : Ahmad Akram             */
/*Description: DC-motor Private File   */
/*Date       : 17/3/2021               */
/*Version    : 1.0V                    */
/***************************************/

#ifndef DC_PRIV_H
#define DC_PRIV_H

#define DC_u8CW   0
#define DC_u8CCW  10

typedef struct
{
	u8 u8Pin0;
	u8 u8Pin1;
	
}TStrDcPins;

extern TStrDcPins AStrDcPinCfg[DC_MAXNB];

#endif
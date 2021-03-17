/***************************************/
/*Author     : Ahmad Akram             */
/*Description: DC-motor Config.c File  */
/*Date       : 17/3/2021               */
/*Version    : 1.0V                    */
/***************************************/
#include "STD_types.H"
#include "BIT_math.H"

#include "DIO_int.h"
#include "DC_cfg.h"
#include "DC_priv.h"

TStrDcPins AStrDcPinCfg[DC_MAXNB]={
	
	{DIO_PIN_4 , DIO_PIN_5},
	{DIO_PIN_6 , DIO_PIN_7}

};
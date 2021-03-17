/***************************************/
/*Author     : Ahmad Akram             */
/*Description: DC-motor Program File   */
/*Date       : 17/3/2021               */
/*Version    : 1.0V                    */
/***************************************/
#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"

#include "DC_int.h"
#include "DC_cfg.h"
#include "DC_priv.h"


void DC_VoidInit(void)
{
	u8 u8DcNbLoc;
	
	/**!Comment : Stop All DC-Motors            */
	for(u8DcNbLoc=0; u8DcNbLoc<DC_MAXNB; u8DcNbLoc++)
	{
		DC_VoidStop(u8DcNbLoc);
	}
	
}

ERRORSTATUS DC_VoidStop(u8 u8MotorNbCpy)
{
	ERRORSTATUS EnuErrStatLoc= OK;
	
	/**!Comment : Check DC-Motor ID             */
	if(u8MotorNbCpy>=DC_MAXNB)
	{
		EnuErrStatLoc=INDEX_OUT_OF_RANGE;
	}
	else
	{
		DIO_VoidSetPinValue(AStrDcPinCfg[u8MotorNbCpy].u8Pin0, DIO_u8LOW);
		DIO_VoidSetPinValue(AStrDcPinCfg[u8MotorNbCpy].u8Pin1, DIO_u8LOW);
	}
	return EnuErrStatLoc;
}

ERRORSTATUS DC_VoidMove(u8 u8MotorNbCpy,u8 u8DirectionCpy)
{
	ERRORSTATUS EnuErrStatLoc= OK;
	
	/**!Comment : Check DC-Motor ID and DIR     */
	if(u8MotorNbCpy>=DC_MAXNB)
	{
		EnuErrStatLoc= INDEX_OUT_OF_RANGE;
	}
	else
	{
		switch(u8DirectionCpy)
		{
			case DC_u8CW:
			DIO_VoidSetPinValue(AStrDcPinCfg[u8MotorNbCpy].u8Pin0, DIO_u8HIGH);
			DIO_VoidSetPinValue(AStrDcPinCfg[u8MotorNbCpy].u8Pin1, DIO_u8LOW);
			break;
			case DC_u8CCW:
			DIO_VoidSetPinValue(AStrDcPinCfg[u8MotorNbCpy].u8Pin0, DIO_u8LOW);
			DIO_VoidSetPinValue(AStrDcPinCfg[u8MotorNbCpy].u8Pin1, DIO_u8HIGH);
			break;
			default :
			EnuErrStatLoc= NOK;
		}
	}
	return EnuErrStatLoc;
}















#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"

#include "SSEG_int.h"
#include "SSEG_cfg.h"
#include "SSEG_priv.h"


ERRORSTATUS SSEG_EnuWriteNb(u8 u8ChNbCpy, u8 u8NbCpy)
{
	ERRORSTATUS EnuErrorStatLoc= OK;
	
	#if SSEG_u8MODE == COMMON_ANODE
	u8  Seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	#else 	
	u8 Seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};	
	#endif
	
	if(u8ChNbCpy>SSEG_MAXNB || u8NbCpy>9)
	{
		ERRORSTATUS EnuErrorStatLoc= INDEX_OUT_OF_RANGE;
	}
	else
	{
		DIO_VoidSetPinValue(AStr7SegCfg[u8ChNbCpy].u8Pin_A , GET_BIT(Seg[u8NbCpy],0));
		DIO_VoidSetPinValue(AStr7SegCfg[u8ChNbCpy].u8Pin_B , GET_BIT(Seg[u8NbCpy],1));
		DIO_VoidSetPinValue(AStr7SegCfg[u8ChNbCpy].u8Pin_C , GET_BIT(Seg[u8NbCpy],2));
		DIO_VoidSetPinValue(AStr7SegCfg[u8ChNbCpy].u8Pin_D , GET_BIT(Seg[u8NbCpy],3));
		DIO_VoidSetPinValue(AStr7SegCfg[u8ChNbCpy].u8Pin_E , GET_BIT(Seg[u8NbCpy],4));
		DIO_VoidSetPinValue(AStr7SegCfg[u8ChNbCpy].u8Pin_F , GET_BIT(Seg[u8NbCpy],5));
		DIO_VoidSetPinValue(AStr7SegCfg[u8ChNbCpy].u8Pin_G , GET_BIT(Seg[u8NbCpy],6));
		DIO_VoidSetPinValue(AStr7SegCfg[u8ChNbCpy].u8Pin_CM, GET_BIT(Seg[u8NbCpy],7));
	}

	
	return EnuErrorStatLoc;
}
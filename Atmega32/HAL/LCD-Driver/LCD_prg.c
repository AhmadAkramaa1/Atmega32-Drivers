/*************************************/
/* Author      : Ahmad Akram         */
/* Description : LCD Program file    */
/* Date        : 25 FEB 2021         */
/* Version     : 1.0V                */
/*************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include <util/delay.h>

#include "DIO_int.h"

#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"


void LCD_VoidInit()
{
	DIO_VoidSetPinValue(LCD_EN,DIO_u8LOW);
	LCD_VoidSendCmd(0x38);           
	_delay_ms(1);
	LCD_VoidSendCmd(0x0F);             
	_delay_ms(1);
	LCD_VoidSendCmd(0x01);
	_delay_ms(2);
	LCD_VoidSendCmd(0x06);
	_delay_ms(1);
}
void LCD_VoidSendCmd(u8 u8CmdCpy)
{
	DIO_VoidSetPinValue(LCD_RS,DIO_u8LOW);
	VoidPutOnBus(u8CmdCpy);
	
}
void LCD_VoidSendChar(u8 u8CharCpy)
{
	DIO_VoidSetPinValue(LCD_RS,DIO_u8HIGH);
	VoidPutOnBus(u8CharCpy);
}

void LCD_VoidSendString(u8* u8PtrArrCpy)
{
	u8 u8CtrLoc=0;
	while(u8PtrArrCpy[u8CtrLoc] != '\0')
	{
		LCD_VoidSendChar(u8PtrArrCpy[u8CtrLoc]);
		u8CtrLoc++;
		if(u8CtrLoc==30)
		{
			break;
		/*	u8PtrArrCpy[u8CtrLoc]='\0';    //wrong line, can't modify string letters */
		}
		else
		{}	
	}
}

static void VoidPutOnBus(u8 u8DataOrCmdCpy)
{
	DIO_VoidSetPinValue(LCD_RW,DIO_u8LOW);
	DIO_VoidSetPinValue(LCD_EN,DIO_u8HIGH);
	
	DIO_VoidSetPinValue( LCD_D0 ,  GET_BIT(u8DataOrCmdCpy,0));
	DIO_VoidSetPinValue( LCD_D1 ,  GET_BIT(u8DataOrCmdCpy,1));
	DIO_VoidSetPinValue( LCD_D2 ,  GET_BIT(u8DataOrCmdCpy,2));
	DIO_VoidSetPinValue( LCD_D3 ,  GET_BIT(u8DataOrCmdCpy,3));
	DIO_VoidSetPinValue( LCD_D4 ,  GET_BIT(u8DataOrCmdCpy,4));
	DIO_VoidSetPinValue( LCD_D5 ,  GET_BIT(u8DataOrCmdCpy,5));
	DIO_VoidSetPinValue( LCD_D6 ,  GET_BIT(u8DataOrCmdCpy,6));
	DIO_VoidSetPinValue( LCD_D7 ,  GET_BIT(u8DataOrCmdCpy,7));
	
	_delay_ms(1);
	DIO_VoidSetPinValue(LCD_EN,DIO_u8LOW);
	_delay_ms(2);
}
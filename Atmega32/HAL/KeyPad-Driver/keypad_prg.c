/****************************************/
/*Author      : Ahmad Akram             */
/*Description : Keypad Program file     */
/*Date        : 4/3/2021                */
/*Version     : 1.0V                    */
/****************************************/
#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"

#include "Keypad_int.h"
#include "Keypad_cfg.h"
#include "Keypad_priv.h"


void Keypad_VoidInit(void)
{
	
	/*******************************************************/
	/**!Comment : activate Pullup Resistors For input pins */
	/*******************************************************/
	DIO_VoidSetPinValue(KEYPAD_u8INPUT0,DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_u8INPUT1,DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_u8INPUT2,DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_u8INPUT3,DIO_u8HIGH);
	
	/**************************************************/
	/**!Comment : Initialize output pins as high seq  */
	/**************************************************/
	DIO_VoidSetPinValue(KEYPAD_u8OUTPUT0,DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_u8OUTPUT1,DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_u8OUTPUT2,DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_u8OUTPUT3,DIO_u8HIGH);
	
}

u8 Keypad_u8GetPressedKey(void)
{
	u8 u8ReadedKeyLoc;
	u8 u8ReturnValLoc;
	/********************************************************/
	/**!Comment : start first sequence R4R3R2R1             */
	/**                                 1 1 1 0             */
	/********************************************************/
	DIO_VoidSetPinValue(KEYPAD_u8OUTPUT0,DIO_u8LOW);
	DIO_VoidSetPinValue(KEYPAD_u8OUTPUT1,DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_u8OUTPUT2,DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_u8OUTPUT3,DIO_u8HIGH);
	/********************************************************/
	/**!Comment : Read input from first sequence C4C3C2C1   */
	/********************************************************/
	u8ReadedKeyLoc=u8ReadKey();
	switch(u8ReadedKeyLoc)
	{

		case 0b00001110 :              
			u8ReturnValLoc = BUTTON_0;
		break;
		case 0b00001101 :
			u8ReturnValLoc = BUTTON_1;
		break;
		case 0b00001011 :
			u8ReturnValLoc = BUTTON_2;
		break;
		case 0b00000111 :
			u8ReturnValLoc = BUTTON_3;
		break;
		default :
			u8ReturnValLoc =0xFF;
	}
	if(u8ReturnValLoc == 0xFF)
	{
		/*********************************************************/
		/**!Comment : start Second sequence R4R3R2R1             */
		/**                                  1 1 0 1             */
		/*********************************************************/
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT0,DIO_u8HIGH);
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT1,DIO_u8LOW);
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT2,DIO_u8HIGH);
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT3,DIO_u8HIGH);
		/*********************************************************/
		/**!Comment : Read input from Second sequence C4C3C2C1   */
		/*********************************************************/
		u8ReadedKeyLoc=u8ReadKey();
		switch(u8ReadedKeyLoc)
		{
	
			case 0b00001110 :              
				u8ReturnValLoc = BUTTON_4;
			break;
			case 0b00001101 :
				u8ReturnValLoc = BUTTON_5;
			break;
			case 0b00001011 :
				u8ReturnValLoc = BUTTON_6;
			break;
			case 0b00000111 :
				u8ReturnValLoc = BUTTON_7;
			break;
			default :
				u8ReturnValLoc =0xFF;
		}
	}
	if(u8ReturnValLoc == 0xFF)
	{
		/********************************************************/
		/**!Comment : start Third sequence R4R3R2R1             */
		/**                                 1 0 1 1             */
		/********************************************************/
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT0,DIO_u8HIGH);
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT1,DIO_u8HIGH);
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT2,DIO_u8LOW);
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT3,DIO_u8HIGH);
		/********************************************************/
		/**!Comment : Read input from Third sequence C4C3C2C1   */
		/********************************************************/
		u8ReadedKeyLoc=u8ReadKey();
		switch(u8ReadedKeyLoc)
		{
	
			case 0b00001110 :              
				u8ReturnValLoc = BUTTON_8;
			break;
			case 0b00001101 :
				u8ReturnValLoc = BUTTON_9;
			break;
			case 0b00001011 :
				u8ReturnValLoc = BUTTON_10;
			break;
			case 0b00000111 :
				u8ReturnValLoc = BUTTON_11;
			break;
			default :
				u8ReturnValLoc =0xFF;
		}
	}
	if(u8ReturnValLoc == 0xFF)
	{
		/*********************************************************/
		/**!Comment : start fourth sequence R4R3R2R1             */
		/**                                  0 1 1 1             */
		/*********************************************************/
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT0,DIO_u8HIGH);
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT1,DIO_u8HIGH);
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT2,DIO_u8HIGH);
		DIO_VoidSetPinValue(KEYPAD_u8OUTPUT3,DIO_u8LOW);
		/*********************************************************/
		/**!Comment : Read input from fourth sequence C4C3C2C1   */
		/*********************************************************/
		u8ReadedKeyLoc=u8ReadKey();
		switch(u8ReadedKeyLoc)
		{
			
			case 0b00001110 :              
				u8ReturnValLoc = BUTTON_12;
			break;
			case 0b00001101 :
				u8ReturnValLoc = BUTTON_13;
			break;
			case 0b00001011 :
				u8ReturnValLoc = BUTTON_14;
			break;
			case 0b00000111 :
				u8ReturnValLoc = BUTTON_15;
			break;
			default :
				u8ReturnValLoc =0xFF;
		}
	}
	return u8ReturnValLoc;
}
static u8 u8ReadKey(void)
{
	u8 ReturnKeyLoc;
	
	ReturnKeyLoc = DIO_u8GetPinValue(KEYPAD_u8INPUT0);
	ReturnKeyLoc |= DIO_u8GetPinValue(KEYPAD_u8INPUT1)<<1;
	ReturnKeyLoc |= DIO_u8GetPinValue(KEYPAD_u8INPUT2)<<2;
	ReturnKeyLoc |= DIO_u8GetPinValue(KEYPAD_u8INPUT3)<<3;
	
	return ReturnKeyLoc;
	
}
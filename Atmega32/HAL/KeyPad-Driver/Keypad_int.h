/****************************************/
/*Author      : Ahmad Akram             */
/*Description : Keypad Interface file   */
/*Date        : 4/3/2021                */
/*Version     : 1.0V                    */
/****************************************/
#ifndef KEYPAD_INT_H
#define KEYPAD_INT_H



/********************************************/
/**Description : Intialize keypad           */
/*				 -activate pullup Resistors */
/*				 -Make all Output Rows = 1  */
/********************************************/
void Keypad_VoidInit(void);

/********************************************/
/**Description :-pressed key is from 0->15  */
/*				-In case "0xFF"             */
/*				 {No key is Pressed}        */
/********************************************/
/*  Keypad Order :                          */
/*                    0  1  2  3            */
/*                    4  5  6  7            */
/*                    8  9  A  B            */
/*                    C  D  E  F            */
/********************************************/
u8 Keypad_u8GetPressedKey(void);



#endif









/*************************************/
/* Author      : Ahmad Akram         */
/* Description : LCD Interface file  */
/* Date        : 25 FEB 2021         */
/* Version     : 1.0V                */
/*************************************/

#ifndef LCD_INT_H
#define LCD_INT_H

/**       SET OF COMMANDS        */
#define CLEAR_ALL        0x01
#define RM_CURSOR        0x0C
#define Cursor_BLINK     0x0F
#define CURSOR_NO_BLINK  0x0E

#define CURSOR_MV_RIGHT  0x14 
#define CURSOR_MV_LEFT   0x10
#define DISP_MV_RIGHT    0x1C
#define DISP_MV_LEFT     0x18

#define DISP_ONE_LINE    0x30
#define DISP_TWO_LINES   0x38

#define GOTO_CGRAM       0x40
#define FIRST_LINE       0x80
#define SECOND_LINE      0xC0

/*****************************************/
/** Description: LCD Initialization func */
/*****************************************/
void LCD_VoidInit();

/*****************************************/
/** Input:                               */
/**       u8cmdcpy: Choose From          */
/**                 "SET OF COMMANDS"    */
/*****************************************/
void LCD_VoidSendCmd(u8 u8CmdCpy);

/******************************************/
/** Description: Send Data or NB In ASCII */
/**				 Format                   */
/******************************************/
/** Examples: 's','N','B','I','1','2'...  */
/******************************************/
/**      0,1,2,3,4,5,6,7 in case of CGRAM */
/******************************************/
void LCD_VoidSendChar(u8 u8CharCpy);

/********************************************/
/** Description: Send STRING 30 Letters Max */
/********************************************/
/** Examples: "I Am a Pro" , "AHMAD"        */
/********************************************/
void LCD_VoidSendString(u8* u8PtrArrCpy);

#endif



















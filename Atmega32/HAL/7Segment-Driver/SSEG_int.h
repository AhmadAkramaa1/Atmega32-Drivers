/*******************************************/
/*Author      : Ahmad Akram                */
/*Description : 7SEG Interface file        */
/*Date        : 7/3/2021                   */
/*Version     : 1.0V                       */
/*******************************************/

#ifndef SSEG_INT_H
#define SSEG_INT_H


/**********************************************/
/**Inputs:                                    */
/**	  u8ChNbCpy : There are 2 7Segments  0,1  */
/**	  u8NbCpy   : Nb From 0 To 9              */
/**********************************************/

ERRORSTATUS SSEG_EnuWriteNb(u8 u8ChNbCpy, u8 u8NbCpy);



#endif









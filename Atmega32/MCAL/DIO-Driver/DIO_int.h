/***************************************/
/*Author     : Ahmad akram             */
/*description: Interface file for DIO  */
/*Date       : 13 FEB 2021             */
/*Version    : 1.0V                    */
/***************************************/

#ifndef DIO_INT_H
#define DIO_INT_H

/*             Pin Value              */
#define DIO_u8HIGH   1
#define DIO_u8LOW    0

/*             Pin Direction          */
#define DIO_u8OUTPUT 1
#define DIO_u8INPUT  0

/*             PortA Pins             */
#define DIO_PIN_0    0
#define DIO_PIN_1    1
#define DIO_PIN_2    2
#define DIO_PIN_3    3
#define DIO_PIN_4    4
#define DIO_PIN_5    5
#define DIO_PIN_6    6
#define DIO_PIN_7    7
/*             PortB Pins             */
#define DIO_PIN_8    8
#define DIO_PIN_9    9
#define DIO_PIN_10   10
#define DIO_PIN_11   11
#define DIO_PIN_12   12
#define DIO_PIN_13   13
#define DIO_PIN_14   14
#define DIO_PIN_15   15
/*             PortC Pins             */
#define DIO_PIN_16   16
#define DIO_PIN_17   17
#define DIO_PIN_18   18
#define DIO_PIN_19   19
#define DIO_PIN_20   20
#define DIO_PIN_21   21
#define DIO_PIN_22   22
#define DIO_PIN_23   23
/*             PortD Pins             */
#define DIO_PIN_24   24
#define DIO_PIN_25   25
#define DIO_PIN_26   26
#define DIO_PIN_27   27
#define DIO_PIN_28   28
#define DIO_PIN_29   29
#define DIO_PIN_30   30
#define DIO_PIN_31   31

/*****************************************/
/**!Comment :  initalization function    */
/*****************************************/
void DIO_VoidInit(void);

/********************************************/
/** INPUTS :                                */
/**        u8PinNbCpy  : DIO_PIN_x          */
/**                      x in Range[0... 31]*/
/**        u8PinValueCpy : DIO_u8HIGH       */
/**                        DIO_u8LOW        */
/********************************************/
void DIO_VoidSetPinValue(u8 u8PinNbCpy,u8 u8PinValueCpy);

/********************************************/
/** INPUTS :                                */
/**        u8PinNbCpy  : DIO_PIN_x          */
/**                      x in Range[0... 31]*/
/**        u8PinDirCpy : DIO_u8OUTPUT       */
/**                      DIO_u8INPUT        */
/********************************************/
void DIO_VoidSetPinDirection(u8 u8PinNbCpy,u8 u8PinDirCpy);

/********************************************/
/** INPUTS :                                */
/**        u8PinNbCpy  : DIO_PIN_x          */
/**                      x in Range[0... 31]*/
/********************************************/
u8 DIO_u8GetPinValue(u8 u8PinNbCpy);

#endif
/***************************************/
/*Author     : Ahmad akram             */
/*description: Private file for DIO    */
/*Date       : 13 FEB 2021             */
/*Version    : 1.0V                    */
/***************************************/

#ifndef DIO_PRIV_H
#define DIO_PRIV_H

#define DIO_u8OUTPUT 1
#define DIO_u8INPUT  0

#define DDRA  *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA  *((volatile u8*)0x39)

#define DDRB  *((volatile u8*)0x37)
#define PORTB *((volatile u8*)0x38)
#define PINB  *((volatile u8*)0x36)

#define DDRC  *((volatile u8*)0x34)
#define PORTC *((volatile u8*)0x35)
#define PINC  *((volatile u8*)0x33)

#define DDRD  *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)
#define PIND  *((volatile u8*)0x30)

#endif
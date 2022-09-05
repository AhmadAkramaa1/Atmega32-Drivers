/**************************************/
/*Author     : Ahmad Akram            */
/*Description: TWI Private File       */
/*Date       : 3 Sept 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef TWI_PRIV_H
#define TWI_PRIV_H


#define TWCR (*((volatile u8*)0x56))

#define TWDR (*((volatile u8*)0x23))
#define TWAR (*((volatile u8*)0x22))
#define TWSR (*((volatile u8*)0x21))
#define TWBR (*((volatile u8*)0x20))

#define REACT    1
#define IGNORE   0


#endif
/**************************************/
/*Author     : Ahmad Akram            */
/*Description: SPI Private File       */
/*Date       : 28 Aug 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef SPI_PRIV_H
#define SPI_PRIV_H



#define SPDR (*((volatile u8*)0x2F))
#define SPSR (*((volatile u8*)0x2E))
#define SPCR (*((volatile u8*)0x2D))

#define   MASTER       1
#define   SLAVE        2

#define   MSB_FIRST    5
#define   LSB_FIRST    6

#define   DIVBY_4      4
#define   DIVBY_8      8
#define   DIVBY_16     16
#define   DIVBY_32     32
#define   DIVBY_64     64
#define   DIVBY_128    128

#define   IDLE_LOW     10
#define   IDLE_HIGH    11

#define   SAMPLE_LEAD_SETUP_TRAIL 20
#define   SETUP_LEAD_SAMPLE_TRAIL 21



#endif
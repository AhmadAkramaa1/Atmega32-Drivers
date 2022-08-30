/**************************************/
/*Author     : Ahmad Akram            */
/*Description: SPI Configuration File */
/*Date       : 28 Aug 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef SPI_CFG_H
#define SPI_CFG_H

/*****************************/
/**MODE = MASTER             */
/**       SLAVE              */
/*****************************/
#define MODE MASTER 

/*****************************/
/**DATAORDER = MSB_FIRST     */
/**            LSB_FIRST     */
/*****************************/
#define DATAORDER LSB_FIRST

/*****************************/
/**PRESCALER = DIVBY_4       */
/**            DIVBY_8       */
/**            DIVBY_16      */
/**            DIVBY_32      */
/**            DIVBY_64      */
/**            DIVBY_128     */
/*****************************/
#define PRESCALER DIVBY_4

/*****************************/
/**CLKPOL = IDLE_LOW         */
/**         IDLE_HIGH        */
/*****************************/
#define CLKPOL IDLE_LOW

/*****************************/
/**CLKPHA =                  */
/**  SAMPLE_LEAD_SETUP_TRAIL */
/**  SETUP_LEAD_SAMPLE_TRAIL */
/*****************************/
#define CLKPHA SAMPLE_LEAD_SETUP_TRAIL


#endif
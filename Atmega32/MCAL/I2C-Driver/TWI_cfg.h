/**************************************/
/*Author     : Ahmad Akram            */
/*Description: TWI Configuration File */
/*Date       : 3 Sept 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef TWI_CFG_H
#define TWI_CFG_H

/****************************************/
/** -while in Master Mode :             */
/**       PRESCALER_MCLK must be >= 10  */
/**                                     */
/** -SCL = FOSC/(16+2*(PRESCALER_MCLK)) */
/****************************************/

#define FOSC            8000000UL

#define PRESCALER_MCLK  10UL

/****************************************/
/**GENERALCALL = REACT                  */
/**              IGNORE                 */
/****************************************/
#define GENERALCALL     REACT  



#endif
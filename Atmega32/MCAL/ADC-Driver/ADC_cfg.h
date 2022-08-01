/**************************************/
/*Author     : Ahmad Akram            */
/*Description: ADC Configuration File */
/*Date       : 30 jun 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef ADC_CFG_H
#define ADC_CFG_H


#define Vref        AVCC              //AVCC, AREF, INTERNAL

#define ADJUSTMENT  RIGHT             //RIGHT or LEFT
	
#define RESOLUTION  EIGHT             //EIGHT or TEN
	
#define TRIG_SOURCE FREE_RUNNING_MODE //8 different modes, choose one to start with
	
#define PRESCALER   DIVBY_64          //DIVBY_64 or DIVBY_128


#endif


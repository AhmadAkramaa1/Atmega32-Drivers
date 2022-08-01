/**************************************/
/*Author     : Ahmad Akram            */
/*Description: ADC Private File       */
/*Date       : 30 jun 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef ADC_PRIV_H
#define ADC_PRIV_H
 

#define RIGHT                5   //RIGHT or LEFT
#define LEFT                 15  

#define EIGHT                8   //EIGHT or TEN
#define TEN                  10  

#define DIVBY_64             64  //Fcpu divby 64 or 128
#define DIVBY_128            128  



#define SFIOR   (*((volatile u8*)0x50))

#define ADMUX   (*((volatile u8*)0x27))
#define	ADCSRA  (*((volatile u8*)0x26))
#define ADCH    (*((volatile u8*)0x25))
#define ADCL    (*((volatile u8*)0x24))





#endif
/********************************/
/* author      : ahmad akram    */
/* description : BITMATH library*/
/* date        : 26/7/2019      */
/* version     : 1.0v           */
/********************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(reg,bit) (reg|=(1<<bit))
#define CLEAR_BIT(reg,bit) (reg&=~(1<<bit))
#define TOGGLE_BIT(reg,bit) (reg^=(1<<bit))
#define GET_BIT(reg,bit) ((reg>>bit)&(0x01))

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)       CONC_help(b7,b6,b5,b4,b3,b2,b1,b0) //to replace macros to numbers first
#define CONC_help(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0  //then concatenate

#endif


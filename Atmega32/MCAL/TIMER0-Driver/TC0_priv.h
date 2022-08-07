/**************************************/
/*Author     : Ahmad Akram            */
/*Description: TC0 Private File       */
/*Date       : 3 Aug 2022             */
/*Version    : 1.0v                   */
/**************************************/

#ifndef TC0_PRIV_H
#define TC0_PRIV_H


#define TCCR0 (*((volatile u8*)0x53))

#define TCNT0 (*((volatile u8*)0x52))
#define OCR0  (*((volatile u8*)0x5c))

#define TIMSK (*((volatile u8*)0x59))
#define TIFR  (*((volatile u8*)0x58))


#define NORMAL           50
#define CTC              51
#define FAST_PWM         52
#define PHASE_PWM        53

#define NC_OFF           14    
#define NC_TOGGLE        11
#define NC_CLEAR         12
#define NC_SET           13

#define FPH_OFF          20
#define F_CMP0TOP1       23
#define F_CMP1TOP0       27
#define PH_CMPUP0CMPD1   24
#define PH_CMPUP1CMPD0   29


#define DIVBY_1          1
#define DIVBY_8          8
#define DIVBY_64         64
#define DIVBY_256        25
#define DIVBY_1024       10
#define EXT_T0FALLEDGE   0
#define EXT_T0RISEEDGE   5



#endif
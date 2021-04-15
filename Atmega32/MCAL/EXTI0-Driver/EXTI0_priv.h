/****************************************/
/*Author     : Ahmad Akram              */
/*Description: Private file For EXTI0   */
/*Date       : 4 june 2021              */
/*Version    : 1.0                      */
/****************************************/

#ifndef EXTI0_PRIV_H
#define EXTI0_PRIV_H

#define FALLING_EDGE 1
#define RISING_EDGE  3
#define LOW_LEVEL    5
#define IOC          7

#define MCUCR   *((volatile u8*)0x55)
#define GICR    *((volatile u8*)0x5B)
#define GIFR    *((volatile u8*)0x5A)


#endif
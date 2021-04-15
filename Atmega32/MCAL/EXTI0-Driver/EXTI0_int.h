/****************************************/
/*Author     : Ahmad Akram              */
/*Description: Interface file For EXTI0 */
/*Date       : 4 june 2021              */
/*Version    : 1.0                      */
/****************************************/


#ifndef EXTI0_INT_H
#define EXTI0_INT_H

#define FALLING_EDGE 1
#define RISING_EDGE  3
#define LOW_LEVEL    5
#define IOC          7

/*************************************/
/*Descr: -initialize configuration   */
/*	     -disable interrupt		   	 */
/*	     -clear flag       		   	 */
/*************************************/
void EXTI0_VoidInit(void);

/*************************************/
/*	enable interrupt		   		 */
/*************************************/
void EXTI0_VoidEnable(void);

/*************************************/
/*	disable interrupt		   		 */
/*************************************/
void EXTI0_VoidDisable(void);

/*************************************/
/*u8ModeCpy: write down diff modes   */
/*  			-FALLING_EDGE 		 */
/*  			-RISING_EDGE  		 */
/*  			-LOW_LEVEL    		 */
/*  			-IOC				 */
/*************************************/
/*  IOC -> Interrupt on change		 */
/*************************************/
void EXTI0_VoidChMode(u8 u8ModeCpy);

/***********************************************/
/*u8FuncNameCpy: write your app funcname -(ISR)*/
/***********************************************/
void EXTI0_VoidCallBackFunc(PF u8FuncNameCpy);


#endif
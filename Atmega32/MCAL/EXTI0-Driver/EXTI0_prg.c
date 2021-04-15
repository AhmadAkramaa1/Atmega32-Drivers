/****************************************/
/*Author     : Ahmad Akram              */
/*Description: Program file For EXTI0   */
/*Date       : 4 june 2021              */
/*Version    : 1.0                      */
/****************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "EXTI0_int.h"
#include "EXTI0_cfg.h"
#include "EXTI0_priv.h"

volatile PF EXTI0_PfCallBackAdd = NULL ;

void EXTI0_VoidInit(void)
{
	#if MODE == IOC
		CLEAR_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);

	#elif MODE == FALLING_EDGE
		SET_BIT(MCUCR,1);
		CLEAR_BIT(MCUCR,0);
		
	#elif MODE == RISING_EDGE
		SET_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);
	
	#else
	/**!Comment: default is LOW_LEVEL */
		CLEAR_BIT(MCUCR,1);
		CLEAR_BIT(MCUCR,0);
		
	#endif
	
	/* Disable interrupt */
	CLEAR_BIT(GICR,6);
	
	/* Clear flag        */
	SET_BIT(GIFR,6);
}

void EXTI0_VoidEnable(void)
{
	SET_BIT(GICR,6);
}

void EXTI0_VoidDisable(void)
{
	CLEAR_BIT(GICR,6);
}

void EXTI0_VoidChMode(u8 u8ModeCpy)
{
	switch(u8ModeCpy)
	{
		case  IOC:
		CLEAR_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);
		break;
		
		case  FALLING_EDGE:
		SET_BIT(MCUCR,1);
		CLEAR_BIT(MCUCR,0);
		break;
		
		case  RISING_EDGE:
		SET_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);
		break;
		
		default:
		/**!Comment: default is LOW_LEVEL */
		CLEAR_BIT(MCUCR,1);
		CLEAR_BIT(MCUCR,0);
		break;
	}
}

void EXTI0_VoidCallBackFunc(PF PfFuncNameCpy)
{
	
		EXTI0_PfCallBackAdd = PfFuncNameCpy;
		
}

void __vector_1 (void) __attribute__((signal,used));
void __vector_1 (void)
{
	if (EXTI0_PfCallBackAdd != NULL)
	{
		EXTI0_PfCallBackAdd();
	}
}
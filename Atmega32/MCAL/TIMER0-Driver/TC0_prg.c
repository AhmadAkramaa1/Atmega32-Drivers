/**************************************/
/*Author     : Ahmad Akram            */
/*Description: TC0 Program File       */
/*Date       : 3 Aug 2022             */
/*Version    : 1.0v                   */
/**************************************/

#include"STD_types.h"
#include"BIT_math.h"

#include "TC0_int.h"
#include "TC0_cfg.h"
#include "TC0_priv.h"

volatile PF OVCallBackAdd = NULL;
volatile PF CMPCallBackAdd = NULL;

void TC0_VoidInit(void)
{
	
	/* init configurations */
	#if (WGMODE == NORMAL)
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);
	#elif (WGMODE == PHASE_PWM)
	CLEAR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	#elif (WGMODE == CTC)
	SET_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);
	#elif (WGMODE == FAST_PWM)
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	#else /* normal mode */
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);
	#endif
	
	#if ((WGMODE == NORMAL) || (WGMODE == CTC))
	
		#if (CMPOUTMODE == NC_OFF)
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
		#elif (CMPOUTMODE == NC_TOGGLE)
		CLEAR_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
		#elif (CMPOUTMODE == NC_CLEAR)
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
		#elif (CMPOUTMODE == NC_SET)
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
		#else
		/* OC0 disconnected i.e. NC_OFF */
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
		#endif

	#elif ((WGMODE == FAST_PWM) || (WGMODE == PHASE_PWM))
		
		#if (PWM_CMPOUTMODE == FPH_OFF)
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
		#elif (PWM_CMPOUTMODE == F_CMP0TOP1)
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
		#elif (PWM_CMPOUTMODE == F_CMP1TOP0)
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
		#elif (PWM_CMPOUTMODE == PH_CMPUP0CMPD1)
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
		#elif (PWM_CMPOUTMODE == PH_CMPUP1CMPD0)
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
		#else
		/* OC0 disconnected i.e. FPH_OFF */
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
		#endif

	#else
	/* OC0 disconnected */
	CLEAR_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,4);
	#endif
	
	/* stop TIMER clk */
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
	/* disable cmp interrupt & OV interrupt */
	CLEAR_BIT(TIMSK,1);
	CLEAR_BIT(TIMSK,0);
	/* clear registers */
	TCNT0 = 0;
	OCR0 = 0;
	
}

void TC0_VoidStart(void)
{
	/* set prescaler */
	#if (PRESCALER == DIVBY_1)
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	#elif (PRESCALER == DIVBY_8)
	CLEAR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
	#elif (PRESCALER == DIVBY_64)
	CLEAR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	#elif (PRESCALER == DIVBY_256)
	SET_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
	#elif (PRESCALER == DIVBY_1024)
	SET_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	#elif (PRESCALER == EXT_T0FALLEDGE)
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
	#elif (PRESCALER == EXT_T0RISEEDGE)
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	#else 
	/* DIVBY_1 */
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	#endif
	
}

void TC0_VoidStop(void)
{
	/* NO CLK SOURCE HENCE TIMER IS STOPPED */
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
}

void TC0_VoidEnableOV_I(void)
{
	SET_BIT(TIMSK,0);
} 

void TC0_VoidDisableOV_I(void)
{
	CLEAR_BIT(TIMSK,0);
}

void TC0_VoidEnableCmp_I(void)
{
	SET_BIT(TIMSK,1);
}

void TC0_VoidDisableCmp_I(void)
{
	CLEAR_BIT(TIMSK,1);
}

void TC0_VoidSetTC0Reg(u8 u8RegValCpy)
{
	TCNT0 = u8RegValCpy;
}

void TC0_VoidSetCmpVal(u8 u8CmpValCpy)
{
	OCR0 = u8CmpValCpy;
}

void TC0_voidForceCmpMatch(void)
{
	
	#if ((WGMODE == NORMAL) || (WGMODE == CTC))
	/* generate a signal */
	SET_BIT(TCCR0,7);
	CLEAR_BIT(TCCR0,7);
	#else
	
	#endif
	
}

void TC0_VoidOVCallBack(PF VoidFuncNameCpy)
{
	OVCallBackAdd = VoidFuncNameCpy;
}
void TC0_VoidCMPCallBack(PF VoidFuncNameCpy)
{
	CMPCallBackAdd = VoidFuncNameCpy;
}

void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	if(OVCallBackAdd != NULL)
	{
		/* clear flag */
		SET_BIT(TIFR,0);
		OVCallBackAdd();
	}
}

void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	if(CMPCallBackAdd!= NULL)
	{
		/* clear flag */
		SET_BIT(TIFR,1);
		CMPCallBackAdd();
	}
}

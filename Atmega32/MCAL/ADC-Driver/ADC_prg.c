/**************************************/
/*Author     : Ahmad Akram            */
/*Description: ADC Program File       */
/*Date       : 30 jun 2022            */
/*Version    : 1.0v                   */
/**************************************/

#include "BIT_math.h"
#include "STD_types.h"

#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"

volatile PF ADC_PFCallBackAdd = NULL;

void ADC_VoidInit(void)
{
/**              init all registers based on configuration             **/
/**                                 ADMUX REG                          **/	
	#if (Vref == INTERNAL)
	SET_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	#elif (Vref == AREF)
	CLEAR_BIT(ADMUX,7);
	CLEAR_BIT(ADMUX,6);
	#else //AVCC
	CLEAR_BIT(ADMUX,7);        
	SET_BIT(ADMUX,6);
	#endif
	#if (ADJUSTMENT == LEFT)
	SET_BIT(ADMUX,5);
	#else //RIGHT
	CLEAR_BIT(ADMUX,5);
	#endif
	//Leave ADMUX 4-0 channel selection bits 
/************************************************************************/
/**                                ADCSRA REG                          **/
	CLEAR_BIT(ADCSRA,7); 						//Disable ADC
	//LEAVE ADCSRA BIT 6 ADC start conversion
	CLEAR_BIT(ADCSRA,5); 						//disable auto trigger
	//LEAVE ADCSRA BIT 4 interrupt flag
	CLEAR_BIT(ADCSRA,3); 						//disable interrupt
	
	#if (PRESCALER == DIVBY_128)    			//prescaler bits 2,1,0
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
	#else // DIVBY_64                        
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);
	#endif
/************************************************************************/
/**                                SFIOR REG                           **/
	#if (TRIG_SOURCE == FREE_RUNNING_MODE)
	CLEAR_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);      
	#elif (TRIG_SOURCE == ANALOG_COMPARATOR)
	CLEAR_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
	#elif (TRIG_SOURCE == EXTI0_REQ)
	CLEAR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
	#elif (TRIG_SOURCE == TC0_CMPMATCH)
	CLEAR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);                   // Select auto trig mode if auto trig is enabled 
	#elif (TRIG_SOURCE == TC0_OVERFLOW)                  
	SET_BIT(SFIOR,7);                           //default will be FREE_RUNNING_MODE
	CLEAR_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);                   
	#elif (TRIG_SOURCE == TC_CMPMATCHB)                     //SFIOR REG
	SET_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
	#elif (TRIG_SOURCE == TC1_OVERFLOW)
	SET_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
	#elif (TRIG_SOURCE == TC1_CPTEVENT)
	SET_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
	#else
	CLEAR_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);	
	#endif
/************************************************************************/

}

void ADC_VoidEnable(void)
{
	SET_BIT(ADCSRA,7);
}

void ADC_VoidDisable(void)
{
	CLEAR_BIT(ADCSRA,7);
}

void ADC_VoidEnable_I(void)
{
	SET_BIT(ADCSRA,3);
}

void ADC_VoidDisable_I(void)
{
	CLEAR_BIT(ADCSRA,3);
}

void ADC_VoidEnable_AutoTrig(void)
{
	SET_BIT(ADCSRA,5);
}

void ADC_VoidDisable_AutoTrig(void)
{
	CLEAR_BIT(ADCSRA,5);
}

void ADC_VoidChangeVref(u8 u8VrefCpy)
{
	
	if(u8VrefCpy == INTERNAL)
	{
		SET_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
	}
	else if(u8VrefCpy == AREF)
	{
		CLEAR_BIT(ADMUX,7);
		CLEAR_BIT(ADMUX,6);
	}
	else if(u8VrefCpy == AVCC)
	{
		CLEAR_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
	}
	else
	{}
	
}
void ADC_VoidSetTrigMod(u8 u8TriggerCpy)
{

	if(u8TriggerCpy == FREE_RUNNING_MODE)     
	{
		CLEAR_BIT(SFIOR,7); 
		CLEAR_BIT(SFIOR,6); 
		CLEAR_BIT(SFIOR,5);
		}
	else if(u8TriggerCpy == ANALOG_COMPARATOR)
	{
		CLEAR_BIT(SFIOR,7); 
		CLEAR_BIT(SFIOR,6);   
		SET_BIT(SFIOR,5);
	}
	else if(u8TriggerCpy == EXTI0_REQ)
	{
		CLEAR_BIT(SFIOR,7);   
		SET_BIT(SFIOR,6); 
		CLEAR_BIT(SFIOR,5);
	} 
	else if(u8TriggerCpy == TC0_CMPMATCH)
	{
		CLEAR_BIT(SFIOR,7);   
		SET_BIT(SFIOR,6);   
		SET_BIT(SFIOR,5);
	} 
	else if(u8TriggerCpy == TC0_OVERFLOW)
	{
		SET_BIT(SFIOR,7); 
		CLEAR_BIT(SFIOR,6); 
		CLEAR_BIT(SFIOR,5);
	}  
	else if(u8TriggerCpy == TC_CMPMATCHB)
	{
		SET_BIT(SFIOR,7); 
		CLEAR_BIT(SFIOR,6);   
		SET_BIT(SFIOR,5);
	} 
	else if(u8TriggerCpy == TC1_OVERFLOW)
	{
		SET_BIT(SFIOR,7);   
		SET_BIT(SFIOR,6); 
		CLEAR_BIT(SFIOR,5);
		} 
	else if(u8TriggerCpy == TC1_CPTEVENT)
	{
		SET_BIT(SFIOR,7);   
		SET_BIT(SFIOR,6);   
		SET_BIT(SFIOR,5);
	}
	else
	{}
}

/** call one time then auto trigger will start automatically if enabled */
ERRORSTATUS ADC_ErrStartConvPol(u8 u8PinNbCpy)
{
	
	if(u8PinNbCpy>=0 && u8PinNbCpy<=7)
	{
		
		ADMUX&=0b11100000;                  //clear selection bits 
		ADMUX|=u8PinNbCpy;                  //select Pin number
		
		SET_BIT(ADCSRA,6);                  //start conv & wait till flag ==1
		while(GET_BIT(ADCSRA,4) == 0);        
		SET_BIT(ADCSRA,4);                  //clear flag then call u16ReadVal()
		return OK;
	}
	else
	{
		return NOK;
	}
	
}

ERRORSTATUS ADC_ErrStartConv_I(u8 u8PinNbCpy)     
{
	//if ADC interrupt is enabled otherwise do nothing
	if(GET_BIT(ADCSRA,3) == 1)
	{
		if(u8PinNbCpy>=0 && u8PinNbCpy<=7) 
		{
			ADMUX&=0b11100000;
			ADMUX|=u8PinNbCpy;
			SET_BIT(ADCSRA,6);
			return OK;
		}
		else
		{
			return INDEX_OUT_OF_RANGE;
		}
	}
	else
	{
		return NOK;
	}
}

u16 ADC_u16ReadVal(void)
{
	u16 u16RetValLoc=0;
	#if(RESOLUTION == EIGHT)
		#if(ADJUSTMENT == LEFT)
		//eight and left
		u16RetValLoc=ADCH;
		
		#else  //RIGHT
		//eight and right
		u16RetValLoc=((ADCL>>2)|(ADCH<<6));
		
		#endif
	
	#else  //TEN	
		#if(ADJUSTMENT == LEFT)
		//ten and left
		u16RetValLoc|=(ADCL>>6); 
		u16RetValLoc=(u16RetValLoc<<14);
		u16RetValLoc|=ADCH;
		u16Readed_Valueloc=((u16Readed_Valueloc<<2) | (u16Readed_Valueloc>>14));
		
		#else  //RIGHT
		//ten and right
		u16RetValLoc=ADCL;
		u16RetValLoc|=(GET_Bit(ADCH,0)<<9);
		u16RetValLoc|=(GET_Bit(ADCH,1)<<10);
		
		#endif
	
	#endif
	return u16RetValLoc;
}

void ADC_VoidCallBack(PF VoidFuncNameCpy)
{
	
	ADC_PFCallBackAdd = VoidFuncNameCpy;
	
}

void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
	if(ADC_PFCallBackAdd != NULL)
	{
		SET_BIT(ADCSRA,4);   //clear interrupt flag then implement the user function 
		ADC_PFCallBackAdd(); 
	}
	else
	{}
}
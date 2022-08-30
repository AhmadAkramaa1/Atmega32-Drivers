/**************************************/
/*Author     : Ahmad Akram            */
/*Description: SPI Program File       */
/*Date       : 28 Aug 2022            */
/*Version    : 1.0v                   */
/**************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "SPI_int.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"

volatile PF PfCallBackAdd = NULL;

void SPI_VoidInit(void)
{
	                      /**            Initialize Control Register              */
	                                  /**           SPCR          */
	CLEAR_BIT(SPCR,7); //disable interrupt
	CLEAR_BIT(SPCR,6); //disable SPI 
	#if (DATAORDER == MSB_FIRST)
		CLEAR_BIT(SPCR,5);
    #else              //default order is LSB_FIRST
		SET_BIT(SPCR,5);
	#endif
	
	#if (MODE == MASTER)
		SET_BIT(SPCR,4);
	#else              //default mode is SLAVE
		CLEAR_BIT(SPCR,4);
	#endif
	
	#if (MODE == MASTER)
		
		#if (CLKPOL == IDLE_HIGH)
			SET_BIT(SPCR,3);
		#else          //default is IDLE_LOW
			CLEAR_BIT(SPCR,3);
		#endif
	
		/** Note That when we choose SAMPLE_LEAD_SETUP_TRAIL,                   */
		/** the fist clk edge will be ignored as we can not start with sampling */
		#if (CLKPHA == SAMPLE_LEAD_SETUP_TRAIL)
			CLEAR_BIT(SPCR,2);
		#else          //default is SETUP_LEAD_SAMPLE_TRAIL)
			SET_BIT(SPCR,2);
		#endif
	
		#if (PRESCALER == DIVBY_4)
			CLEAR_BIT(SPSR,0);
			CLEAR_BIT(SPCR,1);
			CLEAR_BIT(SPCR,0);
		#elif (PRESCALER == DIVBY_8)
			SET_BIT(SPSR,0);
			CLEAR_BIT(SPCR,1);
			SET_BIT(SPCR,0);
		#elif (PRESCALER == DIVBY_16)
			CLEAR_BIT(SPSR,0);	
			CLEAR_BIT(SPCR,1);
			SET_BIT(SPCR,0);
		#elif (PRESCALER == DIVBY_32)
			SET_BIT(SPSR,0);	
			SET_BIT(SPCR,1);
			CLEAR_BIT(SPCR,0);
		#elif (PRESCALER == DIVBY_64)
			CLEAR_BIT(SPSR,0);	
			SET_BIT(SPCR,1);
			CLEAR_BIT(SPCR,0);
		#elif (PRESCALER == DIVBY_128)
			CLEAR_BIT(SPSR,0);	
			SET_BIT(SPCR,1);
			SET_BIT(SPCR,0);
		#else          //default is DIVBY_4 
			CLEAR_BIT(SPSR,0);
			CLEAR_BIT(SPCR,1);
			CLEAR_BIT(SPCR,0);
		#endif
	#else
		               //Ignore ucpol, ucpha & prescaler Bits
	#endif
 /** SPSR  contain SPIF & WCOL flags and SPI2X Bit is Already used with prescaler */
 
}

void SPI_VoidEnable(void){SET_BIT(SPCR,6);}
void SPI_VoidDisable(void){CLEAR_BIT(SPCR,6);}

void SPI_VoidEnable_I(void){SET_BIT(SPCR,7);}
void SPI_VoidDisable_I(void){CLEAR_BIT(SPCR,7);}

u8 SPI_U8ExchangeDataPol(u8 u8DataCpy)
{
	
	SPDR = u8DataCpy;
	if(GET_BIT(SPSR,6) == 1)          //If wcol became 1, read it then
	{
		while(GET_BIT(SPSR,7) == 0); //wait till Tcomplete
		SPDR = u8DataCpy;            //then access SPDR to clear flag
	}
	else
	{}
	                   //wait till SPIF = 1 and exchanging data is finished
	while(GET_BIT(SPSR,7) == 0);
	return SPDR;
}

void SPI_VoidSendData_I(u8 u8DataCpy)
{
	if(GET_BIT(SPCR,7) == 1 )            //check if interrupt is enabled and
	{
		SPDR = u8DataCpy;
		if(GET_BIT(SPSR,6) == 1)         //If wcol became 1, read it then 
		{
			while(GET_BIT(SPSR,7) == 0); //wait till Tcomplete
			SPDR = u8DataCpy;            //then access SPDR to clear flag
		}
		else
		{}
	}
	/**if user called this outside ISR, wcol will be set so we have to check       */
	/**status flag to ensure there is no data in shift register before writing SPDR*/
}
u8 SPI_U8ReadData_I(void)
{
	if(GET_BIT(SPCR,7) == 1) // check if interrupt is enabled
	{
		return SPDR;
	}
	else
	{
		return 0xFF;
	}
}

void SPI_VoidCallBack(PF PfFuncNameCpy)
{
	PfCallBackAdd = PfFuncNameCpy;
}


void __vector_12(void) __attribute__((signal,used)); 
void __vector_12(void)
{
	#if (MODE == MASTER)
	if(GET_BIT(SPCR,4) == 0) // check if SPI still MASTER
	{
		SET_BIT(SPCR,4);
	}
	else
	{
		if(PfCallBackAdd != NULL)
		{
			PfCallBackAdd();
		}
	}
	#else
	if(PfCallBackAdd != NULL)
	{
		PfCallBackAdd();
	}
	#endif
}



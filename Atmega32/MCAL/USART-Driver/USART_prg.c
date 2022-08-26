/**************************************/
/*Author     : Ahmad Akram            */
/*Description: USART Program File     */
/*Date       : 10 Aug 2022            */
/*Version    : 1.0v                   */
/**************************************/

#include "BIT_math.h"
#include "STD_types.h"

#include "USART_int.h"
#include "USART_cfg.h"
#include "USART_priv.h"

PF PfCallBackAddTXE = NULL;
PF PfCallBackAddTX = NULL;
PF PfCallBackAddRX = NULL;

void USART_VoidInit(void)
{ 
	                  /**             baud rate              */

	#if ((MODE == SYNC_MASTER) || (MODE == ASYNC_NORMAL) || (MODE == ASYNC_2X))
		/** Local variable for saving the BaudRateRegister */
		u16 UBRRLoc=0;
		#if (BAUDRATE == 0)
			#undef BAUDRATE
			#define BAUDRATE 9600UL
		#else
			
		#endif
		
		/** ubrr is 12 bits so its value should be 0-4095. */
		#if (MODE == SYNC_MASTER)
			UBRRLoc=(FOSC/(2*BAUDRATE))-1; 
		
		#elif (MODE == ASYNC_NORMAL)
			UBRRLoc=(FOSC/(16*BAUDRATE))-1;
		
		#elif (MODE == ASYNC_2X)
			UBRRLoc=(FOSC/(8*BAUDRATE))-1;
		#else
		
		#endif
			
		/** in order to access UBRRH we have to put BIT 7 as LOW */
		CLEAR_BIT(UBRRH,7);
		
		/** Load the UBRRLoc in the UBRRH & UBRRL */
		UBRRH = ((UBRRLoc>>8)&(0b00001111));
		UBRRL = UBRRLoc;
	#else
	
	#endif
	                      /**        UCSRA REGISTER           */
	
	/** ignore interrupt flags bits7,6,5 */
	/** clear error flags                */
	CLEAR_BIT(UCSRA,4);  //Frame Error
	CLEAR_BIT(UCSRA,3);  //Data OverRun
	CLEAR_BIT(UCSRA,2);  //Parity Error
	#if (MODE == ASYNC_2X)
		SET_BIT(UCSRA,1);
	#else 
		/** clear bit for "sync" and "async normal" modes */
		CLEAR_BIT(UCSRA,1);
	#endif
	/** Multi Processor Comm Mode */
	CLEAR_BIT(UCSRA,0);
	
		                  /**        UCSRB REGISTER           */
	/** disable all interrupts */
	CLEAR_BIT(UCSRB,7); //Rx Complete
	CLEAR_BIT(UCSRB,6); //Tx Complete
	CLEAR_BIT(UCSRB,5); //Tx Register Empty
	/** disable receiver and transmitter */
	CLEAR_BIT(UCSRB,4);  //Rx
	CLEAR_BIT(UCSRB,3);  //Tx
	/** bit 2 will be used with UCSRC for frame format  */
	/** bit 1 will be used as ninth bit in receive func */
	/** bit 0 will be used as ninth bit in Transmit func*/
	
			              /**        UCSRC REGISTER           */

	
	/** in order to access UCSRC we have to put BIT 7 as High */
	SET_BIT(UCSRC,7);
	#if ((MODE == SYNC_MASTER) || (MODE == SYNC_SLAVE))
		SET_BIT(UCSRC,6);
	#else //Mode is async
		CLEAR_BIT(UCSRC,6);
	#endif
	
	#if (PARITY == NO)
		CLEAR_BIT(UCSRC,5);
		CLEAR_BIT(UCSRC,4);
	#elif (PARITY == EVEN)
		SET_BIT(UCSRC,5);
		CLEAR_BIT(UCSRC,4);
	#elif (PARITY == ODD)
		SET_BIT(UCSRC,5);
		SET_BIT(UCSRC,4);	
	#else //default is NO
		CLEAR_BIT(UCSRC,5);
		CLEAR_BIT(UCSRC,4);	
	#endif
	
	#if (STOPBITS == _2SPB)
		SET_BIT(UCSRC,3);
	#else //default is 1 stop Bit
		CLEAR_BIT(UCSRC,3);
	#endif
	
	/** frame format */
	#if (DATABITS == _9BITS)
		SET_BIT(UCSRB,2);
		SET_BIT(UCSRC,2);
		SET_BIT(UCSRC,1);
	#elif (DATABITS == _5BITS)
		CLEAR_BIT(UCSRB,2);
		CLEAR_BIT(UCSRC,2);
		CLEAR_BIT(UCSRC,1);
	#elif (DATABITS == _6BITS)
		CLEAR_BIT(UCSRB,2);
		CLEAR_BIT(UCSRC,2);
		SET_BIT(UCSRC,1);
	#elif (DATABITS == _7BITS)
		CLEAR_BIT(UCSRB,2);
		SET_BIT(UCSRC,2);
		CLEAR_BIT(UCSRC,1);	
	#elif (DATABITS == _8BITS)
		CLEAR_BIT(UCSRB,2);
		SET_BIT(UCSRC,2);
		SET_BIT(UCSRC,1);
	#else       //default is 8 bit
		CLEAR_BIT(UCSRB,2);
		SET_BIT(UCSRC,2);
		SET_BIT(UCSRC,1);
	#endif
	/** clk polarity bit when synchronous mode only */
	#if (MODE == SYNC_MASTER || SYNC_SLAVE)
		#if (CLKPOLARITY == SAMPLERX_UP_CHANGETX_DOWN)
			SET_BIT(UCSRC,0);
		#else //Default will be SAMPLERX_DOWN_CHANGETX_UP
			CLEAR_BIT(UCSRC,0);
		#endif
	#else //Async
		CLEAR_BIT(UCSRC,0);
	#endif

}

void USART_VoidEnableTx(void)
{
	SET_BIT(UCSRB,3);
}
void USART_VoidDisableTx(void)
{
	CLEAR_BIT(UCSRB,3);
}

void USART_VoidEnableRx(void)
{
	SET_BIT(UCSRB,4);
}
void USART_VoidDisableRx(void)
{
	CLEAR_BIT(UCSRB,4);
}

void USART_VoidEnable_I(void)
{
	SET_BIT(UCSRB,7); //Rx Complete
	SET_BIT(UCSRB,6); //Tx Complete
	SET_BIT(UCSRB,5); //Tx Register Empty
}
void USART_VoidDisable_I(void)
{
	CLEAR_BIT(UCSRB,7); //Rx Complete
	CLEAR_BIT(UCSRB,6); //Tx Complete
	CLEAR_BIT(UCSRB,5); //Tx Register Empty
}

void USART_VoidTransmitPol(s16 DataCpy)
{
	/** wait till TXempty flag is 1 & reg is empty. */
	while(!GET_BIT(UCSRA,5));
	
	#if (DATABITS == _9BITS)
		/** put the ninth bit in UCSRB before lower bits in udr */
		if(GET_BIT(DataCpy,8) == 1) 
		{
			SET_BIT(UCSRB,0);
		}
		else
		{
			CLEAR_BIT(UCSRB,0);
		}
	#else
		
	#endif
	
	UDR = DataCpy;
	
}

s16 USART_S16ReceivePol(void)
{
	s16 DataLoc=0;
	/** wait till RX complete flag is 1 & UDR has data. */
	while(!GET_BIT(UCSRA,7));
	/** Check for errors before reading UDR */
	if(GET_BIT(UCSRA,4) == 1)
	{
		SET_BIT(DataLoc,15);  //frame error flag will be bit 15
	}
	if(GET_BIT(UCSRA,3) == 1)
	{
		SET_BIT(DataLoc,14);  //DataOverRun flag will be Bit 14
	}
	if(GET_BIT(UCSRA,2) == 1)
	{
		SET_BIT(DataLoc,13);  //Parity error flag will be Bit 13
	}
	
	#if (DATABITS == _9BITS)
		
		if(GET_BIT(UCSRB,1) == 1)
		{
			SET_BIT(DataLoc,8);
		}
		
	#else
		
	#endif
	
	DataLoc |= UDR;
 
	return DataLoc;
}

void USART_VoidTransmit_I(s16 DataCpy)
{
	/** transmit interrupt must be enabled */
	if(GET_BIT(UCSRB,5) == 1)
	{
		#if (DATABITS == _9BITS)
		/** put the ninth bit in UCSRB before lower bits in UDR */
		if(GET_BIT(DataCpy,8) == 1) 
		{
			SET_BIT(UCSRB,0);
		}
		else
		{
			CLEAR_BIT(UCSRB,0);
		}
		#else
		
		#endif
	
		UDR = DataCpy;
	}
	else
	{}

}
s16 USART_S16DataReceived_I(void)
{
	s16 DataLoc=0;
	/** receive interrupt must be enabled */
	if(GET_BIT(UCSRB,7) == 1)
	{
		/** before data I want to see if any errors */
		if(GET_BIT(UCSRA,4) == 1)
		{
			SET_BIT(DataLoc,15);  //frame error flag will be bit 15
		}
		if(GET_BIT(UCSRA,3) == 1)
		{
			SET_BIT(DataLoc,14);  //DataOverRun flag will be Bit 14
		}
		if(GET_BIT(UCSRA,2) == 1)
		{
			SET_BIT(DataLoc,13);  //Parity error flag will be Bit 13
		}
	
		#if (DATABITS == _9BITS)
		
		if(GET_BIT(UCSRB,1) == 1)
		{
			SET_BIT(DataLoc,8);
		}
		
		#else
		
		#endif
	
		DataLoc |= UDR;
	}
 
	return DataLoc;
}


void USART_VoidCallBack_TEmty(PF PfFuncNameCpy)
{
	PfCallBackAddTXE = PfFuncNameCpy;
} 
void USART_VoidCallBack_TComplete(PF PfFuncNameCpy)
{
	PfCallBackAddTX = PfFuncNameCpy;
}
void USART_VoidCallBack_RComplete(PF PfFuncNameCpy)
{
	PfCallBackAddRX = PfFuncNameCpy;
}

void __vector_14(void) __attribute__((signal,used));
void __vector_14(void)
{
	/** This function will continue as long as the flag is set                 */
	/** TXE flag will be cleared automatically                                 */
	/** UDR must be read or another interrupt will fire as soon as ISR finishes*/
	if(PfCallBackAddTXE != NULL)
	{
		PfCallBackAddTXE();
	}
	else
	{}
}
void __vector_15(void) __attribute__((signal,used));
void __vector_15(void)
{
	
	if(PfCallBackAddTX != NULL)
	{
		PfCallBackAddTX();
		SET_BIT(UCSRA,6); //clear TX flag
	}
	else
	{}
}
void __vector_13(void) __attribute__((signal,used));
void __vector_13(void)
{
	/** This function will continue as long as the flag is set                 */
	/** RX flag will be cleared automatically                                  */
	/** UDR must be read or another interrupt will fire as soon as ISR finishes*/
	if(PfCallBackAddRX != NULL)
	{
		PfCallBackAddRX();
	}
	else
	{}
}


/**************************************/
/*Author     : Ahmad Akram            */
/*Description: TWI Program File       */
/*Date       : 3 Sept 2022            */
/*Version    : 1.0v                   */
/**************************************/


#include "BIT_math.h"
#include "STD_types.h"

#include "TWI_int.h"
#include "TWI_cfg.h"
#include "TWI_priv.h"



void TWI_VoidInit(void)
{
	          /**       Enable TWI        */
	SET_BIT(TWCR,2);
	
	          /**     set prescaler       */
	#if ((PRESCALER_MCLK >= 10) && (PRESCALER_MCLK < 256) )
		TWBR =PRESCALER_MCLK;
	#else
		TWBR = 10;
	#endif
	
	/** prescaler bits(TWPS 1-0) will be always 0 and  */
	/** SCL will be controlled from PRESCALER_MCLK.    */
	CLEAR_BIT(TWSR,1);
	CLEAR_BIT(TWSR,0); 
	
	          /**  control General call   */
	#if (GENERALCALL == REACT)
		SET_BIT(TWAR,0);
	#else
		//default is IGNORE General call
		CLEAR_BIT(TWAR,0);
	#endif
}

void TWI_VoidEnable(void)
{
	SET_BIT(TWCR,2);
}

void TWI_VoidDisable(void)
{
	CLEAR_BIT(TWCR,2);
}

void TWI_VoidSetMyAdd(u8 u8MyAddCpy)
{
	/**Address 0000000 is reserved and 1111xxx should be left for future purposes */
	if(u8MyAddCpy > 0 && u8MyAddCpy <120)
	{
		TWAR &= 0x01;            //Masking MSB
		TWAR |= (u8MyAddCpy<<1); //writing Address
	}
	else
	{}
}

void TWI_VoidStartCond(void)
{
	TWCR = 0b11100100;           //TWINT, Ack, TWSTA, TWEN must be written, Ack is Don't care. 
	while(GET_BIT(TWCR,7) == 0); //wait while start is transmitted and TWINT becomes 1
}

void TWI_VoidStopCond(void)
{
	TWCR = 0b11010100;          //TWINT, Ack, TWSTO, TWEN must be written, Ack is Don't care.
}

void TWI_VoidSend(u8 u8AddndDataCpy)
{
	TWDR = u8AddndDataCpy;
	TWCR = 0b11000100;          //TWINT, Ack, TWEN are SET, start sending data. Ack is Don't care for master. slave should receive ack 
	while(GET_BIT(TWCR,7) == 0);//wait while byte is sent, flag becomes 1 and Status register is updated
}

u8 TWI_U8ReceivewAck(void)
{
	TWCR=0b11000100;            //TWINT, Ack, TWEN are SET. Start receiving and Send Ack when data is received
	while(GET_BIT(TWCR,7) == 0);//wait while byte is received, flag becomes 1 and Status register is updated
	return TWDR;
}

u8 TWI_U8ReceivewNoAck(void)
{
	TWCR = 0b10000100;          //TWINT, TWEN are SET with Ack disabled. Start receiving 
	while(GET_BIT(TWCR,7) == 0);//wait while byte is received and flag becomes 1
	return TWDR ;
}

u8 TWI_U8CheckStatus(tenuTWI_Stat EnuStatusCpy)
{
	if((TWSR & 0xF8) == EnuStatusCpy) 
	{
		return 1;              //if Status is true 1 is returned
	}
	else
	{
		return (TWSR & 0xF8);  //else current status is returned
	}
	
}


/*******************************************************/
/**in Receiving Functions, (Sla+R/W) must be ack first */
/**therefore,we wait for the next status to read TWDR, */
/*******************************************************/
 
/**************************************/
/*Author     : Ahmad Akram            */
/*Description: TWI Interface File     */
/*Date       : 3 Sept 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef TWI_INT_H
#define TWI_INT_H

/*******************************************/
/**Description: status register values     */
/*******************************************/
/**MT: Master Transmitter                  */
/**MR: Master Receiver                     */
/**SR: Slave Receiver                      */
/**ST: Slave Transmitter                   */
/**s: sent                                 */
/**r: received                             */
/**SlaW: Slave address + Write             */
/**SlaR: Slave address + Read              */
/**MArbLoss: Arbitration loss as Master    */
/*******************************************/
typedef enum{
 
	StartCon_s = 0x08 ,
	RepStartCon_s= 0x10 ,
	MT_SlaW_s_Ack_r = 0x18,
	MT_SlaW_s_NoAck_r = 0x20 ,
	MT_Data_s_Ack_r = 0x28 ,
	MT_Data_s_NOAck_r = 0x30 ,
	MT_ArbLoss = 0x38 ,
	MR_SlaR_s_ACK_r = 0x40 ,
	MR_SlaR_s_NoAck_r = 0x48 ,
	MR_Data_r_Ack_s = 0x50 ,
	MR_Data_r_NoAck_s = 0x58 ,
	SR_SlaW_r_Ack_s = 0x60 ,
	SR_MArbLoss_SlaW_r_Ack_s = 0x68 ,
	SR_GenCall_r_Ack_s = 0x70 ,
	SR_MArbLoss_GenCall_r_Ack_s = 0x78 ,
	SR_SlaW_r_Data_r_Ack_s = 0x80,
	SR_SlaW_r_Data_r_NoAck_s = 0x88,
	SR_GenCall_r_Data_r_Ack_s = 0x90,
	SR_GenCall_r_Data_r_NoAck_s = 0x98,
	SR_StoporRepStart_r = 0xA0,
	ST_SlaR_r_Ack_s = 0xA8,
	ST_MArbLoss_SlaR_r_Ack_s = 0xB0,
	ST_Data_s_Ack_r = 0xB8,
	ST_Data_s_NoAck_r = 0xC0,
	ST_LastData_s_Ack_r = 0xC8,
	NoStatus_Flagis0 = 0xF8,
	IllegalStart_or_Stop = 0x00

}tenuTWI_Stat;


/*******************************************/
/**Description: Init Func for TWI          */
/*******************************************/
/**!Comment: -Set PRESCALER                */
/**          -Control General call         */
/**          -Enable TWI                   */
/*******************************************/
void TWI_VoidInit(void);

/*******************************************/
/**Description: Enable & Disable TWI       */
/*******************************************/
void TWI_VoidEnable(void);
void TWI_VoidDisable(void);

/*******************************************/
/**Description: Set TWI Address            */
/*******************************************/
/**u8MyAddCpy = ( 1->119 )                 */
/**                                        */
/**- Address 0 is reserved                 */
/**- 119->127 is left for future purposes  */
/**                                        */
/**Any value outside limits will be ignored*/
/*******************************************/
void TWI_VoidSetMyAdd(u8 u8MyAddCpy);

/*******************************************/
/**Description: Start & Stop conditions    */
/*******************************************/
void TWI_VoidStartCond(void);
void TWI_VoidStopCond(void);

/*******************************************/
/**Description: Send Address Or Data       */
/*******************************************/
/**u8AddndDataCpy = 1 Byte of data or      */
/**                 Address                */
/**Address Format:                         */
/**__________________________________      */
/**|A6 |A5 |A4 |A3 |A2 |A1 |A0 |R/W |      */
/**                                        */
/**- LSB is R/W bit in case of Master      */
/**  sending Sla+R or Sla+W.               */
/**- Read = 1, Write = 0                   */
/*******************************************/
void TWI_VoidSend(u8 u8AddndDataCpy);

/*******************************************/
/**Description: Receive Byte & send Ack    */
/*******************************************/
/** !Comment: if returned value(u8) = 0xFF,*/
/** It means that Slave is disconnected.   */
/*******************************************/
u8 TWI_U8ReceivewAck(void);

/*******************************************/
/**Description: Receive Byte & send NoAck  */
/*******************************************/
u8 TWI_U8ReceivewNoAck(void);

/*******************************************/
/**Description: Check Status Register      */
/*******************************************/
/** EnuStatusCpy = Status register Values▲ */
/*******************************************/
/** Returned value(u8) = 1 which means True*/
/** otherwise, Current Status is returned  */
/*******************************************/
u8 TWI_U8CheckStatus(tenuTWI_Stat EnuStatusCpy);


#endif

/********************************************************************/
/** All transmissions must contain the same number of data packets, */
/** otherwise the result of the arbitration is undefined.           */
/********************************************************************/
/**"this will not be controlled by the driver so it must be         */
/** considered in the Software Application"                         */
/********************************************************************/
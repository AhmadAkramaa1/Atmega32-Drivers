/**************************************/
/*Author     : Ahmad Akram            */
/*Description: USART Interface File   */
/*Date       : 10 Aug 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef USART_INT_H
#define USART_INT_H


/*******************************************/
/**Description: Init Func for USART        */
/*******************************************/
/**!Comment: -set BaudRate & Frame Format  */
/**          -Initialize USART Registers.  */
/**          -Disable: TX, RX, Interrupts  */
/**                  & clear flags.        */
/*******************************************/
void USART_VoidInit(void);

/*******************************************/
/**Description:Enable & Disable Transmitter*/
/*******************************************/
void USART_VoidEnableTx(void);
void USART_VoidDisableTx(void);

/*******************************************/
/**Description:Enable & Disable Receiver   */
/*******************************************/
void USART_VoidEnableRx(void);
void USART_VoidDisableRx(void);

/*******************************************/
/**Description:Enable & Disable Interrupt  */
/*******************************************/
void USART_VoidEnable_I(void);
void USART_VoidDisable_I(void);

/*******************************************/
/**Description:Transmit data using polling */
/*******************************************/
/**DataCpy: data size will be as specified */
/**         in data format. any bigger     */
/**         value than specified will      */
/**         corrupt the data transmitted   */
/*******************************************/
void USART_VoidTransmitPol(s16 DataCpy);

/*******************************************/
/**Description: Receive data using polling */
/*******************************************/
/**Error Flags :                           */
/**frame(FE),dataoverrun(DOR),parity(PE)   */
/*******************************************/
/**received Data is as follows :           */
/**                                        */
/**      |FE|DOR|PE|    12-9   |D8| -dataH */
/**      --------------------------        */
/**      |D7| D6|D5|D4|D3|D2|D1|D0| -dataL */
/*******************************************/
s16 USART_S16ReceivePol(void);

/*******************************************/
/**Description:Transmit data - Interrupt   */
/*******************************************/
/**DataCpy: data size will be as specified */
/**         in data format. any bigger     */
/**         value than specified will      */
/**         corrupt the data transmitted.  */
/*******************************************/
/** -Interrupt must be enabled or nothing  */
/**  happen                                */
/*******************************************/
void USART_VoidTransmit_I(s16 DataCpy);

/*******************************************/
/**Description:Received data - Interrupt   */
/*******************************************/
/** -Interrupt must be enabled or 0 is     */
/**  received.                             */
/*******************************************/
/**Error Flags :                           */
/**frame(FE),dataoverrun(DOR),parity(PE)   */
/*******************************************/
/**received Data is as follows :           */
/**                                        */
/**      |FE|DOR|PE|    12-9   |D8| -dataH */
/**      --------------------------        */
/**      |D7| D6|D5|D4|D3|D2|D1|D0| -dataL */
/*******************************************/
s16 USART_S16DataReceived_I(void);

/*******************************************/
/** Description: callback functions for    */
/**              UDR empty, Tx and Rx      */
/*******************************************/
/**PfFuncNameCpy :void Func to be executed */
/**               when interrupt is fired  */
/*******************************************/
void USART_VoidCallBack_TEmpty(PF PfFuncNameCpy); 
void USART_VoidCallBack_TComplete(PF PfFuncNameCpy);
void USART_VoidCallBack_RComplete(PF PfFuncNameCpy);





#endif

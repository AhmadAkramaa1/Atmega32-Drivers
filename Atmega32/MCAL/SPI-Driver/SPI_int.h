/**************************************/
/*Author     : Ahmad Akram            */
/*Description: SPI Interface File     */
/*Date       : 28 Aug 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef SPI_INT_H
#define SPI_INT_H

#define DUMMY 0xFF

/*******************************************/
/**Description: Initialize SPI Register    */
/**             Disable SPI                */
/**             Disable SPI Interrupt      */
/*******************************************/
void SPI_VoidInit(void);

/*******************************************/
/**Description:Enable & Disable SPI        */
/*******************************************/
void SPI_VoidEnable(void);
void SPI_VoidDisable(void);

/*******************************************/
/**Description:Enable & Disable Interrupt  */
/*******************************************/
void SPI_VoidEnable_I(void);
void SPI_VoidDisable_I(void);

/*******************************************/
/**Description: Exchange Data with Master  */
/**             and Slave                  */
/*******************************************/
/**u8DataCpy =  DUMMY, to Just read data   */
/**                                        */
/**return(u8) = data Received from Device  */
/*******************************************/
/**In slave mode, Reg can be set but will  */
/**not be transfered till SSpin becomes low*/
/*******************************************/
u8 SPI_U8ExchangeDataPol(u8 u8DataCpy);

/*******************************************/
/**Description: Send Data - Interrupt      */
/*******************************************/
/**u8DataCpy =  Byte sent to slave         */
/*******************************************/
/**Interrupt must be enabled otherwise     */
/**nothing happens. When I is enabled, Func*/
/**should be called inside CallBackFunc or */
/**Write-collision may cause delay to send */
/*******************************************/
void SPI_VoidSendData_I(u8 u8DataCpy);

/*******************************************/
/**Description: Receive Data - Interrupt   */
/*******************************************/
/**return(u8) = Byte received from slave   */
/*******************************************/
/**Interrupt must be enabled otherwise     */
/**DUMMY is received                       */
/*******************************************/
u8 SPI_U8ReadData_I(void);

/*******************************************/
/** Description: callback function for     */
/**              TComplete                 */
/*******************************************/
/**PfFuncNameCpy :void Func to be executed */
/**               when interrupt is fired  */
/*******************************************/
void SPI_VoidCallBack(PF PfFuncNameCpy);


#endif
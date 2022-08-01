/**************************************/
/*Author     : Ahmad Akram            */
/*Description: ADC Interface File     */
/*Date       : 30 jun 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef ADC_INT_H
#define ADC_INT_H

/*            ADC pins (ADC0 - ADC7)                 */
#define ADC0    0
#define ADC1    1
#define ADC2    2
#define ADC3    3
#define ADC4    4
#define ADC5    5
#define ADC6    6
#define ADC7    7

/*            ADC voltage  reference                 */
#define INTERNAL    5
#define AVCC        10
#define AREF        15


/*          ADC 8 auto triggering modes              */
#define FREE_RUNNING_MODE  0
#define ANALOG_COMPARATOR  1
#define EXTI0_REQ          2
#define TC0_CMPMATCH       3
#define TC0_OVERFLOW       4
#define TC_CMPMATCHB       5
#define TC1_OVERFLOW       6
#define TC1_CPTEVENT       7


/*******************************************/
/**init Func for ADC                       */
/*******************************************/
/**!Comment: -Initialize ADC Registers.    */
/**           -Disable: ADC, Interrupts,   */
/**                    Auto Trigger.       */
/*******************************************/
void ADC_VoidInit(void);

/*******************************************/
/**Enable & Disable ADC                    */
/*******************************************/
void ADC_VoidEnable(void);

void ADC_VoidDisable(void);

/*******************************************/
/**Enable & Disable ADC Interrupt          */
/*******************************************/
void ADC_VoidEnable_I(void);

void ADC_VoidDisable_I(void);

/*******************************************/
/**Enable & Disable ADC Auto Trigger       */
/*******************************************/
void ADC_VoidEnable_AutoTrig(void);

void ADC_VoidDisable_AutoTrig(void);

/*******************************************/
/**change ADC voltage reference            */
/*******************************************/
/**   u8VrefCpy:  INTERNAL                 */
/**               AREF                     */
/**               AVCC                     */
/*******************************************/
void ADC_VoidChangeVref(u8 u8VrefCpy);

/*******************************************/
/**change ADC auto trigger source          */
/*******************************************/
/**   u8TriggerCpy : FREE_RUNNING_MODE     */
/**                  ANALOG_COMPARATOR     */
/**                  EXTI0_REQ             */
/**                  TC0_CMPMATCH          */
/**                  TC0_OVERFLOW          */
/**                  TC_CMPMATCHB          */
/**                  TC1_OVERFLOW          */
/**                  TC1_CPTEVENT          */
/*******************************************/
void ADC_VoidSetTrigMod(u8 u8TriggerCpy);

/*******************************************/
/**read ADC with polling from pins 0to7    */
/*******************************************/
/**u8PinNbCpy : ADC0->ADC7                 */
/*******************************************/
ERRORSTATUS ADC_ErrStartConvPol(u8 u8PinNbCpy);

/*******************************************/
/**ADC interrupt must be enabled or        */
/**      nothing will happen               */
/*******************************************/
/**u8PinNbCpy : ADC0->ADC7                 */
/*******************************************/
ERRORSTATUS ADC_ErrStartConv_I(u8 u8PinNbCpy);

/*******************************************/
/**read ADC Data Register                  */
/*******************************************/
/**retval=8or10Bits depending on RESOLUTION*/
/*******************************************/
u16 ADC_u16ReadVal(void);

/*******************************************/
/**ADC interrupt ISR                       */
/*******************************************/
void ADC_VoidCallBack(PF VoidFuncNameCpy);

#endif


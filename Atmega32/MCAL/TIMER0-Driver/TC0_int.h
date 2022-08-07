/**************************************/
/*Author     : Ahmad Akram            */
/*Description: tC0 Interface File     */
/*Date       : 3 Aug 2022             */
/*Version    : 1.0v                   */
/**************************************/

#ifndef TC0_INT_H
#define TC0_INT_H


/**************************************************************/
/** Description: -Initialize control register                 */
/**              -stop Timer0 & clear registers               */
/**              -Disable Overflow & Cmp match interrupts     */
/**************************************************************/
void TC0_VoidInit(void);

/**************************************************************/
/** Description: -start & stop Timer0                         */
/** -in Start, Default F=DIVBY_1 if not specified by PRESCALER*/
/**************************************************************/
void TC0_VoidStart(void);
void TC0_VoidStop(void);

/**************************************************************/
/** Description: -enable & disable overflow Interrupt         */
/**************************************************************/
void TC0_VoidEnableOV_I(void); 
void TC0_VoidDisableOV_I(void);

/**************************************************************/
/** Description: -enable & disable Cmp match Interrupt        */
/**************************************************************/
void TC0_VoidEnableCmp_I(void);
void TC0_VoidDisableCmp_I(void);

/**************************************************************/
/** Description: -Set timer register                          */
/** Du8RegValCpy= values from 0 to 255                        */
/**************************************************************/
void TC0_VoidSetTC0Reg(u8 u8RegValCpy);

/**************************************************************/
/** Description: -set compare value register                  */
/** u8CmpValCpy = values from 0 to 255                        */
/**************************************************************/
void TC0_VoidSetCmpVal(u8 u8CmpValCpy);

/**************************************************************/
/** Description:                                              */
/**      -this function works with NORMAL and CTC modes only. */
/**      -OC0 pin will change as if a cmp match happened      */
/**       without clearing timer or generating interrupt      */
/**************************************************************/
void TC0_voidForceCmpMatch(void);

/**************************************************************/
/** Description:                                              */
/**     -call back functions when Interrupt is fired          */
/** VoidFuncNameCpy: takes a void function that returns void  */
/**                 defined by the user.                      */
/**************************************************************/
void TC0_VoidOVCallBack(PF VoidFuncNameCpy);
void TC0_VoidCMPCallBack(PF VoidFuncNameCpy);


#endif


/*

	normal             ctc                  |	  	fastpwm  		                           |   phasepwm  
											|								                   
  	  tccr0 bit7 foc is active              |                           tccr0 bit7 foc is 0      
	wgm00	 	      wgm10                 |        wgm11	 	                               |     wgm01
											|								                   |
 Com bits 00 OC0off                         | Com bits 00 OC0off                               | Com bits 00 OC0off       
          01 toggle OC0                     |          01 reserved                             |          01 reserved
		  10 clear  OC0                     |          10 clear when cmpmatch, set on TOP      |          10 clear on cmpmatch up, set on cmpmatch down
		  11 SET    OC0                     |          11 SET   when cmpmatch,clear on TOP     |          11 SET   on cmpmatch up,clear on cmpmatch down
-in ctc, if ocr=0, max freq occurs          |   if ocr=max,cmpmatch is ignored                 |   if ocr=max,cmpmatch is ignored
-not recommended to generate waveforms      |,set or clear is done when reaching top           |            ,output will be high    for non-inverted(combits=10) and low when inverted(combits=11)
in normal mode as it will take too much cpu |   ifocr=0 and (combits=01),genFreq 50 dutycycle  |   if ocr=0 ,output will be low     for non inverted(combits=10)and high when inverted(combits=11)
time									    |   if ocr=0,a spike will occur only			   | oc0 changes without cmpmatch if ocr change value from max or timer start with bigger value than ocr   
                                            | -OCR0 Update and TOV0 Interrupt Flag Set at max  | OCR0 Update at max & TOV0 Interrupt Flag Set at bottom


*/
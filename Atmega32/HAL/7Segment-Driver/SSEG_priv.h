/*******************************************/
/*Author      : Ahmad Akram                */
/*Description : 7SEG Private file          */
/*Date        : 7/3/2021                   */
/*Version     : 1.0V                       */
/*******************************************/


#ifndef SSEG_PRIV_H
#define SSEG_PRIV_H


#define COMMON_ANODE     0x50
#define COMMON_CATHODE   0x0F


typedef struct
{
	u8 u8Pin_A ;
	u8 u8Pin_B ;
	u8 u8Pin_C ;
	u8 u8Pin_D ;
	u8 u8Pin_E ;
	u8 u8Pin_F ;
	u8 u8Pin_G ;
	u8 u8Pin_CM;
	
}TStr7Seg;

extern TStr7Seg AStr7SegCfg[SSEG_MAXNB];


#endif
/*****************************/
/* author      : ahmad akram */
/* description : STD library */
/* date        : 19/7/2019   */
/* version     : 1.1v        */
/*****************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double f80;
typedef enum
{
	OK,
	NOK,
	INDEX_OUT_OF_RANGE,
	NULL_POINTER
}ERRORSTATUS;
typedef void (*PF)(void);
#define NULL  (void * )0
#endif






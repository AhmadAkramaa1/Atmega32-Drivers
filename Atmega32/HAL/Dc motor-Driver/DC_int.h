/***************************************/
/*Author     : Ahmad Akram             */
/*Description: DC-motor Interface File */
/*Date       : 17/3/2021               */
/*Version    : 1.0V                    */
/***************************************/

#ifndef DC_INT_H
#define DC_INT_H

#define DC_u8CW   0
#define DC_u8CCW  10

/***********************************************/
/** Description : initialization function      */
/***********************************************/
void DC_VoidInit(void);

/***********************************************/
/** INPUT :                                    */
/**      u8MotorNbCpy  :motor ID Starts from 0 */
/**         Example  ->(0,1,2... MaxNbOfMotors)*/
/***********************************************/
ERRORSTATUS DC_VoidStop(u8 u8MotorNbCpy);

/***********************************************/
/** INPUTS :                                   */
/**    u8MotorNbCpy  :  motor ID Starts from 0 */
/**         Example  ->(0,1,2... MaxNbOfMotors)*/
/**      									   */
/**    u8DirectionCpy: Clockwise Or Counter CW */
/**         Example  ->  (DC_u8CW, DC_u8CCW)   */
/***********************************************/
ERRORSTATUS DC_VoidMove(u8 u8MotorNbCpy,u8 u8DirectionCpy);


#endif

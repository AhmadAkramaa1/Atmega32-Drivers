/***************************************/
/*Author     : Ahmad Akram             */
/*Description: USART Configuration File*/
/*Date       : 10 Aug 2022             */
/*Version    : 1.0v                    */
/***************************************/

#ifndef USART_CFG_H
#define USART_CFG_H


/**            System frequency in HZ             */
#define FOSC     8000000UL      

/** The baud rate is in Bits/sec, Symbol is 1 bit */
#define BAUDRATE 9600UL

/**************************************/
/** MODE = SYNC_MASTER                */ 
/**        SYNC_SLAVE                 */
/**        ASYNC_NORMAL               */
/**        ASYNC_2X                   */
/**************************************/
#define MODE     SYNC_MASTER 

/**************************************/
/** DATABITS = _5BITS                 */
/**            _6BITS                 */
/**            _7BITS                 */
/**            _8BITS                 */
/**            _9BITS                 */
/**************************************/
#define DATABITS _8BITS         

/**************************************/
/** PARITY = NO                       */
/**          EVEN                     */
/**          ODD                      */
/**************************************/
#define PARITY   NO

/**************************************/
/**  STOPBITS = _1SPB                 */
/**             _2SPB                 */
/**************************************/
#define STOPBITS _1SPB

/********************************************/
/**             IN SYNC MODE                */
/********************************************/ 
/** CLKPOLARITY =                           */
/**       SAMPLERX_UP_CHANGETX_DOWN         */
/**       SAMPLERX_DOWN_CHANGETX_UP         */
/********************************************/
#define CLKPOLARITY  SAMPLERX_DOWN_CHANGETX_UP
                                                      



#endif
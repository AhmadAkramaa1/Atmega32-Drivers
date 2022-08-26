/**************************************/
/*Author     : Ahmad Akram            */
/*Description: USART Private File     */
/*Date       : 10 Aug 2022            */
/*Version    : 1.0v                   */
/**************************************/

#ifndef USART_PRIV_H
#define USART_PRIV_H

#define UDR   (*((volatile u8*)0x2C))

#define UCSRA (*((volatile u8*)0x2B))
#define UCSRB (*((volatile u8*)0x2A))
#define UCSRC (*((volatile u8*)0x40))

#define UBRRH (*((volatile u8*)0x40))
#define UBRRL (*((volatile u8*)0x29))


#define SYNC_MASTER  1
#define SYNC_SLAVE   2
#define ASYNC_NORMAL 3
#define ASYNC_2X     4

#define _5BITS       5
#define _6BITS       6
#define _7BITS       7
#define _8BITS       8
#define _9BITS       9

#define NO           10
#define EVEN         11
#define ODD          12

#define _1SPB        20
#define _2SPB        21

#define SAMPLERX_UP_CHANGETX_DOWN 30
#define SAMPLERX_DOWN_CHANGETX_UP 31


#endif
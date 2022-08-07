/**************************************/
/*Author     : Ahmad Akram            */
/*Description: TC0 Configuration File */
/*Date       : 3 Aug 2022             */
/*Version    : 1.0v                   */
/**************************************/

#ifndef TC0_CFG_H
#define TC0_CFG_H


/****************************/
/** WGMODE = NORMAL         */
/**          CTC            */
/**          FAST_PWM       */
/**          PHASE_PWM      */
/****************************/
#define WGMODE         FAST_PWM   

/**************************************************/
/**control OC0pin when cmpmatch *-in non PWM modes*/
/**************************************************/
/**  CMPOUTMODE = NC_OFF                          */
/**               NC_TOGGLE                       */
/**               NC_CLEAR                        */
/**               NC_SET                          */
/**************************************************/
#define CMPOUTMODE     NC_OFF

/**********************************************************************/
/**control OC0pin when cmpmatch *-in PWM modes                        */
/**********************************************************************/
/**PWM_CMPOUTMODE = FPH_OFF        ->disconnect OC0 pin               */
/**                 F_CMP0TOP1     ->clear on cmp,set on top          */
/**                 F_CMP1TOP0     ->set on cmp,clear on top          */
/**                 PH_CMPUP0CMPD1 ->clear when up,set when down      */
/**                 PH_CMPUP1CMPD0 ->set when up,clear when down      */
/**********************************************************************/
#define PWM_CMPOUTMODE F_CMP0TOP1   

/*********************************/
/** PRESCALER = DIVBY_1          */
/**             DIVBY_8          */
/**             DIVBY_64         */
/**             DIVBY_256        */
/**             DIVBY_1024       */
/**             EXT_T0FALLEDGE   */
/**             EXT_T0RISEEDGE   */
/*********************************/
#define PRESCALER      DIVBY_8



#endif


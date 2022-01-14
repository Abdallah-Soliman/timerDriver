

/** Timer_congifure.h
 *
 *
 * Created on: Jun 6, 2021
 *      Author: abdalluah
 *
 * */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/*chose_MODE :  0-NORMAL
                1-PHASE_CORRECT_MODE
                2-CTC_MODE
                3-FAST_PWM
 */
    #define TIMER0_SELECT_MODE   NORMAL




/*CHOSE MOD FOR FAST PWM:
  inverted=0 non_inverted_mode=1
                                */
#define TIMER0_FAST_PWM_selection   NON_INVERTED


/*chose_clock :   0-NO_CLK_SOURCE
                  1-NO_CLK_SOURCE
                  2-CLK_SOURCE_8
                  3-CLK_SOURCE_64
                  4CLK_SOURCE_256
                  5-CLK_SOURCE_1024

                                        */

#define TIMER0_PRESCALER_SELECTION    CLK_SOURCE_1024

/* TIMER0 OVERFLOW INTERRUPT:
        ENABLEL OR DISABEL        */


#define TIMER0_OVF_INTURRPTS   DISABEL


 /*       TO Compare match  inturrupts
                ENABEL OR DISABEL                   */

#define TIMER0_COMP_INTURRPTS   DISABEL



    /*pre load value */
#define TIMER0_PreLoad   97

#endif /*TIMR_CFG_H*/





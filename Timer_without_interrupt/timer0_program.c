
#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include"timer0_privet.h"

#include "Timer_config.h"

#include "DIO_private.h"
#include "DIO_interface.h"



uint_8 counter=0;
uint_8 pre_load_value=0;
uint_8 flage=0;
uint_32 Ton=0,T=0;

void (*gcallBack)(void)=NULL;

void timer_callback(void(*CallBack)(void))
{
	gcallBack =CallBack ;
}

void Pre_Load_Value(uint_8 au8_Pre_load_value)
{
	TCNT0 =au8_Pre_load_value ;

}


void Timer0_Voidint(void)
{
	/* TIMER0_SELECT_MODE*/

	#if TIMER0_SELECT_MODE == NORMAL_MODE

	   /*SELECT NORMALMOD (0V)*/
		     CLR_BIT(TCCR0,WGM01);
		     CLR_BIT(TCCR0,WGM00);

	#elif TIMER0_SELECT_MODE ==FAST_PWM
	             SET_BIT(TCCR0,WGM01);
	             SET_BIT(TCCR0,WGM00);
		        #if  TIMER0_FAST_PWM_selection == NON_INVERTED
	                    CLR_BIT(TCCR0,COM00);
	                     SET_BIT(TCCR0 ,COM01);
			     #elif  TIMER0_FAST_PWM_selection == INVERTED
	                     SET_BIT(TCCR0,COM00);
	                     SET_BIT(TCCR0,COM01);
	              #endif

	#elif TIMER0_SELECT_MODE ==CTC_MODE
	    	            SET_BIT(TCCR0,WGM01);
	    	            CLR_BIT(TCCR0,WGM00);

	#elif TIMER0_SELECT_MODE == PHASE_CORRECT_MODE
	    	             CLR_BIT(TCCR0,WGM01);
	    	             SET_BIT(TCCR0,WGM00);
    #else
         #error    "Wrong TIMER order"
	    #endif

#if TIMER0_PRESCALER_SELECTION == NO_CLK_SOURCE
	    	             CLR_BIT(TCCR0 , CS00);
	    	             CLR_BIT(TCCR0 , CS01);
	    	             CLR_BIT(TCCR0 , CS02);

#elif TIMER0_PRESCALER_SELECTION == NO_PRESCALER

          SET_BIT(TCCR0,CS00);
	      CLR_BIT(TCCR0,CS01);
	      CLR_BIT(TCCR0,CS01);
#elif TIMER0_PRESCALER_SELECTION == CLK_SOURCE_8

	      CLR_BIT(TCCR0,CS00);
	      SET_BIT(TCCR0,CS01);
	      CLR_BIT(TCCR0,CS02);
#elif TIMER0_PRESCALER_SELECTION == CLK_SOURCE_64
          SET_BIT(TCCR0,CS00);
          SET_BIT(TCCR0,CS01);
	      CLR_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER_SELECTION ==  CLK_SOURCE_256
	     CLR_BIT(TCCR0,CS00);
	     CLR_BIT(TCCR0,CS01);
	     SET_BIT(TCCR0,CS02);
#elif TIMER0_PRESCALER_SELECTION ==  CLK_SOURCE_1024
	     SET_BIT(TCCR0,CS00);
	     CLR_BIT(TCCR0,CS01);
	     SET_BIT(TCCR0,CS02);
#endif

	    /*OVER FLOW INTURRPT*/
#if TIMER0_OVF_INTURRPTS == DISABLE
	     CLR_BIT(TIMSK,TOIEO);
#elif  	 TIMER0_OVF_INTURRPTS == ENABLE
	     SET_BIT(TIMSK,TOIEO);

#endif
}




void Timer0_VoidintDutyCycle(uint_8 au8_Copy_Duty){

	OCR0=au8_Copy_Duty;
}


void Timer0_delay(uint_8 au8_Timeout)
{
	uint_8 au8_counter=0;
    while( GET_BIT(TIFR ,TOV0)==0)
    {
    	SET_BIT(TIFR ,TOV0);
    	au8_counter++;
         if(au8_counter == au8_Timeout)
        	 break;
    }

}


void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
	if (gcallBack!=NULL )
	{
		gcallBack();
	}
	else{
		/*do nothing*/
	    }

}


void __vector_10(void) __attribute__((signal));

void __vector_10(void)
{
	static uint_8 counter=0;
	counter++;

if(counter==123)
{
	TCNT0=TIMER0_PreLoad;
	DIO_TogPinValue(PORTB, PIN0);
	counter=0;
}


}



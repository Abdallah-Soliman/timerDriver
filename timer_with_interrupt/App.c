/*
 * App.c
 *
 *  Created on: Jan 6, 2022
 *      Author: abdalah
 */

#include "primitive_data_types.h"
#include"BIT_MATH.h"
#include "DIO_interface.h"
#include "timer0_interface.h"
#include "GIE_interface.h"
void SW_PWM_Gneration(void);


void main ()
{
	  /*some peripheral initialization  */

	DIO_SetPinDirection(PORTB , PIN4 , OUTPUT);

	DIO_SetPinValue(PORTB,PIN4,HIGH);

	timer_callback(SW_PWM_Gneration);

	GIE_voidEnable();

	Timer0_Voidint();
	/*preload value for 300ms*/
	Pre_Load_Value(230);
	while(1);

}


          /*call back function */
         /*300m on 500m off */
void SW_PWM_Gneration(void)
{
	static uint8_t counter=0;
	 counter++;
     if(counter == 10)
     {
    	 DIO_SetPinValue(PORTB,PIN4,LOW);
    	 Pre_Load_Value(204);
     }
     else if(counter == 26)
     {
    	 DIO_SetPinValue(PORTB,PIN4,HIGH);
    	 Pre_Load_Value(230);
    	 counter=0;
     }

}

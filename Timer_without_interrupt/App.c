/*
 * App.c
 *
 *  Created on: Jan 6, 2022
 *      Author: abdalah
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "timer0_interface.h"
#include "GIE_interface.h"
#include "delay_interface.h"
void main ()
{
	  /*some peripheral initialization  */

	DIO_SetPinDirection(PORTB , PIN4 , OUTPUT);

	while(1)
	{
		DIO_SetPinValue(PORTB,PIN4,HIGH);
		Delay(9);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		Delay(15);
	}



}


          /*call back function */
         /*300m on 500m off */


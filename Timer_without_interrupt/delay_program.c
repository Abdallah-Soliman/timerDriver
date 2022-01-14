/*
 * delay_program.c
 *
 *  Created on: Jan 11, 2022
 *      Author: abdalah
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "timer0_interface.h"
void Delay(uint_8 delay)
{
	Timer0_delay(delay);
}




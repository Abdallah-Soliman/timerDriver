/*
 * DIO_program.c
 *
 *  Created on: Jun 1, 2022
 *      Author: Abdulla Mohamed Soliman
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_private.h"
#include "DIO_private.h"

void DIO_SetPinDirection(uint_8 au8_PORT , uint_8 au8_PIN , uint_8 au8_DIRECTION)
{
	switch (au8_PORT)
	{
		case PORTA: if (au8_DIRECTION==INPUT)
					{
						CLR_BIT(DDRA_REG,au8_PIN);
					}
					else if(au8_DIRECTION==OUTPUT)
					{
						SET_BIT(DDRA_REG,au8_PIN);
					}
					else
					{
						//do noting
					}
					break;
		case PORTB: if (au8_DIRECTION==INPUT)
					{
						CLR_BIT(DDRB_REG,au8_PIN);
					}
					else if(au8_DIRECTION==OUTPUT)
					{
						SET_BIT(DDRB_REG,au8_PIN);
					}
					else
					{
						//do noting
					}
					break;
		case PORTC: if (au8_DIRECTION==INPUT)
					{
						CLR_BIT(DDRC_REG,au8_PIN);
					}
					else if(au8_DIRECTION==OUTPUT)
					{
						SET_BIT(DDRC_REG,au8_PIN);
					}
					else
					{
						//do noting
					}
					break;
		case PORTD: if (au8_DIRECTION==INPUT)
					{
						CLR_BIT(DDRD_REG,au8_PIN);
					}
					else if(au8_DIRECTION==OUTPUT)
					{
						SET_BIT(DDRD_REG,au8_PIN);
					}
					else
					{
						//do noting
					}
					break;
		default://error
			break;
	}//switch
}//function
void DIO_SetPinValue(uint_8 au8_PORT , uint_8 au8_PIN , uint_8 au8_VALUE)
{
	switch (au8_PORT)
		{
			case PORTA: if (au8_VALUE==LOW)
						{
							CLR_BIT(PORTA_REG,au8_PIN);
						}
						else if(au8_VALUE==HIGH)
						{
							SET_BIT(PORTA_REG,au8_PIN);
						}
						else
						{
							//do noting
						}
						break;
			case PORTB: if (au8_VALUE==LOW)
						{
							CLR_BIT(PORTB_REG,au8_PIN);
						}
						else if(au8_VALUE==HIGH)
						{
							SET_BIT(PORTB_REG,au8_PIN);
						}
						else
						{
							//do noting
						}
						break;
			case PORTC: if (au8_VALUE==LOW)
						{
							CLR_BIT(PORTC_REG,au8_PIN);
						}
						else if(au8_VALUE==HIGH)
						{
							SET_BIT(PORTC_REG,au8_PIN);
						}
						else
						{
							//do noting
						}
						break;
			case PORTD: if (au8_VALUE==LOW)
						{
							CLR_BIT(PORTD_REG,au8_PIN);
						}
						else if(au8_VALUE==HIGH)
						{
							SET_BIT(PORTD_REG,au8_PIN);
						}
						else
						{
							//do noting
						}
						break;
			default://error
				break;
		}//switch
}//function
void DIO_TogPinValue(uint_8 au8_PORT , uint_8 PIN)
{
	switch(au8_PORT)
	{
		case PORTA: TOG_BIT(PORTA_REG,PIN);break;
		case PORTB: TOG_BIT(PORTB_REG,PIN);break;
		case PORTC: TOG_BIT(PORTC_REG,PIN);break;
		case PORTD: TOG_BIT(PORTD_REG,PIN);break;
		default://error
			break;
	}//switch
}//function
void DIO_TogPinDirection(uint_8 au8_PORT , uint_8 PIN)
{
	switch(au8_PORT)
	{
		case PORTA: TOG_BIT(DDRA_REG,PIN);break;
		case PORTB: TOG_BIT(DDRB_REG,PIN);break;
		case PORTC: TOG_BIT(DDRC_REG,PIN);break;
		case PORTD: TOG_BIT(DDRD_REG,PIN);break;
		default://error
			break;
	}//switch
}//function
void DIO_Setau8_PORTDirection(uint_8 au8_PORT , uint_8 DIRECTION)
{
	switch(au8_PORT)
	{
		case PORTA: DDRA_REG=DIRECTION;break;
		case PORTB: DDRB_REG=DIRECTION;break;
		case PORTC: DDRC_REG=DIRECTION;break;
		case PORTD: DDRD_REG=DIRECTION;break;
		default://error
			break;
	}//switch
}//function
void DIO_Setau8_PORTValue(uint_8 au8_PORT , uint_8 VALUE)
{
	switch(au8_PORT)
	{
		case PORTA: PORTA_REG=VALUE;break;
		case PORTB: PORTB_REG=VALUE;break;
		case PORTC: PORTC_REG=VALUE;break;
		case PORTD: PORTD_REG=VALUE;break;
		default://error
			break;
	}//switch
}//function
uint_8 DIO_GetPinValue(uint_8 au8_PORT,uint_8 PIN)
{
	uint_8 PinValue;
	switch(au8_PORT)
	{
		case PORTA: PinValue = GET_BIT(PINA_REG,PIN); break;
		case PORTB: PinValue = GET_BIT(PINB_REG,PIN); break;
		case PORTC: PinValue = GET_BIT(PINC_REG,PIN); break;
		case PORTD: PinValue = GET_BIT(PIND_REG,PIN); break;
		default://error
			break;
	}//switch
	return PinValue;
}//function
uint_8 DIO_Getau8_PORTValue(uint_8 au8_PORT)
{
	uint_8 PinValue;
	switch(au8_PORT)
	{
		case PORTA: PinValue =*((uint_8*)0x39); break;
		case PORTB: PinValue =*((uint_8*)0x36); break;
		case PORTC: PinValue =*((uint_8*)0x33); break;
		case PORTD: PinValue =*((uint_8*)0x30); break;
		default://error
			break;
	}//switch
	return PinValue;
}


/*
 * DIO_INTERFACE.h
 *
 *  Created on: JUN 1, 2022
 *      Author: Abdullah Mohamed Soliman
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

                    /* DIO APIs deales with pins */
         void DIO_SetPinDirection(uint_8 PORT , uint_8 PIN , uint_8 DIRECTION);
         void DIO_SetPinValue(uint_8 PORT , uint_8 PIN , uint_8 VALUE);
         void DIO_TogPinValue(uint_8 PORT , uint_8 PIN);
         void DIO_TogPinDirection(uint_8 PORT , uint_8 PIN);
         uint_8 DIO_GetPinValue(uint_8 PORT,uint_8 PIN);

                     /* DIO APIs deales with ports */
        void DIO_SetPortDirection(uint_8 PORT , uint_8 DIRECTION);
        void DIO_SetPortValue(uint_8 PORT , uint_8 VALUE);
        void DIO_PULLUP(uint_8 PORT,uint_8 PIN);
        uint_8 DIO_GetPortValue(uint_8 PORT);




// DIO macros
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/* pin direction*/
#define OUTPUT 1
#define INPUT  0

/* pin values*/
#define LOW  0
#define HIGH 1

/* Pin numbers*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


#endif /* DIO_INTERFACE_H_ */

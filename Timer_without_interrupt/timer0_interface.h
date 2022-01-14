
#ifndef _TIMER0_INTE_H_
#define _TIMER0_INTE_H_


void Timer0_Voidint(void);

void timer_callback(void(*CallBack)(void));
void Pre_Load_Value(uint_8 Pre_load_value);
void Timer0_delay(uint_8 au8_Timeout);
void Timer0_VoidintDutyCycle(uint_8 Copy_Duty);

#endif


#ifndef _TIMER0_INTE_H_
#define _TIMER0_INTE_H_


void Timer0_Voidint(void);

void timer_callback(void(*CallBack)(void));
void Pre_Load_Value(uint8_t Pre_load_value);
void Timer0_delay(uint8_t au8_Timeout);
void Timer0_VoidintDutyCycle(uint8_t Copy_Duty);

#endif
